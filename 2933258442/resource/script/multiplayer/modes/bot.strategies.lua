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
			min = 45,
			max = 60,
		},
		BotInfantry = {
			min = 50,
			max = 95,
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
			min = 2,
			max = 5,
		},
		BotInfantry = {
			min = 40,
			max = 80,
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
		},
		forceUnitCount = {
			min = 8,
			max = 16,
		},
		BotInfantry = {
			min = 40,
			max = 90,
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
			min = 3,
			max = 8,
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
			min = 15,
			max = 20,
		},
		BotInfantry = {
			min = 40,
			max = 60,
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
			min = 15,
			max = 20,
		},
		BotInfantry = {
			min = 40,
			max = 60,
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
	{
		-- enableEliteTactic = 1,
		StrategyName = "Elite Strategy",
		StrategyUnitTypes = {
			"Elite",
			"Flamer",
			"Paratrooper",
		},
		forceUnitCount = {
			min = 5,
			max = 10,
		},
		BotInfantry = {
			min = 40,
			max = 80,
		},
		BotATInfantry = {
			min = 2,
			max = 4,
		},
		BotInfantrySignaller = {
			min = 1,
			max = 3,
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
			min = 3,
			max = 6,
		},
		BotHeavyTanks = {
			min = 3,
			max = 5,
		},
		BotSPGs = {
			min = 1,
			max = 5,
		},
		BotTankDestroyers = {
			min = 1,
			max = 1,
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
	{
		-- enableInfantryTactic = 1,
		StrategyName = "Infantry Strategy",
		StrategyUnitTypes = {
			-- "Wave",
			"Support",
			"Big_gun",
			"AT"
		},
		forceUnitCount = {
			min = 5,
			max = 15,
		},
		BotInfantry = {
			min = 50,
			max = 100,
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
	{
		-- enableBigGunTactic = 1,
		StrategyName = "BigGun Strategy",
		StrategyUnitTypes = {
			"Artillery",
			"Big_gun",
		},
		forceUnitCount = {
			min = 3,
			max = 6,
		},
		BotInfantry = {
			min = 50,
			max = 80,
		},
		BotATInfantry = {
			min = 3,
			max = 6,
		},
		BotInfantrySignaller = {
			min = 1,
			max = 3,
		},
		BotArtillery = {
			min = 1,
			max = 4,
		},
		BotMortars = {
			min = 3,
			max = 4,
		},
		BotEmplacements = {
			min = 3,
			max = 4,
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
	{
		-- enableAASpamTactic = 1,
		StrategyName = "AAspam Strategy",
		StrategyUnitTypes = {
			"AA",
			"Fighter",
			"Mortar",
		},
		forceUnitCount = {
			min = 6,
			max = 10,
		},
		BotInfantry = {
			min = 45,
			max = 90,
		},
		BotATInfantry = {
			min = 3,
			max = 9,
		},
		BotInfantrySignaller = {
			min = 1,
			max = 1,
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
			min = 3,
			max = 4,
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
			max = 1,
		},
		BotTankDestroyers = {
			min = 1,
			max = 3,
		},
		BotAircraft = {
			min = 1,
			max = 3,
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
	{
		-- enableLightSpamTactic = 1,
		StrategyName = "Light Tank Rush Strategy",
		StrategyUnitTypes = {
			"Light",
			"Fighter",
		},
		forceUnitCount = {
			min = 6,
			max = 12,
		},
		BotInfantry = {
			min = 60,
			max = 90,
		},
		BotATInfantry = {
			min = 1,
			max = 1,
		},
		BotInfantrySignaller = {
			min = 1,
			max = 1,
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
			min = 3,
			max = 4,
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
			max = 1,
		},
		BotTankDestroyers = {
			min = 3,
			max = 6,
		},
		BotAircraft = {
			min = 1,
			max = 3,
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
	{
		-- enableArmoredCarSpamTactic = 1,
		StrategyName = "Armored Car Rush Strategy",
		StrategyUnitTypes = {
			"Armored",
		},
		forceUnitCount = {
			min = 6,
			max = 15,
		},
		BotInfantry = {
			min = 50,
			max = 90,
		},
		BotATInfantry = {
			min = 1,
			max = 3,
		},
		BotInfantrySignaller = {
			min = 1,
			max = 2,
		},
		BotArtillery = {
			min = 1,
			max = 3,
		},
		BotMortars = {
			min = 1,
			max = 2,
		},
		BotEmplacements = {
			min = 1,
			max = 4,
		},
		BotTanks = {
			min = 1,
			max = 1,
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
			min = 3,
			max = 6,
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
	return strategy
end
