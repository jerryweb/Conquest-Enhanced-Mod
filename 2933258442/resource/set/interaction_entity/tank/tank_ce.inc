; ================= Vehicle Hull Down Fortifications =================

(define "light_hull_down_sequence"
    {on "hull_down"
        {delay_ex 8 "tank_hull_down"
            {spawn "sandbag_framed_straight" offset 110 0 0}
            {spawn "sandbag_framed_straight" offset 110 50 0}
            {spawn "sandbag_framed_straight" offset 110 -50 0}
            {delay_ex 2 "tank_hull_down"
                {spawn "sandbag_heap_pile" offset 100 -100 0}   
                {delay_ex 2 "tank_hull_down"
                    {spawn "sandbag_framed_straight_90" offset 0 110 0}
                    {spawn "sandbag_framed_straight_90" offset -50 110 0}
                    {spawn "sandbag_framed_straight_90" offset 50 110 0}
                    {delay_ex 2 "tank_hull_down"
                        {spawn "sandbag_heap_pile" offset -100 -100 0}
                        {delay_ex 2 "tank_hull_down"
                            {spawn "sandbag_framed_straight_180" offset -110 0 0}
                            {spawn "sandbag_framed_straight_180" offset -110 50 0}
                            {spawn "sandbag_framed_straight_180" offset -110 -50 0}
                            {delay_ex 2 "tank_hull_down"
                                {spawn "sandbag_framed_straight_270" offset 0 -110 0}
                                {spawn "sandbag_framed_straight_270" offset -50 -110 0}
                                {spawn "sandbag_framed_straight_270" offset 50 -110 0}
                                {delay_ex 2 "tank_hull_down"
                                    {spawn "sandbag_heap_pile" offset 100 100 0}
                                }
                            }                           
                        }
                    }
                }                       
            }
        }
    }

    {on "_explosion"
        {kill_delay "tank_hull_down"}
    }
    {on "die"
        {kill_delay "tank_hull_down"}
    }
)

{"tank light"
    ("light_hull_down_sequence")
}

{"halftrack"
    ("light_hull_down_sequence")
}

{"8_wheels"
    ("light_hull_down_sequence")
}


(define "heavy_hull_down_sequence"
    {on "hull_down"
        {delay_ex 8 "tank_hull_down"
            {spawn "sandbag_framed_straight" offset 110 25 0}
            {spawn "sandbag_framed_straight" offset 110 75 0}
            {spawn "sandbag_framed_straight" offset 110 -25 0}
            {spawn "sandbag_framed_straight" offset 110 -75 0}
            {delay_ex 4 "tank_hull_down"
                {spawn "sandbag_framed_straight_90" offset -25 110 0}
                {spawn "sandbag_framed_straight_90" offset -75 110 0}
                {spawn "sandbag_framed_straight_90" offset 25 110 0}
                {spawn "sandbag_framed_straight_90" offset 75 110 0}
                {delay_ex 4 "tank_hull_down"
                    {spawn "sandbag_framed_straight_180" offset -110 25 0}
                    {spawn "sandbag_framed_straight_180" offset -110 75 0}
                    {spawn "sandbag_framed_straight_180" offset -110 -25 0}
                    {spawn "sandbag_framed_straight_180" offset -110 -75 0}
                    {delay_ex 4 "tank_hull_down"
                        {spawn "sandbag_framed_straight_270" offset -25 -110 0}
                        {spawn "sandbag_framed_straight_270" offset -75 -110 0}
                        {spawn "sandbag_framed_straight_270" offset 25 -110 0}
                    }
                }                   
            }
        }
    }

    {on "_explosion"
        {kill_delay "tank_hull_down"}
    }
    {on "die"
        {kill_delay "tank_hull_down"}
    }
)

{"tank medium"
    ("heavy_hull_down_sequence")
}

{"tank heavy"
    ("heavy_hull_down_sequence")
}

; ================= Vehicle Artillery & Rocket Tags =================

{"tank detect_artillery rocket"
    {on spawn
        {delay 1
            {tags add "short_range"}
        }
    }
}

(define "tag_vehicle_artillery"
    {"%entity"
        {on spawn
            {delay 0.2
                {tags add "artillery"}
            }
        }
    }
)

("tag_vehicle_artillery" entity(tank artillery_minimap_medium_2))
("tag_vehicle_artillery" entity(tank detect_artillery))
("tag_vehicle_artillery" entity(tank artillery_minimap_medium))
("tag_vehicle_artillery" entity(tank artillery_minimap_heavy))
("tag_vehicle_artillery" entity(spg artillery_minimap_medium))
("tag_vehicle_artillery" entity(spg detect_artillery))

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

; ================= Mine Sweeper AI Logic =================

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
                {delay_ex 60 "mine_search_timer"
                    {tags remove "clearing_mines"}
                }
            }
        }
    }

    {on "remove_mine_sweeper"
        {if operatable
            {if not user_control
                {kill_delay "mine_search_timer"}
                {tags add "mine_clear_not_needed"}
                {hide 10}
            }
        }
    }
}