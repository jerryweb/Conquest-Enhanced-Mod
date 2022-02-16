Purchases["campaign_capture_the_flag"] = {
	{--purchase 4 tank assault group
		divisionName = "Tank and infantry",
		waveNumber = 4,
	    -- Repeat = 6,
	    minRepeat = 4,
		maxRepeat = 6,
	    skipPossible = false,
	    waveDuration = 20,
		Units = {
			["ger"] = {--Germany
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "panzer5d"},
				{priority = 2.0, class = UnitClass.HeavyTank, unit = "panzer5a"},
				{priority = 2.0, class = UnitClass.HeavyTank, unit = "panzer5g"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "tiger1h"},
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "tiger1e"},
				{priority = 0.1, class = UnitClass.HeavyTank, unit = "tiger1hunt"},
			--Tanks_medium
				{priority = 3.5, class = UnitClass.Tank, unit = "panzer3j"},
				{priority = 2.5, class = UnitClass.Tank, unit = "panzer3j1"},
				{priority = 2.5, class = UnitClass.Tank, unit = "panzer3l"},
				{priority = 2.5, class = UnitClass.Tank, unit = "panzer3m"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4d"},
				{priority = 1.5, class = UnitClass.Tank, unit = "panzer4f1"},
				{priority = 3.0, class = UnitClass.Tank, unit = "panzer4f2"},
				{priority = 3.0, class = UnitClass.Tank, unit = "panzer4g"},
			--Tanks_light
				{priority = 0.5, class = UnitClass.Tank, unit = "panzer2c"},
				{priority = 0.6, class = UnitClass.Tank, unit = "panzer2f"},
				{priority = 0.7, class = UnitClass.Tank, unit = "panzer35t"},
				{priority = 1.2, class = UnitClass.Tank, unit = "pz38t_a"},
				{priority = 1.2, class = UnitClass.Tank, unit = "pz38t_f"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz38t_g"},
			},
			["rus"] = {--Russia
			--Tanks_heavy
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "kv1_40"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "kv2_40"},
				{priority = 2.0, class = UnitClass.HeavyTank, unit = "kv1_41"},
	        --Tanks_medium
				{priority = 2.0, class = UnitClass.Tank, unit = "t3476_40"},
				{priority = 2.5, class = UnitClass.Tank, unit = "t3476_41"},
				{priority = 0.1, class = UnitClass.Tank, unit = "t3457_41"},
				{priority = 3.5, class = UnitClass.Tank, unit = "t3476_42"},
				{priority = 3.5, class = UnitClass.Tank, unit = "t3476_43"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "t30"},
				{priority = 0.5, class = UnitClass.Tank, unit = "t40"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t60"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t70"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t70m"},
				{priority = 1.5, class = UnitClass.Tank, unit = "bt5"},
				{priority = 1.0, class = UnitClass.Tank, unit = "bt7"},
			},
			["fra"] = {--France
			--Infantry
				-- 1
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "h39"},				
				{priority = 1.0, class = UnitClass.Tank, unit = "char_d2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75_fr"},
			--Tanks_heavy	
				{priority = 1.0, class = UnitClass.Tank, unit = "b1bis"},				
			},
			["pol"] = {--Poland
			--Infantry
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "7tp"},
				{priority = 1.0, class = UnitClass.Tank, unit = "r35_pol"},
				--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_pol"},
				--Tanks_heavy			
			},
			["jap"] = {--Japan
			--Infantry
				-- 1
			--Tanks_medium
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_chi-ha"},
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_shinhoto_47mm"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type1_chi-he"},
				{priority = 2.5, class = UnitClass.Tank, unit = "type97_shinhoto_120mm"},
				{priority = 1.0, class = UnitClass.Tank, unit = "type2_ho-i"},
				{priority = 1.0, class = UnitClass.Tank, unit = "type2_ho-i_kou"},								
			},
			["usa"] = {--USA
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m24_chaffee"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m3lee"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4"},	
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e8"},
			},
			["eng"] = {--Britain
			--Infantry
				-- 1
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa1"},
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2"},
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_mki"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "valentine_mkiii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "matilda_mkii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_vi"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4"},
		--Tanks_heavy
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_ii"},
			},
			["ita"] = {--Italy
			--Tanks_light
				{priority = 1.0, class = UnitClass.Vehicle, unit = "cv35"},
				{priority = 1.0, class = UnitClass.Tank, unit = "l640"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1441"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1542"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3n_ita"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4g_ita"},
			--Tanks_heavy			
			}
		}
	},
	{--purchase 5 infantry support
		waveNumber = 5,
		-- Repeat = 8,
		minRepeat = 6,
		maxRepeat = 9,
        skipPossible = false,		
		waveDuration = 25,
		Units = {
			["ger"] = {--Germany
			--Infantry Squads
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_con(ger)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular_vet_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_blau_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_pionier_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_pz_pio_con"},
			},
			["rus"] = {--Russia
			--Infantry Squads
				{priority = 2.5, class = UnitClass.Infantry, unit = "squad_rifleunit_alt_con(rus)"},
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_rifleunit_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_guards_smg_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_flame_con(rus)"},
			},
			["fra"] = {--France
			--Infantry
				-- 1
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mg_late(fra)"},				
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(fra)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(fra)"},
			-- 5
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_marine_late(fra)"},				
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(fra)"},
				-- 6
			},
			["pol"] = {--Poland
			--Infantry
				-- 1
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(pol)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(pol)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_mg_late(pol)"},				
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(pol)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(pol)"},
				-- 3
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(pol)"},
			-- 4
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_scout_late(pol)"},				
			-- 6
			},
			["jap"] = {--Japan
			--Infantry
				-- 1
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(jap)"},
				-- 3
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(jap)"},
			-- 4
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(jap)"},
			},
			["usa"] = {--USA
			--Infantry
				-- 1
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(usa)"},
				-- 3
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(usa)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_marine(usa)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(usa)"},
			},
			["eng"] = {--Britain
			--Infantry
				-- 1
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(eng)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_mg_late(eng)"},				
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(eng)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(eng)"},
				-- 3
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(eng)"},
				-- 4
				-- 5
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(eng)"},				-- 6
			},
			["ita"] = {--Italy
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_light(ita)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular(ita)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(ita)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(ita)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_mg(ita)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(ita)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_flamer(ita)"},
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
