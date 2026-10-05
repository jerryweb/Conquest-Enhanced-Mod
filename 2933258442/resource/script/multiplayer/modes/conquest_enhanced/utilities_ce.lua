-- =========================================================
-- UTILITIES FILE FOR CONQUEST ENHANCED
-- =========================================================
waveOneGraphOverrideActive = false
local unitBases = {"Cannon", "SPG", "Plane", "Heavy"}
local unitRoles = {"Artillery", "Breakthrough"}
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
-- graph, regardless of wave number (e.g. artillery, breakthrough-role armor).
-- AirDefense-role Cannon/SPG/Plane units are exempted from the base-type exclusion.
local function IsPermanentlyWaypointGraphExempt(spawnInfo)
	local spawnBase = spawnInfo and spawnInfo.base
	local spawnRoles = spawnInfo and spawnInfo.roles
	local isAirDefense = contains(spawnRoles, AIR_DEFENSE_ROLE)

	if not isAirDefense and containsAny(spawnBase, unitBases) then
		return true
	end

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