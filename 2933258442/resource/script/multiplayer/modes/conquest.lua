require([[/script/multiplayer/modes/utility]])

-- Time from start of match AI will wait before attempting to buy a unit.
local StartSpawnTime = {
	-- Bot is defender
	DefenseMin = 5 * 1000, 
	DefenseMax = 7 * 1000,
	-- Bot is attacker. Controlled by preptime now. 
	AttackMin = 1 * 1000, 
	AttackMax = 1 * 1000,
}

-- Time from last purchase AI will wait before attempting to buy a new unit.
local SpawnCooldownTime = {
	-- Time between each wave
	DCGWaveOffMin = 2 * 60000, 
	DCGWaveOffMax = 2.5 * 60000,
	-- Time between each spawn
	DCGMin = 2 * 1000, 
	DCGMax = 7 * 1000,
}

-- Number of possible units than can be in a wave attack
local WaveUnit = {
	Min = 7,
	Max = 10,
}

-- Sets time limit AI will wait for a unit it has chosen to buy if the unit is not yet available
local UnitSpawnWaitTime = 1.5 * 60000 -- 1:30min (ms) 

-- Time delay for units to get a new move order after spawn move order. Loops.
local OrderRotationPeriod = {
    DCG = { 
    	Min = 2 * 60000, -- 2:30 min (ms)
    	Max = 4 * 60000, -- 4:00 min (ms)
    }, -- 4:30 min (ms)
    DCG_FLANK = {
    	Min = 6 * 60000, -- 6:00 min (ms)
    	Max = 8 * 60000 -- 8:00 min (ms)
    },
    CannonTimeOut = 1.0 * 60000,
    InitialUnitSpawnTimeout = 0.5 * 60000,
}

local botDefender
enableWaveCounter = true

local waveSpawnPossible
local waveSpawnActive = true
local waveUnitCount = 0
local waveNumber = 0
local waveUnitTotal = math.random(WaveUnit.Min, WaveUnit.Max)
if printDebug then print("Print: initial waveUnitTotal", waveUnitTotal) end

local firstPurchase = true
local conquestSpawnPointIndex = 0

function GameModeSpawnUnit(unit, maxSquadSize)
	if BotApi.Commands:SpawnAt(unit, maxSquadSize, conquestSpawnPointIndex) then
		conquestSpawnPointIndex = setAiSpawnIndex(conquestSpawnPointIndex)
		return true
	end

	return false
end

local function isAttackerOrDefender()
	botDefender = not BotApi.Conquest.Attacking
	if printDebug then print("Print: botDefender", botDefender) end
end

local function setVarsInMissionScript()
	-- CE vars to set
	SpawnCooldownTime, WaveUnit = SetCEWaveSettings(SpawnCooldownTime, WaveUnit, botDefender)

	if printDebug then 
    	print("WaveUnit.Min = ", WaveUnit.Min)
    	print("WaveUnit.Max = ", WaveUnit.Max)
  	end

  	waveUnitTotal = math.random(WaveUnit.Min, WaveUnit.Max)
  	if printDebug then print("Print: setting initial waveUnitTotal", waveUnitTotal) end

	-- Mission script var is from the user's perspective.
	BotApi.Scene:SetVar("user_is_defender", botDefender and 0 or 1)

	local nationMap = { rus = 1, ger = 2, fin = 3, usa = 4, eng = 5, jap = 6 }
	local difficultyMap = { easy = 1, normal = 2, hard = 3, heroic = 4 }
	local spawnMap = { a = 1, b = 2 }
	local playerSpawnNameMap = {
		a1 = 1, a2 = 2, a3 = 3, a4 = 4,
		b1 = 5, b2 = 6, b3 = 7, b4 = 8,
	}

	BotApi.Scene:SetVar("bot_army", nationMap[BotApi.Instance.army] or 0)
	BotApi.Scene:SetVar("bot_difficulty", difficultyMap[BotApi.Instance.difficulty] or 0)
	BotApi.Scene:SetVar("bots_spawnside", spawnMap[spawnSide] or 0)
	BotApi.Scene:SetVar("player_spawn_name", playerSpawnNameMap[BotApi.Conquest.PlayerSpawnPoint] or 0)

	BotApi.Scene:SetVar("enemyid", BotApi.Instance.playerId)
	BotApi.Scene:SetVar("id_1st_enemy", BotApi.Conquest.FirstEnemyId)
	BotApi.Scene:SetVar("id_defenderbot", BotApi.Conquest.DefenderBotId)
	BotApi.Scene:SetVar("id_1st_player", BotApi.Conquest.FirstPlayerId)

	print("player_spawn_name == ", playerSpawnNameMap[BotApi.Conquest.PlayerSpawnPoint])
	print("bots_spawnside == ", spawnMap[spawnSide])
	print("enemyid == ", BotApi.Instance.playerId)
	print("id_1st_enemy == ", BotApi.Conquest.FirstEnemyId)
	print("id_defenderbot == ", BotApi.Conquest.DefenderBotId)
	print("id_1st_player == ", BotApi.Conquest.FirstPlayerId)

	SetCEMissionVariables(botDefender, difficultyMap[BotApi.Instance.difficulty] or 0)
end

function WaveAttack()
	if not botDefender then
		waveSpawnPossible = true
	end

	if forceUnitPriority and forceUnitCount >= forceUnitCountMax then
		if printDebug then print("Print: forceUnitCount max reached: ", forceUnitCount, " Disabling unit priority override") end
		forceUnitPriority = false
		forceUnitCount = 0
	end

	if waveSpawnPossible then
		if waveUnitCount >= waveUnitTotal then
			waveUnitTotal = math.random(WaveUnit.Min, WaveUnit.Max)
			if printDebug then print("Print: waveUnitTotal", waveUnitTotal) end
			waveSpawnActive = false
			waveUnitCount = 0
			waveNumber = waveNumber + 1
			if printDebug then print("Print: waveNumber", waveNumber) end
		else
			waveSpawnActive = true
		end
	end
end

function WaveUnitCounter()
	if waveSpawnPossible then
		waveUnitCount = waveUnitCount + 1
		if printDebug then print("Print: waveUnitCount =", waveUnitCount) end
	end

	if forceUnitPriority then 
		forceUnitCount = forceUnitCount + 1
		if printDebug then print("Print: forceUnitCount =", forceUnitCount) end
	end
end

function GameModeSpawnCooldown()
	WaveAttack()
	local spawnTime
	if botDefender and firstPurchase then
		spawnTime = {Min = StartSpawnTime.DefenseMin, Max = StartSpawnTime.DefenseMax}
	elseif firstPurchase then
		spawnTime = {Min = StartSpawnTime.AttackMin, Max = StartSpawnTime.AttackMax}
	elseif not waveSpawnActive then
		spawnTime = {Min = SpawnCooldownTime.DCGWaveOffMin, Max = SpawnCooldownTime.DCGWaveOffMax}
	else
		spawnTime = {Min = SpawnCooldownTime.DCGMin, Max = SpawnCooldownTime.DCGMax}
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

function CaptureFlag(squad)
	if IsSquadToAlwaysIgnore(squad) then
		if printDebug then print("Print: SQUAD always ignored thus no action squad ", squad, "Player#", BotApi.Instance.playerId) end
		return
	end

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

	if IsSquadInScript(squad) then
		return
	end

	if IsSquadToIgnore(squad) then
		local rndAI = math.random()
		if searchDestroy > rndAI then
			if printDebug then print("Print: [see_enemy] seek by squad ", squad, "Player#", BotApi.Instance.playerId) end
			BotApi.Commands:SeekAndDestroy(squad)
			return
		else
			if printDebug then print("Print: [see_enemy] donothing by squad ", squad, "Player#", BotApi.Instance.playerId) end
			return
		end
	end

	if printDebug then print("Print: [notags] ctf by squad", squad, "Player#", BotApi.Instance.playerId, "Flag name: ", flag.name) end
	return BotApi.Commands:CaptureFlag(squad, flag.name)
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

		available = CheckUnitMaxCount(unit, available)
		
		if not min_income then min_income = -1 end
		if not min_team then min_team = 0 end
		
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
    isAttackerOrDefender()
    setVarsInMissionScript()
    OnGameStartUtility("conquest", botDefender)
    waveUnitTotal = ActivateAiStrategy(waveUnitTotal)
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

function OnGameSpawn(args)
	if not sceneVariableSquad then 
		SelectAiSpawnStrategy()
		sceneVariableSquad = args.squadId 
		print("Spawned Scene variable successfully!")
		if printDebug then print("Print: SQAUD ", args.squadId, " set as scene variable.") end
		StartSceneCheckTimer()
		SetGeneralSquadTagCheckTimer()
		return
	else
		DefaultSquadSpawnOrders(args, OrderRotationPeriod)
	end
end

-- Notifies the mission script that player defense prep time is over.
function OnPrepTimeOver()
	SpawnSceneVariable()
	BotApi.Scene:SetVar("prep_inform", 1)	
	if printDebug then print("Print: prep_inform set to 1, Player defense prep is over.") end
end

BotApi.Events:Subscribe(BotApi.Events.GameStart, OnGameStart)
BotApi.Events:Subscribe(BotApi.Events.GameEnd, OnGameStop)
BotApi.Events:Subscribe(BotApi.Events.Quant, OnGameQuant)
BotApi.Events:Subscribe(BotApi.Events.GameSpawn, OnGameSpawn)
BotApi.Events:Subscribe(BotApi.Events.Waypoint, OnWaypoint)
BotApi.Events:Subscribe(BotApi.Events.PrepTimeOver, OnPrepTimeOver)