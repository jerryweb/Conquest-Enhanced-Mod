{"cannon"
    {on "ce_build_ai_cannon_sandbags"
        ;{if not tagged "ce_ai_cannon_sandbags"
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
        ;}
    }

    {on "artillery_attempt_failed"
        {tags remove "artillery_selected"}
        {tags remove "_lua_mi"}
        {tags add "artillery_advancing"}
        {delay 10
            {tags remove "artillery_advancing"}
        }
    }

    {on "artillery_attempt_failed_with_order"
        {call "tag_squad_need_next_order"}
        {call "artillery_attempt_failed"}
    }

    {on "artillery_start_combat_timer"
        {tags remove "artillery_selected"}
        {tags add "artillery_in_combat"}
        {delay 60
           {tags remove "artillery_in_combat"}
           {tags remove "_lua_mi"}
           ;{tags add "cannon_need_next_order"}
           ;{call "tag_squad_need_next_order"}
        }
    }

    {on "select_artillery"
        {tags add "artillery_selected"}
        ;{call "smoke_for_test"}
        {tags add "_lua_mi"}
    }

    {on "force_move_cannons_stuck_in_spawn"
        {call "tag_squad_need_next_order"}
        {call "set_ignore_spawn_logic"}
        {tags remove "select_force_moving_cannon_from_spawn"}
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

;============================Short Range Artillery=========================================

    (define "tag_short_range"
        {"%entity" 
            {on spawn
                {delay 1
                    {tags add "short_range"}
                }
            }
        }
    )

    ("tag_short_range" entity(76mm_land_mattress))
    ("tag_short_range" entity(105mm_m3))
    ("tag_short_range" entity(114mm_qf_how))
    ("tag_short_range" entity(114mm_qf_how_wooden))
    ("tag_short_range" entity(122mm_m1910_fin))
    ("tag_short_range" entity(114mm_h18_how_mid))
    ("tag_short_range" entity(114mm_h18_how_late))
    ("tag_short_range" entity(152mm_bl_6))
    ("tag_short_range" entity(210mm_h17))
    ("tag_short_range" entity(280mm_br5))
    ("tag_short_range" entity(600mm_thor))



;============================Long Range Artillery=========================================

    (define "tag_long_range"
        {"%entity"
            {on spawn
                {delay 0.2
                    {tags add "long_range"}
                }
            }
        }
    )

    ("tag_long_range" entity(105mm_sk18))
    ("tag_long_range" entity(105mm_k34))
    ("tag_long_range" entity(107mm_m1910_30))
    ("tag_long_range" entity(114mm_bl_4_5))
    ("tag_long_range" entity(114mm_bl_4_5_mk1))
    ("tag_long_range" entity(122mm_a19))
    ("tag_long_range" entity(152mm_br2))
    ("tag_long_range" entity(152mm_bl_6_mk19))
    ("tag_long_range" entity(155mm_gpf_ger))
    ("tag_long_range" entity(155mm_gpf_us))
    ("tag_long_range" entity(155mm_k17))
    ("tag_long_range" entity(155mm_m1a1_longtom_eng))
    ("tag_long_range" entity(170mm_k18))
    ("tag_long_range" entity(183mm_bl_7_2))
    ("tag_long_range" entity(183mm_bl_7_2_mk6))
    ("tag_long_range" entity(203mm_b4))
    ("tag_long_range" entity(203mm_m1))
    ("tag_long_range" entity(210mm_k39))
    ("tag_long_range" entity(210mm_morser))

