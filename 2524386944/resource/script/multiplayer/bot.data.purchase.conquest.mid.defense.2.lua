Purchases["campaign_capture_the_flag"] = {
	{--purchase 1 starting recon wave
		divisionName = "Infantry and support weapons",
		waveNumber = 1,
		-- Repeat = 6,
		minRepeat = 3,
		maxRepeat = 6,
		skipPossible = false,
		waveDuration = 20,
		Units = {
			["ger"] = {--Germany
				--Infantry Squads
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_fallschirmjaeger_con(ger)"},
			},
			["rus"] = {--Russia
			--Infantry Singles
			
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_paras(rus)"},
				-- {priority = 1.5, class = UnitClass.Infantry, unit = "squad_border(rus)"},
			--Wheel_vehicles
			},
			["fra"] = {--France
			--Infantry
			-- 3
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
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
			-- 6
			},
			["jap"] = {--Japan
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(jap)"},
			},
			["usa"] = {--USA
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(usa)"},
			},
			["eng"] = {--Britain
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(eng)"},
			},
			["ita"] = {--Italy
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(ita)"},
			}
		}
	},
	{--purchase 2 mortar
		waveNumber = 2,
	    -- Repeat = 2,
	    minRepeat = 1,
		maxRepeat = 2,
	    skipPossible = false,
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
			["fra"] = {--France				
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81_mm_m1_fr"},											
			},
			["pol"] = {--Poland
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_pol"},
			},
			["jap"] = {--Japan
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_jap"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "120mm_type_38"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "200mm_type_4"}
			},
			["usa"] = {--USA
			--Howitzers				
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81_mm_m1"},
			},
			["eng"] = {--Britain
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "76mm_mk_ii"},
			},
			["ita"] = {--Italy
			--Howitzers				
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_ita"},
			}
		}
	},
	{--purchase 4 infantry support
		waveNumber = 4,
		-- Repeat = 10,
		minRepeat = 6,
		maxRepeat = 8,
        skipPossible = false,		
		waveDuration = 35,
		Units = {
			["ger"] = {--Germany
			--Infantry Squads
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_con(ger)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular_vet_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_pz_pio_con"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_regular_armor_con"},
			},
			["rus"] = {--Russia
			--Infantry Squads
			    {priority = 2.5, class = UnitClass.Infantry, unit = "squad_rifleunit_alt_con(rus)"},
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_rifleunit_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
			},
			["fra"] = {--France
			--Infantry
				-- 1
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mg_late(fra)"},				
				-- 2
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(fra)"},
				-- 5
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_marine_late(fra)"},				
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(fra)"},
				-- 6
			},
			["pol"] = {--Poland
			--Infantry
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(pol)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_mg_late(pol)"},				
				-- 2
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(pol)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(pol)"},
				-- 6
			},
			["jap"] = {--Japan
			--Infantry
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(jap)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(jap)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(jap)"},
			},
			["usa"] = {--USA
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(usa)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_marine(usa)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(usa)"},
			},
			["eng"] = {--Britain
			--Infantry
				-- 1
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(eng)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_mg_late(eng)"},				
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(eng)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(eng)"},				-- 6
			},
			["ita"] = {--Italy
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular(ita)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(ita)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_mg(ita)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_flamer(ita)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "mechanized_infantry_ita"},
			}
		}
	},
	{--purchase Emplancement wave 5
		waveNumber = 5,
	    -- Repeat = 6,
		minRepeat = 2,
		maxRepeat = 4,
	    skipPossible = false,
	    waveDuration = 10,
		Units = {
			["ger"] = {--Germany
			--HMGs
				{priority = 1.5, class = UnitClass.Vehicle, unit = "mg42_lafette"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "mg34_lafette"},
			--Anti_Aircraft
				{priority = 1.0, class = UnitClass.AATank, unit = "20mm_flak30"},
				{priority = 0.5, class = UnitClass.AATank, unit = "37mm_flak37"},
			--Anti_Tank
				{priority = 0.5, class = UnitClass.ATTank, unit = "47mm_pakt"},
				{priority = 1.5, class = UnitClass.ATTank, unit = "50mm_pak38"},
			--Infantry_Support
				{priority = 1.1, class = UnitClass.ArtilleryTank, unit = "75mm_leig18"},
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "150mm_sig33"},
			},
			["rus"] = {--Russia
           --HMGs
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dshk_aa"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "maxim"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "sg43_stand"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dshk_stan"},
			--Anti_Aircraft
				{priority = 0.5, class = UnitClass.AATank, unit = "37mm_61k"},
				{priority = 1.0, class = UnitClass.AATank, unit = "25mm_72k"},
			--Anti_Tank
				{priority = 1.0, class = UnitClass.ATTank, unit = "57mm_zis2"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "45mm_m42"},
			--Infantry_Support
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "76mm_m43"},
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "76mm_m1927"},
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "76mm_zis3"},
			},
			["fra"] = {--France
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1919a4_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb_fr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1_fr"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "57_mm_m1_fr"},
			},
			["pol"] = {--Poland
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "37mm_bofors"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf6pdr_pol"},
			},
			["jap"] = {--Japan
			--Infantry
				-- 1
				{priority = 1.0, class = UnitClass.ATTank, unit = "20mm_type_2"},	
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_88"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_90"},
			},
			["usa"] = {--USA
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1917a1_aa"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "76_mm_m5"},
			},
			["eng"] = {--Britain
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_vickers_mki"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_bren"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf40mm"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf6pdr"},
			},
			["ita"] = {--Italy
				{priority = 1.0, class = UnitClass.Vehicle, unit = "8mm_fiat_revelli_m1914_35"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "8mm_breda_37"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "2cm_solothurn"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "obice_7513"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "7_5cm_pak97_38"},
			}
		}
	},
		{--purchase 7 Tank 2
		waveNumber = 7,
		-- Repeat = 7,
		minRepeat = 1,
		maxRepeat = 2,
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
	{--purchase 9 rocket arty
		waveNumber = 9,
		-- Repeat = 1,
		minRepeat = 1,
		maxRepeat = 2,
        skipPossible = false,		
		waveDuration = 5,
		Units = {
			["ger"] = {--Germany
		        {priority = 11.0, class = UnitClass.ArtilleryTank, unit = "150mm_nebelwerfer41"},
			},
			["rus"] = {--Russia
				{priority = 11.0, class = UnitClass.ArtilleryTank, unit = "bm13_studebaker"},
			},
			["fra"] = {--France
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l_fr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m1918"},
			},
			["pol"] = {--Poland
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105mm_wz29"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155mm_wz1917"},								
			},
			["jap"] = {--Japan
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "200mm_type_4"},
				--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "toyota_rocket"},				
			},
			["usa"] = {--USA
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "107_mm_m2"},				
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m2"},
			},
			["eng"] = {--Britain
			--Infantry
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl72"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "land_mattress"},				
			},
			["ita"] = {--Italy
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "obice_10017"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "obice_210"},
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
