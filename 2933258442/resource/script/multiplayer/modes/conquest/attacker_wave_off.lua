-- =========================================================
-- ATTACKER WAVE-OFF CONTROLLER
-- =========================================================
-- Controls dynamic delay between completed attacker waves.
-- Attacker pressure measurement lives in attacker_pressure.lua.

ConquestAttackerWaveOff = ConquestAttackerWaveOff or {}

-- Stores the bot-force snapshot taken before an attacker wave starts buying.
function ConquestAttackerWaveOff.CapturePreWaveSnapshot()
	ConquestAttackerPressure.CapturePreWaveSnapshot()
end

-- Stores the bot-force snapshot taken after an attacker wave finishes buying.
function ConquestAttackerWaveOff.CapturePostWaveSnapshot()
	ConquestAttackerPressure.CapturePostWaveSnapshot()
end

-- Builds current-vs-post-wave pressure details for attacker wave-off decisions.
function ConquestAttackerWaveOff.GetCurrentPressureDetails()
	return ConquestAttackerPressure.GetCurrentSnapshot()
end

-- Rolls small +/- timing variance so wave release timing is not perfectly predictable.
local function RollRandomVarianceSeconds()
	local variance = ConquestConfig.AttackerDynamicWaveOff.RandomVarianceSeconds or 0

	if variance <= 0 then
		return 0
	end

	return math.random(-variance, variance)
end

-- Returns the one random variance roll assigned to the current wave-off window.
local function GetWaveOffVarianceSeconds()
	if not ConquestState.attackerWaveOffVarianceSeconds then
		ConquestState.attackerWaveOffVarianceSeconds = 0
	end

	return ConquestState.attackerWaveOffVarianceSeconds
end

-- Calculates the target wave-off time from current pressure details.
function ConquestAttackerWaveOff.GetTargetWaveOffSeconds(details)
	local config = ConquestConfig.AttackerDynamicWaveOff

	if not details then
		return config.ForceReleaseSeconds
	end

	local attacker = details.attacker
	local objective = details.objective

	local attackerStateSeconds =
		config.WaveOffSecondsByAttackerState[attacker.pressureLevel]
		or config.WaveOffSecondsByAttackerState.retained

	local objectiveDelta =
		config.ObjectiveProgressSecondsDelta[objective.progressTag]
		or 0

	return attackerStateSeconds
		+ objectiveDelta
		+ GetWaveOffVarianceSeconds()
end

local function GetFixedCooldown(seconds, shouldHoldWave)
	local milliseconds = seconds * 1000

	return milliseconds, milliseconds, shouldHoldWave
end

local function IsFirstWaveOffCheck()
	return ConquestState.attackerWaveOffElapsedSeconds <= 0
end

local function ScheduleFirstWaveOffCheck()
	local config = ConquestConfig.AttackerDynamicWaveOff

	ConquestState.attackerWaveOffElapsedSeconds = config.FirstCheckSeconds
	ConquestState.attackerWaveOffVarianceSeconds = RollRandomVarianceSeconds()

	if printDebug then
		print(
			"Print: attacker wave-off first check scheduled",
			"elapsed=", ConquestState.attackerWaveOffElapsedSeconds,
			"variance=", ConquestState.attackerWaveOffVarianceSeconds
		)
	end

	return GetFixedCooldown(config.FirstCheckSeconds, true)
end

local function BuildWaveOffContext()
	local config = ConquestConfig.AttackerDynamicWaveOff
	local details = ConquestAttackerWaveOff.GetCurrentPressureDetails()
	local targetWaveOffSeconds = ConquestAttackerWaveOff.GetTargetWaveOffSeconds(details)

	ConquestState.attackerWaveOffTargetSeconds = targetWaveOffSeconds
	ConquestAttackerWaveOff.PrintCurrentPressureDetails(details, targetWaveOffSeconds)

	return {
		config = config,
		details = details,
		targetWaveOffSeconds = targetWaveOffSeconds,
	}
end

local function ShouldForceRelease(context)
	return ConquestState.attackerWaveOffElapsedSeconds >= context.config.ForceReleaseSeconds
end

local function ShouldReleaseByTarget(context)
	return ConquestState.attackerWaveOffElapsedSeconds >= context.targetWaveOffSeconds
end

local function ReleaseWaveOff(reason, context)
	ConquestState.attackerWaveOffReleaseReady = true

	if printDebug then
		if reason == "force release" then
			print(
				"Print: attacker wave-off force release",
				"elapsed=", ConquestState.attackerWaveOffElapsedSeconds,
				"forceRelease=", context.config.ForceReleaseSeconds
			)
		else
			print(
				"Print: attacker wave-off target reached",
				"elapsed=", ConquestState.attackerWaveOffElapsedSeconds,
				"target=", context.targetWaveOffSeconds
			)
		end
	end

	return GetFixedCooldown(1, false)
end

local function HoldWaveOff(context)
	local elapsedBeforeHold = ConquestState.attackerWaveOffElapsedSeconds
	local remainingSeconds = context.targetWaveOffSeconds - elapsedBeforeHold
	local nextCheckSeconds = math.min(context.config.RepeatPollIntervalSeconds, remainingSeconds)

	ConquestState.attackerWaveOffElapsedSeconds =
		ConquestState.attackerWaveOffElapsedSeconds + nextCheckSeconds

	if printDebug then
		print(
			"Print: attacker wave-off holding",
			"elapsed=", elapsedBeforeHold,
			"nextElapsed=", ConquestState.attackerWaveOffElapsedSeconds,
			"target=", context.targetWaveOffSeconds,
			"nextCheck=", nextCheckSeconds
		)
	end

	return GetFixedCooldown(nextCheckSeconds, true)
end

-- Returns the next attacker wave-off cooldown range and whether the next wave should stay held.
function ConquestAttackerWaveOff.GetNextCooldown()
	if IsFirstWaveOffCheck() then
		return ScheduleFirstWaveOffCheck()
	end

	local context = BuildWaveOffContext()

	if ShouldForceRelease(context) then
		return ReleaseWaveOff("force release", context)
	end

	if ShouldReleaseByTarget(context) then
		return ReleaseWaveOff("target reached", context)
	end

	return HoldWaveOff(context)
end

-- Returns true when unit selection should defer to the wave-off controller instead of selecting a unit.
function ConquestAttackerWaveOff.ShouldDeferPurchaseForWaveOff()
	return not ConquestState.botDefender
		and not ConquestState.attackerWavesFinished
		and not ConquestState.waveSpawnActive
		and not ConquestState.purchasePhase
end

-- Resets attacker wave-off timing state before the next attacker wave starts.
function ConquestAttackerWaveOff.ResetCooldown()
	ConquestState.attackerWaveOffElapsedSeconds = 0
	ConquestState.attackerWaveOffTargetSeconds = 0
	ConquestState.attackerWaveOffVarianceSeconds = 0
	ConquestState.attackerWaveOffPlayerPeakComposition = nil
	ConquestState.attackerWaveOffReleaseReady = false
end

-- Prints current wave-off pressure details when printDebug is enabled.
function ConquestAttackerWaveOff.PrintCurrentPressureDetails(details, targetWaveOffSeconds)
	if not printDebug or not details then
		return
	end

	local attacker = details.attacker
	local player = details.player
	local objective = details.objective

	targetWaveOffSeconds = targetWaveOffSeconds or ConquestAttackerWaveOff.GetTargetWaveOffSeconds(details)

	print(
		"Print: attacker wave-off pressure",
		"attackerPressure=", attacker.pressureLevel,
		"objective=", objective.progressTag,
		"targetWaveOffSeconds=", targetWaveOffSeconds,
		"baseline=", attacker.baselineSource,
		"waveInfantryRatioRaw=", attacker.waveInfantryRatioRaw,
		"waveInfantryRatio=", attacker.waveInfantryRatio,
		"wavePressureScore=", attacker.wavePressureScore,
		"wavePressureBaselineScore=", attacker.wavePressureBaselineScore,
		"wavePressureRatioRaw=", attacker.wavePressureRatioRaw,
		"wavePressureRatio=", attacker.wavePressureRatio,
		"componentLossTags=", ConquestAttackerPressure.FormatTags(attacker.componentLossTags),
		"playerDefenseTags=", ConquestAttackerPressure.FormatTags(player.defenseTags),
		"playerInfantryRetention=", player.infantryRetention,
		"playerPressureScore=", player.pressureScore,
		"playerPeakPressureScore=", player.peakPressureScore,
		"playerPressureRetention=", player.pressureRetention
	)
end
