Purchases["campaign_capture_the_flag"] = {
	{--purchase 1 starting recon wave
		divisionName = "Tank division",
		waveNumber = 1,
		-- Repeat = 6,
		minRepeat = 3,
		maxRepeat = 6,
		skipPossible = false,
		waveDuration = 20,
		Units = {
			["ger"] = {--Germany
				--Infantry Squads
				--Wheel_vehicles
				{priority = 0.1, class = UnitClass.Vehicle, unit = "p204_f"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz231"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz221"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_2"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_pz_pio_con"},
			},
			["rus"] = {--Russia
			--Infantry Singles
			--Wheel_vehicles
				{priority = 1.8, class = UnitClass.Vehicle, unit = "m3a1e1_scout_mgun"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ba6"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "ba64"},
			},
			["fra"] = {--France
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dodgewc55_fr"},	
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m17_fr"},
			},
			["pol"] = {--Poland
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound_pol"},
			},
			["jap"] = {--Japan
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(jap)"},
			--Wheel_vehicles
				{priority = 2.5, class = UnitClass.Vehicle, unit = "type93"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type94aa"},
			},
			["usa"] = {--USA
		    --Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound"},
			},
			["eng"] = {--Britain
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "humber"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "mk2daimler"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound"},
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2"},
			},
			["ita"] = {--Italy
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ab41"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "autocannone10017"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Vehicle, unit = "cv35"},
				{priority = 1.0, class = UnitClass.Tank, unit = "l640"},
			}
		}
	},
	{--purchase 2 tank assault group
		waveNumber = 2,
	    -- Repeat = 10,
		minRepeat = 4,
		maxRepeat = 8,
	    skipPossible = false,
	    waveDuration = 11,
		Units = {
			["ger"] = {--Germany
			--Tanks_heavy
			    {priority = 2.5, class = UnitClass.HeavyTank, unit = "panzer5a"},
				{priority = 2.0, class = UnitClass.HeavyTank, unit = "panzer5g"},
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "tiger1e"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "tiger1h"},
				{priority = 0.2, class = UnitClass.HeavyTank, unit = "tiger1hunt"},
				{priority = 0.1, class = UnitClass.HeavyTank, unit = "tiger2h"},
			--Tanks_medium
			    {priority = 2.5, class = UnitClass.Tank, unit = "panzer3m"},
				{priority = 3.5, class = UnitClass.Tank, unit = "panzer4h"},
				{priority = 3.0, class = UnitClass.Tank, unit = "panzer4j"},
			},
			["rus"] = {--Russia
			--Tanks_heavy
				{priority = 0.1, class = UnitClass.HeavyTank, unit = "churchill3"},
				{priority = 0.1, class = UnitClass.HeavyTank, unit = "kv85"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "kv1s"},
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "is1_43"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "is2_43"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "is2_44"},
            --Tanks_medium
				{priority = 3.5, class = UnitClass.Tank, unit = "t3476_43"},
				{priority = 0.1, class = UnitClass.Tank, unit = "t3457_43"},
				{priority = 0.5, class = UnitClass.Tank, unit = "t3476_43_flame"},
				{priority = 2.5, class = UnitClass.Tank, unit = "t3485_44"},
			},
			["fra"] = {--France
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8_fr"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_76_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cavalier_mk_vii"},
			},
			["pol"] = {--Poland
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly_pol"},
			},
			["jap"] = {--Japan
			--Tanks_medium
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_chi-ha"},
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_shinhoto_47mm"},
				{priority = 1.0, class = UnitClass.Tank, unit = "type1_chi-he"},
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_shinhoto_120mm"},
				{priority = 1.2, class = UnitClass.Tank, unit = "type3_chi-nu"},
				{priority = 1.0, class = UnitClass.Tank, unit = "type3_chi-nu2"},
			},
			["usa"] = {--USA
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m3lee"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4"},	
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e8"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3_105"},
				{priority = 0.7, class = UnitClass.HeavyTank, unit = "m26_pershing"},
			},
			["eng"] = {--Britain
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
				{priority = 0.8, class = UnitClass.Tank, unit = "churchill_mk_ii"},
				{priority = 0.8, class = UnitClass.Tank, unit = "churchill_mk_iv"},
				{priority = 0.8, class = UnitClass.Tank, unit = "churchill_mk_vii"},			
			},
			["ita"] = {--Italy
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3n_ita"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4g_ita"},
			--SPG
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "m7518"},
				{priority = 0.5, class = UnitClass.ATTank, unit = "m7534"},
				{priority = 0.5, class = UnitClass.ATTank, unit = "stug3g_ita"},
			}
		}
	},
	{--purchase 3 infantry support
		waveNumber = 3,
		-- Repeat = 8,
		minRepeat = 6,
		maxRepeat = 8,
        skipPossible = false,		
		waveDuration = 30,
		Units = {
			["ger"] = {--Germany
			--Infantry Squads
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_pz_pio_con"},
			},
			["rus"] = {--Russia
			--Infantry Squads
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_rifleunit_con(rus)"},
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
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(fra)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(fra)"},
				-- 4
				-- 5
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_marine_late(fra)"},				
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(fra)"},
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
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(pol)"},
				-- 4
				-- 5
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_scout_late(pol)"},				
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(pol)"},
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
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(jap)"},
				-- 4
				-- 5
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
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(usa)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(usa)"},
				-- 4
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
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(eng)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(eng)"},
				-- 4
				-- 5
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
	},
	{--purchase 4 SPG support
		waveNumber = 4,
		-- Repeat = 4,
		minRepeat = 1,
		maxRepeat = 4,
        skipPossible = false,		
		waveDuration = 11,
		Units = {
			["ger"] = {--Germany
			--SPG
				{priority = 2.5, class = UnitClass.ATTank, unit = "stug3g_late"},
				{priority = 2.0, class = UnitClass.ATTank, unit = "stug3g"},
				{priority = 0.1, class = UnitClass.Tank, unit = "grille_m"},
				{priority = 4.0, class = UnitClass.ArtilleryTank, unit = "stuh42"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sturmpanzer4"},
				{priority = 1.1, class = UnitClass.ArtilleryTank, unit = "sturmtiger"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "jagdpanther"}
			},
			["rus"] = {--Russia
			--SPG
				{priority = 2.0, class = UnitClass.ATTank, unit = "su100"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "su152"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "isu122s"},
				{priority = 2.0, class = UnitClass.ATTank, unit = "isu152"}
			},
			["fra"] = {--France
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine_fr"},
				{priority = 0.2, class = UnitClass.ArtilleryTank, unit = "m7_fr"},
			},
			["pol"] = {--Poland
				{priority = 0.1, class = UnitClass.ATTank, unit = "achilles_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton_pol"},
			},
			["jap"] = {--Japan
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "type1_ho-ni1"},
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "type1_ho-ni2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "type4_ho-ro"},
			--Tanks_heavy
			},
			["usa"] = {--USA
			--SPG
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t12gmc"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m12gmc"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7"},
			},
			["eng"] = {--Britain
				{priority = 0.2, class = UnitClass.Tank, unit = "churchill_avre"},
			--SPG
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton"},
			},
			["ita"] = {--Italy
			--SPG
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7518"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m7534"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_ita"},
			}
		}
	},
	{--purchase 5 Tank 2
		waveNumber = 5,
		-- Repeat = 4,
		minRepeat = 2,
		maxRepeat = 4,
        skipPossible = false,		
		waveDuration = 5,
		Units = {
			["ger"] = {--Germany
			--Tanks_heavy
			    {priority = 2.5, class = UnitClass.HeavyTank, unit = "panzer5a"},
				{priority = 2.0, class = UnitClass.HeavyTank, unit = "panzer5g"},
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "tiger1e"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "tiger1h"},
				{priority = 0.2, class = UnitClass.HeavyTank, unit = "tiger1hunt"},
				{priority = 0.1, class = UnitClass.HeavyTank, unit = "tiger2h"},
			--Tanks_medium
			    {priority = 2.5, class = UnitClass.Tank, unit = "panzer3m"},
				{priority = 3.5, class = UnitClass.Tank, unit = "panzer4h"},
				{priority = 3.0, class = UnitClass.Tank, unit = "panzer4j"},
			},
			["rus"] = {--Russia
			--Tanks_heavy
				{priority = 0.1, class = UnitClass.HeavyTank, unit = "churchill3"},
				{priority = 0.1, class = UnitClass.HeavyTank, unit = "kv85"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "kv1s"},
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "is1_43"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "is2_43"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "is2_44"},
            --Tanks_medium
				{priority = 3.5, class = UnitClass.Tank, unit = "t3476_43"},
				{priority = 0.1, class = UnitClass.Tank, unit = "t3457_43"},
				{priority = 0.5, class = UnitClass.Tank, unit = "t3476_43_flame"},
				{priority = 2.5, class = UnitClass.Tank, unit = "t3485_44"},
			},
			["fra"] = {--France
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m4halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m17_fr"},	
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_76_fr"},
			},
			["pol"] = {--Poland
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly_pol"},
			},
			["jap"] = {--Japan
			--Tanks_medium
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_chi-ha"},
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_shinhoto_47mm"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type1_chi-he"},
				{priority = 2.5, class = UnitClass.Tank, unit = "type97_shinhoto_120mm"},
				{priority = 0.5, class = UnitClass.Tank, unit = "type3_chi-nu"},
				{priority = 1.0, class = UnitClass.Tank, unit = "type3_chi-nu2"},
			},
			["usa"] = {--USA
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "m4a3e2_jumbo_76w"},	
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "m26_pershing"},
			},
			["eng"] = {--Britain
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_ii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_iv"},
				{priority = 0.2, class = UnitClass.Tank, unit = "churchill_avre"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_vii"},			
			},
			["ita"] = {--Italy
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3n_ita"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4g_ita"},
			}
		}
	},
	{--purchase 6 infantry attack 2
		waveNumber = 6,
		-- Repeat = 8,
		minRepeat = 6,
		maxRepeat = 8,
        skipPossible = false,		
		waveDuration = 22,
		Units = {
			["ger"] = {--Germany
			--Infantry Squads
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_con(ger)"},
				{priority = 3.0, class = UnitClass.Infantry, unit = "squad_pz_pio_con"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "blitz3_6_flak30"},
			},
			["rus"] = {--Russia
			--Infantry Squads
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_rifleunit_con(rus)"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "gaz_aaa_72k"},
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
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(fra)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(fra)"},
				-- 4				-- 5
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_marine_late(fra)"},				
				-- 6
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
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(pol)"},
				-- 4				-- 5
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_scout_late(pol)"},				
				
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
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(jap)"},
				-- 4			
			},
			["usa"] = {--USA
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(usa)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(usa)"},
				-- 3
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(usa)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(usa)"},
				-- 4	
			},
			["eng"] = {--Britain
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(eng)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(eng)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(eng)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(eng)"},
				-- 3
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(eng)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(eng)"},
				-- 4			
			},
			["ita"] = {--Italy
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_light(ita)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular(ita)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(ita)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_mg(ita)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(ita)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_flamer(ita)"},
			}
		}
	},
	{--purchase 7 rocket arty
		waveNumber = 7,
		-- Repeat = 2,
		minRepeat = 1,
		maxRepeat = 1,
        skipPossible = false,		
		waveDuration = 5,
		Units = {
			["ger"] = {--Germany
		       {priority = 2.0, class = UnitClass.ArtilleryTank, unit = "150mm_sfh18"},
			},
			["rus"] = {--Russia
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "152mm_ml20"},
			},
			["fra"] = {--France
			--Howitzers
				{priority = 0.8, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l_fr"},
			--Wheel_vehicles	
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m4halftrack_fr"},
			--SPG
				{priority = 0.2, class = UnitClass.ArtilleryTank, unit = "m7_fr"},
			},
			["pol"] = {--Poland
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45_pol"},			
			--SPG
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton_pol"},
			},
			["jap"] = {--Japan
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "200mm_type_4"},
			},
			["usa"] = {--USA
			--Tanks_medium
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l"},	
			},
			["eng"] = {--Britain
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr"},
			--SPG
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton"},
			},
			["ita"] = {--Italy
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "obice_10017"},
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
