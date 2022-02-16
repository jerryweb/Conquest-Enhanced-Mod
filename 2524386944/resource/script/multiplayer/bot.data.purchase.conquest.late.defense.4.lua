Purchases["campaign_capture_the_flag"] = {
	{--purchase 1 starting recon wave
		divisionName = "Elite division (Shock Troops)",
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
			},
			["fra"] = {--France
			--Infantry
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(fra)"},
				-- 5
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_marine_late(fra)"},				
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(fra)"},
			},
			["pol"] = {--Poland
			--Infantry
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(pol)"},
				-- 5
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_scout_late(pol)"},				
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(pol)"},
			},
			["jap"] = {--Japan
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(jap)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(jap)"},
			},
			["usa"] = {--USA
			--Infantry
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(usa)"},
				-- 5
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_marine(usa)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(usa)"},		
			},
			["eng"] = {--Britain
			--Infantry
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(eng)"},
				-- 5
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_scout_late(eng)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(eng)"},	
			},
			["ita"] = {--Italy
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(ita)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_mg(ita)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(ita)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_flamer(ita)"},
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
			},
			["fra"] = {--France
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8_fr"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_76_fr"},
			},
			["pol"] = {--Poland
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_pol"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly_pol"},
			},
			["jap"] = {--Japan		
			--Tanks_medium
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_shinhoto_47mm"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type1_chi-he"},
				{priority = 0.5, class = UnitClass.Tank, unit = "type3_chi-nu2"},
			},
			["usa"] = {--USA,
			--Tanks_medium
				{priority = 0.8, class = UnitClass.Tank, unit = "m4a3_75"},
				{priority = 1.5, class = UnitClass.Tank, unit = "m4a3_zippo"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e2_jumbo"},
			},
			["eng"] = {--Britain
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly"},
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_iv"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_vii"},
			},
			["ita"] = {--Italy
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ab41"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3n_ita"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4g_ita"},
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
