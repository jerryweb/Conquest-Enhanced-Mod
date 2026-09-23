Purchases["conquest.rus"] = {
	{Repeat = 0, --infinite
		Units = {
			---[====[
			-- Infantry
				---[[
				--{availability = "1.4", base = { "Infantry", "Single" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = {}, unit = "single_officer(rus)"},
				--{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = {}, unit = "squad_officer_con(rus)"},
				--{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = {}, mobility = { "Motorized" }, unit = "squad_officer_gaz_con"},
				--{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade4", posture = { "Flexible" }, roles = { "Recon", "MG" }, effects = { "VsInfantry" }, unit = "ba20_command"},

				--T1
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Defensive" }, roles = { "Line" }, effects = {}, unit = "squad_border(rus)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_partisan_con(rus)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_penal_con(rus)"},
				{availability = "1.2", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_conscripts_con(rus)"},

				--T1+
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_vet_partisan_rifle_late_con(rus)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_vet_partisan_smg_late_con(rus)"},

				--T2
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, unit = "squad_nkvd_recon_con(rus)"},
				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, unit = "squad_recon_con(rus)"},
				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, unit = "squad_recon_44_con(rus)"},

				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_nkvd_sapper_con(rus)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Defensive" }, roles = { "Line" }, effects = {}, unit = "squad_sapper_con(rus)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_sapper_44_con(rus)"},

				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "squad_at_rifle_con(rus)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "squad_nkvd_at_rifle_con(rus)"},

				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_nkvd_rifle_con(rus)"},
				{availability = "1.1", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_rifleunit_alt_con(rus)"},
				{availability = "0.9", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_rifleunit_con(rus)"},

				{availability = "1.2", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Motorized" }, unit = "squad_rifle_motorised_con"},

				{availability = "0.9", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_rifle_43_con(rus)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_rifle_43_heavy_con(rus)"},
				{availability = "0.9", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_rifle_44_con(rus)"},

				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_smg_con(rus)"},
				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_smg_mg_43_con(rus)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_smg_mg_43_heavy_con(rus)"},
				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_smg_mg_44_con(rus)"},

				--T2+
				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_guardsrifle_con(rus)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Motorized" }, unit = "squad_guardsrifle_motorised_con"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_guards_smg_con(rus)"},
				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_guardsrifle_44_con(rus)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Motorized" }, unit = "squad_guardsrifle_44_motor_con(rus)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_guards_smg_mg_44_con(rus)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Motorized" }, unit = "squad_guards_smg_mg_44_motor_con(rus)"},

				--T3
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_nkvd_mountain_con(rus)"},
				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_mountainrifles_con(rus)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_marines_reg_con(rus)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_cav_44_con(rus)"},
				
				--T3+
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Motorized" }, unit = "squad_elite_guardsrifle_44_motor_con(rus)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Assault" }, effects = { "VsInfantry" }, mobility = { "Motorized" }, unit = "squad_elite_guards_smg_mg_44_motor_con(rus)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_guards_cav_44_con(rus)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_guards_marines_44_con(rus)"},

				--T4
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_nkvd_mountain_cav_con(rus)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_mountain_cav_44_con(rus)"},

				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_assaultsappers_con(rus)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_assaultsappers_flame_con(rus)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_assaultsappers_at_con(rus)"},

				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_paras_con(rus)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Offensive" }, roles = { "Recon", "Assault" }, effects = {}, unit = "squad_spetsnaz(rus)"}, --stealth
				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_marines_con(rus)"},

				--T4+
				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, identity = { "Guards" }, unit = "squad_guards_paras_con(rus)"},

				--Singles/Teams
				{availability = "1.3", base = { "Infantry", "Single" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "single_at(rus)"},
				{availability = "1.4", base = { "Infantry", "Single" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "single_at2(rus)"},
				{availability = "1.4", base = { "Infantry", "Single" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "single_at_pzs_late_con(rus)"},
				{availability = "1.4", base = { "Infantry", "Single" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "single_at_late_con(rus)"},

				--{availability = "1.4", base = { "Infantry", "Single" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "" }, effects = {}, unit = "single_medic(rus)"},
				{availability = "1.5", base = { "Infantry", "Single" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "single_riflegrenade(rus)"},
				--{availability = "1.5", base = { "Infantry", "Single" }, class = {}, grade = "Grade1", posture = { "Defensive" }, roles = {}, effects = {}, unit = "single_ap_miner(rus)"},
				--{availability = "1.5", base = { "Infantry", "Single" }, class = {}, grade = "Grade1", posture = { "Defensive" }, roles = {}, effects = {}, unit = "single_at_miner(rus)"},
				--{availability = "1.5", base = { "Infantry", "Single" }, class = {}, grade = "Grade1", posture = { "Defensive" }, roles = {}, effects = {}, unit = "single_engineer(rus)"},
				{availability = "1.6", base = { "Infantry", "Single" }, class = {}, grade = "Grade3", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "single_flamer(rus)"},
				--{availability = "1.4", base = { "Infantry", "Single" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "" }, effects = {}, unit = "single_tankman(rus)"},
				{availability = "1.2", base = { "Infantry", "Single" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry" }, unit = "single_sniper(rus)"},
				--]]

			-- Cannons
				---[[
				--{availability = "1.4", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "Unarmed", "Supply" }, effects = {}, unit = "inf_crate_rus"},
				--{availability = "1.4", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "Unarmed", "Supply" }, effects = {}, unit = "ap_2"},

				--HMGs
				{availability = "1.3", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "maxim"},
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "ds39_stand"},
				{availability = "1.4", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "sg43_stand"},
				{availability = "1.4", base = { "Cannon" }, class = { "Medium" }, grade = "Grade3", posture = { "Defensive" }, roles = { "MG" }, effects = { "VsInfantry",  "VsVehicle" }, unit = "dshk_stan"},
				--Anti_Aircraft
				{availability = "1.4", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "dshk_aa"},
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "25mm_72k"},
				{availability = "1.3", base = { "Cannon" }, class = { "Medium" }, grade = "Grade3", posture = { "Defensive" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "37mm_61k"},
				{availability = "1.5", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade3", posture = { "Defensive" }, roles = { "AirDefense", "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "76mm_m1938"},
				{availability = "1.3", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade4", posture = { "Defensive" }, roles = { "AirDefense", "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "85mm_52k"},
				--Anti_Tank
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "37mm_m30"},
				{availability = "1.3", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "45mm_m37"},
				{availability = "1.4", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "45mm_m42"},
				{availability = "1.6", base = { "Cannon" }, class = { "Medium" }, grade = "Grade3", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "57mm_zis2"},
				{availability = "1.5", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade4", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsArmor", "VsVehicle" }, unit = "100mm_bs3"},
				--Field Guns
				{availability = "1.6", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "76mm_bpk76"},
				{availability = "1.4", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "FieldGun" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "76mm_m1902"},
				{availability = "1.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "FieldGun" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "76mm_m1933"},
				{availability = "1.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade3", posture = { "Defensive" }, roles = { "FieldGun" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "76mm_f22"},
				{availability = "1.2", base = { "Cannon" }, class = { "Medium" }, grade = "Grade3", posture = { "Defensive" }, roles = { "FieldGun" }, effects = { "VsInfantry",  "VsVehicle", "VsArmor" }, unit = "76mm_zis3"},
				--Infantry_Support
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "m41_ampulomet"},
				{availability = "1.3", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "76mm_m1927"},
				{availability = "1.3", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "76mm_m43"},
				--Mortars
				{availability = "1.3", base = { "Cannon" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Mortar" }, effects = { "VsInfantry" }, unit = "82mm_bm37"},
				{availability = "1.4", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade3", posture = { "Defensive" }, roles = { "Mortar" }, effects = { "VsInfantry" }, unit = "120mm_pm38"},
				--Artillery
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "107mm_m1910_30"},
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "122mm_m1910"},
				{availability = "1.4", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "122mm_m30"},
				{availability = "1.3", base = { "Cannon" }, class = { "Medium" }, grade = "Grade3", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "122mm_a19"},
				{availability = "1.3", base = { "Cannon" }, class = { "Medium" }, grade = "Grade3", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "152mm_ml20"},
				{availability = "1.6", base = { "Cannon" }, class = { "Medium" }, grade = "Grade4", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "152mm_br2"},
				{availability = "1.6", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade4", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "203mm_b4"},
				{availability = "1.6", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade4", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "280mm_br5"},
				{availability = "1.5", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade3", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "300mm_m30"},
				{availability = "1.6", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade4", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "300mm_m31"},
				--]]

			-- Non-Tank vehicles
				---[[
				{availability = "1.5", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "m72"},
				{availability = "1.3", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "gaz67b"},
				{availability = "1.6", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "t20"},
				{availability = "1.6", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "t27"},
				{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "universal_carrier_rus"},
				{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "mmg_carrier_rus"},

				{availability = "1.5", base = { "Vehicle" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "Recon", "MG" }, effects = { "VsInfantry" }, unit = "fai_m"},
				{availability = "1.3", base = { "Vehicle" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "Recon", "MG" }, effects = { "VsInfantry" }, unit = "ba20"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "Recon", "MG" }, effects = { "VsInfantry" }, unit = "ba64"},
				{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "Recon", "MG" }, effects = { "VsInfantry" }, unit = "m3a1e1_scout_mgun"},
				{availability = "1.2", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry", "VsVehicle" }, unit = "ba6"},
				{availability = "1.2", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry", "VsVehicle" }, unit = "ba10"},

				{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "gaz_aaa_maximx4"},
				{availability = "1.6", base = { "Vehicle" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "gaz_aaa_72k"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Heavy" }, grade = "Grade3", posture = { "Flexible" }, roles = { "AirDefense", "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "yag10_29k"},
				{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "zis5_dshk"},

				{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade3", posture = { "Offensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "zis6_bm8_48"},
				{availability = "1.4", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade4", posture = { "Offensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "zis6_bm13_16"},
				{availability = "1.4", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade4", posture = { "Offensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "bm13_studebaker"},
				{availability = "1.4", base = { "Vehicle" }, class = { "Heavy" }, grade = "Grade4", posture = { "Offensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "bm31_12"},

				--{availability = "1.3", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Unarmed", "Transport" }, effects = {}, unit = "gaz67"},
				--{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Unarmed", "Transport" }, effects = {}, unit = "gaz_aaa"},
				--{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Unarmed", "Transport" }, effects = {}, unit = = "zis5"},
				--{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Unarmed", "Supply" }, effects = {}, unit = "gaz_aaa_supply"},
				--{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Unarmed" }, effects = {}, unit = "gaz_fuel"},
				--{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Unarmed" }, effects = {}, unit = "zis5eng"},
				--]]

			-- Tanks
				---[[
				{availability = "1.2", base = { "Tank" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "t37a"},
				{availability = "1.5", base = { "Tank" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry", "VsVehicle" }, unit = "t40"},
				{availability = "1.4", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle" }, unit = "t30"},
				{availability = "1.0", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle" }, unit = "t60"},
				{availability = "1.6", base = { "Tank" }, class = { "Light" }, grade = "Grade4", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "t50"},
				{availability = "1.0", base = { "Tank" }, class = { "Light" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "t70"},
				{availability = "1.0", base = { "Tank" }, class = { "Light" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "t70m"},

				{availability = "1.5", base = { "Tank" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "bt2_da2"},
				{availability = "1.4", base = { "Tank" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "bt2"},
				{availability = "1.1", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "bt5"},
				{availability = "1.0", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "bt7"},

				{availability = "1.6", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "kht26"},
				{availability = "1.4", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "kht130"},
				{availability = "1.5", base = { "Tank" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "t26_31"},
				{availability = "1.4", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "t26_33"},
				{availability = "1.2", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "t26_39"},

				{availability = "1.5", base = { "Tank" }, class = { "Light" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "m3_stuart_late_rus"},
				{availability = "1.5", base = { "Tank" }, class = { "Light" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "m3a1_stuart_rus"},

				{availability = "1.6", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "valentine2"},
				{availability = "1.3", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "valentine7"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "valentine9"},

				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "m3_lee_rus"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "m4a2_75_early_rus"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "m4a2_75_late_rus"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade4", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "m4a2_76w_early_rus"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade4", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "m4a2_76w_late_rus"},

				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "t28"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "t28_38"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "t28e"},

				{availability = "1.6", base = { "Tank" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "t3457_41"},
				{availability = "1.6", base = { "Tank" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "t3457_43"},
				{availability = "1.2", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "t3476_40"},
				{availability = "1.1", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "t3476_41"},
				{availability = "1.6", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "t3476_41e"},
				{availability = "0.9", base = { "Tank" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "t3476_42"},
				{availability = "0.9", base = { "Tank" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "t3476_43"},
				{availability = "1.1", base = { "Tank" }, class = { "Medium" }, grade = "Grade4", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "t3485_44"},
				{availability = "1.6", base = { "Tank" }, class = { "Medium" }, grade = "Grade4", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "t3485_44a"},
				{availability = "1.6", base = { "Tank" }, class = { "Medium" }, grade = "Grade4", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "t3485_44b"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "Assault" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "t3476_43_flame"},
				{availability = "1.5", base = { "Tank" }, class = { "Medium" }, grade = "Grade4", posture = { "Flexible" }, roles = { "Assault" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "t3485_44_flame"},
				{availability = "1.6", base = { "Tank" }, class = { "Medium" }, grade = "Grade4", posture = { "Flexible" }, roles = { "Assault" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "t3485_44a_flame"},

				{availability = "1.5", base = { "Tank" }, class = { "Heavy" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "churchill3"},
				{availability = "1.6", base = { "Tank" }, class = { "Heavy" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "t35"},
				{availability = "1.6", base = { "Tank" }, class = { "Heavy" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "t35_late"},
				{availability = "1.6", base = { "Tank" }, class = { "Heavy" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "smk"},
				{availability = "1.6", base = { "Tank" }, class = { "Heavy" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "kv1_39"},
				{availability = "1.5", base = { "Tank" }, class = { "Heavy" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "kv1_40"},
				{availability = "1.3", base = { "Tank" }, class = { "Heavy" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "kv1_40e"},
				{availability = "1.2", base = { "Tank" }, class = { "Heavy" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "kv1_41"},
				{availability = "1.3", base = { "Tank" }, class = { "Heavy" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "kv1_42"},
				{availability = "1.5", base = { "Tank" }, class = { "Heavy" }, grade = "Grade3", posture = { "Flexible" }, roles = { "Assault" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "kv8"},

				{availability = "1.2", base = { "Tank" }, class = { "Heavy" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "kv1s"},
				{availability = "1.5", base = { "Tank" }, class = { "Heavy" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "kv85"},
				{availability = "1.5", base = { "Tank" }, class = { "Heavy" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "is1_43"},
				{availability = "1.3", base = { "Tank" }, class = { "Heavy" }, grade = "Grade4", posture = { "Flexible" }, roles = { "Breakthrough" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "is2_43"},
				{availability = "1.2", base = { "Tank" }, class = { "Heavy" }, grade = "Grade4", posture = { "Flexible" }, roles = { "Breakthrough" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "is2_44"},
				{availability = "1.5", base = { "Tank" }, class = { "Heavy" }, grade = "Grade4", posture = { "Flexible" }, roles = { "Breakthrough" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "is2_45"},
				--]]

			-- Self-Propelled Guns
				---[[
				{availability = "1.0", base = { "SPG" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "FieldGun" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "su76"},
				{availability = "1.6", base = { "SPG" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "zis30"},
				{availability = "1.3", base = { "SPG" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "su85"},
				{availability = "1.5", base = { "SPG" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "su85m"},
				{availability = "1.4", base = { "SPG" }, class = { "Medium" }, grade = "Grade4", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "su100"},
				{availability = "1.2", base = { "SPG" }, class = { "Heavy" }, grade = "Grade4", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "isu122s"},

				{availability = "1.6", base = { "SPG" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "su26"},
				{availability = "1.5", base = { "SPG" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle",}, unit = "bt7a"},
				{availability = "1.3", base = { "SPG" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "su122"},
				{availability = "1.3", base = { "SPG" }, class = { "Heavy" }, grade = "Grade4", posture = { "Flexible" }, roles = { "InfantryGun", "Breakthrough"}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "kv2_40"},
				{availability = "1.4", base = { "SPG" }, class = { "Heavy" }, grade = "Grade4", posture = { "Flexible" }, roles = { "InfantryGun", "AntiTank", "Breakthrough" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "su152"},
				{availability = "1.2", base = { "SPG" }, class = { "Heavy" }, grade = "Grade4", posture = { "Flexible" }, roles = { "InfantryGun", "AntiTank", "Breakthrough" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "isu152"},

				{availability = "1.6", base = { "SPG" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "Artillery" }, effects = { "VsInfantry" }, unit = "t60_bm8_24"},
				--]]
			---]====]
		}
	}
}
