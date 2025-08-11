;============== AI LUA BOT FILE Scripts ==============		
			(include "ai_lua_triggers.inc")

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
                    {## "timer"
						{time 65}
						{title "AI should buy miners"}
					}
                    {## "delay"
						{time 10}
					}
                    {## "if"
						{condition
							{type entities}
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _prioritize_de_miner}
										}
									}
									
								}
							}
						}
						{## "timer"
						{time 65}
						{title "AI is buying deminers"}
                        }
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
			{"ai/purchase_priority/set_aa_priority"
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
											{prop player_plane}
										}
										{state
											{state "operatable inhabited"}
										}
									}
									{exclude
										{state
											{state linked}
										}
										{tag
											{tag _bot}
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
					{"entity_state"
						{selector
							{tag scene_variable}
						}
						{tag_add _prioritize_aa}
					}
					{"delay"
						{time 180}
					}
					{"entity_state"
						{selector
							{tag scene_variable}
						}
						{tag_remove _prioritize_aa}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "ai/purchase_priority/reduce_deminer_priortity"}
					}
				}
			}

;============== AI ARTILLERY ==============		
			{"ai/artillery/spg_arty"
				{condition
					{terms
						{"1.event"
							{id "enable_ai_attack_logic"}
						}
						{"2.entities"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
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
											{state "operatable inhabited"}
										}
										{prop
											{prop vehicle}
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
										{tag
											{tag _user_ally}
										}
										{tag
											{tag artillery_in_combat}
										}
										{prop
											{prop cannon}
										}
										{tag
											{tag _user}
										}
										{tag
											{tag ai_arty_in_script}
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
							{ignore_captured_by_user 0}
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
										{state "operatable inhabited"}
									}
									{prop
										{prop vehicle}
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
									{tag
										{tag _user_ally}
									}
									{tag
										{tag artillery_in_combat}
									}
									{prop
										{prop cannon}
									}
									{tag
										{tag _user}
									}
									{tag
										{tag ai_arty_in_script}
									}
								}
							}
							{sort
								{type shuffle}
							}
							{amount 1
							}
						}
						{tag_add spg_arty_selected}
					}
					{"delay"
						{time 0.2}
					}
					{"select"
						{amount 1
						}
						{tag spg_arty_selected}
						{zone "gamezone"}
						{type vehicle}
						{state inhabited}
					}
					{"delay"
						{time 0.2}
					}
					{"entity_state"
						{selector
							{source current}
							{ignore_captured_by_user 0}
						}
						{tag_add ai_arty_in_script}
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
							{sort
								{type entity}
								{entity
									{amount 1
									}
									{tag spg_arty_selected}
									{zone "gamezone"}
									{type vehicle}
									{state operatable}
								}
							}
							{amount 1
							}
						}
						{tag_add spg_arty_target}
					}
					{"delay"
						{time 0.2}
					}
					{"switch"
						{"case"
							{condition
								{type near}
								{units
									{ignore_captured_by_user 0}
									{amount 1
									}
									{tag spg_arty_selected}
									{zone "gamezone"}
									{type vehicle}
									{state inhabited}
								}
								{near_to
									{ignore_captured_by_user 0}
									{tag spg_arty_target}
									{state operatable}
								}
								{distance 210}
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
									{tag spg_arty_target}
									{state operatable}
								}
							}
							{"delay"
								{time 6}
							}
						}
						{"default"
							{"action"
								{selector
									{source current}
								}
								{drop orders}
								{action move}
								{target
									{amount 1
									}
									{tag spg_arty_target}
									{state operatable}
								}
							}
							{"delay"
								{time 12}
							}
						}
					}
					{"action"
						{selector
							{source current}
						}
						{drop orders}
						{action cancel}
						{target
							{amount 1
							}
							{tag spg_arty_target}
							{state operatable}
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
						{action suppression_fire}
						{target
							{amount 1
							}
							{tag spg_arty_target}
							{state operatable}
						}
					}
					{"delay"
						{time 1}
					}
					{"action"
						{selector
							{source current}
						}
						{action attack}
						{target
							{amount 1
							}
							{tag spg_arty_target}
							{state operatable}
						}
					}
					{"delay"
						{time 5}
					}
					{"effect"
						{selector
							{tag spg_arty_selected}
						}
						{effect set_artillery_given_orders}
					}
					{"delay"
						{time 0.2}
					}
					{"entity_state"
						{selector
							{tag spg_arty_target}
						}
						{tag_remove spg_arty_target}
					}
					{"delay"
						{time 5}
					}
					{"trigger"
						{name "ai/artillery/spg_arty"}
					}
				}
			}
			{"ai/artillery/arty"
				{condition
					{terms
						{"1.event"
							{id "enable_ai_attack_logic"}
						}
						{"2.entities"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
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
											{state "operatable inhabited"}
										}
										{prop
											{prop cannon}
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
										{tag
											{tag _user_ally}
										}
										{tag
											{tag artillery_in_combat}
										}
										{tag
											{tag _user}
										}
										{tag
											{tag ai_arty_in_script}
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
							{ignore_captured_by_user 0}
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
										{state "operatable inhabited"}
									}
									{prop
										{prop cannon}
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
									{tag
										{tag _user_ally}
									}
									{tag
										{tag artillery_in_combat}
									}
									{tag
										{tag _user}
									}
									{tag
										{tag ai_arty_in_script}
									}
								}
							}
							{sort
								{type shuffle}
							}
							{amount 1
							}
						}
						{tag_add arty_selected}
					}
					{"delay"
						{time 0.2}
					}
					{"select"
						{amount 1
						}
						{tag arty_selected}
						{zone "gamezone"}
						{type vehicle}
						{state operatable}
					}
					{"delay"
						{time 0.2}
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
					{"entity_state"
						{selector
							{source current}
							{ignore_captured_by_user 0}
						}
						{tag_add ai_arty_in_script}
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
							{sort
								{type entity}
								{entity
									{amount 1
									}
									{tag arty_selected}
									{zone "gamezone"}
									{type vehicle}
									{state inhabited}
								}
							}
							{amount 1
							}
						}
						{tag_add arty_target}
					}
					{"delay"
						{time 0.2}
					}
					{"action"
						{selector
							{source current}
						}
						{drop orders}
						{action move}
						{target
							{amount 1
							}
							{tag arty_target}
							{state operatable}
						}
					}
					{"delay"
						{time 12}
					}
					{"action"
						{selector
							{source current}
						}
						{drop orders}
						{target
							{amount 1
							}
							{tag arty_target}
							{state operatable}
						}
					}
					{"delay"
						{time 0.2}
					}
					{"actor_state"
						{selector
							{source current}
						}
						{cannon fire}
					}
					{"delay"
						{time 1}
					}
					{"action"
						{selector
							{source current}
						}
						{drop orders}
						{action suppression_fire}
						{target
							{amount 1
							}
							{tag arty_target}
							{state operatable}
						}
					}
					{"delay"
						{time 1}
					}
					{"action"
						{selector
							{source current}
						}
						{action attack}
						{target
							{amount 1
							}
							{tag arty_target}
							{state operatable}
						}
					}
					{"delay"
						{time 5}
					}
					{"effect"
						{selector
							{tag arty_selected}
						}
						{effect set_artillery_given_orders}
					}
					{"delay"
						{time 0.2}
					}
					{"entity_state"
						{selector
							{tag arty_target}
						}
						{tag_remove arty_target}
					}
					{"delay"
						{time 5}
					}
					{"trigger"
						{name "ai/artillery/arty"}
					}
				}
			}
			
;============== AI GRENADES	==============		
			{"ai_logic/ai_add_smoke_grenade"
				{condition
					{terms
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
					{"delay"
						{time 60}
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
							{amount 30
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
			{"ai_logic/ai_repair_vehicles_new"
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
									}
								}
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
										{state
											{state inhabited}
										}
									}
								}
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
										{state
											{state user_control}
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
											{state inhabited}
										}
										{tag
											{tag ammo_cooked}
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
					{## "talk"
						{selector
							{amount 1
							}
							{zone "gamezone"}
							{type human}
						}
						{text "mission/multi/test_message"}
					}
					{"call"
						{function "ai_repair_vehicle"}
						{context
							{specified}
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
								{amount 1
								}
							}
						}
					}
					{"delay"
						{time 6}
					}
					{"trigger"
						{name "ai_logic/ai_repair_vehicles_new"}
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
							{name "ai_logic/ai_repair_vehicles_new"}
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
					{## "action"
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
								}
							}
							{sort
								{type shuffle}
							}
							{amount 1
							}
						}
					}
					{## "action"
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
								}
							}
							{sort
								{type shuffle}
							}
							{amount 1
							}
						}
					}
					{## "action"
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
								}
							}
							{sort
								{type shuffle}
							}
							{amount 1
							}
						}
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
										{zone "gamezone"}
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
									{zone "gamezone"}
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
										{tag
											{tag ready_to_move}
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
										{state
											{state user_control}
										}
										{tag
											{tag cmp_def}
										}
										{prop
											{prop ai_recon_plane}
										}
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
						{delay 28}
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
			{"ai_logic/air/fighter"
				{condition
					{expression "1 & !2 & 3"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag fighter_ready}
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
											{tag fighter_select_sorty}
										}
									}
								}
							}
						}
						{"2.trigger"
							{name "ai_logic/air/bomber_ce"}
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
										{tag fighter_ready}
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
										{tag fighter_select_sorty}
									}
								}
							}
							{amount 1
							}
						}
						{effect select_for_sorty}
					}
					{"delay"
						{time 0.5}
					}
					{"air_state"
						{selector
							{tag fighter_select_sorty}
							{type vehicle}
							{state operatable}
						}
						{drop orders}
						{altitude 34}
					}
					{"delay"
						{time 0.5}
					}
					{## "call"
						{function "attack_player_air_defense_fighter"}
						{context
							{specified}
							{selector
								{tag fighter_select_sorty}
								{type vehicle}
								{state operatable}
							}
						}
					}
					{"call"
						{function "attack_player_ai_fighter"}
						{context
							{specified}
							{selector
								{tag fighter_select_sorty}
								{type vehicle}
								{state operatable}
							}
						}
					}
					{"delay"
						{time 2}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag fighter_select_sorty}
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
										{tag combat_run}
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
						{tag_add combat_run}
						{tag_remove fighter_select_sorty}
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
											{tag bomber_ce}
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
									}
								}
							}
						}
						{"if"
							{condition
								{type rand}
								{value 0.5}
							}
							{"trigger"
								{name "ai_logic/air/bomber_ce"}
								{on}
							}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"trigger"
						{name "ai_logic/air/fighter"}
					}
				}
			}
			{"ai_logic/air/bomber_ce"
				{condition
					{expression "1 & !2 & 3"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag bomber_ce_ready}
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
									}
								}
							}
						}
						{"2.trigger"
							{name "ai_logic/air/fighter"}
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
										{tag bomber_ce_ready}
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
										{tag bomber_ce_select_sorty}
									}
								}
							}
							{amount 1
							}
						}
						{effect select_for_sorty}
					}
					{"delay"
						{time 0.5}
					}
					{"air_state"
						{selector
							{tag bomber_ce_select_sorty}
							{type vehicle}
							{state operatable}
						}
						{altitude 40}
					}
					{"delay"
						{time 1}
					}
					{## "call"
						{function "attack_player_air_defense_bomber_ce"}
						{context
							{specified}
							{selector
								{tag bomber_ce_select_sorty}
								{type vehicle}
								{state operatable}
							}
						}
					}
					{"call"
						{function "attack_player_ai_bomber"}
						{context
							{specified}
							{selector
								{tag bomber_ce_select_sorty}
								{type vehicle}
								{state operatable}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag bomber_ce_select_sorty}
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
										{tag combat_run}
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
						{tag_add combat_run}
						{tag_remove bomber_ce_select_sorty}
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
											{tag fighter}
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
									}
								}
							}
						}
						{"if"
							{condition
								{type rand}
								{value 0.5}
							}
							{"trigger"
								{name "ai_logic/air/fighter"}
								{on}
							}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"trigger"
						{name "ai_logic/air/bomber_ce"}
					}
				}
			}

			{"ai_logic/air/ai_recon_plane"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag ai_recon_ready}
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
									{tag
										{tag ai_recon_ready}
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
										{tag recon_select_sorty}
									}
								}
							}
							{amount 1
							}
						}
						{effect select_for_sorty}
					}
					{"delay"
						{time 0.5}
					}
					{"air_state"
						{selector
							{tag recon_select_sorty}
							{type vehicle}
							{state operatable}
						}
						{altitude 50}
					}
					{"delay"
						{time 1}
					}
					{"air_attack"
						{selector
							{tag recon_select_sorty}
						}
						{enemies
							{amount 1
							}
							{tag flag_point}
						}
						{move_from_back}
						{force_placement}
						{attack_altitude 50}
					}
					{## "delay"
						{time 1}
					}
					{## "effect"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag recon_select_sorty}
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
										{tag recon_select_sorty}
									}
								}
							}
							{amount 1
							}
						}
						{effect tag_squad_need_next_order}
					}
					{"squad_create"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag recon_select_sorty}
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
										{tag recon_select_sorty}
									}
								}
							}
							{amount 1
							}
						}
						{name ai_recon_plane}
					}
					{"delay"
						{time 1}
					}
					{"squad_dismiss"
						{squad ai_recon_plane}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag recon_select_sorty}
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
										{tag combat_run}
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
						{tag_add combat_run}
						{tag_remove recon_select_sorty}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "ai_logic/air/ai_recon_plane"}
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
										{state
											{state user_control}
										}
										{tag
											{tag ready_to_move}
										}
										{tag
											{tag cmp_def}
										}
										{tag
											{tag user_plane}
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
								{type entities}
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag move_to_start_waypoint}
											}
										}
										{include
											{state
												{state operatable}
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
												{tag cmp_def}
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
											{tag
												{tag user_plane}
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
											{tag move_to_start_waypoint}
										}
									}
									{include
										{prop
											{prop airborne}
										}
										{state
											{state operatable}
										}
										{tag
											{tag drop_plane}
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
											{tag ready_to_move}
										}
										{tag
											{tag cmp_def}
										}
										{tag
											{tag user_plane}
										}
									}
								}
							}
							{"air_state"
								{selector
									{source current}
								}
								{drop orders}
								{altitude 45}
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
												{tag move_to_start_waypoint}
											}
										}
										{include
											{state
												{state operatable}
											}
											{prop
												{prop airborne}
											}
											{tag
												{tag fighter}
											}
										}
										{exclude
											{tag
												{tag cmp_def}
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
											{tag
												{tag fighter_ready}
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
											{tag move_to_start_waypoint}
										}
									}
									{include
										{prop
											{prop airborne}
										}
										{state
											{state operatable}
										}
										{tag
											{tag fighter}
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
											{tag fighter_ready}
										}
										{tag
											{tag cmp_def}
										}
									}
								}
							}
							{"air_state"
								{selector
									{source current}
								}
								{drop orders}
								{altitude 38}
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
												{tag move_to_start_waypoint}
											}
										}
										{include
											{state
												{state operatable}
											}
											{prop
												{prop airborne}
											}
											{tag
												{tag bomber_ce}
											}
										}
										{exclude
											{tag
												{tag cmp_def}
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
											{tag
												{tag bomber_ce_ready}
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
											{tag move_to_start_waypoint}
										}
									}
									{include
										{prop
											{prop airborne}
										}
										{state
											{state operatable}
										}
										{tag
											{tag bomber_ce}
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
											{tag bomber_ce_ready}
										}
										{tag
											{tag cmp_def}
										}
									}
								}
							}
							{"air_state"
								{selector
									{source current}
								}
								{drop orders}
								{altitude 40}
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
												{tag move_to_start_waypoint}
											}
										}
										{include
											{state
												{state operatable}
											}
											{prop
												{prop airborne}
											}
											{tag
												{tag bot_recon}
											}
										}
										{exclude
											{tag
												{tag cmp_def}
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
											{tag
												{tag ai_recon_ready}
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
											{tag move_to_start_waypoint}
										}
									}
									{include
										{prop
											{prop airborne}
										}
										{state
											{state operatable}
										}
										{tag
											{tag bot_recon}
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
											{tag ai_recon_ready}
										}
										{tag
											{tag cmp_def}
										}
									}
								}
							}
							{"air_state"
								{selector
									{source current}
								}
								{drop orders}
								{altitude 50}
							}
						}
					}
					{"delay"
						{time 0.2}
					}
					{"actor_to_waypoint"
						{selector
							{source current}
						}
						{waypoint "3000"}
						{approach "safe teleport"}
					}
					{"delay"
						{time 0.2}
					}
					{"effect"
						{selector
							{source current}
						}
						{effect move_plane_to_initial_waypoint}
					}
					{"delay"
						{time 0.2}
					}
					{"trigger"
						{name "ai_logic/air/move_planes_offmap"}
					}
				}
			}
			{"ai_logic/air/send_ai_drop_plane"
				{condition
					{terms
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag drop_plane}
										}
									}
									{include
										{tag
											{tag ready_to_move}
										}
										{state
											{state operatable}
										}
										{prop
											{prop vehicle}
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
										{tag
											{tag moving_to_drop_zone}
										}
										{tag
											{tag on_mission}
										}
									}
								}
								{amount 1
								}
							}
						}
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag fighter}
										}
										{tag
											{tag bomber_ce}
										}
									}
									{include
										{state
											{state operatable}
										}
									}
									{exclude
										{tag
											{tag combat_run}
										}
										{state
											{state inactive}
										}
									}
								}
							}
							{count
								{op "<<="}
								{value 1}
							}
						}
						{"3.event"
							{id "air_raid_start"}
						}
					}
				}
				{actions
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
							{"effect"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag drop_plane}
											}
										}
										{include
											{tag
												{tag ready_to_move}
											}
											{state
												{state operatable}
											}
											{prop
												{prop vehicle}
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
											{tag
												{tag moving_to_drop_zone}
											}
										}
									}
									{amount 1
									}
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
												{tag drop_plane}
											}
										}
										{include
											{tag
												{tag ready_to_move}
											}
											{state
												{state operatable}
											}
											{prop
												{prop vehicle}
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
											{tag
												{tag moving_to_drop_zone}
											}
										}
									}
									{amount 1
									}
								}
								{effect prep_drop_plane_to_move}
							}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"air_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag moving_to_drop_zone}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop vehicle}
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
									{tag
										{tag ready_to_move}
									}
								}
							}
							{amount 1
							}
						}
						{drop orders}
						{altitude 47}
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
									{source advanced}
									{group
										{select
											{tag
												{tag moving_to_drop_zone}
											}
										}
										{include
											{state
												{state operatable}
											}
											{prop
												{prop vehicle}
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
											{tag
												{tag ready_to_move}
											}
										}
									}
									{amount 1
									}
								}
								{target
									{amount 1
									}
									{tag drop_plane_start_point}
								}
							}
							{## "actor_to_waypoint"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag moving_to_drop_zone}
											}
										}
										{include
											{state
												{state operatable}
											}
											{prop
												{prop vehicle}
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
											{tag
												{tag ready_to_move}
											}
										}
									}
									{amount 1
									}
								}
								{waypoint "3101"}
								{approach "safe teleport & rotate"}
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
												{tag moving_to_drop_zone}
											}
										}
										{include
											{state
												{state operatable}
											}
											{prop
												{prop vehicle}
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
											{tag
												{tag ready_to_move}
											}
										}
									}
									{amount 1
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
							{"air_attack"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag moving_to_drop_zone}
											}
										}
										{include
											{state
												{state operatable}
											}
											{prop
												{prop vehicle}
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
											{tag
												{tag ready_to_move}
											}
										}
									}
									{amount 1
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
								{attack_altitude 45}
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
										{tag moving_to_drop_zone}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop vehicle}
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
							{amount 1
							}
						}
						{tag_remove moving_to_drop_zone}
					}
					{"delay"
						{time 4.15}
					}
					{"trigger"
						{name "ai_logic/air/send_ai_drop_plane"}
					}
				}
			}
			
			{"ai_logic/air/change_drop_zone_location"
				{condition
					{expression "1 & !2 & 3"}
					{terms
						{"1.entities"
							{selector
								{tag bot}
								{zone "gamezone"}
								{type human}
								{state operatable}
							}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag drop_plane}
										}
									}
									{include
										{state
											{state operatable}
										}
										{prop
											{prop drop_plane}
										}
										{prop
											{prop ai}
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
						{"3.event"
							{id "air_raid_start"}
						}
					}
				}
				{actions
					{"delay"
						{time 180}
					}
					{"entity_state"
						{selector
							{tag drop_zone_selected}
						}
						{tag_remove drop_zone_selected}
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
							{"entity_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag drop_zone}
											}
										}
										{exclude
											{tag
												{tag drop_zone_selected}
											}
										}
									}
									{sort
										{type entity}
										{entity
											{amount 1
											}
											{tag user_team}
										}
									}
									{amount 8
									}
								}
								{tag_add drop_zone_selected}
							}
						}
					}
					{"delay"
						{time 120}
					}
					{"trigger"
						{name "ai_logic/air/change_drop_zone_location"}
					}
				}
			}
			{"ai_logic/air/add_drop_points_to_user_spawn"
				{condition
					{terms
						{"1.entities"
							{selector
								{tag user_team}
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
							{tag user_team}
						}
						{effect spawn_drop_zone_targets}
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
										{tag drop_zone}
									}
								}
								{exclude
									{zone
										{zone "gamezone"}
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
								{type entities}
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag user_team}
											}
										}
										{include
											{tag
												{tag spawn_a}
											}
										}
									}
								}
							}
							{"spawn"
								{entity "ai_waypoint_pole"}
								{waypoint "3101"}
								{disable_random_spawn_position}
							}
							{"spawn"
								{entity "ai_waypoint_pole"}
								{waypoint "3102"}
								{disable_random_spawn_position}
							}
						}
						{"default"
							{"spawn"
								{entity "ai_waypoint_pole"}
								{waypoint "3103"}
								{disable_random_spawn_position}
							}
							{"spawn"
								{entity "ai_waypoint_pole"}
								{waypoint "3104"}
								{disable_random_spawn_position}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag drop_zone}
									}
								}
								{exclude
									{zone
										{zone "gamezone"}
									}
								}
							}
						}
						{tag_add drop_plane_start_point}
						{tag_remove drop_zone}
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
										{tag drop_plane_start_point}
									}
								}
							}
							{sort
								{type entity}
								{entity
									{tag user_team}
								}
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
							{source advanced}
							{group
								{select
									{tag
										{tag spawn_drop_zone}
									}
								}
							}
							{sort
								{type entity}
								{entity
									{amount 1
									}
									{tag drop_plane_start_point}
								}
								{mode farthest}
							}
							{amount 6
							}
						}
						{tag_add keep_post}
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
										{tag drop_zone}
									}
								}
								{exclude
									{zone
										{zone "gamezone"}
									}
									{tag
										{tag drop_plane_start_point}
									}
								}
							}
							{group
								{select
									{tag
										{tag spawn_drop_zone}
									}
								}
								{exclude
									{tag
										{tag keep_post}
									}
								}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"if"
						{condition
							{type entities}
							{selector
								{tag drop_plane_start_point}
							}
							{count
								{op "=="}
								{value 0}
							}
						}
						{"delete"
							{selector
								{tag drop_zone_selected}
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
					{## "delay"
						{time 1}
					}
					{## "effect"
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
								}
							}
							{amount 1
							}
						}
						{effect select_paratroopers_to_give_orders}
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
									{meters 100}
								}
								{tag
									{"tag pair"}
									{"for selector" p_crew}
									{"for enemy" p_cannon_enter}
								}
							}
							{"delay"
								{time 1}
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
							{"delay"
								{time 1}
							}
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
									{speed fast}
									{kind fast}
									{type normal}
								}
							}
							{"delay"
								{time 1}
							}
							{"effect"
								{selector
									{tag selected_paratrooper}
								}
								{effect tag_squad_need_next_order}
							}
						}
					}
					{## "delay"
						{time 0.5}
					}
					{## "squad_create"
						{selector
							{tag selected_paratrooper}
							{state operatable}
						}
					}
					{"delay"
						{time 0.5}
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

;============== AI ATTACK LOGIC ==========
			{## "ai_logic/flanking/disembarked_inf_need_orders"
				{condition
					{terms
						{"1.entities"
							{selector
								{tag inf_need_to_attack}
								{state operatable}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 3}
					}
					{"entity_state"
						{selector
							{amount 5
							}
							{tag inf_need_to_attack}
							{type human}
							{state operatable}
						}
						{tag_add inf_getting_ordered}
						{tag_remove inf_need_to_attack}
					}
					{"delay"
						{time 1}
					}
					{"select"
						{tag inf_getting_ordered}
						{type human}
						{state operatable}
					}
					{"delay"
						{time 0.5}
					}
					{"effect"
						{selector
							{source current}
						}
						{effect tag_squad_need_next_order}
					}
					{"delay"
						{time 0.5}
					}
					{"squad_create"
						{selector
							{tag inf_getting_ordered}
							{state operatable}
						}
					}
					{"delay"
						{time 0.5}
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
						{time 0.5}
					}
					{"entity_state"
						{selector
							{tag inf_getting_ordered}
							{type human}
						}
						{tag_remove inf_getting_ordered}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "ai_logic/flanking/disembarked_inf_need_orders"}
					}
				}
			}
			{## "ai_logic/force_move_ai_cannons"
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
					{## "while"
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
			
;============== AI SCENE VARS	==============
			{"ai_logic/scene_variable/move_scene_variable"
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
					;{"delay"
					;	{time 0.2}
					;}
					{"actor_to_waypoint"
						{selector
							{source current}
						}
						{waypoint "3001"}
						{approach "safe teleport"}
					}
				}
			}

;============== AI MISC	==============	
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
							{id "init2"}
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
			{"ai_logic/check_ai_abandon_mechanic_enabled"
				{condition
					{terms
						{"1.cmp_i"
							{var "enable_ai_abandon_mechanics$"}
							{op ">"}
							{value 0}
						}
						{"2.entities"
							{selector
								{source advanced}
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
										{zone
											{zone "gamezone"}
										}	
									}
									{exclude
										{tag
											{tag _ai_abandon_check_active}
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
										{tag _bot}
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
									{tag
										{tag _ai_abandon_check_active}
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
								}
							}
						}
						{tag_add _ai_abandon_check_active}
					}
					{"delay"
						{time 0.2}
					}
					{"trigger"
						{name "ai_logic/check_ai_abandon_mechanic_enabled"}
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

			{"ai/strategy/human_wave_alert"
				{condition
					{terms
						{"1.cmp_i"
							{var "human_wave_strategy_active$"}
							{op ">"}
							{value 0}
						}
						{"2.entities"
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
											{prop human}
										}
										{state
											{state "operatable"}
										}
									}
									{exclude
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
						{time 5}
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
								{text "mission/multi/human_wave_alert_1"}
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
								{text "mission/multi/human_wave_alert_2"}
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
								{text "mission/multi/human_wave_alert_3"}
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
								{text "mission/multi/human_wave_alert_4"}
							}
						}
					}
				}
			}

			{## "ai_logic/retreat_to_repair_tank"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag need_to_repair}
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
											{state user_control}
										}
									}
								}
							}
						}
					}
				}
				{actions
					{"effect"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag need_to_repair}
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
										{tag cmp_def}
									}
									{state
										{state user_control}
									}
								}
							}
							{amount 1
							}
						}
						{effect retreat_to_repair}
					}
					{"delay"
						{time 0.5}
					}
					{"actor_state"
						{selector
							{amount 1
							}
							{tag reversing_to_repair}
							{type vehicle}
							{state operatable}
						}
						{drop orders}
						{movement
							{speed fast}
							{forward off}
							{backward on}
						}
					}
					{"delay"
						{time 0.2}
					}
					{"action"
						{selector
							{amount 1
							}
							{tag reversing_to_repair}
							{type vehicle}
							{state operatable}
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
								{exclude
									{state
										{state inactive}
									}
								}
							}
							{sort
								{type entity}
								{entity
									{amount 1
									}
									{tag reversing_to_repair}
									{type vehicle}
									{state operatable}
								}
							}
							{amount 1
							}
						}
					}
					{"delay"
						{time 0.2}
					}
					{"entity_state"
						{selector
							{tag reversing_to_repair}
						}
						{tag_remove reversing_to_repair}
					}
					{"delay"
						{time 0.2}
					}
					{"trigger"
						{name "ai_logic/retreat_to_repair_tank"}
					}
				}
			}
			{## "ai_logic/ai_stop_reversing_set"
				{condition
					{terms
						{"1.entities"
							{selector
								{tag ai_stop_reversing}
								{type tank}
								{state operatable}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"actor_state"
						{selector
							{tag ai_stop_reversing}
							{type tank}
							{state operatable}
						}
						{movement
							{forward on}
							{backward on}
						}
					}
					{"delay"
						{time 0.2}
					}
					{"entity_state"
						{selector
							{tag ai_stop_reversing}
						}
						{tag_remove ai_stop_reversing}
					}
					{"delay"
						{time 0.2}
					}
					{"trigger"
						{name "ai_logic/ai_stop_reversing_set"}
					}
				}
			}
