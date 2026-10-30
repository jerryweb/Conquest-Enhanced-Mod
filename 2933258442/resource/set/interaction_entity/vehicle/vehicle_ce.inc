{"vehicle"   
;============= Tagging Functions ============================

    {on "tag_squad_need_next_order"
        {if tagged "engine_turned_off"
            {if operatable
                {call "engine_on"}
            }
        }
        {tags remove "cmp_mg"}
        {tags remove "cannon_selected_to_move"}
        {tags remove "cannon_need_next_order"}
        {tags remove "artillery_in_combat"}
        {tags remove "artillery_selected"}
        {tags remove "artillery_ordered"}
        {tags remove "_lua_mi"}
        {tags remove "selected_recon_plane"}

        {tags add "_lua_need_next_order"}
        {delay 10.1 
            {tags remove "_lua_need_next_order"}
        }
    }

;============= Vanilla and Overloaded Functions =============
    {on break
        {if not tagged "exploded"
            {if component "body"
                {tags remove "possible_enemy_artillery"}
                {tags remove "possible_enemy_cannon"}
                {tags remove "possible_enemy_tank"}
            }
        }
    }

    {on destroy
        {if component "body"
            {tags remove "possible_enemy_artillery"}
            {tags remove "possible_enemy_cannon"}
            {tags remove "possible_enemy_tank"}
        }
    }

    {on crew out    
        {if not user_control
            {if prop "multi_board"
                {if prop "truck"
                    {if not crew_in_place "seat1"
                        {delay 3 {tags add "_ai_veh_empty"}}
                    }
                }
            }            
        }
    }
; ================= CE Functions ===========================
    {on "smoke_for_test"
        {add_view "smoke_yellow_norm" "smoke" "root"}
        {view start "smoke"}
        {delay 10 "smoke"
            {view stop "smoke"}
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

    {on "hide_transports"
        {tags remove "_transport_rtb"}
        {hide 5}      
    }

    {on "ce_build_ai_cannon_sandbags"
        {able select 0}
    }    

    {on "prep_veh_for_p_crew"
        {tags remove "p_cannon_enter"}
        {tags add "trooper_to_crew"}
        {delay 30
            {tags remove "trooper_to_crew"}
        }
    }

(include "veh_sandbags.inc")
}

(include "radio_vehicle_tagging.inc")