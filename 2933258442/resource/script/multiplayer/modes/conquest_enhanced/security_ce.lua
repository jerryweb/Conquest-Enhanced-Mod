-- =========================================================
-- DEFENDER SECURITY WAVE (CONQUEST ENHANCED)
-- =========================================================
-- Small flanking waves the bot buys while defending against the player.
-- Runs only when the bot is the defender. Flanking comes from the mission-layer
-- waypoint graph, which stays enabled for these squads (only the counterattack
-- phase and the wave-1 attacker override turn it off, see utilities_ce.lua).
--
-- Rules:
--   * First wave is rolled 4-6 minutes after match start, then every 4-6 minutes
--     after each wave starts, up to ConquestConfig.DefenderSecurityWave.MaxTotal.
--   * A security wave and a defender counterattack never run at the same time.
--     The counterattack has priority. Whichever wave is blocked waits
--     ConflictRetryDelay, then checks its conditions again.
--   * Stops when the winner is decided.

ConquestSecurityWave = ConquestSecurityWave or {}

local PHASE_DEFENDER_SECURITY = "defender_security"

local function GetPlan()
	return ConquestConfig.DefenderSecurityWave
end

local function IsMatchOver()
	return ConquestBattleResult.IsWinnerDecided()
end

local function HasWavesRemaining()
	return ConquestState.securityWavesStarted < GetPlan().MaxTotal
end

-- Returns true while a security wave purchase phase is running.
function ConquestSecurityWave.IsActive()
	return ConquestState.purchasePhase == PHASE_DEFENDER_SECURITY
end

-- Rolls how many units the next security wave buys. Only the risk delta applies:
-- defender_security has an entry in RiskPurchaseCountDelta and none in the
-- difficulty, battle-scale or commitment tables.
local function RollTargetUnits()
	local plan = GetPlan()
	local baseUnits = math.random(plan.MinUnits, plan.MaxUnits)
	local target = ConquestPressure.ApplyPurchaseCountDelta(baseUnits, PHASE_DEFENDER_SECURITY, plan.MinWaveUnits)

	if printDebug then
		print("Print: purchaseTarget phase=", PHASE_DEFENDER_SECURITY,
			"baseUnits=", baseUnits,
			"finalTargetBudget=", target)
	end

	return target
end

-- Queues the next wave-ready timer, unless the wave cap has been reached.
local function ArmNextTimer()
	if not HasWavesRemaining() then
		return
	end

	local plan = GetPlan()
	local delay = math.random(plan.IntervalMin, plan.IntervalMax)

	if printDebug then
		print("Print: security wave timer armed", "delay", delay,
			"started", ConquestState.securityWavesStarted,
			"max", plan.MaxTotal)
	end

	BotApi.Events:SetQuantTimer(function()
		if IsMatchOver() then
			return
		end

		ConquestState.securityWaveReady = true

		if printDebug then
			print("Print: security wave ready")
		end

		ConquestSecurityWave.TryStart()
	end, delay)
end

-- Queues one conflict retry. Only one retry is ever pending.
local function ScheduleRetry()
	if ConquestState.securityWaveRetryPending then
		return
	end

	ConquestState.securityWaveRetryPending = true

	BotApi.Events:SetQuantTimer(function()
		ConquestState.securityWaveRetryPending = false
		ConquestSecurityWave.TryStart()
	end, GetPlan().ConflictRetryDelay)
end

-- Opens the purchase phase for one security wave.
local function StartWave()
	ConquestState.securityWaveReady = false
	ConquestState.securityWavesStarted = ConquestState.securityWavesStarted + 1

	local target = RollTargetUnits()
	ConquestWaves.StartPurchasePhase(PHASE_DEFENDER_SECURITY, target)

	-- The bot idles for minutes between phases. Restart the cooldown now that a
	-- phase is active so the first purchase happens within seconds.
	if not spawningUnit and Context and Context.SpawnWait and Context.SpawnWait.CooldownTimer then
		KillSpawnCooldownTimer()
		SetSpawnCooldownTimer()
	end

	ArmNextTimer()

	if printDebug then
		print("Print: security wave started",
			"number=", ConquestState.securityWavesStarted,
			"targetBudget=", target)
	end

	return true
end

-- Starts the pending security wave if conditions allow, otherwise queues a retry.
-- Called when the wave becomes ready and from each retry. It is not polled every
-- quant, so a blocked wave really waits ConflictRetryDelay.
function ConquestSecurityWave.TryStart()
	if not ConquestState.botDefender or IsMatchOver() then
		return false
	end

	if not ConquestState.securityWaveReady then
		return false
	end

	-- Wait for the garrison to be released normally instead of forcing the
	-- garrison-ready failsafe.
	if not ConquestState.defenderOpeningFinished or ConquestState.defenderOpeningGarrisonReadyPending then
		ScheduleRetry()
		return false
	end

	-- A running phase (counterattack or anything else) blocks the wave, and a
	-- ready counterattack has priority over it.
	if ConquestState.purchasePhase or ConquestDefenderCounterattack.HasReadyPending() then
		if printDebug then
			print("Print: security wave blocked, retry in",
				GetPlan().ConflictRetryDelay,
				"phase=", tostring(ConquestState.purchasePhase))
		end

		ScheduleRetry()
		return false
	end

	return StartWave()
end

-- Ends the active security wave purchase phase.
function ConquestSecurityWave.FinishActive()
	ConquestPurchaseProfiles.FinishPurchasePhasePlan()
	ConquestState.purchasePhase = nil

	if printDebug then
		print("Print: security wave finished", "number=", ConquestState.securityWavesStarted)
	end
end

-- Called by a counterattack that was blocked by an active security wave.
-- The counterattack waits ConflictRetryDelay before it tries to start again.
function ConquestSecurityWave.HoldCounterattack()
	if ConquestState.counterattackHeldForSecurity then
		return
	end

	ConquestState.counterattackHeldForSecurity = true

	if printDebug then
		print("Print: counterattack held for security wave, retry in", GetPlan().ConflictRetryDelay)
	end

	BotApi.Events:SetQuantTimer(function()
		ConquestState.counterattackHeldForSecurity = false
	end, GetPlan().ConflictRetryDelay)
end

function ConquestSecurityWave.IsCounterattackHeld()
	return ConquestState.counterattackHeldForSecurity == true
end

-- Arms the first wave timer at match start. Does nothing when the player defends.
function ConquestSecurityWave.Init()
	if not ConquestState.botDefender then
		return
	end

	ArmNextTimer()
end
