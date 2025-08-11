; ================= Flag Point Entities =================

{"flag"
	{on spawn
		{delay 1
			{tags add "flag_point"}
		}
		{delay 3
			(mod "mp"
				{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}
				{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}
				{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}
				{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}
	            ;{spawn "chicken" random_position 400 offset 0 0 180}

				{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}
				{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}
				{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}
				{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}

				{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}
				{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}
				{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}
				{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0} 

				{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}
				{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}
				{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}
				{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}				  
	        )   
		}
    }
    
	{on "call_flag_defense_crates"
		(mod "mp"
			{if tagged "defense_level_2"
	    		{spawn "ammo2" random_position 20}
	    	else tagged "defense_level_3"
	    		{spawn "ammo2" random_position 20}
	    		{call "drop_ammo_crates"}
	    	}
    	)
	}

	{on "drop_ammo_crates"
		{add_view "smoke_yellow_norm" "smoke" "root"}
		{view start "smoke"}
		{delay 9
			{start_sound "vehicle/airborne/cargo_plane_flyby.wav"}
		}
		{delay 17 "smoke"
			{if rand 0.5
				{spawn "paradrop_ammo_crates_1" random_position 400 offset 0 0 1000
					{tags add "defense_supply_drop"}
					{tags add "ammo_crate_1"}
				}
			else 
				{spawn "paradrop_ammo_crates_3" random_position 400 offset 0 0 1000
					{tags add "defense_supply_drop"}
					{tags add "ammo_crate_2"}
				}
			}
		}
		{delay 20 "smoke"
			{view stop "smoke"}
		}	
	}
}

{"flag_ammo"
	{on spawn 
		{delay 0.1
			{tags remove "flag_point"}
			{tags add "supplies"}
		}
	}
}

{"ammo2"
	{on spawn 
		{tags add "supplies"}
	}
}

{"map_point"
	{on "spawn_drop_zone_targets"
		{spawn "ai_waypoint_pole" random_position 50 scale 4.0
			{tags add "drop_zone_selected"}
			{tags add "spawn_drop_zone"}
		}
		{spawn "ai_waypoint_pole" random_position 2500 scale 4.0
			{tags add "drop_zone_selected"}
			{tags add "spawn_drop_zone"}
		}
		{spawn "ai_waypoint_pole" random_position 2500 scale 4.0
			{tags add "drop_zone_selected"}
			{tags add "spawn_drop_zone"}
		}
		{spawn "ai_waypoint_pole" random_position 2500 scale 4.0
			{tags add "drop_zone_selected"}
			{tags add "spawn_drop_zone"}
		}
		{spawn "ai_waypoint_pole" random_position 2500 scale 4.0
			{tags add "drop_zone_selected"}
			{tags add "spawn_drop_zone"}
		}
		{spawn "ai_waypoint_pole" random_position 2500 scale 4.0
			{tags add "drop_zone_selected"}
			{tags add "spawn_drop_zone"}
		}
		{spawn "ai_waypoint_pole" random_position 2500 scale 4.0
			{tags add "drop_zone_selected"}
			{tags add "spawn_drop_zone"}
		}
		{spawn "ai_waypoint_pole" random_position 2500 scale 4.0
			{tags add "drop_zone_selected"}
			{tags add "spawn_drop_zone"}
		}
		{spawn "ai_waypoint_pole" random_position 2500 scale 4.0
			{tags add "drop_zone_selected"}
			{tags add "spawn_drop_zone"}
		}
		{spawn "ai_waypoint_pole" random_position 2500 scale 4.0
			{tags add "drop_zone_selected"}
			{tags add "spawn_drop_zone"}
		}
		{spawn "ai_waypoint_pole" random_position 2500 scale 4.0
			{tags add "drop_zone_selected"}
			{tags add "spawn_drop_zone"}
		}
		{spawn "ai_waypoint_pole" random_position 2500 scale 4.0
			{tags add "drop_zone_selected"}
			{tags add "spawn_drop_zone"}
		}
	}
	
	{on "spawn_ai_waypoint_poles"
		{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}
		{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}
		{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}
		{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0} 

		{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}
		{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}
		{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}
		{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}
	}
}

{"ce_drop"
    {on spawn
        {tags add "ce_drop"}
    }
}
{"ce_vehicle_drop"
    {on spawn
        {tags add "ce_vehicle_drop"}
    }
}

; ============== Generic Entites ==================
{"smokecustom"
	{on "onThrow"
		{delay 0.5
        	{impulse up -22.01 com}
        }
	}
}

{"parachute_attach ammo_crate"
	(define "paradrop_vehicle"
		{if tagged "rus"
			{if rand 0.5
				("spawn_paradropped_vehicle" veh("m41_ampulomet"))
			else
				("spawn_paradropped_vehicle" veh("120mm_pm38"))
			}
		else tagged "ger"
			{if rand 0.5
				("spawn_paradropped_vehicle" veh("80mm_sgrw34_rapid"))
			else
				("spawn_paradropped_vehicle" veh("200mm_ldgw40"))
			}
		else tagged "usa"
			{if rand 0.5
				("spawn_paradropped_vehicle" veh("81mm_m1"))
			else
				("spawn_paradropped_vehicle" veh("107mm_m2"))
			}
		else tagged "rus_supply_box"	
			("spawn_paradropped_vehicle" veh("inf_crate_rus"))	
		else tagged "ger_supply_box"	
			("spawn_paradropped_vehicle" veh("inf_crate_ger"))	
		else tagged "usa_supply_box"	
			("spawn_paradropped_vehicle" veh("inf_crate_usa"))	
		}
	)

	(define "spawn_paradropped_vehicle"
		{spawn %veh offset 0 0 18
			{tags add "paradropped_veh"}
		}
	)

	{on ground_hit overload
		{kill_delay "parachute_swing"}
		{ani_play "landing" callback}
		{tags remove "_flight"}
		{with_linked_entity "attach"
			{unlink}
			{ani_wind "close" begin}
			{impulse up 0.01}
		}
		{delay 1
			{if tagged "ammo_crate_1"
				{spawn "ammo_boxes_drop_01" offset 0 0 18}
			else tagged "ammo_crate_2"
				{spawn "ammo_boxes_drop_03" offset 0 0 18}
			else tagged "ce_vehicle_drop"
				("paradrop_vehicle")
			else not tagged "ce_drop"
				{spawn "ammo2" offset 0 0 18}
			}
		}
		
		{physics_work 0}
	}
}


{"paradrop inventory_box"
	{on spawn 
		{delay 20
			{spawn "pointer_mines" "basis" x}
		}	
	}
}

{"pointer_mines"				;// mission objective icon/helper
	{on spawn
		{tags add "pointer_mines"}
		{add_view "mines" "mines" "upper"}
		{view start "mines"}
		{delay 300
			{delete}
		}
	}
}



;=================== Effects ====================

;{"shell_s1"
;	{on spawn overload
;		{delay 120
;			{hide 2}
;		}
;	}
;}
;
;{"shell_s2"
;	{on spawn overload
;		{delay 120
;			{hide 2}
;		}
;	}
;}
;
;{"shell_s3"
;	{on spawn overload
;		{delay 120
;			{hide 2}
;		}
;	}
;}

;=================== AI Logic Post ====================
{"ai_waypoint_pole"
	{on spawn
		{tags add "drop_zone"}
		;{delay 15
		;	{add_view "smoke_yellow_norm" "smoke" "root"}
		;	{view start "smoke"}
		;}
	}

	(define "spawn_object_for_defense"
		{if terrain_fx "ice"
			{spawn %object random_position 500 random_orientation constrain_after_dir {tex_mod "win"}}  
		else terrain_fx "snow"
			{spawn %object random_position 500 random_orientation constrain_after_dir {tex_mod "win"}}
		else terrain_fx "deep_water"
			;// don't spawn
		else
			{spawn %object random_position 500 random_orientation constrain_after_dir}
		}
	)

	{on "spawn_hedgehogs"
		{start_sound "vehicle/deploy/foxhole"}
		{spawn "building_smoke" "fx_dirt01"}
		{spawn "building_smoke" "fx_dirt02"}
		{spawn "building_smoke" "fx_dirt03"}
		{spawn "building_smoke" "fx_dirt04"}
		{spawn "building_smoke" "fx_dirt05"}
		{link_sound "trench_deploy" "vehicle/deploy/trench/"}
		{play_sound "trench_deploy"}
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
	}
}



; ================= Aim Entities =================
{"aim_dummy"
	(define "spawn_aim_dummy"
		{on spawn
			{tags add %0}
			;{spawn %1
			;	{tags add %1}
			;}
			{delay 0.2
				{call "static_supply_drop"}
			}
			{delay 3
				{delete}
			}
		}
	)

	(define "spawn_no_aim_dummy"
		{on spawn
			{tags add %0}
			{delay 3
				{delete}
			}
		}
	)

	{on "static_supply_drop"
		{spawn "paradrop_ammo_crates_basic" random_position 10}
		;{if rand 0.5
		;	{spawn "paradrop_ammo_crates_1" random_position 10}
		;else 
		;	{spawn "paradrop_ammo_crates_3" random_position 10}
		;}
	}
}

{"aim_dummy fin"			;// mission helper
	("spawn_aim_dummy" args "fin_supply_drop_aim" "paradrop_ammo_fin")
}

{"aim_dummy ger"			;// mission helper
	("spawn_aim_dummy" args "ger_supply_drop_aim" "paradrop_ammo_ger")
}

{"aim_dummy rus"			;// mission helper
	("spawn_aim_dummy" args "rus_supply_drop_aim" "paradrop_ammo_rus")
}

{"aim_dummy usa"			;// mission helper
	("spawn_aim_dummy" args "usa_supply_drop_aim" "paradrop_ammo_usa")
}


{"aim_dummy recon"			;// mission helper
	{on spawn
		{delay 3
			{delete}
			
		}
	}

}


; ================= Spawn Entities =================
{"spawn_aim"
	(define "spawn_aim_dummy"
		{on spawn
			{tags add "spawn_aim"}
			{tags add "%0_%1"}
		}
	)
}

{"spawn_aim side_a 1"
	("spawn_aim_dummy" args side_a 1)
}

{"spawn_aim side_a 2"
	("spawn_aim_dummy" args side_a 2)
}

{"spawn_aim side_a 3"
	("spawn_aim_dummy" args side_a 3)
}

{"spawn_aim side_a 4"
	("spawn_aim_dummy" args side_a 1)
}

{"spawn_aim side_b 1"
	("spawn_aim_dummy" args side_b 1)
}

{"spawn_aim side_b 2"
	("spawn_aim_dummy" args side_b 2)
}

{"spawn_aim side_b 3"
	("spawn_aim_dummy" args side_b 3)
}

{"spawn_aim side_b 4"
	("spawn_aim_dummy" args side_b 4)
}

{"spawn_waypoint_graph_disable"
	{on spawn
		{tags add "waypoint_graph_disable"}
	}
}

;============== PLAYER SERVICE =============
{"hedgehog_service"
     {on spawn
        {tags add "player_hedgehog"}
    }
    {on "set_dynamite"
    	{spawn "satchel_charge_rus" random_position 30
    		{delay 0.5
    			{call "onThrow"}
    			{delay 8
    				{call "explosion"}
    			}
    		}
    	}
    	{tags add "dynamite_set"}
    }
}

{"spawn_pointflag11-3a"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "1_a_1-3_mg"}
	}
}

{"spawn_pointflag12-3a"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "1_a_2-3_mg"}
	}
}

{"spawn_pointflag13a"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "1_a_3_mg"}
	}
}

{"spawn_pointflag21-3a"
    {on spawn
	    {tags add "cmp_def"}
        {tags add "2_a_1-3_mg"}
	}
}

{"spawn_pointflag22-3a"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "2_a_2-3_mg"}
	}
}

{"spawn_pointflag23a"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "2_a_3_mg"}
	}
}

{"spawn_pointflag31-3a"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "3_a_1-3_mg"}
	}
}

{"spawn_pointflag32-3a"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "3_a_2-3_mg"}
	}
}

{"spawn_pointflag33a"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "3_a_3_mg"}
	}
}

{"spawn_pointflag41-3a"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "4_a_1-3_mg"}
	}
}

{"spawn_pointflag42-3a"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "4_a_2-3_mg"}
	}
}

{"spawn_pointflag43a"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "4_a_3_mg"}
	}
}
 
{"spawn_pointflag51-3a"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "5_a_1-3_mg"}
	}
}

{"spawn_pointflag52-3a"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "5_a_2-3_mg"}
	}
}

{"spawn_pointflag53a"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "5_a_3_mg"}
	}
}


{"spawn_pointflag11-3b"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "1_b_1-3_mg"}
	}
}

{"spawn_pointflag12-3b"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "1_b_2-3_mg"}
	}
}

{"spawn_pointflag13b"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "1_b_3_mg"}
	}
}

{"spawn_pointflag21-3b"
    {on spawn
	    {tags add "cmp_def"}
        {tags add "2_b_1-3_mg"}
	}
}

{"spawn_pointflag22-3b"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "2_b_2-3_mg"}
	}
}

{"spawn_pointflag23b"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "2_b_3_mg"}
	}
}

{"spawn_pointflag31-3b"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "3_b_1-3_mg"}
	}
}

{"spawn_pointflag32-3b"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "3_b_2-3_mg"}
	}
}

{"spawn_pointflag33b"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "3_b_3_mg"}
	}
}

{"spawn_pointflag41-3b"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "4_b_1-3_mg"}
	}
}

{"spawn_pointflag42-3b"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "4_b_2-3_mg"}
	}
}

{"spawn_pointflag43b"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "4_b_3_mg"}
	}
}
 
{"spawn_pointflag51-3b"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "5_b_1-3_mg"}
	}
}

{"spawn_pointflag52-3b"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "5_b_2-3_mg"}
	}
}

{"spawn_pointflag53b"
    {on spawn
	    {tags add "cmp_def"}
		{tags add "5_b_3_mg"}
	}
}


{"stuff weapon flare_gun"
    {on grounded on
        {impulse up 11}
        {delay 1 
            {delete}
        }
    }
}

{"ally_infantry_support"
    {on spawn
        {delay 0.1
        	{tags add "ally_infantry_mark"}
        }
        {delay 1.6
			{delete}
		}
	}
}

;{"animal"
;    {on spawn
;        {delay 1.1
;            {player 0}
;        }
;    }
;}

{"antitank"
    {on spawn
        {delay 1.6
            {tags add "at_mine"}
            
        }
      
    }   
}


{"howitzer_pit_emplacement"
	{on spawn
		{delay 1.1
            {spawn "trench_dirt_mortar_engineer" "fx_invers" x }
        }
	}
}

{"dummy_emplacement"
	{on spawn
		{delay 0.1
            {able "select" 0}
            {components "body" break}
            {able select 0}
            {crew_enable group "crew" 0}
            {crew_enable group "passenger" 0}
            {crew_emit}
        }
	}
}
{"illusion_emplacement"
	{on spawn
		{delay 2.0		
			{delete}
		}
	}
}

{"heavy_blitz3_6_radio"
	{on spawn
		{delay 0.1
            {spawn "blitz3_6_radio" "enumerator_logo1" x }
        }
	}
}
{"heavy_aa_regelbau_flak_ring_88mm_flak36"
	{on spawn
		{delay 0.1
            {spawn "aa_regelbau_flak_ring_88mm_flak36" "enumerator_logo1" x }
        }
	}
}
{"heavy_emplacement_50mm_kwk39_platform"
	{on spawn
		{delay 0.1
            {spawn "emplacement_50mm_kwk39_platform" "enumerator_logo1" x }
        }
	}
}
{"heavy_emplacement_80mm_sgrw34_rapid"
	{on spawn
		{delay 0.1
            {spawn "emplacement_80mm_sgrw34_rapid" "enumerator_logo1" x }
        }
	}
}
{"heavy_emplacement_81mm_m1"
	{on spawn
		{delay 0.1
            {spawn "emplacement_81mm_m1" "enumerator_logo1" x }
        }
	}
}
{"heavy_emplacement_82mm_bm37"
	{on spawn
		{delay 0.1
            {spawn "emplacement_82mm_bm37" "enumerator_logo1" x }
        }
	}
}
{"heavy_emplacement_152mm_ml20"
	{on spawn
		{delay 0.1
            {spawn "emplacement_152mm_ml20" "enumerator_logo1" x }
        }
	}
}
{"heavy_emplacement_155mm_gpf_platform"
	{on spawn
		{delay 0.1
            {spawn "emplacement_155mm_gpf_platform" "enumerator_logo1" x }
        }
	}
}
{"heavy_emplacement_155mm_gpf_us"
	{on spawn
		{delay 0.1
            {spawn "emplacement_155mm_gpf_us" "enumerator_logo1" x }
        }
	}
}
{"heavy_emplacement_305mm_mb_2_12"
	{on spawn
		{delay 0.1
            {spawn "emplacement_305mm_mb_2_12" "enumerator_logo1" x }
        }
	}
}
{"heavy_flak_ring_88mm_flak36"
	{on spawn
		{delay 0.1
            {spawn "flak_ring_88mm_flak36" "enumerator_logo1" x }
        }
	}
}
{"heavy_m1917_30cal_emplacement"
	{on spawn
		{delay 0.1
            {spawn "m1917_30cal_emplacement" "enumerator_logo1" x }
        }
	}
}
{"heavy_maxim_emplacement"
	{on spawn
		{delay 0.1
            {spawn "maxim_emplacement" "enumerator_logo1" x }
        }
	}
}
{"heavy_maxim_x4_emplacement"
	{on spawn
		{delay 0.1
            {spawn "maxim_x4_emplacement" "enumerator_logo1" x }
        }
	}
}
{"heavy_50cal_quad_m45_emplacement"
	{on spawn
		{delay 0.1
            {spawn "50cal_quad_m45_emplacement" "enumerator_logo1" x }
        }
	}
}
{"heavy_mg42_lafette_emplacement"
	{on spawn
		{delay 0.1
            {spawn "mg42_lafette_emplacement" "enumerator_logo1" x }
        }
	}
}
{"heavy_mgun_ring_emplacement"
	{on spawn
		{delay 0.1
            {spawn "mgun_ring_emplacement" "enumerator_logo1" x }
        }
	}
}
{"heavy_regel_bau_pak_75mm_pak40"
	{on spawn
		{delay 0.1
            {spawn "regel_bau_pak_75mm_pak40" "enumerator_logo1" x }
        }
	}
}
{"heavy_regel_bau_76mm_m5_m1"
	{on spawn
		{delay 0.1
            {spawn "regel_bau_76mm_m5_m1" "enumerator_logo1" x }
        }
	}
}
{"heavy_regel_bau_76mm_zis3"
	{on spawn
		{delay 0.1
            {spawn "regel_bau_76mm_zis3" "enumerator_logo1" x }
        }
	}
}
{"heavy_sandbag_bunker_dummy_50cal"
	{on spawn
		{delay 0.1
            {spawn "sandbag_bunker_dummy_50cal" "enumerator_logo1" x }
        }
	}
}
{"heavy_sandbag_bunker_m2_50cal_tripod" ;// Added June 21
	{on spawn
		{delay 0.1
            {spawn "sandbag_bunker_m2_50cal_tripod" "enumerator_logo1" x }
        }
	}
}
{"trench_logs_straight_illusion"
	{on spawn
		{delay 0.1
            {spawn "trench_logs_straight" "basic" x }
        }
	}
}
{"trench_engineer_illusion"
	{on spawn
		{delay 0.1
            {spawn "trench_engineer" "basic" x }
        }
	}
}
{"heavy_sandbag_bunker_sg43_stand"
	{on spawn
		{delay 0.1
            {spawn "sandbag_bunker_sg43_stand" "enumerator_logo1" x }
        }
	}
}
{"heavy_sandbag_bunker_ds39_stand"
	{on spawn
		{delay 0.1
            {spawn "sandbag_bunker_ds39_stand" "enumerator_logo1" x }
        }
	}
}
{"heavy_sandbag_bunker_ds39_stand"
	{on spawn
		{delay 0.1
            {spawn "sandbag_bunker_ds39_stand" "enumerator_logo1" x }
        }
	}
}
{"heavy_sandbag_bunker_hmg42" ;// Added June 21
    {on spawn
        {delay 0.1
            {spawn "sandbag_bunker_hmg42" "enumerator_logo1" x }
        }
    }
}
{"heavy_supply_crate_build"
	{on spawn
		{delay 0.1
            {spawn "supply_crate_build" "enumerator_logo1" x }
        }
	}
}

{"heavy_240mm_type_45"
	{on spawn
		{delay 0.1
            {spawn "240mm_type_45" "enumerator_logo1" x }
        }
	}
}
{"heavy_200mm_type_3"
	{on spawn
		{delay 0.1
            {spawn "200mm_type_3" "enumerator_logo1" x }
        }
	}
}

{"heavyy_mg_type1"
	{on spawn
		{delay 0.1
            {spawn "heavy_mgg_type1" "enumerator_logo1" x }
        }
	}
}

{"heavyy_200mm_type_4"
	{on spawn
		{delay 0.1
            {spawn "heavy_200mm_type_4" "enumerator_logo1" x }
        }
	}
}

{"heavyy_75mm_type_88"
	{on spawn
		{delay 0.1
            {spawn "heavy_75mm_type_88" "enumerator_logo1" x }
        }
	}
}

{"heavyy_57mm_type_2"
	{on spawn
		{delay 0.1
            {spawn "heavy_57mm_type_2" "enumerator_logo1" x }
        }
	}
}

{"200mm_type_3"
	{on spawn
		{delay 1.5
            {able "select" 1}
        }
	}
}

{"heavy_200mm_type_4"
	{on spawn
		{delay 1.5
            {able "select" 1}
        }
	}
}

{"ally_support_dummy_high_dum"
    {on spawn overload
        
        {delay 0.2
            {tags add "support_mark_high"}
        }
	}
}

{"ally_support_dummy_low_dum"
    {on spawn overload
        
        {delay 0.2
            {tags add "support_mark_low"}
        }
        
        
	}
}
