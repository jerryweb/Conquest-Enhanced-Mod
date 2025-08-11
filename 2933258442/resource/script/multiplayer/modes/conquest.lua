require([[/script/multiplayer/modes/utility]])

-- Sets time limit AI will wait for a unit it has chosen to buy if the unit is not yet available
local UnitSpawnWaitTime = 1.5 * 60000 -- 1:30min (ms) 

-- Time delay for units to get a new move order after spawn move order. Loops.
-- local OrderRotationPeriod = 2.5 * 60000 -- 2:30 min (ms)
local OrderRotationPeriod = {
    DCG = { 
    	Min = 3 * 60000, -- 2:30 min (ms)
    	Max = 4 * 60000, -- 4:00 min (ms)
    }, -- 4:30 min (ms)
    DCG_FLANK = {
    	Min = 6 * 60000, -- 6:00 min (ms)
    	Max = 8 * 60000 -- 8:00 min (ms)
    },
    InitialUnitSpawnTimeout = 0.5 * 60000
}

local waveUnitTotal = math.random(WaveUnit.Min, WaveUnit.Max)
-- local botDefender
enableWaveCounter = true
local function isAttackerOrDefender()
	botDefender = teamSize > 1
	if printDebug then print("Print: BotIsDefender -", botDefender) end
	SetCEWaveSettings()
	waveUnitTotal = math.random(WaveUnit.Min, WaveUnit.Max)
  	if printDebug then print("Print: setting initial waveUnitTotal", waveUnitTotal) end
end

local function setVarsInMissionScript()
	if teamSize > 1 then
		BotApi.Scene:SetVar("user_is_defender", 0)
	else
		BotApi.Scene:SetVar("user_is_defender", 1)
	end

	local botNation = BotApi.Instance.army
	local botDifficulty = BotApi.Instance.difficulty
	local nationMap = { rus = 1, ger = 2, fin = 3, usa = 4, eng = 5, ita = 6, fra = 7, pol = 8, jap = 9, usaf = 10, ally = 11, axis = 12 }
	local difficultyMap = { easy = 1, normal = 2, hard = 3, heroic = 4 }
	
	BotApi.Scene:SetVar("bot_army", nationMap[botNation] or 0)
	BotApi.Scene:SetVar("bot_difficulty", difficultyMap[botDifficulty] or 0)

	local spawnMap = { a = 1, b = 2}
	BotApi.Scene:SetVar("bots_spawnside", spawnMap[spawnSide] or 0)

	BotApi.Scene:SetVar("enemyid", BotApi.Instance.playerId)
	BotApi.Scene:SetVar("id_1st_enemy", BotApi.Instance.CampaignFirstEnemyId)
	BotApi.Scene:SetVar("id_defenderbot", BotApi.Instance.CampaignDefenderBotId)
	BotApi.Scene:SetVar("id_1st_player", BotApi.Instance.CampaignFirstPlayerId)

	print("enemyid == ", BotApi.Instance.playerId)
	print("id_1st_enemy == ", BotApi.Instance.CampaignFirstEnemyId)
	print("id_defenderbot == ", BotApi.Instance.CampaignDefenderBotId)
	print("id_1st_player == ", BotApi.Instance.CampaignFirstPlayerId)
	print("SpawnSide", spawnSide) 

	SetCEMissionVariables(botDefender)
end

local waveSpawnPossible
local waveSpawnActive = true
local waveUnitCount = 0
local waveNumber = 0
function WaveAttack()
	if not botDefender then
		waveSpawnPossible = true
	end

	if forceUnitCount >= forceUnitCountMax then
		if printDebug then print("Print: forceUnitCount max reached: ", forceUnitCount, " Disabling unit priority override") end
		forceUnitPriority = false
		forceUnitCount = 0
	end

	if waveSpawnPossible then
		if waveUnitCount >= waveUnitTotal then			
			waveUnitTotal = math.random(WaveUnit.Min, WaveUnit.Max)
			waveSpawnActive = false
			waveUnitCount = 0
			waveNumber = waveNumber + 1
			if printDebug then 
				print("Print: waveNumber", waveNumber) 
			    print("WaveUnit.Min = ", WaveUnit.Min)
			    print("WaveUnit.Max = ", WaveUnit.Max)
				print("Print: waveUnitTotal", waveUnitTotal) 
			end
		else
			waveSpawnActive = true
			if printDebug then print("Print: waveSpawnActive = ", waveSpawnActive) end
		end
	end
end

function WaveUnitCounter()
	if waveSpawnPossible then
		waveUnitCount = waveUnitCount + 1
		if printDebug then print("Print: waveUnitCount =", waveUnitCount) end
	
		if forceUnitPriority then 
			forceUnitCount = forceUnitCount + 1
			if printDebug then print("Print: forceUnitCount =", forceUnitCount) end
		end
	end
end

local firstPurchase = true
function GameModeSpawnCooldown()
	WaveAttack()
	local spawnTime
	-- Bot defender and first buy
	if botDefender and firstPurchase then
		spawnTime = {Min = StartSpawnTime.DefenseMin, Max = StartSpawnTime.DefenseMax}
	-- Bot attacker and first buy
	elseif firstPurchase then
		spawnTime = {Min = StartSpawnTime.AttackMin, Max = StartSpawnTime.AttackMax}
	-- Bot entering wave cooldown
	elseif not waveSpawnActive then
		spawnTime = {Min = SpawnCooldownTime.DCGWaveOffMin, Max = SpawnCooldownTime.DCGWaveOffMax}
	else
		spawnTime = {Min = SpawnCooldownTime.DCGMin, Max = SpawnCooldownTime.DCGMax}
	end

	if challenge_map then
      	if botDefender then
          	spawnTime =  {Min = 9999 * 60 * 1000,  Max = 9999 * 60 * 1000} 
      	end
 	end 

	local cooldown = math.random(spawnTime.Min, spawnTime.Max)
	firstPurchase = false
	return cooldown
end

function table.shuffle(tbl)
	local rand = math.random
	for i = #tbl, 2, -1 do
	  local j = rand(i)
	  tbl[i], tbl[j] = tbl[j], tbl[i]
	end
	return tbl
end
  
-- Function to shuffle the flags table
local function shuffleFlags(flags)
	if waveNumber <= 1 then
		table.sort(flags, function(a, b) return a.name < b.name end)
	else
		table.shuffle(flags)
	end
end

-- Function to calculate flag priority for attacker
local function calculateAttackerPriority(f, enemyTeam, team, firstEnemyFlagEncountered)
    if f.owner == enemyTeam and not firstEnemyFlagEncountered then
        firstEnemyFlagEncountered = true
        return f.priority, firstEnemyFlagEncountered
    elseif f.owner == enemyTeam or f.owner == team then
        return f.priority * 0, firstEnemyFlagEncountered
    end
    return f.priority, firstEnemyFlagEncountered
end

-- Function to calculate flag priority for defender
local function calculateDefenderPriority(f, enemyTeam, team)
    if f.owner == enemyTeam then
        return f.priority * 2
    elseif f.owner == team then
        return f.priority * 0.5
    end
    return f.priority
end

function GetFlagToCapture(flagPoints, getPriority, flags)
	local alliedFlags, opponentFlags, neutralFlags, totalFlags = CalculateFlagStatistics(BotApi.Scene.Flags)
	local capturableFlags = CalculateCapturableFlags(totalFlags, alliedFlags)

	PrintFlagDebugInfo(alliedFlags, opponentFlags, neutralFlags, totalFlags, capturableFlags, teamIsLosing)
    
    searchDestroy = CalculateSearchDestroyValue(capturableFlags, alliedFlags, opponentFlags)
	-- searchDestroy = 10

	if waveNumber <= 1 then
        shuffleFlags(flags)
    end
	local firstEnemyFlagEncountered = false

	return GetRandomItem(flags, function(f)
		if not botDefender then
			-- bot prioritize one flag (1st in flags table that is enemy)
			local priority
			priority, firstEnemyFlagEncountered = calculateAttackerPriority(f, enemyTeam, team, firstEnemyFlagEncountered)
			return priority
		else
			return calculateDefenderPriority(f, enemyTeam, team)
		end
	end)
end

function GetCurrentSpawnWaitTime()
    return UnitSpawnWaitTime
end

function GetUnitToSpawn(units)
	if not units then
		return nil
	end
	
	local unitsToSpawn = {}
	
	local income = BotApi.Commands:Income(BotApi.Instance.playerId)

	if printDebug then print("Player#".. BotApi.Instance.playerId.. " Units") end
	for i, unit in pairs(units) do
		local min_team = unit.min_team  -- not used
		local min_income = unit.min_income -- not used
		local available = BotApi.Commands:IsUnitAvailable(unit.unit)
		if unit.maxUnitCount then 
			local currentUnitCount = 0
			if currentUnitCountTable[unit.unit] then 
				currentUnitCount = currentUnitCountTable[unit.unit] 
			end
			if unit.maxUnitCount and currentUnitCount >= unit.maxUnitCount  then 
				available = false
				if printDebug then print("Max allowed count of " .. unit.maxUnitCount .. " for " .. unit.unit .. " reached! Unit not available!") end
			end
		end
		if not min_income then min_income = -1 end
		if not min_team then min_team = 0 end
		
		--if printDebug then print("------ Unit", unit.unit) end

		if teamSize >= min_team and income >= min_income and available then
			table.insert(unitsToSpawn, unit)
		end
	end

	-- TODO: instead of return nil, find the shortest tts and delay calling function again by that time 
	if #unitsToSpawn == 0 then
		return nil
	end

	return GetRandomItem(unitsToSpawn, function(t)
		return GetUnitPriority(t)
	end)
end

function OnGameStart()
	NoresusOnGameStart()
	CheckIfChallengeMap()
    isAttackerOrDefender()
    setVarsInMissionScript()
    OnGameStartUtility("conquest", waveUnitTotal)
end

function OnGameQuant()
	TrySpawnUnit()

	local waypoints = BotApi.Scene.Waypoints
	if #waypoints == 0 then
		for i, squad in pairs(BotApi.Scene.Squads) do
			if not Context.SquadTimers[squad] then
				if printDebug then print("SQUAD ", squad, " SquadTimers = nil") end
				SetSquadOrder(CaptureFlag, squad, math.random(OrderRotationPeriod.DCG.Min, OrderRotationPeriod.DCG.Max), true)
			end
		end
	end
end

function GotoNextWaypoint(squad)
	local waypoints = BotApi.Scene.Waypoints
	BotApi.Commands:CaptureFlag(squad, waypoints[math.random(#waypoints)]) --captureflag is basically gothereandattack
	if printDebug then print("Print: #captureFlag call inside GoToNextWaypoint") end
end

function OnWaypoint(args)
	if printDebug then print("Print: #GotoNextWaypoint call inside OnWaypoint") end
	GotoNextWaypoint(args.squadId)
end

-- NOTE: Returns true if squad tagged "_lua_mi" or "_lua_alert".
-- NOTE: "_lua_mi" = reserved for mission script use.
-- NOTE: "_lua_alert" = squad abruptly runs into enemy force seek&destroy.
-- NOTE: Returns true if squad tagged "_lua_need_next_order" for general ignore.
function IsSquadInScript(squad)
	if BotApi.Scene:IsSquadTagged(squad, "_lua_mi") or BotApi.Scene:IsSquadTagged(squad, "repairing") then
		if printDebug then print("Print: SQUADinSCRIPT thus no action squad", squad, "Player#",BotApi.Instance.playerId, "Team", team) end
		return true
	elseif BotApi.Scene:IsSquadTagged(squad, "_lua_alert") then
		if printDebug then print("Print: SQUADinALERT thus seek by squad", squad, "Player#",BotApi.Instance.playerId, "Team", team) end
		BotApi.Commands:SeekAndDestroy(squad)
		return true
	end
end

	-- NOTE: Returns true if squad tagged "_lua_ignore" for general ignore.
function IsSquadToIgnore(squad)
	if BotApi.Scene:IsSquadTagged(squad, "_lua_ignore") then
		return true
	end
end
function IsSquadToAlwaysIgnore(squad)
	if BotApi.Scene:IsSquadTagged(squad, "_lua_always_ignore") then
		return true
	end
end
function IsSquadInCombat(squad)
	if BotApi.Scene:IsSquadTagged(squad, "_lua_alert") then
		if printDebug then print("Print: SQUADinALERT thus seek by squad", squad, "Player#",BotApi.Instance.playerId, "Team", BotApi.Instance.team) end
		BotApi.Commands:SeekAndDestroy(squad)
		return true
	end
end
function IsSquadForceNextOrder(squad)
	if BotApi.Scene:IsSquadTagged(squad, "force_next_order") then
		return true
	end
end

function CaptureFlag(squad)
	if not BotApi.Scene:IsSquadExists(squad) then
		return
	end		

	if squad == sceneVariableSquad then
		return
	end

	if IsSquadToAlwaysIgnore(squad) then
		if printDebug then print("Print: SQUAD always ignored thus no action squad ", squad, "Player#", BotApi.Instance.playerId) end
		return
	end
	local rndAI = math.random()
	local flags = {}
    for i, flag in pairs(BotApi.Scene.Flags) do
        table.insert(flags, {id = i, name = flag.name, priority = getDefaultFlagPriority(flag), owner = flag.occupant})
    end
	
	local flag = GetFlagToCapture(BotApi.Scene.Flags, getDefaultFlagPriority, flags)

	if not flag then
		if printDebug then print("Print: No Flags so SeekAndDestroy by squad ", squad, "Player#", BotApi.Instance.playerId) end
		BotApi.Commands:SeekAndDestroy(squad)
		return
	end

	if IsSquadInCombat(squad) then
		if printDebug then print("Print: SQUADinSCRIPT/inFlag thus no action squad ", squad, "Player#", BotApi.Instance.playerId) end
		return
	end

	if IsSquadInScript(squad) then
		if printDebug then print("Print: SQUADinSCRIPT/inFlag thus no action squad ", squad, "Player#", BotApi.Instance.playerId) end
		return
	end

	if IsSquadToIgnore(squad) then
		if searchDestroy > rndAI then
			if printDebug then print("Print: [see_enemy] seek by squad ", squad, "Player#", BotApi.Instance.playerId) end
			BotApi.Commands:SeekAndDestroy(squad)
			return
		else
			if printDebug then print("Print: [see_enemy] do nothing by squad ", squad, "Player#", BotApi.Instance.playerId) end
			return
		end
	end

	-- if printDebug then print("Print: SQUAD needs the next order", squad, "Player#", BotApi.Instance.playerId) end
	if searchDestroy > rndAI then
		if printDebug then print("Print: [see_enemy] seek by squad ", squad, "Player#", BotApi.Instance.playerId) end
		BotApi.Commands:SeekAndDestroy(squad)
		return 
	else	
		if printDebug then print("Print: [notags] ctf by squad", squad, "Player#", BotApi.Instance.playerId, "Flag name: ", flag.name) end
		return BotApi.Commands:CaptureFlag(squad, flag.name)
	end
end

function OnGameSpawn(args)
	if not sceneVariableSquad then 
		sceneVariableSquad = args.squadId 
		if printDebug then print("Print: SQAUD ", args.squadId, " set as scene variable.") end
		SetSquadOrder(CaptureFlag, args.squadId, generalSquadTagCheckDelay, false)
		return
	else
		if not ai_attack_started then
			ai_attack_started = true
			BotApi.Scene:SetVar("ai_attack_started", 1)
			print("AI has started their attack!")
			SelectAiSpawnStrategy()
		end
		DefaultSquadSpawnOrders(args)
	end
end

function DefaultSquadSpawnOrders(args)
	local squadTypes = DoubleQueue.popLeft(unitsToSpawnQueue)
	local unitFollowWaypointGraph = true
	local isAircaft = false
	local isCannon = false
	local function UnitType (val, types)
		for index, value in ipairs(types) do
			if value == "Cannon" then 
				unitFollowWaypointGraph = false
				isCannon = true
				return false
			elseif value == "Aircraft" then
				isAircaft = true
				return false		
			elseif value == val then
				return true
			end
		end
		return false
	end
	
	if printDebug then print("Popping off next squad that spawed from the unitsToSpawnQueue. Queue size is now ", DoubleQueue.size(unitsToSpawnQueue)) end
	-- if followWaypointGraphs then 
	-- 	if UnitType("AT", squadTypes) then 
	-- 		if UnitType("Tank", squadTypes) or UnitType("Vehicle", squadTypes) or UnitType("Armored", squadTypes) then
	-- 			unitFollowWaypointGraph = false
	-- 		end
	if UnitType("Tank", squadTypes) then 
		if UnitType("Support", squadTypes) then
			unitFollowWaypointGraph = false
		end
	end


	local waypoints = BotApi.Scene.Waypoints
	if #waypoints == 0 then
		if isAircaft then
			if printDebug then print("SQUAD  ", args.squadId, " with unit type: airplane is following waypoint graph!") end
			SetSquadOrder(CaptureFlag, args.squadId, OrderRotationPeriod.DCG_FLANK.Max, false)
		elseif followWaypointGraphs and unitFollowWaypointGraph then
			if printDebug then print("SQUAD  ", args.squadId, " with unit type: ", type, " following waypoint graph!") end
			SetSquadOrder(CaptureFlag, args.squadId, OrderRotationPeriod.InitialUnitSpawnTimeout, false)
		else
			if printDebug then print("SQUAD  ", args.squadId, " with unit type: ", type, " using vanilla logic!") end
            local orderDelay = OrderRotationPeriod.DCG.Min - 1.5 * 60000
			-- if botDefender then 
				-- orderDelay = orderDelay + 2.5 * 60000
			-- end		
            SetSquadOrder(CaptureFlag, args.squadId, orderDelay, true)
		end
	else
		GotoNextWaypoint(args.squadId)
		if printDebug then print("Print: #waypoints != 0") end
	end
end

BotApi.Events:Subscribe(BotApi.Events.GameStart, OnGameStart)
BotApi.Events:Subscribe(BotApi.Events.GameEnd, OnGameStop)
BotApi.Events:Subscribe(BotApi.Events.Quant, OnGameQuant)
BotApi.Events:Subscribe(BotApi.Events.GameSpawn, OnGameSpawn)
BotApi.Events:Subscribe(BotApi.Events.Waypoint, OnWaypoint)