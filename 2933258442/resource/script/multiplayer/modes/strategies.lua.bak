-- File created by Hawka
require([[/conquest_configuration/bot.conquest_configuration]])

-- Default min max values for unit type priorities. These values should be overwritted by division roster specific values.
strategyTable = {
  StrategyName = "Default",
  StrategyUnitTypes = {
  },
	BotInfantry = 1.0,
	BotTeamInfantry = 1.0,
	BotATInfantry = 1.0,
	BotInfantrySignaller = 1.0,
	BotArtillery = 1.0,
	BotMortars = 1.0,
	BotEmplacements = 1.0,
	BotTanks = 1.0,
	BotHeavyTanks = 1.0,
	BotArmored = 1.0,
	BotSPGs = 1.0,
	BotTankDestroyers = 1.0,
	BotAircraft = 1.0,
	BotReconAircraft = 1.0,
	BotParatroopers = 1.0,
}

-- Noresus AI battalion type (only used for Noresus mod)
StrategyTemplates = {
	{-- Index 1
		-- enableHumanWaveTactic = 1,
		StrategyName = "Human Wave Strategy",
		StrategyUnitTypes = {
			"Wave",
			"Flamer",
			"Super_Wave",
		},
		BotInfantry = 1.0,
		BotTeamInfantry = 1.0,
		BotATInfantry = 1.0,
		BotInfantrySignaller = 1.0,
		BotArtillery = 1.0,
		BotMortars = 1.0,
		BotEmplacements = 1.0,
		BotTanks = 1.0,
		BotHeavyTanks = 1.0,
		BotArmored = 1.0,
		BotSPGs = 1.0,
		BotTankDestroyers = 1.0,
		BotAircraft = 1.0,
		BotReconAircraft = 1.0,
		BotParatroopers = 0.2,
		forceUnitCount = {
			min = 8,
			max = 15,
		},
	},
	{-- Index 2
		-- enableArtyTactic = 1,
		StrategyName = "Artillery Strategy",
		StrategyUnitTypes = {
			"Rocket_Arty",
            "Artillery",
		},
		BotInfantry = 1.0,
		BotTeamInfantry = 1.0,
		BotATInfantry = 1.0,
		BotInfantrySignaller = 1.1,
		BotArtillery = 1.1,
		BotMortars = 1.0,
		BotEmplacements = 1.0,
		BotTanks = 0.7,
		BotHeavyTanks = 0.2,
		BotArmored = 0.8,
		BotSPGs = 1.0,
		BotTankDestroyers = 0.7,
		BotAircraft = 0.5,
		BotReconAircraft = 1.0,
		BotParatroopers = 0.2,
		forceUnitCount = {
			min = 1,
			max = 2,
		},
	},
	{-- Index 3
		-- enableAirborneTactic = 1,
		StrategyName = "Airborne Strategy",
		StrategyUnitTypes = {
			"Paratrooper",
			"Fighter",
			"Bomber",
			"Group_Air"
		},
		StrategyExcludeUnitTypes = {
			"ReconPlane"
		},
		BotInfantry = 1.0,
		BotTeamInfantry = 1.0,
		BotATInfantry = 1.0,
		BotInfantrySignaller = 1.0,
		BotArtillery = 0.5,
		BotMortars = 0.8,
		BotEmplacements = 0.8,
		BotTanks = 0.8,
		BotHeavyTanks = 0.5,
		BotArmored = 0.8,
		BotSPGs = 0.7,
		BotTankDestroyers = 0.7,
		BotAircraft = 1.1,
		BotReconAircraft = 1.0,
		BotParatroopers = 1.0,
		forceUnitCount = {
			min = 3,
			max = 6,
		},
	},
	{-- Index 4
		StrategyName = "Heavy Armor Strategy",
		StrategyUnitTypes = {
            "Heavy",
			"ReconPlane",
			"Engineer",
			"Tank",
            "Mechanized_Infantry",
		},
		StrategyExcludeUnitTypes = {
			"Armored",
			"Vehicle",
			"Cannon",
			"Aircraft",
		},
		forceUnitCount = {
			min = 7,
			max = 10,
		},
		BotInfantry = 0.9,
		BotTeamInfantry = 0.9,
		BotATInfantry = 0.5,
		BotInfantrySignaller = 0.4,
		BotArtillery = 0.1,
		BotMortars = 0.1,
		BotEmplacements = 0.1,
		BotTanks = 1.0,
		BotHeavyTanks = 1.3,
		BotArmored = 0.7,
		BotSPGs = 0.5,
		BotTankDestroyers = 0.3,
		BotAircraft = 0.1,
		BotReconAircraft = 0.5,
		BotParatroopers = 0.1,		
	},
	{-- Index 5
		-- enableTankTactic = 1,
		StrategyName = "Armor Strategy",
		StrategyUnitTypes = {
            "Tank",
			"Engineer",
			"AA",
		},
		StrategyExcludeUnitTypes = {
			"Armored",
			"Vehicle",
			"Cannon",
			"AT",
			"Aircraft",
		},
		BotInfantry = 0.9,
		BotTeamInfantry = 1.0,
		BotATInfantry = 0.5,
		BotInfantrySignaller = 0.5,
		BotArtillery = 0.4,
		BotMortars = 0.4,
		BotEmplacements = 0.2,
		BotTanks = 1.25,
		BotHeavyTanks = 1.0,
		BotArmored = 0.8,
		BotSPGs = 0.6,
		BotTankDestroyers = 0.4,
		BotAircraft = 0.3,
		BotReconAircraft = 0.6,
		BotParatroopers = 0.1,
		forceUnitCount = {
			min = 7,
			max = 10,
		},
	},
	{-- Index 6
		StrategyName = "Infantry Strategy",
		StrategyUnitTypes = {
			"Squad",
			"Support",
			"Big_gun",
			"Elite",
			"AT",
		},
		StrategyExcludeUnitTypes = {
			"Tank",
			"Vehicle",
		},
		BotInfantry = 1.25,
		BotTeamInfantry = 1.1,
		BotATInfantry = 1.15,
		BotInfantrySignaller = 1.0,
		BotArtillery = 0.7,
		BotMortars = 0.8,
		BotEmplacements = 0.8,
		BotTanks = 0.7,
		BotHeavyTanks = 0.25,
		BotArmored = 0.8,
		BotSPGs = 0.7,
		BotTankDestroyers = 0.7,
		BotAircraft = 0.6,
		BotReconAircraft = 0.7,
		BotParatroopers = 0.4,
		forceUnitCount = {
			min = 8,
			max = 16,
		},
	},
}

-- Function to pick a random number from the set
local function PickRandomNumber(set)
	math.randomseed(os.time())
    -- Generate a random index
    local index = math.random(1, #set)
    -- Return the randomly selected number
    return set[index]
end

function SelectAiStrategyTemplate(botDefender) 
	local index = math.random(1, #StrategyTemplates)
	local strategy = StrategyTemplates[index]

	if neBattalionType then
		print("AI battalion = ", neBattalionType)
		if neBattalionType == "INF" then
			index = PickRandomNumber({1,3,6})
		elseif neBattalionType == "MOT" then
			index = PickRandomNumber({1,6})
		elseif neBattalionType == "MEC" then
			index = PickRandomNumber({6})
		elseif neBattalionType == "LT" then
			index = PickRandomNumber({5})
		elseif neBattalionType == "MT" then
			index = PickRandomNumber({5})
		elseif neBattalionType == "HT" then
			index = PickRandomNumber({4,5})
		elseif neBattalionType == "ART" then
			index = PickRandomNumber({2})
		end
		strategy = StrategyTemplates[index]
	end
	if testing and strategyIndexOverride then 
		index = strategyIndexOverride
		strategy = StrategyTemplates[index] 
	end
	print("Getting the AI strategy name...")
	if strategy.StrategyName then
		print("Loaded AI strategy ", strategy.StrategyName)
	else
		print("AI strategy has no name!")
	end
	print("Strategy index = ", index)
	BotApi.Scene:SetVar("ai_strategy_selection", index)
	return strategy
end
