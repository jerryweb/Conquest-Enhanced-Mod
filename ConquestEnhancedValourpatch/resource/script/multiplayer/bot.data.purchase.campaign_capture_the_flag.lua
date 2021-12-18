Purchases["campaign_capture_the_flag"] = {
	{
		Repeat = 0, --infinite
		Units = {
			["ger"] = {--Germany
			--Infantry Singles
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(ger)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(ger)"},	
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(ger)"},

			--	{priority = 0.1, class = UnitClass.Infantry, unit = "single_medic(ger)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(ger)"},
			--	{priority = 0.1, class = UnitClass.Infantry, unit = "single_officer(ger)"},

				{priority = 0.5, class = UnitClass.Infantry, unit = "single_ap_miner(ger)"},	
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_at_miner(ger)"},
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(ger)"},

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
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.ATTank, unit = "mg34_lafette"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "mg42_lafette"},
			--	{priority = 1.0, class = UnitClass.ATTank, unit = "20mm_flak30"},
			--	{priority = 1.0, class = UnitClass.ATTank, unit = "37mm_flak37"},
			--AT_Wreapon
			--	{priority = 1.0, class = UnitClass.ATTank, unit = "37mm_pak36"},
			--	{priority = 1.0, class = UnitClass.ATTank, unit = "47mm_pakt"},
			--	{priority = 2.0, class = UnitClass.ATTank, unit = "50mm_pak38"},
			--	{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_leig18"},
			--	{priority = 2.0, class = UnitClass.ATTank, unit = "88mm_flak18"},
			--	{priority = 2.0, class = UnitClass.ATTank, unit = "88mm_flak36"},
			--	{priority = 2.0, class = UnitClass.ATTank, unit = "75mm_pak40"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ATTank, unit = "80mm_sgrw34"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "105mm_lefh18"},
				{priority = 2.0, class = UnitClass.ATTank, unit = "150mm_sig33"},
				{priority = 2.0, class = UnitClass.ATTank, unit = "150mm_sfh18"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "150mm_nebelwerfer41"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "210mm_morser18"},
				{priority = 2.0, class = UnitClass.ATTank, unit = "120mm_sgrw42"},
			--Wheel_vehicles
				{priority = 1.5, class = UnitClass.Vehicle, unit = "kubelwagen_mg"},
				{priority = 2.0, class = UnitClass.Vehicle, unit = "blitz3_6_flak30"},
				{priority = 0.1, class = UnitClass.Vehicle, unit = "p204_f"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz231"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "sdkfz221"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "sdkfz234_2"},
			--Half_tracks
				{priority = 1.0, class = UnitClass.Vehicle, unit = "sdkfz251c"},
				{priority = 0.1, class = UnitClass.ATTank, unit = "sdkfz10_pak38"},
				{priority = 0.1, class = UnitClass.ATTank, unit = "sdkfz8_flak18"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer1b"},
				{priority = 0.1, class = UnitClass.Tank, unit = "panzer1f"},
				{priority = 2.0, class = UnitClass.Tank, unit = "panzer2c"},
				{priority = 2.0, class = UnitClass.Tank, unit = "panzer2f"},
				{priority = 1.5, class = UnitClass.Tank, unit = "panzer35t"},
				{priority = 2.5, class = UnitClass.Tank, unit = "pz38t_a"},
				{priority = 2.5, class = UnitClass.Tank, unit = "pz38t_f"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz38t_g"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer2l"},
			--Tanks_medium
				{priority = 2.5, class = UnitClass.Tank, unit = "panzer3e"},
				{priority = 2.5, class = UnitClass.Tank, unit = "panzer3f"},
				{priority = 3.5, class = UnitClass.Tank, unit = "panzer3j"},
				{priority = 2.5, class = UnitClass.Tank, unit = "panzer3j1"},
				{priority = 2.5, class = UnitClass.Tank, unit = "panzer3l"},
				{priority = 2.5, class = UnitClass.Tank, unit = "panzer3m"},
				{priority = 1.5, class = UnitClass.Tank, unit = "panzer3n"},
				{priority = 0.5, class = UnitClass.Tank, unit = "panzer3_flamm"},
				{priority = 1.0, class = UnitClass.Tank, unit = "panzer4d"},
				{priority = 1.5, class = UnitClass.Tank, unit = "panzer4f1"},
				{priority = 3.0, class = UnitClass.Tank, unit = "panzer4f2"},
				{priority = 3.0, class = UnitClass.Tank, unit = "panzer4g"},
				{priority = 3.5, class = UnitClass.Tank, unit = "panzer4h"},
				{priority = 3.0, class = UnitClass.Tank, unit = "panzer4j"},
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "panzerjager1"},
				{priority = 1.5, class = UnitClass.ATTank, unit = "stug3b"},
				{priority = 1.5, class = UnitClass.ATTank, unit = "stug3f"},
				{priority = 3.0, class = UnitClass.ATTank, unit = "stug3g"},
				{priority = 0.5, class = UnitClass.ATTank, unit = "stug3g_late"},
				{priority = 2.5, class = UnitClass.ATTank, unit = "hetzer"},
				{priority = 2.0, class = UnitClass.ATTank, unit = "marder2"},
				{priority = 2.5, class = UnitClass.ATTank, unit = "marder3m"},
				{priority = 0.1, class = UnitClass.Tank, unit = "grille_m"},
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "stuh42"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sturmpanzer4"},
			
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "panzer5d"},
				{priority = 2.5, class = UnitClass.HeavyTank, unit = "panzer5a"},
				{priority = 2.5, class = UnitClass.HeavyTank, unit = "panzer5g"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "tiger1h"},
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "tiger1e"},
			--	{priority = 0.1, class = UnitClass.HeavyTank, unit = "tiger1hunt"},
			--	{priority = 0.1, class = UnitClass.HeavyTank, unit = "tiger2p"},
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "tiger2h"},
			--SPG
				{priority = 0.1, class = UnitClass.ArtilleryTank, unit = "bison"},
				{priority = 0.1, class = UnitClass.ArtilleryTank, unit = "sig33b"},
				{priority = 0.1, class = UnitClass.ATTank, unit = "ferdinand"},
				{priority = 0.1, class = UnitClass.ATTank, unit = "sturmtiger"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "jagdpanther"}
			},
			["fra"] = {--France
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(fra)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(fra)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade_late(fra)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(fra)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(fra)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(fra)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(fra)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(fra)"},
				-- 6
			--Automatic_weaponry
			--AT_Wreapon
			--Howitzers
			{priority = 0.8, class = UnitClass.ArtilleryTank, unit = "0_3cal_m1919a4_fr"},
			{priority = 0.8, class = UnitClass.ArtilleryTank, unit = "0_5cal_m2hb_fr"},
			{priority = 0.8, class = UnitClass.ArtilleryTank, unit = "75_mm_m1897a4_fr"},
			{priority = 0.8, class = UnitClass.ArtilleryTank, unit = "81_mm_m1_fr"},
			{priority = 0.8, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l_fr"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dodgewc55_fr"},	
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m4halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_fr"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m17_fr"},	
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8_fr"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75_fr"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_76_fr"},
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine_fr"},
				{priority = 0.2, class = UnitClass.ArtilleryTank, unit = "m7_fr"}
			},
			["pol"] = {--Poland
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(pol)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(pol)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(pol)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(pol)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(pol)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(pol)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(pol)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(pol)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(pol)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(pol)"},
				-- 6
			--Automatic_weaponry
			--AT_Wreapon
			--Howitzers
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "303_bren_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bl45_pol"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_pol"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound_pol"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_pol"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_pol"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly_pol"},
			--Tanks_heavy			
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "achilles_pol"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton_pol"}
			},
			["jap"] = {--Japan
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(jap)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(jap)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(jap)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(jap)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(jap)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(jap)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(jap)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_sturmtrooper(jap)"},
				-- 6
			--Automatic_weaponry
			--AT_Wreapon
			--Howitzers
			{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "type92_stan"},
			{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "20mm_type_2"},
			{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "75mm_type_41"},
			{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81mm_brandt_jap"},
			{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "150mm_type_97"},
			{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "200mm_type_4"},
			{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105mm_type_92"},
			{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "120mm_type_38"},
			--Wheel_vehicles
				{priority = 2.5, class = UnitClass.Vehicle, unit = "type93"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "type94aa"},
			--Half_tracks
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "type94_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type97_te-ke"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type95_ha-go"},
			--Tanks_medium
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_chi-ha"},
				{priority = 1.5, class = UnitClass.Tank, unit = "type97_shinhoto_47mm"},
				{priority = 2.0, class = UnitClass.Tank, unit = "type1_chi-he"},
				{priority = 2.5, class = UnitClass.Tank, unit = "type97_shinhoto_120mm"},
				{priority = 0.5, class = UnitClass.Tank, unit = "type3_chi-nu"},
			--SPG
				{priority = 1.0, class = UnitClass.ATTank, unit = "type1_ho-ni1"},
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "type1_ho-ni2"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "type4_ho-ro"}
			--Tanks_heavy
			},
			["usa"] = {--USA
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at(usa)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar(usa)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_riflegrenade(usa)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(usa)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(usa)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(usa)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(usa)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(usa)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_sturmtrooper(usa)"},
			--Automatic_weaponry
			--AT_Weapons
			--Howitzers			
                {priority = 1.0, class = UnitClass.ArtilleryTank, unit = "0_3cal_m1917a1_aa"},
                {priority = 1.0, class = UnitClass.ArtilleryTank, unit = "0_5cal_m2hb"},
                {priority = 1.0, class = UnitClass.ArtilleryTank, unit = "75_mm_m1"},
                {priority = 1.0, class = UnitClass.ArtilleryTank, unit = "81_mm_m1"},
                {priority = 1.0, class = UnitClass.ArtilleryTank, unit = "107_mm_m2"},	
                {priority = 1.0, class = UnitClass.ArtilleryTank, unit = "105_mm_m2a1l"},	
                {priority = 1.0, class = UnitClass.ArtilleryTank, unit = "155_mm_m2"},	
		    --Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willysmb"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willys50"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "willysat"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dodgewc55"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3a1_scout"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m20"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m16"},											  
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m8_grayhound"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t30hmc"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "cckw353_2xt27"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Tank, unit = "m22"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_stuart"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m3_satan"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m5a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m24_chaffee"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m18"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "m3lee"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a1"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4"},	
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_75"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3_zippo"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e8"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a3e2_jumbo"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3_105"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m4a3c"},	
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "m4a3e2_jumbo_76w"},	
				{priority = 1.0, class = UnitClass.HeavyTank, unit = "m26_pershing"},
			--SPG
				{priority = 1.0, class = UnitClass.Vehicle, unit = "t12gmc"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m10wolverine"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m36"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7"}
			},
			["eng"] = {--Britain
			--Infantry
				-- 1
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_light_late(eng)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_at_late(eng)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(eng)"},
				-- 2
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_regular_late(eng)"},
				{priority = 2.0, class = UnitClass.ATInfantry, unit = "single_mortar_late(eng)"},
				-- 3
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(eng)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer_late(eng)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "single_sniper(eng)"},
				-- 4
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(eng)"},
				-- 5
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier_late(eng)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_stormtrooper_late(eng)"},
				-- 6
			--Automatic_weaponry
			--AT_Wreapon
			--Howitzers
			{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "303_bren"},
			{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "76mm_mk_ii"},
			{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "qf25pdr"},
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "dingo"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "m3halftrack_eng"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "humber"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "mk2daimler"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "staghound"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.AATank, unit = "crusader_aa2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "crusader_mk6"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "valentine_mkiii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "matilda_mkii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_iv"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4"},
				{priority = 1.0, class = UnitClass.Tank, unit = "challenger_a30"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m4a4_firefly"},
				{priority = 1.0, class = UnitClass.Tank, unit = "cromwell_mk_vi"},
				{priority = 1.0, class = UnitClass.Tank, unit = "comet_a34"},
			--Tanks_heavy
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_ii"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_iv"},
				{priority = 0.2, class = UnitClass.Tank, unit = "churchill_avre"},
				{priority = 1.0, class = UnitClass.Tank, unit = "churchill_mk_vii"},			
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "achilles"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "sexton"}
			},
			["ita"] = {--Italy
			--Infantry
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_light(ita)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_regular(ita)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_pionier(ita)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_stormtrooper(ita)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_mg(ita)"},
				{priority = 1.0, class = UnitClass.ATInfantry, unit = "single_atrifle(ita)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "single_flamer(ita)"},
			--Automatic_weaponry
			--AT_Weapons
			--Howitzers				
			--Wheel_vehicles
				{priority = 1.0, class = UnitClass.Vehicle, unit = "ab41"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "autocannone10017"},
			--Tanks_light
				{priority = 1.0, class = UnitClass.Vehicle, unit = "cv35"},
				{priority = 1.0, class = UnitClass.Tank, unit = "l640"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1441"},
				{priority = 1.0, class = UnitClass.Tank, unit = "m1542"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "pz3n_ita"},
				{priority = 1.0, class = UnitClass.Tank, unit = "pz4g_ita"},
			--Tanks_heavy			
			--SPG
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "m7518"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "m7534"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "stug3g_ita"}
			},	
			["rus"] = {--Russia
			--Infantry Singles
				{priority = 3.0, class = UnitClass.ATInfantry, unit = "single_at(rus)"},
				{priority = 1.5, class = UnitClass.ATInfantry, unit = "single_riflegrenade(rus)"},
			--	{priority = 0.1, class = UnitClass.Infantry, unit = "single_medic(rus)"},

				{priority = 1.5, class = UnitClass.Infantry, unit = "single_flamer(rus)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "single_sniper(rus)"},
			--	{priority = 0.1, class = UnitClass.Infantry, unit = "single_officer(rus)"},

				{priority = 0.5, class = UnitClass.Infantry, unit = "single_ap_miner(rus)"},
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_at_miner(rus)"},
				{priority = 0.5, class = UnitClass.Infantry, unit = "single_engineer(rus)"},

			--Infantry Squads
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_partisan_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_penal_con(rus)"},

				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_border(rus)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_conscript_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_recon_con(rus)"},
				{priority = 2.5, class = UnitClass.Infantry, unit = "squad_rifleunit_alt_con(rus)"},
				{priority = 3.5, class = UnitClass.Infantry, unit = "squad_rifleunit_con(rus)"},
				{priority = 3.0, class = UnitClass.ATInfantry, unit = "squad_at_rifle_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_smg_con(rus)"},
				{priority = 2.0, class = UnitClass.Infantry, unit = "squad_rifle_motorised_con"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_mountainrifles_con(rus)"},

				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_guards_smg_con(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_guardsrifle_motorised_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_con(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_assaultsappers_flame_con(rus)"},

				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_paras(rus)"},
				{priority = 1.0, class = UnitClass.Infantry, unit = "squad_spetsnaz(rus)"},
				{priority = 1.5, class = UnitClass.Infantry, unit = "squad_marines_con(rus)"},
			--Automatic_weaponry
				{priority = 1.0, class = UnitClass.ATTank, unit = "maxim"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "dshk_stan"},
			--	{priority = 1.0, class = UnitClass.ATTank, unit = "25mm_72k"},
			--	{priority = 1.0, class = UnitClass.ATTank, unit = "37mm_61k"},
			--AT_Wreapon
			--	{priority = 1.0, class = UnitClass.ATTank, unit = "45mm_m37"},
			--	{priority = 1.0, class = UnitClass.ATTank, unit = "57mm_zis2"},
			--	{priority = 2.0, class = UnitClass.ATTank, unit = "76mm_zis3"},
			--	{priority = 1.0, class = UnitClass.ATTank, unit = "75mm_m43"},
			--	{priority = 1.0, class = UnitClass.ATTank, unit = "76mm_m1927"},
			--	{priority = 2.0, class = UnitClass.ATTank, unit = "76mm_f22"},
			--	{priority = 2.0, class = UnitClass.ATTank, unit = "85mm_52k"},
			--Howitzers
				{priority = 1.0, class = UnitClass.ATTank, unit = "82mm_bm37"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "120mm_pm38"},
				{priority = 2.0, class = UnitClass.ATTank, unit = "122mm_m30"},
				{priority = 2.0, class = UnitClass.ATTank, unit = "152mm_ml20"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "203mm_b4"},
			--Wheel_vehicles
				{priority = 1.5, class = UnitClass.Vehicle, unit = "gaz67b"},
				{priority = 1.0, class = UnitClass.Vehicle, unit = "gaz_aaa_72k"},
				{priority = 1.5, class = UnitClass.Vehicle, unit = "ba20"},
				{priority = 2.0, class = UnitClass.Vehicle, unit = "ba6"},
				{priority = 0.5, class = UnitClass.Vehicle, unit = "ba64"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "bm13_studebaker"},
			--Tanks_light
				{priority = 0.5, class = UnitClass.Tank, unit = "t26_31"},
				{priority = 0.1, class = UnitClass.Tank, unit = "kht26"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t26_33"},
				{priority = 2.0, class = UnitClass.Tank, unit = "t26_39"},
				{priority = 0.1, class = UnitClass.Tank, unit = "t27"},
				{priority = 2.0, class = UnitClass.Tank, unit = "t37a"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t30"},
				{priority = 0.5, class = UnitClass.Tank, unit = "t40"},
				{priority = 3.0, class = UnitClass.Tank, unit = "t60"},
				{priority = 3.0, class = UnitClass.Tank, unit = "t70"},
				{priority = 3.0, class = UnitClass.Tank, unit = "t70m"},
				{priority = 0.5, class = UnitClass.Tank, unit = "bt2_da2"},
				{priority = 1.0, class = UnitClass.Tank, unit = "bt2"},
				{priority = 2.5, class = UnitClass.Tank, unit = "bt5"},
				{priority = 3.0, class = UnitClass.Tank, unit = "bt7"},
			--Tanks_medium
				{priority = 1.0, class = UnitClass.Tank, unit = "t28"},
				{priority = 2.0, class = UnitClass.Tank, unit = "t3476_40"},
				{priority = 2.5, class = UnitClass.Tank, unit = "t3476_41"},
				{priority = 0.1, class = UnitClass.Tank, unit = "t3457_41"},
				{priority = 3.5, class = UnitClass.Tank, unit = "t3476_42"},
				{priority = 3.5, class = UnitClass.Tank, unit = "t3476_43"},
				{priority = 0.1, class = UnitClass.Tank, unit = "t3457_43"},
				{priority = 1.0, class = UnitClass.Tank, unit = "t3476_43_flame"},
				{priority = 2.5, class = UnitClass.Tank, unit = "t3485_44"},
			--Tanks_heavy
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "kv1_40"},
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "kv2_40"},
				{priority = 2.0, class = UnitClass.HeavyTank, unit = "kv1_41"},
				{priority = 2.0, class = UnitClass.HeavyTank, unit = "kv1s"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "kv85"},
				{priority = 0.5, class = UnitClass.HeavyTank, unit = "is1_43"},
				{priority = 1.5, class = UnitClass.HeavyTank, unit = "is2_43"},
				{priority = 2.0, class = UnitClass.HeavyTank, unit = "is2_44"},
			--SPG
				{priority = 0.1, class = UnitClass.ATTank, unit = "zis30"},
				{priority = 3.0, class = UnitClass.ArtilleryTank, unit = "su76"},
				{priority = 1.5, class = UnitClass.ATTank, unit = "su85"},
				{priority = 1.0, class = UnitClass.ATTank, unit = "su100"},
				{priority = 1.5, class = UnitClass.ArtilleryTank, unit = "su122"},
				{priority = 1.0, class = UnitClass.ArtilleryTank, unit = "su152"},
				{priority = 2.0, class = UnitClass.ArtilleryTank, unit = "isu152"}
			}
		}
	}
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
