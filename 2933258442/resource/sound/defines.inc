;signal hit	-- AI reaction to sound
;loudness	tag
;volume		value
;tag		-- specifies to which volume group the sounds are belong to.
;				Possible groups: "effects", "emotions", "speech",
;				"environment" and "default"
;==============================================	IMPULSE SIGNALS ===================================
;**********************************************	SMALL ARMS  ***************************************
;----------------------------------------------	3RD PERSON DC -----------------------------------------------------
(define "Small-Arms_S1_3p"
	{loudness "weapon_3p"}
	{signal shot 120}
	{SignalPeriod 2}
	{tag effects}
)
(define "Small-Arms_S2_3p"
	{loudness "weapon_3p"}
	{signal shot 130}
	{SignalPeriod 2}
	{tag effects}
)
(define "Small-Arms_S3_3p"
	{loudness "weapon_3p"}
	{signal shot 140}
	{SignalPeriod 3}
	{tag effects}
)
(define "Small-Arms_S4_3p"
	{loudness "weapon_3p"}
	{signal shot 150}
	{SignalPeriod 3}
	{tag effects}
)
(define "Launcher_S1_3p"
	{loudness "weapon_3p"}
	{signal shot 160}
	{SignalPeriod 4}
	{tag effects}
)
;----------------------------------------------	CLOSE -----------------------------------------------
(define "Small-Arms_S1_close"
	{loudness "Small-Arms_S1_close"}
	{signal shot 120}
	{SignalPeriod 2}
	{tag effects}
	{volume 0.5}
)
(define "Small-Arms_S2_close"
	{loudness "Small-Arms_S2_close"}
	{signal shot 130}
	{SignalPeriod 2}
	{tag effects}
	{volume 0.5}
)
(define "Small-Arms_S3_close"
	{loudness "Small-Arms_S3_close"}
	{signal shot 140}
	{SignalPeriod 3}
	{tag effects}
	{volume 0.5}
)
(define "Small-Arms_S4_close"
	{loudness "Small-Arms_S4_close"}
	{signal shot 150}
	{SignalPeriod 3}
	{tag effects}
	{volume 0.5}
)
(define "Launcher_S1_close"
	{loudness "Launcher_S1_close"}
	{signal shot 160}
	{SignalPeriod 4}
	{tag effects}
)
;----------------------------------------------	MID -----------------------------------------------------
(define "Small-Arms_S1_mid"
	{loudness "Small-Arms_S1_mid"} 
	{tag effects}
)
(define "Small-Arms_S2_mid"
	{loudness "Small-Arms_S2_mid"}
	{tag effects}
)
(define "Small-Arms_S3_mid"
	{loudness "Small-Arms_S3_mid"}
	{tag effects}
)
(define "Small-Arms_S4_mid"
	{loudness "Small-Arms_S4_mid"}
	{tag effects}
)
(define "Launcher_S1_mid"
	{loudness "Launcher_S1_mid"}
	{tag effects}
)
;----------------------------------------------	FAR -----------------------------------------------------
(define "Small-Arms_S1_far"
	{loudness "Small-Arms_S1_far"}
	{tag effects}
)
(define "Small-Arms_S2_far"
	{loudness "Small-Arms_S2_far"}
	{tag effects}
)
(define "Small-Arms_S3_far" 
	{loudness "Small-Arms_S3_far"}
	{tag effects}
)
(define "Small-Arms_S4_far"
	{loudness "Small-Arms_S4_far"}
	{tag effects}
)
(define "Launcher_S1_far"
	{loudness "Launcher_S1_far"}
	{tag effects}

)
;**********************************************	CANNONS  ***************************************
(define "Autocannon_3p"
	{loudness "weapon_3p"}
	{signal shot 160}
	{tag effects}
)
(define "Cannon_S1_3p"
	{loudness "weapon_3p"}
	{signal shot 160}
	{tag effects}
)
(define "Cannon_S2_3p"
	{loudness "weapon_3p"}
	{signal shot 160}
	{tag effects}
)
(define "Cannon_S3_3p"
	{loudness "weapon_3p"}
	{signal shot 180}
	{tag effects}
)
(define "Cannon_S4_3p" 
	{loudness "weapon_3p"}
	{signal shot 200}
	{tag effects}
)
(define "Cannon_S5_3p"
	{loudness "weapon_3p"}
	{signal shot 200}
	{tag effects}
)
(define "Cannon_S6_3p"
	{loudness "weapon_3p"}
	{signal shot 200}
	{tag effects}
)
(define "Launcher_S2_3p"
	{loudness "weapon_3p"}
	{signal shot 200}
	{tag effects}
)
;----------------------------------------------	Close -----------------------------------------------------
(define "Autocannon_close"
	{loudness "Cannon-Auto_close"}
	{signal shot 160}
	{SignalPeriod 5}
	{tag effects}
)
(define "Cannon_S1_close"
	{loudness "Cannon_S1_close"}
	{signal shot 160}
	{SignalPeriod 5}
	{volume 0.75}
	{tag effects}
)
(define "Cannon_S2_close"
	{loudness "Cannon_S2_close"}
	{signal shot 160}
	{SignalPeriod 5}
	{volume 0.75}
	{tag effects}
)
(define "Cannon_S3_close"
	{loudness "Cannon_S3_close"}
	{signal shot 180}
	{SignalPeriod 5}
	{volume 0.75}
	{tag effects}
)
(define "Cannon_S4_close" 
	{loudness "Cannon_S4_close"}
	{signal shot 200}
	{SignalPeriod 5}
	{volume 0.75}
	{tag effects}
)
(define "Cannon_S5_close"
	{loudness "Cannon_S5_close"}
	{signal shot 200}
	{SignalPeriod 7}
	{volume 0.75}
	{tag effects}
)
(define "Cannon_S6_close"
	{loudness "Cannon_S6_close"}
	{signal shot 200}
	{SignalPeriod 7}
	{volume 0.75}
	{tag effects}
)
(define "Launcher_S2_close"
	{loudness "Launcher_S2_close"}
	{signal shot 200}
	{SignalPeriod 7}
	{volume 0.5}
	{tag effects}
)
;----------------------------------------------	Sweeteners -----------------------------------------------------
(define "mortar_sweetener_light"
	{loudness "mortar_sweetener_light"}
	{tag effects}
)
(define "mortar_sweetener"
	{loudness "mortar_sweetener"}
	{tag effects}
)
(define "cannon_sweetener_light"
	{loudness "cannon_sweetener_light"}
	{tag effects}
)
(define "cannon_sweetener"
	{loudness "cannon_sweetener"}
	{tag effects}
)
;----------------------------------------------	MID -----------------------------------------------------
(define "Autocannon_mid"
	{loudness "Cannon-Auto_mid"}
	{volume 1.25}
	{tag effects}
)
(define "Cannon_S1_mid"
	{loudness "Cannon_S1_mid"}
	{volume 1.25}
	{tag effects}
)
(define "Cannon_S2_mid"
	{loudness "Cannon_S2_mid"}
	{volume 1.25}
	{tag effects}
)
(define "Cannon_S3_mid"
	{loudness "Cannon_S3_mid"}
	{volume 1.25}
	{tag effects}
)
(define "Cannon_S4_mid" 
	{loudness "Cannon_S4_mid"}
	{volume 1.25}
	{tag effects}
)
(define "Cannon_S5_mid"
	{loudness "Cannon_S5_mid"}
	{volume 1.25}
	{tag effects}
)
(define "Cannon_S6_mid"
	{loudness "Cannon_S6_mid"}
	{volume 1.25}
	{tag effects}
)
(define "Launcher_S2_mid"
	{loudness "Launcher_S2_mid"}
	{tag effects}
)
;----------------------------------------------	FAR -----------------------------------------------------
(define "Autocannon_far"
	{loudness "Cannon-Auto_far"}
	{volume 1.25}
	{tag effects}
)
(define "Cannon_S1_far"
	{loudness "Cannon_S1_far"}
	{volume 1.25}
	{tag effects}
)
(define "Cannon_S2_far"
	{loudness "Cannon_S2_far"}
	{volume 1.25}
	{tag effects}
)
(define "Cannon_S3_far"
	{loudness "Cannon_S3_far"}
	{volume 1.25}
	{tag effects}
)
(define "Cannon_S4_far" 
	{loudness "Cannon_S4_far"}
	{volume 1.25}
	{tag effects}
)
(define "Cannon_S5_far"
	{loudness "Cannon_S5_far"}
	{volume 1.25}
	{tag effects}
)
(define "Cannon_S6_far"
	{loudness "Cannon_S6_far"}
	{volume 1.25}
	{tag effects}
)
(define "Launcher_S2_far"
	{loudness "Launcher_S2_far"}
	{volume 1.25}
	{tag effects}
)
;**********************************************	EXPLOSIONS  ***************************************
(define "Explosion_S1_shockwave"
	{loudness "Explosion_S1_shockwave"}
	{tag effects}
)
(define "Explosion_S2_shockwave"
	{loudness "Explosion_S2_shockwave"}
	{tag effects}
)
(define "Explosion_S3_shockwave"
	{loudness "Explosion_S3_shockwave"}
	{tag effects}
)
;----------------------------------------------	CLOSE -----------------------------------------------------
(define "Explosion-Auto_close"
	{loudness "Explosion_Auto_close"}
	{signal explosion 5}
	{volume 0.5}
	{tag effects}
)
(define "Explosion_S1_close"
	{loudness "Explosion_S1_close"}
	{signal explosion 5}
	{volume 0.5}
	{tag effects}
)
(define "Explosion_S2_close"
	{loudness "Explosion_S2_close"}
	{signal explosion 5}
	{volume 0.5}
	{tag effects}
)
(define "Explosion_S3_close"
	{loudness "Explosion_S3_close"}
	{signal explosion 10}
	{volume 0.5}
	{tag effects}
)
(define "Explosion_S4_close" 
	{loudness "Explosion_S4_close"}
	{signal explosion 10}
	{volume 0.5}
	{tag effects}
)
(define "Explosion_S5_close"
	{loudness "Explosion_S5_close"}
	{signal explosion 10}
	{volume 0.5}
	{tag effects}
)
(define "Explosion_S6_close"
	{loudness "Explosion_S6_close"}
	{signal explosion 10}
	{volume 0.5}
	{tag effects}
)
;----------------------------------------------	MID -----------------------------------------------------
(define "Explosion-Auto_mid"
	{loudness "Explosion_Auto_mid"}
	{volume 0.8}
	{tag effects}
)
(define "Explosion_S1_mid"
	{loudness "Explosion_S1_mid"}
	{volume 1.25}
	{tag effects}
)
(define "Explosion_S2_mid"
	{loudness "Explosion_S2_mid"}
	{volume 1.25}
	{tag effects}
)
(define "Explosion_S3_mid"
	{loudness "Explosion_S3_mid"}
	{volume 1.25}
	{tag effects}
)
(define "Explosion_S4_mid" 
	{loudness "Explosion_S4_mid"}
	{volume 1.25}
	{tag effects}
)
(define "Explosion_S5_mid"
	{loudness "Explosion_S5_mid"}
	{volume 1.25}
	{tag effects}
)
(define "Explosion_S6_mid"
	{loudness "Explosion_S6_mid"}
	{volume 1.25}
	{tag effects}
)
;----------------------------------------------	FAR -----------------------------------------------------
(define "Explosion-Auto_far"
	{loudness "Explosion_Auto_far"}
	{tag effects}
)
(define "Explosion_S1_far"
	{loudness "Explosion_S1_far"}
	{volume 1.25}
	{tag effects}
)
(define "Explosion_S2_far"
	{loudness "Explosion_S2_far"}
	{volume 1.25}
	{tag effects}
)
(define "Explosion_S3_far"
	{loudness "Explosion_S3_far"}
	{volume 1.25}
	{tag effects}
)
(define "Explosion_S4_far" 
	{loudness "Explosion_S4_far"}
	{volume 1.25}
	{tag effects}
)
(define "Explosion_S5_far"
	{loudness "Explosion_S5_far"}
	{volume 1.25}
	{tag effects}
)
(define "Explosion_S6_far"
	{loudness "Explosion_S6_far"}
	{volume 1.25}
	{tag effects}
)
;----------------------------------------------	IMPACT SIGNALS	--------------------------------------
;///////////////////////////////////////////////Shell Casings
(define "casing_s1_soft"
	{loudness "casing_s1"}
	{tag effects}
	{volume 0.35}
)
(define "casing_s1_hard"
	{loudness "casing_s1"}
	{tag effects}
	{volume 0.5}
)
(define "casing_s2_soft"
	{loudness "casing_s2"}
	{tag effects}
	{volume 0.35}
)
(define "casing_s2_hard"
	{loudness "casing_s2"}
	{tag effects}
	{volume 0.5}
)
(define "casing_s3_soft"
	{loudness "casing_s3"}
	{tag effects}
	{volume 0.35}
)
(define "casing_s3_hard"
	{loudness "casing_s3"}
	{tag effects}
	{volume 0.5}
)
(define "casing_large"
	{signal hit 7.5}
	{loudness "casing_s3"}
	{tag effects}
	{volume 0.5}
)
(define "casing_s5_soft"
	{signal hit 7.5}
	{loudness "casing_s5"}
	{tag effects}
)
;///////////////////////////////////////////////Sonic Cracks
(define "crack_s1_d1"
	{signal hit 25}
	{loudness "crack_s1_d1"}
	{tag effects}
)
(define "crack_s1_d2"
	{loudness "crack_s1_d2"}
	{tag effects}
	{volume 0.5}
)
(define "crack_s2_d1"
	{signal hit 25}
	{loudness "crack_s2_d1"}
	{tag effects}
)
(define "crack_s2_d2"
	{loudness "crack_s2_d2"}
	{tag effects}
	{volume 0.5}
)
(define "crack_s3_d1"
	{signal hit 25}
	{loudness "crack_s3_d1"}
	{tag effects}
	{volume 0.75}
)
(define "crack_s3_d2"
	{loudness "crack_s3_d2"}
	{tag effects}
	{volume 0.5}
)
(define "crack_s4_d1"
	{signal hit 35}
	{loudness "crack_s4_d1"}
	{tag effects}
)
(define "crack_s4_d2"
	{loudness "crack_s4_d2"}
	{tag effects}
)
;=========================Projectiles=========================
(define "projectile"
	{loudness "projectile"}
	{tag environment}
)
(define "projectile_high_vel"
	{loudness "projectile_high_vel"}
	{tag environment}
)
(define "projectile_howitzer"
	{loudness "projectile_howitzer"}
	{tag environment}
)
;=========================ANIMAL=========================

(define "animal"
	{loudness "animal"}
	{volume 0.5}
	{tag environment}
)

;=========================CRUSH=========================

(define "crush"
	{signal hit 5}
	{loudness "crush"}
	{volume 0.8}
	{tag effects}
)
(define "crush_small"
	{signal hit 5}
	{loudness "crush"}
	{volume 0.8}
	{tag effects}
)

;=======================DETONATION======================
;---CLOSE---
(define "50kg_bomb"
	{signal explosion 10}
	{loudness "50kg_bomb"}
	{tag effects}
)

(define "100kg_bomb"
	{signal explosion 10}
	{loudness "100kg_bomb"}
	{tag effects}
)

(define "250kg_bomb"
	{signal explosion 20}
	{loudness "250kg_bomb"}
	{tag effects}
)

(define "ap_shell"
	{signal explosion 5}
	{loudness "ap_shell"}
	{volume 0.6}
	{tag effects}
)

(define "auto_shell"
	{signal explosion 5}
	{loudness "auto_shell"}
	{volume 1}
	{tag effects}
)

(define "cook_off"
	{signal explosion 5}
	{loudness "cook_off"}
	{tag effects}
)

(define "explosion_fiery"
	{signal explosion 5}
	{loudness "explosion_fiery"}
	{tag effects}
)

(define "explosion_medium"
	{signal explosion 10}
	{loudness "explosion_medium"}
	{tag effects}
)

(define "explosion_small"
	{signal explosion 5}
	{loudness "explosion_small"}
	{tag effects}
)

(define "explosion_vehicle"
	{signal explosion 20}
	{loudness "explosion_vehicle"}
	{tag effects}
)

(define "grenade"
	{signal explosion 5}
	{loudness "grenade"}
	{tag effects}
)

(define "grenade_smoke"
	{signal explosion 3}
	{loudness "grenade_smoke"}
	{volume 0.6}
	{tag effects}
)

(define "he_size1"
	{signal explosion 5}
	{loudness "he_size1"}
	{tag effects}
)

(define "he_size2"
	{signal explosion 5}
	{loudness "he_size2"}
	{tag effects}
)

(define "he_size3"
	{signal explosion 10}
	{loudness "he_size3"}
	{tag effects}
)

(define "he_size4"
	{signal explosion 20}
	{loudness "he_size4"}
	{tag effects}
)

(define "he_size5"
	{signal explosion 20}
	{loudness "he_size5"}
	{tag effects}
)

(define "exp_small"
	{signal explosion 5}
	{loudness "grenade"}
	{tag effects}
)

;---BKG---
(define "bkg_50kg_bomb"
	{loudness "bkg_50kg_bomb"}
	{tag effects}
)

(define "bkg_100kg_bomb"
	{loudness "bkg_100kg_bomb"}
	{tag effects}
)

(define "bkg_250kg_bomb"
	{loudness "bkg_250kg_bomb"}
	{tag effects}
)

(define "bkg_auto_shell"
	{loudness "bkg_auto_shell"}
	{tag effects}
)

(define "bkg_ap_shell"
	{loudness "bkg_ap_shell"}
	{tag effects}
)

(define "bkg_explosion_vehicle"
	{loudness "bkg_explosion_vehicle"}
	{tag effects}
)

(define "bkg_grenade"
	{loudness "bkg_grenade"}
	{tag effects}
)

(define "bkg_he_size1"
	{loudness "bkg_he_size1"}
	{tag effects}
)

(define "bkg_he_size2"
	{loudness "bkg_he_size2"}
	{tag effects}
)

(define "bkg_he_size3"
	{loudness "bkg_he_size3"}
	{tag effects}
)

(define "bkg_he_size4"
	{loudness "bkg_he_size4"}
	{tag effects}
)

(define "bkg_he_size5"
	{loudness "bkg_he_size5"}
	{tag effects}
)

(define "explosion_water"
	{loudness "explosion_water"}
	{volume 1}
	{tag effects}
)

;=========================FIRE=========================

(define "fire"
	{signal sound 3}
	{loudness "fire"}
	{volume 0.9}
	{tag effects}
)

;=========================GUI=========================

(define "gui"
	{loudness "gui"}
	{volume 0.5}
	{tag effects}
)

(define "pointer"
	{loudness "gui"}
	{volume 0.8}
	{tag effects}
)

;=========================HIT=========================

(define "hit_foliage"
	{signal hit 5}
	{loudness "hit_foliage"}
	{volume 0.4}
	{tag effects}
)

(define "hit_glass"
	{signal hit 5}
	{loudness "hit_glass"}
	{volume 0.4}
	{tag effects}
)

(define "hit_ground"
	{signal hit 5}
	{loudness "hit_ground"}
	{volume 0.4}
	{tag effects}
)

(define "hit_ground_large"
	{signal hit 10}
	{loudness "hit_ground_large"}
	{volume 0.5}
	{tag effects}
)

(define "hit_ground_shell"
	{signal hit 5}
	{loudness "hit_ground_shell"}
	{volume 0.3}
	{tag effects}
)

(define "hit_human"
	{signal hit 10}
	{loudness "hit_human"}
	{volume 0.5}
	{tag effects}
)

(define "hit_rock"
	{signal hit 10}
	{loudness "hit_rock"}
	{tag effects}
)

(define "hit_snow"
	{signal hit 5}
	{loudness "hit_snow"}
	{volume 0.4}
	{tag effects}
)

(define "hit_wood"
	{signal hit 5}
	{loudness "hit_wood"}
	{volume 0.4}
	{tag effects}
)

(define "hit_wood_large"
	{signal hit 15}
	{loudness "hit_wood_large"}
	{volume 0.6}
	{tag effects}
)

(define "hit_steel"
	{signal hit 10}
	{loudness "hit_steel"}
	{volume 0.5}
	{tag effects}
)

(define "hit_steel_large"
	{signal hit 15}
	{loudness "hit_steel_large"}
	{tag effects}
)

(define "hit_steel_penetrate"
	{signal hit 15}
	{loudness "hit_steel_penetrate"}
	{tag effects}
)

(define "hit_steel_ricochet"
	{signal hit 15}
	{loudness "hit_steel_ricochet"}
	{tag effects}
)

(define "bkg_hit_steel_penetrate"
	{signal hit 15}
	{loudness "bkg_hit_steel"}
	{tag effects}
)

(define "bkg_hit_steel_ricochet"
	{signal hit 15}
	{loudness "bkg_hit_steel"}
	{volume 1}
	{tag effects}
)

(define "hit_water"
	{signal hit 10}
	{loudness "hit_water"}
	{volume 0.4}
	{tag effects}
)

(define "water_splash"
	{signal hit 5}
	{loudness "water_splash"}
	{volume 0.4}
	{tag effects}
)

;========================HUMAN========================

(define "inf_anims"
	{signal sound 3}
	{loudness "inf_anims"}
	{volume 0.75}
	{tag effects}
)

(define "crawl"
	{signal movement 1}
	{loudness "footsteps"}
	{volume 0.35}
	{tag effects}
)

(define "run"
	{loudness "footsteps"}
	{signal movement 15}
	{volume 0.35}
	{SignalPeriod 0.5}
	{tag effects}
)
(define "walk"
	{loudness "footsteps"}
	{signal movement 5}
	{volume 0.35}
	{SignalPeriod 0.5}
	{tag effects}
)
(define "gear_rattle"
	{loudness "gear"}
	{volume 0.35}
	{tag effects}
)
(define "gear_rattle_normal"
	{loudness "gear"}
	{volume 0.35}
	{tag effects}
)
(define "gear_rattle_fast"
	{loudness "gear"}
	{volume 0.35}
	{tag effects}
)

(define "footsteps"
	{signal movement 8}
	{loudness "footsteps"}
	{tag effects}
)

(define "footsteps_cta"
	{signal movement 8}
	{loudness "footsteps"}
	{tag effects}
)

(define "footsteps_start"
	{signal movement 5}
	{loudness "footsteps"}
	{volume 0.2}
	{tag effects}
)

(define "swim"
	{signal movement 8}
	{loudness "swim"}
	{volume 0.3}
	{tag effects}
)

;======================INTERFACE======================

(define "interface"
	{loudness "interface"}
	{volume 0.5}
	{tag effects}
)

;=======================MISSION=======================

(define "mission"
	{loudness "mission"}
	{volume 1}
	{tag effects}
)

(define "mission_voice"
	{loudness "mission_voice"}
	{volume 1}
	{tag speech}
)

;========================PUSH========================

(define "push"
	{signal hit 15}
	{loudness "push"}
	{volume 0.3}
	{tag effects}
)

;========================TALK========================

(define "talk"
	{loudness "talk"}
	{volume 1}
	{tag emotions}
)
(define "talk_low"
	{loudness "talk_quiet"}
	{volume 0.7}
	{tag emotions}
)

(define "talk_normal"
	{loudness "talk_normal"}
	{volume 1}
	{tag emotions}
)
(define "talk_shout"
	{loudness "talk_shout"}
	{volume 1}
	{tag emotions}
)
(define "breath"
	{loudness "breath"}
	{volume 0.15}
	{tag effects}
)
(define "emotes"
	{loudness "talk"}
	{volume 1}
	{tag emotions}
)
;======================UTILITY======================

(define "utility"
	{loudness "utility"}
	{volume 1}
	{tag effects}
)

;======================VEHICLE======================
(define "vehicle_engine"
	{signal movement 30}
	{loudness "vehicle_engine"}
	{volume 0.40}
	{tag effects}
)
(define "vehicle_engine_idle"
	{signal movement 15}
	{volume 0.30}
	{loudness "vehicle_engine_idle"}
	{tag effects}
)
(define "vehicle_engine_small"
	{signal movement 30}
	{loudness "vehicle_engine_small"}
	{volume 0.30}
	{tag effects}
)
(define "vehicle_engine_small_idle"
	{signal movement 15}
	{volume 0.25}
	{loudness "vehicle_engine_small_idle"}
	{tag effects}
)
(define "vehicle_engine_car"
	{signal movement 30}
	{loudness "vehicle_engine_car"}
	{volume 0.50}
	{tag effects}
)
(define "vehicle_engine_car_idle"
	{signal movement 15}
	{volume 0.35}
	{loudness "vehicle_engine_car_idle"}
	{tag effects}
)
(define "vehicle_electric"
	{signal movement 10}
	{loudness "vehicle_engine_car"}
	{volume 0.3}
	{tag effects}
)

(define "vehicle_btr"
	{signal movement 30}
	{loudness "vehicle_engine"}
	{volume 0.6}
	{tag effects}
)

(define "vehicle_tracks"
	{signal movement 20}
	{loudness "vehicle_tracks"}
	{tag effects}
	{volume 0.8}
)
(define "vehicle_wheels"
	{signal movement 20}
	{loudness "vehicle_wheels"}
	{volume 0.5}
	{tag effects}
)
(define "vehicle_overlays"
	{signal movement 10}
	{loudness "vehicle_overlays"}
	{volume 0.5}
	{tag effects}
)

(define "vehicle_overlays_small"
	{signal movement 10}
	{loudness "vehicle_overlays_small"}
	{volume 0.5}
	{tag effects}
)

(define "vehicle_plane"
	{signal movement 30}
	{loudness "vehicle_plane"}
	{volume 0.7}
	{tag effects}
)

(define "vehicle_marine"
	{signal movement 30}
	{loudness "vehicle_marine"}
	{volume 0.7}
	{tag effects}
)

(define "vehicle_marine_large"
	{signal movement 30}
	{loudness "vehicle_marine_large"}
	{volume 1.0}
	{tag effects}
)

(define "vehicle_internal"
	{signal explosion 5}
	{loudness "vehicle_internal"}
	{volume 0.7}
	{tag effects}
)

(define "vehicle_anims"
	{signal movement 5}
	{loudness "vehicle_anims"}
	{volume 0.9}
	{tag effects}
)

(define "turret"
	{signal movement 5}
	{loudness "turret"}
	{volume 0.5}
	{tag effects}
)

(define "bkg_plane"
	{loudness "bkg_plane"}
	{volume 0.7}
	{tag effects}
)

;======================WEAPON======================

(define "reload"
	{signal sound 0}
	{loudness "reload"}
	{volume 1.0}
	{tag effects}
)
(define "cannon_reload"
	{signal sound 0}
	{loudness "cannon_reload"}
	{volume 1.0}
	{tag effects}
)
(define "recoil"
	{signal sound 1}
	{loudness "recoil"}
	{volume 0.4}
	{tag effects}
)
(define "recoil_cannon"
	{signal sound 1}
	{loudness "cannon_recoil"}
	{tag effects}
)
(define "reload_large"
	{signal sound 5}
	{loudness "reload_large"}
	{volume 1.1}
	{tag effects}
)

(define "reload_interior"
	{loudness "reload_interior"}
	{volume 1.0}
	{tag environment}
)

(define "equip"
	{signal sound 5}
	{loudness "equip"}
	{volume 0.8}
	{tag effects}
)

;---SHOTS---
(define "tracer"
	{signal shot 10}
	{loudness "tracer"}
	{tag effects}
)

(define "artillery"
	{signal shot 50}
	{loudness "artillery"}
	{tag effects}
)

(define "incoming"
	{signal shot 50}
	{loudness "artillery"}
	{volume 0.3}
	{tag effects}
)

(define "flame"
	{signal shot 100}
	{SignalPeriod 2}
	{loudness "flame"}
	{tag effects}
)

(define "mortar"
	{signal shot 20}
	{loudness "mortar"}
	{tag effects}
)

(define "gun_auto"
	{signal shot 15}
	{loudness "auto_size1"}
	{tag effects}
)

(define "gun_37_57"
	{signal shot 20}
	{loudness "gun_size1"}
	{tag effects}
)

(define "gun_75_105"
	{signal shot 30}
	{loudness "gun_size2"}
	{tag effects}
)

(define "gun_122_152"
	{signal shot 40}
	{loudness "gun_size3"}
	{tag effects}
)

(define "gun_203_210"
	{signal shot 50}
	{loudness "gun_size4"}
	{tag effects}
)

(define "rocket_large"
	{signal shot 50}
	{loudness "rocket_large"}
	{tag effects}
)

(define "rocket_small"
	{signal shot 20}
	{loudness "rocket_small"}
	{tag effects}
)

(define "3p_gun"
	{loudness "3p_gun"}
	{tag effects}
)

(define "mgun"
	{signal shot 20}
	{loudness "mgun"}
	{volume 0.9}
	{tag effects}
)

(define "rifle"
	{signal shot 20}
	{loudness "rifle"}
	{tag effects}
)

(define "pistol"
	{signal shot 15}
	{loudness "pistol"}
	{volume 0.7}
	{tag effects}
)

(define "smg"
	{signal shot 15}
	{loudness "smg"}
	{volume 0.7}
	{tag effects}
)

(define "supressed"
	{signal shot 2}
	{loudness "smg"}
	{volume 0.7}
	{tag effects}
)

(define "mg_interior"
	{loudness "vehicle_int_gun"}
	{signal shot 120}
	{SignalPeriod 1}
	{tag environment}
)
(define "MG_interior_S1"
	{loudness "vehicle_int_gun"}
	{signal shot 120}
	{SignalPeriod 1}
	{tag environment}
)
(define "MG_interior_S3"
	{loudness "vehicle_int_gun"}
	{signal shot 140}
	{SignalPeriod 1}
	{tag environment}
)
(define "MG_interior_S4"
	{loudness "vehicle_int_gun"}
	{signal shot 150}
	{SignalPeriod 1}
	{tag environment}
)

(define "gun_interior_size1"
	(include "\sound\signal_presets.inc")
	("int_gun_auto")
	{loudness "vehicle_int_gun"}
	{signal shot 160}
	{tag environment}
)

(define "gun_interior_size2"
	(include "\sound\signal_presets.inc")
	("int_gun_37_57")
	{loudness "vehicle_int_gun"}
	{signal shot 180}
	{tag environment}
)

(define "gun_interior_size3"
	(include "\sound\signal_presets.inc")
	("int_gun_75_105")
	{loudness "vehicle_int_gun"}
	{signal shot 200}
	{tag environment}
)

(define "gun_interior_size4"
	(include "\sound\signal_presets.inc")
	("int_gun_122_152")
	{loudness "vehicle_int_gun"}
	{signal shot 200}
	{tag environment}
)

;---BKG---
(define "bkg_auto"
	{loudness "bkg_auto"}
	{tag effects}
)

(define "bkg_gun_size1"
	{loudness "bkg_gun_size1"}
	{tag effects}
)

(define "bkg_gun_size2"
	{loudness "bkg_gun_size2"}
	{tag effects}
)

(define "bkg_gun_size3"
	{loudness "bkg_gun_size3"}
	{tag effects}
)

(define "bkg_gun_size4"
	{loudness "bkg_gun_size4"}
	{tag effects}
)

(define "bkg_rocket"
	{loudness "bkg_rocket"}
	{tag effects}
)

(define "bkg_mortar"
	{loudness "bkg_mortar"}
	{tag effects}
)

(define "bkg_hmg"
	{loudness "bkg_mgun"}
	{volume 0.45}
	{tag effects}
)

(define "bkg_mg"
	{loudness "bkg_mgun"}
	{volume 0.4}
	{tag effects}
)

(define "bkg_rifle"
	{loudness "bkg_rifle"}
	{volume 0.35}
	{tag effects}
)

(define "bkg_smg"
	{loudness "bkg_smg"}
	{volume 0.3}
	{tag effects}
)

;======================WORLD======================

(define "world"
	{loudness "world"}
	{volume 0.5}
	{tag main_environment}
)

(define "environment"
	{loudness "environment"}
	{volume 0.65}
	{tag environment}
)
(define "environment_local_tiny"
	{loudness "environment_local_small"}
	{tag environment}
	{volume 0.65}
)
(define "environment_local_small"
	{loudness "environment_local_small"}
	{tag environment}
)
(define "environment_local"
	{loudness "environment_local"}
	{tag environment}
)
