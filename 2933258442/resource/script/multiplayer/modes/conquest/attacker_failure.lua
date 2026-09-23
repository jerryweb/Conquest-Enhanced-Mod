-- =========================================================
-- ATTACKER FAILURE WATCHER
-- =========================================================
-- Watches the battle after the final attacker wave has finished buying and asks repeatedly whether the attack can still take an objective.
-- The attacker's remaining force is scored into assault strength, the player's into a defense score that sets the bar it is compared against.
-- When the attack is finished, sets the configured mission var so mission script can order attacker retreat.

ConquestAttackerFailure = ConquestAttackerFailure or {}

local SNAPSHOT_QUERY_INTERVAL_SECONDS = 5

local OBJECTIVE_PROGRESS_NONE = "no_objective_progress"
local OBJECTIVE_PROGRESS_CONTESTED = "objective_contested"

local THRESHOLD_GROUP_NO_PROGRESS = "NoProgress"
local THRESHOLD_GROUP_PARTIAL_PROGRESS = "PartialProgress"
local THRESHOLD_GROUP_NEAR_VICTORY = "NearVictory"

-- Arms the post-final-wave failure watcher.
function ConquestAttackerFailure.Arm()
	ConquestState.attackerFailureArmed = true
	ConquestState.attackerFailureElapsedSeconds = 0
	ConquestState.attackerFailureCheckCount = 0

	if printDebug then
		print("Print: attacker failure watcher armed")
	end
end

-- Returns true when the purchase hook should only advance final-failure watcher timing.
function ConquestAttackerFailure.ShouldDeferPurchaseForFailureCheck()
	return not ConquestState.botDefender
		and ConquestState.attackerWavesFinished
		and ConquestState.attackerFailureArmed
end

-- Returns the objective-progress threshold group for failure evaluation.
local function GetThresholdGroup(snapshot)
	local objective = snapshot.objective
	local totalFlags = objective.totalFlags or 0
	local attackerOwnedFlags = objective.attackerOwnedFlags or 0
	local neutralFlags = objective.neutralFlags or 0

	if objective.progressTag == OBJECTIVE_PROGRESS_NONE then
		return THRESHOLD_GROUP_NO_PROGRESS
	end

	if objective.progressTag == OBJECTIVE_PROGRESS_CONTESTED then
		return THRESHOLD_GROUP_PARTIAL_PROGRESS
	end

	if totalFlags > 0 and attackerOwnedFlags >= totalFlags - 1 then
		return THRESHOLD_GROUP_NEAR_VICTORY
	end

	if attackerOwnedFlags > 0 or neutralFlags > 0 then
		return THRESHOLD_GROUP_PARTIAL_PROGRESS
	end

	return THRESHOLD_GROUP_NO_PROGRESS
end

local function GetCombinedHeavyArmor(composition)
	return (composition.HeavyArmor or 0) + (composition.SuperHeavyArmor or 0)
end

-- Returns a composition's total under a weight table, in infantry-equivalents.
local function ScoreComposition(composition, weights)
	local c = composition or {}
	local total = 0

	for category, weight in pairs(weights) do
		total = total + ((c[category] or 0) * weight)
	end

	return total
end

-- Returns the weighted categories in stable order so a debug line can be compared across checks and replayed later.
local function GetSortedCategories(weights)
	local categories = {}

	for category, _ in pairs(weights) do
		table.insert(categories, category)
	end

	table.sort(categories)

	return categories
end

-- Returns what the attacker can still bring to bear on taking ground.
local function GetAssaultStrength(snapshot)
	return ScoreComposition(snapshot.attacker.currentComposition, ConquestConfig.AssaultWeights)
end

-- Returns the defending force the bar is scaled against.
local function GetPlayerDefense(snapshot)
	return ScoreComposition(snapshot.player.currentComposition, ConquestConfig.PlayerDefenseWeights)
end

-- Returns whether the attacker still has anything that can reliably capture an objective.
local function HasAssaultCapability(snapshot)
	local attacker = snapshot.attacker.currentComposition

	return (attacker.Infantry or 0) > 0
		or (attacker.Armor or 0) > 0
		or GetCombinedHeavyArmor(attacker) > 0
end

-- Returns whether the player still has a defense worth retreating from.
local function HasPlayerDefense(playerDefense)
	return playerDefense > 0
end

-- Returns the assault-strength bar for the current progress group, clamped to the group's configured range.
local function GetAssaultBar(playerDefense, threshold)
	local bar = playerDefense * threshold.PlayerDefenseRatio

	if bar < threshold.MinBar then
		return threshold.MinBar
	end

	if bar > threshold.MaxBar then
		return threshold.MaxBar
	end

	return bar
end

-- Evaluates attack viability for one snapshot against the current progress group's bar, with the capability floor in front.
function ConquestAttackerFailure.EvaluateSnapshot(snapshot)
	local thresholdGroup = GetThresholdGroup(snapshot)
	local threshold = ConquestConfig.AttackerFailure[thresholdGroup]

	local assaultStrength = GetAssaultStrength(snapshot)
	local playerDefense = GetPlayerDefense(snapshot)
	local bar = GetAssaultBar(playerDefense, threshold)

	local hasAssaultCapability = HasAssaultCapability(snapshot)
	local hasPlayerDefense = HasPlayerDefense(playerDefense)

	local attackOver
	if not hasAssaultCapability then
		-- Nothing left that can take a flag, so there is no defense to judge it against.
		attackOver = true
	else
		attackOver = assaultStrength <= bar and hasPlayerDefense
	end

	return {
		thresholdGroup = thresholdGroup,
		threshold = threshold,
		assaultStrength = assaultStrength,
		playerDefense = playerDefense,
		bar = bar,
		hasAssaultCapability = hasAssaultCapability,
		hasPlayerDefense = hasPlayerDefense,
		attackOver = attackOver,
	}
end

local function PrintNoSnapshotDebug()
	if printDebug then
		print(
			"Print: attacker failure check",
			"check=", ConquestState.attackerFailureCheckCount,
			"result=", "no_snapshot"
		)
	end
end

-- Formats every weighted component and its contribution so a logged check can be reconstructed exactly.
-- Calibration depends on this staying complete.
local function FormatWeightedComponents(composition, weights)
	local c = composition or {}
	local parts = {}

	for _, category in ipairs(GetSortedCategories(weights)) do
		local count = c[category] or 0
		local weight = weights[category]

		table.insert(parts, category .. "=" .. tostring(count) .. "x" .. tostring(weight) .. "=" .. tostring(count * weight))
	end

	return table.concat(parts, " ")
end

local function PrintAttackerFailureCheckDebug(snapshot, evaluation)
	print(
		"Print: attacker failure check",
		"check=", ConquestState.attackerFailureCheckCount,
		"group=", evaluation.thresholdGroup,
		"wouldEndBattle=", evaluation.attackOver,
		"assaultStrength=", evaluation.assaultStrength,
		"bar=", evaluation.bar,
		"playerDefense=", evaluation.playerDefense,
		"playerDefenseRatio=", evaluation.threshold.PlayerDefenseRatio,
		"minBar=", evaluation.threshold.MinBar,
		"maxBar=", evaluation.threshold.MaxBar,
		"hasAssaultCapability=", evaluation.hasAssaultCapability,
		"hasPlayerDefense=", evaluation.hasPlayerDefense,
		"objective=", snapshot.objective.progressTag,
		"attackerOwnedFlags=", snapshot.objective.attackerOwnedFlags,
		"totalFlags=", snapshot.objective.totalFlags,
		"assault=[", FormatWeightedComponents(snapshot.attacker.currentComposition, ConquestConfig.AssaultWeights), "]",
		"defense=[", FormatWeightedComponents(snapshot.player.currentComposition, ConquestConfig.PlayerDefenseWeights), "]"
	)
end

local function GetFixedCooldown(seconds)
	local milliseconds = seconds * 1000

	return milliseconds, milliseconds
end

local function GetCompletedPurchaseIdleCooldown()
	return ConquestConfig.CompletedPurchaseIdleTime.Min, ConquestConfig.CompletedPurchaseIdleTime.Max
end

-- Requests attacker retreat through mission script and stops the watcher.
local function CompleteAttackerFailure()
	ConquestBattleResult.RequestBotRetreat()
	ConquestState.attackerFailureArmed = false
end

-- Runs one attacker-failure check and requests attacker retreat when the threshold passes.
function ConquestAttackerFailure.Check()
	local snapshot = ConquestAttackerPressure.GetCurrentSnapshot(SNAPSHOT_QUERY_INTERVAL_SECONDS)

	ConquestState.attackerFailureCheckCount = ConquestState.attackerFailureCheckCount + 1

	if not snapshot then
		PrintNoSnapshotDebug()
		return false
	end

	local evaluation = ConquestAttackerFailure.EvaluateSnapshot(snapshot)

	if printDebug then
		PrintAttackerFailureCheckDebug(snapshot, evaluation)
	end

	if evaluation.attackOver then
		CompleteAttackerFailure()
	end

	return evaluation.attackOver
end

-- Returns the next post-final-wave cooldown used to drive failure checks.
function ConquestAttackerFailure.GetNextCooldown()
	local config = ConquestConfig.AttackerFailure

	if not ConquestState.attackerFailureArmed then
		return GetCompletedPurchaseIdleCooldown()
	end

	if ConquestState.attackerFailureElapsedSeconds <= 0 then
		ConquestState.attackerFailureElapsedSeconds = config.InitialCheckDelaySeconds

		if printDebug then
			print(
				"Print: attacker failure first check scheduled",
				"elapsed=", ConquestState.attackerFailureElapsedSeconds
			)
		end

		return GetFixedCooldown(config.InitialCheckDelaySeconds)
	end

	ConquestAttackerFailure.Check()

	if not ConquestState.attackerFailureArmed then
		return GetCompletedPurchaseIdleCooldown()
	end

	ConquestState.attackerFailureElapsedSeconds =
		ConquestState.attackerFailureElapsedSeconds + config.RepeatCheckIntervalSeconds

	return GetFixedCooldown(config.RepeatCheckIntervalSeconds)
end
