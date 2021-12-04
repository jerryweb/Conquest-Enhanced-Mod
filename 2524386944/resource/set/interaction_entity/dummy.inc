{"mud_sp_mesh"   ;// fx test
	{on spawn
		{scale from 0.1 to 1 time 0.001}
		{delay 1.0 
			{delete}
		}
	}
}

{"dummy"
	{on "stop"	{view stop ""}}
	{on "pause"	{view pause ""}}
	{on "delete"{delete}}
}

{"ps_dummy"
	{on "delete"{hide 3}}
}

{"physics_damping"
;	{friction 1000}
;	{restitution 0.001}
}


(define "throwing_weapon"
	{on contact
		{if effector "human"
			{delay 0
				{constrain_velocity 1}
			}
		}
	}
	{on "drop_item"							;// when item is not in hand and is dropped from inventory.
		{volumes "body" disable contact}	;// stops soldiers from killing themselves when removing knife from inventory
		{delay 1
			{volumes "body" enable contact}
		}
	}
)

{"knife" ("throwing_weapon")}
{"axe" ("throwing_weapon")}

{"stone"
	{on bullet_hit
		{bullet_detonate}
	}
}

{"wp_piece"		;// fx - white phosphorus 
	{on spawn
		{add_view "wp_flare" "wp" "root"}
		{view start "wp"}
		{delay 0.05
			{volumes "body" enable contact}
			{fire radius 0.3 time 0.2 heating 2 follow}
			{fire radius 0.15 time 15 heating 0.1 follow}
		}
		{delay 25 10
			{delete}
		}
	}
}

{"part"
	{on "check_delete_part"				;// called only inside tear, so with_effector swaps entity & effector for flag check
		{with_effector
			{if "delete_parts"
				{with_effector
					{delay 20
						{hide 3}
					}
				}
			}
		}
	}
}

{"flesh part"
	{on spawn
		{delay 0.01 {volumes disable bullet contact blast touch}}
		{delay 1 {volumes enable bullet contact blast touch}}
		{delay 300 240 {hide 1}}
	}
	{on blast
		{delay 0.01 {volumes disable bullet contact blast touch}}
		{delay 3 {volumes enable bullet contact blast touch}}
		{if rand 0.2 {spawn "ground_blood_big"}}
		{if rand 0.3 {spawn "ground_blood_small"}}
		{if rand 0.25 {spawn "ground_blood01"}}
		{if rand 0.2 {spawn "ground_blood02"}}
		{if rand 0.15 {spawn "ground_blood03"}}
	}
	{on bullet_hit
		{if rand 0.3 {spawn "bloodspark_small01"}}
		{if rand 0.3 {spawn "bloodspark_small02"}}
		{if rand 0.3 {spawn "bloodsparks01"}}
		{if rand 0.3 {spawn "bloodsparks02"}}
		{if rand 0.2 {spawn "ground_blood_big"}}
		{if rand 0.1 {spawn "ground_blood_small"}}
		{if rand 0.15 {spawn "ground_blood01"}}
		{if rand 0.1 {spawn "ground_blood02"}}
		{if rand 0.2 {spawn "ground_blood03"}}
	}
	{on contact
		{if stuff "fg"
			{spawn "#_torse02" {impulse up 1 2 dir 1 3}}
			{spawn "#_guts02a" {impulse up 2 1 dir 2 1}}
			{spawn "#_hand05" {impulse up 2 1 dir 2 1}}
			{spawn "#_head02" {impulse up 2 2 dir 3 2}}
			{if rand 0.5 
				{spawn "#_lowtor03" {impulse up 2 2 dir 3 2}}
			else rand 0.5 
				{spawn "#_halflimb02" {impulse up 2 2 dir 3 2}}
				{spawn "#_leg04" {impulse up 2 2 dir 3 2}}
			}
		}
		{if stuff "ap"
			{spawn "#_torse02" {impulse up 1 2 dir 1 3}}
			{spawn "#_guts02a" {impulse up 2 1 dir 2 1}}
			{spawn "#_hand05" {impulse up 2 1 dir 2 1}}
			{spawn "#_head02" {impulse up 2 2 dir 3 2}}
			{if rand 0.5 
				{spawn "#_lowtor03" {impulse up 2 2 dir 3 2}}
			else rand 0.5 
				{spawn "#_halflimb02" {impulse up 2 2 dir 3 2}}
				{spawn "#_leg04" {impulse up 2 2 dir 3 2}}
			}
		}
		{if stuff "apds"
			{spawn "#_torse02" {impulse up 1 2 dir 1 3}}
			{spawn "#_guts02a" {impulse up 2 1 dir 2 1}}
			{spawn "#_hand05" {impulse up 2 1 dir 2 1}}
			{spawn "#_head02" {impulse up 2 2 dir 3 2}}
			{if rand 0.5 
				{spawn "#_lowtor03" {impulse up 2 2 dir 3 2}}
			else rand 0.5 
				{spawn "#_halflimb02" {impulse up 2 2 dir 3 2}}
				{spawn "#_leg04" {impulse up 2 2 dir 3 2}}
			}
		}
		{if stuff "apcb"
			{spawn "#_torse02" {impulse up 1 2 dir 1 3}}
			{spawn "#_guts02a" {impulse up 2 1 dir 2 1}}
			{spawn "#_hand05" {impulse up 2 1 dir 2 1}}
			{spawn "#_head02" {impulse up 2 2 dir 3 2}}
			{if rand 0.5 
				{spawn "#_lowtor03" {impulse up 2 2 dir 3 2}}
			else rand 0.5 
				{spawn "#_halflimb02" {impulse up 2 2 dir 3 2}}
				{spawn "#_leg04" {impulse up 2 2 dir 3 2}}
			}
		}
		{if stuff "heat_shell"
			{spawn "#_torse02" {impulse up 1 2 dir 1 3}}
			{spawn "#_guts02a" {impulse up 2 1 dir 2 1}}
			{spawn "#_hand05" {impulse up 2 1 dir 2 1}}
			{spawn "#_head02" {impulse up 2 2 dir 3 2}}
			{if rand 0.5 
				{spawn "#_lowtor03" {impulse up 2 2 dir 3 2}}
			else rand 0.5 
				{spawn "#_halflimb02" {impulse up 2 2 dir 3 2}}
				{spawn "#_leg04" {impulse up 2 2 dir 3 2}}
			}
		}
		{if stuff "sm"
			{spawn "#_torse02" {impulse up 1 2 dir 1 3}}
			{spawn "#_guts02a" {impulse up 2 1 dir 2 1}}
			{spawn "#_hand05" {impulse up 2 1 dir 2 1}}
			{spawn "#_head02" {impulse up 2 2 dir 3 2}}
			{if rand 0.5 
				{spawn "#_lowtor03" {impulse up 2 2 dir 3 2}}
			else rand 0.5 
				{spawn "#_halflimb02" {impulse up 2 2 dir 3 2}}
				{spawn "#_leg04" {impulse up 2 2 dir 3 2}}
			}
		}
		{delay 0.01 {volumes disable bullet contact blast touch}}
		{delay 15 {volumes enable bullet contact touch}}
		{if rand 0.02 {spawn "ground_blood01"}}
		{if rand 0.02 {spawn "ground_blood02"}}
		{if rand 0.02 {spawn "ground_blood03"}}
	}
	{on ground_hit
		{if min_speed 0.1
			{if rand 0.2 {spawn "ground_blood_big"}}
			{if rand 0.3 {spawn "ground_blood_small"}}
			{if rand 0.25 {spawn "ground_blood01"}}
			{if rand 0.2 {spawn "ground_blood02"}}
			{if rand 0.15 {spawn "ground_blood03"}}
		}
	}
}
{"small part"
	{on spawn
		{delay 0.01
			{volumes disable bullet contact blast touch}	;//prevent destroying at spawn moment
		}
		{delay 2 {volumes enable bullet contact blast}}
		;{call "stop_view"}
		{delay 25 15 {hide 10}}
	}
	{on blast_hit
		{if min_energy 0.5
			{hide 1}
		else
			{impulse up 3 1 dir 2 1}
		}
	}
	{on bullet_hit
		{if stuff "bullet"
			{impulse up 2 1 dir 1 0.5}
		else stuff "shell"
			{hide 1}
		}
	}
	{on contact
		{if effector "vehicle"
			{volumes disable bullet contact blast}		;//prevent destroing at spawn moment
			{hide 1}
		}
	}
}

{"small part fx"
	{on "stop_view"
		{delay 0.5 0.3 {view stop ""}}
	}
}

{"medium part"
	{on spawn
		{delay 0.1
			{volumes disable bullet contact blast touch}	;//prevent destroing at spawn moment
		}
		{delay 1 {volumes enable bullet contact blast}}
	}
	{on blast_hit
		{if min_energy 1.0
			{hide 1}
		else
			{impulse up 1 1 dir 2 1}
		}
	}
	{on bullet_hit
		{if stuff "bullet"
			{impulse up 0.5 0.5 dir 0.5 0.5}
		else stuff "shell"
			{hide 1}
		}
	}
	{on contact
		{impulse up 0.1 0.1 dir 0.1 0.1}
	}
}

{"big part"
	{on spawn
		{delay 0.1
			{volumes disable touch}
		}
	}
	{on blast_hit
		{if min_energy 8 
			{impulse up 5 1 dir 5 1}
		  else min_energy 0.5
			{impulse up 1 0.3 dir 1 0.5}
		}
	}
	{on bullet_hit
		{if stuff "big shell"
			{impulse up 5 1 dir 5 1}
		 else stuff "shell"
			{impulse up 1 0.3 dir 1 0.5}
		 else stuff "zenite"
			{impulse up 0.2 0.1 dir 0.1 0.05}
		}
	}
}

{"big part delete"
	{on spawn
		{delay 20
			{delete}
		}
	}
}

{"wood part"
	{on spawn
		{delay 2
			{volumes enable float}
		}
	}
;//	{on ground_hit
;//		{if terrain "water"
;//			{call "kick"}
;//		else terrain "deep_water"
;//			{call "kick"}
;//		}
;//	}
;//	{on "kick"
;//		{delay 15
;//			{kill_delay "kick_process"}
;//		}
;//		{call "kick_process"}
;//	}
;//	{on "kick_process"
;//		{delay 0.3 0.1 "kick_process"
;//			{impulse up 1}
;//			{call "kick_process"}
;//		}
;//	}
}

{"lamp_kerosene"
	{on spawn
		{add_view "light_kerosene_lamp" "light" "light"}
		{if tagged "broken"
			{bone hide "light"}
		else
			{view start "light"}
		}
	}
	{on break_armor
		{if volume "body"
			{if not tagged "broken"
				{call "break"}
			}
		}
	}
	{on contact 
		{if can_crush
			{if not tagged "broken"
				{call "break"}
			}
		}
	}
	{on "break"
		{bone cut "light"}
		{spawn "lamp_kerosene_hit" "basis"}
		{tags add "broken"}
	}
}

{"fx_piece_flame"			;// fx entity that causes burn/heat damage for flamethrowers 
	{on spawn
		{volumes "body" disable contact}
		{gravity 1}
		{call "delete_time"}
		{delay 0
			;{add_view "fire_flame_thrower_fly" "fire1" "root"}
			{view start "fire1"}
		}
		{delay 0.05
			{volumes "body" enable contact}
			{call "fire_radius"}
		}
		{delay 0.1
			{add_view "fire_flame_thrower_fly4" "fire2" "root"}
			{view start "fire2"}
		}
		{delay 0.3
			{add_view "fire_flame_thrower_fly4_1" "fire3" "root"}
			{view start "fire3"}
			{view stop "fire2"}
		}
	}
	{on contact
		{volumes disable contact}
		{fire radius 1 time 2 heating 0.25 effector follow}
		{if rand 0.2
			{call_synced "spawn_fire_die"}
		}
		{call "end"}
	}
	
	{on "spawn_fire_die"
		{spawn "fire_die"}
	}
	{##on grounded on			;// entity completely stopped moving on the ground and physics is disabled
		{view stop "fire1"}
		{view stop "fire2"}
		{call "ground_end"}
	}
	{on ground_hit
		{view stop "fire1"}
		{view stop "fire2"}
		{call "ground_end"}
	}
	{on "end"
		{view stop "fire1"}
		{view stop "fire2"}
		{view stop "fire3"}
		{delay 0.01
			{delete}
		}
	}
	{on "ground_end"
		{if not under_water
			{if terrain_fx "water"
				else terrain_fx "shallow_water"
				else
				{spawn "fire_flame_thrower" dir_velocity}
				{if rand 0.3
					{call_synced "ground_end_fire"}
				}
			}
		}
		{call "end"}
	}
	{on "ground_end_fire"
		{fire radius 1.2 time 20 heating 0.25}
		{spawn "fire_flame_thrower_ground" offset 0 0 -10}
		{spawn "burned_spot01" random_orientation}
	}
	{on "delete_time"}
	{on "fire_radius"}
}

{"fx_piece_flame 30"			;// causes flamer thrower fuel to burn up after delay (disables far shooting)
	{on "delete_time" overload
		{delay 1.1
			{call "end"}
		}
	}
	{on "fire_radius" overload
		{fire radius 0.9 time 1.1 heating 0.75 follow}
	}
}

{"fx_piece_flame 40"			;// causes flamer thrower fuel to burn up after delay (disables far shooting)
	{on "delete_time" overload
		{delay 1.4
			{call "end"}
		}
	}
	{on "fire_radius" overload
		{fire radius 0.9 time 1.4 heating 0.75 follow}
	}
}

{"fx_piece_flame 60"			;// causes flamer thrower fuel to burn up after delay (disables far shooting)
	{on "delete_time" overload
		{delay 1.5
			{call "end"}
		}
	}
	{on "fire_radius" overload
		{fire radius 0.9 time 1.5 heating 0.75 follow}
	}
}

{"fx_piece_flame 80"			;// causes flamer thrower fuel to burn up after delay (disables far shooting)
	{on "delete_time" overload
		{delay 1.8
			{call "end"}
		}
	}
	{on "fire_radius" overload
		{fire radius 0.9 time 1.8 heating 0.75 follow}
	}
}

{"burn_piece"					;// spawned entity that attaches fire damage to entities it contacts (ex. 125mm_ampulomet)
	{on contact
		{volumes disable contact}
		{fire radius 1 time 20 heating 0.25 effector follow}
		{delete}
	}
	{on grounded on			;// entity completely stopped moving on the ground and physics is disabled
		{delete}
	}
	{on ground_hit
		{delete}
	}
}

{"inventory_box"			;// used by ammo boxes and crates
	{on "break"
		{explode_inventory
			{5			"ex_ap_size1"	3	}
			{30			"ex_bomb_50kg"	8	}
			{100		"ex_bomb_100kg"	11	}
			{1000		"train_die"		15	}
			{10000		"train_die"		20	}
			{100000		"train_die"		25	}
			{1000000	"train_die"		30	}
		}
	}
}

{"flag"
	{on spawn
		{call "start"}
	}
	{on "stop"
		{ani_stop "flattern"}
		{ani_play "stop"}
	}
	{on "start"
		{ani_play "flattern" loop}
	}
}

{##"flag captureable" ;// No longer used?
	{on "capture"
		{if tex_mod "1"
			{ani_play "up" resume callback}
		else
			{ani_play "down" resume callback}
		}
	}
	{on "cancel"
		{set "stop" 1}
		{ani_stop "up"}
		{ani_stop "down"}
		{set "stop" 0}
	}
	{on "enable"
		{volumes "activate" enable contact}
	}
	{on "disable"
		{volumes "activate" disable contact}
	}
	{on animation_end "down"
		{if not "stop"
			{tex_mod "1"}
			{call "capture"}
		}
	}
	{on animation_end "up"
		{if not "stop"
			{tags add "captured"}
		}
	}
}

{"map_point"
	{on "start"
		{ani_play "rotate" loop}
	}
}

{"starshell"
	{on spawn
		{add_view "starshell_light"	"light" "root"}
		{delay 0.4
			{view start "light"}
		}
		{impulse up 40 fx 10 20 fy 10 20}
		{delay 4 1
			{delete}
		}
	}
}

{"water"
	{on spawn
		{ani_play "wave" loop}
		{add_view "wash_big_flow" "wash" "FX_wash"}
		{add_view "wash_big_flow" "wash" "FX_wash1"}
		{add_view "wash_big_flow" "wash" "FX_wash2"}
		{add_view "wash_big_flow" "wash" "FX_wash3"}
		{add_view "wash_big_flow" "wash" "FX_wash4"}
		{add_view "wash_big_flow" "wash" "FX_wash5"}
		{add_view "wash_big_flow" "wash" "FX_wash6"}
		{add_view "wash_big_flow" "wash" "FX_wash7"}
		{add_view "wash_big_flow" "wash" "FX_wash8"}
		{add_view "wash_big_flow" "wash" "FX_wash9"}
		{view start "wash"}
	}
}

{"water_animation_pingpong"
	{on spawn
		{set "backward" 0}
		{call "animate"}
	}
	{on animation_end "wave"
		{call "animate"}
	}
	{on "animate"
		{if "backward"
			{ani_play "wave" -1 callback}
			{set "backward" 0}
		else
			{ani_play "wave" 1 callback}
			{set "backward" 1}
		}
	}
}

{"cord_wood"
	{inflammation_time 3}
	(define "burn_start"
		{add_view "smoke_camp_norm" "fire" "fx_light"}
		{tags add "burning"}
		{view start "fire"}
		{burn time %0}
		{fire radius 0.7 time %0 heating 0.3 follow}
		{delay %0
			{view stop "fire"}
			{tags remove "burning"}
			{tags remove "burned"}
		}
	)
	{on spawn
		{if tagged "burning"
			{add_view "smoke_camp_norm" "fire" "fx_light"}
			{view start "fire"}
		}
	}
	{on "_burn"
		{if tagged "poured"
			{tags add "burned"}
			("burn_start" args 300)
		}
	}
	{on "burn"
		{if not burned
			{call "_burn"}
		}
	}
	{on contact
		{if effector "vehicle"
			{call "break"}
		}
	}
	{on blast
		{if volume "body"
			{if min_energy 0.5
				{call "break"}
			}
		}
	}
	{on "break"
		{if tagged "burning"
			{spawn "camp_die" no_position offset 0 0 5}
		else
			{spawn "wood_hit_small" no_position}
		}
		{delete}
	}
	{on "pour_over"
		{if name "fuel"
			{tags add "poured"}
		}
	}
}

{"camp_fire"
	{on spawn
		{call "burn"}
	}
	{on "_burn" overload
		("burn_start" args 7200)
	}
}

{"camp_fire_o"
	{on "_burn" overload}
}

{"camp_fire2"
	{on contact overload}
}

{"post_way"
	{on "hide"
		{bone hide "root"}
	}
	{on "show"
		{bone show "root"}
	}
}

{"stuff"
	{on "crush_container"
		{impulse up 0.4 0.2 dir 1 0.5}
		{impulse dir 2 1 cx 0 1 cy 0 1}
	}
	{on "drop_item"			;// when item is not in hand and is dropped from inventory.
		{impulse dir 2 1 cx 0 1 cy 0 1}
		{delay 0.4
			{link_sound "gunhit" "weapon/drop/gun_drop"}
			{play_sound "gunhit"}
		}
	}
	{on blast_hit
		{if not linked
			{call "blast_physics"}
		}
	}
	{on bullet_hit
		{if not linked
			{if stuff "shell"
				{call "shell_physics"}
			else
				{call "bullet_physics"}
			}
		}
	}
	{on "bullet_physics"
		{if min_mass 25
			{impulse up 0 dir 0.1 0.1}
		else min_mass 8
			{impulse up 0.1 0.05 dir 0.3 0.1}
		else
			{impulse up 0.4 0.2 dir 0.7 0.3}
		}
	}
	{on "shell_physics"
		{if min_mass 40
			{impulse up 0.2 0.1 dir 1 0.1}
		else min_mass 20
			{impulse up 0.4 0.2 dir 5 0.5}
		else min_mass 10
			{impulse up 1.0 0.2 dir 10 0.5}
		else min_mass 2
			{impulse up 1.5 0.2 dir 15 0.5}
		else
			{impulse up 2.5 0.2 dir 20 0.5}
		}
	}
	{on "blast_physics"
		{if min_energy 5
			{call "shell_physics"}
		else min_energy 0.3
			{call "bullet_physics"}
		}
	}
}

{"stuff no_blast_physics"
	{on "blast_physics" overload}
}

{"shell_cannon"		;// empty shell ejected from cannons
	{on spawn
		{volumes "body" disable contact}
		{delay 0.1
			{volumes "body" enable contact}
		}
	}
}

{"shell_cannon_auto"		;// empty shell ejected from cannons
	{on spawn
		{volumes "body" disable contact}
		{delay 0.05
			{volumes "body" enable contact}
		}
	}
}

{"paratrooper"
	{on spawn
		{tags add "base"}
		{view hide "parachute_x"}
	}
	{on "start"
		{ani_play "flight" callback}
		{tags add "_flight"}
	}
	{on animation_end "flight"
		{ani_play "landing" callback}
		{tags remove "_flight"}
	}
	{on animation_end "landing"
		{view show "parachute_x"}
		{hide 20}
	}
}

{"paratrooper_attach"
	{on animation_end "flight"
		{with_linked_entity "attach"
			{unlink}
		}
		{delay 10
			{delete}
		}
	}
}

{"parachute_cargo_attach"
	{on "start"
		{animate_place "attach" "paratruper_flight"}
	}
	{on animation_end "landing"
		{with_linked_entity "attach"
			{unlink}
		}
	}
}

{"parachute_inventory"			;// parachute ammo and weapon crates
	{on spawn
		{tags add "paratrooper_air"}
		{tags add "base"}
		{view hide "parachute_x"}
		{delay 0.7
			{tags remove "base"}
		}
		{ani_play "flight" callback}
	}
	{on "start"
		{ani_play "flight" callback}
	}
	{on animation_end "flight"
		{tags add "paratrooper"}
		{ani_play "landing" callback}
		{delay 5.0
			{spawn "inventory_box_parashute" "basis"}
		}
	}
	{on animation_end "landing"
		{view show "parachute_x"}
		{spawn "inf_crate_rus"}
		    {inactive 0}
			{tags remove "hidden"}
	}
}

{"random_animation"
	{on spawn
		{call "random_animation"}
	}

	(define "random_animation"
		rand 0.1
		{ani_play "animation%0" callback}
	)
	{on "random_animation"
		{if  ("random_animation" args 0)
		else ("random_animation" args 1)
		else ("random_animation" args 2)
		else ("random_animation" args 3)
		else ("random_animation" args 4)
		else ("random_animation" args 5)
		else ("random_animation" args 6)
		else ("random_animation" args 7)
		else ("random_animation" args 8)
		else rand 0.1
			{call "delay"}
		else
			{call "random_animation"}
		}
	}

	(define "random_animation_end"
		{on animation_end "animation%0"
			{call "random_animation"}
		}
	)
	("random_animation_end" args 0)
	("random_animation_end" args 1)
	("random_animation_end" args 2)
	("random_animation_end" args 3)
	("random_animation_end" args 4)
	("random_animation_end" args 5)
	("random_animation_end" args 6)
	("random_animation_end" args 7)
	("random_animation_end" args 8)

	{on "delay"
		{call "random_animation"}
	}
}

{"random_animation with_delay"
	{on "delay" overload
		{delay 12 4
			{call "random_animation"}
		}
	}
}

{"blast_flattern"
	{on blast
		{if volume "flattern"
			{if min_energy 0.3
				{ani_play "flattern"}
			}
		}
	}
}

{"pointer_attack"
	{on spawn
		{tags add "pointer_attack"}
	    {delay 1
			{spawn "flare_marker"}
		}
	}
	{on "show"
		{delay 50
			{inactive 0}
		}
	}
}


{"pointer_defend"
	{on spawn
		{tags add "pointer_defend"}
	}
	{on "show"
		{inactive 0}
		{delay 5
			{inactive 1}
		}
	}
}

{"pointer_enemy"
	{on spawn
		{tags add "pointer_enemy"}
		{spawn "artillery_aim"}
		{delay 11 {tags remove "artillery_aim"}}
	}
}

{"pointer_artillery"
	{on spawn
		{tags add "pointer_artillery"}
	}
}

{"pointer_mortar"
	{on spawn
		{tags add "pointer_mortar"}
	}
}

{"pointer_going"
	{on spawn
		{tags add "pointer_going"}
		{spawn "flare_artillery"}
	}
	{on "show"
		{inactive 0}
		{delay 55
			{inactive 1}
		}
	}
}

{"pointer_watchout"
	{on spawn
		{tags add "pointer_watchout"}
	}
	{on "show"
		{delay 50
			{inactive 0}
		}
	}
}

{"pointer_help"
	{on spawn
		{tags add "pointer_help"}
	}
	{on "show"
		{inactive 0}
		{delay 5
			{inactive 1}
		}
	}
}

{"user_guide"
	{on spawn
		{tags add "user_guide"}
		{inactive 0}
		{delay 10
			{hide 5}
		}
	}
}

{"radio_beacon"
	{on spawn
		{add_view "stop_signal" "lamp" "fx_lamp"}
		{view start "lamp"}
	}
}

{"eureka_beacon"
	{on spawn
		{spawn "light_boat_dir" "eureka_beacon_light" x}
		{delay 150.0
			{delete}
		}
	}
}

{"sandstorm"
	{on spawn
		{add_view "desert2_fx" "lamp" "fx_lamp"}
		{view start "super"}
	}
}

{"big_flying_rocket"
	{on spawn
		{link_sound "fly" "weapon/shot/reactive/rocket"}
		{play_sound "fly" 1}
	}
}

{"welding"
	{on spawn
		{add_view "spark_electro02a" "welding" "root"}
		{view start "welding"}
	}
}

{"air_cloud"
	{on spawn
		{add_view "dustrun_snow_big" "air_cloud" "root"}
		{view start "air_cloud"}
	}
}

{"exp_det_dust"
	{on "explode"
		{add_view "ex_det" "detonation" "basis"}
		{view start "detonation"}
	}
}

{"flash_gun_big_entity"
	{on "explode"
		{add_view "flash_gun_big" "detonation" "basis"}
		{view start "detonation"}
	}
}

{"light_plafond_dim_entity"
	{on spawn
		{add_view "light_plafond_dim" "welding" "root"}
		{view start "welding"}
	}
}

{"light_plafond_dim_w_entity"
	{on spawn
		{add_view "light_plafond_dim_w" "welding" "root"}
		{view start "welding"}
	}
}

(define "shellhole_show_with_delay"
	{on spawn
		{view hide "shellhole"}
		{delay %0
			{view show "shellhole"}
		}
	}
)

{"shellhole_dead_moto"
	("shellhole_show_with_delay" args 0.1)
}
{"shellhole_dead_car"
	("shellhole_show_with_delay" args 0.2)
}
{"shellhole_dead_tank"
	("shellhole_show_with_delay" args 0.35)
}

{"foxhole_spawned"
	{on spawn
		{tags add "foxhole_spawned"}		;// mission script helper
	}
}

{"trench_engineer"
	{on spawn
		{tags add "trench_spawned"}		;// mission script helper
	}
}

{"flare"
	{on spawn
		{gravity 1.3}
		{tags add "flare"}
		{add_view "signal_rocket" "flare" "root"}
		{view start "flare"}
		{delay 45.5
			{delete}
		}
	}
}

{"flare_marker"				;// Flare Marker ammo, for special missions scripting
	{on spawn
		{tags add "flare"}
		{add_view "smoke_flare_green" "smoke" "root"}
		{view start "smoke"}
		{delay 60 2 {view stop "smoke"}}
		{delay 60 {delete}}
	}
}

{"light_mortar_barrage"				;// Flare Marker ammo, for special missions scripting
	{on spawn
	    {if not tagged "fired"
			{tags add "fired"}
			(define "rnd_art_bomb"
				{delay %delay 0.5
					{spawn "mortar_single_120_dummy" random_position 350}
				}
			)
			("rnd_art_bomb" delay(2))
			("rnd_art_bomb" delay(4))
			("rnd_art_bomb" delay(6))
			("rnd_art_bomb" delay(8))
			("rnd_art_bomb" delay(10))
			("rnd_art_bomb" delay(12))
			("rnd_art_bomb" delay(14))
			("rnd_art_bomb" delay(16))
			("rnd_art_bomb" delay(18))
			("rnd_art_bomb" delay(2))
			("rnd_art_bomb" delay(4))
			("rnd_art_bomb" delay(6))
			("rnd_art_bomb" delay(8))
			("rnd_art_bomb" delay(10))
			("rnd_art_bomb" delay(12))
			("rnd_art_bomb" delay(14))
			("rnd_art_bomb" delay(16))
			("rnd_art_bomb" delay(18))
			("rnd_art_bomb" delay(2))
			("rnd_art_bomb" delay(4))
			("rnd_art_bomb" delay(6))
			("rnd_art_bomb" delay(8))
			("rnd_art_bomb" delay(10))
			("rnd_art_bomb" delay(12))
			("rnd_art_bomb" delay(14))
			("rnd_art_bomb" delay(16))
			("rnd_art_bomb" delay(18))
			

			{hide 19}
		}
	}
}

{"light_mortar_barrageger"				;// Flare Marker ammo, for special missions scripting
	{on spawn
	    {if not tagged "fired"
			{tags add "fired"}
			(define "rnd_art_bomb"
				{delay %delay 0.5
					{spawn "mortar_single_120_dummy" random_position 350}
				}
			)
			("rnd_art_bomb" delay(2))
			("rnd_art_bomb" delay(4))
			("rnd_art_bomb" delay(6))
			("rnd_art_bomb" delay(8))
			("rnd_art_bomb" delay(10))
			("rnd_art_bomb" delay(12))
			("rnd_art_bomb" delay(14))
			("rnd_art_bomb" delay(16))
			("rnd_art_bomb" delay(18))
			("rnd_art_bomb" delay(2))
			("rnd_art_bomb" delay(4))
			("rnd_art_bomb" delay(6))
			("rnd_art_bomb" delay(8))
			("rnd_art_bomb" delay(10))
			("rnd_art_bomb" delay(12))
			("rnd_art_bomb" delay(14))
			("rnd_art_bomb" delay(16))
			("rnd_art_bomb" delay(18))
			("rnd_art_bomb" delay(2))
			("rnd_art_bomb" delay(4))
			("rnd_art_bomb" delay(6))
			("rnd_art_bomb" delay(8))
			("rnd_art_bomb" delay(10))
			("rnd_art_bomb" delay(12))
			("rnd_art_bomb" delay(14))
			("rnd_art_bomb" delay(16))
			("rnd_art_bomb" delay(18))
			

			{hide 19}
		}
	}
}

{"heavy_arty_barrage"	
    {on spawn
		{if not tagged "fired"
			{tags add "fired"}
			(define "rnd_art_bomb"
				{delay %delay 0.5
					{spawn "artillery_single_150_dummy" random_position 700}
				}
			)
			("rnd_art_bomb" delay(0.5))
			("rnd_art_bomb" delay(1))
			("rnd_art_bomb" delay(1.5))
			("rnd_art_bomb" delay(2))
			("rnd_art_bomb" delay(2.5))
			("rnd_art_bomb" delay(3))
			("rnd_art_bomb" delay(3.5))
			("rnd_art_bomb" delay(4))

			("rnd_art_bomb" delay(13.5))
			("rnd_art_bomb" delay(14))
			("rnd_art_bomb" delay(14.5))
			("rnd_art_bomb" delay(15))
			("rnd_art_bomb" delay(15.5))
			("rnd_art_bomb" delay(16))
			("rnd_art_bomb" delay(16.5))
			("rnd_art_bomb" delay(17))
			{hide 18}
		}
	}
}

{"heavy_arty_barrageger"	
    {on spawn
		{if not tagged "fired"
			{tags add "fired"}
			(define "rnd_art_bomb"
				{delay %delay 0.5
					{spawn "artillery_single_150_dummy" random_position 700}
				}
			)
			("rnd_art_bomb" delay(0.5))
			("rnd_art_bomb" delay(1))
			("rnd_art_bomb" delay(1.5))
			("rnd_art_bomb" delay(2))
			("rnd_art_bomb" delay(2.5))
			("rnd_art_bomb" delay(3))
			("rnd_art_bomb" delay(3.5))
			("rnd_art_bomb" delay(4))

			("rnd_art_bomb" delay(13.5))
			("rnd_art_bomb" delay(14))
			("rnd_art_bomb" delay(14.5))
			("rnd_art_bomb" delay(15))
			("rnd_art_bomb" delay(15.5))
			("rnd_art_bomb" delay(16))
			("rnd_art_bomb" delay(16.5))
			("rnd_art_bomb" delay(17))
			{hide 18}
		}
	}
}

{"smoke_cover_callin"
    {on spawn
		{if not tagged "fired"
			{tags add "fired"}
			(define "rnd_art_bomb"
				{delay %delay 0.5
					{spawn "mortar_single_120_dummy2" offset -250 0 1000}
				}
			)
		}
	}
}

{"smoke_cover_callinger"
    {on spawn
		{if not tagged "fired"
			{tags add "fired"}
			(define "rnd_art_bomb"
				{delay %delay 0.5
					{spawn "mortar_single_120_dummy2" offset -250 0 1000}
				}
			)
		}
	}
}

{"parachute_signal_fire"
	{on spawn
		{add_view "signal_rocket2" "signal" "fx_signal"}
		{view start "signal"}
		{ani_play "flight" 0.5}
		{delay 3
			{ani_stop "flight"}
			{delay 35
				{ani_play "flight" resume callback}
			}
		}
	}
	{on animation_end "flight"
		{delay 0
			{delete}
		}
	}
}

{"delete_after_spawn"
	{on spawn
		{delay 10
			{hide 2}
		}
	}
}

{"fire_source"
	{on spawn
		{set "burning" 1}
		{fire radius 1.5 time 99999 heating 0.5 follow}
	}
}

{"pointer"
	{on spawn
		{tags add "pointer"}
;		{add_view "mission_pointer" "mission_pointer" "pointer"}
;		{view start "mission_pointer"}
	}
	{on "show"
		{inactive 0}
		{link_sound "pointer" "world/pointer/"}
		{play_sound "pointer"}
		{delay 10
			{inactive 1}
		}
	}
}

{"pointer_green"
	{on spawn
		{tags add "pointer"}
;		{add_view "mission_pointer_g" "mission_pointer_g" "pointer"}
;		{view start "mission_pointer_g"}
	}
	{on "show"
		{inactive 0}
		{delay 10
			{inactive 1}
		}
	}
}

{"pointer_blue"
	{on spawn
		{tags add "pointer"}
;		{add_view "mission_pointer_b" "mission_pointer_b" "pointer"}
;		{view start "mission_pointer_b"}
	}
	{on "show"
		{inactive 0}
		{delay 10
			{inactive 1}
		}
	}
	
}
{"pointer_bait"				;// mission objective icon/helper
	{on spawn
		{tags add "pointer_bait"}
		{add_view "bait" "bait" "upper"}
		{view start "bait"}
	}
}
{"pointer_wood"				;// mission objective icon/helper
	{on spawn
		{tags add "pointer_wood"}
		{add_view "wood" "wood" "upper"}
		{view start "wood"}
	}
}
{"pointer_repair"				;// mission objective icon/helper
	{on spawn
		{tags add "pointer_repair"}
		{add_view "repair" "repair" "upper"}
		{view start "repair"}
	}
}
{"pointer_ammo"				;// mission objective icon/helper
	{on spawn
		{tags add "pointer_ammo"}
		{add_view "ammo" "ammo" "upper"}
		{view start "ammo"}
	}
}
{"pointer_mines"				;// mission objective icon/helper
	{on spawn
		{tags add "pointer_mines"}
		{add_view "mines" "mines" "upper"}
		{view start "mines"}
		{delay 2
		    {view stop "mines"}
		}
		{delay 3 {delete}}
	}
}
{"pointer_fuel"				;// mission objective icon/helper
	{on spawn
		{tags add "pointer_fuel"}
		{add_view "fuel" "fuel" "upper"}
		{view start "fuel"}
	}
}

{"crosshair"				;// mission objective icon/helper
	{on "mortar"
		{tags add "mortar_bombarding"}
		{spawn "mortar_barrage"}
	}
}

{"artillery_aim"			;// mission helper
	{on spawn
		{tags add "artillery_aim"}
		{delay 70
		    {tags remove "artillery_aim"}
		}
	}
}

{"fire_small_fx"
	{on spawn
		{add_view "fire_small" "fire_small" "root"}
		{add_view "sun" "sun" "root"}
		{view start "sun"}
		{view start "fire_small"}
		;{add_view "light_spot_ground" "light_spot_ground" "root"}
		;{view start "light_spot_ground"}
	}
}

;// register engine-used props

{"steel"}
{"wood"}
{"flesh"}
{"concrete"}
{"sand"}
{"ice"}

{"capacity"}
{"collectable"}
{"crater"}
{"flag_slave"}
{"nocover"}
{"no_plant"}
{"obstacle_ignore_height"}
{"self_propelled"}
{"shoulderbag"}
{"slow_on_crush"}
{"spread_items"}
{"trailer"}
{"tractor"}
{"turn_over"}

{"round_sandbag"}
{"round_sandbag2"}
{"round_sandbag2"}
{"round_sandbag3"}
{"sandbag_cannon"}
{"sandbag_cannon_concentric"}
{"sandbag_tank_3m"}
{"sandbag_tank_5m"}
{"sandbag_round"}
{"no_minimap_view"}
{"delete_after_burn"}


{"vision_lev01_air"}

{"vision_lev01_boat"}
{"vision_lev02_boat"}
{"vision_lev03_boat"}
{"vision_lev04_boat"}
{"vision_lev05_boat"}

{"vision_lev00_can"}
{"vision_lev01_can"}
{"vision_lev02_can"}
{"vision_lev03_can"}
{"vision_lev04_can"}
{"vision_lev05_can"}

{"vision_lev01"}
{"vision_lev02"}
{"vision_lev03"}
{"vision_lev04"}
{"vision_lev05"}
{"vision_lev06"}