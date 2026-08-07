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

            {delay 0.2
                {if tagged "rocket_artillery"
                    {tags add "short_range"}
                }
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
                        {clear_inventory}  
                        {call_synced "explosion"}                         
                    }   
                else
                    {if user_control
                        {clear_inventory}   
                        {call_synced "break_all"}  
                    }
                }
                {tags remove "sabotage_possible"}   
            }                       
        }
    )

    (define "cannon_sandbag_fast"
        ;{call "deactivate_vehicle"}
        {start_sound "vehicle/deploy/foxhole"}
        {delay 5
            {start_sound "vehicle/construction/entrench"}
            {if terrain_fx "ice"
                {spawn %0 %1 x constrain_after_dir {tex_mod "win"}}
            else terrain_fx "snow"
                {spawn %0 %1 x constrain_after_dir {tex_mod "win"}}
            else
                {spawn %0 %1 x constrain_after_dir}
            }
            ;{call "activate_vehicle"}
        }
    )

    {on "smoke_for_test"
        {add_view "smoke_yellow_norm" "smoke" "root"}
        {view start "smoke"}
        {delay 10 "smoke"
            {view stop "smoke"}
        }
    }
    
    {on "smoke_for_test_red"
        {add_view "smoke_flare_red" "smoke" "root"}
        {view start "smoke"}
        {delay 10 {view stop "smoke"}}
    }

    {on "smoke_for_test_dark_red"
        {add_view "smoke_flare_dark_red" "smoke" "root"}
        {view start "smoke"}
        {delay 10 {view stop "smoke"}}
    }

    {on "smoke_for_test_blue"
        {add_view "smoke_flare_blue" "smoke" "root"}
        {view start "smoke"}
        {delay 10 {view stop "smoke"}}
    }

    {on "smoke_for_test_light_red"
        {add_view "smoke_flare_light_red" "smoke" "root"}
        {view start "smoke"}
        {delay 10 {view stop "smoke"}}
    }

    {on "smoke_for_test_light_purple"
        {add_view "smoke_flare_light_purple" "smoke" "root"}
        {view start "smoke"}
        {delay 10 {view stop "smoke"}}
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
            {if rand 0.25
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

                    {delay 4
                        {call "activate_vehicle"}
                    }
                } 
            else rand 0.25      
                {delay 17.5
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

                    {delay 4
                        {call "activate_vehicle"}
                    }
                }
            else rand 0.25      
                {delay 18.75
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

                    {delay 4
                        {call "activate_vehicle"}
                    }
                }
            else 
                {delay 20
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

                    {delay 4
                        {call "activate_vehicle"}
                    }
                }
            }
        }
    }

    {on "tag_squad_need_next_order"
        {if tagged "engine_turned_off"
            {if operatable
                {call "engine_on"}
            }
        }
        {tags remove "cmp_mg"}
        {tags remove "ai_emplacement_defenses"}
        {tags remove "_user"}
        {tags remove "_user_ally"}
        {tags remove "attacking_flag_1"}
        {tags remove "attacking_flag_2"}
        {tags remove "attacking_flag_3"}
        {tags remove "attacking_flag_4"}
        {tags remove "attacking_flag_5"}
        {tags remove "artillery_in_combat"}
        {tags remove "artillery_selected"}
        {tags remove "artillery_ordered"}

        {if tagged "artillery"
            {tags remove "_lua_always_ignore"}
        }

        ;{call "smoke_for_test_light_purple"}

        {tags add "_lua_need_next_order"}
        {delay 10.1 
            {tags remove "_lua_need_next_order"}
        }
    }

    {on "tag_squad_in_lua_mi"
        {tags add "_lua_mi"}
        {tags add "td_attacking_targets"}
        {delay 45
            {tags remove "_lua_mi"}
            {tags remove "td_attacking_targets"}
            {if operatable
                {if not user_control
                    {call "tag_squad_need_next_order"}  
                }
            }          
        }
    }

    {on "tag_user_ally"
        {tags add "_user_ally"}
        {tags remove "_ai"}
        {tags remove "_bot"}
        {tags remove "bot"}
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
        {delay 75
            {tags remove "ignore_repair"}
        }
    }

    {on "prep_veh_for_p_crew"
        {tags remove "p_cannon_enter"}
        {tags add "trooper_to_crew"}
        {delay 30
            {tags remove "trooper_to_crew"}
        }
    }
    
    {on "select_artillery"
        {tags add "artillery_selected"}
        {tags add "artillery_ordered"}
        ;{call "smoke_for_test_blue"}
        {tags add "_lua_always_ignore"}
    }

    {on "select_spg_artillery"
        {tags add "spg_artillery_selected"}
        {tags add "spg_artillery_ordered"}
        {delay 240
            {tags remove "attacking_flag_1"}
            {tags remove "attacking_flag_2"}
            {tags remove "attacking_flag_3"}
            {tags remove "attacking_flag_4"}
            {tags remove "attacking_flag_5"}
            {tags remove "artillery_in_combat"}
            {tags remove "artillery_selected"}
            {tags remove "artillery_ordered"}
        }
        ;{call "smoke_for_test_blue"}
        ;{tags add "_lua_always_ignore"}
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

    {on "tag_td_in_combat"
        {if not user_control
            {if tagged "_bot"
                {if operatable
                    ;{call "smoke_for_test"}
                    ;{spawn "artillery_warning_light"}
                    {tags add "td_attacking_targets"}
                    {tags remove "td_in_combat"}
                    {delay 45
                        {tags remove "td_attacking_targets"}  
                    }
                }
            }
        }
    }

    {on "_explosion" overload sync
        {tags add "exploded"}
        {call "break_all"}
        {stop_sound "move"}
        {stop_sound "move_end"}
        {stop_sound "engine_full"}
        {stop_sound "engine_stop"}
        {stop_sound "exhaust"}
        {call "engine fullstop"}
        {view stop "fire1"}
        {view stop "fire2"}
        {tags add "destroyed"}
        {kick_entity_manager}
        {volumes disable blast}
        {call "explosion_sound"}
        {if not terrain_fx "bridge"
            {if not terrain_fx "bridge_wood"
                {if not under_water
                    {call "spawn_shellhole"}
                }
            }
        }

        {delay_ex 0
            {set "no_burn_volumes" 1}
            {set_skeleton "_xx" sync}
            {call "impulse"}
            {ani_play "death"}
            {call "cut_parts"}
            {if not tagged "_ai_defender"
                {mark_for_persistence}          ;// Conquest map persistence
            }
        }
        {delay 0.2
            {restore_volume_states} ; restore volume ables from .def file
        }
    }

    {on "_burn" overload
        {if not tagged "burned"
            {if not able "exploded"
                {talk "burning"}
                {damage_report "engine" "component/engine_burn"}
                {add_view "smoke_fire_engine" "burn_fire" "FXfire1"}
                {add_view "smoke_engine" "burn_fire_smoke" "FXfire1"}
                ;{add_view "smoke_black" "burn_fire" "FXfire1"}
                {view start "burn_fire"}
                {burn time 12}
                {tags add "burned"}
                {play_sound "flame" 1}
                {set "burn_fire" 1}
                {call "stat_break"}
                {tags add "no_scavenge"}        ;// tag for conquest so that vehicle cannot be repaired/recovered
                {if not tagged "_ai_defender"
                    {mark_for_persistence}          ;// Conquest map persistence
                }
                {delay 4 2
                    {unlink_trailer}
                    {call_synced "check_burn_emit"}
                }
                {delay 10 2
                    {if not tagged "engine_brake"
                        {components "engine" break}
                    }
                    {delay 5 4
                        {call_synced "hull_destroyed"}
                        {call_synced "car_destroyed"}
                        {call_synced "railway_destroyed"}
                    }
                }
                {delay 180
                    {view start "burn_fire_smoke"}
                    {delay 900
                        {view stop "burn_fire_smoke"}
                    }
                    {delay 2
                        {view stop "burn_fire"}
                    }
                    {stop_sound "flame"}
                    {set "burn_fire" 0}
                    {able "burning" 0}
                }
            }
        }
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
        {delay_ex 8 "building_sandbag_ring"
            {spawn "sandbag_heap_straight" offset 80 25 -5}
            {spawn "sandbag_heap_straight" offset 80 -25 -5}
            {delay_ex 2 "building_sandbag_ring"
                {spawn "sandbag_heap_pile" offset 76 76 -5}
                {delay_ex 2 "building_sandbag_ring"
                    {spawn "sandbag_heap_straight_90" offset 25 80 -5}
                    {spawn "sandbag_heap_straight_90" offset -25 80 -5}
                    {delay_ex 2 "building_sandbag_ring"
                        {spawn "sandbag_heap_pile" offset -76 76 -5}
                        {delay_ex 2 "building_sandbag_ring"
                            {spawn "sandbag_heap_straight" offset -80 25 -5}
                            {delay_ex 2 "building_sandbag_ring"
                                {spawn "sandbag_heap_pile" offset -76 -76 -5}
                                {delay_ex 2 "building_sandbag_ring"
                                    {spawn "sandbag_heap_straight_270" offset 25 -80 -5}
                                    {spawn "sandbag_heap_straight_270" offset -25 -80 -5}
                                    {delay_ex 2 "building_sandbag_ring"
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

    {on "tag_artillery"
        ("tag_veh" args "artillery")
    }

    {on "tag_heavy_artillery"
        ("tag_veh" args "heavy_artillery")    
    }

    {on "tag_rocket_artillery"
        ("tag_veh" args "rocket_artillery")   
    }  
;================ Vanilla Hardcoded LOGIC ========================
    {on "activate_vehicle"
        {tags remove "ignore_repair"}
    }

    {on "show_radio_icon"
        {view start "beacon_fx"}
        {delay 60
            {view stop "beacon_fx"}
        }
    }

    {on spawn
        {add_view "beacon_fx" "beacon_fx" "body"}
            
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


;================ ARTY LOGIC END ========================
    {on operatable on
        {if user_control
            ;{call "clear_bad_player_tags"}
            {tags remove "artillery_moving_slow"}
            {tags remove "_ai_defender"}  
            {delay 1.5
                {if tagged "radio_car"
                    {view start "beacon_fx"}
                }
            }          
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
        {if tagged "not_selectable"
            ;{if tagged "_lua_always_ignore"
                {if user_control
                    {damage_report "sabotage" "<s(20)b+c(#FF0000)>:)"}
                    {clear_inventory}
                    {call_synced "explosion"}
                }
           ;}
        }

        {if tagged "paradropped_veh"
            {tags remove "paradropped_veh"}
            {tags remove "_lua_mi"}
            {tags remove "trooper_to_crew"}
            {if not user_control
                {tags add "paradrop_veh_need_new_squad"}
            }
        }
        {delay 1
            {if tagged "radio_car"
                {call "show_radio_icon"}
            }
        }
    }

    {on operatable off
        {delay 1
            {if tagged "_abandoned"
                {tags remove "_user_ally"}
            }
        }
        {view stop "beacon_fx"}
    }

    {on break
        {if not tagged "exploded"
            {if component "body"
                {tags remove "_user_ally"}
                {kill_delay "building_sandbag_ring"}
                {if not user_control
                    {if tagged "artillery"
                        {able minimap 0}
                    }
                else tagged "_bot"
                    {if tagged "artillery"
                        {able minimap 0}
                    }   
                }
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
            {able "select" 0}
        }
    }
}
