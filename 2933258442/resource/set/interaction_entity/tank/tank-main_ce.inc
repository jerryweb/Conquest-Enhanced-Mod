{"tank"
	{on "hull_destroyed" overload
		{if not tagged "hull_destroyed"
			{tags add "hull_destroyed"}
			{tags add "no_scavenge"}		;// tag for conquest so that vehicle cannot be repaired/recovered
			{if not tagged "_ai_defender"
				{mark_for_persistence}			;// Conquest map persistence
			}
			
			{if not tagged "body_break"
				{components "body" break}
			}
			{damage_report "body" "component/body_destroyed"}
			{able select 0}
			{able repaired 0}
			{able minimap 0}
			{delay 2
				{kick_entity_manager}
				{tags add "destroyed"}
			}
			{delay 10
				{call "hatch_fire"}
				{clear_inventory}
			}
			{delay 20 5
				{##/* if rand 0.5
					{call_synced "cookoff"}
					{view stop "smoke3"}
					{stop_sound "flame_1"}
				*/}
			}
			{delay 87
				{stop_sound "flame_1"}
			}
		}
	}

	{on "vehicle_destroyed" overload
		{if not tagged "vehicle_destroyed"
			{if not tagged "ammo_cooked2"
				{tags add "vehicle_destroyed"}
				{ani_wind "open" end}
				{ani_wind "open1" end}
				{tags add "no_scavenge"}		;// tag for conquest so that vehicle cannot be repaired/recovered
				{if not tagged "_ai_defender"
					{mark_for_persistence}			;// Conquest map persistence
				}
				{if not tagged "body_break"
					{components "body" break}
				}
				;//{damage_report "body" "component/body_destroyed"}
				{able select 0}
				{able repaired 0}
				{able minimap 0}
				{delay 2
					{kick_entity_manager}
					{tags add "destroyed"}
				}
				{if not tagged "exploded"
					;//{view pause "cooking_presmoke_1"}
					{view start "fire_vehicle_death"}
					{play_sound "flame_1" 1}
					{clear_inventory}
					{delay 500 60
						{if not tagged "exploded"
							{view pause "fire_vehicle_death"}
							{view start "smoke_vehicle_death"}
							{stop_sound "flame_1"}
							{call_synced "tags_add_ammo_cooked"}
							{call_synced "tags_add_ammo_cooked2"}
						}
					}
				}
				{delay 200 200
					{if rand 0.3
						{call_synced "rand_break_ammo"}
					}
				}
			}
		}
	}

	(define "deploy_smoke_screen"
        {if not user_control
            {if not tagged "smoke_screen_launch"
                {delay 3
                    {if operatable
                        {call "smoke_screen"}
                        {tags add "smoke_screen_launch"}
                        {delay 60
                            {tags remove "smoke_screen_launch"}
                        }
                    }   
                }    
            }
        }
    )

    {on "tag_veh_wait"
        {tags remove "veh_attacking"}
    }

    {on "tag_tank_slow"
        {tags remove "tank_slow"}
        {tags add "slow_move"}
        {tags remove "remove_slow_move"}
        {delay 60
            {tags remove "slow_move"}
            {tags add "remove_slow_move"}
        }
    }

    {on "destory_if_abandoned"
        {if not tagged "tankaction"
            {if tagged "immobile"
                {if not tagged "_abandoned"
                    {if not tagged "destroyed"
                        {if not user_control
                            {if operatable
                                {call "emit_crew"}
                                {delay 5
                                    {components "body" break}
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    {on "abandoncheck"
        {if tagged "_ai_abandon_check_active"
            {if not tagged "ai_emplacement_defenses"
                {if not tagged "player_armor" 
                    {if not user_control
                        ;/("destory_if_abandoned" args delay(240))
                        ;/("destory_if_abandoned" args delay(300))
                        ;/("destory_if_abandoned" args delay(360))
                        ;/("destory_if_abandoned" args delay(420))
                        {delay 180
                            {call "destory_if_abandoned"}
                        }
                        {delay 240
                            {call "destory_if_abandoned"}
                        }
                        {delay 360
                            {call "destory_if_abandoned"}
                        }
                        {delay 480
                            {call "destory_if_abandoned"}
                        }
                    }
                }
            } 
        }   
    }

    {on "retreat_to_repair"
        {tags remove "selected_tank_to_repair"}
        {tags add "reversing_to_repair"}
        {tags add "_lua_mi"}
        {delay 120
        	{if rand 0.3
            	("deploy_smoke_screen")
            } 
            {drop_orders}
            {tags add "ai_stop_reversing"}
            {tags remove "reversing_to_repair"}
            {delay 30
            	{tags remove "_lua_mi"}
            }            
        }
    }

    {on break                       ;// {on break} is for when components break
        {if not tagged "exploded"
            ("deploy_smoke_screen")
            {if component "engine"
                {tags add "immobile"}   
            else component "trackleft"
                {if operatable
                    {if not user_control 
                        {if not tagged "ai_emplacement_defenses"   
                            {tags add "immobile"}
                        }    
                    }
                }
            else component "trackright"
                {if operatable
                    {if not user_control 
                        {if not tagged "ai_emplacement_defenses"   
                            {tags add "immobile"}
                        }    
                    }
                }    
            }
        }
    }

    {on repair 
        {if component "engine"
            {tags remove "immobile"}
        else component "trackleft"
            {tags remove "immobile"}
        else component "trackright"
            {tags remove "immobile"}
        else component "turret"
            {if not user_control
                {if not tagged "ai_emplacement_defenses"
                    {tags remove "disarmed_tank"}
                    {tags remove "engine_turned_off"}
                    ;{call "repaired_engine_check"}
                    {call "tag_squad_need_next_order"}
                }
            }
        }
    }

	(include "tank-damage_ce.inc")	
}