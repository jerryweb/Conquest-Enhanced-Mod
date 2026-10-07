{"vehicle"   
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

    {on "deploy_smoke"}                     ;// overridden in tank file

    {on "reverse_directly_back_20_meters"
        {call "deploy_smoke"}
        {spawn "ai_waypoint_pole_h" "basis" x constrain_after_dir scale 4
            {spawn "ai_waypoint_pole" "reverse_here" x constrain_after_dir
                {tags add "back_up"}
            }
            {delay 0.01 {delete}}
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
}
