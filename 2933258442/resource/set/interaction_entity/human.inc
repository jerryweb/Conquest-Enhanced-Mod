{"human"
	(include "human_idle.inc")
	{inflammation_time 1.5}
	{on spawn
		{add_view	"cigarettesmoke"		"smoke"		"head"}
		{add_view	"drops_water_small2"	"on_water"	"foot3r"}
		{add_view	"drops_water_small2"	"on_water"	"foot3l"}
		{add_view	"wash_human_small"		"swim_move"	"head"}
		{add_view	"drops_water_small"		"on_puddle"	"foot3r"}
		{add_view	"drops_water_small"		"on_puddle"	"foot3r"}
		{add_view	"drops_puddle_small"	"on_shallow_water"	"foot3r"}
		{add_view	"drops_puddle_small"	"on_shallow_water"	"foot3l"}
		{add_view	"drops_puddle_small"	"on_row"		"gun_back"}
		{add_view 	"fire_dead" 			"burn_fire" "body"}

		{add_view	"marker_healing"			"marker_healing"			"head" not_manual not_scenario}
		{add_view	"marker_repair"				"marker_repair"				"head" not_manual not_scenario}
		{add_view	"marker_ammo_out"			"marker_ammo_out"			"head" not_manual not_scenario}
		{add_view	"marker_ammo_refill"		"marker_ammo_refill"		"head" not_manual not_scenario}
		{add_view	"marker_personage"			"marker_personage"			"head" not_manual not_scenario}
		{add_view	"marker_personage_acute"	"marker_personage_acute"	"head" not_manual not_scenario}
		{add_view	"marker_veterancy"			"marker_veterancy"			"head" not_manual not_scenario}
		{add_view	"selection_linked"			"selection_linked"			"head" not_manual not_scenario}

		{link_sound "crush"				"human/crush"}
		{link_sound "stabbed"			"hit/human/melee"}
		{link_sound "swim"				"human/move/swim"}
		{link_sound "splash"			"hit/water/splash/small"}
		{link_sound "splash_big"		"hit/water/splash/medium"}
		{link_sound "splash_paddle"		"vehicle/marine/goatley_boat/paddle/"}
		{link_sound "breath"			"human/exhausted/"}
		{link_sound "throw"				"human/anims/throw/"}
		{link_sound "burn"				"fire/loops/medium"}
		{link_sound "burn_scream"		"human/burn"}

		{link_sound "body_fall_heavy"	"human/body_fall/heavy"}
		{link_sound "body_fall_light"	"human/body_fall/light"}

		{link_sound "death_breathe"		"human/death_breathe/"}
		{link_sound "death_choke"		"human/death_choke/"}

		{link_sound "screw_twist"		"human/anims/repair/screw_twist/"}
		{link_sound "wrench_turn"		"human/anims/repair/wrench_turn/"}
		{link_sound "toolbox_open"		"human/anims/repair/toolbox_open/"}
		{link_sound "toolbox_close"		"human/anims/repair/toolbox_close/"}
		{link_sound "tool_equip"		"human/anims/repair/tool_equip/"}

		{link_sound "open_bolt"			"weapon/reload/open_bolt/"}
		{link_sound "close_bolt"		"weapon/reload/close_bolt/"}

		{link_sound "pick_up_small"		"human/anims/pickup/small/"}
		{link_sound "crouch"			"human/anims/crouch/"}
		{link_sound "drink_canteen"		"human/anims/drink_canteen/"}
		{link_sound "prone_to_stand"	"human/anims/prone_to_stand/"}
		{link_sound "stand_to_prone"	"human/anims/stand_to_prone/"}
		{link_sound "rest_gun"			"human/anims/rest_gun/"}
		{link_sound "stand_at_attention""human/anims/stand_at_attention/"}
		{link_sound "metal_footstep"	"human/move/normal/metal"}
		{link_sound "metal_hand"		"human/anims/metal_hand"}
		{link_sound "shovel_ground"		"human/anims/dig/shovel/ground"}
		{link_sound "shovel_snow"		"human/anims/dig/shovel/snow"}
		{link_sound "pickaxe_ground"	"human/anims/dig/pickaxe/ground"}
		{link_sound "construct_mine"	"human/anims/construct_mine"}
		{link_sound "construct_sandbag"	"human/anims/construct_sandbag"}

		{tags remove "playing_bagpipes"}

		(mod "mp" 							;// fix for conquest. Stops infantry from being of fire at spawn, if they were on fire but not dead at end of last mission.
			{if able "burning"
				{able "burning" 0}
				{able select 1}
			}
		)
		(mod not "mp"
			{if able "burning"
				{call "add_burn_fx"}
				{view start "burn_fire"}
			}
		)

		{delay 0.1
			{if linked "airborne"
				{volumes disable blast}		;// stops crew from being killed by AA blast energy
			}
		}
		{call "dead_personage"}
		{if tagged "_anim_loop" {call "check_animation"}}	;// for mission scripts
	}
	{on "dead_personage"
		{delay 0.5
			{if tagged "_bleedout_"
				{able "personage" 0}
			}
		}
	}

	(define "knock_out"
		{if not water_level -0.1
			{if not dead
				{knockdown %t %r}
			}
		}
	)

	(define "human_health"
		{health_damage_count (* 1.429 %c)
			{effects "" "hit" "damage" "die" "die"}
		}
	)

	{on contact
		{if not impregnable
			{if not volume "ram"
				{kill_flags reset}
				{volumes disable contact}
				{if effector "fx_piece_flame"
					{if not dead
						("human_health" c(15))
					}
					{delay 0.04
						{volumes enable contact}
					}
				else
					{delay 2
						{volumes enable contact}
					}
				}
				{if effector "killzone_small"
					{call "unhealable"}
				else effector "killzone"
					{call "unhealable"}
				}
				{if effector "cannon"
					; do nothing
				else effector "bicycle"
					; do nothing
				else effector "vehicle"
					{call "unhealable"}
				}
				{if effector "tank"
					{if effector_velocity 1
						{call "crush"}
						{health_damage_count 500 {effects "" "hit" "damage" "die" "die"}}
						("knock_out" t(10) r(2))	;// time unconscious. 10 ±2 seconds
					}
				else effector "marine"
					{spawn "blood_medium"}
					{health_damage_count 80 {effects "" "hit" "damage" "die" "die"}}
				else effector "cannon"
					{if effector_velocity 1
						{spawn "blood_medium"}
						{health_damage_count 5 {effects "" "hit" "damage" "die" "die"}}
					}
				else effector "bicycle"
					{if effector_velocity 1
						{spawn "blood_medium"}
						{health_damage_count 5 {effects "" "hit" "damage" "die" "die"}}
					}
				else effector "moto"
					{call "crush"}
					{if effector_velocity 30
						{health_damage_count 200 {effects "" "hit" "damage" "die" "die"}}
						("knock_out" t(10) r(2))	;// time unconscious. 10 ±2 seconds
					else effector_velocity 10
						{health_damage_count 50 {effects "" "hit" "damage" "die" "die"}}
						("knock_out" t(5) r(2))	;// time unconscious. 5 ±2 seconds
					else effector_velocity 1
						{health_damage_count 5 {effects "" "hit" "damage" "die" "die"}}
					}
				else effector "vehicle"
						{if effector_velocity 1
							{call "crush"}
							{health_damage_count 200 {effects "" "hit" "damage" "die" "die"}}
							("knock_out" t(5) r(2))	;// time unconscious. 5 ±2 seconds
						}
				else effector "knife"
					{if contact_velocity 10
						{play_sound "stabbed"}
						{health_damage_count 1000
							{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
						}
						{tags add "_stabbed"}
					}
				else effector "axe"
					{if contact_velocity 5
						("human_health" c(500))
					}
				(define "contact_part"
				else effector %e
					{if contact_velocity %v
						{if difficulty "easy"
							{if user_control
								("human_health" c(%ud))
							else
								("human_health" c(%d))
							}
						else
							("human_health" c(%d))
							%x
						}
						("human_health" c(%d))
						%x
					}
				)
				("contact_part" e("building_part")	v(3)	ud(20)	d(60)	x({knockdown 5 2})	)
				("contact_part" e("big part")		v(3)	ud(20)	d(60)	x({knockdown 5 2})	)
				("contact_part" e("medium part")	v(6)	ud(10)	d(30)	x()	)
				("contact_part" e("small part")		v(10)	ud(3)	d(20)	x()	)
				else effector "chicken"
					{health_damage_count 0
						{effects "" "hit" "hit" "hit" "hit"}
					}
				else effector "wire"
					{health_damage_count 20
						{effects "" "hit" "damage" "die" "die"}
					}
				}
			}
		}
	}

	{on bullet_hit
		{kill_flags reset}
		{signal hit 5}
		{if stuff "shell fg"
			{bullet_detonate}
			{call "process_bullet_hit"}
			{call "unhealable"}
		else stuff "rocketlauncher"
			{bullet_detonate}
			{call "process_bullet_hit"}
			{call "unhealable"}
		else stuff "rifle_grenade_at"
			{bullet_detonate}
			{call "process_bullet_hit"}
		else stuff "bullet"
			{if volume_armored
				{bullet_detonate}
				{spawn "helmet_hit_bul"}
			}
			{call "process_bullet_hit"}
			{if tagged "start_personage"
				{if rand 0.5
					{call_synced "unhealable"}
				}
			}
		else stuff "shell"
			{call "process_bullet_hit"}
			{call "unhealable"}
		else stuff "flare"
			{tags add "_flare_hit"}
			{call "_burn"}
		else
			{call "process_bullet_hit"}
		}
	}
	{on "blow_effect"
		{if not name "knife"
			{start_sound "human/blow"}
		}
	}
	{on "blow_opponent_effect"
		{if name "head"
			{spawn "blood_small" "head"}
		}
	}
	{on blow opponent sync
		{if name "knife"
			{play_sound "stabbed"}
			{health_damage_blow
				{effects "" "hit" "hit" "die_from_knife" "die_from_knife"}
			}
			{tags add "_stabbed"}
		else
			{health_damage_blow
				{effects "" "hit" "hit" "die" "die"}
			}
		}
	}

	{on "process_bullet_hit" sync
		{if hit_side front
			{kill_flags front}
		else hit_side back
			{kill_flags back}
		else
			{kill_flags front back}
		}

		{if velocity 7
			{kill_flags run}
		else velocity 0.1
			{kill_flags go}
		}
		{kill_flags piercing}
		{if	stuff "rifle"
			{kill_flags rifle}
		}
		{if	stuff "mgun"
			{kill_flags mgun}
		}
		{if	stuff "smg"
			{kill_flags smg}
		}
		{if	stuff "pistol"
			{kill_flags pistol}
		}

		{health_damage_pierce
			{effects
				"hit-scream"
				"hit-light"
				"hit-heavy"
				"die"
				"hit-explosion"
				"throw-off"
				"throw-off-and-die"
			}
			{explosive_treshold 70} ;// value = amount of damage done to human
			{table	;// table for "throw_off" impluse
			;//{ , impulse}
				{30 	1	}
				{200	2.5	}
				{500	3	}
				{5000	5	}
			}
		}
		{if not dead
			{if volume_any "head face" 								; // new condition volume_any
				{ani_play "flinch/flinch_head_01" norestart}		; // the 'norestart' flag in this case effectively removes the need to check if the animation is already running to avoid jerking
			else volume "body"
				{ani_play "flinch/flinch_chest_01" norestart}
			else volume "hand1l"
				{ani_play "flinch/flinch_chest_l_01" norestart}
			else volume "hand2l"
				{ani_play "flinch/flinch_arm_l_01" norestart}
			else volume "hand1r"
				{ani_play "flinch/flinch_chest_r_01" norestart}
			else volume "hand2r"
				{ani_play "flinch/flinch_arm_r_01" norestart}
			else volume_any "foot1l foot2l"
				{ani_play "flinch/flinch_leg_l_01" norestart}
			else volume_any "foot1r foot2r"
				{ani_play "flinch/flinch_leg_r_01" norestart}
			}
		}
	}

	{on blast_hit overload sync
		{if not dead
			{if min_energy 2
				{call "unhealable"}
			else min_energy 1.25
				(mod "mp" {call "unhealable"})
			}
			{if volume_any "head face" 								; // new condition volume_any
				{ani_play "flinch/flinch_head_01" norestart}		; // the 'norestart' flag in this case effectively removes the need to check if the animation is already running to avoid jerking
			else volume "body"
				{ani_play "flinch/flinch_chest_01" norestart}
			else volume "hand1l"
				{ani_play "flinch/flinch_chest_l_01" norestart}
			else volume "hand2l"
				{ani_play "flinch/flinch_arm_l_01" norestart}
			else volume "hand1r"
				{ani_play "flinch/flinch_chest_r_01" norestart}
			else volume "hand2r"
				{ani_play "flinch/flinch_arm_r_01" norestart}
			else volume_any "foot1l foot2l"
				{ani_play "flinch/flinch_leg_l_01" norestart}
			else volume_any "foot1r foot2r"
				{ani_play "flinch/flinch_leg_r_01" norestart}
			}
		}
		{if stuff "grenade"
			{if min_energy 0.80
				("human_health" c(85))
			}
			;{if min_energy 0.4	;// this in combo with other code causes humans to not die from grenades at 0 health
				;("knock_out" t(0.5) r(0.1))	;// time unconscious. 1 ±0.2 seconds
				;{tags add "grenade_hit"}
			;}
		}
		{if stuff "rifle"		;// Rifle grenades. Tag from weapon not ammo.
			{if min_energy 0.95
				("human_health" c(85))
			}
		}
		{if stuff "mine"
			{if min_energy 0.75
				("human_health" c(200))
			else min_energy 0.45
				("human_health" c(60))
			}
		}
		{if min_energy 2.6
			("human_health" c(350))
		else min_energy 1.9
			("human_health" c(225))
		else min_energy 1.25
			("human_health" c(85))
		}

		{kill_flags reset}
		{if hit_side front
			{kill_flags front}
		else hit_side back
			{kill_flags back}
		else
			{kill_flags front back}
		}
		{kill_flags blast}

		{health_damage_blast
			{effects
				"hit-scream"
				"hit-light"
				"hit-heavy"
				"die"
				"hit-explosion"
				"throw-off"
				"throw-off-and-die"
			}
			{table	;// table for "throw_off" impulse
			;//{blast energy, impulse}
				{0.95	0.05}
				{1.1	0.15}
				{2.0	0.5 }
				{10		2	}
				{50		3	}
			}
		}
	}

	{on "die_throw_high"
		{set "die_after_throw" 1}
		{call "personage_check"}
		{spawn "blood_small"}
		{call "die_scream"}
		{call "throw_high"}
	}

	{on "hit-scream"
		{if not "talk"
			{set "talk" 1}
			{talk "injuring"}
			{delay 10 2
				{set "talk" 0}
			}
		}
	}

	{on "hit-light"
		{if not dead
			{spawn "ce_hit_blood_small"}
		}
	}

	{on "hit-heavy"
		{spawn "ce_hit_blood_medium"}
	}

	{on "hit-explosion"
		{call "unhealable"}
		{if tagged "no_explosion"
			{call "die"}
		else
			{call "die_scream"}
			{call "explosion"}
		}
	}

	{on "throw-off"
		{set "die_after_throw" 0}
		{if not stuff "no_throw"
			{if not linked "airborne"
				{call "throw_high"}
			}
		}
	}

	{on "throw-off-and-die"
		;//{start_sound "human/talk/impulse"} ;//?
		{set "die_after_throw" 1}
		{call "die_scream"}
		{if not stuff "no_throw"
			{if not linked "airborne"
				{call "personage_check"}
				{call "throw_high"}
			}
		else
			{if stuff "shell"
				{call "unhealable"}
				{call "die"}
				{call "explosion"}
			else stuff "auto"
				{call "unhealable"}
				{call "die"}
			}
		}
	}

	{on "hit"
		{call "hit-scream"}
	}

	{on "damage"
		{call "hit"}
	}

	{on "throw_high"
		{if senseless
			{if not dead
				{call "die"} ;// kills humans when knocked out then hit with large enough blast to throw them (even if they still have health left)
			}
		else
			{if not dead
				{if linked "vehicle"
					{if "die_after_throw"
						{throw_off up 1.3 0.5 dir 5.5 2 forward 4 turn 0 360 die force}
					else
						{throw_off up 1.3 0.5 dir 5.5 2 forward 4 turn 0 360 force}
					}
					{call "stop_vehicle_ani"}
				else
					{if "die_after_throw"
						{throw_off up 3 0.8 dir 3.5 0.5 forward 0 0 die}
					else
						{if not linked "windowed"
							{throw_off up 3 0.8 dir 3.5 0.5 forward 0 0}
						}
					}
				}
			else
				{call "explosion"}
			}
		}
	}

	{on "throw_off_end"				;// from {crew_throw_off} in vehicle.inc and cannon.inc
		{if "not_knocked"
			;// do nothing
		else
			("knock_out" t(4) r(1))	;// time unconscious. 12 ±3 seconds
		}
	}

	{on "throw_off_end_die"		;// from {crew_throw_off} in vehicle.inc and cannon.inc
		;//{start_sound "human/talk/impulse"} ;//?
		{call "die"}
	}

	{on "throw_off_from_tower"
		{throw_off up 1 forward 2 die force}
		;//{start_sound "human/talk/impulse"} ;//?
	}

	{on "throw_off_from_ladder"
		{throw_off up 1 forward -2 die force}
		;//{start_sound "human/talk/impulse"} ;//?
	}

	{on "throw_off_from_ship"
		{throw_off up 3 dir 3 1 die force}
		;//{start_sound "human/talk/impulse"} ;//?
	}

	{on "throw_off_from_vehicle"
		;//{start_sound "human/talk/impulse"} ;//?
		{throw_off up 1 0.5 dir 1 turn 0 360 force die}
	}
	{on "throw_off_from_moto"
		;//{start_sound "human/talk/impulse"} ;//?
		{throw_off up 1 0.5 dir 1 turn 0 360 force die}
	}

	{on "linker_simulation"
		{if effector "airborne"
			;// do nothing
		else effector "cannon"
			;// do nothing
		else effector "paratrooper"
			{tags remove "eject"}
			{call "para_idle_animation"}
		else altitude 3
			{throw_off up 1 forward 2 die force}
		}
		{if effector "parachute_attach"
			{physics_work 0}
		}
	}

	{on "unhealable"
		{if not tagged "hero_unit"				;// exception for unit to be revive-able in missions
			{tags add "no_revive"}
			{delay 0.2							;// removes tag in case blast wave doesn't kill human
				{tags remove "no_revive"}
			}
			{if tagged "start_personage"
				{if personage
					{able "personage" 0}		;// stops human from being revive-able if in revive state
					{call "die_with_blood"}
				}
			}
		}
	}

	{on "personage_check"
		{if not tagged "hero_unit"				;// exception for unit to be revive-able in missions
			{if not user_control
				{able "personage" 0}
			else swimming
				{able "personage" 0}
			else burned
				{able "personage" 0}
			else tagged "crush"
				{able "personage" 0}
			else tagged "no_revive"
				{able "personage" 0}
				{tags remove "no_revive"}
			else 
				{if rand 0.5
					{call_synced "mp_personage_0"}
				}
			}
		}
	}

	{on "mp_personage_0"
		(mod "mp"
			{able "personage" 0}
		)
	}

	{on "floating"			;// dead and floating. Currently does not work. Revisit.
	}

	{on "die"
		{view stop "officer"}
		{view stop "documents"}
		{view stop "mines"}
		{view stop "medic"}
		{call "stop_bagpipes"}
		{call "stop_repair"}
		{call "personage_check"}
		{if linked "airborne"
			{call "delete"}
		}
		{if linked "vehicle"
			{call "stop_vehicle_ani"}
		}
		{if not dead
			{spawn "blood_small"}
			{if linked
				{if linked "shipflak"
					{call "throw_off_from_ship"}
				else linked "doublecolt"
					{call "throw_off_from_ship"}
				else linked "car"
					{if place "driver"
						{throw_off up 1 forward 1 turn -90 die force rotate_to_dir}
					else place "commander"
						{throw_off up 1 forward 1 turn +90 die force rotate_to_dir}
					else
						{call "die_with_blood"}
					}
				else linked "parachute_attach"
					{tags add "die_parachute"}

				else altitude 2
					{if boarding
						{call "throw_off_from_ladder"}
					else
						{call "throw_off_from_tower"}
					}
				else linked "cannon"
					{call "die_with_blood"}
				else linked "moto"
					{call "throw_off_from_moto"}
				else linked "vehicle"
					{call "throw_off_from_vehicle"}
				else
					{call "die_with_blood"}
				}
			else swimming
				{call "die_without_blood"}
				{call "floating"}
			else
				{call "die_with_blood"}
			}
		}
	}

	{on "die_with_blood"
		;{if not senseless
			{if not able "personage"
				{if not burned
					{call "ce_blood_splash"}
					{delay 2
						{call "ce_blood_pool_once"}		;// spawns a pool of blood that spreads
					}
				}
				{tags add "_bleedout_"}
			}
		;}
		{call "die_without_blood"}
	}

	{on "die_without_blood"
		{view pause "swim"}
		{if not "die_from_knife"
			{call "die_scream"}
		}
		{if not kill_flags blast
			{kill_flags piercing}
		}
		{call "stop_bagpipes"}
		{die}
		{delay 5
			{volumes enable contact}
		}
	}

	{on "die_scream"
		{if not "die_sound"
			{set "die_sound" 1}
			{talk "death_cry"}
			{signal mandie 5}
		}
	}

	{on "die_from_knife"
		{set "die_from_knife" 1}
		{call "die"}
	}

	{on ground_hit
		{if linked "parachute_attach"
			{tags remove "can_die"}
			{unlink}						;// kicks human out of parachute when reaching ground

		else tagged "can_die"
			{tags add "call_die"}
			{call "die"}
			{kill_delay "parachute"}
			{tags remove "can_die"}
			{tags remove "eject"}
			{call "disable_physics"}
		else
			{if min_speed 10
				{spawn "blood_medium" "basis" x}	;// Fall and hit the ground.
				{call "ce_blood_splash"}
			}
		}
		{call "ce_blood_pool_once"}
	}

	{on "disable_physics"					;// stops sliding after landing on ground. forces soldier to ground
		{delay 1.3
			{physics_work 0}
			{delay 0
				{physics_work 1}
				{throw_off up 0.5 0.2 forward 1 0.5}
			}
		}
	}

	{on "explosion"
		{if not dead
			{if not burned
				{spawn "ce_blood_blast"}
			}
		}
		{spawn "blood_medium"}
		{call "die"}
	}

	{on "crush"
		{spawn "blood_medium"}
		{play_sound "crush"}
		{call "unhealable"}
	}

	{on "delete"
		{if not dead
			{stat_notify die}
		}
		{delete}
	}

	{on "burn_volume"
		{if not impregnable
			{if volume "fire"
				{call "_burn"}
			}
		}
	}

	{on "start_burn_damage"
		{able select 0}
		{drop_orders}
		{weapon_work "hand_right" 0}
		{call "unhealable"}
		(define "burn_damage"					;// causes increasing damage to human health over time
			{delay %t "burn_damage"
				{if not dead
					{if able "burning"
						("human_health" c(%c))
						{fire radius 1 time 1 heating 0.25 follow}	;// adds heating to unit (potential to set other items on fire due to proximity)
						{if not tagged "no_revive"
							{if not tagged "hero_unit"	;// exception for unit to be revive-able in missions
								{tags add "no_revive"}
							}
						}
					else
						{kill_delay "burn_damage"}
						{tags remove "no_revive"}
					}
				else
					{if not "burn_tex"
						{set "burn_tex" 1}
						{tex_mod "burned"}
						{tags add "_burned"}
						;{tex_morph "burned" 5}
					}
				}
			}
		)
		("burn_damage" t(0.0) c(10))
		("burn_damage" t(0.3) c(10))
		("burn_damage" t(0.6) c(15))
		("burn_damage" t(0.9) c(20))
		("burn_damage" t(1.2) c(25))
		("burn_damage" t(1.5) c(30))
		("burn_damage" t(1.8) c(35))
		("burn_damage" t(2.1) c(40))
		("burn_damage" t(2.4) c(45))
		("burn_damage" t(2.7) c(50))
		("burn_damage" t(3) c(100))
		("burn_damage" t(4) c(200))
		("burn_damage" t(5) c(300))
	}

	{on "stop_burn_damage"
		{view pause "burn_fire"}		;// stops burning fx
		{kill_delay "burn_scream"}		;// stop loop call for talk
		{stop_sound "burn"}
		{able "burning" 0}			;// stops uncontrollable actions (keep in-case friendly is set on fire and is not damaged/killed)
		{delay 1.0
			{call "stop_burn"}
		}
		{if not dead
			{able select 1}
			{weapon_work "hand_right" 1}
			{tags remove "no_revive"}
		}
	}

	{on "_burn"
		{if not burned
			{able "burning" 1}			;// causes unit to act uncontrollable
			(define "try_get_off"		;// unlinks unit from vehicles
				{delay %0
					{if not tagged "can_die"
						{unlink}
					}
				}
			)

			("try_get_off" args 0.5)
			("try_get_off" args 2.0)
			("try_get_off" args 3.0)
			("try_get_off" args 4.0)
			("try_get_off" args 5.0)

			{call "add_burn_fx"}
			{delay_effect 0.5 "burn_scream"}	;// calls burn_scream event below and loops

			{if not dead
				{call_synced "start_burn_damage"}
			}

			{delay 20
				{call_synced "stop_burn_damage"}
			}
			{burn time 20}					;// Required! Without it, humans die instantly when on fire
		}
	}

	{on "add_burn_fx"
		{play_sound "burn" 1}
		{view start "burn_fire"}
	}

	{on "burn_scream"
		{if not dead
			{if not senseless
				{if not "quench"
					{if not tagged "death_cry_talk"
						{tags add "death_cry_talk"}
						{talk "death_cry"}
						{delay 4 {tags remove "death_cry_talk"}}
					}
					{delay_effect 1.25 "burn_scream"}		;// calls own event again (loops)
				else
					{call "stop_burn_damage"}
					{set "quench" 0}							;// allows unit to be able to burn again
					{able "burning" 0}							;// stops uncontrollable actions
				}
			}
		}
	}

	{on "stop_burn"
		{stop_sound "breath"}
		{if burned
			{burn stop_retry}
			{set "quench" 1}			;// stops "burn_scream" loop
			{delay 2					;// quench 0 in "burn_scream" not working. Backup code.
				{set "quench" 0}
			}
		}
	}

	{on "smoke"
		{smoke}
	}

	{on "smoking"
		{view start "smoke"}
		{delay 0.3 0.1
			{view pause "smoke"}
		}
	}

	{on "link_weapon"
		{if effector "stuff weapon"		;// see interaction_entity/stuff.inc
			{with_effector
				{call "link_human"}
			}
		}
	}

	{on "unlink_weapon"
		{if effector "stuff weapon"		;// see interaction_entity/stuff.inc
			{with_effector
				{call "unlink_human"}
			}
		}
	}

	{on fire "hand_right"
		{if effector "stuff weapon"		;// see interaction_entity/stuff.inc
			{with_effector
				{call "fire"}
			}
		}
	}

	{on "reload"
		{if effector "stuff weapon"
			{set "delete_parts" 1}				;// defined in dummy.inc hides torn magazine after delay.
			{with_effector
				{call "weapon_reload"}			;// defined in stuff.inc
			}
		}
	}

	(define "terrain_fx_human"					;// adds fx for human movement on water terrains
		{on terrain_fx %terrain enter
			{if not swimming
				{view start "on_%fx"}
			}
			{if burned
				{delay 0.5
					{call "%effect"}				;// stops human burn damage and fire fx
				}
			}
		}
		{on terrain_fx %terrain leave
			{view pause "on_%fx"}
		}
	)
	("terrain_fx_human" terrain("water")			fx(water)			effect(stop_burn))
	("terrain_fx_human" terrain("shallow_water")	fx(shallow_water)	effect(stop_burn))
	("terrain_fx_human" terrain("puddle")			fx(puddle)			effect())
	("terrain_fx_human" terrain("mud")				fx(mud)				effect())

	{on "diving"			;// transition from walking in shallow water to jumping/diving into water or deep water terrains
		{delay 0.3
			{spawn "spherewater_big"}
		}
		{call "stop_bagpipes"}
	}

	{on swim on				;// swimming movement mode
		{view pause "on_water"}
		{view start "swim"}
		{call "stop_burn"}
		{kill_delay "after_swim"}
	}

	{on swim off			;// swimming movement mode
		{delay 1.5 "after_swim"
			{view pause "swim"}
			{if water_level 0.7		;// called after human stops moving from throw-off. checks if human is underwater and cannot be accessed by medic/revived
				{if tagged "start_personage"
					{call "unhealable"}
				}
			}
		}
	}

	{on move on
		{if swimming
			{view start "swim_move"}
			{play_sound "swim" 1}
		}
	}

	{on move off
		{view pause "swim_move"}
		{call "stop_move_sounds"}
	}

	(define "play_move_sound"
		{start_sound "human/move/gear_rattle/%0/" 1}
		{if terrain_fx "road"
				{start_sound "human/move/%0/road/" 1}
		else terrain_fx "rock"
				{start_sound "human/move/%0/road/" 1}
		else terrain_fx "bridge"
				{start_sound "human/move/%0/road/" 1}
		else terrain_fx "bridge_wood"
				{start_sound "human/move/%0/wood/" 1}
		else terrain_fx "bridge_steel"
				{start_sound "human/move/%0/metal/" 1}
		else terrain_fx "country_road"
			{if rain
				{start_sound "human/move/%0/mud/" 1}
			else
				{start_sound "human/move/%0/ground/" 1}
				{view start "on_ground"}
				{delay 0.2
					{view pause "on_ground"}
				}
			}
		else terrain_fx "mud"
			{start_sound "human/move/%0/mud/" 1}
		else terrain_fx "ice"
			{start_sound "human/move/%0/ice/" 1}
		else terrain_fx "snow"
			{start_sound "human/move/%0/snow/" 1}
		else terrain_fx "sand"
			{start_sound "human/move/%0/sand/" 1}
		else terrain_fx "grass"
			{if rain
				{start_sound "human/move/%0/grass/" 1}
			else
				{start_sound "human/move/%0/grass/" 1}
				{view start "on_ground"}
				{delay 0.2
					{view pause "on_ground"}
				}
			}
		else terrain_fx "water"
			{start_sound "human/move/%0/shallow_water/" 1}
		else terrain_fx "shallow_water"
			{start_sound "human/move/%0/shallow_water/" 1}
		else terrain_fx "puddle"
			{start_sound "human/move/%0/puddle/" 1}
		else terrain_fx "ground"
			{if rain
				{start_sound "human/move/%0/mud/" 1}
			else
				{start_sound "human/move/%0/ground/" 1}
			}
		}
	)

	{on "stop_move_sounds"
		{stop_sound "swim"}
		{stop_sound "breath"}
		{stop_sound "wade"}
		{set "fast_move_mode" 0}
	}

	{on movement_mode_changed
		{call "stop_move_sounds"}
		{if name "fast"
			{if not lying
				("play_move_sound" args fast)
				{play_sound "breath" 1}
				{set "fast_move_mode" 1}
			}
		}
		{if lying									;// give human chance to put out fire if they go prone/lie and move
			{if burned
				{delay 1.75 0.5
					{call_synced "stop_burn"}				;// stops human burn damage and fire fx
				}
			}
		}
	}

	(define "play_leg_sound"
		{if velocity 16
			("play_move_sound" args fast %0)
			{play_sound "breath" 1}
		else lying
			("play_move_sound" args lying %0)
		else
			("play_move_sound" args normal %0)
		}
	)

	{on animation_event "arm_right"				;// event created by animation
		{play_sound "throw"}
	}

	{on animation_event "leg_left"				;// event created by animation
		("play_leg_sound")
		{if velocity 16
			{if not season "winter"
				{if not rain
					{if terrain_fx "country_road"
						{spawn "dustrun_foot_ground" "foot3l" x}
					else terrain_fx "ground"
						{spawn "dustrun_foot_ground" "foot3l" x}
					else terrain_fx "sand"
						{spawn "dustrun_foot_ground" "foot3l" x}
					}
				}
			}
		}
	}
	{on animation_event "leg_right"				;// event created by animation
		("play_leg_sound")
		{if velocity 16
			{if not season "winter"
				{if not rain
					{if terrain_fx "country_road"
						{spawn "dustrun_foot_ground" "foot3r" x}
					else terrain_fx "ground"
						{spawn "dustrun_foot_ground" "foot3r" x}
					else terrain_fx "sand"
						{spawn "dustrun_foot_ground" "foot3r" x}
					}
				}
			}
		}
	}
	{on animation_event "body_fall_heavy"		;// event created by animation
		{play_sound "body_fall_heavy"}
	}
	{on animation_event "body_fall_light"		;// event created by animation
		{play_sound "body_fall_light"}
	}
	{on animation_event "screw_twist"			;// event created by animation
		{play_sound "screw_twist"}
	}
	{on animation_event "wrench_turn"			;// event created by animation
		{play_sound "wrench_turn"}
	}
	{on animation_event "toolbox_open"			;// event created by animation
		{play_sound "toolbox_open"}
	}
	{on animation_event "toolbox_close"			;// event created by animation
		{play_sound "toolbox_close"}
	}
	{on animation_event "tool_equip"			;// event created by animation
		{play_sound "tool_equip"}
	}
	{on animation_event "pick_up_small"			;// event created by animation
		{play_sound "pick_up_small"}
	}
	{on animation_event "crouch"				;// event created by animation
		{play_sound "crouch"}
	}
	{on animation_event "drink_canteen"			;// event created by animation
		{play_sound "drink_canteen"}
	}
	{on animation_event "prone_to_stand"		;// event created by animation
		{play_sound "prone_to_stand"}
	}
	{on animation_event "stand_to_prone"		;// event created by animation
		{play_sound "stand_to_prone"}
	}
	{on animation_event "rest_gun"				;// event created by animation
		{play_sound "rest_gun"}
	}
	{on animation_event "stand_at_attention"	;// event created by animation
		{play_sound "stand_at_attention"}
	}
	{on animation_event "splash"				;// event created by animation
		{play_sound "splash"}
	}
	{on animation_event "row"					;// event created by animation
		{if tagged "forward"
			{play_sound "splash_paddle"}
			{view start "on_row"}
			{delay 0.5
				{view pause "on_row"}
			}
		}
	}
	{on animation_event "row_off"				;// event created by animation
		{if tagged "backward"
			{play_sound "splash_paddle"}
			{view start "on_row"}
			{delay 0.5
				{view pause "on_row"}
			}
		}
	}
	{on animation_event "swim"					;// event created by animation
		{play_sound "swim"}
	}
	{on animation_event "burn_scream"			;// event created by animation
		{play_sound "burn_scream"}
	}
	{on animation_event "metal_footstep"		;// event created by animation
		{play_sound "metal_footstep"}
	}
	{on animation_event "metal_hand"			;// event created by animation
		{play_sound "metal_hand"}
	}
	{on animation_event "shovel"				;// event created by animation
		{if terrain_fx "snow"
			{play_sound "shovel_snow"}
		else terrain_fx "sand"
			{play_sound "shovel_snow"}
		else
			{play_sound "shovel_ground"}
		}
	}
	{on animation_event "pickaxe"				;// event created by animation
		{play_sound "pickaxe_ground"}
	}
	{on animation_event "construct_mine"		;// event created by animation
		{play_sound "construct_mine"}
	}
	{on animation_event "construct_sandbag"		;// event created by animation
		{play_sound "construct_sandbag"}
	}
	{on animation_event "jump"					;// event created by animation
		{call "eject"}
	}
	{on animation_event "play_piano"			;// event created by animation
		{link_sound "play_piano"				"world/instrument/piano"}
		{play_sound "play_piano"}
	}

	{on animation_event "bagpipes_stop"			;// event created by animation
		{call "stop_bagpipes"}
	}

	{on "falldown"
		{if altitude 3
			{throw_off up 1 forward 0.01 die force}
		else altitude 1.25 					;// lower values will cause humans to fall when building trenches
			{throw_off up 1 forward 0.01 force}
		else
			{if lying
				("knock_out" t(0.1) r(0))
			}
		}
	}

	{on board in							;// boarding a vehicle
		{view pause "swim"}
		{if linked "airborne"
			{volumes disable blast}					;// stops crew from being killed by AA blast energy
		}
	}

	{on board out							;// exiting a vehicle
		{if linked "airborne"
			{delay 0.01
				;{call "eject"}
				{volumes disable contact}			;// stops humans from "colliding" with plane when ejecting.
				{volumes enable bullet}
				{delay 1 {volumes enable contact blast}}
			}
		}
		{if linked "parachute_attach"
			{call "throw_off_parachute"}
		}
		{call "stop_vehicle_ani"}
	}

	{on "throw_off_parachute"			;// used as emergency call to kick off parachute when landing in obstacle
		{set "not_knocked" 1}			;// helps stops {knock_down} call when thrown off from plane
		{delay 0
			{physics_work 1}
			{if tagged "die_parachute"
				{throw_off up 0.5 0.2 forward 1 0.5 die force}
			else
				{throw_off up 0.5 0.2 forward 1 0.5}
			}
		}
	}

	{on "eject"								;// human leaving airborne unit
		{tags add "can_die"}
		{if altitude 1
			{throw_off up 1 forward 0.01}
			{delay 0 "parachute"
				;(mod not "mp"
					{if altitude 4
						{tags add "eject"}
						{spawn "parachute_attach" "basis" x random_orientation
							{delay 0.5
								{if not tagged "_flight"
									{delete}
								}
							}
						}
						;//{spawn "paratrooper_attach" offset 205 -10 -534}
					}
				;)
			}
		else
			{call_synced "do_throw_on_ground"}
		}
	}
	{on "do_throw_off"
		{throw_off up 2 forward 0.01}
	}

	{on "do_throw_on_ground"
		{throw_on_ground}
	}

	{on "kill_neutral"}

	{on "start_healing"
		{view start ally neutral "marker_healing"}
	}

	{on "stop_healing"
		{view pause "marker_healing"}
	}

	{on "start_repair"
		{view start ally neutral "marker_repair"}
	}

	{on "stop_repair"
		{view pause "marker_repair"}
	}

	{on "start_ammo_out"
		{view start ally neutral "marker_ammo_out"}
		{tags add "ammo_out"}
	}

	{on "stop_ammo_out"
		{view pause "marker_ammo_out"}
		{tags remove "ammo_out"}
	}

	{on "start_ammo_refill"
		{view start ally neutral "marker_ammo_refill"}
		{delay 2.5
			{view pause "marker_ammo_refill"}
		}
	}

	{on "start_personage"
		{view pause "marker_repair"}
		{view pause "marker_personage_acute"}
		{view start ally neutral "marker_personage"}
		{tags add "start_personage"}
	}

	{on "stop_personage"
		{set "die_sound" 0}
		{view pause "marker_personage"}
		{view pause "marker_personage_acute"}
		{if tagged "start_personage"
			{delay 1
				{if dead
					{call "ce_blood_pool_once"}		;// spawns a pool of blood that spreads
					{tags add "_bleedout_"}
				}
			}
		}
		{tags remove "start_personage"}
	}

	{on "start_personage_acute"
		{view pause "marker_personage"}
		{view start ally neutral "marker_personage_acute"}
	}

	{on "start_veterancy"
		{view start ally neutral "marker_veterancy"}
		{delay 3.5
			{view pause "marker_veterancy"}
		}
	}

	{on "stop_veterancy"
		{view pause "marker_veterancy"}
	}

	{on "hide_veterancy"
		{view hide "marker_veterancy"}
	}

	{on "capture"
		{tags add "capturer"}
	}

	{on "officer_mark"
		{add_view	"officer" "officer" "head"}
		{view start "officer"}
	}

	{on "stop_officer_mark"
		{view pause "officer"}
	}

	{on "mines_mark"
		{add_view	"mines" "mines" "head"}
		{view start "mines"}
	}

	{on "medic_mark"
		{add_view	"medic" "medic" "head"}
		{view start "medic"}
	}

	{on "documents"
		{add_view	"documents" "documents" "head"}
		{view start "documents"}
	}

	{on "para_idle_animation"
		{if rand 0.33
			{ani_play "para_drop_idle_1" loop}
		else rand 0.5
			{ani_play "para_drop_idle_2" loop}
		else
			{ani_play "para_drop_idle_3" loop}
		}
	}

	{on "lie_wounded_animation_stop" 			;// used in mission scripts
		{ani_stop "lie_wounded"}
		{ani_stop "lie_wounded_1"}
		{ani_stop "lie_wounded_2"}
	}

	{on "knock_out_short" 						;// used in mission scripts
		("knock_out" t(5) r(1))	;// time unconscious. 5 ±1 seconds
	}

	{on "stop_vehicle_ani"
		;// parachute link
		{ani_stop "para_drop_idle_1"}
		{ani_stop "para_drop_idle_2"}
		{ani_stop "para_drop_idle_3"}

		;// goatley_boat 
		{ani_stop "goatley_crew_l_row_1"}
		{ani_stop "goatley_crew_l_row_2"}
		{ani_stop "goatley_crew_l_row_3"}
		{ani_stop "goatley_crew_l_row_4"}
		{ani_stop "goatley_crew_l_row_5"}
		{ani_stop "goatley_crew_r_row_1"}
		{ani_stop "goatley_crew_r_row_2"}
		{ani_stop "goatley_crew_r_row_3"}
		{ani_stop "goatley_crew_r_row_4"}
		{ani_stop "goatley_crew_r_row_5"}
		{ani_stop "goatley_crew_l_idle"}
		{ani_stop "goatley_crew_r_idle"}
	}

	{on "play_bagpipes"
		{kill_delay "bagpipes_end"}
		{if not tagged "playing_bagpipes"
			{tags add "playing_bagpipes"}
			{link_sound "bagpipes" "weapon/bagpipes"}
			{play_sound "bagpipes"}
		else
			{call "stop_bagpipes"}
		}
		{delay 29.0 "bagpipes_end"
			{tags remove "playing_bagpipes"}
		}
	}

	{on "stop_bagpipes"
		{if tagged "playing_bagpipes"
			{stop_sound "bagpipes"}
			{link_sound "bagpipes_drop" "weapon/bagpipes/drop"}
			{play_sound "bagpipes_drop"}
			{tags remove "playing_bagpipes"}
		}
	}

	{on "die_static"							;// map/mission helper for placing bodies
		{able select 0}
		{able ammo_out_indicator 0}
		{able ally_crew 0}
		{able talk 0}
		{able minimap 0}
		{able personage 0}
		{able neutral 1}
		{call "die_from_knife"}
	}

	{on "spawn_blood_delayed"				;// mission helper
		{call "ce_blood_splash"}
		{tags add "blood_delay_active"}
		{delay 1.0
			{tags remove "blood_delay_active"}
		}
	}

	{on "clear_inventory"
		{clear_inventory}
	}

	{on "check_animation"
		{if tagged "anim_loop_lie_wounded"
			{ani_wind "lie_wounded" end}
			{ani_play "lie_wounded" loop}
		}
		{if tagged "anim_loop_lie_wounded_1"
			{ani_wind "lie_wounded_1" end}
			{ani_play "lie_wounded_1" loop}
		}
		{if tagged "anim_loop_lie_wounded_2"
			{ani_wind "lie_wounded_2" end}
			{ani_play "lie_wounded_2" loop}
		}
		{if tagged "anim_loop_squat_gun_aside_look_around"
			{ani_wind "idle_mission\idle_passive_squat_gun_aside_look_around" end}
			{ani_play "idle_mission\idle_passive_squat_gun_aside_look_around" loop}
		}
		{if tagged "anim_loop_stand_gun_strap_simple3"
			{ani_wind "idle_mission\idle_passive_stand_gun_strap_simple3" end}
			{ani_play "idle_mission\idle_passive_stand_gun_strap_simple3" loop}
		}
		{if tagged "anim_loop_sit_crate_01"
			{ani_wind "cinematics\cin_idle_sit_crate_01" end}
			{ani_play "cinematics\cin_idle_sit_crate_01" loop}
		}
	}
}

;{change_obstacle "nothing"}  ;// command that might be useful in future. Changes to a specific obstacle defined in .mdl