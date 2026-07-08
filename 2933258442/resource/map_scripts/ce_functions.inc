; File created by Hawka
;==========================================================================================================

; Vanilla var includes
(include "../map/multi/dcg_functions.inc")

;============ AI SPAWN LOGIC  ========================================
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

;============ AI TAGGING LOGIC  ========================================
			{"select_ai_bot_units_to_tag"
				{"switch"
					{"case"
						{condition
							{type cmp_i}
							{var "id_defenderbot$"}
							{op "=="}
							{value 1}
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
										{state
											{state operatable}
										}
									}
									{exclude
										{tag
											{tag _ai}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag _animal}
										}
										{tag
											{tag cmp_def}
										}
										{tag
											{tag air_vehicle}
										}
										{player
											{player "0"}
										}
										{state
											{state user_control}
										}
										{player
											{player "1"}
										}
										{tag
											{tag _ai_defender}
										}
									}
								}
							}
							{tag_add _ai}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "id_defenderbot$"}
							{op "=="}
							{value 2}
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
										{state
											{state operatable}
										}
									}
									{exclude
										{tag
											{tag _ai}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag _animal}
										}
										{tag
											{tag cmp_def}
										}
										{tag
											{tag air_vehicle}
										}
										{player
											{player "0"}
										}
										{state
											{state user_control}
										}
										{player
											{player "2"}
										}
										{tag
											{tag _ai_defender}
										}
									}
								}
							}
							{tag_add _ai}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "id_defenderbot$"}
							{op "=="}
							{value 3}
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
										{state
											{state operatable}
										}
									}
									{exclude
										{tag
											{tag _ai}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag _animal}
										}
										{tag
											{tag cmp_def}
										}
										{tag
											{tag air_vehicle}
										}
										{player
											{player "0"}
										}
										{state
											{state user_control}
										}
										{player
											{player "3"}
										}
										{tag
											{tag _ai_defender}
										}
									}
								}
							}
							{tag_add _ai}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "id_defenderbot$"}
							{op "=="}
							{value 4}
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
										{state
											{state operatable}
										}
									}
									{exclude
										{tag
											{tag _ai}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag _animal}
										}
										{tag
											{tag cmp_def}
										}
										{tag
											{tag air_vehicle}
										}
										{player
											{player "0"}
										}
										{state
											{state user_control}
										}
										{player
											{player "4"}
										}
										{tag
											{tag _ai_defender}
										}
									}
								}
							}
							{tag_add _ai}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "id_defenderbot$"}
							{op "=="}
							{value 5}
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
										{state
											{state operatable}
										}
									}
									{exclude
										{tag
											{tag _ai}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag _animal}
										}
										{tag
											{tag cmp_def}
										}
										{tag
											{tag air_vehicle}
										}
										{player
											{player "0"}
										}
										{state
											{state user_control}
										}
										{player
											{player "5"}
										}
										{tag
											{tag _ai_defender}
										}
									}
								}
							}
							{tag_add _ai}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "id_defenderbot$"}
							{op "=="}
							{value 6}
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
										{state
											{state operatable}
										}
									}
									{exclude
										{tag
											{tag _ai}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag _animal}
										}
										{tag
											{tag cmp_def}
										}
										{tag
											{tag air_vehicle}
										}
										{player
											{player "0"}
										}
										{state
											{state user_control}
										}
										{player
											{player "6"}
										}
										{tag
											{tag _ai_defender}
										}
									}
								}
							}
							{tag_add _ai}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "id_defenderbot$"}
							{op "=="}
							{value 7}
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
										{state
											{state operatable}
										}
									}
									{exclude
										{tag
											{tag _ai}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag _animal}
										}
										{tag
											{tag cmp_def}
										}
										{tag
											{tag air_vehicle}
										}
										{player
											{player "0"}
										}
										{state
											{state user_control}
										}
										{player
											{player "7"}
										}
										{tag
											{tag _ai_defender}
										}
									}
								}
							}
							{tag_add _ai}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "id_defenderbot$"}
							{op "=="}
							{value 8}
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
										{state
											{state operatable}
										}
									}
									{exclude
										{tag
											{tag _ai}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag _animal}
										}
										{tag
											{tag cmp_def}
										}
										{tag
											{tag air_vehicle}
										}
										{player
											{player "0"}
										}
										{state
											{state user_control}
										}
										{player
											{player "8"}
										}
										{tag
											{tag _ai_defender}
										}
									}
								}
							}
							{tag_add _ai}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "id_defenderbot$"}
							{op "=="}
							{value 9}
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
										{state
											{state operatable}
										}
									}
									{exclude
										{tag
											{tag _ai}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag _animal}
										}
										{tag
											{tag cmp_def}
										}
										{tag
											{tag air_vehicle}
										}
										{player
											{player "0"}
										}
										{state
											{state user_control}
										}
										{player
											{player "9"}
										}
										{tag
											{tag _ai_defender}
										}
									}
								}
							}
							{tag_add _ai}
						}
					}
					{"default"
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
										{state
											{state operatable}
										}
									}
									{exclude
										{tag
											{tag _ai}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag _animal}
										}
										{tag
											{tag cmp_def}
										}
										{tag
											{tag air_vehicle}
										}
										{player
											{player "0"}
										}
										{state
											{state user_control}
										}
										{tag
											{tag _ai_defender}
										}
									}
								}
							}
							{tag_add _ai}
						}
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
