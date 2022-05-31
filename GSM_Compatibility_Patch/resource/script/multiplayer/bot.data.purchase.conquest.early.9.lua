Purchases["campaign_capture_the_flag"] = {
	{--purchase 1 
		divisionName = "GSM Blitz Division",
		waveNumber = 1,
		minRepeat = 3,
		maxRepeat = 6,
		skipPossible = false,
		waveDuration = 20,
		Units = {
			["ger"] = {--Germany

				--Tanks_light
					{priority = 1.0, class = UnitClass.Tank,  unit = "panzer1b"},
					{priority = 1.0, class = UnitClass.Tank,  unit = "panzer1f"},
					{priority = 1.0, class = UnitClass.Tank,  unit = "panzer2c"},
					{priority = 1.0, class = UnitClass.Tank,  unit = "pz35t"},
					{priority = 1.0, class = UnitClass.Tank,  unit = "pz38t_a"},
					{priority = 1.0, class = UnitClass.Tank,  unit = "pz38t_f"},
					{priority = 1.0, class = UnitClass.Tank,  unit = "pz38t_g"},
					{priority = 1.0, class = UnitClass.Tank, unit = "panzer742r"},
					{priority = 1.0, class = UnitClass.Tank,  unit = "h39_ger"},

				--Tanks_medium
					{priority = 1.0, class = UnitClass.Tank, unit = "panzer3e"},
					{priority = 1.0, class = UnitClass.Tank, unit = "panzer3f"},
					{priority = 1.0, class = UnitClass.Tank, unit = "panzer4d"},
					{priority = 1.0, class = UnitClass.Tank, unit = "d2_ger"},			
			},
			["rus"] = {--Russia
				--Tanks_light
					{priority = 1.0, class = UnitClass.Tank, unit = "t18"},
					{priority = 1.0, class = UnitClass.Tank, unit = "t26_31"},
					{priority = 1.0, class = UnitClass.Tank, unit = "kht26"},,
					{priority = 1.0, class = UnitClass.Tank, unit = "t30"},
					{priority = 1.0, class = UnitClass.Tank, unit = "t40"},
					{priority = 1.0, class = UnitClass.Tank, unit = "t60"},
					{priority = 1.0, class = UnitClass.Tank, unit = "t70"},
					{priority = 1.0, class = UnitClass.Tank, unit = "t70m"},
					{priority = 1.0, class = UnitClass.Tank, unit = "bt2_da2"},
					{priority = 1.0, class = UnitClass.Tank, unit = "bt2"},
					{priority = 1.0, class = UnitClass.Tank, unit = "bt5"},
					{priority = 1.0, class = UnitClass.Tank, unit = "bt7"},
					{priority = 1.0, class = UnitClass.Tank, unit = "m3stuart"},
				--Tanks_medium
					{priority = 1.0, class = UnitClass.Tank, unit = "t28"},
					{priority = 1.0, class = UnitClass.Tank,  unit = "valentine2"},
					{priority = 1.0, class = UnitClass.Tank,  unit = "matilda2"},
			}
		}
	},
	{--purchase 2 Motar support
		waveNumber = 2,
		minRepeat = 1,
		maxRepeat = 2,
        skipPossible = true,		
		waveDuration = 30,
		isHeavyArty = true,
		Units = {
			["ger"] = {--Germany
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "80mm_sgrw34"},		
			},
			["rus"] = {--Russia
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "82mm_bm37"},
			}
		}
	},
	{--purchase 3 SPG support
		waveNumber = 3,
		minRepeat = 1,
		maxRepeat = 1,
        skipPossible = false,		
		waveDuration = 5,
		Units = {
			["ger"] = {--Germany
			--SPG
				{priority = 1.0, class = UnitClass.ATTank,  unit = "panzerjager1"},
				{priority = 0.75, class = UnitClass.ATTank, unit = "marder_1fcm_36"},
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "bison2"},
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "bison"},
			},
			["rus"] = {--Russia
			--SPG
				{priority = 1.0, class = UnitClass.ATTank,  unit = "at-1"},
				{priority = 0.75, class = UnitClass.ArtilleryTank,  unit = "su5"},

			}
		}
	},
	{--purchase 4 infantry attack 2
		waveNumber = 4,
		minRepeat = 3,
		maxRepeat = 4,
        skipPossible = false,		
		waveDuration = 30,
		Units = {
			["ger"] = {--Germany
			--Infantry Squads
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_osttruppen_con(ger)"},
				{priority = 0.75, class = UnitClass.Infantry, unit = "squad_strafbatallion_con(ger)"},

				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_sicherung_con(ger)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular_con(ger)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular_motor_con"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular_armor_con"},	
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pz_pio_con"},
			},
			["rus"] = {--Russia
			--Infantry Singles
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_flamer(rus)"},
				{priority = 0.50, class = UnitClass.Infantry, unit = "single_sniper(rus)"},
			--Infantry Squads
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_rifle_motorised_con"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_recon_con(rus)"},
			}
		}
	},
	{--purchase 5 tank support
		waveNumber = 5,
		minRepeat = 2,
		maxRepeat = 5,
        skipPossible = false,		
		waveDuration = 15,
		Units = {
			["ger"] = {--Germany
			--Tanks_light
				{priority = 1.5, class = UnitClass.Tank,  unit = "pz38t_a"},
				{priority = 1.5, class = UnitClass.Tank,  unit = "pz38t_f"},
				{priority = 1.5, class = UnitClass.Tank,  unit = "pz38t_g"},
				{priority = 0.5, class = UnitClass.Tank,  unit = "h39_ger"},

			--Tanks_medium
				{priority = 1.5, class = UnitClass.Tank, unit = "panzer3e"},
				{priority = 1.5, class = UnitClass.Tank, unit = "panzer3f"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4d"},
				{priority = 0.5, class = UnitClass.Tank, unit = "d2_ger"},
			},
			["rus"] = {--Russia

			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "t70"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t70m"},,
				{priority = 1.0, class = UnitClass.Tank, unit = "bt7"},
				{priority = 0.5, class = UnitClass.Tank, unit = "t80"},
				{priority = 0.7, class = UnitClass.Tank, unit = "m3stuart"},
			--Tanks_medium
				{priority = 0.7, class = UnitClass.Tank, unit = "t28"},
				{priority = 1.5, class = UnitClass.Tank,  unit = "valentine2"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "matilda2"},
			}
		}
	},
	{--purchase 6 arty support
		waveNumber = 6,
		minRepeat = 1,
		maxRepeat = 1,
        skipPossible = true,	
        isHeavyArty = true,	
		waveDuration = 5,
		Units = {
			["ger"] = {--Germany
			},
			["rus"] = {--Russia
			--SPG
				{priority = 0.75, class = UnitClass.ArtilleryTank,  unit = "su5"},

			}
		}
	},
	{--purchase 7 light tank rush
		waveNumber = 7,
		minRepeat = 2,
		maxRepeat = 4,
        skipPossible = false,		
		waveDuration = 10,
		Units = {
			["ger"] = {--Germany
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank,  unit = "panzer1b"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "flakpanzer1a"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "panzer1f"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "panzer2c"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer2f"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "pz35t"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer742r"},
			},
			["rus"] = {--Russia

			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ba20"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ba6"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ba11"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m17"},

			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "t18"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t26_31"},
				{priority = 1.0, class = UnitClass.Tank, unit = "kht26"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t26_33"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t26_39"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t27"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t37a"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t30"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t40"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t60"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3stuart"},
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
