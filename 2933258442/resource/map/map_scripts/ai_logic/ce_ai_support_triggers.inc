; File created by Hawka
;==========================================================================================================
			{"ai_support/set_player"
				{condition
					{terms
						{"2.entities"
							{selector
								{source advanced}
								{group
									{include
										{player
											{player "0"}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
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
										{zone
											{zone "gamezone"}
										}
										{tag
											{tag ai_support_selected}
										}
										{tag
											{tag _ai_support_for_user}
										}
									}
								}
							}
							{count
								{op ">"}
								{value 8}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 2.5}
					}
					{"effect"
						{selector
							{source advanced}
							{group
								{include
									{player
										{player "0"}
									}
									{state
										{state operatable}
									}
									{prop
										{prop human}
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
									{zone
										{zone "gamezone"}
									}
									{tag
										{tag ai_support_selected}
									}
									{tag
										{tag _ai_support_for_user}
									}
								}
							}
							{sort
								{type entity}
								{entity
									{amount 1
									}
									{tag spawn_anchor}
									{player "2"}
								}
							}
							{amount 12
							}
						}
						{effect set_ai_support_unit_for_user}
					}
					{"delay"
						{time 0.2}
					}
					{"select"
						{tag ai_support_selected}
						{type human}
						{state "not dead"}
					}
					{"delay"
						{time 0.2}
					}
					{"player"
						{selector
							{source current}
						}
						{drop orders}
						{operation set}
						{player "2"}
					}
					{"delay"
						{time 0.2}
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
												{tag radio_operator}
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
										{exclude
											{state
												{state dead}
											}
											{state
												{state linked}
											}
											{state
												{state inactive}
											}
											{tag
												{tag _bot}
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
											{state
												{state "operatable inhabited user_control"}
											}
											{prop
												{prop vehicle}
											}
										}
										{exclude
											{state
												{state linked}
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
							{"action"
								{selector
									{source current}
								}
								{action move}
								{target
									{amount 1
									}
									{tag radio_operator}
									{zone "gamezone"}
									{state operatable}
								}
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
												{tag officer}
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
										{exclude
											{state
												{state dead}
											}
											{state
												{state linked}
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
							{"action"
								{selector
									{source current}
								}
								{action move}
								{target
									{amount 1
									}
									{tag officer}
									{zone "gamezone"}
									{type human}
									{state "not dead"}
								}
							}
						}
						{"default"
							{"action"
								{selector
									{source current}
								}
								{action move}
								{target
									{amount 1
									}
									{tag spawn_anchor}
									{player "2"}
								}
							}
						}
					}
					{"delay"
						{time 0.2}
					}
					{"actor_state"
						{selector
							{source current}
						}
						{fire_mode open}
						{move_mode free}
						{weapon_prepare on}
						{ai_move
							{mode enable}
						}
						{movement
							{speed assault}
						}
					}
					{"delay"
						{time 0.2}
					}
					{"entity_state"
						{selector
							{tag ai_support_selected}
						}
						{tag_remove ai_support_selected}
					}
					{"delay"
						{time 0.5}
					}
					{"trigger"
						{name "ai_support/set_player"}
					}
				}
			}
			{"ai_support/warning_ai_support_for_user_arrived"
				{condition
					{expression "!1 & 2"}
					{terms
						{"1.event"
							{id "talk_on"}
						}
						{"2.entities"
							{selector
								{tag _ai_support_for_user}
								{zone "gamezone"}
								{type human}
								{state "not dead"}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"event"
						{event "talk_on"}
						{mode set}
						{delay 0}
					}
					{"delay"
						{time 1}
					}
					{"switch"
						{"case"
							{condition
								{type rand}
								{value 0.5}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag _ai_support_for_user}
									{type human}
									{state "not dead"}
								}
								{text "mission/multi/ai_support_spawn_notification_1"}
							}
						}
						{"default"
							{"talk"
								{selector
									{amount 1
									}
									{tag _ai_support_for_user}
									{type human}
									{state "not dead"}
								}
								{text "mission/multi/ai_support_spawn_notification_2"}
							}
						}
					}
					{"delay"
						{time 8}
					}
					{"event"
						{event "talk_on"}
						{mode reset}
						{delay 0}
					}
				}
			}
			{"ai_support/check_ai_support_in_command_range"
				{condition
					{terms
						{"1.entities"
							{selector
								{tag _ai_support_for_user}
								{type human}
								{state "not dead"}
							}
						}
					}
				}
				{actions
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
										{tag
											{tag _ai_support_for_user}
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
											{tag cmd_range_check}
										}
										{state
											{state dead}
										}
										{state
											{state user_control}
										}
										{state
											{state linked}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag in_cmd_range}
										}
										{tag
											{tag out_cmd_range}
										}
									}
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
											{tag _ai_support_for_user}
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
											{tag cmd_range_check}
										}
										{tag
											{tag select_for_cmd_range_check}
										}
										{state
											{state dead}
										}
										{state
											{state user_control}
										}
										{state
											{state linked}
										}
										{tag
											{tag _bot}
										}
									}
								}
								{amount 1
								}
							}
							{tag_add select_for_cmd_range_check}
						}
						{"delay"
							{time 0.2}
						}
						{"switch"
							{"case"
								{condition
									{type near}
									{units
										{source advanced}
										{group
											{select
												{tag
													{tag select_for_cmd_range_check}
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
													{tag cmd_range_check}
												}
												{state
													{state dead}
												}
												{state
													{state user_control}
												}
												{state
													{state linked}
												}
												{tag
													{tag _bot}
												}
											}
										}
									}
									{near_to
										{source advanced}
										{group
											{select
												{tag
													{tag officer}
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
											{exclude
												{state
													{state dead}
												}
												{state
													{state linked}
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
									{distance 40}
								}
								{"entity_state"
									{selector
										{tag select_for_cmd_range_check}
										{type human}
										{state "not dead"}
									}
									{tag_add in_cmd_range}
								}
							}
							{"case"
								{condition
									{type near}
									{units
										{source advanced}
										{group
											{select
												{tag
													{tag select_for_cmd_range_check}
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
													{tag cmd_range_check}
												}
												{state
													{state dead}
												}
												{state
													{state user_control}
												}
												{state
													{state linked}
												}
												{tag
													{tag _bot}
												}
											}
										}
									}
									{near_to
										{source advanced}
										{group
											{select
												{tag
													{tag radio_operator}
												}
											}
											{include
												{state
													{state user_control}
												}
												{prop
													{prop human}
												}
												{tag
													{tag _user}
												}
											}
											{exclude
												{state
													{state dead}
												}
												{state
													{state linked}
												}
												{state
													{state inactive}
												}
												{tag
													{tag _bot}
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
												{state
													{state "operatable inhabited user_control"}
												}
												{prop
													{prop vehicle}
												}
												{tag
													{tag _user}
												}
											}
											{exclude
												{state
													{state linked}
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
									{distance 75}
								}
								{"entity_state"
									{selector
										{tag select_for_cmd_range_check}
										{type human}
										{state "not dead"}
									}
									{tag_add in_cmd_range}
								}
							}
							{"default"
								{"entity_state"
									{selector
										{tag select_for_cmd_range_check}
									}
									{tag_add out_cmd_range}
								}
							}
						}
						{"delay"
							{time 0.2}
						}
						{"entity_state"
							{selector
								{tag select_for_cmd_range_check}
							}
							{tag_add cmd_range_check}
							{tag_remove select_for_cmd_range_check}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"ables"
						{selector
							{tag in_cmd_range}
						}
						{add select}
					}
					{"ables"
						{selector
							{tag out_cmd_range}
						}
						{remove select}
					}
					{"ables"
						{selector
							{tag cmd_range_check}
						}
						{remove crew}
					}
					{"delay"
						{time 0.5}
					}
					{"effect"
						{selector
							{tag cmd_range_check}
							{type human}
							{state "not dead"}
						}
						{effect check_ai_support_cmd_range}
					}
					{"delay"
						{time 5}
					}
					{"trigger"
						{name "ai_support/check_ai_support_in_command_range"}
					}
				}
			}