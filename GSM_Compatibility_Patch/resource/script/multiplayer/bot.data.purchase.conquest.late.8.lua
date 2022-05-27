Purchases["campaign_capture_the_flag"] = {
	{--purchase 1 
		divisionName = "Master GSM Wave Template",
		waveNumber = 1,
		minRepeat = 3,
		maxRepeat = 6,
		skipPossible = false,
		waveDuration = 20,
		Units = {
			["ger"] = {--Germany
			--Infantry Singles
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_at(ger)"},
				{priority = 1.5, class = UnitClass.ATInfantry, unit = "single_riflegrenade(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(ger)"},
				{priority = 0.1, class = UnitClass.Infantry, unit = "single_officer(ger)"},
				{priority = 0.1, class = UnitClass.Infantry, unit = "squad_officer_con(ger)"},
				{priority = 0.1, class = UnitClass.Infantry, unit = "squad_officer_kubel_con"},
				{priority = 0.1, class = UnitClass.Infantry, unit = "squad_officer_250_3_con"},

			--Infantry Squads
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_osttruppen_con(ger)"},
				{priority = 0.75, class = UnitClass.Infantry, unit = "squad_strafbatallion_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_luftwaffe_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_blau_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_brandenburger_con(ger)"},

				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_sicherung_con(ger)"},
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_regular_motor_con"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_regular_armor_con"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular_vet_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_gd_motor_con"},

				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_pionier_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_pz_pio_con"},

				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_recon_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_recon_motor_con"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_recon_armor_con"},

				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_jaeger_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_gebirgsjaeger_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_fallschirmjaeger_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_fallschirmjaeger_motor_con"},

				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_fallschirmjaeger_para_con_late"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_fallschirmjaeger_para_con"},
			--HMGs
				{priority = 1.5, class = UnitClass.Vehicle, unit = "mg34_lafette"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "mg42_lafette"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "mg131_lafette"},
			--Anti_Aircraft
				{priority = 0.5, class = UnitClass.AATank, unit = "37mm_flak37"},
				{priority = 1.0, class = UnitClass.AATank, unit = "88mm_flak18"},
				{priority = 1.0, class = UnitClass.AATank, unit = "88mm_flak36"},
			--Anti_Tank
				{priority = 1.5, class = UnitClass.ATTank, unit = "50mm_pak38"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_pak40"},
			--Mortars
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "80mm_sgrw34"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "120mm_sgrw42"},
			--Infantry_Support
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "75mm_leig18"},
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "150mm_sig33ai"},
			--Artillery
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "105mm_lefh18ai"},
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "150mm_sfh18ai"},
				{priority = 0.1, class = UnitClass.ArtilleryTank, unit = "210mm_morser18ai"},
				{priority = 0.5, class = UnitClass.ArtilleryTank,  unit = "wespe"},
				{priority = 0.5, class = UnitClass.ArtilleryTank,  unit = "hummel"},
				{priority = 0.5, class = UnitClass.ArtilleryTank,  unit = "b1sf"},
				{priority = 0.5, class = UnitClass.ArtilleryTank,  unit = "grille"},
			-- Rocket_Artillery
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "150mm_nebelwerfer41ai"},
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "300mm_nebelwerfer42ai"},
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "zgkw303f"},
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "sdkfz4"},
			--Wheel_vehicles
				{priority = 0.5, class = UnitClass.Vehicle, unit = "kubelwagen_mg"},
				{priority = 2.0, class = UnitClass.AATank, unit = "blitz3_6_flak30"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz231"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz221"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "sdkfz234_1"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_2"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_3"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_4"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "sdkfz222"},

			--Half_tracks
				{priority = 1.0, class = UnitClass.Vehicle, unit = "sdkfz251c"},
				{priority = 0.8, class = UnitClass.ATTank, unit = "sdkfz10_pak38"},
				{priority = 0.5, class = UnitClass.ATTank, unit = "sdkfz8_flak18"},
				{priority = 0.6, class = UnitClass.ATTank, unit = "sdkfz7_2"},

			--Tanks_light
				{priority = 2.0, class = UnitClass.Tank, unit = "panzer2f"},
				{priority = 0.5, class = UnitClass.Tank,  unit = "grille_m"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "panzer2l"},
				{priority = 0.3, class = UnitClass.Tank,  unit = "panzer2j"},
				{priority = 0.3, class = UnitClass.Tank,  unit = "panzer1f"},

			--Tanks_medium
				{priority = 2.5, class = UnitClass.Tank, unit = "panzer3l"},
				{priority = 2.5, class = UnitClass.Tank, unit = "panzer3m"},
				{priority = 1.5, class = UnitClass.Tank, unit = "panzer3n"},
				{priority = 0.5, class = UnitClass.Tank, unit = "panzer3_flamm"},
				{priority = 3.0, class = UnitClass.Tank, unit = "panzer4g"},
				{priority = 3.5, class = UnitClass.Tank, unit = "panzer4h"},
				{priority = 3.0, class = UnitClass.Tank, unit = "panzer4j"},
				{priority = 0.5, class = UnitClass.Tank, unit = "d2_ger"},
				{priority = 0.5, class = UnitClass.Tank, unit = "char_b1"},
				{priority = 0.5, class = UnitClass.Tank, unit = "char_b1_flamer"},
				{priority = 0.7, class = UnitClass.Tank, unit = "wirbelwind"},
				{priority = 0.7, class = UnitClass.Tank, unit = "ostwind"},
				{priority = 0.5, class = UnitClass.Tank, unit = "kugelblitz"},
				{priority = 0.1, class = UnitClass.Tank, unit = "maus"},
				{priority = 0.4, class = UnitClass.Tank, unit = "t3476_43_ger"},
				{priority = 0.4, class = UnitClass.Tank, unit = "t3485_44_ger"},
				{priority = 0.3, class = UnitClass.Tank, unit = "m4a4_firefly_ger"},

			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "panzer5d"},
				{priority = 2.5, class = UnitClass.HeavyTank, unit = "panzer5g"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "tiger1h"},
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "tiger1e"},
				{priority = 0.1, class = UnitClass.HeavyTank, unit = "tiger1hunt"},
				{priority = 0.1, class = UnitClass.HeavyTank, unit = "tiger2p"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "tiger2h"},
				{priority = 0.4, class = UnitClass.HeavyTank, unit = "pz756r"},
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "tiger_p"},

			--SPG
				{priority = 2.0, class = UnitClass.ATTank,  unit = "stug3g"},
				{priority = 2.0, class = UnitClass.ATTank,  unit = "stug3g_late"},
				{priority = 2.0, class = UnitClass.ATTank,  unit = "hetzer"},
				{priority = 0.3, class = UnitClass.ATTank,  unit = "sdkfz301wanze"},
				{priority = 1.5, class = UnitClass.ATTank,  unit = "marder3m"},
				{priority = 0.3, class = UnitClass.ATTank, unit = "dicker_max"}, 
				{priority = 0.3, class = UnitClass.ATTank, unit = "sturer_emil"}, 
				{priority = 0.5, class = UnitClass.ATTank,  unit = "nashorn"}, 
				{priority = 0.8, class = UnitClass.ATTank,  unit = "jagdpanzer_iv"},
				{priority = 0.8, class = UnitClass.ATTank,  unit = "jagdpanther"},
				{priority = 0.5, class = UnitClass.ATTank,  unit = "elefant"},
				{priority = 0.5, class = UnitClass.ATTank,  unit = "jagdtiger"},
				{priority = 0.5, class = UnitClass.ArtilleryTank,  unit = "geschuetzwagen_ivb"},
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "sig33b"},
				{priority = 0.5, class = UnitClass.ArtilleryTank,  unit = "sturmpanzer4"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "stuh42"},
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "kv2_754r"},			
			},
			["rus"] = {--Russia
			--Infantry Singles
				{priority = 1.5, class = UnitClass.ATInfantry, unit = "single_at(rus)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(rus)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "single_sniper(rus)"},
				{priority = 0.1, class = UnitClass.Infantry, unit = "single_officer(rus)"},
				{priority = 0.1, class = UnitClass.Infantry, unit = "squad_officer_con(rus)"},
				{priority = 0.1, class = UnitClass.Infantry, unit = "squad_officer_gaz_con"},

			--Infantry Squads
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_partisan_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_penal_con(rus)"},

				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_border(rus)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_conscripts_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_recon_con(rus)"},
				{priority = 2.5, class = UnitClass.Infantry, unit = "squad_rifleunit_alt_con(rus)"},
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_rifleunit_con(rus)"},
				{priority = 1.5, class = UnitClass.ATInfantry, unit = "squad_at_rifle_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_smg_con(rus)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_rifle_motorised_con"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_mountainrifles_con(rus)"},

				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_guards_smg_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_motorised_con"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_flame_con(rus)"},

				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_paras(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_spetsnaz(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_marines_con(rus)"},

				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_rus_paras_con"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_rus_paras_con_late"},
			--HMGs
				{priority = 1.5, class = UnitClass.Vehicle, unit = "maxim"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "sg43_stand"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dshk_stan"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dshk_aa"},
			--Anti_Aircraft
				{priority = 1.5, class = UnitClass.AATank, unit = "37mm_61k"},
				{priority = 1.5, class = UnitClass.AATank, unit = "85mm_52k"},
			--Anti_Tank
				{priority = 0.1, class = UnitClass.ATTank, unit = "57mm_zis2"},
				{priority = 0.5, class = UnitClass.ATTank, unit = "100mm_bs3"},
			--Mortars
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "82mm_bm37"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "120mm_pm38"},
			--Infantry_Support
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "76mm_m43"},
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "76mm_zis3"},
			--Artillery
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "122mm_m30ai"},
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "122mm_a19ai"},
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "152mm_ml20ai"},
				{priority = 0.1, class = UnitClass.ArtilleryTank, unit = "203mm_b4ai"},
			--Rocket_Artillery
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bm13_studebakerai"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bm31_12ai"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bm_8_24"},

			--Wheel_vehicles
				{priority = 1.5, class = UnitClass.Vehicle, unit = "gaz67b"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "gaz_aaa_72k"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "ba20"},
				{priority = 2.0, class = UnitClass.Vehicle, unit = "ba6"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "ba64"},
				{priority = 0.75, class = UnitClass.Vehicle, unit = "universal_carrier_rus"},
				{priority = 0.75, class = UnitClass.Vehicle, unit = "mmg_carrier_rus"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1e1_scout_mgun"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ba11"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m17"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "yag10_29k"},

			--Tanks_light
				{priority = 3.0, class = UnitClass.Tank, unit = "t60"},
				{priority = 3.0, class = UnitClass.Tank, unit = "t70m"},
				{priority = 0.5, class = UnitClass.Tank, unit = "t80"},
				{priority = 0.7, class = UnitClass.Tank, unit = "m3stuart"},
				{priority = 0.7, class = UnitClass.Tank, unit = "t50"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank,  unit = "t3476_43"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "t3476_43_flame"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "t3457_43"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "matilda2"},
				{priority = 1.7, class = UnitClass.Tank,  unit = "m4a2"},
				{priority = 0.5, class = UnitClass.Tank,  unit = "m4a2_76w"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "t3485_44"},
				{priority = 0.5, class = UnitClass.Tank,  unit = "t44"},
				{priority = 0.1, class = UnitClass.Tank,  unit = "t44_122"},

			--Tanks_heavy
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "churchill3"},
				{priority = 1.0, class = UnitClass.ArtilleryTank,  unit = "kv2_40"},
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "is1_43"},
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "is2_43"},
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "is2_44"},
				{priority = 0.3, class = UnitClass.HeavyTank,unit = "kv-122"},
				{priority = 0.3, class = UnitClass.HeavyTank, unit = "is3"},

			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "su76i"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "wolverine"},
				{priority = 1.0, class = UnitClass.ATTank,  unit = "su85m"},
				{priority = 1.0, class = UnitClass.ATTank,  unit = "su100"},
				{priority = 1.2, class = UnitClass.ArtilleryTank, unit = "su122"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "su152"},
				{priority = 1.0, class = UnitClass.ArtilleryTank,  unit = "isu152"},
				{priority = 1.0, class = UnitClass.ArtilleryTank,  unit = "isu122"},
				{priority = 1.0, class = UnitClass.ArtilleryTank,  unit = "isu122s"},
				{priority = 0.3, class = UnitClass.ArtilleryTank, unit = "su14"},
			}
		}
	},
	{--purchase officer
		waveNumber = 2,
		minRepeat = 1,
		maxRepeat = 1,
        skipPossible = true,
	    skipChance = 0.45,		
		waveDuration = 5,
		Units = {
			["ger"] = {--Germany
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_officer(ger)"},
				{priority = 0.5, class = UnitClass.Infantry, unit = "squad_officer_con(ger)"},
				-- {priority = 0.7, class = UnitClass.Infantry, unit = "squad_officer_kubel_con"},
				-- {priority = 0.2, class = UnitClass.Infantry, unit = "squad_officer_250_3_con"},
			},
			["rus"] = {--Russia
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_officer(rus)"},
				{priority = 0.5, class = UnitClass.Infantry, unit = "squad_officer_con(rus)"},
				-- {priority = 0.1, class = UnitClass.Infantry, unit = "squad_officer_gaz_con"},
			},
			["hun"] = {--Hungary
				{priority = 1.1, class = UnitClass.Infantry, unit = "single_officer(hun)"},
			},
			["fra"] = {--France
				{priority = 1.1, class = UnitClass.Infantry, unit = "single_officer(fra)"},
			},
			["pol"] = {--Poland
				{priority = 1.1, class = UnitClass.Infantry, unit = "single_officer(pol)"},
			},
			["jap"] = {--Japan
				{priority = 1.1, class = UnitClass.Infantry, unit = "single_officer(jap)"},
			},
			["usa"] = {--USA
				{priority = 1.1, class = UnitClass.Infantry, unit = "single_officer(usa)"},
			},
			["eng"] = {--Britain
				{priority = 1.1, class = UnitClass.Infantry, unit = "single_officer(eng)"},
			},
			["ita"] = {--Italy
				{priority = 1.1, class = UnitClass.Infantry, unit = "single_officer(ita)"},
			}
		}
	},
	{--purchase 3 infantry support
		waveNumber = 3,
		minRepeat = 6,
		maxRepeat = 8,
        skipPossible = false,		
		waveDuration = 30,
		Units = {
			["ger"] = {--Germany
			--Infantry Singles
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_at(ger)"},
				{priority = 1.5, class = UnitClass.ATInfantry, unit = "single_riflegrenade(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(ger)"},
				{priority = 0.1, class = UnitClass.Infantry, unit = "single_officer(ger)"},
				{priority = 0.1, class = UnitClass.Infantry, unit = "squad_officer_con(ger)"},
				{priority = 0.1, class = UnitClass.Infantry, unit = "squad_officer_kubel_con"},
				{priority = 0.1, class = UnitClass.Infantry, unit = "squad_officer_250_3_con"},

			--Infantry Squads
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_osttruppen_con(ger)"},
				{priority = 0.75, class = UnitClass.Infantry, unit = "squad_strafbatallion_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_luftwaffe_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_blau_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_brandenburger_con(ger)"},

				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_sicherung_con(ger)"},
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_regular_motor_con"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_regular_armor_con"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular_vet_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_gd_motor_con"},

				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_pionier_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_pz_pio_con"},

				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_recon_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_recon_motor_con"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_recon_armor_con"},

				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_jaeger_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_gebirgsjaeger_con(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_fallschirmjaeger_con(ger)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_fallschirmjaeger_motor_con"},

				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_fallschirmjaeger_para_con_late"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_fallschirmjaeger_para_con"},
			--HMGs
				{priority = 1.5, class = UnitClass.Vehicle, unit = "mg34_lafette"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "mg42_lafette"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "mg131_lafette"},
			--Anti_Aircraft
				{priority = 0.5, class = UnitClass.AATank, unit = "37mm_flak37"},
				{priority = 1.0, class = UnitClass.AATank, unit = "88mm_flak18"},
				{priority = 1.0, class = UnitClass.AATank, unit = "88mm_flak36"},
			--Anti_Tank
				{priority = 1.5, class = UnitClass.ATTank, unit = "50mm_pak38"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_pak40"},
			--Mortars
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "80mm_sgrw34"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "120mm_sgrw42"},
			--Infantry_Support
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "75mm_leig18"},
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "150mm_sig33ai"},
			--Artillery
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "105mm_lefh18ai"},
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "150mm_sfh18ai"},
				{priority = 0.1, class = UnitClass.ArtilleryTank, unit = "210mm_morser18ai"},
				{priority = 0.5, class = UnitClass.ArtilleryTank,  unit = "wespe"},
				{priority = 0.5, class = UnitClass.ArtilleryTank,  unit = "hummel"},
				{priority = 0.5, class = UnitClass.ArtilleryTank,  unit = "b1sf"},
				{priority = 0.5, class = UnitClass.ArtilleryTank,  unit = "grille"},
			-- Rocket_Artillery
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "150mm_nebelwerfer41ai"},
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "300mm_nebelwerfer42ai"},
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "zgkw303f"},
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "sdkfz4"},
			--Wheel_vehicles
				{priority = 0.5, class = UnitClass.Vehicle, unit = "kubelwagen_mg"},
				{priority = 2.0, class = UnitClass.AATank, unit = "blitz3_6_flak30"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz231"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz221"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "sdkfz234_1"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_2"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_3"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_4"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "sdkfz222"},

			--Half_tracks
				{priority = 1.0, class = UnitClass.Vehicle, unit = "sdkfz251c"},
				{priority = 0.8, class = UnitClass.ATTank, unit = "sdkfz10_pak38"},
				{priority = 0.5, class = UnitClass.ATTank, unit = "sdkfz8_flak18"},
				{priority = 0.6, class = UnitClass.ATTank, unit = "sdkfz7_2"},

			--Tanks_light
				{priority = 2.0, class = UnitClass.Tank, unit = "panzer2f"},
				{priority = 0.5, class = UnitClass.Tank,  unit = "grille_m"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "panzer2l"},
				{priority = 0.3, class = UnitClass.Tank,  unit = "panzer2j"},
				{priority = 0.3, class = UnitClass.Tank,  unit = "panzer1f"},

			--Tanks_medium
				{priority = 2.5, class = UnitClass.Tank, unit = "panzer3l"},
				{priority = 2.5, class = UnitClass.Tank, unit = "panzer3m"},
				{priority = 1.5, class = UnitClass.Tank, unit = "panzer3n"},
				{priority = 0.5, class = UnitClass.Tank, unit = "panzer3_flamm"},
				{priority = 3.0, class = UnitClass.Tank, unit = "panzer4g"},
				{priority = 3.5, class = UnitClass.Tank, unit = "panzer4h"},
				{priority = 3.0, class = UnitClass.Tank, unit = "panzer4j"},
				{priority = 0.5, class = UnitClass.Tank, unit = "d2_ger"},
				{priority = 0.5, class = UnitClass.Tank, unit = "char_b1"},
				{priority = 0.5, class = UnitClass.Tank, unit = "char_b1_flamer"},
				{priority = 0.7, class = UnitClass.Tank, unit = "wirbelwind"},
				{priority = 0.7, class = UnitClass.Tank, unit = "ostwind"},
				{priority = 0.5, class = UnitClass.Tank, unit = "kugelblitz"},
				{priority = 0.1, class = UnitClass.Tank, unit = "maus"},
				{priority = 0.4, class = UnitClass.Tank, unit = "t3476_43_ger"},
				{priority = 0.4, class = UnitClass.Tank, unit = "t3485_44_ger"},
				{priority = 0.3, class = UnitClass.Tank, unit = "m4a4_firefly_ger"},

			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "panzer5d"},
				{priority = 2.5, class = UnitClass.HeavyTank, unit = "panzer5g"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "tiger1h"},
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "tiger1e"},
				{priority = 0.1, class = UnitClass.HeavyTank, unit = "tiger1hunt"},
				{priority = 0.1, class = UnitClass.HeavyTank, unit = "tiger2p"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "tiger2h"},
				{priority = 0.4, class = UnitClass.HeavyTank, unit = "pz756r"},
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "tiger_p"},

			--SPG
				{priority = 2.0, class = UnitClass.ATTank,  unit = "stug3g"},
				{priority = 2.0, class = UnitClass.ATTank,  unit = "stug3g_late"},
				{priority = 2.0, class = UnitClass.ATTank,  unit = "hetzer"},
				{priority = 0.3, class = UnitClass.ATTank,  unit = "sdkfz301wanze"},
				{priority = 1.5, class = UnitClass.ATTank,  unit = "marder3m"},
				{priority = 0.3, class = UnitClass.ATTank, unit = "dicker_max"}, 
				{priority = 0.3, class = UnitClass.ATTank, unit = "sturer_emil"}, 
				{priority = 0.5, class = UnitClass.ATTank,  unit = "nashorn"}, 
				{priority = 0.8, class = UnitClass.ATTank,  unit = "jagdpanzer_iv"},
				{priority = 0.8, class = UnitClass.ATTank,  unit = "jagdpanther"},
				{priority = 0.5, class = UnitClass.ATTank,  unit = "elefant"},
				{priority = 0.5, class = UnitClass.ATTank,  unit = "jagdtiger"},
				{priority = 0.5, class = UnitClass.ArtilleryTank,  unit = "geschuetzwagen_ivb"},
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "sig33b"},
				{priority = 0.5, class = UnitClass.ArtilleryTank,  unit = "sturmpanzer4"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "stuh42"},
				{priority = 0.5, class = UnitClass.ArtilleryTank, unit = "kv2_754r"},			
			},
			["rus"] = {--Russia
			--Infantry Singles
				{priority = 1.5, class = UnitClass.ATInfantry, unit = "single_at(rus)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(rus)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "single_sniper(rus)"},
				{priority = 0.1, class = UnitClass.Infantry, unit = "single_officer(rus)"},
				{priority = 0.1, class = UnitClass.Infantry, unit = "squad_officer_con(rus)"},
				{priority = 0.1, class = UnitClass.Infantry, unit = "squad_officer_gaz_con"},

			--Infantry Squads
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_partisan_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_penal_con(rus)"},

				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_border(rus)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_conscripts_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_recon_con(rus)"},
				{priority = 2.5, class = UnitClass.Infantry, unit = "squad_rifleunit_alt_con(rus)"},
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_rifleunit_con(rus)"},
				{priority = 1.5, class = UnitClass.ATInfantry, unit = "squad_at_rifle_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_smg_con(rus)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_rifle_motorised_con"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_mountainrifles_con(rus)"},

				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_guards_smg_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_motorised_con"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_flame_con(rus)"},

				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_paras(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_spetsnaz(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_marines_con(rus)"},

				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_rus_paras_con"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_rus_paras_con_late"},
			--HMGs
				{priority = 1.5, class = UnitClass.Vehicle, unit = "maxim"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "sg43_stand"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dshk_stan"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dshk_aa"},
			--Anti_Aircraft
				{priority = 1.5, class = UnitClass.AATank, unit = "37mm_61k"},
				{priority = 1.5, class = UnitClass.AATank, unit = "85mm_52k"},
			--Anti_Tank
				{priority = 0.1, class = UnitClass.ATTank, unit = "57mm_zis2"},
				{priority = 0.5, class = UnitClass.ATTank, unit = "100mm_bs3"},
			--Mortars
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "82mm_bm37"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "120mm_pm38"},
			--Infantry_Support
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "76mm_m43"},
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "76mm_zis3"},
			--Artillery
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "122mm_m30ai"},
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "122mm_a19ai"},
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "152mm_ml20ai"},
				{priority = 0.1, class = UnitClass.ArtilleryTank, unit = "203mm_b4ai"},
			--Rocket_Artillery
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bm13_studebakerai"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bm31_12ai"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bm_8_24"},

			--Wheel_vehicles
				{priority = 1.5, class = UnitClass.Vehicle, unit = "gaz67b"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "gaz_aaa_72k"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "ba20"},
				{priority = 2.0, class = UnitClass.Vehicle, unit = "ba6"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "ba64"},
				{priority = 0.75, class = UnitClass.Vehicle, unit = "universal_carrier_rus"},
				{priority = 0.75, class = UnitClass.Vehicle, unit = "mmg_carrier_rus"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1e1_scout_mgun"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ba11"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m17"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "yag10_29k"},

			--Tanks_light
				{priority = 3.0, class = UnitClass.Tank, unit = "t60"},
				{priority = 3.0, class = UnitClass.Tank, unit = "t70m"},
				{priority = 0.5, class = UnitClass.Tank, unit = "t80"},
				{priority = 0.7, class = UnitClass.Tank, unit = "m3stuart"},
				{priority = 0.7, class = UnitClass.Tank, unit = "t50"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank,  unit = "t3476_43"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "t3476_43_flame"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "t3457_43"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "matilda2"},
				{priority = 1.7, class = UnitClass.Tank,  unit = "m4a2"},
				{priority = 0.5, class = UnitClass.Tank,  unit = "m4a2_76w"},
				{priority = 1.0, class = UnitClass.Tank,  unit = "t3485_44"},
				{priority = 0.5, class = UnitClass.Tank,  unit = "t44"},
				{priority = 0.1, class = UnitClass.Tank,  unit = "t44_122"},

			--Tanks_heavy
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "churchill3"},
				{priority = 1.0, class = UnitClass.ArtilleryTank,  unit = "kv2_40"},
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "is1_43"},
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "is2_43"},
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "is2_44"},
				{priority = 0.3, class = UnitClass.HeavyTank,unit = "kv-122"},
				{priority = 0.3, class = UnitClass.HeavyTank, unit = "is3"},

			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "su76i"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "wolverine"},
				{priority = 1.0, class = UnitClass.ATTank,  unit = "su85m"},
				{priority = 1.0, class = UnitClass.ATTank,  unit = "su100"},
				{priority = 1.2, class = UnitClass.ArtilleryTank, unit = "su122"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "su152"},
				{priority = 1.0, class = UnitClass.ArtilleryTank,  unit = "isu152"},
				{priority = 1.0, class = UnitClass.ArtilleryTank,  unit = "isu122"},
				{priority = 1.0, class = UnitClass.ArtilleryTank,  unit = "isu122s"},
				{priority = 0.3, class = UnitClass.ArtilleryTank, unit = "su14"},
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
