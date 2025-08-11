{"tank"
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
        {tags remove "need_to_repair"}
        {tags add "reversing_to_repair"}
        {tags add "_lua_mi"}
        {delay 40
            {call "engine_off"}
            ;{call "abandoncheck"}
            {tags add "ai_stop_reversing"}
        }
    }

    {on "reload"
       {if not user_control
           {if not tagged "player_armor"
               {tags add "tankaction"}
               {delay 45
                   {tags remove "tankaction"}
               }
           }
       }
    }

    {on break                       ;// {on break} is for when components break
        {if not tagged "exploded"
            ("deploy_smoke_screen")
            {if component "engine"
                {tags add "immobile"}
                ;{call "abandoncheck"}
                {if tagged "_ai_abandon_check_active"
                    {if tagged "disarmed_tank"
                        {delay 1
                            {call "emit_crew"}
                            {delay 5
                                {components "body" break}
                            }
                        }
                    }
                }
            else component "turret"
                {if not tagged "multi_turret"
                    {if operatable
                        {if not user_control 
                            {if not tagged "ai_emplacement_defenses"
                                {if tagged "_ai_abandon_check_active"
                                    {tags add "disarmed_tank"}
                                    {if tagged "immobile"
                                        {delay 1
                                            {call "emit_crew"}
                                            {delay 5
                                                {components "body" break}
                                            }
                                        }
                                    }
                                }
                                ;{if work "body"
                                ;    {if work "engine"
                                ;        ;{tags add "need_to_repair"}
                                ;        ;{drop_orders}
                                ;        {call "engine_off"}
                                ;        ;{call "abandoncheck"}
                                ;    }
                                ;}
                            }
                        }
                    } 
                }    
            else component "trackleft"
                {if operatable
                    {if not user_control 
                        {if not tagged "ai_emplacement_defenses"   
                            {tags add "immobile"}
                            ;{call "abandoncheck"}
                            {if tagged "_ai_abandon_check_active"
                                {if tagged "disarmed_tank"
                                    {delay 1
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
            else component "trackright"
                {if operatable
                    {if not user_control 
                        {if not tagged "ai_emplacement_defenses"   
                            {tags add "immobile"}
                            ;{call "abandoncheck"}
                            {if tagged "_ai_abandon_check_active"
                                {if tagged "disarmed_tank"
                                    {delay 1
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
            else component "gun"
                {if operatable
                    {if not user_control 
                        {if not tagged "ai_emplacement_defenses"   
                            {if tagged "_ai_abandon_check_active"
                                {tags add "disarmed_tank"}
                                {if tagged "immobile"
                                    {delay 1
                                        {call "emit_crew"}
                                        {delay 5
                                            {components "body" break}
                                        }
                                    }
                                }
                            }
                            ;{if work "body"
                            ;    {if work "engine"
                            ;        ;{tags add "need_to_repair"}
                            ;        ;{drop_orders}
                            ;        {call "engine_off"}
                            ;        ;{call "abandoncheck"}
                            ;    }
                            ;}
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
}

{"tank light" 
    {on "hull_down"
        {delay 8
            {spawn "sandbag_framed_straight" offset 110 0 0}
            {spawn "sandbag_framed_straight" offset 110 50 0}
            {spawn "sandbag_framed_straight" offset 110 -50 0}
            {delay 2
                {spawn "sandbag_heap_pile" offset 100 -100 0}   
                {delay 2
                    {spawn "sandbag_framed_straight_90" offset 0 110 0}
                    {spawn "sandbag_framed_straight_90" offset -50 110 0}
                    {spawn "sandbag_framed_straight_90" offset 50 110 0}
                    {delay 2
                        {spawn "sandbag_heap_pile" offset -100 -100 0}
                        {delay 2
                            {spawn "sandbag_framed_straight_180" offset -110 0 0}
                            {spawn "sandbag_framed_straight_180" offset -110 50 0}
                            {spawn "sandbag_framed_straight_180" offset -110 -50 0}
                            {delay 2
                                {spawn "sandbag_framed_straight_270" offset 0 -110 0}
                                {spawn "sandbag_framed_straight_270" offset -50 -110 0}
                                {spawn "sandbag_framed_straight_270" offset 50 -110 0}
                                {delay 2
                                    {spawn "sandbag_heap_pile" offset 100 100 0}
                                }
                            }                           
                        }
                    }
                }                       
            }
        }
    }
}

{"tank medium" 
    {on "hull_down" 
        {delay 8
            {spawn "sandbag_framed_straight" offset 110 25 0}
            {spawn "sandbag_framed_straight" offset 110 75 0}
            {spawn "sandbag_framed_straight" offset 110 -25 0}
            {spawn "sandbag_framed_straight" offset 110 -75 0}
            {delay 4
                {spawn "sandbag_framed_straight_90" offset -25 110 0}
                {spawn "sandbag_framed_straight_90" offset -75 110 0}
                {spawn "sandbag_framed_straight_90" offset 25 110 0}
                {spawn "sandbag_framed_straight_90" offset 75 110 0}
                {delay 4
                    {spawn "sandbag_framed_straight_180" offset -110 25 0}
                    {spawn "sandbag_framed_straight_180" offset -110 75 0}
                    {spawn "sandbag_framed_straight_180" offset -110 -25 0}
                    {spawn "sandbag_framed_straight_180" offset -110 -75 0}
                    {delay 4
                        {spawn "sandbag_framed_straight_270" offset -25 -110 0}
                        {spawn "sandbag_framed_straight_270" offset -75 -110 0}
                        {spawn "sandbag_framed_straight_270" offset 25 -110 0}
                    }
                }                   
            }
        }
    }
}

{"tank heavy" 
    ;{on spawn
    ;    {delay 0.2
    ;        {if not user_control
    ;            {if operatable
    ;                ;{call "set_ignore_spawn_logic"}
    ;                ;{call "tag_squad_need_next_order"}
    ;                {delay 60
    ;                   {if not user_control
    ;                       {if operatable
    ;                           {call "tag_squad_need_next_order"}
    ;                       }
    ;                   }
    ;                }
    ;            }
    ;        }
    ;    }
    ;}

    {on "hull_down"
        {delay 8
            {spawn "sandbag_framed_straight" offset 110 25 0}
            {spawn "sandbag_framed_straight" offset 110 75 0}
            {spawn "sandbag_framed_straight" offset 110 -25 0}
            {spawn "sandbag_framed_straight" offset 110 -75 0}
            {delay 4
                {spawn "sandbag_framed_straight_90" offset -25 110 0}
                {spawn "sandbag_framed_straight_90" offset -75 110 0}
                {spawn "sandbag_framed_straight_90" offset 25 110 0}
                {spawn "sandbag_framed_straight_90" offset 75 110 0}
                {delay 4
                    {spawn "sandbag_framed_straight_180" offset -110 25 0}
                    {spawn "sandbag_framed_straight_180" offset -110 75 0}
                    {spawn "sandbag_framed_straight_180" offset -110 -25 0}
                    {spawn "sandbag_framed_straight_180" offset -110 -75 0}
                    {delay 4
                        {spawn "sandbag_framed_straight_270" offset -25 -110 0}
                        {spawn "sandbag_framed_straight_270" offset -75 -110 0}
                        {spawn "sandbag_framed_straight_270" offset 25 -110 0}
                    }
                }                   
            }
        }
    }
}

{"halftrack"
    {on "hull_down"
        {delay 8
            {spawn "sandbag_framed_straight" offset 110 0 0}
            {spawn "sandbag_framed_straight" offset 110 50 0}
            {spawn "sandbag_framed_straight" offset 110 -50 0}
            {delay 2
                {spawn "sandbag_heap_pile" offset 100 -100 0}   
                {delay 2
                    {spawn "sandbag_framed_straight_90" offset 0 110 0}
                    {spawn "sandbag_framed_straight_90" offset -50 110 0}
                    {spawn "sandbag_framed_straight_90" offset 50 110 0}
                    {delay 2
                        {spawn "sandbag_heap_pile" offset -100 -100 0}
                        {delay 2
                            {spawn "sandbag_framed_straight_180" offset -110 0 0}
                            {spawn "sandbag_framed_straight_180" offset -110 50 0}
                            {spawn "sandbag_framed_straight_180" offset -110 -50 0}
                            {delay 2
                                {spawn "sandbag_framed_straight_270" offset 0 -110 0}
                                {spawn "sandbag_framed_straight_270" offset -50 -110 0}
                                {spawn "sandbag_framed_straight_270" offset 50 -110 0}
                                {delay 2
                                    {spawn "sandbag_heap_pile" offset 100 100 0}
                                }
                            }                           
                        }
                    }
                }                       
            }
        }
    }
}

; ===== Artillery ===== 
    {"tank artillery_minimap_medium_2" 
        {on spawn
            {delay 0.2
                {tags add "artillery"}
            }
        }
    }

    {"tank detect_artillery" 
        {on spawn
            {delay 0.2
                {tags add "artillery"}
            }
        }
    }

    {"tank artillery_minimap_medium" 
        {on spawn
            {delay 0.2
                {tags add "artillery"}
            }
        }
    }

    {"tank artillery_minimap_heavy" 
        {on spawn
            {delay 0.2
                {tags add "artillery"}
            }
        }
    }

    {"spg artillery_minimap_medium" 
        {on spawn
            {delay 0.2
                {tags add "artillery"}
            }
        }
    }

    {"spg detect_artillery" 
        {on spawn
            {delay 0.2
                {tags add "artillery"}
            }
        }
    }

    {"nebelwerfer" 
        {on spawn
            {delay 0.2
                {call "tag_rocket_artillery"}
            }
        }
    }

    {"katusha"
        {on spawn
            {delay 0.2
                {call "tag_rocket_artillery"}
            }
        }
    }
;=====================================================================
{"mine_exploder"
    {on spawn
        {delay 0.2
            {if not user_control
                {call "set_ignore_spawn_logic"}
                {tags add "_lua_mi"}
            }
        }
    }

    {on "search_for_minses"
        {if operatable
            {if not user_control
                {tags add "clearing_mines"}
                {tags remove "mine_clearer_selected"}
                {delay 60
                    {tags remove "clearing_mines"}
                }
            }
        }
    }

    {on "remove_mine_sweeper"
        {if operatable
            {if not user_control
                {tags add "mine_clear_not_needed"}
                {hide 10}
            }
        }
    }
}