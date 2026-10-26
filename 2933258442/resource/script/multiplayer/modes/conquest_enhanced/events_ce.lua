-- Percentage chance (between 0 and 1) to enable the Classic CE Radio Mechanics. Currently it is set as a random event with a 18% chance to occur per match.
-- and can be countered with a radio vehicle.
enableCommunicationsCutMechanics = 0.18

-- Defaults live here so this file works without edits to runtime_config.lua.
-- Move the table there if you prefer all tuning values in one place.
ConquestConfig.RearAttack = ConquestConfig.RearAttack or {
	EventChance = 0.20, -- chance the event is active for the match
	ToggleChance = 0.50, -- chance the spawns swap sides before each attacker wave
}
