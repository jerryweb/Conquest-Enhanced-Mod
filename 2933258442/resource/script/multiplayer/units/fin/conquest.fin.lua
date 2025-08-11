Purchases["conquest.fin"] = {
	{Repeat = 0, --infinite
        Units = {
			---[====[
			-- Infantry
				---[[
				--{priority = 1.0, type = {"Infantry", "Team", "Command",}, unit = "single_officer(fin)"},
				--{priority = 1.0, type = {"Infantry", "Team", "Command",}, unit = "team_officer_con(fin)"},
				-- {priority = 0.01, type = {"Infantry", "Squad", "Command",}, unit = "squad_officer_con(fin)"},

				{priority = 1.0, type = {"Infantry", "Squad", "Wave",}, unit = "squad_civil_guard_early_con(fin)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Wave",}, unit = "squad_reserves_mid_con(fin)"},

				--T2
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_scout_mid_con(fin)"},
		
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifle_early_con(fin)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifle_lmg_early_con(fin)"},
				
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifle_mid_con(fin)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifle_late_dp_con(fin)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_rifle_late_dt_con(fin)"},
				
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_engineer_mid_con(fin)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Flamer",}, unit = "squad_eng_flame_con(fin)"},

				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_assault_mid_con(fin)"},
				{priority = 1.0, type = {"Infantry", "Squad", "AT",}, unit = "squad_antitank_late_con(fin)"},
				
				


				--T2+
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_vet_scout_mid_con(fin)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_vet_rifle_mid_con(fin)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_vet_rifle_late_con(fin)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_marksmen_mid_con(fin)"},
				
				--T3
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_border_guard_early_con(fin)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_cav_mid_con(fin)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_cav_late_con(fin)"},
				
				--T3+
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_vet_cav_mid_con(fin)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_vet_cav_late_con(fin)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_elite_rifle_mid_con(fin)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_elite_rifle_late_con(fin)"},

				--T4
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_jag_scout_late_con(fin)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_jag_mid_con(fin)"},
				{priority = 1.0, type = {"Infantry", "Squad",}, unit = "squad_jag_late_con(fin)"},
				{priority = 1.0, type = {"Infantry", "Squad", "AT", "Elite",}, unit = "squad_jag_at_late_con(fin)"},

				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_border_jag_mid_con(fin)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_border_jag_late_con(fin)"},
				{priority = 1.0, type = {"Infantry", "Squad", "AT", "Elite",}, unit = "squad_border_jag_at_late_con(fin)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_sissi_mid_con(fin)"},
				
				--T4+
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_vet_jag_mid_con(fin)"},
				{priority = 1.0, type = {"Infantry", "Squad", "Elite",}, unit = "squad_vet_jag_late_con(fin)"},

				--Singles/Teams
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at(fin)"},
				{priority = 1.0, type = {"Infantry", "Team", "AT",}, unit = "single_at_pzs_late_con(fin)"},
				{priority = 1.0, type = {"Infantry", "Squad", "AT",}, unit = "squad_at_late_con(fin)"},

				--{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_medic(fin)"},
				--{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_ap_miner(fin)"},
				--{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_at_miner(fin)"},
				{priority = 1.0, type = {"Infantry", "Team", "Engineer",}, unit = "single_engineer(fin)"},
				{priority = 1.0, type = {"Infantry", "Team", "Flamer",}, unit = "single_flamer(fin)"},
				-- {priority = 0.1, type = {"Infantry", "Squad", "Engineer",}, unit = "squad_heavy_engineer_mid_con(fin)"},
				{priority = 1.0, type = {"Infantry", "Team",}, unit = "single_sniper(fin)"},
				{priority = 1.0, type = {"Infantry", "Team", "Elite",}, unit = "white_death_con(fin)"},
				{priority = 1.0, type = {"Infantry", "Team", "Signaller"}, unit = "single_signaller(fin)"},
				--]]

			-- Cannons
				---[[
				--{priority = 1.0, type = {"Cannon", "Supply", "Ammo",}, unit = "inf_crate_fin"},
				--{priority = 1.0, type = {"Cannon", "Spotlight",}, unit = "150mm_sw34"},

				--HMGs
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "maxim_m1910_30"},
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "ds39_stand_fin"},
				{priority = 1.0, type = {"Cannon", "MG",}, unit = "panzernest_krab"},
				--Anti Aircraft
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "20mm_itk35"},
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "20mm_itk40"},
				{priority = 1.0, type = {"Cannon", "AA",}, unit = "40mm_itk38b"},
				{priority = 1.0, type = {"Cannon", "AA", "AT",}, unit = "75mm_itk37"},
				--Anti Tank
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "20mm_l39"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "37mm_pstk36"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "45mm_pstk32"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "47mm_pstk39"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "50mm_pstk38"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "76mm_k02"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "76mm_k02_30_40"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "75mm_pstk9738"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "76mm_k36"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "75mm_k40"},
				{priority = 1.0, type = {"Cannon", "AT",}, unit = "75mm_k44"},
				--Mortars
				{priority = 1.0, type = {"Cannon", "Mortar",}, unit = "50mm_krh38"},
				{priority = 1.0, type = {"Cannon", "Mortar",}, unit = "81mm_krh36"},
				{priority = 1.0, type = {"Cannon", "Mortar",}, unit = "120mm_krh40"},
				{priority = 1.0, type = {"Cannon", "Mortar",}, unit = "170mm_minewerfer"},
				--Infantry Support
				{priority = 1.0, type = {"Cannon", "Support",}, unit = "76mm_m1927_fin"},
				{priority = 1.0, type = {"Cannon", "Support",}, unit = "84mm_k18"},
				{priority = 1.0, type = {"Cannon", "Support",}, unit = "84mm_k18_late"},
				--Artillery
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "105mm_k13ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "105mm_h33ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "105mm_k34ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "107mm_k10ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "120mm_k78_31ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "122mm_m1910_finai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "150mm_h40ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "155mm_h17ai"},
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "203mm_h17ai"},
				--Rocket Artillery
				{priority = 1.0, type = {"Cannon", "Artillery",}, unit = "150mm_rkh41ai"},
				--]]

			-- Wheeled vehicles
				---[[
				{priority = 1.0, type = {"Vehicle", "AA",}, unit = "ford_3ton_breda"},
				{priority = 1.0, type = {"Armored", "MG",}, unit = "l182"},
				{priority = 1.0, type = {"Armored",}, unit = "ba6_fin"},
				{priority = 1.0, type = {"Armored",}, unit = "ba10_fin"},

				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Transport",}, unit = "m42_truppenfahrrad"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Transport",}, unit = "ford_v3000"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Supply", "Ammo",}, unit = "ford_v3000_ammo"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed", "Supply", "Fuel",}, unit = "ford_v3000_fuel"},
				--{priority = 1.0, type = {"Vehicle", "Unarmed","Supply", "Engineer",}, unit = "ford_v3000_eng"},
				--]]

			-- Tankettes
				---[[
				{priority = 1.0, type = {"Armored", "MG",}, unit = "t20_fin"},
				--]]

			-- Tanks
				---[[
				{priority = 1.0, type = {"Tank", "Light",}, unit = "ft17_mg_fin"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "t37a_fin"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "ft17_fin"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "vickers_6t_altb"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "t26e"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "t26_33_fin"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "bt5_fin"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "kht130_fin"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "t50_fin"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "l62"},
				{priority = 1.0, type = {"Tank", "Light",}, unit = "bt42"},

				{priority = 1.0, type = {"Tank", "Medium",}, unit = "t28_38_fin"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "t3476_41_fin"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "panzer4j_fin"},
				{priority = 1.0, type = {"Tank", "Medium",}, unit = "t3485_44_fin"},

				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "kv1_40e_fin"},
				{priority = 1.0, type = {"Tank", "Heavy",}, unit = "kv1_42_fin"},
				--]]

			-- Self-Propelled Guns
				---[[
				{priority = 1.0, type = {"Tank", "Medium", "AT",}, unit = "stug3g_fin"},
				{priority = 1.0, type = {"Tank", "Heavy", "AT",}, unit = "isu152_fin"},
				--]]
			--Aircraft
				{priority = 1.0, type = {"Aircraft", "Bomber",}, unit = "blenheim_mk1_ai"},	
			---]====]
		}
	}
}