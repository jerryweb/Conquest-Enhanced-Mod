-- File created by Hawka
require([[/conquest_configuration/bot.conquest_configuration]])

-- =================== CE AI Variables ==================
checkIfVanillaMapLoaded = false
followWaypointGraphs = true
generalSquadTagCheckDelay = 10 * 1000
sceneVariableSquad = nil 

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
  for i, flag in pairs(BotApi.Scene.Flags) do
    -- print("i: ", i)
    print("flag name: ", flag.name)
    print("flag occupant: ", flag.occupant)
    
    if followWaypointGraphs then
      checkMapAIMovementLogic(flag.name)
    end
  end

  if followWaypointGraphs then
      BotApi.Scene:SetVar("enable_ai_waypoint_graphs", 1)
  else
      BotApi.Scene:SetVar("enable_ai_waypoint_graphs", 0)
  end

  -- checkVarPercentage("weather_selection", weather_selection_override)

  --checkVarPercentage("enable_ce_radio_mechanic", enableRadioMechanics)
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
    if challenge_map then
      BotApi.Scene:SetVar("max_ai_defender_inf_per_flag_count", AiDefenderCount.Defending.challengeMaps.infantry.perFlag + botDifficultyModifier)
      BotApi.Scene:SetVar("max_ai_defender_at_flag", AiDefenderCount.Defending.infantry.max_ai_defender_at_flag)
      -- BotApi.Scene:SetVar("max_ai_defender_inf_count", AiDefenderCount.Defending.challengeMaps.infantry.max)
      BotApi.Scene:SetVar("max_ai_inf_def_x5_count", AiDefenderCount.Defending.challengeMaps.infantry.x5_cloneClount)
    else
      print("setting ai defender count for bot defending")
      BotApi.Scene:SetVar("max_ai_defender_inf_per_flag_count", AiDefenderCount.Defending.infantry.perFlag + botDifficultyModifier)
      BotApi.Scene:SetVar("max_ai_defender_at_flag", AiDefenderCount.Defending.infantry.max_ai_defender_at_flag)
      -- BotApi.Scene:SetVar("max_ai_defender_inf_count", AiDefenderCount.Defending.infantry.max)
      BotApi.Scene:SetVar("max_ai_inf_def_x5_count", AiDefenderCount.Defending.infantry.x5_cloneClount) 
    end
  else
     if challenge_map then
       BotApi.Scene:SetVar("max_ai_defender_inf_per_flag_count", AiDefenderCount.Attacking.challengeMaps.infantry.perFlag + botDifficultyModifier)
       BotApi.Scene:SetVar("max_ai_defender_at_flag", AiDefenderCount.Attacking.infantry.max_ai_defender_at_flag)
      -- BotApi.Scene:SetVar("max_ai_defender_inf_count", AiDefenderCount.Attacking.challengeMaps.infantry.max)
      BotApi.Scene:SetVar("max_ai_inf_def_x5_count", AiDefenderCount.Attacking.challengeMaps.infantry.x2_cloneClount)
      BotApi.Scene:SetVar("max_ai_defender_emplacement_total_count", AiDefenderCount.Attacking.challengeMaps.emplacement.perFlag * totalFlags)
     else
      print("setting ai emplacement defender count for bot attacking = ", AiDefenderCount.Attacking.emplacement.perFlag * totalFlags)
      print("setting ai defender count for bot attacking = ",  AiDefenderCount.Attacking.infantry.perFlag + botDifficultyModifier)
      BotApi.Scene:SetVar("max_ai_defender_at_flag", AiDefenderCount.Attacking.infantry.max_ai_defender_at_flag)
      -- BotApi.Scene:SetVar("max_ai_defender_inf_count", AiDefenderCount.Attacking.infantry.max)
      BotApi.Scene:SetVar("max_ai_defender_inf_per_flag_count", AiDefenderCount.Attacking.infantry.perFlag + botDifficultyModifier)
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

function KillSceneCheckTimer()
  if Context.SceneCheckTimer then
    BotApi.Events:KillQuantTimer(Context.SceneCheckTimer)
    Context.SceneCheckTimer = nil
  end
end

-- Checks the squad scene variable for tagged info about the match
function CheckSceneVariable(squad)

  --   if followWaypointGraphs then 
  --     if BotApi.Scene:IsSquadTagged(squad, "_lua_waypoint_graph_disabled") then
  --       print("Print: AI Waypoint graphs disabled by scene! followWaypointGraphs = ", followWaypointGraphs)
  --       followWaypointGraphs = false
  --   end
  --   else
  --     if BotApi.Scene:IsSquadTagged(squad, "_lua_waypoint_graph_enabled") then
  --         print("Print: AI Waypoint graphs enabled by scene! followWaypointGraphs = ", followWaypointGraphs)
  --         followWaypointGraphs = true
  --     end
  --   end

  --   if not forceUnitPriority then
  --     if BotApi.Scene:IsSquadTagged(squad, "_prioritize_de_miner") then
  --       print("Player has a lot of mines. Prioritze buying de-meiner!")
  --         forceUnitPriority = true 
  --       forcedUnitTypes = {"Miner"}
  --       forceUnitCountMax = 1   
  --     end
  --   end

  --   if not environment then
  --     if BotApi.Scene:IsSquadTagged(squad, "_autumn") then
  --       environment = "autumn"
  --   elseif BotApi.Scene:IsSquadTagged(squad, "_spring") then
  --       environment = "spring"
  --   elseif BotApi.Scene:IsSquadTagged(squad, "_summer") then
  --       environment = "summer"
  --   elseif BotApi.Scene:IsSquadTagged(squad, "_winter") then
  --       environment = "winter"
  --   end
  -- elseif environment and not intialSceneEnvironmentCheck then 
  --   print("Print: Scene evironment = ", environment)
  --   print("Print: Getting maxWeatherOptions with max size of ", maxWeatherOptions[environment])
  --   intialSceneEnvironmentCheck = true
  --     SetDynamicWeatherTimer()
  -- end
end

function StartSceneCheckTimer()
  local setSceneCheckTimer = function(callback)
      Context.SceneCheckTimer = BotApi.Events:SetQuantTimer(
        function()
          print("checking scene")         
          if not checkIfVanillaMapLoaded and not BotApi.Scene:IsSquadTagged(sceneVariableSquad, "_ce_map_scripts_running") then
            print("Vanilla Map Loaded!!! Disabling CE bot file logic")
            followWaypointGraphs = false           
          end
          checkIfVanillaMapLoaded = true
          Context.SceneCheckTimer  = nil
          CheckSceneVariable(sceneVariableSquad)
          callback(callback)          
        end,
        generalSquadTagCheckDelay)
    end
    setSceneCheckTimer(setSceneCheckTimer)
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