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
					{"talk"
						{selector
							{amount 1
							}
							{tag _ai_support_for_user}
							{type human}
							{state "not dead"}
						}
						{text "mission/multi/ai_support_spawn_notification"}
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
			{"ai_support/order_support_squad"
				{condition
					{expression "(1 | 3) & 2"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag pointer_attack}
										}
									}
									{exclude
										{tag
											{tag ai_support_ack}
										}
										{tag
											{tag ignore}
										}
									}
								}
							}
						}
						{"2.entities"
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
										{state
											{state dead}
										}
										{state
											{state user_control}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag support_order_ack}
										}
										{tag
											{tag getting_ai_support_order}
										}
									}
								}
							}
						}
						{"3.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag pointer_defend}
										}
									}
									{exclude
										{tag
											{tag ignore}
										}
										{tag
											{tag ai_support_ack}
										}
									}
								}
							}
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
										{tag pointer_attack}
									}
									{tag
										{tag pointer_defend}
									}
								}
								{exclude
									{tag
										{tag ai_support_ack}
									}
									{tag
										{tag ignore}
									}
								}
							}
							{amount 1
							}
						}
						{tag_add ai_support_ack}
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
									{state
										{state dead}
									}
									{state
										{state user_control}
									}
									{tag
										{tag _bot}
									}
									{tag
										{tag support_order_ack}
									}
									{tag
										{tag getting_ai_support_order}
									}
								}
							}
							{sort
								{type entity}
								{entity
									{amount 1
									}
									{tag ai_support_ack}
								}
							}
							{amount 12
							}
						}
						{tag_add getting_ai_support_order}
					}
					{"delay"
						{time 0.2}
					}
					{"select"
						{tag getting_ai_support_order}
						{type human}
						{state "not dead"}
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
												{tag pointer_defend}
											}
										}
										{include
											{tag
												{tag ai_support_ack}
											}
										}
										{exclude
											{tag
												{tag ignore}
											}
										}
									}
								}
							}
							{"action"
								{selector
									{source current}
								}
								{drop orders}
								{action advance}
								{target
									{tag ai_support_ack}
								}
							}
							{"actor_to_cover"
								{selector
									{source current}
								}
								;{drop orders}
								{mode random}
							}
							{"actor_state"
								{selector
									{source current}
								}
								{move_mode zone}
								{move_radius 25}
								{weapon_prepare on}
								{movement
									{speed fast}
								}
								;{ai
								;	{no_advance on}
								;}
							}
							{"delay"
								{time 0.2}
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
											{tag getting_ai_support_order}
											{type human}
											{state "not dead"}
										}
										{text "mission/multi/ai_support_defend_order_ack_1"}
									}
								}
								{"default"
									{"talk"
										{selector
											{amount 1
											}
											{tag getting_ai_support_order}
											{type human}
											{state "not dead"}
										}
										{text "mission/multi/ai_support_defend_order_ack_2"}
									}
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
												{tag pointer_attack}
											}
										}
										{include
											{tag
												{tag ai_support_ack}
											}
										}
										{exclude
											{tag
												{tag ignore}
											}
										}
									}
								}
							}
							{"action"
								{selector
									{source current}
								}
								{drop orders}
								{action advance}
								{target
									{tag ai_support_ack}
								}
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
								{ai
									{no_advance off}
								}
							}
							{"delay"
								{time 0.2}
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
											{type human}
											{state "not dead"}
										}
										{text "mission/multi/ai_support_attack_order_ack_1"}
									}
								}
								{"default"
									{"talk"
										{selector
											{amount 1
											}
											{tag getting_ai_support_order}
											{type human}
											{state "not dead"}
										}
										{text "mission/multi/ai_support_attack_order_ack_2"}
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
										{tag ai_support_ack}
									}
								}
							}
							{amount 1
							}
						}
						{tag_add ignore}
						{tag_remove ai_support_ack}
					}
					{"delay"
						{time 0.2}
					}
					{"effect"
						{selector
							{source current}
						}
						{effect officer_mark}
					}
					{"delay"
						{time 2}
					}
					{"trigger"
						{name "ai_support/order_support_squad"}
					}
				}
			}