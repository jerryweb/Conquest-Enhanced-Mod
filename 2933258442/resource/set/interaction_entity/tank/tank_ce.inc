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

{"tank detect_artillery rocket"
    {on spawn
        {delay 1
            {tags add "short_range"}
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

{"8_wheels"
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