Purchases["campaign_capture_the_flag"] = {
	{--purchase 1 starting recon wave c 1 по 5 бой
		divisionName = "Condor Mid Tank Division",
		waveNumber = 1, -- какая по порядку будет
		-- Repeat = 6, -- сколько раз должно вызваться, чтобы могло перейти к следующей волне
		minRepeat = 4,
		maxRepeat = 12,
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
                {priority = 1.0, class = UnitClass.ATTank, unit = "80mm_sgrw34"}
			},
			["rus"] = {--Russia
			--Howitzers
                {priority = 1.0, class = UnitClass.ATTank, unit = "82mm_bm37"}
			}
		}
	},
	{--purchase 3 heavy tank group
		waveNumber = 3,
	    -- Repeat = 10,
	    minRepeat = 4,
		maxRepeat = 6,
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
			}
		}
	},
	{--purchase 4 medium tank group
		waveNumber = 4,
	    -- Repeat = 16,
	    minRepeat = 12,
		maxRepeat = 16,
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
			}
		}
	},
	{--purchase 5 light tank group
		waveNumber = 5,
	    -- Repeat = 20,
	    minRepeat = 16,
		maxRepeat = 20,
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
			}
		}
	},
	{--purchase 6 infantry support
		waveNumber = 6,
		-- Repeat = 60,
		minRepeat = 45,
		maxRepeat = 60,
        skipPossible = false,		
		waveDuration = 35,
		Units = {
			["ger"] = {--Germany
			--Infantry Squads
			    {priority = 1.0, class = UnitClass.Infantry, unit = "squad_regular_motor_con"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular_con(ger)"},
				{priority = 0.1, class = UnitClass.Infantry, unit = "single_officer(ger)"},
				{priority = 0.2, class = UnitClass.ATInfantry, unit = "single_at(ger)"},
				{priority = 0.2, class = UnitClass.ATInfantry, unit = "single_riflegrenade(ger)"}
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
	{--purchase 7 SPG support
		waveNumber = 7,
		-- Repeat = 6,
		minRepeat = 4,
		maxRepeat = 6,
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
			}
		}
	},
	{--purchase 8 mgun support
		waveNumber = 8,
		-- Repeat = 12,
		minRepeat = 8,
		maxRepeat = 12,
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
			}
		}
	},	
	-- {--purchase 9 gun support
	-- 	waveNumber = 9,
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
	-- },
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
				{priority = 1.0, class = UnitClass.ATTank, unit = "marder2"},
				{priority = 0.1, class = UnitClass.ArtilleryTank, unit = "sig33b"},
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
