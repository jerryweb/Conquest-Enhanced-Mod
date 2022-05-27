Purchases["campaign_capture_the_flag"] = {
	{--purchase 1 
		divisionName = "GSM Generic Mid Division",
		waveNumber = 1,
		minRepeat = 3,
		maxRepeat = 6,
		skipPossible = false,
		waveDuration = 20,
		Units = {
			["ger"] = {--Germany
			--Infantry Squads
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_pionier_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_pz_pio_con"},

				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_recon_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_recon_motor_con"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_recon_armor_con"},

				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_jaeger_con(ger)"},
			--Wheel_vehicles
				{priority = 0.5, class = UnitClass.Vehicle, unit = "kubelwagen_mg"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz231"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "sdkfz234_1"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "sdkfz222"},

			--Half_tracks
				{priority = 1.0, class = UnitClass.Vehicle, unit = "sdkfz251c"},
			},
			["rus"] = {--Russia
			--Infantry Squads
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_recon_con(rus)"},

				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_guards_smg_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_motorised_con"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_flame_con(rus)"},

			--Wheel_vehicles
				{priority = 1.5, class = UnitClass.Vehicle, unit = "gaz67b"},
				{priority = 2.0, class = UnitClass.Vehicle, unit = "ba6"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "ba64"},
				{priority = 0.75, class = UnitClass.Vehicle, unit = "universal_carrier_rus"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1e1_scout_mgun"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ba10"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ba11"},
			}
		}
	},
	{--purchase officer
		waveNumber = 2,
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
				-- {priority = 0.2, class = UnitClass.Infantry, unit = "squad_officer_250_3_con"},
			},
			["rus"] = {--Russia
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_officer(rus)"},
				{priority = 0.5, class = UnitClass.Infantry, unit = "squad_officer_con(rus)"},
				-- {priority = 0.1, class = UnitClass.Infantry, unit = "squad_officer_gaz_con"},
			},
		}
	},
	{--purchase 3 mgun support
		waveNumber = 3,
		minRepeat = 1,
		maxRepeat = 1,
        skipPossible = true,		
		waveDuration = 5,
		Units = {
			["ger"] = {--Germany
			--HMGs
				{priority = 1.5, class = UnitClass.Vehicle, unit = "mg34_lafette"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "mg42_lafette"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "mg131_lafette"},			
			},
			["rus"] = {--Russia
			--HMGs
				{priority = 1.5, class = UnitClass.Vehicle, unit = "maxim"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "sg43_stand"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dshk_stan"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dshk_aa"},
			}
		}
	},
	{--purchase 4 mortar
		waveNumber = 4,
	    minRepeat = 1,
		maxRepeat = 2,
	    skipPossible = true,
	    skipChance = 0.4,
	    waveDuration = 5,
	    isHeavyArty = true,
		Units = {
			["ger"] = {--Germany
				--Howitzers
				{priority = 2.0, class = UnitClass.ATTank, unit = "80mm_sgrw34"},
			},
			["rus"] = {--Russia
			--Howitzers
				{priority = 2.0, class = UnitClass.ATTank, unit = "82mm_bm37"},
			},
		}
	},
	{--purchase 5 tank assault group
		waveNumber = 5,
	    minRepeat = 4,
		maxRepeat = 6,
	    skipPossible = false,
	    waveDuration = 20,
		Units = {
			["ger"] = {--Germany
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer3f"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer3j"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer3j1"},
				{priority = 0.9, class = UnitClass.Tank, unit = "panzer3l"},
				{priority = 0.8, class = UnitClass.Tank, unit = "panzer3m"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4d"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4f1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4f2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4g"},
				{priority = 0.8, class = UnitClass.Tank, unit = "d2_ger"},
				{priority = 0.5, class = UnitClass.Tank, unit = "char_b1"},
				{priority = 0.7, class = UnitClass.Tank, unit = "t3476_43_ger"},

			--Tanks_heavy
				{priority = 0.9, class = UnitClass.HeavyTank, unit = "panzer5a"},
				{priority = 0.9, class = UnitClass.HeavyTank, unit = "tiger1e"},
			},
			["rus"] = {--Russia
			--Tanks_medium
				{priority = 1.4, class = UnitClass.Tank, unit = "t28"},
				{priority = 2.0, class = UnitClass.Tank,  unit = "t3476_40"},
				{priority = 2.0, class = UnitClass.Tank,  unit = "t3476_41"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t3457_41"},
				{priority = 1.5, class = UnitClass.Tank,  unit = "valentine2"},
				{priority = 1.5, class = UnitClass.Tank,  unit = "valentine7"},
				{priority = 1.5, class = UnitClass.Tank,  unit = "valentine9"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "matilda2"},
				{priority = 1.2, class = UnitClass.Tank,  unit = "m4a2"},

			--Tanks_heavy
				{priority = 2.0, class = UnitClass.HeavyTank, unit = "kv1_40"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "kv1e_40"},
				{priority = 2.0, class = UnitClass.HeavyTank,  unit = "kv1_41"},
				{priority = 0.5, class = UnitClass.HeavyTank,  unit = "kv1e_41"},
			}
		}
	},
	{--purchase 6 SPG support 
		waveNumber = 6,
		minRepeat = 3,
		maxRepeat = 6,
		skipPossible = false,
		waveDuration = 20,
		Units = {
			["ger"] = {--Germany
			--SPG
				{priority = 0.8, class = UnitClass.Tank,  unit = "panzer2h"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "stug3b"},
				{priority = 1.0, class = UnitClass.ATTank,  unit = "stug3f"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "marder2"},
				{priority = 1.0, class = UnitClass.ATTank,  unit = "marder3h"},
				{priority = 0.5, class = UnitClass.ArtilleryTank,  unit = "geschuetzwagen_ivb"},
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "bison2"},
							
			},
			["rus"] = {--Russia
			--SPG
				{priority = 1.0, class = UnitClass.ATTank,  unit = "zis30"},
				{priority = 1.1, class = UnitClass.ATTank, unit = "su76"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "su76i"},
				{priority = 0.7, class = UnitClass.ArtilleryTank,  unit = "su5"},
				{priority = 0.5, class = UnitClass.ArtilleryTank,  unit = "kv2_40"},
			}
		}
	},
	{--purchase 7 infantry attack 2
		waveNumber = 7,
		minRepeat = 5,
		maxRepeat = 9,
        skipPossible = false,		
		waveDuration = 25,
		Units = {
			["ger"] = {--Germany
			--Infantry Singles
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_at(ger)"},
				{priority = 1.5, class = UnitClass.ATInfantry, unit = "single_riflegrenade(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(ger)"},

				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_regular_motor_con"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_regular_armor_con"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular_vet_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_gd_motor_con"},

				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_pionier_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_pz_pio_con"},

				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_jaeger_con(ger)"},			
			},
			["rus"] = {--Russia
			--Infantry Singles
				{priority = 1.5, class = UnitClass.ATInfantry, unit = "single_at(rus)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(rus)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "single_sniper(rus)"},

			--Infantry Squads
				{priority = 2.5, class = UnitClass.Infantry, unit = "squad_rifleunit_alt_con(rus)"},
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_rifleunit_con(rus)"},
				{priority = 1.5, class = UnitClass.ATInfantry, unit = "squad_at_rifle_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_smg_con(rus)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_rifle_motorised_con"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_mountainrifles_con(rus)"},
			}
		}
	},
	{--purchase 8 artillery
		waveNumber = 8,
		minRepeat = 1,
		maxRepeat = 1,
        skipPossible = true,
	    skipChance = 0.6,
	    isHeavyArty = true,		
		waveDuration = 5,
				Units = {
			["ger"] = {--Germany
			--Artillery
				{priority = 1.1, class = UnitClass.ArtilleryTank, unit = "105mm_lefh18ai"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "150mm_sfh18ai"},
				{priority = 0.8, class = UnitClass.ArtilleryTank,  unit = "wespe"},
				{priority = 0.7, class = UnitClass.ArtilleryTank,  unit = "hummel"},
			},
			["rus"] = {--Russia
			--Artillery
				{priority = 1.2, class = UnitClass.ArtilleryTank, unit = "122mm_m30ai"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "152mm_ml20ai"},
				{priority = 0.8, class = UnitClass.ArtilleryTank,  unit = "su5"},
			}
		}
	},
	{--purchase 9 support vehicles
		waveNumber = 9,
		minRepeat = 2,
		maxRepeat = 4,
        skipPossible = false,		
		waveDuration = 10,
		Units = {
			["ger"] = {--Germany
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.AATank, unit = "blitz3_6_flak30"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_2"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_3"},
			--Half_tracks
				{priority = 0.8, class = UnitClass.ATTank, unit = "sdkfz10_pak38"},
				{priority = 0.5, class = UnitClass.ATTank, unit = "sdkfz8_flak18"},
				{priority = 0.6, class = UnitClass.ATTank, unit = "sdkfz7_2"},

				{priority = 0.7, class = UnitClass.Tank, unit = "wirbelwind"},		
			},
			["rus"] = {--Russia
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "gaz_aaa_72k"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ba10"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ba11"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m17"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "yag10_29k"},
			}
		}		
	},
	{--purchase 10 light tank rush
		waveNumber = 10,
		minRepeat = 4,
		maxRepeat = 8,
        skipPossible = false,		
		waveDuration = 10,
		Units = {
			["ger"] = {--Germany
			--Wheel_vehicles
				{priority = 2.0, class = UnitClass.AATank, unit = "blitz3_6_flak30"},

				{priority = 1.0, class = UnitClass.Vehicle, unit = "sdkfz234_1"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_2"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_3"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_4"},

			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer2f"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "pz38t_a"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "pz38t_f"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "pz38t_g"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "grille_m"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "panzer2l"},
				{priority = 0.5, class = UnitClass.Tank,  unit = "panzer1f"},
				{priority = 0.8, class = UnitClass.Tank, unit = "panzer742r"},							
			},
			["rus"] = {--Russia

			--Tanks_light
				{priority = 0.5, class = UnitClass.Tank, unit = "t40"},
				{priority = 3.0, class = UnitClass.Tank, unit = "t60"},
				{priority = 3.0, class = UnitClass.Tank, unit = "t70m"},
				{priority = 3.0, class = UnitClass.Tank, unit = "bt7"},
				{priority = 3.0, class = UnitClass.Tank, unit = "bt7a"},
				{priority = 0.5, class = UnitClass.Tank, unit = "t80"},
				{priority = 0.7, class = UnitClass.Tank, unit = "m3stuart"},
				{priority = 0.7, class = UnitClass.Tank, unit = "t50"},
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
