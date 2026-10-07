
(define "ce_ai_cannon_bag"
    {if terrain_fx "ice"
        {spawn "%entity" offset %x %y %z {tex_mod "win"}}
    else terrain_fx "snow"
        {spawn "%entity" offset %x %y %z {tex_mod "win"}}
    else
        {spawn "%entity" offset %x %y %z}
    }
)

(define "ce_ai_cannon_native_cover"
    {if terrain_fx "ice"
        {spawn "%entity" "basis" x constrain_after_dir {tex_mod "win"}}
    else terrain_fx "snow"
        {spawn "%entity" "basis" x constrain_after_dir {tex_mod "win"}}
    else
        {spawn "%entity" "basis" x constrain_after_dir}
    }
)

{"cannon"
    {on "ce_build_ai_cannon_sandbags"
        {if not tagged "ce_ai_cannon_sandbags"
            {if operatable
                {if not user_control
                    {if not prop "no_sandbags"
                        {tags add "ce_ai_cannon_sandbags"}
                        {call "ce_ai_cannon_cover_shape"}
                    }
                }
            }
        }
    }

    {on "ce_ai_cannon_cover_shape"
        {if prop "mortar"
            {call "ce_ai_cannon_ring_small"}
        else prop "detect_cannon_aa"
            {call "ce_ai_cannon_ring_aa"}
        else prop "trailer_heavy"
            {call "ce_ai_cannon_ring_medium"}
        else prop "cannon_sandbag_small"
            ("ce_ai_cannon_native_cover" entity(sandbag_cannon_shallow_ai))
        else
            ("ce_ai_cannon_native_cover" entity(sandbag_cannon_standard_ai))
        }
    }

    {on "ce_ai_cannon_ring_small"
        {if rand 0.5
            {call "ce_ai_cannon_ring_small_heap"}
        else
            {call "ce_ai_cannon_ring_small_framed"}
        }
    }

    {on "ce_ai_cannon_ring_aa"
        {if prop "trailer_heavy"
            {call "ce_ai_cannon_ring_medium"}
        else prop "trailer_medium"
            {if prop "muzzle_37mm_40mm_auto"
                {call "ce_ai_cannon_ring_medium"}
            else
                {call "ce_ai_cannon_ring_short"}
            }
        else prop "trailer_light"
            {call "ce_ai_cannon_ring_short"}
        else
            {call "ce_ai_cannon_ring_medium"}
        }
    }

    {on "ce_ai_cannon_ring_medium"
        {if rand 0.5
            {call "ce_ai_cannon_ring_short"}
        else
            {call "ce_ai_cannon_ring_lane"}
        }
    }

    {on "ce_ai_cannon_ring_heavy"
        {if rand 0.5
            {call "ce_ai_cannon_ring_heavy_heap"}
        else
            {call "ce_ai_cannon_ring_heavy_framed"}
        }
    }

    {on "ce_ai_cannon_ring_small_heap"
        ("ce_ai_cannon_bag" entity(sandbag_heap_curved) x(40) y(0) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_curved_90) x(0) y(40) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_curved_270) x(0) y(-40) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_pile) x(-60) y(40) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_pile) x(-60) y(-40) z(-5))
    }

    {on "ce_ai_cannon_ring_small_framed"
        ("ce_ai_cannon_bag" entity(sandbag_framed_curved) x(40) y(0) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_framed_curved_90) x(0) y(40) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_framed_curved_270) x(0) y(-40) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_pile) x(-60) y(40) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_pile) x(-60) y(-40) z(-5))
    }

    {on "ce_ai_cannon_ring_short"
        ("ce_ai_cannon_bag" entity(sandbag_structured_straight) x(80) y(25) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_structured_straight) x(80) y(-25) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_structured_straight2) x(25) y(80) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_structured_straight2) x(-25) y(80) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_structured_straight) x(-80) y(25) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_structured_straight) x(-80) y(-25) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_structured_straight2) x(25) y(-80) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_structured_straight2) x(-25) y(-80) z(-5))
    }

    {on "ce_ai_cannon_ring_lane"
        ("ce_ai_cannon_bag" entity(sandbag_heap_straight) x(80) y(25) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_straight) x(80) y(-25) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_pile) x(72) y(72) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_straight_90) x(25) y(80) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_straight_90) x(-25) y(80) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_pile) x(-72) y(72) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_straight) x(-80) y(25) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_pile) x(-90) y(-25) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_pile) x(-130) y(-25) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_straight_270) x(25) y(-80) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_pile) x(-30) y(-80) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_pile) x(-70) y(-80) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_pile) x(-110) y(-80) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_pile) x(72) y(-72) z(-5))
    }

    {on "ce_ai_cannon_ring_heavy_heap"
        ("ce_ai_cannon_bag" entity(sandbag_heap_curved) x(75) y(0) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_pile) x(68) y(68) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_curved_90) x(0) y(75) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_pile) x(-68) y(68) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_curved_180) x(-75) y(0) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_curved_270) x(0) y(-75) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_pile) x(70) y(-70) z(-5))
    }

    {on "ce_ai_cannon_ring_heavy_framed"
        ("ce_ai_cannon_bag" entity(sandbag_framed_curved) x(80) y(0) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_pile) x(68) y(68) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_framed_curved_90) x(0) y(80) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_pile) x(-68) y(68) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_framed_curved_180) x(-80) y(0) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_framed_curved_270) x(0) y(-80) z(-5))
        ("ce_ai_cannon_bag" entity(sandbag_heap_pile) x(70) y(-70) z(-5))
    }
}

{"cannon trailer_heavy detect_atgun muzzle_85mm_93mm invisible"
    {on "ce_ai_cannon_cover_shape" overload
        {call "ce_ai_cannon_ring_heavy"}
    }
}
{"cannon trailer_heavy detect_atgun muzzle_75mm_76mm_round"
    {on "ce_ai_cannon_cover_shape" overload
        {call "ce_ai_cannon_ring_medium"}
    }
}
{"37mm_flak37 cannon"
    {on "ce_ai_cannon_cover_shape" overload
        {call "ce_ai_cannon_ring_short"}
    }
}
{"85mm_52k cannon"
    {on "ce_ai_cannon_cover_shape" overload
        {call "ce_ai_cannon_ring_heavy"}
    }
}
{"40mm_m1 cannon"
    {on "ce_ai_cannon_cover_shape" overload
        {call "ce_ai_cannon_ring_heavy"}
    }
}
{"40mm_itk38b cannon"
    {on "ce_ai_cannon_cover_shape" overload
        {call "ce_ai_cannon_ring_heavy"}
    }
}
{"37mm_pstk36 cannon"
    {on "ce_build_ai_cannon_sandbags" overload}
}
