-- =========================================================
-- UTILITIES FILE FOR CONQUEST ENHANCED
-- =========================================================
local waveOneGraphOverrideActive = false
local lastWrittenGraphVar = nil -- last value sent to BotApi, used to skip redundant writes
-- Latched answer to "does this map have a waypoint graph?". Closed until the map layer
-- reports it; once open it stays open, and if the wait runs out it stays closed all match.
local mapGraphGateOpen = false
-- Map-layer var, written once per match about 3 seconds after start. 1/true: the map
-- has a waypoint graph. 0/unset: it does not, so the graph never turns on.
local MAP_CONTAINS_GRAPH_VAR = "map_contains_waypoint_graphs"
local MAP_GRAPH_FIRST_CHECK_MS = 6 * 1000 -- first read, just after the map layer writes it
local MAP_GRAPH_RETRY_MS = 1 * 1000       -- re-read interval while it is still unset
local MAP_GRAPH_MAX_WAIT_MS = 15 * 1000   -- give up after this long: treat as no graph

-- Cannons never follow the graph, regardless of role.
local alwaysExemptBases = {"Cannon"}
-- These bases are exempt unless the unit has the AirDefense role.
local exemptBasesUnlessAirDefense = {"SPG", "Plane"}
local exemptClassesUnlessAirDefense = {"Heavy"}
local unitRoles = {"Artillery", "Breakthrough"}

-- Specific unit names (from roster files like conquest.ger) that should use the waypoint graph
local shouldFollowWaypointUnitNames = { hetzer = true }
-- Specific unit names (from roster files like conquest.ger) that should skip the waypoint graph
local exemptUnitNames = { sdkfz234_4 = true, sdkfz251d_22 = true, t30_hmc = true }
local AIR_DEFENSE_ROLE = "AirDefense"
local ENABLE_WAYPOINT_GRAPH = "enable_waypoint_graph"

local function checkVarPercentage(varName, varPecetage)
  local result = (varPecetage >= math.random()) and 1 or 0
  BotApi.Scene:SetVar(varName, result)
  print(varName .. " = ", result)
end

-- Helper function to check if a table contains a specific value
local function contains(tbl, target)
	if not tbl then return false end
	if type(tbl) == "string" then return tbl == target end
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

local PHASE_DEFENDER_COUNTERATTACK = "defender_counterattack" -- must match waves.lua

-- True while the bot's defender counterattack purchase phase is running.
local function IsDefenderCounterattackActive()
	return ConquestState.purchasePhase == PHASE_DEFENDER_COUNTERATTACK
end

-- True for the whole match once the rear attack event has been rolled on.
local function IsRearAttackEventActive()
	return ConquestRearAttack ~= nil and ConquestRearAttack.IsEventActive()
end

-- The value the graph var should have when the wave-1 override is NOT active.
-- Off until the map reports a graph, off while the bot's defender counterattack
-- is running, and off for the whole match when the rear attack event is active.
-- Otherwise on.
local function GetBaseWaypointGraphEnabled()
	if not mapGraphGateOpen or IsDefenderCounterattackActive() or IsRearAttackEventActive() then
		return 0
	end
	return 1
end

-- Same truthy test waves.lua uses for mission vars.
local function IsMapGraphVarEnabled()
	local value = BotApi.Scene:GetVar(MAP_CONTAINS_GRAPH_VAR)
	return value == 1 or value == "1" or value == true
end

-- Reads the map-layer var until it reports a graph or the wait runs out. Opening the
-- gate refreshes the scene var in the same step, so the mission graph and the Lua
-- spawn order (ShouldSkipWaypointGraph) always change together.
local function ScheduleMapGraphGateCheck(delay, waited)
	BotApi.Events:SetQuantTimer(function()
		waited = waited + delay
		if IsMapGraphVarEnabled() then
			mapGraphGateOpen = true
			ConquestContext.RefreshWaypointGraph()
			if printDebug then
				print("Print: map reports a waypoint graph, graph logic enabled")
			end
		elseif waited >= MAP_GRAPH_MAX_WAIT_MS then
			if printDebug then
				print("Print: map reports no waypoint graph, graph stays off")
			end
		else
			ScheduleMapGraphGateCheck(MAP_GRAPH_RETRY_MS, waited)
		end
	end, delay)
end

function ConquestContext.SetEnableWaypointGraph(enableWaypointGraphVar)
	if enableWaypointGraphVar == lastWrittenGraphVar then return end
	lastWrittenGraphVar = enableWaypointGraphVar
	BotApi.Scene:SetVar(ENABLE_WAYPOINT_GRAPH, enableWaypointGraphVar)
	if printDebug then
		print("enable spawn waypoint grid = ", enableWaypointGraphVar)
	end
end

function ConquestContext.SetCEVarsInMissionScript()
	CEWeather.Start()
	local sabotageChance = enableSabotageMechanics
	local sabotageEnabled = sabotageChance > 0
		and (sabotageChance >= 1 or math.random() < sabotageChance)
	BotApi.Scene:SetVar("ai_sabotage", sabotageEnabled and 1 or 0)
	-- Bot attacker: the first wave is still pending, so the override starts armed.
	waveOneGraphOverrideActive = not ConquestState.botDefender
	mapGraphGateOpen = false -- closed until the map layer reports a graph
	lastWrittenGraphVar = nil -- force a write at mission start
	ConquestContext.RefreshWaypointGraph()
	ScheduleMapGraphGateCheck(MAP_GRAPH_FIRST_CHECK_MS, 0)
	checkVarPercentage("enable_ce_radio_mechanic", enableCommunicationsCutMechanics) -- use this to control both variables for now
  	checkVarPercentage("enable_ce_cut_communications_mechanic", enableCommunicationsCutMechanics)
	
end

-- Recomputes and applies the graph var. Call this whenever the base state can
-- change mid-match (counter attack starting or finishing).
function ConquestContext.RefreshWaypointGraph()
	local enable = waveOneGraphOverrideActive and 0 or GetBaseWaypointGraphEnabled()
	ConquestContext.SetEnableWaypointGraph(enable)
end

-- Toggles the wave-1 override: when active, every spawning squad skips the
-- waypoint graph regardless of unit type.
function SetWaveOneGraphOverride(isActive)
	waveOneGraphOverrideActive = isActive
	ConquestContext.RefreshWaypointGraph()
end

-- The override is active only for the very first attacker wave; every later
-- wave follows the graph again (subject to the base state).
function UpdateWaveOneGraphOverride()
	local isFirstWave = ConquestState.waveNumber == 0
	if printDebug then
		print(isFirstWave and "Initial recon wave spawning." or "Later wave spawning.")
	end
	SetWaveOneGraphOverride(isFirstWave)
end

-- Returns true for unit types that must never follow the mission-layer waypoint
-- graph, regardless of wave number.
-- Cannons are always exempt. SPG/Plane/Heavy are exempt unless AirDefense.
-- Artillery/Breakthrough roles are exempt in all cases.
local function IsPermanentlyWaypointGraphExempt(spawnInfo)
	if not spawnInfo then return false end

	-- 1. Specific unit names from roster definitions take priority
	local spawnUnit = spawnInfo.unit
	if spawnUnit then
		if shouldFollowWaypointUnitNames[spawnUnit] then
			return false
		elseif exemptUnitNames[spawnUnit] then
			return true
		end
	end

	local spawnBase = spawnInfo.base
	local spawnClass = spawnInfo.class
	local spawnRoles = spawnInfo.roles

	-- 2. All cannons, including AirDefense cannons
	if containsAny(spawnBase, alwaysExemptBases) then
		return true
	end

	-- 3. Other base/class exclusions, skipped for AirDefense units
	if not contains(spawnRoles, AIR_DEFENSE_ROLE) then
		if containsAny(spawnBase, exemptBasesUnlessAirDefense)
			or containsAny(spawnClass, exemptClassesUnlessAirDefense) then
			return true
		end
	end

	-- 4. Role exclusions
	return containsAny(spawnRoles, unitRoles)
end

-- Returns true when this spawning squad should skip the waypoint graph and use
-- a Lua CaptureFlag order instead: the map has no graph (or has not reported one
-- yet), the wave-1 override is active, a bot defender counterattack is running,
-- the rear attack event is active, or this unit type is permanently graph-exempt.
function ShouldSkipWaypointGraph()
	if not mapGraphGateOpen then
		return true
	end

	if waveOneGraphOverrideActive or IsDefenderCounterattackActive() or IsRearAttackEventActive() then
		return true
	end

	-- Safety guard for Context to prevent runtime nil errors
	return IsPermanentlyWaypointGraphExempt(Context and Context.SpawnInfo)
end

-- =========================================================
-- ORDER ROTATION PERIOD BY UNIT TYPE
-- =========================================================
-- ConquestConfig.OrderRotationPeriod is a table: { Default = ms, Cannon = ms }.
-- A plain number is still accepted and applies to every squad.
function GetRotationPeriod(spawnInfo)
	local periods = ConquestConfig.OrderRotationPeriod
	if type(periods) ~= "table" then
		return periods
	end
	if periods.Cannon and spawnInfo and contains(spawnInfo.base, "Cannon") then
		return periods.Cannon
	end
	return periods.Default
end
