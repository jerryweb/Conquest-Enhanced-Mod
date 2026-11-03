-- Percentage chance (between 0 and 1) to enable the Classic CE Radio Mechanics. Currently it is set as a random event with a 18% chance to occur per match.
-- and can be countered with a radio vehicle.
enableCommunicationsCutMechanics = 0.18

-- Chance to enable sabotage mechanic 
enableSabotageMechanics = 0.35

-- Defaults live here so this file works without edits to runtime_config.lua.
-- Move the table there if you prefer all tuning values in one place.
ConquestRearAttack = ConquestRearAttack or {}

-- Chance to enable rear attack event
-- Chance to flip what side the ai spawns is located
ConquestConfig.RearAttack = ConquestConfig.RearAttack or {
	EventChance = 0.15, -- chance the event is active for the match
	ToggleChance = 0.50, -- chance the spawns swap sides before each attacker wave
}

ConquestConfig.AirRaid = ConquestConfig.AirRaid or {
	Chance = 0.05, -- chance the event happens this match (single roll)
	DelayMin = 0.5, -- the roll happens this long after prep time ends
	DelayMax = 6 * 60000,
	ActiveDelay = 30000,    -- time between the warning and the active variable
}