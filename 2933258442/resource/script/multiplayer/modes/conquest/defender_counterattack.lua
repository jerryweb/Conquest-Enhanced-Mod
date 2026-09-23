-- =========================================================
-- DEFENDER COUNTERATTACK
-- =========================================================
-- Owns defender counterattack queueing, timing, start/finish helpers,
-- and scene snapshots for later counterattack purchase planning.

ConquestDefenderCounterattack = ConquestDefenderCounterattack or {}

local SNAPSHOT_QUERY_INTERVAL_SECONDS = 5
local PHASE_DEFENDER_COUNTERATTACK = "defender_counterattack"
local SCENE_MEMORY_DEFENDER_COUNTERATTACK = "defender_counterattack"

-- Returns the current owner of a scene flag by name.
local function GetFlagOwnerByName(flagName)
	for _, flag in pairs(BotApi.Scene.Flags) do
		if flag.name == flagName then
			return flag.occupant
		end
	end

	return nil
end

-- Checks total and per-flag counterattack limits.
local function CanUseCounterattackForFlag(flagName)
	local plan = ConquestConfig.DefenderCounterattack
	local flagCount = ConquestState.counterattacksByFlag[flagName] or 0

	if ConquestState.totalCounterattacksStarted >= plan.MaxTotal then
		return false
	end

	return flagCount < plan.MaxPerFlag
end

-- Removes a flag from the pending counterattack queue.
local function ClearPending(flagName)
	ConquestState.counterattackPendingByFlag[flagName] = nil
end

-- Rolls how many units the defender buys during one counterattack burst.
local function RollTargetUnits()
	local plan = ConquestConfig.DefenderCounterattack
	local baseUnits = math.random(plan.MinUnits, plan.MaxUnits)

	return ConquestPressure.ApplyPurchaseCountDelta(baseUnits, PHASE_DEFENDER_COUNTERATTACK)
end

function ConquestDefenderCounterattack.RollTargetUnitsForSim()
	return RollTargetUnits()
end

-- Captures and stores the scene state used by later defender counterattack purchase planning.
function ConquestDefenderCounterattack.CapturePlanningSnapshot(flagName, targetUnits)
	local sceneSnapshot = ConquestScene.QueryCompositionSnapshot(SNAPSHOT_QUERY_INTERVAL_SECONDS)
	local compositions = sceneSnapshot.compositions
	local botComposition = compositions[BotApi.Instance.playerId] or ConquestScene.CreateEmptyComposition()
	local playerComposition = compositions[BotApi.Conquest.FirstPlayerId] or ConquestScene.CreateEmptyComposition()

	ConquestSceneMemory.Update(SCENE_MEMORY_DEFENDER_COUNTERATTACK, botComposition, playerComposition, true)

	ConquestState.defenderCounterattackSnapshot = {
		flagName = flagName,
		targetUnits = targetUnits,
		botComposition = botComposition,
		playerComposition = playerComposition,
	}

	if printDebug then
		print(
			"Print: defender counterattack snapshot",
			"flag=", flagName,
			"targetUnits=", targetUnits,
			"bot=", ConquestScene.FormatCompositionSummary(botComposition),
			"player=", ConquestScene.FormatCompositionSummary(playerComposition)
		)
	end

	return ConquestState.defenderCounterattackSnapshot
end

-- Starts a defender counterattack purchase phase for a specific lost flag.
function ConquestDefenderCounterattack.Start(flagName)
	if not ConquestState.botDefender then
		return false
	end

	if ConquestBattleResult.IsWinnerDecided() then
		return false
	end

	if not ConquestState.defenderOpeningFinished then
		return false
	end

	if ConquestState.defenderOpeningGarrisonReadyPending then
		ConquestWaves.ResolveGarrisonReadyBeforePurchase(PHASE_DEFENDER_COUNTERATTACK)
	end

	if ConquestState.purchasePhase then
		return false
	end

	if not CanUseCounterattackForFlag(flagName) then
		return false
	end

	ConquestState.counterattackFlagName = flagName
	ConquestState.totalCounterattacksStarted = ConquestState.totalCounterattacksStarted + 1
	ConquestState.counterattacksByFlag[flagName] = (ConquestState.counterattacksByFlag[flagName] or 0) + 1

	local targetUnits = RollTargetUnits()
	ConquestDefenderCounterattack.CapturePlanningSnapshot(flagName, targetUnits)
	ConquestWaves.StartPurchasePhase(PHASE_DEFENDER_COUNTERATTACK, targetUnits)

	return true
end

-- Ends the active defender counterattack and clears its target flag.
function ConquestDefenderCounterattack.FinishActive()
	ConquestState.counterattackFlagName = nil
	ConquestPurchaseProfiles.FinishPurchasePhasePlan()
	ConquestState.purchasePhase = nil
end

-- Returns true if any queued defender counterattack is ready to start.
function ConquestDefenderCounterattack.HasReadyPending()
	for _, pending in pairs(ConquestState.counterattackPendingByFlag) do
		if pending.ready then
			return true
		end
	end

	return false
end

-- Refreshes the idle spawn cooldown when a counterattack becomes ready during completed-purchase idle time.
local function RefreshIdleCooldownForReadyCounterattack()
	if ConquestBattleResult.IsWinnerDecided() then
		return false
	end

	if not ConquestState.botDefender then
		return false
	end

	if not ConquestState.defenderOpeningFinished then
		return false
	end

	if ConquestState.defenderOpeningGarrisonReadyPending then
		ConquestWaves.ResolveGarrisonReadyBeforePurchase(PHASE_DEFENDER_COUNTERATTACK)
	end

	if ConquestState.purchasePhase then
		return false
	end

	if not Context or not Context.SpawnWait or not Context.SpawnWait.CooldownTimer then
		return false
	end

	if not KillSpawnCooldownTimer or not SetSpawnCooldownTimer then
		return false
	end

	KillSpawnCooldownTimer()
	SetSpawnCooldownTimer()

	return true
end

-- Attempts to start one ready pending counterattack if its flag is still lost.
local function TryStartPending(flagName)
	if ConquestBattleResult.IsWinnerDecided() then
		ClearPending(flagName)
		return false
	end

	local pending = ConquestState.counterattackPendingByFlag[flagName]

	if not pending or not pending.ready then
		return false
	end

	if not CanUseCounterattackForFlag(flagName) then
		ClearPending(flagName)
		return false
	end

	if GetFlagOwnerByName(flagName) == team then
		ClearPending(flagName)
		return false
	end

	if ConquestDefenderCounterattack.Start(flagName) then
		ClearPending(flagName)
		return true
	end

	return false
end

-- Attempts to start the first ready pending defender counterattack.
function ConquestDefenderCounterattack.TryStartAnyPending()
	for flagName, pending in pairs(ConquestState.counterattackPendingByFlag) do
		if pending.ready and TryStartPending(flagName) then
			return true
		end
	end

	return false
end

-- Queues the response delay that runs after a confirmed flag loss.
local function QueueResponse(flagName)
	local pending = ConquestState.counterattackPendingByFlag[flagName]
	if not pending then
		return
	end

	local plan = ConquestConfig.DefenderCounterattack
	local delay = math.random(plan.ResponseDelayMin, plan.ResponseDelayMax)

	if printDebug then
		print("Print: defender counterattack response queued", flagName, "delay", delay)
	end

	BotApi.Events:SetQuantTimer(function()
		if ConquestBattleResult.IsWinnerDecided() then
			ClearPending(flagName)
			return
		end

		local currentPending = ConquestState.counterattackPendingByFlag[flagName]
		if not currentPending then
			return
		end

		if GetFlagOwnerByName(flagName) == team then
			ClearPending(flagName)
			return
		end

		currentPending.ready = true

		if printDebug then
			print("Print: defender counterattack ready", flagName)
		end

		if RefreshIdleCooldownForReadyCounterattack() then
			return
		end

		TryStartPending(flagName)
	end, delay)
end

-- Queues the confirmation delay after a defender flag becomes not defender-owned.
local function QueueConfirmation(flagName)
	if ConquestState.counterattackPendingByFlag[flagName] then
		return
	end

	if ConquestState.counterattackFlagName == flagName then
		return
	end

	if not CanUseCounterattackForFlag(flagName) then
		return
	end

	ConquestState.counterattackPendingByFlag[flagName] = {
		ready = false,
	}

	if printDebug then
		print("Print: defender counterattack confirmation queued", flagName)
	end

	local plan = ConquestConfig.DefenderCounterattack

	BotApi.Events:SetQuantTimer(function()
		if ConquestBattleResult.IsWinnerDecided() then
			ClearPending(flagName)
			return
		end

		local pending = ConquestState.counterattackPendingByFlag[flagName]
		if not pending then
			return
		end

		if GetFlagOwnerByName(flagName) == team then
			ClearPending(flagName)
			return
		end

		if math.random() > plan.ResponseChance then
			ClearPending(flagName)
			return
		end

		if printDebug then
			print("Print: defender counterattack confirmed", flagName)
		end

		QueueResponse(flagName)
	end, plan.ConfirmDelay)
end

-- Watches flag ownership changes and queues defender counterattacks for lost flags.
function ConquestDefenderCounterattack.UpdateFlagOwnership()
	if not ConquestState.botDefender then
		return
	end

	if ConquestBattleResult.IsWinnerDecided() then
		return
	end

	if not BotApi.Scene.Flags then
		return
	end

	ConquestDefenderCounterattack.TryStartAnyPending()

	for _, flag in pairs(BotApi.Scene.Flags) do
		local previousOwner = ConquestState.flagOwners[flag.name]
		local currentOwner = flag.occupant

		if previousOwner == nil then
			ConquestState.flagOwners[flag.name] = currentOwner
		elseif previousOwner ~= currentOwner then
			if printDebug then
				print("Print: defender flag ownership changed", tostring(flag.name), "previousOwner=", tostring(previousOwner), "currentOwner=", tostring(currentOwner))
			end

			if previousOwner == team and currentOwner ~= team then
				QueueConfirmation(flag.name)
			end

			ConquestState.flagOwners[flag.name] = currentOwner
		end
	end
end
