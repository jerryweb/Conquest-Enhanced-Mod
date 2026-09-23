-- =========================================================
-- PURCHASE FLOW
-- =========================================================
-- Unit availability filtering and selection hook.

local PHASE_DEFENDER_OPENING = "defender_opening"

local PLACEMENT_BODY = "body"
local PLACEMENT_MG_SUPPORT = "mg_support"
local PLACEMENT_GUN_SUPPORT = "gun_support"
local PLACEMENT_MOBILE_SUPPORT = "mobile_support"
local PLACEMENT_FALLBACK = "fallback"

local PLATFORM_INFANTRY_SQUAD = "InfantrySquad"
local PLATFORM_INFANTRY_SINGLE = "InfantrySingle"
local PLATFORM_CANNON = "Cannon"
local PLATFORM_VEHICLE = "Vehicle"
local PLATFORM_TANK = "Tank"
local PLATFORM_SPG = "SPG"

-- SpawnAt receives an index into the bot's available spawn-side mappoint list.
-- Defender-opening garrisons intentionally skip index 1 on 2- and 3-flag maps
-- Conquest layouts use indexes 0/2 and 0/2/3 for flag coverage.
local GARRISON_SPAWN_SEQUENCE_BY_FLAG_COUNT = {
	[1] = { 0 },
	[2] = { 0, 2 },
	[3] = { 0, 2, 3 },
	[4] = { 0, 1, 2, 3 },
}

-- Zero-based offsets into the active garrison spawn sequence. These stagger
-- placement classes so support units do not all open on the same flag slot.
-- Each class still rotates across every active flag slot.
local GARRISON_PLACEMENT_CLASS_SEQUENCE_OFFSET = {
	[PLACEMENT_BODY] = 0,
	[PLACEMENT_MG_SUPPORT] = 0,
	[PLACEMENT_GUN_SUPPORT] = 1,
	[PLACEMENT_MOBILE_SUPPORT] = 2,
	[PLACEMENT_FALLBACK] = 0,
}

local function GetGarrisonPlacementClass(unit)
	local platform = ConquestPurchaseScoring.GetPlatformLabel(unit)

	if platform == PLATFORM_INFANTRY_SQUAD or platform == PLATFORM_INFANTRY_SINGLE then
		return PLACEMENT_BODY
	end

	if platform == PLATFORM_TANK or platform == PLATFORM_SPG or platform == PLATFORM_VEHICLE then
		return PLACEMENT_MOBILE_SUPPORT
	end

	if platform == PLATFORM_CANNON then
		if ConquestPurchaseScoring.UnitHasTag(unit, "MachineGun")
			or ConquestPurchaseScoring.UnitHasTag(unit, "MG") then
			return PLACEMENT_MG_SUPPORT
		end

		return PLACEMENT_GUN_SUPPORT
	end

	return PLACEMENT_FALLBACK
end

local function GetGarrisonSpawnSequence()
	local flagCount = ConquestState.defenderOpeningFlagCount or 1
	return GARRISON_SPAWN_SEQUENCE_BY_FLAG_COUNT[flagCount] or GARRISON_SPAWN_SEQUENCE_BY_FLAG_COUNT[4]
end

local function GetGarrisonSpawnPointIndex(placementClass)
	local sequence = GetGarrisonSpawnSequence()
	local className = placementClass or PLACEMENT_FALLBACK
	local counters = ConquestState.garrisonSpawnPointIndexByPlacementClass
	local classProgress = counters[className] or 0
	local classOffset = GARRISON_PLACEMENT_CLASS_SEQUENCE_OFFSET[className] or 0
	local sequenceIndex = ((classOffset + classProgress) % #sequence) + 1

	return sequence[sequenceIndex]
end

local function CommitGarrisonSpawnPointIndex(placementClass)
	local className = placementClass or PLACEMENT_FALLBACK
	local counters = ConquestState.garrisonSpawnPointIndexByPlacementClass
	counters[className] = (counters[className] or 0) + 1
end

-- Hook used by utility.lua to spawn the selected unit.
function GameModeSpawnUnit(unit, maxSquadSize)
	local isGarrisonSpawn = ConquestState.purchasePhase == PHASE_DEFENDER_OPENING
	local spawnPointIndex = ConquestState.spawnPointIndex or 0
	local placementClass

	if isGarrisonSpawn then
		local selectedUnit = ConquestState.pendingPurchaseUnit
		if type(selectedUnit) ~= "table" and type(unit) == "table" then
			selectedUnit = unit
		end

		placementClass = GetGarrisonPlacementClass(selectedUnit)
		spawnPointIndex = GetGarrisonSpawnPointIndex(placementClass)
	end

	if not BotApi.Commands:SpawnAt(unit, maxSquadSize, spawnPointIndex) then
		return false
	end

	if isGarrisonSpawn then
		CommitGarrisonSpawnPointIndex(placementClass)
	else
		ConquestState.spawnPointIndex = spawnPointIndex + 1
	end

	return true
end

-- Hook used by utility.lua for the maximum wait while trying to buy a unit.
function GetCurrentSpawnWaitTime()
	return ConquestConfig.UnitSpawnWaitTime
end

-- Hook used by utility.lua to choose the next unit the bot should buy.
function GetUnitToSpawn(units)
	if ConquestBattleResult.IsWinnerDecided() then
		return nil
	end

	if ConquestAttackerWaveOff.ShouldDeferPurchaseForWaveOff() then
		SetSpawnCooldownTimer()
		return nil
	end

	if ConquestAttackerFailure.ShouldDeferPurchaseForFailureCheck() then
		SetSpawnCooldownTimer()
		return nil
	end

	if not units then
		return nil
	end

	if not ConquestWaves.CanPurchaseUnit() then
		return nil
	end

	local unitsToSpawn = {}

	if printDebug then
		print("Player#" .. BotApi.Instance.playerId .. " Units")
	end

	for _, unit in pairs(units) do
		if BotApi.Commands:IsUnitAvailable(unit.unit) then
			table.insert(unitsToSpawn, unit)
		end
	end

	if #unitsToSpawn == 0 then
		return nil
	end

	local selectedUnit = ConquestPurchaseScoring.SelectUnitForCurrentPlan(unitsToSpawn)
	ConquestState.pendingPurchaseUnit = selectedUnit
	return selectedUnit
end
