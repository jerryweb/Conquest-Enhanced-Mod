{"human"
	{on spawn	
		{delay 0.5
			;{add_view	"auto_medic"				"auto_medic"				"head" not_manual not_scenario} ;// Auto Medic edited by TJDagger
			{call "tag_ai_tank_crew"}	
			{call "clear_bad_player_tags"}

			;{if user_control
			;	{if tagged "auto_medic"
			;		{view start ally neutral "auto_medic"}
			;	}
			;}
		}
	}
	{on "set_ignore_spawn_logic"
	
		{tags remove "in_spawn_zone_a_1_inf"}
		{tags remove "in_spawn_zone_a_2_inf"}
		{tags remove "in_spawn_zone_a_3_inf"}
		{tags remove "in_spawn_zone_a_4_inf"}

		{tags remove "in_spawn_zone_b_1_inf"}
		{tags remove "in_spawn_zone_b_2_inf"}
		{tags remove "in_spawn_zone_b_3_inf"}
		{tags remove "in_spawn_zone_b_4_inf"}

		{tags remove "moving_to_waypoint_graph"}
		{tags remove "_lua_mi"}
		{tags add "ignore_spawn_logic"}
	}

	{on "tag_squad_need_next_order"
		{if tagged "_lua_mi"
			{tags remove "_lua_mi"}
		}
		{delay 0.25
			{tags add "_lua_need_next_order"}
			{delay 10.1  
				{tags remove "_lua_need_next_order"}
				{tags remove "inf_need_to_attack"}
				{tags remove "paratrooper_need_orders"}
			}		
		}
	}

;============= Tagging Functions =============
	{on "clear_bad_player_tags"
		{if user_control
			{tags remove "ai_air_target"}
			{tags remove "ai_tank_crew"}
			{tags remove "ignore_recrew"}
			{tags remove "_bot"}
			{tags remove "_ai"}
			{tags remove "bot"}
		}	
	}

	{on "tag_ai_engineer"
		{tags add "ai_engineer"}
		{tags add "ignore_recrew"}
		{tags add "ignore_spawn_logic"}
		{tags add "_lua_always_ignore"}
		{tags remove "_bot"}
		{tags remove "_ai"}
		{tags remove "bot"}
	}

	{on "tag_ai_tank_crew"
		{if not user_control
			{delay 0.4
				{if linked "tank"				
					{if not linked "airborne"
						{if not linked "multi_board"
							{tags add "ai_tank_crew"}
							{tags add "ignore_spawn_logic"}
							{tags add "_lua_always_ignore"}
						}
					}	
				}
			}	
		}
	}
	
	{on "link_weapon"
		{if effector "stuff weapon"		;// see interaction_entity/stuff.inc
			{call "tag_breed"}		
		}
		{if effector "stuff grenade"		;// see interaction_entity/stuff.inc
			{call "tag_breed"}		
		}
	}

	{on "tag_breed"
		{if effector "binocular"
			{tags add "officer"}
		else effector "ai_flare_pistol"
			{if not user_control
				{tags add "ai_signaller"}
				{tags add "ignore_recrew"}
			}
		}
	}

	{on "tag_user_ally"
		{tags add "_user_ally"}
		{tags remove "_ai"}
		{tags remove "_bot"}
		{tags remove "bot"}
	}

	(define "check_if_tank_crew_idle" 
		{delay %delay
			{if tagged "ai_tank_crew"
				{if not tagged "tank_crew_idle"
					{if not dead
						{if not tagged "repairing"
							{if not tagged "action_repair_tank_crew"
								{if not linked "vehicle"
									{if not user_control
										{tags add "tank_crew_idle"}	
									}
								}
							}
						}
					}
				}
			}
		}
	)

	{on "notify_signaller_has_spawned"
		{tags add "acknowledged"}
		{delay 2
			{spawn "artillery_warning_light"}
		}
	}

	{on "select_paratroopers_to_give_orders"
		{tags remove "paratrooper_need_orders"}
		{tags add "selected_paratrooper"}
		;{tags add "_lua_mi"}
		;{delay 5.25
		;	{tags remove "_lua_mi"}
		;}
	}

	{on "order_paratrooper"
		{tags remove "p_crew"}
		{tags remove "selected_paratrooper"}
		{tags remove "paratrooper_need_orders"}
		{tags remove "_lua_mi"}
	}

	{on "send_ai_to_partol"
		{tags add "go_patrol"}
		{delay 150
			{if not dead
				{tags remove "patrolling"}
			}
		}
	}

	{on "pervitin_taken"
        {if not tagged "enhanced"
            {delay 0.1
               	{if rand 0.25
                    {damage_report "medic_action" "<s(10)b+c(FF0000)>....OOOOHHHH YEAHHH!!!"}
                else rand 0.25
                    {damage_report "medic_action" "<s(10)b+c(FF0000)>THAT'S THE STUFF!"}
                else rand 0.25
                    {damage_report "medic_action" "<s(10)b+c(FF0000)>oof...KILL THEM ALL!!!"}
                else
                    {damage_report "medic_action" "<s(10)b+c(FF0000)>Pill taken"}
                }
                {tags add "enhanced"}
                ("human_health" c(-2000))
            }
            {delay 120
                {if rand 0.5
               	 	{damage_report "medic_action" "<s(10)b+c(00FF00)>Sobered up"}
                    ("human_health" c(2000))
                    {tags remove "enhanced"}
                else rand 0.1
                	{damage_report "medic_action" "<s(10)b+c(00FF00)>Sobered up"}
                    ("human_health" c(1900))
                    {tags remove "enhanced"}
                else rand 0.1
               		{damage_report "medic_action" "<s(10)b+c(00FF00)>Sobered up"}
                    ("human_health" c(1800))
                    {tags remove "enhanced"}
                else
                	{damage_report "medic_action" "<s(10)b+c(FF0009)>OVERDOSE"}
                    ("human_health" c(2800))
                    {tags remove "enhanced"}
                }
            }
        }
    }

;============= Repair Functions =============
	{on "prep_to_repair_veh"
		{if tagged "ai_tank_crew"
			{tags remove "tank_crew_idle"}
			{tags add "action_repair_tank_crew"}
			{tags add "ignore_recrew"}
		else
			{tags add "action_repair"}
		}
	}

	{on "start_repair"
		{view start ally neutral "marker_repair"}
		{tags remove "tank_crew_idle"}
	}

	{on "stop_repair"
		{view pause "marker_repair"}
		{delay 10
			{if tagged "ai_tank_crew"
				{tags remove "tank_crew_idle"}
				{tags remove "ignore_recrew"}
			}
		}
		("check_if_tank_crew_idle" delay(5))
	}

;============= More Engineer Functions =============
	{on "prep_to_destroy_hedgehogs"
		{tags add "action_destroy_hedgehog"}
		{delay 5
			{tags remove "action_destroy_hedgehog"}
			{tags add "engineer_action"}
			{tags add "attacking_hedgehog"}
			{delay 30
				{if tagged "attacking_hedgehog"
					{drop_orders}
					{tags remove "engineer_action"}
				}
			}
		}
	}

	{on "clear_dynamite_area"
		{if tagged "attacking_hedgehog"
			{drop_orders}
			{tags remove "attacking_hedgehog"}
			{tags remove "engineer_action"}
			{tags add "run"}
			{delay 10
				{tags remove "run"}
			}
		}
	}	

;============= Auto Medic Functions =============

	;{on "stop_healing"
	;	{if tagged "ignore_auto_medic"
	;		{tags remove "ignore_auto_medic"}
	;	}
	;}
;
	;{on "medic_move_to_auto_healing_zone"									;// Auto Medic edited by ;TJDagger
	;	{tags add "move_to_auto_healing_zone"}
	;	{call "set_auto_medic"}
	;	{delay 25
	;		{tags remove "move_to_auto_healing_zone"}
	;	}
	;}
;
	;{on "set_auto_medic"
	;	{tags add "auto_medic"}
	;	{view start ally neutral "auto_medic"}
	;	{damage_report "medic_action" "<s(10)b+c(FF0000)>Going to Heal."}
	;	;{delay 40
	;		;{view pause "auto_medic"}
	;	;}
	;}
;
;
	;{on "ignore_auto_medic_60"									;// Auto Medic edited by TJDagger
	;	{tags add "ignore_auto_medic"}
	;	{if tagged "medic"
	;		{call "set_auto_medic"}
	;	}
	;	{tags remove "medic_action_revive"}
	;	{tags remove "medic_patient"}
	;	{delay 60
	;		{tags remove "ignore_auto_medic"}
	;	}
	;}
;
	;{on "auto_medic_toggle"								;// Auto Medic edited by TJDagger
	;	{if not tagged "auto_medic"
	;		{call "set_auto_medic"}
	;		{damage_report "medic_action" "<s(10)b+c(FF0000)>Auto medic is activated"}
	;	else
	;		{view pause "auto_medic"}
	;		{tags remove "auto_medic"}
	;		{damage_report "medic_action" "<s(10)b+c(000000)>Auto medic is NOT activated"}
	;	}
	;}

;============= Auto Resupply Functions =============

	{on "start_ammo_out"
		{tags add "no_ammo"}
	}

	{on "start_ammo_refill"
		{tags remove "no_ammo"}
	}

	{on "set_auto_resupply"
		{tags add "auto_resupply"}
		{view pause "marker_ammo_out"}
		{view start ally neutral "marker_ammo_refill"}
		{delay 5
			{view pause "marker_ammo_refill"}
		}
	}

	{on "ignore_auto_resupply_30"									
		{tags add "ignore_auto_resupply"}
		{tags remove "action_resupply"}
		{damage_report "resupply_action" "<s(10)b+c(FFD700)>Going to resupply"}
		{delay 30
			{tags remove "ignore_auto_resupply"}
		}
	}

	{on "auto_resupply_toggle"								
		{if not tagged "auto_resupply"
			{call "set_auto_resupply"}
			{damage_report "resupply_action" "<s(10)b+c(FFD700)>Auto resupply activated"}
		else
			{view pause "marker_ammo_refill"}
			{tags remove "auto_resupply"}
			{damage_report "resupply_action" "<s(10)b+c(000000)>Auto resupply is NOT activated"}
		}
	}

;============= Recrew Functions =============
	{on "ignore_recrew_60"
		{tags add "ignore_recrew"}
		{tags remove "recrew_action"}
		{tags remove "recrew_action_defender_ai"}
		{tags remove "recrew_action_tank_crew"}
		{tags remove "tank_crew_idle"}
		{delay 60
			{tags remove "ignore_recrew"}
			("check_if_tank_crew_idle" delay(5))
		}
	}

	{on "prep_ai_tank_crew_for_recrew"
		{tags add "ai_tc_vcrew"}
		{tags add "_lua_mi"}
		{tags remove "tank_crew_idle"}
		{tags remove "looking_for_veh"}
	}

;============= Grenade Functions =============
	{on "throw_smoke_grenade"
		{if not user_control
			{tags remove "throw_smoke"}
			{tags remove "_lua_mi"}
			{tags add "throwing_smoke_ignore"}

			{delay 45
				{tags remove "throwing_smoke_ignore"}
			}
		}
	}

	{on "add_custom_smoke_grenade"
		{if not user_control
			{tags add "give_custom_smoke_grenade"}
			{delay 240
				{if not dead
					{tags remove "ignore_give_smoke"}
				}
			}
		}
	}

;============= Vanilla and Overloaded Functions =============
	{on board in							;// boarding a vehicle
		{tags remove "tank_crew_idle"}
		{tags remove "looking_for_veh"}
		{tags remove "ignore_recrew"}
		{tags remove "ecrew"}
		{tags remove "tcrew"}
		{tags remove "p_crew"}
		{tags remove "ai_tc_vcrew"}
		{tags remove "def_tcrew"}
		{tags remove "def_ecrew"}
		{tags remove "_lua_mi"}
		{tags remove "_mi_temp4"}
		{tags remove "_mi_temp6"}
	}	

	{on board out							;// exiting a vehicle
		("check_if_tank_crew_idle" delay(7))
		;{if linked "multi_board"
		;	{if not tagged "ai_tank_crew"
		;		{if not user_control
		;			{if not dead
		;				{tags add "inf_need_to_attack"}
		;				{delay 30
		;					{tags remove "inf_need_to_attack"}
		;				}
		;			}
		;		}
		;	}
		;}		
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
			{delay 6
				{physics_work 1}
				{drop_orders}
			}
		}
	}


	{on ground_hit 
		;{tags remove "eject_null"}
		{if tagged "paratrooper"
			{if not user_control
				{if not dead
					{tags add "paratrooper_need_orders"}
					{delay 120
						{tags remove "paratrooper_need_orders"}
					}
				}
			}
			{tags remove "paratrooper"}
		}
	}

	{on "die"
		{view stop "auto_medic"}
		{if tagged "ai_signaller"
			{clear_inventory}
			{tags remove "ai_signaller"}
		}
		{tags remove "paratrooper_need_orders"}
		{tags remove "ai_engineer"}
		{tags remove "ai_tank_crew"}
		{tags remove "inf_need_to_attack"}
		{tags remove "tank_crew_idle"}
		{tags remove "ignore_recrew"}
	}
}