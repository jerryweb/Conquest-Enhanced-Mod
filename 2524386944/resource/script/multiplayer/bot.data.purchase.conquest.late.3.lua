Purchases["campaign_capture_the_flag"] = {
	{--purchase 1 starting recon wave
		divisionName = "Infantry and support weapon",
		waveNumber = 1,
		-- Repeat = 6,
		minRepeat = 6,
		maxRepeat = 8,
		skipPossible = false,
		waveDuration = 20,
		Units = {
			["ger"] = {--Germany
				--Infantry Squads
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_recon_con(ger)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_recon_armor_con"},
			--Wheel_vehicles
				{priority = 5.1, class = UnitClass.Vehicle, unit = "p204_f"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz231"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz221"},
			},
			["rus"] = {--Russia
			--Infantry Singles
			    {priority = 2.5, class = UnitClass.Infantry, unit = "squad_recon_con(rus)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_spetsnaz(rus)"},
			--Wheel_vehicles
				{priority = 1.8, class = UnitClass.Vehicle, unit = "m3a1e1_scout_mgun"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "ba64"},
			}
		}
	},
	{--purchase 2 mortar
		waveNumber = 2,
	    -- Repeat = 2,
		minRepeat = 2,
		maxRepeat = 3,
	    skipPossible = false,
	    waveDuration = 5,
	    isHeavyArty = true,
		Units = {
			["ger"] = {--Germany
				--Howitzers
			    {priority = 2.0, class = UnitClass.ArtilleryTank, unit = "120mm_sgrw42"},
			},
			["rus"] = {--Russia
			--Howitzers
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "120mm_pm38"},
			}
		}
	},
	{--purchase 3 tank assault group
		waveNumber = 3,
	    -- Repeat = 6,
		minRepeat = 2,
		maxRepeat = 4,
	    skipPossible = false,
	    waveDuration = 10,
		Units = {
			["ger"] = {--Germany
			--Tanks_medium
				{priority = 2.5, class = UnitClass.Tank, unit = "panzer3m"},
				{priority = 1.5, class = UnitClass.Tank, unit = "panzer3n"},
				{priority = 3.0, class = UnitClass.Tank, unit = "panzer4g"},
				{priority = 3.5, class = UnitClass.Tank, unit = "panzer4h"},
				{priority = 3.0, class = UnitClass.Tank, unit = "panzer4j"},
			--Tanks_light
				{priority = 0.6, class = UnitClass.Tank, unit = "panzer2f"},
			--SPG
			},
			["rus"] = {--Russia
            --Tanks_medium
				{priority = 3.5, class = UnitClass.Tank, unit = "t3476_42"},
				{priority = 3.5, class = UnitClass.Tank, unit = "t3476_43"},
				{priority = 0.1, class = UnitClass.Tank, unit = "t3457_43"},
				{priority = 3.5, class = UnitClass.Tank, unit = "t3476_43"},
				{priority = 0.5, class = UnitClass.Tank, unit = "t3485_44"},
			--Tanks_light
				{priority = 3.0, class = UnitClass.Tank, unit = "t60"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t70m"},
			}
		}
	},
	{--purchase Emplancement wave
		waveNumber = 4,
	    -- Repeat = 6,
		minRepeat = 2,
		maxRepeat = 4,
	    skipPossible = false,
	    waveDuration = 10,
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
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "150mm_sig33"},
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
			}
		}
	},
	{--purchase 5 infantry support
		waveNumber = 5,
		-- Repeat = 10,
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
			}
		}
	},
	{--purchase 6 SPG support
		waveNumber = 6,
		-- Repeat = 5,
		minRepeat = 1,
		maxRepeat = 2,
        skipPossible = false,		
		waveDuration = 40,
		Units = {
			["ger"] = {--Germany
			--SPG
		     		{priority = 2.5, class = UnitClass.ATTank, unit = "stug3g_late"},
					{priority = 1.5, class = UnitClass.ATTank, unit = "hetzer"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "marder2"},
				{priority = 0.5, class = UnitClass.ATTank, unit = "marder3m"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "stuh42"},
			},
			["rus"] = {--Russia
			--SPG
				{priority = 2.5, class = UnitClass.ATTank, unit = "su85"},
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "su122"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "isu152"},
			}
		}
	},
	{--purchase 7 Tank 2
		waveNumber = 7,
		-- Repeat = 5,
		minRepeat = 2,
		maxRepeat = 4,
        skipPossible = false,		
		waveDuration = 15,
		Units = {
			["ger"] = {--Germany
			--Tanks_medium
				{priority = 2.5, class = UnitClass.Tank, unit = "panzer3m"},
				{priority = 1.5, class = UnitClass.Tank, unit = "panzer4h"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4j"},
			--Tanks_light
				{priority = 0.6, class = UnitClass.Tank, unit = "panzer2f"},
			--SPG
			},
			["rus"] = {--Russia
            --Tanks_medium
				{priority = 3.5, class = UnitClass.Tank, unit = "t3476_42"},
				{priority = 3.5, class = UnitClass.Tank, unit = "t3476_43"},
			--Tanks_light
				{priority = 3.0, class = UnitClass.Tank, unit = "t70m"},
				{priority = 2.0, class = UnitClass.Tank, unit = "t60"},
				{priority = 1.0, class = UnitClass.Tank, unit = "bt7"},
			}
		}
	},
	{--purchase 8 infantry attack 2
		waveNumber = 8,
		-- Repeat = 10,
		minRepeat = 6,
		maxRepeat = 11,
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
			}
		}
	},
	{--purchase 9 rocket arty
		waveNumber = 9,
		-- Repeat = 2,
		minRepeat = 1,
		maxRepeat = 2,
        skipPossible = false,		
		waveDuration = 5,
		Units = {
			["ger"] = {--Germany
		        {priority = 11.0, class = UnitClass.ArtilleryTank, unit = "300mm_nebelwerfer42"},
			},
			["rus"] = {--Russia
				{priority = 11.0, class = UnitClass.ArtilleryTank, unit = "bm31_12"},
			}
		}
	},
	{--purchase 10 light tank rush
		waveNumber = 10,
		-- Repeat = 10,
		minRepeat = 2,
		maxRepeat = 4,
        skipPossible = false,		
		waveDuration = 10,
		Units = {
			["ger"] = {--Germany
			--Wheel_vehicles
				{priority = 2.5, class = UnitClass.Vehicle, unit = "sdkfz234_2"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "blitz3_6_flak30"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz231"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer2l"},
			},
			["rus"] = {--Russia
            --Tanks_light			
				{priority = 3.0, class = UnitClass.Tank, unit = "t70m"},
				{priority = 2.0, class = UnitClass.Tank, unit = "t60"},
				{priority = 1.0, class = UnitClass.Tank, unit = "bt7"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "gaz_aaa_72k"},
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
