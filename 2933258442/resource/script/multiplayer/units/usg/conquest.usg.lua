Purchases["conquest.usg"] = {
	{Repeat = 0, --infinite

        Units = {
			---[====[
			-- Infantry
				---[[
				{priority = 1.0, type = {"Infantry", "Team", "Command",}, unit = "single_officer(usg)"},
				--{priority = 1.0, type = {"Infantry", "Squad", "Command",}, unit = "squad_officer_con(usg)"},
				--{priority = 1.0, type = {"Infantry", "Squad", "Command",}, unit = "squad_officer_m3a1_commander_con"},
				-- {priority =  0.01, type = {"Infantry", "Squad", "Command",}, unit = "squad_officer_m3a1_halftrack_con"},

				{priority = 0.8, type = {"Infantry", "Squad",}, unit = "squad_mp_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_45th_rifle_con(usg)"},

				--Recon
				--{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_1st_arm_recon_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_cav_late_con1(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_cav_late_con2(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_82nd_recon_con(usg)"},

				--T2
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifle_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_1st_arm_rifle_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_1st_arm_rifle_mech_con(usg)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifle_late_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_arm_rifle_mech_late_con(usg)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_eng_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_eng_mech_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_eng_mech_late_con(usg)"},

				--T2+
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_vet_rifle_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_vet_rifle_late_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_2nd_arm_rifle_mech_late_con(usg)"},

				--T3
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_82nd_glider_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_82nd_glider_pio_con(usg)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_mountain_late_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_mountain_pio_late_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_101st_glider_late_con(usg)"},

				--T3+
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_1st_rifle_late_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_1st_arm_rifle_mech_late_con(usg)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_82nd_glider_late_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_82nd_glider_pio_late_con(usg)"},

				--T4
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_ranger_assault_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_ranger_assault_mg_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_ranger_assault_late_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_ranger_assault_mg_late_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_ranger_special_late_con(usg)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_82nd_eng_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_82nd_con(usg)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "1st_special_con(usg)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_101st_eng_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_101st_con(usg)"},

				--T4+
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_82nd_eng_late_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_82nd_late_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_82nd_demo_late_con(usg)"},

				--Singles/Teams
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at1_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at2_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at3_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at4_con(usg)"},
				
				--{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_medic(usg)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_riflegrenade_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_riflegrenade2_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_ap_miner(usg)"},
				{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_at_miner(usg)"},
				{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_engineer(usg)"},
				{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_flamer(usg)"},
				--{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_tankman(usg)"},
				{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_sniper(usg)"},
				{priority = 1.0, type = {"Infantry", "Team", "Signaller",}, unit = "single_signaller(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Wave",}, unit = "squad_sicherung_con(usg)"},
			{priority = 1.0, type = {"Infantry", "Team", "Command",}, unit = "single_officer(usg)"},
				--{priority = 1.0, type = {"Infantry", "Squad", "Command",}, unit = "squad_officer_con(usg)"},
				--{priority = 1.0, type = {"Infantry", "Squad", "Command",}, unit = "squad_officer_kubel_con"},
				--{priority = 1.0, type = {"Infantry", "Squad", "Command",}, unit = "squad_officer_250_3_con"},

				--T1
				{priority = 1.0, type = {"Infantry", "Squad", "Wave",}, unit = "squad_osttruppen_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Wave",}, unit = "squad_strafbatallion_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_luftwaffe_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Wave",}, unit = "squad_volkssturm_con(usg)"},

				--T2
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_sicherung_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_recon_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_regular_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_pionier_con(usg)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_lw_jaeger_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_grenadier_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_sturmgren_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_sturmgren_heavy_con(usg)"},

				{priority = 1.0, type = {"Infantry", "Squad", "Wave",}, unit = "squad_volksg_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Wave",}, unit = "squad_volksg_sturm_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_volksg_heavy_con(usg)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_recon_motor_con"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_regular_motor_con"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_recon_armor_con"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_pz_recon_armor_late_con"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_regular_armor_con"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_pzgren_motor_con"},
				{priority = 1.0, type = {"Infantry", "Squad", "Mechanized_Infantry",}, unit = "squad_pzgren_armor_con"},
				{priority = 1.0, type = {"Infantry", "Squad", "Mechanized_Infantry",}, unit = "squad_sturm_pzgren_armor_con"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_pz_pio_con"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_pz_pio_late_con"},

				--T2+
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_regular_vet_con(usg)"},

				--T3
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_fusilier_late_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_fusilier_smg_late_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_jaeger_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_sturmjager_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_sturm_begleitgren_motor_con"},

				--T3+
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_gd_motor_con"},
				{priority = 1.0, type = {"Infantry", "Squad", "Mechanized_Infantry",}, unit = "squad_pzg_gd_armor_con"},
				{priority = 1.0, type = {"Infantry", "Squad", "Mechanized_Infantry",}, unit = "squad_pzg_lehr_armor_con"},
				{priority = 1.0, type = {"Infantry", "Squad", "Mechanized_Infantry",}, unit = "squad_sturm_pzg_lehr_armor_con"},

				--T4
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_blau_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_gebirgsjaeger_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_gebirgsjaeger_late_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_gebirgs_recon_late_con(usg)"},

				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_brandenburger_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_brandenburger_44_con(usg)"},

				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_fallschirmjaeger_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_fallschirmjaeger_motor_con"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_fallschirm_recon_late_con(usg)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_fallschirmjaeger_late_motor_con"},

				{priority = 1.0, type = {"Aircraft", "Paratrooper", "Infantry", "Squad",}, unit = "squad_fallschirmjaeger_para_con_late"},
				{priority = 1.0, type = {"Aircraft", "Paratrooper", "Infantry", "Squad",}, unit = "squad_fallschirmjaeger_para_con"},

			-- Cannons
				---[[
				--{priority = 1.0, type = {"Cannon", "Supply", "Ammo",}, unit = "inf_crate_usr"},

				--HMGs
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "m1917_30cal"},
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "m2_30cal_tripod"},
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "m2_50cal_tripod"},
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "mg34_lafette",},
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "mg42_lafette",},
			--	{priority = 1.0, type = {"Cannon", "MG",}, unit = "panzernest_krab_ger"},
				--Anti Aircraft
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "50cal_quad_m45"},
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "40mm_m1"},
				{priority = 1.0, type = {"Cannon", "AA", "AT",}, unit = "90mm_m1a1"},
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "20mm_flak30"},
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "20mm_flak38"},
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "37mm_flak37"},
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "50mm_flak41"},
				{priority = 1.0, type = {"Cannon", "AA", "AT",}, unit = "88mm_flak18"},
				{priority = 1.0, type = {"Cannon", "AA", "AT",}, unit = "88mm_flak36"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "28mm_pzb41"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "37mm_pak36"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "47mm_pakt"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "50mm_pak38"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "75mm_pak9738"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "75mm_pak40"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "88mm_pak4341"},
				-- {priority = 1.0, type = {"Cannon", "AT",}, unit = "pak_44"},
				--Anti Tank
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "37mm_m3a1"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "57mm_m1"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "57mm_m1_late"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "75mm_m1897"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "76mm_m5_m1"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "76mm_m5_m6"},
				--Mortars
				{priority = 1.0, type = {"Cannon", "Mortar",}, unit = "60mm_m2"},
				{priority = 1.0, type = {"Cannon", "Mortar",}, unit = "81mm_m1"},
				{priority = 1.0, type = {"Cannon", "Mortar",}, unit = "107mm_m2"},
				{priority = 1.0, type = {"Cannon", "Mortar",}, unit = "80mm_sgrw34"},
				{priority = 1.0, type = {"Cannon", "Mortar",}, unit = "100mm_nbw35"},
				{priority = 1.0, type = {"Cannon", "Mortar",}, unit = "120mm_sgrw42"},
				{priority = 1.0, type = {"Cannon", "Mortar", "Big_gun",}, unit = "200mm_ldgw40"},
				--Infantry Support
				{priority = 1.0, type = {"Cannon", "Support",}, unit = "75mm_m3a3"},
				{priority = 1.0, type = {"Cannon", "Support",}, unit = "75mm_m1a1"},
				{priority = 1.0, type = {"Cannon", "Support",}, unit = "75mm_leig18"},
				{priority = 1.0, type = {"Cannon", "Support",}, unit = "75mm_lg40"},
				{priority = 1.0, type = {"Cannon", "Support", "Big_gun",}, unit = "150mm_sig33"},
				--Artillery
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "105mm_m2a1ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "105mm_m3ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "114mm_m1ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "155mm_schneider_usai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "155mm_m1ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "155mm_gpf_usai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "155mm_m1a1_longtomai"},
				{priority = 1.0, type = {"Cannon", "Artillery", "Big_gun",}, unit = "203mm_m1ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "105mm_lefh18ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "105mm_sk18ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "150mm_sfh18ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "170mm_k18ai"},
				-- {priority = 1.0, type = {"Cannon", "Artillery",}, unit = "155mm_gpf_ger"},
				
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "210mm_morser18ai"},
				{priority = 1.0, type = {"Cannon", "Artillery", "Big_gun",}, unit = "600mm_thorai"},
				--Rocket Artillery
				{priority = 1.0, type = {"Cannon", "Artillery", "Rocket_Arty",}, unit = "150mm_nebelwerfer41ai"},
				{priority = 1.0, type = {"Cannon", "Artillery", "Rocket_Arty",}, unit = "210mm_nebelwerfer42ai"},
				{priority = 1.0, type = {"Cannon", "Artillery", "Rocket_Arty",}, unit = "300mm_nebelwerfer42ai"},
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
				{priority = 1.0, type = {"Vehicle", "MG",}, unit = "bmw_r71"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Transport",}, unit = "kubelwagen"},
				{priority = 1.0, type = {"Vehicle", "MG",}, unit = "kubelwagen_mg"},
				{priority = 1.0, type = {"Vehicle", "MG",}, unit = "kubelwagen_dak"},
				{priority = 1.0, type = {"Vehicle", "AA",}, unit = "blitz3_6_flak30"},
				{priority = 1.0, type = {"Armored", "MG",}, unit = "sdkfz221"},
				{priority = 1.0, type = {"Armored", "AA",}, unit = "sdkfz222a"},
				{priority = 1.0, type = {"Armored", "AA",}, unit = "sdkfz231"},
				{priority = 0.75, type = {"Armored",}, unit = "p204_f"},
				{priority = 1.0, type = {"Armored", "AA",}, unit = "sdkfz234_1"},
				{priority = 1.0, type = {"Armored", "AT",}, unit = "sdkfz234_2"},
				{priority = 1.0, type = {"Armored", "Support",}, unit = "sdkfz234_3"},
				{priority = 1.0, type = {"Armored", "AT",}, unit = "sdkfz234_4"},
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
				{priority = 1.0, type = {"Armored", "MG",}, unit = "sdkfz250a_1"},
				{priority = 1.0, type = {"Armored", "AA",}, unit = "sdkfz250a_9"},
				{priority = 1.0, type = {"Armored", "AT",}, unit = "sdkfz250a_11"},
				{priority = 1.0, type = {"Armored", "MG", "Transport",}, unit = "sdkfz251c"},
				{priority = 1.0, type = {"Armored", "Mortar",}, unit = "sdkfz251c_2"},
				{priority = 1.0, type = {"Armored", "MG", "Transport",}, unit = "sdkfz251d_1"},
				{priority = 1.0, type = {"Armored", "Artillery", "Rocket_Arty",}, unit = "sdkfz251d_1_stuka"},
				{priority = 1.0, type = {"Armored", "MG",}, unit = "sdkfz251d_16"},
				{priority = 1.0, type = {"Armored", "AA",}, unit = "sdkfz251d_17"},
				{priority = 1.0, type = {"Armored", "AA",}, unit = "sdkfz251d_21"},
				{priority = 1.0, type = {"Armored", "AT",}, unit = "sdkfz251d_22"},
				{priority = 1.0, type = {"Vehicle", "AA",}, unit = "sdkfz10_4"},
				{priority = 1.0, type = {"Vehicle", "AA",}, unit = "sdkfz6_2"},
				{priority = 1.0, type = {"Armored", "AA",}, unit = "sdkfz7_2"},
				{priority = 1.0, type = {"Vehicle", "AT",}, unit = "sdkfz10_pak38"},
				{priority = 1.0, type = {"Armored", "AA", "AT",}, unit = "sdkfz8_flak18"},
				{priority = 1.0, type = {"Armored", "Artillery", "Rocket_Arty",}, unit = "panzerwerfer42"},
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
				{priority = 1.0, type = {"Tank", "Light",}, unit = "panzer1b"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "panzer1f"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "panzer2c"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "panzer2f"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "panzer2l"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "pz35t"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "pz38t_a"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "pz38t_f"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "pz38t_g"},
				{priority = 0.75, type = {"Tank", "Light",}, unit = "pz38h_735"},
				{priority = 0.75, type = {"Tank", "Light", "Artillery", "Rocket_Arty",}, unit = "pz38h_w40"},
				{priority = 0.75, type = {"Tank", "Medium",}, unit = "panzer35s"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "panzer3e"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "panzer3f"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "panzer3j"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "panzer3j1"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "panzer3l"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "panzer3m"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "panzer3n"},
				{priority = 1.0, type = {"Tank", "Medium", "Flamer",}, unit = "panzer3_flamm"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "panzer4d"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "panzer4f1"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "panzer4f2"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "panzer4g"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "panzer4h"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "panzer4j"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "panzer5d"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "panzer5a"},
				{priority = 1.0, type = {"Tank", "Heavy", "Elite",}, unit = "panzer5g"},
				{priority = 0.75, type = {"Tank", "Heavy",}, unit = "panzerb2"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "tiger1h"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "tiger1e"},
				{priority = 1.0, type = {"Tank", "Heavy", "Elite",}, unit = "tiger1hunt"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "tiger2p"},
				{priority = 1.0, type = {"Tank", "Heavy", "Elite",}, unit = "tiger2h"},
				{priority = 1.0, type = {"Armored", "MG", "Miner"}, unit = "pz3m"},
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
				{priority = 1.0, type = {"Tank", "Light", "AT",}, unit = "panzerjager1"},
				{priority = 1.0, type = {"Tank", "Light", "AT",}, unit = "marder2"},
				{priority = 1.0, type = {"Tank", "Light", "AT",}, unit = "marder3m"},
				{priority = 1.0, type = {"Tank", "Light", "AT",}, unit = "hetzer"},
				{priority = 1.0, type = {"Tank", "Light", "AA",}, unit = "grille_m"},
				{priority = 1.0, type = {"Tank", "Light", "Support", "Big_gun",}, unit = "bison"},
				{priority = 1.0, type = {"Tank", "Light", "Artillery", "Big_gun",}, unit = "grille_k"},
				{priority = 1.0, type = {"Tank", "Light", "Artillery",}, unit = "wespe"},
				{priority = 1.0, type = {"Tank", "Medium", "AT",}, unit = "stug3b"},
				{priority = 1.0, type = {"Tank", "Medium", "AT",}, unit = "stug3f"},
				{priority = 1.0, type = {"Tank", "Medium", "AT",}, unit = "stug3g"},
				{priority = 1.0, type = {"Tank", "Medium", "AT",}, unit = "stug3g_late"},
				{priority = 1.0, type = {"Tank", "Medium", "AT",}, unit = "jagdpanzer4_l48_early"},
				{priority = 1.0, type = {"Tank", "Medium", "AT",}, unit = "jagdpanzer4_l48"},
				{priority = 1.0, type = {"Tank", "Medium", "AT",}, unit = "panzer4_70_v"},
				{priority = 1.0, type = {"Tank", "Medium", "AT",}, unit = "nashorn"},
				{priority = 1.0, type = {"Tank", "Medium", "AA",}, unit = "wirbelwind"},
				{priority = 1.0, type = {"Tank", "Medium", "AA",}, unit = "ostwind"},
				{priority = 1.0, type = {"Tank", "Medium", "Support", "Big_gun",}, unit = "stuh42"},
				{priority = 1.0, type = {"Tank", "Medium", "Support", "Big_gun",}, unit = "sig33b"},
				{priority = 1.0, type = {"Tank", "Medium", "Support", "Big_gun",}, unit = "sturmpanzer4"},
				{priority = 1.0, type = {"Tank", "Medium", "Artillery",}, unit = "hummel"},
				{priority = 1.0, type = {"Tank", "Heavy", "AT",}, unit = "ferdinand"},
				{priority = 1.0, type = {"Tank", "Heavy", "AT",}, unit = "jagdpanther"},
				{priority = 1.0, type = {"Tank", "Heavy", "AT",}, unit = "jagdtiger"},
				{priority = 1.0, type = {"Tank", "Heavy", "AT", "Big_gun",}, unit = "sturmtiger"},
				--]]
               {priority = 1.0, type = {"Aircraft", "Fighter",}, unit = "bf109_f4_ai"},
				{priority = 1.0, type = {"Aircraft", "Bomber",}, unit = "bf110_e2_ai"},
				{priority = 1.0, type = {"Aircraft", "Fighter",}, unit = "p47_d22_ai"},
				{priority = 1.0, type = {"Aircraft", "Bomber",}, unit = "p47_d22_bomber_ai"},
				--]]
			---STUFF
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "sherman5c"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "sherman3_late"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "37mm_m3"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "37mm_pak36_late"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "50mm_pak38_late"},
				{priority = 1.0, type = {"Cannon", "Support", "Big_gun",}, unit = "150mm_sig33_late"},				
			-- Cannons
				---[[
				--{priority = 1.0, type = {"Cannon", "Supply", "Ammo",}, unit = "inf_crate_ger"},
				--{priority = 1.0, type = {"Cannon", "Supply", "Ammo",}, unit = "ammo_trailer"},
				--{priority = 1.0, type = {"Cannon", "Spotlight",}, unit = "150mm_sw34_ger"},

				--HMGs
				
				--Anti Aircraft
				
				--Anti Tank
				

				--Mortars
				
				--Infantry Support
				
				--Artillery
				
				--Rocket Artillery
				
				--]]

			-- Wheel vehicles
				---[[
				
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Transport",}, unit = "blitz3_6"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Supply", "Ammo",}, unit = "blitz3_6_art_ammo"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Supply", "Fuel",}, unit = "blitz3_6_fuel"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed","Supply", "Engineer",}, unit = "blitz3_6_engineering"},
				
				--]]

			-- Halftracks
				---[[
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Supply", "Engineer",}, unit = "kettenkrad_eng"},
				
				
				--]]

			-- Tanks
				---[[
				
				--]]

			-- Self-Propelled Guns
				---[[
				
				--]]

			--Aircraft
				
				
				
			--MACE
				---[[
				-- {priority = 1.0, type = {"Tank", "Light",}, unit = "pz38h_735"},
				
				-- {priority = 1.0, type = {"Cannon", "AT",}, unit = "88mm-raketenwerfer43"},
				-- {priority = 1.0, type = {"Armored", "AT",}, unit = "sdkfz221_spzb41"},
				-- {priority = 1.0, type = {"Armored", "AT",}, unit = "sdkfz301wanze"},
				-- {priority = 1.0, type = {"Armored", "Artillery",}, unit = "sdkfz251c_stuka"},
				-- {priority = 1.0, type = {"Armored", "Artillery",}, unit = "sdkfz4_panzerwerfer"},

				-- {priority = 1.0, type = {"Tank", "Light",}, unit = "pzkpfw_2hvk903"},
				-- {priority = 1.0, type = {"Tank", "Medium",}, unit = "panther_ii-hd"},
				-- {priority = 1.0, type = {"Tank", "Medium",}, unit = "ezart"},

				-- {priority = 1.0, type = {"Tank", "Light", "AA",}, unit = "flakpanzer1a"},
				-- {priority = 1.0, type = {"Tank", "Light", "AA",}, unit = "coelian_i"},

				-- {priority = 1.0, type = {"Tank", "Light", "AT",}, unit = "marder_1fcm_36"},
				-- {priority = 1.0, type = {"Tank", "Light", "Artillery",}, unit = "wespe"},
				-- {priority = 1.0, type = {"Tank", "Light", "Support",}, unit = "bison2"},
				-- {priority = 1.0, type = {"Tank", "Heavy", "AT", "Support",}, unit = "dicker_max"},
				-- {priority = 1.0, type = {"Tank", "Medium", "Artillery",}, unit = "geschuetzwagen_ivb"},
				-- {priority = 1.0, type = {"Tank", "Heavy", "AT",}, unit = "nashorn"},
				-- {priority = 1.0, type = {"Tank", "Heavy", "Artillery",}, unit = "hummel"},

				-- {priority = 1.0, type = {"Tank", "Heavy", "AT",}, unit = "elefant"},
				-- {priority = 1.0, type = {"Tank", "Medium", "AT",}, unit = "jagdpanzer_iv_a"},
				-- {priority = 1.0, type = {"Tank", "Medium", "AT",}, unit = "jagdpanzer_iv_a_armor"},
				-- {priority = 1.0, type = {"Tank", "Medium", "AT",}, unit = "jagdpziv_70"},

				-- {priority = 1.0, type = {"Tank", "Heavy",}, unit = "nbfz"},
				-- {priority = 1.0, type = {"Tank", "Heavy",}, unit = "pz6p_panzerbefehiswagen"},
				-- {priority = 1.0, type = {"Tank", "Heavy",}, unit = "pz6p_panzerbefehiswagen_commander"},
				-- {priority = 1.0, type = {"Tank", "Heavy",}, unit = "pzkpfw_6_ausf_b_tiger_sla16"},
				-- {priority = 1.0, type = {"Tank", "Heavy",}, unit = "pz6bh_105mm"},
				-- {priority = 1.0, type = {"Tank", "Heavy",}, unit = "pzkpfw_8_maus"},
				
				---Beute Panzers
				-- {priority = 1.0, type = {"Tank", "Light",}, unit = "t60r"},
				-- {priority = 1.0, type = {"Tank", "Medium",}, unit = "pzkw747_76_41"},
				-- {priority = 1.0, type = {"Tank", "Medium",}, unit = "pzkw747_76_43"},
				-- {priority = 1.0, type = {"Tank", "Medium",}, unit = "pzkw747_57_41"},
				-- {priority = 1.0, type = {"Tank", "Medium",}, unit = "pzkw747_57_43"},
				-- {priority = 1.0, type = {"Tank", "Medium",}, unit = "pzkw747_85"},
				-- {priority = 1.0, type = {"Tank", "Heavy",}, unit = "pzkw753_40"},
				-- {priority = 1.0, type = {"Tank", "Heavy",}, unit = "pzkw753_41"},
				-- {priority = 1.0, type = {"Tank", "Heavy",}, unit = "pzkw755_85"},
				-- {priority = 1.0, type = {"Tank", "Heavy",}, unit = "pzkw755_s"},
				-- {priority = 1.0, type = {"Tank", "Heavy", "Support",}, unit = "kv2_754r"},
				-- {priority = 1.0, type = {"Tank", "Medium",}, unit = "beutepanzer_m4a2"},
			-- -]====]
			--Aircraft
				
		}
	}
}