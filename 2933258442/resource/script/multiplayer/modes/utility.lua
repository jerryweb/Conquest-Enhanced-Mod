-- Utility variables for various game modes
require([[/script/multiplayer/modes/utility_ce]])

local defenseStarted = false
spawnPoint = BotApi.Instance.spawnPointName
spawnSide = string.sub(spawnPoint,1,1)
gameMode = BotApi.Instance.gameMode
enemyTeam = BotApi.Instance.enemyTeam
team = BotApi.Instance.team
teamSize = BotApi.Instance.teamSize

MaxSquadSize = 0
gameModeSpawnTimer = 0
Purchases = {}
PIter = {}
PIter.__index = PIter

FlagOwnership = {
    Allied = 1,
    Opponent = 2,
    Neutral = 3
}

-- Is the flag located on the bot's team side of the map, enemies side of the map, or on the center line
FlagLocation = {
    Enemy = 1,
    Friendly = 3,
    Center = 6,
    EnemyBase = 1,
    FriendlyBase = 5,
    EvacFriendlyBase = 3,
}

FlagCaptureArea = {
	-- applying any props to cannons class vehicles does not seem to work
	-- These props do Not work
	Helicopter = 3, -- props helicopter (reserved)
	Artillery = 175, -- props detect_artillery (not work)
	Mortar = 100, -- props mortar (reserved)
	ATgun = 50, -- props detect_atgun (not work)
	Captor = 100, -- props captor (transport trucks)
	Vehicle = 18, -- props vehicle
	Infantry = 25 -- ~= to any of the props above
}

unitsToSpawnQueue = DoubleQueue.new()
currentUnitCountTable = {}
-- Utility functions and shared logic for various game modes


-- Function to set spawn cooldown timer
function SetSpawnCooldownTimer()
	gameModeSpawnTimer = GameModeSpawnCooldown()
	print("Print: player#".. BotApi.Instance.playerId.. " will wait ".. (gameModeSpawnTimer / 1000) .."s before purchasing another unit")
	Context.SpawnWait.CooldownTimer = BotApi.Events:SetQuantTimer(
		function() 
			Context.SpawnWait.CooldownTimer = nil 
		end, 
		gameModeSpawnTimer)
end

-- Function to kill spawn cooldown timer
function KillSpawnCooldownTimer()
	if Context.SpawnWait.CooldownTimer then
		BotApi.Events:KillQuantTimer(Context.SpawnWait.CooldownTimer)
		Context.SpawnWait.CooldownTimer = nil
	end
end

-- Function to kill spawn wait timer
function KillSpawnWaitTimer()
	if Context.SpawnWait.WaitTimer then
		BotApi.Events:KillQuantTimer(Context.SpawnWait.WaitTimer)
		Context.SpawnWait.WaitTimer = nil
	end
end

-- PIter class for managing unit purchases
function PIter:new(data)
    local obj = {
        idx = nil,
        rpt = nil,
        purchases = data
    }
    setmetatable(obj, self)
    obj:nextIndex()
    return obj
end

function PIter:current()
    if self.idx then
		return self.purchases[self.idx].Units
	end
end

function PIter:nextIndex()
    if not self.purchases or next(self.purchases) == nil then
        self.idx, self.rpt = nil, nil
        return
    end
    
    self.idx = next(self.purchases, self.idx)
    if self.idx then
        self.rpt = self.purchases[self.idx].Repeat
    else
        self.rpt = nil
    end
end

function PIter:moveNext()
	if not self.rpt or self.rpt == 0 then
		return
	end
	
	self.rpt = self.rpt - 1

	if self.rpt == 0 then
		self:nextIndex()
	end
end

-- Function to calculate item rates
local function calculateItemRates(items, getRate)
    local item_rates = {}
    local total = 0
    for i, item in pairs(items) do
        local rate = getRate(item)
        total = total + rate
        table.insert(item_rates, {i = item, r = rate})
    end
    return item_rates, total
end

-- Function to print unitsToSpawn or GetFlagToCapture with priority pre and post 
local function printDebugInfo(caller, item_rates, total)
    -- Sort item_rates by probability in ascending order
    table.sort(item_rates, function(a, b)
        return (a.r / total) > (b.r / total)
    end)
    
    if caller == "GetNextUnitToSpawn" then
        ---[[
        print("Print: Possible Units for", "Player#", BotApi.Instance.playerId, "Team", BotApi.Instance.team, "SpawnPoint", spawnPoint)
        for j, item_rate in pairs(item_rates) do
            local tts2 = BotApi.Commands:TimeToSpawnUnit(item_rate.i.unit) / 1000
            local tts_seconds = string.format("%.1f", tts2)
            local probability = string.format("%.1f%%", (item_rate.r / total) * 100) -- Calculate probability of purchasing this unit
            --print("---", probability, item_rate.i.unit, "--- TTS:" .. tts_seconds .. "s", "- Rate:" .. item_rate.r, " BaseRate:" .. item_rate.i.priority)
            print("---", probability, item_rate.i.unit, "-- TTS:" .. tts_seconds .. "s", "-- Rate:" .. item_rate.r)
        end
        --]]
    elseif caller == "order" then
        ---[[
        print("Print: Flags for Move Order for", "Player#", BotApi.Instance.playerId, "Team", BotApi.Instance.team, "SpawnPoint", spawnPoint)
        for j, item_rate in pairs(item_rates) do
            local probability = string.format("%.1f%%", (item_rate.r / total) * 100) -- Calculate probability of capturing this flag
            print("---", probability, item_rate.i.name, "-- Rate:" .. item_rate.r, "-- BaseRate:" .. item_rate.i.priority)
        end
        --]]
    else
        print("Print: Caller", caller)
    end
end

-- Function to handle special order logic
local function handleOrderLogic(caller)
    if caller == "order" and captureBackFlag then
        captureBackFlag = false
    end
end

-- Function to get a random item based on rates
local function getRandomItemFromRates(item_rates, total)
    local rnd = math.random()
    local bound = 0.0
    for j, item_rate in pairs(item_rates) do
        bound = bound + item_rate.r
        if rnd < bound / total then
            return item_rate.i
        end
    end
end

-- Main function to get a random item
function GetRandomItem(items, getRate)
    local item_rates, total = calculateItemRates(items, getRate)
    local caller = debug.getinfo(2, "n").name  -- checks which function called GetRandomItem
    
    if printDebug then printDebugInfo(caller, item_rates, total) end
    handleOrderLogic(caller)
    
    return getRandomItemFromRates(item_rates, total)
end

-- Function to get team that owns flag
function GetFlagOwner(flag)
    if flag.occupant == team then
        return FlagOwnership.Allied
    elseif flag.occupant == enemyTeam then
        return FlagOwnership.Opponent
    else
        return FlagOwnership.Neutral
    end
end

-- Function to get flags location of the map in relation to each team
function LookupFlagLocation(flag, flagLocationMap, spawnSide)
	local flagLocationsForCurrentGameMode = flagLocationMap[gameMode] or flagLocationMap
    local locationData = flagLocationsForCurrentGameMode[flag.name] or flagLocationsForCurrentGameMode["default"]
    if type(locationData) == "function" then
        return locationData(spawnSide)
    else
        return locationData
    end
end

-- Function to give Flag a capture priority
function getDefaultFlagPriority(flag)
    if not flagLocationMap then
        return GetFlagOwner(flag) * 1
    end
    return GetFlagOwner(flag) * LookupFlagLocation(flag, flagLocationMap, spawnSide)
end

-- Function used for ordering units to capture flag
function GetFlagPosition(flag)
    local location = LookupFlagLocation(flag, flagLocationMap, spawnSide)
    if location == FlagLocation.Center then
        return "center"
    elseif location == FlagLocation.Friendly or location == FlagLocation.FriendlyBase then
        return "friendly"
    elseif location == FlagLocation.Enemy or location == FlagLocation.EnemyBase then
        return "enemy"
    end
    return
end

-- Function to calculate flag statistics
function CalculateFlagStatistics(flags)
    local alliedFlags, opponentFlags, neutralFlags, totalFlags = 0, 0, 0, 0
    for i, flag in pairs(flags) do
        totalFlags = totalFlags + 1
        if flag.occupant == team then
            alliedFlags = alliedFlags + 1
        elseif flag.occupant == enemyTeam then
            opponentFlags = opponentFlags + 1
        else
            neutralFlags = neutralFlags + 1
        end
    end
    return alliedFlags, opponentFlags, neutralFlags, totalFlags
end

-- Function to calculate capturable flags
function CalculateCapturableFlags(totalFlags, alliedFlags)
    return totalFlags - alliedFlags
end

-- Function to print flag debug information
function PrintFlagDebugInfo(alliedFlags, opponentFlags, neutralFlags, totalFlags, capturableFlags, teamIsLosing)
    if printDebug then
        print("alliedFlags:", alliedFlags, "opponentFlags:", opponentFlags, "neutralFlags:", neutralFlags, "totalFlags:", totalFlags, "capturableFlags:", capturableFlags)
        print("teamIsLosing:", teamIsLosing)
    end
end

-- Function to calculate search destroy value
function CalculateSearchDestroyValue(capturableFlags, alliedFlags, opponentFlags)
    if capturableFlags > alliedFlags then
        return 0.60
    elseif capturableFlags == opponentFlags then
        return 0.40
    else
        return 0.30
    end
end

-- Function to prepare flags for random selection
function PrepareFlags(flagPoints, getPriority, getPosition)
    local flags = {}
    for i, flag in pairs(flagPoints) do
        table.insert(flags, {name = flag.name, priority = getPriority(flag), owner = flag.occupant, location = getPosition(flag)})
    end
    return flags
end

function GetNextUnitToSpawn(purchase)
	local units = purchase:current()
	
	if not units then
		return nil
	end
	
	local unit = GetUnitToSpawn(units)
	purchase:moveNext()
	return unit
end


function UpdateUnitToSpawn(purchase)
	Context.SpawnInfo = GetNextUnitToSpawn(purchase)
end

-- Called OnGameStart()
function OnGameStartUtility(purchasesModuleSuffix, waveUnitTotal)
    print("Print: AI Bot is player#" .. BotApi.Instance.playerId .. ", nation " .. BotApi.Instance.army .. ", on team " .. team .. " which has " .. teamSize .. " player(s)")
    print("Print: player#" .. BotApi.Instance.playerId .. ", has a difficulty of " .. BotApi.Instance.difficulty)
	
	print("CUSTOM WAYPOINTS = ", followWaypointGraphs)
	print("Attempting to spawn scene_variable")
   
    -- Seed random for unpredictability
    math.randomseed(os.time() * BotApi.Instance.hostId)
    math.random() math.random() math.random() math.random()

    -- Load purchases module
    local purchasesModule = [[/script/multiplayer/units/]] .. BotApi.Instance.army .. "/" .. purchasesModuleSuffix .. "." .. BotApi.Instance.army
    
    BotApi.Commands:Spawn("scene_variable", MaxSquadSize)
	print("Spawned Scene variable successfully!")

	-- Check scene variable if loaded map uses CE scripts or vanilla scripts
	Context.InitialSceneTimerCheck = BotApi.Events:SetQuantTimer(
		function()
			if not BotApi.Scene:IsSquadTagged(sceneVariableSquad, "_ce_map_scripts_running") then
				print("Vanilla Map Loaded!!! Disabling CE bot file logic")
				followWaypointGraphs = false
				if botDefender then
					-- Vanilla spawn overwrites 
					SpawnCooldownTime.DCGWaveOffDefendMin = 2 * 60 * 1000
					SpawnCooldownTime.DCGWaveOffDefendMax = 2.5 * 60 * 1000
					KillSpawnCooldownTimer()
					KillInitialSceneCheckTimer()
				end
			end
		end, generalSquadTagCheckDelay)

    if module_exists(purchasesModule) then
        require(purchasesModule)
    else
        print("Print: Module does not exist: " .. purchasesModule)
    end

    -- Get purchases
    local purchases = Purchases[purchasesModuleSuffix .. "." .. BotApi.Instance.army]
    if not purchases then
        print("Print: !!WARNING!! NoPurchases")
        purchases = {}
    end

    -- Set up context
    Context.Purchase = PIter:new(purchases)
    -- Load random AI strategy for advanced AI system
    strategyTable = SelectAiStrategyTemplate(botDefender)
	waveUnitTotal = ActivateAiStrategy(waveUnitTotal)
    -- Update and set cooldown
    UpdateUnitToSpawn(Context.Purchase)
    SetSpawnCooldownTimer()
    SetGeneralSquadTagCheckTimer()
end

---[=[
function TrySpawnUnit()
	if Context.SpawnWait.CooldownTimer then
		return
	end

	if not BotApi.Commands:CanSpawn() then
		return
	end

	if not Context.SpawnInfo then
		UpdateUnitToSpawn(Context.Purchase)
		return
	end

	local unit = Context.SpawnInfo.unit

	---[[ -- ! Moved to GetUnitToSpawn(). Active for debuging
	if not BotApi.Commands:IsUnitAvailable(unit) then
		print("Print: !!WARNING!! player#".. BotApi.Instance.playerId.. " tried to purchase: ".. unit .." which is not available")
		KillSpawnWaitTimer()
		UpdateUnitToSpawn(Context.Purchase)
		return
	end
	--]]

	if spawningUnit then
        if enableWaveCounter then 
            WaveUnitCounter()
        end
		KillSpawnWaitTimer()
		SetSpawnCooldownTimer()
		UpdateUnitToSpawn(Context.Purchase)
		spawningUnit = nil
		return
	end

	if BotApi.Commands:Spawn(unit, MaxSquadSize) then
		spawningUnit = true
		-- if Context.SpawnInfo.type == "Paratrooper" then
		-- 	print("duplicating paratroopers!!!")
		-- 	BotApi.Commands:Spawn(unit, MaxSquadSize)
		-- 	DoubleQueue.pushRight(unitsToSpawnQueue, Context.SpawnInfo.type)
		-- end
		if Context.SpawnInfo.maxUnitCount then
			if currentUnitCountTable[unit] then
				currentUnitCountTable[unit] = currentUnitCountTable[unit] + 1
			else
				currentUnitCountTable[unit] = 1
			end
			if printDebug then print("Incrementing  ", unit, " unit count. Current unit count =", currentUnitCountTable[unit]) end
		end
		DoubleQueue.pushRight(unitsToSpawnQueue, Context.SpawnInfo.type)
		-- if printDebug then print("Adding ", unit, " of types ", Context.SpawnInfo.type, " Queue size is now ", DoubleQueue.size(unitsToSpawnQueue)) end
		if printDebug then print("Adding ", unit, ". Queue size is now ", DoubleQueue.size(unitsToSpawnQueue)) end
		return
	end
	
	local currentUnitSpawnWaitTime = GetCurrentSpawnWaitTime()
	---[[ -- TODO: Move to GetUnitToSpawn()
	local tts = BotApi.Commands:TimeToSpawnUnit(unit)
	local min_tts = currentUnitSpawnWaitTime + gameModeSpawnTimer
	if tts > min_tts then
		print("Print: !!WARNING!! player#".. BotApi.Instance.playerId.. " tried to purchase: ".. unit .." but the TTS (unit timer) is greater than UnitSpawnWaitTime ".. (tts / 1000) .."s verses ".. (min_tts / 1000) .."s")
		KillSpawnWaitTimer()
		UpdateUnitToSpawn(Context.Purchase)
		return
	end
	--]]

	-- TODO: Move to GetUnitToSpawn()
	if not Context.SpawnWait.WaitTimer then
		if printDebug then 
			print("Print: player#".. BotApi.Instance.playerId .." tried to purchase: ".. unit .." Not enough MP, DP, CP, or the unit timer is not unlocked")
			print("Print: player#".. BotApi.Instance.playerId .." will wait a maximum of ".. (currentUnitSpawnWaitTime / 1000 + 1) .."s for resources or unit timer before it attempts a new unit purchase")
		end
		Context.SpawnWait.WaitTimer = BotApi.Events:SetQuantTimer(
			function()
				Context.SpawnWait.WaitTimer = nil
				UpdateUnitToSpawn(Context.Purchase)
			end, currentUnitSpawnWaitTime + 1000)
	end
	local spawningUnit = nil
end
--]=]
function OnGameStop()
	NoresusOnGameEnd()
	KillSpawnCooldownTimer()
	KillSpawnWaitTimer()
	KillInitialSceneCheckTimer()
	KillAiSpawnMoveTimer()
	for squad, timer in pairs(Context.SquadTimers) do
		if timer then
			BotApi.Events:KillQuantTimer(timer)
		end
	end
end

function SetSquadOrder(order, squad, delay, initialOrder)
	if initialOrder then
		order(squad)		
	end
	if squad == sceneVariableSquad then
		CheckSceneVariable(squad)
	end
	local setTimer = nil
	setTimer = function(callback)
		Context.SquadTimers[squad] = BotApi.Events:SetQuantTimer(
			function()
				order(squad)
				Context.SquadTimers[squad] = nil
				if BotApi.Scene:IsSquadExists(squad) then
					if squad == sceneVariableSquad then
						CheckSceneVariable(squad)
					end	
					callback(callback)
				end
			end,
			delay)
		end
	setTimer(setTimer)
end

-- Checks the squad scene variable for tagged info about the match
function CheckSceneVariable(squad)
  	-- Check if player has started the defense mission early
  	if not botDefender and not defenseStarted then
  		if BotApi.Scene:IsSquadTagged(squad, "_lua_start_defense_mission") then 
  	  		print("PLAYER HAS INITIATED DEFENSE EARLY!!!")
  	  		KillSpawnCooldownTimer()
  	  		defenseStarted = true
  	  	end
  	end

  	if followWaypointGraphs then 
  		if BotApi.Scene:IsSquadTagged(squad, "_lua_waypoint_graph_disabled") then
		    print("Print: AI Waypoint graphs disabled by scene! followWaypointGraphs = ", followWaypointGraphs)
		    followWaypointGraphs = false
		end
  	else
  		if BotApi.Scene:IsSquadTagged(squad, "_lua_waypoint_graph_enabled") then
	  	  	print("Print: AI Waypoint graphs enabled by scene! followWaypointGraphs = ", followWaypointGraphs)
	  	    followWaypointGraphs = true
  		end
  	end

    if not forceUnitPriority then
    	if BotApi.Scene:IsSquadTagged(squad, "_prioritize_de_miner") then
    		print("Player has a lot of mines. Prioritze buying de-meiner!")
        	forceUnitPriority = true 
    		forcedUnitTypes = {"Miner"}
    		forceUnitCountMax = 1   
    	end
    end
  	-- elseif BotApi.Scene:IsSquadTagged(squad, "_prioritize_aa") and not forceUnitPriority then
  	  -- forceUnitPriority = true 
  	  -- forcedUnitTypes = {"AA"}
  	  -- forceUnitCountMax = 2    
  	  -- print("Player has planes. Prioritze buying AA!")
  	-- end
end