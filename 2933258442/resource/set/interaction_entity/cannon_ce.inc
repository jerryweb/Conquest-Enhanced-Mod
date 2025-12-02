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

; ============ CE CANNONS DETONATIONS DEFINES ============ 

;{"cannon"		
;	{on spawn
;		{link_sound "cracks01" "detonation\cook_off\cracks"}	
;		{link_sound "cracks02" "detonation\cook_off\cracks"}
;		{link_sound "cracks03" "detonation\cook_off\cracks"}
;		{link_sound "cracks04" "detonation\cook_off\cracks"}		
;		{link_sound "cracks05" "detonation\cook_off\cracks"}				
;	}					
;}	

; 		============ MEDIUM_LIGHT ============ 

(define "Medium_light_Cannon_Detonation"
	{on "cut_parts"

		; ==== 15% chance: full ammo cook-off sequence ====
		{if rand 0.15
			{call "explosion"}		

			{if rand 0.33
				{spawn "tank_die_light"}
			}

			; --- pick ONE of the 4 cooking FX ---
			{if rand 0.25
				{spawn "cooking_high_ce"}
			else rand 0.333333
				{spawn "cooking_high_ce"}
			else rand 0.5
				{spawn "cooking_high_ce"}
			else
				{spawn "cooking_high_ce"}
			}

			{if rand 0.33
				{spawn "metal_hit_br_max"}
			}		

			{spawn "tank_die_dust_light"}			

			{if rand 0.33
				{spawn "ex_he_size3"}
			else rand 0.5
				{spawn "ex_air_heat_size3"}
			else
				{spawn "ex_air_he_size3"}
			}

			; halos for big cook-off
			{if rand 0.4
				{spawn "det_flash_bigger"}
			else rand 0.6
				{spawn "det_flash_big"}
			else
				{spawn "det_flash_medium"}
			}						
			{spawn "smoke_white_Medium_2"}

			; --- delayed cook-off sounds ---
			{delay 1		
				{start_Sound "detonation\cook_off\cracks"}								
			}		
			{delay 1.5					
				{start_Sound "detonation\cook_off\cracks"}	
			}							
			{delay 2 "loop"	
				;{play_sound "cracks01" 1}		
				;{play_sound "cracks02" 1}										
				;{play_sound "cracks03" 1}
				;{play_sound "cracks04" 1}	
				{start_Sound "detonation\s3\shockwave\Dirt\Trickle"}																					
			}
			{delay 4
				{start_Sound "detonation\cook_off\snaps"}
				{play_sound "snaps05" 1}																	
			}
			{delay 8.5					
				{start_Sound "detonation\cook_off\cracks"}	
			}						
			{delay 14
				{start_sound "detonation/cook_off/transition"}						
			}
		else
			; ==== Otherwise (no cook-off) choose simpler explosion type ====
			{if rand 0.33
				; --- Simple dirt burst ---
				{call "explosion"}
				{spawn "_shock"}
				{spawn "tank_die_light"}	
				{spawn "tank_die_dust_light"}
				{spawn "metal_hit_br_max"}

			else rand 0.5
				; --- Air HE type blast ---
				{call "explosion"}	
				{spawn "ex_air_he_size3"}
				{spawn "tank_die_dust_light"}

			else
				; --- Failsafe / vanilla-style detonation ---
				{call "explosion"}	
				{spawn "_shock"}
				;{spawn "medium_flash"}				
				{spawn "tank_die_dust_light"}
				{spawn "det_flash_medium"}					
			}
		}
	}
)

; 		============ MEDIUM ============ 

(define "Medium_Cannon_Detonation"
	{on "cut_parts"

		; ==== 15% chance: full ammo cook-off sequence ====
		{if rand 0.15
			{call "explosion"}		

			{if rand 0.33
				{spawn "tank_die_light"}
			}

			; --- pick ONE of the 4 cooking FX ---
			{if rand 0.25
				{spawn "cooking_high_ce"}
			else rand 0.333333
				{spawn "cooking_high_ce"}
			else rand 0.5
				{spawn "cooking_high_ce"}
			else
				{spawn "cooking_high_ce"}
			}

			{if rand 0.33
				{spawn "metal_hit_br_max"}
			}		

			{spawn "tank_die_dust_light"}			

			{if rand 0.33
				{spawn "ex_he_size3"}
			else rand 0.5
				{spawn "ex_air_heat_size3"}
			else
				{spawn "ex_air_he_size3"}
			}

			; halos for big cook-off
			{if rand 0.4
				{spawn "det_flash_bigger"}
			else rand 0.6
				{spawn "det_flash_big"}
			else
				{spawn "det_flash_medium"}
			}						
			{spawn "smoke_white_Medium_2"}

			; --- delayed cook-off sounds ---
			{delay 1		
				{start_Sound "detonation\cook_off\cracks"}								
			}		
			{delay 1.5					
				{start_Sound "detonation\cook_off\cracks"}	
			}							
			{delay 2 "loop"	
				;{play_sound "cracks01" 1}		
				;{play_sound "cracks02" 1}										
				;{play_sound "cracks03" 1}
				;{play_sound "cracks04" 1}	
				{start_Sound "detonation\s3\shockwave\Dirt\Trickle"}																					
			}
			{delay 4
				{start_Sound "detonation\cook_off\snaps"}
				{play_sound "snaps05" 1}																	
			}
			{delay 8.5					
				{start_Sound "detonation\cook_off\cracks"}	
			}						
			{delay 14
				{start_sound "detonation/cook_off/transition"}						
			}
		else
			; ==== Otherwise (no cook-off) choose simpler explosion type ====
			{if rand 0.33
				; --- Simple dirt burst ---
				{call "explosion"}
				{spawn "_shock"}
				{spawn "tank_die_light"}	
				{spawn "tank_die_dust_light"}
				{spawn "metal_hit_br_max"}	
				{start_Sound "detonation\cook_off\snaps"}				
			else rand 0.5
				; --- Air HE type blast ---
				{call "explosion"}	
				{spawn "ex_air_he_size3"}
				{spawn "tank_die_dust_light"}
			else
				; --- Failsafe / vanilla-style detonation ---
				{call "explosion"}	
				{spawn "_shock"}
				;{spawn "medium_flash"}				
				{spawn "tank_die_dust_light"}
				{spawn "det_flash_medium"}					
			}
		}
	}
)

; 		============ MEDIUM_HEAVY ============ 

(define "Medium_Heavy_Cannon_Detonation"
	{on "cut_parts"

		; ==== 15% chance: full ammo cook-off sequence ====
		{if rand 0.15
			{call "explosion"}		

			{if rand 0.33
				{spawn "tank_die_light"}
			}

			; --- pick ONE of the 4 cooking FX ---
			{if rand 0.25
				{spawn "cooking_high_ce"}
			else rand 0.333333
				{spawn "cooking_high_ce_light"}
			else rand 0.5
				{spawn "cooking_high_ce_heavy"}
			else
				{spawn "cooking_high_ce_chaotic"}
			}

			{if rand 0.33
				{spawn "metal_hit_br_max"}
			}		

			{spawn "tank_die_dust_light"}			

			{if rand 0.33
				{spawn "ex_he_size3"}
			else rand 0.5
				{spawn "ex_air_heat_size4"}
			else
				{spawn "ex_air_he_size4"}
			}

			; halos for big cook-off
			{if rand 0.4
				{spawn "det_flash_bigger"}
			else rand 0.6
				{spawn "det_flash_big"}
			else
				{spawn "det_flash_medium"}
			}						
			{spawn "smoke_white_Medium_2"}

			; --- delayed cook-off sounds ---
			{delay 1		
				{start_Sound "detonation\cook_off\cracks"}								
			}		
			{delay 1.5					
				{start_Sound "detonation\cook_off\cracks"}	
			}							
			{delay 2 "loop"	
				;{play_sound "cracks01" 1}		
				;{play_sound "cracks02" 1}										
				;{play_sound "cracks03" 1}
				;{play_sound "cracks04" 1}	
				{start_Sound "detonation\s3\shockwave\Dirt\Trickle"}																					
			}
			{delay 4
				{start_Sound "detonation\cook_off\snaps"}
				{play_sound "snaps05" 1}																	
			}
			{delay 8.5					
				{start_Sound "detonation\cook_off\cracks"}	
			}						
			{delay 14
				{start_sound "detonation/cook_off/transition"}						
			}
		else
			; ==== Otherwise (no cook-off) choose simpler explosion type ====
			{if rand 0.33
				; --- Simple dirt burst ---
				{call "explosion"}
				{spawn "_shock"}
				{spawn "tank_die_light"}	
				{spawn "tank_die_dust_light"}
				{spawn "metal_hit_br_max"}

			else rand 0.5
				; --- Air HE type blast ---
				{spawn "_shock"}
				{call "explosion"}	
				{spawn "ex_air_he_size4"}
				{spawn "tank_die_dust_light"}

			else
				; --- Failsafe / vanilla-style detonation ---
				{call "explosion"}	
				{spawn "_shock"}
				;{spawn "medium_flash"}				
				{spawn "tank_die_dust_light"}
				{spawn "det_flash_medium"}					
			}
		}
	}
)

; ============ CE CANNONS DETONATIONS  ============ 
; 		============ MEDIUM ============ 
{"muzzle_75mm_76mm"
("Medium_Cannon_Detonation")
}
{"muzzle_75mm_76mm_sides"
("Medium_Cannon_Detonation")
}

; ============ CE CANNONS DETONATIONS ============ 
; 		============ MEDIUM_LIGHT ============ 
{"muzzle_50mm_57mm"
("Medium_light_Cannon_Detonation")
}