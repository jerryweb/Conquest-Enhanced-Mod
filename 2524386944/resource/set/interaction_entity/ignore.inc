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

	{on "sandbag_heavy_flak"
		{delay 1
			{if operatable
				{if tagged "88mm_flak18"
					{call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.2
						{call "sandbag_ring_heap_curved"}
					else rand 0.4
						{call "sandbag_ring_framed_curved"}
					else rand 0.6
						{call "sandbag_ring_heap_straight"}
					else rand 0.8
						{call "sandbag_ring_framed_straight"}
					else rand 1
						{call "sandbag_ring_heap_straight_with_lane"}
					}
				else tagged "88mm_flak36"
					{call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.2
						{call "sandbag_ring_heap_curved"}
					else rand 0.4
						{call "sandbag_ring_framed_curved"}
					else rand 0.6
						{call "sandbag_ring_heap_straight"}
					else rand 0.8
						{call "sandbag_ring_framed_straight"}
					else rand 1
						{call "sandbag_ring_heap_straight_with_lane"}
					}
				else tagged "85mm_52k"
					{call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.2
						{call "sandbag_ring_heap_curved"}
					else rand 0.4
						{call "sandbag_ring_framed_curved"}
					else rand 0.6
						{call "sandbag_ring_heap_straight"}
					else rand 0.8
						{call "sandbag_ring_framed_straight"}
					else rand 1
						{call "sandbag_ring_heap_straight_with_lane"}
					}
				else tagged "120mm_sgrw42"
				    {call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.5
						{call "sandbag_ring_heap_curved_small"}
					else rand 1
						{call "sandbag_ring_frame_curved_small"}
					}
				else tagged "80mm_sgrw34"
				    {call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.5
						{call "sandbag_ring_heap_curved_small"}
					else rand 1
						{call "sandbag_ring_frame_curved_small"}
					}
				else tagged "120mm_pm38"
				    {call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.5
						{call "sandbag_ring_heap_curved_small"}
					else rand 1
						{call "sandbag_ring_frame_curved_small"}
					}
				else tagged "82mm_bm37"
				    {call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.5
						{call "sandbag_ring_heap_curved_small"}
					else rand 1
						{call "sandbag_ring_frame_curved_small"}
					}
				}	
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

{"tank"
    {on "hull_down"
	    {start_sound "vehicle/deploy/foxhole"}
		{call "deactivate_vehicle"}
		{if tagged "light_tank"
			{if operatable
				{delay 6
			   	    {spawn "sandbag_structured_straight2" offset 2 70 0}
					{spawn "sandbag_structured_straight2" offset 0 70 10}
					{spawn "sandbag_structured_straight2" offset 0 70 -10}
					{delay 2
						{spawn "sandbag_structured_straight2" offset 2 -70 0}
						{spawn "sandbag_structured_straight2" offset 0 -70 10}
						{spawn "sandbag_structured_straight2" offset 0 -70 -10}
						{delay 2
							{spawn "sandbag_structured_straight2" offset 55 70 0}
							{spawn "sandbag_structured_straight2" offset 55 70 10}
							{spawn "sandbag_structured_straight2" offset 55 70 -10}
							{delay 2
								{spawn "sandbag_structured_straight2" offset 55 -70 0}
								{spawn "sandbag_structured_straight2" offset 55 -70 10}
								{spawn "sandbag_structured_straight2" offset 55 -70 -10}
								{delay 2
									{spawn "sandbag_structured_straight2" offset -55 70 0}
									{spawn "sandbag_structured_straight2" offset -55 70 10}
									{spawn "sandbag_structured_straight2" offset -55 70 -10}
									{delay 2
										{spawn "sandbag_structured_straight2" offset -55 -70 0}
										{spawn "sandbag_structured_straight2" offset -55 -70 10}
										{spawn "sandbag_structured_straight2" offset -55 -70 -10}
										{delay 2
											{spawn "sandbag_structured_straight2" offset -55 -70 0}
											{spawn "sandbag_structured_straight2" offset -55 -70 10}
											{spawn "sandbag_structured_straight2" offset -55 -70 -10}
											{delay 2
												{spawn "sandbag_structured_straight" offset 70 2 0}
												{spawn "sandbag_structured_straight" offset 70 0 10}
												{spawn "sandbag_structured_straight" offset 70 0 -10}
												{delay 2
													{spawn "sandbag_structured_straight" offset -70 2 0}
													{spawn "sandbag_structured_straight" offset -70 0 10}
													{spawn "sandbag_structured_straight" offset -70 0 -10}
													{delay 2
														{spawn "sandbag_structured_straight" offset 70 55 0}
														{spawn "sandbag_structured_straight" offset 70 55 10}
														{spawn "sandbag_structured_straight" offset 70 55 -10}
														{delay 2
															{spawn "sandbag_structured_straight" offset -70 55 0}
															{spawn "sandbag_structured_straight" offset -70 55 10}
															{spawn "sandbag_structured_straight" offset -70 55 -10}
															{delay 2
																{spawn "sandbag_structured_straight" offset 70 -55 0}
																{spawn "sandbag_structured_straight" offset 70 -55 10}
																{spawn "sandbag_structured_straight" offset 70 -55 -10}
																{delay 2
																	{spawn "sandbag_structured_straight" offset -70 -55 0}
																	{spawn "sandbag_structured_straight" offset -70 -55 10}
																	{spawn "sandbag_structured_straight" offset -70 -55 -10}
																	{if rand 0.5
																	    {spawn "netting_square" "basis" x scale 1.3}
																	}
																	{call "activate_vehicle"}
																	{call "engine_on"}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}		
				}
			}
		else tagged "heavy_tank"
		    {delay 8
		   	    {spawn "sandbag_structured_straight2" offset 2 90 0}
				{spawn "sandbag_structured_straight2" offset 0 90 10}
				{spawn "sandbag_structured_straight2" offset 2 -90 0}
				{spawn "sandbag_structured_straight2" offset 0 -90 10}
				{delay 2
					{spawn "sandbag_structured_straight2" offset 75 90 0}
					{spawn "sandbag_structured_straight2" offset 75 90 10}
					{spawn "sandbag_structured_straight2" offset 75 -90 0}
					{spawn "sandbag_structured_straight2" offset 75 -90 10}
					{delay 2
						{spawn "sandbag_structured_straight2" offset -75 90 0}
						{spawn "sandbag_structured_straight2" offset -75 90 10}
						{spawn "sandbag_structured_straight2" offset -75 -90 0}
						{spawn "sandbag_structured_straight2" offset -75 -90 10}
						{delay 2
							{spawn "sandbag_structured_straight2" offset 2 90 0}
							{spawn "sandbag_structured_straight2" offset 0 90 20}
							{spawn "sandbag_structured_straight2" offset 2 -90 0}
							{spawn "sandbag_structured_straight2" offset 0 -90 20}
							{delay 2
								{spawn "sandbag_structured_straight2" offset 75 90 0}
								{spawn "sandbag_structured_straight2" offset 75 90 20}
								{spawn "sandbag_structured_straight2" offset 75 -90 0}
								{spawn "sandbag_structured_straight2" offset 75 -90 20}
								{delay 2
									{spawn "sandbag_structured_straight2" offset -75 90 0}
									{spawn "sandbag_structured_straight2" offset -75 90 10}
									{spawn "sandbag_structured_straight2" offset -75 -90 0}
									{spawn "sandbag_structured_straight2" offset -75 -90 20}
									{delay 2
										{spawn "sandbag_structured_straight" offset 90 2 0}
										{spawn "sandbag_structured_straight" offset 90 0 10}
										{spawn "sandbag_structured_straight" offset -90 2 0}
										{spawn "sandbag_structured_straight" offset -90 0 10}
										{delay 2
											{spawn "sandbag_structured_straight" offset 90 75 0}
											{spawn "sandbag_structured_straight" offset 90 75 10}
											{spawn "sandbag_structured_straight" offset -90 75 0}
											{spawn "sandbag_structured_straight" offset -90 75 10}
											{delay 2
												{spawn "sandbag_structured_straight" offset 90 -75 0}
												{spawn "sandbag_structured_straight" offset 90 -75 10}
												{spawn "sandbag_structured_straight" offset -90 -75 0}
												{spawn "sandbag_structured_straight" offset -90 -75 10}	
												{delay 2
													{spawn "sandbag_structured_straight" offset 90 2 0}
													{spawn "sandbag_structured_straight" offset 90 0 20}
													{spawn "sandbag_structured_straight" offset -90 2 0}
													{spawn "sandbag_structured_straight" offset -90 0 20}
													{delay 2
														{spawn "sandbag_structured_straight" offset 90 75 0}
														{spawn "sandbag_structured_straight" offset 90 75 20}
														{spawn "sandbag_structured_straight" offset -90 75 0}
														{spawn "sandbag_structured_straight" offset -90 75 20}
														{delay 2
															{spawn "sandbag_structured_straight" offset 90 -75 0}
															{spawn "sandbag_structured_straight" offset 90 -75 20}
															{spawn "sandbag_structured_straight" offset -90 -75 0}
															{spawn "sandbag_structured_straight" offset -90 -75 20}
															{if rand 0.5
															    {spawn "netting_square" "basis" x scale 1.3}
															}
															{call "activate_vehicle"}
															{call "engine_on"}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
		    }
		else "spg"
            {delay 8
					{spawn "sandbag_structured_straight2" offset 2 90 0}
					{spawn "sandbag_structured_straight2" offset 0 90 10}
					{spawn "sandbag_structured_straight2" offset 2 -90 0}
					{spawn "sandbag_structured_straight2" offset 0 -90 10}
					{delay 2
						{spawn "sandbag_structured_straight2" offset 75 90 0}
						{spawn "sandbag_structured_straight2" offset 75 90 10}
						{spawn "sandbag_structured_straight2" offset 75 -90 0}
						{spawn "sandbag_structured_straight2" offset 75 -90 10}
						{delay 2
							{spawn "sandbag_structured_straight2" offset -75 90 0}
							{spawn "sandbag_structured_straight2" offset -75 90 10}
							{spawn "sandbag_structured_straight2" offset -75 -90 0}
							{spawn "sandbag_structured_straight2" offset -75 -90 10}
							{delay 2
								{spawn "sandbag_structured_straight2" offset 2 90 0}
								{spawn "sandbag_structured_straight2" offset 0 90 12}
								{spawn "sandbag_structured_straight2" offset 2 -90 0}
								{spawn "sandbag_structured_straight2" offset 0 -90 12}
								{delay 2
									{spawn "sandbag_structured_straight2" offset 75 90 0}
									{spawn "sandbag_structured_straight2" offset 75 90 12}
									{spawn "sandbag_structured_straight2" offset 75 -90 0}
									{spawn "sandbag_structured_straight2" offset 75 -90 12}
									{delay 2
										{spawn "sandbag_structured_straight2" offset -75 90 0}
										{spawn "sandbag_structured_straight2" offset -75 90 10}
										{spawn "sandbag_structured_straight2" offset -75 -90 0}
										{spawn "sandbag_structured_straight2" offset -75 -90 12}
										{delay 2
											{spawn "sandbag_structured_straight" offset 90 2 0}
											{spawn "sandbag_structured_straight" offset 90 0 10}
											{spawn "sandbag_structured_straight" offset -90 2 0}
											{spawn "sandbag_structured_straight" offset -90 0 10}
											{delay 2
												{spawn "sandbag_structured_straight" offset 90 75 0}
												{spawn "sandbag_structured_straight" offset 90 75 10}
												{spawn "sandbag_structured_straight" offset -90 75 0}
												{spawn "sandbag_structured_straight" offset -90 75 10}
												{delay 2
													{spawn "sandbag_structured_straight" offset 90 -75 0}
													{spawn "sandbag_structured_straight" offset 90 -75 10}
													{spawn "sandbag_structured_straight" offset -90 -75 0}
													{spawn "sandbag_structured_straight" offset -90 -75 10}
													{delay 2
														{spawn "sandbag_structured_straight" offset 90 2 0}
														{spawn "sandbag_structured_straight" offset 90 0 12}
														{spawn "sandbag_structured_straight" offset -90 2 0}
														{spawn "sandbag_structured_straight" offset -90 0 12}
														{delay 2
															{spawn "sandbag_structured_straight" offset 90 75 0}
															{spawn "sandbag_structured_straight" offset 90 75 12}
															{spawn "sandbag_structured_straight" offset -90 75 0}
															{spawn "sandbag_structured_straight" offset -90 75 12}
															{delay 2
																{spawn "sandbag_structured_straight" offset 90 -75 0}
																{spawn "sandbag_structured_straight" offset 90 -75 12}
																{spawn "sandbag_structured_straight" offset -90 -75 0}
																{spawn "sandbag_structured_straight" offset -90 -75 12}
																{if rand 0.5
																    {spawn "netting_square" "basis" x scale 1.3}
																}
																{call "activate_vehicle"}
																{call "engine_on"}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}

		else 
			{delay 8
		   	    {spawn "sandbag_structured_straight2" offset 2 90 0}
				{spawn "sandbag_structured_straight2" offset 0 90 10}
				{spawn "sandbag_structured_straight2" offset 2 -90 0}
				{spawn "sandbag_structured_straight2" offset 0 -90 10}
				{delay 2
					{spawn "sandbag_structured_straight2" offset 75 90 0}
					{spawn "sandbag_structured_straight2" offset 75 90 10}
					{spawn "sandbag_structured_straight2" offset 75 -90 0}
					{spawn "sandbag_structured_straight2" offset 75 -90 10}
					{delay 2
						{spawn "sandbag_structured_straight2" offset -75 90 0}
						{spawn "sandbag_structured_straight2" offset -75 90 10}
						{spawn "sandbag_structured_straight2" offset -75 -90 0}
						{spawn "sandbag_structured_straight2" offset -75 -90 10}
						{delay 2
							{spawn "sandbag_structured_straight2" offset 2 90 0}
							{spawn "sandbag_structured_straight2" offset 0 90 15}
							{spawn "sandbag_structured_straight2" offset 2 -90 0}
							{spawn "sandbag_structured_straight2" offset 0 -90 15}
							{delay 2
								{spawn "sandbag_structured_straight2" offset 75 90 0}
								{spawn "sandbag_structured_straight2" offset 75 90 15}
								{spawn "sandbag_structured_straight2" offset 75 -90 0}
								{spawn "sandbag_structured_straight2" offset 75 -90 15}
								{delay 2
									{spawn "sandbag_structured_straight2" offset -75 90 0}
									{spawn "sandbag_structured_straight2" offset -75 90 10}
									{spawn "sandbag_structured_straight2" offset -75 -90 0}
									{spawn "sandbag_structured_straight2" offset -75 -90 15}
									{delay 2
										{spawn "sandbag_structured_straight" offset 90 2 0}
										{spawn "sandbag_structured_straight" offset 90 0 10}
										{spawn "sandbag_structured_straight" offset -90 2 0}
										{spawn "sandbag_structured_straight" offset -90 0 10}
										{delay 2
											{spawn "sandbag_structured_straight" offset 90 75 0}
											{spawn "sandbag_structured_straight" offset 90 75 10}
											{spawn "sandbag_structured_straight" offset -90 75 0}
											{spawn "sandbag_structured_straight" offset -90 75 10}
											{delay 2
												{spawn "sandbag_structured_straight" offset 90 -75 0}
												{spawn "sandbag_structured_straight" offset 90 -75 10}
												{spawn "sandbag_structured_straight" offset -90 -75 0}
												{spawn "sandbag_structured_straight" offset -90 -75 10}
												{delay 2
													{spawn "sandbag_structured_straight" offset 90 2 0}
													{spawn "sandbag_structured_straight" offset 90 0 15}
													{spawn "sandbag_structured_straight" offset -90 2 0}
													{spawn "sandbag_structured_straight" offset -90 0 15}
													{delay 2
														{spawn "sandbag_structured_straight" offset 90 75 0}
														{spawn "sandbag_structured_straight" offset 90 75 15}
														{spawn "sandbag_structured_straight" offset -90 75 0}
														{spawn "sandbag_structured_straight" offset -90 75 15}
														{delay 2
															{spawn "sandbag_structured_straight" offset 90 -75 0}
															{spawn "sandbag_structured_straight" offset 90 -75 15}
															{spawn "sandbag_structured_straight" offset -90 -75 0}
															{spawn "sandbag_structured_straight" offset -90 -75 15}
															{if rand 0.5
															    {spawn "netting_square" "basis" x scale 1.3}
															}
															{call "activate_vehicle"}
															{call "engine_on"}
														}
													}
												}		
											}
										}
									}
								}
							}
						}
					}
				}	
			}
	    }
    }
	
		
	{on "reload"
		{call "reload_delay"}
		{if tagged "ai_armor"
		    {if not tagged "player_armor"
		        {tags add "tankaction"}
		        {delay 120
		            {tags remove "tankaction"}
				}
			}
		}
		(define "reload_delay"
			{if tagged "gun_fired"
				{delay %0 ;4.5
					{tags remove "gun_fired"}
					{ani_play "shell_eject" -1.0}
					{ani_play "shell_hatch" -1.0}
				}
			else
				{delay %1 ;0.5
					{ani_play "shell_eject" 1.0}
				}
				{delay %2 ;5
					{ani_play "shell_eject" -1.0}
				}
			}
		)
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
				{tags add "immobile"}
				{call "abandoncheck"}
				{spawn "tank_die_particle" "engine"}
				{view start "smoke1_1"}
				{set "smoke1" 1}
				{delay 30
					{view pause "smoke1_1"}
					{set "smoke1" 0}
				}
			else component "turret"
				{tags add "turret_brake"}
				
			else component "mantlet"
				{tags add "mantlet_brake"}
			else component "trackleft"
				{talk "broken_track"}
				{call "abandoncheck"}
				{tags add "immobile"}
			else component "trackright"
				{talk "broken_track"}
				{tags add "immobile"}
				{call "abandoncheck"}
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
	
	{on "abandoncheck"
	    {if not tagged "player_armor" 
		    {delay 120
			    {if not tagged "tankaction"
					{if tagged "immobile"
					    {if not tagged "_abandoned"
							{if not tagged "destroyed"
							    {if not tagged "player_armor"
								    {if operatable
										{call "emit_crew"}
					               		{delay 5
					                 	    {call "_explosion"}
										}
									}
								}
							}
					    }
				    }
			    }
		    }
			{delay 180
			    {if not tagged "tankaction"
					{if tagged "immobile"
					    {if not tagged "_abandoned"
							{if not tagged "destroyed"
							    {if not tagged "player_armor"
								    {if operatable
										{call "emit_crew"}
					               		{delay 5
					                 	    {call "_explosion"}
										}
									}
								}
							}
					    }
				    }
			    }
		    }
			{delay 240
			    {if not tagged "tankaction"
					{if tagged "immobile"
					    {if not tagged "_abandoned"
							{if not tagged "destroyed"
							    {if not tagged "player_armor"
								    {if operatable
										{call "emit_crew"}
					               		{delay 5
					                 	    {call "_explosion"}
										}
									}
								}
							}
					    }
				    }
			    }
		    }
			{delay 300
			    {if not tagged "tankaction"
					{if tagged "immobile"
					    {if not tagged "_abandoned"
							{if not tagged "destroyed"
							    {if not tagged "player_armor"
								    {if operatable
										{call "emit_crew"}
					               		{delay 5
					                 	    {call "_explosion"}
										}
									}
								}
							}
					    }
				    }
			    }
		    }
			{delay 360
			    {if not tagged "tankaction"
					{if tagged "immobile"
					    {if not tagged "_abandoned"
							{if not tagged "destroyed"
							    {if not tagged "player_armor"
								    {if operatable
										{call "emit_crew"}
					               		{delay 5
					                 	    {call "_explosion"}
										}
									}
								}
							}
					    }
				    }
			    }
		    }
		}
	}
	
	{on repair
		{if component "turret"
			{call "update_turret"}
			{tags remove "turret_brake"}
		else component "body"
			{view pause "smoke1"}
			{call "update_turret"}
			{tags remove "turret_stopped_by_body"}
			{tags remove "body_break"}
			{able "select" 1}
			{call "activate_vehicle"}
			{tags remove "death_counter_1"}
			{tags remove "death_counter_2"}
			{tags remove "death_counter_3"}
			{tags remove "death_counter_4"}
			{tags remove "death_counter_start"}
		else component "engine"
			{tags remove "engine_brake"}
			{view pause "smoke1_1"}
			{tags remove "immobile"}
		else component "mantlet"
			{tags remove "mantlet_brake"}
			{call "update_mantlet"}
		else component "trackleft"
			{tags remove "immobile"}
		else component "trackright"
			{tags remove "immobile"}
		}
	}
}






