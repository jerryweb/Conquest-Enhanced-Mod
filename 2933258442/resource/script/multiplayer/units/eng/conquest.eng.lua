Purchases["conquest.eng"] = {
	{Repeat = 0, --infinite
		Units = {
			---[====[
			-- Infantry
				---[[
				--{availability = "1.4", base = { "Infantry", "Single" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = {}, unit = "single_officer(eng)"},
				--{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = {}, unit = "squad_officer_con(eng)"},
				--{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = {}, mobility = { "Mechanized" }, unit = "squad_officer_carrier_con"},
				--{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = {}, effects = {}, mobility = { "Mechanized" }, unit = "squad_officer_m5a1_halftrack_con"},

				--T1
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Defensive" }, roles = { "Line" }, effects = {}, unit = "squad_rear_echelon_early_con(eng)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Defensive" }, roles = { "Line" }, effects = {}, unit = "squad_brig_defense_mid_con(eng)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Defensive" }, roles = { "Line" }, effects = {}, unit = "squad_div_defense_mg_mid_con(eng)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Defensive" }, roles = { "Line" }, effects = {}, unit = "squad_brig_defense_late_con(eng)"},

				--Recon
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, unit = "squad_rec_mc_early_con(eng)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, mobility = { "Mechanized" }, unit = "squad_rec_scout_early_con(eng)"}, --vehicle

				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, unit = "squad_recce_assault_mid_con(eng)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, mobility = { "Mechanized" }, unit = "squad_recce_carrier_mid_con(eng)"}, --vehicle

				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, unit = "squad_recce_assault_late_con(eng)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, mobility = { "Motorized" }, unit = "squad_recce_assault_mot_late_con(eng)"}, --vehicle
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, mobility = { "Mechanized" }, unit = "squad_recce_carrier_late_con(eng)"}, --vehicle

				--T2
				{availability = "0.9", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_rifle_early_con(eng)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_pio_early_con(eng)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Mechanized" }, unit = "squad_carrier_early_con(eng)"}, --vehicle

				{availability = "0.9", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_rifle_mid_con(eng)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Defensive" }, roles = { "Line" }, effects = {}, unit = "squad_r_eng_mid_con(eng)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Mechanized" }, unit = "squad_carrier_mid_con(eng)"}, --vehicle

				{availability = "0.9", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_rifle_late_con(eng)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Motorized" }, unit = "squad_rifle_mot_late_con(eng)"}, --vehicle
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Defensive" }, roles = { "Line" }, effects = {}, unit = "squad_r_eng_late_con(eng)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_assault_pio_late_con(eng)"},

				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_rifle_late_con(can)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Mechanized" }, unit = "squad_rifle_mech_late_con(can)"}, --vehicle
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, mobility = { "Mechanized" }, unit = "squad_carrier_late_con(can)"}, --vehicle

				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_rifle_late_con(pol)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Mechanized" }, unit = "squad_rifle_mech_late_con(pol)"}, --vehicle
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Mechanized" }, unit = "squad_carrier_late_con(pol)"}, --vehicle

				--T2+
				{availability = "1.2", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_vet_rifle_mid_con(eng)"},

				{availability = "1.2", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_vet_rifle_late_con(eng)"},

				--T3
				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_51hl_rifle_early_con(eng)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Offensive" }, roles = { "Assault" }, effects = {}, unit = "squad_com_early_con(eng)"}, --stealth

				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_7th_ad_rifle_mid_con(eng)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Offensive" }, roles = { "Assault" }, effects = {}, unit = "squad_rm_com_assault_mid_con(eng)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_rn_com_beach_mid_con(eng)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_1st_airland_pio_mid_con(eng)"},
				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_1st_airland_rifle_mid_con(eng)"},

				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Offensive" }, roles = { "Assault" }, effects = {}, unit = "squad_rm_com_assault_late_con(eng)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, unit = "squad_6th_airland_recon_late_con(eng)"},
				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_6th_airland_rifle_late_con(eng)"},
				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_gds_ad_rifle_late_con(eng)"},
				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Offensive" }, roles = { "Assault" }, effects = {}, unit = "squad_com_rifle_late_con(eng)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_com_smg_s_late_con(eng)"}, --stealth

				--T3+
				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_51hl_rifle_mid_con(eng)"},

				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_7th_ad_rifle_late_con(eng)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_7th_ad_pio_late_con(eng)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Defensive" }, roles = { "Line" }, effects = {}, unit = "squad_7th_ad_eng_late_con(eng)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, unit = "squad_1st_airland_recon_late_con(eng)"},
				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_1st_airland_rifle_late_con(eng)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = { "VsInfantry" }, unit = "squad_1st_airland_support_late_con(eng)"},

				--T4
				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_hl_bw_rifle_early_con(eng)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_hl_bw_inf_pio_early_con(eng)"},

				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, unit = "squad_1st_para_recce_mid_con(eng)"},
				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_1st_para_rifle_mid_con(eng)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Offensive" }, roles = { "Assault" }, effects = {}, unit = "squad_com_rifle_mid_con(eng)"}, --stealth
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_sas_mid_con(eng)"}, --stealth

				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Defensive" }, roles = { "Line" }, effects = {}, unit = "squad_6th_para_eng_late_con(eng)"},
				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_6th_para_rifle_late_con(eng)"},

				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "squad_1st_para_at_late_con(can)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_1st_para_protect_late_con(can)"},
				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = { "VsInfantry" }, unit = "squad_1st_para_rifle_late_con(can)"},

				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Defensive" }, roles = { "Line" }, effects = {}, unit = "squad_1st_para_eng_late_con(pol)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_1st_para_eng_flame_late_con(pol)"},
				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = { "VsInfantry" }, unit = "squad_1st_para_rifle_late_con(pol)"},

				--T4+
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Defensive" }, roles = { "Line" }, effects = {}, unit = "squad_1st_para_eng_late_con(eng)"},
				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = { "VsInfantry" }, unit = "squad_1st_para_rifle_late_con(eng)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, mobility = { "Motorized" }, unit = "squad_1st_para_recce_late_con(eng)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_sas_late_con(eng)"}, --stealth

				--Singles/Teams
				{availability = "1.3", base = { "Infantry", "Single" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "single_at_con(eng)"},
				{availability = "1.4", base = { "Infantry", "Single" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "single_at1_con(eng)"},
				{availability = "1.3", base = { "Infantry", "Single" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "single_at2_con(eng)"},
				
				--{availability = "1.4", base = { "Infantry", "Single" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = {}, unit = "single_medic(eng)"},
				{availability = "1.3", base = { "Infantry", "Single" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "single_riflegrenade_con(eng)"},
				--{availability = "1.5", base = { "Infantry", "Single" }, class = {}, grade = "Grade1", posture = { "Defensive" }, roles = {}, effects = {}, unit = "single_ap_miner(eng)"},
				--{availability = "1.5", base = { "Infantry", "Single" }, class = {}, grade = "Grade1", posture = { "Defensive" }, roles = {}, effects = {}, unit = "single_at_miner(eng)"},
				--{availability = "1.5", base = { "Infantry", "Single" }, class = {}, grade = "Grade1", posture = { "Defensive" }, roles = {}, effects = {}, unit = "single_engineer(eng)"},
				{availability = "1.3", base = { "Infantry", "Single" }, class = {}, grade = "Grade3", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "single_flamer(eng)"},
				--{availability = "1.4", base = { "Infantry", "Single" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = {}, unit = "single_tankman(eng)"},
				{availability = "1.4", base = { "Infantry", "Single" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry" }, unit = "single_sniper(eng)"},
				--]]

			-- Cannons
				---[[
				--{availability = "1.4", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "Unarmed", "Supply" }, effects = {}, unit = "inf_crate_eng"},
				--{availability = "1.4", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "Unarmed", "Supply" }, effects = {}, unit = "ammo_trailer_eng"},

				--HMGs
				{availability = "1.3", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "vickers_mg"},
				--Anti Aircraft
				{availability = "1.6", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "20mm_polsten"},
				{availability = "1.6", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "20mm_oerlikon"},
				{availability = "1.4", base = { "Cannon" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "40mm_qf40_early"},
				{availability = "1.3", base = { "Cannon" }, class = { "Medium" }, grade = "Grade3", posture = { "Defensive" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "40mm_qf40"},
				{availability = "1.6", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade3", posture = { "Defensive" }, roles = { "AirDefense" }, effects = { "VsVehicle" }, unit = "94mm_qf_3_7_aa_early"},
				{availability = "1.5", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade4", posture = { "Defensive" }, roles = { "AirDefense", "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "94mm_qf_3_7_aa_mid"},
				{availability = "1.5", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade4", posture = { "Defensive" }, roles = { "AirDefense", "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "94mm_qf_3_7_aa_late"},
				--Anti Tank
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "37mm_qf_mk1"},
				{availability = "1.4", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "40mm_qf2_early"},
				{availability = "1.4", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "40mm_qf2_mid"},
				{availability = "1.6", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "40mm_qf2_late"},
				{availability = "1.6", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "40mm_qf2_littlejohn_mid"},
				{availability = "1.6", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "40mm_qf2_littlejohn_late"},
				{availability = "1.4", base = { "Cannon" }, class = { "Medium" }, grade = "Grade3", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "57mm_qf6_mk2_early"},
				{availability = "1.4", base = { "Cannon" }, class = { "Medium" }, grade = "Grade3", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "57mm_qf6_mk4_early"},
				{availability = "1.4", base = { "Cannon" }, class = { "Medium" }, grade = "Grade3", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "57mm_qf6_mk4_late"},
				{availability = "1.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade3", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "76mm_qf17_25"},
				{availability = "1.4", base = { "Cannon" }, class = { "Medium" }, grade = "Grade4", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "76mm_qf17_early"},
				{availability = "1.4", base = { "Cannon" }, class = { "Medium" }, grade = "Grade4", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "76mm_qf17_mid"},
				{availability = "1.4", base = { "Cannon" }, class = { "Medium" }, grade = "Grade4", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "76mm_qf17_late"},
				--Infantry Support
				{availability = "1.6", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "75mm_m1a1_eng"},
				{availability = "1.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "84mm_qf18_2pa"},
				{availability = "1.6", base = { "Cannon" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "94mm_qf_how_early"},
				{availability = "1.6", base = { "Cannon" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "94mm_qf_how"},
				--Mortars
				{availability = "1.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Mortar" }, effects = { "VsInfantry" }, unit = "81mm_ml3_early"},
				{availability = "1.3", base = { "Cannon" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Mortar" }, effects = { "VsInfantry" }, unit = "81mm_ml3"},
				{availability = "1.5", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade3", posture = { "Defensive" }, roles = { "Mortar" }, effects = { "VsInfantry" }, unit = "107mm_ml4_2"},
				--Artillery
				{availability = "1.3", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "84mm_qf18_5p"},
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "88mm_qf25_mk1_4p"},
				{availability = "1.3", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "88mm_qf25_mk2"},
				{availability = "1.3", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "88mm_qf25_mk2_late"},
				{availability = "1.6", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "114mm_qf_how_wooden"},
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "114mm_qf_how"},
				{availability = "1.6", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "114mm_bl_4_5_mk1"},
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "114mm_bl_4_5"},
				{availability = "1.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade3", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "140mm_bl_5_5"},
				{availability = "1.4", base = { "Cannon" }, class = { "Medium" }, grade = "Grade3", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "140mm_bl_5_5_late"},
				{availability = "1.4", base = { "Cannon" }, class = { "Medium" }, grade = "Grade3", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "152mm_bl_6_mk19"},
				{availability = "1.4", base = { "Cannon" }, class = { "Medium" }, grade = "Grade3", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "152mm_bl_6"},
				{availability = "1.4", base = { "Cannon" }, class = { "Medium" }, grade = "Grade3", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "155mm_m1a1_longtom_eng"},
				{availability = "1.6", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade4", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "183mm_bl_7_2"},
				{availability = "1.6", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade4", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "183mm_bl_7_2_mk6"},
				{availability = "1.5", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade4", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "203mm_bl_8"},
				--Rocket Artillery
				{availability = "1.4", base = { "Cannon" }, class = { "Light" }, grade = "Grade3", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "76mm_land_mattress"},
				--]]

			-- Wheel vehicles
				---[[
				{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "willys_mb_mg_eng"},
				{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "morris_cs9"},
				{availability = "1.6", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Recon" }, effects = {}, unit = "daimler_dingo_boys"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Recon", "MG" }, effects = { "VsInfantry" }, unit = "daimler_dingo_early"},
				{availability = "1.2", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Recon", "MG" }, effects = { "VsInfantry" }, unit = "daimler_dingo"},

				{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Recon", "MG" }, effects = { "VsInfantry" }, unit = "humber_recon_mk2"},
				{availability = "1.3", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Recon", "MG" }, effects = { "VsInfantry" }, unit = "humber_recon_mk3"},
				{availability = "1.3", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Recon", "MG" }, effects = { "VsInfantry" }, unit = "humber_scout"},
				{availability = "1.3", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "Recon", "MG" }, effects = { "VsInfantry", "VsVehicle" }, unit = "humber_mk2"},
				{availability = "1.2", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry", "VsVehicle" }, unit = "humber_mk4"},
				{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry", "VsVehicle" }, unit = "daimler_mk1"},
				{availability = "1.6", base = { "Vehicle" }, class = { "Light" }, grade = "Grade3", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry", "VsVehicle" }, unit = "daimler_mk1_lj"},
				{availability = "1.2", base = { "Vehicle" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry", "VsVehicle" }, unit = "daimler_mk2"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Light" }, grade = "Grade3", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry", "VsVehicle" }, unit = "daimler_mk2_lj"},

				{availability = "1.5", base = { "Vehicle" }, class = { "Heavy" }, grade = "Grade2", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry", "VsVehicle" }, unit = "aec_mk1"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Heavy" }, grade = "Grade4", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "aec_mk2"},
				{availability = "1.3", base = { "Vehicle" }, class = { "Heavy" }, grade = "Grade3", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "aec_mk3"},

				{availability = "1.4", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry", "VsVehicle" }, unit = "staghound_mk1"},
				{availability = "1.4", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "staghound_mk3"},
				
				{availability = "1.5", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "staghound_mk2"},

				{availability = "1.6", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "staghound_mkaa"},
				{availability = "1.6", base = { "Vehicle" }, class = { "Light" }, grade = "Grade3", posture = { "Flexible" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "morris_c9_aa"},

				--{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Unarmed", "Transport" }, effects = {}, unit = "willys_mb_eng"},
				--{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Unarmed", "Transport" }, effects = {}, unit = "morris_c8"},
				--{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Unarmed", "Transport" }, effects = {}, unit = "bedford_oyd"},
				--{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Unarmed", "Transport" }, effects = {}, unit = "bedford_qlt"},
				--{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Unarmed", "Supply" }, effects = {}, unit = "bedford_oyd_art_ammo"},
				--{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Unarmed", "Supply" }, effects = {}, unit = "bedford_qld_art_ammo"},
				--{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Unarmed" }, effects = {}, unit = "bedford_oyc_fuel"},
				--{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Unarmed" }, effects = {}, unit = "bedford_oyd_engineer"},
				--{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Unarmed" }, effects = {}, unit = "bedford_qld_engineer"},
				--]]

			-- Halftracks
				---[[
				{availability = "1.2", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "universal_carrier_mk1"},
				{availability = "1.3", base = { "Vehicle" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "mmg_carrier_mk1"},
				{availability = "1.2", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "universal_carrier_mk2"},
				{availability = "1.3", base = { "Vehicle" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "mmg_carrier_mk2"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Light" }, grade = "Grade2", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "wasp_mk2c"},

				{availability = "1.4", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "m5_halftrack"},
				{availability = "1.4", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "m5a1_halftrack"},
				{availability = "1.6", base = { "Vehicle" }, class = { "Heavy" }, grade = "Grade3", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "lvt4_eng"},
				--]]

			-- Tanks
				---[[
				{availability = "1.0", base = { "Tank" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "vickers_mk6"},
				{availability = "1.3", base = { "Tank" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "matilda1"},
				{availability = "1.6", base = { "Tank" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry", "VsVehicle" }, unit = "matilda1_50"},

				{availability = "1.4", base = { "Tank" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Recon", "MG"  }, effects = { "VsInfantry", "VsVehicle" }, unit = "stuart5_recce"},
				{availability = "1.5", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "tetrarch_mk7"},
				{availability = "1.6", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "tetrarch_mk7_littlejohn"},

				{availability = "1.1", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "cruiser_mk1"},
				{availability = "1.4", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "cruiser_mk2"},
				{availability = "1.4", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "cruiser_mk2a"},
				{availability = "1.5", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "cruiser_mk3"},
				{availability = "1.5", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "cruiser_mk3_late"},
				{availability = "1.4", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "cruiser_mk4"},
				{availability = "1.2", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "cruiser_mk4a"},

				{availability = "1.1", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "stuart1"},
				{availability = "1.4", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "stuart3"},
				{availability = "1.2", base = { "Tank" }, class = { "Light" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "stuart5"},
				{availability = "1.5", base = { "Tank" }, class = { "Light" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "stuart6"},
				{availability = "1.6", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "m22_locust"},

				{availability = "1.4", base = { "Tank" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "cruiser_mk1_cs"},
				{availability = "1.5", base = { "Tank" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "cruiser_mk2a_cs"},


				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "matilda2_mk1"},
				{availability = "1.2", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "matilda2_mk3"},
				{availability = "1.0", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "crusader_mk1"},
				{availability = "1.0", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "crusader_mk2"},
				{availability = "1.3", base = { "Tank" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "crusader_mk3"},

				{availability = "1.6", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "valentine_mk1"},
				{availability = "1.3", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "valentine_mk2"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "valentine_mk3"},
				{availability = "1.5", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "valentine_mk9"},
				{availability = "1.6", base = { "Tank" }, class = { "Medium" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "valentine_mk10"},
				{availability = "1.6", base = { "Tank" }, class = { "Medium" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "valentine_mk11"},

				{availability = "1.3", base = { "Tank" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "cromwell4"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "cromwell5"},
				{availability = "1.3", base = { "Tank" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "cromwell7"},
				{availability = "1.3", base = { "Tank" }, class = { "Medium" }, grade = "Grade4", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "comet1_a34"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade4", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "challenger_a30"},

				{availability = "1.2", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "grant"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "sherman1_armor"},
				{availability = "1.0", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "sherman2_dv"},
				{availability = "1.5", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "sherman2a"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "sherman3_early"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "sherman5_mid"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "sherman5_late"},
				{availability = "1.6", base = { "Tank" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "sherman5_late_tulip"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade3", posture = { "Offensive" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "sherman5_crab"}, -- de-miner
				{availability = "1.5", base = { "Tank" }, class = { "Medium" }, grade = "Grade3", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "sherman5_croc"},

				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "matilda2_mk4_cs"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "crusader_mk1_cs"},
				{availability = "1.3", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "crusader_mk2_cs"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "cromwell6"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "cromwell8"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "sherman1b"},

				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade4", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "sherman1c_armor"},
				{availability = "1.3", base = { "Tank" }, class = { "Medium" }, grade = "Grade4", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "sherman1c_hybrid"},
				{availability = "1.6", base = { "Tank" }, class = { "Medium" }, grade = "Grade4", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "sherman1c_tulip_hybrid"},
				{availability = "1.2", base = { "Tank" }, class = { "Medium" }, grade = "Grade4", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "sherman5c"},

				{availability = "1.4", base = { "Tank" }, class = { "Heavy" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "churchill_mk1"},
				{availability = "1.4", base = { "Tank" }, class = { "Heavy" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "churchill_mk2"},
				{availability = "1.4", base = { "Tank" }, class = { "Heavy" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "churchill_mk3"},
				{availability = "1.4", base = { "Tank" }, class = { "Heavy" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "churchill_mk3_l50"},
				{availability = "1.4", base = { "Tank" }, class = { "Heavy" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "churchill_mk3_l50_late"},
				{availability = "1.4", base = { "Tank" }, class = { "Heavy" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "churchill_mk3_qf75"},
				{availability = "1.4", base = { "Tank" }, class = { "Heavy" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "churchill_mk4"},
				{availability = "1.4", base = { "Tank" }, class = { "Heavy" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "churchill_mk4_l50"},
				{availability = "1.4", base = { "Tank" }, class = { "Heavy" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "churchill_mk4_l50_late"},
				{availability = "1.4", base = { "Tank" }, class = { "Heavy" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "churchill_mk4_qf75"},
				{availability = "1.2", base = { "Tank" }, class = { "Heavy" }, grade = "Grade4", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "churchill_mk7"},
				{availability = "1.2", base = { "Tank" }, class = { "Heavy" }, grade = "Grade4", posture = { "Offensive" }, roles = { "Assault", "Breakthrough" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "churchill_mk7_croc"},

				{availability = "1.2", base = { "Tank" }, class = { "Heavy" }, grade = "Grade3", posture = { "Offensive" }, roles = { "InfantryGun", "Breakthrough" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "churchill_mk4_avre"},
				{availability = "1.4", base = { "Tank" }, class = { "Heavy" }, grade = "Grade3", posture = { "Flexible" }, roles = { "InfantryGun", "Breakthrough" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "churchill_mk5"},
				{availability = "1.5", base = { "Tank" }, class = { "Heavy" }, grade = "Grade4", posture = { "Flexible" }, roles = { "InfantryGun", "Breakthrough" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "churchill_mk8"},
				--]]

			-- Self-Propelled Guns
				---[[
				{availability = "1.5", base = { "SPG" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "vickers_aa_mk1"},
				{availability = "1.5", base = { "SPG" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "crusader_aa_mk1"},
				{availability = "1.5", base = { "SPG" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "crusader_aa_mk2"},

				{availability = "1.3", base = { "SPG" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "wolverine_mk1"},
				{availability = "1.2", base = { "SPG" }, class = { "Medium" }, grade = "Grade4", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "achilles_mk2"},
				{availability = "1.3", base = { "SPG" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "archer"},

				{availability = "1.5", base = { "SPG" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "bishop"},
				{availability = "1.3", base = { "SPG" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "sexton_mk2"},
				--]]
			---]====]
		}
	}
}
