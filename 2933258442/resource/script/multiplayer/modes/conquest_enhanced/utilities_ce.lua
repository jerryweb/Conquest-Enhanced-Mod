-- =========================================================
-- UTILITIES FILE FOR CONQUEST ENHANCED
-- =========================================================
forceInitialOrder = false
local unitBases = {"Cannon", "SPG", "Plane"}
local unitRoles = {"Artillery", "Breakthrough"}
local AIR_DEFENSE_ROLE = "AirDefense"
local FORCE_INITIAL_ORDER_VAR = "force_initial_order"

-- Helper function to check if a table contains a specific value
local function contains(tbl, target)
	if not tbl then return false end
	for _, val in ipairs(tbl) do
		if val == target then return true end
	end
	return false
end

function SetForceInitialOrderVar(initialOrder)
	BotApi.Scene:SetVar(FORCE_INITIAL_ORDER_VAR, initialOrder)
	forceInitialOrder = initialOrder
end

function GetForceInitialOrderVar()
	forceInitialOrder = BotApi.Scene:GetVar(FORCE_INITIAL_ORDER_VAR)
end

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