Purchases["campaign_capture_the_flag"] = {
	{--purchase 1 starting recon wave c 1 по 5 бой GENERIC DIVISION
		divisionName = "Generic division",
		waveNumber = 1, -- какая по порядку будет
		minRepeat = 2,
		maxRepeat = 4,
		skipPossible = false,  -- ничего не делает
		waveDuration = 20, -- длительность того, как долго бот будет вызывать данные войска. Каждый юнит вызывается каждые 3 секунды. Если нужно чтобы было только определенное количество то Repeat * 3 < Wave duration  При этом Repeat говорит сколько раз нужно вызвать юнит.
		Units = {
			["ger"] = {--Germany
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "kubelwagen_mg"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz221"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz231"},
			--Infantry Squads
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_recon_con(ger)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_recon_armor_con"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_sicherung_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_regular_con(ger)"},
			},
			["rus"] = {--Russia
			--Infantry Singles
			    {priority = 2.5, class = UnitClass.Infantry, unit = "squad_recon_con(rus)"},
		        {priority = 1.0, class = UnitClass.Infantry, unit = "squad_border(rus)"},
			--Wheel_vehicles
				{priority = 1.5, class = UnitClass.Vehicle, unit = "gaz67b"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ba6"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "ba20"},
			},
			["fra"] = {--France
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(fra)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade_late(fra)"},
				-- 3
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(fra)"},
				-- 4
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_marine_late(fra)"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_fr"},
			},
			["pol"] = {--Poland
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(pol)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(pol)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(pol)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(pol)"},
				-- 3
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(pol)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "wz34"},
			},
			["jap"] = {--Japan
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(jap)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(jap)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(jap)"},
				-- 4
			--Wheel_vehicles
				{priority = 2.5, class = UnitClass.Vehicle, unit = "type93"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type94aa"},
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
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_marine(usa)"},	
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willysmb"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20"},
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
				-- 4
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "squad_scout_late(eng)"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_eng"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "humber"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "mk2daimler"},
			},
			["ita"] = {--Italy
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_light(ita)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular(ita)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_mg(ita)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(ita)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_flamer(ita)"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ab41"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "autocannone10017"},
			}
		}
	},
	{--purchase 2 mortar
		waveNumber = 2,
	    minRepeat = 1,
		maxRepeat = 1,
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
				{priority = 0.8, class = UnitClass.ArtilleryTank, unit = "81_mm_m1_fr"},
			},
			["pol"] = {--Poland
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_pol"},
			},
			["jap"] = {--Japan
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_jap"},
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
	{--purchase 3 tank assault group
		waveNumber = 3,
	    minRepeat = 2,
		maxRepeat = 5,
	    skipPossible = false,
	    waveDuration = 20,
		Units = {
			["ger"] = {--Germany
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer3e"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer3f"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer3j"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4d"},
				{priority = 0.1, class = UnitClass.Tank, unit = "panzer4f1"},
			--Tanks_light
				{priority = 0.5, class = UnitClass.Tank, unit = "panzer1b"},
				{priority = 2.5, class = UnitClass.Tank, unit = "panzer2c"},
				{priority = 0.6, class = UnitClass.Tank, unit = "panzer2f"},
				{priority = 0.7, class = UnitClass.Tank, unit = "panzer35t"},
				{priority = 2.2, class = UnitClass.Tank, unit = "pz38t_a"},
				{priority = 1.2, class = UnitClass.Tank, unit = "pz38t_f"},
			},
			["rus"] = {--Russia
			--Tanks_heavy
				{priority = 0.1, class = UnitClass.HeavyTank, unit = "kv1_40"},
		    --Tanks_medium
				{priority = 0.5, class = UnitClass.Tank, unit = "t28"},
				{priority = 1.5, class = UnitClass.Tank, unit = "bt5"},
			--Tanks_light
			   	{priority = 2.0, class = UnitClass.Tank, unit = "t26_33"},
				{priority = 2.0, class = UnitClass.Tank, unit = "t26_39"},
				{priority = 0.5, class = UnitClass.Tank, unit = "t3476_40"},
				{priority = 0.5, class = UnitClass.Tank, unit = "t3476_41"},
		    },
			["fra"] = {--France
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "amr35-13mm"},
				{priority = 1.0, class = UnitClass.Tank, unit = "amr35-25mm"},
				{priority = 1.0, class = UnitClass.Tank, unit = "r35"},
				{priority = 1.0, class = UnitClass.Tank, unit = "r39"},
				{priority = 1.0, class = UnitClass.Tank, unit = "char_d2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "s35"},
			--Tanks_heavy	
				{priority = 1.0, class = UnitClass.Tank, unit = "b1bis"},
			},
			["pol"] = {--Poland
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "7tp"},
				{priority = 1.0, class = UnitClass.Tank, unit = "r35_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "vickersedw"},
				{priority = 1.0, class = UnitClass.Tank, unit = "vickersejw"},
				{priority = 0.3, class = UnitClass.Tank, unit = "crusader_pol"},
			--Tanks_medium
			},
			["jap"] = {--Japan
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "type94_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type97_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type95_ha-go"},
			--Tanks_medium
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_chi-ha"},
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_shinhoto_47mm"},
			},
			["usa"] = {--USA
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m22"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_stuart"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_satan"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m3lee"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4"},	
			},
			["eng"] = {--Britain
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_mk6"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "valentine_mkiii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "matilda_mkii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv"},
			},
			["ita"] = {--Italy
			--Tanks_light
				{priority = 1.0, class = UnitClass.Vehicle, unit = "cv35"},
				{priority = 1.0, class = UnitClass.Tank, unit = "l640"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1441"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1542"},
			}
		}
	},
	{--purchase 4 field gun support
		waveNumber = 4,
	    minRepeat = 2,
		maxRepeat = 4,
	    skipPossible = false,
	    waveDuration = 5,
		Units = {
			["ger"] = {--Germany
				--HMGs
				{priority = 1.5, class = UnitClass.Vehicle, unit = "mg34_lafette"},
				--Anti_Tank
				{priority = 1.5, class = UnitClass.ATTank, unit = "37mm_pak36"},
				{priority = 0.5, class = UnitClass.ATTank, unit = "47mm_pakt"},
			 },
			["rus"] = {--Russia
				--HMGs
				{priority = 1.5, class = UnitClass.Vehicle, unit = "maxim"},
				--Anti_Tank
				{priority = 1.5, class = UnitClass.ATTank, unit = "45mm_m37"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "45mm_m42"},
			},
			["fra"] = {--France
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1919a4_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb_fr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1_fr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "13mm_hotchkiss"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "25mm_hotchkiss_mle34"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "47mm_puteaux_mle37"},

			},
			["pol"] = {--Poland
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ckm_wz30_mgun"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "37mm_bofors"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "20mm_fka"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf2pdr_pol"},
			},
			["jap"] = {--Japan
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type92_stan"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "20mm_type_2"},	
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "37mm_type_94"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_88"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_90"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_41"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "47mm_type_1"},
			},
			["usa"] = {--USA
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1917a1_aa"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_maxson"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "37_mm_m3"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1897a4"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "76_mm_m5"},
			},
			["eng"] = {--Britain
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_vickers_mki"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_bren"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf2pdr"},
			},
			["ita"] = {--Italy
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "8mm_fiat_revelli_m1914_35"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "8mm_breda_37"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_2065"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "2cm_solothurn"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_4732"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_7527"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "obice_7513"},
			}
		}
	},
	{--purchase 5 infantry support
		waveNumber = 5,
		minRepeat = 3,
		maxRepeat = 4,
        skipPossible = false,		
		waveDuration = 25,
		Units = {
			["ger"] = {--Germany
			--Infantry Squads
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_osttruppen_con(ger)"},
				{priority = 0.75, class = UnitClass.Infantry, unit = "squad_strafbatallion_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_luftwaffe_con(ger)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_sicherung_con(ger)"},
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_con(ger)"},
					{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(ger)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(ger)"},	
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular_vet_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_blau_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_pionier_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_pz_pio_con"},
			},
			["rus"] = {--Russia
			--Infantry Squads
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_partisan_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_penal_con(rus)"},

				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_border(rus)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_conscripts_con(rus)"},
				{priority = 2.5, class = UnitClass.Infantry, unit = "squad_rifleunit_alt_con(rus)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(rus)"},
				{priority = 1.5, class = UnitClass.ATInfantry, unit = "single_riflegrenade(rus)"},
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_rifleunit_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_mountainrifles_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_guards_smg_con(rus)"},
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
			},
			["ita"] = {--Italy
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_light(ita)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular(ita)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_mg(ita)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(ita)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_flamer(ita)"},
			}
		}
	},
	{--purchase 6 SPG support
		waveNumber = 6,
		minRepeat = 1,
		maxRepeat = 1,
        skipPossible = false,		
		waveDuration = 5,
		Units = {
			["ger"] = {--Germany
			--SPG
				{priority = 0.5, class = UnitClass.ATTank, unit = "panzerjager1"},
				{priority = 1.5, class = UnitClass.ATTank, unit = "stug3b"},
			},
			["rus"] = {--Russia
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "zis30"},
			},
			["fra"] = {--France
			--SPG
				{priority = 0.7, class = UnitClass.ArtilleryTank, unit = "bs-75"}
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "autocanon_75mm"}
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "laffly15tcc"}
			},
			["pol"] = {--Poland			
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "pf621_75mm"},
			},
			["jap"] = {--Japan
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "type1_ho-ni1"},
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "type1_ho-ni2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "type4_ho-ro"}
			--Tanks_heavy
			},
			["usa"] = {--USA
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t30hmc"},
			--SPG
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t12gmc"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7"}
			},
			["eng"] = {--Britain			
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "achilles"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton"}
			},
			["ita"] = {--Italy		
			--SPG
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7518"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m7534"},
			}
		}
	},
	{--purchase 7 Tank 2
		waveNumber = 7,
		minRepeat = 2,
		maxRepeat = 3,
        skipPossible = false,		
		waveDuration = 20,
		Units = {
			["ger"] = {--Germany
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer3e"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer3f"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer3j"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4d"},
				{priority = 0.1, class = UnitClass.Tank, unit = "panzer4f1"},
			--Tanks_light
				{priority = 0.5, class = UnitClass.Tank, unit = "panzer1b"},
				{priority = 2.5, class = UnitClass.Tank, unit = "panzer2c"},
				{priority = 0.6, class = UnitClass.Tank, unit = "panzer2f"},
				{priority = 0.7, class = UnitClass.Tank, unit = "panzer35t"},
				{priority = 2.2, class = UnitClass.Tank, unit = "pz38t_a"},
				{priority = 1.2, class = UnitClass.Tank, unit = "pz38t_f"},
			},
			["rus"] = {--Russia
			--Tanks_heavy
				{priority = 0.1, class = UnitClass.HeavyTank, unit = "kv1_40"},
		    --Tanks_medium
				{priority = 0.5, class = UnitClass.Tank, unit = "t28"},
				{priority = 1.5, class = UnitClass.Tank, unit = "bt5"},
			--Tanks_light
			   	{priority = 2.0, class = UnitClass.Tank, unit = "t26_33"},
				{priority = 2.0, class = UnitClass.Tank, unit = "t26_39"},
					{priority = 0.5, class = UnitClass.Tank, unit = "t3476_40"},
				{priority = 0.5, class = UnitClass.Tank, unit = "t3476_41"},
		    },
			["fra"] = {--France
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "r35"},
				{priority = 1.0, class = UnitClass.Tank, unit = "r39"},
				{priority = 1.0, class = UnitClass.Tank, unit = "char_d2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "s35"},
			--Tanks_heavy	
				{priority = 1.0, class = UnitClass.Tank, unit = "b1bis"},
			},
			["pol"] = {--Poland
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_pol"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "7tp"},
				{priority = 1.0, class = UnitClass.Tank, unit = "r35_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "tks-20mm"},
				{priority = 1.0, class = UnitClass.Tank, unit = "vickersejw"},
			},
			["jap"] = {--Japan
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "type94_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type97_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type95_ha-go"},
			--Tanks_medium
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_chi-ha"},
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_shinhoto_47mm"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type1_chi-he"},
			},
			["usa"] = {--USA
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m22"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_stuart"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_satan"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m3lee"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4"},	
			},
			["eng"] = {--Britain
			--Tanks_light
				{priority = 1.0, class = UnitClass.Vehicle, unit = "cv35"},
				{priority = 1.0, class = UnitClass.Tank, unit = "l640"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1441"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1542"},
			}
		}
	},
	{--purchase 8 infantry attack 2
		waveNumber = 8,
		minRepeat = 3,
		maxRepeat = 4,
        skipPossible = false,		
		waveDuration = 30,
		Units = {
			["ger"] = {--Germany
			--Infantry Squads
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_osttruppen_con(ger)"},
				{priority = 0.75, class = UnitClass.Infantry, unit = "squad_strafbatallion_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_luftwaffe_con(ger)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_sicherung_con(ger)"},
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_con(ger)"},
					{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(ger)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(ger)"},	
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular_vet_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_blau_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_pionier_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_pz_pio_con"},
			},
			["rus"] = {--Russia
			--Infantry Squads
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_partisan_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_penal_con(rus)"},

				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_border(rus)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_conscripts_con(rus)"},
				{priority = 2.5, class = UnitClass.Infantry, unit = "squad_rifleunit_alt_con(rus)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(rus)"},
				{priority = 1.5, class = UnitClass.ATInfantry, unit = "single_riflegrenade(rus)"},
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_rifleunit_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_mountainrifles_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_guards_smg_con(rus)"},
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
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_marine_late(fra)"},
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
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_marine(usa)"},
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
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "squad_scout_late(eng)"},
			},
			["ita"] = {--Italy
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_light(ita)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular(ita)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_mg(ita)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(ita)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_flamer(ita)"},
			}
		}
	},
	{--purchase 9 light tank rush
		waveNumber = 9,
		minRepeat = 2,
		maxRepeat = 4,
        skipPossible = false,		
		waveDuration = 10,
		Units = {
			["ger"] = {--Germany
			--Wheel_vehicles
			{priority = 0.7, class = UnitClass.Tank, unit = "panzer1b"},
				{priority = 2.0, class = UnitClass.Tank, unit = "panzer2c"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer2f"},
				{priority = 0.5, class = UnitClass.Tank, unit = "panzer35t"},
				{priority = 2.5, class = UnitClass.Tank, unit = "pz38t_a"},
				{priority = 0.5, class = UnitClass.Tank, unit = "pz38t_f"},
			},
			["rus"] = {--Russia
            --Tanks_light			
			   {priority = 0.5, class = UnitClass.Tank, unit = "t26_31"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t26_33"},
				{priority = 2.0, class = UnitClass.Tank, unit = "t26_39"},
				{priority = 2.0, class = UnitClass.Tank, unit = "t37a"},
				{priority = 0.1, class = UnitClass.Tank, unit = "bt2"},
				{priority = 2.5, class = UnitClass.Tank, unit = "bt5"},
				{priority = 0.5, class = UnitClass.Tank, unit = "t40"},
				{priority = 3.0, class = UnitClass.Tank, unit = "t60"},
			},
			["fra"] = {--France
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m17_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "laffly_s15_toe"},
				{priority = 1.0, class = UnitClass.Tank, unit = "laffly_v15t_mg"},	
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "amr35-13mm"},
				{priority = 1.0, class = UnitClass.Tank, unit = "amr35-25mm"},
			},
			["pol"] = {--Poland
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "vickersedw"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "tks-mg"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound_pol"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "wz34"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv_pol"},
			},
			["jap"] = {--Japan
			--Wheel_vehicles
				{priority = 2.5, class = UnitClass.Vehicle, unit = "type93"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type94aa"},
			--Half_tracks
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "type94_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type97_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type95_ha-go"},
			},
			["usa"] = {--USA
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willysmb"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willys50"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m16"},											  
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t30hmc"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m22"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_stuart"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_satan"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8"},
			},
			["eng"] = {--Britain
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_eng"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "humber"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "mk2daimler"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_mk6"},
			},
			["ita"] = {--Italy
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ab41"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "autocannone10017"},
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
