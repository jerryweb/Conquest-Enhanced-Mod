; File created by Hawka
;==========================================================================================================

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
												{tag _user}
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
										{tag _user}
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
						{"entity_state"
							{selector
								{source current}
							}
							{tag_add in_spawn_zone_%zone_inf}
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
												{tag _user}
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
												{tag _user}
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
							{time 0.5}
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
												{state "operatable inhabited"}
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
							{time 0.25}
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
										{state "operatable inhabited"}
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
							{time 0.25}
						}
						{"entity_state"
							{selector
								{source current}
							}
							{tag_add in_spawn_zone_%zone_veh}
						}
						{"delay"
							{time 0.25}
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
										{state "operatable inhabited"}
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
										{tag artillery}
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
							{time 0.25}
						}
						{"entity_state"
							{selector
								{source current}
							}
							{tag_add _lua_mi}
						}
						{"delay"
							{time 0.25}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{tag in_spawn_zone_%zone_veh}
									{type vehicle}
									{state inhabited}
								}
							}
							{action
								{type start}
								{waypoint "%waypoint"}
								{make_squad}
							}
						}
						{"delay"
							{time 0.25}
						}							
						{"effect"
							{selector
								{source current}
							}
							{effect set_ignore_spawn_logic}
						}
						{"delay"
							{time 0.25}
						}
						{"trigger"
							{name "ai_spawn_logic/side_%side/veh/veh_spawn_%zone"}
						}
					}
				}
			)

			(define "spawn_placement"; parms: conquest_spawn_point, location
				{"if"
					{condition
						{type entities}
						{selector
							{tag _default_%location}
						}
					}
					{"placement"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag spawnpoint_conquest}
									}
								}
								{include
									{tag
										{tag %conquest_spawn_point}
									}
								}
							}
						}
						{target
							{amount 1
							}
							{tag _default_%location}
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

; ============= SIDE B ===================================
			("ai_inf_spawn" side(b) zone(b_1) waypoint(2011))
			("ai_inf_spawn" side(b) zone(b_2) waypoint(2012))
			("ai_inf_spawn" side(b) zone(b_3) waypoint(2013))
			("ai_inf_spawn" side(b) zone(b_4) waypoint(2014))

			("ai_vehicle_spawn" side(b) zone(b_1) waypoint(2011))
			("ai_vehicle_spawn" side(b) zone(b_2) waypoint(2012))
			("ai_vehicle_spawn" side(b) zone(b_3) waypoint(2013))
			("ai_vehicle_spawn" side(b) zone(b_4) waypoint(2014))

; ============= GENERAL TRIGGERS ===================================
			{"ai_spawn_logic/move_ai_spawn"
				{condition
					{terms
						{"2.cmp_i"
							{var "change_ai_spawns$"}
							{op "=="}
							{value 1}
						}
					}
				}
				{actions
					{"delay"
						{time 0.2}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "ai_spawn_strategy$"}
								{op "=="}
								{value 3}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "bots_spawnside$"}
										{op "=="}
										{value 1}
									}
									("spawn_placement" conquest_spawn_point(a1) location(b1))
									("spawn_placement" conquest_spawn_point(a2) location(b2))
									("spawn_placement" conquest_spawn_point(a3) location(b3))
									("spawn_placement" conquest_spawn_point(a4) location(b4))
								}
								{"case"
									{condition
										{type cmp_i}
										{var "bots_spawnside$"}
										{op "=="}
										{value 2}
									}
									("spawn_placement" conquest_spawn_point(b1) location(a1))
									("spawn_placement" conquest_spawn_point(b2) location(a2))
									("spawn_placement" conquest_spawn_point(b3) location(a3))
									("spawn_placement" conquest_spawn_point(b4) location(a4))
								}
								{"default"}
							}
						}
						{"default"
							("spawn_placement" conquest_spawn_point(a1) location(a1))
							("spawn_placement" conquest_spawn_point(a2) location(a2))
							("spawn_placement" conquest_spawn_point(a3) location(a3))
							("spawn_placement" conquest_spawn_point(a4) location(a4))				
							("spawn_placement" conquest_spawn_point(b1) location(b1))
							("spawn_placement" conquest_spawn_point(b2) location(b2))
							("spawn_placement" conquest_spawn_point(b3) location(b3))
							("spawn_placement" conquest_spawn_point(b4) location(b4))
						}
					}
					{"delay"
						{time 0.2}
					}
					{"set_i"
						{var "change_ai_spawns$"}
						{op "="}
						{value 0}
					}
					{"trigger"
						{name "ai_spawn_logic/move_ai_spawn"}
					}
				}
			}
			{"ai_spawn_logic/tag_spawned_veh_with_sabotage_chance"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag bot}
										}
									}
									{include
										{state
											{state operatable}
										}
										{prop
											{prop vehicle}
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
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag bot}
									}
								}
								{include
									{state
										{state "operatable inhabited"}
									}
									{prop
										{prop vehicle}
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
								}
							}
						}
						{tag_add sabotage_possible}
					}
					{"delay"
						{time 2}
					}
					{"trigger"
						{name "ai_spawn_logic/tag_spawned_veh_with_sabotage_chance"}
					}
				}
			}
			{"notify_rear_attack"
				{condition
					{terms
						{"1.cmp_i"
							{var "ai_spawn_strategy$"}
							{op "=="}
							{value 3}
						}
					}
				}
				{actions
					{"call"
						{function "ai_rear_attack_notify"}
					}
				}
			}