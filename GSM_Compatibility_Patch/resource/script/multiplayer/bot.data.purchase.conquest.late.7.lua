Purchases["campaign_capture_the_flag"] = {
	{--purchase 1 starting recon wave
		divisionName = "Airborne Division",
		waveNumber = 1,
		-- Repeat = 6,
		minRepeat = 6,
		maxRepeat = 8,
		skipPossible = true,
		waveDuration = 20,
		Units = {
			["ger"] = {--Germany
				--Infantry Squads
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_fallschirmjaeger_para_con_late"},
			},
			["hun"] = {--Hungary
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_light(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_sturmtrooper(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "single_mg(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_sniper(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_mortar(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_flamer(hun)"},	
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_at(hun)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_bazooker(hun)"},
			--Automatic_weaponry
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "4cm_bofors_36m"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "4cm_40m"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "7_5cm_pak97_38_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "8cm_bofors_29m"},
			--Howitzers
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_hun"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "8cm_feldkanone"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "10cm_37m"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "10cm_feldhaubtize"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "krupp_mg"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "csaba40m"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "csaba39m"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi2_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi1"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "toldi1_rocket"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pzkpfw38t_hun"},
				{priority = 1.0, class = UnitClass.AATank, unit = "nimrod"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "turan1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan1_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan2_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan3"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3m_hun"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4f_hun"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4h_hun"},
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "pz6e_hun"},
			--SPG				
				{priority = 1.0, class = UnitClass.ATTank, unit = "marder2_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "hetzer_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_hun"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "zrinyi2"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "zrinyi1"}
			},
			["rus"] = {--Russia
			--Infantry Singles
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_rus_paras_con_late"},
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
				-- 5 
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_marine_late(fra)"},				
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(fra)"},
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
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_scout_late(pol)"},				
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(pol)"},
			},
			["jap"] = {--Japan
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_airborne_jap_con"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_snlf_jap_con"},
			},
			["usa"] = {--USA
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_airborne_usa_con"},
			},
			["eng"] = {--Britain
			--Infantry
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_airborne_eng_con"},
			},
			["ita"] = {--Italy
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_airborne_ita_con"},
			}
		}
	},
    {--purchase officer
		waveNumber = 7,
		minRepeat = 1,
		maxRepeat = 1,
        skipPossible = false,		
		waveDuration = 2,
		Units = {
			["ger"] = {--Germany
			--Tanks_medium
				{priority = 1.1, class = UnitClass.Infantry, unit = "single_officer(ger)"},
				{priority = 0.5, class = UnitClass.Infantry, unit = "squad_officer_con(ger)"},
				{priority = 0.7, class = UnitClass.Infantry, unit = "squad_officer_kubel_con"},
				{priority = 0.2, class = UnitClass.Infantry, unit = "squad_officer_250_3_con"},
			},
			["rus"] = {--Russia
			--Tanks_heavy
				{priority = 0.1, class = UnitClass.Infantry, unit = "single_officer(rus)"},
				{priority = 0.1, class = UnitClass.Infantry, unit = "squad_officer_con(rus)"},
				{priority = 0.1, class = UnitClass.Infantry, unit = "squad_officer_gaz_con"},
			},
			["hun"] = {--Hungary
			},
			["fra"] = {--France
			},
			["pol"] = {--Poland
			},
			["jap"] = {--Japan
			},
			["usa"] = {--USA
			},
			["eng"] = {--Britain
			},
			["ita"] = {--Italy
			}
		}
	},
	{--purchase 2  mortar
		waveNumber = 2,
	    -- Repeat = 2,
		minRepeat = 1,
		maxRepeat = 2,
	    skipPossible = true,
	    skipChance = 0.6,
	    waveDuration = 10,
	    isHeavyArty = true,
		Units = {
			["ger"] = {--Germany
				--Howitzers
			    {priority = 2.0, class = UnitClass.ArtilleryTank, unit = "120mm_sgrw42"},
			},
			["hun"] = {--Hungary
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_light(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_sturmtrooper(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "single_mg(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_sniper(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_mortar(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_flamer(hun)"},	
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_at(hun)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_bazooker(hun)"},
			--Automatic_weaponry
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "4cm_bofors_36m"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "4cm_40m"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "7_5cm_pak97_38_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "8cm_bofors_29m"},
			--Howitzers
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_hun"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "8cm_feldkanone"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "10cm_37m"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "10cm_feldhaubtize"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "krupp_mg"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "csaba40m"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "csaba39m"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi2_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi1"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "toldi1_rocket"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pzkpfw38t_hun"},
				{priority = 1.0, class = UnitClass.AATank, unit = "nimrod"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "turan1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan1_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan2_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan3"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3m_hun"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4f_hun"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4h_hun"},
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "pz6e_hun"},
			--SPG				
				{priority = 1.0, class = UnitClass.ATTank, unit = "marder2_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "hetzer_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_hun"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "zrinyi2"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "zrinyi1"}
			},
			["rus"] = {--Russia
			--Howitzers
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "120mm_pm38"},
			},
			["fra"] = {--France
			--Howitzers
				{priority = 0.8, class = UnitClass.ArtilleryTank, unit = "81_mm_m1_fr"},
				{priority = 0.8, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l_fr"},
			},
			["pol"] = {--Poland
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_pol"},
			},
			["jap"] = {--Japan
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_jap"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "150mm_type_96"},
			},
			["usa"] = {--USA
			--Howitzers			
                {priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81_mm_m1"},
                {priority = 1.0, class = UnitClass.ArtilleryTank, unit = "107_mm_m2"},	
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
	    -- Repeat = 6,
		minRepeat = 2,
		maxRepeat = 4,
	    skipPossible = false,
	    waveDuration = 10,
		Units = {
			["ger"] = {--Germany
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "tiger1e"},
			--Tanks_medium
				{priority = 1.5, class = UnitClass.Tank, unit = "panzer3m"},
				{priority = 1.5, class = UnitClass.Tank, unit = "panzer3n"},
				{priority = 2.0, class = UnitClass.Tank, unit = "panzer4g"},
				{priority = 2.5, class = UnitClass.Tank, unit = "panzer4h"},
				{priority = 2.0, class = UnitClass.Tank, unit = "panzer4j"},

			--Tanks_light
				{priority = 0.6, class = UnitClass.Tank, unit = "panzer2f"},
			--SPG
			},
			["hun"] = {--Hungary
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_light(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_sturmtrooper(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "single_mg(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_sniper(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_mortar(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_flamer(hun)"},	
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_at(hun)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_bazooker(hun)"},
			--Automatic_weaponry
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "4cm_bofors_36m"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "4cm_40m"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "7_5cm_pak97_38_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "8cm_bofors_29m"},
			--Howitzers
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_hun"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "8cm_feldkanone"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "10cm_37m"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "10cm_feldhaubtize"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "krupp_mg"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "csaba40m"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "csaba39m"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi2_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi1"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "toldi1_rocket"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pzkpfw38t_hun"},
				{priority = 1.0, class = UnitClass.AATank, unit = "nimrod"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "turan1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan1_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan2_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan3"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3m_hun"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4f_hun"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4h_hun"},
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "pz6e_hun"},
			--SPG				
				{priority = 1.0, class = UnitClass.ATTank, unit = "marder2_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "hetzer_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_hun"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "zrinyi2"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "zrinyi1"}
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
			},
			["fra"] = {--France
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8_fr"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75_fr"},
			},
			["pol"] = {--Poland
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_pol"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_pol"},
			--Tanks_heavy			
			},
			["jap"] = {--Japan
			--Tanks_medium
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_chi-ha"},
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_shinhoto_47mm"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type1_chi-he"},
				{priority = 2.5, class = UnitClass.Tank, unit = "type97_shinhoto_120mm"},
				{priority = 0.5, class = UnitClass.Tank, unit = "type3_chi-nu"},
			},
			["usa"] = {--USA
				{priority = 1.0, class = UnitClass.Tank, unit = "m24_chaffee"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m3lee"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4"},	
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e8"},
			},
			["eng"] = {--Britain
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_mk6"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "valentine_mkiii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4"},
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
			}
		}
	},
	{--purchase  4 Emplancement wave
		waveNumber = 4,
	    -- Repeat = 6,
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
					-- {priority = 0.5, class = UnitClass.AATank, unit = "88mm_flak36"},
				--Anti_Tank
					-- {priority = 1.0, class = UnitClass.ATTank, unit = "75mm_pak40"},
				--Infantry_Support
					{priority = 1.1, class = UnitClass.ArtilleryTank, unit = "75mm_leig18"},
					{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "150mm_sig33ai"},
			},
			["hun"] = {--Hungary
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_light(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_sturmtrooper(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "single_mg(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_sniper(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_mortar(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_flamer(hun)"},	
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_at(hun)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_bazooker(hun)"},
			--Automatic_weaponry
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "4cm_bofors_36m"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "4cm_40m"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "7_5cm_pak97_38_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "8cm_bofors_29m"},
			--Howitzers
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_hun"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "8cm_feldkanone"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "10cm_37m"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "10cm_feldhaubtize"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "krupp_mg"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "csaba40m"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "csaba39m"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi2_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi1"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "toldi1_rocket"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pzkpfw38t_hun"},
				{priority = 1.0, class = UnitClass.AATank, unit = "nimrod"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "turan1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan1_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan2_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan3"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3m_hun"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4f_hun"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4h_hun"},
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "pz6e_hun"},
			--SPG				
				{priority = 1.0, class = UnitClass.ATTank, unit = "marder2_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "hetzer_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_hun"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "zrinyi2"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "zrinyi1"}
			},
			["rus"] = {--Russia
	           --HMGs
					{priority = 1.0, class = UnitClass.Vehicle, unit = "dshk_aa"},
				--Anti_Aircraft
					{priority = 0.8, class = UnitClass.AATank, unit = "37mm_61k"},
					-- {priority = 0.8, class = UnitClass.AATank, unit = "85mm_52k"},
				--Anti_Tank
					-- {priority = 1.0, class = UnitClass.ATTank, unit = "57mm_zis2"},
					{priority = 0.4, class = UnitClass.ATTank, unit = "100mm_bs3"},
				--Infantry_Support
					{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "76mm_m43"},
			},
			["fra"] = {--France
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1919a4_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb_fr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1_fr"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "57_mm_m1_fr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1897a4_fr"},
			},
			["pol"] = {--Poland
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_bren_pol"},	
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "20mm_fka"},			
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf6pdr_pol"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf17pdr_pol"},
			},
			["jap"] = {--Japan
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type92_stan"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "20mm_type_2"},	
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_88"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_90"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_type_41"},
			--Howitzers
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "105mm_type_92"},
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "120mm_type_38"},
			},
			["usa"] = {--USA
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_3cal_m1917a1_aa"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "0_5cal_m2hb"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "40_mm_m1"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "75_mm_m1897a4"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "76_mm_m5late"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "90_mm_m1"},
			},
			["eng"] = {--Britain
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_vickers_mki"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "303_bren"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf40mm"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf6pdr"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "qf17pdr"},
			},
			["ita"] = {--Italy
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.Vehicle, unit = "8mm_breda_37"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "2cm_solothurn"},
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_4732"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "cannone_7527"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "obice_7513"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "7_5cm_pak97_38"},
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
				-- {priority = 1.5, class = UnitClass.Infantry, unit = "squad_fallschirmjaeger_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_blau_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_brandenburger_con(ger)"},
			},
			["hun"] = {--Hungary
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_light(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_sturmtrooper(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "single_mg(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_sniper(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_mortar(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_flamer(hun)"},	
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_at(hun)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_bazooker(hun)"},
			--Automatic_weaponry
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "4cm_bofors_36m"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "4cm_40m"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "7_5cm_pak97_38_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "8cm_bofors_29m"},
			--Howitzers
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_hun"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "8cm_feldkanone"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "10cm_37m"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "10cm_feldhaubtize"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "krupp_mg"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "csaba40m"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "csaba39m"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi2_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi1"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "toldi1_rocket"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pzkpfw38t_hun"},
				{priority = 1.0, class = UnitClass.AATank, unit = "nimrod"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "turan1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan1_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan2_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan3"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3m_hun"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4f_hun"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4h_hun"},
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "pz6e_hun"},
			--SPG				
				{priority = 1.0, class = UnitClass.ATTank, unit = "marder2_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "hetzer_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_hun"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "zrinyi2"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "zrinyi1"}
			},
			["rus"] = {--Russia
			--Infantry Squads
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_mountainrifles_con(rus)"},

				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_guards_smg_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_flame_con(rus)"},

				-- {priority = 1.0, class = UnitClass.Infantry, unit = "squad_paras_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_spetsnaz(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_marines_con(rus)"},
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
								-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(fra)"},
			},
			["pol"] = {--Poland
			--Infantry
				-- 1
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(pol)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(pol)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(pol)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(pol)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(pol)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_scout_late(pol)"},				
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(pol)"},
				-- 6
			},
			["jap"] = {--Japan
			--Infantry
				-- 1
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(jap)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(jap)"},
				-- 3
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(jap)"},
			},
			["usa"] = {--USA
			--Infantry
				-- 1
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
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(eng)"},
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
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular(ita)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(ita)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_mg(ita)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(ita)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_flamer(ita)"},
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
		     		{priority = 1.5, class = UnitClass.ATTank, unit = "stug3g_late"},
					{priority = 1.5, class = UnitClass.ATTank, unit = "hetzer"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sturmpanzer4"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "marder3m"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "stuh42"},
			},
			["hun"] = {--Hungary
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_light(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_sturmtrooper(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "single_mg(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_sniper(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_mortar(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_flamer(hun)"},	
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_at(hun)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_bazooker(hun)"},
			--Automatic_weaponry
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "4cm_bofors_36m"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "4cm_40m"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "7_5cm_pak97_38_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "8cm_bofors_29m"},
			--Howitzers
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_hun"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "8cm_feldkanone"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "10cm_37m"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "10cm_feldhaubtize"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "krupp_mg"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "csaba40m"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "csaba39m"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi2_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi1"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "toldi1_rocket"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pzkpfw38t_hun"},
				{priority = 1.0, class = UnitClass.AATank, unit = "nimrod"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "turan1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan1_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan2_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan3"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3m_hun"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4f_hun"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4h_hun"},
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "pz6e_hun"},
			--SPG				
				{priority = 1.0, class = UnitClass.ATTank, unit = "marder2_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "hetzer_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_hun"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "zrinyi2"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "zrinyi1"}
			},
			["rus"] = {--Russia
			--SPG
				{priority = 2.5, class = UnitClass.ATTank, unit = "su85"},
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "su122"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "isu152"},
			},
			["fra"] = {--France
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine_fr"},
				{priority = 0.7, class = UnitClass.ArtilleryTank, unit = "m7_fr"},
				{priority = 0.6, class = UnitClass.ArtilleryTank, unit = "m4a3_105_fr"},
			},
			["pol"] = {--Poland
			--SPG
				{priority = 0.5, class = UnitClass.ATTank, unit = "achilles_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton_pol"},
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "m4a3_105_pol"},
			},
			["jap"] = {--Japan
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "type1_ho-ni1"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "type1_ho-ni2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "type4_ho-ro"},
			--Tanks_heavy
			},
			["usa"] = {--USA
			--SPG
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t12gmc"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m36"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m18"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "t30hmc"},
			},
			["eng"] = {--Britain			
			--SPG
				{priority = 0.4, class = UnitClass.ATTank, unit = "achilles"},
				{priority = 0.4, class = UnitClass.ATTank, unit = "m4a3_105_eng"},
			},
			["ita"] = {--Italy			
			--SPG
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7518"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m7534"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_ita"},
			}
		}
	},
	{--purchase 7 Tank 2
		waveNumber = 7,
		-- Repeat = 5,
		minRepeat = 2,
		maxRepeat = 6,
        skipPossible = false,		
		waveDuration = 15,
		Units = {
			["ger"] = {--Germany
				{priority = 0.8, class = UnitClass.HeavyTank, unit = "tiger1e"},
			--Tanks_medium
				{priority = 2.5, class = UnitClass.Tank, unit = "panzer3m"},
				{priority = 1.5, class = UnitClass.Tank, unit = "panzer4h"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4j"},
			--Tanks_light
				{priority = 0.9, class = UnitClass.Tank, unit = "panzer2f"},
			--SPG
			},
			["hun"] = {--Hungary
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_light(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_sturmtrooper(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "single_mg(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_sniper(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_mortar(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_flamer(hun)"},	
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_at(hun)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_bazooker(hun)"},
			--Automatic_weaponry
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "4cm_bofors_36m"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "4cm_40m"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "7_5cm_pak97_38_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "8cm_bofors_29m"},
			--Howitzers
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_hun"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "8cm_feldkanone"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "10cm_37m"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "10cm_feldhaubtize"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "krupp_mg"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "csaba40m"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "csaba39m"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi2_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi1"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "toldi1_rocket"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pzkpfw38t_hun"},
				{priority = 1.0, class = UnitClass.AATank, unit = "nimrod"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "turan1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan1_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan2_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan3"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3m_hun"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4f_hun"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4h_hun"},
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "pz6e_hun"},
			--SPG				
				{priority = 1.0, class = UnitClass.ATTank, unit = "marder2_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "hetzer_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_hun"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "zrinyi2"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "zrinyi1"}
			},
			["rus"] = {--Russia
            --Tanks_medium
				{priority = 3.5, class = UnitClass.Tank, unit = "t3476_42"},
				{priority = 3.5, class = UnitClass.Tank, unit = "t3476_43"},
			--Tanks_light
				{priority = 3.0, class = UnitClass.Tank, unit = "t70m"},
				{priority = 2.0, class = UnitClass.Tank, unit = "t60"},
				{priority = 1.0, class = UnitClass.Tank, unit = "bt7"},
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
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_pol"},
			},
			["jap"] = {--Japan
			--Tanks_medium
				{priority = 2.0, class = UnitClass.Tank, unit = "type1_chi-he"},
				{priority = 2.5, class = UnitClass.Tank, unit = "type97_shinhoto_120mm"},
				{priority = 0.5, class = UnitClass.Tank, unit = "type3_chi-nu"},
				{priority = 1.0, class = UnitClass.Tank, unit = "type2_ho-i"},
				{priority = 1.0, class = UnitClass.Tank, unit = "type2_ho-i_kou"},				
			},
			["usa"] = {--USA
		--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m22"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m4"},	
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e2_jumbo"},
			},
			["eng"] = {--Britain
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_a30"},
			--Tanks_heavy
				{priority = 0.2, class = UnitClass.Tank, unit = "churchill_avre"},
			},
			["ita"] = {--Italy
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3n_ita"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4g_ita"},
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
				-- {priority = 1.5, class = UnitClass.Infantry, unit = "squad_fallschirmjaeger_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_blau_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_brandenburger_con(ger)"},
			},
			["hun"] = {--Hungary
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_light(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_sturmtrooper(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "single_mg(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_sniper(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_mortar(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_flamer(hun)"},	
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_at(hun)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_bazooker(hun)"},
			--Automatic_weaponry
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "4cm_bofors_36m"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "4cm_40m"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "7_5cm_pak97_38_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "8cm_bofors_29m"},
			--Howitzers
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_hun"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "8cm_feldkanone"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "10cm_37m"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "10cm_feldhaubtize"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "krupp_mg"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "csaba40m"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "csaba39m"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi2_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi1"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "toldi1_rocket"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pzkpfw38t_hun"},
				{priority = 1.0, class = UnitClass.AATank, unit = "nimrod"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "turan1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan1_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan2_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan3"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3m_hun"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4f_hun"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4h_hun"},
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "pz6e_hun"},
			--SPG				
				{priority = 1.0, class = UnitClass.ATTank, unit = "marder2_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "hetzer_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_hun"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "zrinyi2"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "zrinyi1"}
			},
			["rus"] = {--Russia
			--Infantry Squads
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_mountainrifles_con(rus)"},

				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_guards_smg_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_flame_con(rus)"},

				-- {priority = 1.0, class = UnitClass.Infantry, unit = "squad_paras_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_spetsnaz(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_marines_con(rus)"},
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
								-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
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
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(pol)"},
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
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(jap)"},
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
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(ita)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_mg(ita)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(ita)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_flamer(ita)"},
			}
		}
	},
	{--purchase 9 rocket arty
		waveNumber = 9,
		-- Repeat = 2,
		minRepeat = 1,
		maxRepeat = 2,
        skipPossible = true,
	    skipChance = 0.65,		
		waveDuration = 5,
		isHeavyArty = true,
		Units = {
			["ger"] = {--Germany
		        {priority = 1.0, class = UnitClass.ArtilleryTank, unit = "300mm_nebelwerfer42ai", isHeavyArty = true},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "150mm_nebelwerfer41ai"},
			},
			["hun"] = {--Hungary
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_light(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_sturmtrooper(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "single_mg(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_sniper(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_mortar(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_flamer(hun)"},	
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_at(hun)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_bazooker(hun)"},
			--Automatic_weaponry
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "4cm_bofors_36m"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "4cm_40m"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "7_5cm_pak97_38_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "8cm_bofors_29m"},
			--Howitzers
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_hun"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "8cm_feldkanone"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "10cm_37m"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "10cm_feldhaubtize"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "krupp_mg"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "csaba40m"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "csaba39m"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi2_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi1"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "toldi1_rocket"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pzkpfw38t_hun"},
				{priority = 1.0, class = UnitClass.AATank, unit = "nimrod"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "turan1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan1_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan2_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan3"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3m_hun"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4f_hun"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4h_hun"},
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "pz6e_hun"},
			--SPG				
				{priority = 1.0, class = UnitClass.ATTank, unit = "marder2_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "hetzer_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_hun"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "zrinyi2"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "zrinyi1"}
			},
			["rus"] = {--Russia
				{priority = 11.0, class = UnitClass.ArtilleryTank, unit = "bm31_12ai", isHeavyArty = true},
			},
			["fra"] = {--France
			--Howitzers
				{priority = 0.8, class = UnitClass.ArtilleryTank, unit = "75_mm_m1897a4_fr"},
				{priority = 0.8, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l_fr"},
				{priority = 0.8, class = UnitClass.ArtilleryTank, unit = "155_mm_m1918"},
			},
			["pol"] = {--Poland
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155mm_wz1917"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105mm_wz29"},
			},
			["jap"] = {--Japan
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "200mm_type_4"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "toyota_rocket"},
			--Tanks_heavy
			},
			["usa"] = {--USA
			--Howitzers			
                {priority = 1.0, class = UnitClass.ArtilleryTank, unit = "203_mm_m115"},	
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "m4a3c"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "cckw353_2xt27"},
	
			},
			["eng"] = {--Britain
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "land_mattress"},
			},
			["ita"] = {--Italy		
			--SPG
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "obice_210"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "obice_10017"},
			
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
			["hun"] = {--Hungary
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_light(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_sturmtrooper(hun)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "single_mg(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_sniper(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_mortar(hun)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_flamer(hun)"},	
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_at(hun)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_bazooker(hun)"},
			--Automatic_weaponry
			--AT_Weapons
				{priority = 1.0, class = UnitClass.ATTank, unit = "4cm_bofors_36m"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "4cm_40m"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "7_5cm_pak97_38_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "8cm_bofors_29m"},
			--Howitzers
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_hun"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "8cm_feldkanone"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "10cm_37m"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "10cm_feldhaubtize"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "krupp_mg"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "csaba40m"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "csaba39m"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi2_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "toldi1"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "toldi1_rocket"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pzkpfw38t_hun"},
				{priority = 1.0, class = UnitClass.AATank, unit = "nimrod"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "turan1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan1_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan2_late"},
				{priority = 1.0, class = UnitClass.Tank, unit = "turan3"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3m_hun"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4f_hun"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4h_hun"},
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "pz6e_hun"},
			--SPG				
				{priority = 1.0, class = UnitClass.ATTank, unit = "marder2_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "hetzer_hun"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_hun"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "zrinyi2"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "zrinyi1"}
			},
			["rus"] = {--Russia
            --Tanks_light			
				{priority = 3.0, class = UnitClass.Tank, unit = "t70m"},
				{priority = 2.0, class = UnitClass.Tank, unit = "t60"},
				{priority = 1.0, class = UnitClass.Tank, unit = "bt7"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "gaz_aaa_72k"},
			},
			["fra"] = {--France
			
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "panhard"},	
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m4halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m17_fr"},	
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8_fr"},
			},
			["pol"] = {--Poland
	
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound_pol"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_pol"},
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
			--Tanks_medium
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_chi-ha"},
			},
			["usa"] = {--USA
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
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_satan"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8"},
			},
			["eng"] = {--Britain
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2"},
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa1"},
			},
			["ita"] = {--Italy
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
