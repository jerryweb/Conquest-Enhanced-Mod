Purchases["campaign_capture_the_flag"] = {
	{--purchase 3 heavy tank group
		divisionName = "Condor Mid Tank Division",
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
			--Tanks_heavy
			    {priority = 0.4, class = UnitClass.HeavyTank, unit = "kv1_40"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "kv1_41"},
				{priority = 0.1, class = UnitClass.HeavyTank, unit = "kv2_40"},
			},
			["fra"] = {--France				
			--Tanks_medium			
				{priority = 1.0, class = UnitClass.Tank, unit = "s35"},			
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75_fr"},
				{priority = 0.3, class = UnitClass.Tank, unit = "m4a3_76_fr"},
			--Tanks_heavy	
				{priority = 1.0, class = UnitClass.Tank, unit = "b1bis"},										
			},
			["pol"] = {--Poland								
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_pol"},
				{priority = 0.4, class = UnitClass.Tank, unit = "m4a4_firefly_pol"},
			},
			["jap"] = {--Japan
			--Tanks_medium
				{priority = 2.0, class = UnitClass.Tank, unit = "type1_chi-he"},
				{priority = 1.0, class = UnitClass.Tank, unit = "type3_chi-nu"},
				{priority = 1.0, class = UnitClass.Tank, unit = "type3_chi-nu2"},
			},
			["usa"] = {--USA
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e2_jumbo"},
			},
			["eng"] = {--Britain
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_ii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_iv"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_crocodile"},			
			},
			["ita"] = {--Italy
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3n_ita"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4g_ita"},
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
				{priority = 0.7, class = UnitClass.Tank, unit = "t3476_41"},				
				{priority = 0.7, class = UnitClass.Tank, unit = "t3476_42"},
				{priority = 0.1, class = UnitClass.Tank, unit = "t3457_41"},
				{priority = 0.1, class = UnitClass.Tank, unit = "t3476_40"},
			--Tanks_heavy
			},
			["fra"] = {--France				
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "r35"},
				{priority = 1.0, class = UnitClass.Tank, unit = "r39"},
				{priority = 1.0, class = UnitClass.Tank, unit = "h39"},				
				{priority = 1.0, class = UnitClass.Tank, unit = "s35"},			
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75_fr"},							
			},
			["pol"] = {--Poland									
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_pol"},
			},
			["jap"] = {--Japan
			--Tanks_medium
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_chi-ha"},
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_shinhoto_47mm"},
				{priority = 1.0, class = UnitClass.Tank, unit = "type2_ho-i"},
				{priority = 1.0, class = UnitClass.Tank, unit = "type2_ho-i_kou"},								
			},
			["usa"] = {--USA
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m3lee"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4"},	
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75"},
			},
			["eng"] = {--Britain
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "valentine_mkiii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "matilda_mkii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_vi"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_a30"},
				{priority = 1.0, class = UnitClass.Tank, unit = "comet_a34"},
			},
			["ita"] = {--Italy
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3n_ita"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4g_ita"},
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
				{priority = 1.0, class = UnitClass.Tank, unit = "t60"},			
			},
			["fra"] = {--France												
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "amr35-13mm"},
				{priority = 1.0, class = UnitClass.Tank, unit = "amr35-25mm"},				
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "r35"},
				{priority = 1.0, class = UnitClass.Tank, unit = "r39"},
				{priority = 1.0, class = UnitClass.Tank, unit = "h39"},											
			},
			["pol"] = {--Poland							
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "7tp"},
				{priority = 1.0, class = UnitClass.Tank, unit = "r35_pol"},
			},
			["jap"] = {--Japan
			--Tanks_light
				{priority = 2.0, class = UnitClass.Tank, unit = "type95_ha-go"},
			},
			["usa"] = {--USA
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_stuart"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m24_chaffee"},
			},
			["eng"] = {--Britain
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa1"},
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2"},
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_mki"},
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_mki_cs"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_mk6"},
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
				{priority = 2.5, class = UnitClass.Infantry, unit = "squad_rifleunit_alt_con(rus)"},
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_rifleunit_con(rus)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_at(rus)"},
			},
			["fra"] = {--France
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mg_late(fra)"},				
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade_late(fra)"},
				-- 3
				-- 5
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_marine_late(fra)"},				
			},
			["pol"] = {--Poland
			--Infantry
				-- 1
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(pol)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_mg_late(pol)"},				
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(pol)"},
				-- 4
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_scout_late(pol)"},												
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

			},
			["usa"] = {--USA
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(usa)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(usa)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(usa)"},

			},
			["eng"] = {--Britain
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(eng)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(eng)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_mg_late(eng)"},				
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_scout_late(eng)"},			
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
