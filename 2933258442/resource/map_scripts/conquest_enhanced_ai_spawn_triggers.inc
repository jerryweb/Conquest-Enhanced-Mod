; ============= GENERAL AI SPAWN TRIGGER DEFINES ===================================
			(define "ai_inf_spawn" ; parms: side, zone, waypoint 
				{"ai_spawn_logic/side_%side/inf/inf_spawn_%zone"
					{condition
						{terms
							{"1.entities"
								{selector
									{source advanced}
									{group
										{select
											{zone
												{zone "%zone"}
											}
										}
										{include
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state user_control}
											}
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
												{tag player}
											}
											{tag
												{tag ignore_spawn_logic}
											}
											{tag
												{tag moving_to_waypoint_graph}
											}
											{tag
												{tag cmp_def}
											}
											{tag
												{tag _def}
											}
										}
									}
								}
							}
							{"2.cmp_i"
								{var "enable_ai_waypoint_graphs$"}
								{op ">"}
								{value 0}
							}
						}
					}
					{actions
						{"delay"
							{time 1}
						}
						{"select"
							{source advanced}
							{group
								{select
									{zone
										{zone "%zone"}
									}
								}
								{include
									{prop
										{prop human}
									}
									{state
										{state operatable}
									}
								}
								{exclude
									{state
										{state user_control}
									}
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
										{tag player}
									}
									{tag
										{tag ignore_spawn_logic}
									}
									{tag
										{tag moving_to_waypoint_graph}
									}
								}
							}
							{amount 6
							}
						}
						{"delay"
							{time 0.5}
						}
						{## "actor_state"
							{selector
								{source current}
							}
							{fire_mode open}
							{weapon_prepare on}
							{ai_move
								{mode enable}
							}
							{movement
								{speed assault}
							}
						}
						{"entity_state"
							{selector
								{source current}
							}
							{tag_add in_spawn_zone_%zone_inf}
						}
						{"delay"
							{time 1}
						}
						{## "switch"
							{"case"
								{condition
									{type cmp_i}
									{var "force_ai_direct_attack_logic$"}
									{op "=="}
									{value 0}
								}
								{"entity_state"
									{selector
										{source current}
									}
									{tag_add _lua_mi}
								}
								{"delay"
									{time 0.5}
								}
								{"waypoint"
									{who
										{type actor}
										{actors
											{source advanced}
											{group
												{select
													{tag
														{tag in_spawn_zone_%zone_inf}
													}
												}
												{include
													{prop
														{prop human}
													}
													{state
														{state operatable}
													}
													{zone
														{zone "%zone"}
													}
												}
												{exclude
													{state
														{state user_control}
													}
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
														{tag player}
													}
													{tag
														{tag ignore_spawn_logic}
													}
													{tag
														{tag moving_to_waypoint_graph}
													}
													{tag
														{tag cmp_def}
													}
													{tag
														{tag _def}
													}
												}
											}
										}
									}
									{action
										{type start}
										{waypoint "%waypoint"}
										{make_squad}
									}
								}
							}
							{"default"
								{"switch"
									{"case"
										{condition
											{type rand}
											{value 0.5}
										}
										{"entity_state"
											{selector
												{source current}
											}
											{tag_add _lua_mi}
										}
										{"delay"
											{time 0.5}
										}
										{"waypoint"
											{who
												{type actor}
												{actors
													{source advanced}
													{group
														{select
															{tag
																{tag in_spawn_zone_%zone_inf}
															}
														}
														{include
															{prop
																{prop human}
															}
															{state
																{state operatable}
															}
															{zone
																{zone "%zone"}
															}
														}
														{exclude
															{state
																{state user_control}
															}
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
																{tag player}
															}
															{tag
																{tag ignore_spawn_logic}
															}
															{tag
																{tag moving_to_waypoint_graph}
															}
															{tag
																{tag cmp_def}
															}
															{tag
																{tag _def}
															}
														}
													}
												}
											}
											{action
												{type start}
												{waypoint "%waypoint"}
												{make_squad}
											}
										}
									}
									{"default"
										{"effect"
											{selector
												{source current}
											}
											{effect tag_squad_need_next_order}
										}
									}
								}
							}
						}
						{"entity_state"
							{selector
								{source current}
							}
							{tag_add _lua_mi}
						}
						{"delay"
							{time 0.5}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag in_spawn_zone_%zone_inf}
											}
										}
										{include
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
											{zone
												{zone "%zone"}
											}
										}
										{exclude
											{state
												{state user_control}
											}
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
												{tag player}
											}
											{tag
												{tag ignore_spawn_logic}
											}
											{tag
												{tag moving_to_waypoint_graph}
											}
											{tag
												{tag cmp_def}
											}
											{tag
												{tag _def}
											}
										}
									}
								}
							}
							{action
								{type start}
								{waypoint "%waypoint"}
								{make_squad}
							}
						}
						{"delay"
							{time 0.5}
						}
						{"call"
							{function "ai_spawn_inf_settings"}
							{context
								{specified}
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag in_spawn_zone_%zone_inf}
											}
										}
										{include
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
											{zone
												{zone "%zone"}
											}
										}
										{exclude
											{state
												{state user_control}
											}
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
												{tag player}
											}
											{tag
												{tag ignore_spawn_logic}
											}
											{tag
												{tag moving_to_waypoint_graph}
											}
											{tag
												{tag cmp_def}
											}
											{tag
												{tag _def}
											}
										}
									}
								}
							}
						}
						{"delay"
							{time 2}
						}
						{"trigger"
							{name "ai_spawn_logic/side_%side/inf/inf_spawn_%zone"}
						}
					}
				}	
			)

			(define "ai_vehicle_spawn" ; parms: side, zone, waypoint 
				{"ai_spawn_logic/side_%side/veh/veh_spawn_%zone"
					{condition
						{terms
							{"1.entities"
								{selector
									{source advanced}
									{group
										{select
											{zone
												{zone "%zone"}
											}
										}
										{include
											{state
												{state operatable}
											}
											{prop
												{prop vehicle}
											}
										}
										{exclude
											{state
												{state user_control}
											}
											{state
												{state dead}
											}
											{state
												{state linked}
											}
											{state
												{state inactive}
											}
											{prop
												{prop human}
											}
											{prop
												{prop airborne}
											}
											{tag
												{tag ignore_spawn_logic}
											}
											{tag
												{tag moving_to_waypoint_graph}
											}
											{tag
												{tag artillery}
											}
											{tag
												{tag heavy_artillery}
											}
											{tag
												{tag rocket_artillery}
											}
											{prop
												{prop cannon}
											}
											{tag
												{tag cmp_def}
											}
											{tag
												{tag _def}
											}
											{prop
												{prop test_veh}
											}
										}
									}
								}
							}
							{"2.cmp_i"
								{var "enable_ai_waypoint_graphs$"}
								{op ">"}
								{value 0}
							}
						}
					}
					{actions
						{"delay"
							{time 1}
						}
						{"select"
							{source advanced}
							{group
								{select
									{zone
										{zone "%zone"}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop vehicle}
									}
								}
								{exclude
									{state
										{state user_control}
									}
									{state
										{state dead}
									}
									{state
										{state linked}
									}
									{state
										{state inactive}
									}
									{prop
										{prop human}
									}
									{prop
										{prop airborne}
									}
									{tag
										{tag ignore_spawn_logic}
									}
									{tag
										{tag moving_to_waypoint_graph}
									}
									{tag
										{tag artillery}
									}
									{tag
										{tag heavy_artillery}
									}
									{tag
										{tag rocket_artillery}
									}
									{prop
										{prop cannon}
									}
									{prop
										{prop test_veh}
									}
								}
							}
							{amount 1
							}
						}
						{"delay"
							{time 1}
						}
						{"entity_state"
							{selector
								{source current}
							}
							{tag_add in_spawn_zone_%zone_veh}
						}
						{"delay"
							{time 1}
						}
						{"entity_state"
							{selector
								{tag in_spawn_zone_%zone_veh}
								{type vehicle}
								{state operatable}
							}
							{tag_add moving_to_waypoint_graph}
						}
						{"delay"
							{time 0.5}
						}
						{"select"
							{source advanced}
							{group
								{select
									{tag
										{tag in_spawn_zone_%zone_veh}
									}
								}
								{include
									{state
										{state inhabited}
									}
									{prop
										{prop vehicle}
									}
									{tag
										{tag moving_to_waypoint_graph}
									}
								}
								{exclude
									{state
										{state user_control}
									}
									{state
										{state dead}
									}
									{state
										{state linked}
									}
									{state
										{state inactive}
									}
									{prop
										{prop human}
									}
									{prop
										{prop airborne}
									}
									{tag
										{tag ignore_spawn_logic}
									}
									{tag
										{tag artillery}
									}
									{tag
										{tag heavy_artillery}
									}
									{tag
										{tag rocket_artillery}
									}
									{prop
										{prop cannon}
									}
									{prop
										{prop test_veh}
									}
								}
							}
						}
						{"delay"
							{time 0.5}
						}
						{## "switch"
							{"case"
								{condition
									{type cmp_i}
									{var "force_ai_direct_attack_logic$"}
									{op "=="}
									{value 0}
								}
								{"entity_state"
									{selector
										{source current}
									}
									{tag_add _lua_mi}
								}
								{"delay"
									{time 0.5}
								}
								{"waypoint"
									{who
										{type actor}
										{actors
											{tag in_spawn_zone_%zone_veh}
											{type vehicle}
											{state operatable}
										}
									}
									{action
										{type start}
										{waypoint "%waypoint"}
										{make_squad}
									}
								}
							}
							{"default"
								{"switch"
									{"case"
										{condition
											{type rand}
											{value 0.5}
										}
										{"entity_state"
											{selector
												{source current}
											}
											{tag_add _lua_mi}
										}
										{"delay"
											{time 0.5}
										}
										{"waypoint"
											{who
												{type actor}
												{actors
													{tag in_spawn_zone_%zone_veh}
													{type vehicle}
													{state operatable}
												}
											}
											{action
												{type start}
												{waypoint "%waypoint"}
												{make_squad}
											}
										}
									}
									{"default"
										{"effect"
											{selector
												{source current}
											}
											{effect tag_squad_need_next_order}
										}
									}
								}
							}
						}
						{"entity_state"
							{selector
								{source current}
							}
							{tag_add _lua_mi}
						}
						{"delay"
							{time 0.5}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{tag in_spawn_zone_%zone_veh}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "%waypoint"}
								{make_squad}
							}
						}
						{"delay"
							{time 1}
						}							
						{"effect"
							{selector
								{source current}
							}
							{effect set_ignore_spawn_logic}
						}
						{"delay"
							{time 3}
						}
						{"trigger"
							{name "ai_spawn_logic/side_%side/veh/veh_spawn_%zone"}
						}
					}
				}
			)

			(define "ai_cannon_spawn" ; parms: side, zone, waypoint
				{## "ai_spawn_logic/side_%side/cannon/can_spawn_%zone"
						{condition
							{terms
								{"1.entities"
									{selector
										{source advanced}
										{group
											{select
												{zone
													{zone "%zone"}
												}
											}
											{include
												{state
													{state inhabited}
												}
												{prop
													{prop cannon}
												}
											}
											{exclude
												{state
													{state user_control}
												}
												{state
													{state dead}
												}
												{state
													{state linked}
												}
												{state
													{state inactive}
												}
												{prop
													{prop human}
												}
												{prop
													{prop airborne}
												}
												{prop
													{prop tank}
												}
												{tag
													{tag ignore_spawn_logic}
												}
												{tag
													{tag moving_to_waypoint_graph}
												}
												{tag
													{tag artillery}
												}
												{tag
													{tag heavy_artillery}
												}
												{tag
													{tag rocket_artillery}
												}										
												{tag
													{tag cmp_def}
												}
												{tag
													{tag _def}
												}
											}
										}
									}
								}
								{"2.cmp_i"
									{var "enable_ai_waypoint_graphs$"}
									{op ">"}
									{value 0}
								}
							}
						}
						{actions
							{"delay"
								{time 1}
							}
							{"select"
								{source advanced}
								{group
									{select
										{zone
											{zone "%zone"}
										}
									}
									{include
										{state
											{state inhabited}
										}
										{prop
											{prop cannon}
										}
									}
									{exclude
										{state
											{state user_control}
										}
										{state
											{state dead}
										}
										{state
											{state linked}
										}
										{state
											{state inactive}
										}
										{prop
											{prop human}
										}
										{prop
											{prop airborne}
										}
										{prop
											{prop tank}
										}
										{tag
											{tag ignore_spawn_logic}
										}
										{tag
											{tag moving_to_waypoint_graph}
										}
										{tag
											{tag artillery}
										}
										{tag
											{tag heavy_artillery}
										}
										{tag
											{tag rocket_artillery}
										}										
										{tag
											{tag cmp_def}
										}
										{tag
											{tag _def}
										}
									}
								}
								{amount 1
								}
							}
							{"delay"
								{time 0.5}
							}
							{"entity_state"
								{selector
									{source current}
								}
								{tag_add in_spawn_zone_%zone_can}
							}
							{"delay"
								{time 0.5}
							}
							
							{"select"
								{source advanced}
								{group
									{select
										{tag
											{tag in_spawn_zone_%zone_can}
										}
									}
									{include
										{state
											{state inhabited}
										}
										{prop
											{prop cannon}
										}
									}
									{exclude
										{state
											{state user_control}
										}
										{state
											{state dead}
										}
										{state
											{state linked}
										}
										{state
											{state inactive}
										}
										{prop
											{prop human}
										}
										{prop
											{prop airborne}
										}
										{tag
											{tag ignore_spawn_logic}
										}
										{tag
											{tag artillery}
										}
										{tag
											{tag heavy_artillery}
										}
										{tag
											{tag rocket_artillery}
										}
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
								{tag_add _lua_mi}
							}					
							{"delay"
								{time 0.5}
							}
							{## "waypoint"
								{who
									{type actor}
									{actors
										{tag in_spawn_zone_%zone_can}
										{type cannon}
										{state operatable}
									}
								}
								{action
									{type start}
									{waypoint "%waypoint"}
									{make_squad}
								}
							}
							{"entity_state"
								{selector
									{source advanced}
									{group
										{select
											{zone
												{zone "fpc1"}
											}
											{zone
												{zone "fpc2"}
											}
											{zone
												{zone "fpc3"}
											}
											{zone
												{zone "fpc4"}
											}
											{zone
												{zone "fpc5"}
											}
										}
										{include
											{tag
												{tag flag_point}
											}
										}
										{exclude
											{state
												{state inactive}
											}
										}
									}
									{amount 1
									}
								}
								{tag_add selected_for_cannon_attack_%zone}
							}
							{"delay"
								{time 0.2}
							}
							{"switch"
								{"case"
									{condition
										{type entities}
										{selector
											{tag selected_for_cannon_attack_%zone}
											{zone "fpc1"}
										}
									}
									{"action"
										{selector
											{source current}
										}
										{drop orders}
										{action attack}
										{waypoint "1"}
									}
								}
								{"case"
									{condition
										{type entities}
										{selector
											{tag selected_for_cannon_attack_%zone}
											{zone "fpc2"}
										}
									}
									{"action"
										{selector
											{source current}
										}
										{drop orders}
										{action attack}
										{waypoint "2"}
									}
								}
								{"case"
									{condition
										{type entities}
										{selector
											{tag selected_for_cannon_attack_%zone}
											{zone "fpc3"}
										}
									}
									{"action"
										{selector
											{source current}
										}
										{drop orders}
										{action attack}
										{waypoint "3"}
									}
								}
								{"case"
									{condition
										{type entities}
										{selector
											{tag selected_for_cannon_attack_%zone}
											{zone "fpc4"}
										}
									}
									{"action"
										{selector
											{source current}
										}
										{drop orders}
										{action attack}
										{waypoint "4"}
									}
								}
								{"case"
									{condition
										{type entities}
										{selector
											{tag selected_for_cannon_attack_%zone}
											{zone "fpc5"}
										}
									}
									{"action"
										{selector
											{source current}
										}
										{drop orders}
										{action attack}
										{waypoint "5"}
									}
								}
							}
							{"delay"
								{time 0.5}
							}
							{"effect"
								{selector
									{source current}
								}
								{effect set_ignore_spawn_logic}
							}
							{"delay"
								{time 3}
							}
							{"trigger"
								{name "ai_spawn_logic/side_%side/cannon/can_spawn_%zone"}
							}
						}
					}
			)

			(define "focus_ai_spawn_case" ; parms: target_waypoint, 
						{"case"
							{condition
								{type cmp_i}
								{var "ai_spawn_strategy$"}
								{op "=="}
								{value %waypoint}
							}
							{"timer"
								{time 8}
								{title "focus waypoint %waypoint"}
							}
							{"switch"
								{"case"
									{condition
										{type entities}
										{selector
											{source advanced}
											{group
												{select
													{tag
														{tag spawn_a}
													}
												}
												{include
													{tag
														{tag ai_spawn}
													}
												}
											}
										}
									}
									{"placement"
										{selector
											{source advanced}
											{group
												{select
													{zone
														{zone "a_1"}
													}
													{zone
														{zone "a_2"}
													}
													{zone
														{zone "a_3"}
													}
													{zone
														{zone "a_4"}
													}
												}
												{include
													{tag
														{tag ai_spawn}
													}
												}
											}
										}
										{target_waypoint "100%waypoint"}
									}
								}
								{"case"
									{condition
										{type entities}
										{selector
											{source advanced}
											{group
												{select
													{tag
														{tag spawn_b}
													}
												}
												{include
													{tag
														{tag ai_spawn}
													}
												}
											}
										}
									}
									{"placement"
										{selector
											{source advanced}
											{group
												{select
													{zone
														{zone "b_1"}
													}
													{zone
														{zone "b_2"}
													}
													{zone
														{zone "b_3"}
													}
													{zone
														{zone "b_4"}
													}
												}
												{include
													{tag
														{tag ai_spawn}
													}
												}
											}
										}
										{target_waypoint "200%waypoint"}
									}
								}
							}
						}
			)

; ============= SIDE A ===================================
			("ai_inf_spawn" side(a) zone(a_1) waypoint(1011))
			("ai_inf_spawn" side(a) zone(a_2) waypoint(1012))
			("ai_inf_spawn" side(a) zone(a_3) waypoint(1013))
			("ai_inf_spawn" side(a) zone(a_4) waypoint(1014))

			("ai_vehicle_spawn" side(a) zone(a_1) waypoint(1011))
			("ai_vehicle_spawn" side(a) zone(a_2) waypoint(1012))
			("ai_vehicle_spawn" side(a) zone(a_3) waypoint(1013))
			("ai_vehicle_spawn" side(a) zone(a_4) waypoint(1014))

			;("ai_cannon_spawn" side(a) zone(a_1) waypoint(1011))
			;("ai_cannon_spawn" side(a) zone(a_2) waypoint(1012))
			;("ai_cannon_spawn" side(a) zone(a_3) waypoint(1013))
			;("ai_cannon_spawn" side(a) zone(a_4) waypoint(1014))

; ============= SIDE B ===================================
			("ai_inf_spawn" side(b) zone(b_1) waypoint(2011))
			("ai_inf_spawn" side(b) zone(b_2) waypoint(2012))
			("ai_inf_spawn" side(b) zone(b_3) waypoint(2013))
			("ai_inf_spawn" side(b) zone(b_4) waypoint(2014))

			("ai_vehicle_spawn" side(b) zone(b_1) waypoint(2011))
			("ai_vehicle_spawn" side(b) zone(b_2) waypoint(2012))
			("ai_vehicle_spawn" side(b) zone(b_3) waypoint(2013))
			("ai_vehicle_spawn" side(b) zone(b_4) waypoint(2014))

			;("ai_cannon_spawn" side(b) zone(b_1) waypoint(2011))
			;("ai_cannon_spawn" side(b) zone(b_2) waypoint(2012))
			;("ai_cannon_spawn" side(b) zone(b_3) waypoint(2013))
			;("ai_cannon_spawn" side(b) zone(b_4) waypoint(2014))

; ============= GENERAL TRIGGERS ===================================
			{"ai_spawn_logic/tag_ai_spawns"
				{condition
				}
				{actions
					{"delay"
						{time 1}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "bots_spawnside$"}
								{op "=="}
								{value 2}
							}
							{"entity_state"
								{selector
									{tag spawn_b}
								}
								{tag_add ai_spawn}
							}
						}
						{"default"
							{"entity_state"
								{selector
									{tag spawn_a}
								}
								{tag_add ai_spawn}
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
									{zone
										{zone "a_1"}
									}
									{zone
										{zone "b_1"}
									}
								}
								{include
									{tag
										{tag ai_spawn}
									}
								}
							}
						}
						{tag_add spawn_1}
					}
					{"delay"
						{time 0.2}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{zone
										{zone "a_2"}
									}
									{zone
										{zone "b_2"}
									}
								}
								{include
									{tag
										{tag ai_spawn}
									}
								}
							}
						}
						{tag_add spawn_2}
					}
					{"delay"
						{time 0.2}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{zone
										{zone "a_3"}
									}
									{zone
										{zone "b_3"}
									}
								}
								{include
									{tag
										{tag ai_spawn}
									}
								}
							}
						}
						{tag_add spawn_3}
					}
					{"delay"
						{time 0.2}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{zone
										{zone "a_4"}
									}
									{zone
										{zone "b_4"}
									}
								}
								{include
									{tag
										{tag ai_spawn}
									}
								}
							}
						}
						{tag_add spawn_4}
					}
				}
			}
			{"ai_spawn/tag_spawned_veh_with_sabotage_chance"
				{condition
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
										{prop
											{prop vehicle}
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
											{state linked}
										}
										{prop
											{prop airborne}
										}
										{tag
											{tag sabotage_possible}
										}
										{tag
											{tag _user}
										}
										{tag
											{tag player_armor}
										}
										{tag
											{tag player_car}
										}
										{tag
											{tag player_veh}
										}
									}
								}
							}
						}
						{"2.event"
							{id "sabotage_ai_veh"}
						}
					}
				}
				{actions
					{"entity_state"
						{"delay"
							{time 5}
						}
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
									{prop
										{prop vehicle}
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
										{state linked}
									}
									{prop
										{prop airborne}
									}
									{tag
										{tag sabotage_possible}
									}
									{tag
										{tag _user}
									}
									{tag
										{tag player_armor}
									}
									{tag
										{tag player_car}
									}
									{tag
										{tag player_veh}
									}
								}
							}
						}
						{tag_add sabotage_possible}
					}
					{"delay"
						{time 5}
					}
					{"trigger"
						{name "ai_spawn/tag_spawned_veh_with_sabotage_chance"}
					}
				}
			}
			{"ai_spawn_logic/move_ai_spawn_new"
				{condition
					{terms
						{"1.cmp_i"
							{var "change_ai_spawns$"}
							{op "=="}
							{value 1}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"switch"
						("focus_ai_spawn_case" waypoint(1))
						("focus_ai_spawn_case" waypoint(2))
						("focus_ai_spawn_case" waypoint(3))
						("focus_ai_spawn_case" waypoint(4))
						; Case 5 is vanilla attack logic						
						{"case"
							{condition
								{type cmp_i}
								{var "ai_spawn_strategy$"}
								{op "=="}
								{value 6}
							}
							{## "call"
								{function "ai_rear_attack_notify"}
							}
							{"delay"
								{time 10}
							}
							{"call"
								{function "move_ai_spawns_to_rear"}
							}
						}
						{"default"
							{"timer"
								{time 8}
								{title "default spawns active"}
							}
							{"call"
								{function "reset_ai_spawn_new"}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"set_i"
						{var "change_ai_spawns$"}
						{op "="}
						{value 0}
					}
					{"trigger"
						{name "ai_spawn_logic/move_ai_spawn_new"}
					}
				}
			}
			{"notify_rear_attack"
				{condition
					{terms
						{"1.cmp_i"
							{var "ai_spawn_strategy$"}
							{op "=="}
							{value 6}
						}
					}
				}
				{actions
					{"call"
						{function "ai_rear_attack_notify"}
					}
				}
			}