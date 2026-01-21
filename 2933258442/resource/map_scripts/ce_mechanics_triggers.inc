;============ RADIO SCRIPTS========================================		 
			{"conquest_enhanced_mechanics/radio/enable_neutral_and_player_units_on_minimap"
				{condition
					{terms
						{"1.entities"
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
						}
						{"2.event"
							{id "init_radio_mechanics"}
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
							{type entities}
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag radio_car}
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
											{tag radio_man}
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
								{zone "gamezone"}
								{type human}
								{state "not dead"}
							}
							{text "mission/multi/radio_event"}
						}
					}
				}
			}
			{"conquest_enhanced_mechanics/radio/check_radio_car_manned"
				{condition
					{terms
						{"1.event"
							{id "init_radio_mechanics"}
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
												{tag radio_car}
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
												{tag radio_man}
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
								{"sound"
									{name "interface/task_new"}
								}
								{"timer"
									{time 5}
									{title "mission/multi/enable_radio"}
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
									{function "alert_radio_down"}
								}
							}
						}
					}
					{"delay"
						{time 5}
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
						{time 5}
					}
					{"trigger"
						{name "conquest_enhanced_mechanics/radio/check_radio_car_manned"}
					}
				}
			}
			{"conquest_enhanced_mechanics/radio/tag_player_radio_man"
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
											{tag radio_man}
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
											{tag radio_man}
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
											{tag radio_man}
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
										{tag radio_man}
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
										{tag radio_man}
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
										{tag radio_man}
									}
								}
							}
						}
						{tag_add radio_man}
					}
					{"delay"
						{time 1}
					}
					{"effect"
						{selector
							{tag radio_man}
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
						{name "conquest_enhanced_mechanics/radio/tag_player_radio_man"}
					}
				}
			}
			
;============ MAP SETUP SCRIPTS========================================			
			{"conquest_enhanced_mechanics/set_ai_veh_sabotage_chance"
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
											{prop vehicle}
										}
										{state
											{state operatable}
										}
									}
									{exclude
										{state
											{state inactive}
										}
										{prop
											{prop airborne}
										}
										{state
											{state user_control}
										}
										{tag
											{tag _user_ally}
										}
									}
								}
							}
						}
						{"3.cmp_i"
							{var "ai_attack_started$"}
							{op ">"}
							{value 0}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"if"
						{condition
							{type cmp_i}
							{var "ai_sabotage$"}
							{op "=="}
							{value 1}
						}
						{"event"
							{event "sabotage_ai_veh"}
							{mode set}
							{delay 0}
						}
					}
					{"delay"
						{time 1}
					}
					{"if"
						{condition
							{type event}
							{id "sabotage_ai_veh"}
						}
						{"call"
							{function "sabotage_ai_veh_function"}
						}
					}
				}
			}
			{"conquest_enhanced_mechanics/scene_variable/move_scene_variable"
				{condition
					{terms
						{"1.entities"
							{selector
								{tag scene_variable}
								{type vehicle}
							}
						}
					}
				}
				{actions
					{"select"
						{tag scene_variable}
						{type vehicle}
					}
					{"delay"
						{time 0.2}
					}
					{"entity_state"
						{selector
							{source current}
						}
						{impregnability full}
						{discovered off}
						{tag_add "_ce_map_scripts_running"}
					}
					{"delay"
						{time 0.2}
					}
					{"actor_to_waypoint"
						{selector
							{source current}
						}
						{waypoint "3001"}
						{approach "safe teleport"}
					}
				}
			}

;============ OFF MAP SCRIPTS========================================			
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
											{tag _user}
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
											{tag _user}
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
											{tag _user}
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
									{tag _user}
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