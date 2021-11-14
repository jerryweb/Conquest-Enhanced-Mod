Purchases["campaign_capture_the_flag"] = {
	{--purchase 1 starting recon wave c 1 по 5 бой
		divisionName = "Condor Early Tank Division",
		waveNumber = 1, -- какая по порядку будет
		-- Repeat = 6, -- сколько раз должно вызваться, чтобы могло перейти к следующей волне
		minRepeat = 4,
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
			}
		}
	},
	{--purchase 2 mortar
		waveNumber = 2,
	    -- Repeat = 6,
	    minRepeat = 4,
		maxRepeat = 6,
	    skipPossible = false,
	    waveDuration = 8,
		Units = {
			["ger"] = {--Germany
		    --Howitzers
                {priority = 1.0, class = UnitClass.ATTank, unit = "80mm_sgrw34"},
			},
			["rus"] = {--Russia
			--Howitzers
                {priority = 1.0, class = UnitClass.ATTank, unit = "82mm_bm37"},
			}
		}
	},	
	{--purchase 3 medium tank group
		waveNumber = 3,
	    -- Repeat = 30,
	    minRepeat = 24,
		maxRepeat = 30,
	    skipPossible = false,
	    waveDuration = 20,
		Units = {
			["ger"] = {--Germany
			--Tanks_medium
				{priority = 2.0, class = UnitClass.Tank, unit = "panzer3e"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer3f"},
				{priority = 0.3, class = UnitClass.Tank, unit = "panzer3j"},
				{priority = 0.2, class = UnitClass.Tank, unit = "panzer3j1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4d"},
			},
			["rus"] = {--Russia		
			--Tanks_medium
				{priority = 0.8, class = UnitClass.Tank, unit = "t28"},
				{priority = 0.1, class = UnitClass.Tank, unit = "t3476_40"},
				{priority = 0.1, class = UnitClass.Tank, unit = "t3476_41"},
			--Tanks_heavy
			}
		}
	},
	{--purchase 4 light tank group
		waveNumber = 4,
	    -- Repeat = 20,
	    minRepeat = 16,
		maxRepeat = 20,
	    skipPossible = false,
	    waveDuration = 20,
		Units = {
			["ger"] = {--Germany
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer1b"},
				{priority = 2.0, class = UnitClass.Tank, unit = "panzer2c"},
				{priority = 2.0, class = UnitClass.Tank, unit = "panzer2f"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer35t"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz38t_a"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz38t_f"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz38t_g"},
			},
			["rus"] = {--Russia			
            --Tanks_light
				{priority = 2.0, class = UnitClass.Tank, unit = "t26_33"},
				{priority = 2.0, class = UnitClass.Tank, unit = "t26_39"},
				{priority = 0.5, class = UnitClass.Tank, unit = "t26_31"},				
			}
		}
	},
	{--purchase 5 infantry support
		waveNumber = 5,
		-- Repeat = 60,
		minRepeat = 45,
		maxRepeat = 60,
        skipPossible = false,		
		waveDuration = 35,
		Units = {
			["ger"] = {--Germany
			--Infantry Squads
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_con(ger)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_at(ger)"},
				{priority = 0.1, class = UnitClass.Infantry, unit = "single_officer(ger)"},
			},
			["rus"] = {--Russia
			--Infantry Squads
				{priority = 2.5, class = UnitClass.Infantry, unit = "squad_rifleunit_alt_con(rus)"},
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_rifleunit_con(rus)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_at(rus)"},
				{priority = 0.1, class = UnitClass.Infantry, unit = "single_officer(rus)"}
			}
		}
	},
	{--purchase 6 SPG support
		waveNumber = 6,
		-- Repeat = 6,
		minRepeat = 4,
		maxRepeat = 6,
        skipPossible = false,		
		waveDuration = 15,
		Units = {
			["ger"] = {--Germany
			--SPG
				{priority = 0.5, class = UnitClass.ATTank, unit = "panzerjager1"},
				{priority = 0.1, class = UnitClass.ArtilleryTank, unit = "bison"},
			},
			["rus"] = {--Russia
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "zis30"},
			}
		}
	},
	{--purchase 7 mgun support
		waveNumber = 7,
		-- Repeat = 12,
		minRepeat = 8,
		maxRepeat = 12,
        skipPossible = false,		
		waveDuration = 15,
		Units = {
			["ger"] = {--Germany
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "mg34_lafette"},
			},
			["rus"] = {--Russia
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "maxim"},
			}
		}
	},
	-- {--purchase 8 gun support
	-- 	waveNumber = 8,
	-- 	-- Repeat = 2,
	-- 	minRepeat = 1,
	-- 	maxRepeat = 2,
 --        skipPossible = false,		
	-- 	waveDuration = 15,
	-- 	Units = {
	-- 		["ger"] = {--Germany
	-- 		--SPG
	-- 			{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_leig18"},
	-- 		},
	-- 		["rus"] = {--Russia
	-- 		--SPG
	-- 			{priority = 1.0, class = UnitClass.ATTank, unit = "76mm_m1927"},
	-- 		}
	-- 	}
	-- }
		{--purchase 8 SPG support
		waveNumber = 8,
		-- Repeat = 2,
		minRepeat = 1,
		maxRepeat = 2,
        skipPossible = false,		
		waveDuration = 15,
		Units = {
			["ger"] = {--Germany
			--SPG
				{priority = 0.5, class = UnitClass.ATTank, unit = "panzerjager1"},
				{priority = 0.1, class = UnitClass.ArtilleryTank, unit = "bison"},
			},
			["rus"] = {--Russia
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "zis30"},
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
