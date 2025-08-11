-- Config file created by Hawka
-- This file can be used for configurations of Conquest Enhanced as well as enable testing mode. 
-- However, not all configurations are tested so CHANGE AT YOUR OWN RISK.
-- IF YOU MODIFY THIS FILE, ALL PLAYERS FOR A COOP MATCH MUST HAVE THE SAME CONFIG FILE.You WILL get a desync if all the files and values do not match.
-- If you have any questions or requests for the file, you can message Hawka on steam or the GOH discord.

-- ================================= Standard Settings =========================================
	-- Prints more information in game.log for debugging purposes
	printDebug = false
	
	-- This enables testing mode for debugging, and is not advised for regular play. Make sure this is off unless you are specifcally testing for something. 
	testing = false

	-- This is the strategy the ai will use to spawn units. If you want to randomly select one, just set it to nil
	-- strategyIndexOverride = 5

	-- Time from start of match AI will wait before attempting to buy a unit.
	oneFlagOffsetTime = {
	    -- Bot is defender
    	DefenseMin = 1 * 60 * 1000, 
    	DefenseMax = 2 * 60 * 1000,
    	-- Bot is attacker
    	AttackMin = 8 * 60 * 1000, 
    	AttackMax = 10 * 60 * 1000,
	}

	twoFlagOffsetTime = oneFlagOffsetTime
	threeFlagOffsetTime = {
	     -- Bot is defender
    	DefenseMin = 1 * 60 * 1000, 
    	DefenseMax = 2 * 60 * 1000,
    	-- Bot is attacker
    	AttackMin = 10 * 60 * 1000, 
    	AttackMax = 13 * 60 * 1000,
	}
	fourFlagOffsetTime = {
	     -- Bot is defender
    	DefenseMin = 1 * 60 * 1000, 
    	DefenseMax = 1 * 60 * 1000,
    	-- Bot is attacker
    	AttackMin = 11 * 60 * 1000, 
    	AttackMax = 13 * 60 * 1000,
	}
	fiveFlagOffsetTime = {
	     -- Bot is defender
    	DefenseMin = 1 * 60 * 1000, 
    	DefenseMax = 1 * 60 * 1000,
    	-- Bot is attacker
    	AttackMin = 13 * 60 * 1000, 
    	AttackMax = 15 * 60 * 1000,
	}

	-- Time when the AI reinforcements are called in when testing is set to true
	firstWaveOffsetTimeForTesting = 60

	-- Time from last purchase AI will wait before attempting to buy a new unit.
	DCGWaveOffOverwrite = {
		-- Time between each wave when bot is attacking
		AttackMinWaveOff = 1.25 * 60 * 1000,
		AttackMaxWaveOff = 1.75 * 60 * 1000,
     	-- Time between each wave when bot is defending
     	DefenseMinWaveOff = 3 * 60 * 1000, 
     	DefenseMaxWaveOff = 7 * 60 * 1000,

     }

    -- Number of possible units than can be in a wave attack in conquest
	WaveUnit = {
	-- Conquest    
	    -- Bot is attacker
	    AttackMin = 20,
	    AttackMax = 42,
	    -- Bot is defender
	    DefendMin = 4,
	    DefendMax = 8,
	-- MP
	    Min = 7,
	    Max = 10,
	}

-- ================================= Advanded Settings =========================================
	-- Percentage chance (between 0 and 1) to enable the Classic CE Radio Mechanics. Currently it is set as a random event with a 15% chance to occur per match.
	-- and can be countered with a radio vehicle.
	enableRadioMechanics = 1
	
	enableCommunicationsCutMechanics = 0.2


	-- Percentage chance (between 0 and 1) for the AI sabotage event. This event has a percentage based on difficulty within the scripts, so this value will override that value.
	enableSabotageMechanics = 0.35
	
	-- Percentage chance (between 0 and 1) that the AI will spawn from the player's side randomly during battle
	enableRearAttackMechanics = 0.15

	-- Enabled this setting to allow AI to scuttle disabled tanks (tanks that have turret and gun disabled or are immobile for at least 3 mins). MUST BE SET TO 1 0R 0
	enableAiAbandonMechanics = 1

	-- Enable posibility for certain divisions to perform certain strategies (This is checked at the start of every AI wave)
	enableAiStrategy = 0.3

	-- Number of AI Defender Infantry and vehicles that are spawned for a attack or defense mission.
	AiDefenderCount = {
		-- Bot is attacker
		Attacking = {
			emplacement = {
				max = 10,
				perFlag = 2
			},
			infantry = {
				x2_cloneClount = 3,
				max = 50,
				perFlag = 12
			},
			challengeMaps = {
				emplacement = {
				max = 10,
				perFlag = 2
				},
				infantry = {
					x2_cloneClount = 3,
					max = 45,
					perFlag = 10
				},
			}
		}, 
		-- Bot is defender
		Defending = {
			emplacement = {
				defenseLevelOne = 99,
				defenseLevelTwo = 15,
				defenseLevelThree = 20
			},
			infantry = {
				x5_cloneClount = 5,
				max = -1,
				perFlag = 30
			},
			challengeMaps = {
				emplacement = {
				defenseLevelOne = 99,
				defenseLevelTwo = 80,
				defenseLevelThree = 80
				},
				infantry = {
					x5_cloneClount = 20,
					max = -1,
					perFlag = 70
				},
			}
		}
	}
	
	
-- =============================== Logging DO NOT MODIFY =======================================
	require([[/conquest_configuration/bot.mod_configuration]])

	-- print("Initial player conquest configuration:")
	-- print("Testing mode: ", testing)
	-- print("Verbose: ", verbose)
	-- print("Default first wave offset time for 1 flag missions: ", oneFlagOffsetTime)
	-- print("Default first wave offset time for 2 flag missions: ", twoFlagOffsetTime)
	-- print("Default first wave offset time for 3 flag missions: ", threeFlagOffsetTime)
	-- print("Default first wave offset time for 4 flag missions: ", fourFlagOffsetTime)
	-- print("Default first wave offset time for 5 flag missions: ", fiveFlagOffsetTime)
	-- print("First wave offset time for testing: ", firstWaveOffsetTimeForTesting)
	-- print("Division to test: ", testingDivision)
	-- print("Chance to change first wave offset: ", chanceToOffsetFirstWave)
	-- print("Lower bound of first wave offset in seconds: ", lowerBoundFirstWaveOffset)
	-- print("Upper bound of first wave offset in seconds: ", upperBoundFirstWaveOffset)

	-- print("Typhoon wave mode chance: ", chanceToSetTyphoonWaveMode)
	-- print("Default typhoon wave mode interval: ", typhoonWaveInterval)
	-- print("Default typhoon wave mode duration: ", typhoonWaveDuration)
	-- print("Typhoon wave mode dynamic toggle chance: ", chanceToSetTyphoonWaveModeToggle)
	-- print("Default typhoon wave mode dynamic toggle: ", typhoonWaveToggleInterval)

	-- for faction, division in pairs(maxNumberOfDivisions) do
	-- 	for j, k in pairs(maxNumberOfDivisions.Faction) do
	-- 		print("Max number of ", j, " divisions: ", k)
	-- 	end
	-- end
