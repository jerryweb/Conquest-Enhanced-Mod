{"human"
; ================= Spawn Extensions =================
	{on spawn
		{delay 0.1
			{if linked "airborne"
				{if not linked "drop_plane"
					{tags add "air_pilot"}
				}
			}
		}

		{delay 0.5
			{add_view "beacon_fx" "beacon_fx" "head" not_manual not_scenario}
			{delay 3
				{view start "ai_control_zone_fx"}
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
		{if effector "stuff weapon"			;// see interaction_entity/stuff.inc
			{call "tag_breed"}
		else effector "stuff grenade"
			{call "tag_breed"}
		}
	}

;============= Vanilla and Overloaded Functions =============
	(include "blood_ce.inc")

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
		{tags remove "_lua_mi"}
		{delay 0.25
			{tags add "_lua_need_next_order"}
			{delay 10.1
				{tags remove "_lua_need_next_order"}
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
		{kill_delay "pervitin_timer"}

		{if tagged "ai_signaller"
			{clear_inventory}
			{tags remove "ai_signaller"}
		else tagged "radio_man"
       	 	{clear_inventory} 
       	 	{tags remove "radio_man"}
		}
		
		{tags remove "paratrooper_need_orders"}
		{tags remove "enhanced"}
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
			{able "select" 0}
		}
	}

	{on "check_ai_support_cmd_range"
		{if tagged "out_cmd_range"
			{if not tagged "support_out_of_range"
				{damage_report "ai_support_out_cmd_range" "human/ai_support_out_cmd_range"}
			}
			{tags add "support_out_of_range"}
		else tagged "in_cmd_range"
			{tags remove "support_out_of_range"}
		}
		{tags remove "in_cmd_range"}
		{tags remove "out_cmd_range"}
		{tags remove "cmd_range_check"}
		{tags remove "select_for_cmd_range_check"}
	}
	
	;// Wear-off of pervitin: report message, adjust health, clear the "enhanced" tag.
	(define "pervitin_end_ce"
		{damage_report "pervitin_action" "human/pervitin_%msg"}
		("human_health" c(%hp))
		{tags remove "enhanced"}
	)


	{on "pervitin_taken"
		{tags remove "will_take_drugs"}
		{if not tagged "enhanced"
			{delay 0.1
				{if rand 0.25
					{damage_report "pervitin_action" "human/take_pervitin_1"}
				else rand 0.25
					{damage_report "pervitin_action" "human/take_pervitin_2"}
				else rand 0.25
					{damage_report "pervitin_action" "human/take_pervitin_3"}
				else
					{damage_report "pervitin_action" "human/take_pervitin_4"}
				}
				{tags add "enhanced"}
				("human_health" c(-500))
			}

			{delay_ex 60 "pervitin_timer"
				{if not dead
					{if not user_control
						{if rand 0.3
							("pervitin_end_ce" msg(sober) hp(500))
						else rand 0.1
							("pervitin_end_ce" msg(sober) hp(400))
						else rand 0.1
							("pervitin_end_ce" msg(sober) hp(300))
						else
							("pervitin_end_ce" msg(overdose) hp(1000))
						}
					else
						{if rand 0.5
							("pervitin_end_ce" msg(sober) hp(500))
						else
							("pervitin_end_ce" msg(overdose) hp(1000))
						}
					}
				}
			}
		}
	}
}
