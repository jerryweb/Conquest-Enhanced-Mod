{"cannon"
    {on "ce_build_ai_cannon_sandbags"
        {if not tagged "ce_ai_cannon_sandbags"
            {if operatable
                {if not user_control
                    {tags add "ce_ai_cannon_sandbags"}
                    {if prop "mg_stan"
                        {if prop "cannon_sandbag_standard"
                            {call "construction_sandbag_cannon_standard"}
                        else prop "cannon_sandbag_small"
                            {call "construction_sandbag_cannon_shallow_ai"}
                        else prop "fixed"
                            {call "construction_sandbag_cannon_shallow_ai"}
                        else prop "cannon_sandbag_standard_ai"
                            {call "construction_sandbag_cannon_standard_ai"}
                        else prop "cannon_sandbag_small_ai"
                            {call "construction_sandbag_cannon_shallow_ai"}
                        }
                    else prop "cannon_sandbag_small"
                        {call "construction_sandbag_cannon_shallow"}
                    else
                        {call "construction_sandbag_cannon_standard"}
                    }
                }
            }
        }
    }
}

{"searchlight"
    {on "construction_sandbag_cannon_standard" overload
        {call "random_heavy_sandbag_ring"}
    }
    {on "hull_down" overload
        {call "random_heavy_sandbag_ring"}
    }
}

{"cannon trailer_heavy detect_atgun muzzle_85mm_93mm invisible"
    {on "construction_sandbag_cannon_standard" overload
        {call "random_heavy_sandbag_ring"}
    }
}

{"cannon trailer_heavy detect_atgun muzzle_75mm_76mm_round"
    {on "construction_sandbag_cannon_standard" overload
        {call "random_medium_sandbag_ring"}
    }
}

{"cannon detect_cannon_aa trailer_heavy"
    {on "construction_sandbag_cannon_standard" overload
        {call "random_medium_sandbag_ring"}
    }
}

{"cannon detect_cannon_aa trailer_medium"
    {on "construction_sandbag_cannon_standard" overload
        {call "sandbag_ring_heap_straight_short_no_piles"}
    }
}

{"cannon detect_cannon_aa trailer_medium muzzle_37mm_40mm_auto"
    {on "construction_sandbag_cannon_standard" overload
        {call "random_medium_sandbag_ring"}
    }
}

{"cannon detect_cannon_aa trailer_light"
    {on "construction_sandbag_cannon_standard" overload
        {call "sandbag_ring_heap_straight_short_no_piles"}
    }
}

{"mortar cannon"
    {on "construction_sandbag_cannon_standard" overload
        {call "random_small_sandbag_ring"}
    }
    {on "construction_sandbag_cannon_shallow" overload
        {call "random_small_sandbag_ring"}
    }
}

{"37mm_pstk36"
    {on "construction_sandbag_cannon_standard" overload}
    {on "construction_sandbag_cannon_shallow" overload}
}

{"37mm_flak37"
    {on "construction_sandbag_cannon_standard" overload
        {call "sandbag_ring_heap_straight_short_no_piles"}
    }
}

{"85mm_52k"
    {on "construction_sandbag_cannon_standard" overload
        {call "random_heavy_sandbag_ring"}
    }
}

{"pak_44"
    {on "construction_sandbag_cannon_standard" overload
        {call "random_medium_sandbag_ring"}
    }
}

{"40mm_m1"
    {on "construction_sandbag_cannon_standard" overload
        {call "random_heavy_sandbag_ring"}
    }
}

{"40mm_itk38b"
    {on "construction_sandbag_cannon_standard" overload
        {call "random_heavy_sandbag_ring"}
    }
}
