Purchases["campaign_capture_the_flag"] = {
	{--purchase 1 starting recon wave c 1 по 5 бой
		divisionName = "Condor Mid Tank Division",
		waveNumber = 1, -- какая по порядку будет
		-- Repeat = 6, -- сколько раз должно вызваться, чтобы могло перейти к следующей волне
		minRepeat = 3,
		maxRepeat = 6,
		skipPossible = false,  -- ничего не делает
		waveDuration = 20, -- длительность того, как долго бот будет вызывать данные войска. Каждый юнит вызывается каждые 3 секунды. Если нужно чтобы было только определенное количество то Repeat * 3 < Wave duration  При этом Repeat говорит сколько раз нужно вызвать юнит.
		Units = {
			["ger"] = {--Germany
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "kubelwagen_mg"},
				{priority = 0.1, class = UnitClass.Vehicle, unit = "p204_f"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "sdkfz231"},
				{priority = 2.0, class = UnitClass.Vehicle, unit = "sdkfz221"},
			--Infantry Squads
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_recon_con(ger)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_recon_motor_con"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_recon_armor_con"},				
			},
			["rus"] = {--Russia
			--Infantry Singles
			    {priority = 2.5, class = UnitClass.Infantry, unit = "squad_recon_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_sniper(rus)"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ba6"},
				{priority = 2.0, class = UnitClass.Vehicle, unit = "ba20"},
		    },
			["fra"] = {--France
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(fra)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade_late(fra)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(fra)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(fra)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(fra)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(fra)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1919a4_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb_fr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1_fr"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "57_mm_m1_fr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1897a4_fr"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81_mm_m1_fr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l_fr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m1918"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dodgewc55_fr"},	
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m4halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m17_fr"},	
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8_fr"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_76_fr"},
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine_fr"},
				{priority = 0.2, class = UnitClass.ArtilleryTank, unit = "m7_fr"}
			},
			["pol"] = {--Poland
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(pol)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(pol)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(pol)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(pol)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(pol)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(pol)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(pol)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(pol)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_bren_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf40mm_pol"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf2pdr_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf6pdr_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf17pdr_pol"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45_pol"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound_pol"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_pol"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly_pol"},
			--Tanks_heavy			
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "achilles_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton_pol"}
			},
			["jap"] = {--Japan
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(jap)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(jap)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(jap)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(jap)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(jap)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(jap)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type92_stan"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "20mm_type_2"},	
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "37mm_type_94"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_88"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_90"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_41"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "47mm_type_1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_4"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_jap"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105mm_type_92"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "120mm_type_38"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "200mm_type_4"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "150mm_type_96"},
			--Wheel_vehicles
				{priority = 2.5, class = UnitClass.Vehicle, unit = "type93"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type94aa"},
			--Half_tracks
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "type94_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type97_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type95_ha-go"},
			--Tanks_medium
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_chi-ha"},
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_shinhoto_47mm"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type1_chi-he"},
				{priority = 2.5, class = UnitClass.Tank, unit = "type97_shinhoto_120mm"},
				{priority = 0.5, class = UnitClass.Tank, unit = "type3_chi-nu"},
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "type1_ho-ni1"},
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "type1_ho-ni2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "type4_ho-ro"}
			--Tanks_heavy
			},
			["usa"] = {--USA
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(usa)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(usa)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(usa)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(usa)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(usa)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(usa)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(usa)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(usa)"},
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1917a1_aa"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_maxson"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "37_mm_m3"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1897a4"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "76_mm_m5late"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "90_mm_m1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "76_mm_m5"},
			--Howitzers				
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81_mm_m1"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "203_mm_m115"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willysmb"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willys50"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willysat"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dodgewc55"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m16"},											  
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t30hmc"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "cckw353_2xt27"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m22"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_stuart"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_satan"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m24_chaffee"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m18"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m3lee"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4"},	
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_zippo"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e2_jumbo"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3_105"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3c"},	
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "m4a3e2_jumbo_76w"},	
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "m26_pershing"},
			--SPG
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t12gmc"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m36"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7"}
			},
			["eng"] = {--Britain
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(eng)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(eng)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(eng)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(eng)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(eng)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(eng)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(eng)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(eng)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(eng)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(eng)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(eng)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_vickers_mki"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_bren"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf40mm"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf2pdr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf6pdr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf17pdr"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "76mm_mk_ii"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf3,7inch"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl72"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_eng"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "humber"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "mk2daimler"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_mk6"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "valentine_mkiii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "matilda_mkii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_a30"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_vi"},
				{priority = 1.0, class = UnitClass.Tank, unit = "comet_a34"},
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_ii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_iv"},
				{priority = 0.2, class = UnitClass.Tank, unit = "churchill_avre"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_vii"},			
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "achilles"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton"}
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
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "8mm_fiat_revelli_m1914_35"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "8mm_breda_37"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_2065"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "2cm_solothurn"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_4732"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_7527"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "obice_7513"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "7_5cm_pak97_38"},
			--Howitzers				
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_ita"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "obice_10017"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ab41"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "autocannone10017"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Vehicle, unit = "cv35"},
				{priority = 1.0, class = UnitClass.Tank, unit = "l640"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1441"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1542"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3n_ita"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4g_ita"},
			--Tanks_heavy			
			--SPG
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7518"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m7534"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_ita"}
			}
		}
	},
	{--purchase 2 mortar
		waveNumber = 2,
	    -- Repeat = 6,
	    minRepeat = 1,
		maxRepeat = 2,
	    skipPossible = false,
	    waveDuration = 8,
	    isHeavyArty = true,
		Units = {
			["ger"] = {--Germany
		    --Howitzers
                {priority = 1.0, class = UnitClass.ATTank, unit = "80mm_sgrw34"}
			},
			["rus"] = {--Russia
			--Howitzers
                {priority = 1.0, class = UnitClass.ATTank, unit = "82mm_bm37"},
			},
						["fra"] = {--France
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(fra)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade_late(fra)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(fra)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(fra)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(fra)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(fra)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1919a4_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb_fr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1_fr"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "57_mm_m1_fr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1897a4_fr"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81_mm_m1_fr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l_fr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m1918"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dodgewc55_fr"},	
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m4halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m17_fr"},	
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8_fr"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_76_fr"},
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine_fr"},
				{priority = 0.2, class = UnitClass.ArtilleryTank, unit = "m7_fr"}
			},
			["pol"] = {--Poland
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(pol)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(pol)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(pol)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(pol)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(pol)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(pol)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(pol)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(pol)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_bren_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf40mm_pol"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf2pdr_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf6pdr_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf17pdr_pol"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45_pol"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound_pol"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_pol"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly_pol"},
			--Tanks_heavy			
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "achilles_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton_pol"}
			},
			["jap"] = {--Japan
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(jap)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(jap)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(jap)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(jap)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(jap)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(jap)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type92_stan"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "20mm_type_2"},	
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "37mm_type_94"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_88"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_90"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_41"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "47mm_type_1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_4"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_jap"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105mm_type_92"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "120mm_type_38"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "200mm_type_4"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "150mm_type_96"},
			--Wheel_vehicles
				{priority = 2.5, class = UnitClass.Vehicle, unit = "type93"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type94aa"},
			--Half_tracks
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "type94_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type97_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type95_ha-go"},
			--Tanks_medium
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_chi-ha"},
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_shinhoto_47mm"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type1_chi-he"},
				{priority = 2.5, class = UnitClass.Tank, unit = "type97_shinhoto_120mm"},
				{priority = 0.5, class = UnitClass.Tank, unit = "type3_chi-nu"},
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "type1_ho-ni1"},
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "type1_ho-ni2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "type4_ho-ro"}
			--Tanks_heavy
			},
			["usa"] = {--USA
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(usa)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(usa)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(usa)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(usa)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(usa)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(usa)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(usa)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(usa)"},
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1917a1_aa"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_maxson"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "37_mm_m3"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1897a4"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "76_mm_m5late"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "90_mm_m1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "76_mm_m5"},
			--Howitzers				
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81_mm_m1"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "203_mm_m115"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willysmb"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willys50"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willysat"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dodgewc55"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m16"},											  
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t30hmc"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "cckw353_2xt27"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m22"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_stuart"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_satan"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m24_chaffee"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m18"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m3lee"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4"},	
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_zippo"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e2_jumbo"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3_105"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3c"},	
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "m4a3e2_jumbo_76w"},	
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "m26_pershing"},
			--SPG
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t12gmc"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m36"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7"}
			},
			["eng"] = {--Britain
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(eng)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(eng)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(eng)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(eng)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(eng)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(eng)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(eng)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(eng)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(eng)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(eng)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(eng)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_vickers_mki"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_bren"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf40mm"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf2pdr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf6pdr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf17pdr"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "76mm_mk_ii"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf3,7inch"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl72"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_eng"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "humber"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "mk2daimler"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_mk6"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "valentine_mkiii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "matilda_mkii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_a30"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_vi"},
				{priority = 1.0, class = UnitClass.Tank, unit = "comet_a34"},
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_ii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_iv"},
				{priority = 0.2, class = UnitClass.Tank, unit = "churchill_avre"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_vii"},			
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "achilles"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton"}
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
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "8mm_fiat_revelli_m1914_35"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "8mm_breda_37"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_2065"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "2cm_solothurn"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_4732"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_7527"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "obice_7513"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "7_5cm_pak97_38"},
			--Howitzers				
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_ita"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "obice_10017"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ab41"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "autocannone10017"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Vehicle, unit = "cv35"},
				{priority = 1.0, class = UnitClass.Tank, unit = "l640"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1441"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1542"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3n_ita"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4g_ita"},
			--Tanks_heavy			
			--SPG
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7518"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m7534"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_ita"}
			}
		}
	},
	{--purchase 3 heavy tank group
		waveNumber = 3,
	    -- Repeat = 10,
	    minRepeat = 2,
		maxRepeat = 3,
	    skipPossible = false,
	    waveDuration = 20,
		Units = {
			["ger"] = {--Germany
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4f2"},
			},
			["rus"] = {--Russia				
			--Tanks_heavy
			    {priority = 0.4, class = UnitClass.HeavyTank, unit = "kv1_40"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "kv1_41"},
				{priority = 0.1, class = UnitClass.HeavyTank, unit = "kv2_40"},
			},
						["fra"] = {--France
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(fra)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade_late(fra)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(fra)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(fra)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(fra)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(fra)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1919a4_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb_fr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1_fr"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "57_mm_m1_fr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1897a4_fr"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81_mm_m1_fr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l_fr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m1918"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dodgewc55_fr"},	
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m4halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m17_fr"},	
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8_fr"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_76_fr"},
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine_fr"},
				{priority = 0.2, class = UnitClass.ArtilleryTank, unit = "m7_fr"}
			},
			["pol"] = {--Poland
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(pol)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(pol)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(pol)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(pol)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(pol)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(pol)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(pol)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(pol)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_bren_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf40mm_pol"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf2pdr_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf6pdr_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf17pdr_pol"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45_pol"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound_pol"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_pol"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly_pol"},
			--Tanks_heavy			
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "achilles_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton_pol"}
			},
			["jap"] = {--Japan
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(jap)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(jap)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(jap)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(jap)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(jap)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(jap)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type92_stan"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "20mm_type_2"},	
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "37mm_type_94"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_88"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_90"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_41"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "47mm_type_1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_4"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_jap"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105mm_type_92"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "120mm_type_38"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "200mm_type_4"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "150mm_type_96"},
			--Wheel_vehicles
				{priority = 2.5, class = UnitClass.Vehicle, unit = "type93"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type94aa"},
			--Half_tracks
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "type94_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type97_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type95_ha-go"},
			--Tanks_medium
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_chi-ha"},
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_shinhoto_47mm"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type1_chi-he"},
				{priority = 2.5, class = UnitClass.Tank, unit = "type97_shinhoto_120mm"},
				{priority = 0.5, class = UnitClass.Tank, unit = "type3_chi-nu"},
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "type1_ho-ni1"},
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "type1_ho-ni2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "type4_ho-ro"}
			--Tanks_heavy
			},
			["usa"] = {--USA
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(usa)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(usa)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(usa)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(usa)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(usa)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(usa)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(usa)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(usa)"},
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1917a1_aa"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_maxson"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "37_mm_m3"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1897a4"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "76_mm_m5late"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "90_mm_m1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "76_mm_m5"},
			--Howitzers				
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81_mm_m1"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "203_mm_m115"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willysmb"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willys50"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willysat"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dodgewc55"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m16"},											  
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t30hmc"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "cckw353_2xt27"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m22"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_stuart"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_satan"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m24_chaffee"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m18"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m3lee"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4"},	
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_zippo"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e2_jumbo"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3_105"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3c"},	
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "m4a3e2_jumbo_76w"},	
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "m26_pershing"},
			--SPG
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t12gmc"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m36"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7"}
			},
			["eng"] = {--Britain
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(eng)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(eng)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(eng)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(eng)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(eng)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(eng)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(eng)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(eng)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(eng)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(eng)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(eng)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_vickers_mki"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_bren"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf40mm"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf2pdr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf6pdr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf17pdr"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "76mm_mk_ii"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf3,7inch"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl72"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_eng"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "humber"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "mk2daimler"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_mk6"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "valentine_mkiii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "matilda_mkii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_a30"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_vi"},
				{priority = 1.0, class = UnitClass.Tank, unit = "comet_a34"},
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_ii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_iv"},
				{priority = 0.2, class = UnitClass.Tank, unit = "churchill_avre"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_vii"},			
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "achilles"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton"}
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
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "8mm_fiat_revelli_m1914_35"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "8mm_breda_37"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_2065"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "2cm_solothurn"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_4732"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_7527"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "obice_7513"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "7_5cm_pak97_38"},
			--Howitzers				
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_ita"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "obice_10017"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ab41"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "autocannone10017"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Vehicle, unit = "cv35"},
				{priority = 1.0, class = UnitClass.Tank, unit = "l640"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1441"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1542"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3n_ita"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4g_ita"},
			--Tanks_heavy			
			--SPG
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7518"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m7534"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_ita"}
			}
		}
	},
	{--purchase 4 medium tank group
		waveNumber = 4,
	    -- Repeat = 16,
	    minRepeat = 6,
		maxRepeat = 8,
	    skipPossible = false,
	    waveDuration = 20,
		Units = {
			["ger"] = {--Germany
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4f1"},
				{priority = 0.6, class = UnitClass.Tank, unit = "panzer4f2"},
			},
			["rus"] = {--Russia		
			--Tanks_medium				
				{priority = 0.7, class = UnitClass.Tank, unit = "t3476_41"},				
				{priority = 0.7, class = UnitClass.Tank, unit = "t3476_42"},
				{priority = 0.1, class = UnitClass.Tank, unit = "t3457_41"},
				{priority = 0.1, class = UnitClass.Tank, unit = "t3476_40"},
			--Tanks_heavy
			},
						["fra"] = {--France
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(fra)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade_late(fra)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(fra)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(fra)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(fra)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(fra)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1919a4_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb_fr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1_fr"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "57_mm_m1_fr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1897a4_fr"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81_mm_m1_fr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l_fr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m1918"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dodgewc55_fr"},	
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m4halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m17_fr"},	
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8_fr"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_76_fr"},
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine_fr"},
				{priority = 0.2, class = UnitClass.ArtilleryTank, unit = "m7_fr"}
			},
			["pol"] = {--Poland
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(pol)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(pol)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(pol)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(pol)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(pol)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(pol)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(pol)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(pol)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_bren_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf40mm_pol"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf2pdr_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf6pdr_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf17pdr_pol"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45_pol"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound_pol"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_pol"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly_pol"},
			--Tanks_heavy			
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "achilles_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton_pol"}
			},
			["jap"] = {--Japan
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(jap)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(jap)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(jap)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(jap)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(jap)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(jap)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type92_stan"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "20mm_type_2"},	
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "37mm_type_94"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_88"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_90"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_41"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "47mm_type_1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_4"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_jap"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105mm_type_92"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "120mm_type_38"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "200mm_type_4"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "150mm_type_96"},
			--Wheel_vehicles
				{priority = 2.5, class = UnitClass.Vehicle, unit = "type93"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type94aa"},
			--Half_tracks
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "type94_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type97_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type95_ha-go"},
			--Tanks_medium
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_chi-ha"},
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_shinhoto_47mm"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type1_chi-he"},
				{priority = 2.5, class = UnitClass.Tank, unit = "type97_shinhoto_120mm"},
				{priority = 0.5, class = UnitClass.Tank, unit = "type3_chi-nu"},
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "type1_ho-ni1"},
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "type1_ho-ni2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "type4_ho-ro"}
			--Tanks_heavy
			},
			["usa"] = {--USA
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(usa)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(usa)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(usa)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(usa)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(usa)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(usa)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(usa)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(usa)"},
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1917a1_aa"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_maxson"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "37_mm_m3"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1897a4"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "76_mm_m5late"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "90_mm_m1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "76_mm_m5"},
			--Howitzers				
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81_mm_m1"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "203_mm_m115"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willysmb"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willys50"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willysat"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dodgewc55"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m16"},											  
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t30hmc"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "cckw353_2xt27"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m22"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_stuart"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_satan"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m24_chaffee"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m18"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m3lee"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4"},	
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_zippo"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e2_jumbo"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3_105"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3c"},	
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "m4a3e2_jumbo_76w"},	
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "m26_pershing"},
			--SPG
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t12gmc"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m36"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7"}
			},
			["eng"] = {--Britain
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(eng)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(eng)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(eng)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(eng)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(eng)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(eng)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(eng)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(eng)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(eng)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(eng)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(eng)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_vickers_mki"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_bren"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf40mm"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf2pdr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf6pdr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf17pdr"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "76mm_mk_ii"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf3,7inch"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl72"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_eng"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "humber"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "mk2daimler"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_mk6"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "valentine_mkiii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "matilda_mkii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_a30"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_vi"},
				{priority = 1.0, class = UnitClass.Tank, unit = "comet_a34"},
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_ii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_iv"},
				{priority = 0.2, class = UnitClass.Tank, unit = "churchill_avre"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_vii"},			
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "achilles"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton"}
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
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "8mm_fiat_revelli_m1914_35"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "8mm_breda_37"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_2065"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "2cm_solothurn"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_4732"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_7527"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "obice_7513"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "7_5cm_pak97_38"},
			--Howitzers				
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_ita"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "obice_10017"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ab41"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "autocannone10017"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Vehicle, unit = "cv35"},
				{priority = 1.0, class = UnitClass.Tank, unit = "l640"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1441"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1542"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3n_ita"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4g_ita"},
			--Tanks_heavy			
			--SPG
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7518"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m7534"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_ita"}
			}
		}
	},
	{--purchase 5 light tank group
		waveNumber = 5,
	    -- Repeat = 20,
	    minRepeat = 5,
		maxRepeat = 10,
	    skipPossible = false,
	    waveDuration = 20,
		Units = {
			["ger"] = {--Germany
			--Tanks_light
                {priority = 0.4, class = UnitClass.Tank, unit = "panzer3j1"},
				{priority = 0.6, class = UnitClass.Tank, unit = "panzer3j"},
				{priority = 0.2, class = UnitClass.Tank, unit = "panzer3f"},
				{priority = 0.2, class = UnitClass.Tank, unit = "panzer3e"},
				{priority = 0.5, class = UnitClass.Tank, unit = "panzer2f"},
				{priority = 0.1, class = UnitClass.Tank, unit = "panzer2c"},
				
			},
			["rus"] = {--Russia			
            --Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "t60"},			
			},
						["fra"] = {--France
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(fra)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade_late(fra)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(fra)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(fra)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(fra)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(fra)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1919a4_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb_fr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1_fr"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "57_mm_m1_fr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1897a4_fr"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81_mm_m1_fr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l_fr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m1918"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dodgewc55_fr"},	
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m4halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m17_fr"},	
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8_fr"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_76_fr"},
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine_fr"},
				{priority = 0.2, class = UnitClass.ArtilleryTank, unit = "m7_fr"}
			},
			["pol"] = {--Poland
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(pol)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(pol)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(pol)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(pol)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(pol)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(pol)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(pol)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(pol)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_bren_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf40mm_pol"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf2pdr_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf6pdr_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf17pdr_pol"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45_pol"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound_pol"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_pol"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly_pol"},
			--Tanks_heavy			
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "achilles_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton_pol"}
			},
			["jap"] = {--Japan
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(jap)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(jap)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(jap)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(jap)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(jap)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(jap)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type92_stan"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "20mm_type_2"},	
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "37mm_type_94"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_88"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_90"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_41"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "47mm_type_1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_4"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_jap"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105mm_type_92"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "120mm_type_38"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "200mm_type_4"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "150mm_type_96"},
			--Wheel_vehicles
				{priority = 2.5, class = UnitClass.Vehicle, unit = "type93"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type94aa"},
			--Half_tracks
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "type94_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type97_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type95_ha-go"},
			--Tanks_medium
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_chi-ha"},
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_shinhoto_47mm"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type1_chi-he"},
				{priority = 2.5, class = UnitClass.Tank, unit = "type97_shinhoto_120mm"},
				{priority = 0.5, class = UnitClass.Tank, unit = "type3_chi-nu"},
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "type1_ho-ni1"},
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "type1_ho-ni2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "type4_ho-ro"}
			--Tanks_heavy
			},
			["usa"] = {--USA
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(usa)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(usa)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(usa)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(usa)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(usa)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(usa)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(usa)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(usa)"},
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1917a1_aa"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_maxson"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "37_mm_m3"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1897a4"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "76_mm_m5late"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "90_mm_m1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "76_mm_m5"},
			--Howitzers				
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81_mm_m1"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "203_mm_m115"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willysmb"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willys50"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willysat"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dodgewc55"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m16"},											  
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t30hmc"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "cckw353_2xt27"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m22"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_stuart"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_satan"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m24_chaffee"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m18"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m3lee"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4"},	
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_zippo"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e2_jumbo"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3_105"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3c"},	
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "m4a3e2_jumbo_76w"},	
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "m26_pershing"},
			--SPG
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t12gmc"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m36"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7"}
			},
			["eng"] = {--Britain
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(eng)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(eng)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(eng)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(eng)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(eng)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(eng)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(eng)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(eng)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(eng)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(eng)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(eng)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_vickers_mki"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_bren"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf40mm"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf2pdr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf6pdr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf17pdr"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "76mm_mk_ii"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf3,7inch"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl72"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_eng"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "humber"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "mk2daimler"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_mk6"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "valentine_mkiii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "matilda_mkii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_a30"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_vi"},
				{priority = 1.0, class = UnitClass.Tank, unit = "comet_a34"},
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_ii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_iv"},
				{priority = 0.2, class = UnitClass.Tank, unit = "churchill_avre"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_vii"},			
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "achilles"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton"}
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
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "8mm_fiat_revelli_m1914_35"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "8mm_breda_37"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_2065"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "2cm_solothurn"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_4732"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_7527"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "obice_7513"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "7_5cm_pak97_38"},
			--Howitzers				
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_ita"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "obice_10017"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ab41"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "autocannone10017"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Vehicle, unit = "cv35"},
				{priority = 1.0, class = UnitClass.Tank, unit = "l640"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1441"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1542"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3n_ita"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4g_ita"},
			--Tanks_heavy			
			--SPG
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7518"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m7534"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_ita"}
			}
		}
	},
	{--purchase 6 infantry support
		waveNumber = 6,
		-- Repeat = 60,
		minRepeat = 7,
		maxRepeat = 10,
        skipPossible = false,		
		waveDuration = 35,
		Units = {
			["ger"] = {--Germany
			--Infantry Squads
			    {priority = 1.0, class = UnitClass.Infantry, unit = "squad_regular_motor_con"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular_con(ger)"},
				{priority = 0.2, class = UnitClass.ATInfantry, unit = "single_at(ger)"},
				{priority = 0.2, class = UnitClass.ATInfantry, unit = "single_riflegrenade(ger)"}
			},
			["rus"] = {--Russia
			--Infantry Squads
				{priority = 2.5, class = UnitClass.Infantry, unit = "squad_rifleunit_alt_con(rus)"},
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_rifleunit_con(rus)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_at(rus)"},
			},
						["fra"] = {--France
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(fra)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade_late(fra)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(fra)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(fra)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(fra)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(fra)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1919a4_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb_fr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1_fr"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "57_mm_m1_fr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1897a4_fr"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81_mm_m1_fr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l_fr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m1918"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dodgewc55_fr"},	
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m4halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m17_fr"},	
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8_fr"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_76_fr"},
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine_fr"},
				{priority = 0.2, class = UnitClass.ArtilleryTank, unit = "m7_fr"}
			},
			["pol"] = {--Poland
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(pol)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(pol)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(pol)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(pol)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(pol)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(pol)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(pol)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(pol)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_bren_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf40mm_pol"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf2pdr_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf6pdr_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf17pdr_pol"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45_pol"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound_pol"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_pol"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly_pol"},
			--Tanks_heavy			
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "achilles_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton_pol"}
			},
			["jap"] = {--Japan
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(jap)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(jap)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(jap)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(jap)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(jap)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(jap)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type92_stan"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "20mm_type_2"},	
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "37mm_type_94"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_88"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_90"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_41"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "47mm_type_1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_4"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_jap"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105mm_type_92"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "120mm_type_38"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "200mm_type_4"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "150mm_type_96"},
			--Wheel_vehicles
				{priority = 2.5, class = UnitClass.Vehicle, unit = "type93"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type94aa"},
			--Half_tracks
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "type94_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type97_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type95_ha-go"},
			--Tanks_medium
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_chi-ha"},
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_shinhoto_47mm"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type1_chi-he"},
				{priority = 2.5, class = UnitClass.Tank, unit = "type97_shinhoto_120mm"},
				{priority = 0.5, class = UnitClass.Tank, unit = "type3_chi-nu"},
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "type1_ho-ni1"},
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "type1_ho-ni2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "type4_ho-ro"}
			--Tanks_heavy
			},
			["usa"] = {--USA
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(usa)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(usa)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(usa)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(usa)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(usa)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(usa)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(usa)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(usa)"},
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1917a1_aa"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_maxson"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "37_mm_m3"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1897a4"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "76_mm_m5late"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "90_mm_m1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "76_mm_m5"},
			--Howitzers				
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81_mm_m1"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "203_mm_m115"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willysmb"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willys50"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willysat"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dodgewc55"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m16"},											  
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t30hmc"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "cckw353_2xt27"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m22"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_stuart"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_satan"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m24_chaffee"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m18"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m3lee"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4"},	
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_zippo"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e2_jumbo"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3_105"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3c"},	
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "m4a3e2_jumbo_76w"},	
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "m26_pershing"},
			--SPG
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t12gmc"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m36"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7"}
			},
			["eng"] = {--Britain
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(eng)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(eng)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(eng)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(eng)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(eng)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(eng)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(eng)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(eng)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(eng)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(eng)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(eng)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_vickers_mki"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_bren"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf40mm"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf2pdr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf6pdr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf17pdr"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "76mm_mk_ii"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf3,7inch"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl72"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_eng"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "humber"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "mk2daimler"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_mk6"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "valentine_mkiii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "matilda_mkii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_a30"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_vi"},
				{priority = 1.0, class = UnitClass.Tank, unit = "comet_a34"},
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_ii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_iv"},
				{priority = 0.2, class = UnitClass.Tank, unit = "churchill_avre"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_vii"},			
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "achilles"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton"}
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
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "8mm_fiat_revelli_m1914_35"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "8mm_breda_37"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_2065"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "2cm_solothurn"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_4732"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_7527"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "obice_7513"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "7_5cm_pak97_38"},
			--Howitzers				
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_ita"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "obice_10017"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ab41"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "autocannone10017"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Vehicle, unit = "cv35"},
				{priority = 1.0, class = UnitClass.Tank, unit = "l640"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1441"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1542"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3n_ita"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4g_ita"},
			--Tanks_heavy			
			--SPG
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7518"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m7534"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_ita"}
			}
		}
	},
	{--purchase 7 SPG support
		waveNumber = 7,
		-- Repeat = 6,
		minRepeat = 2,
		maxRepeat = 4,
        skipPossible = false,		
		waveDuration = 15,
		Units = {
			["ger"] = {--Germany
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "marder2"},
				{priority = 0.1, class = UnitClass.ArtilleryTank, unit = "sig33b"},
			},
			["rus"] = {--Russia
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "zis30"},
			},
						["fra"] = {--France
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(fra)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade_late(fra)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(fra)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(fra)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(fra)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(fra)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1919a4_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb_fr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1_fr"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "57_mm_m1_fr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1897a4_fr"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81_mm_m1_fr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l_fr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m1918"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dodgewc55_fr"},	
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m4halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m17_fr"},	
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8_fr"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_76_fr"},
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine_fr"},
				{priority = 0.2, class = UnitClass.ArtilleryTank, unit = "m7_fr"}
			},
			["pol"] = {--Poland
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(pol)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(pol)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(pol)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(pol)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(pol)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(pol)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(pol)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(pol)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_bren_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf40mm_pol"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf2pdr_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf6pdr_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf17pdr_pol"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45_pol"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound_pol"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_pol"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly_pol"},
			--Tanks_heavy			
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "achilles_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton_pol"}
			},
			["jap"] = {--Japan
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(jap)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(jap)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(jap)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(jap)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(jap)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(jap)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type92_stan"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "20mm_type_2"},	
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "37mm_type_94"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_88"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_90"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_41"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "47mm_type_1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_4"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_jap"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105mm_type_92"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "120mm_type_38"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "200mm_type_4"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "150mm_type_96"},
			--Wheel_vehicles
				{priority = 2.5, class = UnitClass.Vehicle, unit = "type93"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type94aa"},
			--Half_tracks
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "type94_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type97_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type95_ha-go"},
			--Tanks_medium
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_chi-ha"},
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_shinhoto_47mm"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type1_chi-he"},
				{priority = 2.5, class = UnitClass.Tank, unit = "type97_shinhoto_120mm"},
				{priority = 0.5, class = UnitClass.Tank, unit = "type3_chi-nu"},
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "type1_ho-ni1"},
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "type1_ho-ni2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "type4_ho-ro"}
			--Tanks_heavy
			},
			["usa"] = {--USA
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(usa)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(usa)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(usa)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(usa)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(usa)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(usa)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(usa)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(usa)"},
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1917a1_aa"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_maxson"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "37_mm_m3"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1897a4"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "76_mm_m5late"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "90_mm_m1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "76_mm_m5"},
			--Howitzers				
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81_mm_m1"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "203_mm_m115"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willysmb"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willys50"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willysat"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dodgewc55"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m16"},											  
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t30hmc"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "cckw353_2xt27"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m22"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_stuart"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_satan"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m24_chaffee"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m18"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m3lee"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4"},	
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_zippo"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e2_jumbo"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3_105"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3c"},	
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "m4a3e2_jumbo_76w"},	
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "m26_pershing"},
			--SPG
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t12gmc"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m36"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7"}
			},
			["eng"] = {--Britain
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(eng)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(eng)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(eng)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(eng)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(eng)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(eng)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(eng)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(eng)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(eng)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(eng)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(eng)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_vickers_mki"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_bren"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf40mm"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf2pdr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf6pdr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf17pdr"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "76mm_mk_ii"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf3,7inch"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl72"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_eng"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "humber"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "mk2daimler"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_mk6"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "valentine_mkiii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "matilda_mkii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_a30"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_vi"},
				{priority = 1.0, class = UnitClass.Tank, unit = "comet_a34"},
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_ii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_iv"},
				{priority = 0.2, class = UnitClass.Tank, unit = "churchill_avre"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_vii"},			
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "achilles"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton"}
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
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "8mm_fiat_revelli_m1914_35"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "8mm_breda_37"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_2065"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "2cm_solothurn"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_4732"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_7527"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "obice_7513"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "7_5cm_pak97_38"},
			--Howitzers				
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_ita"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "obice_10017"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ab41"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "autocannone10017"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Vehicle, unit = "cv35"},
				{priority = 1.0, class = UnitClass.Tank, unit = "l640"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1441"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1542"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3n_ita"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4g_ita"},
			--Tanks_heavy			
			--SPG
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7518"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m7534"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_ita"}
			}
		}
	},
	{--purchase 8 mgun support
		waveNumber = 8,
		-- Repeat = 12,
		minRepeat = 1,
		maxRepeat = 4,
        skipPossible = false,		
		waveDuration = 15,
		Units = {
			["ger"] = {--Germany
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "mg34_lafette"},
				{priority = 0.2, class = UnitClass.ATTank, unit = "mg42_lafette"},
			},
			["rus"] = {--Russia
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "maxim"},
				{priority = 0.2, class = UnitClass.ATTank, unit = "dshk_stan"},
			},
						["fra"] = {--France
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(fra)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade_late(fra)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(fra)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(fra)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(fra)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(fra)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1919a4_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb_fr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1_fr"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "57_mm_m1_fr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1897a4_fr"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81_mm_m1_fr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l_fr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m1918"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dodgewc55_fr"},	
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m4halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m17_fr"},	
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8_fr"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_76_fr"},
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine_fr"},
				{priority = 0.2, class = UnitClass.ArtilleryTank, unit = "m7_fr"}
			},
			["pol"] = {--Poland
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(pol)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(pol)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(pol)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(pol)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(pol)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(pol)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(pol)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(pol)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_bren_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf40mm_pol"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf2pdr_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf6pdr_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf17pdr_pol"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45_pol"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound_pol"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_pol"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly_pol"},
			--Tanks_heavy			
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "achilles_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton_pol"}
			},
			["jap"] = {--Japan
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(jap)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(jap)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(jap)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(jap)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(jap)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(jap)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type92_stan"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "20mm_type_2"},	
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "37mm_type_94"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_88"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_90"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_41"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "47mm_type_1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_4"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_jap"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105mm_type_92"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "120mm_type_38"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "200mm_type_4"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "150mm_type_96"},
			--Wheel_vehicles
				{priority = 2.5, class = UnitClass.Vehicle, unit = "type93"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type94aa"},
			--Half_tracks
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "type94_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type97_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type95_ha-go"},
			--Tanks_medium
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_chi-ha"},
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_shinhoto_47mm"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type1_chi-he"},
				{priority = 2.5, class = UnitClass.Tank, unit = "type97_shinhoto_120mm"},
				{priority = 0.5, class = UnitClass.Tank, unit = "type3_chi-nu"},
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "type1_ho-ni1"},
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "type1_ho-ni2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "type4_ho-ro"}
			--Tanks_heavy
			},
			["usa"] = {--USA
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(usa)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(usa)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(usa)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(usa)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(usa)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(usa)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(usa)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(usa)"},
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1917a1_aa"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_maxson"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "37_mm_m3"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1897a4"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "76_mm_m5late"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "90_mm_m1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "76_mm_m5"},
			--Howitzers				
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81_mm_m1"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "203_mm_m115"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willysmb"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willys50"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willysat"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dodgewc55"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m16"},											  
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t30hmc"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "cckw353_2xt27"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m22"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_stuart"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_satan"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m24_chaffee"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m18"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m3lee"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4"},	
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_zippo"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e2_jumbo"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3_105"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3c"},	
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "m4a3e2_jumbo_76w"},	
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "m26_pershing"},
			--SPG
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t12gmc"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m36"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7"}
			},
			["eng"] = {--Britain
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(eng)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(eng)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(eng)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(eng)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(eng)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(eng)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(eng)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(eng)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(eng)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(eng)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(eng)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_vickers_mki"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_bren"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf40mm"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf2pdr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf6pdr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf17pdr"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "76mm_mk_ii"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf3,7inch"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl72"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_eng"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "humber"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "mk2daimler"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_mk6"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "valentine_mkiii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "matilda_mkii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_a30"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_vi"},
				{priority = 1.0, class = UnitClass.Tank, unit = "comet_a34"},
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_ii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_iv"},
				{priority = 0.2, class = UnitClass.Tank, unit = "churchill_avre"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_vii"},			
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "achilles"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton"}
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
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "8mm_fiat_revelli_m1914_35"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "8mm_breda_37"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_2065"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "2cm_solothurn"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_4732"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_7527"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "obice_7513"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "7_5cm_pak97_38"},
			--Howitzers				
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_ita"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "obice_10017"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ab41"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "autocannone10017"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Vehicle, unit = "cv35"},
				{priority = 1.0, class = UnitClass.Tank, unit = "l640"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1441"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1542"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3n_ita"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4g_ita"},
			--Tanks_heavy			
			--SPG
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7518"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m7534"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_ita"}
			}
		}
	},	
	{--purchase 9 gun support
		waveNumber = 9,
		-- Repeat = 2,
		minRepeat = 1,
		maxRepeat = 2,
        skipPossible = false,		
		waveDuration = 15,
		Units = {
			["ger"] = {--Germany
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_leig18"},
			},
			["rus"] = {--Russia
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "76mm_m1927"},
			},
						["fra"] = {--France
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(fra)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade_late(fra)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(fra)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(fra)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(fra)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(fra)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1919a4_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb_fr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1_fr"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "57_mm_m1_fr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1897a4_fr"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81_mm_m1_fr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l_fr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m1918"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dodgewc55_fr"},	
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m4halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m17_fr"},	
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8_fr"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_76_fr"},
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine_fr"},
				{priority = 0.2, class = UnitClass.ArtilleryTank, unit = "m7_fr"}
			},
			["pol"] = {--Poland
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(pol)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(pol)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(pol)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(pol)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(pol)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(pol)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(pol)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(pol)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_bren_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf40mm_pol"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf2pdr_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf6pdr_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf17pdr_pol"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45_pol"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound_pol"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_pol"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly_pol"},
			--Tanks_heavy			
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "achilles_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton_pol"}
			},
			["jap"] = {--Japan
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(jap)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(jap)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(jap)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(jap)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(jap)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(jap)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type92_stan"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "20mm_type_2"},	
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "37mm_type_94"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_88"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_90"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_41"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "47mm_type_1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_4"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_jap"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105mm_type_92"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "120mm_type_38"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "200mm_type_4"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "150mm_type_96"},
			--Wheel_vehicles
				{priority = 2.5, class = UnitClass.Vehicle, unit = "type93"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type94aa"},
			--Half_tracks
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "type94_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type97_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type95_ha-go"},
			--Tanks_medium
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_chi-ha"},
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_shinhoto_47mm"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type1_chi-he"},
				{priority = 2.5, class = UnitClass.Tank, unit = "type97_shinhoto_120mm"},
				{priority = 0.5, class = UnitClass.Tank, unit = "type3_chi-nu"},
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "type1_ho-ni1"},
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "type1_ho-ni2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "type4_ho-ro"}
			--Tanks_heavy
			},
			["usa"] = {--USA
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(usa)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(usa)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(usa)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(usa)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(usa)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(usa)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(usa)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(usa)"},
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1917a1_aa"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_maxson"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "37_mm_m3"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1897a4"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "76_mm_m5late"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "90_mm_m1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "76_mm_m5"},
			--Howitzers				
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81_mm_m1"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "203_mm_m115"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willysmb"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willys50"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willysat"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dodgewc55"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m16"},											  
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t30hmc"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "cckw353_2xt27"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m22"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_stuart"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_satan"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m24_chaffee"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m18"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m3lee"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4"},	
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_zippo"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e2_jumbo"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3_105"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3c"},	
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "m4a3e2_jumbo_76w"},	
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "m26_pershing"},
			--SPG
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t12gmc"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m36"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7"}
			},
			["eng"] = {--Britain
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(eng)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(eng)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(eng)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(eng)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(eng)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(eng)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(eng)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(eng)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(eng)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(eng)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(eng)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_vickers_mki"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_bren"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf40mm"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf2pdr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf6pdr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf17pdr"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "76mm_mk_ii"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf3,7inch"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl72"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_eng"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "humber"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "mk2daimler"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_mk6"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "valentine_mkiii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "matilda_mkii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_a30"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_vi"},
				{priority = 1.0, class = UnitClass.Tank, unit = "comet_a34"},
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_ii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_iv"},
				{priority = 0.2, class = UnitClass.Tank, unit = "churchill_avre"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_vii"},			
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "achilles"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton"}
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
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "8mm_fiat_revelli_m1914_35"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "8mm_breda_37"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_2065"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "2cm_solothurn"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_4732"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_7527"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "obice_7513"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "7_5cm_pak97_38"},
			--Howitzers				
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_ita"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "obice_10017"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ab41"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "autocannone10017"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Vehicle, unit = "cv35"},
				{priority = 1.0, class = UnitClass.Tank, unit = "l640"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1441"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1542"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3n_ita"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4g_ita"},
			--Tanks_heavy			
			--SPG
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7518"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m7534"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_ita"}
			}
		}
	},
	{--purchase 10 gun support
		waveNumber = 10,
		-- Repeat = 2,
		minRepeat = 1,
		maxRepeat = 2,
        skipPossible = false,		
		waveDuration = 15,
		Units = {
			["ger"] = {--Germany
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "marder2"},
				{priority = 0.1, class = UnitClass.ArtilleryTank, unit = "sig33b"},
			},
			["rus"] = {--Russia
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "zis30"},
			},
						["fra"] = {--France
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(fra)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade_late(fra)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(fra)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(fra)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(fra)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(fra)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1919a4_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb_fr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1_fr"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "57_mm_m1_fr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1897a4_fr"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81_mm_m1_fr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l_fr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m1918"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dodgewc55_fr"},	
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m4halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m17_fr"},	
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8_fr"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_76_fr"},
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine_fr"},
				{priority = 0.2, class = UnitClass.ArtilleryTank, unit = "m7_fr"}
			},
			["pol"] = {--Poland
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(pol)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(pol)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(pol)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(pol)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(pol)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(pol)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(pol)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(pol)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_bren_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf40mm_pol"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf2pdr_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf6pdr_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf17pdr_pol"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45_pol"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound_pol"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_pol"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly_pol"},
			--Tanks_heavy			
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "achilles_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton_pol"}
			},
			["jap"] = {--Japan
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(jap)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(jap)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(jap)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(jap)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(jap)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(jap)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type92_stan"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "20mm_type_2"},	
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "37mm_type_94"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_88"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_90"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_41"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "47mm_type_1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_4"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_jap"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105mm_type_92"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "120mm_type_38"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "200mm_type_4"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "150mm_type_96"},
			--Wheel_vehicles
				{priority = 2.5, class = UnitClass.Vehicle, unit = "type93"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type94aa"},
			--Half_tracks
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "type94_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type97_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type95_ha-go"},
			--Tanks_medium
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_chi-ha"},
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_shinhoto_47mm"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type1_chi-he"},
				{priority = 2.5, class = UnitClass.Tank, unit = "type97_shinhoto_120mm"},
				{priority = 0.5, class = UnitClass.Tank, unit = "type3_chi-nu"},
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "type1_ho-ni1"},
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "type1_ho-ni2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "type4_ho-ro"}
			--Tanks_heavy
			},
			["usa"] = {--USA
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(usa)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(usa)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(usa)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(usa)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(usa)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(usa)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(usa)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(usa)"},
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1917a1_aa"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_maxson"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "37_mm_m3"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1897a4"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "76_mm_m5late"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "90_mm_m1"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "76_mm_m5"},
			--Howitzers				
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81_mm_m1"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "203_mm_m115"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willysmb"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willys50"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willysat"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dodgewc55"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m16"},											  
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t30hmc"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "cckw353_2xt27"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m22"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_stuart"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_satan"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m24_chaffee"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m18"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m3lee"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4"},	
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_zippo"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e2_jumbo"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3_105"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3c"},	
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "m4a3e2_jumbo_76w"},	
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "m26_pershing"},
			--SPG
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t12gmc"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m36"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7"}
			},
			["eng"] = {--Britain
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(eng)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(eng)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(eng)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(eng)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(eng)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(eng)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(eng)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(eng)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(eng)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(eng)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(eng)"},
				-- 6
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_vickers_mki"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_bren"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf40mm"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf2pdr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf6pdr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf17pdr"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "76mm_mk_ii"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf3,7inch"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl72"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_eng"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "humber"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "mk2daimler"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_mk6"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "valentine_mkiii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "matilda_mkii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_a30"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_vi"},
				{priority = 1.0, class = UnitClass.Tank, unit = "comet_a34"},
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_ii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_iv"},
				{priority = 0.2, class = UnitClass.Tank, unit = "churchill_avre"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_vii"},			
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "achilles"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton"}
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
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "8mm_fiat_revelli_m1914_35"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "8mm_breda_37"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_2065"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "2cm_solothurn"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_4732"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_7527"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "obice_7513"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "7_5cm_pak97_38"},
			--Howitzers				
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_ita"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "obice_10017"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ab41"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "autocannone10017"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Vehicle, unit = "cv35"},
				{priority = 1.0, class = UnitClass.Tank, unit = "l640"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1441"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1542"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3n_ita"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4g_ita"},
			--Tanks_heavy			
			--SPG
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7518"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m7534"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_ita"}
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
