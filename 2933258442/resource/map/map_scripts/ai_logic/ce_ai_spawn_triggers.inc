; File created by Hawka
;==========================================================================================================

			{"ai_spawn_logic/check_waypoint_graph_exists"
				{condition
				}
				{actions
					{"spawn"
						{entity "waypoint_graph_key"}
						{waypoint "1110"}
					}
				}
			}
			{"ai_spawn_logic/check_if_map_has_waypoint_grid"
				{condition
				}
				{actions
					{"delay"
						{time 5}
					}
					{"if"
						{condition
							{type entities}
							{selector
								{tag waypoint_graph_present}
							}
						}
						{"set_i"
							{var "map_contains_waypoint_graphs$"}
							{op "="}
							{value 1}
						}
					}
				}
			}
			{"ai_spawn_logic/order_usa_cannons_stuck_in_spawn"
				{condition
					{terms
						{"1.entities"
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
										{state
											{state "operatable inhabited"}
										}
										{prop
											{prop m2_30cal_tripod}
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
										{tag
											{tag ignore_spawn_logic}
										}
									}
								}
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
										{state
											{state "operatable inhabited"}
										}
										{prop
											{prop "60mm_m2"}
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
										{tag
											{tag ignore_spawn_logic}
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
					{## "timer"
						{time 5}
						{title "DBG: Force moving emplacements from spawn!"}
					}
					{"select"
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
								{state
									{state "operatable inhabited"}
								}
								{prop
									{prop m2_30cal_tripod}
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
								{tag
									{tag ignore_spawn_logic}
								}
							}
						}
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
								{state
									{state "operatable inhabited"}
								}
								{prop
									{prop "60mm_m2"}
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
								{tag
									{tag ignore_spawn_logic}
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
						{tag_add select_force_moving_cannon_from_spawn}
					}
					{"delay"
						{time 0.2}
					}
					{"select"
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
								{state
									{state "operatable inhabited"}
								}
								{tag
									{tag select_force_moving_cannon_from_spawn}
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
								{tag
									{tag ignore_spawn_logic}
								}
							}
						}
						{amount 1
						}
					}
					{"delay"
						{time 0.2}
					}
					{"actor_state"
						{selector
							{source current}
						}
						{cannon move}
					}
					{## "effect"
						{selector
							{source current}
						}
						{effect smoke_for_test}
					}
					{"delay"
						{time 0.1}
					}
					{"effect"
						{selector
							{source current}
						}
						{effect force_move_cannons_stuck_in_spawn}
					}
					{"delay"
						{time 2}
					}
					{"trigger"
						{name "ai_spawn_logic/order_usa_cannons_stuck_in_spawn"}
					}
				}
			}

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
												{prop sq_autocannon}
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
												{prop cannon}
											}
										}
									}
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
												{prop tank}
											}
											{prop
												{prop medium}
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
											{tag
												{tag "+mobilegun"}
											}
											{prop
												{prop cannon}
											}
											{prop
												{prop td}
											}
											{prop
												{prop "-turret"}
											}
											;{prop
											;	{prop sq_he_large}
											;}
											;{prop
											;	{prop sq_he_medium}
											;}
										}
									}
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
												{prop hetzer}
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
												{prop cannon}
											}
											{prop
												{prop sq_he_large}
											}
											{prop
												{prop sq_he_medium}
											}
										}
									}
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
												{prop mortar_carrier_mk1_boys}
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
												{prop cannon}
											}
											{prop
												{prop sq_he_large}
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
										{prop sq_autocannon}
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
										{prop cannon}
									}
								}
							}
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
										{prop tank}
									}
									{prop
										{prop medium}
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
									{tag
										{tag "+mobilegun"}
									}
									{prop
										{prop cannon}
									}
									{prop
										{prop td}
									}
									{prop
										{prop "-turret"}
									}
									;{prop
									;	{prop sq_he_large}
									;}
									;{prop
									;	{prop sq_he_medium}
									;}
								}
							}
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
										{prop hetzer}
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
										{prop cannon}
									}
									{prop
										{prop sq_he_large}
									}
									{prop
										{prop sq_he_medium}
									}
								}
							}
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
										{prop mortar_carrier_mk1_boys}
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
										{prop cannon}
									}
									{prop
										{prop sq_he_large}
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
							{time 2}
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
