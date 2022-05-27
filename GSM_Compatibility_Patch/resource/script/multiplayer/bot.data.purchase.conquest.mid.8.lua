Purchases["campaign_capture_the_flag"] = {
	{--purchase 1 
		divisionName = "GSM Irregular Division",
		waveNumber = 1,
		minRepeat = 3,
		maxRepeat = 6,
		skipPossible = false,
		waveDuration = 20,
		Units = {
			["ger"] = {--Germany
			--Infantry Squads
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_blau_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_brandenburger_con(ger)"},
				{priority = 1.1, class = UnitClass.Infantry, unit = "squad_regular_vet_con(ger)"},
				{priority = 1.2, class = UnitClass.Infantry, unit = "squad_jaeger_con(ger)"},
			--Wheel_vehicles
				{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_3"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_4"},			
			},
			["rus"] = {--Russia
			--Infantry Squads
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_penal_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_mountainrifles_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_guards_smg_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_motorised_con"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_flame_con(rus)"},
			--Wheel_vehicles
				{priority = 1.5, class = UnitClass.Vehicle, unit = "gaz67b"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "ba20"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ba10"},
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
			},
			["rus"] = {--Russia
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_officer(rus)"},
				{priority = 0.5, class = UnitClass.Infantry, unit = "squad_officer_con(rus)"},
			},
		}
	},
	{--purchase 3 mortar
		waveNumber = 3,
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
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "120mm_sgrw42"},
			},
			["rus"] = {--Russia
			--Howitzers
				{priority = 2.0, class = UnitClass.ATTank, unit = "82mm_bm37"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "120mm_pm38"},
			},
		}
	},
	{--purchase 4 tank assault group
		waveNumber = 4,
		minRepeat = 4,
		maxRepeat = 6,
	    skipPossible = false,
	    waveDuration = 20,
		Units = {
			["ger"] = {--Germany
			--Tanks_medium
				{priority = 1.05, class = UnitClass.Tank, unit = "panzer3f"},
				{priority = 1.05, class = UnitClass.Tank, unit = "panzer3j"},
				{priority = 1.05, class = UnitClass.Tank, unit = "panzer3j1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4d"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4f1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4f2"},
				{priority = 0.8, class = UnitClass.Tank, unit = "d2_ger"},
				{priority = 0.6, class = UnitClass.Tank, unit = "char_b1"},
				{priority = 0.6, class = UnitClass.Tank, unit = "char_b1_flamer"},
				{priority = 0.9, class = UnitClass.Tank, unit = "t3476_43_ger"},

			--Tanks_heavy
				{priority = 0.6, class = UnitClass.HeavyTank, unit = "pz756r"},
			},
			["rus"] = {--Russia
			--Tanks_medium
				{priority = 1.5, class = UnitClass.Tank,  unit = "valentine2"},
				{priority = 1.5, class = UnitClass.Tank,  unit = "valentine7"},
				{priority = 1.5, class = UnitClass.Tank,  unit = "valentine9"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "matilda2"},
				{priority = 1.5, class = UnitClass.Tank,  unit = "m4a2"},

			--Tanks_heavy
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "kv1e_40"},
				{priority = 0.5, class = UnitClass.HeavyTank,  unit = "kv1e_41"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "kv1s"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "churchill3"}, 
				{priority = 0.6, class = UnitClass.HeavyTank,unit = "kv-122"},
			}
		}
	},
	{--purchase 5 SPG support
		waveNumber = 5,
		minRepeat = 1,
		maxRepeat = 3,
        skipPossible = false,		
		waveDuration = 10,
		Units = {
			["ger"] = {--Germany
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "marder_1fcm_36"},
				{priority = 0.3, class = UnitClass.ATTank, unit = "dicker_max"}, 
				{priority = 0.5, class = UnitClass.ArtilleryTank,  unit = "geschuetzwagen_ivb"},
				{priority = 0.8, class = UnitClass.ArtilleryTank, unit = "bison"},
				{priority = 0.8, class = UnitClass.ArtilleryTank, unit = "bison2"},
				{priority = 0.9, class = UnitClass.ArtilleryTank, unit = "kv2_754r"},			
			},
			["rus"] = {--Russia
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "su76i"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "wolverine"},
				{priority = 0.5, class = UnitClass.ArtilleryTank,  unit = "su5"},
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "su100y"}
			}
		}
	},
	{--purchase 6 infantry support
		waveNumber = 6,
		minRepeat = 7,
		maxRepeat = 10,
        skipPossible = false,		
		waveDuration = 35,
		Units = {
			["ger"] = {--Germany
			--Infantry Singles
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_at(ger)"},
				{priority = 1.5, class = UnitClass.ATInfantry, unit = "single_riflegrenade(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(ger)"},
			--Infantry Squads
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_blau_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_brandenburger_con(ger)"},
			},
			["rus"] = {--Russia
			--Infantry Singles
				{priority = 1.5, class = UnitClass.ATInfantry, unit = "single_at(rus)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(rus)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "single_sniper(rus)"},
				
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_penal_con(rus)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_rifle_motorised_con"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_mountainrifles_con(rus)"},
			}
		}
	},
	{--purchase 7 tank assault group
		waveNumber = 7,
		minRepeat = 4,
		maxRepeat = 6,
	    skipPossible = false,
	    waveDuration = 20,
		Units = {
			["ger"] = {--Germany
				{priority = 0.9, class = UnitClass.Tank, unit = "panzer742r"},
				{priority = 0.9, class = UnitClass.Tank,  unit = "h39_ger"},
			--Tanks_medium
				{priority = 1.05, class = UnitClass.Tank, unit = "panzer3f"},
				{priority = 1.05, class = UnitClass.Tank, unit = "panzer3j"},
				{priority = 1.05, class = UnitClass.Tank, unit = "panzer3j1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4d"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4f1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4f2"},
				{priority = 0.8, class = UnitClass.Tank, unit = "d2_ger"},
				{priority = 0.6, class = UnitClass.Tank, unit = "char_b1"},
				{priority = 0.6, class = UnitClass.Tank, unit = "char_b1_flamer"},
				{priority = 0.9, class = UnitClass.Tank, unit = "t3476_43_ger"},

			--Tanks_heavy
				{priority = 0.6, class = UnitClass.HeavyTank, unit = "pz756r"},
			},
			["rus"] = {--Russia
			--Tanks_medium
				{priority = 1.5, class = UnitClass.Tank,  unit = "valentine2"},
				{priority = 1.5, class = UnitClass.Tank,  unit = "valentine7"},
				{priority = 1.5, class = UnitClass.Tank,  unit = "valentine9"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "matilda2"},
				{priority = 1.5, class = UnitClass.Tank,  unit = "m4a2"},

			--Tanks_heavy
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "kv1e_40"},
				{priority = 0.5, class = UnitClass.HeavyTank,  unit = "kv1e_41"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "kv1s"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "churchill3"}, 
				{priority = 0.6, class = UnitClass.HeavyTank,unit = "kv-122"},
			}
		}
	},
	{--purchase 8 Artillery
		waveNumber = 8,
		minRepeat = 1,
		maxRepeat = 2,
        skipPossible = true,
	    skipChance = 0.6,
	    isHeavyArty = true,		
		waveDuration = 15,
		Units = {
			["ger"] = {--Germany
			--Artillery
				{priority = 1.1, class = UnitClass.ArtilleryTank, unit = "105mm_lefh18ai"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "150mm_sfh18ai"},
				{priority = 0.8, class = UnitClass.ArtilleryTank,  unit = "b1sf"},
				{priority = 0.8, class = UnitClass.ArtilleryTank,  unit = "grille"},
				{priority = 0.7, class = UnitClass.ArtilleryTank,  unit = "geschuetzwagen_ivb"},	
			},
			["rus"] = {--Russia
			--Artillery
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "122mm_m30ai"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "152mm_ml20ai"},
			--Rocket_Artillery
				{priority = 1.8, class = UnitClass.ArtilleryTank, unit = "bm_8_24"},

			--SPG
				{priority = 1.0, class = UnitClass.ArtilleryTank,  unit = "su5"},
			}
		}
	},
	{--purchase 9 support
		waveNumber = 9,
		minRepeat = 4,
		maxRepeat = 6,
	    skipPossible = false,
	    waveDuration = 20,
		Units = {
			["ger"] = {--Germany
			-- Rocket_Artillery
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "150mm_nebelwerfer41ai"},
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "sdkfz4"},
			--Wheel_vehicles
				{priority = 2.0, class = UnitClass.AATank, unit = "blitz3_6_flak30"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_3"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_4"},
			--Half_tracks
				{priority = 0.8, class = UnitClass.ATTank, unit = "sdkfz10_pak38"},
				{priority = 0.5, class = UnitClass.ATTank, unit = "sdkfz8_flak18"},
				{priority = 0.8, class = UnitClass.ATTank, unit = "sdkfz7_2"},
				{priority = 0.7, class = UnitClass.ATTank, unit = "sdkfz301wanze"},

			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank,  unit = "grille_m"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer742r"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "h39_ger"},
							
			},
			["rus"] = {--Russia
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "gaz_aaa_72k"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ba10"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ba11"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m17"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "yag10_29k"},

			--Tanks_light
				{priority = 3.0, class = UnitClass.Tank, unit = "bt7a"},
				{priority = 0.5, class = UnitClass.Tank, unit = "t80"},
				{priority = 0.7, class = UnitClass.Tank, unit = "m3stuart"},
			}
		}
	},
	{--purchase 10 emplacements
		waveNumber = 10,
	    minRepeat = 1,
		maxRepeat = 2,
	    skipPossible = true,
	    skipChance = 0.4,
	    waveDuration = 8,
		Units = {
			["ger"] = {--Germany
			--HMGs
				{priority = 1.5, class = UnitClass.Vehicle, unit = "mg34_lafette"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "mg42_lafette"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "mg131_lafette"},
			--Anti_Aircraft
				{priority = 1.0, class = UnitClass.AATank, unit = "20mm_flak30"},
				{priority = 0.5, class = UnitClass.AATank, unit = "37mm_flak37"},
			--Anti_Tank
				{priority = 1.5, class = UnitClass.ATTank, unit = "50mm_pak38"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_pak40"},
			--Infantry_Support
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "75mm_leig18"},
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "150mm_sig33ai"},			
			},
			["rus"] = {--Russia,
			--HMGs
				{priority = 1.5, class = UnitClass.Vehicle, unit = "maxim"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "sg43_stand"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dshk_stan"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dshk_aa"},
			--Anti_Aircraft
				{priority = 0.5, class = UnitClass.AATank, unit = "25mm_72k"},
				{priority = 1.5, class = UnitClass.AATank, unit = "37mm_61k"},
			--Anti_Tank
				{priority = 1.5, class = UnitClass.ATTank, unit = "45mm_m37"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "45mm_m42"},
				{priority = 0.1, class = UnitClass.ATTank, unit = "57mm_zis2"},
			--Mortars
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "82mm_bm37"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "120mm_pm38"},
			--Infantry_Support
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "76mm_m43"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "76mm_zis3"},
			--Artillery
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "122mm_a19ai"},
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
