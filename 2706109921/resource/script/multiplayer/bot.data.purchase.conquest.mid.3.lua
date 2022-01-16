Purchases["campaign_capture_the_flag"] = {
	{--purchase 1 starting recon wave
		divisionName = "Tank division",
		waveNumber = 1,
		-- Repeat = 6,
		minRepeat = 3,
		maxRepeat = 5,
		skipPossible = false,
		waveDuration = 20,
		Units = {
			["ger"] = {--Germany
				--Infantry Squads
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_recon_con(ger)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_recon_armor_con"},
				--Wheel_vehicles
				{priority = 0.1, class = UnitClass.Vehicle, unit = "p204_f"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz231"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz221"},
			},
			["rus"] = {--Russia
			--Infantry Singles
			    {priority = 2.5, class = UnitClass.Infantry, unit = "squad_recon_con(rus)"},
			--Wheel_vehicles
				{priority = 1.5, class = UnitClass.Vehicle, unit = "ba64"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ba6"},
			},
			["fra"] = {--France
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(fra)"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m4halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_fr"},
			},
			["pol"] = {--Poland
			--Infantry
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(pol)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_scout_late(pol)"},				
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "wz34"},
			},
			["jap"] = {--Japan
			--Infantry
				-- 1
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(jap)"},
				--Wheel_vehicles
				{priority = 2.5, class = UnitClass.Vehicle, unit = "type93"},
				{priority = 2.5, class = UnitClass.Vehicle, unit = "type1_ho-ki_mg"},				
			--Half_tracks
			},
			["usa"] = {--USA
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(usa)"},
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(usa)"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m16"},											  
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound"},
			},
			["eng"] = {--Britain
			--Infantry
				-- 1
			-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(eng)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_scout_late(eng)"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_eng"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "humber"},
			},
			["ita"] = {--Italy
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_light(ita)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular(ita)"},
			    {priority = 1.0, class = UnitClass.Vehicle, unit = "cv35"},
				{priority = 1.0, class = UnitClass.Tank, unit = "l640"},
			}
		}
	},
	{--purchase 2 tank assault group
		waveNumber = 2,
	    -- Repeat = 6,
		minRepeat = 4,
		maxRepeat = 8,
	    skipPossible = false,
	    waveDuration = 20,
		Units = {
			["ger"] = {--Germany
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "panzer5d"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "tiger1h"},
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
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "kv2_40"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "kv1_41"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "kv1s"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "kv85"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "is1_43"},
				{priority = 0.1, class = UnitClass.HeavyTank, unit = "is2_43"},
	        --Tanks_medium
				{priority = 3.5, class = UnitClass.Tank, unit = "t3476_42"},
				{priority = 3.5, class = UnitClass.Tank, unit = "t3476_43"},
				{priority = 0.1, class = UnitClass.Tank, unit = "t3457_43"},
			--Tanks_light
				{priority = 0.5, class = UnitClass.Tank, unit = "t40"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t60"},
				{priority = 1.5, class = UnitClass.Tank, unit = "t70"},
				{priority = 2.0, class = UnitClass.Tank, unit = "t70m"},
				{priority = 1.0, class = UnitClass.Tank, unit = "bt7"},
			},
			["fra"] = {--France
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8_fr"},
			--Tanks_medium
			    {priority = 1.0, class = UnitClass.Tank, unit = "char_d2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75_fr"},
				{priority = 0.5, class = UnitClass.Tank, unit = "m4a3_76_fr"},
			--Tanks_heavy	
				{priority = 1.0, class = UnitClass.Tank, unit = "b1bis"},				
					
			},
			["pol"] = {--Poland
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_pol"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_pol"},
			},
			["jap"] = {--Japan
				{priority = 2.0, class = UnitClass.Tank, unit = "type1_chi-he"},
				{priority = 2.5, class = UnitClass.Tank, unit = "type97_shinhoto_120mm"},
				{priority = 1.0, class = UnitClass.Tank, unit = "type3_chi-nu"},
				{priority = 1.0, class = UnitClass.Tank, unit = "type3_chi-nu2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "type2_ho-i"},
				{priority = 1.0, class = UnitClass.Tank, unit = "type2_ho-i_kou"},								
			},
			["usa"] = {--USA
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_satan"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4"},	
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_zippo"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e2_jumbo"},
			},
			["eng"] = {--Britain
			--Tanks_light
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_vi"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_a30"},
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_ii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_iv"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_vii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_crocodile"},			
			},
			["ita"] = {--Italy
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3n_ita"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4g_ita"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_ita"}
			}
		}
	},
	{--purchase 3 infantry support
		waveNumber = 3,
		-- Repeat = 8,
		minRepeat = 6,
		maxRepeat = 8,
        skipPossible = false,		
		waveDuration = 25,
		Units = {
			["ger"] = {--Germany
			--Infantry Squads
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_con(ger)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular_vet_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_pz_pio_con"},
			},
			["rus"] = {--Russia
			--Infantry Squads
				{priority = 2.5, class = UnitClass.Infantry, unit = "squad_rifleunit_alt_con(rus)"},
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_rifleunit_con(rus)"},
			},
			["fra"] = {--France
			--Infantry
			-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(fra)"},
			},
			["pol"] = {--Poland
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(pol)"},
			},
			["jap"] = {--Japan
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(jap)"},
			},
			["usa"] = {--USA
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(usa)"},
			},
			["eng"] = {--Britain
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(eng)"},
			},
			["ita"] = {--Italy
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular(ita)"},
			}
		}
	},
	{--purchase 4 howtizer
		waveNumber = 4,
		-- Repeat = 2,
		minRepeat = 1,
		maxRepeat = 2,
        skipPossible = false,		
		waveDuration = 7,
		Units = {
			["ger"] = {--Germany
		       {priority = 2.0, class = UnitClass.ArtilleryTank, unit = "105mm_lefh18"},
			   	{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "150mm_sfh18"},
			},
			["rus"] = {--Russia
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "122mm_m30"},
					{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "152mm_ml20"},
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
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105mm_type_92"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "150mm_type_96"},
			},
			["usa"] = {--USA
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "107_mm_m2"},				
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m2"},
			},
			["eng"] = {--Britain
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl72"},
			},
			["ita"] = {--Italy
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "obice_10017"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "obice_210"},
			}
		}
	},
	{--purchase 5 SPG support
		waveNumber = 5,
		-- Repeat = 1,
		minRepeat = 2,
		maxRepeat = 3,
        skipPossible = false,		
		waveDuration = 5,
		Units = {
			["ger"] = {--Germany
			--SPG
				{priority = 1.5, class = UnitClass.ATTank, unit = "stug3f"},
				{priority = 3.0, class = UnitClass.ATTank, unit = "stug3g"},
							{priority = 4.0, class = UnitClass.ArtilleryTank, unit = "stuh42"},
			--SPG
				{priority = 0.1, class = UnitClass.ArtilleryTank, unit = "sturmpanzer4"},
				{priority = 0.1, class = UnitClass.ArtilleryTank, unit = "bison"},
				{priority = 1.1, class = UnitClass.ArtilleryTank, unit = "sig33b"},
				{priority = 0.1, class = UnitClass.ArtilleryTank, unit = "sturmtiger"},
			},
			["rus"] = {--Russia
			--SPG
				{priority = 1.5, class = UnitClass.ATTank, unit = "su85"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "su100"},
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "su122"},
			},
			["fra"] = {--France
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine_fr"},
				{priority = 0.2, class = UnitClass.ArtilleryTank, unit = "m7_fr"},
			},
			["pol"] = {--Poland
				{priority = 0.1, class = UnitClass.ATTank, unit = "achilles_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton_pol"}
			},
			["jap"] = {--Japan
				{priority = 1.0, class = UnitClass.ATTank, unit = "type1_ho-ni1"},
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "type1_ho-ni2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "type4_ho-ro"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "type5_ho-chi"}
			},
			["usa"] = {--USA
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m12gmc"},				
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m36"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m18"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3c"},	
			},
			["eng"] = {--Britain
			--SPG
				{priority = 0.5, class = UnitClass.ATTank, unit = "achilles"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3_105_eng"}
			},
			["ita"] = {--Italy
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_ita"}
			}
		}
	},
	{--purchase 6 Tank 2
		waveNumber = 6,
		-- Repeat = 7,
		minRepeat = 5,
		maxRepeat = 10,
        skipPossible = false,		
		waveDuration = 11,
		Units = {
			["ger"] = {--Germany
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "panzer5d"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "tiger1h"},
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
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "kv2_40"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "kv1_41"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "kv1s"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "kv85"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "is1_43"},
				{priority = 0.1, class = UnitClass.HeavyTank, unit = "is2_43"},
	        --Tanks_medium
				{priority = 3.5, class = UnitClass.Tank, unit = "t3476_42"},
				{priority = 3.5, class = UnitClass.Tank, unit = "t3476_43"},
				{priority = 0.1, class = UnitClass.Tank, unit = "t3457_43"},
			--Tanks_light
				{priority = 0.5, class = UnitClass.Tank, unit = "t40"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t60"},
				{priority = 1.5, class = UnitClass.Tank, unit = "t70"},
				{priority = 2.0, class = UnitClass.Tank, unit = "t70m"},
				{priority = 1.0, class = UnitClass.Tank, unit = "bt7"},
			},
			["fra"] = {--France
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75_fr"},
				{priority = 0.5, class = UnitClass.Tank, unit = "m4a3_76_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8_fr"},
			--Tanks_medium
			    {priority = 1.0, class = UnitClass.Tank, unit = "char_d2"},
			--Tanks_heavy	
				{priority = 1.0, class = UnitClass.Tank, unit = "b1bis"},				
					
			},
			["pol"] = {--Poland
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_pol"},
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_pol"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_pol"},
			},
			["jap"] = {--Japan
				{priority = 1.0, class = UnitClass.Tank, unit = "type3_chi-nu2"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type1_chi-he"},
				{priority = 2.5, class = UnitClass.Tank, unit = "type97_shinhoto_120mm"},
				{priority = 1.0, class = UnitClass.Tank, unit = "type3_chi-nu"},
				{priority = 1.0, class = UnitClass.Tank, unit = "type2_ho-i"},
				{priority = 1.0, class = UnitClass.Tank, unit = "type2_ho-i_kou"},								
			},
			["usa"] = {--USA
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e2_jumbo"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_zippo"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_satan"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4"},	
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75"},
			},
			["eng"] = {--Britain
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_ii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_iv"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_vii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_crocodile"},	
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_vi"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_a30"},
			--Tanks_heavy
			},
			["ita"] = {--Italy
			--Tanks_medium
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_ita"}
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3n_ita"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4g_ita"},
			}
		}
	},
	{--purchase 7 infantry attack 2
		waveNumber = 7,
		-- Repeat = 10,
		minRepeat = 8,
		maxRepeat = 10,
        skipPossible = false,		
		waveDuration = 25,
		Units = {
			["ger"] = {--Germany
			--Infantry Squads
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_con(ger)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular_vet_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_pz_pio_con"},
			},
			["rus"] = {--Russia
			--Infantry Squads
				{priority = 2.5, class = UnitClass.Infantry, unit = "squad_rifleunit_alt_con(rus)"},
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_rifleunit_con(rus)"},
			},
			["fra"] = {--France
			--Infantry
			-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(fra)"},
			},
			["pol"] = {--Poland
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(pol)"},
			},
			["jap"] = {--Japan
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(jap)"},
			},
			["usa"] = {--USA
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(usa)"},
			},
			["eng"] = {--Britain
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(eng)"},
			},
			["ita"] = {--Italy
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular(ita)"},
			}
		}
	},
	{--purchase 8  aa support
		waveNumber = 8,
		-- Repeat = 1,
		minRepeat = 2,
		maxRepeat = 4,
        skipPossible = false,		
		waveDuration = 3,
		Units = {
			["ger"] = {--Germany
		  	    {priority = 1.0, class = UnitClass.AATank, unit = "20mm_flak30"},
				{priority = 0.5, class = UnitClass.AATank, unit = "37mm_flak37"},
			},
			["rus"] = {--Russia
		        {priority = 0.5, class = UnitClass.AATank, unit = "25mm_72k"},
				{priority = 1.5, class = UnitClass.AATank, unit = "37mm_61k"},
			},
			["fra"] = {--France
				{priority = 1.0, class = UnitClass.ATTank, unit = "13mm_hotchkiss"},				
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1_fr"},
			},
			["pol"] = {--Poland
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf40mm_pol"},
			},
			["jap"] = {--Japan
				{priority = 1.0, class = UnitClass.ATTank, unit = "20mm_type_2"},	
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type94aa"},
			},
			["usa"] = {--USA
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m16"},											  
			},
			["eng"] = {--Britain
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf40mm"},
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa1"},
			},
			["ita"] = {--Italy
				{priority = 1.0, class = UnitClass.ATTank, unit = "2cm_solothurn"},
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
