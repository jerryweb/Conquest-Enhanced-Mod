Purchases["conquest.usr"] = {
	{Repeat = 0, --infinite

        Units = {
			---[====[
			-- Infantry
				{priority = 1.0, type = {"Infantry", "Team", "Command",}, unit = "single_officer(usr)"},
				--{priority = 1.0, type = {"Infantry", "Squad", "Command",}, unit = "squad_officer_con(usr)"},
				--{priority = 1.0, type = {"Infantry", "Squad", "Command",}, unit = "squad_officer_m3a1_commander_con"},
				-- {priority =  0.01, type = {"Infantry", "Squad", "Command",}, unit = "squad_officer_m3a1_halftrack_con"},

				{priority = 0.8, type = {"Infantry", "Squad",}, unit = "squad_mp_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_45th_rifle_con(usr)"},

				--Recon
				--{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_1st_arm_recon_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_cav_late_con1(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_cav_late_con2(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_82nd_recon_con(usr)"},

				--T2
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifle_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_1st_arm_rifle_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_1st_arm_rifle_mech_con(usr)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifle_late_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_arm_rifle_mech_late_con(usr)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_eng_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_eng_mech_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_eng_mech_late_con(usr)"},

				--T2+
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_vet_rifle_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_vet_rifle_late_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_2nd_arm_rifle_mech_late_con(usr)"},

				--T3
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_82nd_glider_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_82nd_glider_pio_con(usr)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_mountain_late_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_mountain_pio_late_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_101st_glider_late_con(usr)"},

				--T3+
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_1st_rifle_late_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_1st_arm_rifle_mech_late_con(usr)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_82nd_glider_late_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_82nd_glider_pio_late_con(usr)"},

				--T4
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_ranger_assault_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_ranger_assault_mg_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_ranger_assault_late_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_ranger_assault_mg_late_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_ranger_special_late_con(usr)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_82nd_eng_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_82nd_con(usr)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "1st_special_con(usr)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_101st_eng_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_101st_con(usr)"},

				--T4+
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_82nd_eng_late_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_82nd_late_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_82nd_demo_late_con(usr)"},

				--Singles/Teams
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at1_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at2_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at3_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at4_con(usr)"},
				
				--{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_medic(usr)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_riflegrenade_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_riflegrenade2_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_ap_miner(usr)"},
				{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_at_miner(usr)"},
				{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_engineer(usr)"},
				{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_flamer(usr)"},
				--{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_tankman(usr)"},
				{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_sniper(usr)"},
				{priority = 1.0, type = {"Infantry", "Team", "Signaller",}, unit = "single_signaller(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_border(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_partisan_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_penal_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_conscripts_con(usr)"},

				--T1+
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_vet_partisan_rifle_late_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_vet_partisan_smg_late_con(usr)"},

				--T2
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_nkvd_recon_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_recon_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_recon_44_con(usr)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_nkvd_sapper_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_sapper_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_sapper_44_con(usr)"},

				{priority = 1.0, type = {"Infantry", "Squad", "AT",}, unit = "squad_at_rifle_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad", "AT",}, unit = "squad_nkvd_at_rifle_con(usr)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_nkvd_rifle_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifleunit_alt_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifleunit_con(usr)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifle_motorised_con"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifle_43_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifle_43_heavy_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifle_44_con(usr)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_smg_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_smg_mg_43_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_smg_mg_43_heavy_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_smg_mg_44_con(usr)"},

				--T2+
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guardsrifle_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guardsrifle_motorised_con"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guards_smg_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guardsrifle_44_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guardsrifle_44_motor_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guards_smg_mg_44_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guards_smg_mg_44_motor_con(usr)"},

				--T3
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_nkvd_mountain_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_mountainrifles_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_marines_reg_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_cav_44_con(usr)"},
				
				--T3+
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_elite_guardsrifle_44_motor_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_elite_guards_smg_mg_44_motor_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guards_cav_44_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guards_marines_44_con(usr)"},

				--T4
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_nkvd_mountain_cav_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_mountain_cav_44_con(usr)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_assaultsappers_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_assaultsappers_flame_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad", "AT",}, unit = "squad_assaultsappers_at_con(usr)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_paras_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_spetsnaz(usr)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_marines_con(usr)"},

				--T4+
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guards_paras_con(usr)"},

				--Singles/Teams
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at(usr)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at2(usr)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at_pzs_late_con(usr)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at_late_con(usr)"},

				--{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_medic(usr)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_riflegrenade(usr)"},
				{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_ap_miner(usr)"},
				{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_at_miner(usr)"},
				{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_engineer(usr)"},
				{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_flamer(usr)"},
				--{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_tankman(usr)"},
				{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_sniper(usr)"},

				--]]

			-- Cannons
				---[[
				--{priority = 1.0, type = {"Cannon", "Supply", "Ammo",}, unit = "inf_crate_usr"},

				--HMGs
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "m1917_30cal"},
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "m2_30cal_tripod"},
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "m2_50cal_tripod"},
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "maxim"},
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "ds39_stand"},
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "sg43_stand"},
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "dshk_stan"},
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "dshk_aa"},
				--Anti Aircraft
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "50cal_quad_m45"},
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "40mm_m1"},
				{priority = 1.0, type = {"Cannon", "AA", "AT",}, unit = "90mm_m1a1"},
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "25mm_72k"},
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "37mm_61k"},
				{priority = 1.0, type = {"Cannon", "AA", "AT",}, unit = "76mm_m1938"},
				{priority = 1.0, type = {"Cannon", "AA", "AT",}, unit = "85mm_52k"},
				--Anti Tank
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "37mm_m3a1"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "57mm_m1"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "57mm_m1_late"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "75mm_m1897"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "76mm_m5_m1"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "76mm_m5_m6"},
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
				{priority = 1.0, type = {"Cannon", "Mortar",}, unit = "60mm_m2"},
				{priority = 1.0, type = {"Cannon", "Mortar",}, unit = "81mm_m1"},
				{priority = 1.0, type = {"Cannon", "Mortar",}, unit = "107mm_m2"},
				{priority = 1.0, type = {"Cannon", "Mortar",}, unit = "82mm_bm37"},
				{priority = 1.0, type = {"Cannon", "Mortar",}, unit = "120mm_pm38"},
				--Infantry Support
				{priority = 1.0, type = {"Cannon", "Support",}, unit = "75mm_m3a3"},
				{priority = 1.0, type = {"Cannon", "Support",}, unit = "75mm_m1a1"},
				{priority = 1.0, type = {"Cannon", "Support",}, unit = "76mm_m1927"},
				{priority = 1.0, type = {"Cannon", "Support",}, unit = "76mm_m43"},
				--Artillery
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "105mm_m2a1ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "105mm_m3ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "114mm_m1ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "155mm_schneider_usai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "155mm_m1ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "155mm_gpf_usai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "155mm_m1a1_longtomai"},
				{priority = 1.0, type = {"Cannon", "Artillery", "Big_gun",}, unit = "203mm_m1ai"},
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
				--Rocket Artillery
				--]]

			-- Wheel vehicles
				---[[
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Transport",}, unit = "willys_mb"},
				{priority = 1.0, type = {"Vehicle", "MG",}, unit = "willys_mb_30cal"},
				{priority = 1.0, type = {"Vehicle", "MG",}, unit = "willys_mb_50cal"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Transport",}, unit = "wc51"},
				{priority = 1.0, type = {"Vehicle", "MG",}, unit = "wc52_50cal"},
				{priority = 1.0, type = {"Vehicle", "AT",}, unit = "m6_gmc"},

				{priority = 1.0, type = {"Armored", "MG",}, unit = "m20"},
				{priority = 1.0, type = {"Armored", "AT",}, unit = "m8_greyhound_early"},
				{priority = 1.0, type = {"Armored", "AT",}, unit = "m8_greyhound"},
				--{priority = 1.0, type = {"Vehicle", "MG", "Transport",}, unit = "m5_hst"},
				--{priority = 1.0, type = {"Armored", "Unarmed", "Transport",}, unit = "m3a1_transport"},
				{priority = 1.0, type = {"Armored", "MG", "Transport",}, unit = "m3a1_scout"},
				--{priority = 1.0, type = {"Armored", "MG", "Transport",}, unit = "m3a1_commander"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Transport",}, unit = "cckw"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Supply", "Ammo",}, unit = "cckw_art_ammo"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Supply", "Ammo",}, unit = "cckw_redball"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Supply", "Fuel",}, unit = "cckw_fuel"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed","Supply", "Engineer",}, unit = "cckw_engineer"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed","Supply", "Engineer",}, unit = "cckw_engineer_late"},
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
				--]]

			-- Halftracks
				---[[
				{priority = 1.0, type = {"Armored", "MG", "Transport",}, unit = "m2_halftrack"},
				{priority = 1.0, type = {"Armored", "MG", "Transport",}, unit = "m3_halftrack"},
				{priority = 1.0, type = {"Armored", "MG", "Transport",}, unit = "m3a1_halftrack"},
				{priority = 1.0, type = {"Armored", "Mortar",}, unit = "m4_mortar_carrier"},
				{priority = 1.0, type = {"Armored", "Mortar",}, unit = "m4a1_mortar_carrier"},
				{priority = 1.0, type = {"Armored", "Mortar",}, unit = "m21_mortar_carrier"},
				{priority = 1.0, type = {"Armored", "AA",}, unit = "m13_mgmc"},
				{priority = 1.0, type = {"Armored", "AA",}, unit = "m15a1_cgmc"},
				{priority = 1.0, type = {"Armored", "AA",}, unit = "m16_mgmc"},

				{priority = 1.0, type = {"Armored", "AT",}, unit = "m3_gmc"},
				{priority = 1.0, type = {"Armored", "AT",}, unit = "m3a1_gmc"},
				{priority = 1.0, type = {"Armored", "Support",}, unit = "t30_hmc"},
				{priority = 1.0, type = {"Armored", "Artillery",}, unit = "t19_hmc"},
				
				{priority = 1.0, type = {"Armored", "MG",}, unit = "t20"},
				{priority = 1.0, type = {"Armored", "MG",}, unit = "t27"},
				--]]

			-- Tanks
				---[[
				{priority = 1.0, type = {"Tank", "Light",}, unit = "m3_stuart_early"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "m3_stuart_late"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "m3a1_stuart"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "m5a1_stuart"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "m5a1_stuart_late"},
				{priority = 1.0, type = {"Tank", "Light", "Support",}, unit = "m8_hmc"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "m24_chaffee"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "lvt4"},

				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m3_lee"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m4_75_early"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m4_75_early_armor"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m4_75_late"},
				{priority = 1.0, type = {"Tank", "Medium", "Support",}, unit = "m4_105"},

				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m4a1_75_early"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m4a1_75_mid"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m4a1_75_mid_armor"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m4a1_75_late"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "t1e3_m4a1_75"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m4a1_76w"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m4a1_76w_mid"},
		
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m4a3_75_late"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m4a3_75w_early"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m4a3_75w"},
				{priority = 1.0, type = {"Tank", "Medium", "Elite",}, unit = "m4a3_75w_e4_5"},
				{priority = 1.0, type = {"Tank", "Medium", "Support", "Elite", "Big_gun",}, unit = "m4a3_105"},
				{priority = 1.0, type = {"Tank", "Medium", "Support", "Elite", "Big_gun",}, unit = "m4a3_105_hvss"},

				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m4a3_76w"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m4a3_76w_hvss"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m4a3_76w_field1"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m4a3e2_75"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m4a3e2_76"},
				{priority = 1.0, type = {"Tank", "Medium", "Artillery", "Elite", "Rocket_Arty",}, unit = "m4a3_calliope"},

				{priority = 1.0, type = {"Tank", "Heavy", "Elite",}, unit = "m26_pershing"},
				{priority = 1.0, type = {"Tank", "Heavy", "Elite",}, unit = "t26e4"},
				{priority = 1.0, type = {"Tank", "Medium", "Miner",}, unit = "t1e3_m4a1_75"},
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
				{priority = 1.0, type = {"Tank", "Light", "AT",}, unit = "m10_gmc"},
				{priority = 1.0, type = {"Tank", "Light", "AT",}, unit = "m10_gmc_late"},
				{priority = 1.0, type = {"Tank", "Light", "AT",}, unit = "m18_hellcat"},
				{priority = 1.0, type = {"Tank", "Light", "AT",}, unit = "m18_hellcat_late"},

				{priority = 1.0, type = {"Tank", "Light", "AT",}, unit = "m36_gmc"},
				{priority = 1.0, type = {"Tank", "Medium", "AT",}, unit = "m36b1_gmc"},

				{priority = 1.0, type = {"Tank", "Medium", "Artillery",}, unit = "m7_hmc"},
				{priority = 1.0, type = {"Tank", "Medium", "Artillery",}, unit = "m7b1_hmc"},
				{priority = 1.0, type = {"Tank", "Medium", "Artillery",}, unit = "m12_gmc"},
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
                
				--]]
			---STUFF
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "sherman5c"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "sherman3_late"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "37mm_m3"},
			-- Cannons
				---[[
				--{priority = 1.0, type = {"Cannon", "Supply", "Ammo",}, unit = "inf_crate_usr"},
				--{priority = 1.0, type = {"Cannon", "Supply", "Ammo",}, unit = "ap_2"},

				--HMGs
				
				--Anti_Aircraft
				
				--Anti_Tank
				
				--Mortars
				
				--Infantry_Support
				
				--Artillery
				
				--]]

			-- Wheeled vehicles
				---[[
				
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Transport",}, unit = "gaz_aaa"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Transport",}, unit = "zis5"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Supply", "Ammo",}, unit = "gaz_aaa_supply"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Supply", "Fuel",}, unit = "gaz_fuel"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed","Supply", "Engineer",}, unit = "zis5eng"},
				--]]

			-- Tankettes
				---[[
				
				--]]

			-- Tanks
				---[[
				
				--]]

			-- Self-Propelled Guns
				---[[
				
				--]]

			--Aircraft
				
			---]====]
			--MACE
			
				-- {priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_cossacks_con(usr)"},
				-- {priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_marines_late_con(usr)"},
				-- {priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_marines_guards_con(usr)"},
				
				-- {priority = 1.0, type = {"Vehicle", "AA", "AT",}, unit = "zsu_29k"},
				
				-- {priority = 1.0, type = {"Tank", "Light",}, unit = "t50e"},
				
				-- {priority = 1.0, type = {"Tank", "Light",}, unit = "t70_45"},
				-- {priority = 1.0, type = {"Tank", "Light", "AA",}, unit = "zsu_37"},
				-- {priority = 1.0, type = {"Tank", "Light", "AA",}, unit = "zut_37"},
				-- {priority = 1.0, type = {"Tank", "Light", "Artillery",}, unit = "bm8_24"},
				-- {priority = 1.0, type = {"Tank", "Light", "Artillery",}, unit = "rbt_5"},

				-- {priority = 1.0, type = {"Tank", "Medium",}, unit = "t34_100"},
				-- {priority = 1.0, type = {"Tank", "Medium",}, unit = "t44"},
				-- {priority = 1.0, type = {"Tank", "Medium",}, unit = "t44_122"},
				-- {priority = 1.0, type = {"Tank", "Medium",}, unit = "t28_40"},
				-- {priority = 1.0, type = {"Tank", "Medium",}, unit = "ussr_m3_medium"},
				-- {priority = 1.0, type = {"Tank", "Medium",}, unit = "t28_85"},
				-- {priority = 1.0, type = {"Tank", "Medium",}, unit = "t29"},
				
				-- {priority = 1.0, type = {"Tank", "Heavy",}, unit = "matilda_f96"},
				-- {priority = 1.0, type = {"Tank", "Heavy",}, unit = "kv_220"},
				-- {priority = 1.0, type = {"Tank", "Heavy",}, unit = "kv220"},
				-- {priority = 1.0, type = {"Tank", "Heavy",}, unit = "kv2_zis6"},
				-- {priority = 1.0, type = {"Tank", "Heavy",}, unit = "kv4b"},
				-- {priority = 1.0, type = {"Tank", "Heavy",}, unit = "kv5"},
				-- {priority = 1.0, type = {"Tank", "Heavy",}, unit = "kv2_zis6"},
				-- {priority = 1.0, type = {"Tank", "Heavy",}, unit = "is_3"},
				-- {priority = 1.0, type = {"Tank", "Heavy",}, unit = "is_4"},
				-- {priority = 1.0, type = {"Tank", "Heavy",}, unit = "is_4m"},
				-- {priority = 1.0, type = {"Tank", "Heavy",}, unit = "is_6"},
				-- {priority = 1.0, type = {"Tank", "Heavy",}, unit = "is_7"},
				
				-- {priority = 1.0, type = {"Tank", "Heavy", "AT",}, unit = "isu152"},
			---]====]
			--Aircraft
			{priority = 1.0, type = {"Aircraft", "Fighter",}, unit = "yak1_ser69_ai"},
				{priority = 1.0, type = {"Aircraft", "Bomber",}, unit = "il2_mod42_ai"},
				{priority = 1.0, type = {"Aircraft", "Fighter",}, unit = "p47_d22_ai"},
				{priority = 1.0, type = {"Aircraft", "Bomber",}, unit = "p47_d22_bomber_ai"},
				
		}
	}
}