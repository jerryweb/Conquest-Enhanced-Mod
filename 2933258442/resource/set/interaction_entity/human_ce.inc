{"human"
; ================= Spawn Extensions =================
	{on spawn
		{delay 0.5
			{add_view "beacon_fx" "beacon_fx" "head" not_manual not_scenario}
			{delay 3
				{if tagged "radio_man"
					{call "show_radio_icon"}
				}
			}
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

	{on "personage_check" overload
		{if not tagged "hero_unit"				;// exception for unit to be revive-able in missions
			{if not user_control
				{if not tagged "_ai_support_for_user"
					{able "personage" 0}
				}
			else swimming
				{able "personage" 0}
			else burned
				{able "personage" 0}
			else tagged "crush"
				{able "personage" 0}
			else tagged "no_revive"
				{able "personage" 0}
				{tags remove "no_revive"}
			else 
				{if rand 0.5
					{call_synced "mp_personage_0"}
				}
			}
		}
	}

	{on "officer_mark"
		{if not dead
			{if tagged "_ai_support_for_user"
				{delay 5
					{call "stop_officer_mark"}
				}
			}
			{tags remove "getting_ai_support_order"}
			{tags add "support_order_ack"}
			{delay 20
				{tags remove "support_order_ack"}
			}
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
	{on "show_radio_icon"
       	{view start "beacon_fx"}
    }

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

	{on "set_ai_support_unit_for_user"
		{if not user_control
			{tags add "ai_support_selected"}
	        {tags add "_ai_support_for_user"}
	        {able "personage" 1}
	        {able "select" 0}
		}
    }
}