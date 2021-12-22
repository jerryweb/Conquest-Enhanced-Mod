Purchases["campaign_capture_the_flag"] = {
	{--purchase 1 arty wave
		divisionName = "Arty Noob division",
		waveNumber = 1,
		-- Repeat = 6,
		minRepeat = 2,
		maxRepeat = 6,
		skipPossible = false,
		waveDuration = 20,
		isHeavyArty = true,
		Units = {
			["ger"] = {--Germany
			--Infantry_Support
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "75mm_leig18"},
			--Artillery
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "105mm_lefh18"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "150mm_sfh18"},
				{priority = 11.0, class = UnitClass.ArtilleryTank, unit = "150mm_nebelwerfer41"}
			},
			["rus"] = {--Russia
			--Artillery
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "76mm_m1927"},
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "76mm_m43"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "122mm_m30"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "152mm_ml20"},
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
			},
			["rus"] = {--Russia
			--Infantry Singles
			    {priority = 2.5, class = UnitClass.Infantry, unit = "squad_recon_con(rus)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_spetsnaz(rus)"},
				-- {priority = 1.5, class = UnitClass.Infantry, unit = "squad_border(rus)"},
			--Wheel_vehicles
			}
		}
	},
	{--purchase 3 mortar
		waveNumber = 3,
	    -- Repeat = 2,
	    minRepeat = 1,
		maxRepeat = 2,
	    skipPossible = false,
	    waveDuration = 5,
		Units = {
			["ger"] = {--Germany
				--Howitzers
				{priority = 1.0, class = UnitClass.ATTank, unit = "80mm_sgrw34"},
			    {priority = 3.0, class = UnitClass.ArtilleryTank, unit = "120mm_sgrw42"},
			},
			["rus"] = {--Russia
			--Howitzers
				{priority = 1.0, class = UnitClass.ATTank, unit = "82mm_bm37"},
				{priority = 3.0, class = UnitClass.ArtilleryTank, unit = "120mm_pm38"},
			}
		}
	},
	{--purchase 4 tank assault group
		waveNumber = 4,
	    -- Repeat = 3,
	    minRepeat = 2,
		maxRepeat = 4,
	    skipPossible = false,
	    waveDuration = 10,
		Units = {
			["ger"] = {--Germany
			--Tanks_medium
				{priority = 0.5, class = UnitClass.Tank, unit = "panzer3j"},
				{priority = 2.5, class = UnitClass.Tank, unit = "panzer3j1"},
				{priority = 0.5, class = UnitClass.Tank, unit = "panzer3l"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4d"},
				{priority = 1.5, class = UnitClass.Tank, unit = "panzer4f1"},
					{priority = 1.0, class = UnitClass.Tank, unit = "panzer4g"},
				{priority = 1.5, class = UnitClass.Tank, unit = "panzer4h"},
			},
			["rus"] = {--Russia
	        --Tanks_medium
				{priority = 2.0, class = UnitClass.Tank, unit = "t3476_40"},
				{priority = 2.5, class = UnitClass.Tank, unit = "t3476_41"},
				{priority = 3.5, class = UnitClass.Tank, unit = "t3476_42"},
				{priority = 3.5, class = UnitClass.Tank, unit = "t3476_43"},
			}
		}
	},
	{--purchase 5 infantry support
		waveNumber = 5,
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
			}
		}
	},
	{--purchase Emplancement wave 6
		waveNumber = 6,
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
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "122mm_a19"},
			}
		}
	},
	{--purchase 7 SPG support
		waveNumber = 7,
		-- Repeat = 5,
		minRepeat = 2,
		maxRepeat = 4,
        skipPossible = false,		
		waveDuration = 20,
		Units = {
			["ger"] = {--Germany
			--SPG
				{priority = 1.5, class = UnitClass.ATTank, unit = "stug3b"},
				{priority = 1.5, class = UnitClass.ATTank, unit = "hetzer"},
				{priority = 1.5, class = UnitClass.ATTank, unit = "stug3f"},
				{priority = 2.0, class = UnitClass.ATTank, unit = "stug3g"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sturmpanzer4"},
				{priority = 0.5, class = UnitClass.Tank, unit = "grille_m"},
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "stuh42"},
						--SPG
				{priority = 1.1, class = UnitClass.ArtilleryTank, unit = "bison"},
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "sig33b"},
			},
			["rus"] = {--Russia
			--SPG
			{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "su76"},
				{priority = 1.5, class = UnitClass.ATTank, unit = "su85"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "su100"},
			}
		}
	},
	{--purchase 8 Tank 2
		waveNumber = 8,
		-- Repeat = 7,
		minRepeat = 2,
		maxRepeat = 4,
        skipPossible = false,		
		waveDuration = 20,
		Units = {
			["ger"] = {--Germany
			--Tanks_medium
				{priority = 0.5, class = UnitClass.Tank, unit = "panzer3j"},
				{priority = 2.5, class = UnitClass.Tank, unit = "panzer3j1"},
				{priority = 0.5, class = UnitClass.Tank, unit = "panzer3l"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4d"},
				{priority = 1.5, class = UnitClass.Tank, unit = "panzer4f1"},
					{priority = 1.0, class = UnitClass.Tank, unit = "panzer4g"},
				{priority = 1.5, class = UnitClass.Tank, unit = "panzer4h"},
			},
			["rus"] = {--Russia
	        --Tanks_medium
				{priority = 2.0, class = UnitClass.Tank, unit = "t3476_40"},
				{priority = 2.5, class = UnitClass.Tank, unit = "t3476_41"},
				{priority = 3.5, class = UnitClass.Tank, unit = "t3476_42"},
				{priority = 3.5, class = UnitClass.Tank, unit = "t3476_43"},
			}
		}
	},
	{--purchase 9 infantry attack 2
		waveNumber = 9,
		-- Repeat = 15,
		minRepeat = 4,
		maxRepeat = 8,
        skipPossible = false,		
		waveDuration = 35,
		Units = {
			["ger"] = {--Germany
			--Infantry Squads
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_con(ger)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular_vet_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_pz_pio_con"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_jaeger_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_gebirgsjaeger_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(ger)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(ger)"},
			},
			["rus"] = {--Russia
			--Infantry Squads
				{priority = 2.5, class = UnitClass.Infantry, unit = "squad_rifleunit_alt_con(rus)"},
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_rifleunit_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_mountainrifles_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
				{priority = 1.5, class = UnitClass.ATInfantry, unit = "single_riflegrenade(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(rus)"},
			}
		}
	},
	{--purchase 10 rocket arty
		waveNumber = 10,
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
			}
		}
	},
	{--purchase 11 light tank rush
		waveNumber = 11,
		-- Repeat = 8,
		minRepeat = 4,
		maxRepeat = 8,
        skipPossible = false,		
		waveDuration = 10,
		Units = {
			["ger"] = {--Germany
			--Wheel_vehicles
				{priority = 2.5, class = UnitClass.Vehicle, unit = "sdkfz234_2"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "blitz3_6_flak30"},
				{priority = 2.0, class = UnitClass.Tank, unit = "panzer2f"},
				{priority = 0.1, class = UnitClass.Vehicle, unit = "p204_f"},
				{priority = 2.5, class = UnitClass.Tank, unit = "pz38t_f"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz38t_g"},
					{priority = 1.0, class = UnitClass.Tank, unit = "panzer2l"},
			},
			["rus"] = {--Russia
            --Tanks_light			
			    {priority = 1.0, class = UnitClass.Tank, unit = "t60"},
				{priority = 2.0, class = UnitClass.Tank, unit = "t70"},
				{priority = 3.0, class = UnitClass.Tank, unit = "t70m"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "gaz_aaa_72k"},
				{priority = 2.0, class = UnitClass.Vehicle, unit = "ba6"},
			}
		}
	},
	{--purchase 12 howtizer
		waveNumber = 12,
		-- Repeat = 1,
		minRepeat = 1,
		maxRepeat = 2,
        skipPossible = false,		
		waveDuration = 5,
		Units = {
			["ger"] = {--Germany
		       {priority = 2.0, class = UnitClass.ArtilleryTank, unit = "105mm_lefh18"},
			   	{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "150mm_sfh18"},
			},
			["rus"] = {--Russia
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "122mm_m30"},
					{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "152mm_ml20"},
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
