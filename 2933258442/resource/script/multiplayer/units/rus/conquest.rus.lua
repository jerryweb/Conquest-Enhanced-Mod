Purchases["conquest.rus"] = {
	{Repeat = 0, --infinite
        Units = {
			---[====[
			-- Infantry
				---[[
				-- {priority = 1.0, type = {"Infantry", "Team", "Command",}, unit = "single_officer(rus)"},
				--{priority = 1.0, type = {"Infantry", "Squad", "Command",}, unit = "squad_officer_con(rus)"},
				--{priority = 1.0, type = {"Infantry", "Squad", "Command",}, unit = "squad_officer_gaz_con"},
				-- {priority = 0.01, type = {"Infantry", "Squad", "Command",}, unit = "ba20_command"},

				{priority = 1.0, type = {"Infantry", "Squad", "Wave",}, unit = "squad_border(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Wave",}, unit = "squad_partisan_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Wave",}, unit = "squad_penal_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Wave",}, unit = "squad_conscripts_con(rus)"},

				--T1+
				{priority = 1.0, type = {"Infantry", "Squad", "Wave",}, unit = "squad_vet_partisan_rifle_late_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Wave",}, unit = "squad_vet_partisan_smg_late_con(rus)"},

				--T2
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_nkvd_recon_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_recon_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_recon_44_con(rus)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_nkvd_sapper_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_sapper_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_sapper_44_con(rus)"},

				{priority = 1.0, type = {"Infantry", "Squad", "AT",}, unit = "squad_at_rifle_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad", "AT",}, unit = "squad_nkvd_at_rifle_con(rus)"},

				{priority = 1.0, type = {"Infantry", "Squad", "Wave",}, unit = "squad_nkvd_rifle_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifleunit_alt_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifleunit_con(rus)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifle_motorised_con"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifle_43_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifle_43_heavy_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifle_44_con(rus)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_smg_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_smg_mg_43_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_smg_mg_43_heavy_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_smg_mg_44_con(rus)"},

				--T2+
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guardsrifle_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guardsrifle_motorised_con"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guards_smg_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guardsrifle_44_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guardsrifle_44_motor_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guards_smg_mg_44_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guards_smg_mg_44_motor_con(rus)"},

				--T3
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_nkvd_mountain_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_mountainrifles_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_marines_reg_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_cav_44_con(rus)"},
				
				--T3+
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_elite_guardsrifle_44_motor_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_elite_guards_smg_mg_44_motor_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_guards_cav_44_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_guards_marines_44_con(rus)"},

				--T4
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_nkvd_mountain_cav_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_mountain_cav_44_con(rus)"},

				{priority = 1.0, type = {"Infantry", "Squad", "Elite", "Flamer"}, unit = "squad_assaultsappers_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite", "Flamer"}, unit = "squad_assaultsappers_flame_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad", "AT", "Elite",}, unit = "squad_assaultsappers_at_con(rus)"},

				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_paras_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_spetsnaz(rus)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_marines_con(rus)"},

				--T4+
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_guards_paras_con(rus)"},

				--Singles/Teams
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at(rus)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at2(rus)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at_pzs_late_con(rus)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at_late_con(rus)"},

				--{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_medic(rus)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_riflegrenade(rus)"},
				--{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_ap_miner(rus)"},
				--{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_at_miner(rus)"},
				{priority = 1.0, type = {"Infantry", "Team", "Engineer",}, unit = "single_engineer(rus)"},
				{priority = 1.0, type = {"Infantry", "Team", "Flamer"}, unit = "single_flamer(rus)"},
				--{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_tankman(rus)"},
				{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_sniper(rus)"},
				{priority = 1.0, type = {"Infantry", "Team", "Signaller"}, unit = "single_signaller(rus)"},
				--]]

			-- Cannons
				---[[
				--{priority = 1.0, type = {"Cannon", "Supply", "Ammo",}, unit = "inf_crate_rus"},
				--{priority = 1.0, type = {"Cannon", "Supply", "Ammo",}, unit = "ap_2"},

				--HMGs
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "maxim"},
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "ds39_stand"},
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "sg43_stand"},
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "dshk_stan"},
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "dshk_aa"},
				--Anti_Aircraft
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "25mm_72k"},
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "37mm_61k"},
				{priority = 1.0, type = {"Cannon", "AA", "AT",}, unit = "76mm_m1938"},
				{priority = 1.0, type = {"Cannon", "AA", "AT",}, unit = "85mm_52k"},
				--Anti_Tank
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "37mm_m30"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "m41_ampulomet"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "45mm_m37"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "45mm_m42"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "57mm_zis2"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "76mm_bpk76"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "76mm_m1902"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "76mm_m1933"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "76mm_f22"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "76mm_zis3"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "100mm_bs3"},
				--Mortars
				{priority = 1.0, type = {"Cannon", "Mortar",}, unit = "82mm_bm37"},
				{priority = 1.0, type = {"Cannon", "Mortar",}, unit = "120mm_pm38"},
				--Infantry_Support
				{priority = 1.0, type = {"Cannon", "Support",}, unit = "76mm_m1927"},
				{priority = 1.0, type = {"Cannon", "Support",}, unit = "76mm_m43"},
				--Artillery
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "107mm_m1910_30ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "122mm_m1910ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "122mm_m30ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "122mm_a19ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "152mm_ml20ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "152mm_br2ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "203mm_b4ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "280mm_br5ai"},
				{priority = 1.0, type = {"Cannon", "Artillery", "Big_gun",}, unit = "300mm_m30"},
				{priority = 1.0, type = {"Cannon", "Artillery", "Big_gun",}, unit = "300mm_m31"},
				--]]

			-- Wheeled vehicles
				---[[
				{priority = 1.0, type = {"Vehicle", "MG",}, unit = "m72"},
				{priority = 1.0, type = {"Vehicle", "AA",}, unit = "gaz_aaa_maximx4"},
				{priority = 1.0, type = {"Vehicle", "AA",}, unit = "gaz_aaa_72k"},
				{priority = 1.0, type = {"Vehicle", "AA", "AT",}, unit = "yag10_29k"},
				{priority = 1.0, type = {"Vehicle", "AA",}, unit = "zis5_dshk"},
				{priority = 1.0, type = {"Vehicle", "Artillery", "Rocket_Arty",}, unit = "zis6_bm8_48"},
				{priority = 1.0, type = {"Vehicle", "Artillery", "Rocket_Arty",}, unit = "zis6_bm13_16"},
				{priority = 1.0, type = {"Vehicle", "Artillery", "Rocket_Arty",}, unit = "bm13_studebakerai"},
				{priority = 1.0, type = {"Vehicle", "Artillery", "Rocket_Arty",}, unit = "bm31_12ai"},
				--{priority = 1.0, type = {"Vehicle",  "Unarmed", "Transport",}, unit = "gaz67"},
				{priority = 1.0, type = {"Vehicle", "MG",}, unit = "gaz67b"},
				{priority = 1.0, type = {"Armored", "MG",}, unit = "fai_m"},
				{priority = 1.0, type = {"Armored", "MG",}, unit = "ba20"},
				{priority = 1.0, type = {"Armored", "MG",}, unit = "ba6"},
				{priority = 1.0, type = {"Armored", "MG",}, unit = "ba10"},
				{priority = 1.0, type = {"Armored", "MG",}, unit = "ba64"},
				{priority = 1.0, type = {"Armored", "MG",}, unit = "universal_carrier_rus"},
				{priority = 1.0, type = {"Armored", "MG",}, unit = "mmg_carrier_rus"},
				{priority = 1.0, type = {"Armored", "MG",}, unit = "m3a1e1_scout_mgun"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Transport",}, unit = "gaz_aaa"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Transport",}, unit = "zis5"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Supply", "Ammo",}, unit = "gaz_aaa_supply"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Supply", "Fuel",}, unit = "gaz_fuel"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed","Supply", "Engineer",}, unit = "zis5eng"},
				--]]

			-- Tankettes
				---[[
				{priority = 1.0, type = {"Armored", "MG",}, unit = "t20"},
				{priority = 1.0, type = {"Armored", "MG",}, unit = "t27"},
				--]]

			-- Tanks
				---[[
				{priority = 1.0, type = {"Tank", "Light",}, unit = "t37a"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "t40"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "t30"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "t60"},
				{priority = 1.0, type = {"Tank", "Light", "Artillery", "Rocket_Arty",}, unit = "t60_bm8_24"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "t50"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "t70"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "t70m"},

				{priority = 1.0, type = {"Tank", "Light",}, unit = "bt2_da2"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "bt2"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "bt5"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "bt7"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "bt7a"},

				{priority = 1.0, type = {"Tank", "Light",}, unit = "t26_31"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "kht26"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "t26_33"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "t26_39"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "kht130"},

				{priority = 1.0, type = {"Tank", "Light",}, unit = "m3_stuart_late_rus"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "m3a1_stuart_rus"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "valentine2"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "valentine7"},
				{priority = 1.0, type = {"Tank", "Light", "Elite",}, unit = "valentine9"},

				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m3_lee_rus"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m4a2_75_early_rus"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m4a2_75_late_rus"},
				{priority = 1.0, type = {"Tank", "Medium", "Elite",}, unit = "m4a2_76w_early_rus"},
				{priority = 1.0, type = {"Tank", "Medium", "Elite",}, unit = "m4a2_76w_late_rus"},

				{priority = 1.0, type = {"Tank", "Medium",}, unit = "t28"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "t28_38"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "t28e"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "t3476_40"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "t3476_41"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "t3476_41e"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "t3457_41"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "t3476_42"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "t3476_43"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "t3457_43"},
				{priority = 1.0, type = {"Tank", "Medium", "Flamer",}, unit = "t3476_43_flame"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "t3485_44"},
				{priority = 1.0, type = {"Tank", "Medium", "Elite",}, unit = "t3485_44a"},
				{priority = 1.0, type = {"Tank", "Medium", "Elite",}, unit = "t3485_44b"},
				{priority = 1.0, type = {"Tank", "Medium", "Elite", "Flamer",}, unit = "t3485_44_flame"},
				{priority = 1.0, type = {"Tank", "Medium", "Elite", "Flamer",}, unit = "t3485_44a_flame"},
				{priority = 1.0, type = {"Armored", "MG", "Deminer",}, unit = "t34m"},
				{priority = 1.0, type = {"Tank", "Heavy", "Elite",}, unit = "churchill3"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "t35"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "t35_late"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "smk"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "kv1_39"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "kv1_40"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "kv1_40e"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "kv1_41"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "kv8"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "kv1_42"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "kv2_40"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "kv1s"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "kv85"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "is1_43"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "is2_43"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "is2_44"},
				{priority = 1.0, type = {"Tank", "Heavy", "Elite", "Big_gun",}, unit = "is2_45"},
				--]]

			-- Self-Propelled Guns
				---[[
				{priority = 1.0, type = {"Tank", "Light", "Support",}, unit = "su26"},
				{priority = 1.0, type = {"Tank", "Light", "AT",}, unit = "zis30"},
				{priority = 1.0, type = {"Tank", "Light", "Support",}, unit = "su76"},
				{priority = 1.0, type = {"Tank", "Medium", "AT",}, unit = "su85"},
				{priority = 1.0, type = {"Tank", "Medium", "AT",}, unit = "su85m"},
				{priority = 1.0, type = {"Tank", "Medium", "AT",}, unit = "su100"},
				{priority = 1.0, type = {"Tank", "Medium", "Support",}, unit = "su122"},
				{priority = 1.0, type = {"Tank", "Heavy", "AT", "Big_gun",}, unit = "su152"},
				{priority = 1.0, type = {"Tank", "Heavy", "AT", "Big_gun",}, unit = "isu122s"},
				{priority = 1.0, type = {"Tank", "Heavy", "AT", "Big_gun",}, unit = "isu152"},
				--]]

			--Aircraft
				{priority = 1.0, type = {"Aircraft", "Fighter",}, unit = "yak1_ser69_ai"},
				{priority = 1.0, type = {"Aircraft", "Bomber",}, unit = "il2_mod42_ai"},
				{priority = 1.0, type = {"Aircraft", "Paratrooper",}, unit = "squad_rus_paras_con"},
				{priority = 1.0, type = {"Aircraft", "Paratrooper",}, unit = "squad_rus_paras_con_late"},
			---]====]
			--MACE
			
		
		}
	}
}