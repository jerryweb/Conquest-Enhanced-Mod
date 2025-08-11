
; Presets for all melee, small arm weapons and avoidance skills

(include "/set/breed/presets/perks/health.inc")


;/* - Fortification Building Skills - */

(define "fortification"
	{barricade
		{"fortifications" "foxhole"}
		{"fortifications" "medic_rally"}
	}
	{"resources" "10%"}
)

(define "engineer"
	{fortification}
	{barricade
		{"fortifications" "barricade_sq"}
		{"fortifications" "barricade"}

		{"fortifications" "barbwire"}
		{"fortifications" "hedgehog"}

		{"fortifications" "foxhole"}
		{"fortifications" "foxhole_big"}
		{"fortifications" "mortar_pit"}
		{"fortifications" "tank_cover"}

		{"fortifications" "heavy_mg_mg34"}
		{"fortifications" "heavy_mg_maxim"}
		{"fortifications" "heavy_mg_maxim_m1910_30"}
		{"fortifications" "heavy_mg_m1917_30cal"}

		{"fortifications" "placement_nest"}
		{"fortifications" "watch_tower"}
		{"fortifications" "emplacement_trench"}
		{"fortifications" "pillbox_earth"}
		{"fortifications" "sandbag_watchtower"}
		{"fortifications" "sandbag_heap_curved"}
        {"fortifications" "fire_position"}
		{"fortifications" "mg_new_foxhole"}
        {"fortifications" "sandbag_framed_straight"}
        {"fortifications" "sand_shuttering_box5"}
		{"fortifications" "sand_shuttering_box1"}
        {"fortifications" "sandbag_straight_heap"}
         {"fortifications" "mg42_lafette_emplacement"}
        {"fortifications" "m1917_30cal_emplacement"}
        {"fortifications" "maxim_emplacement"}
        {"fortifications" "mgun_ring_emplacement"}
        {"fortifications" "emplacement_50mm_kwk39_platform"}
        {"fortifications" "maxim_x4_emplacement"}
        {"fortifications" "50cal_quad_m45_emplacement"}		
        {"fortifications" "emplacement_82mm_bm37"}
        {"fortifications" "emplacement_80mm_sgrw34_rapid"}
        {"fortifications" "emplacement_81mm_m1"}
        {"fortifications" "blitz3_6_radio"}
        {"fortifications" "simple_mg_bunker_dummy"}
        {"fortifications" "supply_crate_build"}
        {"fortifications" "sandbag_bunker_dummy_50cal"}
        {"fortifications" "sandbag_bunker_ds39_stand"} ;// Added 7 June
		{"fortifications" "sandbag_bunker_sg43_stand"} ;// Added 7 June
        {"fortifications" "sandbag_bunker_dummy_mg"}
        {"fortifications" "modular_ce_trench"} ;// Added June 15
        {"fortifications" "modular_ce_trench2"} ;// Added June 15
        {"fortifications" "emplacement_305mm_mb_2_12"}
        {"fortifications" "emplacement_152mm_ml20"}
        {"fortifications" "emplacement_155mm_gpf_us"}
        {"fortifications" "emplacement_155mm_gpf_platform"}
        {"fortifications" "regel_bau_pak_75mm_pak40"}
        {"fortifications" "aa_regelbau_flak_ring_88mm_flak36"}
        {"fortifications" "flak_ring_88mm_flak36"}
        {"fortifications" "mmpillbox_dummy"}
        {"fortifications" "pillbox_dummy"}
        {"fortifications" "flak_ring_dummy"}
        {"fortifications" "aa_regelbau_dummy"}
		{"fortifications" "sandbag_bunker_hmg42"} ;// Added 21 June 2025
        {"fortifications" "sandbag_bunker_m2_50cal_tripod"} ;// Added 21 June 2025
		{"fortifications" "regel_bau_76mm_m5_m1"} ;// Added 27 June 2025
		{"fortifications" "regel_bau_76mm_zis3"} ;// Added 27 June 2025
		
        {"fortifications" "240mm_type_45"}
        {"fortifications" "200mm_type_3"}
        
        {"fortifications" "heavy_mgg_type1"}
        {"fortifications" "heavy_200mm_type_4"}
        {"fortifications" "heavy_75mm_type_88"}
        {"fortifications" "heavy_57mm_type_2"}
        

	}
	{"resources" "1000%"}
	{"resources_regeneration" "0%"}
	{mechanic factor 2.0}
)

(define "engineer_heavy_fin"
	{fortification}
	{barricade
		{"fortifications" "barricade_sq"}
		{"fortifications" "barricade"}
		{"fortifications" "barbwire"}
		{"fortifications" "hedgehog"}
		{"fortifications" "foxhole"}
		{"fortifications" "foxhole_big"}
		{"fortifications" "tank_cover"}
		{"fortifications" "fin_bunker"}
		{"fortifications" "fin_coastal_gun"}
		{"fortifications" "placement_nest"}
		{"fortifications" "watch_tower"}
		{"fortifications" "emplacement_trench"}
		{"fortifications" "pillbox_earth"}
		{"fortifications" "sandbag_watchtower"}
		{"fortifications" "sandbag_heap_curved"}
        {"fortifications" "fire_position"}
		{"fortifications" "mg_new_foxhole"}
        {"fortifications" "sandbag_framed_straight"}
        {"fortifications" "sand_shuttering_box5"}
		{"fortifications" "sand_shuttering_box1"}
        {"fortifications" "sandbag_straight_heap"}

		{"fortifications" "heavy_mg_mg34"}
		{"fortifications" "heavy_mg_maxim"}
		{"fortifications" "heavy_mg_maxim_m1910_30"}
		{"fortifications" "heavy_mg_m1917_30cal"}
	}
	{"resources" "1000%"}
	{"resources_regeneration" "0%"}
	{mechanic factor 2.0}
)

;/* - Repair Skills - */

(define "skilled_repair"
	{mechanic factor 1.0}
)

(define "basic_repair"
	{mechanic factor 0.3}
)


;/* - Revive Skills - */

;(define "medic"
;	{"medic" 10.0}
;	{"speed" 1.15}
;	{"stamina" "180%"}
;)

;/* - Tank and Cannon Main Gun Weapon Skills - */

(define "elite_gun"
	{"tank_gun" lvl_6}
)

(define "expert_gun"
	{"tank_gun" lvl_4}
)

(define "skilled_gun"
	{"tank_gun" lvl_3}
)

(define "basic_gun"
	{"tank_gun" lvl_1}
)

;/* - Anti-Tank Weapon Skills - */

(define "at_rank_1"
	{"rocketlauncher" lvl_1}
	{"rifle" lvl_1}
)

(define "at_rank_2"
	{"rocketlauncher" lvl_2}
	{"rifle" lvl_2}
)

(define "at_rank_3"
	{"rocketlauncher" lvl_3}
	{"rifle" lvl_3}
)

(define "at_rank_4"
	{"rocketlauncher" lvl_4}
	{"rifle" lvl_4}
)

(define "at_rank_5"
	{"rocketlauncher" lvl_5}
	{"rifle" lvl_5}
)

(define "at_rank_6"
	{"rocketlauncher" lvl_6}
	{"rifle" lvl_6}
)


(define "skill_rank_0"
	("at_rank_1")
	{"pistol" lvl_1}
	{"smg" lvl_1}
	{"mgun" lvl_1}
	{"mgun_light" lvl_1}
	{"rifle" lvl_1}
	{"melee" lvl_1}
	{"avoidance" lvl_1}
    ;("health_rank_1")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "at_rank_7"
	{"rocketlauncher" lvl_7}
	{"rifle" lvl_7}
)

(define "at_rank_8"
	{"rocketlauncher" lvl_8}
	{"rifle" lvl_8}
)

(define "at_rank_9"
	{"rocketlauncher" lvl_9}
	{"rifle" lvl_9}
)

(define "at_rank_10"
	{"rocketlauncher" lvl_10}
	{"rifle" lvl_10}
)

(define "skill_rank_0"
	("at_rank_1")
	{"pistol" lvl_1}
	{"smg" lvl_1}
	{"mgun" lvl_1}
	{"rifle" lvl_1}
	{"melee" lvl_1}
	{"avoidance" lvl_1}
	;("health_rank_1")
	("fortification")
	("basic_repair")
	("basic_gun")
)

;/* - Sub-Machine Gunner Levels - ; Soldiers with an sub-machine gun their for primary weapon */

(define "smg_skill_rank_1"
	("at_rank_1")
	{"pistol" lvl_2}
	{"smg" lvl_2}
	{"mgun" lvl_1}
	{"mgun_light" lvl_1}
	{"rifle" lvl_1}
	{"melee" lvl_1}
	{"avoidance" lvl_1}
	;("health_rank_1")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "smg_skill_rank_2"
	("at_rank_2")
	{"pistol" lvl_3}
	{"smg" lvl_3}
	{"mgun" lvl_2}
	{"mgun_light" lvl_2}
	{"rifle" lvl_2}
	{"melee" lvl_2}
	{"avoidance" lvl_2}
	;("health_rank_2")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "smg_skill_rank_3"
	("at_rank_3")
	{"pistol" lvl_4}
	{"smg" lvl_4}
	{"mgun" lvl_3}
	{"mgun_light" lvl_3}
	{"rifle" lvl_3}
	{"melee" lvl_3}
	{"avoidance" lvl_3}
	;("health_rank_3")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "smg_skill_rank_4"
	("at_rank_4")
	{"pistol" lvl_5}
	{"smg" lvl_5}
	{"mgun" lvl_4}
	{"mgun_light" lvl_4}
	{"rifle" lvl_4}
	{"melee" lvl_4}
	{"avoidance" lvl_4}
	;("health_rank_4")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "smg_skill_rank_5"
	("at_rank_5")
	{"pistol" lvl_6}
	{"smg" lvl_6}
	{"mgun" lvl_5}
	{"mgun_light" lvl_4}
	{"rifle" lvl_5}
	{"melee" lvl_5}
	{"avoidance" lvl_5}
	;("health_rank_4")
	("fortification")
	("basic_repair")
	("basic_gun")
)


;/* - Rifleman Levels - ; Soldiers with an rifle for their primary weapon */

(define "rifle_skill_rank_1"
	("at_rank_1")
	{"pistol" lvl_2}
	{"smg" lvl_1}
	{"mgun" lvl_1}
	{"mgun_light" lvl_1}
	{"rifle" lvl_2}
	{"melee" lvl_1}
	{"avoidance" lvl_1}
	;("health_rank_1")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "rifle_skill_rank_2"
	("at_rank_2")
	{"pistol" lvl_3}
	{"smg" lvl_2}
	{"mgun" lvl_2}
	{"mgun_light" lvl_2}
	{"rifle" lvl_3}
	{"melee" lvl_2}
	{"avoidance" lvl_2}
	;("health_rank_2")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "rifle_skill_rank_3"
	("at_rank_3")
	{"pistol" lvl_4}
	{"smg" lvl_3}
	{"mgun" lvl_3}
	{"mgun_light" lvl_3}
	{"rifle" lvl_4}
	{"melee" lvl_3}
	{"avoidance" lvl_3}
	;("health_rank_3")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "rifle_skill_rank_4"
	("at_rank_4")
	{"pistol" lvl_5}
	{"smg" lvl_4}
	{"mgun" lvl_4}
	{"mgun_light" lvl_4}
	{"rifle" lvl_5}
	{"melee" lvl_4}
	{"avoidance" lvl_4}
	;("health_rank_4")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "rifle_skill_rank_5"
	("at_rank_5")
	{"pistol" lvl_6}
	{"smg" lvl_5}
	{"mgun" lvl_5}
	{"rifle" lvl_6}
	{"melee" lvl_5}
	{"avoidance" lvl_5}
	;("health_rank_4")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "rifle_skill_rank_6"
	("at_rank_6")
	{"pistol" lvl_7}
	{"smg" lvl_7}
	{"mgun" lvl_7}
	{"rifle" lvl_8}
	{"melee" lvl_7}
	{"avoidance" lvl_7}
	;("health_rank_4")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "rifle_skill_rank_7"
	("at_rank_7")
	{"pistol" lvl_6}
	{"smg" lvl_6}
	{"mgun" lvl_6}
	{"rifle" lvl_8}
	{"melee" lvl_6}
	{"avoidance" lvl_6}
	;("health_rank_4")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "rifle_skill_rank_8"
	("at_rank_8")
	{"pistol" lvl_6}
	{"smg" lvl_6}
	{"mgun" lvl_6}
	{"rifle" lvl_9}
	{"melee" lvl_6}
	{"avoidance" lvl_6}
	;("health_rank_4")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "rifle_skill_rank_9"
	("at_rank_9")
	{"pistol" lvl_6}
	{"smg" lvl_6}
	{"mgun" lvl_6}
	{"rifle" lvl_10}
	{"melee" lvl_6}
	{"avoidance" lvl_6}
	;("health_rank_4")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "rifle_skill_rank_10"
	("at_rank_10")
	{"pistol" lvl_6}
	{"smg" lvl_6}
	{"mgun" lvl_6}
	{"rifle" lvl_10}
	{"melee" lvl_6}
	{"avoidance" lvl_6}
	;("health_rank_4")
	("fortification")
	("basic_repair")
	("basic_gun")
)

;/* - MG Loaders/assistant Levels - ; Soldiers with an rifle/pistol for their primary weapon, but are also trained for MG use */

(define "loader_skill_rank_1"
	("at_rank_1")
	{"pistol" lvl_2}
	{"smg" lvl_1}
	{"mgun" lvl_2}
	{"mgun_light" lvl_2}
	{"rifle" lvl_2}
	{"melee" lvl_1}
	{"avoidance" lvl_1}
	;("health_rank_1")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "loader_skill_rank_2"
	("at_rank_2")
	{"pistol" lvl_3}
	{"smg" lvl_2}
	{"mgun" lvl_3}
	{"mgun_light" lvl_3}
	{"rifle" lvl_3}
	{"melee" lvl_2}
	{"avoidance" lvl_2}
	;("health_rank_2")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "loader_skill_rank_3"
	("at_rank_3")
	{"pistol" lvl_4}
	{"smg" lvl_3}
	{"mgun" lvl_4}
	{"mgun_light" lvl_4}
	{"rifle" lvl_4}
	{"melee" lvl_3}
	{"avoidance" lvl_3}
	;("health_rank_3")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "loader_skill_rank_4"
	("at_rank_4")
	{"pistol" lvl_5}
	{"smg" lvl_4}
	{"mgun" lvl_5}
	{"mgun_light" lvl_5}
	{"rifle" lvl_5}
	{"melee" lvl_4}
	{"avoidance" lvl_4}
	;("health_rank_4")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "loader_skill_rank_5"
	("at_rank_5")
	{"pistol" lvl_6}
	{"smg" lvl_5}
	{"mgun" lvl_6}
	{"rifle" lvl_6}
	{"melee" lvl_5}
	{"avoidance" lvl_5}
	;("health_rank_4")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "loader_skill_smg_rank_1"
	("at_rank_1")
	{"pistol" lvl_2}
	{"smg" lvl_2}
	{"mgun" lvl_2}
	{"mgun_light" lvl_2}
	{"rifle" lvl_1}
	{"melee" lvl_1}
	{"avoidance" lvl_1}
	;("health_rank_1")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "loader_skill_smg_rank_2"
	("at_rank_2")
	{"pistol" lvl_3}
	{"smg" lvl_3}
	{"mgun" lvl_3}
	{"mgun_light" lvl_3}
	{"rifle" lvl_2}
	{"melee" lvl_2}
	{"avoidance" lvl_2}
	;("health_rank_2")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "loader_skill_smg_rank_3"
	("at_rank_3")
	{"pistol" lvl_4}
	{"smg" lvl_4}
	{"mgun" lvl_4}
	{"mgun_light" lvl_4}
	{"rifle" lvl_3}
	{"melee" lvl_3}
	{"avoidance" lvl_3}
	;("health_rank_3")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "loader_skill_smg_rank_4"
	("at_rank_4")
	{"pistol" lvl_5}
	{"smg" lvl_5}
	{"mgun" lvl_5}
	{"mgun_light" lvl_5}
	{"rifle" lvl_4}
	{"melee" lvl_4}
	{"avoidance" lvl_4}
	;("health_rank_4")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "loader_skill_smg_rank_5"
	("at_rank_5")
	{"pistol" lvl_6}
	{"smg" lvl_6}
	{"mgun" lvl_6}
	{"rifle" lvl_5}
	{"melee" lvl_5}
	{"avoidance" lvl_5}
	;("health_rank_4")
	("fortification")
	("basic_repair")
	("basic_gun")
)


;/* - Machine Gunner Levels - ; Soldiers with an machine gun for their primary weapon */

(define "mg_skill_rank_1"
	("at_rank_1")
	{"pistol" lvl_2}
	{"smg" lvl_1}
	{"mgun" lvl_2}
	{"mgun_light" lvl_2}
	{"rifle" lvl_1}
	{"melee" lvl_1}
	{"avoidance" lvl_1}
	;("health_rank_1")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "mg_skill_rank_2"
	("at_rank_2")
	{"pistol" lvl_3}
	{"smg" lvl_2}
	{"mgun" lvl_3}
	{"mgun_light" lvl_3}
	{"rifle" lvl_2}
	{"melee" lvl_2}
	{"avoidance" lvl_2}
	;("health_rank_2")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "mg_skill_rank_3"
	("at_rank_3")
	{"pistol" lvl_4}
	{"smg" lvl_3}
	{"mgun" lvl_4}
	{"mgun_light" lvl_4}
	{"rifle" lvl_3}
	{"melee" lvl_3}
	{"avoidance" lvl_3}
	;("health_rank_3")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "mg_skill_rank_4"
	("at_rank_4")
	{"pistol" lvl_5}
	{"smg" lvl_4}
    {"mgun" lvl_5}
	{"mgun_light" lvl_5}
	{"rifle" lvl_4}
	{"melee" lvl_4}
	{"avoidance" lvl_4}
	;("health_rank_4")
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "mg_skill_rank_5"
	("at_rank_5")
	{"pistol" lvl_6}
	{"smg" lvl_5}
	{"mgun" lvl_6}
	{"rifle" lvl_5}
	{"melee" lvl_5}
	{"avoidance" lvl_5}
	;("health_rank_4")
	("fortification")
	("basic_repair")
	("basic_gun")
)