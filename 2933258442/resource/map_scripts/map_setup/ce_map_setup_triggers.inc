			{## "debug/vars"
				{condition
					{terms
						{"1.cmp_i"
							{var "user_team$"}
							{op ">"}
							{value 0}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "enemyid$"}
								{op "=="}
								{value 1}
							}
							{"timer"
								{time 8}
								{title "enemid is 1"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "enemyid$"}
								{op "=="}
								{value 2}
							}
							{"timer"
								{time 8}
								{title "enemid is 2"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "enemyid$"}
								{op "=="}
								{value 3}
							}
							{"timer"
								{time 8}
								{title "enemid is 3"}
							}
						}
						{"default"
							{"timer"
								{time 8}
								{title "enemyid is above 3"}
							}
						}
					}
					{"delay"
						{time 7}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "user_is_defender$"}
								{op "=="}
								{value 0}
							}
							{"timer"
								{time 8}
								{title "user is defender == 0"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "user_is_defender$"}
								{op "=="}
								{value 1}
							}
							{"timer"
								{time 8}
								{title "user is defender == 1"}
							}
						}
						{"default"
							{"timer"
								{time 8}
								{title "user is defender not 0 or 1!"}
							}
						}
					}
					{"delay"
						{time 7}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "def_team$"}
								{op "=="}
								{value 1}
							}
							{"timer"
								{time 8}
								{title "def_team == 1 (a)"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "def_team$"}
								{op "=="}
								{value 2}
							}
							{"timer"
								{time 8}
								{title "def_team == 2(b)"}
							}
						}
						{"default"
							{"timer"
								{time 8}
								{title "DEF TEAM UNKNOWN"}
							}
						}
					}
					{"delay"
						{time 7}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "arrows$"}
								{op "=="}
								{value 1}
							}
							{"timer"
								{time 8}
								{title "arrows == 1(a)"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "arrows$"}
								{op "=="}
								{value 2}
							}
							{"timer"
								{time 8}
								{title "arrows == 2(b)"}
							}
						}
						{"default"
							{"timer"
								{time 8}
								{title "arrows invalid!"}
							}
						}
					}
					{"delay"
						{time 7}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "bot_army$"}
								{op "=="}
								{value 1}
							}
							{"timer"
								{time 8}
								{title "bot army==1 RUS"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "bot_army$"}
								{op "=="}
								{value 2}
							}
							{"timer"
								{time 8}
								{title "bot army==2 GER"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "bot_army$"}
								{op "=="}
								{value 3}
							}
							{"timer"
								{time 8}
								{title "bot army==3 FIN"}
							}
						}
						{"default"
							{"timer"
								{time 8}
								{title "bot army ABOVE 3!!!!"}
							}
						}
					}
					{"delay"
						{time 5}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "bot_mp_team$"}
								{op "=="}
								{value 1}
							}
							{"timer"
								{time 8}
								{title "bot_mp_team 1"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "bot_mp_team$"}
								{op "=="}
								{value 2}
							}
							{"timer"
								{time 8}
								{title "bot_mp_team 2"}
							}
						}
						{"default"
							{"timer"
								{time 8}
								{title "bot_mp_team INVALID"}
							}
						}
					}
					{"event"
						{event "ai_air_possible"}
						{mode set}
						{delay 0}
					}
					{"delay"
						{time 5}
					}
					{"set_i"
						{var "ai_air_on$"}
						{op "="}
						{value 1}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "ai_sabotage$"}
								{op "=="}
								{value 1}
							}
							{## "timer"
								{time 8}
								{title "ai_sabotage == true"}
							}
						}
						{"default"
							{## "timer"
								{time 8}
								{title "ai_sabotage not set in bot file"}
							}
						}
					}
				}
			}
			{## "debug/test_script"
				{condition
					{terms
						{"1.entities"
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag rocket_artillery}
									}
								}
								{include
									{state
										{state "operatable inhabited"}
									}
									{prop
										{prop cannon}
									}
									{tag
										{tag _bot}
									}
								}
								{exclude
									{tag
										{tag artillery_in_combat}
									}
									{state
										{state inactive}
									}
									{state
										{state linked}
									}
									{state
										{state user_control}
									}
									{tag
										{tag _user}
									}
									{tag
										{tag _user_ally}
									}
									{tag
										{tag player_veh}
									}
									{tag
										{tag rocket_arty_selected}
									}
								}
							}
						}
					}
				}
				{actions
					{##"delay"
						{time 15}
					}
					{"timer"
						{time 300}
						{title "rocket artillery exists"}
					}
					{## "squad_create"
						{selector
							{ignore_captured_by_user 0}
							{tag _bot}
							{zone "gamezone"}
							{state operatable}
						}
						{name test_squad}
					}
					{## "delay"
						{time 5}
					}
					{## "squad_dismiss"
						{squad test_squad}
					}
				}
			}
			{## "debug/test_flag"
				{condition
					{expression "(1 | 2) & 3"}
					{terms
						{"1.entities"
							{source advanced}
							{group
								{select
									{tag
										{tag flag_point}
									}
								}
								{include
									{zone
										{zone "fpc1"}
									}
								}
								{exclude
									{state
										{state inactive}
									}
								}
							}
						}
						{"2.entities"
							{source advanced}
							{group
								{select
									{tag
										{tag flag_point}
									}
								}
								{include
									{zone
										{zone "fpc2"}
									}
								}
								{exclude
									{state
										{state inactive}
									}
								}
							}
						}
						{"3.event"
							{id "enable_ai_attack_logic"}
						}
					}
				}
				{actions
					{##"delay"
						{time 15}
					}
					{"timer"
						{time 300}
						{title "flag exists"}
					}
					{## "squad_create"
						{selector
							{ignore_captured_by_user 0}
							{tag _bot}
							{zone "gamezone"}
							{state operatable}
						}
						{name test_squad}
					}
					{## "delay"
						{time 5}
					}
					{## "squad_dismiss"
						{squad test_squad}
					}
				}
			}

;============ MAP SETUP SCRIPTS========================================	
			{"conquest_enhanced_mechanics/ai_defenders/spawn_hedgehogs"
				{condition
					{terms
						{"1.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 0}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{zone
											{zone "combat"}
										}
									}
									{include
										{prop
											{prop logic_post}
										}
									}
								}
							}
						}
						{"3.event"
							{id "dcg"}
						}
					}
				}
				{actions
					{"delay"
						{time 15}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "defense_level$"}
								{op ">="}
								{value 3}
							}
							{"effect"
								{selector
									{source advanced}
									{group
										{select
											{zone
												{zone "combat"}
											}
										}
										{include
											{prop
												{prop logic_post}
											}
										}
									}
									{sort
										{type shuffle}
									}
									{amount 20
									}
								}
								{effect spawn_hedgehogs}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "defense_level$"}
								{op "=="}
								{value 2}
							}
							{"effect"
								{selector
									{source advanced}
									{group
										{select
											{zone
												{zone "combat"}
											}
										}
										{include
											{prop
												{prop logic_post}
											}
										}
									}
									{sort
										{type shuffle}
									}
									{amount 12
									}
								}
								{effect spawn_hedgehogs}
							}
						}
						{"default"
							{"effect"
								{selector
									{source advanced}
									{group
										{select
											{zone
												{zone "combat"}
											}
										}
										{include
											{prop
												{prop logic_post}
											}
										}
									}
									{sort
										{type shuffle}
									}
									{amount 8
									}
								}
								{effect spawn_hedgehogs}
							}
						}
					}
				}
			}
			{"conquest_enhanced_mechanics/disable_ai_waypoint_graph_logic"
				{condition
					{terms
						{"1.entities"
							{selector
								{tag disable_waypoint_graph}
							}
						}
					}
				}
				{actions
					{"entity_state"
						{selector
							{tag scene_variable}
						}
						{tag_add _lua_waypoint_graph_disabled}
					}
					{"set_i"
						{var "enable_ai_waypoint_graphs$"}
						{op "="}
						{value 0}
					}
					{## "timer"
						{time 5}
						{title "disabling ai waypoint graphs"}
					}
				}
			}
			{"check_if_grid_zones_exist"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{zone
											{zone "grid_a1"}
										}
										{zone
											{zone "grid_a2"}
										}
										{zone
											{zone "grid_a3"}
										}
										{zone
											{zone "grid_b1"}
										}
										{zone
											{zone "grid_b2"}
										}
										{zone
											{zone "grid_b3"}
										}
										{zone
											{zone "grid_c1"}
										}
										{zone
											{zone "grid_c2"}
										}
										{zone
											{zone "grid_c3"}
										}
									}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 3}
					}
					{"set_i"
						{var "ai_grid_system_active$"}
						{op "+"}
						{value 1}
					}
					{## "timer"
						{time 5}
						{title "AI grid system available"}
					}
				}
			}
			{"disable_netural_plane_minimap_icons"
				{condition
				}
				{actions
					{"delay"
						{time 3}
					}
					{"ables"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{zone
										{zone "gamezone"}
									}
								}
								{include
									{prop
										{prop airborne}
									}
								}
								{exclude
									{state
										{state inhabited}
									}
									{state
										{state inactive}
									}
								}
							}
						}
						{remove minimap}
					}	
				}
			}

;============ AI DEFENDER SETUP SCRIPTS========================================
			(define "delete_ai_defenders_thread" ;parms: flag_number
				{"thread"				
					{"while"
						{condition
							{type entities}
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag "%flag_a_1-3"}
										}
										{tag
											{tag "%flag_b_1-3"}
										}
										{tag
											{tag "%flag_a_2-3"}
										}
										{tag
											{tag "%flag_b_2-3"}
										}
										{tag
											{tag "%flag_a_3"}
										}
										{tag
											{tag "%flag_b_3"}
										}
									}
									{include
										{prop
											{prop human}
										}
										{tag
											{tag cmp_def}
										}
										{state
											{state operatable}
										}
									}
									{exclude
										{state
											{state dead}
										}	
										;{state
										;	{state inactive}
										;}
										{tag
											{tag "hidden"}
										}
										{state
											{state user_control}
										}
									}
								}
								{group
									{select
										{tag
											{tag "%flag_a_1-3"}
										}
										{tag
											{tag "%flag_b_1-3"}
										}
										{tag
											{tag "%flag_a_2-3"}
										}
										{tag
											{tag "%flag_b_2-3"}
										}
										{tag
											{tag "%flag_a_3"}
										}
										{tag
											{tag "%flag_b_3"}
										}
									}
									{include
										{prop
											{prop human}
										}
										{tag
											{tag _def}
										}
										{state
											{state operatable}
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
											{state user_control}
										}
									}
								}
							}
							{count
								{op ">"}
								{value "max_ai_defender_inf_per_flag_count$"}
							}
						}
						{"delete"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag "%flag_a_1-3"}
										}
										{tag
											{tag "%flag_b_1-3"}
										}
										{tag
											{tag "%flag_a_2-3"}
										}
										{tag
											{tag "%flag_b_2-3"}
										}
										{tag
											{tag "%flag_a_3"}
										}
										{tag
											{tag "%flag_b_3"}
										}
									}
									{include
										{prop
											{prop human}
										}
										{tag
											{tag cmp_def}
										}
										{state
											{state operatable}
										}
									}
									{exclude
										{state
											{state dead}
										}
										;{state
										;	{state inactive}
										;}
										{tag
											{tag "hidden"}
										}
										{state
											{state user_control}
										}
									}
								}
								{group
									{select
										{tag
											{tag "%flag_a_1-3"}
										}
										{tag
											{tag "%flag_b_1-3"}
										}
										{tag
											{tag "%flag_a_2-3"}
										}
										{tag
											{tag "%flag_b_2-3"}
										}
										{tag
											{tag "%flag_a_3"}
										}
										{tag
											{tag "%flag_b_3"}
										}
									}
									{include
										{prop
											{prop human}
										}
										{tag
											{tag _def}
										}
										{state
											{state operatable}
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
											{state user_control}
										}
									}
								}
								{amount 3
								}
							}
						}
						{"delay"
							{time 0.2}
						}
						{## "timer"
							{time 15}
							{title "Deleting extra AI defenders"}
						}
					}
				}
			)

			{"conquest_enhanced_mechanics/ai_defenders/tag_ai_defenders"
				{condition
					{terms
						{"1.cmp_i"
							{var "id_defenderbot$"}
							{op ">"}
							{value 0}
						}
					}
				}
				{actions
					{"delay"
						{time 10}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{zone
										{zone "gamezone"}
									}
								}
								{include
									{prop
										{prop vehicle}
									}
									{state
										{state "operatable inhabited"}
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
								}
							}
						}
						{tag_add _ai_defender}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_defender}
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
										{state inactive}
									}
									{state
										{state user_control}
									}
									{tag
										{tag _user}
									}
									{state
										{state linked}
									}
								}
							}
						}
						{tag_add no_scavenge}
					}
					{"delay"
						{time 0.1}
					}
					{"if"
						{condition
							{type cmp_i}
							{var "user_is_defender$"}
							{op "=="}
							{value 1}
						}
						{"effect"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _ai_defender}
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
											{state inactive}
										}
										{state
											{state user_control}
										}
										{tag
											{tag _user}
										}
										{state
											{state linked}
										}
									}
								}
							}
							{effect tag_user_ally}
						}
					}
					{"event"
						{event "ai_defender_vehicles_tagged"}
						{mode set}
						{delay 0}
					}
				}
			}
			{"conquest_enhanced_mechanics/ai_defenders/set_defense_level"
				{condition
					{terms
						{"1.cmp_i"
							{var "defense_level$"}
							{op "=="}
							{value 0}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
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
												{tag "1_a_3"}
											}
											{tag
												{tag "1_b_3"}
											}
											{tag
												{tag "2_a_3"}
											}
											{tag
												{tag "2_b_3"}
											}
											{tag
												{tag "3_a_3"}
											}
											{tag
												{tag "3_b_3"}
											}
											{tag
												{tag "4_a_3"}
											}
											{tag
												{tag "4_b_3"}
											}
											{tag
												{tag "5_a_3"}
											}
											{tag
												{tag "5_b_3"}
											}
										}
										{include
											;{prop
											;	{prop human}
											;}
											{tag
												{tag cmp_def}
											}
											{zone
												{zone "gamezone"}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{tag
												{tag hidden}
											}
											{state
												{state user_control}
											}
											{state
												{state inactive}
											}
											;{state
											;	{state linked}
											;}
										}
									}
								}
							}
							{"set_i"
								{var "defense_level$"}
								{op "="}
								{value 3}
							}
							{"delay"
								{time 0.5}
							}
							{"entity_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag flag_point}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
										}
										{exclude
											{state
												{state inactive}
											}
										}
									}
								}
								{tag_add defense_level_3}
							}
							{## "timer"
								{time 5}
								{title "tagging defense level 3"}
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
												{tag "1_a_2-3"}
											}
											{tag
												{tag "1_b_2-3"}
											}
											{tag
												{tag "2_a_2-3"}
											}
											{tag
												{tag "2_b_2-3"}
											}
											{tag
												{tag "3_a_2-3"}
											}
											{tag
												{tag "3_b_2-3"}
											}
											{tag
												{tag "4_a_2-3"}
											}
											{tag
												{tag "4_b_2-3"}
											}
											{tag
												{tag "5_a_2-3"}
											}
											{tag
												{tag "5_b_2-3"}
											}
										}
										{include
											;{prop
											;	{prop human}
											;}
											{tag
												{tag cmp_def}
											}
											{zone
												{zone "gamezone"}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{tag
												{tag hidden}
											}
											{state
												{state user_control}
											}
											{state
												{state inactive}
											}
											;{state
											;	{state linked}
											;}
										}
									}
								}
							}
							{"set_i"
								{var "defense_level$"}
								{op "="}
								{value 2}
							}
							{"delay"
								{time 0.5}
							}
							{"entity_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag flag_point}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
										}
										{exclude
											{state
												{state inactive}
											}
										}
									}
								}
								{tag_add defense_level_2}
							}
							{## "timer"
								{time 5}
								{title "tagging defense level 2"}
							}
						}
						{"default"
							{"set_i"
								{var "defense_level$"}
								{op "="}
								{value 1}
							}
							{## "timer"
								{time 5}
								{title "tagging defense level 1"}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"if"
						{condition
							{type cmp_i}
							{var "user_is_defender$"}
							{op "=="}
							{value 1}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag defense_level_3}
											}
											{tag
												{tag defense_level_2}
											}
										}
									}
								}
							}
							{"effect"
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
								}
								{effect call_flag_defense_crates}
							}
							{## "timer"
								{time 5}
								{title "calling defense crates"}
							}
						}
					}
				}
			}
			{"conquest_enhanced_mechanics/ai_defenders/balance_ai_defender_infantry"
				{condition
					{terms
						{"1.event"
							{id "ai_defender_vehicles_balanced"}
						}
					}
				}
				{actions
					{"delay"
						{time 3}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag cmp_def}
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
									{zone
										{zone "gamezone"}
									}
								}
							}
							{amount 10
							}
						}
						{tag_add not_delete}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{amount 10
							}
							{tag not_delete}
						}
						{inactive on}
					}
					{"if"
						{condition
							{type entities}
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag extra_inf_def}
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
										{zone
											{zone "gamezone"}
										}
										{state
											{state user_control}
										}
										{state
											{state linked}
										}
										{tag
											{tag _user}
										}
									}
								}
							}
						}
						{"while"
							{condition
								{type cmp_i}
								{var "current_ai_inf_def_x5_count$"}
								{op "<<"}
								{value "max_ai_inf_def_x5_count$"}
							}
							{"set_i"
								{var "current_ai_inf_def_x5_count$"}
								{op "+"}
								{value 1}
							}
							{"delay"
								{time 0.3}
							}
							{"call"
								{function "move_extra_ai_defenders_to_point"}
							}
							{"delay"
								{time 0.3}
							}
						}
					}
					{"delay"
						{time 0.2}
					}
					{"actor_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
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
										{tag not_delete}
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
										{state dead}
									}
									{state
										{state user_control}
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
						{move_mode hold}
						{move_radius 4}
						{weapon_prepare on}
					}
					{"delay"
						{time 0.2}
					}
					{"actor_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag cmp_def}
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
										{state linked}
									}
									{state
										{state user_control}
									}
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
									{tag
										{tag not_delete}
									}
								}
							}
						}
						{move_mode zone}
						{move_radius 20}
						{weapon_prepare on}
						{ai
							{advance_ratio 1}
							{retreat_ratio 5}
						}
					}
					{"delay"
						{time 0.2}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{zone
										{zone "gamezone"}
									}
									{tag
										{tag cmp_def}
									}
									{tag
										{tag _def}
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
										{state inactive}
									}
									{state
										{state user_control}
									}
									{tag
										{tag player}
									}
									{tag
										{tag _user}
									}
								}
							}
						}
						{tag_add ignore_spawn_logic}
					}
					{"if"
						{condition
							{type cmp_i}
							{var "user_is_defender$"}
							{op "=="}
							{value 1}
						}
						{"effect"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{zone
											{zone "gamezone"}
										}
										;{tag
										;	{tag cmp_def}
										;}
										;{tag
										;	{tag _def}
										;}
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
										;{state
										;	{state inactive}
										;}
										{state
											{state user_control}
										}
										{tag
											{tag player}
										}
										{tag
											{tag _user}
										}
									}
								}
							}
							{effect tag_user_ally}
						}
					}
					{"delay"
						{time 0.2}
					}
					{## "timer"
						{time 15}
						{title "Deleting extra AI defenders"}
					}
					("delete_ai_defenders_thread" flag(1))
					("delete_ai_defenders_thread" flag(2))
					("delete_ai_defenders_thread" flag(3))
					("delete_ai_defenders_thread" flag(4))
					("delete_ai_defenders_thread" flag(5))
					{"delay"
						{time 5}
					}
					{"delete"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag extra_inf_def}
									}
								}
								{include
									{prop
										{prop human}
									}
								}
								{exclude
									{zone
										{zone "gamezone"}
									}
								}
							}
						}
					}
					{"event"
						{event "ai_defender_inf_balanced"}
						{mode set}
						{delay 15}
					}
				}
			}
			{"conquest_enhanced_mechanics/ai_defenders/balance_ai_defender_veh"
				{condition
					{terms
						{"1.event"
							{id "ai_defender_vehicles_tagged"}
						}
					}
				}
				{actions
					{"delay"
						{time 2}
					}
					{"if"
						{condition
							{type cmp_i}
							{var "user_is_defender$"}
							{op "=="}
							{value 0}
						}
						{"switch"
							{"case"
								{condition
									{type cmp_i}
									{var "defense_level$"}
									{op ">="}
									{value 3}
								}
								{"set_i"
									{var "max_ai_defender_emplacement_total_count$"}
									{op "="}
									{value "max_ai_defender_emplacement_count_level_3$"}
								}
							}
							{"case"
								{condition
									{type cmp_i}
									{var "defense_level$"}
									{op "=="}
									{value 2}
								}
								{"set_i"
									{var "max_ai_defender_emplacement_total_count$"}
									{op "="}
									{value "max_ai_defender_emplacement_count_level_2$"}
								}
							}
							{"default"
								{"set_i"
									{var "max_ai_defender_emplacement_total_count$"}
									{op "="}
									{value "max_ai_defender_emplacement_count_level_1$"}
								}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"while"
						{condition
							{type entities}
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
											{state "operatable inhabited"}
										}
										{prop
											{prop vehicle}
										}
										{tag
											{tag _ai_defender}
										}
									}
									{exclude
										{state
											{state linked}
										}
										{state
											{state user_control}
										}
										{tag
											{tag hidden}
										}
										{prop
											{prop airborne}
										}
									}
								}
							}
							{count
								{op ">"}
								{value "max_ai_defender_emplacement_total_count$"}
							}
						}
						{"delete"
							{selector
								{source advanced}
								{group
									{select
										{zone
											{zone "gamezone"}
										}
									}
									{include
										{prop
											{prop vehicle}
										}
										{state
											{state "operatable inhabited"}
										}
										{tag
											{tag _ai_defender}
										}
									}
									{exclude
										{state
											{state user_control}
										}
										{tag
											{tag hidden}
										}
										{prop
											{prop airborne}
										}
									}
								}
								{amount 1
								}
							}
						}
						{"delay"
							{time 0.2}
						}
					}
					{"delay"
						{time 5}
					}
					{"event"
						{event "ai_defender_vehicles_balanced"}
						{mode set}
						{delay 0}
					}
				}
			}
			{"conquest_enhanced_mechanics/delete_untagged_humans"
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
										{tag
											{tag hidden}
										}
										{tag
											{tag _user_ally}
										}
										{tag
											{tag cmp_def}
										}
										{with_item
											{type existance}
											{item "weapon"}
										}
									}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 3}
					}
					{"delete"
						{selector
							{source advanced}
							{group
								{select
									{zone
										{zone "gamezone"}
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
									{tag
										{tag hidden}
									}
									{tag
										{tag _user_ally}
									}
									{tag
										{tag cmp_def}
									}
									{with_item
										{type existance}
										{item "weapon"}
									}
									{tag
										{tag _def}
									}
								}
							}
						}
					}
				}
			}

			

