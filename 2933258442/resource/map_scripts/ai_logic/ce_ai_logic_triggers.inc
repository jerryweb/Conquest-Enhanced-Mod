;============== AI Purchase Priority Scripts ==============					
			{"ai/purchase_priority/set_de-miner_priority"
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
											{prop mine_exploder}
										}
										{state
											{state operatable}
										}
										{prop
											{prop vehicle}
										}
									}
									{exclude
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
							{count
								{op "<<"}
								{value 1}
							}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag mine_planted}
										}
									}
									{include
										{tag
											{tag at_mine}
										}
									}
								}
							}
							{count
								{op ">"}
								{value 30}
							}
						}
						{"3.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 1}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{tag scene_variable}
						}
						{tag_add _prioritize_de_miner}
					}
					{"delay"
						{time 240}
					}
					{"trigger"
						{name "ai/purchase_priority/set_de-miner_priority"}
					}
				}
			}
			{"ai/purchase_priority/reduce_deminer_priortity"
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
											{prop mine_exploder}
										}
										{state
											{state operatable}
										}
										{prop
											{prop vehicle}
										}
									}
									{exclude
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
							{count
								{op ">="}
								{value 1}
							}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag scene_variable}
										}
									}
									{include
										{tag
											{tag _prioritize_de_miner}
										}
									}
								}
							}
							{count
								{op "=="}
								{value 1}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{tag scene_variable}
						}
						{tag_remove _prioritize_de_miner}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "ai/purchase_priority/reduce_deminer_priortity"}
					}
				}
			}

;============== AI GRENADES	==============		
			{"ai_logic/ai_add_smoke_grenade"
				{condition
					{terms
						{"1.cmp_i"
							{var "ai_attack_started$"}
							{op ">"}
							{value 0}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{zone
											{zone "gamezone"}
										}
									}
									{include
										{with_item
											{type amount}
											{item "smoke_grenade"}
											{min 1}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{tag
											{tag cmp_def}
										}
										{tag
											{tag _def}
										}
										{tag
											{tag _user_ally}
										}
										{tag
											{tag ignore_give_smoke}
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
										{with_item
											{type amount}
											{item "smokecustom"}
											{min 1}
										}
									}
								}
							}
						}
					}
				}
				{actions
					{## "timer"
						{time 10}
						{title "giving AI smoke"}
					}
					{"delay"
						{time 10}
					}
					{"effect"
						{selector
							{source advanced}
							{group
								{select
									{zone
										{zone "gamezone"}
									}
								}
								{include
									{with_item
										{type amount}
										{item "smoke_grenade"}
										{min 1}
									}
									{prop
										{prop human}
									}
								}
								{exclude
									{tag
										{tag cmp_def}
									}
									{tag
										{tag _def}
									}
									{tag
										{tag _user_ally}
									}
									{tag
										{tag ignore_give_smoke}
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
									{with_item
										{type amount}
										{item "smokecustom"}
										{min 1}
									}
								}
							}
							{amount 15
							}
						}
						{effect add_custom_smoke_grenade}
					}
					{"delay"
						{time 1}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "bot_army$"}
								{op "=="}
								{value 1}
							}
							{"inventory"
								{selector
									{tag give_custom_smoke_grenade}
									{type human}
									{state operatable}
								}
								{action add}
								{item "ai_rdg1_smoke" "grenade"}
								{stack 0}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "bot_army$"}
								{op "=="}
								{value 2}
							}
							{"switch"
								{"case"
									{condition
										{type rand}
										{value 0.75}
									}
									{"inventory"
										{selector
											{tag give_custom_smoke_grenade}
											{type human}
											{state operatable}
										}
										{action add}
										{item "ai_m24_smoke" "grenade"}
										{stack 0}
									}
								}
								{"default"
									{"inventory"
										{selector
											{tag give_custom_smoke_grenade}
											{type human}
											{state operatable}
										}
										{action add}
										{item "ai_nbk39" "grenade"}
										{stack 0}
									}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "bot_army$"}
								{op "=="}
								{value 3}
							}
							{"switch"
								{"case"
									{condition
										{type rand}
										{value 0.4}
									}
									{"inventory"
										{selector
											{tag give_custom_smoke_grenade}
											{type human}
											{state operatable}
										}
										{action add}
										{item "ai_m42_wp" "grenade"}
										{stack 0}
									}
								}
								{"default"
									{"inventory"
										{selector
											{tag give_custom_smoke_grenade}
											{type human}
											{state operatable}
										}
										{action add}
										{item "ai_m43_smoke" "grenade"}
										{stack 0}
									}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "bot_army$"}
								{op "=="}
								{value 4}
							}
							{"switch"
								{## "case"
									{condition
										{type rand}
										{value 0.4}
									}
									{"inventory"
										{selector
											{tag give_custom_smoke_grenade}
											{type human}
											{state operatable}
										}
										{action add}
										{item "ai_m15_wp" "grenade"}
										{stack 0}
									}
								}
								{"default"
									{"inventory"
										{selector
											{tag give_custom_smoke_grenade}
											{type human}
											{state operatable}
										}
										{action add}
										{item "ai_anm8_smoke" "grenade"}
										{stack 0}
									}
								}
							}
						}
						{"default"
							{"inventory"
								{selector
									{tag give_custom_smoke_grenade}
									{type human}
									{state operatable}
								}
								{action add}
								{item "ai_nbk39" "grenade"}
								{stack 0}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{tag give_custom_smoke_grenade}
							{type human}
							{state operatable}
						}
						{tag_add ignore_give_smoke}
						{tag_remove give_custom_smoke_grenade}
					}
					{"delay"
						{time 30}
					}
					{"trigger"
						{name "ai_logic/ai_add_smoke_grenade"}
					}
				}
			}

;============== AI ENGINEER SCRIPTS =============
			{"ai_logic/tag_ai_engineer"
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
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
										{with_item
											{type existance}
											{item "pickaxe"}
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
										{state
											{state user_control}
										}
										{tag
											{tag ai_engineer}
										}
										{tag
											{tag player}
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
									}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.5}
					}
					{"effect"
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
									{state
										{state operatable}
									}
									{prop
										{prop human}
									}
									{with_item
										{type existance}
										{item "pickaxe"}
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
									{state
										{state user_control}
									}
									{tag
										{tag ai_engineer}
									}
									{tag
										{tag player}
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
								}
							}
						}
						{effect tag_ai_engineer}
					}
					{"delay"
						{time 0.5}
					}
					{"actor_state"
						{selector
							{tag ai_engineer}
							{type human}
							{state "not dead"}
						}
						{movement
							{speed assault}
							{kind fast}
						}
						{ai
							{follow_commander off}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"inventory"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag ai_engineer}
									}
								}
								{include
									{with_item
										{type existance}
										{item "pickaxe"}
									}
									{state
										{state operatable}
									}
								}
								{exclude
									{tag
										{tag player}
									}
									{state
										{state dead}
									}
									{state
										{state user_control}
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
						{action remove}
						{item "pickaxe"}
					}
					{"delay"
						{time 0.5}
					}
					{"trigger"
						{name "ai_logic/tag_ai_engineer"}
					}
				}
			}
			{"ai_logic/clear_mines"
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
											{prop mine_exploder}
										}
										{state
											{state operatable}
										}
										{prop
											{prop vehicle}
										}
									}
									{exclude
										{state
											{state user_control}
										}
										{tag
											{tag clearing_mines}
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
						{"2.entities"
							{selector
								{tag mine_planted}
								{zone "gamezone"}
							}
						}
						{"3.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 1}
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
							}
							{include
								{prop
									{prop mine_exploder}
								}
								{state
									{state operatable}
								}
								{prop
									{prop vehicle}
								}
							}
							{exclude
								{state
									{state user_control}
								}
								{tag
									{tag clearing_mines}
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
							{source current}
						}
						{tag_add mine_clearer_selected}
					}
					{"delay"
						{time 0.5}
					}
					{"select"
						{amount 1
						}
						{tag mine_clearer_selected}
						{zone "gamezone"}
						{state operatable}
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
										{tag mine_planted}
									}
								}
								{exclude
									{tag
										{tag selected_for_clearing}
									}
									{state
										{state inactive}
									}
									{tag
										{tag mine_to_clear}
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
												{tag mine_clearer_selected}
											}
										}
										{include
											{state
												{state operatable}
											}
											{zone
												{zone "gamezone"}
											}
										}
										{exclude
											{state
												{state inactive}
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
						{tag_add mine_to_clear}
					}
					{"delay"
						{time 0.5}
					}
					{"action"
						{selector
							{source current}
						}
						{drop orders}
						{action advance}
						{target
							{source advanced}
							{group
								{select
									{tag
										{tag mine_to_clear}
									}
								}
								{exclude
									{state
										{state inactive}
									}
								}
							}
							{amount 1
							}
						}
					}
					{"loop" 8
						{"entity_state"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag mine_planted}
										}
									}
									{exclude
										{tag
											{tag selected_for_clearing}
										}
										{state
											{state inactive}
										}
										{tag
											{tag mine_to_clear}
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
													{tag mine_to_clear}
												}
											}
											{include
												{zone
													{zone "gamezone"}
												}
											}
											{exclude
												{state
													{state inactive}
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
							{tag_add mine_to_clear}
						}
						{"delay"
							{time 0.5}
						}
						{"action"
							{selector
								{source current}
							}
							{action advance}
							{target
								{source advanced}
								{group
									{select
										{tag
											{tag mine_to_clear}
										}
									}
									{exclude
										{tag
											{tag selected_for_clearing}
										}
										{state
											{state inactive}
										}
									}
								}
								{amount 1
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
											{tag mine_to_clear}
										}
									}
									{exclude
										{state
											{state inactive}
										}
									}
								}
							}
							{tag_add selected_for_clearing}
							{tag_remove mine_to_clear}
						}
						{"delay"
							{time 0.5}
						}
					}
					{"delay"
						{time 5}
					}
					{"action"
						{selector
							{source current}
						}
						{action advance}
						{target
							{source advanced}
							{group
								{select
									{tag
										{tag mine_planted}
									}
								}
								{exclude
									{state
										{state inactive}
									}
									{tag
										{tag selected_for_clearing}
									}
								}
							}
							{sort
								{type shuffle}
							}
							{amount 1
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{tag selected_for_clearing}
						}
						{tag_remove selected_for_clearing}
					}
					{"delay"
						{time 1}
					}
					{"actor_state"
						{selector
							{source current}
						}
						{fire_mode return}
						{movement
							{backward off}
						}
					}
					{"delay"
						{time 1}
					}
					{"effect"
						{selector
							{source current}
						}
						{effect search_for_minses}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "ai_logic/clear_mines"}
					}
				}
			}
			{"ai_logic/hide_mine_sweeper_not_needed"
				{condition
					{expression "(1 & 2 & 3) | (2 & 3 & 4)"}
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
											{prop mine_exploder}
										}
										{state
											{state operatable}
										}
										{prop
											{prop vehicle}
										}
									}
									{exclude
										{state
											{state user_control}
										}
										{tag
											{tag mine_clear_not_needed}
										}
										{state
											{state linked}
										}
										{state
											{state inactive}
										}
										{tag
											{tag return_home}
										}
										{tag
											{tag mine_clear_not_needed}
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
											{tag mine_planted}
										}
									}
									{include
										{tag
											{tag at_mine}
										}
									}
								}
							}
							{count
								{op "<<"}
								{value 5}
							}
						}
						{"3.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 1}
						}
						{"4.entities"
							{selector
								{source advanced}
								{group
									{select
										{zone}
									}
									{include
										{prop
											{prop mine_exploder}
										}
										{state
											{state operatable}
										}
										{prop
											{prop vehicle}
										}
										{tag
											{tag return_home}
										}
									}
									{exclude
										{state
											{state user_control}
										}
										{tag
											{tag mine_clear_not_needed}
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
					{"delay"
						{time 1}
					}
					{"effect"
						{selector
							{source advanced}
							{group
								{select
									{zone}
								}
								{include
									{prop
										{prop mine_exploder}
									}
									{state
										{state operatable}
									}
									{prop
										{prop vehicle}
									}
								}
								{exclude
									{state
										{state user_control}
									}
									{state
										{state inactive}
									}
									{state
										{state linked}
									}
									{tag
										{tag mine_clear_not_needed}
									}
								}
							}
						}
						{effect remove_mine_sweeper}
					}
					{"delay"
						{time 1}
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
									{prop
										{prop vehicle}
									}
									{prop
										{prop mine_exploder}
									}
									{state
										{state operatable}
									}
								}
								{exclude
									{tag
										{tag return_home}
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
									{tag
										{tag mine_clear_not_needed}
									}
								}
							}
						}
						{tag_add return_home}
					}
					{"delay"
						{time 1}
					}
					{"action"
						{selector
							{tag return_home}
							{zone "gamezone"}
							{type vehicle}
							{state operatable}
						}
						{drop orders}
						{action advance}
						{target
							{amount 1
							}
							{tag ai_spawn}
						}
					}
					{"delay"
						{time 1}
					}
					{"delete"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag return_home}
									}
								}
							}
						}
					}
					{"trigger"
						{name "ai_logic/hide_mine_sweeper_not_needed"}
					}
				}
			}
			{"ai_logic/ai_repair_vehicles"
				{condition
					{expression "1 & 2 & 3"}
					{terms
						{"1.entities"
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
								{group
									{select
										{tag
											{tag _bot}
										}
									}
									{include
										{broken_components
											{masks
												"trackleft"
											}
										}
										{state
											{state inhabited}
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
								{group
									{select
										{tag
											{tag _bot}
										}
									}
									{include
										{broken_components
											{masks
												"trackright"
											}
										}
										{state
											{state inhabited}
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
							}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag ai_engineer}
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
										{tag
											{tag repairing}
										}
										{tag
											{tag player}
										}
										{tag
											{tag engineer_action}
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
											{tag player_hedgehog}
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
								{op "<<"}
								{value 4}
							}
						}
					}
				}
				{actions
					{"select"
						{source advanced}
						{group
							{select
								{tag
									{tag ai_engineer}
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
								{tag
									{tag repairing}
								}
								{tag
									{tag player}
								}
								{tag
									{tag engineer_action}
								}
							}
						}
						{amount 1
						}
					}
					{"delay"
						{time 0.2}
					}
					{"effect"
						{selector
							{source current}
						}
						{effect prep_to_repair_veh}
					}
					{"delay"
						{time 0.2}
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
						{amount 1
						}
					}
					{"delay"
						{time 0.2}
					}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{tag action_repair}
									{zone "gamezone"}
									{type human}
									{state "not dead"}
								}
								{count
									{op "=="}
									{value 0}
								}
							}
							{"entity_state"
								{selector
									{tag action_repair}
								}
								{tag_remove action_repair}
							}
							{"delay"
								{time 1}
							}
							{"trigger"
								{name "ai_logic/ai_repair_vehicles"}
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
											{state
												{state "operatable inhabited"}
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
									{group
										{select
											{tag
												{tag _bot}
											}
										}
										{include
											{broken_components
												{masks
													"trackleft"
												}
											}
											{state
												{state inhabited}
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
									{group
										{select
											{tag
												{tag _bot}
											}
										}
										{include
											{broken_components
												{masks
													"trackright"
												}
											}
											{state
												{state inhabited}
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
								}
							}
							{"entity_state"
								{selector
									{source advanced}
									{group
										{select
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
											{state
												{state "operatable inhabited"}
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
									{group
										{select
											{tag
												{tag _bot}
											}
										}
										{include
											{broken_components
												{masks
													"trackleft"
												}
											}
											{state
												{state inhabited}
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
									{group
										{select
											{tag
												{tag _bot}
											}
										}
										{include
											{broken_components
												{masks
													"trackright"
												}
											}
											{state
												{state inhabited}
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
											{tag ai_spawn}
											{zone "gamezone"}
										}
									}
									{amount 1
									}
								}
								{tag_add repair_target}
							}
						}
						{"default"
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
						}
					}
					{"delay"
						{time 0.4}
					}
					{"action"
						{selector
							{source current}
						}
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
					{"delay"
						{time 0.2}
					}
					{"actor_state"
						{selector
							{source current}
						}
						{movement
							{speed assault}
							{kind fast}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"effect"
						{selector
							{tag repair_target}
						}
						{effect ignore_repair_75}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source current}
						}
						{tag_remove action_repair}
					}
					{"delay"
						{time 0.5}
					}
					{"trigger"
						{name "ai_logic/ai_repair_vehicles"}
					}
				}
			}
			{"ai_logic/ai_engineer_set_dynamite_on_barricade"
				{condition
					{terms
						{"1.near"
							{units
								{tag attacking_hedgehog}
								{zone "gamezone"}
								{type human}
								{state "not dead"}
							}
							{near_to
								{source advanced}
								{group
									{select
										{tag
											{tag player_hedgehog}
										}
									}
									{exclude
										{tag
											{tag crushed}
										}
										{tag
											{tag dynamite_set}
										}
										{state
											{state inactive}
										}
									}
								}
							}
							{distance 5}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"effect"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag player_hedgehog}
									}
								}
								{exclude
									{tag
										{tag crushed}
									}
									{tag
										{tag dynamite_set}
									}
									{state
										{state inactive}
									}
								}
							}
							{sort
								{type entity}
								{entity
									{tag attacking_hedgehog}
									{zone "gamezone"}
									{type human}
									{state "not dead"}
								}
							}
							{amount 1
							}
						}
						{effect set_dynamite}
					}
					{"delay"
						{time 4}
					}
					{"trigger"
						{name "ai_logic/ai_engineer_set_dynamite_on_barricade"}
					}
				}
			}
			{"ai_logic/destory_hedgehogs_simple"
				{condition
					{expression "1 & 2 & !3"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag ai_engineer}
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
											{state inactive}
										}
										{state
											{state linked}
										}
										{state
											{state user_control}
										}
										{tag
											{tag repairing}
										}
										{tag
											{tag action_repair}
										}
										{tag
											{tag engineer_action}
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
											{tag player_hedgehog}
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
						{"3.trigger"
							{name "ai_logic/ai_repair_vehicles"}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"select"
						{source advanced}
						{group
							{select
								{tag
									{tag ai_engineer}
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
									{state inactive}
								}
								{state
									{state linked}
								}
								{state
									{state user_control}
								}
								{tag
									{tag repairing}
								}
								{tag
									{tag action_repair}
								}
								{tag
									{tag engineer_action}
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
											{tag player_hedgehog}
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
					{"delay"
						{time 0.5}
					}
					{"effect"
						{selector
							{source current}
						}
						{effect prep_to_destroy_hedgehogs}
					}
					{"delay"
						{time 0.5}
					}
					{"select"
						{tag action_destroy_hedgehog}
						{type human}
						{state operatable}
					}
					{"delay"
						{time 1}
					}
					{"action"
						{selector
							{source current}
						}
						{drop orders}
						{action advance}
						{target
							{source advanced}
							{group
								{select
									{tag
										{tag player_hedgehog}
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
									{source advanced}
									{group
										{select
											{tag
												{tag action_destroy_hedgehog}
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
												{tag engineer_action}
											}
											{state
												{state dead}
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
								}
							}
							{amount 1
							}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"actor_state"
						{selector
							{source current}
						}
						{movement
							{speed assault}
							{kind fast}
						}
					}
					{"delay"
						{time 20}
					}
					{"trigger"
						{name "ai_logic/destory_hedgehogs_simple"}
					}
				}
			}
			{"ai_logic/clear_dynamite_area"
				{condition
					{terms
						{"1.near"
							{units
								{ignore_captured_by_user 0}
								{tag attacking_hedgehog}
								{type human}
								{state operatable}
							}
							{near_to
								{tag dynamite_planted}
							}
							{distance 10}
						}
					}
				}
				{actions
					{"select"
						{source advanced}
						{group
							{select
								{tag
									{tag attacking_hedgehog}
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
								{state
									{state dead}
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
						{sort
							{type entity}
							{entity
								{amount 1
								}
								{tag player_hedgehog}
							}
						}
						{amount 1
						}
					}
					{"effect"
						{selector
							{source current}
						}
						{effect clear_dynamite_area}
					}
					{"delay"
						{time 0.5}
					}
					{"action"
						{selector
							{tag run}
							{type human}
							{state operatable}
						}
						{drop orders}
						{action move}
						{target
							{amount 1
							}
							{tag ai_spawn}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"actor_state"
						{selector
							{tag run}
							{type human}
							{state operatable}
						}
						{fire_mode open}
						{movement
							{speed assault}
							{kind fast}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"trigger"
						{name "ai_logic/clear_dynamite_area"}
					}
				}
			}

;============== AI ATTACK LOGIC ==========
			{"ai_logic/force_move_ai_cannons"
				{condition
					{expression "1"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
										}
									}
									{include
										{prop
											{prop cannon}
										}
										{state
											{state operatable}
										}
									}
									{exclude
										{state
											{state linked}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{tag
											{tag ignore_ai_cannon_move}
										}
										{tag
											{tag _user_ally}
										}
										{tag
											{tag artillery}
										}
										{tag
											{tag heavy_artillery}
										}
										{tag
											{tag rocket_artillery}
										}
									}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 120}
					}
					{"while"
						{condition
							{type see_actors}
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
										}
									}
									{include
										{prop
											{prop cannon}
										}
										{state
											{state operatable}
										}
									}
									{exclude
										{state
											{state linked}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{tag
											{tag ignore_ai_cannon_move}
										}
										{tag
											{tag _user_ally}
										}
										{tag
											{tag artillery}
										}
										{tag
											{tag heavy_artillery}
										}
										{tag
											{tag rocket_artillery}
										}
									}
								}
							}
							{enemy
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
										{state
											{state dead}
										}
										{state
											{state inactive}
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
							{distance
								{mode near_than}
								{meters 50}
							}
							{tag
								{"tag pair"}
								{"for selector" ignore_ai_cannon_move}
							}
						}
						{"delay"
							{time 0.2}
						}
					}
					{"select"
						{source advanced}
						{group
							{select
								{tag
									{tag _bot}
								}
							}
							{include
								{prop
									{prop cannon}
								}
								{state
									{state operatable}
								}
							}
							{exclude
								{state
									{state linked}
								}
								{state
									{state inactive}
								}
								{state
									{state user_control}
								}
								{tag
									{tag ignore_ai_cannon_move}
								}
								{tag
									{tag _user_ally}
								}
								{tag
									{tag artillery}
								}
								{tag
									{tag heavy_artillery}
								}
								{tag
									{tag rocket_artillery}
								}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"actor_state"
						{selector
							{source current}
						}
						{cannon move}
					}
					{"delay"
						{time 0.2}
					}
					{"effect"
						{selector
							{source current}
						}
						{effect tag_squad_need_next_order}
					}
					{"delay"
						{time 3}
					}
					{"actor_state"
						{selector
							{source current}
						}
						{cannon move}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{source current}
						}
						{tag_remove ai_connon_to_move}
					}
					{"delay"
						{time 2}
					}
					{"trigger"
						{name "ai_logic/force_move_ai_cannons"}
					}
				}
			}
			{"ai_logic/reverse_tank_to_repair"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.near"
							{units
								{source advanced}
								{group
									{select
										{tag
											{tag turret_brake}
										}
										{tag
											{tag gun_brake}
										}
									}
									{include
										{zone
											{zone "gamezone"}
										}
										{prop
											{prop tank}
										}
										{tag
											{tag _bot}
										}
										{state
											{state "operatable inhabited"}
										}
									}
									{exclude
										{state
											{state user_control}
										}
										{state
											{state linked}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _user_ally}
										}
										{broken_components
											{masks
												"trackleft"
											}
										}
										{broken_components
											{masks
												"trackright"
											}
										}
										{tag
											{tag engine_brake}
										}
										{tag
											{tag selected_tank_to_repair}
										}
										{tag
											{tag reversing_to_repair}
										}
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
								}
							}
							{near_to
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
							{distance 200}
						}
						{"2.trigger"
							{name "ai_logic/stop_reversing"}
						}
					}
				}
				{actions
					{"delay"
						{time 5}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag turret_brake}
									}
									{tag
										{tag gun_brake}
									}
								}
								{include
									{zone
										{zone "gamezone"}
									}
									{prop
										{prop tank}
									}
									{tag
										{tag _bot}
									}
									{state
										{state "operatable inhabited"}
									}
								}
								{exclude
									{state
										{state user_control}
									}
									{state
										{state linked}
									}
									{state
										{state inactive}
									}
									{tag
										{tag _user_ally}
									}
									{broken_components
										{masks
											"trackleft"
										}
									}
									{broken_components
										{masks
											"trackright"
										}
									}
									{tag
										{tag engine_brake}
									}
									{tag
										{tag selected_tank_to_repair}
									}
									{tag
										{tag reversing_to_repair}
									}
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
							}
							{sort
								{type entity}
								{entity
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
											{zone
												{zone "gamezone"}
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
									{amount 1
									}
								}
							}
							{amount 1
							}
						}
						{tag_add selected_tank_to_repair}
					}
					{"delay"
						{time 0.2}
					}
					{"select"
						{tag selected_tank_to_repair}
						{type tank}
						{state inhabited}
					}
					{"delay"
						{time 0.2}
					}
					{"actor_state"
						{selector
							{source current}
						}
						{drop orders}
						{movement
							{speed fast}
							{kind fast}
							{forward off}
							{backward on}
						}
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
							{source advanced}
							{group
								{select
									{tag
										{tag ai_spawn}
									}
								}
								{include
									{zone
										{zone "gamezone"}
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
									{tag selected_tank_to_repair}
									{type tank}
									{state inhabited}
								}
							}
						}
					}
					{"delay"
						{time 0.2}
					}
					{"effect"
						{selector
							{source current}
						}
						{effect retreat_to_repair}
					}
					{## "timer"
						{time 120}
						{title "falling back"}
					}
					{"delay"
						{time 0.2}
					}
					{"trigger"
						{name "ai_logic/reverse_tank_to_repair"}
					}
				}
			}
			{"ai_logic/stop_reversing"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag ai_stop_reversing}
										}
									}
								}
							}
						}
						{"2.trigger"
							{name "ai_logic/reverse_tank_to_repair"}
						}
					}
				}
				{actions
					{## "timer"
						{time 3}
						{title "AI tank stop reversing"}
					}
					{"entity_state"
						{selector
							{amount 1
							}
							{tag ai_stop_reversing}
							{type vehicle}
							{state inhabited}
						}
						{tag_add reversing_ai_selected}
						{tag_remove ai_stop_reversing}
					}
					{"delay"
						{time 0.1}
					}
					{"select"
						{amount 1
						}
						{tag reversing_ai_selected}
						{type vehicle}
						{state inhabited}
					}
					{"delay"
						{time 0.1}
					}
					{"effect"
						{selector
							{source current}
						}
						{effect engine_toggle}
					}
					{"delay"
						{time 0.1}
					}
					{"effect"
						{selector
							{tag reversing_ai_selected}
						}
						{effect tag_ai_for_static_repairng}
					}
					{"delay"
						{time 0.2}
					}
					{"trigger"
						{name "ai_logic/stop_reversing"}
					}
				}
			}
			{"ai_logic/enable_forward_movement"
				{condition
					{expression "1"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag ai_ready_to_move}
										}
									}
								}
							}
						}
					}
				}
				{actions
					{## "timer"
						{time 3}
						{title "AI tank stop reversing"}
					}
					{"entity_state"
						{selector
							{amount 1
							}
							{tag ai_ready_to_move}
							{type vehicle}
							;{state inhabited}
						}
						{tag_add ready_to_move_ai_selected}
					}
					{"delay"
						{time 0.1}
					}
					{"select"
						{amount 1
						}
						{tag ready_to_move_ai_selected}
						{type vehicle}
						;{state inhabited}
					}
					{"delay"
						{time 0.1}
					}
					{"effect"
						{selector
							{source current}
						}
						{effect engine_toggle}
					}
					;{"effect"
					;	{selector
					;		{source current}
					;	}
					;	{effect engine_toggle}
					;}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag ready_to_move_ai_selected}
						}
						{tag_remove ai_ready_to_move}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag ready_to_move_ai_selected}
						}
						{tag_remove ready_to_move_ai_selected}
					}
					{"delay"
						{time 0.2}
					}
					{"trigger"
						{name "ai_logic/stop_reversing"}
					}
				}
			}

;============== AI AIR =========================
			{"ai_logic/air/set_air_raid_event"
				{condition
					{expression "(1 & 2) | 3"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag user_plane}
										}
									}
									{include
										{state
											{state user_control}
										}
										{prop
											{prop drop_plane}
										}
										{state
											{state operatable}
										}
									}
									{exclude
										{tag
											{tag dropping_troopers}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{tag
											{tag moving_to_drop_zone}
										}
										{tag
											{tag on_mission}
										}
									}
								}
							}
						}
						{"2.cmp_i"
							{var "noresusenabled$"}
							{op "=="}
							{value 1}
						}
						{"3.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag move_to_start_waypoint}
										}
									}
									{include
										{prop
											{prop airborne}
										}
										{state
											{state "operatable inhabited"}
										}
									}
									{exclude
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{tag
											{tag cmp_def}
										}
										{state
											{state user_control}
										}
										;{prop
										;	{prop ai_recon_plane}
										;}
									}
								}
							}
						}
					}
				}
				{actions
					
					{"event"
						{event "air_raid_warning"}
						{mode set}
						{delay 12}
					}
					{"event"
						{event "air_raid_start"}
						{mode set}
						{delay 24}
					}
					{"if"
						{condition
							{type entities}
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag user_plane}
										}
									}
									{include
										{prop
											{prop drop_plane}
										}
										{state
											{state inhabited}
										}
									}
									{exclude
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{tag
											{tag ai}
										}
									}
								}
							}
						}
						{"effect"
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
											{prop map_point}
										}
									}
								}
							}
							{effect spawn_ai_waypoint_poles}
						}
					}
					{## "timer"
						{time 15}
						{title "air raid started"}
                    }
				}
			}
			{"ai_logic/air/big_air_raid_alarm"
				{condition
					{terms
						{"1.event"
							{id "air_raid_warning"}
						}
					}
				}
				{actions
					{"delay"
						{time 5}
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
												{tag drop_plane}
											}
										}
										{include
											{prop
												{prop airborne}
											}
											{state
												{state operatable}
											}
											{prop
												{prop drop_plane}
											}
										}
										{exclude
											{state
												{state user_control}
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
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "enable_ce_radio_mechanic$"}
										{op "=="}
										{value 1}
									}
									{"switch"
										{"case"
											{condition
												{type cmp_i}
												{var "radio_active$"}
												{op "=="}
												{value 1}
											}
											{"sound"
												{name "world/alarm/sirene"}
											}
											{"delay"
												{time 45}
											}
											{"if"
												{condition
													{type entities}
													{selector
														{source advanced}
														{group
															{select
																{tag
																	{tag user_plane}
																}
															}
															{include
																{prop
																	{prop drop_plane}
																}
																{state
																	{state inhabited}
																}
															}
															{exclude
																{state
																	{state inactive}
																}
																{state
																	{state linked}
																}
																{tag
																	{tag ai}
																}
															}
														}
													}
												}
												{"sound"
													{name "world/alarm/sirene"}
												}
											}
										}
										{"default"
											{"if"
												{condition
													{type entities}
													{selector
														{source advanced}
														{group
															{select
																{tag
																	{tag user_plane}
																}
															}
															{include
																{prop
																	{prop drop_plane}
																}
																{state
																	{state inhabited}
																}
															}
															{exclude
																{state
																	{state inactive}
																}
																{state
																	{state linked}
																}
																{tag
																	{tag ai}
																}
															}
														}
													}
												}
												{"sound"
													{name "world/alarm/sirene"}
												}
												{"delay"
													{time 45}
												}
												{"sound"
													{name "world/alarm/sirene"}
												}
											}
										}
									}
								}
								{"default"
									{"sound"
										{name "world/alarm/sirene"}
									}
									{"delay"
										{time 45}
									}
									{"if"
										{condition
											{type entities}
											{selector
												{source advanced}
												{group
													{select
														{tag
															{tag user_plane}
														}
													}
													{include
														{prop
															{prop drop_plane}
														}
														{state
															{state inhabited}
														}
													}
													{exclude
														{state
															{state inactive}
														}
														{state
															{state linked}
														}
														{tag
															{tag ai}
														}
													}
												}
											}
										}
										{"sound"
											{name "world/alarm/sirene"}
										}
									}
								}
							}
						}
						{"default"
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "enable_ce_radio_mechanic$"}
										{op "=="}
										{value 1}
									}
									{"switch"
										{"case"
											{condition
												{type cmp_i}
												{var "radio_active$"}
												{op "=="}
												{value 1}
											}
											{"sound"
												{name "world/alarm/sirenlong01"}
											}
											{"delay"
												{time 45}
											}
											{"if"
												{condition
													{type entities}
													{selector
														{source advanced}
														{group
															{select
																{tag
																	{tag user_plane}
																}
															}
															{include
																{prop
																	{prop drop_plane}
																}
																{state
																	{state inhabited}
																}
															}
															{exclude
																{state
																	{state inactive}
																}
																{state
																	{state linked}
																}
																{tag
																	{tag ai}
																}
															}
														}
													}
												}
												{"sound"
													{name "world/alarm/sirenlong01"}
												}
											}
										}
										{"default"
											{"if"
												{condition
													{type entities}
													{selector
														{source advanced}
														{group
															{select
																{tag
																	{tag user_plane}
																}
															}
															{include
																{prop
																	{prop drop_plane}
																}
																{state
																	{state inhabited}
																}
															}
															{exclude
																{state
																	{state inactive}
																}
																{state
																	{state linked}
																}
																{tag
																	{tag ai}
																}
															}
														}
													}
												}
												{"sound"
													{name "world/alarm/sirenlong01"}
												}
												{"delay"
													{time 45}
												}
												{"sound"
													{name "world/alarm/sirenlong01"}
												}
											}
										}
									}
								}
								{"default"
									{"sound"
										{name "world/alarm/sirenlong01"}
									}
									{"delay"
										{time 45}
									}
									{"if"
										{condition
											{type entities}
											{selector
												{source advanced}
												{group
													{select
														{tag
															{tag user_plane}
														}
													}
													{include
														{prop
															{prop drop_plane}
														}
														{state
															{state inhabited}
														}
													}
													{exclude
														{state
															{state inactive}
														}
														{state
															{state linked}
														}
														{tag
															{tag ai}
														}
													}
												}
											}
										}
										{"sound"
											{name "world/alarm/sirenlong01"}
										}
									}
								}
							}
						}
					}
				}
			}

			{"ai_logic/air/tag_ai_drop_plane_faction"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag drop_plane}
										}
									}
									{include
										{prop
											{prop ai}
										}
										{prop
											{prop drop_plane}
										}
										{state
											{state operatable}
										}
									}
									{exclude
										{tag
											{tag rus}
										}
										{tag
											{tag ger}
										}
										{tag
											{tag usa}
										}
										{state
											{state inactive}
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
					{"delay"
						{time 0.2}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "bot_army$"}
								{op "=="}
								{value 1}
							}
							{"entity_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag drop_plane}
											}
										}
										{include
											{prop
												{prop ai}
											}
											{prop
												{prop drop_plane}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag rus}
											}
											{tag
												{tag ger}
											}
											{tag
												{tag usa}
											}
											{state
												{state inactive}
											}
											{state
												{state user_control}
											}
										}
									}
								}
								{tag_add rus}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "bot_army$"}
								{op "=="}
								{value 4}
							}
							{"entity_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag drop_plane}
											}
										}
										{include
											{prop
												{prop ai}
											}
											{prop
												{prop drop_plane}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag rus}
											}
											{tag
												{tag ger}
											}
											{tag
												{tag usa}
											}
											{state
												{state inactive}
											}
											{state
												{state user_control}
											}
										}
									}
								}
								{tag_add usa}
							}
						}
					}
					{"delay"
						{time 0.2}
					}
					{"trigger"
						{name "ai_logic/air/tag_ai_drop_plane_faction"}
					}
				}
			}
			{"ai_logic/air/move_planes_offmap"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag move_to_start_waypoint}
										}
									}
									{include
										{prop
											{prop airborne}
										}
										{state
											{state "operatable inhabited"}
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
											{state user_control}
										}
										{tag
											{tag plane_ready}
										}
										{tag
											{tag cmp_def}
										}
										{tag
											{tag user_plane}
										}
										{tag
											{tag plane_select_fly_by}
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
					{## "timer"
						{time 5}
						{title "moving planes"}
					}
					{"select"
						{source advanced}
						{group
							{select
								{tag
									{tag move_to_start_waypoint}
								}
							}
							{include
								{prop
									{prop airborne}
								}
								{state
									{state "operatable inhabited"}
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
									{state user_control}
								}
								{tag
									{tag plane_ready}
								}
								{tag
									{tag cmp_def}
								}
								{tag
									{tag user_plane}
								}
								{tag
									{tag plane_select_fly_by}
								}
							}
						}
						{amount 1
						}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source current}
						}
						{tag_add plane_selected_to_move_to_start}
					}
					{"delay"
						{time 0.1}
					}
					{"select"
						{amount 1}
						{tag plane_selected_to_move_to_start}
						{type vehicle}
						{state inhabited}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag plane_selected_to_move_to_start}
									}
								}
								{exclude
									{prop
										{prop ai_recon_plane}
									}
								}
							}
						}
						{tag_add _lua_always_ignore}
					}
					{## "action"
						{selector
							{tag plane_selected_to_move_to_start}
							{type vehicle}
							{state inhabited}
						}
						{drop orders}
						{action cancel}
					}
					{## "delay"
						{time 0.2}
					}
					{## "air_state"
						{selector
							{tag plane_selected_to_move_to_start}
							{type vehicle}
							{state inhabited}
						}
						{drop orders}
						{altitude 80}
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
												{tag plane_selected_to_move_to_start}
											}
										}
										{include
											{prop
												{prop drop_plane}
											}
											{state
												{state "operatable inhabited"}
											}
										}
										{exclude
											{state
												{state linked}
											}
											{state
												{state user_control}
											}
											{state
												{state inactive}
											}
										}
									}
								}
							}
							{"air_state"
								{selector
									{source current}
								}
								{drop orders}
								{altitude 80}
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
												{tag plane_selected_to_move_to_start}
											}
										}
										{include
											{prop
												{prop ai_recon_plane}
											}
											{state
												{state "operatable inhabited"}
											}
										}
										{exclude
											{state
												{state linked}
											}
											{state
												{state user_control}
											}
											{state
												{state inactive}
											}
										}
									}
								}
							}
							{"air_state"
								{selector
									{source current}
								}
								{drop orders}
								{altitude 75}
							}
						}
						{"default"
							{"air_state"
								{selector
									{source current}
								}
								{drop orders}
								{altitude 70}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"waypoint"
						{who
							{type actor}
							{actors
								{tag plane_selected_to_move_to_start}
								{type vehicle}
								{state inhabited}
							}
						}
						{action
							{type start}
							{waypoint "3000"}
							{approach "safe teleport & rotate"}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"effect"
						{selector
							{source current}
						}
						{effect move_plane_to_initial_waypoint}
					}
					{"delay"
						{time 0.1}
					}
					{"trigger"
						{name "ai_logic/air/move_planes_offmap"}
					}
				}
			}
			{"ai_logic/air/send_plane_to_fly_by"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag plane_ready}
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
											{state user_control}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{tag
											{tag combat_run}
										}
										{tag
											{tag plane_select_fly_by}
										}
										{tag
											{tag move_to_start_waypoint}
										}
									}
								}
							}
						}
						{"3.event"
							{id "air_raid_start"}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"effect"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag plane_ready}
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
										{state user_control}
									}
									{state
										{state inactive}
									}
									{state
										{state linked}
									}
									{tag
										{tag combat_run}
									}
									{tag
										{tag plane_select_fly_by}
									}
									{tag
										{tag move_to_start_waypoint}
									}
								}
							}
							{amount 1
							}
						}
						{effect select_plane_for_fly_by}
					}
					{"delay"
						{time 0.5}
					}
					{## "timer"
						{time 6}
						{title "sending planes on fly by"}
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
												{tag plane_select_fly_by}
											}
										}
										{include
											{state
												{state "operatable inhabited"}
											}
											{prop
												{prop drop_plane}
											}
										}
										{exclude
											{state
												{state user_control}
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
							{"select"
								{source advanced}
								{group
									{select
										{tag
											{tag plane_select_fly_by}
										}
									}
									{include
										{state
											{state "operatable inhabited"}
										}
										{prop
											{prop airborne}
										}
										{tag
											{tag drop_plane}
										}
									}
									{exclude
										{tag
											{tag dropping_troopers}
										}
										{state
											{state user_control}
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
							{"delay"
								{time 0.5}
							}
							{"switch"
								{## "case"
									{condition
										{type entities}
										{selector
											{tag drop_zone_selected}
											{zone "gamezone"}
										}
									}
									{"effect"
										{selector
											{source current}
										}
										{effect prep_drop_plane_to_move_fast_drop}
									}
								}
								{"default"
									{"effect"
										{selector
											{source advanced}
											{group
												{select
													{tag
														{tag plane_select_fly_by}
													}
												}
												{include
													{state
														{state "operatable inhabited"}
													}
													{prop
														{prop drop_plane}
													}
												}
												{exclude
													{state
														{state user_control}
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
										{effect prep_drop_plane_to_move}
									}
								}
							}
							{## "delay"
								{time 0.5}
							}
							{## "air_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag plane_select_fly_by}
											}
										}
										{include
											{state
												{state "operatable inhabited"}
											}
											{prop
												{prop drop_plane}
											}
										}
										{exclude
											{state
												{state user_control}
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
								{altitude 70}
							}
							{"delay"
								{time 0.5}
							}
							{"switch"
								{"case"
									{condition
										{type entities}
										{selector
											{tag drop_zone_selected}
											{zone "gamezone"}
										}
									}
									{"placement"
										{selector
											{source current}
										}
										{target
											{amount 1
											}
											{tag drop_plane_start_point}
										}
									}
									{"delay"
										{time 0.5}
									}
									{"air_attack"
										{selector
											{source advanced}
											{group
												{select
													{tag
														{tag plane_select_fly_by}
													}
												}
												{include
													{state
														{state "operatable inhabited"}
													}
													{prop
														{prop drop_plane}
													}
												}
												{exclude
													{state
														{state user_control}
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
										{enemies
											{amount 1
											}
											{tag drop_zone_selected}
											{zone "gamezone"}
										}
										{force_placement}
										{random_weapon 0}
										{attack_altitude 45}
									}
								}
								{"default"
									{## "air_attack"
										{selector
											{source advanced}
											{group
												{select
													{tag
														{tag plane_select_fly_by}
													}
												}
												{include
													{state
														{state "operatable inhabited"}
													}
													{prop
														{prop drop_plane}
													}
												}
												{exclude
													{state
														{state user_control}
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
										{enemies
											{amount 1
											}
											{tag drop_zone_selected}
											{zone "gamezone"}
										}
										{force_placement}
										{random_weapon 0}
										{attack_altitude 45}
									}
									{"air_attack"
										{selector
											{source advanced}
											{group
												{select
													{tag
														{tag plane_select_fly_by}
													}
												}
												{include
													{state
														{state "operatable inhabited"}
													}
													{prop
														{prop drop_plane}
													}
												}
												{exclude
													{state
														{state user_control}
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
										{enemies
											{source advanced}
											{group
												{select
													{tag
														{tag drop_zone}
													}
												}
												{include
													{zone
														{zone "gamezone"}
													}
												}
											}
											{amount 1
											}
										}
										{move_from_back}
										{force_placement}
										{random_weapon 0}
										{attack_altitude 75}
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
												{tag plane_select_fly_by}
											}
										}
										{include
											{state
												{state "operatable inhabited"}
											}
											{prop
												{prop ai_recon_plane}
											}
										}
										{exclude
											{state
												{state user_control}
											}
											{state
												{state inactive}
											}
											{state
												{state linked}
											}
											{tag
												{tag combat_run}
											}
											{prop
												{prop drop_plane}
											}
										}
									}
								}
							}
							{"select"
								{source advanced}
								{group
									{select
										{tag
											{tag plane_select_fly_by}
										}
									}
									{include
										{state
											{state "operatable inhabited"}
										}
										{prop
											{prop ai_recon_plane}
										}
									}
									{exclude
										{state
											{state user_control}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{tag
											{tag combat_run}
										}
										{prop
											{prop drop_plane}
										}
									}
								}
							}
							{"delay"
								{time 1}
							}
							{"air_state"
								{selector
									{source current}
								}
								{drop orders}
								{altitude 80}
							}
							{"delay"
								{time 0.5}
							}
							{"air_attack"
								{selector
									{source current}
								}
								{drop orders}
								{enemies
									{source advanced}
									{group
										{select
											{tag
												{tag flag_point}
											}
										}
										{exclude
											{zone
												{zone "fpc4"}
											}
										}
									}
									{amount 1
									}
								}
								{move_from_back}
								{force_placement}
								{random_weapon 0}
								{attack_altitude 70}
							}
						}
						{"default"
							{"select"
								{amount 1
								}
								{tag plane_select_fly_by}
								{type vehicle}
								{state inhabited}
							}
							{"delay"
								{time 1}
							}
							{"air_state"
								{selector
									{source current}
								}
								{drop orders}
								{altitude 70}
							}
							{"delay"
								{time 1}
							}
							{## "air_attack"
								{selector
									{source current}
								}
								{enemies
									{source advanced}
									{group
										{select
											{tag
												{tag flag_point}
											}
										}
										;{include
										;	{tag
										;		{tag fpc1}
										;	}
										;}
										{exclude
											{tag
												{tag fpc4}
											}
										}
									}
									{amount 1
									}
								}
								{move_from_back}
								{force_placement}
								{random_weapon 0}
								{attack_altitude 70}
							}
							{"air_attack"
										{selector
											{source advanced}
											{group
												{select
													{tag
														{tag plane_select_fly_by}
													}
												}
												{include
													{state
														{state "operatable inhabited"}
													}
													{prop
														{prop drop_plane}
													}
												}
												{exclude
													{state
														{state user_control}
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
										{enemies
											{source advanced}
											{group
												{select
													{tag
														{tag drop_zone}
													}
												}
												{include
													{zone
														{zone "gamezone"}
													}
												}
											}
											{amount 1
											}
										}
										{move_from_back}
										{force_placement}
										{random_weapon 0}
										{attack_altitude 75}
									}
							{"delay"
								{time 1}
							}
							{"action"
								{selector
									{source current}
								}
								{drop orders}
								{action advance}
								{target
									{source advanced}
									{group
										{select
											{tag
												{tag map_point}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
										}
									}
									{sort
										{type entity}
										{entity
											{amount 1
											}
											{tag plane_select_fly_by}
											{type vehicle}
											{state inhabited}
										}
										{mode farthest}
									}
									{amount 1
									}
								}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{tag plane_select_fly_by}
						}
						{tag_remove plane_select_fly_by}
					}
					{"delay"
						{time 2}
					}
					{"trigger"
						{name "ai_logic/air/send_plane_to_fly_by"}
					}
				}
			}
			{"ai_logic/air/send_plane_on_sorty"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag plane_ready_for_sorty}
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
										{tag
											{tag combat_run}
										}
										{prop
											{prop drop_plane}
										}
										{prop
											{prop ai_recon_plane}
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
										{tag plane_ready_for_sorty}
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
									{tag
										{tag plane_select_fly_by}
									}
									{state
										{state linked}
									}
									{state
										{state user_control}
									}
									{state
										{state inactive}
									}
									{tag
										{tag plane_select_for_sorty}
									}
								}
							}
							{amount 1
							}
						}
						{tag_add plane_select_for_sorty}
						{tag_remove plane_ready_for_sorty}
					}
					{"delay"
						{time 0.2}
					}
					{"select"
						{tag plane_select_for_sorty}
						{type vehicle}
						{state inhabited}
					}
					{"delay"
						{time 0.2}
					}
					{"air_state"
						{selector
							{source current}
						}
						{altitude 35}
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
												{tag plane_select_for_sorty}
											}
										}
										{include
											{tag
												{tag fighter}
											}
											{state
												{state "operatable inhabited"}
											}
										}
										{exclude
											{state
												{state inactive}
											}
											{state
												{state linked}
											}
											{tag
												{tag combat_run}
											}
										}
									}
								}
							}
							{"call"
								{function "attack_player_ai_fighter"}
								{context
									{specified}
									{selector
										{amount 1
										}
										{tag plane_select_for_sorty}
										{type vehicle}
										{state inhabited}
									}
								}
							}
						}
						{"default"
							{"call"
								{function "attack_player_ai_bomber"}
								{context
									{specified}
									{selector
										{amount 1
										}
										{tag plane_select_for_sorty}
										{type vehicle}
										{state inhabited}
									}
								}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{source current}
						}
						{tag_add combat_run}
						{tag_remove plane_select_for_sorty}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "ai_logic/air/send_plane_on_sorty"}
					}
				}
			}

			{"ai_logic/paratrooper_orders"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag paratrooper_need_orders}
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
											{state linked}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{tag
											{tag eject_null}
										}
										{tag
											{tag ai_signaller}
										}
									}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 10}
					}
					{"switch"
						{"case"
							{condition
								{type see_actors}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag selected_paratrooper}
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
												{state linked}
											}
											{state
												{state inactive}
											}
											{state
												{state user_control}
											}
											{tag
												{tag eject_null}
											}
											{tag
												{tag ai_signaller}
											}
										}
									}
									{amount 1
									}
								}
								{enemy
									{source advanced}
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
												{tag trooper_to_crew}
											}
											{state
												{state inhabited}
											}
											{state
												{state linked}
											}
										}
									}
								}
								{distance
									{mode near_than}
									{meters 160}
								}
								{tag
									{"tag pair"}
									{"for selector" p_crew}
									{"for enemy" p_cannon_enter}
								}
							}
							{"effect"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag paratrooper_need_orders}
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
												{state linked}
											}
											{state
												{state inactive}
											}
											{state
												{state user_control}
											}
											{tag
												{tag eject_null}
											}
											{tag
												{tag ai_signaller}
											}
										}
									}
									{sort
										{type entity}
										{entity
											{amount 1
											}
											{tag p_crew}
											{type human}
											{state operatable}
										}
									}
									{amount 2
									}
								}
								{effect select_paratroopers_to_give_orders}
							}
							{"delay"
								{time 0.5}
							}
							{"entity_state"
								{selector
									{tag selected_paratrooper}
									{type human}
									{state operatable}
								}
								{tag_add p_crew}
							}
							{"delay"
								{time 0.5}
							}
							{"actor_state"
								{selector
									{tag p_crew}
									{type human}
									{state operatable}
								}
								{drop orders}
								{movement
									{speed fast}
									{kind fast}
									{type normal}
								}
							}
							{"delay"
								{time 0.5}
							}
							{"board"
								{selector
									{tag p_crew}
									{type human}
									{state operatable}
								}
								{vehicle
									{source advanced}
									{group
										{select
											{tag
												{tag p_cannon_enter}
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
											{state
												{state linked}
											}
										}
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
												{tag p_cannon_enter}
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
											{state
												{state linked}
											}
										}
									}
								}
								{effect prep_veh_for_p_crew}
							}
						}
						{"default"
							{"effect"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag paratrooper_need_orders}
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
												{tag selected_paratrooper}
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
											{state
												{state user_control}
											}
											{tag
												{tag eject_null}
											}
										}
									}
									{amount 5
									}
									{sort
										{type entity}
										{entity
											{amount 1
											}
											{tag selected_paratrooper}
											{type human}
										}
									}
								}
								{effect select_paratroopers_to_give_orders}
							}
							{"delay"
								{time 1}
							}
							{"actor_state"
								{selector
									{tag selected_paratrooper}
									{type human}
									{state operatable}
								}
								{drop orders}
								{move_mode free}
								{weapon_prepare on}
								{ai_move
									{mode enable}
								}
								{movement
									{speed assault}
									{type normal}
								}
								{ai
									{advance_ratio "3"}
								}
								{human
									{veterancy 5}
								}
							}
							{"delay"
								{time 1}
							}							
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "ai_grid_system_active$"}
										{op ">"}
										{value 0}
									}
									{"switch"
										{"case"
											{condition
												{type rand}
												{value 0.33}
											}
											{"waypoint"
												{who
													{type actor}
													{actors
														{tag selected_paratrooper}
														{type human}
														{state "not dead"}
													}
												}
												{action
													{type start}
													{waypoint "5004"}
													{make_squad}
												}
											}
										}
										{"case"
											{condition
												{type rand}
												{value 0.33}
											}
											{"waypoint"
												{who
													{type actor}
													{actors
														{tag selected_paratrooper}
														{type human}
														{state "not dead"}
													}
												}
												{action
													{type start}
													{waypoint "5005"}
													{make_squad}
												}
											}
										}
										{"case"
											{condition
												{type rand}
												{value 0.33}
											}
											{"waypoint"
												{who
													{type actor}
													{actors
														{tag selected_paratrooper}
														{type human}
														{state "not dead"}
													}
												}
												{action
													{type start}
													{waypoint "5006"}
													{make_squad}
												}
											}
										}
										{"default"
											{"effect"
												{selector
													{tag selected_paratrooper}
												}
												{effect tag_squad_need_next_order}
											}
										}
									}
								}
								{"default"
									{"effect"
										{selector
											{tag selected_paratrooper}
										}
										{effect tag_squad_need_next_order}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.25}
					}
					{"inventory"
						{selector
							{tag selected_paratrooper}
							{type human}
							{state operatable}
						}
						{action add}
						{item "ai_nbk39" "grenade"}
						{stack 0}
					}
					{"delay"
						{time 0.25}
					}
					{"effect"
						{selector
							{tag selected_paratrooper}
						}
						{effect order_paratrooper}
					}
					{"delay"
						{time 0.5}
					}
					{"trigger"
						{name "ai_logic/paratrooper_orders"}
					}
				}
			}

;============== AI ARTILLERY ==============						
			(define "cannon_artillery_flag_attack_case" ; flag
				{"case"
					{condition
						{type entities}
						{selector
							{tag possible_artillery_target}
							{zone "fpc%flag"}
						}
					}
					{"select"
						{amount 1
						}
						{tag artillery_selected}
						{type vehicle}
						{state inhabited}
					}
					{"delay"
						{time 0.2}
					}
					{"action"
						{selector
							{source current}
						}
						{action cancel}
					}
					{"delay"
						{time 0.2}
					}
					{"actor_state"
						{selector
							{source current}
						}
						{drop orders}
						{cannon fire}
					}
					{"delay"
						{time 0.2}
					}
					{"entity_state"
						{selector
							{source current}
						}
						{tag_add attacking_flag_%flag}
					}
					{"delay"
						{time 1}
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
											{zone
												{zone "gamezone"}
											}
										}
										{exclude
											{prop
												{prop airborne}
											}
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
									{amount 1
									}
								}
								{near_to
									{source advanced}
									{group
										{select
											{zone
												{zone "fpc%flag"}
											}
										}
										{include
											{tag
												{tag possible_artillery_target}
											}
										}
									}
									{amount 1
									}
								}
								{distance 100}
							}
							{"loop" 18
								{"actor_fire"
									{selector
										{amount 1
										}
										{tag artillery_selected}
										{type vehicle}
										{state inhabited}
									}
									{attack enemies}
									{enemies
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
												{zone
													{zone "gamezone"}
												}
											}
											{exclude
												{prop
													{prop airborne}
												}
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
										{sort
											{type entity}
											{entity
												{amount 1
												}
												{tag flag_point}
												{zone "fpc%flag"}
											}
										}
										{amount 1
										}
									}
									{interval 0}
									{time 0}
									{burst_mode long}
								}
								{## "action"
									{selector
										{source current}
									}
									{action suppression_fire}
									{target
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
												{zone
													{zone "gamezone"}
												}
											}
											{exclude
												{prop
													{prop airborne}
												}
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
										{sort
											{type entity}
											{entity
												{amount 1
												}
												{tag flag_point}
												{zone "fpc%flag"}
											}
										}
										{amount 1
										}
									}
								}
							}
						}
						{"default"
							{"loop" 18
								{"actor_fire"
									{selector
										{tag artillery_selected}
										{type vehicle}
										{state inhabited}
									}
									{attack position}
									{waypoint "%flag"}
									{deviate}
									{burst_mode long}
								}
							}
						}
					}
					{"delay"
						{time 1}
					}
				}
			)
			(define "cannon_artillery_target_attack_case" ;
				{"if"
					{condition
						{type near}
						{units
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
									{state
										{state inactive}
									}
									{tag
										{tag _bot}
									}
									{tag
										{tag possible_artillery_target}
									}
									{state
										{state dead}
									}
									{state
										{state linked}
									}
									{prop
										{prop airborne}
									}
								}
							}
						}
						{near_to
							{source advanced}
							{group
								{select
									{zone
										{zone "fpc%flag"}
									}
								}
								{include
									{tag
										{tag fpc%flag}
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
					{"switch"
						{"case"
							{condition
								{type near}
								{units
									{source advanced}
									{group
										{select
											{tag
												{tag _user_ally}
											}
											{tag
												{tag _user}
											}
										}
										{include
											{prop
												{prop vehicle}
											}
											{state
												{state "operatable inhabited"}
											}
										}
										{exclude
											{state
												{state inactive}
											}
											{prop
												{prop airborne}
											}
											{tag
												{tag _bot}
											}
											{tag
												{tag possible_artillery_target}
											}
										}
									}
								}
								{near_to
									{source advanced}
									{group
										{select
											{zone
												{zone "fpc%flag"}
											}
										}
										{include
											{zone
												{zone "fpc%flag"}
											}
										}
									}
								}
								{distance 100}
							}
							{"entity_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag _user_ally}
											}
											{tag
												{tag _user}
											}
										}
										{include
											{prop
												{prop vehicle}
											}
											{state
												{state "operatable inhabited"}
											}
										}
										{exclude
											{state
												{state inactive}
											}
											{prop
												{prop airborne}
											}
											{tag
												{tag _bot}
											}
											{tag
												{tag possible_artillery_target}
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
														{tag fpc%flag}
													}
												}
												{include
													{zone
														{zone "fpc%flag"}
													}
												}
												{exclude
													{state
														{state inactive}
													}
												}
											}
											{amount 1
											}
										}
									}
									{amount 2
									}
								}
								{tag_add possible_artillery_target}
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
											{state
												{state inactive}
											}
											{tag
												{tag _bot}
											}
											{tag
												{tag possible_artillery_target}
											}
											{state
												{state dead}
											}
											{state
												{state linked}
											}
											{prop
												{prop airborne}
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
														{tag fpc%flag}
													}
												}
												{include
													{zone
														{zone "fpc%flag"}
													}
												}
												{exclude
													{state
														{state inactive}
													}
												}
											}
											{amount 1
											}
										}
									}
									{amount 2
									}
								}
								{tag_add possible_artillery_target}
							}
						}
					}
					{"delay"
						{time 0.2}
					}
				}
			)
			(define "spg_cannon_artillery_flag_attack_case" ; flag
				{"case"
					{condition
						{type entities}
						{selector
							{tag spg_artillery_flag_to_attack}
							{zone "fpc%flag"}
						}
					}
					{"select"
						{amount 1
						}
						{tag spg_artillery_selected}
						{type vehicle}
						{state inhabited}
					}
					{"delay"
						{time 0.2}
					}
					{"action"
						{selector
							{source current}
						}
						{drop orders}
						{action rotate}
						{target
							{amount 1
							}
							{tag spg_artillery_flag_to_attack}
						}
					}
					{"delay"
						{time 4}
					}
					{"entity_state"
						{selector
							{source current}
						}
						{tag_add attacking_flag_%flag}
					}
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
												{tag spg_artillery_selected}
											}
										}
										{include
											{tag
												{tag rocket_artillery}
											}
											{state
												{state "operatable inhabited"}
											}
											{tag
												{tag _bot}
											}
										}
										{exclude
											{state
												{state inactive}
											}
											{state
												{state linked}
											}
											{tag
												{tag _user}
											}
											{tag
												{tag _user_ally}
											}
											{state
												{state user_control}
											}
											{prop
												{prop panzerwerfer42}
											}
										}
									}
								}
							}
							{"loop" 18
								{"actor_fire"
									{selector
										{tag spg_artillery_selected}
										{type vehicle}
										{state inhabited}
									}
									{attack position}
									{waypoint "%flag"}
									{deviate}
									{burst_mode long}
									{only_weapon
										{use}
										{place rocket}
									}
								}
								{## "action"
									{selector
										{source current}
									}
									{drop orders}
									{action surpression_fire}
									{waypoint "%flag"}
								}
								{## "timer"
									{time 5}
									{title adfad}
								}
							}
						}
						{"default"
							{"loop" 18
								{"actor_fire"
									{selector
										{tag spg_artillery_selected}
										{type vehicle}
										{state inhabited}
									}
									{attack position}
									{waypoint "%flag"}
									{deviate}
									{burst_mode long}
								}
								{## "action"
									{selector
										{source current}
									}
									{drop orders}
									{action surpression_fire}
									{waypoint "%flag"}
								}
							}
						}
					}
				}
			)
			(define "cancel_arillery_attack_on_flag_conditions"  ; entities_group_1, entities_group_2, flag 
				{"%entities_group_1.entities"
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
									{zone "fpc%flag"}
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
								{prop
									{prop airborne}
								}
							}
						}
					}
					{count
						{op "=="}
						{value 0}
					}
				}
				{"%entities_group_2.entities"
					{selector
						{tag attacking_flag_%flag}
						{type vehicle}
						{state inhabited}
					}
				}
			)
			(define "cancel_attack_for_flag" ; flag
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
									{state
										{state operatable}
									}
									{zone
										{zone "fpc%flag"}
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
						}
						{count
							{op "=="}
							{value 0}
						}
					}
					{## "action"
						{selector
							{tag attacking_flag_%flag}
							{type vehicle}
							{state inhabited}
						}
						{drop orders}
					}
					{"delay"
						{time 0.1}
					}
					{"actor_state"
						{selector
							{tag attacking_flag_%flag}
							{type vehicle}
							{state inhabited}
						}
						{cannon move}
					}					
					{"delay"
						{time 0.1}
					}
					{"effect"
						{selector
							{tag attacking_flag_%flag}
							{type vehicle}
							{state inhabited}
						}
						{effect tag_squad_need_next_order}
					}
				}
				{"delay"
					{time 0.4}
				}
			)
	;------- Functions ---------------------

			{"ai/artillery/cannon_artillery_attack"
				{condition
					{expression "1 & !2 & !3"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag artillery}
										}
									}
									{include
										{prop
											{prop cannon}
										}
										{state
											{state "operatable inhabited"}
										}
										{tag
											{tag _bot}
										}
									}
									{exclude
										{tag
											{tag artillery_in_combat}
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
										{tag
											{tag _user}
										}
										{tag
											{tag _user_ally}
										}
										{tag
											{tag artillery_ordered}
										}
										{tag
											{tag _ai_defender}
										}
									}
								}
							}
						}
						{"2.event"
							{id "cannon_artillery_script_thread_active"}
						}
						{"3.event"
							{id "cannon_artillery_script_cooldown"}
						}
					}
				}
				{actions
					{"event"
						{event "cannon_artillery_script_thread_active"}
						{mode set}
						{delay 0}
					}
					{"delay"
						{time 1}
					}
					{"effect"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag artillery}
									}
								}
								{include
									{prop
										{prop cannon}
									}
									{state
										{state "operatable inhabited"}
									}
									{tag
										{tag _bot}
									}
								}
								{exclude
									{tag
										{tag artillery_in_combat}
									}
									{state
										{state inactive}
									}
									{state
										{state user_control}
									}
									{state
										{state linked}
									}
									{tag
										{tag _user}
									}
									{tag
										{tag _user_ally}
									}
									{tag
										{tag _ai_defender}
									}
									{tag
										{tag artillery_selected}
									}
									{tag
										{tag artillery_ordered}
									}
								}
							}
							{amount 1
							}
						}
						{effect select_artillery}
					}
					{"delay"
						{time 0.3}
					}
					{## "timer"
						{time 10}
						{title "artillery scripts active"}
					}
					{## "effect"
						{selector
							{tag artillery_selected}
						}
						{effect smoke_for_test}
					}
					{"delay"
						{time 0.3}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag possible_enemy_artillery}
									}
									{tag
										{tag possible_enemy_tank}
									}
									{tag
										{tag possible_enemy_cannon}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop vehicle}
									}
								}
								{exclude
									{state
										{state inactive}
									}
									{tag
										{tag _bot}
									}
									{tag
										{tag possible_artillery_target}
									}
								}
							}
							{sort
								{type entity}
								{entity
									{amount 1
									}
									{tag artillery_selected}
									{type vehicle}
									{state inhabited}
								}
							}
							{amount 1
							}
						}
						{tag_add possible_artillery_target}
						{tag_remove possible_flag_for_cannon_artillery_attack}
					}
					{"delay"
						{time 0.2}
					}
					("cannon_artillery_target_attack_case" flag(1))
					("cannon_artillery_target_attack_case" flag(2))
					("cannon_artillery_target_attack_case" flag(3))
					("cannon_artillery_target_attack_case" flag(4))
					("cannon_artillery_target_attack_case" flag(5))
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
												{tag artillery_selected}
											}
										}
										{include
											{prop
												{prop cannon}
											}
											{state
												{state "operatable inhabited"}
											}
											{tag
												{tag long_range}
											}
										}
										{exclude
											{tag
												{tag short_range}
											}
											{state
												{state user_control}
											}
											{state
												{state inactive}
											}
											{state
												{state linked}
											}
										}
									}
									{amount 1
									}
								}
								{near_to
									{amount 1
									}
									{tag possible_artillery_target}
								}
								{distance 400}
							}
							{## "timer"
								{time 3}
								{title "long range artillery in range of flag"}
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
												{tag artillery_selected}
											}
										}
										{include
											{prop
												{prop cannon}
											}
											{state
												{state "operatable inhabited"}
											}
										}
										{exclude
											{tag
												{tag long_range}
											}
											{tag
												{tag short_range}
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
								}
								{near_to
									{amount 1
									}
									{tag possible_artillery_target}
								}
								{distance 355}
							}
							{## "timer"
								{time 3}
								{title "artillery in range of flag"}
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
												{tag artillery_selected}
											}
										}
										{include
											{prop
												{prop cannon}
											}
											{state
												{state "operatable inhabited"}
											}
											{tag
												{tag short_range}
											}
										}
										{exclude
											{tag
												{tag long_range}
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
								}
								{near_to
									{amount 1
									}
									{tag possible_artillery_target}
								}
								{distance 270}
							}
							{## "timer"
								{time 3}
								{title "short range artillery in range of flag"}
							}
						}
						{"default"
							{"entity_state"
								{selector
									{tag artillery_selected}
								}
								{tag_remove artillery_selected}
							}
							{"delay"
								{time 0.5}
							}
							{"entity_state"
								{selector
									{tag possible_artillery_target}
								}
								{tag_remove possible_artillery_target}
							}
							{"delay"
								{time 4}
							}
							{"trigger"
								{name "ai/artillery/cannon_artillery_attack"}
							}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"select"
						{amount 1
						}
						{tag artillery_selected}
						{type vehicle}
						{state inhabited}
					}
					{"delay"
						{time 0.2}
					}
					{"action"
						{selector
							{source current}
						}
						{action cancel}
					}
					{"delay"
						{time 0.2}
					}
					{"actor_state"
						{selector
							{source current}
						}
						{drop orders}
						{cannon fire}
					}
					{"delay"
						{time 0.2}
					}
					{"entity_state"
						{selector
							{source current}
						}
						{tag_add attacking_priority_target}
					}
					{## "effect"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag possible_artillery_target}
									}
								}
								{include
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
						{effect smoke_for_test}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag possible_artillery_target}
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
									{state
										{state dead}
									}
									{tag
										{tag _bot}
									}
								}
							}
							{sort
								{type entity}
								{entity
									{amount 1
									}
									{tag artillery_selected}
									{type vehicle}
									{state inhabited}
								}
							}
							{amount 1
							}
						}
						{tag_add artillery_target}
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
												{tag artillery_target}
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
								{action attack}
								{target
									{amount 1
									}
									{tag artillery_target}
									{type tank}
									{state operatable}
								}
							}
						}
						{"default"
							{"loop" 3
								{"action"
									{selector
										{source current}
									}
									{action suppression_fire}
									{target
										{source advanced}
										{group
											{select
												{tag
													{tag possible_artillery_target}
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
												{state
													{state dead}
												}
												{tag
													{tag _bot}
												}
											}
										}
										{sort
											{type entity}
											{entity
												{amount 1
												}
												{tag artillery_selected}
												{type vehicle}
												{state inhabited}
											}
										}
										{amount 1
										}
									}
								}
							}
						}
					}
					{"effect"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag artillery_selected}
									}
								}
								{include
									{tag
										{tag _bot}
									}
									{state
										{state "operatable inhabited"}
									}
									{prop
										{prop cannon}
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
										{state user_control}
									}
									{tag
										{tag _user}
									}
									{tag
										{tag _user_ally}
									}
									{tag
										{tag cannon_dig_in_cooldown}
									}
								}
							}
						}
						{effect dig_in_artillery}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{tag artillery_selected}
							{type vehicle}
							{state inhabited}
						}
						{tag_add artillery_in_combat}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{tag artillery_selected}
						}
						{tag_remove artillery_selected}
					}
					{"delay"
						{time 1}
					}
					{"event"
						{event "cannon_artillery_script_thread_active"}
						{mode reset}
						{delay 0}
					}
					{"entity_state"
						{selector
							{tag possible_artillery_target}
						}
						{tag_remove possible_artillery_target}
					}
					{"entity_state"
						{selector
							{tag artillery_target}
						}
						{tag_remove artillery_target}
					}
					{"delay"
						{time 1}
					}
					{"if"
						{condition
							{type entities}
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag artillery}
										}
									}
									{include
										{prop
											{prop cannon}
										}
										{state
											{state "operatable inhabited"}
										}
										{tag
											{tag _bot}
										}
									}
									{exclude
										{tag
											{tag artillery_in_combat}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{state
											{state linked}
										}
										{tag
											{tag _user}
										}
										{tag
											{tag _user_ally}
										}
										{tag
											{tag artillery_selected}
										}
										{tag
											{tag artillery_ordered}
										}
									}
								}
							}
							{count
								{op "=="}
								{value 0}
							}
						}
						{## "timer"
							{time 10}
							{title "Cannon artillery script cooldown"}
						}
						{"event"
							{event "cannon_artillery_script_cooldown"}
							{mode set}
							{delay 0}
						}
						{"delay"
							{time 0.2}
						}
						{"event"
							{event "cannon_artillery_script_cooldown"}
							{mode reset}
							{delay 10}
						}
						{"entity_state"
							{selector
								{tag artillery_ordered}
							}
							{tag_remove artillery_ordered}
						}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "ai/artillery/cannon_artillery_attack"}
					}
				}
			}				
			{## "ai/artillery/spg_cannon_artillery_attack"
				{condition
					{expression "1 & !2 & !3"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag artillery}
										}
									}
									{include
										{prop
											{prop tank}
										}
										{state
											{state "operatable inhabited"}
										}
										{tag
											{tag _bot}
										}
									}
									{exclude
										{tag
											{tag spg_artillery_in_combat}
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
										{tag
											{tag _user}
										}
										{tag
											{tag _user_ally}
										}
										{tag
											{tag spg_artillery_ordered}
										}
										{prop
											{prop cannon}
										}
									}
								}
							}
						}
						{"2.event"
							{id "spg_cannon_artillery_script_thread_active"}
						}
						{"3.event"
							{id "spg_cannon_artillery_script_cooldown"}
						}
					}
				}
				{actions
					{"event"
						{event "spg_cannon_artillery_script_thread_active"}
						{mode set}
						{delay 0}
					}
					{"delay"
						{time 1}
					}
					{"effect"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag artillery}
									}
								}
								{include
									{prop
										{prop tank}
									}
									{state
										{state "operatable inhabited"}
									}
									{tag
										{tag _bot}
									}
								}
								{exclude
									{tag
										{tag spg_artillery_in_combat}
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
									{tag
										{tag _user}
									}
									{tag
										{tag _user_ally}
									}
									{tag
										{tag spg_artillery_ordered}
									}
									{prop
										{prop cannon}
									}
								}
							}
							{amount 1
							}
						}
						{effect select_spg_artillery}
					}
					{"delay"
						{time 0.3}
					}
					{"call"
						{function "check_if_player_in_flag_zones_for_spg_artillery"}
					}
					{"delay"
						{time 0.3}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag possible_flag_for_spg_cannon_artillery_attack}
									}
								}
							}
							{sort
								{type entity}
								{entity
									{amount 1
									}
									{tag spg_artillery_selected}
									{type vehicle}
									{state inhabited}
								}
							}
							{amount 1
							}
						}
						{tag_add spg_artillery_flag_to_attack}
						{tag_remove possible_flag_for_spg_cannon_artillery_attack}
					}
					{"delay"
						{time 0.3}
					}
					{"entity_state"
						{selector
							{tag possible_flag_for_spg_cannon_artillery_attack}
						}
						{tag_remove possible_flag_for_spg_cannon_artillery_attack}
					}
					{"delay"
						{time 0.3}
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
												{tag spg_artillery_selected}
											}
										}
										{include
											{prop
												{prop tank}
											}
											{state
												{state "operatable inhabited"}
											}
											{tag
												{tag long_range}
											}
										}
										{exclude
											{tag
												{tag short_range}
											}
											{state
												{state user_control}
											}
											{state
												{state inactive}
											}
											{state
												{state linked}
											}
											{prop
												{prop cannon}
											}
										}
									}
									{amount 1
									}
								}
								{near_to
									{amount 1
									}
									{tag spg_artillery_flag_to_attack}
								}
								{distance 400}
							}
							{## "timer"
								{time 3}
								{title "long range spg artillery in range of flag"}
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
												{tag spg_artillery_selected}
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
												{tag long_range}
											}
											{tag
												{tag short_range}
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
												{prop cannon}
											}
										}
									}
									{amount 1
									}
								}
								{near_to
									{amount 1
									}
									{tag spg_artillery_flag_to_attack}
								}
								{distance 345}
							}
							{## "timer"
								{time 3}
								{title "spg artillery in range of flag"}
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
												{tag spg_artillery_selected}
											}
										}
										{include
											{prop
												{prop tank}
											}
											{state
												{state "operatable inhabited"}
											}
											{tag
												{tag long_range_rocket}
											}
										}
										{exclude
											{tag
												{tag long_range}
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
												{prop cannon}
											}
										}
									}
									{amount 1
									}
								}
								{near_to
									{amount 1
									}
									{tag spg_artillery_flag_to_attack}
								}
								{distance 300}
							}
							{## "timer"
								{time 3}
								{title "short range spg artillery in range of flag"}
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
												{tag spg_artillery_selected}
											}
										}
										{include
											{prop
												{prop tank}
											}
											{state
												{state "operatable inhabited"}
											}
											{tag
												{tag short_range}
											}
										}
										{exclude
											{tag
												{tag long_range}
											}
											{tag
												{tag long_range_rocket}
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
												{prop cannon}
											}
										}
									}
									{amount 1
									}
								}
								{near_to
									{amount 1
									}
									{tag spg_artillery_flag_to_attack}
								}
								{distance 260}
							}
							{## "timer"
								{time 3}
								{title "short range spg artillery in range of flag"}
							}
						}
						{"default"
							{"entity_state"
								{selector
									{tag spg_artillery_selected}
								}
								{tag_remove spg_artillery_selected}
							}
							{"delay"
								{time 0.5}
							}
							{"entity_state"
								{selector
									{tag spg_artillery_flag_to_attack}
								}
								{tag_remove spg_artillery_flag_to_attack}
							}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"switch"
						("spg_cannon_artillery_flag_attack_case" flag(1))
						("spg_cannon_artillery_flag_attack_case" flag(2))
						("spg_cannon_artillery_flag_attack_case" flag(3))
						("spg_cannon_artillery_flag_attack_case" flag(4))
						("spg_cannon_artillery_flag_attack_case" flag(5))
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{tag spg_artillery_selected}
							{type vehicle}
							{state inhabited}
						}
						{tag_add spg_artillery_in_combat}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{tag spg_artillery_selected}
						}
						{tag_remove spg_artillery_selected}
					}
					{"delay"
						{time 1}
					}
					{"event"
						{event "spg_cannon_artillery_script_thread_active"}
						{mode reset}
						{delay 0}
					}
					{"entity_state"
						{selector
							{tag spg_artillery_flag_to_attack}
						}
						{tag_remove spg_artillery_flag_to_attack}
					}
					{"delay"
						{time 1}
					}
					{"if"
						{condition
							{type entities}
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag artillery}
										}
									}
									{include
										{prop
											{prop tank}
										}
										{state
											{state "operatable inhabited"}
										}
										{tag
											{tag _bot}
										}
									}
									{exclude
										{tag
											{tag spg_artillery_in_combat}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{state
											{state linked}
										}
										{tag
											{tag _user}
										}
										{tag
											{tag _user_ally}
										}
										{tag
											{tag spg_artillery_selected}
										}
										{tag
											{tag spg_artillery_ordered}
										}
										{prop
											{prop cannon}
										}
									}
								}
							}
							{count
								{op "=="}
								{value 0}
							}
						}
						{## "timer"
							{time 10}
							{title "Spg Cannon artillery script cooldown"}
						}
						{"event"
							{event "spg_cannon_artillery_script_cooldown"}
							{mode set}
							{delay 0}
						}
						{"delay"
							{time 0.2}
						}
						{"event"
							{event "spg_cannon_artillery_script_cooldown"}
							{mode reset}
							{delay 10}
						}
						{"entity_state"
							{selector
								{tag spg_artillery_ordered}
							}
							{tag_remove spg_artillery_ordered}
						}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "ai/artillery/spg_cannon_artillery_attack"}
					}
				}
			}
			{## "ai/artillery/set_spg_artillery_slow"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag artillery}
										}
									}
									{include
										{prop
											{prop vehicle}
										}
										{state
											{state "operatable inhabited"}
										}
										{tag
											{tag _bot}
										}
									}
									{exclude
										{prop
											{prop cannon}
										}
										{state
											{state linked}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{tag
											{tag artillery_moving_slow}
										}
									}
								}
								{group
									{select
										{tag
											{tag artillery}
										}
									}
									{include
										{prop
											{prop tank}
										}
										{state
											{state "operatable inhabited"}
										}
										{tag
											{tag _bot}
										}
									}
									{exclude
										{prop
											{prop cannon}
										}
										{state
											{state linked}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{tag
											{tag artillery_moving_slow}
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
					{"select"
						{source advanced}
						{group
							{select
								{tag
									{tag artillery}
								}
							}
							{include
								{prop
									{prop vehicle}
								}
								{state
									{state "operatable inhabited"}
								}
								{tag
									{tag _bot}
								}
							}
							{exclude
								{prop
									{prop cannon}
								}
								{state
									{state linked}
								}
								{state
									{state inactive}
								}
								{state
									{state user_control}
								}
								{tag
									{tag artillery_moving_slow}
								}
							}
						}
						{group
							{select
								{tag
									{tag _bot}
								}
							}
							{include
								{prop
									{prop wespe}
								}
								{state
									{state "operatable inhabited"}
								}
								
							}
							{exclude
								{prop
									{prop cannon}
								}
								{state
									{state linked}
								}
								{state
									{state inactive}
								}
								{state
									{state user_control}
								}
								{tag
									{tag artillery_moving_slow}
								}
							}
						}
					}
					{"delay"
						{time 0.3}
					}
					{"actor_state"
						{selector
							{source current}
						}
						{movement
							{speed slow}
						}
					}
					{"delay"
						{time 0.3}
					}
					{"entity_state"
						{selector
							{source current}
						}
						{tag_add artillery_moving_slow}
					}
					{"delay"
						{time 0.3}
					}
					{"trigger"
						{name "ai/artillery/set_spg_artillery_slow"}
					}
				}
			}

			{## "ai/artillery/cancel_artillery_attack_on_flags"
				{condition
					{expression "((1 & 2) | (3 & 4) | (5 & 6) | (7 & 8) | (9 & 10)) & !11"}
					{terms
						{"1.entities"
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
										{zone
											{zone "fpc1"}
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
							}
							{count
								{op "=="}
								{value 0}
							}
						}
						{"2.entities"
							{selector
								{tag attacking_flag_1}
								{type vehicle}
								{state inhabited}
							}
						}
						{"3.entities"
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
										{zone
											{zone "fpc2"}
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
							}
							{count
								{op "=="}
								{value 0}
							}
						}
						{"4.entities"
							{selector
								{tag attacking_flag_2}
								{type vehicle}
								{state inhabited}
							}
						}
						{"5.entities"
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
										{zone
											{zone "fpc3"}
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
							}
							{count
								{op "=="}
								{value 0}
							}
						}
						{"6.entities"
							{selector
								{tag attacking_flag_3}
								{type vehicle}
								{state inhabited}
							}
						}
						{"7.entities"
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
										{zone
											{zone "fpc4"}
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
							}
							{count
								{op "=="}
								{value 0}
							}
						}
						{"8.entities"
							{selector
								{tag attacking_flag_4}
								{type vehicle}
								{state inhabited}
							}
						}
						{"9.entities"
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
										{zone
											{zone "fpc5"}
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
							}
							{count
								{op "=="}
								{value 0}
							}
						}
						{"10.entities"
							{selector
								{tag attacking_flag_5}
								{type vehicle}
								{state inhabited}
							}
						}
						{"11.event"
							{id "cannon_artillery_script_thread_active"}
						}
					}
				}
				{actions
					{"event"
						{event "cannon_artillery_script_thread_active"}
						{mode set}
						{delay 0}
					}
					{## "timer"
						{time 10}
						{title "canel attacking flag"}
					}
					{"delay"
						{time 1}
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
										{state
											{state operatable}
										}
										{zone
											{zone "fpc1"}
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
							}
							{count
								{op "=="}
								{value 0}
							}
						}
						{"action"
							{selector
								{tag attacking_flag_1}
								{type vehicle}
								{state inhabited}
							}
							{action cancel}
							{drop orders}
						}
						{"delay"
							{time 0.1}
						}
						{"actor_state"
							{selector
								{tag attacking_flag_1}
								{type vehicle}
								{state inhabited}
							}
							{cannon move}
						}
						{"delay"
							{time 0.1}
						}
						{"effect"
							{selector
								{tag attacking_flag_1}
								{type vehicle}
								{state inhabited}
							}
							{effect tag_squad_need_next_order}
						}
					}
					{"delay"
						{time 0.4}
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
										{state
											{state operatable}
										}
										{zone
											{zone "fpc2"}
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
							}
							{count
								{op "=="}
								{value 0}
							}
						}
						{"action"
							{selector
								{tag attacking_flag_2}
								{type vehicle}
								{state inhabited}
							}
							{action cancel}
							{drop orders}
						}
						{"delay"
							{time 0.1}
						}
						{"actor_state"
							{selector
								{tag attacking_flag_2}
								{type vehicle}
								{state inhabited}
							}
							{cannon move}
						}
						{"delay"
							{time 0.1}
						}
						{"effect"
							{selector
								{tag attacking_flag_2}
								{type vehicle}
								{state inhabited}
							}
							{effect tag_squad_need_next_order}
						}
					}
					{"delay"
						{time 0.4}
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
										{state
											{state operatable}
										}
										{zone
											{zone "fpc3"}
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
							}
							{count
								{op "=="}
								{value 0}
							}
						}
						{"action"
							{selector
								{tag attacking_flag_3}
								{type vehicle}
								{state inhabited}
							}
							{action cancel}
							{drop orders}
						}
						{"delay"
							{time 0.1}
						}
						{"actor_state"
							{selector
								{tag attacking_flag_3}
								{type vehicle}
								{state inhabited}
							}
							{cannon move}
						}
						{"delay"
							{time 0.1}
						}
						{"effect"
							{selector
								{tag attacking_flag_3}
								{type vehicle}
								{state inhabited}
							}
							{effect tag_squad_need_next_order}
						}
					}
					{"delay"
						{time 0.4}
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
										{state
											{state operatable}
										}
										{zone
											{zone "fpc4"}
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
							}
							{count
								{op "=="}
								{value 0}
							}
						}
						{"action"
							{selector
								{tag attacking_flag_4}
								{type vehicle}
								{state inhabited}
							}
							{action cancel}
							{drop orders}
						}
						{"delay"
							{time 0.1}
						}
						{"actor_state"
							{selector
								{tag attacking_flag_4}
								{type vehicle}
								{state inhabited}
							}
							{cannon move}
						}
						{"delay"
							{time 0.1}
						}
						{"effect"
							{selector
								{tag attacking_flag_4}
								{type vehicle}
								{state inhabited}
							}
							{effect tag_squad_need_next_order}
						}
					}
					{"delay"
						{time 0.4}
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
										{state
											{state operatable}
										}
										{zone
											{zone "fpc5"}
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
							}
							{count
								{op "=="}
								{value 0}
							}
						}
						{"action"
							{selector
								{tag attacking_flag_5}
								{type vehicle}
								{state inhabited}
							}
							{action cancel}
							{drop orders}
						}
						{"delay"
							{time 0.1}
						}
						{"actor_state"
							{selector
								{tag attacking_flag_5}
								{type vehicle}
								{state inhabited}
							}
							{cannon move}
						}
						{"delay"
							{time 0.1}
						}
						{"effect"
							{selector
								{tag attacking_flag_5}
								{type vehicle}
								{state inhabited}
							}
							{effect tag_squad_need_next_order}
						}
					}
					{"delay"
						{time 0.4}
					}
					{"event"
						{event "cannon_artillery_script_thread_active"}
						{mode reset}
						{delay 0}
					}
					{"delay"
						{time 2}
					}
					{"trigger"
						{name "ai/artillery/cancel_artillery_attack_on_flags"}
					}
				}
			}
			{"ai/artillery/force_artillery_cancel"
				{condition
					{terms
						{"1.entities"
							{selector
								{tag artillery_in_combat}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 120}
					}
					{## "timer"
						{time 8}
						{title "Force Canceling Artillery Attack"}
					}
					{"select"
						{source advanced}
						{group
							{select
								{tag
									{tag artillery}
								}
							}
							{include
								{tag
									{tag _bot}
								}
								{state
									{state "operatable inhabited"}
								}
								{prop
									{prop cannon}
								}
								{tag
									{tag artillery_in_combat}
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
									{state user_control}
								}
								{tag
									{tag _user}
								}
								{tag
									{tag _user_ally}
								}
								{tag
									{tag artillery_selected}
								}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"action"
						{selector
							{source current}
						}
						{drop orders}
						{action cancel}
					}
					{"delay"
						{time 1}
					}
					{"actor_state"
						{selector
							{source current}
						}
						{cannon move}
					}
					{"delay"
						{time 0.1}
					}
					{"effect"
						{selector
							{source current}
						}
						{effect tag_squad_need_next_order}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "ai/artillery/force_artillery_cancel"}
					}
				}
			}
			{## "ai/artillery/activate_artillery_in_rear_line"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{zone
											{zone "grid_a1"}
										}
										{zone
											{zone "grid_a2"}
										}
										{zone
											{zone "grid_a3"}
										}
										{zone
											{zone "grid_c1"}
										}
										{zone
											{zone "grid_c2"}
										}
										{zone
											{zone "grid_c3"}
										}
									}
									{include
										{state
											{state "operatable inhabited"}
										}
										{tag
											{tag artillery}
										}
										{tag
											{tag _bot}
										}
									}
									{exclude
										{state
											{state user_control}
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
					}
				}
				{actions
					{"delay"
						{time 180}
					}
					{## "timer"
						{time 8}
						{title "Artillery in rear grids getting new orders"}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{zone
										{zone "grid_a1"}
									}
									{zone
										{zone "grid_a2"}
									}
									{zone
										{zone "grid_a3"}
									}
									{zone
										{zone "grid_c1"}
									}
									{zone
										{zone "grid_c2"}
									}
									{zone
										{zone "grid_c3"}
									}
								}
								{include
									{state
										{state "operatable inhabited"}
									}
									{tag
										{tag artillery}
									}
									{tag
										{tag _bot}
									}
								}
								{exclude
									{state
										{state user_control}
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
						{tag_add artillery_in_combat}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "ai/artillery/force_artillery_cancel"}
						{on}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "ai/artillery/activate_artillery_in_rear_line"}
					}
				}
			}

;============== AI MISC	==============	
			{"ai/spot_priority_targets"
				{condition
					{expression "(1 | 2 | 3) & !4"}
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
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
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{tag
											{tag _user_ally}
										}
									}
								}
								{amount 1
								}
							}
							{enemy
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
										{zone
											{zone "gamezone"}
										}
										{tag
											{tag artillery}
										}
									}
									{exclude
										{prop
											{prop airborne}
										}
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
							{distance
								{mode near_than}
								{meters 200}
							}
							{tag
								{"tag pair"}
								{"for enemy" possible_enemy_artillery}
							}
						}
						{"2.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
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
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{tag
											{tag _user_ally}
										}
									}
								}
								{amount 1
								}
							}
							{enemy
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
										{zone
											{zone "gamezone"}
										}
										{prop
											{prop tank}
										}
									}
									{exclude
										{prop
											{prop airborne}
										}
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
							{distance
								{mode near_than}
								{meters 200}
							}
							{tag
								{"tag pair"}
								{"for enemy" possible_enemy_tank}
							}
						}
						{"3.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
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
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{tag
											{tag _user_ally}
										}
									}
								}
								{amount 1
								}
							}
							{enemy
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
										{zone
											{zone "gamezone"}
										}
										{prop
											{prop cannon}
										}
									}
									{exclude
										{prop
											{prop airborne}
										}
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag artillery}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 200}
							}
							{tag
								{"tag pair"}
								{"for enemy" possible_enemy_cannon}
							}
						}
						{"4.event"
							{id "cannon_artillery_script_thread_active"}
						}
					}
				}
				{actions
					{## "timer"
						{time 6}
						{title "tagging enemy priority targets"}
					}
					{"if"
						{condition
							{type see_actors}
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
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
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{tag
											{tag _user_ally}
										}
									}
								}
								{amount 1
								}
							}
							{enemy
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
										{zone
											{zone "gamezone"}
										}
										{tag
											{tag artillery}
										}
									}
									{exclude
										{prop
											{prop airborne}
										}
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag possible_enemy_artillery}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 200}
							}
							{tag
								{"tag pair"}
								{"for enemy" possible_enemy_artillery}
							}
						}
					}
					{"if"
						{condition
							{type see_actors}
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
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
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{tag
											{tag _user_ally}
										}
									}
								}
								{amount 1
								}
							}
							{enemy
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
										{zone
											{zone "gamezone"}
										}
										{prop
											{prop tank}
										}
									}
									{exclude
										{prop
											{prop airborne}
										}
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag possible_enemy_tank}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 200}
							}
							{tag
								{"tag pair"}
								{"for enemy" possible_enemy_tank}
							}
						}
					}
					{"if"
						{condition
							{type see_actors}
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
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
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{tag
											{tag _user_ally}
										}
									}
								}
								{amount 1
								}
							}
							{enemy
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
										{zone
											{zone "gamezone"}
										}
										{prop
											{prop cannon}
										}
									}
									{exclude
										{prop
											{prop airborne}
										}
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag artillery}
										}
										{tag
											{tag possible_enemy_cannon}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 200}
							}
							{tag
								{"tag pair"}
								{"for enemy" possible_enemy_cannon}
							}
						}
					}
					{"delay"
						{time 60}
					}
					{"entity_state"
						{selector
							{tag possible_enemy_artillery}
							{type vehicle}
							{state "not operatable"}
						}
						{tag_remove possible_enemy_artillery}
					}
					{"entity_state"
						{selector
							{tag possible_enemy_tank}
							{type tank}
							{state "not operatable"}
						}
						{tag_remove possible_enemy_tank}
					}
					{"entity_state"
						{selector
							{tag possible_enemy_cannon}
							{type vehicle}
							{state "not operatable"}
						}
						{tag_remove possible_enemy_cannon}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "ai/spot_priority_targets"}
					}
				}
			}
			{"ai_logic/ai_patrol_logic"
				{condition
					{expression "(1 | 2 | 3 | 4 | 5) & 6"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{zone
											{zone "fpc1"}
										}
									}
									{include
										{prop
											{prop human}
										}
										{state
											{state operatable}
										}
										{tag
											{tag cmp_def}
										}
									}
									{exclude
										{state
											{state user_control}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{tag
											{tag patrolling}
										}
										{tag
											{tag go_patrol}
										}
										{tag
											{tag _bot}
										}
									}
								}
							}
							{count
								{op ">"}
								{value "max_ai_defender_at_flag$"}
							}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{zone
											{zone "fpc2"}
										}
									}
									{include
										{prop
											{prop human}
										}
										{state
											{state operatable}
										}
										{tag
											{tag cmp_def}
										}
									}
									{exclude
										{state
											{state user_control}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{tag
											{tag patrolling}
										}
										{tag
											{tag go_patrol}
										}
										{tag
											{tag _bot}
										}
									}
								}
							}
							{count
								{op ">"}
								{value "max_ai_defender_at_flag$"}
							}
						}
						{"3.entities"
							{selector
								{source advanced}
								{group
									{select
										{zone
											{zone "fpc3"}
										}
									}
									{include
										{prop
											{prop human}
										}
										{state
											{state operatable}
										}
										{tag
											{tag cmp_def}
										}
									}
									{exclude
										{state
											{state user_control}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{tag
											{tag patrolling}
										}
										{tag
											{tag go_patrol}
										}
										{tag
											{tag _bot}
										}
									}
								}
							}
							{count
								{op ">"}
								{value "max_ai_defender_at_flag$"}
							}
						}
						{"4.entities"
							{selector
								{source advanced}
								{group
									{select
										{zone
											{zone "fpc4"}
										}
									}
									{include
										{prop
											{prop human}
										}
										{state
											{state operatable}
										}
										{tag
											{tag cmp_def}
										}
									}
									{exclude
										{state
											{state user_control}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{tag
											{tag patrolling}
										}
										{tag
											{tag go_patrol}
										}
										{tag
											{tag _bot}
										}
									}
								}
							}
							{count
								{op ">"}
								{value "max_ai_defender_at_flag$"}
							}
						}
						{"5.entities"
							{selector
								{source advanced}
								{group
									{select
										{zone
											{zone "fpc5"}
										}
									}
									{include
										{prop
											{prop human}
										}
										{state
											{state operatable}
										}
										{tag
											{tag cmp_def}
										}
									}
									{exclude
										{state
											{state user_control}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{tag
											{tag patrolling}
										}
										{tag
											{tag go_patrol}
										}
										{tag
											{tag _bot}
										}
									}
								}
							}
							{count
								{op ">"}
								{value "max_ai_defender_at_flag$"}
							}
						}
						{"6.event"
							{id "ai_defender_inf_balanced"}
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
											{zone
												{zone "fpc1"}
											}
										}
										{include
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
											{tag
												{tag cmp_def}
											}
										}
										{exclude
											{state
												{state user_control}
											}
											{state
												{state inactive}
											}
											{state
												{state linked}
											}
											{tag
												{tag patrolling}
											}
											{tag
												{tag go_patrol}
											}
											{tag
												{tag _bot}
											}
										}
									}
								}
								{count
									{op ">"}
									{value "max_ai_defender_at_flag$"}
								}
							}
							{"effect"
								{selector
									{source advanced}
									{group
										{select
											{zone
												{zone "fpc1"}
											}
										}
										{include
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
											{tag
												{tag cmp_def}
											}
										}
										{exclude
											{state
												{state user_control}
											}
											{state
												{state inactive}
											}
											{state
												{state linked}
											}
											{tag
												{tag patrolling}
											}
											{tag
												{tag go_patrol}
											}
											{tag
												{tag _bot}
											}
										}
									}
									{amount 4
									}
								}
								{effect send_ai_to_partol}
							}
						}
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{group
										{select
											{zone
												{zone "fpc2"}
											}
										}
										{include
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
											{tag
												{tag cmp_def}
											}
										}
										{exclude
											{state
												{state user_control}
											}
											{state
												{state inactive}
											}
											{state
												{state linked}
											}
											{tag
												{tag patrolling}
											}
											{tag
												{tag go_patrol}
											}
											{tag
												{tag _bot}
											}
										}
									}
								}
								{count
									{op ">"}
									{value "max_ai_defender_at_flag$"}
								}
							}
							{"effect"
								{selector
									{source advanced}
									{group
										{select
											{zone
												{zone "fpc2"}
											}
										}
										{include
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
											{tag
												{tag cmp_def}
											}
										}
										{exclude
											{state
												{state user_control}
											}
											{state
												{state inactive}
											}
											{state
												{state linked}
											}
											{tag
												{tag patrolling}
											}
											{tag
												{tag go_patrol}
											}
											{tag
												{tag _bot}
											}
										}
									}
									{amount 4
									}
								}
								{effect send_ai_to_partol}
							}
						}
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{group
										{select
											{zone
												{zone "fpc3"}
											}
										}
										{include
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
											{tag
												{tag cmp_def}
											}
										}
										{exclude
											{state
												{state user_control}
											}
											{state
												{state inactive}
											}
											{state
												{state linked}
											}
											{tag
												{tag patrolling}
											}
											{tag
												{tag go_patrol}
											}
											{tag
												{tag _bot}
											}
										}
									}
								}
								{count
									{op ">"}
									{value "max_ai_defender_at_flag$"}
								}
							}
							{"effect"
								{selector
									{source advanced}
									{group
										{select
											{zone
												{zone "fpc3"}
											}
										}
										{include
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
											{tag
												{tag cmp_def}
											}
										}
										{exclude
											{state
												{state user_control}
											}
											{state
												{state inactive}
											}
											{state
												{state linked}
											}
											{tag
												{tag patrolling}
											}
											{tag
												{tag go_patrol}
											}
											{tag
												{tag _bot}
											}
										}
									}
									{amount 4
									}
								}
								{effect send_ai_to_partol}
							}
						}
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{group
										{select
											{zone
												{zone "fpc4"}
											}
										}
										{include
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
											{tag
												{tag cmp_def}
											}
										}
										{exclude
											{state
												{state user_control}
											}
											{state
												{state inactive}
											}
											{state
												{state linked}
											}
											{tag
												{tag patrolling}
											}
											{tag
												{tag go_patrol}
											}
											{tag
												{tag _bot}
											}
										}
									}
								}
								{count
									{op ">"}
									{value "max_ai_defender_at_flag$"}
								}
							}
							{"effect"
								{selector
									{source advanced}
									{group
										{select
											{zone
												{zone "fpc4"}
											}
										}
										{include
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
											{tag
												{tag cmp_def}
											}
										}
										{exclude
											{state
												{state user_control}
											}
											{state
												{state inactive}
											}
											{state
												{state linked}
											}
											{tag
												{tag patrolling}
											}
											{tag
												{tag go_patrol}
											}
											{tag
												{tag _bot}
											}
										}
									}
									{amount 4
									}
								}
								{effect send_ai_to_partol}
							}
						}
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{group
										{select
											{zone
												{zone "fpc5"}
											}
										}
										{include
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
											{tag
												{tag cmp_def}
											}
										}
										{exclude
											{state
												{state user_control}
											}
											{state
												{state inactive}
											}
											{state
												{state linked}
											}
											{tag
												{tag patrolling}
											}
											{tag
												{tag go_patrol}
											}
											{tag
												{tag _bot}
											}
										}
									}
								}
								{count
									{op ">"}
									{value "max_ai_defender_at_flag$"}
								}
							}
							{"effect"
								{selector
									{source advanced}
									{group
										{select
											{zone
												{zone "fpc5"}
											}
										}
										{include
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
											{tag
												{tag cmp_def}
											}
										}
										{exclude
											{state
												{state user_control}
											}
											{state
												{state inactive}
											}
											{state
												{state linked}
											}
											{tag
												{tag patrolling}
											}
											{tag
												{tag go_patrol}
											}
											{tag
												{tag _bot}
											}
										}
									}
									{amount 4
									}
								}
								{effect send_ai_to_partol}
							}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"call"
						{function "recon_random_flag"}
						{context
							{specified}
							{selector
								{tag go_patrol}
								{type human}
								{state operatable}
							}
						}
					}
					{"delay"
						{time 3}
					}
					{"switch"
						{"case"
							{condition
								{type rand}
								{value 0.33}
							}
							{"actor_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag go_patrol}
											}
										}
										{include
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
											{tag
												{tag cmp_def}
											}
										}
										{exclude
											{state
												{state user_control}
											}
											{state
												{state inactive}
											}
											{state
												{state linked}
											}
											{tag
												{tag patrolling}
											}
										}
									}
								}
								{fire_mode open}
								;{move_mode free}
								{weapon_prepare on}
								{ai_move
									{mode enable}
								}
								{movement
									{speed spot}
									;{kind fast}
									;{type normal}
								}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.33}
							}
							{"actor_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag go_patrol}
											}
										}
										{include
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
											{tag
												{tag cmp_def}
											}
										}
										{exclude
											{state
												{state user_control}
											}
											{state
												{state inactive}
											}
											{state
												{state linked}
											}
											{tag
												{tag patrolling}
											}
										}
									}
								}
								{fire_mode open}
								;{move_mode free}
								{weapon_prepare on}
								{ai_move
									{mode enable}
								}
								{movement
									{speed walk}
									;{kind fast}
									;{type normal}
								}
							}
						}
						{"default"
							{"actor_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag go_patrol}
											}
										}
										{include
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
											{tag
												{tag cmp_def}
											}
										}
										{exclude
											{state
												{state user_control}
											}
											{state
												{state inactive}
											}
											{state
												{state linked}
											}
											{tag
												{tag patrolling}
											}
										}
									}
								}
								{fire_mode open}
								;{move_mode free}
								{weapon_prepare on}
								{ai_move
									{mode enable}
								}
								{movement
									{speed assault}
									;{kind fast}
									;{type normal}
								}
							}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{tag go_patrol}
							{type human}
							{state operatable}
						}
						{tag_add patrolling}
						{tag_remove go_patrol}
					}
					{"delay"
						{time 2}
					}
					{"trigger"
						{name "ai_logic/ai_patrol_logic"}
					}
				}
			}
			{"ai/taunts/killed_officer"
				{condition
					{terms
						{"1.entities"
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
											{state "dead user_control"}
										}
										{zone
											{zone "gamezone"}
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
						}
						{"2.rand"
							{value 0.4}
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
								{type rand}
								{value 0.4}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag _bot}
									{zone "gamezone"}
									{type human}
								}
								{text "mission/multi/officer_killed_1"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.4}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag _bot}
									{zone "gamezone"}
									{type human}
								}
								{text "mission/multi/officer_killed_2"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.4}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag _bot}
									{zone "gamezone"}
									{type human}
								}
								{text "mission/multi/officer_killed_3"}
							}
						}
						{"default"
							{"talk"
								{selector
									{amount 1
									}
									{tag _bot}
									{zone "gamezone"}
									{type human}
								}
								{text "mission/multi/officer_killed_4"}
							}
						}
					}
				}
			}
			{"ai/taunts/destroyed_heavy_tank"
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
										{state
											{state user_control}
										}
										{prop
											{prop heavy}
										}
										{prop
											{prop tank}
										}
										{broken_components
											{masks
												"body"
											}
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
											{state operatable}
										}
									}
								}
							}
						}
						{"2.rand"
							{value 0.4}
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
								{type rand}
								{value 0.35}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag _bot}
									{zone "gamezone"}
									{type human}
								}
								{text "mission/multi/heavy_tank_destroyed_1"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.40}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag _bot}
									{zone "gamezone"}
									{type human}
								}
								{text "mission/multi/heavy_tank_destroyed_2"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.4}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag _bot}
									{zone "gamezone"}
									{type human}
								}
								{text "mission/multi/heavy_tank_destroyed_3"}
							}
						}
						{"default"
							{"talk"
								{selector
									{amount 1
									}
									{tag _bot}
									{zone "gamezone"}
									{type human}
								}
								{text "mission/multi/generic_taunt_3"}
							}
						}
					}
				}
			}
			{"ai/taunts/destroyed_artillery"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag artillery}
										}
										{tag
											{tag rocket_artillery}
										}
									}
									{include
										{state
											{state user_control}
										}
										{prop
											{prop vehicle}
										}
										{broken_components
											{masks
												"body"
											}
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
											{state operatable}
										}
									}
								}
							}
						}
						{"2.rand"
							{value 0.4}
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
								{type rand}
								{value 0.35}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag _bot}
									{zone "gamezone"}
									{type human}
								}
								{text "mission/multi/artillery_destroyed_1"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.40}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag _bot}
									{zone "gamezone"}
									{type human}
								}
								{text "mission/multi/artillery_destroyed_2"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.45}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag _bot}
									{zone "gamezone"}
									{type human}
								}
								{text "mission/multi/artillery_destroyed_3"}
							}
						}
						{"default"
							{"talk"
								{selector
									{amount 1
									}
									{tag _bot}
									{zone "gamezone"}
									{type human}
								}
								{text "mission/multi/generic_taunt_3"}
							}
						}
					}
				}
			}
			{"ai/taunts/destroyed_radio_car"
				{condition
					{terms
						{"1.entities"
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
											{state user_control}
										}
										{prop
											{prop vehicle}
										}
										{broken_components
											{masks
												"body"
											}
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
											{state operatable}
										}
									}
								}
							}
						}
						{"2.rand"
							{value 0.4}
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
								{type rand}
								{value 0.25}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag _bot}
									{zone "gamezone"}
									{type human}
								}
								{text "mission/multi/radio_car_destroyed_1"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.25}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag _bot}
									{zone "gamezone"}
									{type human}
								}
								{text "mission/multi/generic_taunt_1"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.25}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag _bot}
									{zone "gamezone"}
									{type human}
								}
								{text "mission/multi/generic_taunt_2"}
							}
						}
						{"default"
							{"talk"
								{selector
									{amount 1
									}
									{tag _bot}
									{zone "gamezone"}
									{type human}
								}
								{text "mission/multi/generic_taunt_3"}
							}
						}
					}
				}
			}