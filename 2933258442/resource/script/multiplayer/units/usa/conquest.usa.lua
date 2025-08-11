Purchases["conquest.usa"] = {
	{Repeat = 0, --infinite

        Units = {
			---[====[
			-- Infantry
				---[[
				-- {priority = 1.0, type = {"Infantry", "Team", "Command",}, unit = "single_officer(usa)"},
				--{priority = 1.0, type = {"Infantry", "Squad", "Command",}, unit = "squad_officer_con(usa)"},
				--{priority = 1.0, type = {"Infantry", "Squad", "Command",}, unit = "squad_officer_m3a1_commander_con"},
				-- {priority =  0.01, type = {"Infantry", "Squad", "Command",}, unit = "squad_officer_m3a1_halftrack_con"},

				{priority = 0.8, type = {"Infantry", "Squad","Wave",}, unit = "squad_mp_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Squad","Wave",}, unit = "squad_45th_rifle_con(usa)"},

				--Recon
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_1st_arm_recon_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_cav_late_con1(usa)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_cav_late_con2(usa)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_82nd_recon_con(usa)"},

				--T2
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifle_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_1st_arm_rifle_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Mechanized_Infantry",}, unit = "squad_1st_arm_rifle_mech_con(usa)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifle_late_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Mechanized_Infantry",}, unit = "squad_arm_rifle_mech_late_con(usa)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_eng_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Mechanized_Infantry",}, unit = "squad_eng_mech_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Mechanized_Infantry",}, unit = "squad_eng_mech_late_con(usa)"},

				--T2+
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_vet_rifle_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_vet_rifle_late_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Mechanized_Infantry",}, unit = "squad_2nd_arm_rifle_mech_late_con(usa)"},

				--T3
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_82nd_glider_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Flamer",}, unit = "squad_82nd_glider_pio_con(usa)"},

				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_mountain_late_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_mountain_pio_late_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_101st_glider_late_con(usa)"},

				--T3+
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_1st_rifle_late_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Mechanized_Infantry",}, unit = "squad_1st_arm_rifle_mech_late_con(usa)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_82nd_glider_late_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Flamer",}, unit = "squad_82nd_glider_pio_late_con(usa)"},

				--T4
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_ranger_assault_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_ranger_assault_mg_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_ranger_assault_late_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_ranger_assault_mg_late_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_ranger_special_late_con(usa)"},

				{priority = 1.0, type = {"Infantry", "Squad", "Flamer",}, unit = "squad_82nd_eng_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_82nd_con(usa)"},

				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "1st_special_con(usa)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_101st_eng_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_101st_con(usa)"},

				--T4+
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_82nd_eng_late_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_82nd_late_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_82nd_demo_late_con(usa)"},

				--Singles/Teams
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at1_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at2_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at3_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at4_con(usa)"},
				
				--{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_medic(usa)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_riflegrenade_con(usa)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_riflegrenade2_con(usa)"},
				--{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_ap_miner(usa)"},
				--{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_at_miner(usa)"},
				{priority = 1.0, type = {"Infantry", "Team", "Engineer",}, unit = "single_engineer(usa)"},
				{priority = 1.0, type = {"Infantry", "Team", "Flamer",}, unit = "single_flamer(usa)"},
				--{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_tankman(usa)"},
				{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_sniper(usa)"},
				{priority = 1.0, type = {"Infantry", "Team", "Signaller",}, unit = "single_signaller(usa)"},

				--]]

			-- Cannons
				---[[
				--{priority = 1.0, type = {"Cannon", "Supply", "Ammo",}, unit = "inf_crate_usa"},

				--HMGs
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "m1917_30cal"},
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "m2_30cal_tripod"},
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "m2_50cal_tripod"},
				--Anti Aircraft
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "50cal_quad_m45"},
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "40mm_m1"},
				{priority = 1.0, type = {"Cannon", "AA", "AT",}, unit = "90mm_m1a1"},
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
				--Infantry Support
				{priority = 1.0, type = {"Cannon", "Support",}, unit = "75mm_m3a3"},
				{priority = 1.0, type = {"Cannon", "Support",}, unit = "75mm_m1a1"},
				--Artillery
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "105mm_m2a1ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "105mm_m3ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "114mm_m1ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "155mm_schneider_usai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "155mm_m1ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "155mm_gpf_usai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "155mm_m1a1_longtomai"},
				{priority = 1.0, type = {"Cannon", "Artillery", "Big_gun",}, unit = "203mm_m1ai"},
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
				{priority = 1.0, type = {"Tank", "Medium", "Deminer",}, unit = "t1e3_m4a1_75"},
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
				--]]
			---]====]
			--Aircraft
				{priority = 1.0, type = {"Aircraft", "Fighter",}, unit = "p47_d22_ai"},
				{priority = 1.0, type = {"Aircraft", "Bomber",}, unit = "p47_d22_bomber_ai"},
				{priority = 0.5, type = {"Aircraft", "Paratrooper",}, unit = "squad_82nd_paras_glider_con"},
				{priority = 0.5, type = {"Aircraft", "Paratrooper",}, unit = "squad_82nd_paras_eng_con"},
				{priority = 0.5, type = {"Aircraft", "Paratrooper",}, unit = "squad_82nd_paras_con"},
				{priority = 0.5, type = {"Aircraft", "Paratrooper",}, unit = "squad_101st_paras_glider_con"},
				{priority = 0.5, type = {"Aircraft", "Paratrooper",}, unit = "squad_101st_paras_eng_con"},
				{priority = 0.5, type = {"Aircraft", "Paratrooper",}, unit = "squad_101st_paras_con"},
			---STUFF
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "sherman5c"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "sherman3_late"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "37mm_m3"},
		}
	}
}