-- =========================================================
-- UTILITIES FILE FOR CONQUEST ENHANCED
-- =========================================================
forceInitialOrder = false
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

function ConquestContext.SetCEVarsInMissionScript(botDefender)
	local enableWaypointGraph = ConquestState.botDefender and 1 or 0
	-- enableWaypointGraph = 1

	ConquestContext.SetEnableWaypointGraph(enableWaypointGraph)
	-- BotApi.Scene:SetVar(ENABLE_SPAWN_A_1_WAYPOINT_GRID, enableWaypointGraph)
	-- BotApi.Scene:SetVar(ENABLE_SPAWN_A_2_WAYPOINT_GRID, enableWaypointGraph)
	-- BotApi.Scene:SetVar(ENABLE_SPAWN_A_3_WAYPOINT_GRID, enableWaypointGraph)
	-- BotApi.Scene:SetVar(ENABLE_SPAWN_A_4_WAYPOINT_GRID, enableWaypointGraph)

	-- BotApi.Scene:SetVar(ENABLE_SPAWN_B_1_WAYPOINT_GRID, enableWaypointGraph)
	-- BotApi.Scene:SetVar(ENABLE_SPAWN_B_2_WAYPOINT_GRID, enableWaypointGraph)
	-- BotApi.Scene:SetVar(ENABLE_SPAWN_B_3_WAYPOINT_GRID, enableWaypointGraph)
	-- BotApi.Scene:SetVar(ENABLE_SPAWN_B_4_WAYPOINT_GRID, enableWaypointGraph)

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

function SetForceInitialOrder(forceInitialOrderBoolean)
	forceInitialOrder = forceInitialOrderBoolean
	
	-- Consistently pass 1 or 0 integer flag to BotApi
	local enableWaypointGraph = forceInitialOrderBoolean and 0 or 1
	ConquestContext.SetEnableWaypointGraph(enableWaypointGraph)
end

function CheckIfInitialAttackingReconWave()
	if ConquestState.waveNumber == 0 then
		if printDebug then
			print("Initial recon wave spawning.")
		end
		SetForceInitialOrder(true)
	elseif ConquestState.waveNumber == 1 then 
		if printDebug then
			print("2nd wave spawning.")
		end
		SetForceInitialOrder(false)
	end
end

-- function SetForceInitialOrderVar(enableWaypointGraph)
-- 	BotApi.Scene:SetVar(ENABLE_WAYPOINT_GRAPH, enableWaypointGraph)
-- 	-- BotApi.Scene:SetVar("enable_spawn_a_1_waypoint_grid", enableWaypointGraph)
-- 	-- BotApi.Scene:SetVar("enable_spawn_a_2_waypoint_grid", enableWaypointGraph)
-- 	-- BotApi.Scene:SetVar("enable_spawn_a_3_waypoint_grid", enableWaypointGraph)
-- 	-- BotApi.Scene:SetVar("enable_spawn_a_4_waypoint_grid", enableWaypointGraph)

-- 	-- BotApi.Scene:SetVar("enable_spawn_b_1_waypoint_grid", enableWaypointGraph)
-- 	-- BotApi.Scene:SetVar("enable_spawn_b_2_waypoint_grid", enableWaypointGraph)
-- 	-- BotApi.Scene:SetVar("enable_spawn_b_3_waypoint_grid", enableWaypointGraph)
-- 	-- BotApi.Scene:SetVar("enable_spawn_b_4_waypoint_grid", enableWaypointGraph)

-- 	forceInitialOrder = not enableWaypointGraph 
-- end

-- function GetForceInitialOrderVar()
-- 	forceInitialOrder = not BotApi.Scene:GetVar(ENABLE_WAYPOINT_GRAPH)
-- end

function CheckUnitPropertiesToFollowWaypoints()
	if forceInitialOrder then 
		return true
	end
	
	-- Added safety guard for Context to prevent runtime nil errors
	local spawnBase = Context and Context.SpawnInfo and Context.SpawnInfo.base
	local spawnRoles = Context and Context.SpawnInfo and Context.SpawnInfo.roles

	-- Exception: Cannon/SPG/Plane are allowed IF they are AirDefense
	local isAirDefense = contains(spawnRoles, AIR_DEFENSE_ROLE)

	for _, base in ipairs(unitBases) do 
		if contains(spawnBase, base) then 
			if not isAirDefense then
				return true
			end
		end 
	end
	
	for _, role in ipairs(unitRoles) do 
		if contains(spawnRoles, role) then
			return true
		end 
	end
	
	return false
end