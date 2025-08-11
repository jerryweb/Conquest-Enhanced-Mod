-- File created by Hawka
require([[/script/multiplayer/modes/bot.strategies]])
-- =================== CE AI Variables ==================
generalSquadTagCheckDelay = 10 * 1000
checkAiSpawnMoveDelay = 2.5 * 60 * 1000
followWaypointGraphs = true
botDefender = false
sceneVariableSquad = nil 
forceUnitPriority = false 
forcedUnitTypes = {}
excludedUnitTypes = {}
forceUnitCount = 0
forceUnitCountMax = 0
botApiUnitsIndex = nil
force_ai_direct_attack_logic = 0
ai_attack_started = false

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

-- Default min max values for unit type priorities. These values should be overwritted by division roster specific values.
strategyTable = {
  StrategyUnitTypes = {
  },
  BotInfantry = {
    min = 15,
    max = 50,
  },
  BotATInfantry = {
    min = 2,
    max = 4,
  },
  BotInfantrySignaller = {
    min = 1,
    max = 2,
  },
  BotArtillery = {
    min = 1,
    max = 2,
  },
  BotMortars = {
    min = 1,
    max = 2,
  },
  BotEmplacements = {
    min = 1,
    max = 3,
  },
  BotTanks = {
    min = 2,
    max = 4,
  },
  BotHeavyTanks = {
    min = 1,
    max = 1,
  },
  BotSPGs = {
    min = 1,
    max = 2,
  },
  BotTankDestroyers = {
    min = 2,
    max = 4,
  },
  BotAircraft = {
    min = 1,
    max = 2,
  },
  BotReconAircraft = {
    min = 1,
    max = 2,
  },
  BotArmored = {
    min = 2,
    max = 5,
  },
}

-- =====================================

function IsSquadNeedNextOrder(squad)
  if BotApi.Scene:IsSquadTagged(squad, "_lua_need_next_order") then
    return true
  end
end

function SeekAndDestroy(squad)
  BotApi.Commands:SeekAndDestroy(squad)
end

function SetGeneralSquadTagCheckTimer()
  local setTagCheckTimer = nil
  
  setTagCheckTimer = function(callback)
    Context.GeneralSquadTagCheckTimer = BotApi.Events:SetQuantTimer(
      function()
        Context.GeneralSquadTagCheckTimer = nil
        for i, squad in pairs(BotApi.Scene.Squads) do

          if IsSquadNeedNextOrder(squad) then
            if printDebug then 
              print("squad ", squad, " getting next order") 
            end
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

function KillAiSpawnMoveTimer()
  if Context.AiSpawnMoveTimer then
    BotApi.Events:KillQuantTimer(Context.AiSpawnMoveTimer)
    Context.AiSpawnMoveTimer = nil
  end
end

function ActivateAiStrategy(waveUnitTotal)
  math.randomseed(os.time())
  if not forceUnitPriority then 
    if enableAiStrategy > math.random() then
      if strategyTable.StrategyUnitTypes then
        print("AI activating forced priorirty!")	
        forceUnitPriority = true
        forceUnitCount = 0
        forceUnitCountMax = math.random(strategyTable.forceUnitCount.min, strategyTable.forceUnitCount.max)
        forcedUnitTypes = strategyTable.StrategyUnitTypes
        if strategyTable.StrategyExcludeUnitTypes then
          excludedUnitTypes = strategyTable.StrategyExcludeUnitTypes
        end
        print("Print: forceUnitCountMax = ", forceUnitCountMax) 
        print("Print: waveUnitTotal = ", waveUnitTotal) 
        if forceUnitCountMax > waveUnitTotal then
          waveUnitTotal = forceUnitCountMax
        end
        if strategyTable.StrategyName == "Human Wave Strategy" then 
          print("unleashing the wave")
          BotApi.Scene:SetVar("human_wave_strategy_active", 1)
        end
      end
    end
  end
  return waveUnitTotal
end

function QueueAiUnitCounts()
  -- if printDebug then print("queuing ai unit counts") end
  searchProps = {
    -- Human tags
      "soldier", 
      "crew", 
      "soldier_pzscheck",
      "soldier_pzfaust",
      "soldier_atr",
      "soldier_atr_grenade",
      "soldier_bazooka",

    -- search by prop
    -- Mortars	
      "mortar",

    -- Artillery
      "detect_artillery",	

    -- Emplacements
      "detect_atgun",
      "detect_cannon_aa",
    -- BTR
      "armored_car",

    -- Tanks
      "light",
      "medium",
      "heavy",
      "mine_exploder",
      "td",
      "spg",

    -- Aircraft
      "bomber_ce",
      "fighter",
      "drop_plane",
      "ai_recon_plane",
    }
  
    

    local propertyToVariable = {
    -- Humans
      ["soldier"] = {"BotInfantry"},
      ["soldier_pzscheck"] = {"BotInfantry", "BotATInfantry"},
      ["soldier_pzfaust"] = {"BotInfantry", "BotATInfantry"},
      ["soldier_atr"] = {"BotInfantry", "BotATInfantry"},
      ["soldier_atr_grenade"] = {"BotInfantry", "BotATInfantry"},
      ["soldier_bazooka"] = {"BotInfantry", "BotATInfantry"},
      ["soldier_signaller"] = {"BotInfantry", "BotInfantrySignaller"},
  
    -- Artillery
      ["detect_artillery"] = {"BotArtillery"},

    -- Mortars
      ["mortar"] = {"BotMortars"},

    -- Emplacements
      ["detect_atgun"] = {"BotEmplacements"},
      ["detect_cannon_aa"] = {"BotEmplacements"},

    -- BTR
     ["armored_car"] = {"BotArmored"},

    -- Tanks
      ["heavy"] = {"BotHeavyTanks","BotTanks"},
      ["light"] = {"BotTanks"},
      ["medium"] = {"BotTanks"},

    -- SPGs
      ["td"] = {"BotTankDestroyers"},
      ["spg"] = {"BotSPGs"},

    -- Aircraft
      ["fighter"] = {"BotAircraft"},
      ["bomber_ce"] = {"BotAircraft"},
      ["drop_plane"] = {"BotDropAircraft"},
      ["ai_recon_plane"] = {"BotReconAircraft"},
    }		

    
    -- Count of current units by type for AI
    local aiUnitCounts = {
      BotInfantry = 0,
      BotATInfantry = 0,
      BotInfantrySignaller = 0,
      BotTanks = 0,
      BotHeavyTanks = 0,
      BotSPGs = 0,
      BotTankDestroyers = 0,
      BotMortars = 0,
      BotEmplacements = 0,
      BotArtillery = 0,
      BotAircraft = 0,
      BotDropAircraft = 0,
      BotReconAircraft = 0,
      BotArmored = 0,
    }

    -- print("Calling QueryScene for bot units")
    local sceneUnits = BotApi.Scene:QueryScene(searchProps, 5)
    local botUnits = nil 
    -- print("Checking index 2 for bot units in sceneUnits")
    -- if printDebug then print("Checking for sceneUnits") end
    if sceneUnits[BotApi.Instance.playerId][2] then 
      botUnits = sceneUnits[BotApi.Instance.playerId][2]
    else
      print("Bot scene units not stored in index 2! Looking for bot units")
      print("BotApi.Instance.playerId = ", BotApi.Instance.playerId)
      for i = 2, 10 do
        if sceneUnits[BotApi.Instance.playerId][i] then
          print("Bot scene units are stored at index ", i)
          botApiUnitsIndex = i
          botUnits = sceneUnits[BotApi.Instance.playerId][botApiUnitsIndex]
          print("Done")
          break
        end
      end
    end
    
  
    for i, prop in ipairs(searchProps) do
      local count = botUnits[i]
      local variables = propertyToVariable[prop]
      if variables then
        for _, variable in ipairs(variables) do
          aiUnitCounts[variable] = aiUnitCounts[variable] + count
        end
      end
    end

    aiUnitCounts.BotTanks = aiUnitCounts.BotTanks - aiUnitCounts.BotTankDestroyers

    --  print("Bot Player#:" ..BotApi.Instance.playerId.. " Infantry: " .. aiUnitCounts.BotInfantry)
    --  print("Bot Player#:" ..BotApi.Instance.playerId.. " ATInfantry: " .. aiUnitCounts.BotATInfantry)
    --  print("Bot Player#:" ..BotApi.Instance.playerId.. " Mortars: " .. aiUnitCounts.BotMortars)
    --  print("Bot Player#:" ..BotApi.Instance.playerId.. " Tanks: " .. aiUnitCounts.BotTanks)
    --  print("Bot Player#:" ..BotApi.Instance.playerId.. " Heavy Tanks: " .. aiUnitCounts.BotHeavyTanks)
    --  print("Bot Player#:" ..BotApi.Instance.playerId.. " Artillery: " .. aiUnitCounts.BotArtillery)
    --  print("Bot Player#:" ..BotApi.Instance.playerId.. " Aircraft: " .. aiUnitCounts.BotAircraft)
    --  print("Bot Player#:" ..BotApi.Instance.playerId.. " Drop Planes: " .. aiUnitCounts.BotDropAircraft)
    --  print("Bot Player#:" ..BotApi.Instance.playerId.. " Recon Planes: " .. aiUnitCounts.BotReconAircraft)
    --  print("Bot Player#:" ..BotApi.Instance.playerId.. " Tank Destroyers: " .. aiUnitCounts.BotTankDestroyers)
    --  print("Bot Player#:" ..BotApi.Instance.playerId.. " SPGs: " .. aiUnitCounts.BotSPGs)
     return aiUnitCounts
end

function GetUnitPriority(t)
  -- if printDebug then print("getting uint priorties") end
  local function UnitType (val)
    for index, value in ipairs(t.type) do
      if value == val then
        return true
      end
    end
    return false
  end

  local function UnitTypesWithExclusions(types, excludedTypes) 
    local unitTypeFound = false
    for i, type in ipairs(types) do
      if UnitType(type) then
        unitTypeFound = true
        break
      end
    end 

    for i, excludedType in ipairs(excludedTypes) do
      if UnitType(excludedType) then
        unitTypeFound = false
        break
      end
    end 
    return unitTypeFound
  end
  
  local unitCounts = QueueAiUnitCounts()
  local basePriority = t.priority
  local priorityMultiplier = 1

  -- Bot buys infantry first
  if unitCounts.BotInfantry < strategyTable.BotInfantry.min then -- minimum amount of infantry
    if UnitType("Infantry") then
      priorityMultiplier = priorityMultiplier
      if UnitType("Squad") then
        priorityMultiplier = priorityMultiplier * 1.2 
      elseif UnitType("Team") then
        priorityMultiplier = priorityMultiplier * 1.1 
      end
    else
      priorityMultiplier = priorityMultiplier * 0.1
    end
  elseif unitCounts.BotInfantry >= strategyTable.BotInfantry.max then -- maximum amount of infantry
    if UnitType("Infantry") and not UnitType("AT") and not UnitType("Signaller") then
      if botDefender then 
        priorityMultiplier = priorityMultiplier * 0.25
      else 
        priorityMultiplier = priorityMultiplier * 0.5
      end
    end
  end

  if UnitType("Infantry") and UnitType("AT") then
    if unitCounts.BotInfantry > strategyTable.BotInfantry.min - 5 and unitCounts.BotATInfantry <= strategyTable.BotATInfantry.min then
      priorityMultiplier = priorityMultiplier * 4
    elseif unitCounts.BotATInfantry >= strategyTable.BotATInfantry.max then
      priorityMultiplier = priorityMultiplier * 0.2
    end
  end

  if UnitType("Infantry") and UnitType("Signaller") then
    if unitCounts.BotInfantry > strategyTable.BotInfantry.min - 5 and unitCounts.BotInfantrySignaller <= strategyTable.BotInfantrySignaller.min then
      priorityMultiplier = priorityMultiplier 
    elseif unitCounts.BotInfantrySignaller >= strategyTable.BotInfantrySignaller.max then
      priorityMultiplier = priorityMultiplier * 0.1
    end
  end

  if unitCounts.BotInfantry + unitCounts.BotATInfantry >= strategyTable.BotInfantry.max and unitCounts.BotATInfantry >= strategyTable.BotATInfantry.min then
    if UnitType("Infantry") then
      priorityMultiplier = priorityMultiplier * 0.1
    end
  end

  

  if UnitType("Tank") and UnitType("Heavy") and not UnitType("Support") and not UnitType("Artillery") and not UnitType("AA") and not UnitType("AT") then
    if unitCounts.BotHeavyTanks < strategyTable.BotHeavyTanks.min then -- minimum amount of heavy tanks
      priorityMultiplier = priorityMultiplier * 1.5
    elseif unitCounts.BotHeavyTanks >= strategyTable.BotHeavyTanks.max then -- maximum amount of heavy tanks
      priorityMultiplier = priorityMultiplier * 0.1
    end
  end

  if UnitType("Tank") and not UnitType("Heavy") and not UnitType("Support") and not UnitType("Artillery") and not UnitType("AA") and not UnitType("AT") then
    if unitCounts.BotTanks < strategyTable.BotTanks.min then -- minimum amount of tanks
      priorityMultiplier = priorityMultiplier * 2
    elseif unitCounts.BotTanks >= strategyTable.BotTanks.max then -- maximum amount of tanks
      priorityMultiplier = priorityMultiplier * 0.1
    end
  end

  -- Priorities for Vehicles =========================================================================================
  if UnitType("Mortar") then
    if unitCounts.BotMortars < strategyTable.BotMortars.min then -- minimum amount of mortars
      priorityMultiplier = priorityMultiplier * 2.5
    elseif unitCounts.BotMortars >= strategyTable.BotMortars.max then -- maximum amount of mortars
      priorityMultiplier = priorityMultiplier * 0.1
    end
  end
  
  if UnitType("Artillery") then
    if unitCounts.BotArtillery < strategyTable.BotArtillery.min then -- minimum amount of artillery
      priorityMultiplier = priorityMultiplier * 1.1
    elseif unitCounts.BotArtillery >= strategyTable.BotArtillery.max then -- maximum amount of artillery
      priorityMultiplier = priorityMultiplier * 0.1
    end
  end

  if UnitType("Tank") and UnitType("AT") then 
    if unitCounts.BotTankDestroyers < strategyTable.BotTankDestroyers.min then -- minimum amount of TDs
      priorityMultiplier = priorityMultiplier * 1.25
    elseif unitCounts.BotTankDestroyers >= strategyTable.BotTankDestroyers.max then -- maximum amount of TDs
      priorityMultiplier = priorityMultiplier * 0.1
    end
  end
  if UnitType("Tank") and UnitType("Support") then 
    if unitCounts.BotSPGs < strategyTable.BotSPGs.min then -- minimum amount of SPGs
      priorityMultiplier = priorityMultiplier * 1.05
    elseif unitCounts.BotSPGs >= strategyTable.BotSPGs.max then -- maximum amount of SPGs
      priorityMultiplier = priorityMultiplier * 0.1
    end
  end

  if UnitType("Armored") then
    if unitCounts.BotArmored >= strategyTable.BotArmored.max then
        priorityMultiplier = priorityMultiplier * 0.1
    else
      priorityMultiplier = priorityMultiplier * 0.80
    end
  end


  -- Global priorities for different class of cannons
  if UnitType("Cannon") then
    if unitCounts.BotEmplacements >= strategyTable.BotEmplacements.max then
        priorityMultiplier = priorityMultiplier * 0.1
    else
      priorityMultiplier = priorityMultiplier * 0.75
    end
  end

  if UnitType("Aircraft") then
    if unitCounts.BotAircraft >= strategyTable.BotAircraft.max then
        priorityMultiplier = priorityMultiplier * 0.1
    elseif sceneVariableSquad then 
      if BotApi.Scene:IsSquadTagged(sceneVariableSquad, "nub_no_aa") then 
        priorityMultiplier = priorityMultiplier * 1.25
      end
    else
      priorityMultiplier = priorityMultiplier * 0.25
    end
  end

  if UnitType("ReconPlane") then
    if unitCounts.BotReconAircraft < strategyTable.BotReconAircraft.min then -- minimum amount of recon planes
      priorityMultiplier = priorityMultiplier * 1.5
    elseif unitCounts.BotReconAircraft >= strategyTable.BotReconAircraft.max then -- maximum amount of recon planes
      priorityMultiplier = priorityMultiplier * 0.1
    end
  end

  -- Global priorities for different class of all other vehicles and infantry teams
  if not UnitType("Cannon") and not UnitType("Squad") and not UnitType("Team")  and not UnitType("Tank") and not UnitType("Artillery") and not UnitType("Aircraft") then
    priorityMultiplier = priorityMultiplier * 0.25
  end
  
  -- Override all preivous priority calculations if true
  if forceUnitPriority then
    if UnitTypesWithExclusions(forcedUnitTypes, excludedUnitTypes) then 
      if UnitType("Command") then 
        basePriority = 1
        priorityMultiplier = 1.5
      elseif UnitType("Signaller") then     
        priorityMultiplier = 1.5
      elseif UnitType("ReconPlane") then  
        priorityMultiplier = 2
      else 
        priorityMultiplier = 2.5
      end
    else 
      priorityMultiplier = 0.01
    end 
  end
  -- print("Unit ", t.unit, " has priority = ", basePriority * priorityMultiplier)
  return basePriority * priorityMultiplier
end
