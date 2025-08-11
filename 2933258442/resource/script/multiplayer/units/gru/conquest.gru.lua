Purchases["conquest.gru"] = {
	{Repeat = 0, --infinite
        Units = {
			---[====[
			-- Infantry
				---[[
				{priority = 1.0, type = {"Infantry", "Team", "Command",}, unit = "single_officer(gru)"},
				--{priority = 1.0, type = {"Infantry", "Squad", "Command",}, unit = "squad_officer_con(gru)"},
				--{priority = 1.0, type = {"Infantry", "Squad", "Command",}, unit = "squad_officer_kubel_con"},
				--{priority = 1.0, type = {"Infantry", "Squad", "Command",}, unit = "squad_officer_250_3_con"},

				--T1
				{priority = 1.0, type = {"Infantry", "Squad", "Wave",}, unit = "squad_osttruppen_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Wave",}, unit = "squad_strafbatallion_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_luftwaffe_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Wave",}, unit = "squad_volkssturm_con(gru)"},

				--T2
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_sicherung_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_recon_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_regular_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_pionier_con(gru)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_lw_jaeger_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_grenadier_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_sturmgren_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_sturmgren_heavy_con(gru)"},

				{priority = 1.0, type = {"Infantry", "Squad", "Wave",}, unit = "squad_volksg_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Wave",}, unit = "squad_volksg_sturm_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_volksg_heavy_con(gru)"},

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
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_regular_vet_con(gru)"},

				--T3
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_fusilier_late_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_fusilier_smg_late_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_jaeger_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_sturmjager_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_sturm_begleitgren_motor_con"},

				--T3+
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_gd_motor_con"},
				{priority = 1.0, type = {"Infantry", "Squad", "Mechanized_Infantry",}, unit = "squad_pzg_gd_armor_con"},
				{priority = 1.0, type = {"Infantry", "Squad", "Mechanized_Infantry",}, unit = "squad_pzg_lehr_armor_con"},
				{priority = 1.0, type = {"Infantry", "Squad", "Mechanized_Infantry",}, unit = "squad_sturm_pzg_lehr_armor_con"},

				--T4
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_blau_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_gebirgsjaeger_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_gebirgsjaeger_late_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_gebirgs_recon_late_con(gru)"},

				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_brandenburger_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_brandenburger_44_con(gru)"},

				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_fallschirmjaeger_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_fallschirmjaeger_motor_con"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_fallschirm_recon_late_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_fallschirmjaeger_late_motor_con"},

				{priority = 1.0, type = {"Aircraft", "Paratrooper", "Infantry", "Squad",}, unit = "squad_fallschirmjaeger_para_con_late"},
				{priority = 1.0, type = {"Aircraft", "Paratrooper", "Infantry", "Squad",}, unit = "squad_fallschirmjaeger_para_con"},
				


				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at(gru)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at_pzs_late_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "squad_at_late_con(gru)"},

				--{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_medic(gru)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_riflegrenade(gru)"},
				-- {priority = 1.0, type = {"Infantry", "Team",}, unit = "single_ap_miner(gru)"},
				-- {priority = 1.0, type = {"Infantry", "Team",}, unit = "single_at_miner(gru)"},
				{priority = 1.0, type = {"Infantry", "Team", "Engineer",}, unit = "single_engineer(gru)"},
				{priority = 1.0, type = {"Infantry", "Team","Flamer",}, unit = "single_flamer(gru)"},
				--{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_tankman(gru)"},
				{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_sniper(gru)"},
                
				{priority = 1.0, type = {"Infantry", "Team", "Signaller",}, unit = "single_signaller(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_border(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_partisan_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_penal_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_conscripts_con(gru)"},

				--T1+
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_vet_partisan_rifle_late_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_vet_partisan_smg_late_con(gru)"},

				--T2
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_nkvd_recon_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_recon_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_recon_44_con(gru)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_nkvd_sapper_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_sapper_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_sapper_44_con(gru)"},

				{priority = 1.0, type = {"Infantry", "Squad", "AT",}, unit = "squad_at_rifle_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad", "AT",}, unit = "squad_nkvd_at_rifle_con(gru)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_nkvd_rifle_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifleunit_alt_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifleunit_con(gru)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifle_motorised_con"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifle_43_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifle_43_heavy_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifle_44_con(gru)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_smg_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_smg_mg_43_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_smg_mg_43_heavy_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_smg_mg_44_con(gru)"},

				--T2+
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guardsrifle_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guardsrifle_motorised_con"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guards_smg_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guardsrifle_44_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guardsrifle_44_motor_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guards_smg_mg_44_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guards_smg_mg_44_motor_con(gru)"},

				--T3
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_nkvd_mountain_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_mountainrifles_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_marines_reg_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_cav_44_con(gru)"},
				
				--T3+
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_elite_guardsrifle_44_motor_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_elite_guards_smg_mg_44_motor_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guards_cav_44_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guards_marines_44_con(gru)"},

				--T4
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_nkvd_mountain_cav_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_mountain_cav_44_con(gru)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_assaultsappers_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_assaultsappers_flame_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad", "AT",}, unit = "squad_assaultsappers_at_con(gru)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_paras_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_spetsnaz(gru)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_marines_con(gru)"},

				--T4+
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_guards_paras_con(gru)"},

				--Singles/Teams
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at(gru)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at2(gru)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at_pzs_late_con(gru)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at_late_con(gru)"},

				--{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_medic(gru)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_riflegrenade(gru)"},
				{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_ap_miner(gru)"},
				{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_at_miner(gru)"},
				{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_engineer(gru)"},
				{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_flamer(gru)"},
				--{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_tankman(gru)"},
				{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_sniper(gru)"},
				{priority = 1.0, type = {"Infantry", "Team", "Signaller"}, unit = "single_signaller(gru)"},
				--{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_tankman(gru)"},
				
			
				--]]

			-- Cannons
				---[[
				--{priority = 1.0, type = {"Cannon", "Supply", "Ammo",}, unit = "inf_crate_ger"},
				--{priority = 1.0, type = {"Cannon", "Supply", "Ammo",}, unit = "ammo_trailer"},
				--{priority = 1.0, type = {"Cannon", "Spotlight",}, unit = "150mm_sw34_ger"},

				--HMGs
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "mg34_lafette"},
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "mg42_lafette"},
			--	{priority = 1.0, type = {"Cannon", "MG",}, unit = "panzernest_krab_ger"},
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "maxim"},
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "ds39_stand"},
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "sg43_stand"},
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "dshk_stan"},
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "dshk_aa"},
				--Anti Aircraft
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "20mm_flak30"},
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "20mm_flak38"},
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "37mm_flak37"},
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "50mm_flak41"},
				{priority = 1.0, type = {"Cannon", "AA", "AT",}, unit = "88mm_flak18"},
				{priority = 1.0, type = {"Cannon", "AA", "AT",}, unit = "88mm_flak36"},
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "25mm_72k"},
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "37mm_61k"},
				{priority = 1.0, type = {"Cannon", "AA", "AT",}, unit = "76mm_m1938"},
				{priority = 1.0, type = {"Cannon", "AA", "AT",}, unit = "85mm_52k"},
				--Anti Tank
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "28mm_pzb41"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "37mm_pak36"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "47mm_pakt"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "50mm_pak38"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "75mm_pak9738"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "75mm_pak40"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "88mm_pak4341"},
				-- {priority = 1.0, type = {"Cannon", "AT",}, unit = "pak_44"},
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
				{priority = 1.0, type = {"Cannon", "Mortar",}, unit = "80mm_sgrw34"},
				{priority = 1.0, type = {"Cannon", "Mortar",}, unit = "100mm_nbw35"},
				{priority = 1.0, type = {"Cannon", "Mortar",}, unit = "120mm_sgrw42"},
				{priority = 1.0, type = {"Cannon", "Mortar", "Big_gun",}, unit = "200mm_ldgw40"},
				{priority = 1.0, type = {"Cannon", "Mortar",}, unit = "82mm_bm37"},
				{priority = 1.0, type = {"Cannon", "Mortar",}, unit = "120mm_pm38"},
				--Infantry Support
				{priority = 1.0, type = {"Cannon", "Support",}, unit = "75mm_leig18"},
				{priority = 1.0, type = {"Cannon", "Support",}, unit = "75mm_lg40"},
				{priority = 1.0, type = {"Cannon", "Support", "Big_gun",}, unit = "150mm_sig33"},
				{priority = 1.0, type = {"Cannon", "Support",}, unit = "76mm_m1927"},
				{priority = 1.0, type = {"Cannon", "Support",}, unit = "76mm_m43"},
				--Artillery
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "105mm_lefh18ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "105mm_sk18ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "150mm_sfh18ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "170mm_k18ai"},
				-- {priority = 1.0, type = {"Cannon", "Artillery",}, unit = "155mm_gpf_ger"},
				
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "210mm_morser18ai"},
				{priority = 1.0, type = {"Cannon", "Artillery", "Big_gun",}, unit = "600mm_thorai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "107mm_m1910_30ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "122mm_m1910ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "122mm_m30ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "122mm_a19ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "152mm_ml20ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "152mm_br2ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "203mm_b4ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "280mm_br5ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "300mm_m30"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "300mm_m31"},
				--Rocket Artillery
				{priority = 1.0, type = {"Cannon", "Artillery", "Rocket_Arty",}, unit = "150mm_nebelwerfer41ai"},
				{priority = 1.0, type = {"Cannon", "Artillery", "Rocket_Arty",}, unit = "210mm_nebelwerfer42ai"},
				{priority = 1.0, type = {"Cannon", "Artillery", "Rocket_Arty",}, unit = "300mm_nebelwerfer42ai"},
				{priority = 1.0, type = {"Vehicle", "Artillery", "Rocket_Arty",}, unit = "zis6_bm8_48"},
				{priority = 1.0, type = {"Vehicle", "Artillery", "Rocket_Arty",}, unit = "zis6_bm13_16"},
				{priority = 1.0, type = {"Vehicle", "Artillery", "Rocket_Arty",}, unit = "bm13_studebakerai"},
				{priority = 1.0, type = {"Vehicle", "Artillery", "Rocket_Arty",}, unit = "bm31_12ai"},
				--]]

			-- Wheel vehicles
				---[[
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
				{priority = 1.0, type = {"Vehicle", "MG",}, unit = "m72"},
				{priority = 1.0, type = {"Vehicle", "AA",}, unit = "gaz_aaa_maximx4"},
				{priority = 1.0, type = {"Vehicle", "AA",}, unit = "gaz_aaa_72k"},
				{priority = 1.0, type = {"Vehicle", "AA", "AT",}, unit = "yag10_29k"},
				{priority = 1.0, type = {"Vehicle", "AA",}, unit = "zis5_dshk"},
				
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
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Transport",}, unit = "blitz3_6"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Supply", "Ammo",}, unit = "blitz3_6_art_ammo"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Supply", "Fuel",}, unit = "blitz3_6_fuel"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed","Supply", "Engineer",}, unit = "blitz3_6_engineering"},
				
				--]]

			-- Halftracks
				---[[
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Supply", "Engineer",}, unit = "kettenkrad_eng"},
				
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
				{priority = 1.0, type = {"Armored", "MG",}, unit = "t20"},
				{priority = 1.0, type = {"Armored", "MG",}, unit = "t27"},
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
				{priority = 1.0, type = {"Tank", "Heavy", "Elite",}, unit = "tiger2p"},
				{priority = 1.0, type = {"Tank", "Heavy", "Elite",}, unit = "tiger2h"},

				{priority = 1.0, type = {"Armored", "MG", "Deminer",}, unit = "pz3m"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "t37a"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "t40"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "t30"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "t60"},
				{priority = 1.0, type = {"Tank", "Light", "Artillery",}, unit = "t60_bm8_24"},
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
				{priority = 1.0, type = {"Tank", "Light",}, unit = "valentine9"},

				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m3_lee_rus"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m4a2_75_early_rus"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m4a2_75_late_rus"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m4a2_76w_early_rus"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "m4a2_76w_late_rus"},

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
				{priority = 1.0, type = {"Tank", "Medium", "Flamer", "Elite",}, unit = "t3485_44_flame"},
				{priority = 1.0, type = {"Tank", "Medium", "Flamer", "Elite",}, unit = "t3485_44a_flame"},

				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "churchill3"},
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
				{priority = 1.0, type = {"Tank", "Heavy", "Big_gun",}, unit = "is2_44"},
				{priority = 1.0, type = {"Tank", "Heavy", "Elite", "Big_gun",}, unit = "is2_45"},
				--]]

			-- Self-Propelled Guns
				---[[
				{priority = 1.0, type = {"Tank", "Light", "AT",}, unit = "panzerjager1"},
				{priority = 1.0, type = {"Tank", "Light", "AT",}, unit = "marder2"},
				{priority = 1.0, type = {"Tank", "Light", "AT",}, unit = "marder3m"},
				{priority = 1.0, type = {"Tank", "Light", "AT",}, unit = "hetzer"},

				{priority = 1.0, type = {"Tank", "Light", "AA",}, unit = "grille_m"},

				{priority = 1.0, type = {"Tank", "Light", "Support", "Big_gun",}, unit = "bison"},
				{priority = 1.0, type = {"Tank", "Light", "Artillery",}, unit = "pz38h_w40"},
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

				{priority = 1.0, type = {"Tank", "Medium", "Support",}, unit = "stuh42"},
				{priority = 1.0, type = {"Tank", "Medium", "Support",}, unit = "sig33b"},
				{priority = 1.0, type = {"Tank", "Medium", "Support", "Big_gun",}, unit = "sturmpanzer4"},
				{priority = 1.0, type = {"Tank", "Medium", "Artillery",}, unit = "hummel"},

				{priority = 1.0, type = {"Tank", "Heavy", "AT",}, unit = "ferdinand"},
				{priority = 1.0, type = {"Tank", "Heavy", "AT",}, unit = "jagdpanther"},
				{priority = 1.0, type = {"Tank", "Heavy", "AT",}, unit = "jagdtiger"},
				{priority = 1.0, type = {"Tank", "Heavy", "AT", "Big_gun",}, unit = "sturmtiger"},
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
				{priority = 1.0, type = {"Aircraft", "Fighter",}, unit = "bf109_f4_ai"},
				{priority = 1.0, type = {"Aircraft", "Bomber",}, unit = "bf110_e2_ai"},
				{priority = 1.0, type = {"Aircraft", "Fighter",}, unit = "yak1_ser69_ai"},
				{priority = 1.0, type = {"Aircraft", "Bomber",}, unit = "il2_mod42_ai"},
			---STUFF				
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "37mm_pak36_late"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "50mm_pak38_late"},
				{priority = 1.0, type = {"Cannon", "Support", "Big_gun",}, unit = "150mm_sig33_late"},						
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
				
				-- -Beute Panzers
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
				-- {priority = 1.0, type = {"Tank", "Heavy",}, unit = "type_5"},
                
				--]]

			-- Cannons
				---[[
				--{priority = 1.0, type = {"Cannon", "Supply", "Ammo",}, unit = "inf_crate_rus"},
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
			
				-- {priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_cossacks_con(gru)"},
				-- {priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_marines_late_con(gru)"},
				-- {priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_marines_guards_con(gru)"},
				
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
				
				-- {priority = 1.0, type = {"Tank", "Heavy", "AT",}, unit = "isu152"}
				--]]
			---]====]
		}
	}
}