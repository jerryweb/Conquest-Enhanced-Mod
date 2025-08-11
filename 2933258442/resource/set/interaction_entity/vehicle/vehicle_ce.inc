{"vehicle"   
    (define "tag_veh" 
        {delay 0.2
            {if operatable
                {tags add %0}
            
            else user_control
                {tags add %0}
            }
            {if not user_control
                (mod "mp"
                    {able "select" 1}
                )
            }   
        }
    )

    (define "tag_non_user_vehicle" 
        {delay 0.2
            {if not user_control
                {tags add %0}   
            }
        }
    )

    (define "sabotage_abandoned_veh"
        {delay %delay 0.1
            {if tagged "sabotage_possible"
                {damage_report "sabotage" "<s(10)b+c(#FF0000)>SABOTAGE"}
                {if not operatable
                    {if able "repair"
                        {if rand 0.5
                            {call_synced "explosion"}
                        else
                            {clear_inventory}   
                        }       
                    }   
                else
                    {if user_control
                        {if rand 0.5
                            {call_synced "break_all"}
                        else
                            {clear_inventory}   
                        }
                    }
                }
                {tags remove "sabotage_possible"}   
            }                       
        }
    )

    {on "smoke_for_test"
        {add_view "smoke_yellow_norm" "smoke" "root"}
        {view start "smoke"}
        {delay 10 "smoke"
            {view stop "smoke"}
        }
    }

    {on "hull_down"
        {if not tagged "deactivated"
            {start_sound "vehicle/deploy/foxhole"}
            {call "deactivate_vehicle"}
            {damage_report "hull_down_action" "<s(10)b+c(00FF00)>Building sandbags. Vehicle disabled for 100 seconds"}
            {delay 100
                {call "activate_vehicle"}
                {if not tagged "no_scavenge"
                    {call "engine_on"}
                }
            }
        }
    }

    {on "tank_cover_hull_down"
        {if not tagged "deactivated"
            {start_sound "vehicle/deploy/foxhole"}
            {call "deactivate_vehicle"}
            {delay 16
                {spawn "building_smoke" "fx_dirt01"}
                {spawn "building_smoke" "fx_dirt02"}
                {spawn "building_smoke" "fx_dirt03"}
                {spawn "building_smoke" "fx_dirt04"}
                {spawn "building_smoke" "fx_dirt05"}
                {link_sound "trench_deploy" "vehicle/deploy/trench/"}
                {play_sound "trench_deploy"}
                {if terrain_fx "ice"
                    {spawn "tank_cover_new" "basis" x constrain_after_dir  {tex_mod "win"}}  
                else terrain_fx "snow"
                    {spawn "tank_cover_new" "basis" x constrain_after_dir  {tex_mod "win"}}
                else
                    {spawn "tank_cover_new" "basis" x constrain_after_dir }
                }
            }
            {delay 20
                {call "activate_vehicle"}
            }
        }
    }

    {on "toggle_slow_move"
        {if tagged "slow_move_activated"
            {if not "toggle_delay"
                ;{view pause "test"}
                {tags add "set_remove_slow_move_tag"}
            }
        else not "toggle_delay"
            {tags add "set_slow_move"}
            {delay 5
                {if tagged "set_slow_move"
                    {damage_report "toggle_slow_move_action" "<s(10)b+c(FF0000)>Driver Not Listening! Try slow move again!"}
                    {tags remove "set_slow_move"}
                }
            }
        }

        {set "toggle_delay" 1}          ;// stops accidental double click of UI button
        {delay 1 {set "toggle_delay" 0}}      
    }

    {on "process_slow_move_tags"
        ;{view start ally neutral "test"}
        {if tagged "set_slow_move"
            {damage_report "toggle_slow_move_action" "<s(10)b+c(FFD700)>Slow move activated!"}
            {tags remove "set_slow_move"}
            {tags add "slow_move_activated"}
            {if not user_control
                {delay 30
                    {tags remove "slow_move_activated"}
                    {tags add "set_remove_slow_move_tag"}
                }
            }
        else tagged "set_remove_slow_move_tag"
            {damage_report "toggle_slow_move_action" "<s(10)b+c(FFD700)>Slow move deactivated!"}
            {tags remove "set_remove_slow_move_tag"}
            {tags remove "slow_move_activated"}
        }
    }

    {on "tag_squad_need_next_order"
        {if tagged "bot_recon"
            {delay 15
                {tags remove "cmp_mg"}
                {tags remove "ai_emplacement_defenses"}
                {tags remove "_user"}
                {tags remove "_user_ally"}
                {tags add "_lua_need_next_order"}
                {delay 10.1  
                    {tags remove "_lua_need_next_order"}
                }
            }
        else
            {if tagged "engine_turned_off"
                {if operatable
                    {call "engine_on"}
                }
            }
            {tags remove "cmp_mg"}
            {tags remove "ai_emplacement_defenses"}
            {tags remove "_user"}
            {tags remove "_user_ally"}
            {tags add "_lua_need_next_order"}
            {delay 10.1 
                {tags remove "_lua_need_next_order"}
            }
        }
    }

    {on "ignore_steal_supplies"
        {tags add "stealing_supplies"}
        {delay 60 
            {tags remove "stealing_supplies"}
        }
    }

    {on "ignore_recrew_for_x_sec"
        {tags add "ignore_recrew"}
        {tags remove "recrew_action"}
        {tags remove "recrew_action_tank_crew"}
        {tags remove "recrew_action_defender_ai"}
        {tags remove "vehicle_to_recrew_defender_ai"}
        {tags remove "vehicle_to_recrew"}
        {tags remove "vehicle_to_recrew_tank_crew"}
        {delay 120
            {tags remove "ignore_recrew"}
        }
    }

    {on "ignore_repair_75"
        {tags add "ignore_repair"}
        {tags remove "repair_target"}
        {tags remove "repair_target_tank_crew"}
        {delay 75
            {tags remove "ignore_repair"}
        }
    }

    {on "prep_veh_for_tc_recrew"
        {tags add "tc_etank_enter"}
        {delay 70
            {tags remove "tc_etank_enter"}
        }
    }

    {on "prep_veh_for_p_crew"
        {tags remove "p_cannon_enter"}
        {tags add "trooper_to_crew"}
        {delay 30
            {tags remove "trooper_to_crew"}
        }
    }
    
    {on "set_artillery_given_orders"
        {tags add "_lua_always_ignore"}
        {tags remove "arty_selected"}       
        {tags remove "rocket_arty_selected"}
        {tags remove "spg_arty_selected"}
        {tags remove "spg_rocket_arty_selected"}
        {tags remove "_lua_need_next_order"}
        {delay 15
            {tags remove "ai_arty_in_script"}
        }
    }

    {on "set_ignore_spawn_logic"
        {tags remove "in_spawn_zone_a"}
        {tags remove "in_spawn_zone_a_1_veh"}
        {tags remove "in_spawn_zone_a_2_veh"}
        {tags remove "in_spawn_zone_a_3_veh"}
        {tags remove "in_spawn_zone_a_4_veh"}
        {tags remove "in_spawn_zone_a_1_can"}
        {tags remove "in_spawn_zone_a_2_can"}
        {tags remove "in_spawn_zone_a_3_can"}
        {tags remove "in_spawn_zone_a_4_can"}

        {tags remove "in_spawn_zone_b"}
        {tags remove "in_spawn_zone_b_1_veh"}
        {tags remove "in_spawn_zone_b_2_veh"}
        {tags remove "in_spawn_zone_b_3_veh"}
        {tags remove "in_spawn_zone_b_4_veh"}
        {tags remove "in_spawn_zone_b_1_can"}
        {tags remove "in_spawn_zone_b_2_can"}
        {tags remove "in_spawn_zone_b_3_can"}
        {tags remove "in_spawn_zone_b_4_can"}

        {tags remove "moving_to_waypoint_graph"}
        {tags remove "_lua_mi"}
        {tags add "ignore_spawn_logic"}
    }

; =========== Build Sandbag Ring Functions ===========
    {on "sandbag_ring_heap_curved"
        {delay 10
            {spawn "sandbag_heap_curved" offset 75 0 -5}
            {delay 2
                {spawn "sandbag_heap_pile" offset 68 68 -5}
                {delay 2
                    {spawn "sandbag_heap_curved_90" offset 0 75 -5}
                    {delay 2
                        {spawn "sandbag_heap_pile" offset -68 68 -5}
                        {delay 2
                            {spawn "sandbag_heap_curved_180" offset -75 0 -5}
                            {delay 2
                                {spawn "sandbag_heap_curved_270" offset 0 -75 -5}
                                {delay 2
                                    {spawn "sandbag_heap_pile" offset 70 -70 -5}
                                    {call "activate_vehicle"}
                                }
                            }
                        }
                    }
                }
            }
        }
    }           
    {on "sandbag_ring_framed_curved"
        {delay 10
            {spawn "sandbag_framed_curved" offset 80 0 -5}
            {delay 2
                {spawn "sandbag_heap_pile" offset 68 68 -5}
                {delay 2
                    {spawn "sandbag_framed_curved_90" offset 0 80 -5}
                    {delay 2
                        {spawn "sandbag_heap_pile" offset -68 68 -5}
                        {delay 2
                            {spawn "sandbag_framed_curved_180" offset -80 0 -5}
                            {delay 2
                                {spawn "sandbag_framed_curved_270" offset 0 -80 -5}
                                {delay 2
                                    {spawn "sandbag_heap_pile" offset 70 -70 -5}
                                    {call "activate_vehicle"}
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    {on "sandbag_ring_framed_straight"
        {delay 10
            {spawn "sandbag_framed_straight" offset 80 25 -5}
            {spawn "sandbag_framed_straight" offset 80 -25 -5}
            {delay 2
                {spawn "sandbag_heap_pile" offset 72 72 -5}
                {delay 2
                    {spawn "sandbag_framed_straight_90" offset 25 80 -5}
                    {spawn "sandbag_framed_straight_90" offset -25 80 -5}
                    {delay 2
                        {spawn "sandbag_heap_pile" offset -72 72 -5}
                        {delay 2
                            {spawn "sandbag_framed_straight_180" offset -80 25 -5}
                            {spawn "sandbag_framed_straight_180" offset -80 -25 -5}
                            {delay 2
                                {spawn "sandbag_framed_straight_270" offset 25 -80 -5}
                                {spawn "sandbag_framed_straight_270" offset -25 -80 -5}
                                {delay 2
                                    {spawn "sandbag_heap_pile" offset 72 -72 -5}
                                    {call "activate_vehicle"}
                                }
                            }
                        }
                    }
                }       
            }
        }   
    }   
    {on "sandbag_ring_heap_straight_with_lane"
        {delay 10
            {spawn "sandbag_heap_straight" offset 80 25 -5}
            {spawn "sandbag_heap_straight" offset 80 -25 -5}
            {delay 2
                {spawn "sandbag_heap_pile" offset 72 72 -5}
                {delay 2
                    {spawn "sandbag_heap_straight_90" offset 25 80 -5}
                    {spawn "sandbag_heap_straight_90" offset -25 80 -5}
                    {delay 2
                        {spawn "sandbag_heap_pile" offset -72 72 -5}
                        {delay 2
                            {spawn "sandbag_heap_straight" offset -80 25 -5}
                            {spawn "sandbag_heap_pile" offset -90 -25 -5}
                            {spawn "sandbag_heap_pile" offset -130 -25 -5}
                            {delay 2
                                {spawn "sandbag_heap_straight_270" offset 25 -80 -5}
                                {spawn "sandbag_heap_pile" offset -30 -80 -5}
                                {spawn "sandbag_heap_pile" offset -70 -80 -5}
                                {spawn "sandbag_heap_pile" offset -110 -80 -5}
                                {delay 2
                                    {spawn "sandbag_heap_pile" offset 72 -72 -5}
                                    {call "activate_vehicle"}
                                }
                            }
                        }
                    }
                }       
            }
        }   
    }   
    {on "sandbag_ring_heap_straight_no_piles"
        {delay 8
            {spawn "sandbag_heap_straight" offset 80 25 -5}
            {spawn "sandbag_heap_straight" offset 80 -25 -5}
            {delay 2    
                {spawn "sandbag_heap_straight_90" offset 25 80 -5}
                {spawn "sandbag_heap_straight_90" offset -25 80 -5}
                {delay 2                    
                    {spawn "sandbag_heap_straight" offset -80 25 -5}
                    {delay 2
                        {spawn "sandbag_heap_straight_270" offset 25 -80 -5}
                        {spawn "sandbag_heap_straight_270" offset -25 -80 -5}
                                                    
                        {call "activate_vehicle"}
                            
                    }                   
                }                                           
            }                       
        }   
    }
    {on "sandbag_ring_heap_straight"
        {delay 8
            {spawn "sandbag_heap_straight" offset 80 25 -5}
            {spawn "sandbag_heap_straight" offset 80 -25 -5}
            {delay 2
                {spawn "sandbag_heap_pile" offset 76 76 -5}
                {delay 2
                    {spawn "sandbag_heap_straight_90" offset 25 80 -5}
                    {spawn "sandbag_heap_straight_90" offset -25 80 -5}
                    {delay 2
                        {spawn "sandbag_heap_pile" offset -76 76 -5}
                        {delay 2
                            {spawn "sandbag_heap_straight" offset -80 25 -5}
                            {delay 2
                                {spawn "sandbag_heap_pile" offset -76 -76 -5}
                                {delay 2
                                    {spawn "sandbag_heap_straight_270" offset 25 -80 -5}
                                    {spawn "sandbag_heap_straight_270" offset -25 -80 -5}
                                    {delay 2
                                        {spawn "sandbag_heap_pile" offset 76 -76 -5}
                                        {call "activate_vehicle"}
                                    }
                                }
                            }
                        }
                    }
                }       
            }
        }   
    }
    {on "sandbag_ring_heap_straight_short_no_piles"
        {delay 8
            {spawn "sandbag_structured_straight" offset 80 25 -5}
            {spawn "sandbag_structured_straight" offset 80 -25 -5}
            {delay 2    
                {spawn "sandbag_structured_straight2" offset 25 80 -5}
                {spawn "sandbag_structured_straight2" offset -25 80 -5}
                {delay 2                    
                    {spawn "sandbag_structured_straight" offset -80 25 -5}
                    {spawn "sandbag_structured_straight" offset -80 -25 -5}
                    {delay 2
                        {spawn "sandbag_structured_straight2" offset 25 -80 -5}
                        {spawn "sandbag_structured_straight2" offset -25 -80 -5}
                        {delay 2                            
                            {call "activate_vehicle"}
                        }   
                    }                   
                }                                           
            }                       
        }   
    }

    {on "sandbag_ring_heap_curved_small"
        {delay 10
            {spawn "sandbag_heap_curved" offset 40 0 -5}
            {delay 5
                {spawn "sandbag_heap_curved_90" offset 0 40 -5}
                {delay 5
                    {spawn "sandbag_heap_curved_270" offset 0 -40 -5}
                        {delay 5
                        {spawn "sandbag_heap_pile" offset -60 40 -5}
                        {delay 5
                            {spawn "sandbag_heap_pile" offset -60 -40 -5}
                            {call "activate_vehicle"}
                        }
                    }
                }
            }
        }
    }
    {on "sandbag_ring_frame_curved_small"
        {delay 10
            {spawn "sandbag_framed_curved" offset 40 0 -5}
            {delay 5
                {spawn "sandbag_framed_curved_90" offset 0 40 -5}
                {delay 5
                    {spawn "sandbag_framed_curved_270" offset 0 -40 -5}
                    {delay 5
                        {spawn "sandbag_heap_pile" offset -60 40 -5}
                        {delay 5
                            {spawn "sandbag_heap_pile" offset -60 -40 -5}
                            {call "activate_vehicle"}
                        }
                    }
                }
            }
        }
    }

; =========== Randomized Sandbag Ring Functions ===========
    {on "sandbag_initial_build_settings"
        {call "deactivate_vehicle"}
        {start_sound "vehicle/deploy/foxhole"}
        {damage_report "buld_sandbag_ring" "<s(10)b+c(00FF00)>Building sandbags. Emplacement disabled"}
    }

    {on "random_small_sandbag_ring"
        {call "sandbag_initial_build_settings"}
        {if rand 0.5
            {call "sandbag_ring_heap_curved_small"}
        else 
            {call "sandbag_ring_frame_curved_small"}
        }
    }

    {on "random_medium_sandbag_ring"
        {call "sandbag_initial_build_settings"}
        {if rand 0.33
            {call "sandbag_ring_heap_straight"}
        else rand 0.33
            {call "sandbag_ring_heap_straight_with_lane"}
        else 
            {call "sandbag_ring_heap_straight_short_no_piles"}
        }
    }

    {on "random_heavy_sandbag_ring"
        {call "sandbag_initial_build_settings"}
        {if rand 0.2
            {call "sandbag_ring_heap_curved"}
        else rand 0.2
            {call "sandbag_ring_framed_curved"}
        else rand 0.2
            {call "sandbag_ring_heap_straight"}
        else rand 0.2
            {call "sandbag_ring_framed_straight"}
        else
            {call "sandbag_ring_heap_straight_with_lane"}
        }
    } 

; =========== Tagging Functions ===========
    {on "tag_supplies"
        {if not user_control
            {tags add "supplies"}
        else user_control 
            {tags add "supplies"}
        }
    }

    ;{on "tag_aa_gun"
    ;    {delay 0.3
    ;        {if not tagged "hmg"
    ;            ("tag_veh" args "aa_flak")
    ;        }
    ;    }
    ;}

    ;{on "tag_spaa"
    ;    ("tag_veh" args "spaa")
    ;}

    ;{on "tag_heavy_aa_gun"
    ;    {tags remove "heavy_at_gun"}
    ;    ("tag_veh" args "aa_flak_heavy")
    ;}   

    ;{on "tag_mortar"
    ;    {delay 0.3
    ;        {if not tagged "hmg"
    ;            ("tag_veh" args "mortar")   
    ;        }
    ;    }
    ;}

    {on "tag_artillery"
        ("tag_veh" args "artillery")
        {delay 0.2
            {if not user_control
                {tags add "_lua_always_ignore"}
            }
        }
    }

    {on "tag_heavy_artillery"
        ("tag_veh" args "heavy_artillery")
        {delay 0.2
            {if not user_control
                {tags add "_lua_always_ignore"}
            }
        }       
    }

    {on "tag_rocket_artillery"
        ("tag_veh" args "rocket_artillery")   
        {delay 0.2
            {if not user_control
                {tags add "_lua_always_ignore"}
            }
        }
    }  
;================ Vanilla Hardcoded LOGIC ========================
    {on "leave_unit"
        {delay 1
            {if tagged "_abandoned"
                {tags remove "_user_ally"}
            }
        }
    }

    {on "activate_vehicle"
        {tags remove "ignore_repair"}
    }

    {on spawn
        {delay 0.4
            {if linked "ce_drop"
                {tags add "no_scavenge"}
            }
        }

        {delay 2
            {if not able "select"
                {tags add "not_selectable"}
            }   
        } 

        {delay 1
            {if not user_control
                {if operatable
                    {if tagged "artillery"
                        {able "select" 0}
                    else tagged "rocket_artillery"
                        {able "select" 0}
                    else tagged "heavy_artillery"
                        {able "select" 0}
                    }
                }
            }            
        }
    
        {delay 5
            {if user_control
                {tags remove "ai_air_target"}
                {tags remove "ignore_recrew"}
                {tags remove "ignore_spawn_logic"}
                {tags remove "stage2"}
                {tags remove "stage3"}
                {tags remove "stealing_supplies"}
                {tags remove "_bot"}
                {tags remove "_ai"}
                {tags remove "bot"}
                {tags remove "bot_tank"}
                {tags remove "bot_car"}
                {tags remove "bot_veh"}
                {tags remove "in_spawn_zone_b_2_veh"}
                {tags remove "in_spawn_zone_b_1_veh"}
                {tags remove "in_spawn_zone_b_3_veh"}
                {tags remove "in_spawn_zone_b_4_veh"}
                {tags remove "in_spawn_zone_a_1_veh"}
                {tags remove "in_spawn_zone_a_2_veh"}
                {tags remove "in_spawn_zone_a_3_veh"}
                {tags remove "in_spawn_zone_a_4_veh"}
                {tags remove "moving_to_waypoint_graph"}
            }
        }

        {delay 0.4
            {if user_control
                {if tagged "sabotage_possible"  
                    {tags remove "sabotage_possible"}
                }
            }
        }
    }

;================ ARTY LOGIC ========================
    {on fire "gun"
        {if not user_control
            {if tagged "_bot"
                {if tagged "artillery"
                    {tags add "artillery_in_combat"}
                    {delay 70
                        {tags remove "artillery_in_combat"}
                    }
                else tagged "heavy_artillery"
                    {tags add "artillery_in_combat"}
                    {delay 70
                        {tags remove "artillery_in_combat"}
                    }
                else tagged "rocket_artillery"  
                    {tags add "artillery_in_combat"}
                    {delay 70
                        {tags remove "artillery_in_combat"}
                    }
                }
            }
        }
    }

    {on move on
        {if tagged "artillery"
            {tags remove "_lua_need_next_order"}
        else tagged "heavy_artillery"
            {tags remove "_lua_need_next_order"}
        else tagged "rocket_artillery"  
            {tags remove "_lua_need_next_order"}
        }
    }
;================ ARTY LOGIC END ========================
    {on operatable on
        {if user_control
            {call "clear_bad_player_tags"}
        }
        {if tagged "supplies"
            {delay 1
                {if not user_control
                    {call "emit_crew"}
                    {delay 5
                        {call "_explosion"}
                    }
                }
            }
            
        else tagged "sabotage_possible"
            {if user_control
                {if rand 0.5
                    ("sabotage_abandoned_veh" delay(0.1))
                else 
                    {tags remove "sabotage_possible"}
                }
            }
        }

        {if tagged "paradropped_veh"
            {tags remove "paradropped_veh"}
            {tags remove "_lua_mi"}
            {tags remove "trooper_to_crew"}
            {if not user_control
                {tags add "paradrop_veh_need_new_squad"}
            }
        }
    }

    {on operatable off
        {delay 1
            {if tagged "_abandoned"
                {tags remove "_user_ally"}
            }
        }

        {if tagged "slow_move_activated"
            {if not user_control
                {tags add "set_remove_slow_move_tag"}
            }
        }
    }

    {on break
        {if not tagged "exploded"
            {if component "body"
                {tags remove "_user_ally"}
            }
        }
    }

;================ Vanilla Hardcoded LOGIC END ========================  
}

{"scene_variable"
    {on spawn
        {delay 0.2
            {tags add "scene_variable"}
            {crew_enable group "crew" 0}
            {crew_enable group "passenger" 0}
        }
    }
}
