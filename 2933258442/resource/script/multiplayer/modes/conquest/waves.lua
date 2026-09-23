-- =========================================================
-- WAVE / COOLDOWN LOGIC
-- =========================================================
-- Purchase-count and cooldown behavior.

ConquestWaves = ConquestWaves or {}

local PHASE_ATTACKER_WAVE = "attacker_wave"
local PHASE_DEFENDER_OPENING = "defender_opening"
local PHASE_DEFENDER_COUNTERATTACK = "defender_counterattack"
local MISSION_VAR_GARRISON_END = "garrison_end"
local MISSION_VAR_GARRISON_READY = "garrison_ready"

-- Rolls how many attacker waves this battle will use.
local function RollAttackerMaxWaves()
	local plan = ConquestConfig.AttackerWaves
	return math.random(plan.MaxWavesMin, plan.MaxWavesMax)
end

function ConquestWaves.RollAttackerMaxWavesForSim()
	return RollAttackerMaxWaves()
end

-- Returns the configured attacker wave size pattern, falling back to flat if missing.
local function GetAttackerWavePattern()
	local plan = ConquestConfig.AttackerWaves
	return ConquestConfig.AttackerWavePatterns[plan.Pattern] or ConquestConfig.AttackerWavePatterns.flat
end

local function GetAttackerWaveStep()
	local pattern = GetAttackerWavePattern()
	local nextWaveNumber = ConquestState.waveNumber + 1

	if nextWaveNumber == 1 then
		return pattern.First
	end

	if nextWaveNumber >= ConquestState.attackerMaxWaves then
		return pattern.Final
	end

	return pattern.Middle
end

-- Returns the unit-count scale for the next attacker wave based on its position in the pattern.
local function GetAttackerWaveScale()
	local step = GetAttackerWaveStep()

	if type(step) == "table" then
		return step.Scale or 1.0
	end

	return step or 1.0
end

-- Returns the composition intent for the next attacker wave.
local function GetAttackerWaveIntent()
	local step = GetAttackerWaveStep()

	if type(step) == "table" then
		return step.Intent or "main_attack"
	end

	return "main_attack"
end

-- Rolls the unit target for the next attacker wave after applying pressure deltas and the wave pattern scale.
local function RollAttackerWaveTarget()
	local plan = ConquestConfig.AttackerWaves
	local baseUnits = math.random(plan.MinUnits, plan.MaxUnits)
	local adjustedUnits = ConquestPressure.ApplyPurchaseCountDelta(baseUnits, PHASE_ATTACKER_WAVE, plan.MinWaveUnits)
	local waveScale = GetAttackerWaveScale()
	local waveIntent = GetAttackerWaveIntent()
	local scaledTarget = math.floor((adjustedUnits * waveScale) + 0.5)
	local target = math.max(scaledTarget, plan.MinWaveUnits)

	if printDebug then
		print("Print: purchaseTarget phase=", PHASE_ATTACKER_WAVE,
			"baseUnits=", baseUnits,
			"pressureAdjustedUnits=", adjustedUnits,
			"wave=", ConquestState.waveNumber + 1,
			"attackerMaxWaves=", ConquestState.attackerMaxWaves,
			"waveScale=", waveScale,
			"intent=", waveIntent,
			"finalTargetBudget=", target)
	end

	return target, waveIntent
end

local function GetDefenderOpeningFlagCount()
	local count = 0

	for _, _ in pairs(BotApi.Scene.Flags or {}) do
		count = count + 1
	end

	return math.max(1, count)
end

local function IsMissionVarEnabled(varName)
	local value = BotApi.Scene:GetVar(varName)
	return value == 1 or value == "1" or value == true
end

local function PrintGarrisonReadyFailsafeWarning(phase)
	if ConquestState.defenderOpeningGarrisonReadyFailsafeWarning then
		return
	end

	ConquestState.defenderOpeningGarrisonReadyFailsafeWarning = true

	print("Warning: garrison_ready missing before purchase phase. Releasing garrison hold. phase=", phase or "purchase_phase")
end

-- Rolls how many units the defender buys during the initial garrison setup.
local function RollDefenderOpeningTarget(flagCount)
	local plan = ConquestConfig.DefenderOpening
	flagCount = flagCount or GetDefenderOpeningFlagCount()
	local baseUnitsPerFlag = math.random(plan.MinUnitsPerFlag, plan.MaxUnitsPerFlag)
	local adjustedUnitsPerFlag = ConquestPressure.ApplyPurchaseCountDelta(baseUnitsPerFlag, PHASE_DEFENDER_OPENING, plan.MinUnitsPerFlagFloor)
	local target = adjustedUnitsPerFlag * flagCount

	if printDebug then
		print("Print: purchaseTarget phase=", PHASE_DEFENDER_OPENING,
			"baseUnitsPerFlag=", baseUnitsPerFlag,
			"pressureAdjustedUnitsPerFlag=", adjustedUnitsPerFlag,
			"flagCount=", flagCount,
			"finalTargetBudget=", target)
	end

	return target
end


function ConquestWaves.RollAttackerWaveTargetForSim()
	if ConquestState.attackerMaxWaves <= 0 then
		ConquestState.attackerMaxWaves = RollAttackerMaxWaves()
	end

	return RollAttackerWaveTarget()
end

function ConquestWaves.RollDefenderOpeningTargetForSim()
	return RollDefenderOpeningTarget()
end

-- Starts a finite purchase phase and resets its purchase counter.
function ConquestWaves.StartPurchasePhase(phase, target)
	if ConquestState.botDefender and phase ~= PHASE_DEFENDER_OPENING then
		ConquestWaves.ResolveGarrisonReadyBeforePurchase(phase)
	end

	ConquestState.purchasePhase = phase
	ConquestState.phasePurchaseCount = 0
	ConquestState.phasePurchaseTarget = target

	ConquestPurchaseProfiles.StartPurchasePhasePlan(phase, target)

	if printDebug then
		print("Print: purchasePhase", phase, "targetBudget", target)
	end
end

-- Starts the next attacker wave purchase phase.
local function StartAttackerWave()
	if ConquestState.attackerMaxWaves <= 0 then
		ConquestState.attackerMaxWaves = RollAttackerMaxWaves()
	end

	ConquestAttackerWaveOff.CapturePreWaveSnapshot()

	ConquestState.waveSpawnActive = true
	ConquestState.attackerWaveTargetFlagName = nil

	local target, waveIntent = RollAttackerWaveTarget()
	ConquestState.waveUnitTotal = target
	ConquestState.attackerWaveIntent = waveIntent

	ConquestWaves.StartPurchasePhase(PHASE_ATTACKER_WAVE, ConquestState.waveUnitTotal)

	if printDebug then
		print("Print: attacker wave", ConquestState.waveNumber + 1, "of", ConquestState.attackerMaxWaves)
	end
end

-- Finishes the current attacker wave and marks all waves complete when the max is reached.
local function FinishAttackerWave()
	ConquestState.waveSpawnActive = false
	ConquestAttackerWaveOff.CapturePostWaveSnapshot()

	ConquestState.waveNumber = ConquestState.waveNumber + 1
	ConquestPurchaseProfiles.FinishPurchasePhasePlan()
	ConquestState.purchasePhase = nil

	if ConquestState.waveNumber >= ConquestState.attackerMaxWaves then
		ConquestState.attackerWavesFinished = true
		ConquestAttackerFailure.Arm()
	end

	if printDebug then
		print("Print: waveNumber", ConquestState.waveNumber)
		print("Print: attackerWavesFinished", ConquestState.attackerWavesFinished)
	end
end

-- Starts the defender's initial garrison purchase phase if it has not already finished.
local function StartDefenderOpening()
	if ConquestState.defenderOpeningFinished then
		return
	end

	if ConquestConfig.DefenderOpening.UnitsHoldMovement then
		BotApi.Scene:SetVar(MISSION_VAR_GARRISON_END, 0)
		BotApi.Scene:SetVar(MISSION_VAR_GARRISON_READY, 0)
		ConquestState.defenderOpeningHoldRegistrationActive = true
		ConquestState.defenderOpeningGarrisonReadyFailsafeWarning = false
		RegisterCurrentGarrisonSquads()
	end

	local flagCount = GetDefenderOpeningFlagCount()
	ConquestState.defenderOpeningFlagCount = flagCount
	ConquestState.garrisonSpawnPointIndexByPlacementClass = {}

	ConquestWaves.StartPurchasePhase(PHASE_DEFENDER_OPENING, RollDefenderOpeningTarget(flagCount))

-- by Carlos, This block expires purchases for AI defender bot after garrisoning stage (as a failsafe)
	BotApi.Events:SetQuantTimer(function()
		ConquestState.defenderOpeningExpired = true
	end, ConquestConfig.DefenderOpening.MaxDuration)
end

-- Marks the defender opening complete and clears the active purchase phase.
local function FinishDefenderOpening()
	ConquestState.defenderOpeningFinished = true
	ConquestPurchaseProfiles.FinishPurchasePhasePlan()
	ConquestState.purchasePhase = nil

	if not ConquestConfig.DefenderOpening.UnitsHoldMovement then
		BotApi.Scene:SetVar(MISSION_VAR_GARRISON_END, 1)
		ConquestState.defenderOpeningGarrisonReadyFailsafeWarning = false
		return
	end

	RegisterCurrentGarrisonSquads()
	BotApi.Scene:SetVar(MISSION_VAR_GARRISON_END, 1)
	ConquestState.defenderOpeningGarrisonReadyPending = true

	if printDebug then
		print("Print: garrison_end set to 1, waiting for garrison_ready")
	end
end

-- Ends the defender opening once MaxDuration passes so no further garrison units
-- are placed on objective flags. Runs before TrySpawnUnit in the quant so a pending
-- retry cannot buy outside a phase.
function ConquestWaves.UpdateDefenderOpeningCutoff()
	if not ConquestState.defenderOpeningExpired or ConquestState.defenderOpeningFinished then
		return
	end

	if ConquestState.purchasePhase ~= PHASE_DEFENDER_OPENING then
		return
	end

	KillSpawnWaitTimer()
	Context.SpawnInfo = nil

	if printDebug then
		print("Print: defender opening cut off",
			"spent=", ConquestState.phasePurchaseCount,
			"targetBudget=", ConquestState.phasePurchaseTarget)
	end

	FinishDefenderOpening()

	if not spawningUnit then
		KillSpawnCooldownTimer()
		SetSpawnCooldownTimer()
	end
end

function ConquestWaves.UpdateDefenderOpeningGarrisonReady()
	if not ConquestState.defenderOpeningGarrisonReadyPending then
		return
	end

	RegisterCurrentGarrisonSquads()

	if not IsMissionVarEnabled(MISSION_VAR_GARRISON_READY) then
		return
	end

	ConquestState.defenderOpeningGarrisonReadyPending = false
	ConquestState.defenderOpeningHoldRegistrationActive = false
	ConquestState.defenderOpeningGarrisonReadyFailsafeWarning = false

	if printDebug then
		print("Print: garrison_ready received, defender opening hold registration ended")
	end
end


-- Releases the garrison-ready wait if a later purchase phase needs to start before
-- the mission script returns garrison_ready. This is a purchase-boundary failsafe,
-- not normal timing behavior. Registered garrison squads are left unchanged.
function ConquestWaves.ResolveGarrisonReadyBeforePurchase(phase)
	if not ConquestState.defenderOpeningGarrisonReadyPending then
		return true
	end

	ConquestWaves.UpdateDefenderOpeningGarrisonReady()
	if not ConquestState.defenderOpeningGarrisonReadyPending then
		return true
	end

	RegisterCurrentGarrisonSquads()
	PrintGarrisonReadyFailsafeWarning(phase)

	ConquestState.defenderOpeningGarrisonReadyPending = false
	ConquestState.defenderOpeningHoldRegistrationActive = false

	return true
end


-- Returns true once the current finite purchase phase has bought enough units.
local function HasPhaseReachedTarget()
	return (ConquestState.phasePurchaseTarget or 0) > 0
		and (ConquestState.phasePurchaseCount or 0) >= ConquestState.phasePurchaseTarget
end

-- Advances purchase phase state before cooldown and purchase checks run.
function ConquestWaves.UpdatePurchasePhase()
	if ConquestBattleResult.IsWinnerDecided() then
		return
	end

	if ConquestState.botDefender then
		if ConquestState.defenderOpeningGarrisonReadyPending then
			ConquestWaves.UpdateDefenderOpeningGarrisonReady()
			return
		end

		if not ConquestState.defenderOpeningFinished then
			if not ConquestState.purchasePhase then
				StartDefenderOpening()
			end

			if ConquestState.purchasePhase == PHASE_DEFENDER_OPENING and HasPhaseReachedTarget() then
				FinishDefenderOpening()
			end

			return
		end

		if ConquestState.purchasePhase == PHASE_DEFENDER_COUNTERATTACK and HasPhaseReachedTarget() then
			ConquestDefenderCounterattack.FinishActive()
		end

		return
	end

	if ConquestState.attackerWavesFinished then
		return
	end

	if not ConquestState.purchasePhase then
		if not ConquestState.waveSpawnActive and not ConquestState.attackerWaveOffReleaseReady then
			return
		end

		ConquestAttackerWaveOff.ResetCooldown()
		StartAttackerWave()
		return
	end

	if ConquestState.purchasePhase == PHASE_ATTACKER_WAVE and HasPhaseReachedTarget() then
		FinishAttackerWave()
	end
end


-- Returns whether the bot is currently allowed to buy another unit.
function ConquestWaves.CanPurchaseUnit()
	if ConquestBattleResult.IsWinnerDecided() then
		return false
	end

	ConquestWaves.UpdatePurchasePhase()

	if ConquestState.botDefender then
		if ConquestState.defenderOpeningGarrisonReadyPending then
			if ConquestState.purchasePhase then
				ConquestWaves.ResolveGarrisonReadyBeforePurchase(ConquestState.purchasePhase)
			elseif ConquestDefenderCounterattack.HasReadyPending() then
				ConquestDefenderCounterattack.TryStartAnyPending()
			else
				return false
			end
		end

		if not ConquestState.purchasePhase then
			ConquestDefenderCounterattack.TryStartAnyPending()
		end

		if ConquestState.purchasePhase == PHASE_DEFENDER_OPENING then
			return not HasPhaseReachedTarget()
		end

		if ConquestState.purchasePhase == PHASE_DEFENDER_COUNTERATTACK then
			return not HasPhaseReachedTarget()
		end

		return false
	end

	if ConquestState.attackerWavesFinished then
		return false
	end

	return not HasPhaseReachedTarget()
end

-- Tracks one successful purchase against the active finite purchase phase.
function ConquestWaves.OnUnitPurchased()
	if not ConquestState.purchasePhase then
		return
	end

	local forceCost = ConquestPurchaseProfiles.CommitPendingPurchaseCost()
	ConquestState.phasePurchaseCount = ConquestState.phasePurchaseCount + forceCost

	if printDebug then
		print("Print: purchasePhase", ConquestState.purchasePhase,
			"phasePurchaseBudget =", ConquestState.phasePurchaseCount,
			"targetBudget =", ConquestState.phasePurchaseTarget,
			"lastCost =", forceCost)
	end
end

-- Hook called by utility.lua after a successful purchase.
function OnUnitPurchased()
	ConquestWaves.OnUnitPurchased()
end

-- Chooses the cooldown range for the next purchase attempt based on current phase state.
local function GetCooldownRange()
	if ConquestState.botDefender and ConquestState.firstPurchase then
		return ConquestConfig.StartSpawnTime.DefenseMin, ConquestConfig.StartSpawnTime.DefenseMax
	end

	if ConquestState.firstPurchase then
		return ConquestConfig.StartSpawnTime.AttackMin, ConquestConfig.StartSpawnTime.AttackMax
	end

	if ConquestState.botDefender and ConquestState.defenderOpeningFinished and not ConquestState.purchasePhase then
		if ConquestDefenderCounterattack.HasReadyPending() then
			return ConquestConfig.DefenderCounterattack.ChainedResponseDelayMin, ConquestConfig.DefenderCounterattack.ChainedResponseDelayMax
		end

		return ConquestConfig.CompletedPurchaseIdleTime.Min, ConquestConfig.CompletedPurchaseIdleTime.Max
	end

	if ConquestState.attackerWavesFinished then
		return ConquestAttackerFailure.GetNextCooldown()
	end

	if not ConquestState.waveSpawnActive then
		local minCooldown, maxCooldown = ConquestAttackerWaveOff.GetNextCooldown()
		return minCooldown, maxCooldown
	end

	return ConquestConfig.SpawnCooldownTime.DCGMin, ConquestConfig.SpawnCooldownTime.DCGMax
end

-- Hook called by utility.lua to get the next spawn cooldown.
function GameModeSpawnCooldown()
	ConquestWaves.UpdatePurchasePhase()

	local minCooldown, maxCooldown = GetCooldownRange()
	local cooldown = math.random(minCooldown, maxCooldown)

	ConquestState.firstPurchase = false
	return cooldown
end
