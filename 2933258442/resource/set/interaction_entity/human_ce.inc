{"human"
; ================= Spawn Extensions =================
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

	{on "link_weapon"
		{if effector "stuff weapon"		;// see interaction_entity/stuff.inc
			{call "tag_breed"}		
		}
		{if effector "stuff grenade"		;// see interaction_entity/stuff.inc
			{call "tag_breed"}		
		}
	}

;============= Vanilla and Overloaded Functions =============
	{on ground_hit 
		{if tagged "paratrooper"
			{if not user_control
				{if not dead
					{tags add "paratrooper_need_orders"}
					{delay 120 "para_orders_timer"
						{tags remove "paratrooper_need_orders"}
					}
				}
			}
			{tags remove "paratrooper"}
		}
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

	{on "tag_breed"
		{if effector "binocular"
			{if user_control
				{tags add "officer"}
			}
		else effector "ai_flare_pistol"
			{if not user_control
				{tags add "ai_signaller"}
				{tags add "ignore_recrew"}
			}
		}
	}

; ================= Die Extensions =================
	{on "die"
		{tags remove "possible_enemy_officer"}
	}

	{on "die_from_knife"
		{tags remove "possible_enemy_officer"}
	}

; ================= CE Functions =================
	{on "smoke_for_test"
        {add_view "smoke_yellow_norm" "smoke" "root"}
        {view start "smoke"}
        {delay 10 "smoke"
            {view stop "smoke"}
        }
    }

    {on "order_paratrooper"
		{tags remove "p_crew"}
		{tags remove "selected_paratrooper"}
		{tags remove "_lua_mi"}
	}
}