Purchases["campaign_capture_the_flag"] = {
	{--purchase 1 starting recon wave c 1 по 5 бой
		divisionName = "Condor Late Tank Division",
		waveNumber = 1, -- какая по порядку будет
		-- Repeat = 10, -- сколько раз должно вызваться, чтобы могло перейти к следующей волне
		minRepeat = 6,
		maxRepeat = 10,
		skipPossible = false,  -- ничего не делает
		waveDuration = 2, -- длительность того, как долго бот будет вызывать данные войска. Каждый юнит вызывается каждые 3 секунды. Если нужно чтобы было только определенное количество то Repeat * 3 < Wave duration  При этом Repeat говорит сколько раз нужно вызвать юнит.
		Units = {
			["ger"] = {--Germany
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "sdkfz234_2"},
				{priority = 0.3, class = UnitClass.Tank, unit = "panzer2l"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "sdkfz231"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "sdkfz221"},
			--Infantry Squads
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_recon_con(ger)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_recon_armor_con"}				
			},
			["rus"] = {--Russia
			--Infantry Singles
			    {priority = 1.0, class = UnitClass.Infantry, unit = "squad_recon_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_sniper(rus)"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ba64"},
				{priority = 0.2, class = UnitClass.Vehicle, unit = "ba6"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1e1_scout_mgun"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "gaz67b"}
			}
		}
	},
	{--purchase 2 mortar
		waveNumber = 2,
	    -- Repeat = 6,
	    minRepeat = 1,
		maxRepeat = 2,
	    skipPossible = false,
	    waveDuration = 3,
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
	{--purchase 3 heavy mortar
		waveNumber = 3,
	    -- Repeat = 2,
	    minRepeat = 0,
		maxRepeat = 0,
	    skipPossible = false,
	    waveDuration = 3,
		Units = {
			["ger"] = {--Germany
		    --Howitzers
                
			},
			["rus"] = {--Russia
			--Howitzers
                
			}
		}
	},
	{--purchase 4 heavy tank group
		waveNumber = 4,
	    -- Repeat = 17,
	    minRepeat = 2,
		maxRepeat = 4,
	    skipPossible = false,
	    waveDuration = 2,
		Units = {
			["ger"] = {--Germany
			--Tanks_heavy
				{priority = 0.8, class = UnitClass.HeavyTank, unit = "panzer5d"},
				{priority = 0.4, class = UnitClass.HeavyTank, unit = "panzer5a"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "panzer5g"}				
			},
			["rus"] = {--Russia				
			--Tanks_heavy
			{priority = 2.5, class = UnitClass.Tank, unit = "t3485_44"},
			{priority = 1.5, class = UnitClass.HeavyTank, unit = "is2_43"},
			{priority = 1.0, class = UnitClass.HeavyTank, unit = "is2_44"}
			}
		}
	},
	{--purchase 5 medium tank group
		waveNumber = 5,
	    -- Repeat = 20,
	    minRepeat = 2,
		maxRepeat = 4,
	    skipPossible = false,
	    waveDuration = 2,
		Units = {
			["ger"] = {--Germany
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4h"},
				{priority = 0.5, class = UnitClass.Tank, unit = "panzer4j"},
				{priority = 0.2, class = UnitClass.Tank, unit = "panzer4g"}
			},
			["rus"] = {--Russia		
			--Tanks_medium					
                {priority = 1.2, class = UnitClass.Tank, unit = "t3485_44"},
				{priority = 0.7, class = UnitClass.Tank, unit = "t3476_43"},
				{priority = 0.1, class = UnitClass.Tank, unit = "t3457_43"}
			}
		}
	},
	{--purchase 6 light tank group
		waveNumber = 6,
	    -- Repeat = 10,
	    minRepeat = 2,
		maxRepeat = 4,
	    skipPossible = false,
	    waveDuration = 2,
		Units = {
			["ger"] = {--Germany
			--Tanks_light
                
				
			},
			["rus"] = {--Russia			
            --Tanks_light
				{priority = 0.2, class = UnitClass.Tank, unit = "t60"},
				{priority = 0.4, class = UnitClass.Tank, unit = "t70"},
				{priority = 0.4, class = UnitClass.Tank, unit = "t70m"}			
			}
		}
	},
	{--purchase 7 infantry support
		waveNumber = 7,
		-- Repeat = 50,
		minRepeat = 4,
		maxRepeat = 6,
        skipPossible = false,		
		waveDuration = 3,
		Units = {
			["ger"] = {--Germany
			--Infantry Squads
			    {priority = 1.0, class = UnitClass.Infantry, unit = "squad_regular_motor_con"},
				{priority = 0.2, class = UnitClass.Infantry, unit = "squad_pz_pio_con"}
			},
			["rus"] = {--Russia
			--Infantry Squads
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_smg_con(rus)"}
			}
		}
	},
	{--purchase 8 SPG support
		waveNumber = 8,
		-- Repeat = 12,
		minRepeat = 2,
		maxRepeat = 4,
        skipPossible = false,		
		waveDuration = 3,
		Units = {
			["ger"] = {--Germany
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "marder3m"},
				{priority = 0.1, class = UnitClass.ArtilleryTank, unit = "sig33b"},
			},
			["rus"] = {--Russia
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "su85"},
				{priority = 0.2, class = UnitClass.ArtilleryTank, unit = "su122"}
			}
		}
	},
	{--purchase 11 AA support
		waveNumber = 11,
		-- Repeat = 12,
		minRepeat = 1,
		maxRepeat = 2,
        skipPossible = false,		
		waveDuration = 3,
		Units = {
			["ger"] = {--Germany
			--AA
			    {priority = 0.6, class = UnitClass.Vehicle, unit = "blitz3_6_flak30"},	
				{priority = 0.1, class = UnitClass.Tank, unit = "grille_m"}
			},
			["rus"] = {--Russia
			--AA
		
				{priority = 0.2, class = UnitClass.Vehicle, unit = "gaz_aaa_72k"}
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
