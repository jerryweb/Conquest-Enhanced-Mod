Purchases["campaign_capture_the_flag"] = {
	{--purchase 1 starting recon wave
		divisionName = "GSM Prototype Division",
		waveNumber = 1,
		minRepeat = 3,
		maxRepeat = 6,
		skipPossible = false,
		waveDuration = 20,
		Units = {
			["ger"] = {--Germany
				--Infantry Squads
					{priority = 0.7, class = UnitClass.Infantry, unit = "squad_regular_armor_con"},
					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_regular_vet_con(ger)"},
					{priority = 0.7, class = UnitClass.Infantry, unit = "squad_gd_motor_con"},

					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_pionier_con(ger)"},
					{priority = 0.7, class = UnitClass.Infantry, unit = "squad_pz_pio_con"},

					{priority = 0.5, class = UnitClass.Infantry, unit = "squad_jaeger_con(ger)"},
					{priority = 0.5, class = UnitClass.Infantry, unit = "squad_gebirgsjaeger_con(ger)"},

				--Tanks_light
					{priority = 0.5, class = UnitClass.Tank,  unit = "panzer2l"},
					{priority = 0.7, class = UnitClass.Tank,  unit = "panzer2j"},			
			},
			["rus"] = {--Russia

				--Infantry Squads
					{priority = 1.5, class = UnitClass.ATInfantry, unit = "squad_at_rifle_con(rus)"},
					{priority = 1.5, class = UnitClass.Infantry, unit = "squad_smg_con(rus)"},
					{priority = 0.5, class = UnitClass.Infantry, unit = "squad_rifle_motorised_con"},

					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_guards_smg_con(rus)"},
					{priority = 0.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_motorised_con"},
					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_con(rus)"},
					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_flame_con(rus)"},

					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_spetsnaz(rus)"},
					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_marines_con(rus)"},

				--Tanks_light
					{priority = 0.5, class = UnitClass.Tank, unit = "t80"},
					{priority = 0.7, class = UnitClass.Tank, unit = "t50"},
			}
		}
	},
    {--purchase officer
		waveNumber = 1,
		minRepeat = 1,
		maxRepeat = 1,
        skipPossible = true,
	    skipChance = 0.45,		
		waveDuration = 5,
		Units = {
			["ger"] = {--Germany
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_officer(ger)"},
				{priority = 0.5, class = UnitClass.Infantry, unit = "squad_officer_con(ger)"},
				{priority = 0.7, class = UnitClass.Infantry, unit = "squad_officer_kubel_con"},
				{priority = 0.2, class = UnitClass.Infantry, unit = "squad_officer_250_3_con"},
			},
			["rus"] = {--Russia
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_officer(rus)"},
				{priority = 0.5, class = UnitClass.Infantry, unit = "squad_officer_con(rus)"},
				{priority = 0.1, class = UnitClass.Infantry, unit = "squad_officer_gaz_con"},
			},
		}
	},
	{--purchase 3 super heavy tank
		waveNumber = 3,
		minRepeat = 1,
		maxRepeat = 2,
		skipPossible = false,
		waveDuration = 20,
		Units = {
			["ger"] = {--Germany
				--Tanks_heavy
					{priority = 1.0, class = UnitClass.HeavyTank, unit = "maus"},
			},
			["rus"] = {--Russia
				--Tanks_heavy
					{priority = 1.0, class = UnitClass.HeavyTank, unit = "is3"},
			}
		}
	},
	{--purchase 4 infantry support
		waveNumber = 6,
		minRepeat = 4,
		maxRepeat = 6,
        skipPossible = false,		
		waveDuration = 20,
		Units = {
			["ger"] = {--Germany
				--Infantry Singles
					{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(ger)"},
					{priority = 1.0, class = UnitClass.Infantry, unit = "single_flamer(ger)"},
					{priority = 1.0, class = UnitClass.Infantry, unit = "single_sniper(ger)"},

				--Infantry Squads
					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_regular_armor_con"},
					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_regular_vet_con(ger)"},
					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_gd_motor_con"},

					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_pionier_con(ger)"},
					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_pz_pio_con"},

					{priority = 0.5, class = UnitClass.Infantry, unit = "squad_jaeger_con(ger)"},
					{priority = 0.5, class = UnitClass.Infantry, unit = "squad_gebirgsjaeger_con(ger)"},
			},
			["rus"] = {--Russia
				--Infantry Singles
					{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(rus)"},
					{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(rus)"},
					{priority = 2.0, class = UnitClass.Infantry, unit = "single_sniper(rus)"},

				--Infantry Squads
					{priority = 1.5, class = UnitClass.ATInfantry, unit = "squad_at_rifle_con(rus)"},
					{priority = 1.5, class = UnitClass.Infantry, unit = "squad_smg_con(rus)"},
					{priority = 2.0, class = UnitClass.Infantry, unit = "squad_rifle_motorised_con"},

					{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_guards_smg_con(rus)"},
					{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_motorised_con"},
					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_con(rus)"},
					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_flame_con(rus)"},

					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_spetsnaz(rus)"},
					{priority = 1.5, class = UnitClass.Infantry, unit = "squad_marines_con(rus)"},
			}
		}
	},
	{--purchase 5 SPG support
		waveNumber = 5,
		minRepeat = 1,
		maxRepeat = 3,
        skipPossible = false,		
		waveDuration = 40,
		Units = {
			["ger"] = {--Germany
				--SPG
					{priority = 0.3, class = UnitClass.ATTank,  unit = "sdkfz301wanze"},
					{priority = 0.3, class = UnitClass.ATTank, unit = "dicker_max"}, 
					{priority = 0.3, class = UnitClass.ATTank, unit = "sturer_emil"}, 
					{priority = 0.5, class = UnitClass.ATTank,  unit = "nashorn"}, 
					{priority = 0.6, class = UnitClass.ATTank,  unit = "jagdpanzer_iv"},
					{priority = 0.5, class = UnitClass.ATTank,  unit = "elefant"},
					{priority = 0.5, class = UnitClass.ArtilleryTank,  unit = "grille"},
					{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "kv2_754r"},			
			},
			["rus"] = {--Russia
				--SPG
					{priority = 1.0, class = UnitClass.ATTank, unit = "wolverine"},
					{priority = 1.0, class = UnitClass.ATTank,  unit = "su100"},
					{priority = 1.2, class = UnitClass.ATTank, unit = "su122"},
					{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "su152"},
					{priority = 1.0, class = UnitClass.ArtilleryTank,  unit = "isu152"},
					{priority = 1.0, class = UnitClass.ATTank,  unit = "isu122s"},
			}
		}
	},
	{--purchase 6 Support Vehicle wave
		waveNumber = 6,
		minRepeat = 3,
		maxRepeat = 4,
		skipPossible = false,
	    waveDuration = 10,
		Units = {
			["ger"] = {--Germany
				--Wheel_vehicles,,
					{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_3"},
					{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_4"},

				--Half_tracks
					{priority = 0.5, class = UnitClass.ATTank, unit = "sdkfz8_flak18"},
				--Tanks_medium
					{priority = 0.7, class = UnitClass.Tank, unit = "ostwind"},
					{priority = 0.9, class = UnitClass.Tank, unit = "kugelblitz"},
			},
			["rus"] = {--Russia
				--Wheel_vehicles
					{priority = 1.0, class = UnitClass.Vehicle, unit = "gaz_aaa_72k"},
					{priority = 1.5, class = UnitClass.Vehicle, unit = "ba20"},
					{priority = 1.0, class = UnitClass.Vehicle, unit = "m17"},
					{priority = 1.0, class = UnitClass.Vehicle, unit = "yag10_29k"},
			}
		}	
	},	
	{--purchase 3  tank assault group
		waveNumber = 3,
		minRepeat = 2,
		maxRepeat = 4,
	    skipPossible = false,
	    waveDuration = 10,
		Units = {
			["ger"] = {--Germany

			--Tanks_medium
				{priority = 0.5, class = UnitClass.Tank, unit = "panzer3_flamm"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4h"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4j"},
				{priority = 0.8, class = UnitClass.Tank, unit = "char_b1_flamer"},
				{priority = 0.7, class = UnitClass.Tank, unit = "t3485_44_ger"},
				{priority = 2.7, class = UnitClass.Tank, unit = "m4a4_firefly_ger"},

			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "panzer5d"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "panzer5a"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "panzer5g"},
				{priority = 0.8, class = UnitClass.HeavyTank, unit = "tiger_p"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "tiger1hunt"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "tiger2p"},
				{priority = 0.8, class = UnitClass.HeavyTank, unit = "pz756r"},
			},
			["rus"] = {--Russia
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank,  unit = "t3476_43_flame"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "valentine9"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "m4a2"},
				{priority = 0.8, class = UnitClass.Tank,  unit = "m4a2_76w"},
				{priority = 0.8, class = UnitClass.Tank,  unit = "t44"},
				{priority = 0.6, class = UnitClass.Tank,  unit = "t44_122"},

			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "churchill3"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "is1_43"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "is2_43"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "is2_44"},
				{priority = 0.8, class = UnitClass.HeavyTank,unit = "kv-122"},
				{priority = 0.7, class = UnitClass.HeavyTank, unit = "kv220"},
			}
		}
	},
	{--purchase 8 infantry attack 2
		waveNumber = 8,
		minRepeat = 4,
		maxRepeat = 8,
        skipPossible = false,		
		waveDuration = 35,
		Units = {
			["ger"] = {--Germany
				--Infantry Singles
					{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(ger)"},
					{priority = 1.0, class = UnitClass.Infantry, unit = "single_flamer(ger)"},
					{priority = 1.0, class = UnitClass.Infantry, unit = "single_sniper(ger)"},

				--Infantry Squads
					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_regular_armor_con"},
					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_regular_vet_con(ger)"},
					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_gd_motor_con"},

					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_pionier_con(ger)"},
					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_pz_pio_con"},

					{priority = 0.5, class = UnitClass.Infantry, unit = "squad_jaeger_con(ger)"},
					{priority = 0.5, class = UnitClass.Infantry, unit = "squad_gebirgsjaeger_con(ger)"},
			},
			["rus"] = {--Russia
				--Infantry Singles
					{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(rus)"},
					{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(rus)"},
					{priority = 2.0, class = UnitClass.Infantry, unit = "single_sniper(rus)"},

				--Infantry Squads
					{priority = 1.5, class = UnitClass.ATInfantry, unit = "squad_at_rifle_con(rus)"},
					{priority = 1.5, class = UnitClass.Infantry, unit = "squad_smg_con(rus)"},
					{priority = 2.0, class = UnitClass.Infantry, unit = "squad_rifle_motorised_con"},

					{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_guards_smg_con(rus)"},
					{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_motorised_con"},
					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_con(rus)"},
					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_flame_con(rus)"},

					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_spetsnaz(rus)"},
					{priority = 1.5, class = UnitClass.Infantry, unit = "squad_marines_con(rus)"},
			}
		}
	},
	{--purchase 9 arty
		waveNumber = 9,
		minRepeat = 1,
		maxRepeat = 2,
        skipPossible = true,		
		waveDuration = 5,
		isHeavyArty = true,	
		Units = {
			["ger"] = {--Germany
				--Artillery
					{priority = 1.0, class = UnitClass.ArtilleryTank,  unit = "geschuetzwagen_ivb"},
				-- Rocket_Artillery
					{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "zgkw303f"},
					{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sdkfz251_1_stuka"},		
			},
			["rus"] = {--Russia
				--Artillery
					{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "su5"},
					{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "su14"},
				--Rocket_Artillery
					{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bm31_12ai"},
					{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bm_8_24"},
			}
		}
	},	
	{--purchase 10  tank assault group
		waveNumber = 10,
		minRepeat = 2,
		maxRepeat = 4,
	    skipPossible = false,
	    waveDuration = 10,
		Units = {
			["ger"] = {--Germany

			--Tanks_medium
				{priority = 0.5, class = UnitClass.Tank, unit = "panzer3_flamm"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4h"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4j"},
				{priority = 0.8, class = UnitClass.Tank, unit = "char_b1_flamer"},
				{priority = 0.7, class = UnitClass.Tank, unit = "t3485_44_ger"},
				{priority = 0.7, class = UnitClass.Tank, unit = "m4a4_firefly_ger"},

			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "panzer5d"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "panzer5a"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "panzer5g"},
				{priority = 0.8, class = UnitClass.HeavyTank, unit = "tiger_p"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "tiger1hunt"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "tiger2p"},
				{priority = 0.8, class = UnitClass.HeavyTank, unit = "pz756r"},
			},
			["rus"] = {--Russia
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank,  unit = "t3476_43_flame"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "valentine9"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "m4a2"},
				{priority = 0.8, class = UnitClass.Tank,  unit = "m4a2_76w"},
				{priority = 0.8, class = UnitClass.Tank,  unit = "t44"},
				{priority = 0.6, class = UnitClass.Tank,  unit = "t44_122"},

			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "churchill3"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "is1_43"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "is2_43"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "is2_44"},
				{priority = 0.8, class = UnitClass.HeavyTank,unit = "kv-122"},
				{priority = 0.7, class = UnitClass.HeavyTank, unit = "kv220"},
			}
		}
	},
	{--purchase 11 light tank rush
		waveNumber = 11,
		minRepeat = 4,
		maxRepeat = 6,
        skipPossible = false,		
		waveDuration = 10,
		Units = {
			["ger"] = {--Germany
				--Tanks_light
					{priority = 0.5, class = UnitClass.Tank,  unit = "grille_m"},
					{priority = 0.5, class = UnitClass.Tank,  unit = "panzer2h"},
					{priority = 0.6, class = UnitClass.Tank,  unit = "panzer2l"},
					{priority = 0.7, class = UnitClass.Tank,  unit = "panzer2j"},
			},
			["rus"] = {--Russia
				--Tanks_light
					{priority = 0.4, class = UnitClass.Tank, unit = "t60"},
					{priority = 1.0, class = UnitClass.Tank, unit = "t70m"},
					{priority = 0.5, class = UnitClass.Tank, unit = "t80"},
					{priority = 0.7, class = UnitClass.Tank, unit = "t50"},
			}
		}
	},	
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
