-- File created by Hawka
require([[/conquest_configuration/bot.conquest_configuration]])
-- Noresus AI battalion type (only used for Noresus mod)
StrategyTemplates = {
	{-- Index 1
		-- enableHumanWaveTactic = 1,
		StrategyName = "Human Wave Strategy",
		StrategyUnitTypes = {
			"Wave",
			"Flamer",
			"Command",
		},
		forceUnitCount = {
			min = 15,
			max = 30,
		},
		BotInfantry = {
			min = 40,
			max = 80,
		},
		BotATInfantry = {
			min = 4,
			max = 8,
		},
		BotInfantrySignaller = {
			min = 1,
			max = 3,
		},
		BotArtillery = {
			min = 1,
			max = 2,
		},
		BotMortars = {
			min = 1,
			max = 3,
		},
		BotEmplacements = {
			min = 1,
			max = 5,
		},
		BotTanks = {
			min = 4,
			max = 6,
		},
		BotHeavyTanks = {
			min = 1,
			max = 2,
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
	},
	{-- Index 2
		-- enableArtyTactic = 1,
		StrategyName = "Arty Strategy",
		StrategyUnitTypes = {
			"Rocket_Arty",
            "Artillery",
		},
		forceUnitCount = {
			min = 3,
			max = 5,
		},
		BotInfantry = {
			min = 40,
			max = 60,
		},
		BotATInfantry = {
			min = 1,
			max = 4,
		},
		BotInfantrySignaller = {
			min = 2,
			max = 3,
		},
		BotArtillery = {
			min = 4,
			max = 6,
		},
		BotMortars = {
			min = 3,
			max = 6,
		},
		BotEmplacements = {
			min = 0,
			max = 1,
		},
		BotTanks = {
			min = 2,
			max = 3,
		},
		BotHeavyTanks = {
			min = 1,
			max = 1,
		},
		BotSPGs = {
			min = 1,
			max = 1,
		},
		BotTankDestroyers = {
			min = 1,
			max = 1,
		},
		BotAircraft = {
			min = 0,
			max = 0,
		},
		BotReconAircraft = {
			min = 1,
			max = 2,
		},
		BotArmored = {
			min = 2,
			max = 5,
		},
	},
	{-- Index 3
		-- enableAirborneTactic = 1,
		StrategyName = "Airborne Strategy",
		StrategyUnitTypes = {
			"Paratrooper",
			"Fighter",
			"Group_Air"
		},
		StrategyExcludeUnitTypes = {
			"ReconPlane"
		},
		forceUnitCount = {
			min = 3,
			max = 6,
		},
		BotInfantry = {
			min = 30,
			max = 45,
		},
		BotATInfantry = {
			min = 2,
			max = 5,
		},
		BotInfantrySignaller = {
			min = 1,
			max = 1,
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
			max = 1,
		},
		BotTanks = {
			min = 2,
			max = 6,
		},
		BotHeavyTanks = {
			min = 1,
			max = 1,
		},
		BotSPGs = {
			min = 1,
			max = 1,
		},
		BotTankDestroyers = {
			min = 1,
			max = 1,
		},
		BotAircraft = {
			min = 4,
			max = 12,
		},
		BotReconAircraft = {
			min = 1,
			max = 4,
		},
		BotArmored = {
			min = 2,
			max = 5,
		},
	},
	{-- Index 4
		-- enableTankTactic = 1,
		StrategyName = "Heavy Armor Strategy",
		StrategyUnitTypes = {
            "Heavy",
			"ReconPlane",
			"Engineer",
            "Mechanized_Infantry",
		},
		StrategyExcludeUnitTypes = {
			"Armored",
			"Vehicle",
			"Cannon",
		},
		forceUnitCount = {
			min = 7,
			max = 10,
		},
		BotInfantry = {
			min = 20,
			max = 30,
		},
		BotATInfantry = {
			min = 1,
			max = 1,
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
			max = 1,
		},
		BotEmplacements = {
			min = 1,
			max = 1,
		},
		BotTanks = {
			min = 6,
			max = 12,
		},
		BotHeavyTanks = {
			min = 3,
			max = 5,
		},
		BotSPGs = {
			min = 3,
			max = 5,
		},
		BotTankDestroyers = {
			min = 1,
			max = 1,
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
	},
	{-- Index 5
		-- enableTankTactic = 1,
		StrategyName = "Armor Strategy",
		StrategyUnitTypes = {
            "Tank",
			"ReconPlane",
			"Engineer",
			"AA",
		},
		StrategyExcludeUnitTypes = {
			"Armored",
			"Vehicle",
			"Cannon",
			"AT",
		},
		forceUnitCount = {
			min = 7,
			max = 10,
		},
		BotInfantry = {
			min = 20,
			max = 30,
		},
		BotATInfantry = {
			min = 1,
			max = 1,
		},
		BotInfantrySignaller = {
			min = 1,
			max = 2,
		},
		BotArtillery = {
			min = 1,
			max = 1,
		},
		BotMortars = {
			min = 1,
			max = 1,
		},
		BotEmplacements = {
			min = 1,
			max = 1,
		},
		BotTanks = {
			min = 8,
			max = 14,
		},
		BotHeavyTanks = {
			min = 1,
			max = 3,
		},
		BotSPGs = {
			min = 1,
			max = 2,
		},
		BotTankDestroyers = {
			min = 1,
			max = 1,
		},
		BotAircraft = {
			min = 1,
			max = 2,
		},
		BotReconAircraft = {
			min = 2,
			max = 4,
		},
		BotArmored = {
			min = 1,
			max = 3,
		},
	},
	{-- Index 6
		StrategyName = "Infantry Strategy",
		StrategyUnitTypes = {
			-- "Wave",
			"Squad",
			"Support",
			"Big_gun",
			"AT",
		},
		forceUnitCount = {
			min = 8,
			max = 16,
		},
		BotInfantry = {
			min = 40,
			max = 65,
		},
		BotATInfantry = {
			min = 3,
			max = 6,
		},
		BotInfantrySignaller = {
			min = 2,
			max = 3,
		},
		BotArtillery = {
			min = 2,
			max = 4,
		},
		BotMortars = {
			min = 3,
			max = 4,
		},
		BotEmplacements = {
			min = 2,
			max = 3,
		},
		BotTanks = {
			min = 1,
			max = 3,
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
			max = 5,
		},
		BotAircraft = {
			min = 1,
			max = 1,
		},
		BotReconAircraft = {
			min = 1,
			max = 2,
		},
		BotArmored = {
			min = 2,
			max = 5,
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
			index = PickRandomNumber({1,6,7})
		elseif neBattalionType == "MOT" then
			index = PickRandomNumber({6,7,9})
		elseif neBattalionType == "MEC" then
			index = PickRandomNumber({6,7,11})
		elseif neBattalionType == "LT" then
			index = PickRandomNumber({10,11})
		elseif neBattalionType == "MT" then
			index = PickRandomNumber({5,10})
		elseif neBattalionType == "HT" then
			index = PickRandomNumber({4,5})
		elseif neBattalionType == "ART" then
			index = PickRandomNumber({2,8,9})
		end
		strategy = StrategyTemplates[index]
	end
	if testing and strategyIndexOverride then 
		index = strategyIndexOverride
		strategy = StrategyTemplates[index] 
	end
	if botDefender then 
		print("Bot defending! Changing infantry threshold")
		strategy.BotInfantry.min = 10
		strategy.BotInfantry.max = 20
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
