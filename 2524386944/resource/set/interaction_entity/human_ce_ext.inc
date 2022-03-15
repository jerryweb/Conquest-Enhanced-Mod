{"human"		
	
	{on "medic_carry" 		;// UI button to toggle engine on/off
		{if operatable
			{if not tagged "1" 
				{if tagged "default" 
				    {tags add "carry"}
				    {tags remove "default"}
				    {view start ally neutral "marker_personage"}
					{view pause "marker_healing"}
				else tagged "carry_off"
				    {tags add "default"}
					{tags remove "carry_off"}
				    {view pause "marker_healing"}
			    else 
				    {tags add "carry_off"}
					{tags remove "carry"}
					{tags remove "default"}
					{view start ally neutral "marker_healing"}
					{view pause "marker_personage"}
				}
			}
		}
	}
	
	{on "tag_medic_reviving"
		{tags add "reviving"}
		{delay 10 
			{if tagged "reviving"
				{tags remove "reviving"}
			}
		}
	}

	{on "stop_healing"
		{if not tagged "carry_off"
		    {view pause "marker_healing"}
		}
		{tags remove "reviving"}
	}

	{on "medic_get_body"
		{tags add "picking_up_body"}
		{delay 15
			{tags remove "picking_up_body"}
		}
	}
	
	{on "stop_personage"
		{view pause "marker_personage"}
		{view pause "marker_healing"}
	}
	
	{on "go_resupply" 		;// UI button to toggle engine on/off
		{if operatable
			{if not tagged "resupplying" 
				{tags add "resupplying"}
				{tags remove "noresupply"}
				{view pause "marker_ammo_out"}
				{view start ally neutral "start_blinded"}
				{delay 2.5
			        {view pause "start_blinded"}
				}
				else 
				{tags add "noresupply"}
				{tags remove "resupplying"}
				{view pause "marker_ammo_refill"}
				{view start ally neutral "marker_ammo_out"}
				{delay 2.5
			        {view pause "marker_ammo_out"}
				}
			}
		}
	}
	
	{on "start_ammo_out"
		{view start ally neutral "marker_ammo_out"}
		{tags add "noammo"}
	}

	{on "stop_ammo_out"
		{view pause "marker_ammo_out"}
		{tags add "noammo"}
	}
	
	{on "start_ammo_refill"
		{view start ally neutral "marker_ammo_refill"}
		{tags remove "noammo"}
		{delay 2.5
			{view pause "marker_ammo_refill"}
			{tags remove "noammo"}
		}
	}

	{on ground_hit
		{if linked "paratrooper_attach"
			{tags remove "can_die"}	
			{unlink}						;// kicks human out of parachute when reaching ground
			{set "not_knocked" 1}			;// helps stops {knock_down} call when thrown off from plane
			{delay 1.0						;// stops sliding after landing on ground. forces soldier to ground
				{physics_work 0}
				{delay 0
					{physics_work 1}
					{throw_off up 0.5 0.2 forward 1 0.5}
				}
			}
			{delay 1.0
				{if rand 0.3  
					{tags add "attacking_radio"}
				else rand 0.3
					{tags add "attacking_arty"}
				else
					{tags add "freeroam"}
				}
				{tags add "ai_inf"}
				{tags remove "eject"}
				{tags remove "deployed"}
				{tags remove "noname23"}
			}
		else tagged "can_die"
			{call "die"}
			{kill_delay "parachute"}
			{tags remove "can_die"}
			{tags remove "eject"}
		else
			{if min_speed 10
				{spawn "blood_medium" "basis" x}	;// Fall and hit the ground.
				{spawn "blood"}						;// blood splatter ground texture
			}
		}
	}
	
	{on board out 							;// exiting a vehicle
		{if linked "sdkfz251c"
			{if not user_control
				{if not tagged "player"
				    {delay 0.01
					    {tags add "freeroam"}
					    {tags add "ai_inf"}
				    }
				}
			}
		else linked "blitz3_6"
			{if not user_control
				{if not tagged "player"
				    {delay 0.01
					    {tags add "freeroam"}
					    {tags add "ai_inf"}
				    }
				}
			}
		else linked "m3halftrack_fr"
			{if not user_control
				{if not tagged "player"
				    {delay 0.01
					    {tags add "freeroam"}
					    {tags add "ai_inf"}
				    }
				}
			}
		else linked "m3halftrack_eng"
			{if not user_control
				{if not tagged "player"
				    {delay 0.01
					    {tags add "freeroam"}
					    {tags add "ai_inf"}
				    }
				}
			}
		else linked "m3_usa"
			{if not user_control
				{if not tagged "player"
				    {delay 0.01
					    {tags add "freeroam"}
					    {tags add "ai_inf"}
				    }
				}
			}
		else linked "as37"
			{if not user_control
				{if not tagged "player"
				    {delay 0.01
					    {tags add "freeroam"}
					    {tags add "ai_inf"}
				    }
				}
			}
		else linked "type1_ho-ki_mg"
			{if not user_control
				{if not tagged "player"
				    {delay 0.01
					    {tags add "freeroam"}
					    {tags add "ai_inf"}
				    }
				}
			}
		else linked "type1_ho-ki"
			{if not user_control
				{if not tagged "player"
				    {delay 0.01
					    {tags add "freeroam"}
					    {tags add "ai_inf"}
				    }
				}
			}	
		else linked "m3halftrack_pol"
			{if not user_control
				{if not tagged "player"
				    {delay 0.01
					    {tags add "freeroam"}
					    {tags add "ai_inf"}
				    }
				}
			}																			
		else linked "airborne"
			{delay 0.01
				{call "eject"}
				{volumes disable contact}			;// stops humans from "colliding" with plane when ejecting.
				{volumes enable bullet}
				{delay 1 {volumes enable contact blast}}
			}
		else
			{tags add "noammo23"}
		}
	}

	{on "eject" overload
		{tags add "can_die"}
		{if not tagged "player"
			{tags add "deployed"}
		}	
		{tags remove "on_plane_1"}
		{tags remove "on_plane_2"}
		{tags remove "on_plane_3"}
		{tags remove "on_plane_4"}
		{tags remove "on_plane_5"}
		{tags remove "on_plane_6"}
		{tags remove "on_plane_7"}
		{tags remove "on_plane_8"}
		{tags remove "on_plane_9"}
		{tags remove "on_plane_10"}
		{tags remove "on_plane_11"}
		{tags remove "on_plane_12"}
		{tags remove "para_ready"}
		{tags remove "player_para_ready"}
		{tags remove "player_on_plane"}
		{call "pull_chute"}		
	}

	{on "pull_chute"
		{if altitude 1
			{throw_off up 2 forward 0.01}
			{if altitude 56
				{delay 3.0 "parachute"
					{tags add "eject"}	
					{spawn "paratrooper_attach" offset 205 -10 -534}
				}
			else altitude 51
				{delay 2.7 "parachute"
					{tags add "eject"}	
					{spawn "paratrooper_attach" offset 205 -10 -534}
				}
			else altitude 48 		
				{delay 2.8 0.1 "parachute"
					{tags add "eject"}	
					{spawn "paratrooper_attach" offset 205 -10 -534}
				}
			else altitude 43 		
				{delay 2.4 0.1 "parachute"
					{tags add "eject"}	
					{spawn "paratrooper_attach" offset 205 -10 -534}
				}
			else altitude 38 		
				{delay 2.2 0.1 "parachute"
					{tags add "eject"}	
					{spawn "paratrooper_attach" offset 205 -10 -534}
				}
			else altitude 33 		
				{delay 2.0 0.1 "parachute"
					{tags add "eject"}	
					{spawn "paratrooper_attach" offset 205 -10 -534}
				}
			else altitude 28 		
				{delay 1.2 0.1 "parachute"
					{tags add "eject"}	
					{spawn "paratrooper_attach" offset 205 -10 -534}
				}
			else altitude 23 		
				{delay 1.0 0.1 "parachute"
					{tags add "eject"}	
					{spawn "paratrooper_attach" offset 205 -10 -534}
				}
			else altitude 4 		
				{delay 0.4 0.1 "parachute"
					{tags add "eject"}	
					{spawn "paratrooper_attach" offset 205 -10 -534}
				}	
		else
			;{tags remove "can_die"}
			{throw_on_ground}
			}
		}
	}


	{on "tag_paratroopers_on_plane" 
		{if not tagged "on_plane_1"
			{if not tagged "on_plane_2"
				{if not tagged "on_plane_3"
					{if not tagged "on_plane_4"
						{if not tagged "on_plane_5"
							{if not tagged "on_plane_6"
								{if not tagged "on_plane_7"
									{if not tagged "on_plane_8"
										{if not tagged "on_plane_9"
											{if not tagged "on_plane_10"
												{if not tagged "on_plane_11"
													{if not tagged "on_plane_12"
														{if linked "bf110_para_plane"
															{tags add "para_need_tag"}
															{delay 45
																{tags remove "para_need_tag"}
															}
														else linked "il2_mod42_para_plane"
															{tags add "para_need_tag"}
															{delay 45
																{tags remove "para_need_tag"}
															}
														else linked "b25_para_plane"
															{tags add "para_need_tag"}
															{delay 45
																{tags remove "para_need_tag"}
															}
														else linked "beaufighter_para_plane"
															{tags add "para_need_tag"}
															{delay 45
																{tags remove "para_need_tag"}
															}	
														else linked "j2m_raiden_para_plane"
															{tags add "para_need_tag"}
															{delay 45
																{tags remove "para_need_tag"}
															}
														else linked "sm79_para_plane"
															{tags add "para_need_tag"}
															{delay 45
																{tags remove "para_need_tag"}
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
	}	
	
	{on "fortification"
	    {if rand 0.08
		    {spawn "soldier_foxhole" "basis" x}
		else rand 0.08 
		    {spawn "mg_foxhole" "basis" x}
		else rand 0.08 
		    {spawn "sandbag_heap_curved" "basis" x}
		else rand 0.08 
		    {spawn "sandbag_heap_straight" "basis" x}
		else rand 0.08 
		    {spawn "sandbag_structured_curved" "basis" x}
		else rand 0.08 
		    {spawn "sandbag_structured_curved_big" "basis" x}
		else rand 0.08 
		    {spawn "sandbag_structured_straight" "basis" x}
		else rand 0.08 
		    {spawn "sandbag_watchtower" "basis" x}
		else rand 0.08 
		    {spawn "sandbag_curved" "basis" x}
		else rand 0.08 
		    {spawn "sandbag_curved_heap" "basis" x}
		else rand 0.08 
		    {spawn "sandbag_straight" "basis" x}
		else 
		    {spawn "sandbag_straight_heap" "basis" x}
		}
	}
}

{"antitank_1"
    {on spawn
	    {tags add "automatic_weaponary"}
	}
}


{"artillery_aim2"
    {on spawn
	    {tags add "automatic_weaponary"}
		{delay 1
			{if rand 0.08
			    {spawn "soldier_foxhole" "basis" x}
			else rand 0.08 
			    {spawn "mg_foxhole" "basis" x}
			else rand 0.08 
		    	{spawn "sandbag_heap_curved" "basis" x}
			else rand 0.08 
			    {spawn "sandbag_heap_straight" "basis" x}
			else rand 0.08 
			    {spawn "sandbag_structured_curved" "basis" x}
			else rand 0.08 
			    {spawn "sandbag_structured_curved_big" "basis" x}
			else rand 0.08 
			    {spawn "sandbag_structured_straight" "basis" x}
			else rand 0.08 
			    {spawn "sandbag_watchtower" "basis" x}
			else rand 0.08 
			    {spawn "sandbag_curved" "basis" x}
			else rand 0.08 
			    {spawn "sandbag_curved_heap" "basis" x}
			else rand 0.08 
			    {spawn "sandbag_straight" "basis" x}
			else 
			    {spawn "sandbag_straight_heap" "basis" x}
			}
		}
	}
}

{"artillery_aim3"
    {on spawn
	    {tags add "tank_cover"}
		{delay 1
			{spawn "trench_modular"  offset 40 40 40}
			{spawn "trench_modular"  offset 0 0 0}
			{spawn "trench_modular"  offset 0 40 40}
			{spawn "trench_modular"  offset 40 40 0}
			{spawn "trench_modular"  offset 40 0 40}
		}
	}
}