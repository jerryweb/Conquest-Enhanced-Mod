;AUTOMATIC WEAPONRY
{"mg34_lafette"
	 {on spawn
	    {tags add "HMG"}
		{tags add "german"}
		{tags add "mg34_lafette"}

	}
}
{"mg42_lafette"
	 {on spawn
	    {tags add "HMG"}
		{tags add "german"}
		{tags add "mg42_lafette"}

	}
}
{"mg131_lafette"
	 {on spawn
	    {tags add "HMG"}
		{tags add "german"}
		{tags add "mg131_lafette"}

	}
}
{"20mm_flak30"
	 {on spawn
	    {tags add "AAFLAK"}
		{tags add "german"}
		{tags add "20mm_flak30"}

	}
}
{"37mm_flak37"
	 {on spawn
	    {tags add "AAFLAK"}
		{tags add "german"}
		{tags add "37mm_flak37"}

	}
}

; AT WEAPONRY
{"28mm_pzb41"
	{on spawn
	    {tags add "light_at_gun"}
		{tags add "german"}
		{tags add "28mm_pzb41"}

	}
}
{"37mm_pak36"
	{on spawn
	    {tags add "light_at_gun"}
		{tags add "german"}
		{tags add "37mm_pak36"}

	}
}
{"37mm_pak36_late"
	{on spawn
	    {tags add "light_at_gun"}
		{tags add "german"}
		{tags add "37mm_pak36_late"}

	}
}
{"47mm_pakt"
	{on spawn
	    {tags add "light_at_gun"}
		{tags add "german"}
		{tags add "47mm_pakt"}

	}
}
{"50mm_pak38"
	{on spawn
	    {tags add "medium_at_gun"}
		{tags add "german"}
		{tags add "50mm_pak38"}

	}
}
{"75mm_pak40"
	{on spawn
	    {tags add "medium_at_gun"}
		{tags add "german"}
		{tags add "75mm_pak40"}

	}
}
{"88mm_flak18"
	{on spawn
	    {tags add "heavy_at_gun"}
		{tags add "german"}
		{tags add "88mm_flak18"}

	}
}
{"88mm_flak36"
	{on spawn
	    {tags add "heavy_at_gun"}
		{tags add "german"}
		{tags add "88mm_flak36"}

	}
}


;HOWITZERS
{"75mm_leig18"
	{on spawn
    	{tags add "medium_at_gun"}
		{tags add "german"}
		{tags add "75mm_leig18"}

	}
}
{"80mm_sgrw34"
	{on spawn
    	{tags add "artillery"}
		{tags add "german"}
		{tags add "80mm_sgrw34"}

	}
}
{"120mm_sgrw42"
	{on spawn
    	{tags add "artillery"}
		{tags add "german"}
		{tags add "120mm_sgrw42"}

	}
}
{"105mm_lefh18"
	{on spawn
    	{tags add "artillery"}
		{tags add "german"}
		{tags add "105mm_lefh18"}
	}
}
{"150mm_nebelwerfer41"
	{on spawn
		{tags add "rocket_artillery"}
		{tags add "german"}
		{tags add "150mm_nebelwerfer41"}
	}
}
{"150mm_sig33"
	{on spawn
    	{tags add "heavy_at_gun"}
		{tags add "german"}
		{tags add "150mm_sig33"}
	}
}
{"150mm_sfh18"
	{on spawn
    	{tags add "artillery"}
		{tags add "german"}
		{tags add "150_sfh18"}
	}
}
{"210mm_morser18"
	{on spawn
    	{tags add "super_heavy_artillery"}
    	{tags add "artillery"}
		{tags add "german"}
		{tags add "210mm_morser18"}

	}
}
{"300mm_nebelwerfer42"
	{on spawn
		{tags add "rocket_artillery"}
		{tags add "german"}
		{tags add "300mm_nebelwerfer42"}

	}
}
{"105mm_lefh18ai"
	{on spawn
    	{tags add "artillery"}
		{tags add "german"}
		{tags add "105mm_lefh18ai"}
		{tags add "no_scavenge"}
	}
}
{"150mm_nebelwerfer41ai"
	{on spawn
		{tags add "rocket_artillery"}
		{tags add "german"}
		{tags add "150mm_nebelwerfer41ai"}
		{tags add "no_scavenge"}
	}
}
{"150mm_sig33ai"
	{on spawn
    	{tags add "heavy_at_gun"}
		{tags add "german"}
		{tags add "150mm_sig33ai"}
		{tags add "no_scavenge"}
	}
}
{"150mm_sfh18ai"
	{on spawn
    	{tags add "artillery"}
		{tags add "german"}
		{tags add "150_sfh18ai"}
		{tags add "no_scavenge"}
	}
}
{"210mm_morser18ai"
	{on spawn
    	{tags add "super_heavy_artillery"}
    	{tags add "artillery"}
		{tags add "german"}
		{tags add "210mm_morser18ai"}
		{tags add "no_scavenge"}

	}
}
{"300mm_nebelwerfer42ai"
	{on spawn
		{tags add "rocket_artillery"}
		{tags add "german"}
		{tags add "300mm_nebelwerfer42ai"}
		{tags add "no_scavenge"}

	}
}

;_________________________________________________
;|               Wheeled vehicles                 |
;|________________________________________________|

{"kubelwagen"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "kubelwagen"}
	}
}
{"kubelwagen_mg"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "kubelwagen_mg"}
	}
}
{"kubelwagen_dak"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "kubelwagen_dak"}
	}
}
{"kettenkrad_eng"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "kettenkrad_eng"}
	}
}
{"blitz3_6"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "blitz3_6"}
	}
}
{"sdkfz250a_3"
	{on spawn
    	{if not tagged "radioger"
		    {tags add "radio_car"}
		}
		{tags add "german"}
		{tags add "sdkfz250a_3"}
	}
}
{"sdkfz10"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "sdkfz10"}
	}
}
{"sdkfz251c"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "sdkfz251c"}
	}
}
{"sdkfz250a_3"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "sdkfz250a_3"}
	}
}
{"sdkfz250a_11"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "sdkfz250a_11"}
	}
}
{"sdkfz221"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "sdkfz221"}
	}
}
{"sdkfz221_spzb41"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "sdkfz221_spzb41"}
	}
}
{"blitz3_6_flak30"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "blitz3_6_flak30"}
	}
}
{"sdkfz231"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "sdkfz231"}
	}
}
{"p204_f"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "p204_f"}
	}
}
{"sdkfz234_2"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "sdkfz234_2"}
	}
}
{"sdkfz10_pak38"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "sdkfz10_pak38"}
	}
}
{"sdkfz8_flak18"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "sdkfz8_flak18"}
	}
}
{"blitz3_6_art_ammo"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "blitz3_6_art_ammo"}
		{tags add "ammo"}
	}
}
{"blitz3_6_fuel"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "blitz3_6_fuel"}
	}
}
{"blitz3_6_engineering"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "blitz3_6_engineering"}
	}
}

{"sdkfz7"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "sdkfz7"}
	}
}
{"sdkfz7_2"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "sdkfz7_2"}
	}
}
{"sdkfz301wanze"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "sdkfz301wanze"}
	}
}

;_________________________________________________
;|        Main Battle Tanks and SPGs              |
;|________________________________________________|

{"sdkfz222"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "sdkfz222"}
	}
}
{"sdkfz234_1"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "sdkfz234_1"}
	}
}
{"sdkfz234_2"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "sdkfz234_2"}
	}
}
{"sdkfz234_3"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "sdkfz234_3"}
	}
}
{"sdkfz234_4"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "german"}
		{tags add "sdkfz234_4"}
	}
}

;LIGHT
{"panzer1b"
	{on spawn
    	{tags add "light_tank"}
		{tags add "german"}
		{tags add "panzer1b"}
	}
}
{"panzer1f"
	{on spawn
    	{tags add "light_tank"}
		{tags add "german"}
		{tags add "panzer1f"}
	}
}
{"panzer731r"
	{on spawn
    	{tags add "light_tank"}
		{tags add "german"}
		{tags add "panzer731r"}
	}
}
{"panzer742r"
	{on spawn
    	{tags add "light_tank"}
		{tags add "german"}
		{tags add "panzer742r"}
	}
}
{"panzer2c"
	{on spawn
    	{tags add "light_tank"}
		{tags add "german"}
		{tags add "panzer2c"}
	}
}
{"panzer2f"
	{on spawn
    	{tags add "light_tank"}
		{tags add "german"}
		{tags add "panzer2f"}
	}
}
{"panzer2j"
	{on spawn
    	{tags add "light_tank"}
		{tags add "german"}
		{tags add "panzer2j"}
	}
}
{"panzer2l"
	{on spawn
    	{tags add "light_tank"}
		{tags add "german"}
		{tags add "panzer2l"}
	}
}

{"h39_ger"
	{on spawn
    	{tags add "light_tank"}
		{tags add "german"}
		{tags add "h39_ger"}
	}
}
{"d2_ger"
	{on spawn
    	{tags add "light_tank"}
		{tags add "german"}
		{tags add "d2_ger"}
	}
}

{"pz35t"
	{on spawn
    	{tags add "light_tank"}
		{tags add "german"}
		{tags add "pz35t"}
	}
}
{"pz38t_a"
	{on spawn
    	{tags add "light_tank"}
		{tags add "german"}
		{tags add "pz38t_a"}
	}
}
{"pz38t_f"
	{on spawn
    	{tags add "light_tank"}
		{tags add "german"}
		{tags add "pz38t_f"}
	}
}
{"pz38t_g"
	{on spawn
    	{tags add "light_tank"}
		{tags add "german"}
		{tags add "pz38t_g"}
	}
}

;MEDIUM
{"char_b1"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "german"}
		{tags add "char_b1"}
	}
}
{"char_b1_flamer"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "german"}
		{tags add "char_b1_flamer"}
	}
}

{"panzer3e"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "german"}
		{tags add "panzer3e"}
	}
}
{"panzer3f"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "german"}
		{tags add "panzer3f"}
	}
}
{"panzer3j"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "german"}
		{tags add "panzer3j"}
	}
}
{"panzer3j1"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "german"}
		{tags add "panzer3j1"}
	}
}
{"panzer3l"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "german"}
		{tags add "panzer3l"}
	}
}
{"panzer3m"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "german"}
		{tags add "panzer3m"}
	}
}
{"panzer3n"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "german"}
		{tags add "panzer3n"}
	}
}
{"panzer3_flamm"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "german"}
		{tags add "panzer3_flamm"}
	}
}
{"panzer4d"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "german"}
		{tags add "panzer4d"}
	}
}
{"panzer4f1"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "german"}
		{tags add "panzer4f1"}
	}
}
{"panzer4f2"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "german"}
		{tags add "panzer4f2"}
	}
}
{"panzer4g"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "german"}
		{tags add "panzer4g"}
	}
}
{"panzer4h"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "german"}
		{tags add "panzer4b"}
	}
}
{"panzer4j"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "german"}
		{tags add "panzer4j"}
	}
}


{"t3476_43_ger"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "german"}
		{tags add "t3476_43_ger"}
	}
}
{"t3485_44_ger"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "german"}
		{tags add "t3485_44_ger"}
	}
}
{"m4a4_firefly_ger"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "german"}
		{tags add "m4a4_firefly_ger"}
	}
}

{"panzer5d"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "german"}
		{tags add "panzer5d"}
	}
}
{"panzer5a"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "german"}
		{tags add "panzer5a"}
	}
}
{"panzer5g"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "german"}
		{tags add "panzer5g"}
	}
}

;HEAVY
{"pz756r"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "german"}
		{tags add "pz756r"}
	}
}

{"tiger1h"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "german"}
		{tags add "tiger1h"}
	}
}
{"tiger1e"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "german"}
		{tags add "tiger1e"}
	}
}
{"tiger1hunt"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "german"}
		{tags add "tiger1hunt"}
	}
}
{"tiger2h"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "german"}
		{tags add "tiger2h"}
	}
}
{"tiger2p"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "german"}
		{tags add "tiger2p"}
	}
}

{"maus"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "german"}
		{tags add "maus"}
	}
}

;SPG
;--- StuGs ---
{"stug3a"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "stug3a"}
	}
}
{"stug3b"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "stug3b"}
	}
}
{"stug3f"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "stug3f"}
	}
}
{"stug3g"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "stug3g"}
	}
}
{"stug3g_late"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "stug3g_late"}
	}
}

;--- Panzerjäger ---
{"panzerjager1"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "panzerjager1"}
	}
}
{"marder_1fcm_36"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "marder_1fcm_36"}
	}
}
{"panzer2h"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "panzer2h"}
	}
}
{"marder2"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "marder2"}
	}
}
{"marder3h"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "marder3h"}
	}
}
{"marder3m"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "marder3m"}
	}
}
{"hetzer"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "hetzer"}
	}
}
{"jagdpanzer_iv"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "jagdpanzer_iv"}
	}
}
{"dicker_max"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "dicker_max"}
	}
}
{"sturer_emil"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "sturer_emil"}
	}
}
{"nashorn"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "nashorn"}
	}
}
{"elefant"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "elefant"}
	}
}
{"jagdtiger"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "jagdtiger"}
	}
}
{"ferdinand"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "ferdinand"}
	}
}
{"jagdpanther"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "jagdpanther"}
	}
}

;--- Panzerhaubitzen, Sturmpanzer & Panzerwerfer ---
{"zgkw303f"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "zgkw303f"}
	}
}
{"sdkfz4"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "sdkfz4"}
	}
}
{"sdkfz251_1_stuka"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "sdkfz251_1_stuka"}
	}
}
{"bison"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "bison"}
	}
}
{"bison2"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "bison2"}
	}
}
{"sig33b"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "sig33b"}
	}
}
{"grille"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "grille"}
	}
}
{"stuh42"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "stuh42"}
	}
}
{"wespe"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "wespe"}
	}
}
{"geschuetzwagen_ivb"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "geschuetzwagen_ivb"}
	}
}
{"b1sf"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "b1sf"}
	}
}
{"hummel"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "hummel"}
	}
}
{"sturmpanzer4"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "sturmpanzer4"}
	}
}
{"kv2_754r"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "kv2_754r"}
	}
}
{"sturmtiger"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "sturmtiger"}
	}
}

;--- Flakpanzer ---
{"flakpanzer1a"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "flakpanzer1a"}
	}
}
{"grille_m"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "grille_m"}
	}
}
{"wirbelwind"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "wirbelwind"}
	}
}
{"ostwind"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "ostwind"}
	}
}
{"kugelblitz"
	{on spawn
    	{tags add "spg"}
		{tags add "german"}
		{tags add "kugelblitz"}
	}
}

;_______________________________________________
;|					Aircraft					|
;|______________________________________________|

{"conquest_bf110"
	{on spawn
    	{tags add "aircraft"}
		{tags add "conquest_bf110"}
	}
}

{"bf110_e2" 
	{on spawn
    	{tags add "aircraft"}
	}
}

{"bf110_para_plane" 
	{on spawn
    	{tags add "aircraft"}
    	{tags add "german"}
    	{tags add "drop_plane"}
    	{tags add "ready_to_move"}
	}
}

{"bf110_playerplane" 
	{on spawn
    	{tags add "playerplane"}
    	{tags add "aircraft"}
    	{tags add "german"}
	}
}

{"bf110_para_planeplayer" 
	{on spawn
    	{tags add "player_drop_plane"}
    	{tags add "aircraft"}
    	{tags add "german"}
	}
}

