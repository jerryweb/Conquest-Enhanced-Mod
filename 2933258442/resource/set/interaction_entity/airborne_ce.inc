(define "kill_plane_sounds_hard"
    {stop_sound "engine1_start"}
    {stop_sound "engine1_idle"}
    {stop_sound "engine1_full"}

    {stop_sound "engine2_start"}
    {stop_sound "engine2_idle"}
    {stop_sound "engine2_full"}

    {stop_sound "engine3_start"}
    {stop_sound "engine3_idle"}
    {stop_sound "engine3_full"}

    {stop_sound "engine_accelerate"}
    {stop_sound "engine_decelerate"}
    {stop_sound "engine_stop"}

    {stop_sound "bkg_plane"}
    {stop_sound "fall"}
    {stop_sound "bounds"}
)


{"airborne"
	{on "spawn"
		{delay 0.2
			{tags add "ignore_spawn_logic"}
		}
	}

	{on ground_hit sync overload
        {if not tagged "ce_plane_grounded"
            {tags add "ce_plane_grounded"}

            ; Kill engine sounds completely.
            ("kill_plane_sounds_hard")
			; Like... really really hard.

            ; Make sure the plane is actually "dead"
            {components destroy}
			; Especially fuck the crew.
            {kill_crew}
            {if not under_water
                {add_view "aero_die_fire" "ce_fire"  "body"}
                {add_view "aero_fire"     "ce_fire2" "body"}
                {view start "ce_fire"}
                {view start "ce_fire2"}

                {spawn "aero_die_particle"}
                {spawn "aero_die_particle"}
                {spawn "aero_die_particle"}

                {call "spawn_shellhole"}
            }
        }
        {inherited}
    }

	{on "smoke_for_test"
        {add_view "smoke_yellow_norm" "smoke" "root"}
        {view start "smoke"}
        {delay 10 "smoke"
            {view stop "smoke"}
        }
    }


	{on "engine_full_para_fix"
		{delay 2.5 "engine_full"			;// delay for accelerate sound
			{if not destroyed "engine1"
				{play_sound "engine1_full" 1}
				{play_sound "bkg_plane" 1}
				{stop_sound "engine1_idle"}
			}
			{if not destroyed "engine2"
				{play_sound "engine2_full" 1}
				{play_sound "bkg_plane" 1}
				{stop_sound "engine2_idle"}
			}
		}
	}

	{on "select_for_sorty"
		{if operatable
			{if tagged "fighter"
				{tags add "fighter_select_sorty"}
			else tagged "bomber_ce"
				{tags add "bomber_ce_select_sorty"}
			else tagged "bot_recon"
				{tags add "recon_select_sorty"}
			}

			{delay 5
				{tags remove "fighter_select_sorty"}
				{tags remove "bomber_ce_select_sorty"}
				{tags remove "recon_select_sorty"}
			}
		}
	}

	{on "select_plane_for_fly_by"
		{tags add "plane_select_fly_by"}
		{if tagged "fighter"
			{delay 40
				{tags add "plane_ready_for_sorty"}
			}
		else tagged "bomber_ce"
			{delay 50
				{tags add "plane_ready_for_sorty"}
			}
		}
		{tags remove "plane_ready"}
	}

	{on "move_plane_to_initial_waypoint" 
		{tags remove "move_to_start_waypoint"} 
		{tags remove "plane_selected_to_move_to_start"}
		{tags add "plane_ready"}
		{set "landing" 1}
		{call "takeoff_load"}
		{call "takeoff"}	
	}	

	{on "tag_squad_need_next_order"
        {tags add "_lua_need_next_order"}
        {tags remove "plane_select_fly_by"}
        {delay 10.1 
            {tags remove "_lua_need_next_order"}
        }
    }
}

{"airborne drop_plane"
    {on "set_static"							;// map/mission helper for static neutral vehicles
		{able select 0}
		{able ammo_out_indicator 0}
		{able ally_crew 0}
		{able repaired 0}
		{able talk 0}
		{able unmask 0}
		{able emit_passangers_on_enemy 0}
		{able minimap 0}
		{able neutral 1}
		{clear_inventory}
	}

    {on "prep_drop_plane_to_move"
		{delay 15
			{if rand 0.15
				{delay 18
					{call "drop_paratroopers"}
				}
			else rand 0.15
				{delay 15
					{call "drop_paratroopers"}
				}
			else rand 0.15
				{delay 5
					{call "drop_paratroopers"}
				}
			else rand 0.15
				{delay 4
					{call "drop_paratroopers"}
				}	
			else rand 0.15
				{delay 20
					{call "drop_paratroopers"}
				}
			else rand 0.15
				{delay 8
					{call "drop_paratroopers"}
				}
			else rand 0.15
				{delay 11
					{call "drop_paratroopers"}
				}	
			else 
				{delay 10
					{call "drop_paratroopers"}
				}
			}
		}
	}

	{on "prep_drop_plane_to_move_fast_drop"
		{delay 5
			{if rand 0.15
				{delay 1
					{call "drop_paratroopers"}
				}
			else rand 0.15
				{delay 2
					{call "drop_paratroopers"}
				}
			else rand 0.15
				{delay 7
					{call "drop_paratroopers"}
				}
			else rand 0.15
				{delay 4
					{call "drop_paratroopers"}
				}
			else rand 0.15
				{delay 3
					{call "drop_paratroopers"}
				}
			else rand 0.15
				{delay 9
					{call "drop_paratroopers"}
				}	
			else 
				{delay 1.5
					{call "drop_paratroopers"}
				}
			}
		}
	}

	(define "drop_veh"
		{spawn %veh offset 0 0 -75
			{tags add %tag}
			{with_linked_entity "attach"
				{volumes disable contact}			;// stops humans from "colliding" with plane when ejecting.
				{volumes enable bullet}
				{delay 3 {volumes enable contact blast}}
				{if not linked "ce_vehicle_drop"
					{tags add "paradropped_veh"}
				}	
			}
		}
	)

	(define "eject_troopers"
		{delay %delay
			{with_linked_entity %seat
				{unlink}
				{if not user_control
					{tags add "paratrooper"}	
					{tags add "ignore_spawn_logic"}	
				else 
					{tags add "player_paratrooper"}	
				}
						
			}
		}	
	)

	(define "drop_vehicle"
		{if rand 0.4	
			{delay %delay
				{if operatable
					{if tagged "rus"
						{if rand 0.25
							("drop_veh" veh("paradrop_emplacement_box") tag("rus"))
						else rand 0.25
							("drop_veh" veh("paradrop_76mm_m43") tag(""))	
						else rand 0.25
							("drop_veh" veh("paradrop_bpk") tag(""))
						else
							("drop_veh" veh("paradrop_maxim") tag(""))
						}
					else tagged "ger"
						{if rand 0.25
							("drop_veh" veh("paradrop_emplacement_box") tag("ger"))
						else rand 0.25
							("drop_veh" veh("paradrop_75mm_legebig18") tag(""))	
						else rand 0.25
							("drop_veh" veh("paradrop_75mm_lg40") tag(""))
						else
							("drop_veh" veh("paradrop_mg34_lafette") tag(""))
						}
					else tagged "usa"
						{if rand 0.33
							("drop_veh" veh("paradrop_emplacement_box") tag("usa"))
						else rand 0.33
							("drop_veh" veh("paradrop_75mm_m1a1") tag(""))	
						else
							("drop_veh" veh("paradrop_m2_50cal_tripod") tag(""))
						}
					}
				}
			}
		else user_control
			{delay %delay
				{if operatable
					{if tagged "rus"
						("drop_veh" veh("paradrop_emplacement_box") tag("rus_supply_box"))
					else tagged "ger"
						("drop_veh" veh("paradrop_emplacement_box") tag("ger_supply_box"))
					else tagged "usa"
						("drop_veh" veh("paradrop_emplacement_box") tag("usa_supply_box"))
					}
				}	
			}
		}
	)

	{on "drop_paratroopers"
		{tags add "dropping_troopers"}
		{spawn "artillery_warning_light"}	
		("drop_vehicle"   delay(4.5))
	
		("eject_troopers" delay(1) 		seat("seat1"))
		("eject_troopers" delay(1.5)  	seat("seat2"))
		("eject_troopers" delay(2)		seat("seat3"))
		("eject_troopers" delay(2.5)  	seat("seat4"))
		("eject_troopers" delay(3)		seat("seat5"))
		("eject_troopers" delay(3.5)  	seat("seat6"))
		("eject_troopers" delay(4)		seat("seat7"))
		("eject_troopers" delay(5)  	seat("seat8"))
		("eject_troopers" delay(5.5)	seat("seat9"))
		
		("eject_troopers" delay(1) 		seat("seat01"))
		("eject_troopers" delay(1.5)  	seat("seat02"))
		("eject_troopers" delay(2)		seat("seat03"))
		("eject_troopers" delay(2.5)  	seat("seat04"))
		("eject_troopers" delay(3)		seat("seat05"))
		("eject_troopers" delay(3.5)  	seat("seat06"))
		("eject_troopers" delay(4)		seat("seat07"))
		("eject_troopers" delay(5)  	seat("seat08"))
		("eject_troopers" delay(5.5)	seat("seat09"))

		("eject_troopers" delay(6)  	seat("seat10"))
		("eject_troopers" delay(6.5)	seat("seat11"))
		("eject_troopers" delay(7)  	seat("seat12"))
		("eject_troopers" delay(7.5)	seat("seat13"))
		("eject_troopers" delay(8)  	seat("seat14"))
		("eject_troopers" delay(8.5)  	seat("seat15"))
		("eject_troopers" delay(9)		seat("seat16"))
		("eject_troopers" delay(9.5)  	seat("seat17"))
		("eject_troopers" delay(10)		seat("seat18"))
		("eject_troopers" delay(10.5)  	seat("seat19"))
		("eject_troopers" delay(11)  	seat("seat20"))

		{delay 25 
			{hide 5}
		}
	}

	{on break				;// component breaks
		{if not tagged "exploded"
			{if chassis "airborne"
				{if component "body"
					{if not tagged "dropping_troopers"
						{if rand 0.5
							{call "drop_paratroopers"}
						}
					}
				}
			}
		}
	}

	{on destroy				;// component destroyed
		{if not tagged "exploded"
			{if chassis "airborne"
				{if not tagged "dropping_troopers"
					{call "drop_paratroopers"}
				}
			}
		}
	}
}

{"airborne drop_plane player"
	{on spawn
		{delay 0.2
			{tags add "move_to_start_waypoint"}
			{tags add "user_plane"}	
			;{tags remove "moving_to_drop_zone"}	
			;{tags remove "ready_to_move"}	
			{tags remove "on_mission"}	
			{tags remove "nocrew"}
			{tags remove "out"}
			{tags remove "dropping_troopers"}	
			{able "select" 0}
			{set "landing" 1}
			{call "takeoff"}
		}			
	}

	{on crew out
        {if not tagged "nocrew"
			{delay 0.01
	            {tags add "out"}
	                {if not crew_in_place "driver1" 
	                	{if not crew_in_place "seat01" 
	                        {if not crew_in_place "seat02" 
	                            {if not crew_in_place "seat03" 
	                                {if not crew_in_place "seat04" 
	                                    {if not crew_in_place "seat05" 
	                                        {if not crew_in_place "seat06" 
	                                            {if not crew_in_place "seat07" 
	                                                {if not crew_in_place "seat08" 
	                                                   {if not crew_in_place "seat09" 
	                                                    {if not crew_in_place "seat10"
	                                                        {if not crew_in_place "seat11"
	                                                            {if not crew_in_place "seat12"
	                                                                {if not crew_in_place "seat13"
	                                                                	{if operatable
	                     													{delay 0.01
															                    {damage_report "paradrop_action" "<s(10)b+c(FF0009)>GOING TO BASE"}   
															                    {tags add "nocrew"} 
															                    {delay 15
															                    	{hide 10}
															                    }
	                														}
	                													}
	                												}
	                											}
	                										}
	                									}
	                								}
	                							}
	                						}
	                					}
	                				}
	                			}
	                		}
	                	}
	                }
	            }
	        }
        }
    }
}

{"airborne drop_plane ai"
	{on spawn
		{delay 0.2
			{if work "body"
				{tags add "drop_plane"}
				{tags add "move_to_start_waypoint"}
			}
		}
	}
}

{"airborne 3_engine"
	{on "engine_count" overload
		{tags add "engine_count_3"}
	}

	{on "engine_start_sequence" overload
		{inherited}
		{if work "engine1"
			{delay 4.5 0.5
				{call_synced "engine2_start_sequence"}
			}
		else
			{call "engine2_start_sequence"}
		}
	}

	{on "engine1_stop_sequence" overload
		{inherited}
		{if not "engine_on"
			{call "engine2_stop_sequence"}
		}
	}
}

{"airborne fighter ai"	
	{on "set_static"							;// map/mission helper for static neutral vehicles
		{able select 0}
		{able ammo_out_indicator 0}
		{able ally_crew 0}
		{able repaired 0}
		{able talk 0}
		{able unmask 0}
		{able emit_passangers_on_enemy 0}
		{able minimap 0}
		{able neutral 1}
		{clear_inventory}
	}

	{on spawn
		{delay 0.2
			{if work "body"
				{tags add "fighter"}
				{tags add "move_to_start_waypoint"}
			}
		}
	}
}

{"airborne bomber_ce ai"
	{on "set_static"							;// map/mission helper for static neutral vehicles
		{able select 0}
		{able ammo_out_indicator 0}
		{able ally_crew 0}
		{able repaired 0}
		{able talk 0}
		{able unmask 0}
		{able emit_passangers_on_enemy 0}
		{able minimap 0}
		{able neutral 1}
		{clear_inventory}
	}

	{on spawn
		{delay 0.2
			{if work "body"
				{tags add "bomber_ce"}
				{tags add "move_to_start_waypoint"}
			}
		}
	}
}

{"airborne ai_recon_plane"
	{on "set_static"							;// map/mission helper for static neutral vehicles
		{able select 0}
		{able ammo_out_indicator 0}
		{able ally_crew 0}
		{able repaired 0}
		{able talk 0}
		{able unmask 0}
		{able emit_passangers_on_enemy 0}
		{able minimap 0}
		{able neutral 1}
		{clear_inventory}
	}
	
	{on spawn
		{delay 0.2
			{if work "body"
				{tags add "bot_recon"}
				{tags add "move_to_start_waypoint"}
			}
		}
	}

	;{on "move_plane_to_initial_waypoint" 
	;	("move_plane_to_start_waypoint")
	;}
}

{"player_plane"
    {on spawn
        {delay 10
            {able "select" 1}
        }
    }
}


;/*=========== Plane Specifics Begin  ===========*/

{"c-47_skytrain_dakota"
	;("bf110_sound")
	("p47_sound")
	{on spawn
		{delay 0.2
			{tags add "allies"}
		}
	}
}

{"c47_d_para_plane_ger"
	{on spawn
		{delay 0.2
			{tags add "ger"}
		}
	}
}

{"c47_d_para_plane_player_ger"
	{on spawn
		{delay 0.2
			{tags add "ger"}
		}
	}
}

{"sm79_ai"
	("bf110_sound")
}

{"c47_d_para_plane_player"
	{on spawn
		{delay 0.2
			{tags add "usa"}
		}
	}
}