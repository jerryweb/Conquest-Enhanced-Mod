; File created by Hawka
;==========================================================================================================

;============== Bot Tagging ==============					
			{"lua/bot_tags"
				{condition
					{terms
						{"1.cmp_i"
							{var "dcg_on$"}
							{op ">"}
							{value 2}
						}
						{"2.entities"
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
										{state
											{state operatable}
										}
									}
									{exclude
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
											{tag pilot}
										}
										{player
											{player "0"}
										}
										{prop
											{prop airborne}
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
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
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
										{tag pilot}
									}
									{player
										{player "0"}
									}
									{prop
										{prop airborne}
									}
									{state
										{state user_control}
									}
								}
							}
						}
						{tag_add _ai}
					}
					{"call"
						{function "select_ai_bot_units_to_tag"}
					}
					{"delay"
						{time 0.2}
					}
					{"ables"
						{selector
							{ignore_captured_by_user 0}
							{tag _ai}
							{zone "gamezone"}
							{type human}
							{state operatable}
						}
						{remove personage}
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
									{tag
										{tag _ai}
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
										{tag bot}
									}
									{tag
										{tag _user}
									}
									{state
										{state user_control}
									}
								}
							}
						}
						{tag_add bot}
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
									{tag
										{tag _ai}
									}
								}
								{include
									{prop
										{prop tank}
									}
									{state
										{state operatable}
									}
								}
								{exclude
									{tag
										{tag bot_tank}
									}
									{state
										{state user_control}
									}
								}
							}
						}
						{tag_add bot_tank}
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
									{tag
										{tag _ai}
									}
								}
								{include
									{prop
										{prop car}
									}
									{state
										{state operatable}
									}
								}
								{exclude
									{tag
										{tag bot_car}
									}
									{state
										{state user_control}
									}
								}
							}
						}
						{tag_add bot_car}
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
									{tag
										{tag _ai}
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
									{tag
										{tag bot_tank}
									}
									{tag
										{tag bot_car}
									}
									{tag
										{tag bot_veh}
									}
									{prop
										{prop airborne}
									}
									{state
										{state user_control}
									}
								}
							}
						}
						{tag_add _bot_veh}
					}
					{"delay"
						{time 0.2}
					}
					{"ables"
						{selector
							{ignore_captured_by_user 0}
							{tag _bot_veh}
							{zone "gamezone"}
							{type vehicle}
							{state operatable}
						}
						{add emit_on_attack}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _bot_veh}
						}
						{tag_add bot_veh}
						{tag_remove _bot_veh}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag _ai}
									}
								}
								{exclude
									{state
										{state user_control}
									}
								}
							}
						}
						{tag_add _bot}
						{tag_remove _ai}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag hedgehog}
									}
								}
								{include
									{zone
										{zone "_bridge1"}
									}
								}
								{exclude
									{tag
										{tag crushed}
									}
									{tag
										{tag "+chokehog"}
									}
								}
							}
						}
						{tag_add "+chokehog"}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag hedgehog}
									}
								}
								{include
									{zone
										{zone "_bridge2"}
									}
								}
								{exclude
									{tag
										{tag crushed}
									}
									{tag
										{tag "+chokehog"}
									}
								}
							}
						}
						{tag_add "+chokehog"}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag hedgehog}
									}
								}
								{include
									{zone
										{zone "_bridge3"}
									}
								}
								{exclude
									{tag
										{tag crushed}
									}
									{tag
										{tag "+chokehog"}
									}
								}
							}
						}
						{tag_add "+chokehog"}
					}
					{"delay"
						{time 0.1}
					}
					{## "switch"
						{"case"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag smk_}
									{zone "gamezone"}
									{type human}
									{state operatable}
								}
								{count
									{op "<<"}
									{value 55}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag bot}
											}
										}
										{include
											{with_item
												{type amount}
												{item "nbk39" "grenade"}
												{min 1}
											}
										}
										{exclude
											{tag
												{tag smk_}
											}
											{state
												{state dead}
											}
										}
									}
									{group
										{select
											{tag
												{tag bot}
											}
										}
										{include
											{with_item
												{type amount}
												{item "rdg1_smoke" "grenade"}
												{min 1}
											}
										}
										{exclude
											{tag
												{tag smk_}
											}
											{state
												{state dead}
											}
										}
									}
									{group
										{select
											{tag
												{tag bot}
											}
										}
										{include
											{with_item
												{type amount}
												{item "m24_smoke" "grenade"}
												{min 1}
											}
										}
										{exclude
											{tag
												{tag smk_}
											}
											{state
												{state dead}
											}
										}
									}
									{group
										{select
											{tag
												{tag bot}
											}
										}
										{include
											{with_item
												{type amount}
												{item "m43_smoke"}
												{min 1}
											}
										}
										{exclude
											{tag
												{tag smk_}
											}
											{state
												{state dead}
											}
										}
									}
								}
								{tag_add smk_}
							}
						}
						{"default"}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "lua/bot_tags"}
					}
				}
			}
			{"lua/clean"
				{condition
					{type 1}
					{terms
						{"1.entities"
							{selector
								{ignore_captured_by_user 0}
								{tag _lua_alert}
								{zone "gamezone"}
								{state "not operatable"}
							}
						}
						{"2.entities"
							{selector
								{ignore_captured_by_user 0}
								{tag _lua_ignore}
								{zone "gamezone"}
								{state "not operatable"}
							}
						}
						{"3.entities"
							{selector
								{ignore_captured_by_user 0}
								{tag smk_}
								{zone "gamezone"}
								{state "not operatable"}
							}
						}
						{"4.entities"
							{selector
								{ignore_captured_by_user 0}
								{tag _lua_need_next_order}
								{zone "gamezone"}
								{state "not operatable"}
							}
						}
						{"5.entities"
							{selector
								{ignore_captured_by_user 0}
								{tag artillery_target}
								{zone "gamezone"}
								{state "not operatable"}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _bot}
							{zone "gamezone"}
							{state "not operatable"}
						}
						{tag_remove _bot}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag _lua_ignore}
									}
								}
								{exclude
									{tag
										{tag _bot}
									}
								}
							}
						}
						{tag_remove _lua_ignore}
					}
					{"delay"
						{time 0.3}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag _lua_mi}
									}
								}
								{exclude
									{tag
										{tag _bot}
									}
								}
							}
						}
						{tag_remove _lua_mi}
					}
					{"delay"
						{time 0.3}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag _lua_alert}
									}
								}
								{exclude
									{tag
										{tag _bot}
									}
								}
							}
						}
						{tag_remove _lua_alert}
					}
					{"delay"
						{time 0.3}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag _lua_alert}
									}
								}
								{include
									{tag
										{tag _lua_mi}
									}
								}
							}
						}
						{tag_remove _lua_alert}
					}
					{"delay"
						{time 0.3}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag smk_}
									}
								}
								{exclude
									{tag
										{tag _bot}
									}
								}
							}
						}
						{tag_remove smk_}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag noted_by_ai}
							{zone "gamezone"}
							{state "not operatable"}
						}
						{tag_remove noted_by_ai}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag _arrowed}
									}
								}
								{include
									{zone
										{zone "combat"}
									}
								}
								{exclude
									{tag
										{tag air_vehicle}
									}
								}
							}
						}
						{tag_remove _arrowed}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _lua_need_next_order}
							{zone "gamezone"}
							{state "not operatable"}
						}
						{tag_remove _lua_need_next_order}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag artillery_target}
							{zone "gamezone"}
							{state "not operatable"}
						}
						{tag_remove artillery_target}
					}
					{"delay"
						{time 0.5}
					}
					{"switch"
						{"case"
							{condition
								{type trigger}
								{name "ai/recrew_portables"}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag _lua_mi}
											}
										}
										{include
											{tag
												{tag ecrew}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag repairing}
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
								{tag_add _clean}
								{tag_remove _lua_mi}
							}
							{"delay"
								{time 0.5}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag _clean}
								}
								{tag_remove ecrew}
							}
							{"delay"
								{time 0.5}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag _clean}
								}
								{tag_remove _clean}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"switch"
						{"case"
							{condition
								{type trigger}
								{name "ai/recrew_tank"}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag _lua_mi}
											}
										}
										{include
											{tag
												{tag tcrew}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag repairing}
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
								{tag_add _clean}
								{tag_remove _lua_mi}
							}
							{"delay"
								{time 0.5}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag _clean}
								}
								{tag_remove tcrew}
							}
							{"delay"
								{time 0.5}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag _clean}
								}
								{tag_remove _clean}
							}
						}
					}
					{"delay"
						{time 30}
					}
					{"trigger"
						{name "lua/clean"}
					}
				}
			}
			{"lua/alert_clear"
				{condition
					{expression "(!1 & 2 & 4) | (3 & 4)"}
					{terms
						{"1.see_enemy"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _lua_alert}
										}
									}
									{include
										{zone
											{zone "gamezone"}
										}
										{state
											{state operatable}
										}
									}
									{exclude
										{state
											{state user_control}
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
											{tag _lua_alert}
										}
									}
									{include
										{zone
											{zone "gamezone"}
										}
										{state
											{state operatable}
										}
									}
									{exclude
										{state
											{state user_control}
										}
									}
								}
							}
						}
						{"3.entities"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag _lua_alert}
										}
									}
									{include
										{zone
											{zone "gamezone"}
										}
										{tag
											{tag _lua_mi}
										}
										{state
											{state operatable}
										}
									}
								}
							}
						}
						{"4.cmp_i"
							{var "dcg_on$"}
							{op ">"}
							{value 2}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag _lua_alert}
											}
										}
										{include
											{tag
												{tag _lua_mi}
											}
										}
									}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag _lua_alert}
											}
										}
										{include
											{tag
												{tag _lua_mi}
											}
										}
									}
								}
								{tag_remove _lua_alert}
							}
							{"delay"
								{time 10}
							}
							{"trigger"
								{name "lua/alert_clear"}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag _lua_alert}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state user_control}
											}
										}
									}
									{amount 1
									}
								}
								{tag_add alert_temp}
							}
							{"delay"
								{time 0.5}
							}
							{"switch"
								{"case"
									{condition
										{type see_enemy}
										{selector
											{ignore_captured_by_user 0}
											{tag alert_temp}
										}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag alert_temp}
										}
										{tag_remove _lua_alert}
									}
									{"delay"
										{time 1}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag alert_temp}
										}
										{tag_remove alert_temp}
									}
								}
							}
							{"delay"
								{time 10}
							}
							{"trigger"
								{name "lua/alert_clear"}
							}
						}
					}
				}
			}
			{"lua/at_flag_ignore"
				{condition
					{terms
						{"1.cmp_i"
							{var "dcg_on$"}
							{op ">"}
							{value 3}
						}
						{"2.near"
							{units
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
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
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag _lua_ignore}
										}
										{tag
											{tag _lua_alert}
										}
										{tag
											{tag _def}
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
									}
								}
							}
							{near_to
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag flag}
										}
									}
									{exclude
										{state
											{state inactive}
										}
									}
								}
							}
							{distance 61}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
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
									{tag
										{tag _lua_mi}
									}
									{tag
										{tag _lua_ignore}
									}
									{tag
										{tag _lua_alert}
									}
									{tag
										{tag _def}
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
								}
							}
							{amount 1
							}
							{sort
								{type entity}
								{entity
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag flag}
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
						}
						{tag_add _local1}
					}
					{"delay"
						{time 0.5}
					}
					{"switch"
						{"case"
							{condition
								{type near}
								{units
									{ignore_captured_by_user 0}
									{tag _local1}
									{state operatable}
								}
								{near_to
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag flag}
											}
										}
										{exclude
											{state
												{state inactive}
											}
										}
									}
								}
								{distance 62}
							}
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag _local1}
									{state operatable}
								}
								{tag_add _lua_ignore}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag _local1}
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
												{tag _lua_mi}
											}
										}
									}
								}
								{drop orders}
								{fire_mode open}
								{move_mode zone}
								{ai_move
									{mode enable}
								}
								{movement
									{speed assault}
								}
								{ai
									{advance_ratio 2}
									{retreat_ratio 5}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag _local1}
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
											{tag
												{tag _lua_mi}
											}
											{state
												{state user_control}
											}
										}
									}
								}
								{drop orders}
								{fire_mode open}
								{move_mode zone}
								{move_radius 30}
								{ai_move
									{mode enable}
								}
								{movement
									{speed normal}
									{forward on}
									{backward on}
								}
							}
						}
						{"default"}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _local1}
						}
						{tag_remove _local1}
					}
					{"delay"
						{time 15}
					}
					{"trigger"
						{name "lua/at_flag_ignore"}
					}
				}
			}
			{"lua/in_transit_act"
				{condition
					{type 1}
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
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
										{tag
											{tag _lua_alert}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag repairing}
										}
										{tag
											{tag _lua_ignore}
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
										{prop
											{prop airborne}
										}
									}
								}
							}
							{enemy
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag _user}
										}
									}
									{include
										{zone
											{zone "gamezone"}
										}
										{state
											{state operatable}
										}
										{tag
											{tag engine_count_1}
										}
										{tag
											{tag engine_count_2}
										}
										{state
											{state user_control}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 90}
							}
							{tag
								{"tag pair"}
								{"for selector" _act}
								{"for enemy" _noted}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"timer"
						{time 4}
						{title "AI stopping transit to attack"}
					}
					{"switch"
						{"case"
							{condition
								{type see_enemy}
								{selector
									{ignore_captured_by_user 0}
									{tag _act}
									{state operatable}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type entities}
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag _act}
													}
												}
												{include
													{tag
														{tag bot_veh}
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
														{state user_control}
													}
												}
											}
										}
									}
									{"delay"
										{time 0.1}
									}
									{"actor_state"
										{selector
											{tag _act}
											{state operatable}
										}
										{drop orders}
										{fire_mode open}
										{ai_move
											{mode enable}
										}
										{cannon fire}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag _act}
											{state operatable}
										}
										{tag_add _lua_alert}
										{tag_remove _lua_ignore}
									}
									{"delay"
										{time 10}
									}
								}
								{"case"
									{condition
										{type entities}
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag _act}
													}
												}
												{include
													{tag
														{tag bot}
													}
													{prop
														{prop human}
													}
												}
												{exclude
													{state
														{state dead}
													}
												}
											}
										}
									}
									{"delay"
										{time 0.1}
									}
									{"actor_state"
										{selector
											{tag _act}
											{state operatable}
										}
										{drop orders}
										{fire_mode open}
										{move_mode hold}
										{ai_move
											{mode enable}
										}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag _act}
											{state operatable}
										}
										{tag_add _lua_alert}
										{tag_remove _lua_ignore}
									}
									{"delay"
										{time 1}
									}
									{"actor_state"
										{selector
											{tag _act}
											{state operatable}
										}
										{fire_mode open}
										{move_mode free}
										{ai_move
											{mode enable}
										}
									}
									{"delay"
										{time 26}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"actor_state"
										{selector
											{tag _act}
											{type vehicle}
											{state operatable}
										}
										{drop orders}
										{fire_mode open}
										{ai_move
											{mode enable}
										}
										{movement
											{forward off}
											{backward off}
										}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag _act}
											{state operatable}
										}
										{tag_add _lua_alert}
										{tag_remove _lua_ignore}
									}
									{"delay"
										{time 2}
									}
									{"actor_state"
										{selector
											{ignore_captured_by_user 0}
											{tag _act}
										}
										{fire_mode open}
										{move_mode free}
										{ai_move
											{mode enable}
										}
										{movement
											{speed normal}
											{forward on}
											{backward on}
										}
									}
									{"delay"
										{time 26}
									}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type entities}
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag "_noted "}
													}
												}
												{include
													{zone
														{zone "gamezone"}
													}
													{tag
														{tag _user}
													}
													{state
														{state "operatable user_control"}
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
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag "_noted "}
										}
										{tag_add noted_by_ai}
										{tag_remove "_noted "}
									}
								}
								{"default"
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag _noted}
										}
										{tag_remove "_noted "}
									}
								}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag "_noted "}
								}
								{tag_remove "_noted "}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _act}
						}
						{tag_remove _act}
					}
					{"delay"
						{time 5}
					}
					{"trigger"
						{name "lua/in_transit_act"}
					}
				}
			}
			{"lua/ignore_incheck"
				{condition
					{expression "(1 & 2) | (2 & 3)"}
					{terms
						{"1.entities"
							{selector
								{tag _lua_ignore}
								{zone "gamezone"}
								{state operatable}
							}
							{count
								{op ">"}
								{value 30}
							}
						}
						{"2.cmp_i"
							{var "dcg_on$"}
							{op ">"}
							{value 3}
						}
						{"3.entities"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag _lua_ignore}
										}
									}
									{include
										{zone
											{zone "gamezone"}
										}
										{tag
											{tag _lua_mi}
										}
										{state
											{state operatable}
										}
									}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag _lua_ignore}
											}
										}
										{include
											{tag
												{tag _lua_mi}
											}
										}
									}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag _lua_ignore}
											}
										}
										{include
											{tag
												{tag _lua_mi}
											}
										}
									}
								}
								{tag_remove _lua_ignore}
							}
							{"delay"
								{time 10}
							}
							{"trigger"
								{name "lua/ignore_incheck"}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag _lua_ignore}
											}
										}
										{include
											{state
												{state operatable}
											}
										}
									}
									{sort
										{type entity}
										{entity
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag flag}
													}
												}
												{exclude
													{state
														{state inactive}
													}
												}
											}
										}
										{mode farthest}
									}
									{amount 1
									}
								}
								{tag_add _tidy1}
							}
							{"delay"
								{time 1}
							}
							{"switch"
								{"case"
									{condition
										{type see_enemy}
										{selector
											{ignore_captured_by_user 0}
											{tag _tidy1}
											{state operatable}
										}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag _tidy1}
										}
										{tag_remove _lua_ignore}
									}
									{"delay"
										{time 1}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag _tidy1}
										}
										{tag_remove _tidy1}
									}
								}
							}
							{"delay"
								{time 25}
							}
							{"trigger"
								{name "lua/ignore_incheck"}
							}
						}
					}
				}
			}
			{"clean-saved-tags"
				{condition
				}
				{actions
					{"delay"
						{time 0.4}
					}
					{"entity_state"
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
										{state linked}
									}
								}
							}
						}
						{tag_remove cmp_def}
					}
					{"delay"
						{time 0.1}
					}
					{"set_i"
						{var "dcg_on$"}
						{op "="}
						{value 0}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag engine_count_1}
									}
									{tag
										{tag engine_count_2}
									}
								}
								{exclude
									{tag
										{tag air_vehicle}
									}
								}
							}
						}
						{tag_add air_vehicle}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag bot}
						}
						{tag_remove bot}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _bot}
						}
						{tag_remove _bot}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag bot_tank}
						}
						{tag_remove bot_tank}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag bot_car}
						}
						{tag_remove bot_car}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag bot_veh}
						}
						{tag_remove bot_veh}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag smk_target}
						}
						{tag_remove smk_target}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag unhold_iq}
						}
						{tag_remove unhold_iq}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag enemy_near_iq}
						}
						{tag_remove enemy_near_iq}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag bail_veh}
						}
						{tag_remove bail_veh}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag bail_target}
						}
						{tag_remove bail_target}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag noted_by_ai}
						}
						{tag_remove noted_by_ai}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag pursue_target}
						}
						{tag_remove pursue_target}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag ecannon_enter}
						}
						{tag_remove ecannon_enter}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag etank_enter}
						}
						{tag_remove etank_enter}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag e_tank_alt}
						}
						{tag_remove e_tank_alt}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag p_tank_target}
						}
						{tag_remove p_tank_target}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag p_tank_target}
						}
						{tag_remove p_tank_target}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag temp1}
						}
						{tag_remove temp1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag temp2}
						}
						{tag_remove temp2}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag temp3}
						}
						{tag_remove temp3}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag temp4}
						}
						{tag_remove temp4}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag repairing}
						}
						{tag_remove repairing}
					}
					{"delay"
						{time 0.2}
					}
					{"actor_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _user}
							{type vehicle}
						}
						{movement
							{forward on}
							{backward on}
						}
					}
					{"delay"
						{time 0.3}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag air_vehicle}
						}
						{tag_add _arrowed}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _m}
						}
						{tag_remove _m}
					}
					{"delay"
						{time 0.3}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _lua_need_next_order}
						}
						{tag_remove _lua_need_next_order}
					}
					{"set_i"
						{var "dcg_on$"}
						{op "+"}
						{value 1}
					}
				}
			}


;============== AI LOGIC SCRIPTS =============	
			{"ai/bail_portables"
				{condition
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag bot_veh}
										}
									}
									{include
										{state
											{state operatable}
										}
									}
									{exclude
										{state
											{state linked}
										}
										{state
											{state user_control}
										}
									}
								}
							}
							{enemy
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag player}
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
									}
								}
							}
							{distance
								{mode near_than}
								{meters 33}
							}
							{tag
								{"tag pair"}
								{"for selector" bail_veh}
								{"for enemy" bail_target}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"emit"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag bail_veh}
									}
								}
								{include
									{state
										{state operatable}
									}
								}
								{exclude
									{state
										{state user_control}
									}
								}
							}
						}
						{drop orders}
						{emit
							{count 1}
						}
					}
					{"delay"
						{time 0.9}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag bot}
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
										{tag _lua_mi}
									}
									{tag
										{tag _lua_ignore}
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
									{ignore_captured_by_user 0}
									{tag bail_veh}
								}
							}
							{amount 1
							}
						}
						{tag_add temp6}
					}
					{"delay"
						{time 0.2}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag temp6}
							{type human}
							{state operatable}
						}
						{tag_add _lua_ignore}
					}
					{"delay"
						{time 0.2}
					}
					{"actor_state"
						{selector
							{ignore_captured_by_user 0}
							{tag temp6}
							{type human}
							{state operatable}
						}
						{drop orders}
						{fire_mode open}
						{move_mode free}
						{weapon_prepare on}
						{movement
							{speed assault}
							{type normal}
						}
						{ai
							{advance_ratio "0.5"}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"action"
						{selector
							{ignore_captured_by_user 0}
							{tag temp6}
							{type human}
							{state operatable}
						}
						{drop orders}
						{action rotate}
						{target
							{ignore_captured_by_user 0}
							{tag bail_target}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag bail_target}
							{state operatable}
						}
						{tag_add noted_by_ai}
						{tag_remove bail_target}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag bail_veh}
						}
						{tag_remove bail_veh}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag temp6}
						}
						{tag_remove temp6}
					}
					{"delay"
						{time 4.5}
					}
					{"trigger"
						{name "ai/bail_portables"}
					}
				}
			}
			{"ai/ai_unhold"
				{condition
					{type 1}
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag bot}
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
											{tag repairing}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag _lua_alert}
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
							{enemy
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag _user}
										}
									}
									{include
										{state
											{state operatable}
										}
										{state
											{state user_control}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 55}
							}
							{detection located}
							{tag
								{"tag pair"}
								{"for selector" unhold_iq}
								{"for enemy" enemy_near_iq}
							}
						}
						{"2.see_actors"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag bot_car}
										}
										{tag
											{tag bot_tank}
										}
										{tag
											{tag bot_veh}
										}
									}
									{include
										{state
											{state operatable}
										}
									}
									{exclude
										{tag
											{tag repairing}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag _lua_alert}
										}
										{state
											{state user_control}
										}
										{prop
											{prop airborne}
										}
									}
								}
							}
							{enemy
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag _user}
										}
									}
									{include
										{state
											{state operatable}
										}
										{state
											{state user_control}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 66}
							}
							{detection located}
							{tag
								{"tag pair"}
								{"for selector" unhold_iq}
								{"for enemy" enemy_near_iq}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag unhold_iq}
							{state operatable}
						}
						{tag_add _lua_mi}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag unhold_iq}
											}
										}
										{include
											{tag
												{tag bot}
											}
										}
									}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type rand}
										{value 0.4}
									}
									{"delay"
										{time 0.1}
									}
									{"actor_state"
										{selector
											{tag unhold_iq}
											{state operatable}
										}
										{drop orders}
										{fire_mode open}
										{move_mode free}
										{weapon_prepare on}
										{movement
											{speed assault}
										}
										{ai
											{advance_ratio "0.1"}
										}
									}
								}
								{"case"
									{condition
										{type rand}
										{value 0.4}
									}
									{"delay"
										{time 0.1}
									}
									{"actor_state"
										{selector
											{tag unhold_iq}
											{state operatable}
										}
										{drop orders}
										{fire_mode open}
										{move_mode free}
										{weapon_prepare on}
										{movement
											{type crawl}
										}
										{ai
											{advance_ratio "0.05"}
										}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"actor_state"
										{selector
											{tag unhold_iq}
											{state operatable}
										}
										{drop orders}
										{fire_mode open}
										{move_mode free}
										{weapon_prepare on}
										{movement
											{speed sneak}
										}
										{ai
											{advance_ratio "0.1"}
										}
									}
								}
							}
						}
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag unhold_iq}
											}
										}
										{include
											{prop
												{prop vehicle}
											}
										}
										{exclude
											{tag
												{tag bot_veh}
											}
											{state
												{state user_control}
											}
										}
									}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_state"
								{selector
									{tag unhold_iq}
									{type vehicle}
									{state operatable}
								}
								{drop orders}
								{fire_mode open}
								{ai_move
									{mode enable}
								}
								{movement
									{forward off}
									{backward off}
								}
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
									{"delay"
										{time 0.1}
									}
									{"actor_state"
										{selector
											{ignore_captured_by_user 0}
											{tag unhold_iq}
										}
										{fire_mode open}
										{move_mode free}
										{ai_move
											{mode enable}
										}
										{movement
											{speed slow}
											{forward on}
											{backward on}
										}
									}
								}
								{"case"
									{condition
										{type rand}
										{value 0.5}
									}
									{"delay"
										{time 0.1}
									}
									{"actor_state"
										{selector
											{ignore_captured_by_user 0}
											{tag unhold_iq}
										}
										{fire_mode open}
										{move_mode free}
										{ai_move
											{mode enable}
										}
										{movement
											{speed fast}
											{forward on}
											{backward on}
										}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"actor_state"
										{selector
											{ignore_captured_by_user 0}
											{tag unhold_iq}
										}
										{fire_mode open}
										{move_mode free}
										{weapon_prepare on}
										{ai_move
											{mode enable}
										}
										{movement
											{speed normal}
											{forward on}
											{backward on}
										}
									}
								}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"actor_state"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag unhold_iq}
											}
										}
										{include
											{tag
												{tag bot_veh}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state user_control}
											}
										}
									}
								}
								{drop orders}
								{fire_mode open}
								{move_mode free}
								{ai_move
									{mode enable}
								}
								{cannon fire}
							}
							{"delay"
								{time 1}
							}
							{"entity_state"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag unhold_iq}
											}
										}
										{include
											{tag
												{tag bot_veh}
											}
										}
									}
								}
								{tag_add _mi_temp2}
								{tag_remove unhold_iq}
							}
						}
					}
					{"delay"
						{time 2}
					}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag unhold_iq}
											}
										}
										{include
											{tag
												{tag "+mobilegun"}
											}
										}
									}
								}
							}
							{"delay"
								{time 15}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type entities}
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag unhold_iq}
													}
												}
												{include
													{prop
														{prop vehicle}
													}
												}
												{exclude
													{state
														{state user_control}
													}
												}
											}
										}
									}
									{"delay"
										{time 0.1}
									}
									{"switch"
										{"case"
											{condition
												{type rand}
												{value 0.3}
											}
											{"delay"
												{time 0.1}
											}
											{"action"
												{selector
													{tag unhold_iq}
													{state operatable}
												}
												{action rotate}
												{target
													{ignore_captured_by_user 0}
													{tag enemy_near_iq}
												}
											}
											{"delay"
												{time 1}
											}
											{"action"
												{selector
													{tag unhold_iq}
													{state operatable}
												}
												{action move}
												{target
													{ignore_captured_by_user 0}
													{tag enemy_near_iq}
												}
											}
											{"delay"
												{time 5}
											}
										}
										{"case"
											{condition
												{type rand}
												{value 0.3}
											}
											{"delay"
												{time 0.1}
											}
											{"action"
												{selector
													{tag unhold_iq}
													{state operatable}
												}
												{action rotate}
												{target
													{ignore_captured_by_user 0}
													{tag enemy_near_iq}
												}
											}
											{"delay"
												{time 1}
											}
											{"action"
												{selector
													{tag unhold_iq}
													{state operatable}
												}
												{action advance}
												{target
													{ignore_captured_by_user 0}
													{tag enemy_near_iq}
												}
											}
											{"delay"
												{time 8}
											}
										}
										{"case"
											{condition
												{type rand}
												{value 0.3}
											}
											{"delay"
												{time 0.1}
											}
											{"action"
												{selector
													{tag unhold_iq}
													{state operatable}
												}
												{action advance}
												{target
													{source advanced}
													{ignore_captured_by_user 0}
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
															{state
																{state inactive}
															}
														}
													}
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag enemy_near_iq}
														}
													}
												}
											}
											{"delay"
												{time 6}
											}
										}
										{"default"
											{"delay"
												{time 0.1}
											}
											{"action"
												{selector
													{tag unhold_iq}
													{state operatable}
												}
												{action rotate}
												{target
													{ignore_captured_by_user 0}
													{tag enemy_near_iq}
												}
											}
											{"delay"
												{time 1}
											}
											{"action"
												{selector
													{tag unhold_iq}
													{state operatable}
												}
												{action attack}
												{target
													{ignore_captured_by_user 0}
													{tag enemy_near_iq}
												}
											}
											{"delay"
												{time 8}
											}
										}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"switch"
										{"case"
											{condition
												{type rand}
												{value 0.3}
											}
											{"delay"
												{time 0.1}
											}
											{"action"
												{selector
													{tag unhold_iq}
													{state operatable}
												}
												{action move}
												{target
													{ignore_captured_by_user 0}
													{tag enemy_near_iq}
												}
											}
											{"delay"
												{time 4}
											}
										}
										{"case"
											{condition
												{type rand}
												{value 0.3}
											}
											{"delay"
												{time 0.1}
											}
											{"action"
												{selector
													{tag unhold_iq}
													{state operatable}
												}
												{action advance}
												{target
													{ignore_captured_by_user 0}
													{tag enemy_near_iq}
												}
											}
											{"delay"
												{time 5}
											}
										}
										{"case"
											{condition
												{type rand}
												{value 0.3}
											}
											{"delay"
												{time 0.1}
											}
											{"action"
												{selector
													{tag unhold_iq}
													{state operatable}
												}
												{action advance}
												{target
													{source advanced}
													{ignore_captured_by_user 0}
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
															{state
																{state inactive}
															}
														}
													}
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag enemy_near_iq}
														}
													}
												}
											}
											{"delay"
												{time 6}
											}
										}
										{"default"
											{"delay"
												{time 0.1}
											}
											{"action"
												{selector
													{tag unhold_iq}
													{state operatable}
												}
												{action attack}
												{target
													{ignore_captured_by_user 0}
													{tag enemy_near_iq}
												}
											}
											{"delay"
												{time 8}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition
								{type see_enemy}
								{selector
									{ignore_captured_by_user 0}
									{tag unhold_iq}
								}
							}
							{"delay"
								{time 0.1}
							}
						}
						{"default"
							{"delay"
								{time 5}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag unhold_iq}
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
												{state user_control}
											}
										}
									}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_state"
								{selector
									{tag unhold_iq}
									{state operatable}
								}
								{movement
									{forward off}
									{backward off}
								}
							}
							{"delay"
								{time 2}
							}
							{"actor_state"
								{selector
									{ignore_captured_by_user 0}
									{tag unhold_iq}
								}
								{fire_mode open}
								{move_mode free}
								{ai_move
									{mode enable}
								}
								{movement
									{speed slow}
									{forward on}
									{backward on}
								}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
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
									{"actor_to_cover"
										{selector
											{tag unhold_iq}
											{state operatable}
										}
										{mode random}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"actor_state"
										{selector
											{tag unhold_iq}
											{state operatable}
										}
										{fire_mode open}
										{move_mode free}
										{ai_move
											{mode enable}
										}
										{ai
											{advance_ratio 1}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag unhold_iq}
											}
										}
										{include
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state user_control}
											}
										}
									}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_state"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag bot}
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
												{tag _lua_mi}
											}
											{tag
												{tag repairing}
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
										}
									}
									{amount 4
									}
									{sort
										{type entity}
										{entity
											{ignore_captured_by_user 0}
											{tag unhold_iq}
										}
									}
								}
								{drop orders}
								{move_mode free}
								{ai_move
									{mode enable}
								}
								{ai
									{advance_ratio 1}
								}
							}
						}
						{"default"}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag unhold_iq}
						}
						{tag_add _mi_temp2}
						{tag_remove unhold_iq}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag enemy_near_iq}
							{zone "gamezone"}
							{state operatable}
						}
						{tag_add noted_by_ai}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag enemy_near_iq}
						}
						{tag_remove enemy_near_iq}
					}
					{"delay"
						{time 20}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _mi_temp2}
						}
						{tag_remove _lua_mi}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _mi_temp2}
						}
						{tag_remove _mi_temp2}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "ai/ai_unhold"}
					}
				}
			}
			{"ai/tank_alt_fight"
				{condition
					{type 1}
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag bot_tank}
										}
									}
									{include
										{prop
											{prop vehicle}
										}
										{state
											{state "moveable inhabited"}
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
											{tag _ai_defender}
										}

									}
								}
							}
							{enemy
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag _user}
										}
									}
									{include
										{state
											{state operatable}
										}
										{state
											{state user_control}
										}
									}
									{exclude
										{prop
											{prop airborne}
										}
										{state
											{state inactive}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 180}
							}
							{tag
								{"tag pair"}
								{"for selector" e_tank_alt}
								{"for enemy" p_tank_target}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{## "timer"
						{time 4}
						{title "AI tank stopping to fight"}
					}
					{## "effect"
						{selector
							{tag e_tank_alt}
						}
						{effect smoke_for_test}
					}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag p_tank_target}
									{zone "gamezone"}
									{state operatable}
								}
								{count
									{op "=="}
									{value 0}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag e_tank_alt}
								}
								{tag_remove e_tank_alt}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag p_tank_target}
								}
								{tag_remove p_tank_target}
							}
							{"delay"
								{time 15}
							}
							{"trigger"
								{name "ai/tank_alt_fight"}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"actor_state"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag e_tank_alt}
											}
										}
										{include
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state user_control}
											}
										}
									}
								}
								{drop orders}
								{fire_mode open}
								{ai_move
									{mode enable}
								}
								{movement
									{forward off}
									{backward off}
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
												{tag bot}
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
												{tag _lua_mi}
											}
											{tag
												{tag repairing}
											}
											{tag
												{tag e_tank_alt}
											}
											{state
												{state inactive}
											}
											{state
												{state linked}
											}
										}
									}
									{amount 4
									}
									{sort
										{type entity}
										{entity
											{ignore_captured_by_user 0}
											{tag e_tank_alt}
										}
									}
								}
								{tag_add temp2}
							}
							{"delay"
								{time 0.3}
							}
							{"while"
								{condition
									{type near}
									{units
										{source advanced}
										{ignore_captured_by_user 0}
										{group
											{select
												{tag
													{tag temp2}
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
													{tag e_tank_alt}
												}
											}
										}
									}
									{near_to
										{ignore_captured_by_user 0}
										{tag e_tank_alt}
									}
									{distance 100}
								}
								{"delay"
									{time 0.1}
								}
								{"entity_state"
									{selector
										{source advanced}
										{ignore_captured_by_user 0}
										{group
											{select
												{tag
													{tag temp2}
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
													{tag e_tank_alt}
												}
											}
										}
										{sort
											{type entity}
											{entity
												{ignore_captured_by_user 0}
												{tag e_tank_alt}
											}
										}
										{amount 1
										}
									}
									{tag_add e_tank_alt}
									{tag_remove temp2}
								}
								{"delay"
									{time 0.1}
								}
							}
							{"delay"
								{time 0.3}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag e_tank_alt}
									{state operatable}
								}
								{tag_add _lua_mi}
							}
							{"actor_state"
								{selector
									{ignore_captured_by_user 0}
									{tag e_tank_alt}
									{type human}
									{state operatable}
								}
								{drop orders}
								{fire_mode open}
								{move_mode free}
								{ai_move
									{mode enable}
								}
								{ai
									{advance_ratio "0.1"}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_state"
								{selector
									{ignore_captured_by_user 0}
									{tag e_tank_alt}
									{type vehicle}
								}
								{drop orders}
								{fire_mode open}
								{move_mode free}
								{ai_move
									{mode enable}
								}
								{movement
									{speed fast}
									{forward on}
									{backward on}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"squad_create"
								{selector
									{ignore_captured_by_user 0}
									{tag e_tank_alt}
									{zone "gamezone"}
									{state operatable}
								}
								{name e_tank_squad}
							}
							{"delay"
								{time 0.3}
							}
							{"switch"
								{"case"
									{condition
										{type entities}
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag e_tank_alt}
													}
												}
												{include
													{tag
														{tag "+mobilegun"}
													}
												}
											}
										}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
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
											{"action"
												{selector
													{tag e_tank_alt}
													{zone "gamezone"}
													{type vehicle}
													{state inhabited}
												}
												{drop orders}
												{action rotate}
												{target
													{ignore_captured_by_user 0}
													{tag p_tank_target}
													{zone "gamezone"}
												}
											}
											{"delay"
												{time 5}
											}
											{"actor_state"
												{selector
													{tag e_tank_alt}
													{zone "gamezone"}
													{type vehicle}
													{state inhabited}
												}
												{fire_mode open}
												{ai_move
													{mode enable}
												}
												{movement
													{forward on}
													{backward on}
												}
											}
											{"delay"
												{time 0.25}
											}
											{"action"
												{selector
													{tag e_tank_alt}
													{zone "gamezone"}
													{type vehicle}
													{state inhabited}
												}
												{action attack}
												{target
													{ignore_captured_by_user 0}
													{tag p_tank_target}
													{zone "gamezone"}
												}
											}
										}
										{"default"
											{"delay"
												{time 0.25}
											}
											{"action"
												{selector
													{tag e_tank_alt}
													{zone "gamezone"}
													{type vehicle}
													{state inhabited}
												}
												{drop orders}
												{action rotate}
												{target
													{ignore_captured_by_user 0}
													{tag p_tank_target}
													{zone "gamezone"}
												}
											}
											{"delay"
												{time 5}
											}
											{"actor_state"
												{selector
													{tag e_tank_alt}
													{zone "gamezone"}
													{type vehicle}
													{state inhabited}
												}
												{fire_mode open}
												{weapon_prepare on}
												{ai_move
													{mode enable}
												}
												{movement
													{speed fast}
													{forward on}
													{backward off}
												}
											}
											{"delay"
												{time 0.25}
											}
											{"action"
												{selector
													{tag e_tank_alt}
													{zone "gamezone"}
													{type vehicle}
													{state inhabited}
												}
												{action move}
												{target
													{ignore_captured_by_user 0}
													{tag p_tank_target}
													{zone "gamezone"}
												}
											}
											{"delay"
												{time 8}
											}
											{"actor_state"
												{selector
													{ignore_captured_by_user 0}
													{tag e_tank_alt}
													{zone "gamezone"}
													{type vehicle}
												}
												{fire_mode open}
												{move_mode free}
												{weapon_prepare on}
												{ai_move
													{mode enable}
												}
												{movement
													{speed normal}
													{forward on}
													{backward on}
												}
											}
											{"delay"
												{time 1}
											}
											{"action"
												{selector
													{tag e_tank_alt}
													{zone "gamezone"}
													{type vehicle}
													{state inhabited}
												}
												{action attack}
												{target
													{ignore_captured_by_user 0}
													{tag p_tank_target}
													{zone "gamezone"}
												}
											}
										}
									}
								}
							}
							{"delay"
								{time 1}
							}
							{"switch"
								{"case"
									{condition
										{type near}
										{units
											{tag e_tank_alt}
											{type vehicle}
											{state operatable}
										}
										{near_to
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag flag}
													}
												}
												{exclude
													{state
														{state inactive}
													}
												}
											}
										}
										{distance 100}
									}
									{"delay"
										{time 0.1}
									}
									{"effect"
										{selector
											{tag e_tank_alt}
											{type vehicle}
											{state operatable}
										}
										{effect smoke_screen}
									}
								}
								{"default"}
							}
							{"delay"
								{time 30}
							}
							{"squad_dismiss"
								{squad e_tank_squad}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_state"
								{selector
									{ignore_captured_by_user 0}
									{tag e_tank_alt}
									{zone "gamezone"}
									{type vehicle}
								}
								{movement
									{speed normal}
									{forward on}
									{backward on}
								}
							}
							{"delay"
								{time 0.5}
							}
							{"entity_state"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag p_tank_target}
											}
										}
										{include
											{state
												{state "operatable user_control"}
											}
										}
									}
								}
								{tag_add noted_by_ai}
							}
							{"delay"
								{time 1}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag e_tank_alt}
								}
								{tag_add _mi_temp5}
								{tag_remove e_tank_alt}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag p_tank_target}
								}
								{tag_remove p_tank_target}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag temp2}
								}
								{tag_remove temp2}
							}
							{"delay"
								{time 30}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag _mi_temp5}
								}
								{tag_remove _lua_mi}
							}
							{"delay"
								{time 1}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag _mi_temp5}
								}
								{tag_remove _mi_temp5}
							}
							{"delay"
								{time 0.1}
							}
							{"trigger"
								{name "ai/tank_alt_fight"}
							}
						}
					}
				}
			}
			{"ai/recrew_portables"
				{condition
					{type 1}
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag bot}
										}
									}
									{include
										{state
											{state operatable}
										}
									}
									{exclude
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag repairing}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{tag
											{tag ignore_recrew}
										}
										;{tag
										;	{tag _lua_need_next_order}
										;}
										{tag
											{tag ai_signaller}
										}
										{tag
											{tag paratrooper_need_orders}
										}
									}
								}
							}
							{enemy
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag bot_veh}
										}
										{tag
											{tag player_veh}
										}
										{tag
											{tag _ai_defender}
										}
									}
									{include
										{prop
											{prop vehicle}
										}
									}
									{exclude
										{tag
											{tag destroyed}
										}
										{tag
											{tag "_no-recrew"}
										}
										{state
											{state inhabited}
										}
										{state
											{state linked}
										}
									}
								}
								{group
									{select
										{tag
											{tag paradropped_veh}
										}
									}
									{include
										{prop
											{prop vehicle}
										}
									}
									{exclude
										{tag
											{tag destroyed}
										}
										{tag
											{tag "_no-recrew"}
										}
										{state
											{state linked}
										}
										{tag
											{tag not_selectable}
										}
										{tag
											{tag body_break}
										}
										{tag
											{tag p_cannon_enter}
										}
										{tag
											{tag trooper_to_crew}
										}
									}
								}	
							}
							{distance
								{mode near_than}
								{meters 48}
							}
							{tag
								{"tag pair"}
								{"for selector" ecrew}
								{"for enemy" ecannon_enter}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{## "timer"
						{time 4}
						{title "recrewing portables"}
					}
					{"switch"
						{"case"
							{condition
								{type see_actors}
								{selector
									{tag ecrew}
									{zone "gamezone"}
									{type human}
									{state "not dead"}
								}
								{enemy
									{ignore_captured_by_user 0}
									{tag _user}
									{state operatable}
								}
								{distance
									{mode near_than}
									{meters 45}
								}
								{detection visible}
							}
							{"delay"
								{time 1}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag ecrew}
								}
								{tag_remove ecrew}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag ecannon_enter}
								}
								{tag_remove ecannon_enter}
							}
							{"delay"
								{time 20}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag bot}
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
												{tag ecrew}
											}
											{tag
												{tag repairing}
											}
											{tag
												{tag _lua_mi}
											}
											{state
												{state inactive}
											}
											{state
												{state linked}
											}
											;{tag
											;	{tag _lua_need_next_order}
											;}
											{tag
												{tag ai_signaller}
											}
											{tag
												{tag paratrooper_need_orders}
											}
										}
									}
									{amount 2
									}
									{sort
										{type entity}
										{entity
											{ignore_captured_by_user 0}
											{tag ecrew}
										}
									}
								}
								{tag_add temp1}
							}
							{"delay"
								{time 0.3}
							}
							{"while"
								{condition
									{type near}
									{units
										{source advanced}
										{ignore_captured_by_user 0}
										{group
											{select
												{tag
													{tag temp1}
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
													{tag ecrew}
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
									{near_to
										{ignore_captured_by_user 0}
										{tag ecannon_enter}
									}
									{distance 100}
								}
								{"delay"
									{time 0.1}
								}
								{"entity_state"
									{selector
										{source advanced}
										{ignore_captured_by_user 0}
										{group
											{select
												{tag
													{tag temp1}
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
													{tag ecrew}
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
												{ignore_captured_by_user 0}
												{tag ecannon_enter}
											}
										}
										{amount 1
										}
									}
									{tag_add ecrew}
									{tag_remove temp1}
								}
								{"delay"
									{time 0.1}
								}
							}
							{"delay"
								{time 0.3}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag ecrew}
									{state operatable}
								}
								{tag_add _lua_mi}
							}
							{"actor_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag ecrew}
											}
										}
										{include
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag repairing}
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
								{drop orders}
								{fire_mode open}
								{move_mode free}
								{movement
									{speed assault}
								}
							}
							{"delay"
								{time 0.3}
							}
							{"action"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag ecrew}
											}
										}
										{include
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag repairing}
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
								{drop orders}
								{action move}
								{target
									{ignore_captured_by_user 0}
									{tag ecannon_enter}
								}
							}
							{"delay"
								{time 5}
							}
							{"switch"
								{"case"
									{condition
										{type entities}
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag ecannon_enter}
													}
												}
												{include
													{prop
														{prop vehicle}
													}
												}
												{exclude
													{tag
														{tag destroyed}
													}
													{state
														{state inhabited}
													}
												}
											}
										}
									}
									{"delay"
										{time 0.1}
									}
									{"board"
										{selector
											{source advanced}
											{group
												{select
													{tag
														{tag ecrew}
													}
												}
												{include
													{state
														{state operatable}
													}
												}
												{exclude
													{tag
														{tag repairing}
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
										{vehicle
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag ecannon_enter}
													}
												}
												{include
													{prop
														{prop vehicle}
													}
												}
												{exclude
													{tag
														{tag destroyed}
													}
												}
											}
										}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"actor_state"
										{selector
											{source advanced}
											{group
												{select
													{tag
														{tag ecrew}
													}
												}
												{include
													{state
														{state operatable}
													}
												}
												{exclude
													{tag
														{tag repairing}
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
										{drop orders}
										{fire_mode open}
										{move_mode free}
										{ai_move
											{mode enable}
										}
									}
								}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag ecrew}
									{state operatable}
								}
								{tag_add _mi_temp4}
							}
							{"delay"
								{time 20}
							}
							{"entity_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag ecrew}
											}
										}
										{include
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag repairing}
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
								{tag_remove ecrew}
							}
							;{"delay"
							;	{time 0.5}
							;}
							;{"actor_state"
							;	{selector
							;		{tag ecannon_enter}
							;		{state inhabited}
							;	}
							;	{cannon move}
							;}
							;{"effect"
							;	{selector
							;		{tag ecannon_enter}
							;		{type vehicle}
							;		{state inhabited}
							;	}
							;	{effect tag_squad_need_next_order}
							;}
							;{"delay"
							;	{time 0.5}
							;}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag ecannon_enter}
								}
								{tag_remove ecannon_enter}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag temp1}
								}
								{tag_remove temp1}
							}
							{"delay"
								{time 20}
							}
						}
					}
					{"delay"
						{time 30}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _mi_temp4}
									}
								}
								{include
									{state
										{state operatable}
									}
								}
								{exclude
									{tag
										{tag repairing}
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
						{tag_remove _lua_mi}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _mi_temp4}
						}
						{tag_remove _mi_temp4}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "ai/recrew_portables"}
					}
				}
			}
			{"ai/chance_ai_pursue"
				{condition
					{type 1}
					{terms
						{"1.near"
							{units
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag bot}
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
											{tag repairing}
										}
										{tag
											{tag _lua_mi}
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
							{near_to
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag noted_by_ai}
										}
									}
									{include
										{zone
											{zone "gamezone"}
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
											{state inactive}
										}
									}
								}
							}
							{distance 85}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag bot}
									}
								}
								{include
									{zone
										{zone "gamezone"}
									}
									{state
										{state operatable}
									}
								}
								{exclude
									{tag
										{tag repairing}
									}
									{tag
										{tag _lua_mi}
									}
									{tag
										{tag _lua_ignore}
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
									{ignore_captured_by_user 0}
									{tag noted_by_ai}
									{zone "gamezone"}
								}
							}
							{amount 5
							}
						}
						{tag_add temp4}
					}
					{"delay"
						{time 0.5}
					}
					{"while"
						{condition
							{type near}
							{units
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag temp4}
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
											{state linked}
										}
									}
								}
							}
							{near_to
								{ignore_captured_by_user 0}
								{tag noted_by_ai}
								{state operatable}
							}
							{distance 60}
						}
						{"delay"
							{time 0.1}
						}
						{"entity_state"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag temp4}
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
											{state linked}
										}
									}
								}
								{sort
									{type entity}
									{entity
										{ignore_captured_by_user 0}
										{tag noted_by_ai}
										{state operatable}
									}
								}
								{amount 1
								}
							}
							{tag_add pursuer}
							{tag_remove temp4}
						}
						{"delay"
							{time 0.1}
						}
					}
					{"delay"
						{time 0.3}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag pursuer}
							{state operatable}
						}
						{tag_add _lua_mi}
					}
					{"delay"
						{time 0.3}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag noted_by_ai}
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
								}
							}
							{sort
								{type entity}
								{entity
									{ignore_captured_by_user 0}
									{tag pursuer}
								}
							}
						}
						{tag_add pursue_target}
						{tag_remove noted_by_ai}
					}
					{"delay"
						{time 1}
					}
					{"squad_create"
						{selector
							{ignore_captured_by_user 0}
							{tag pursuer}
							{zone "gamezone"}
							{state operatable}
						}
						{name pursuer}
					}
					{"delay"
						{time 0.1}
					}
					{"actor_state"
						{selector
							{ignore_captured_by_user 0}
							{tag pursuer}
							{zone "gamezone"}
							{state operatable}
						}
						{drop orders}
						{move_mode free}
						{weapon_prepare on}
						{ai_move
							{mode enable}
						}
						{ai
							{advance_ratio "0.2"}
						}
					}
					{"delay"
						{time 0.1}
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
							{"action"
								{selector
									{ignore_captured_by_user 0}
									{tag pursuer}
									{zone "gamezone"}
									{state operatable}
								}
								{action advance}
								{target
									{ignore_captured_by_user 0}
									{tag pursue_target}
									{zone "gamezone"}
								}
							}
							{"delay"
								{time 4}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"action"
								{selector
									{ignore_captured_by_user 0}
									{tag pursuer}
									{zone "gamezone"}
									{state operatable}
								}
								{action move}
								{target
									{ignore_captured_by_user 0}
									{tag pursue_target}
									{zone "gamezone"}
								}
							}
							{"delay"
								{time 6}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition
								{type see_enemy}
								{selector
									{ignore_captured_by_user 0}
									{tag pursuer}
									{state operatable}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"action"
								{selector
									{ignore_captured_by_user 0}
									{tag pursuer}
									{state operatable}
								}
								{action attack}
								{target
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag pursue_target}
											}
										}
										{include
											{state
												{state "operatable user_control"}
											}
										}
									}
								}
							}
							{"delay"
								{time 8}
							}
						}
						{"default"
							{"delay"
								{time 5}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"actor_state"
						{selector
							{ignore_captured_by_user 0}
							{tag pursuer}
							{state operatable}
						}
						{drop orders}
						{move_mode free}
						{ai
							{advance_ratio "0.5"}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition
								{type rand}
								{value 0.5}
							}
							{"delay"
								{time 25}
							}
						}
						{"default"
							{"delay"
								{time 45}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"squad_dismiss"
						{squad pursuer}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag pursue_target}
						}
						{tag_remove pursue_target}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag pursuer}
						}
						{tag_add _mi_temp3}
						{tag_remove pursuer}
					}
					{"delay"
						{time 80}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _mi_temp3}
						}
						{tag_remove _lua_mi}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _mi_temp3}
						}
						{tag_remove _mi_temp3}
					}
					{"delay"
						{time 0.5}
					}
					{"trigger"
						{name "ai/chance_ai_pursue"}
					}
				}
			}
			{"ai/recrew_tank"
				{condition
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag bot}
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
											{tag _lua_mi}
										}
										{tag
											{tag repairing}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{tag
											{tag ignore_recrew}
										}
										{tag
											{tag _lua_need_next_order}
										}
										{tag
											{tag ai_signaller}
										}
										{tag
											{tag paratrooper_need_orders}
										}
									}
								}
							}
							{enemy
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag bot_tank}
										}
										{tag
											{tag player_armor}
										}
										{tag
											{tag bot_car}
										}
										{tag
											{tag player_car}
										}
										{tag
											{tag _ai_defense}
										}
									}
									{include
										{zone
											{zone "gamezone"}
										}
										{prop
											{prop vehicle}
										}
									}
									{exclude
										{tag
											{tag destroyed}
										}
										{tag
											{tag body_break}
										}
										{tag
											{tag ammo_cooked}
										}
										{state
											{state inhabited}
										}
										{prop
											{prop multi_board}
										}
										{prop
											{prop airborne}
										}
										{prop
											{prop cannon}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 50}
							}
							{tag
								{"tag pair"}
								{"for selector" tcrew}
								{"for enemy" etank_enter}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition
								{type see_actors}
								{selector
									{ignore_captured_by_user 0}
									{tag tcrew}
									{zone "gamezone"}
									{state operatable}
								}
								{enemy
									{ignore_captured_by_user 0}
									{tag _user}
									{state operatable}
								}
								{distance
									{mode near_than}
									{meters 46}
								}
								{detection visible}
							}
							{"delay"
								{time 1}
							}
							{"entity_state"
								{selector
									{tag tcrew}
								}
								{tag_remove tcrew}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag etank_enter}
								}
								{tag_remove etank_enter}
							}
							{"delay"
								{time 30}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag bot}
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
												{tag tcrew}
											}
											{tag
												{tag _lua_mi}
											}
											{tag
												{tag repairing}
											}
											{state
												{state inactive}
											}
											{state
												{tag ignore_recrew}
											}
											{tag
												{tag _lua_need_next_order}
											}
											{tag
												{tag ai_signaller}
											}
											{tag
												{tag paratrooper_need_orders}
											}										
										}
									}
									{sort
										{type entity}
										{entity
											{ignore_captured_by_user 0}
											{tag tcrew}
										}
									}
									{amount 1
									}
								}
								{tag_add temp3}
							}
							{"delay"
								{time 0.3}
							}
							{"while"
								{condition
									{type near}
									{units
										{source advanced}
										{ignore_captured_by_user 0}
										{group
											{select
												{tag
													{tag temp3}
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
													{tag tcrew}
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
									{near_to
										{ignore_captured_by_user 0}
										{tag etank_enter}
									}
									{distance 90}
								}
								{"delay"
									{time 0.1}
								}
								{"entity_state"
									{selector
										{source advanced}
										{ignore_captured_by_user 0}
										{group
											{select
												{tag
													{tag temp3}
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
													{tag tcrew}
												}
												{state
													{state inactive}
												}
												{state
													{state linked}
												}
												{tag
													{tag _lua_need_next_order}
												}
											}
										}
										{sort
											{type entity}
											{entity
												{ignore_captured_by_user 0}
												{tag etank_enter}
											}
										}
										{amount 1
										}
									}
									{tag_add tcrew}
									{tag_remove temp3}
								}
								{"delay"
									{time 0.1}
								}
							}
							{"delay"
								{time 0.3}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag tcrew}
									{state operatable}
								}
								{tag_add _lua_mi}
							}
							{"actor_state"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag tcrew}
											}
										}
										{include
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag repairing}
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
								{drop orders}
								{fire_mode open}
								{move_mode free}
								{movement
									{speed assault}
								}
							}
							{"delay"
								{time 0.3}
							}
							{"action"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag tcrew}
											}
										}
										{include
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag repairing}
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
								{drop orders}
								{action move}
								{target
									{ignore_captured_by_user 0}
									{tag etank_enter}
								}
							}
							{"delay"
								{time 6}
							}
							{"switch"
								{"case"
									{condition
										{type entities}
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag etank_enter}
													}
												}
												{include
													{prop
														{prop vehicle}
													}
												}
												{exclude
													{tag
														{tag destroyed}
													}
													{tag
														{tag body_break}
													}
													{tag
														{tag ammo_cooked}
													}
													{state
														{state inhabited}
													}
												}
											}
										}
									}
									{"delay"
										{time 0.1}
									}
									{"board"
										{selector
											{source advanced}
											{group
												{select
													{tag
														{tag tcrew}
													}
												}
												{include
													{state
														{state operatable}
													}
												}
												{exclude
													{tag
														{tag repairing}
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
										{vehicle
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag etank_enter}
													}
												}
												{include
													{prop
														{prop vehicle}
													}
												}
												{exclude
													{tag
														{tag destroyed}
													}
													{tag
														{tag ammo_cooked}
													}
													{tag
														{tag body_break}
													}
												}
											}
										}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"actor_state"
										{selector
											{source advanced}
											{group
												{select
													{tag
														{tag tcrew}
													}
												}
												{include
													{state
														{state operatable}
													}
												}
												{exclude
													{tag
														{tag repairing}
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
										{drop orders}
										{fire_mode open}
										{move_mode free}
										{ai_move
											{mode enable}
										}
									}
								}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag tcrew}
									{state operatable}
								}
								{tag_add _mi_temp6}
							}
							{"delay"
								{time 20}
							}
							{"entity_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag tcrew}
											}
										}
										{include
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag repairing}
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
								{tag_remove tcrew}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag temp3}
								}
								{tag_remove temp3}
							}
							{## "delay"
								{time 4}
							}
							{## "effect"
								{selector
									{tag etank_enter}
									{state inhabited}
								}
								{effect tag_squad_need_next_order}
							}							
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag etank_enter}
								}
								{tag_remove etank_enter}
							}
							{"delay"
								{time 20}
							}
						}
					}
					{"delay"
						{time 20}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _mi_temp6}
									}
								}
								{include
									{state
										{state operatable}
									}
								}
								{exclude
									{tag
										{tag repairing}
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
						{tag_remove _lua_mi}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _mi_temp6}
						}
						{tag_remove _mi_temp6}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "ai/recrew_tank"}
					}
				}
			}
			{"ai/ai_tnt_hedgehogs"
				{condition
					{expression "(1 & 2) | (1 & 3)"}
					{terms
						{"1.near"
							{units
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag bot}
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
											{tag _lua_mi}
										}
										{tag
											{tag repairing}
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
							{near_to
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag hedgehog}
										}
									}
									{include
										{zone
											{zone "gamezone"}
										}
									}
									{exclude
										{tag
											{tag crushed}
										}
									}
								}
							}
							{distance 10}
						}
						{"2.entities"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag hedgehog}
										}
									}
									{exclude
										{tag
											{tag crushed}
										}
									}
								}
							}
							{count
								{op ">"}
								{value 10}
							}
						}
						{"3.entities"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag "+chokehog"}
										}
									}
									{exclude
										{tag
											{tag crushed}
										}
									}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag bot}
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
										{tag _lua_mi}
									}
									{tag
										{tag repairing}
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
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag hedgehog}
											}
										}
										{exclude
											{tag
												{tag crushed}
											}
										}
									}
								}
							}
							{amount 1
							}
						}
						{tag_add bot_destroyer}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition
								{type near}
								{units
									{ignore_captured_by_user 0}
									{tag bot_destroyer}
									{type human}
									{state operatable}
								}
								{near_to
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag _bot}
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
												{state user_control}
											}
										}
									}
								}
								{distance 20}
							}
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag bot_destroyer}
								}
								{tag_remove bot_destroyer}
							}
							{"delay"
								{time 50}
							}
							{"trigger"
								{name "ai/ai_tnt_hedgehogs"}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type near}
										{units
											{ignore_captured_by_user 0}
											{tag bot_destroyer}
											{type human}
											{state operatable}
										}
										{near_to
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag "+chokehog"}
													}
												}
												{include
													{tag
														{tag hedgehog}
													}
												}
												{exclude
													{tag
														{tag crushed}
													}
												}
											}
										}
										{distance 10}
									}
									{"delay"
										{time 0.1}
									}
									{"entity_state"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag "+chokehog"}
													}
												}
												{exclude
													{tag
														{tag crushed}
													}
												}
											}
											{sort
												{type entity}
												{entity
													{ignore_captured_by_user 0}
													{tag bot_destroyer}
												}
											}
											{amount 1
											}
										}
										{tag_add "+tnt"}
									}
									{"squad_create"
										{selector
											{ignore_captured_by_user 0}
											{tag bot_destroyer}
											{type human}
											{state operatable}
										}
										{name e_bot_tnt}
									}
									{"delay"
										{time 0.2}
									}
									{"actor_state"
										{selector
											{ignore_captured_by_user 0}
											{tag bot_destroyer}
											{type human}
											{state operatable}
										}
										{drop orders}
										{fire_mode hold}
										{move_mode hold}
										{weapon_prepare off}
										{ai_move
											{mode disable}
											{enable_on injure}
										}
										{movement
											{speed bow}
											{kind fast}
											{type normal}
										}
									}
									{"delay"
										{time 0.1}
									}
									{"action"
										{selector
											{ignore_captured_by_user 0}
											{tag bot_destroyer}
											{type human}
											{state operatable}
										}
										{drop "orders sensor senseless"}
										{action advance}
										{target
											{ignore_captured_by_user 0}
											{tag "+tnt"}
										}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag bot_destroyer}
											{type human}
											{state operatable}
										}
										{tag_add _lua_mi}
									}
									{"delay"
										{time 15}
									}
									{"squad_dismiss"
										{squad e_bot_tnt}
									}
									{"actor_state"
										{selector
											{ignore_captured_by_user 0}
											{tag bot_destroyer}
											{type human}
											{state operatable}
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
										{time 0.1}
									}
									{"action"
										{selector
											{ignore_captured_by_user 0}
											{tag bot_destroyer}
											{type human}
											{state operatable}
										}
										{drop orders}
										{action move}
										{target
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag flag}
													}
												}
												{exclude
													{state
														{state inactive}
													}
												}
											}
											{sort
												{type entity}
												{entity
													{ignore_captured_by_user 0}
													{tag bot_destroyer}
												}
											}
											{amount 1
											}
										}
									}
									{"delay"
										{time 0.1}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag bot_destroyer}
										}
										{tag_remove _lua_mi}
									}
									{"delay"
										{time 0.1}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag bot_destroyer}
										}
										{tag_remove bot_destroyer}
									}
									{"delay"
										{time 35}
									}
									{"trigger"
										{name "ai/ai_tnt_hedgehogs"}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"actor_state"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag bot_destroyer}
													}
												}
												{include
													{state
														{state operatable}
													}
												}
											}
										}
										{drop orders}
										{fire_mode return}
										{move_mode hold}
										{ai_move
											{mode disable}
											{enable_on injure}
										}
										{movement
											{type squat}
										}
									}
									{"delay"
										{time 0.1}
									}
									{"entity_state"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag hedgehog}
													}
												}
												{exclude
													{tag
														{tag crushed}
													}
												}
											}
											{amount 4
											}
											{sort
												{type entity}
												{entity
													{ignore_captured_by_user 0}
													{tag bot_destroyer}
												}
											}
										}
										{tag_add _hedgehog}
									}
									{"delay"
										{time 0.3}
									}
									{"while"
										{condition
											{type near}
											{units
												{ignore_captured_by_user 0}
												{tag bot_destroyer}
											}
											{near_to
												{source advanced}
												{ignore_captured_by_user 0}
												{group
													{select
														{tag
															{tag _hedgehog}
														}
													}
													{exclude
														{tag
															{tag "+hedgehog"}
														}
														{tag
															{tag crushed}
														}
													}
												}
											}
											{distance 16}
										}
										{"delay"
											{time 0.1}
										}
										{"entity_state"
											{selector
												{source advanced}
												{ignore_captured_by_user 0}
												{group
													{select
														{tag
															{tag _hedgehog}
														}
													}
													{exclude
														{tag
															{tag "+hedgehog"}
														}
														{tag
															{tag crushed}
														}
													}
												}
												{sort
													{type entity}
													{entity
														{ignore_captured_by_user 0}
														{tag bot_destroyer}
													}
												}
												{amount 1
												}
											}
											{tag_add "+hedgehog"}
											{tag_remove _hedgehog}
										}
										{"delay"
											{time 0.1}
										}
									}
									{"delay"
										{time 0.2}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag _hedgehog}
										}
										{tag_remove _hedgehog}
									}
									{"delay"
										{time 0.1}
									}
									{"switch"
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag "+hedgehog"}
												}
												{count
													{op ">"}
													{value 3}
												}
											}
											{"delay"
												{time 0.1}
											}
											{"entity_state"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag "+hedgehog"}
															}
														}
													}
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag bot_destroyer}
														}
													}
													{amount 1
													}
												}
												{tag_add "+tnt"}
												{tag_remove "+hedgehog"}
											}
											{"squad_create"
												{selector
													{ignore_captured_by_user 0}
													{tag bot_destroyer}
													{type human}
													{state operatable}
												}
												{name e_bot_tnt}
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
															{tag
																{tag "+hedgehog"}
															}
														}
														{exclude
															{tag
																{tag "+tnt"}
															}
														}
													}
												}
												{tag_remove "+hedgehog"}
											}
											{"actor_state"
												{selector
													{ignore_captured_by_user 0}
													{tag bot_destroyer}
													{type human}
													{state operatable}
												}
												{drop orders}
												{fire_mode hold}
												{move_mode hold}
												{weapon_prepare off}
												{ai_move
													{mode disable}
													{enable_on injure}
												}
												{movement
													{speed bow}
													{kind fast}
													{type normal}
												}
											}
											{"delay"
												{time 0.1}
											}
											{"action"
												{selector
													{ignore_captured_by_user 0}
													{tag bot_destroyer}
													{type human}
													{state operatable}
												}
												{drop "orders sensor senseless"}
												{action advance}
												{target
													{ignore_captured_by_user 0}
													{tag "+tnt"}
												}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{tag bot_destroyer}
													{type human}
													{state operatable}
												}
												{tag_add _lua_mi}
											}
											{"delay"
												{time 15}
											}
											{"squad_dismiss"
												{squad e_bot_tnt}
											}
											{"actor_state"
												{selector
													{ignore_captured_by_user 0}
													{tag bot_destroyer}
													{type human}
													{state operatable}
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
												{time 0.1}
											}
											{"action"
												{selector
													{ignore_captured_by_user 0}
													{tag bot_destroyer}
													{type human}
													{state operatable}
												}
												{drop orders}
												{action move}
												{target
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag flag}
															}
														}
														{exclude
															{state
																{state inactive}
															}
														}
													}
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag bot_destroyer}
														}
													}
													{amount 1
													}
												}
											}
											{"delay"
												{time 0.1}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{tag bot_destroyer}
												}
												{tag_remove _lua_mi}
											}
											{"delay"
												{time 0.1}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{tag bot_destroyer}
												}
												{tag_remove bot_destroyer}
											}
											{"delay"
												{time 35}
											}
											{"trigger"
												{name "ai/ai_tnt_hedgehogs"}
											}
										}
										{"default"
											{"delay"
												{time 0.1}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{tag bot_destroyer}
												}
												{tag_remove bot_destroyer}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{tag "+hedgehog"}
												}
												{tag_remove "+hedgehog"}
											}
											{"delay"
												{time 50}
											}
											{"trigger"
												{name "ai/ai_tnt_hedgehogs"}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			{"ai/ai_tnt_do"
				{condition
					{terms
						{"1.trigger"
							{name "ai/ai_tnt_hedgehogs"}
						}
						{"2.near"
							{units
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag bot_destroyer}
										}
									}
									{include
										{tag
											{tag _lua_mi}
										}
										{state
											{state operatable}
										}
									}
								}
							}
							{near_to
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag "+tnt"}
										}
									}
									{exclude
										{tag
											{tag crushed}
										}
									}
								}
							}
							{distance 2}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"inventory"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag bot_destroyer}
									}
								}
								{include
									{tag
										{tag _lua_mi}
									}
									{state
										{state operatable}
									}
								}
							}
						}
						{action add}
						{item "dynamite_ger_x7"}
					}
					{"delay"
						{time 0.5}
					}
					{"action"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag bot_destroyer}
									}
								}
								{include
									{tag
										{tag _lua_mi}
									}
									{state
										{state operatable}
									}
								}
							}
						}
						{drop orders}
						{action put_dynamite}
						{target
							{ignore_captured_by_user 0}
							{tag null}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"while"
						{condition
							{type near}
							{units
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag bot}
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
											{tag bot_destroyer}
										}
										{tag
											{tag temp5}
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
							{near_to
								{ignore_captured_by_user 0}
								{tag "+tnt"}
							}
							{distance 10}
						}
						{"delay"
							{time 0.1}
						}
						{"entity_state"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag bot}
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
											{tag temp5}
										}
										{tag
											{tag bot_destroyer}
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
										{ignore_captured_by_user 0}
										{tag "+tnt"}
									}
								}
								{amount 2
								}
							}
							{tag_add _temp5}
						}
						{"delay"
							{time 0.1}
						}
						{"action"
							{selector
								{ignore_captured_by_user 0}
								{tag _temp5}
								{type human}
								{state operatable}
							}
							{drop "orders sensor senseless"}
							{action move}
							{target
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag flag}
										}
									}
									{exclude
										{state
											{state inactive}
										}
									}
								}
								{sort
									{type entity}
									{entity
										{ignore_captured_by_user 0}
										{tag _temp5}
									}
								}
								{amount 1
								}
							}
						}
						{"delay"
							{time 0.1}
						}
						{"entity_state"
							{selector
								{ignore_captured_by_user 0}
								{tag _temp5}
							}
							{tag_add temp5}
							{tag_remove _temp5}
						}
						{"delay"
							{time 0.2}
						}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag temp5}
						}
						{tag_remove temp5}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag "+tnt"}
						}
						{tag_remove "+tnt"}
					}
					{"delay"
						{time 18}
					}
					{"trigger"
						{name "ai/ai_tnt_do"}
					}
				}
			}