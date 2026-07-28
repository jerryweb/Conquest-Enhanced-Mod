-- File created by Hawka
require([[/script/multiplayer/modes/spawn_logic]])

-- =================== CE AI Variables ==================
followWaypointGraphs = false
generalSquadTagCheckDelay = 10 * 1000
sceneVariableSquad = nil 
currentUnitCountTable = {}
DynamicWeatherTimer = nil


local intialSceneEnvironmentCheck = false
local environment = nil
local aiSpawnStrategy = 0
local aiSpawnSelectionDelay = 3 * 60000


-- =================== Debug Utilities ==================

function printArray(arr)
    if type(arr) ~= "table" then
        print("Error: Expected a table.")
        return
    end

    -- table.concat joins array elements into a single string separated by ", "
    return "{ " .. table.concat(arr, ", ") .. " }"
end

-- ===================== Timers ================

function KillSceneCheckTimer()
  if Context.SceneCheckTimer then
    BotApi.Events:KillQuantTimer(Context.SceneCheckTimer)
    Context.SceneCheckTimer = nil
  end
end

function StartSceneCheckTimer()
  local setSceneCheckTimer = nil
  local setCEWaypointSystemCheckTimer = nil

  setCEWaypointSystemCheckTimer = BotApi.Events:SetQuantTimer(
    function()
      setCEWaypointSystemCheckTimer = nil
      print("checking if ce waypoint system active")
      if BotApi.Scene:IsSquadTagged(sceneVariableSquad, "_ce_map_scripts_running") then
        print("Vanilla Map Loaded!!! Disabling CE bot file logic")
        followWaypointGraphs = true         
        BotApi.Scene:SetVar("enable_ai_waypoint_graphs", 1)  
      else
        followWaypointGraphs = false  
        BotApi.Scene:SetVar("enable_ai_waypoint_graphs", 0)
      end
      print("CUSTOM WAYPOINTS = ", followWaypointGraphs)
    end, 1000)
    
  setSceneCheckTimer = function(callback)
      Context.SceneCheckTimer = BotApi.Events:SetQuantTimer(
        function()
          if printDebug then print("checking scene variable") end         
          Context.SceneCheckTimer  = nil
          CheckSceneVariable(sceneVariableSquad)
          callback(callback)          
        end, generalSquadTagCheckDelay)
    end
    setSceneCheckTimer(setSceneCheckTimer)
end

function SetGeneralSquadTagCheckTimer()
  local setTagCheckTimer = nil 
  setTagCheckTimer = function(callback)
    Context.GeneralSquadTagCheckTimer = BotApi.Events:SetQuantTimer(
      function()
        Context.GeneralSquadTagCheckTimer = nil
        for i, squad in pairs(BotApi.Scene.Squads) do
          if IsSquadNeedNextOrder(squad) then
            if printDebug then print("squad ", squad, " getting next order") end
            Context.SquadTimers[squad] = nil
          end
        end
        callback(callback)
      end,
      generalSquadTagCheckDelay)
    end
  setTagCheckTimer(setTagCheckTimer)
end

function KillGeneralSquadTagCheckTimer()
  if Context.GeneralSquadTagCheckTimer then 
    BotApi.Events:KillQuantTimer(Context.GeneralSquadTagCheckTimer)
    Context.GeneralSquadTagCheckTimer = nil
  end
end

function SetDynamicWeatherTimer()
  local weatherTimer = SetDynamicWeatherVariables()
  print("Print: dynamic weather apply delay = ", weatherTimer / 1000, "seconds")
  DynamicWeatherTimer = BotApi.Events:SetQuantTimer(
    function() 
      local weather_selection = math.random(1, maxWeatherOptions[environment])
      if weather_selection_override then 
          weather_selection = weather_selection_override
        end
      print("Setting dynamic weather selection =  ", weather_selection)
      BotApi.Scene:SetVar("weather_selection", weather_selection)
      KillDynamicWeatherTimer()
    end, 
    weatherTimer)
end

function KillDynamicWeatherTimer()
  if DynamicWeatherTimer then
    BotApi.Events:KillQuantTimer(DynamicWeatherTimer)
    DynamicWeatherTimer = nil
  end
end

-- =====================================
function SetCEWaveSettings(SpawnCooldownTime, WaveUnit, botDefender)
  print("TESTING MODE = ", testing)

  if botDefender then
    WaveUnit.Min = WaveUnitOverride.DefendMin
    WaveUnit.Max = WaveUnitOverride.DefendMax
    SpawnCooldownTime.DCGWaveOffMin = DCGWaveOffOverwrite.DefenseMinWaveOff
    SpawnCooldownTime.DCGWaveOffMax = DCGWaveOffOverwrite.DefenseMaxWaveOff
  else
    WaveUnit.Min = WaveUnitOverride.AttackMin
    WaveUnit.Max = WaveUnitOverride.AttackMax
    SpawnCooldownTime.DCGWaveOffMin = DCGWaveOffOverwrite.AttackMinWaveOff
    SpawnCooldownTime.DCGWaveOffMax = DCGWaveOffOverwrite.AttackMaxWaveOff
  end

  return SpawnCooldownTime, WaveUnit
end

local function checkMapAIMovementLogic(flagName)
  if followWaypointGraphs == true then 
    for i = 1, 5, 1 do 
        if flagName == "f1" .. i then
        followWaypointGraphs = false
        print("flag name ", flagName, " disable waypoints")
        break
        end
    end
  end
  
  if followWaypointGraphs == true then 
    for f = 5, 9, 1 do 
        if flagName == "f9" .. f then
        followWaypointGraphs = false
        print("challenge map, disable waypoints")
        break
        end
    end
  end
end

local function checkVarPercentage(varName, varPecetage)
  math.randomseed(os.time())
  if varPecetage >= math.random() then
    varPecetage = 1
  else 
    varPecetage = 0
  end
  BotApi.Scene:SetVar(varName, varPecetage)

  print(varName .. " = ", varPecetage)
end

local function checkRearAttackPercentage()
  if enableRearAttackMechanics >= math.random() then
    enableRearAttackMechanics = 1
  else 
    enableRearAttackMechanics = 0
  end
  BotApi.Scene:SetVar("enable_rear_attack_mechanic", enableRearAttackMechanics)

  print("enable_rear_attack_mechanic" .. " = ", enableRearAttackMechanics)
end

function SetCEMissionVariables(botDefender, botDifficulty)
  if botDefender then 
    if botDifficulty == 4 then 
      botDifficultyModifier = AiDefenderCount.Attacking.difficultyModifier.heroic
    elseif botDifficulty == 3 then 
      botDifficultyModifier = AiDefenderCount.Attacking.difficultyModifier.hard
    elseif botDifficulty == 2 then 
      botDifficultyModifier = AiDefenderCount.Attacking.difficultyModifier.normal
    else 
      botDifficultyModifier = AiDefenderCount.Attacking.difficultyModifier.easy
    end
  else 
    if botDifficulty == 4 then 
      botDifficultyModifier = AiDefenderCount.Defending.difficultyModifier.heroic
    elseif botDifficulty == 3 then 
      botDifficultyModifier = AiDefenderCount.Defending.difficultyModifier.hard
    elseif botDifficulty == 2 then 
      botDifficultyModifier = AiDefenderCount.Defending.difficultyModifier.normal
    else 
      botDifficultyModifier = AiDefenderCount.Defending.difficultyModifier.easy
    end
  end
  print("botDifficultyModifier = ", botDifficultyModifier)

  BotApi.Scene:SetVar("noresusenabled", enabledNoresus)
  print("enabledNoresus == ", enabledNoresus)

  local totalFlags = 0
  print("checking flags to disable custom waypoints")
  for i, flag in pairs(BotApi.Scene.Flags) do
    -- print("i: ", i)
    print("flag name: ", flag.name)
    print("flag occupant: ", flag.occupant)

    totalFlags = totalFlags + 1
    
    if followWaypointGraphs then
      checkMapAIMovementLogic(flag.name)
    end
  end
  if printDebug then print("totalFlags: ", totalFlags) end

  checkVarPercentage("enable_ce_radio_mechanic", enableCommunicationsCutMechanics) -- use this to control both variables for now
  checkVarPercentage("enable_ce_cut_communications_mechanic", enableCommunicationsCutMechanics)
  checkVarPercentage("ai_sabotage", enableSabotageMechanics)
  checkVarPercentage("enable_ai_abandon_mechanics", enableAiAbandonMechanics)

  -- only run rear attack script if bot is attacking
  BotApi.Scene:SetVar("max_ai_defender_emplacement_count_level_1", AiDefenderCount.Defending.emplacement.defenseLevelOne)
  BotApi.Scene:SetVar("max_ai_defender_emplacement_count_level_2", AiDefenderCount.Defending.emplacement.defenseLevelTwo)
  BotApi.Scene:SetVar("max_ai_defender_emplacement_count_level_3", AiDefenderCount.Defending.emplacement.defenseLevelThree)


  if botDefender then
    enableRearAttackMechanics = 0
      print("setting ai defender count for bot defending")
      BotApi.Scene:SetVar("max_ai_defender_inf_per_flag_count", AiDefenderCount.Defending.infantry.perFlag + botDifficultyModifier)
      BotApi.Scene:SetVar("max_ai_defender_at_flag", AiDefenderCount.Defending.infantry.max_ai_defender_at_flag)
      BotApi.Scene:SetVar("max_ai_inf_def_x5_count", AiDefenderCount.Defending.infantry.x5_cloneClount) 
  else
      print("setting ai emplacement defender count when bot attacking = ", AiDefenderCount.Attacking.emplacement.perFlag * totalFlags + 1)
      print("setting ai defender count when bot attacking = ",  AiDefenderCount.Attacking.infantry.perFlag + botDifficultyModifier)
      BotApi.Scene:SetVar("max_ai_defender_at_flag", AiDefenderCount.Attacking.infantry.max_ai_defender_at_flag)
      BotApi.Scene:SetVar("max_ai_defender_inf_per_flag_count", AiDefenderCount.Attacking.infantry.perFlag + botDifficultyModifier)
      BotApi.Scene:SetVar("max_ai_inf_def_x5_count", AiDefenderCount.Attacking.infantry.x2_cloneClount)
      BotApi.Scene:SetVar("max_ai_defender_emplacement_total_count", AiDefenderCount.Attacking.emplacement.perFlag * totalFlags + 1)

      print("max_ai_defender_emplacement_total_count = ", AiDefenderCount.Attacking.emplacement.perFlag * totalFlags + 1)
  end
  checkRearAttackPercentage()
end

function CheckUnitMaxCount(unit, available) 
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

  return available
end

function IncrementMaxUnitCount(unit)
  if currentUnitCountTable[unit] then
    currentUnitCountTable[unit] = currentUnitCountTable[unit] + 1
  else
    currentUnitCountTable[unit] = 1
  end
  -- if printDebug then print("Incrementing  ", unit, " unit count. Current unit count =", currentUnitCountTable[unit]) end
end

function DefaultSquadSpawnOrders(args, OrderRotationPeriod)
  local squadTypes = Context.SpawnInfo.type
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

  if UnitType("Tank", squadTypes) then 
    if UnitType("Support", squadTypes) then
      unitFollowWaypointGraph = false
    end
  end

  local waypoints = BotApi.Scene.Waypoints
  if #waypoints == 0 then
    local initialOrder = false
    local squadOrderDelay = math.random(OrderRotationPeriod.DCG.Min, OrderRotationPeriod.DCG.Max)
    
    if isAircaft then
      if not UnitType("ReconPlane", squadTypes) then
        if printDebug then print("SQUAD  ", args.squadId, " with unit type airplane is not using bot logic! This unit will rely on scripting!") end
        squadOrderDelay = OrderRotationPeriod.DCG_FLANK.Max
      end
    elseif isCannon then
      initialOrder = true
      if UnitType("Artillery", squadTypes) then
        if printDebug then print("SQUAD  ", args.squadId, " with unit type: Artillery is using vanilla logic!") end
        squadOrderDelay = OrderRotationPeriod.CannonTimeOut * 5
      else
        if printDebug then print("SQUAD  ", args.squadId, " with unit type: cannon is using vanilla logic!") end
        squadOrderDelay = OrderRotationPeriod.CannonTimeOut
      end
    elseif followWaypointGraphs and unitFollowWaypointGraph then
      if printDebug then print("SQUAD  ", args.squadId, " with unit type: ", printArray(squadTypes), " following waypoint graph!") end      
    else 
      if printDebug then print("SQUAD  ", args.squadId, " with unit type: ", printArray(squadTypes), " using vanilla logic!") end
      initialOrder = true  
    end 

    SetSquadOrder(CaptureFlag, args.squadId, squadOrderDelay, initialOrder)
  else
    GotoNextWaypoint(args.squadId)
    if printDebug then print("Print: #waypoints != 0") end
  end
end


function SetDynamicWeatherVariables()
  print("Print: setting dynamic weather delay")
  local weatherDelay = 9999 * 60 * 1000

  math.randomseed(os.time())
  if environment and enableDynamicWeather >=  math.random()  then
    weatherDelay = math.random(applyDelay.min, applyDelay.max)
  end 
  
  return weatherDelay
end

function SelectAiSpawnStrategy()
  local setAiSpawnStrategyTimer = nil

  setAiSpawnStrategyTimer = function(callback)
    aiSpawnStrategyTimer = BotApi.Events:SetQuantTimer(
      function()
        print("in SelectAiSpawnStrategy function")
        math.randomseed(os.time())
        local changeSpawnStrategyChance = 0.45

        if math.random() < changeSpawnStrategyChance then
          local prevAiSpawnStrategy = aiSpawnStrategy
          
          if enableRearAttackMechanics == 1 then
            aiSpawnStrategy = math.random(0, 3)
          else 
            aiSpawnStrategy = math.random(0, 2)
          end

          print("Ai spawn strategy = ", aiSpawnStrategy)
          if aiSpawnStrategy == 3 and prevAiSpawnStrategy ~= aiSpawnStrategy then 
            followWaypointGraphs = false
            BotApi.Scene:SetVar("enable_ai_waypoint_graphs", 0)  
          elseif prevAiSpawnStrategy == 3 and prevAiSpawnStrategy ~= aiSpawnStrategy  then
            followWaypointGraphs = true
            BotApi.Scene:SetVar("enable_ai_waypoint_graphs", 1)
          end

          print("followWaypointGraphs = ", followWaypointGraphs, " and ai_spawn_strategy = ", aiSpawnStrategy)
          if prevAiSpawnStrategy == 3 or aiSpawnStrategy == 3 and prevAiSpawnStrategy ~= aiSpawnStrategy then 
            BotApi.Scene:SetVar("change_ai_spawns", 1)       
          end
          BotApi.Scene:SetVar("ai_spawn_strategy", aiSpawnStrategy)
        end
        callback(callback)   
      end, aiSpawnSelectionDelay)
  end
  setAiSpawnStrategyTimer(setAiSpawnStrategyTimer)
end

function setAiSpawnIndex(SpawnPointIndex)
  if aiSpawnStrategy == 1 then -- spawn only points 1 and 4
      if SpawnPointIndex == 0 then 
        SpawnPointIndex = 3
      elseif SpawnPointIndex == 3 then 
        SpawnPointIndex = 0
      else 
        SpawnPointIndex = 0
      end
    elseif aiSpawnStrategy == 2 then -- spawn only points 2 and 3 
      if SpawnPointIndex == 1 then 
        SpawnPointIndex = 2
      elseif SpawnPointIndex == 2 then 
        SpawnPointIndex = 1
      else 
        SpawnPointIndex = 1
      end
    else
      SpawnPointIndex = SpawnPointIndex + 1
    end
  return SpawnPointIndex
end

-- =================== Check Squad Tags ==================
function SpawnSceneVariable()
  BotApi.Commands:Spawn("scene_variable", MaxSquadSize)
end

function IsSquadToAlwaysIgnore(squad)
  if BotApi.Scene:IsSquadTagged(squad, "_lua_always_ignore") then
    return true
  end
end

function IsSquadForceNextOrder(squad)
  if BotApi.Scene:IsSquadTagged(squad, "force_next_order") then
    return true
  end
end

function IsSquadNeedNextOrder(squad)
  if BotApi.Scene:IsSquadTagged(squad, "_lua_need_next_order") then
    return true
  end
end

-- Checks the squad scene variable for tagged info about the match
function CheckSceneVariable(squad)

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

    if not environment then
      if BotApi.Scene:IsSquadTagged(squad, "_autumn") then
        environment = "autumn"
    elseif BotApi.Scene:IsSquadTagged(squad, "_spring") then
        environment = "spring"
    elseif BotApi.Scene:IsSquadTagged(squad, "_summer") then
        environment = "summer"
    elseif BotApi.Scene:IsSquadTagged(squad, "_winter") then
        environment = "winter"
    end
  elseif environment and not intialSceneEnvironmentCheck then 
    print("Print: Scene evironment = ", environment)
    print("Print: Getting maxWeatherOptions with max size of ", maxWeatherOptions[environment])
    intialSceneEnvironmentCheck = true
    SetDynamicWeatherTimer()
  end
end

-- =================== Noresus Mechanics ==================
function NoresusOnGameStart()
  if enabledNoresus == 0 then
    print("Skipping Noresus setup logic")
    return
  end
  -- INITIAL STATS
  local salva = io.open("stats.start", "r")
  if salva==nil then
    salva = io.open("stats.start", "w")
    salva:write("first")
    salva:close()
  else
    playerCondition="COWARD"
    salva = io.open("stats.start", "w")
    salva:write(playerCondition)
    salva:close()
    OnGameStop()
  end
end

function NoresusOnGameEnd()
  if enabledNoresus == 0 then
    print("Skipping Noresus teardown logic")
    return
  end
  -- CREA IL FILE CON I RISULTATI DELLE BASI
  if playerCondition~="COWARD" then
    salva = io.open("stats.end", "w")
    for i, flag in pairs(BotApi.Scene.Flags) do
      local rig=""  
      for r, v in pairs(flag) do  -- base e team (2 cicli)
        rig=rig..v..";"
      end
      rig=string.sub(rig,1,-2)
      rig=rig.."\n"
      salva:write(rig)
    end
    salva:close()   
  end
end

