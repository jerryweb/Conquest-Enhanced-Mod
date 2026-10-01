{"vehicle"   
    {on "smoke_for_test"
        {add_view "smoke_yellow_norm" "smoke" "root"}
        {view start "smoke"}
        {delay 10 "smoke"
            {view stop "smoke"}
        }
    }
    
    {on "smoke_for_test_red"
        {add_view "smoke_flare_red" "smoke" "root"}
        {view start "smoke"}
        {delay 10 {view stop "smoke"}}
    }

    {on "smoke_for_test_dark_red"
        {add_view "smoke_flare_dark_red" "smoke" "root"}
        {view start "smoke"}
        {delay 10 {view stop "smoke"}}
    }

    {on "smoke_for_test_blue"
        {add_view "smoke_flare_blue" "smoke" "root"}
        {view start "smoke"}
        {delay 10 {view stop "smoke"}}
    }

    {on "smoke_for_test_light_red"
        {add_view "smoke_flare_light_red" "smoke" "root"}
        {view start "smoke"}
        {delay 10 {view stop "smoke"}}
    }

    {on "smoke_for_test_light_purple"
        {add_view "smoke_flare_light_purple" "smoke" "root"}
        {view start "smoke"}
        {delay 10 {view stop "smoke"}}
    }

    {on "tag_squad_need_next_order"
        {if tagged "engine_turned_off"
            {if operatable
                {call "engine_on"}
            }
        }
        {tags remove "cmp_mg"}
        {tags remove "ai_emplacement_defenses"}
        {tags remove "_user"}
        {tags remove "_user_ally"}
        {tags remove "attacking_flag_1"}
        {tags remove "attacking_flag_2"}
        {tags remove "attacking_flag_3"}
        {tags remove "attacking_flag_4"}
        {tags remove "attacking_flag_5"}
        {tags remove "artillery_in_combat"}
        {tags remove "artillery_selected"}
        {tags remove "artillery_ordered"}

        {if tagged "artillery"
            {tags remove "_lua_always_ignore"}
        }

        ;{call "smoke_for_test_light_purple"}

        {tags add "_lua_need_next_order"}
        {delay 10.1 
            {tags remove "_lua_need_next_order"}
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
}
