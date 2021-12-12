Purchases["campaign_capture_the_flag"] = {
	{--purchase 1 starting recon wave
		divisionName = "Specialized division",
		waveNumber = 1,
		-- Repeat = 6,
		minRepeat = 3,
		maxRepeat = 5,
		skipPossible = false,
		waveDuration = 3,
		Units = {
			["ger"] = {--Germany
				--Infantry Squads
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_recon_con(ger)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_recon_armor_con"},
				--Wheel_vehicles
				{priority = 0.1, class = UnitClass.Vehicle, unit = "p204_f"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz231"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz221"},
			},
			["rus"] = {--Russia
			--Infantry Singles
			    {priority = 2.5, class = UnitClass.Infantry, unit = "squad_recon_con(rus)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_spetsnaz(rus)"},
			--Wheel_vehicles
				{priority = 1.8, class = UnitClass.Vehicle, unit = "m3a1e1_scout_mgun"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ba6"},
			}
		}
	},
	{--purchase 2 mortar
		waveNumber = 2,
	    -- Repeat = 2,
		minRepeat = 1,
		maxRepeat = 3,
	    skipPossible = false,
	    waveDuration = 3,
		Units = {
			["ger"] = {--Germany
				--Howitzers
				{priority = 3.0, class = UnitClass.ArtilleryTank, unit = "120mm_sgrw42"},
			},
			["rus"] = {--Russia
			--Howitzers
				{priority = 3.0, class = UnitClass.ArtilleryTank, unit = "120mm_pm38"},
			}
		}
	},
	{--purchase 3 tank assault group
		waveNumber = 3,
	    -- Repeat = 6,
		minRepeat = 4,
		maxRepeat = 6,
	    skipPossible = false,
	    waveDuration = 3,
		Units = {
			["ger"] = {--Germany
			--Tanks_heavy
				{priority = 0.7, class = UnitClass.HeavyTank, unit = "panzer5d"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "tiger1h"},
			--Tanks_medium
				{priority = 2.5, class = UnitClass.Tank, unit = "panzer3m"},
				{priority = 1.5, class = UnitClass.Tank, unit = "panzer3n"},
				{priority = 0.5, class = UnitClass.Tank, unit = "panzer3_flamm"},
				{priority = 3.0, class = UnitClass.Tank, unit = "panzer4g"},
				{priority = 3.5, class = UnitClass.Tank, unit = "panzer4h"},
		--Tanks_light
			},
			["rus"] = {--Russia
			--Tanks_light
				{priority = 0.5, class = UnitClass.Tank, unit = "valentine9"},
			--Tanks_heavy
				{priority = 1.1, class = UnitClass.Tank, unit = "t3457_43"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t3476_43_flame"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "churchill3"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "kv2_40"},
				{priority = 1.4, class = UnitClass.HeavyTank, unit = "kv1s"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "is1_43"},
			       --Tanks_medium
			}
		}
	},
	{--purchase 4 infantry support
		waveNumber = 4,
		-- Repeat = 8,
		minRepeat = 6,
		maxRepeat = 8,
        skipPossible = false,		
		waveDuration = 3,
		Units = {
			["ger"] = {--Germany
			--Infantry Squads
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_luftwaffe_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_blau_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_brandenburger_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_gebirgsjaeger_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_fallschirmjaeger_con(ger)"},
			},
			["rus"] = {--Russia
			--Infantry Squads
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_paras(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_spetsnaz(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_marines_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_guards_smg_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_flame_con(rus)"},
			}
		}
	},
	{--purchase 5 SPG support
		waveNumber = 5,
		-- Repeat = 2,
		minRepeat = 1,
		maxRepeat = 3,
        skipPossible = false,		
		waveDuration = 3,
		Units = {
			["ger"] = {--Germany
			--SPG
		        {priority = 2.0, class = UnitClass.ArtilleryTank, unit = "stuh42"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sturmpanzer4"},
				{priority = 2.5, class = UnitClass.ATTank, unit = "hetzer"},
				{priority = 1.5, class = UnitClass.ATTank, unit = "stug3f"},
				{priority = 3.0, class = UnitClass.ATTank, unit = "stug3g"},
				{priority = 0.1, class = UnitClass.Tank, unit = "grille_m"}
			},
			["rus"] = {--Russia
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "su152"},
				{priority = 1.5, class = UnitClass.ATTank, unit = "su85"},
				{priority = 1.5, class = UnitClass.ATTank, unit = "su85"},
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "su122"},
			}
		}
	},
	{--purchase 6 Tank 2
		waveNumber = 6,
		-- Repeat = 7,
		minRepeat = 5,
		maxRepeat = 8,
        skipPossible = false,		
		waveDuration = 3,
		Units = {
			["ger"] = {--Germany
			--Tanks_heavy
				{priority = 0.7, class = UnitClass.HeavyTank, unit = "panzer5d"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "tiger1h"},
			--Tanks_medium
				{priority = 2.5, class = UnitClass.Tank, unit = "panzer3m"},
				{priority = 1.5, class = UnitClass.Tank, unit = "panzer3n"},
				{priority = 0.5, class = UnitClass.Tank, unit = "panzer3_flamm"},
				{priority = 3.0, class = UnitClass.Tank, unit = "panzer4g"},
				{priority = 3.5, class = UnitClass.Tank, unit = "panzer4h"},
		--Tanks_light
			},
			["rus"] = {--Russia
			--Tanks_light
				{priority = 0.5, class = UnitClass.Tank, unit = "valentine9"},
			--Tanks_heavy
				{priority = 1.1, class = UnitClass.Tank, unit = "t3457_43"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t3476_43_flame"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "churchill3"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "kv2_40"},
				{priority = 1.4, class = UnitClass.HeavyTank, unit = "kv1s"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "is1_43"},
			       --Tanks_medium
			}
		}
	},
	{--purchase 7 infantry attack 2
		waveNumber = 7,
		-- Repeat = 10,
		minRepeat = 6,
		maxRepeat = 8,
        skipPossible = false,		
		waveDuration = 3,
		Units = {
			["ger"] = {--Germany
			--Infantry Squads
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_luftwaffe_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_blau_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_brandenburger_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_gebirgsjaeger_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_fallschirmjaeger_con(ger)"},
			},
			["rus"] = {--Russia
			--Infantry Squads
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_paras(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_spetsnaz(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_marines_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_guards_smg_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_flame_con(rus)"},
			}
		}
	},
	{--purchase 8  arty
		waveNumber = 8,
		-- Repeat = 1,
		minRepeat = 1,
		maxRepeat = 2,
        skipPossible = false,		
		waveDuration = 3,
		Units = {
			["ger"] = {--Germany
		  	    {priority = 11.0, class = UnitClass.ATTank, unit = "210mm_morser18"},
			},
			["rus"] = {--Russia
		        {priority = 11.0, class = UnitClass.ATTank, unit = "203mm_b4"},
			}
		}
	},
	{--purchase 9 light tank rush
		waveNumber = 9,
		-- Repeat = 8,
		minRepeat = 4,
		maxRepeat = 7,
        skipPossible = false,		
		waveDuration = 3,
		Units = {
			["ger"] = {--Germany
			--Wheel_vehicles
				{priority = 2.5, class = UnitClass.Vehicle, unit = "sdkfz234_2"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "blitz3_6_flak30"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz231"},
				{priority = 0.1, class = UnitClass.Vehicle, unit = "p204_f"},
				{priority = 2.5, class = UnitClass.Tank, unit = "pz38t_f"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz38t_g"},
			},
			["rus"] = {--Russia
            --Tanks_light			
			    {priority = 1.0, class = UnitClass.Tank, unit = "t60"},
				{priority = 3.0, class = UnitClass.Tank, unit = "t70"},
				{priority = 3.0, class = UnitClass.Tank, unit = "t70m"},
					{priority = 3.0, class = UnitClass.Tank, unit = "bt7"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "gaz_aaa_72k"},
			}
		}
	},
	{--purchase 9 light tank rush
		waveNumber = 9,
		-- Repeat = 4,
		minRepeat = 2,
		maxRepeat = 4,
        skipPossible = false,		
		waveDuration = 3,
		Units = {
			["ger"] = {--Germany
			--Wheel_vehicles
	            {priority = 0.5, class = UnitClass.Tank, unit = "panzer3_flamm"},
			},
			["rus"] = {--Russia
            --Tanks_light			
			 {priority = 1.0, class = UnitClass.Tank, unit = "t3476_43_flame"},
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
