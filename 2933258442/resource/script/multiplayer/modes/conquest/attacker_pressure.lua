-- =========================================================
-- ATTACKER PRESSURE SNAPSHOT
-- =========================================================
-- Measures current attacker pressure, player defense state, and objective progress.
-- Wave-off timing and final attacker-failure detection consume this snapshot
-- instead of duplicating scene-query and flag-measurement logic.

ConquestAttackerPressure = ConquestAttackerPressure or {}

local SCENE_MEMORY_ATTACKER_PRE_WAVE = "attacker_pre_wave"
local SCENE_MEMORY_ATTACKER_POST_WAVE = "attacker_post_wave"
local SCENE_MEMORY_ATTACKER_PRESSURE_CURRENT = "attacker_pressure_current"

local OBJECTIVE_PROGRESS_NO_FLAGS = "no_flags"
local OBJECTIVE_PROGRESS_ALL_TAKEN = "all_objectives_taken"
local OBJECTIVE_PROGRESS_ATTACKER_PROGRESS = "objective_progress"
local OBJECTIVE_PROGRESS_CONTESTED = "objective_contested"
local OBJECTIVE_PROGRESS_NONE = "no_objective_progress"

local ATTACKER_BASELINE_SOURCE_WAVE_ADDED = "wave_added"

-- Composition fields used by attacker pressure measurement.
local CompositionFields = {
	"Infantry",
	"Crew",
	"ATInfantry",
	"LightArmor",
	"MediumArmor",
	"Armor",
	"HeavyArmor",
	"SuperHeavyArmor",
	"MachineGun",
	"AutoCannon",
	"LightAT",
	"ATGun",
	"Flame",
	"MediumHE",
	"LargeHE",
	"HE",
	"DirectFireThreat",
	"Engineer",
	"AmmoSupply",
}

-- Returns current scene compositions for the bot attacker and player side.
local function GetCompositions(queryIntervalSeconds)
	local sceneSnapshot = ConquestScene.QueryCompositionSnapshot(queryIntervalSeconds)
	local compositions = sceneSnapshot.compositions
	local botComposition = compositions[BotApi.Instance.playerId] or ConquestScene.CreateEmptyComposition()
	local playerComposition = compositions[BotApi.Conquest.FirstPlayerId] or ConquestScene.CreateEmptyComposition()

	return botComposition, playerComposition
end

-- Returns a non-negative composition delta.
local function GetCompositionDelta(afterComposition, beforeComposition)
	local delta = ConquestScene.CreateEmptyComposition()

	for _, fieldName in ipairs(CompositionFields) do
		delta[fieldName] = math.max((afterComposition[fieldName] or 0) - (beforeComposition[fieldName] or 0), 0)
	end

	return delta
end

-- Updates and returns the peak player defense composition for this wave-off window.
local function UpdatePlayerPeakComposition(currentComposition)
	local peakComposition = ConquestState.attackerWaveOffPlayerPeakComposition

	if not peakComposition then
		peakComposition = ConquestScene.CreateEmptyComposition()
		ConquestState.attackerWaveOffPlayerPeakComposition = peakComposition
	end

	for _, fieldName in ipairs(CompositionFields) do
		peakComposition[fieldName] = math.max(peakComposition[fieldName] or 0, currentComposition[fieldName] or 0)
	end

	return peakComposition
end

-- Returns a high-level pressure level for the attacker force.
local function GetAttackerPressureLevel(pressureRatio)
	return ConquestCombatPressure.GetLevelFromRatio(pressureRatio, ConquestConfig.AttackerDynamicWaveOff)
end

local function AddRatioTag(tags, tagPrefix, currentValue, baselineValue)
	if not baselineValue or baselineValue <= 0 then
		return
	end

	local config = ConquestConfig.AttackerDynamicWaveOff
	local ratio = ConquestCombatPressure.ClampRatio(ConquestCombatPressure.GetRatio(currentValue, baselineValue))

	if ratio < config.DegradedRatio then
		table.insert(tags, tagPrefix .. "_degraded")
	elseif ratio < config.RetainedRatio then
		table.insert(tags, tagPrefix .. "_reduced")
	else
		table.insert(tags, tagPrefix .. "_retained")
	end
end

-- Builds loss tags for major attacker force components.
local function BuildComponentLossTags(currentComposition, baselineComposition, pressureRatio)
	local tags = {}

	AddRatioTag(tags, "infantry", currentComposition.Infantry, baselineComposition.Infantry)
	AddRatioTag(tags, "armor", currentComposition.Armor, baselineComposition.Armor)
	AddRatioTag(tags, "heavy_armor", currentComposition.HeavyArmor, baselineComposition.HeavyArmor)
	AddRatioTag(tags, "super_heavy_armor", currentComposition.SuperHeavyArmor, baselineComposition.SuperHeavyArmor)
	AddRatioTag(tags, "machine_gun", currentComposition.MachineGun, baselineComposition.MachineGun)
	AddRatioTag(tags, "autocannon", currentComposition.AutoCannon, baselineComposition.AutoCannon)
	AddRatioTag(tags, "light_at", currentComposition.LightAT, baselineComposition.LightAT)
	AddRatioTag(tags, "at_gun", currentComposition.ATGun, baselineComposition.ATGun)
	AddRatioTag(tags, "flame", currentComposition.Flame, baselineComposition.Flame)
	AddRatioTag(tags, "medium_he", currentComposition.MediumHE, baselineComposition.MediumHE)
	AddRatioTag(tags, "large_he", currentComposition.LargeHE, baselineComposition.LargeHE)

	AddRatioTag(tags, "combat_pressure", pressureRatio, 1)

	return tags
end

-- Builds named details describing the current player defense composition and retention from peak.
local function BuildPlayerDefenseInfo(playerComposition, playerPeakComposition)
	local config = ConquestConfig.AttackerDynamicWaveOff
	local tags = {}

	local infantryRetention = ConquestCombatPressure.GetRatio(playerComposition.Infantry, playerPeakComposition.Infantry)
	local currentPressureScore = ConquestCombatPressure.CalculateScore(playerComposition)
	local peakPressureScore = ConquestCombatPressure.CalculateScore(playerPeakComposition)
	local pressureRetention = ConquestCombatPressure.GetRatio(currentPressureScore, peakPressureScore)

	if playerComposition.Infantry > 0 then
		table.insert(tags, "player_has_infantry")
	else
		table.insert(tags, "player_no_infantry")
	end

	if playerComposition.ATInfantry > 0
		or playerComposition.LightAT > 0
		or playerComposition.ATGun > 0
		or playerComposition.DirectFireThreat > 0
	then
		table.insert(tags, "player_has_anti_armor")
	else
		table.insert(tags, "player_low_anti_armor")
	end

	if playerComposition.Armor > 0 then
		table.insert(tags, "player_has_armor")
	else
		table.insert(tags, "player_no_armor")
	end

	if playerComposition.HE > 0 then
		table.insert(tags, "player_has_he")
	end

	if currentPressureScore <= 0 then
		table.insert(tags, "player_force_empty")
	elseif infantryRetention < config.DegradedRatio and pressureRetention < config.DegradedRatio then
		table.insert(tags, "player_defense_degraded")
	elseif infantryRetention < config.RetainedRatio or pressureRetention < config.RetainedRatio then
		table.insert(tags, "player_defense_reduced")
	else
		table.insert(tags, "player_defense_retained")
	end

	return {
		tags = tags,
		infantryRetention = infantryRetention,
		pressureRetention = pressureRetention,
		currentPressureScore = currentPressureScore,
		peakPressureScore = peakPressureScore,
	}
end

-- Returns attacker objective progress based on current flag ownership.
local function GetObjectiveProgressInfo()
	local totalFlags = 0
	local attackerOwnedFlags = 0
	local neutralFlags = 0

	for _, flag in pairs(BotApi.Scene.Flags or {}) do
		totalFlags = totalFlags + 1

		if flag.occupant == team then
			attackerOwnedFlags = attackerOwnedFlags + 1
		elseif flag.occupant ~= enemyTeam then
			neutralFlags = neutralFlags + 1
		end
	end

	local progressTag = OBJECTIVE_PROGRESS_NONE

	if totalFlags <= 0 then
		progressTag = OBJECTIVE_PROGRESS_NO_FLAGS
	elseif attackerOwnedFlags >= totalFlags then
		progressTag = OBJECTIVE_PROGRESS_ALL_TAKEN
	elseif attackerOwnedFlags > 0 then
		progressTag = OBJECTIVE_PROGRESS_ATTACKER_PROGRESS
	elseif neutralFlags > 0 then
		progressTag = OBJECTIVE_PROGRESS_CONTESTED
	end

	return {
		progressTag = progressTag,
		totalFlags = totalFlags,
		attackerOwnedFlags = attackerOwnedFlags,
		neutralFlags = neutralFlags,
	}
end

local function GetValidPostWaveBaseline()
	local baseline = ConquestState.attackerPostWaveSnapshot

	if not baseline or not baseline.waveAddedBotComposition then
		return nil
	end

	return baseline
end

local function QueryCurrentCompositions(queryIntervalSeconds)
	local config = ConquestConfig.AttackerDynamicWaveOff
	local intervalSeconds = queryIntervalSeconds or config.QueryIntervalSeconds
	local botComposition, playerComposition = GetCompositions(intervalSeconds)

	ConquestSceneMemory.Update(SCENE_MEMORY_ATTACKER_PRESSURE_CURRENT, botComposition, playerComposition, false)

	return botComposition, playerComposition
end

local function BuildAttackerSnapshot(baseline, currentBotComposition)
	local waveAddedBotComposition = baseline.waveAddedBotComposition
	local waveInfantryRatioRaw = ConquestCombatPressure.GetRatio(currentBotComposition.Infantry, waveAddedBotComposition.Infantry)
	local waveInfantryRatio = ConquestCombatPressure.ClampRatio(waveInfantryRatioRaw)
	local currentPressureScore = ConquestCombatPressure.CalculateScore(currentBotComposition)
	local baselinePressureScore = ConquestCombatPressure.CalculateScore(waveAddedBotComposition)
	local wavePressureRatioRaw = ConquestCombatPressure.GetRatio(currentPressureScore, baselinePressureScore)
	local wavePressureRatio = ConquestCombatPressure.ClampRatio(wavePressureRatioRaw)
	local attackerPressureLevel = GetAttackerPressureLevel(wavePressureRatio)
	local componentLossTags = BuildComponentLossTags(currentBotComposition, waveAddedBotComposition, wavePressureRatio)

	return {
		pressureLevel = attackerPressureLevel,
		baselineSource = ATTACKER_BASELINE_SOURCE_WAVE_ADDED,

		waveInfantryRatioRaw = waveInfantryRatioRaw,
		wavePressureScore = currentPressureScore,
		wavePressureBaselineScore = baselinePressureScore,
		wavePressureRatioRaw = wavePressureRatioRaw,
		waveInfantryRatio = waveInfantryRatio,
		wavePressureRatio = wavePressureRatio,

		componentLossTags = componentLossTags,

		preWaveComposition = baseline.preBotComposition,
		postWaveComposition = baseline.postBotComposition,
		waveAddedComposition = waveAddedBotComposition,
		currentComposition = currentBotComposition,
	}
end

local function BuildPlayerSnapshot(baseline, currentPlayerComposition)
	local playerPeakComposition = UpdatePlayerPeakComposition(currentPlayerComposition)
	local defenseInfo = BuildPlayerDefenseInfo(currentPlayerComposition, playerPeakComposition)

	return {
		defenseTags = defenseInfo.tags,
		infantryRetention = defenseInfo.infantryRetention,
		pressureRetention = defenseInfo.pressureRetention,
		pressureScore = defenseInfo.currentPressureScore,
		peakPressureScore = defenseInfo.peakPressureScore,

		preWaveComposition = baseline.prePlayerComposition,
		postWaveComposition = baseline.postPlayerComposition,
		peakComposition = playerPeakComposition,
		currentComposition = currentPlayerComposition,
	}
end

local function BuildObjectiveSnapshot()
	return GetObjectiveProgressInfo()
end

local function PrintPreWaveSnapshotDebug(waveNumber, botComposition, playerComposition)
	print(
		"Print: attacker pre-wave snapshot",
		"wave=", waveNumber,
		"bot=", ConquestScene.FormatCompositionSummary(botComposition),
		"player=", ConquestScene.FormatCompositionSummary(playerComposition)
	)
end

local function PrintPostWaveSnapshotDebug(completedWaveNumber, preBotComposition, postBotComposition, waveAddedBotComposition, postPlayerComposition)
	print(
		"Print: attacker post-wave snapshot",
		"completedWave=", completedWaveNumber,
		"preBot=", ConquestScene.FormatCompositionSummary(preBotComposition),
		"postBot=", ConquestScene.FormatCompositionSummary(postBotComposition),
		"waveAddedBot=", ConquestScene.FormatCompositionSummary(waveAddedBotComposition),
		"player=", ConquestScene.FormatCompositionSummary(postPlayerComposition)
	)
end

-- Stores the bot-force snapshot taken before an attacker wave starts buying.
function ConquestAttackerPressure.CapturePreWaveSnapshot()
	local botComposition, playerComposition = GetCompositions(0)
	local waveNumber = ConquestState.waveNumber + 1

	ConquestSceneMemory.Update(SCENE_MEMORY_ATTACKER_PRE_WAVE, botComposition, playerComposition, true)

	ConquestState.attackerPreWaveSnapshot = {
		waveNumber = waveNumber,
		botComposition = botComposition,
		playerComposition = playerComposition,
	}

	if printDebug then
		PrintPreWaveSnapshotDebug(waveNumber, botComposition, playerComposition)
	end
end

-- Stores the bot-force snapshot taken after an attacker wave finishes buying.
function ConquestAttackerPressure.CapturePostWaveSnapshot()
	local postBotComposition, postPlayerComposition = GetCompositions(0)
	ConquestSceneMemory.Update(SCENE_MEMORY_ATTACKER_POST_WAVE, postBotComposition, postPlayerComposition, false)

	local preWaveSnapshot = ConquestState.attackerPreWaveSnapshot
	local preBotComposition =
		(preWaveSnapshot and preWaveSnapshot.botComposition)
		or ConquestScene.CreateEmptyComposition()
	local prePlayerComposition =
		(preWaveSnapshot and preWaveSnapshot.playerComposition)
		or ConquestScene.CreateEmptyComposition()
	local waveAddedBotComposition = GetCompositionDelta(postBotComposition, preBotComposition)
	local completedWaveNumber = ConquestState.waveNumber + 1

	ConquestState.attackerPostWaveSnapshot = {
		completedWaveNumber = completedWaveNumber,
		preBotComposition = preBotComposition,
		postBotComposition = postBotComposition,
		waveAddedBotComposition = waveAddedBotComposition,
		prePlayerComposition = prePlayerComposition,
		postPlayerComposition = postPlayerComposition,
	}

	if printDebug then
		PrintPostWaveSnapshotDebug(
			completedWaveNumber,
			preBotComposition,
			postBotComposition,
			waveAddedBotComposition,
			postPlayerComposition
		)
	end
end

-- Builds current pressure details for wave-off and attacker failure checks.
function ConquestAttackerPressure.GetCurrentSnapshot(queryIntervalSeconds)
	local baseline = GetValidPostWaveBaseline()

	if not baseline then
		return nil
	end

	local currentBotComposition, currentPlayerComposition = QueryCurrentCompositions(queryIntervalSeconds)
	local attackerSnapshot = BuildAttackerSnapshot(baseline, currentBotComposition)
	local playerSnapshot = BuildPlayerSnapshot(baseline, currentPlayerComposition)
	local objectiveSnapshot = BuildObjectiveSnapshot()

	return {
		attacker = attackerSnapshot,
		player = playerSnapshot,
		objective = objectiveSnapshot,
	}
end

-- Returns a readable comma-separated tag list.
function ConquestAttackerPressure.FormatTags(tags)
	if not tags or #tags <= 0 then
		return "none"
	end

	return table.concat(tags, ",")
end
