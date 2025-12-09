Purchases["conquest.eng"] = {
	{Repeat = 0, --infinite
		Units = {
			---[====[
			-- Infantry
				---[[
				--{priority = 1.0, type = {"Infantry", "Team", "Command",}, unit = "single_officer(eng)"},
				--{priority = 1.0, type = {"Infantry", "Squad", "Command",}, unit = "squad_officer_con(eng)"},
				--{priority = 1.0, type = {"Infantry", "Squad", "Command",}, unit = "squad_officer_carrier_con"},
				--{priority = 1.0, type = {"Infantry", "Squad", "Command",}, unit = "squad_officer_m5a1_halftrack_con"},

				--T1
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rear_echelon_early_con(eng)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_brig_defense_mid_con(eng)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_div_defense_mg_mid_con(eng)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_brig_defense_late_con(eng)"},

				--Recon
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rec_mc_early_con(eng)"},
				{priority = 0.5, type = {"Infantry", "Squad",}, unit = "squad_rec_scout_early_con(eng)"}, --vehicle

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_recce_assault_mid_con(eng)"},
				{priority = 0.5, type = {"Infantry", "Squad",}, unit = "squad_recce_carrier_mid_con(eng)"}, --vehicle

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_recce_assault_late_con(eng)"},
				{priority = 0.5, type = {"Infantry", "Squad",}, unit = "squad_recce_assault_mot_late_con(eng)"}, --vehicle
				{priority = 0.5, type = {"Infantry", "Squad",}, unit = "squad_recce_carrier_late_con(eng)"}, --vehicle

				--T2
				{priority = 3.5, type = {"Infantry", "Squad",}, unit = "squad_rifle_early_con(eng)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_pio_early_con(eng)"},
				{priority = 0.5, type = {"Infantry", "Squad",}, unit = "squad_carrier_early_con(eng)"}, --vehicle

				{priority = 3.5, type = {"Infantry", "Squad",}, unit = "squad_rifle_mid_con(eng)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_r_eng_mid_con(eng)"},
				{priority = 0.5, type = {"Infantry", "Squad",}, unit = "squad_carrier_mid_con(eng)"}, --vehicle

				{priority = 3.5, type = {"Infantry", "Squad",}, unit = "squad_rifle_late_con(eng)"},
				{priority = 0.5, type = {"Infantry", "Squad",}, unit = "squad_rifle_mot_late_con(eng)"}, --vehicle
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_r_eng_late_con(eng)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_assault_pio_late_con(eng)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifle_late_con(can)"},
				{priority = 0.5, type = {"Infantry", "Squad",}, unit = "squad_rifle_mech_late_con(can)"}, --vehicle
				{priority = 0.5, type = {"Infantry", "Squad",}, unit = "squad_carrier_late_con(can)"}, --vehicle

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifle_late_con(pol)"},
				{priority = 0.5, type = {"Infantry", "Squad",}, unit = "squad_rifle_mech_late_con(pol)"}, --vehicle
				{priority = 0.5, type = {"Infantry", "Squad",}, unit = "squad_carrier_late_con(pol)"}, --vehicle

				--T2+
				{priority = 2.0, type = {"Infantry", "Squad",}, unit = "squad_vet_rifle_mid_con(eng)"},

				{priority = 2.0, type = {"Infantry", "Squad",}, unit = "squad_vet_rifle_late_con(eng)"},

				--T3
				{priority = 1.5, type = {"Infantry", "Squad",}, unit = "squad_51hl_rifle_early_con(eng)"},
				{priority = 0.5, type = {"Infantry", "Squad",}, unit = "squad_com_early_con(eng)"}, --stealth

				{priority = 1.5, type = {"Infantry", "Squad",}, unit = "squad_7th_ad_rifle_mid_con(eng)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rm_com_assault_mid_con(eng)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rn_com_beach_mid_con(eng)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_1st_airland_pio_mid_con(eng)"},
				{priority = 1.5, type = {"Infantry", "Squad",}, unit = "squad_1st_airland_rifle_mid_con(eng)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rm_com_assault_late_con(eng)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_6th_airland_recon_late_con(eng)"},
				{priority = 1.5, type = {"Infantry", "Squad",}, unit = "squad_6th_airland_rifle_late_con(eng)"},
				{priority = 1.5, type = {"Infantry", "Squad",}, unit = "squad_gds_ad_rifle_late_con(eng)"},
				{priority = 1.5, type = {"Infantry", "Squad",}, unit = "squad_com_rifle_late_con(eng)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_com_smg_s_late_con(eng)"},

				--T3+
				{priority = 1.5, type = {"Infantry", "Squad",}, unit = "squad_51hl_rifle_mid_con(eng)"},

				{priority = 1.5, type = {"Infantry", "Squad",}, unit = "squad_7th_ad_rifle_late_con(eng)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_7th_ad_pio_late_con(eng)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_7th_ad_eng_late_con(eng)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_1st_airland_recon_late_con(eng)"},
				{priority = 1.5, type = {"Infantry", "Squad",}, unit = "squad_1st_airland_rifle_late_con(eng)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_1st_airland_support_late_con(eng)"},

				--T4
				{priority = 1.5, type = {"Infantry", "Squad",}, unit = "squad_hl_bw_rifle_early_con(eng)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_hl_bw_inf_pio_early_con(eng)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_1st_para_recce_mid_con(eng)"},
				{priority = 1.5, type = {"Infantry", "Squad",}, unit = "squad_1st_para_rifle_mid_con(eng)"},
				{priority = 0.5, type = {"Infantry", "Squad",}, unit = "squad_com_rifle_mid_con(eng)"}, --stealth
				{priority = 0.5, type = {"Infantry", "Squad",}, unit = "squad_sas_mid_con(eng)"}, --stealth

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_6th_para_eng_late_con(eng)"},
				{priority = 1.5, type = {"Infantry", "Squad",}, unit = "squad_6th_para_rifle_late_con(eng)"},

				{priority = 1.0, type = {"Infantry", "Squad","AT",}, unit = "squad_1st_para_at_late_con(can)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_1st_para_protect_late_con(can)"},
				{priority = 1.5, type = {"Infantry", "Squad",}, unit = "squad_1st_para_rifle_late_con(can)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_1st_para_eng_late_con(pol)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_1st_para_eng_flame_late_con(pol)"},
				{priority = 1.5, type = {"Infantry", "Squad",}, unit = "squad_1st_para_rifle_late_con(pol)"},

				--T4+
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_1st_para_eng_late_con(eng)"},
				{priority = 1.5, type = {"Infantry", "Squad",}, unit = "squad_1st_para_rifle_late_con(eng)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_1st_para_recce_late_con(eng)"},
				{priority = 0.5, type = {"Infantry", "Squad",}, unit = "squad_sas_late_con(eng)"}, --stealth

				--Singles/Teams
				{priority = 1.5, type = {"Infantry", "Team", "AT",}, unit = "single_at_con(eng)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at1_con(eng)"},
				{priority = 1.5, type = {"Infantry", "Team", "AT",}, unit = "single_at2_con(eng)"},
				
				--{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_medic(eng)"},
				{priority = 1.5, type = {"Infantry", "Team", "AT",}, unit = "single_riflegrenade_con(eng)"},
				{priority = 0.5, type = {"Infantry", "Team",}, unit = "single_ap_miner(eng)"},
				{priority = 0.5, type = {"Infantry", "Team",}, unit = "single_at_miner(eng)"},
				{priority = 0.5, type = {"Infantry", "Team",}, unit = "single_engineer(eng)"},
				{priority = 1.5, type = {"Infantry", "Team",}, unit = "single_flamer(eng)"},
				--{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_tankman(eng)"},
				{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_sniper(eng)"},
				--]]

			-- Cannons
				---[[
				--{priority = 1.0, type = {"Cannon", "Supply", "Ammo",}, unit = "inf_crate_eng"},
				--{priority = 1.0, type = {"Cannon", "Supply", "Ammo",}, unit = "ammo_trailer_eng"},

				--HMGs
				{priority = 1.5, type = {"Cannon", "MG",}, unit = "vickers_mg"},
				--Anti Aircraft
				{priority = 0.1, type = {"Cannon", "AA",}, unit = "20mm_polsten"},
				{priority = 0.1, type = {"Cannon", "AA",}, unit = "20mm_oerlikon"},
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "40mm_qf40_early"},
				{priority = 1.5, type = {"Cannon", "AA",}, unit = "40mm_qf40"},
				{priority = 0.1, type = {"Cannon", "AA",}, unit = "94mm_qf_3_7_aa_early"},
				{priority = 0.5, type = {"Cannon", "AA", "AT",}, unit = "94mm_qf_3_7_aa_mid"},
				{priority = 0.5, type = {"Cannon", "AA", "AT",}, unit = "94mm_qf_3_7_aa_late"},
				--Anti Tank
				{priority = 0.5, type = {"Cannon", "AT",}, unit = "37mm_qf_mk1"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "40mm_qf2_early"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "40mm_qf2_mid"},
				{priority = 0.1, type = {"Cannon", "AT",}, unit = "40mm_qf2_late"},
				{priority = 0.1, type = {"Cannon", "AT",}, unit = "40mm_qf2_littlejohn_mid"},
				{priority = 0.1, type = {"Cannon", "AT",}, unit = "40mm_qf2_littlejohn_late"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "57mm_qf6_mk2_early"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "57mm_qf6_mk4_early"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "57mm_qf6_mk4_late"},
				{priority = 0.5, type = {"Cannon", "AT",}, unit = "76mm_qf17_25"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "76mm_qf17_early"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "76mm_qf17_mid"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "76mm_qf17_late"},
				--Mortars
				{priority = 0.5, type = {"Cannon", "Mortar",}, unit = "81mm_ml3_early"},
				{priority = 1.5, type = {"Cannon", "Mortar",}, unit = "81mm_ml3"},
				{priority = 0.5, type = {"Cannon", "Mortar",}, unit = "107mm_ml4_2"},
				--Infantry Support
				{priority = 0.1, type = {"Cannon", "Support",}, unit = "75mm_m1a1_eng"},
				{priority = 0.5, type = {"Cannon", "Support",}, unit = "84mm_qf18_2pa"},
				{priority = 0.1, type = {"Cannon", "Support",}, unit = "94mm_qf_how_early"},
				{priority = 0.1, type = {"Cannon", "Support",}, unit = "94mm_qf_how"},
				--Artillery
				{priority = 1.5, type = {"Cannon", "Artillery",}, unit = "84mm_qf18_5p"},
				{priority = 0.5, type = {"Cannon", "Artillery",}, unit = "88mm_qf25_mk1_4p"},
				{priority = 1.5, type = {"Cannon", "Artillery",}, unit = "88mm_qf25_mk2"},
				{priority = 1.5, type = {"Cannon", "Artillery",}, unit = "88mm_qf25_mk2_late"},
				{priority = 0.1, type = {"Cannon", "Artillery",}, unit = "114mm_qf_how_wooden"},
				{priority = 0.5, type = {"Cannon", "Artillery",}, unit = "114mm_qf_how"},
				{priority = 0.1, type = {"Cannon", "Artillery",}, unit = "114mm_bl_4_5_mk1"},
				{priority = 0.5, type = {"Cannon", "Artillery",}, unit = "114mm_bl_4_5"},
				{priority = 0.5, type = {"Cannon", "Artillery",}, unit = "140mm_bl_5_5"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "140mm_bl_5_5_late"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "152mm_bl_6_mk19"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "152mm_bl_6"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "155mm_m1a1_longtom_eng"},
				{priority = 0.1, type = {"Cannon", "Artillery",}, unit = "183mm_bl_7_2"},
				{priority = 0.1, type = {"Cannon", "Artillery",}, unit = "183mm_bl_7_2_mk6"},
				{priority = 0.5, type = {"Cannon", "Artillery",}, unit = "203mm_bl_8"},
				--Rocket Artillery
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "76mm_land_mattress"},
				--]]

			-- Wheel vehicles
				---[[
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Transport",}, unit = "willys_mb_eng"},
				{priority = 1.0, type = {"Vehicle", "MG",}, unit = "willys_mb_mg_eng"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Transport",}, unit = "morris_c8"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Transport",}, unit = "bedford_oyd"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Transport",}, unit = "bedford_qlt"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Supply", "Ammo",}, unit = "bedford_oyd_art_ammo"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Supply", "Ammo",}, unit = "bedford_qld_art_ammo"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Supply", "Fuel",}, unit = "bedford_oyc_fuel"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Supply", "Engineer",}, unit = "bedford_oyd_engineer"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Supply", "Engineer",}, unit = "bedford_qld_engineer"},

				{priority = 0.1, type = {"Vehicle", "AA",}, unit = "morris_c9_aa"},
	
				{priority = 1.0, type = {"Armored", "MG",}, unit = "morris_cs9"},

				{priority = 0.1, type = {"Armored", "MG",}, unit = "daimler_dingo_boys"},
				{priority = 0.5, type = {"Armored", "MG",}, unit = "daimler_dingo_early"},
				{priority = 2.0, type = {"Armored", "MG",}, unit = "daimler_dingo"},

				{priority = 1.0, type = {"Armored", "MG",}, unit = "humber_recon_mk2"},
				{priority = 1.5, type = {"Armored", "MG",}, unit = "humber_recon_mk3"},
				{priority = 1.5, type = {"Armored", "MG",}, unit = "humber_scout"},
				{priority = 1.5, type = {"Armored", "MG",}, unit = "humber_mk2"},
				{priority = 2.0, type = {"Armored", "AT",}, unit = "humber_mk4"},

				{priority = 1.0, type = {"Armored", "AT",}, unit = "daimler_mk1"},
				{priority = 0.1, type = {"Armored", "AT",}, unit = "daimler_mk1_lj"},
				{priority = 2.0, type = {"Armored", "AT",}, unit = "daimler_mk2"},
				{priority = 0.5, type = {"Armored", "AT",}, unit = "daimler_mk2_lj"},

				{priority = 0.5, type = {"Armored", "AT",}, unit = "aec_mk1"},
				{priority = 0.5, type = {"Armored", "AT",}, unit = "aec_mk2"},
				{priority = 1.5, type = {"Armored", "AT",}, unit = "aec_mk3"},

				{priority = 1.0, type = {"Armored", "AT",}, unit = "staghound_mk1"},
				{priority = 0.5, type = {"Armored", "Support",}, unit = "staghound_mk2"},
				{priority = 1.0, type = {"Armored", "AT",}, unit = "staghound_mk3"},
				{priority = 0.1, type = {"Armored", "AA",}, unit = "staghound_mkaa"},
				--]]

			-- Halftracks
				---[[
				{priority = 2.0, type = {"Armored", "MG",}, unit = "universal_carrier_mk1"},
				{priority = 1.5, type = {"Armored", "MG",}, unit = "mmg_carrier_mk1"},
				{priority = 2.0, type = {"Armored", "MG",}, unit = "universal_carrier_mk2"},
				{priority = 1.5, type = {"Armored", "MG",}, unit = "mmg_carrier_mk2"},
				{priority = 0.5, type = {"Armored", "MG",}, unit = "wasp_mk2c"},

				{priority = 1.0, type = {"Armored", "MG", "Transport",}, unit = "m5_halftrack"},
				{priority = 1.0, type = {"Armored", "MG", "Transport",}, unit = "m5a1_halftrack"},
				{priority = 0.1, type = {"Armored", "MG", "Transport",}, unit = "lvt4_eng"},
				--]]

			-- Tanks
				---[[
				{priority = 3.0, type = {"Tank", "Light", "MG",}, unit = "vickers_mk6"},
				{priority = 0.5, type = {"Tank", "Light", "AA",}, unit = "vickers_aa_mk1"},
				{priority = 2.5, type = {"Tank", "Light",}, unit = "cruiser_mk1"},
				{priority = 1.0, type = {"Tank", "Light", "Support",}, unit = "cruiser_mk1_cs"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "cruiser_mk2"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "cruiser_mk2a"},
				{priority = 0.5, type = {"Tank", "Light", "Support",}, unit = "cruiser_mk2a_cs"},
				{priority = 0.5, type = {"Tank", "Light",}, unit = "cruiser_mk3"},
				{priority = 0.5, type = {"Tank", "Light",}, unit = "cruiser_mk3_late"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "cruiser_mk4"},
				{priority = 2.0, type = {"Tank", "Light",}, unit = "cruiser_mk4a"},
				{priority = 1.5, type = {"Tank", "Light",}, unit = "matilda1"},
				{priority = 0.1, type = {"Tank", "Light",}, unit = "matilda1_50"},
				{priority = 2.5, type = {"Tank", "Light",}, unit = "stuart1"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "stuart3"},
				{priority = 2.0, type = {"Tank", "Light",}, unit = "stuart5"},
				{priority = 1.0, type = {"Tank", "Light", "MG",}, unit = "stuart5_recce"},
				{priority = 0.5, type = {"Tank", "Light",}, unit = "stuart6"},
				{priority = 0.5, type = {"Tank", "Light",}, unit = "tetrarch_mk7"},
				{priority = 0.1, type = {"Tank", "Light",}, unit = "tetrarch_mk7_littlejohn"},
				{priority = 0.1, type = {"Tank", "Light",}, unit = "m22_locust"},

				{priority = 1.0, type = {"Tank", "Medium",}, unit = "matilda2_mk1"},
				{priority = 2.0, type = {"Tank", "Medium",}, unit = "matilda2_mk3"},
				{priority = 1.0, type = {"Tank", "Medium","Support",}, unit = "matilda2_mk4_cs"},
				{priority = 3.0, type = {"Tank", "Medium",}, unit = "crusader_mk1"},
				{priority = 1.0, type = {"Tank", "Medium", "Support",}, unit = "crusader_mk1_cs"},
				{priority = 3.0, type = {"Tank", "Medium",}, unit = "crusader_mk2"},
				{priority = 1.5, type = {"Tank", "Medium", "Support",}, unit = "crusader_mk2_cs"},
				{priority = 1.5, type = {"Tank", "Medium",}, unit = "crusader_mk3"},
				{priority = 0.5, type = {"Tank", "Medium", "AA",}, unit = "crusader_aa_mk1"},
				{priority = 0.5, type = {"Tank", "Medium", "AA",}, unit = "crusader_aa_mk2"},

				{priority = 0.1, type = {"Tank", "Medium",}, unit = "valentine_mk1"},
				{priority = 1.5, type = {"Tank", "Medium",}, unit = "valentine_mk2"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "valentine_mk3"},
				{priority = 0.5, type = {"Tank", "Medium",}, unit = "valentine_mk9"},
				{priority = 0.25, type = {"Tank", "Medium",}, unit = "valentine_mk10"},
				{priority = 0.25, type = {"Tank", "Medium",}, unit = "valentine_mk11"},

				{priority = 1.5, type = {"Tank", "Medium",}, unit = "cromwell4"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "cromwell5"},
				{priority = 1.0, type = {"Tank", "Medium", "Support",}, unit = "cromwell6"},
				{priority = 1.5, type = {"Tank", "Medium",}, unit = "cromwell7"},
				{priority = 1.0, type = {"Tank", "Medium", "Support",}, unit = "cromwell8"},
				{priority = 1.5, type = {"Tank", "Medium",}, unit = "comet1_a34"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "challenger_a30"},

				{priority = 2.0, type = {"Tank", "Medium",}, unit = "grant"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "sherman1_armor"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "sherman1c_armor"},
				{priority = 1.5, type = {"Tank", "Medium",}, unit = "sherman1c_hybrid"},
				{priority = 0.1, type = {"Tank", "Medium",}, unit = "sherman1c_tulip_hybrid"},
				{priority = 1.0, type = {"Tank", "Medium", "Support",}, unit = "sherman1b"},

				{priority = 3.0, type = {"Tank", "Medium",}, unit = "sherman2_dv"},
				{priority = 0.5, type = {"Tank", "Medium",}, unit = "sherman2a"},

				{priority = 1.0, type = {"Tank", "Medium",}, unit = "sherman3_early"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "sherman5_mid"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "sherman5_late"},
				{priority = 0.5, type = {"Tank", "Medium",}, unit = "sherman5_croc"},
				{priority = 0.1, type = {"Tank", "Medium",}, unit = "sherman5_late_tulip"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "sherman5_crab"},
				{priority = 2.0, type = {"Tank", "Medium",}, unit = "sherman5c"},

				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "churchill_mk1"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "churchill_mk2"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "churchill_mk3"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "churchill_mk3_l50"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "churchill_mk3_l50_late"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "churchill_mk3_qf75"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "churchill_mk4"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "churchill_mk4_l50"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "churchill_mk4_l50_late"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "churchill_mk4_qf75"},
				{priority = 2.0, type = {"Tank", "Heavy", "Support",}, unit = "churchill_mk4_avre"},
				{priority = 1.0, type = {"Tank", "Heavy", "Support",}, unit = "churchill_mk5"},
				{priority = 2.0, type = {"Tank", "Heavy",}, unit = "churchill_mk7"},
				{priority = 2.0, type = {"Tank", "Heavy",}, unit = "churchill_mk7_croc"},
				{priority = 0.5, type = {"Tank", "Heavy", "Support",}, unit = "churchill_mk8"},
				--]]

			-- Self-Propelled Guns
				---[[
				{priority = 1.5, type = {"Tank", "Medium", "AT",}, unit = "wolverine_mk1"},
				{priority = 2.0, type = {"Tank", "Medium", "AT",}, unit = "achilles_mk2"},
				{priority = 1.5, type = {"Tank", "Medium", "AT",}, unit = "archer"},

				{priority = 0.5, type = {"Tank", "Medium", "Artillery",}, unit = "bishop"},
				{priority = 1.5, type = {"Tank", "Medium", "Artillery",}, unit = "sexton_mk2"},
				--]]
			---]====]
		}
	}
}