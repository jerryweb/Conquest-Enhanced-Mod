			{"reset_ai_spawn_zones"
				{"switch"
					{"case"
						{condition
							{type cmp_i}
							{var "user_team$"}
							{op "=="}
							{value 1}
						}
						{"delay"
							{time 0.5}
						}
						{"placement"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag spawn_1}
										}
									}
									{include
										{tag
											{tag ai_spawn}
										}
									}
								}
							}
							{target_waypoint "5001"}
						}
						{"delay"
							{time 0.4}
						}
						{"placement"
							{selector
								{source standart}
								{tag spawn_2}
							}
							{target_waypoint "5002"}
						}
						{"delay"
							{time 0.4}
						}
						{"placement"
							{selector
								{source standart}
								{tag spawn_3}
							}
							{target_waypoint "5003"}
						}
						{"delay"
							{time 0.4}
						}
						{"placement"
							{selector
								{source standart}
								{tag spawn_4}
							}
							{target_waypoint "5004"}
						}
					}
					{"default"
						{"delay"
							{time 0.5}
						}
						{"placement"
							{selector
								{source standart}
								{tag spawn_1}
							}
							{target_waypoint "6001"}
						}
						{"delay"
							{time 0.4}
						}
						{"placement"
							{selector
								{source standart}
								{tag spawn_2}
							}
							{target_waypoint "6002"}
						}
						{"delay"
							{time 0.4}
						}
						{"placement"
							{selector
								{source standart}
								{tag spawn_3}
							}
							{target_waypoint "6003"}
						}
						{"delay"
							{time 0.4}
						}
						{"placement"
							{selector
								{source standart}
								{tag spawn_4}
							}
							{target_waypoint "6004"}
						}
					}
				}
			}
			{"move_ai_spawn_to_zones_1_and_2"
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
										{tag
											{tag spawn_1}
										}
										{tag
											{tag spawn_2}
										}
									}
									{include
										{tag
											{tag spawn_b}
										}
									}
								}
							}
							{target_waypoint "5001"}
						}
						{"delay"
							{time 0.4}
						}
						{"placement"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag spawn_3}
										}
										{tag
											{tag spawn_4}
										}
									}
									{include
										{tag
											{tag spawn_b}
										}
									}
								}
							}
							{target_waypoint "5002"}
						}
					}
					{"default"
						{"placement"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag spawn_1}
										}
										{tag
											{tag spawn_2}
										}
									}
									{include
										{tag
											{tag spawn_a}
										}
									}
								}
							}
							{target_waypoint "6001"}
						}
						{"delay"
							{time 0.4}
						}
						{"placement"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag spawn_3}
										}
										{tag
											{tag spawn_4}
										}
									}
									{include
										{tag
											{tag spawn_a}
										}
									}
								}
							}
							{target_waypoint "6002"}
						}
					}
				}
			}
			{"move_to_zone_flanks"
				{"switch"
					{"case"
						{condition
							{type entities}
							{selector
								{tag spawn_4}
							}
						}
						{"switch"
							{"case"
								{condition
									{type cmp_i}
									{var "user_team$"}
									{op "=="}
									{value 1}
								}
								{"select"
									{source advanced}
									{group
										{select
											{tag
												{tag spawn_1}
											}
											{tag
												{tag spawn_2}
											}
										}
										{include
											{tag
												{tag spawn_b}
											}
										}
									}
									{amount 2
									}
								}
								{"delay"
									{time 0.4}
								}
								{"placement"
									{target_waypoint "5001"}
								}
								{"delay"
									{time 1}
								}
								{"select"
									{source advanced}
									{group
										{select
											{tag
												{tag spawn_3}
											}
											{tag
												{tag spawn_4}
											}
										}
										{include
											{tag
												{tag spawn_b}
											}
										}
									}
									{amount 2
									}
								}
								{"delay"
									{time 0.4}
								}
								{"placement"
									{target_waypoint "5004"}
								}
							}
							{"default"
								{"delay"
									{time 0.4}
								}
								{"select"
									{source advanced}
									{group
										{select
											{tag
												{tag spawn_1}
											}
											{tag
												{tag spawn_2}
											}
										}
										{include
											{tag
												{tag spawn_a}
											}
										}
									}
									{amount 2
									}
								}
								{"delay"
									{time 0.4}
								}
								{"placement"
									{target_waypoint "6001"}
								}
								{"delay"
									{time 1}
								}
								{"select"
									{source advanced}
									{group
										{select
											{tag
												{tag spawn_3}
											}
											{tag
												{tag spawn_4}
											}
										}
										{include
											{tag
												{tag spawn_a}
											}
										}
									}
									{amount 2
									}
								}
								{"delay"
									{time 0.4}
								}
								{"placement"
									{target_waypoint "6004"}
								}
							}
						}
					}
					{"default"
						{"switch"
							{"case"
								{condition
									{type cmp_i}
									{var "user_team$"}
									{op "=="}
									{value 1}
								}
								{"select"
									{source advanced}
									{group
										{select
											{tag
												{tag spawn_1}
											}
											{tag
												{tag spawn_2}
											}
										}
										{include
											{tag
												{tag spawn_b}
											}
										}
									}
									{amount 2
									}
								}
								{"delay"
									{time 0.4}
								}
								{"placement"
									{target_waypoint "5001"}
								}
								{"delay"
									{time 1}
								}
								{"select"
									{source advanced}
									{group
										{select
											{tag
												{tag spawn_3}
											}
											{tag
												{tag spawn_4}
											}
										}
										{include
											{tag
												{tag spawn_b}
											}
										}
									}
									{amount 2
									}
								}
								{"delay"
									{time 0.4}
								}
								{"placement"
									{target_waypoint "5003"}
								}
							}
							{"default"
								{"delay"
									{time 0.4}
								}
								{"select"
									{source advanced}
									{group
										{select
											{tag
												{tag spawn_1}
											}
											{tag
												{tag spawn_2}
											}
										}
										{include
											{tag
												{tag spawn_a}
											}
										}
									}
									{amount 2
									}
								}
								{"delay"
									{time 0.4}
								}
								{"placement"
									{target_waypoint "6001"}
								}
								{"delay"
									{time 1}
								}
								{"select"
									{source advanced}
									{group
										{select
											{tag
												{tag spawn_3}
											}
											{tag
												{tag spawn_4}
											}
										}
										{include
											{tag
												{tag spawn_a}
											}
										}
									}
									{amount 2
									}
								}
								{"delay"
									{time 0.4}
								}
								{"placement"
									{target_waypoint "6003"}
								}
							}
						}
					}
				}
			}
			{"move_to_zone_flanks_narrow"
				{"switch"
					{"case"
						{condition
							{type cmp_i}
							{var "user_team$"}
							{op "=="}
							{value 1}
						}
						{## "select"
							{source advanced}
							{group
								{select
									{tag
										{tag ai_spawn}
									}
								}
								{include
									{tag
										{tag spawn_b}
									}
								}
								{exclude
									{tag
										{tag moved}
									}
								}
							}
							{amount 2
							}
						}
						{"select"
							{source advanced}
							{group
								{select
									{tag
										{tag spawn_1}
									}
									{tag
										{tag spawn_2}
									}
								}
								{include
									{tag
										{tag spawn_b}
									}
								}
							}
							{amount 2
							}
						}
						{"delay"
							{time 0.4}
						}
						{"placement"
							{target_waypoint "5001"}
						}
						{## "delay"
							{time 0.4}
						}
						{## "entity_state"
							{tag_add moved}
						}
						{"delay"
							{time 1}
						}
						{## "select"
							{source advanced}
							{group
								{select
									{tag
										{tag ai_spawn}
									}
								}
								{include
									{tag
										{tag spawn_b}
									}
								}
								{exclude
									{tag
										{tag moved}
									}
								}
							}
							{amount 2
							}
						}
						{"select"
							{source advanced}
							{group
								{select
									{tag
										{tag spawn_3}
									}
									{tag
										{tag spawn_4}
									}
								}
								{include
									{tag
										{tag spawn_b}
									}
								}
							}
							{amount 2
							}
						}
						{"delay"
							{time 0.4}
						}
						{"placement"
							{target_waypoint "5003"}
						}
						{## "delay"
							{time 0.4}
						}
						{## "entity_state"
							{tag_remove moved}
						}
					}
					{"default"
						{"delay"
							{time 0.4}
						}
						{## "select"
							{source advanced}
							{group
								{select
									{tag
										{tag ai_spawn}
									}
								}
								{include
									{tag
										{tag spawn_a}
									}
								}
								{exclude
									{tag
										{tag moved}
									}
								}
							}
							{amount 2
							}
						}
						{"select"
							{source advanced}
							{group
								{select
									{tag
										{tag spawn_1}
									}
									{tag
										{tag spawn_2}
									}
								}
								{include
									{tag
										{tag spawn_a}
									}
								}
							}
							{amount 2
							}
						}
						{"delay"
							{time 0.4}
						}
						{"placement"
							{target_waypoint "6001"}
						}
						{## "delay"
							{time 0.4}
						}
						{## "entity_state"
							{tag_add moved}
						}
						{"delay"
							{time 1}
						}
						{## "select"
							{source advanced}
							{group
								{select
									{tag
										{tag ai_spawn}
									}
								}
								{include
									{tag
										{tag spawn_a}
									}
								}
								{exclude
									{tag
										{tag moved}
									}
								}
							}
							{amount 2
							}
						}
						{"select"
							{source advanced}
							{group
								{select
									{tag
										{tag spawn_3}
									}
									{tag
										{tag spawn_4}
									}
								}
								{include
									{tag
										{tag spawn_a}
									}
								}
							}
							{amount 2
							}
						}
						{"delay"
							{time 0.4}
						}
						{"placement"
							{target_waypoint "6003"}
						}
						{## "delay"
							{time 0.4}
						}
						{## "entity_state"
							{tag_remove moved}
						}
					}
				}
			}
			{"move_ai_spawn_to_zones_2_and_3"
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
										{tag
											{tag spawn_1}
										}
										{tag
											{tag spawn_2}
										}
									}
									{include
										{tag
											{tag spawn_b}
										}
									}
								}
							}
							{target_waypoint "5003"}
						}
						{"delay"
							{time 0.4}
						}
						{"placement"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag spawn_3}
										}
										{tag
											{tag spawn_4}
										}
									}
									{include
										{tag
											{tag spawn_b}
										}
									}
								}
							}
							{target_waypoint "5002"}
						}
					}
					{"default"
						{"placement"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag spawn_1}
										}
										{tag
											{tag spawn_2}
										}
									}
									{include
										{tag
											{tag spawn_a}
										}
									}
								}
							}
							{target_waypoint "6003"}
						}
						{"delay"
							{time 0.4}
						}
						{"placement"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag spawn_3}
										}
										{tag
											{tag spawn_4}
										}
									}
									{include
										{tag
											{tag spawn_a}
										}
									}
								}
							}
							{target_waypoint "6002"}
						}
					}
				}
			}
			{"move_ai_spawn_to_zones_3_and_4"
				{"if"
					{condition
						{type entities}
						{selector
							{tag spawn_4}
						}
					}
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
											{tag
												{tag spawn_1}
											}
											{tag
												{tag spawn_2}
											}
										}
										{include
											{tag
												{tag spawn_b}
											}
										}
									}
								}
								{target_waypoint "5003"}
							}
							{"delay"
								{time 0.4}
							}
							{"placement"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag spawn_3}
											}
											{tag
												{tag spawn_4}
											}
										}
										{include
											{tag
												{tag spawn_b}
											}
										}
									}
								}
								{target_waypoint "5004"}
							}
						}
						{"default"
							{"placement"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag spawn_1}
											}
											{tag
												{tag spawn_2}
											}
										}
										{include
											{tag
												{tag spawn_a}
											}
										}
									}
								}
								{target_waypoint "6003"}
							}
							{"delay"
								{time 0.4}
							}
							{"placement"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag spawn_3}
											}
											{tag
												{tag spawn_4}
											}
										}
										{include
											{tag
												{tag spawn_a}
											}
										}
									}
								}
								{target_waypoint "6004"}
							}
						}
					}
				}
			}