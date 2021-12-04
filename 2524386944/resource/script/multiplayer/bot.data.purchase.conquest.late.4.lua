Purchases["campaign_capture_the_flag"] = {
	{--purchase 1 starting recon wave
		divisionName = "Elite division",
		waveNumber = 1,
		-- Repeat = 6,
		minRepeat = 5,
		maxRepeat = 7,
		skipPossible = false,
		waveDuration = 20,
		Units = {
			["ger"] = {--Germany
				--Infantry Squads
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_brandenburger_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_pionier_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_fallschirmjaeger_con(ger)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular_vet_con(ger)"},
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_con(ger)"},
			},
			["rus"] = {--Russia
			--Infantry Singles
		        {priority = 1.5, class = UnitClass.Infantry, unit = "squad_assaultsappers_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_assaultsappers_flame_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_guards_smg_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_marines_con(rus)"},
			}
		}
	},
	{--purchase 2 tank assault group
		waveNumber = 2,
	    -- Repeat = 6,
		minRepeat = 2,
		maxRepeat = 4,
	    skipPossible = false,
	    waveDuration = 10,
		Units = {
			["ger"] = {--Germany
			--Tanks_medium
				{priority = 0.1, class = UnitClass.HeavyTank, unit = "tiger1hunt"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "tiger2h"},
				{priority = 2.5, class = UnitClass.HeavyTank, unit = "panzer5a"},
				{priority = 2.5, class = UnitClass.HeavyTank, unit = "panzer5g"},
				{priority = 3.0, class = UnitClass.Tank, unit = "panzer4j"},
			},
			["rus"] = {--Russia
            --Tanks_medium
	            {priority = 1.5, class = UnitClass.HeavyTank, unit = "is2_43"},
				{priority = 2.0, class = UnitClass.HeavyTank, unit = "is2_44"},
				{priority = 2.5, class = UnitClass.Tank, unit = "t3485_44"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t3476_43_flame"},
			}
		}
	},
	{--purchase 3 infantry support
		waveNumber = 3,
		-- Repeat = 10,
		minRepeat = 4,
		maxRepeat = 6,
        skipPossible = false,		
		waveDuration = 20,
		Units = {
			["ger"] = {--Germany
				--Infantry Squads
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_brandenburger_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_pionier_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_fallschirmjaeger_con(ger)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular_vet_con(ger)"},
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_con(ger)"},
			},
			["rus"] = {--Russia
			--Infantry Singles
		        {priority = 1.5, class = UnitClass.Infantry, unit = "squad_assaultsappers_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_assaultsappers_flame_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_guards_smg_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_marines_con(rus)"},
			}
		}
	},
	{--purchase 4 SPG support
		waveNumber = 4,
		-- Repeat = 5,
		minRepeat = 1,
		maxRepeat = 3,
        skipPossible = false,		
		waveDuration = 40,
		Units = {
			["ger"] = {--Germany
			--SPG
			    {priority = 0.1, class = UnitClass.ATTank, unit = "ferdinand"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "jagdpanther"},
				{priority = 0.1, class = UnitClass.ArtilleryTank, unit = "sturmtiger"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sturmpanzer4"},
			},
			["rus"] = {--Russia
			--SPG
                {priority = 2.0, class = UnitClass.ATTank, unit = "isu122s"},
				{priority = 2.0, class = UnitClass.ATTank, unit = "isu152"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "su152"},
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "su122"},
			}
		}
	},
	{--purchase 5 Tank 2
		waveNumber = 5,
		-- Repeat = 2,
		minRepeat = 1,
		maxRepeat = 3,
        skipPossible = false,		
		waveDuration = 3,
		Units = {
			["ger"] = {--Germany
			--Tanks_medium
				{priority = 0.1, class = UnitClass.HeavyTank, unit = "tiger1hunt"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "tiger2h"},
				{priority = 2.5, class = UnitClass.HeavyTank, unit = "panzer5a"},
				{priority = 2.5, class = UnitClass.HeavyTank, unit = "panzer5g"},
				{priority = 3.0, class = UnitClass.Tank, unit = "panzer4j"},
			},
			["rus"] = {--Russia
            --Tanks_medium
	            {priority = 1.5, class = UnitClass.HeavyTank, unit = "is2_43"},
				{priority = 2.0, class = UnitClass.HeavyTank, unit = "is2_44"},
				{priority = 2.5, class = UnitClass.Tank, unit = "t3485_44"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t3476_43_flame"},
			}
		}
	},
	{--purchase 6 infantry attack 2
		waveNumber = 6,
		-- Repeat = 10,
		minRepeat = 4,
		maxRepeat = 6,
        skipPossible = false,		
		waveDuration = 35,
		Units = {
			["ger"] = {--Germany
				--Infantry Squads
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_brandenburger_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_pionier_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_fallschirmjaeger_con(ger)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular_vet_con(ger)"},
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_con(ger)"},
			},
			["rus"] = {--Russia
			--Infantry Singles
		        {priority = 1.5, class = UnitClass.Infantry, unit = "squad_assaultsappers_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_assaultsappers_flame_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_guards_smg_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_marines_con(rus)"},
			}
		}
	},
	{--purchase 7 arty
		waveNumber = 7,
		-- Repeat = 2,
		minRepeat = 1,
		maxRepeat = 3,
        skipPossible = false,		
		waveDuration = 3,
		Units = {
			["ger"] = {--Germany
		        {priority = 1.0, class = UnitClass.ArtilleryTank, unit = "300mm_nebelwerfer42"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "210mm_morser18"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "150mm_sfh18"},
			},
			["rus"] = {--Russia
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bm31_12"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "152mm_ml20"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "203mm_b4"},
			}
		}
	},
	{--purchase 8 light tank rush
		waveNumber = 8,
		-- Repeat = 6,
		minRepeat = 4,
		maxRepeat = 6,
        skipPossible = false,		
		waveDuration = 10,
		Units = {
			["ger"] = {--Germany
			--Wheel_vehicles
				{priority = 2.5, class = UnitClass.Vehicle, unit = "sdkfz234_2"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "blitz3_6_flak30"},
					{priority = 1.0, class = UnitClass.Tank, unit = "panzer2l"},
					{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz221"},
			},
			["rus"] = {--Russia
			--Wheel_vehicles
					{priority = 3.0, class = UnitClass.Tank, unit = "t60"},
				{priority = 3.0, class = UnitClass.Tank, unit = "t70"},
				{priority = 3.0, class = UnitClass.Tank, unit = "t70m"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "gaz_aaa_72k"},
				{priority = 1.5, class = UnitClass.Tank, unit = "valentine7"},
				{priority = 1.0, class = UnitClass.Tank, unit = "valentine9"},
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
