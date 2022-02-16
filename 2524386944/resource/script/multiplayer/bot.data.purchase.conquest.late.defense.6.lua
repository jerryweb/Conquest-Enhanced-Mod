Purchases["campaign_capture_the_flag"] = {
	{--purchase 1  arty
		divisionName = "Arty Noob division",
		waveNumber = 1,
		-- Repeat = 2,
		minRepeat = 1,
		maxRepeat = 3,
        skipPossible = false,		
		waveDuration = 5,
		isHeavyArty = true,
		Units = {
			["ger"] = {--Germany
		        {priority = 1.0, class = UnitClass.ArtilleryTank, unit = "300mm_nebelwerfer42", isHeavyArty = true},
		        {priority = 0.5, class = UnitClass.ATTank, unit = "210mm_morser18", isHeavyArty = true},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "150mm_sfh18", isHeavyArty = true},
			},
			["rus"] = {--Russia
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bm31_12", isHeavyArty = true},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "152mm_ml20", isHeavyArty = true},
				{priority = 0.5, class = UnitClass.ATTank, unit = "203mm_b4", isHeavyArty = true},
			},
			["fra"] = {--France
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l_fr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m1918"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "22cm_mortier"},
			},
			["pol"] = {--Poland
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105mm_wz29"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155mm_wz1917"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45_pol"},
			},
			["jap"] = {--Japan
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "200mm_type_4"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "150mm_type_96"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "toyota_rocket"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "type4_ha-to"},
			},
			["usa"] = {--USA
			--Howitzers			
                {priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "203_mm_m115"},	
		    --Wheel_vehicles
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "cckw353_2xt27"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3c"},	
			},
			["eng"] = {--Britain
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl72"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "land_mattress"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a4_tulip"}			
			},
			["ita"] = {--Italy
			--Howitzers	
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "obice_210"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "obice_10017"},								
			}	
		}
	},
	{--purchase 2 starting recon wave
		waveNumber = 2,
		-- Repeat = 6,
		minRepeat = 3,
		maxRepeat = 6,
		skipPossible = false,
		waveDuration = 20,
		Units = {
			["ger"] = {--Germany
				--Infantry Squads
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_recon_con(ger)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_recon_armor_con"},
			--Wheel_vehicles
				{priority = 5.1, class = UnitClass.Vehicle, unit = "p204_f"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz231"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz221"},
			},
			["rus"] = {--Russia
			--Infantry Singles
			    {priority = 2.5, class = UnitClass.Infantry, unit = "squad_recon_con(rus)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_spetsnaz(rus)"},
			--Wheel_vehicles
				{priority = 1.8, class = UnitClass.Vehicle, unit = "m3a1e1_scout_mgun"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "ba64"},
			},
			["fra"] = {--France
			--Infantry
				-- 1
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(fra)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade_late(fra)"},
				-- 3
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_fr"},
			},
			["pol"] = {--Poland
			--Infantry
				-- 1
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(pol)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(pol)"},
				-- 2
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(pol)"},
				-- 3
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound_pol"},
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
			--Wheel_vehicles
				{priority = 2.5, class = UnitClass.Vehicle, unit = "type93"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type94aa"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "type94_te-ke"},
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
		    --Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willys50"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willysat"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20"},										  
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound"},
			},
			["eng"] = {--Britain
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(eng)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(eng)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(eng)"},
				-- 2
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(eng)"},
				-- 3
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
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ab41"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "autocannone10017"},
			}
		}
	},
	{--purchase 3 mortar
		waveNumber = 3,
	    -- Repeat = 2,
		minRepeat = 2,
		maxRepeat = 3,
	    skipPossible = false,
	    waveDuration = 5,
	    isHeavyArty = true,
		Units = {
			["ger"] = {--Germany
				--Howitzers
			    {priority = 2.0, class = UnitClass.ArtilleryTank, unit = "120mm_sgrw42"},
			},
			["rus"] = {--Russia
			--Howitzers
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "120mm_pm38"},
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
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "150mm_type_97"},
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
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_fallschirmjaeger_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_blau_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_brandenburger_con(ger)"},
			},
			["rus"] = {--Russia
			--Infantry Squads
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_mountainrifles_con(rus)"},

				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_guards_smg_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_flame_con(rus)"},

				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_paras_con(rus)"},
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
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(pol)"},
				-- 5
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(fra)"},
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
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(jap)"},
				-- 4
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(jap)"},

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
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(usa)"},
				-- 5
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(usa)"},
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
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(eng)"},
				-- 5
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(eng)"},			},
			["ita"] = {--Italy
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular(ita)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(ita)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_mg(ita)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(ita)"},
			}
		}
	},
	{--purchase 9 rocket arty
		waveNumber = 9,
		-- Repeat = 2,
		minRepeat = 1,
		maxRepeat = 2,
        skipPossible = false,		
		waveDuration = 5,
		isHeavyArty = true,
		Units = {
			["ger"] = {--Germany
		        {priority = 11.0, class = UnitClass.ArtilleryTank, unit = "300mm_nebelwerfer42", isHeavyArty = true},
			},
			["rus"] = {--Russia
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bm13_studebaker"},
			},
			["fra"] = {--France
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l_fr"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m1918"},
			},
			["pol"] = {--Poland
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45_pol"},
			},
			["jap"] = {--Japan
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "200mm_type_4"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "toyota_rocket"},
			},
			["usa"] = {--USA
				--Howitzers			
                {priority = 1.0, class = UnitClass.ArtilleryTank, unit = "203_mm_m115"},	
				{priority = 0.7, class = UnitClass.ArtilleryTank, unit = "m4a3c"},
			},
			["eng"] = {--Britain
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "land_mattress"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a4_tulip"}			
			},
			["ita"] = {--Italy
			--SPG
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "obice_210"},
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
