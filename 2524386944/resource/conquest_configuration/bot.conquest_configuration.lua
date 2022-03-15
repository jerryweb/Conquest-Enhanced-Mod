-- This file can be used for configurations of Conquest Enhanced as well as enable testing mode. 
-- However, not all configurations are tested so CHANGE AT YOUR OWN RISK.
-- IF YOU MODIFY THIS FILE, ALL PLAYERS FOR A COOP MATCH MUST HAVE THE SAME CONFIG FILE.You WILL get a desync if all the files and values do not match.
-- If you have any questions or requests for the file, you can message Hawka on steam or the GOH discord.

-- ================================= Standard Settings =========================================
	-- This enables testing mode for debugging, and is not advised for regular play. Make sure this is off unless you are specifcally testing for something. 
	testing = false
	-- This will print a lot more debug statments in the log when playing but may impact performance. 
	verbose = false

	------------------------- Prep Time before Enemy Reinforcements ----------------------------
	-- Default time in seconds when the AI will begin to call in reinforcements. The corresponding difficulty file will also need to be changed to the 
	-- earliest time of all of the offsets listed below give CP to the AI for this to work. I.E. if firstWaveOffsetTimeForTesting is set to 50 then set
	-- 50:10 in the difficulty file.
	oneFlagOffsetTime = 300

	-- Attack Mission Offset Times
	threeFlagOffsetTime = 1400
	fourFlagOffsetTime = 1700

	-- Defense Mission Offset times
	twoFlagOffsetTime = 700
	fiveFlagOffsetTime = 760

	-- Time when the AI reinforcements are called in when testing is set to true
	firstWaveOffsetTimeForTesting = 60
	---------------------------------------------------------------------------------------------


	-- This is the division that will always be selected when testing. If you want to randomly select one, just set it to nil
	-- testingDivision = [[/script/multiplayer/bot.data.purchase.conquest.late.7]] 

	-- Chance that the enemy might come earlier or later than the preset first wave offest. Example: 30% chance enemy comes earlier or later than the standard prep time
	chanceToOffsetFirstWave = 0.3

	-- Offset bounds for the inital enemy wave in seconds. 
	lowerBoundFirstWaveOffset = -120
	upperBoundFirstWaveOffset = 120

-- ================================= Advanded Settings =========================================
	-- This variable controls whether units will spawn all at once for 25 seconds, creating a massive wave, every x seconds (controlled by typhoonWaveInterval)
	-- This represents the percentage change to activate the typhoon wave mode. Example 0.5 == 50% chance
	-- If you want to turn it on all the time you can set it to 1.0 or if you don't want it ever toggle, you can set it to 0.0
	chanceToSetTyphoonWaveMode = 0.5

	-- Interval between typhoon waves
	typhoonWaveInterval = 90

	-- Time the AI has to spawn as many units as it can
	typhoonWaveDuration = 25

	-- This controls whether typhoon wave mode can turn on or off dynamically ingame meaning that the AI can switch between standard spawning mode and typhoon wave mode
	-- This represents the percentage change to activate. Example 0.5 == 50% chance
	-- If you want to turn it on all the time you can set it to 1.0 or if you don't want it ever toggle, you can set it to 0.0
	chanceToSetTyphoonWaveModeToggle = 0.3

	-- Chance to turn typhoon wave mode off and on dynamically when the AI buys a unit
	chanceToggleTyphoonWaveMode = 0.5

	-- This is the interval in seconds at which the typhoon wave mode can toggle on or off during a game
	typhoonWaveToggleInterval = 300

-- =============================== Logging DO NOT MODIFY =======================================
	print("Initial player conquest configuration:")
	print("Testing mode: ", testing)
	print("Verbose: ", verbose)
	print("Default first wave offset time for 1 flag missions: ", oneFlagOffsetTime)
	print("Default first wave offset time for 2 flag missions: ", twoFlagOffsetTime)
	print("Default first wave offset time for 3 flag missions: ", threeFlagOffsetTime)
	print("Default first wave offset time for 4 flag missions: ", fourFlagOffsetTime)
	print("Default first wave offset time for 5 flag missions: ", fiveFlagOffsetTime)
	print("First wave offset time for testing: ", firstWaveOffsetTimeForTesting)
	print("Division to test: ", testingDivision)
	print("Chance to change first wave offset: ", chanceToOffsetFirstWave)
	print("Lower bound of first wave offset in seconds: ", lowerBoundFirstWaveOffset)
	print("Upper bound of first wave offset in seconds: ", upperBoundFirstWaveOffset)

	print("Typhoon wave mode chance: ", chanceToSetTyphoonWaveMode)
	print("Default typhoon wave mode interval: ", typhoonWaveInterval)
	print("Default typhoon wave mode duration: ", typhoonWaveDuration)
	print("Typhoon wave mode dynamic toggle chance: ", chanceToSetTyphoonWaveModeToggle)
	print("Default typhoon wave mode dynamic toggle: ", typhoonWaveToggleInterval)
