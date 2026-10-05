; File created by Hawka
;==========================================================================================================

; ============= GENERAL AI SPAWN TRIGGER DEFINES ===================================
			(define "ai_inf_spawn" ; parms: side, zone, waypoint 
				{"ai_spawn_logic/side_%side/inf/spawn_%zone"
					{condition
						{terms
							;{"1.cmp_i"
							;	{var "enable_spawn_%zone_waypoint_grid$"}
							;	{op ">"}
							;	{value 0}
							;}
							{"1.cmp_i"
								{var "enable_waypoint_graph$"}
								{op ">"}
								{value 0}
							}
							{"2.entities"
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
												{prop human}
											}
											{tag
												{tag bot}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state user_control}
											}
											{state
												{state linked}
											}
											{state
												{state inactive}
											}
											{tag
												{tag player}
											}
											{tag
												{tag _player}
											}
											{tag
												{tag ignore_spawn_logic}
											}
											{tag
												{tag cmp_def}
											}
										}
									}
								}
							}
						}
					}
					{actions
						{"delay"
							{time 0.1}
						}
						{"switch"
							{"case"
								{condition
									{type rand}
									{value 0.5}
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
												{prop human}
											}
											{tag
												{tag bot}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state user_control}
											}
											{state
												{state linked}
											}
											{state
												{state inactive}
											}
											{tag
												{tag player}
											}
											{tag
												{tag _player}
											}
											{tag
												{tag ignore_spawn_logic}
											}
											{tag
												{tag cmp_def}
											}
										}
									}
									{amount 12
									}
								}
							}
							{"default"
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
												{prop human}
											}
											{tag
												{tag bot}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state user_control}
											}
											{state
												{state linked}
											}
											{state
												{state inactive}
											}
											{tag
												{tag player}
											}
											{tag
												{tag _player}
											}
											{tag
												{tag ignore_spawn_logic}
											}
											{tag
												{tag moving_to_spawn_waypoint}
											}
											{tag
												{tag cmp_def}
											}
										}
									}
									{amount 8
									}
								}
							}
						}
						{"delay"
							{time 0.2}
						}
						{"entity_state"
							{selector
								{source current}
							}
							{tag_add _lua_mi}
						}
						{"delay"
							{time 0.2}
						}
						{"entity_state"
							{selector
								{source current}
							}
							{tag_add in_spawn_zone_%zone_inf}
						}
						{"delay"
							{time 0.2}
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
											{state
												{state operatable}
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
												{state user_control}
											}
											{state
												{state linked}
											}
											{state
												{state inactive}
											}
											{tag
												{tag player}
											}
											{tag
												{tag _player}
											}
											{tag
												{tag ignore_spawn_logic}
											}
											{tag
												{tag moving_to_spawn_waypoint}
											}
											{tag
												{tag cmp_def}
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
							{time 0.2}
						}
						{"select"
							{tag in_spawn_zone_%zone_inf}
							{type human}
							{state "not dead"}
						}
						{"delay"
							{time 0.1}
						}
						{"actor_state"
							{selector
								{source current}
							}
							{movement
								{speed assault}
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
							{name "ai_spawn_logic/side_%side/inf/spawn_%zone"}
						}
					}
				}
			)

			(define "ai_veh_spawn" ; parms: side, zone, waypoint 
				{"ai_spawn_logic/side_%side/veh/veh_spawn_%zone"
					{condition
						{terms
							{"1.cmp_i"
								{var "enable_waypoint_graph$"}
								{op ">"}
								{value 0}
							}
							{"2.entities"
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
												{tag cmp_def}
											}
											;{prop
											;	{prop sq_armor_heavy}
											;}
											{prop
												{prop heavy}
											}
											{prop
												{prop sq_armor_super_heavy}
											}
											{prop
												{prop td}
											}
											{prop
												{prop sq_he_large}
											}
											{prop
												{prop cannon}
											}
											{prop
												{prop sq_he_medium}
											}
										}
									}
								}
							}
						}
					}
					{actions
						{"delay"
							{time 0.1}
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
										{tag cmp_def}
									}
									{prop
										{prop sq_armor_heavy}
									}
									{prop
										{prop sq_armor_super_heavy}
									}
									{prop
										{prop td}
									}
									{prop
										{prop sq_he_large}
									}
									{prop
										{prop cannon}
									}
									{prop
										{prop sq_he_medium}
									}
								}
							}
							{amount 1
							}
						}
						{"delay"
							{time 0.2}
						}
						{"entity_state"
							{selector
								{source current}
							}
							{tag_add _lua_mi}
						}
						{"delay"
							{time 0.1}
						}
						{"entity_state"
							{selector
								{source current}
							}
							{tag_add in_spawn_zone_%zone_veh}
						}
						{"delay"
							{time 0.1}
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
							{time 0.1}
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
							{time 0.1}
						}
						{"effect"
							{selector
								{source current}
							}
							{effect set_ignore_spawn_logic}
						}
						{"delay"
							{time 0.1}
						}
						{"trigger"
							{name "ai_spawn_logic/side_%side/veh/veh_spawn_%zone"}
						}
					}
				}
			)

; ============= SIDE A ===================================
			("ai_inf_spawn" side(a) zone(a_1) waypoint(1110))
			("ai_inf_spawn" side(a) zone(a_2) waypoint(1120))
			("ai_inf_spawn" side(a) zone(a_3) waypoint(1130))
			("ai_inf_spawn" side(a) zone(a_4) waypoint(1140))

			("ai_veh_spawn" side(a) zone(a_1) waypoint(1110))
			("ai_veh_spawn" side(a) zone(a_2) waypoint(1120))
			("ai_veh_spawn" side(a) zone(a_3) waypoint(1130))
			("ai_veh_spawn" side(a) zone(a_4) waypoint(1140))

; ============= SIDE B ===================================
			("ai_inf_spawn" side(b) zone(b_1) waypoint(2110))
			("ai_inf_spawn" side(b) zone(b_2) waypoint(2120))
			("ai_inf_spawn" side(b) zone(b_3) waypoint(2130))
			("ai_inf_spawn" side(b) zone(b_4) waypoint(2140))

			("ai_veh_spawn" side(b) zone(b_1) waypoint(2110))
			("ai_veh_spawn" side(b) zone(b_2) waypoint(2120))
			("ai_veh_spawn" side(b) zone(b_3) waypoint(2130))
			("ai_veh_spawn" side(b) zone(b_4) waypoint(2140))
