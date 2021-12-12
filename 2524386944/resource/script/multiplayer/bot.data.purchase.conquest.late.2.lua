Purchases["campaign_capture_the_flag"] = {
	{--purchase 1 starting recon wave
		divisionName = "Tank division",
		waveNumber = 1,
		-- Repeat = 6,
		minRepeat = 3,
		maxRepeat = 6,
		skipPossible = false,
		waveDuration = 3,
		Units = {
			["ger"] = {--Germany
				--Infantry Squads
				--Wheel_vehicles
				{priority = 0.1, class = UnitClass.Vehicle, unit = "p204_f"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz231"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz221"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_2"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_pz_pio_con"},
			},
			["rus"] = {--Russia
			--Infantry Singles
			--Wheel_vehicles
				{priority = 1.8, class = UnitClass.Vehicle, unit = "m3a1e1_scout_mgun"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ba6"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "ba64"},
			}
		}
	},
	{--purchase 2 tank assault group
		waveNumber = 2,
	    -- Repeat = 10,
		minRepeat = 4,
		maxRepeat = 8,
	    skipPossible = false,
	    waveDuration = 3,
		Units = {
			["ger"] = {--Germany
			--Tanks_heavy
			    {priority = 2.5, class = UnitClass.HeavyTank, unit = "panzer5a"},
				{priority = 2.0, class = UnitClass.HeavyTank, unit = "panzer5g"},
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "tiger1e"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "tiger1h"},
				{priority = 0.2, class = UnitClass.HeavyTank, unit = "tiger1hunt"},
				{priority = 0.1, class = UnitClass.HeavyTank, unit = "tiger2h"},
			--Tanks_medium
			    {priority = 2.5, class = UnitClass.Tank, unit = "panzer3m"},
				{priority = 3.5, class = UnitClass.Tank, unit = "panzer4h"},
				{priority = 3.0, class = UnitClass.Tank, unit = "panzer4j"},
			},
			["rus"] = {--Russia
			--Tanks_heavy
				{priority = 0.1, class = UnitClass.HeavyTank, unit = "churchill3"},
				{priority = 0.1, class = UnitClass.HeavyTank, unit = "kv85"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "kv1s"},
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "is1_43"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "is2_43"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "is2_44"},
            --Tanks_medium
				{priority = 3.5, class = UnitClass.Tank, unit = "t3476_43"},
				{priority = 0.1, class = UnitClass.Tank, unit = "t3457_43"},
				{priority = 0.5, class = UnitClass.Tank, unit = "t3476_43_flame"},
				{priority = 2.5, class = UnitClass.Tank, unit = "t3485_44"},
			}
		}
	},
	{--purchase 3 infantry support
		waveNumber = 3,
		-- Repeat = 8,
		minRepeat = 6,
		maxRepeat = 8,
        skipPossible = false,		
		waveDuration = 3,
		Units = {
			["ger"] = {--Germany
			--Infantry Squads
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_pz_pio_con"},
			},
			["rus"] = {--Russia
			--Infantry Squads
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_rifleunit_con(rus)"},
			}
		}
	},
	{--purchase 4 SPG support
		waveNumber = 4,
		-- Repeat = 4,
		minRepeat = 1,
		maxRepeat = 4,
        skipPossible = false,		
		waveDuration = 3,
		Units = {
			["ger"] = {--Germany
			--SPG
				{priority = 2.5, class = UnitClass.ATTank, unit = "stug3g_late"},
				{priority = 2.0, class = UnitClass.ATTank, unit = "stug3g"},
				{priority = 0.1, class = UnitClass.Tank, unit = "grille_m"},
				{priority = 4.0, class = UnitClass.ArtilleryTank, unit = "stuh42"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sturmpanzer4"},
				{priority = 1.1, class = UnitClass.ArtilleryTank, unit = "sturmtiger"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "jagdpanther"}
			},
			["rus"] = {--Russia
			--SPG
				{priority = 2.0, class = UnitClass.ATTank, unit = "su100"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "su152"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "isu122s"},
				{priority = 2.0, class = UnitClass.ATTank, unit = "isu152"}
			}
		}
	},
	{--purchase 5 Tank 2
		waveNumber = 5,
		-- Repeat = 4,
		minRepeat = 2,
		maxRepeat = 4,
        skipPossible = false,		
		waveDuration = 3,
		Units = {
			["ger"] = {--Germany
			--Tanks_heavy
			    {priority = 2.5, class = UnitClass.HeavyTank, unit = "panzer5a"},
				{priority = 2.0, class = UnitClass.HeavyTank, unit = "panzer5g"},
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "tiger1e"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "tiger1h"},
				{priority = 0.2, class = UnitClass.HeavyTank, unit = "tiger1hunt"},
				{priority = 0.1, class = UnitClass.HeavyTank, unit = "tiger2h"},
			--Tanks_medium
			    {priority = 2.5, class = UnitClass.Tank, unit = "panzer3m"},
				{priority = 3.5, class = UnitClass.Tank, unit = "panzer4h"},
				{priority = 3.0, class = UnitClass.Tank, unit = "panzer4j"},
			},
			["rus"] = {--Russia
			--Tanks_heavy
				{priority = 0.1, class = UnitClass.HeavyTank, unit = "churchill3"},
				{priority = 0.1, class = UnitClass.HeavyTank, unit = "kv85"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "kv1s"},
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "is1_43"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "is2_43"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "is2_44"},
            --Tanks_medium
				{priority = 3.5, class = UnitClass.Tank, unit = "t3476_43"},
				{priority = 0.1, class = UnitClass.Tank, unit = "t3457_43"},
				{priority = 0.5, class = UnitClass.Tank, unit = "t3476_43_flame"},
				{priority = 2.5, class = UnitClass.Tank, unit = "t3485_44"},
			}
		}
	},
	{--purchase 6 infantry attack 2
		waveNumber = 6,
		-- Repeat = 8,
		minRepeat = 6,
		maxRepeat = 8,
        skipPossible = false,		
		waveDuration = 3,
		Units = {
			["ger"] = {--Germany
			--Infantry Squads
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_con(ger)"},
				{priority = 3.0, class = UnitClass.Infantry, unit = "squad_pz_pio_con"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "blitz3_6_flak30"},
			},
			["rus"] = {--Russia
			--Infantry Squads
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_rifleunit_con(rus)"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "gaz_aaa_72k"},
			}
		}
	},
	{--purchase 7 rocket arty
		waveNumber = 7,
		-- Repeat = 2,
		minRepeat = 1,
		maxRepeat = 1,
        skipPossible = false,		
		waveDuration = 3,
		Units = {
			["ger"] = {--Germany
		       {priority = 2.0, class = UnitClass.ArtilleryTank, unit = "150mm_sfh18"},
			},
			["rus"] = {--Russia
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "152mm_ml20"},
			}
		}
	}
}

--Conversion Chart
--0.9 = 3.5
--1.0 = 3
--1.1 = 2.5
--1.2 = 2
--1.3 = 1.5
--1.4 = 1
--1.5 = 0.5
--1.6 = 0.1
