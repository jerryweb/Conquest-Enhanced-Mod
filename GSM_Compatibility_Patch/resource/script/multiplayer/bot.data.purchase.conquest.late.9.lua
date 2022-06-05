Purchases["campaign_capture_the_flag"] = {
	{--purchase 1 starting recon wave
		divisionName = "GSM Infantry Assault Divison",
		waveNumber = 1,
		minRepeat = 6,
		maxRepeat = 8,
		skipPossible = false,
		waveDuration = 20,
		Units = {
			["ger"] = {--Germany
				Infantry Squads
					{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular_vet_con(ger)"},
					{priority = 1.5, class = UnitClass.Infantry, unit = "squad_gd_motor_con"},

					{priority = 1.5, class = UnitClass.Infantry, unit = "squad_jaeger_con(ger)"},
					{priority = 1.5, class = UnitClass.Infantry, unit = "squad_gebirgsjaeger_con(ger)"},
					
				--Wheel_vehicles
					{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_3"},
					{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_4"},		
			},
			["rus"] = {--Russia
					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_rifle_motorised_con"},

					{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_guards_smg_con(rus)"},
					{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_motorised_con"},
					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_con(rus)"},
					{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_flame_con(rus)"},

					{priority = 1.5, class = UnitClass.Infantry, unit = "squad_marines_con(rus)"},
				--Wheel_vehicles
					{priority = 1.5, class = UnitClass.Vehicle, unit = "gaz67b"},
					{priority = 0.5, class = UnitClass.Vehicle, unit = "ba64"},
					{priority = 1.0, class = UnitClass.Vehicle, unit = "ba11"},
			}
		}
	},
    {--purchase officer
		waveNumber = 2,
		minRepeat = 1,
		maxRepeat = 1,
        skipPossible = true,
	    skipChance = 0.55,		
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
				{priority = 0.2, class = UnitClass.Infantry, unit = "squad_officer_gaz_con"},
			},
		}
	},
	{--purchase 3  mortar
		waveNumber = 3,
		minRepeat = 1,
		maxRepeat = 2,
	    skipPossible = true,
	    skipChance = 0.4,
	    waveDuration = 5,
	    isHeavyArty = true,
		Units = {
			["ger"] = {--Germany
				--Mortars
					{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "120mm_sgrw42"},			
			},
			["rus"] = {--Russia
				--Mortars
					{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "120mm_pm38"},
			}
		}
	},
	{--purchase 4 tank assault group
		waveNumber = 4,
		minRepeat = 2 ,
		maxRepeat = 4,
	    skipPossible = false,
	    waveDuration = 20,
		Units = {
			["ger"] = {--Germany
				--Tanks_medium
					{priority = 1.5, class = UnitClass.Tank, unit = "panzer3l"},
					{priority = 1.5, class = UnitClass.Tank, unit = "panzer3m"},
					{priority = 1.0, class = UnitClass.Tank, unit = "panzer3n"},
					{priority = 1.0, class = UnitClass.Tank, unit = "panzer4j"},
					{priority = 0.6, class = UnitClass.Tank, unit = "t3476_43_ger"},
					{priority = 0.5, class = UnitClass.Tank, unit = "m4a4_firefly_ger"},

				--Tanks_heavy
					{priority = 0.3, class = UnitClass.HeavyTank, unit = "panzer5a"},
			},
			["rus"] = {--Russia
				--Tanks_light
					{priority = 0.8, class = UnitClass.Tank, unit = "t80"},
					{priority = 0.7, class = UnitClass.Tank, unit = "t50"},
				--Tanks_medium
					{priority = 1.0, class = UnitClass.Tank,  unit = "t3476_43"},
					{priority = 1.0, class = UnitClass.Tank,  unit = "t3457_43"},
					{priority = 1.0, class = UnitClass.Tank,  unit = "valentine9"},
					{priority = 1.0, class = UnitClass.Tank,  unit = "m4a2"},
					{priority = 0.5, class = UnitClass.Tank,  unit = "m4a2_76w"},
					{priority = 0.6, class = UnitClass.Tank,  unit = "t3485_44"},
				--Tanks_heavy
					{priority = 0.5, class = UnitClass.HeavyTank, unit = "churchill3"},
			}
		}
	},
	{--purchase 5 Emplancement wave
		waveNumber = 5,
		minRepeat = 1,
		maxRepeat = 2,
	    skipPossible = true,
	    waveDuration = 10,
	    isHeavyArty = true,
		Units = {
			["ger"] = {--Germany
			--HMGs
				{priority = 1.5, class = UnitClass.Vehicle, unit = "mg42_lafette"},
			--Anti_Aircraft
				{priority = 1.0, class = UnitClass.AATank, unit = "20mm_flak30"},
				{priority = 0.5, class = UnitClass.AATank, unit = "37mm_flak37"},
				{priority = 0.5, class = UnitClass.AATank, unit = "88mm_flak36"},
			--Anti_Tank
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_pak40"},
			--Infantry_Support
				{priority = 1.1, class = UnitClass.ArtilleryTank, unit = "75mm_leig18"},
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "150mm_sig33ai"},
			},
			["rus"] = {--Russia
           --HMGs
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dshk_aa"},
			--Anti_Aircraft
				{priority = 0.8, class = UnitClass.AATank, unit = "37mm_61k"},
				{priority = 0.8, class = UnitClass.AATank, unit = "85mm_52k"},
			--Anti_Tank
				{priority = 1.0, class = UnitClass.ATTank, unit = "57mm_zis2"},
				{priority = 0.4, class = UnitClass.ATTank, unit = "100mm_bs3"},
			--Infantry_Support
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "76mm_m43"},
			},
		}
	},
	{--purchase 6 infantry support
		waveNumber = 6,
		minRepeat = 6,
		maxRepeat = 8,
        skipPossible = false,		
		waveDuration = 20,
		Units = {
			["ger"] = {--Germany
			--Infantry Squads
			    {priority = 1.5, class = UnitClass.Infantry, unit = "squad_jaeger_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_gebirgsjaeger_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_fallschirmjaeger_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_blau_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_brandenburger_con(ger)"},
			},
			["rus"] = {--Russia
			--Infantry Squads
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_mountainrifles_con(rus)"},

				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_guards_smg_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_flame_con(rus)"},

				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_paras_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_spetsnaz(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_marines_con(rus)"},
			},
		}
	},
	{--purchase 7 SPG support
		waveNumber = 7,
		minRepeat = 1,
		maxRepeat = 4,
        skipPossible = false,		
		waveDuration = 20,
		Units = {
			["ger"] = {--Germany
				--SPG
					{priority = 1.0, class = UnitClass.ATTank,  unit = "hetzer"},
					{priority = 1.0, class = UnitClass.ATTank,  unit = "marder3h"},
					{priority = 1.0, class = UnitClass.ATTank,  unit = "marder3m"},
					{priority = 0.3, class = UnitClass.ATTank, unit = "sturer_emil"}, 
					{priority = 0.8, class = UnitClass.ATTank,  unit = "jagdpanzer_iv"},
					{priority = 0.5, class = UnitClass.ATTank,  unit = "jagdtiger"},
					{priority = 0.6, class = UnitClass.ArtilleryTank,  unit = "sturmpanzer4"},
			},
			["rus"] = {--Russia
				--SPG
					{priority = 1.0, class = UnitClass.ATTank, unit = "wolverine"},
					{priority = 1.0, class = UnitClass.ATTank,  unit = "su85m"},
					{priority = 1.0, class = UnitClass.ATTank,  unit = "su100"},
					{priority = 1.0, class = UnitClass.ATTank, unit = "su122"},
					{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "su152"},
					{priority = 1.0, class = UnitClass.ArtilleryTank,  unit = "isu152"},
					{priority = 1.0, class = UnitClass.ATTank,  unit = "isu122s"},
			}
		}
	},
	{--purchase 8 Tank 2
		waveNumber = 8,
		minRepeat = 2,
		maxRepeat = 4,
        skipPossible = false,		
		waveDuration = 15,
		Units = {
			["ger"] = {--Germany
				--Tanks_medium
					{priority = 1.5, class = UnitClass.Tank, unit = "panzer3l"},
					{priority = 1.5, class = UnitClass.Tank, unit = "panzer3m"},
					{priority = 1.0, class = UnitClass.Tank, unit = "panzer3n"},
					{priority = 1.0, class = UnitClass.Tank, unit = "panzer4j"},
					{priority = 0.6, class = UnitClass.Tank, unit = "t3476_43_ger"},
					{priority = 0.5, class = UnitClass.Tank, unit = "m4a4_firefly_ger"},

				--Tanks_heavy
					{priority = 0.3, class = UnitClass.HeavyTank, unit = "panzer5a"},
			},
			["rus"] = {--Russia
				--Tanks_light
					{priority = 0.8, class = UnitClass.Tank, unit = "t80"},
					{priority = 0.7, class = UnitClass.Tank, unit = "t50"},
				--Tanks_medium
					{priority = 1.0, class = UnitClass.Tank,  unit = "t3476_43"},
					{priority = 1.0, class = UnitClass.Tank,  unit = "t3457_43"},
					{priority = 1.0, class = UnitClass.Tank,  unit = "valentine9"},
					{priority = 1.0, class = UnitClass.Tank,  unit = "m4a2"},
					{priority = 0.5, class = UnitClass.Tank,  unit = "m4a2_76w"},
					{priority = 0.6, class = UnitClass.Tank,  unit = "t3485_44"},
				--Tanks_heavy
					{priority = 0.5, class = UnitClass.HeavyTank, unit = "churchill3"},
			}
		}
	},
	{--purchase 9 arty
		waveNumber = 9,
		minRepeat = 1,
		maxRepeat = 2,
        skipPossible = true,
	    skipChance = 0.4,		
		waveDuration = 5,
		Units = {
			["ger"] = {--Germany
				--Artillery
					{priority = 0.4, class = UnitClass.ArtilleryTank, unit = "105mm_lefh18ai"},
					{priority = 0.4, class = UnitClass.ArtilleryTank, unit = "150mm_sfh18ai"},
					{priority = 0.5, class = UnitClass.ArtilleryTank,  unit = "hummel"},
				-- Rocket_Artillery
					{priority = 0.4, class = UnitClass.ArtilleryTank, unit = "150mm_nebelwerfer41ai"},
					{priority = 0.4, class = UnitClass.ArtilleryTank, unit = "300mm_nebelwerfer42ai"},
					{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "zgkw303f"},
					{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "sdkfz251_1_stuka"},			
			},
			["rus"] = {--Russia
				--Artillery
					{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "122mm_m30ai"},
					{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "122mm_a19ai"},
					{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "152mm_ml20ai"},
					{priority = 0.3, class = UnitClass.ArtilleryTank, unit = "su14"},
				--Rocket_Artillery
					{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bm31_12ai"},
					{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bm_8_24"},
			}
		}
	},
	{--purchase 10 light tank rush
		waveNumber = 10,
		minRepeat = 2,
		maxRepeat = 4,
        skipPossible = false,		
		waveDuration = 10,
		Units = {
			["ger"] = {--Germany
				--Wheel_vehicles
					{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz231"},
					{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_1"},
					{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_2"},
					{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_3"},
					{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_4"},

				--Tanks_light
					{priority = 1.0, class = UnitClass.Tank,  unit = "panzer2l"},
					{priority = 0.3, class = UnitClass.Tank,  unit = "panzer2j"},

				--Tanks_medium
					{priority = 0.8, class = UnitClass.Tank, unit = "wirbelwind"},
					{priority = 0.8, class = UnitClass.Tank, unit = "ostwind"},
			},
			["rus"] = {--Russia
				--Wheel_vehicles
					{priority = 1.0, class = UnitClass.Vehicle, unit = "m17"},
					{priority = 1.0, class = UnitClass.Vehicle, unit = "yag10_29k"},

				--Tanks_light
					{priority = 3.0, class = UnitClass.Tank, unit = "t60"},
					{priority = 3.0, class = UnitClass.Tank, unit = "t70"},
					{priority = 0.5, class = UnitClass.Tank, unit = "t80"},
					{priority = 0.7, class = UnitClass.Tank, unit = "m3stuart"},
			}
		}
	},
	{--purchase 11 infantry attack 2
		waveNumber = 11,
		minRepeat = 6,
		maxRepeat = 8,
        skipPossible = false,		
		waveDuration = 35,
		Units = {
			["ger"] = {--Germany
			--Infantry Squads
			    {priority = 1.5, class = UnitClass.Infantry, unit = "squad_jaeger_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_gebirgsjaeger_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_fallschirmjaeger_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_blau_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_brandenburger_con(ger)"},
			},
			["rus"] = {--Russia
			--Infantry Squads
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_mountainrifles_con(rus)"},

				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_guards_smg_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_flame_con(rus)"},

				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_paras_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_spetsnaz(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_marines_con(rus)"},
			},
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
