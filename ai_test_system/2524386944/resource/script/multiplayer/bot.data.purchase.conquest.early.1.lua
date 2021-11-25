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
				{priority = 0.1, class = UnitClass.Vehicle, unit = "p204_f"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz231"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz221"},
			--Infantry Squads
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_recon_con(ger)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_recon_armor_con"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_sicherung_con(ger)"},
			},
			["rus"] = {--Russia
			--Infantry Singles
			    {priority = 2.5, class = UnitClass.Infantry, unit = "squad_recon_con(rus)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_spetsnaz(rus)"},
			--Wheel_vehicles
				{priority = 1.5, class = UnitClass.Vehicle, unit = "gaz67b"},
				{priority = 1.8, class = UnitClass.Vehicle, unit = "m3a1e1_scout_mgun"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ba6"},
			}
		}
	},
	{--purchase 2 mortar
		waveNumber = 2,
	    minRepeat = 1,
		maxRepeat = 1,
	    skipPossible = false,
	    waveDuration = 1,
		Units = {
			["ger"] = {--Germany
				--Howitzers
				{priority = 2.0, class = UnitClass.ATTank, unit = "80mm_sgrw34"},
			    {priority = 2.0, class = UnitClass.ArtilleryTank, unit = "120mm_sgrw42"},
			},
			["rus"] = {--Russia
			--Howitzers
				{priority = 2.0, class = UnitClass.ATTank, unit = "82mm_bm37"},
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "120mm_pm38"},
			}
		}
	},
	{--purchase 3 tank assault group
		waveNumber = 3,
	    minRepeat = 2,
		maxRepeat = 3,
	    skipPossible = false,
	    waveDuration = 20,
		Units = {
			["ger"] = {--Germany
			--Tanks_medium
				{priority = 2.0, class = UnitClass.Tank, unit = "panzer3e"},
				{priority = 2.0, class = UnitClass.Tank, unit = "panzer3f"},
				{priority = 3.5, class = UnitClass.Tank, unit = "panzer3j"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4d"},
				{priority = 1.5, class = UnitClass.Tank, unit = "panzer4f1"},
			--Tanks_light
				{priority = 0.5, class = UnitClass.Tank, unit = "panzer1b"},
				{priority = 0.5, class = UnitClass.Tank, unit = "panzer2c"},
				{priority = 0.6, class = UnitClass.Tank, unit = "panzer2f"},
				{priority = 0.7, class = UnitClass.Tank, unit = "panzer35t"},
				{priority = 1.2, class = UnitClass.Tank, unit = "pz38t_a"},
				{priority = 1.2, class = UnitClass.Tank, unit = "pz38t_f"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz38t_g"},
			},
			["rus"] = {--Russia
			--Tanks_heavy
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "kv1_40"},
		    --Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "t28"},
				{priority = 2.0, class = UnitClass.Tank, unit = "t3476_40"},
			--Tanks_light
			    {priority = 1.0, class = UnitClass.Tank, unit = "t30"},
				{priority = 0.5, class = UnitClass.Tank, unit = "t40"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t60"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t70"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t70m"},
				{priority = 0.5, class = UnitClass.Tank, unit = "t26_31"},
				{priority = 0.1, class = UnitClass.Tank, unit = "kht26"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t26_33"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t26_39"},
				{priority = 0.1, class = UnitClass.Tank, unit = "t27"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t37a"},
				{priority = 0.5, class = UnitClass.Tank, unit = "bt2_da2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "bt2"},
				{priority = 1.5, class = UnitClass.Tank, unit = "bt5"},
				{priority = 1.0, class = UnitClass.Tank, unit = "bt7"},
		    }
		}
	},
	{--purchase 4 infantry support
		waveNumber = 4,
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
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_rifleunit_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_mountainrifles_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_guards_smg_con(rus)"},
			}
		}
	},
	{--purchase 5 SPG support
		waveNumber = 5,
		minRepeat = 1,
		maxRepeat = 1,
        skipPossible = false,		
		waveDuration = 1,
		Units = {
			["ger"] = {--Germany
			--SPG
				{priority = 0.5, class = UnitClass.ATTank, unit = "panzerjager1"},
				{priority = 1.5, class = UnitClass.ATTank, unit = "stug3b"},
			},
			["rus"] = {--Russia
			--SPG
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "su76"},
			}
		}
	},
	{--purchase 6 Tank 2
		waveNumber = 6,
		minRepeat = 2,
		maxRepeat = 3,
        skipPossible = false,		
		waveDuration = 20,
		Units = {
			["ger"] = {--Germany
				{priority = 2.0, class = UnitClass.Tank, unit = "panzer3e"},
				{priority = 2.0, class = UnitClass.Tank, unit = "panzer3f"},
				{priority = 3.5, class = UnitClass.Tank, unit = "panzer3j"},
			--Tanks_light
				{priority = 0.5, class = UnitClass.Tank, unit = "panzer1b"},
				{priority = 0.5, class = UnitClass.Tank, unit = "panzer2c"},
				{priority = 0.6, class = UnitClass.Tank, unit = "panzer2f"},
				{priority = 0.7, class = UnitClass.Tank, unit = "panzer35t"},
				{priority = 1.2, class = UnitClass.Tank, unit = "pz38t_a"},
				{priority = 1.2, class = UnitClass.Tank, unit = "pz38t_f"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz38t_g"},
			},
			["rus"] = {--Russia
			--Tanks_heavy
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "kv1_40"},
		    --Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "t28"},
				{priority = 2.0, class = UnitClass.Tank, unit = "t3476_40"},
				{priority = 2.5, class = UnitClass.Tank, unit = "t3476_41"},
	    	--Tanks_light
			    {priority = 0.5, class = UnitClass.Tank, unit = "t26_31"},
				{priority = 0.1, class = UnitClass.Tank, unit = "kht26"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t26_33"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t26_39"},
				{priority = 0.1, class = UnitClass.Tank, unit = "t27"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t37a"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t30"},
				{priority = 0.5, class = UnitClass.Tank, unit = "t40"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t60"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t70"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t70m"},
				{priority = 0.5, class = UnitClass.Tank, unit = "bt2_da2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "bt2"},
				{priority = 1.5, class = UnitClass.Tank, unit = "bt5"},
				{priority = 1.0, class = UnitClass.Tank, unit = "bt7"},
			}
		}
	},
	{--purchase 7 infantry attack 2
		waveNumber = 7,
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
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_rifleunit_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_mountainrifles_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_guards_smg_con(rus)"},
		}
		}
	},
	{--purchase 8 light tank rush
		waveNumber = 8,
		minRepeat = 2,
		maxRepeat = 4,
        skipPossible = false,		
		waveDuration = 10,
		Units = {
			["ger"] = {--Germany
			--Wheel_vehicles
				{priority = 2.5, class = UnitClass.Vehicle, unit = "sdkfz234_2"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "blitz3_6_flak30"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz231"},
				{priority = 0.1, class = UnitClass.Vehicle, unit = "p204_f"},
				{priority = 2.5, class = UnitClass.Tank, unit = "pz38t_f"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz38t_g"},
			},
			["rus"] = {--Russia
            --Tanks_light			
			    {priority = 3.0, class = UnitClass.Tank, unit = "t60"},
				{priority = 3.0, class = UnitClass.Tank, unit = "t70"},
				{priority = 3.0, class = UnitClass.Tank, unit = "t70m"},
			--Wheel_vehicles
				{priority = 0.5, class = UnitClass.Vehicle, unit = "gaz_aaa_72k"},
				{priority = 2.0, class = UnitClass.Vehicle, unit = "ba6"},
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