; File created by Hawka
;=========================================================================================================
; Vanilla var includes
(include "../multi/dcg_functions.inc")

;============ SPAWN ========================================
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
				{"delay"
					{time 0.2}
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

;============ AI ORDERS LOGIC  ========================================
			{"issue_idle_squad_orders"
				{"delay"
					{time 10}
				}
				{"effect"
					{effect tag_squad_need_next_order}
				}
			}

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
				{## "sound"
					{name "interface/task_fail"}
				}
				{"call"
					{function "fail_radio_objective"}
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
			{"show_radio_objective"
				{"task"
					{name "radio_communications_active"}
				}
				{"sound"
					{name "mission/task_new"}
				}
			}
			{"complete_radio_objective"
				{"task"
					{name "radio_communications_active"}
					{state complete}
				}
				{"sound"
					{name "mission/task_fulfilled"}
				}
			}
			{"fail_radio_objective"
				{"task"
					{name "radio_communications_active"}
					{state fail}
				}
				{"sound"
					{name "mission/task_fail"}
				}
			}
			{"radio_came_up"
				{"timer"
					{time 5}
					{title "mission/multi/enable_radio"}
				}
				{"call"
					{function "complete_radio_objective"}
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
			}
			{"radio_went_down"
				{"call"
					{function "alert_radio_down"}
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
			}