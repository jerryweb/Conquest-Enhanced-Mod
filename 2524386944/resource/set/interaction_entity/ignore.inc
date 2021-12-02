{"vehicle"
    {on spawn
	    {add_view	"marker_veterancy"			"marker_veterancy"			"turret" not_manual not_scenario}
	} 
	
	{on "ignore_infantry" 		;// UI button to toggle engine on/off
		{if operatable
			{if work "turret"
				{if work "body"
					{if not tagged "ignore_off"
						{if not "toggle_delay"
							{tags add "ignore_off"}
							{tags remove "ignore_on"}
							{set "backward" 1}
						}
					else not "toggle_delay"
						{tags add "ignore_on"}
						{tags remove "ignore_off"}
						{set "backward" 0}
					}
				}
			else
				{tags add "ignore_infantry_off"}	;// allows engine to be set to off state when damaged. Cancels auto engine start on repair
			}
		}
		{set "toggle_delay" 1}			;// stops accidental double click of UI button
		{delay 1 {set "toggle_delay" 0}}
	}
	
	{on "reverse_toggle" 		;// UI button to toggle engine on/off
		{if operatable
			{if work "turret"
				{if work "body"
					{if not tagged "reverse_on"
						{if not "toggle_delay"
							{tags add "reverse_on"}
							{tags remove "reverse_off"}
							{set "backward" 0}
							{view start ally neutral "marker_veterancy"}
						}
					else not "toggle_delay"
						{tags add "reverse_off"}
						{tags remove "reverse_on"}
						{set "backward" 1}
						{view pause "marker_veterancy"}
					}
				}
			else
				{tags add "ignore_infantry_off"}	;// allows engine to be set to off state when damaged. Cancels auto engine start on repair
			}
		}
		{set "toggle_delay" 1}			;// stops accidental double click of UI button
		{delay 1 {set "toggle_delay" 0}}
	}
	{on "moving_to_point"
		{tags remove "idle"}
		{tags remove "attack_player"}
		{tags add "moving_to_point"}
		{delay 30
			{tags remove "moving_to_point"}
		}
		{delay 30
			{if not tagged "moving_to_point"
				{tags add "idle"}
			}
		}
	}
	{on "attack_player"
		{tags remove "idle"}
		{tags remove "moving_to_point"}
		{tags add "attack_player"}
		{delay 30
			{tags remove "attack_player"}
		}
		{delay 30
			{if not tagged "attack_player"
				{tags add "idle"}
			}
		}
	}
}

{"tank"
	{on "deploy_smoke"					;// UI button to deploy vehicle smoke screen
		{if operatable
			{if work "body"
				{call "smoke_screen"}
			}
		}
	}
	{on break						;// {on break} is for when components break
		{if not tagged "exploded"
			{start_sound "crush/medium/metal"}
			{if component "ammo"
				{call "ammo_break"}
			}
			{if component "body"
				{tags add "body_break"}
				{tags add "turret_stopped_by_body"}
				{spawn "tank_die_particle" "body"}
				{reset_manual_control}
				{able select 0}			;// disables vehicle from being crewed until body is repaired
				{unlink_trailer}
			else component "engine"
				{tags add "engine_brake"}
				{spawn "tank_die_particle" "engine"}
				{view start "smoke1_1"}
				{call "smoke_screen"}
				{set "smoke1" 1}
				{delay 30
					{view pause "smoke1_1"}
					{set "smoke1" 0}
				}
			else component "turret"
				{tags add "turret_brake"}
				{if not tagged "player_armor"
				    {if not tagged "smoked"
					    {call "smoke_screen"}
						{tags add "smoked"}
						{delay 30
							{tags remove "smoked"}
						}
					}
				}
			else component "mantlet"
				{tags add "mantlet_brake"}
				{if not tagged "player_armor"
				    {if not tagged "smoked"
					    {call "smoke_screen"}
						{tags add "smoked"}
						{delay 30
							{tags remove "smoked"}
						}
					}
				}
			else component "trackleft"
				{talk "broken_track"}
				{if not tagged "player_armor"
				    {if not tagged "smoked"
					    {call "smoke_screen"}
						{tags add "smoked"}
						{delay 30
							{tags remove "smoked"}
						}
					}
				}
			else component "trackright"
				{talk "broken_track"}
				{if not tagged "player_armor"
				    {if not tagged "smoked"
					    {call "smoke_screen"}
						{tags add "smoked"}
						{delay 30
							{tags remove "smoked"}
						}
					}
				}
			else component "fuel"

			else component "cut_part"
				;{if name "blast"} ;// does not work. Blast check comes to late code and is never triggered
				("cut_shield_part" args "shieldr1")
				("cut_shield_part" args "shieldr2")
				("cut_shield_part" args "shieldr3")
				("cut_shield_part" args "shieldr4")
				("cut_shield_part" args "shieldr5")
				("cut_shield_part" args "shieldr6")
				("cut_shield_part" args "shieldr7")
				("cut_shield_part" args "shieldr8")
				("cut_shield_part" args "shieldr9")

				("cut_shield_part" args "shieldl1")
				("cut_shield_part" args "shieldl2")
				("cut_shield_part" args "shieldl3")
				("cut_shield_part" args "shieldl4")
				("cut_shield_part" args "shieldl5")
				("cut_shield_part" args "shieldl6")
				("cut_shield_part" args "shieldl7")
				("cut_shield_part" args "shieldl8")
				("cut_shield_part" args "shieldl9")

				("cut_shield_part" args "shield1")
				("cut_shield_part" args "shield2")
				("cut_shield_part" args "shield3")
				("cut_shield_part" args "shield4")
				("cut_shield_part" args "shield5")
				("cut_shield_part" args "shield6")
				("cut_shield_part" args "shield7")
				("cut_shield_part" args "shield8")
				("cut_shield_part" args "shield9")

				("cut_shield_part" args "detail1")
				("cut_shield_part" args "detail2")
				("cut_shield_part" args "detail3")
				("cut_shield_part" args "detail4")
				("cut_shield_part" args "detail5")
				("cut_shield_part" args "detail6")
				("cut_shield_part" args "detail7")
				("cut_shield_part" args "detail8")
				("cut_shield_part" args "detail9")
				("cut_shield_part" args "detail10")
				("cut_shield_part" args "detail11")
				("cut_shield_part" args "detail12")
				("cut_shield_part" args "detail13")
				("cut_shield_part" args "detail14")
				("cut_shield_part" args "detail15")
				("cut_shield_part" args "detail16")
				("cut_shield_part" args "detail17")
				("cut_shield_part" args "detail18")
				("cut_shield_part" args "detail19")
				("cut_shield_part" args "detail20")

				("shed_shield_part" args "shieldw1")
				("shed_shield_part" args "shieldw2")
				("shed_shield_part" args "shieldw3")
				("shed_shield_part" args "shieldw4")
				("shed_shield_part" args "shieldw5")
				("shed_shield_part" args "shieldw6")
				("shed_shield_part" args "shieldw7")
				("shed_shield_part" args "shieldw8")
				("shed_shield_part" args "shieldw9")
			}
		}
	}
}

