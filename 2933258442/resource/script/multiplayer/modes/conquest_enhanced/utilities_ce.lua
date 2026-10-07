-- =========================================================
-- UTILITIES FILE FOR CONQUEST ENHANCED
-- =========================================================
waveOneGraphOverrideActive = false
local unitBases = {"Cannon", "SPG", "Plane"}
local unitRoles = {"Artillery", "Breakthrough"}
local unitClasses = {"Heavy"}
-- Specific unit names (from roster files like conquest.ger) that should skip the waypoint graph
local exemptUnitNames = {"sdkfz234_4", "hetzer"}
local AIR_DEFENSE_ROLE = "AirDefense"
local ENABLE_WAYPOINT_GRAPH = "enable_waypoint_graph"

-- local ENABLE_SPAWN_A_1_WAYPOINT_GRID = "enable_spawn_a_1_waypoint_grid"
-- local ENABLE_SPAWN_A_2_WAYPOINT_GRID = "enable_spawn_a_2_waypoint_grid"
-- local ENABLE_SPAWN_A_3_WAYPOINT_GRID = "enable_spawn_a_3_waypoint_grid"
-- local ENABLE_SPAWN_A_4_WAYPOINT_GRID = "enable_spawn_a_4_waypoint_grid"

-- local ENABLE_SPAWN_B_1_WAYPOINT_GRID = "enable_spawn_b_1_waypoint_grid"
-- local ENABLE_SPAWN_B_2_WAYPOINT_GRID = "enable_spawn_b_2_waypoint_grid"
-- local ENABLE_SPAWN_B_3_WAYPOINT_GRID = "enable_spawn_b_3_waypoint_grid"
-- local ENABLE_SPAWN_B_4_WAYPOINT_GRID = "enable_spawn_b_4_waypoint_grid"


-- Helper function to check if a table contains a specific value
local function contains(tbl, target)
	if not tbl then return false end
	for _, val in ipairs(tbl) do
		if val == target then return true end
	end
	return false
end

-- Helper function to check if a table contains any value from a target list.
local function containsAny(tbl, targets)
	if not tbl then return false end
	for _, target in ipairs(targets) do
		if contains(tbl, target) then return true end
	end
	return false
end

function ConquestContext.SetCEVarsInMissionScript()
	CEWeather.Start()
	local enableWaypointGraph = ConquestState.botDefender and 1 or 0
	ConquestContext.SetEnableWaypointGraph(enableWaypointGraph)

	if printDebug then
		print("enable spawn waypoint grid = ", enableWaypointGraph)
	end
end

function ConquestContext.SetEnableWaypointGraph(enableWaypointGraphVar)
	BotApi.Scene:SetVar(ENABLE_WAYPOINT_GRAPH, enableWaypointGraphVar)
	if printDebug then
		print("enable spawn waypoint grid = ", enableWaypointGraphVar)
	end
end

-- Toggles the wave-1 override: when active, every spawning squad skips the
-- waypoint graph regardless of unit type.
function SetWaveOneGraphOverride(isActive)
	waveOneGraphOverrideActive = isActive

	-- Consistently pass 1 or 0 integer flag to BotApi
	local enableWaypointGraph = isActive and 0 or 1
	ConquestContext.SetEnableWaypointGraph(enableWaypointGraph)
end

-- Arms the wave-1 override when the first attacker wave spawns, and clears it
-- once wave 2 starts.
function UpdateWaveOneGraphOverride()
	if ConquestState.waveNumber == 0 then
		if printDebug then
			print("Initial recon wave spawning.")
		end
		SetWaveOneGraphOverride(true)
	elseif ConquestState.waveNumber == 1 then
		if printDebug then
			print("2nd wave spawning.")
		end
		SetWaveOneGraphOverride(false)
	end
end

-- Returns true for unit types that must never follow the mission-layer waypoint
-- graph, regardless of wave number (e.g. artillery, heavy armor classes, or specific unit names).
-- AirDefense-role Cannon/SPG/Plane/Heavy units are exempted from the base/class exclusion.
local function IsPermanentlyWaypointGraphExempt(spawnInfo)
	if not spawnInfo then return false end

	-- 1. Check for specific unit name match from roster definitions
	local spawnUnit = spawnInfo.unit
	if spawnUnit and contains(exemptUnitNames, spawnUnit) then
		return true
	end

	-- 2. Extract unit properties
	local spawnBase = spawnInfo.base
	local spawnClass = spawnInfo.class
	local spawnRoles = spawnInfo.roles
	local isAirDefense = contains(spawnRoles, AIR_DEFENSE_ROLE)

	-- 3. Check base and class types (if not AirDefense)
	if not isAirDefense then
		if containsAny(spawnBase, unitBases) or containsAny(spawnClass, unitClasses) then
			return true
		end
	end

	-- 4. Check roles
	return containsAny(spawnRoles, unitRoles)
end

-- Returns true when this spawning squad should skip the waypoint graph and use
-- a Lua CaptureFlag order instead - either because the wave-1 override is
-- active, or because this unit type is permanently graph-exempt.
function ShouldSkipWaypointGraph()
	if waveOneGraphOverrideActive then
		return true
	end

	-- Added safety guard for Context to prevent runtime nil errors
	return IsPermanentlyWaypointGraphExempt(Context and Context.SpawnInfo)
end