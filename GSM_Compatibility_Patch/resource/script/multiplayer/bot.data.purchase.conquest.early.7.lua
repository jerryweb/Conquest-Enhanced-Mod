Purchases["campaign_capture_the_flag"] = {
	{--purchase 1 INFANTRY AND SUPPORT WEAPON BASED 
		divisionName = "GSM Infantry and Support ",
		waveNumber = 1, -- какая по порядку будет
		-- Repeat = 6, -- сколько раз должно вызваться, чтобы могло перейти к следующей волне
		minRepeat = 2,
		maxRepeat = 5,
		skipPossible = false,  -- ничего не делает
		waveDuration = 20, -- длительность того, как долго бот будет вызывать данные войска. Каждый юнит вызывается каждые 3 секунды. Если нужно чтобы было только определенное количество то Repeat * 3 < Wave duration  При этом Repeat говорит сколько раз нужно вызвать юнит.
		Units = {
			["ger"] = {--Germany
			--Wheel_vehicles
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz222"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "sdkfz251c"},
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
		        {priority = 1.0, class = UnitClass.Infantry, unit = "single_sniper(rus)"},
			--Wheel_vehicles
				{priority = 1.5, class = UnitClass.Vehicle, unit = "gaz67b"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "ba20"},
			},
		}
	},
	{--purchase 2 tank assault group
		waveNumber = 2,
	    -- Repeat = 10,
	    minRepeat = 2,
		maxRepeat = 4,
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
				{priority = 1.5, class = UnitClass.Tank,  unit = "valentine2"},
		    },
		}
	},
	{--purchase 2  mortar
		waveNumber = 3,
	    -- Repeat = 2,
	    minRepeat = 1,
		maxRepeat = 2,
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
		}
	},
	{--purchase 4 field gun support
		waveNumber = 4,
		-- Repeat = 3,
		minRepeat = 1,
		maxRepeat = 4,
        skipPossible = true,		
		waveDuration = 8,
		Units = {
			["ger"] = {--Germany
			--SPG
				{priority = 0.8, class = UnitClass.ATTank, unit = "28mm_pzb41"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "37mm_pak36"},
				{priority = 0.8, class = UnitClass.ATTank, unit = "47mm_pakt"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "75mm_leig18"},
			},
			["rus"] = {--Russia
			--SPG
				{priority = 1.5, class = UnitClass.ATTank, unit = "45mm_m37"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "45mm_m42"},
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "76mm_m1927"},
			},
		}
	},
	{--purchase 5 infantry support
		waveNumber = 5,
		-- Repeat = 10,
		minRepeat = 5,
		maxRepeat = 8,
        skipPossible = false,		
		waveDuration = 35,
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
		}
	},
	{--purchase 6 SPG support
		waveNumber = 6,
		-- Repeat = 3,
		minRepeat = 1,
		maxRepeat = 3,
        skipPossible = false,		
		waveDuration = 5,
		Units = {
			["ger"] = {--Germany
			--SPG
				{priority = 0.5, class = UnitClass.ATTank, unit = "panzerjager1"},
				{priority = 1.5, class = UnitClass.ATTank, unit = "stug3b"},
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "bison"},
			},
			["rus"] = {--Russia
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "zis30"},
				{priority = 1.0, class = UnitClass.ATTank,  unit = "at-1"},
				{priority = 0.5, class = UnitClass.ArtilleryTank,  unit = "su5"},
			},
		}
	},
	{--purchase 7 Tank 2
		waveNumber = 7,
		-- Repeat = 5,
		minRepeat = 1,
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
				{priority = 0.7, class = UnitClass.Tank, unit = "bt7a"},
			--Tanks_light
			   	{priority = 2.0, class = UnitClass.Tank, unit = "t26_33"},
				{priority = 2.0, class = UnitClass.Tank, unit = "t26_39"},
				{priority = 0.5, class = UnitClass.Tank, unit = "t3476_40"},
				{priority = 0.5, class = UnitClass.Tank, unit = "t3476_41"},
				{priority = 1.5, class = UnitClass.Tank,  unit = "valentine2"},
		    },
		}
	},
	{--purchase 8 infantry attack 2
		waveNumber = 8,
		-- Repeat = 10,
		minRepeat = 4,
		maxRepeat = 11,
        skipPossible = false,		
		waveDuration = 35,
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
		}
	},
	{--purchase 9 mgun support
		waveNumber = 9,
		Repeat = 3,
		minRepeat = 1,
		maxRepeat = 2,
        skipPossible = false,		
		waveDuration = 7,
		Units = {
			["ger"] = {--Germany
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "mg34_lafette"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "mg131_lafette"},
			},
			["rus"] = {--Russia
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "maxim"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "sg43_stand"},
			},
		}
	},
	{--purchase 10 light tank rush
		waveNumber = 10,
		-- Repeat = 10,
		minRepeat = 3,
		maxRepeat = 6,
        skipPossible = false,		
		waveDuration = 10,
		Units = {
			["ger"] = {--Germany
			--Wheel_vehicles
				{priority = 0.7, class = UnitClass.Tank, unit = "panzer1b"},
				{priority = 0.8, class = UnitClass.Tank,  unit = "flakpanzer1a"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer2c"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer2f"},
				{priority = 0.5, class = UnitClass.Tank, unit = "panzer35t"},
				{priority = 1.5, class = UnitClass.Tank, unit = "pz38t_a"},
			},
			["rus"] = {--Russia
            --Tanks_light			
			   	{priority = 0.75, class = UnitClass.Vehicle, unit = "mmg_carrier_rus"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t26_33"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t26_39"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t37a"},
				{priority = 1.0, class = UnitClass.Tank, unit = "bt2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "bt5"},
				{priority = 0.5, class = UnitClass.Tank, unit = "t40"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t60"},
				{priority = 0.7, class = UnitClass.Tank, unit = "m3stuart"},
			},
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