-- File created by Hawka
require([[/script/multiplayer/modes/strategies]])

forceUnitPriority = false 
forcedUnitTypes = {}
excludedUnitTypes = {}
forceUnitCount = 0
forceUnitCountMax = 0

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
  
  local basePriority = t.priority
  local priorityMultiplier = 1

  if UnitType("Infantry") then
    priorityMultiplier = priorityMultiplier * 1.75
    if UnitType("AT") then 
      priorityMultiplier = priorityMultiplier * strategyTable.BotATInfantry
    elseif UnitType("Signaller") then
      priorityMultiplier = priorityMultiplier * strategyTable.BotInfantrySignaller
    elseif UnitType("Team") then
      priorityMultiplier = priorityMultiplier * strategyTable.BotTeamInfantry 
    else
      priorityMultiplier = priorityMultiplier * strategyTable.BotInfantry
    end
  end
  
  if UnitType("Tank") then      
    if UnitType("Heavy") and not (UnitType("Support") or UnitType("Artillery") or UnitType("AA") or UnitType("AT")) then
      priorityMultiplier = priorityMultiplier * strategyTable.BotHeavyTanks
    elseif UnitType("Support") and not (UnitType("Artillery") or UnitType("AA") or UnitType("AT")) then
      priorityMultiplier = priorityMultiplier * strategyTable.BotSPGs
    elseif UnitType("AA") and not (UnitType("Artillery") or UnitType("Support") or UnitType("AT")) then
      priorityMultiplier = priorityMultiplier * strategyTable.BotTankDestroyers
    elseif UnitType("Artillery") then 
      priorityMultiplier = priorityMultiplier * strategyTable.BotArtillery
    else 
      priorityMultiplier = priorityMultiplier * strategyTable.BotTanks
    end  
  end

  if UnitType("Armored") then     
    priorityMultiplier = priorityMultiplier * strategyTable.BotArmored
  end

  if UnitType("Cannon") then 
    if UnitType("Artillery") then 
      priorityMultiplier = priorityMultiplier * strategyTable.BotArtillery
    else      
      priorityMultiplier = priorityMultiplier * strategyTable.BotEmplacements
    end
  end

  if UnitType("Mortar") then     
    priorityMultiplier = priorityMultiplier * strategyTable.BotMortars
  end

  if UnitType("Aircraft") then     
    if UnitType("ReconPlane") then 
      priorityMultiplier = priorityMultiplier * strategyTable.BotReconAircraft
    elseif UnitType("Paratroopers") then   
      priorityMultiplier = priorityMultiplier * strategyTable.BotParatroopers
    else 
      priorityMultiplier = priorityMultiplier * strategyTable.BotAircraft
    end
  end

  if priorityMultiplier < 0.1 then 
    priorityMultiplier = 0.1
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
