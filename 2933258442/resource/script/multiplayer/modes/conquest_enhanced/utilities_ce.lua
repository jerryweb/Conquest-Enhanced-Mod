-- =========================================================
-- UTILITIES FILE FOR CONQUEST ENHANCED
-- =========================================================
local waveOneGraphOverrideActive = false
local lastWrittenGraphVar = nil -- last value sent to BotApi, used to skip redundant writes

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

-- The value the graph var should have when the wave-1 override is NOT active.
-- On, except while the bot's defender counterattack is running.
local function GetBaseWaypointGraphEnabled()
	if IsDefenderCounterattackActive() then
		return 0
	end
	return 1
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
	-- Bot attacker: the first wave is still pending, so the override starts armed.
	waveOneGraphOverrideActive = not ConquestState.botDefender
	lastWrittenGraphVar = nil -- force a write at mission start
	ConquestContext.RefreshWaypointGraph()
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
-- a Lua CaptureFlag order instead: the wave-1 override is active, a bot
-- defender counterattack is running, or this unit type is permanently
-- graph-exempt.
function ShouldSkipWaypointGraph()
	if waveOneGraphOverrideActive or IsDefenderCounterattackActive() then
		return true
	end

	-- Safety guard for Context to prevent runtime nil errors
	return IsPermanentlyWaypointGraphExempt(Context and Context.SpawnInfo)
end