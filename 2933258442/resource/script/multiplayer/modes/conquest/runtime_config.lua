-- =========================================================
-- RUNTIME CONFIG
-- =========================================================
-- Core Conquest timing, purchase-count, and order constants.

ConquestConfig = ConquestConfig or {}

ConquestConfig.CombatPressureWeights = {
	Infantry = 1.0,
	Armor = 20.0,
	HeavyArmor = 30.0,
	SuperHeavyArmor = 40.0,
	MachineGun = 8.0,
	AutoCannon = 14.0,
	LightAT = 10.0,
	ATGun = 20.0,
	Flame = 15.0,
	MediumHE = 18.0,
	LargeHE = 30.0,
}

-- Infantry-equivalents for how much a unit can still bring to bear on taking ground, which is not what CombatPressureWeights asks.
-- Indirect fire scores low because it cannot hold ground; armor scores high because it can drive onto an objective.
ConquestConfig.AssaultWeights = {
	Infantry = 1.0,
	Crew = 0.0, -- Can capture, but too rarely to count.

	LightArmor = 8.0,
	MediumArmor = 12.0,
	HeavyArmor = 18.0,
	SuperHeavyArmor = 22.0,

	MachineGun = 2.0,
	AutoCannon = 3.0,
	LightAT = 3.0,
	ATGun = 5.0,
	Flame = 4.0,
	MediumHE = 3.0,
	LargeHE = 4.0,

	Engineer = 1.0, -- Capture-capable body the scene query keeps out of Infantry.
	AmmoSupply = 0.0,
}

-- Infantry-equivalents for how much defense the attacker has to get through, used to scale the bar.
-- Support weapons cannot be zero here: scene query buckets an HE-gun tank into MediumHE and an AA truck into MachineGun.
ConquestConfig.PlayerDefenseWeights = {
	Infantry = 1.0,
	Crew = 0.0, -- Lets a crew-only defender read 0 so HasPlayerDefense still fires.

	LightArmor = 6.0,
	MediumArmor = 10.0,
	HeavyArmor = 15.0,
	SuperHeavyArmor = 20.0,

	MachineGun = 4.0,
	AutoCannon = 6.0,
	LightAT = 3.0,
	ATGun = 8.0,
	Flame = 4.0,
	MediumHE = 6.0,
	LargeHE = 8.0,

	Engineer = 1.0,
	AmmoSupply = 0.0,
}

-- Time from match start before the AI attempts its first purchase.
ConquestConfig.StartSpawnTime = {
	-- Bot is defender.
	DefenseMin = 2 * 1000,
	DefenseMax = 2 * 1000,

	-- Bot is attacker.
	AttackMin = 1 * 1000,
	AttackMax = 1 * 1000,
}

-- Time from last purchase before the AI attempts another purchase.
ConquestConfig.SpawnCooldownTime = {
	-- Time between completed attacker waves.
	DCGWaveOffMin = 2 * 60000,
	DCGWaveOffMax = 2.5 * 60000,

	-- Time between purchases inside an active wave/opening.
	DCGMin = 1 * 1000,
	DCGMax = 1 * 1000,
}

-- Baseline attacker wave count and size. Later pressure modifiers can adjust
-- these targets after the baseline is rolled.
ConquestConfig.AttackerWaves = {
	MaxWavesMin = 4,
	MaxWavesMax = 5,

	MinUnits = 5,
	MaxUnits = 6,

	Pattern = "escalating",
	MinWaveUnits = 1,
}

-- Wave-shape multipliers used by AttackerWaves.Pattern.
ConquestConfig.AttackerWavePatterns = {
	flat = {
		First = 1.00,
		Middle = 1.00,
		Final = 1.00,
	},

	escalating = {
		First = { Scale = 0.85, Intent = "probe" },
		Middle = { Scale = 1.00, Intent = "main_attack" },
		Final = { Scale = 1.25, Intent = "main_attack" },
	},

	frontloaded = {
		First = 1.25,
		Middle = 0.95,
		Final = 1.00,
	},

	last_push = {
		First = 0.90,
		Middle = 1.00,
		Final = 1.40,
	},
}

-- Dynamic delay between completed attacker waves.
-- Campaign pressure defines the allowed wait window; scene snapshot pressure later decides where inside that window the next wave releases.
ConquestConfig.AttackerDynamicWaveOff = {
	FirstCheckSeconds = 120, -- Earliest time after a wave finishes where scene-query can start checking whether the next wave should release.
	RepeatPollIntervalSeconds = 30, --  How often the controller re-checks whether the next wave should release.
	ForceReleaseSeconds = 300, -- Hard maximum wait before the next wave releases even if scene pressure says to keep holding.
	QueryIntervalSeconds = 15, --  Scene-query interval used by the wave-off controller.
	RandomVarianceSeconds = 10, -- Small +/- timing variation added to the calculated wave-off target so releases are not perfectly predictable.

	RetainedRatio = 0.80, -- Clamped pressure ratio where the current attacker force still counts as retained.
	DegradedRatio = 0.40, -- Clamped pressure ratio where earlier next-wave release may be justified.


	-- Target wave-off time based on current attacker pressure compared to the latest wave-added baseline.
	-- Lower values release the next wave sooner; higher values give existing pressure more time to work.
	WaveOffSecondsByAttackerState = {
		degraded = 135, -- Previous attacker wave is heavily reduced; next wave can arrive sooner.
		reduced = 165, -- Previous attacker wave is partially reduced; use a moderate wave-off.
		retained = 210, -- Previous attacker wave is mostly intact; delay longer before adding more pressure.
	},

	-- Adds/subtracts time based on attacker objective progress.
	-- Negative values release sooner; positive values delay longer.
	ObjectiveProgressSecondsDelta = {
		no_objective_progress = -15, -- Attacker has made no flag progress; apply more pressure sooner.
		objective_contested = 0, -- Attacker has neutralized/contested a flag but not captured one; keep baseline timing.
		objective_progress = 20, -- Attacker has captured at least one flag; delay slightly to avoid over-stacking pressure.
		all_objectives_taken = 40, -- Attacker owns all flags; delay more because the battle is already near completion.
	},
}

ConquestConfig.CompletedPurchaseIdleTime = {
	Min = 5 * 60000,
	Max = 5 * 60000,
}

ConquestConfig.DefenderOpening = {
	-- Defender opening purchase target is rolled per objective flag, then multiplied by flag count.
	-- Purchase-pressure deltas also apply per flag.
	MinUnitsPerFlag = 7,
	MaxUnitsPerFlag = 8,

	-- Floor on the per-flag result. Without it a weak player on easy and low risk drives the garrison to nothing.
	MinUnitsPerFlagFloor = 3,

	-- Defender opening units hold their spawn/mission-script positions instead of entering Lua movement rotation.
	UnitsHoldMovement = true,

	-- Time limit on the garrison purchases. Units still unbought when it expires are dropped to prevent them spawning in front of the player later
	MaxDuration = 60 * 1000,
}

ConquestConfig.DefenderCounterattack = {
	MinUnits = 3,
	MaxUnits = 5,

	-- Flag ownership must remain changed for this long before the defender responds.
	ConfirmDelay = 50 * 1000,

	-- Delay after confirmation before the counterattack purchase burst starts.
	ResponseDelayMin = 10 * 1000,
	ResponseDelayMax = 30 * 1000,

	-- Delay between separate counterattack bursts that were already queued.
	ChainedResponseDelayMin = 30 * 1000,
	ChainedResponseDelayMax = 60 * 1000,

	-- Chance to respond after a confirmed flag loss. 1.0 = always.
	ResponseChance = 0.75,

	MaxTotal = 3,
	MaxPerFlag = 1,

}

-- Purchase-count deltas applied after baseline phase counts are rolled.
ConquestConfig.PurchasePressure = {
	-- Clamp on the summed delta, per phase. A guard against stacked modifiers
	-- defender_opening needs more room because its delta applies per flag and is then multiplied by flag count.
	DeltaClamp = {
		Default = { min = -2, max = 8 },
		attacker_wave = { min = -2, max = 8 },
		defender_opening = { min = -7, max = 8 },
		defender_counterattack = { min = -2, max = 8 },
	},

	DifficultyPurchaseCountDelta = {
		easy = {
			attacker_wave = -1,
			defender_opening = -1,
			defender_counterattack = 0,
		},
		normal = {
			attacker_wave = 0,
			defender_opening = 0,
			defender_counterattack = 0,
		},
		hard = {
			attacker_wave = 0,
			defender_opening = 1,
			defender_counterattack = 1,
		},
		heroic = {
			attacker_wave = 1,
			defender_opening = 2,
			defender_counterattack = 2,
		},
	},

	RiskPurchaseCountDelta = {
		low = {
			attacker_wave = 0,
			defender_opening = -1,
			defender_counterattack = -1,
		},
		standard = {
			attacker_wave = 0,
			defender_opening = 0,
			defender_counterattack = 0,
		},
		high = {
			attacker_wave = 0,
			defender_opening = 1,
			defender_counterattack = 1,
		},
	},

	CPLimitStages = {
		{ band = "Stage1", max = 60 },
		{ band = "Stage2", max = 140 }, -- +80
		{ band = "Stage3", max = 240 }, -- +100
		{ band = "Stage4", max = 360 }, -- +120
		{ band = "Stage5", max = nil }, -- open-ended. Any value > Stage4.
	},

	PlayerBattleScalePurchaseCountDelta = {
		Stage1 = {
			attacker_wave = -1,
			defender_opening = -3,
			defender_counterattack = 0,
		},
		Stage2 = {
			attacker_wave = 0,
			defender_opening = -3,
			defender_counterattack = 0,
		},
		Stage3 = {
			attacker_wave = 1,
			defender_opening = 1,
			defender_counterattack = 1,
		},
		Stage4 = {
			attacker_wave = 3,
			defender_opening = 2,
			defender_counterattack = 2,
		},
		Stage5 = {
			attacker_wave = 5,
			defender_opening = 3,
			defender_counterattack = 2,
		},
	},

	CommitmentThresholds = {
		{ band = "LowCommitment", max = 0.49 },
		{ band = "NormalCommitment", max = 0.84 },
		{ band = "FullCommitment", max = nil },
	},

	PlayerBattleCommitmentPurchaseCountDelta = {
		LowCommitment = {
			attacker_wave = -1,
			defender_opening = -1,
			defender_counterattack = 0,
		},
		NormalCommitment = {
			attacker_wave = 0,
			defender_opening = 0,
			defender_counterattack = 0,
		},
		FullCommitment = {
			attacker_wave = 0,
			defender_opening = 1,
			defender_counterattack = 0,
		},
	},
}


-- Force identity and slot-planning configuration.
ConquestConfig.PurchaseForces = {
	PrimaryForceRoll = {
		"infantry_force",
		"armored_force",
	},

	SecondaryForceRoll = {
		infantry_force = {
			"none",
			"none",
			"armored_force",
			"anti_tank_force",
			"artillery_support_force",
			"aa_support_force",
		},

		armored_force = {
			"none",
			"none",
			"anti_tank_force",
			"artillery_support_force",
			"aa_support_force",
		},
	},

	SecondaryShare = 0.25,
	SecondaryShareByForce = {
		armored_force = 0.25,
		anti_tank_force = 0.20,
		artillery_support_force = {
			easy = 0.05,
			normal = 0.05,
			hard = 0.10,
			heroic = 0.15,
		},
		aa_support_force = 0.15,
	},
	SecondaryMinTarget = 3,

	SingleForceCost = 0.35,
	DefaultForceCost = 1.0,
}

-- Lane-budget tuning for force identity profiles.
-- purchase_profiles.lua applies this data; designers should adjust ratios here,
-- not inside profile-building code.
ConquestConfig.PurchaseProfiles = {
	PrimaryForce = {
		infantry_force = {
			OrganicSupportShare = 0.40,
		},

		armored_force = {
			BodyShare = 0.35,
			InfantrySupportShare = 0.50,
			-- Mobile support receives the remaining primary-force budget.
		},
	},

	Probe = {
		armored_force = {
			MobileShare = 0.20,
			InfantryShare = 0.60,
			-- Light armor receives the remaining probe budget.
		},
	},
}

-- Unit-selection weights and phase policy.
-- Purchase scoring applies this data; the design/tuning values live here.
ConquestConfig.PurchaseScoring = {
	AvailabilityWeight = {
		["0.9"] = 2.00,
		["1.0"] = 1.70,
		["1.1"] = 1.40,
		["1.2"] = 1.10,
		["1.3"] = 0.80,
		["1.4"] = 0.55,
		["1.5"] = 0.35,
		["1.6"] = 0.20,
		["1.7"] = 0.10,
	},

	DifficultyGradeWeight = {
		easy = {
			Grade1 = 1.60,
			Grade2 = 1.15,
			Grade3 = 0.45,
			Grade4 = 0.15,
		},

		normal = {
			Grade1 = 1.05,
			Grade2 = 1.25,
			Grade3 = 0.85,
			Grade4 = 0.35,
		},

		hard = {
			Grade1 = 0.55,
			Grade2 = 1.10,
			Grade3 = 1.25,
			Grade4 = 0.85,
		},

		heroic = {
			Grade1 = 0.30,
			Grade2 = 0.85,
			Grade3 = 1.30,
			Grade4 = 1.20,
		},
	},

	-- Class-tier gate (parallel to DifficultyGradeWeight)
	DifficultyClassWeight = {
		Curve = {
			easy = {
				Light = 1.30,
				Medium = 0.75,
				Heavy = 0.30,
			},

			normal = {
				Light = 1.15,
				Medium = 1.00,
				Heavy = 0.55,
			},

			hard = {
				Light = 0.90,
				Medium = 1.10,
				Heavy = 1.00,
			},

			heroic = {
				Light = 0.75,
				Medium = 1.05,
				Heavy = 1.25,
			},
		},

		-- Per-base-category gate strength (0 = no gating, 1 = full curve).
		ClassGateStrength = {
			Tank = 1.00,
			SPG = 0.80,
			Vehicle = 0.50,
			Cannon = 0.45,
		},
	},

	-- Controls the split between heavy mortars (not medium mortars) and artillery
	DifficultyIndirectWeight = {
		easy = {
			HeavyMortar = 1.60,
			Artillery = 0.05,
		},

		normal = {
			HeavyMortar = 1.55,
			Artillery = 0.10,
		},

		hard = {
			HeavyMortar = 0.95,
			Artillery = 0.85,
		},

		heroic = {
			HeavyMortar = 0.70,
			Artillery = 1.30,
		},
	},

	-- Global reduction for single infantry so purchase selection prefers squads when lane fit is otherwise equal.
	SingleInfantryWeight = 0.70,

	PhaseFit = {
		attacker_wave = {
			OffensiveOrFlexible = 1.15,
			Defensive = 0.70,
		},

		defender_counterattack = {
			OffensiveOrFlexible = 1.15,
			Defensive = 0.70,
		},

		defender_opening = {
			DefensiveOrFlexible = 1.15,
			MountedInfantry = 0.0,
			OffensiveVehicleSupport = 0.0,
		},
	},

	LaneFit = {
		infantry_body = {
			InfantryLine = 1.00,
			ReconInfantrySquad = 0.65,
			ReconInfantrySingle = 0.35,
			AssaultInfantrySquad = 0.65,
		},

		infantry_organic_support = {
			CannonMachineGun = 1.00,
			LightCannonMortar = 1.00,
			CannonInfantryGun = 1.00,
			FieldGun = 0.90,
			LightCannonAntiArmor = 0.90,
			InfantryAT = 0.65,
			MobileInfantryGun = 0.40,
		},

		armored_body = {
			ArmorTank = 1.00,
			ReconVehicleOrTank = 0.80,
		},

		armored_infantry_support = {
			InfantryLine = 1.15,
			ReconInfantrySquad = 0.45,
			AssaultInfantrySquad = 0.45,
			InfantryAT = 0.35,
		},

		armored_mobile_support = {
			VehicleMachineGun = 1.00,
			MobileInfantryGun = 1.00,
			AssaultVehicleOrTank = 0.90,
			CannonMachineGun = 0.45,
			VehicleMortar = 0.45,
			VehicleRecon = 0.45,
		},

		secondary_armored_force = {
			ArmorTank = 1.00,
			ReconVehicleOrTank = 0.85,
			AssaultVehicleOrTank = 0.65,
		},

		anti_tank_force = {
			InfantryAT = 0.45,
			FieldGun = 0.85,
			AntiArmor = 1.00,
		},

		artillery_support_force = {
			Artillery = 1.00,
			HeavyMortar = 0.80,
		},

		aa_support_force = {
			AirDefense = 1.00,
		},

		probe_mobile = {
			ReconVehicleOrTank = 1.25,
			VehicleMachineGun = 1.15,
			LightArmorTank = 0.75,
		},

		probe_infantry = {
			InfantryLine = 0.50,
			ReconInfantrySquad = 1.20,
			ReconInfantrySingle = 0.35,
		},

		probe_light_armor = {
			LightArmorTank = 1.00,
			ReconVehicleOrTank = 0.90,
			VehicleMachineGun = 0.65,
			NonHeavyArmorTank = 0.25,
		},
	},

	ArmoredInfantrySupportPhaseFit = {
		attacker_wave = {
			MountedInfantry = 1.25,
		},
	},

	SupportLanePhaseFit = {
		PhaseRules = {
			attacker_wave = {
				MobilePlatform = 1.15,
				Cannon = 0.70,
				HeavyIndirectSupport = 0.70,
				MobileAirDefense = 1.10,

				LaneRules = {
					infantry_organic_support = { InfantryAT = 1.15 },
					anti_tank_force = { InfantryAT = 1.15 },
				},
			},

			defender_counterattack = {
				MobilePlatform = 1.15,
				Cannon = 0.55,
				HeavyIndirectSupport = 0.55,
				MobileAirDefense = 1.10,

				LaneRules = {
					infantry_organic_support = { InfantryAT = 1.15 },
					anti_tank_force = { InfantryAT = 1.15 },
				},
			},
		},
	},
}

-- Maximum time the AI waits for resources or unit timer before choosing again.
ConquestConfig.UnitSpawnWaitTime = 1.5 * 60000 -- 1:30 min (ms)

-- Time delay before a squad receives a refreshed order. Loops while squad exists.
ConquestConfig.OrderRotationPeriod = 2.5 * 60000 -- 2:30 min (ms)


-- Post-final-wave attacker failure watcher.
-- Runs after the final attacker wave completes and requests attacker retreat when the
-- attacker's assault strength has fallen to the bar set by the player's remaining defense.
-- Mission script should react by ordering attacker retreat, then set gameover_request_player_win when ready to end.
ConquestConfig.AttackerFailure = {
	InitialCheckDelaySeconds = 60,
	RepeatCheckIntervalSeconds = 15,

	-- bar = clamp(playerDefense * PlayerDefenseRatio, MinBar, MaxBar)
	-- The ratio carries the per-group tightening; the closer to winning, the weaker the attacker may get before it is judged finished.
	-- MaxBar is a stall guard, not a difficulty lever. Set below a plausible surviving force it would only hold a lost battle open.

	-- Attacker owns no objectives and has not neutralized/captured one.
	NoProgress = {
		PlayerDefenseRatio = 0.30,
		MinBar = 12,
		MaxBar = 40,
	},

	-- Attacker owns or has neutralized/captured at least one objective.
	PartialProgress = {
		PlayerDefenseRatio = 0.22,
		MinBar = 8,
		MaxBar = 40,
	},

	-- Attacker owns all but one objective.
	NearVictory = {
		PlayerDefenseRatio = 0.15,
		MinBar = 6,
		MaxBar = 40,
	},
}

