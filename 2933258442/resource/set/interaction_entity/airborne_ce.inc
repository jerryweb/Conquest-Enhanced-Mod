{"airborne"
	{on "spawn"
		{delay 0.2
			{tags add "ignore_spawn_logic"}
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
				{tags remove "fighter_ready"}
			else tagged "bomber_ce"
				{tags add "bomber_ce_select_sorty"}
				{tags remove "bomber_ce_ready"}
			else tagged "bot_recon"
				{tags add "recon_select_sorty"}
				{tags remove "ai_recon_ready"}
			}
			
			;{call "engine_full_para_fix"}
			;{call "takeoff"}
			{delay 5
				{tags remove "fighter_select_sorty"}
				{tags remove "bomber_ce_select_sorty"}
				{tags remove "recon_select_sorty"}
			}
		}
	}

	(define "move_plane_to_start_waypoint"
		{tags remove "move_to_start_waypoint"} 
		{tags remove "player_drop_plane_moving_to_start"}
		{tags remove "move_p_drop_plane"} 
		{tags add %0}
		{set "landing" 1}
		{call "takeoff"}
	)
}

{"airborne drop_plane"
    {on "move_plane_to_initial_waypoint" 
		("move_plane_to_start_waypoint" args "ready_to_move")
	}

    {on "prep_drop_plane_to_move"
    	;{if rand 0.1
    	;	{call "prep_drop_plane_to_move_fast_drop"}
    	;else
    		{tags remove "ready_to_move"}
			{tags add "moving_to_drop_zone"}
			{tags add "on_mission"}
			{delay 5
				{tags remove "moving_to_drop_zone"}
			}
			{delay 5
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
    	;}
	}

	{on "prep_drop_plane_to_move_fast_drop"
		{tags remove "ready_to_move"}
		{tags add "moving_to_drop_zone"}
		{tags add "on_mission"}
		{delay 5
			{tags remove "moving_to_drop_zone"}
		}
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
}

{"airborne drop_plane player"
	{on spawn
		{delay 0.2
			{tags add "move_to_start_waypoint"}
			{tags add "user_plane"}	
			{tags remove "moving_to_drop_zone"}	
			{tags remove "ready_to_move"}	
			{tags remove "on_mission"}	
			{tags remove "nocrew"}
			{tags remove "out"}
			{tags remove "dropping_troopers"}	
			{able "select" 0}
			{set "landing" 1}
			{call "takeoff"}
		}			
	}

	;(define "eject_troopers" overload
	;	{delay %delay
	;		{with_linked_entity %seat
	;			{unlink}
	;			{delay 0
	;				{drop_orders}
	;			}
	;			{tags add "player_paratrooper"}				
	;		}
	;	}	
	;)

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
				{tags add "_lua_always_ignore"}
			}
		}
		
	}

	;(define "eject_troopers"
	;	{delay %delay
	;		{with_linked_entity %seat
	;			{unlink}
	;			{delay 0
	;				{drop_orders}
	;			}
	;			{tags add "paratrooper"}	
	;			{tags add "ignore_spawn_logic"}			
	;		}
	;	}	
	;)
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
	{on spawn
		{delay 0.2
			{if work "body"
				{tags add "fighter"}
				{tags add "move_to_start_waypoint"}
			}
		}
	}

	{on "move_plane_to_initial_waypoint" 
		("move_plane_to_start_waypoint" args "fighter_ready")
	}
}

{"airborne bomber_ce ai"
	{on spawn
		{delay 0.2
			{if work "body"
				{tags add "bomber_ce"}
				{tags add "move_to_start_waypoint"}
			}
		}
	}

	{on "move_plane_to_initial_waypoint" 
		("move_plane_to_start_waypoint" args "bomber_ce_ready")
	}
}

{"airborne ai_recon_plane"
	{on spawn
		{delay 0.2
			{if work "body"
				{tags add "bot_recon"}
				{tags add "move_to_start_waypoint"}
			}
		}
	}

	{on "move_plane_to_initial_waypoint" 
		("move_plane_to_start_waypoint" args "ai_recon_ready")
	}
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

{"ju-52_para_plane"
	{on spawn
		{delay 0.2
			{tags add "ger"}
		}
	}
}

{"ju-52_para_plane_player"
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