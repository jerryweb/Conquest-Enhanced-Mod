-- File created by Hawka
require([[/script/multiplayer/modes/bot.ai_logic]])
-- =================== Vanilla Variable Redefines ==================
-- Time from start of match AI will wait before attempting to buy a unit.
StartSpawnTime = {
 -- Bot is defender
 DefenseMin = 5 * 1000, 
 DefenseMax = 7 * 1000,
 -- Bot is attacker
 AttackMin = 6 * 60000, 
 AttackMax = 8 * 60000,
}

-- Time from last purchase AI will wait before attempting to buy a new unit.
SpawnCooldownTime = {
 -- Time between each wave
 DCGWaveOffMin = 2 * 60000, 
 DCGWaveOffMax = 2.5 * 60000,
 -- Time between each spawn
 DCGMin = 2 * 1000, 
 DCGMax = 7 * 1000,
}


-- Number of possible units than can be in a wave attack
WaveUnit = {
 Min = 7,
 Max = 10,
}

Context = {
  Purchase = nil,
  SpawnInfo = nil,
  SpawnWait = {
    CooldownTimer = nil,
    WaitTimer = nil
  },
  SquadTimers = {},
  GeneralSquadTagCheckTimer = nil,
  InitialSceneTimerCheck = nil,
  AiSpawnMoveTimer = nil
}


-- =================== CE Mechanics Variable Set Functions ==================
challenge_map = false
function CheckIfChallengeMap()
  challenge_map = false
  for i, flag in pairs(BotApi.Scene.Flags) do
    if flag.name == "f99" or flag.name == "f98" or flag.name == "f97" or flag.name == "f96" or flag.name == "f95" then
      challenge_map = true

      break
    end
  end
  print("challenge map check = ", challenge_map)
end

local function checkMapAIMovementLogic(flagName)
  print("checking flags to disable custom waypoints")
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

function SetCEMissionVariables(botDefender)
  BotApi.Scene:SetVar("noresusenabled", enabledNoresus)
  print("enabledNoresus == ", enabledNoresus)

  local totalFlags = 0
  for i, flag in pairs(BotApi.Scene.Flags) do
    -- print("i: ", i)
    print("flag name: ", flag.name)
    print("flag occupant: ", flag.occupant)
    
    if followWaypointGraphs then
      checkMapAIMovementLogic(flag.name)
    end
    totalFlags = totalFlags + 1
  end

  if followWaypointGraphs then
      BotApi.Scene:SetVar("enable_ai_waypoint_graphs", 1)
  else
      BotApi.Scene:SetVar("enable_ai_waypoint_graphs", 0)
  end

  checkVarPercentage("enable_ce_radio_mechanic", enableRadioMechanics)
  checkVarPercentage("enable_ce_cut_communications_mechanic", enableCommunicationsCutMechanics)
  checkVarPercentage("ai_sabotage", enableSabotageMechanics)
  checkVarPercentage("enable_ai_abandon_mechanics", enableAiAbandonMechanics)
  -- only run rear attack script if bot is attacking
  BotApi.Scene:SetVar("max_ai_defender_emplacement_count_level_1", AiDefenderCount.Defending.emplacement.defenseLevelOne)
  BotApi.Scene:SetVar("max_ai_defender_emplacement_count_level_2", AiDefenderCount.Defending.emplacement.defenseLevelTwo)
  BotApi.Scene:SetVar("max_ai_defender_emplacement_count_level_3", AiDefenderCount.Defending.emplacement.defenseLevelThree)
  if botDefender then
    enableRearAttackMechanics = 0
    if challenge_map then
      BotApi.Scene:SetVar("max_ai_defender_inf_per_flag_count", AiDefenderCount.Defending.challengeMaps.infantry.perFlag)
      BotApi.Scene:SetVar("max_ai_defender_at_flag", AiDefenderCount.Defending.infantry.max_ai_defender_at_flag)
      -- BotApi.Scene:SetVar("max_ai_defender_inf_count", AiDefenderCount.Defending.challengeMaps.infantry.max)
      BotApi.Scene:SetVar("max_ai_inf_def_x5_count", AiDefenderCount.Defending.challengeMaps.infantry.x5_cloneClount)
    else
      print("setting ai defender count for bot defending")
      BotApi.Scene:SetVar("max_ai_defender_inf_per_flag_count", AiDefenderCount.Defending.infantry.perFlag)
      BotApi.Scene:SetVar("max_ai_defender_at_flag", AiDefenderCount.Defending.infantry.max_ai_defender_at_flag)
      -- BotApi.Scene:SetVar("max_ai_defender_inf_count", AiDefenderCount.Defending.infantry.max)
      BotApi.Scene:SetVar("max_ai_inf_def_x5_count", AiDefenderCount.Defending.infantry.x5_cloneClount) 
    end
  else
     if challenge_map then
       BotApi.Scene:SetVar("max_ai_defender_inf_per_flag_count", AiDefenderCount.Attacking.challengeMaps.infantry.perFlag)
       BotApi.Scene:SetVar("max_ai_defender_at_flag", AiDefenderCount.Attacking.infantry.max_ai_defender_at_flag)
      -- BotApi.Scene:SetVar("max_ai_defender_inf_count", AiDefenderCount.Attacking.challengeMaps.infantry.max)
      BotApi.Scene:SetVar("max_ai_inf_def_x5_count", AiDefenderCount.Attacking.challengeMaps.infantry.x2_cloneClount)
      BotApi.Scene:SetVar("max_ai_defender_emplacement_total_count", AiDefenderCount.Attacking.challengeMaps.emplacement.perFlag * totalFlags)
     else
      print("setting ai defender count for bot attacking")
      BotApi.Scene:SetVar("max_ai_defender_at_flag", AiDefenderCount.Attacking.infantry.max_ai_defender_at_flag)
      -- BotApi.Scene:SetVar("max_ai_defender_inf_count", AiDefenderCount.Attacking.infantry.max)
      BotApi.Scene:SetVar("max_ai_defender_inf_per_flag_count", AiDefenderCount.Attacking.infantry.perFlag)
      BotApi.Scene:SetVar("max_ai_inf_def_x5_count", AiDefenderCount.Attacking.infantry.x2_cloneClount)
      BotApi.Scene:SetVar("max_ai_defender_emplacement_total_count", AiDefenderCount.Attacking.emplacement.perFlag * totalFlags)
    end
  end
  -- checkVarPercentage("enable_rear_attack_mechanic", enableRearAttackMechanics)
  checkRearAttackPercentage()
  BotApi.Scene:SetVar("max_ai_defender_emplacement_count_level_1", AiDefenderCount.Defending.emplacement.defenseLevelOne)
  BotApi.Scene:SetVar("max_ai_defender_emplacement_count_level_2", AiDefenderCount.Defending.emplacement.defenseLevelTwo)
  BotApi.Scene:SetVar("max_ai_defender_emplacement_count_level_3", AiDefenderCount.Defending.emplacement.defenseLevelThree)
  -- BotApi.Scene:SetVar("force_ai_direct_attack_logic", force_ai_direct_attack_logic)
end

function KillGeneralSquadTagCheckTimer()
  if Context.GeneralSquadTagCheckTimer then 
    BotApi.Events:KillQuantTimer(Context.GeneralSquadTagCheckTimer)
    Context.GeneralSquadTagCheckTimer = nil
  end
end

function KillInitialSceneCheckTimer()
  if Context.InitialSceneTimerCheck then
    BotApi.Events:KillQuantTimer(Context.InitialSceneTimerCheck)
    Context.InitialSceneTimerCheck = nil
  end
end

function KillAiSpawnMoveTimer()
  if Context.AiSpawnMoveTimer then
    BotApi.Events:KillQuantTimer(Context.AiSpawnMoveTimer)
    Context.AiSpawnMoveTimer = nil
  end
end

function SelectAiSpawnStrategy()
  print("in SelectAiSpawnStrategy function")
  Context.AiSpawnMoveTimer = BotApi.Events:SetQuantTimer(
    function()
      math.randomseed(os.time())
      local changeSpawnStrategyChance = 0.4

      if math.random() < changeSpawnStrategyChance then
        local aiSpawnStrategy = 0
        if enableRearAttackMechanics == 1 then
          aiSpawnStrategy = math.random(0, 6)
        else 
          aiSpawnStrategy = math.random(0, 5)
        end

        print("Ai spawn strategy = ", aiSpawnStrategy)
        if aiSpawnStrategy == 5 or aiSpawnStrategy == 6 then 
          followWaypointGraphs = false
          BotApi.Scene:SetVar("enable_ai_waypoint_graphs", 0)  
        else 
          followWaypointGraphs = true
          BotApi.Scene:SetVar("enable_ai_waypoint_graphs", 1)
        end
        BotApi.Scene:SetVar("change_ai_spawns", 1)
        BotApi.Scene:SetVar("ai_spawn_strategy", aiSpawnStrategy)
      end
    end, checkAiSpawnMoveDelay)
end

function SetFirstWaveOffset(flagCount)
  if flagCount == 1 then
    StartSpawnTime = oneFlagOffsetTime
  elseif flagCount == 2 then
    StartSpawnTime = twoFlagOffsetTime
  elseif flagCount == 3 then
    StartSpawnTime = threeFlagOffsetTime
  elseif flagCount == 4 then
    StartSpawnTime = fourFlagOffsetTime
  elseif flagCount == 5 then
    StartSpawnTime = fiveFlagOffsetTime
  end

  if testing then
    StartSpawnTime.DefenseMin = firstWaveOffsetTimeForTesting 
    StartSpawnTime.DefenseMax = firstWaveOffsetTimeForTesting
    StartSpawnTime.AttackMin = firstWaveOffsetTimeForTesting
    StartSpawnTime.AttackMax = firstWaveOffsetTimeForTesting
  end 

  StartSpawnTime.DefenseMin = StartSpawnTime.DefenseMin * 60000
  StartSpawnTime.DefenseMax = StartSpawnTime.DefenseMax * 60000
  StartSpawnTime.AttackMin = StartSpawnTime.AttackMin * 60000
  StartSpawnTime.AttackMax = StartSpawnTime.AttackMax * 60000
end

function SetCEWaveSettings()
  print("TESTING MODE = ", testing)
  local totalFlags = 0
  for i, flag in pairs(BotApi.Scene.Flags) do
    totalFlags = totalFlags + 1
  end

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

  if printDebug then 
    print("WaveUnit.Min = ", WaveUnit.Min)
    print("WaveUnit.Max = ", WaveUnit.Max)
  end

  SetFirstWaveOffset(totalFlags)
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

-- =================== Double Queue Data Structure ==================
DoubleQueue = {}
function DoubleQueue.new ()
  return {first = 0, last = -1}
end

function DoubleQueue.pushRight (list, value)
  local last = list.last + 1
  list.last = last
  list[last] = value
end

function DoubleQueue.popLeft (list)
  local first = list.first
  if first > list.last then error("list is empty") end
  local value = list[first]
  list[first] = nil        -- to allow garbage collection
  list.first = first + 1
  return value
end

function DoubleQueue.size(list)
  local first = list.first
  if first > list.last then return 0 
  else return math.abs(list.last - first) + 1 end
end
