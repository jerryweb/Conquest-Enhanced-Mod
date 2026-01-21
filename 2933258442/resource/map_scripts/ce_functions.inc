			(define "move_extra_ai_defenders_to_point_thread" ;parms: flag zone number, waypoint
				{"thread"
					{"if"
						{condition
							{type entities}
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag fpc%fpc}
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
						{"switch"
							{"case"
								{condition
									{type cmp_i}
									{var "user_is_defender$"}
									{op "=="}
									{value 0}
								}
								{"placement"
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
												{tag
													{tag hidden}
												}
											}
											{exclude
												{zone
													{zone "gamezone"}
												}
												{state
													{state linked}
												}
												{state
													{state user_control}
												}
												;{with_item
												;	{type existance}
												;	{item "at_rifle"}
												;}
												;{with_item
												;	{type existance}
												;	{item "rocketlauncher"}
												;}
											}
										}
										{amount 5
										}
									}
									{target_waypoint "%waypoint"}
									{clone}
								}
							}
							{"default"
								{"placement"
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
												{tag
													{tag hidden}
												}
											}
											{exclude
												{zone
													{zone "gamezone"}
												}
												{state
													{state linked}
												}
												{state
													{state user_control}
												}
												;{with_item
												;	{type existance}
												;	{item "at_rifle"}
												;}
												;{with_item
												;	{type existance}
												;	{item "rocketlauncher"}
												;}
											}
										}
										{amount 2
										}
									}
									{target_waypoint "%waypoint"}
									{clone}
								}
							}
						}
					}
				}
			)

;============ RADIO ========================================
			{"set_ai_minimap_ables"
				{"delay"
					{time 1}
				}
				{"switch"
					{"case"
						{condition
							{type cmp_i}
							{var "radio_active$"}
							{op "=="}
							{value 1}
						}
						{"ables"
							{selector
								{source advanced}
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
										{tag
											{tag _bot}
										}
									}
									{include
										{state
											{state operatable}
										}
									}
									{exclude
										{state
											{state inactive}
										}
										{player
											{player "0"}
										}
										{prop
											{prop airborne}
										}
									}
								}
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
										{tag
											{tag _bot}
										}
									}
									{include
										{state
											{state "operatable inhabited"}
										}
										{prop
											{prop airborne}
										}
									}
									{exclude
										{state
											{state inactive}
										}
										{player
											{player "0"}
										}
										
									}
								}
							}
							{add minimap}
						}
					}
					{"default"
						{"switch"
							{"case"
								{condition
									{type cmp_i}
									{var "user_is_defender$"}
									{op "=="}
									{value 1}
								}
								{"ables"
									{selector
										{source advanced}
										{group
											{select
												{zone
													{zone "gamezone"}
												}
												{zone_ex
													{zone "gamezone"}
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
												{tag
													{tag hidden}
												}
												{state
													{state user_control}
												}
												{tag
													{tag cmp_def}
												}
												{tag
													{tag _def}
												}
												{tag
													{tag _user_ally}
												}
												{player
													{player "0"}
												}
											}
										}
										{group
											{select
												{zone
													{zone "gamezone"}
												}
												{zone_ex
													{zone "gamezone"}
												}
											}
											{include
												{prop
													{prop vehicle}
												}
												{state
													{state inhabited}
												}
											}
											{exclude
												{tag
													{tag hidden}
												}
												{state
													{state user_control}
												}
												{tag
													{tag cmp_def}
												}
												{tag
													{tag _def}
												}
												{tag
													{tag _user_ally}
												}
												{player
													{player "0"}
												}
												{prop
													{prop airborne}
												}
											}
										}
									}
									{remove minimap}
								}
							}
							{"default"
								{## "ables"
									{selector
										{source advanced}
										{group
											{select
												{zone
													{zone "gamezone"}
												}
												{zone_ex
													{zone "gamezone"}
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
												{tag
													{tag hidden}
												}
												{state
													{state user_control}
												}
											}
										}
										{group
											{select
												{zone
													{zone "gamezone"}
												}
												{zone_ex
													{zone "gamezone"}
												}
											}
											{include
												{prop
													{prop vehicle}
												}
												{state
													{state inhabited}
												}
											}
											{exclude
												{tag
													{tag hidden}
												}
												{state
													{state user_control}
												}
											}
										}
									}
									{remove minimap}
								}
								{"ables"
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
											}
											{exclude
												{tag
													{tag hidden}
												}
												{state
													{state user_control}
												}
												{state
													{state inactive}
												}
												{state
													{state dead}
												}
												{prop
													{prop airborne}
												}
											}
										}
									}
									{remove minimap}
								}
							}
						}
					}
				}
				{"delay"
					{time 1}
				}
				{"ables"
					{selector
						{source advanced}
						{group
							{select
								{zone
									{zone "gamezone"}
								}
								{zone_ex
									{zone "gamezone"}
								}
							}
							{include
								{prop
									{prop vehicle}
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
								{prop
									{prop airborne}
								}
							}
						}
					}
					{add minimap}
				}
			}
			{"alert_radio_down"
				{"timer"
					{time 5}
					{title "mission/multi/disable_radio"}
				}
				{"sound"
					{name "interface/task_fail"}
				}
				{"delay"
					{time 3}
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
									{state user_control}
								}
								{prop
									{prop human}
								}
							}
						}
						{amount 1
						}
					}
					{text "mission/multi/radio_vehicle_unmanned"}
				}
			}
			
;============ AI ATTACK ========================================
			{"attack_player_ai_bomber"
				{"switch"
					{"case"
						{condition
							{type entities}
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _user}
										}
										{tag
											{tag _user_ally}
										}
									}
									{include
										{prop
											{prop heavy}
										}
										{prop
											{prop tank}
										}
										{state
											{state "operatable inhabited"}
										}
									}
									{exclude
										{tag
											{tag _bot}
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
						}
						{"entity_state"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _user}
										}
										{tag
											{tag _user_ally}
										}
									}
									{include
										{prop
											{prop heavy}
										}
										{prop
											{prop tank}
										}
										{state
											{state "operatable inhabited"}
										}
									}
									{exclude
										{tag
											{tag _bot}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
									}
								}
								{sort
									{type shuffle}
								}
								{amount 1
								}
							}
							{tag_add bomber_priority_target}
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
											{tag _user}
										}
										{tag
											{tag _user_ally}
										}
									}
									{include
										{state
											{state "operatable inhabited"}
										}
										{tag
											{tag radio_car}
										}
										{prop
											{prop vehicle}
										}
									}
									{exclude
										{tag
											{tag _bot}
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
						}
						{"entity_state"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _user}
										}
										{tag
											{tag _user_ally}
										}
									}
									{include
										{state
											{state "operatable inhabited"}
										}
										{tag
											{tag radio_car}
										}
										{prop
											{prop vehicle}
										}
									}
									{exclude
										{tag
											{tag _bot}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
									}
								}
								{sort
									{type shuffle}
								}
								{amount 1
								}
							}
							{tag_add bomber_priority_target}
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
											{tag _user}
										}
										{tag
											{tag _user_ally}
										}
									}
									{include
										{state
											{state "operatable inhabited"}
										}
										{tag
											{tag artillery}
										}
										{prop
											{prop vehicle}
										}
									}
									{exclude
										{tag
											{tag _bot}
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
						}
						{"entity_state"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _user}
										}
										{tag
											{tag _user_ally}
										}
									}
									{include
										{state
											{state "operatable inhabited"}
										}
										{tag
											{tag artillery}
										}
										{prop
											{prop vehicle}
										}
									}
									{exclude
										{tag
											{tag _bot}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
									}
								}
								{sort
									{type shuffle}
								}
								{amount 1
								}
							}
							{tag_add bomber_priority_target}
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
											{tag _user}
										}
										{tag
											{tag _user_ally}
										}
									}
									{include
										{prop
											{prop tank}
										}
										{state
											{state "operatable inhabited"}
										}
									}
									{exclude
										{tag
											{tag _bot}
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
						}
						{"entity_state"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _user}
										}
										{tag
											{tag _user_ally}
										}
									}
									{include
										{prop
											{prop tank}
										}
										{state
											{state "operatable inhabited"}
										}
									}
									{exclude
										{tag
											{tag _bot}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
									}
								}
								{sort
									{type shuffle}
								}
								{amount 1
								}
							}
							{tag_add bomber_priority_target}
						}
					}
					{"default"
						{"entity_state"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _user}
										}
										{tag
											{tag _user_ally}
										}
									}
									{include
										{state
											{state operatable}
										}
									}
									{exclude
										{tag
											{tag _bot}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{state
											{state dead}
										}
									}
								}
								{sort
									{type shuffle}
								}
								{amount 1
								}
							}
							{tag_add bomber_priority_target}
						}
					}
				}
				{"delay"
					{time 0.25}
				}
				{"air_attack"
					{drop orders}
					{enemies
						{amount 1
						}
						{tag bomber_priority_target}
						{zone "gamezone"}
						{state operatable}
					}
					{count 1}
					{random_weapon 0}
					{attack_altitude 55}
				}
				{"delay"
					{time 0.25}
				}
				{"entity_state"
					{selector
						{source standart}
						{tag bomber_priority_target}
					}
					{tag_remove bomber_priority_target}
				}
			}
			{"attack_player_ai_fighter"
				{"switch"
					{"case"
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
											{state user_control}
										}
									}
									{exclude
										{tag
											{tag _bot}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{state
											{state dead}
										}
									}
								}
							}
						}
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
											{state user_control}
										}
									}
									{exclude
										{tag
											{tag _bot}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{state
											{state dead}
										}
									}
								}
								{sort
									{type shuffle}
								}
								{amount 1
								}
							}
							{tag_add fighter_priority_target}
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
											{tag _user}
										}
										{tag
											{tag _user_ally}
										}
									}
									{include
										{state
											{state "operatable inhabited"}
										}
										{prop
											{prop cannon}
										}
									}
									{exclude
										{tag
											{tag _bot}
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
						}
						{"entity_state"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _user}
										}
										{tag
											{tag _user_ally}
										}
									}
									{include
										{state
											{state "operatable inhabited"}
										}
										{prop
											{prop cannon}
										}
									}
									{exclude
										{tag
											{tag _bot}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
									}
								}
								{sort
									{type shuffle}
								}
								{amount 1
								}
							}
							{tag_add fighter_priority_target}
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
											{tag _user}
										}
										{tag
											{tag _user_ally}
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
										{tag
											{tag _bot}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{state
											{state dead}
										}
									}
								}
							}
						}
						{"entity_state"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _user}
										}
										{tag
											{tag _user_ally}
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
										{tag
											{tag _bot}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{state
											{state dead}
										}
									}
								}
								{sort
									{type shuffle}
								}
								{amount 1
								}
							}
							{tag_add fighter_priority_target}
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
											{tag _user}
										}
										{tag
											{tag _user_ally}
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
										{tag
											{tag _bot}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{state
											{state dead}
										}
									}
								}
							}
						}
						{"entity_state"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _user}
										}
										{tag
											{tag _user_ally}
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
										{tag
											{tag _bot}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{state
											{state dead}
										}
									}
								}
								{sort
									{type shuffle}
								}
								{amount 1
								}
							}
							{tag_add fighter_priority_target}
						}
					}
					{"default"
						{"entity_state"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _user}
										}
										{tag
											{tag _user_ally}
										}
									}
									{include
										{state
											{state operatable}
										}
									}
									{exclude
										{tag
											{tag _bot}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{state
											{state dead}
										}
									}
								}
								{sort
									{type shuffle}
								}
								{amount 1
								}
							}
							{tag_add fighter_priority_target}
						}
					}
				}
				{"delay"
					{time 0.25}
				}
				{"air_attack"
					{drop orders}
					{enemies
						{amount 1
						}
						{tag fighter_priority_target}
						{zone "gamezone"}
					}
					{count 1}
					{random_weapon 0}
					{attack_altitude 35}
				}
				{"delay"
					{time 0.25}
				}
				{"entity_state"
					{selector
						{source standart}
						{tag fighter_priority_target}
					}
					{tag_remove fighter_priority_target}
				}
			}

;============ AI ARTILLERY ========================================
			{"alert_player_of_signaller"
				{"switch"
					{"case"
						{condition
							{type rand}
							{value 0.33}
						}
						{"talk"
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
											{prop human}
										}
										{state
											{state user_control}
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
									}
								}
								{amount 1
								}
							}
							{text "mission/multi/enemy_artillery_signaler_on_field_1"}
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
								{ignore_captured_by_user 0}
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
											{state user_control}
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
									}
								}
								{amount 1
								}
							}
							{text "mission/multi/enemy_artillery_signaler_on_field_2"}
						}
					}
					{"default"
						{"talk"
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
											{prop human}
										}
										{state
											{state user_control}
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
									}
								}
								{amount 1
								}
							}
							{text "mission/multi/enemy_artillery_signaler_on_field_3"}
						}
					}
				}
			}
			{"check_if_player_in_flag_zones"
				{"if"
					{condition
						{type entities}
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _user}
									}
									{tag
										{tag _user_ally}
									}
								}
								{include
									{zone
										{zone "fpc1"}
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
									{tag
										{tag _bot}
									}
								}
							}
						}
					}
					{"entity_state"
						{selector
							{source standart}
							{amount 1
							}
							{tag fpc1}
							{zone "fpc1"}
						}
						{tag_add possible_flag_for_cannon_artillery_attack}
					}
				}
				{"if"
					{condition
						{type entities}
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _user}
									}
									{tag
										{tag _user_ally}
									}
								}
								{include
									{zone
										{zone "fpc2"}
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
									{tag
										{tag _bot}
									}
								}
							}
						}
					}
					{"entity_state"
						{selector
							{source standart}
							{amount 1
							}
							{tag fpc2}
							{zone "fpc2"}
						}
						{tag_add possible_flag_for_cannon_artillery_attack}
					}
				}
				{"if"
					{condition
						{type entities}
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _user}
									}
									{tag
										{tag _user_ally}
									}
								}
								{include
									{zone
										{zone "fpc3"}
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
									{tag
										{tag _bot}
									}
								}
							}
						}
					}
					{"entity_state"
						{selector
							{source standart}
							{amount 1
							}
							{tag fpc3}
							{zone "fpc3"}
						}
						{tag_add possible_flag_for_cannon_artillery_attack}
					}
				}
				{"if"
					{condition
						{type entities}
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _user}
									}
									{tag
										{tag _user_ally}
									}
								}
								{include
									{zone
										{zone "fpc4"}
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
									{tag
										{tag _bot}
									}
								}
							}
						}
					}
					{"entity_state"
						{selector
							{source standart}
							{amount 1
							}
							{tag fpc4}
							{zone "fpc4"}
						}
						{tag_add possible_flag_for_cannon_artillery_attack}
					}
				}
				{"if"
					{condition
						{type entities}
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _user}
									}
									{tag
										{tag _user_ally}
									}
								}
								{include
									{zone
										{zone "fpc5"}
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
									{tag
										{tag _bot}
									}
								}
							}
						}
					}
					{"entity_state"
						{selector
							{source standart}
							{amount 1
							}
							{tag fpc5}
							{zone "fpc5"}
						}
						{tag_add possible_flag_for_cannon_artillery_attack}
					}
				}
			}
			{"check_if_player_in_flag_zones_for_spg_artillery"
				{"if"
					{condition
						{type entities}
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _user}
									}
									{tag
										{tag _user_ally}
									}
								}
								{include
									{zone
										{zone "fpc1"}
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
									{tag
										{tag _bot}
									}
								}
							}
						}
					}
					{"entity_state"
						{selector
							{source standart}
							{amount 1
							}
							{tag fpc1}
							{zone "fpc1"}
						}
						{tag_add possible_flag_for_spg_cannon_artillery_attack}
					}
				}
				{"if"
					{condition
						{type entities}
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _user}
									}
									{tag
										{tag _user_ally}
									}
								}
								{include
									{zone
										{zone "fpc2"}
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
									{tag
										{tag _bot}
									}
								}
							}
						}
					}
					{"entity_state"
						{selector
							{source standart}
							{amount 1
							}
							{tag fpc2}
							{zone "fpc2"}
						}
						{tag_add possible_flag_for_spg_cannon_artillery_attack}
					}
				}
				{"if"
					{condition
						{type entities}
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _user}
									}
									{tag
										{tag _user_ally}
									}
								}
								{include
									{zone
										{zone "fpc3"}
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
									{tag
										{tag _bot}
									}
								}
							}
						}
					}
					{"entity_state"
						{selector
							{source standart}
							{amount 1
							}
							{tag fpc3}
							{zone "fpc3"}
						}
						{tag_add possible_flag_for_spg_cannon_artillery_attack}
					}
				}
				{"if"
					{condition
						{type entities}
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _user}
									}
									{tag
										{tag _user_ally}
									}
								}
								{include
									{zone
										{zone "fpc4"}
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
									{tag
										{tag _bot}
									}
								}
							}
						}
					}
					{"entity_state"
						{selector
							{source standart}
							{amount 1
							}
							{tag fpc4}
							{zone "fpc4"}
						}
						{tag_add possible_flag_for_spg_cannon_artillery_attack}
					}
				}
				{"if"
					{condition
						{type entities}
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _user}
									}
									{tag
										{tag _user_ally}
									}
								}
								{include
									{zone
										{zone "fpc5"}
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
									{tag
										{tag _bot}
									}
								}
							}
						}
					}
					{"entity_state"
						{selector
							{source standart}
							{amount 1
							}
							{tag fpc5}
							{zone "fpc5"}
						}
						{tag_add possible_flag_for_spg_cannon_artillery_attack}
					}
				}
			}

;============ AI REPAIR ========================================
			{"ai_repair_vehicle"
				{"effect"
					{effect prep_to_repair_veh}
				}
				{"delay"
					{time 0.5}
				}
				{"select"
					{source advanced}
					{group
						{select
							{tag
								{tag action_repair}
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
							{tag
								{tag player}
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
						}
					}
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
									{tag body_break}
								}
								{tag
									{tag engine_brake}
								}
								{tag
									{tag turret_brake}
								}
								{tag
									{tag immobile}
								}
								{tag
									{tag gun_brake}
								}
							}
							{include
								{prop
									{prop vehicle}
								}
								{zone
									{zone "gamezone"}
								}
							}
							{exclude
								{destroyed_components
									{masks
										"body"
									}
								}
								{prop
									{prop airborne}
								}
								{tag
									{tag destroyed}
								}
								{prop
									{prop ammo_point}
								}
								{prop
									{prop parachute_attach}
								}
								{tag
									{tag repair_target}
								}
								{tag
									{tag ignore_repair}
								}
								{tag
									{tag not_selectable}
								}
								{state
									{state user_control}
								}
								{tag
									{tag ammo_cooked}
								}
								{tag
									{tag _user_ally}
								}
								{tag
									{tag _user}
								}
							}
						}
						{sort
							{type entity}
							{entity
								{amount 1
								}
								{tag action_repair}
								{zone "gamezone"}
								{type human}
								{state "not dead"}
							}
						}
						{amount 1
						}
					}
					{tag_add repair_target}
				}
				{"delay"
					{time 1}
				}
				{"action"
					{drop orders}
					{action repair}
					{target
						{amount 1
						}
						{tag repair_target}
						{zone "gamezone"}
						{type vehicle}
					}
				}
				{"actor_state"
					{movement
						{speed assault}
						{kind fast}
					}
				}
				{"delay"
					{time 1}
				}
				{"effect"
					{selector
						{source standart}
						{tag repair_target}
					}
					{effect ignore_repair_75}
				}
				{"delay"
					{time 1}
				}
				{"entity_state"
					{tag_remove action_repair}
				}
			}

;============ AUTO RESUPPLY ========================================
			{"send_auto_resupply"
				{"entity_state"
					{tag_add action_resupply}
				}
				{"delay"
					{time 0.25}
				}
				{"actor_state"
					{selector
						{source standart}
						{tag action_resupply}
						{type human}
						{state "not dead"}
					}
					{drop orders}
					{movement
						{speed fast}
						{kind fast}
					}
				}
				{"delay"
					{time 0.25}
				}
				{"action"
					{selector
						{source standart}
						{tag action_resupply}
						{type human}
						{state "not dead"}
					}
					{action move}
					{target
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
						{sort
							{type entity}
							{entity
								{source advanced}
								{group
									{select
										{tag
											{tag action_resupply}
										}
									}
									{exclude
										{tag
											{tag ignore_auto_resupply}
										}
										{tag
											{tag not_selectable}
										}
									}
								}
							}
						}
						{amount 1
						}
					}
				}
				{"delay"
					{time 0.25}
				}
				{"effect"
					{selector
						{source standart}
						{tag action_resupply}
						{type human}
						{state "not dead"}
					}
					{effect ignore_auto_resupply_30}
				}
			}

;============ AI SPAWN LOGIC  ========================================
			{"ai_spawn_inf_settings"
				{"actor_state"
					{fire_mode open}
					{move_mode free}
					{weapon_prepare on}
					{ai_move
						{mode enable}
					}
					{movement
						{speed assault}
					}
					;{ai
					;	{advance_ratio "3"}
					;}
				}
				{"delay"
					{time 0.5}
				}
				{"effect"
					{effect set_ignore_spawn_logic}
				}
			}
			{"ai_rear_attack_notify"
				{"sound"
					{name "interface/morse"}
				}
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
										{tag
											{tag player}
										}
										{zone
											{zone "gamezone"}
										}
									}
									{include
										{prop
											{prop human}
										}
										{state
											{state user_control}
										}
									}
								}
								{amount 1
								}
							}
							{text "mission/multi/rear_attack_1"}
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
										{tag
											{tag player}
										}
										{zone
											{zone "gamezone"}
										}
									}
									{include
										{prop
											{prop human}
										}
										{state
											{state user_control}
										}
									}
								}
								{amount 1
								}
							}
							{text "mission/multi/rear_attack_2"}
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
										{tag
											{tag player}
										}
									}
									{include
										{state
											{state user_control}
										}
										{prop
											{prop human}
										}
									}
								}
								{amount 1
								}
							}
							{text "mission/multi/rear_attack_3"}
						}
					}
				}
				{"entity_state"
					{selector
						{source advanced}
						{group
							{select
								{tag
									{tag arrow_enemy}
								}
							}
						}
					}
					{tag_remove hidden}
					{inactive on}
				}
				{"delay"
					{time 1}
				}
				{"spawn"
					{entity "conquest_spawn_indicator"}
					{waypoint "1001"}
				}
				{"spawn"
					{entity "conquest_spawn_indicator"}
					{waypoint "1002"}
				}
				{"spawn"
					{entity "conquest_spawn_indicator"}
					{waypoint "1003"}
				}
				{"spawn"
					{entity "conquest_spawn_indicator"}
					{waypoint "1004"}
				}
				{"spawn"
					{entity "conquest_spawn_indicator"}
					{waypoint "2001"}
				}
				{"spawn"
					{entity "conquest_spawn_indicator"}
					{waypoint "2002"}
				}
				{"spawn"
					{entity "conquest_spawn_indicator"}
					{waypoint "2003"}
				}
				{"spawn"
					{entity "conquest_spawn_indicator"}
					{waypoint "2004"}
				}				
				{"delay"
					{time 300}
				}
				{"entity_state"
					{selector
						{source advanced}
						{group
							{select
								{tag
									{tag arrow_enemy}
								}
							}
						}
					}
					{inactive on}
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
									{tag arrow_enemy}
								}
							}
						}
					}
					{tag_remove hidden}
					{inactive off}
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
									{tag arrow_enemy}
								}
							}
						}
					}
					{inactive on}
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
									{tag arrow_enemy}
								}
							}
						}
					}
					{inactive off}
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
									{tag arrow_enemy}
								}
							}
						}
					}
					{inactive on}
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
									{tag arrow_enemy}
								}
							}
						}
					}
					{inactive off}
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
									{tag arrow_enemy}
								}
							}
						}
					}
					{inactive on}
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
									{tag arrow_enemy}
								}
							}
						}
					}
					{inactive off}
				}	
			}
			{"reset_ai_spawn_new"
				{"switch"
					{"case"
						{condition
							{type cmp_i}
							{var "user_team$"}
							{op "=="}
							{value 2}
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
								{amount 1
								}
							}
							{target_waypoint "1002"}
						}
						{"delay"
							{time 1}
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
								{amount 1
								}
							}
							{target_waypoint "1003"}
						}
						{"delay"
							{time 1}
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
								{amount 1
								}
							}
							{target_waypoint "1004"}
						}
					}
					{"default"
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
								{amount 1
								}
							}
							{target_waypoint "2002"}
						}
						{"delay"
							{time 1}
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
								{amount 1
								}
							}
							{target_waypoint "2003"}
						}
						{"delay"
							{time 1}
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
								{amount 1
								}
							}
							{target_waypoint "2004"}
						}
					}
				}
				{"delay"
					{time 1}
				}
				{## "entity_state"
					{selector
						{source advanced}
						{group
							{select
								{tag
									{tag scene_variable}
								}
							}
						}
					}
					{tag_add _lua_waypoint_graph_enabled}
				}
				{## "if"
					{condition
						{type entities}
						{selector
							{ignore_captured_by_user 0}
							{tag waypoint_graph_disable}
						}
						{count
							{op "=="}
							{value 0}
						}
					}
					{"if"
						{condition
							{type trigger}
							{mode off}
							{name "ai_spawn_logic/manual_disable_ai_waypoint_graph_logic"}
						}
						{"set_i"
							{var "enable_ai_waypoint_graphs$"}
							{op "="}
							{value 1}
						}
					}
				}
			}
			{"move_ai_spawns_to_rear"
				{"switch"
					{"case"
						{condition
							{type cmp_i}
							{var "user_team$"}
							{op "=="}
							{value 1}
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
								{amount 1
								}
							}
							{target_waypoint "1001"}
						}
						{"delay"
							{time 1}
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
								{amount 1
								}
							}
							{target_waypoint "1002"}
						}
						{"delay"
							{time 1}
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
								{amount 1
								}
							}
							{target_waypoint "1003"}
						}
						{"delay"
							{time 1}
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
								{amount 1
								}
							}
							{target_waypoint "1004"}
						}
					}
					{"default"
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
								{amount 1
								}
							}
							{target_waypoint "2001"}
						}
						{"delay"
							{time 1}
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
								{amount 1
								}
							}
							{target_waypoint "2002"}
						}
						{"delay"
							{time 1}
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
								{amount 1
								}
							}
							{target_waypoint "2003"}
						}
						{"delay"
							{time 1}
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
								{amount 1
								}
							}
							{target_waypoint "2004"}
						}
					}
				}
				{"delay"
					{time 1}
				}
				{## "entity_state"
					{selector
						{source advanced}
						{group
							{select
								{tag
									{tag scene_variable}
								}
							}
						}
					}
					{tag_add _lua_waypoint_graph_disabled}
				}
				{## "set_i"
					{var "enable_ai_waypoint_graphs$"}
					{op "="}
					{value 0}
				}
			}
			{"alert_ai_strategy"
				{"switch"
					{"case"
						{condition
							{type cmp_i}
							{var "ai_strategy_selection$"}
							{op "=="}
							{value 1}
						}
						{"switch"
							{"case"
								{condition
									{type rand}
									{value 0.25}
								}
								{"delay"
									{time 0.1}
								}
								{"talk"
									{selector
										{source standart}
										{amount 1
										}
										{tag player}
										{zone "gamezone"}
										{type human}
										{state "not dead"}
									}
									{text "mission/multi/player_enemy_division_notification_massinf_01"}
								}
							}
							{"case"
								{condition
									{type rand}
									{value 0.25}
								}
								{"delay"
									{time 0.1}
								}
								{"talk"
									{selector
										{source standart}
										{amount 1
										}
										{tag player}
										{zone "gamezone"}
										{type human}
										{state "not dead"}
									}
									{text "mission/multi/player_enemy_division_notification_massinf_02"}
								}
							}
							{"case"
								{condition
									{type rand}
									{value 0.25}
								}
								{"delay"
									{time 0.1}
								}
								{"talk"
									{selector
										{source standart}
										{amount 1
										}
										{tag player}
										{zone "gamezone"}
										{type human}
										{state "not dead"}
									}
									{text "mission/multi/player_enemy_division_notification_massinf_03"}
								}
							}
							{"default"
								{"delay"
									{time 0.1}
								}
								{"talk"
									{selector
										{source standart}
										{amount 1
										}
										{tag player}
										{zone "gamezone"}
										{type human}
										{state "not dead"}
									}
									{text "mission/multi/player_enemy_division_notification_massinf_04"}
								}
							}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "ai_strategy_selection$"}
							{op "=="}
							{value 2}
						}
						{"switch"
							{"case"
								{condition
									{type rand}
									{value 0.33}
								}
								{"delay"
									{time 0.1}
								}
								{"talk"
									{selector
										{source standart}
										{amount 1
										}
										{tag player}
										{zone "gamezone"}
										{type human}
										{state "not dead"}
									}
									{text "mission/multi/player_enemy_division_notification_artillery_01"}
								}
							}
							{"case"
								{condition
									{type rand}
									{value 0.33}
								}
								{"delay"
									{time 0.1}
								}
								{"talk"
									{selector
										{source standart}
										{amount 1
										}
										{tag player}
										{zone "gamezone"}
										{type human}
										{state "not dead"}
									}
									{text "mission/multi/player_enemy_division_notification_artillery_02"}
								}
							}
							{"default"
								{"delay"
									{time 0.1}
								}
								{"talk"
									{selector
										{source standart}
										{amount 1
										}
										{tag player}
										{zone "gamezone"}
										{type human}
										{state "not dead"}
									}
									{text "mission/multi/player_enemy_division_notification_massinf_03"}
								}
							}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "ai_strategy_selection$"}
							{op "=="}
							{value 3}
						}
						{"switch"
							{"case"
								{condition
									{type rand}
									{value 0.17}
								}
								{"delay"
									{time 0.1}
								}
								{"talk"
									{selector
										{source standart}
										{amount 1
										}
										{tag player}
										{zone "gamezone"}
										{type human}
										{state "not dead"}
									}
									{text "mission/multi/player_enemy_division_notification_airborne_01"}
								}
							}
							{"case"
								{condition
									{type rand}
									{value 0.17}
								}
								{"delay"
									{time 0.1}
								}
								{"talk"
									{selector
										{source standart}
										{amount 1
										}
										{tag player}
										{zone "gamezone"}
										{type human}
										{state "not dead"}
									}
									{text "mission/multi/player_enemy_division_notification_airborne_02"}
								}
							}
							{"case"
								{condition
									{type rand}
									{value 0.17}
								}
								{"delay"
									{time 0.1}
								}
								{"talk"
									{selector
										{source standart}
										{amount 1
										}
										{tag player}
										{zone "gamezone"}
										{type human}
										{state "not dead"}
									}
									{text "mission/multi/player_enemy_division_notification_airborne_03"}
								}
							}
							{"case"
								{condition
									{type rand}
									{value 0.17}
								}
								{"delay"
									{time 0.1}
								}
								{"talk"
									{selector
										{source standart}
										{amount 1
										}
										{tag player}
										{zone "gamezone"}
										{type human}
										{state "not dead"}
									}
									{text "mission/multi/player_enemy_division_notification_airborne_04"}
								}
							}
							{"case"
								{condition
									{type rand}
									{value 0.17}
								}
								{"delay"
									{time 0.1}
								}
								{"talk"
									{selector
										{source standart}
										{amount 1
										}
										{tag player}
										{zone "gamezone"}
										{type human}
										{state "not dead"}
									}
									{text "mission/multi/player_enemy_division_notification_airborne_05"}
								}
							}
							{"default"
								{"delay"
									{time 0.1}
								}
								{"talk"
									{selector
										{source standart}
										{amount 1
										}
										{tag player}
										{zone "gamezone"}
										{type human}
										{state "not dead"}
									}
									{text "mission/multi/player_enemy_division_notification_airborne_06"}
								}
							}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "ai_strategy_selection$"}
							{op "=="}
							{value 4}
						}
						{"switch"
							{"case"
								{condition
									{type rand}
									{value 0.33}
								}
								{"delay"
									{time 0.1}
								}
								{"talk"
									{selector
										{source standart}
										{amount 1
										}
										{tag player}
										{zone "gamezone"}
										{type human}
										{state "not dead"}
									}
									{text "mission/multi/player_enemy_division_notification_heavy_01"}
								}
							}
							{"case"
								{condition
									{type rand}
									{value 0.33}
								}
								{"delay"
									{time 0.1}
								}
								{"talk"
									{selector
										{source standart}
										{amount 1
										}
										{tag player}
										{zone "gamezone"}
										{type human}
										{state "not dead"}
									}
									{text "mission/multi/player_enemy_division_notification_heavy_02"}
								}
							}
							{"default"
								{"delay"
									{time 0.1}
								}
								{"talk"
									{selector
										{source standart}
										{amount 1
										}
										{tag player}
										{zone "gamezone"}
										{type human}
										{state "not dead"}
									}
									{text "mission/multi/player_enemy_division_notification_heavy_03"}
								}
							}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "ai_strategy_selection$"}
							{op "=="}
							{value 5}
						}
						{"switch"
							{"case"
								{condition
									{type rand}
									{value 0.33}
								}
								{"delay"
									{time 0.1}
								}
								{"talk"
									{selector
										{source standart}
										{amount 1
										}
										{tag player}
										{zone "gamezone"}
										{type human}
										{state "not dead"}
									}
									{text "mission/multi/player_enemy_division_notification_armored_01"}
								}
							}
							{"case"
								{condition
									{type rand}
									{value 0.33}
								}
								{"delay"
									{time 0.1}
								}
								{"talk"
									{selector
										{source standart}
										{amount 1
										}
										{tag player}
										{zone "gamezone"}
										{type human}
										{state "not dead"}
									}
									{text "mission/multi/player_enemy_division_notification_armored_02"}
								}
							}
							{"default"
								{"delay"
									{time 0.1}
								}
								{"talk"
									{selector
										{source standart}
										{amount 1
										}
										{tag player}
										{zone "gamezone"}
										{type human}
										{state "not dead"}
									}
									{text "mission/multi/player_enemy_division_notification_armored_03"}
								}
							}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "ai_strategy_selection$"}
							{op "=="}
							{value 6}
						}
						{"switch"
							{"case"
								{condition
									{type rand}
									{value 0.5}
								}
								{"delay"
									{time 0.1}
								}
								{"talk"
									{selector
										{source standart}
										{amount 1
										}
										{tag player}
										{zone "gamezone"}
										{type human}
										{state "not dead"}
									}
									{text "mission/multi/player_enemy_division_notification_elite_01"}
								}
							}
							{"default"
								{"delay"
									{time 0.1}
								}
								{"talk"
									{selector
										{source standart}
										{amount 1
										}
										{tag player}
										{zone "gamezone"}
										{type human}
										{state "not dead"}
									}
									{text "mission/multi/player_enemy_division_notification_elite_02"}
								}
							}
						}
					}
				}
			}
									
;============ MISC ========================================
			{"move_extra_ai_defenders_to_point"
				("move_extra_ai_defenders_to_point_thread" fpc(1) waypoint(1))
				("move_extra_ai_defenders_to_point_thread" fpc(2) waypoint(2))
				("move_extra_ai_defenders_to_point_thread" fpc(3) waypoint(3))
				("move_extra_ai_defenders_to_point_thread" fpc(4) waypoint(4))
				("move_extra_ai_defenders_to_point_thread" fpc(5) waypoint(5))
			}
			{"sabotage_ai_veh_function"
				{"delay"
					{time 15}
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
								{prop
									{prop human}
								}
								{state
									{state linked}
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
								{tag
									{tag _user_ally}
								}
							}
						}
						{amount 1
						}
					}
					{text "mission/multi/ai_sabotage_notify"}
				}
				{"delay"
					{time 10}
				}
				{"talk"
					{selector
						{source advanced}
						{group
							{select
								{zone
									{zone "gamezone"}
								}
								{tag
									{tag player}
								}
							}
							{include
								{prop
									{prop human}
								}
								{state
									{state user_control}
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
							}
						}
						{amount 1
						}
					}
					{text "mission/multi/player_sabotage_notify"}
				}
			}
			{"recon_random_flag"
				{"loop" 6
					{"action"
						{action advance}
						{target
							{amount 1
							}
							{tag drop_zone}
							{zone "gamezone"}
						}
					}
					{"delay"
						{time 0.2}
					}
				}
				{## "entity_state"
					{tag_add patrolling}
					{tag_remove go_patrol}
				}
			}
			{"attack_selected_flag"
				{"delay"
					{time 10}
				}
				{"effect"
					{effect tag_squad_need_next_order}
				}
			}			