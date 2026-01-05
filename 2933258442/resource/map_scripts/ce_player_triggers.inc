;============ AUTO RESUPPLY SCRIPTS========================================
			{"player_logic/auto_resupply"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.near"
							{units
								{source advanced}
								{group
									{select
										{tag
											{tag ammo_out}
										}
									}
									{include
										{tag
											{tag _user}
										}
										{state
											{state user_control}
										}
										{prop
											{prop human}
										}
										{tag
											{tag auto_resupply}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{tag
											{tag ignore_auto_resupply}
										}
									}
								}
								{amount 1
								}
							}
							{near_to
								{source advanced}
								{group
									{select
										{tag
											{tag supplies}
										}
									}
									{include
										{zone
											{zone "gamezone"}
										}
									}
									{exclude
										{tag
											{tag hidden}
										}
									}
								}
								{amount 1
								}
							}
							{distance 120}
						}
						{"2.trigger"
							{name "player_logic/send_men_with_no_ammo_to_resupply"}
						}
					}
				}
				{actions
					{"delay"
						{time 0.5}
					}
					{"call"
						{function "send_auto_resupply"}
						{context
							{specified}
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag ammo_out}
										}
									}
									{include
										{tag
											{tag _user}
										}
										{state
											{state user_control}
										}
										{prop
											{prop human}
										}
										{tag
											{tag auto_resupply}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{tag
											{tag ignore_auto_resupply}
										}
									}
								}
								{sort
									{type entity}
									{entity
										{source advanced}
										{group
											{select
												{tag
													{tag supplies}
												}
											}
											{include
												{zone
													{zone "gamezone"}
												}
											}
											{exclude
												{tag
													{tag hidden}
												}
											}
										}
									}
								}
								{amount 1
								}
							}
						}
					}
					{"delay"
						{time 2}
					}
					{"trigger"
						{name "player_logic/auto_resupply"}
					}
				}
			}
			{"player_logic/send_men_with_no_ammo_to_resupply"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag resupply_pointer}
										}
									}
								}
							}
						}
						{"2.trigger"
							{name "player_logic/auto_resupply"}
						}
					}
				}
				{actions
					{"delay"
						{time 0.5}
					}
					{"switch"
						{"case"
							{condition
								{type rand}
								{value 0.33}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag _user}
									{type human}
									{state operatable}
								}
								{text "mission/multi/request_supply_drop_1"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.33}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag _user}
									{type human}
									{state operatable}
								}
								{text "mission/multi/request_supply_drop_2"}
							}
						}
						{"default"
							{"talk"
								{selector
									{amount 1
									}
									{tag _user}
									{type human}
									{state operatable}
								}
								{text "mission/multi/request_supply_drop_3"}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"effect"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag ammo_out}
									}
								}
								{include
									{tag
										{tag _user}
									}
									{state
										{state user_control}
									}
									{prop
										{prop human}
									}
								}
								{exclude
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
									{state
										{state linked}
									}
									{tag
										{tag ignore_auto_resupply}
									}
								}
							}
							{sort
								{type entity}
								{entity
									{source advanced}
									{group
										{select
											{tag
												{tag supplies}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
										}
										{exclude
											{tag
												{tag hidden}
											}
											{state
												{state dead}
											}
										}
									}
								}
							}
							{amount 5
							}
						}
						{effect set_auto_resupply}
					}
					{"delay"
						{time 1}
					}
					{"loop" 5
						{"call"
							{function "send_auto_resupply"}
							{context
								{specified}
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag ammo_out}
											}
										}
										{include
											{tag
												{tag _user}
											}
											{state
												{state user_control}
											}
											{prop
												{prop human}
											}
											{tag
												{tag auto_resupply}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{state
												{state linked}
											}
											{tag
												{tag ignore_auto_resupply}
											}
										}
									}
									{sort
										{type entity}
										{entity
											{source advanced}
											{group
												{select
													{tag
														{tag supplies}
													}
												}
												{include
													{zone
														{zone "gamezone"}
													}
												}
												{exclude
													{tag
														{tag hidden}
													}
													{state
														{state dead}
													}
												}
											}
										}
									}
									{amount 1
									}
								}
							}
						}
						{"delay"
							{time 1.5}
						}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "player_logic/send_men_with_no_ammo_to_resupply"}
					}
				}
			}


;============ Teleport ==========
           {"player_scripts/move_player_spawn"
				{condition
					{expression "1 & 2 & !3 & 4"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{zone
											{zone "gamezone"}
										}
									}
									{include
										{state
											{state operatable}
										}
										{state
											{state user_control}
										}
									}
									{exclude
										{state
											{state inactive}
										}
										{state
											{state dead}
										}
										{state
											{state linked}
										}
									}
								}
							}
						}
						{"2.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 1}
						}
						{"3.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
										}
									}
									{include
										{state
											{state operatable}
										}
										{zone
											{zone "gamezone"}
										}
									}
									{exclude
										{state
											{state user_control}
										}
										{state
											{state inactive}
										}
										{state
											{state dead}
										}
										{state
											{state linked}
										}
									}
								}
							}
						}
						{"4.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag pointer_defend}
										}
									}
									{exclude
										{state
											{state inactive}
										}
									}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"talk"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _user}
									}
								}
								{include
									{prop
										{prop human}
									}
								}
								{exclude
									{state
										{state dead}
									}
								}
							}
							{amount 1
							}
						}
						{text "mission/multi/teleporting_player_defense_units"}
					}
					{"delay"
						{time 1}
					}
					{"actor_to_waypoint"
						{selector
							{source advanced}
							{group
								{select
									{zone
										{zone "gamezone"}
									}
								}
								{include
									{state
										{state user_control}
									}
								}
								{exclude
									{state
										{state inactive}
									}
									{state
										{state dead}
									}
								}
							}
							{group
								{select
									{tag
										{tag _user}
									}
								}
								{exclude
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
								}
							}
						}
						{waypoint "6666"}
						{approach "safe teleport & rotate"}
					}
				}
			}
			
			
;============ DEFENSE START SCRIPTS ==========
			{"player_logic/inform_defense_end"
				{condition
					{terms
						{"1.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 1}
						}
					}
				}
				{actions
					{"delay"
						{time 1800}
					}
					{"loop" 8
						{"talk"
							{selector
								{amount 1
								}
								{tag _user}
								{state "not dead"}
							}
							{text "mission/multi/pointmessage"}
						}
						{"delay"
							{time 200}
						}
					}
				}
			}
			{"player_logic/inform_early_attack_option"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.entities"
							{selector
								{amount 1
								}
								{tag _user}
								{zone "gamezone"}
								{type human}
								{state "not dead"}
							}
						}
						{"2.entities"
							{selector
								{tag defense_mission_started}
							}
							{count
								{op "=="}
								{value 0}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 300}
					}
					{"if"
						{condition
							{type entities}
							{selector
								{tag defense_mission_started}
							}
							{count
								{op "<<"}
								{value 0}
							}
						}
						{"talk"
							{selector
								{amount 1
								}
								{tag _user}
								{state "not dead"}
							}
							{text "mission/multi/defense_start_early_option"}
						}
					}
				}
			}
			{"player_logic/start_defense_early"
				{condition
					{expression "1 & 2 & !3"}
					{terms
						{"1.entities"
							{selector
								{tag start_defense}
							}
						}
						{"2.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 1}
						}
						{"3.entities"
							{selector
								{source advanced}
								{group
									{select
										{zone
											{zone "gamezone"}
										}
									}
									{include
										{tag
											{tag _bot}
										}
										{prop
											{prop human}
										}
										{state
											{state operatable}
										}
									}
									{exclude
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{tag
											{tag _user}
										}
									}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.5}
					}
					{"talk"
						{selector
							{amount 1
							}
							{zone "gamezone"}
							{type human}
							{state operatable}
						}
						{text "mission/multi/start_player_defense_ask"}
					}
					{"timer"
						{time 12}
						{title "mission/multi/defense_started_timer"}
					}
					{"delay"
						{time 12}
					}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{tag start_defense}
								}
							}
							{"entity_state"
								{selector
									{tag scene_variable}
								}
								{tag_add _lua_start_defense_mission}
							}
							{"talk"
								{selector
									{amount 1
									}
									{zone "gamezone"}
									{type human}
									{state operatable}
								}
								{text "mission/multi/start_player_defense_confirm"}
							}
							{"delay"
								{time 60}
							}
							{"entity_state"
								{selector
									{tag scene_variable}
								}
								{tag_add defense_mission_started}
								{tag_remove _lua_start_defense_mission}
							}
						}
						{"default"
							{"trigger"
								{name "player_logic/start_defense_early"}
							}
						}
					}
				}
			}			

			{"player_scripts/check_officer_cheese"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag officer}
										}
									}
									{include
										{prop
											{prop human}
										}
										{state
											{state "operatable user_control"}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{tag
											{tag traitor}
										}
										{tag
											{tag _bleedout_}
										}
									}
								}
							}
							{count
								{op ">"}
								{value 5}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"talk"
						{selector
							{amount 1
							}
							{tag officer}
							{zone "gamezone"}
							{type human}
							{state "not dead"}
						}
						{text "mission/multi/player_ac_000warning"}
					}
					{"sound"
						{name "world/alarm/alarm"}
						{waypoint "1"}
					}
					{"delay"
						{time 5}
					}
					{"switch"
						{"case"
							{condition
								{type rand}
								{value 0.714}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag officer}
									{zone "gamezone"}
									{type human}
									{state "not dead"}
								}
								{text "mission/multi/player_ac_001"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.714}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag officer}
									{zone "gamezone"}
									{type human}
									{state "not dead"}
								}
								{text "mission/multi/player_ac_002"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.714}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag officer}
									{zone "gamezone"}
									{type human}
									{state "not dead"}
								}
								{text "mission/multi/player_ac_003"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.714}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag officer}
									{zone "gamezone"}
									{type human}
									{state "not dead"}
								}
								{text "mission/multi/player_ac_004"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.714}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag officer}
									{zone "gamezone"}
									{type human}
									{state "not dead"}
								}
								{text "mission/multi/player_ac_005"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.714}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag officer}
									{zone "gamezone"}
									{type human}
									{state "not dead"}
								}
								{text "mission/multi/player_ac_006"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.714}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag officer}
									{zone "gamezone"}
									{type human}
									{state "not dead"}
								}
								{text "mission/multi/player_ac_007"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.714}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag officer}
									{zone "gamezone"}
									{type human}
									{state "not dead"}
								}
								{text "mission/multi/player_ac_008"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.714}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag officer}
									{zone "gamezone"}
									{type human}
									{state "not dead"}
								}
								{text "mission/multi/player_ac_009"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.714}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag officer}
									{zone "gamezone"}
									{type human}
									{state "not dead"}
								}
								{text "mission/multi/player_ac_010"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.714}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag officer}
									{zone "gamezone"}
									{type human}
									{state "not dead"}
								}
								{text "mission/multi/player_ac_011"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.714}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag officer}
									{zone "gamezone"}
									{type human}
									{state "not dead"}
								}
								{text "mission/multi/player_ac_012"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.714}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag officer}
									{zone "gamezone"}
									{type human}
									{state "not dead"}
								}
								{text "mission/multi/player_ac_013"}
							}
						}
						{"default"
							{"talk"
								{selector
									{amount 1
									}
									{tag officer}
									{zone "gamezone"}
									{type human}
									{state "not dead"}
								}
								{text "mission/multi/player_ac_014"}
							}
						}
					}
					{"delay"
						{time 5}
					}
					{"while"
						{condition
							{type entities}
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag officer}
										}
									}
									{include
										{prop
											{prop human}
										}
										{state
											{state "operatable user_control"}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
									}
								}
							}
							{count
								{op ">"}
								{value 5}
							}
						}
						{"switch"
							{"case"
								{condition
									{type rand}
									{value 0.5}
								}
								{"effect"
									{selector
										{source advanced}
										{group
											{select
												{tag
													{tag officer}
												}
											}
											{include
												{prop
													{prop human}
												}
												{state
													{state "operatable user_control"}
												}
											}
											{exclude
												{state
													{state dead}
												}
												{state
													{state inactive}
												}
												{state
													{state linked}
												}
											}
										}
										{amount 1
										}
									}
									{effect _burn}
								}
							}
							{"case"
								{condition
									{type rand}
									{value 0.5}
								}
								{"effect"
									{selector
										{source advanced}
										{group
											{select
												{tag
													{tag officer}
												}
											}
											{include
												{prop
													{prop human}
												}
												{state
													{state "operatable user_control"}
												}
											}
											{exclude
												{state
													{state dead}
												}
												{state
													{state inactive}
												}
												{state
													{state linked}
												}
											}
										}
										{amount 1
										}
									}
									{effect explode_human}
								}
							}
							{"default"
								{"entity_state"
									{selector
										{source advanced}
										{group
											{select
												{tag
													{tag officer}
												}
											}
											{include
												{prop
													{prop human}
												}
												{state
													{state "operatable user_control"}
												}
											}
											{exclude
												{state
													{state dead}
												}
												{state
													{state inactive}
												}
												{state
													{state linked}
												}
											}
										}
										{amount 1
										}
									}
									{tag_add traitor}
									{tag_remove officer}
								}
								{"delay"
									{time 0.5}
								}
								{"ables"
									{selector
										{amount 1
										}
										{tag traitor}
										{type human}
										{state operatable}
									}
									{remove select}
								}
								{"delay"
									{time 0.5}
								}
								{"actor_state"
									{selector
										{amount 1
										}
										{tag traitor}
										{type human}
										{state operatable}
									}
									{control AI}
									{fire_mode open}
									{move_mode free}
									{ai_move
										{mode disable}
									}
									{human
										{health 1000}
									}
								}
								{"delay"
									{time 0.5}
								}
								{"player"
									{selector
										{amount 1
										}
										{tag traitor}
										{type human}
										{state operatable}
									}
									{operation set}
									{player "17"}
								}
							}
						}
						{"delay"
							{time 1}
						}
					}
					{"delay"
						{time 2}
					}
					{"trigger"
						{name "player_scripts/check_officer_cheese"}
					}
				}
			}
			{"player_scripts/warn_officer_cheese"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag officer}
										}
									}
									{include
										{prop
											{prop human}
										}
										{state
											{state "operatable user_control"}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{tag
											{tag traitor}
										}
										{tag
											{tag _bleedout_}
										}
									}
								}
							}
							{count
								{op "=="}
								{value 5}
							}
						}
					}
				}
				{actions
					{"talk"
						{selector
							{amount 1
							}
							{tag officer}
							{zone "gamezone"}
							{type human}
							{state "not dead"}
						}
						{text "mission/multi/player_ac_000warning"}
					}
				}
			}

;============ Air SCRIPTS========================================
			{"player_logic/air/move_player_planes_offmap"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag user_plane}
										}
									}
									{include
										{state
											{state user_control}
										}
										{prop
											{prop drop_plane}
										}
										{state
											{state operatable}
										}
										{tag
											{tag move_to_start_waypoint}
										}
									}
									{exclude
										{tag
											{tag dropping_troopers}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{tag
											{tag moving_to_drop_zone}
										}
										{tag
											{tag on_mission}
										}
										{tag
											{tag ready_to_move}
										}
										{tag
											{tag player_drop_plane_moving_to_start}
										}
									}
								}
							}
						}
						{"2.cmp_i"
							{var "noresusenabled$"}
							{op "=="}
							{value 1}
						}
					}
				}
				{actions
					{"delay"
						{time 0.2}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag user_plane}
									}
								}
								{include
									{state
										{state user_control}
									}
									{prop
										{prop drop_plane}
									}
									{state
										{state inhabited}
									}
									{tag
										{tag move_to_start_waypoint}
									}
								}
								{exclude
									{tag
										{tag dropping_troopers}
									}
									{state
										{state inactive}
									}
									{state
										{state linked}
									}
									{tag
										{tag moving_to_drop_zone}
									}
									{tag
										{tag on_mission}
									}
									{tag
										{tag ready_to_move}
									}
									{tag
										{tag player_drop_plane_moving_to_start}
									}
								}
							}
						}
						{tag_add player_drop_plane_moving_to_start}
						{impregnability full}
					}
					{"delay"
						{time 0.5}
					}
					{"select"
						{tag player_drop_plane_moving_to_start}
						{type vehicle}
						{state inhabited}
					}
					{"delay"
						{time 0.5}
					}
					{"air_state"
						{selector
							{source current}
						}
						{drop orders}
						{altitude 45}
					}
					{"delay"
						{time 0.5}
					}
					{"actor_to_waypoint"
						{selector
							{source current}
						}
						{waypoint "3000"}
						{approach "safe teleport & rotate"}
					}
					{"delay"
						{time 0.5}
					}
					{"select"
						{tag player_drop_plane_moving_to_start}
						{type vehicle}
						{state inhabited}
					}
					{"delay"
						{time 0.5}
					}
					{"effect"
						{selector
							{source current}
						}
						{effect move_plane_to_initial_waypoint}
					}
					{"delay"
						{time 0.5}
					}
					{"trigger"
						{name "player_logic/air/move_player_planes_offmap"}
					}
				}
			}
			{"player_logic/air/send_player_drop_plane"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag user_plane}
										}
									}
									{include
										{state
											{state user_control}
										}
										{prop
											{prop drop_plane}
										}
										{tag
											{tag ready_to_move}
										}
										{state
											{state inhabited}
										}
									}
									{exclude
										{tag
											{tag dropping_troopers}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{tag
											{tag moving_to_drop_zone}
										}
										{tag
											{tag on_mission}
										}
										{tag
											{tag move_to_start_waypoint}
										}
									}
								}
							}
						}
						{"2.event"
							{id "air_raid_start"}
						}
					}
				}
				{actions
					{"delay"
						{time 0.5}
					}
					{"select"
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select
								{tag
									{tag user_plane}
								}
							}
							{include
								{state
									{state user_control}
								}
								{prop
									{prop drop_plane}
								}
								{tag
									{tag ready_to_move}
								}
								{state
									{state inhabited}
								}
							}
							{exclude
								{tag
									{tag dropping_troopers}
								}
								{state
									{state inactive}
								}
								{state
									{state linked}
								}
								{tag
									{tag moving_to_drop_zone}
								}
								{tag
									{tag on_mission}
								}
								{tag
									{tag move_to_start_waypoint}
								}
								{zone
									{zone "gamezone"}
								}
							}
						}
						{amount 1
						}
					}
					{"delay"
						{time 0.5}
					}
					{"effect"
						{selector
							{source current}
						}
						{effect prep_drop_plane_to_move}
					}
					{"delay"
						{time 0.2}
					}
					{"select"
						{source advanced}
						{group
							{select
								{tag
									{tag moving_to_drop_zone}
								}
							}
							{include
								{prop
									{prop drop_plane}
								}
								{state
									{state user_control}
								}
								{tag
									{tag user_plane}
								}
								{state
									{state inhabited}
								}
							}
							{exclude
								{state
									{state linked}
								}
								{tag
									{tag dropping_troopers}
								}
								{prop
									{prop ai}
								}
								{state
									{state inactive}
								}
								{zone
									{zone "gamezone"}
								}
							}
						}
						{amount 1
						}
					}
					{## "delay"
						{time 0.2}
					}
					{## "air_state"
						{selector
							{source current}
						}
						{drop orders}
						{altitude 45}
					}
					{"delay"
						{time 0.2}
					}
					{"switch"
						{"case"
							{condition
								{type rand}
								{value 0.33}
							}
							{"air_attack"
								{selector
									{source current}
								}
								{drop orders}
								{enemies
									{amount 1
									}
									{tag drop_zone}
									{zone "gamezone"}
								}
								{move_from_back}
								{force_placement}
								{random_weapon 0}
								{attack_altitude 43}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.33}
							}
							{"air_attack"
								{selector
									{source current}
								}
								{drop orders}
								{enemies
									{amount 1
									}
									{tag drop_zone}
									{zone "gamezone"}
								}
								{move_from_back}
								{force_placement}
								{random_weapon 0}
								{attack_altitude 46}
							}
						}
						{"default"
							{"air_attack"
								{selector
									{source current}
								}
								{drop orders}
								{enemies
									{amount 1
									}
									{tag drop_zone}
									{zone "gamezone"}
								}
								{move_from_back}
								{force_placement}
								{random_weapon 0}
								{attack_altitude 40}
							}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{source current}
						}
						{tag_remove moving_to_drop_zone}
						{impregnability disabled}
					}
					{"delay"
						{time 2}
					}
					{"trigger"
						{name "player_logic/air/send_player_drop_plane"}
					}
				}
			}
			{"player_logic/air/player_jump_prepare_emote"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag user_plane}
										}
									}
									{include
										{state
											{state "inhabited user_control"}
										}
										{prop
											{prop drop_plane}
										}
										{zone
											{zone "gamezone"}
										}
										{tag
											{tag on_mission}
										}
									}
									{exclude
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
									}
								}
							}
						}
					}
				}
				{actions			
					{"switch"
						{"case"
							{condition
								{type rand}
								{value 0.33}
							}
							{"talk"
								{selector
									{source advanced}
									{group
										{select
											{zone
												{zone "gamezone"}
											}
										}
										{include
											{state
												{state "linked user_control"}
											}
											{prop
												{prop human}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
										}
									}
									{amount 1
									}
								}
								{text "mission/multi/player_paratrooper_prepare_to_jump"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.33}
							}
							{"talk"
								{selector
									{source advanced}
									{group
										{select
											{zone
												{zone "gamezone"}
											}
										}
										{include
											{state
												{state "linked user_control"}
											}
											{prop
												{prop human}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
										}
									}
									{amount 1
									}
								}
								{text "mission/multi/player_paratrooper_prepare_to_jump_02"}
							}
						}
						{"default"
							{"talk"
								{selector
									{source advanced}
									{group
										{select
											{zone
												{zone "gamezone"}
											}
										}
										{include
											{state
												{state "linked user_control"}
											}
											{prop
												{prop human}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
										}
									}
									{amount 1
									}
								}
								{text "mission/multi/player_paratrooper_prepare_to_jump_03"}
							}
						}
					}
				}
			}
			{"player_logic/air/player_jump_emote"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag user_plane}
										}
									}
									{include
										{state
											{state "inhabited user_control"}
										}
										{prop
											{prop drop_plane}
										}
										{zone
											{zone "gamezone"}
										}
										{tag
											{tag dropping_troopers}
										}
									}
									{exclude
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{tag
											{tag green_light}
										}
									}
								}
							}
						}
					}
				}
				{actions
					{"switch"
						{"case"
							{condition
								{type rand}
								{value 0.33}
							}
							{"talk"
								{selector
									{source advanced}
									{group
										{select
											{zone
												{zone "gamezone"}
											}
										}
										{include
											{state
												{state "linked user_control"}
											}
											{prop
												{prop human}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
										}
									}
									{amount 1
									}
								}
								{text "mission/multi/player_paratrooper_jump_02"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.33}
							}
							{"talk"
								{selector
									{source advanced}
									{group
										{select
											{zone
												{zone "gamezone"}
											}
										}
										{include
											{state
												{state "linked user_control"}
											}
											{prop
												{prop human}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
										}
									}
									{amount 1
									}
								}
								{text "mission/multi/player_paratrooper_jump_03"}
							}
						}
						{"default"
							{"talk"
								{selector
									{source advanced}
									{group
										{select
											{zone
												{zone "gamezone"}
											}
										}
										{include
											{state
												{state "linked user_control"}
											}
											{prop
												{prop human}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
										}
									}
									{amount 1
									}
								}
								{text "mission/multi/player_paratrooper_jump"}
							}
						}
					}
					{"delay"
						{time 0.2}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag dropping_troopers}
									}
								}
								{include
									{prop
										{prop drop_plane}
									}
									{state
										{state "inhabited user_control"}
									}
									{zone
										{zone "gamezone"}
									}
									{tag
										{tag user_plane}
									}
								}
								{exclude
									{state
										{state inactive}
									}
									{state
										{state linked}
									}
									{tag
										{tag green_light}
									}
								}
							}
							{amount 1
							}
						}
						{tag_add green_light}
					}
					{"delay"
						{time 0.2}
					}
					{"trigger"
						{name "player_logic/air/player_jump_emote"}
					}
				}
			}
			{"player_logic/air/enable_player_drop_plane_select"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag user_plane}
										}
									}
									{include
										{state
											{state user_control}
										}
										{prop
											{prop drop_plane}
										}
										{state
											{state operatable}
										}
									}
									{exclude
										{tag
											{tag dropping_troopers}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{tag
											{tag moving_to_drop_zone}
										}
										{tag
											{tag on_mission}
										}
										{tag
											{tag ready_to_move}
										}
									}
								}
							}
						}
						{"2.cmp_i"
							{var "noresusenabled$"}
							{op "=="}
							{value 0}
						}
					}
				}
				{actions
					{"delay"
						{time 0.2}
					}
					{"ables"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag user_plane}
									}
								}
								{include
									{prop
										{prop drop_plane}
									}
									{state
										{state "operatable user_control"}
									}
								}
								{exclude
									{state
										{state linked}
									}
									{state
										{state inactive}
									}
								}
							}
						}
						{add select}
					}
					{"delay"
						{time 0.2}
					}
					{"trigger"
						{name "player_logic/air/enable_player_drop_plane_select"}
					}
				}
			}
