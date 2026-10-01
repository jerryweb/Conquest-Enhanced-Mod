{"human"
	; ================= Spawn Extensions =================
	{on "smoke_for_test"
        {add_view "smoke_flare_blue" "smoke" "root"}
        {view start "smoke"}
        {delay 10 "smoke"
            {view stop "smoke"}
        }
    }

	{on "set_ignore_spawn_logic"
	
		{tags remove "in_spawn_zone_a_1_inf"}
		{tags remove "in_spawn_zone_a_2_inf"}
		{tags remove "in_spawn_zone_a_3_inf"}
		{tags remove "in_spawn_zone_a_4_inf"}

		{tags remove "in_spawn_zone_b_1_inf"}
		{tags remove "in_spawn_zone_b_2_inf"}
		{tags remove "in_spawn_zone_b_3_inf"}
		{tags remove "in_spawn_zone_b_4_inf"}

		{tags remove "moving_to_waypoint_graph"}
		{tags remove "_lua_mi"}
		{tags add "ignore_spawn_logic"}
	}

;============= Tagging Functions =============
	{on "tag_squad_need_next_order"
		{if tagged "_lua_mi"
			{tags remove "_lua_mi"}
		}
		{delay 0.25
			{tags add "_lua_need_next_order"}
			{delay 10.1  
				{tags remove "_lua_need_next_order"}
				{tags remove "inf_need_to_attack"}
				{tags remove "paratrooper_need_orders"}
			}		
		}
	}
}