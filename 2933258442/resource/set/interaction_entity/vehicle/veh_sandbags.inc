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
