			{"ai_offmap/player_response_to_big_bertha"
				{condition
					{type 1}
					{terms
						{"1.entities"
							{selector
								{tag super_heavy_arty_fired}
							}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag thor_fired}
										}
									}
									{include
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
						}
					}
				}
				{actions
					{"switch"
						{"case"
							{condition
								{type rand}
								{value 0.5}
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
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
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
														{tag super_heavy_arty_fired}
													}
													{tag
														{tag thor_fired}
													}
												}
											}
											{amount 1
											}
										}
									}
									{amount 1
									}
								}
								{text "mission/multi/super_heavy_artillery_incoming_1"}
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
												{state inactive}
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
														{tag super_heavy_arty_fired}
													}
													{tag
														{tag thor_fired}
													}
												}
											}
											{amount 1
											}
										}
									}
									{amount 1
									}
								}
								{text "mission/multi/super_heavy_artillery_incoming_2"}
							}
						}
					}
					{"delay"
						{time 0.2}
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
							{sort
								{type entity}
								{entity
									{source advanced}
									{group
										{select
											{tag
												{tag super_heavy_arty_fired}
											}
											{tag
												{tag thor_fired}
											}
										}
									}
									{amount 1
									}
								}
							}
							{amount 7
							}
						}
						{say retreat}
						{text ""}
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
									{state
										{state linked}
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
										{state inactive}
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
												{tag super_heavy_arty_fired}
											}
											{tag
												{tag thor_fired}
											}
										}
									}
									{amount 1
									}
								}
							}
							{amount 7
							}
						}
						{say tank_retreat}
						{text ""}
					}
					{"delay"
						{time 45}
					}
					{"trigger"
						{name "ai_offmap/player_response_to_big_bertha"}
					}
				}
			}
			{"ai_offmap/delete_flare_gun"
				{condition
					{type 1}
					{terms
						{"1.inventory"
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
							}
							{where "all holders"}
							{item "leuchtpistole34"}
							{compare equal}
							{amount 1}
						}
						{"2.inventory"
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
							}
							{where "all holders"}
							{item "osp30"}
							{compare equal}
							{amount 1}
						}
						{"3.inventory"
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
							}
							{where "all holders"}
							{item "m8_signal_pistol"}
							{compare equal}
							{amount 1}
						}
					}
				}
				{actions
					{"select"
						{source advanced}
						{group
							{select
								{zone
									{zone "gamezone"}
								}
								{zone_ex
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
							{exclude
								{state
									{state inactive}
								}
							}
						}
					}
					{"inventory"
						{selector
							{source current}
						}
						{action put}
					}
					{"inventory"
						{selector
							{source current}
						}
						{action put}
					}
					{"inventory"
						{selector
							{source current}
						}
						{action put}
					}
					{"delay"
						{time 1}
					}
					{"inventory"
						{selector
							{source current}
						}
						{action remove}
						{item "leuchtpistole34"}
					}
					{"inventory"
						{selector
							{source current}
						}
						{action remove}
						{item "osp30"}
					}
					{"inventory"
						{selector
							{source current}
						}
						{action remove}
						{item "m8_signal_pistol"}
					}
					{"delay"
						{time 1}
					}
					{"talk"
						{selector
							{amount 1
							}
							{zone "gamezone"}
							{type human}
						}
						{text "mission/multi/player_pickup_flare_gun"}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "ai_offmap/delete_flare_gun"}
					}
				}
			}
			{"ai_offmap/notify_for_offmap"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag flare_artillery}
										}
									}
									{exclude
										{tag
											{tag acknowledged}
										}
									}
								}
							}
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
												{tag flare_artillery}
											}
										}
										{include
											{tag
												{tag light_artillery_barrage}
											}
										}
										{exclude
											{tag
												{tag acknowledged}
											}
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
										{var "enable_ce_radio_mechanic$"}
										{op "=="}
										{value 1}
									}
									{"if"
										{condition
											{type cmp_i}
											{var "radio_active$"}
											{op "=="}
											{value 1}
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
															{tag ai_signaller}
														}
													}
													{include
														{prop
															{prop human}
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
															{tag cmp_def}
														}
													}
												}
												{amount 1
												}
											}
											{text "mission/multi/calling_light_artillery_barrage"}
										}
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
														{tag ai_signaller}
													}
												}
												{include
													{prop
														{prop human}
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
														{tag cmp_def}
													}
												}
											}
											{amount 1
											}
										}
										{text "mission/multi/calling_light_artillery_barrage"}
									}
								}
							}
							{"delay"
								{time 0.5}
							}
							{"effect"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag flare_artillery}
											}
										}
										{include
											{tag
												{tag light_artillery_barrage}
											}
										}
										{exclude
											{tag
												{tag acknowledged}
											}
											{state
												{state inactive}
											}
										}
									}
								}
								{effect acknowledge_flare_artillery}
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
												{tag flare_artillery}
											}
										}
										{include
											{tag
												{tag medium_artillery_barrage}
											}
										}
										{exclude
											{tag
												{tag acknowledged}
											}
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
										{var "enable_ce_radio_mechanic$"}
										{op "=="}
										{value 1}
									}
									{"if"
										{condition
											{type cmp_i}
											{var "radio_active$"}
											{op "=="}
											{value 1}
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
															{tag ai_signaller}
														}
													}
													{include
														{prop
															{prop human}
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
															{tag cmp_def}
														}
													}
												}
												{amount 1
												}
											}
											{text "mission/multi/calling_medium_artillery_barrage"}
										}
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
														{tag ai_signaller}
													}
												}
												{include
													{prop
														{prop human}
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
														{tag cmp_def}
													}
												}
											}
											{amount 1
											}
										}
										{text "mission/multi/calling_medium_artillery_barrage"}
									}
								}
							}
							{"delay"
								{time 0.5}
							}
							{"effect"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag flare_artillery}
											}
										}
										{include
											{tag
												{tag medium_artillery_barrage}
											}
										}
										{exclude
											{tag
												{tag acknowledged}
											}
											{state
												{state inactive}
											}
										}
									}
								}
								{effect acknowledge_flare_artillery}
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
												{tag flare_artillery}
											}
										}
										{include
											{tag
												{tag heavy_artillery_barrage}
											}
										}
										{exclude
											{tag
												{tag acknowledged}
											}
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
										{var "enable_ce_radio_mechanic$"}
										{op "=="}
										{value 1}
									}
									{"if"
										{condition
											{type cmp_i}
											{var "radio_active$"}
											{op "=="}
											{value 1}
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
															{tag ai_signaller}
														}
													}
													{include
														{prop
															{prop human}
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
															{tag cmp_def}
														}
													}
												}
												{amount 1
												}
											}
											{text "mission/multi/calling_heavy_artillery_barrage"}
										}
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
														{tag ai_signaller}
													}
												}
												{include
													{prop
														{prop human}
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
														{tag cmp_def}
													}
												}
											}
											{amount 1
											}
										}
										{text "mission/multi/calling_heavy_artillery_barrage"}
									}
								}
							}
							{"delay"
								{time 0.5}
							}
							{"effect"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag flare_artillery}
											}
										}
										{include
											{tag
												{tag heavy_artillery_barrage}
											}
										}
										{exclude
											{tag
												{tag acknowledged}
											}
											{state
												{state inactive}
											}
										}
									}
								}
								{effect acknowledge_flare_artillery}
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
												{tag flare_artillery}
											}
										}
										{include
											{tag
												{tag super_heavy_artillery_barrage}
											}
										}
										{exclude
											{tag
												{tag acknowledged}
											}
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
										{var "enable_ce_radio_mechanic$"}
										{op "=="}
										{value 1}
									}
									{"if"
										{condition
											{type cmp_i}
											{var "radio_active$"}
											{op "=="}
											{value 1}
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
															{tag ai_signaller}
														}
													}
													{include
														{prop
															{prop human}
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
															{tag cmp_def}
														}
													}
												}
												{amount 1
												}
											}
											{text "mission/multi/calling_super_heavy_artillery_barrage"}
										}
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
														{tag ai_signaller}
													}
												}
												{include
													{prop
														{prop human}
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
														{tag cmp_def}
													}
												}
											}
											{amount 1
											}
										}
										{text "mission/multi/calling_super_heavy_artillery_barrage"}
									}
								}
							}
							{"delay"
								{time 0.5}
							}
							{"effect"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag flare_artillery}
											}
										}
										{include
											{tag
												{tag super_heavy_artillery_barrage}
											}
										}
										{exclude
											{tag
												{tag acknowledged}
											}
											{state
												{state inactive}
											}
										}
									}
								}
								{effect acknowledge_flare_artillery}
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
												{tag flare_artillery}
											}
										}
										{include
											{tag
												{tag smoke_barrage}
											}
										}
										{exclude
											{tag
												{tag acknowledged}
											}
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
										{var "enable_ce_radio_mechanic$"}
										{op "=="}
										{value 1}
									}
									{"if"
										{condition
											{type cmp_i}
											{var "radio_active$"}
											{op "=="}
											{value 1}
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
															{tag ai_signaller}
														}
													}
													{include
														{prop
															{prop human}
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
															{tag cmp_def}
														}
													}
												}
												{amount 1
												}
											}
											{text "mission/multi/calling_smoke_barrage"}
										}
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
														{tag ai_signaller}
													}
												}
												{include
													{prop
														{prop human}
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
														{tag cmp_def}
													}
												}
											}
											{amount 1
											}
										}
										{text "mission/multi/calling_smoke_barrage"}
									}
								}
							}
							{"delay"
								{time 0.5}
							}
							{"effect"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag flare_artillery}
											}
										}
										{include
											{tag
												{tag smoke_barrage}
											}
										}
										{exclude
											{tag
												{tag acknowledged}
											}
											{state
												{state inactive}
											}
										}
									}
								}
								{effect acknowledge_flare_artillery}
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
												{tag flare_artillery}
											}
										}
										{include
											{tag
												{tag light_rocket_barrage}
											}
										}
										{exclude
											{tag
												{tag acknowledged}
											}
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
										{var "enable_ce_radio_mechanic$"}
										{op "=="}
										{value 1}
									}
									{"if"
										{condition
											{type cmp_i}
											{var "radio_active$"}
											{op "=="}
											{value 1}
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
															{tag ai_signaller}
														}
													}
													{include
														{prop
															{prop human}
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
															{tag cmp_def}
														}
													}
												}
												{amount 1
												}
											}
											{text "mission/multi/calling_light_rocket_barrage"}
										}
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
														{tag ai_signaller}
													}
												}
												{include
													{prop
														{prop human}
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
														{tag cmp_def}
													}
												}
											}
											{amount 1
											}
										}
										{text "mission/multi/calling_light_rocket_barrage"}
									}
								}
							}
							{"delay"
								{time 0.5}
							}
							{"effect"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag flare_artillery}
											}
										}
										{include
											{tag
												{tag light_rocket_barrage}
											}
										}
										{exclude
											{tag
												{tag acknowledged}
											}
											{state
												{state inactive}
											}
										}
									}
								}
								{effect acknowledge_flare_artillery}
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
												{tag flare_artillery}
											}
										}
										{include
											{tag
												{tag heavy_rocket_barrage}
											}
										}
										{exclude
											{tag
												{tag acknowledged}
											}
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
										{var "enable_ce_radio_mechanic$"}
										{op "=="}
										{value 1}
									}
									{"if"
										{condition
											{type cmp_i}
											{var "radio_active$"}
											{op "=="}
											{value 1}
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
															{tag ai_signaller}
														}
													}
													{include
														{prop
															{prop human}
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
															{tag cmp_def}
														}
													}
												}
												{amount 1
												}
											}
											{text "mission/multi/calling_heavy_rocket_barrage"}
										}
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
														{tag ai_signaller}
													}
												}
												{include
													{prop
														{prop human}
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
														{tag cmp_def}
													}
												}
											}
											{amount 1
											}
										}
										{text "mission/multi/calling_heavy_rocket_barrage"}
									}
								}
							}
							{"delay"
								{time 0.5}
							}
							{"effect"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag flare_artillery}
											}
										}
										{include
											{tag
												{tag heavy_rocket_barrage}
											}
										}
										{exclude
											{tag
												{tag acknowledged}
											}
											{state
												{state inactive}
											}
										}
									}
								}
								{effect acknowledge_flare_artillery}
							}
						}
					}
					{"delay"
						{time 3}
					}
					{"trigger"
						{name "ai_offmap/notify_for_offmap"}
					}
				}
			}
			{"ai_offmap/notify_for_signaller_spawn"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag ai_signaller}
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
											{tag acknowledged}
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
										{state
											{state inactive}
										}
									}
								}
							}
						}
					}
				}
				{actions
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "enable_ce_radio_mechanic$"}
								{op "=="}
								{value 1}
							}
							{"if"
								{condition
									{type cmp_i}
									{var "radio_active$"}
									{op "=="}
									{value 1}
								}
								{"call"
									{function "alert_player_of_signaller"}
								}
							}
						}
						{"default"
							{"call"
								{function "alert_player_of_signaller"}
							}
						}
					}
					{"delay"
						{time 3}
					}
					{"effect"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag ai_signaller}
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
										{tag acknowledged}
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
									{state
										{state inactive}
									}
								}
							}
						}
						{effect notify_signaller_has_spawned}
					}
					{"delay"
						{time 10}
					}
					{"trigger"
						{name "ai_offmap/notify_for_signaller_spawn"}
					}
				}
			}