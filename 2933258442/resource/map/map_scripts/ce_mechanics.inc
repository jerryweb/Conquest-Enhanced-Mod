			{"conquest_enhanced_mechanics/radio/enable_neutral_and_player_units_on_minimap"
				{condition
					{terms
						{"1.event"
							{id "init_radio_mechanics"}
						}
						{"2.event"
							{id "cut_communications"}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"ables"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag _user}
									}
								}
								{include
									{prop
										{prop vehicle}
									}
									{state
										{state chassis_work}
									}
								}
								{exclude
									{player
										{player "0"}
									}
									{prop
										{prop airborne}
									}
									{broken_components
										{masks
											"body"
										}
									}
									{destroyed_components
										{masks
											"body"
										}
									}
									{destroyed_components
										{masks
											"hull"
										}
									}
									{broken_components
										{masks
											"hull"
										}
									}
									{destroyed_components
										{masks
											"chassis"
										}
									}
									{broken_components
										{masks
											"chassis"
										}
									}
									{state
										{state inactive}
									}
									{state
										{state dead}
									}
									{tag
										{tag not_selectable}
									}
								}
							}
						}
						{add minimap}
					}
					{"delay"
						{time 15}
					}
					{"trigger"
						{name "conquest_enhanced_mechanics/radio/enable_neutral_and_player_units_on_minimap"}
					}
				}
			}
			{"conquest_enhanced_mechanics/radio/radio_init"
				{condition
					{terms
						{"1.cmp_i"
							{var "enable_ce_radio_mechanic$"}
							{op ">"}
							{value 0}
						}
					}
				}
				{actions
					{"delay"
						{time 30}
					}
					{"if"
						{condition
							{type cmp_i}
							{var "enable_ce_cut_communications_mechanic$"}
							{op "=="}
							{value 1}
						}
						{"event"
							{event "cut_communications"}
							{mode set}
							{delay 30}
						}
						{"delay"
							{time 30}
						}
						{"talk"
							{selector
								{ignore_captured_by_user 0}
								{amount 1
								}
								{tag player}
								{type human}
								{state "not dead"}
							}
							{text "mission/multi/radio_event"}
						}
						{"call"
							{function "show_radio_objective"}
						}
					}
					{"delay"
						{time 5}
					}
					{"if"
						{condition
							{type entities}
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag radio_operator}
										}
									}
									{include
										{state
											{state "operatable inhabited"}
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
											{state linked}
										}
									}
								}
								{group
									{select
										{tag
											{tag radio_operator}
										}
									}
									{include
										{prop
											{prop human}
										}
										{state
											{state operatable}
										}
										{state
											{state user_control}
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
						}
						{"set_i"
							{var "radio_active$"}
							{op "="}
							{value 1}
						}
					}
					{"delay"
						{time 1}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "radio_active$"}
								{op ">"}
								{value 0}
							}
							{"timer"
								{time 5}
								{title "mission/multi/enable_radio"}
							}
							{"call"
								{function "complete_radio_objective"}
							}
						}
						{"default"
							{"call"
								{function "alert_radio_down"}
							}
						}
					}
					{"event"
						{event "init_radio_mechanics"}
						{mode set}
						{delay 5}
					}
				}
			}
			{"conquest_enhanced_mechanics/radio/tag_player_radio_operator"
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
										{with_item
											{type existance}
											{item "ce_usa_radio"}
										}
										{state
											{state "operatable user_control"}
										}
									}
									{exclude
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{state
											{state dead}
										}
										{tag
											{tag radio_operator}
										}
									}
								}
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
										{with_item
											{type existance}
											{item "ce_eng_radio"}
										}
										{state
											{state "operatable user_control"}
										}
									}
									{exclude
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{state
											{state dead}
										}
										{tag
											{tag radio_operator}
										}
									}
								}
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
										{with_item
											{type existance}
											{item "ce_german_radio"}
										}
										{state
											{state "operatable user_control"}
										}
									}
									{exclude
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{state
											{state dead}
										}
										{tag
											{tag radio_operator}
										}
									}
								}
							}
						}
					}
				}
				{actions
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
										{prop human}
									}
									{with_item
										{type existance}
										{item "ce_usa_radio"}
									}
									{state
										{state "operatable user_control"}
									}
								}
								{exclude
									{state
										{state inactive}
									}
									{state
										{state linked}
									}
									{state
										{state dead}
									}
									{tag
										{tag radio_operator}
									}
								}
							}
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
									{with_item
										{type existance}
										{item "ce_eng_radio"}
									}
									{state
										{state "operatable user_control"}
									}
								}
								{exclude
									{state
										{state inactive}
									}
									{state
										{state linked}
									}
									{state
										{state dead}
									}
									{tag
										{tag radio_operator}
									}
								}
							}
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
									{with_item
										{type existance}
										{item "ce_german_radio"}
									}
									{state
										{state "operatable user_control"}
									}
								}
								{exclude
									{state
										{state inactive}
									}
									{state
										{state linked}
									}
									{state
										{state dead}
									}
									{tag
										{tag radio_operator}
									}
								}
							}
						}
						{tag_add radio_operator}
					}
					{"delay"
						{time 1}
					}
					{"effect"
						{selector
							{tag radio_operator}
							{zone "gamezone"}
							{type human}
							{state operatable}
						}
						{effect show_radio_icon}
					}
					{"delay"
						{time 0.5}
					}
					{"trigger"
						{name "conquest_enhanced_mechanics/radio/tag_player_radio_operator"}
					}
				}
			}
			{"conquest_enhanced_mechanics/radio/watch_radio_operators"
				{condition
					{terms
						{"1.event"
							{id "init_radio_mechanics"}
						}
					}
				}
				{actions
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag radio_operator}
											}
										}
										{include
											{prop
												{prop vehicle}
											}
											{state
												{state "operatable inhabited"}
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
												{state linked}
											}
										}
									}
									{group
										{select
											{tag
												{tag radio_operator}
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
							}
							{"if"
								{condition
									{type cmp_i}
									{var "radio_active$"}
									{op "=="}
									{value 0}
								}
								{"set_i"
									{var "radio_active$"}
									{op "="}
									{value 1}
								}
								{"call"
									{function "radio_came_up"}
								}
							}
						}
						{"default"
							{"if"
								{condition
									{type cmp_i}
									{var "radio_active$"}
									{op ">"}
									{value 0}
								}
								{"set_i"
									{var "radio_active$"}
									{op "="}
									{value 0}
								}
								{"call"
									{function "radio_went_down"}
								}
							}
						}
					}
					{"delay"
						{time 2}
					}
					{"if"
						{condition
							{type event}
							{id "cut_communications"}
						}
						{"call"
							{function "set_ai_minimap_ables"}
						}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "conquest_enhanced_mechanics/radio/watch_radio_operators"}
					}
				}
			}

			{"conquest_enhanced_mechanics/delete_empty_ai_emplacements"
				{condition
					{terms
						{"1.entities"
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
											{prop cannon}
										}
										{player
											{player "0"}
										}
										;{state
										;	{state operatable}
										;}
										;{tag
										;	{tag cmp_def}
										;}
									}
									{exclude
										{state
											{state inhabited}
										}
										{state
											{state linked}
										}
										{state
											{state dead}
										}
										{state
											{state user_control}
										}
									}
								}
							}
						}
						{"2.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 0}
						}
					}
				}
				{actions
					{## "timer"
						{time 10}
						{title "deleting empty cannons"}
					}
					{"delay"
						{time 10}
					}
					{"delete"
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
										{prop cannon}
									}
									{player
										{player "0"}
									}
									;{state
									;	{state operatable}
									;}
									;{tag
									;	{tag cmp_def}
									;}
								}
								{exclude
									{state
										{state inhabited}
									}
									{state
										{state linked}
									}
									{state
										{state dead}
									}
									{state
										{state user_control}
									}
								}
							}
						}
					}
				}
			}

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
								{var "tier2$"}
								{op "=="}
								{value 1}
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