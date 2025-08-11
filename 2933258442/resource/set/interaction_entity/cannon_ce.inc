{"cannon"
	{on spawn
		{delay 0.5
        	{if linked "ce_drop"
        	    {tags add "no_scavenge"}
        	}
        }
    }
}

{"cannon ai"
	{on spawn
		{delay 1
			{if operatable
				{tags remove "not_selectable"}
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

; ===== Artillery ===== 
	{"cannon detect_artillery artillery_minimap_medium" 
		{on spawn
			{delay 0.2
				{tags add "artillery"}
			}
		}
	}

	{"cannon detect_artillery trailer_heavy" 
		{on spawn
			{delay 0.2
				{tags add "artillery"}
			}
		}
	}

	{"cannon detect_artillery artillery_minimap_heavy" 
		{on spawn
			{delay 0.2
				{tags add "heavy_artillery"}
			}
		}
	}

	{"cannon detect_artillery"
		{on spawn
			{delay 0.2
				{tags add "artillery"}
			}
		}
	}
;=====================================================================

{"mortar cannon" 
	;{on spawn
	;	{delay 0.2
	;		{call "tag_mortar"}	
	;	}
	;}

	{on "construction_sandbag_cannon_standard" overload
		{call "random_small_sandbag_ring"}
	}

	{on "construction_sandbag_cannon_shallow" overload
		{call "random_small_sandbag_ring"}
	}
}

;{"mortar_big cannon" 
;	{on spawn
;		{delay 0.2
;			{call "tag_mortar"}	
;		}
;	}
;}

{"mortar_pit_emplacement"
    {on spawn
        {delay 5.1
            {spawn "trench_dirt_mortar_engineer" offset 50 0 0}
        }
    }
}

{"flak_ring_aa"
    {on spawn
        {delay 0.2
            {physics_work 0}
            {volumes disable contact}
            {delay 0.1
                {spawn "flak_ring" offset 0 0 -10} 
            }
        }
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