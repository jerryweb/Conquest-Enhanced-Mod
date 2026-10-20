; File created by Hawka
;==========================================================================================================

			{"ai_logic/ai_smoke_at_vehicles"
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
											{tag smk_}
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
										;{tag
										;	{tag _user}
										;}
										{zone
											{zone "combat"}
										}
									}
									{include
										{state
											{state "operatable inhabited"}
										}
										{prop
											{prop vehicle}
										}
									}
									{exclude
										{prop
											{prop airborne}
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
								{meters 145}
							}
							{tag
								{"tag pair"}
								{"for selector" ai_veh_smoke}
								{"for enemy" smk_veh_target}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{## "timer"
						{time 6}
						{title "in ai vehicle smoke script"}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag smk_}
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
										{tag ai_veh_smoke}
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
									{tag ai_veh_smoke}
								}
							}
							{amount 3}
						}
						{tag_add ai_veh_smoke}
					}
					{"delay"
						{time 0.3}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag ai_veh_smoke}
							{state operatable}
						}
						{tag_add _mi_temp_veh_smoke}
						{tag_remove smk_}
					}
					{"delay"
						{time 0.2}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _mi_temp_veh_smoke}
						}
						{tag_add _lua_mi}
					}
					{"inventory"
						{selector
							{tag ai_veh_smoke}
							{type human}
							{state "not dead"}
						}
						{action take}
						{item "smoke"}
					}
					{"delay"
						{time 0.5}
					}
					{"actor_fire"
						{selector
							{tag ai_veh_smoke}
							{type human}
							{state operatable}
						}
						{drop "orders sensor senseless"}
						{deviate}
						{enemies
							{ignore_captured_by_user 0}
							{tag smk_veh_target}
						}
						{interval 0}
						{time 0}
						{burst_mode once}
					}
					{"delay"
						{time 2}
					}
					{"actor_state"
						{selector
							{ignore_captured_by_user 0}
							{tag ai_veh_smoke}
							{state operatable}
						}
						{drop orders}
						{fire_mode open}
						{move_mode free}
						{ai_move
							{mode enable}
						}
						{ai
							{advance_ratio 1}
						}
					}
					{"delay"
						{time 1}
					}
					{"actor_to_cover"
						{selector
							{ignore_captured_by_user 0}
							{tag ai_veh_smoke}
							{state operatable}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag smk_veh_target}
						}
						{tag_remove smk_veh_target}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag ai_veh_smoke}
						}
						{tag_remove ai_veh_smoke}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _mi_temp_veh_smoke}
						}
						{tag_remove _lua_mi}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _mi_temp_veh_smoke}
						}
						{tag_remove _mi_temp_veh_smoke}
					}
					{"delay"
						{time 60}
					}
					{"trigger"
						{name "ai_logic/ai_smoke_at_vehicles"}
					}
				}
			}
			{"ai_logic/spg_see_engage"
				{condition
					{terms
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
										{state
											{state "operatable inhabited"}
										}
										{prop
											{prop tank}
										}
										{tag
											{tag "+mobilegun"}
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
											{tag spg_engaging}
										}
										{tag
											{tag _lua_mi}
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
										{player
											{player "1"}
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
										{player
											{player "0"}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 150}
							}
							{detection visible}
							{tag
								{"tag pair"}
								{"for selector" spg_stop_to_attack}
								{"for enemy" spg_target}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.5}
					}
					{"select"
						{amount 1
						}
						{tag spg_stop_to_attack}
						{player "1"}
						{type tank}
						{state inhabited}
					}
					{"delay"
						{time 0.5}
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
							{tag spg_target}
							{state operatable}
						}
					}
					{"delay"
						{time 4}
					}
					{"action"
						{selector
							{source current}
						}
						{action attack}
						{target
							{amount 1
							}
							{tag spg_target}
							{state operatable}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag spg_target}
						}
						{tag_remove spg_target}
					}
					{"effect"
						{selector
							{source current}
						}
						{effect spg_engaging_target}
					}
					{"delay"
						{time 0.5}
					}
					{"trigger"
						{name "ai_logic/spg_see_engage"}
					}
				}
			}
			{"ai_logic/give_cannon_next_order"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag cannon_need_next_order}
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
										{tag cannon_need_next_order}
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
						{tag_add cannon_selected_to_move}
						{tag_remove cannon_need_next_order}
					}
					{"delay"
						{time 0.2}
					}
					{"select"
						{source advanced}
						{group
							{select
								{tag
									{tag cannon_selected_to_move}
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
									{state inactive}
								}
								{state
									{state user_control}
								}
							}
						}
						{amount 1
						}
					}
					{## "delay"
						{time 0.2}
					}
					{## "entity_state"
						{selector
							{source current}
						}
						{tag_add _lua_mi}
					}
					{"delay"
						{time 0.2}
					}
					{"actor_state"
						{selector
							{source current}
						}
						{drop orders}
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
						{time 0.5}
					}
					{"trigger"
						{name "ai_logic/give_cannon_next_order"}
					}
				}
			}

;=========== Recon =======================================================================================
			
			(define "spot_inf_targets_criteria" 
				{"%condition_one.see_actors"
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
							}
						}
					}
					{enemy
						{source advanced}
						{group
							{select
								{zone
									{zone "forward%flag"}
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
								{tag
									{tag _bot}
								}
								{player
									{player "1"}
								}
								{player
									{player "0"}
								}
								{tag
									{tag possible_enemy_inf}
								}
								{state
									{state linked}
								}
							}
						}
					}
					{distance
						{mode near_than}
						{meters 200}
					}
					{detection visible}
					{tag
						{"tag pair"}
						{"for enemy" possible_enemy_inf}
					}
				}
				{"%condition_two.cmp_i"
					{var "attacker_target_flag$"}
					{op "=="}
					{value %flag}
				}
			)
			(define "spot_inf_targets_case"
				{"case"
					{condition
						{type cmp_i}
						{var "attacker_target_flag$"}
						{op "=="}
						{value %flag}
					}
					{"loop" 10
						{"delay"
							{time 0.25}
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
										}
									}
								}
								{enemy
									{source advanced}
									{group
										{select
											{zone
												{zone "forward%flag"}
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
											{tag
												{tag _bot}
											}
											{player
												{player "1"}
											}
											{player
												{player "0"}
											}
											{tag
												{tag possible_enemy_inf}
											}
											{state
												{state linked}
											}
										}
									}
								}
								{distance
									{mode near_than}
									{meters 200}
								}
								{detection visible}
								{tag
									{"tag pair"}
									{"for enemy" possible_enemy_inf}
								}
							}
						}
					}
				}
			)

			{"ai_logic/spot_priority_inf_targets"
				{condition
					{expression "(1 & 2) | (3 & 4) | (5 & 6) | (7 & 8) | (9 & 10)"}
					{terms
						("spot_inf_targets_criteria" flag(1) condition_one(1) condition_2(2))
						("spot_inf_targets_criteria" flag(2) condition_one(3) condition_2(4))
						("spot_inf_targets_criteria" flag(3) condition_one(5) condition_2(6))
						("spot_inf_targets_criteria" flag(4) condition_one(7) condition_2(8))
						("spot_inf_targets_criteria" flag(5) condition_one(9) condition_2(10))
					}
				}
				{actions
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{tag possible_enemy_inf}
						}
						{tag_add possible_enemy_inf}
					}
					{"delay"
						{time 0.5}
					}
					{"switch"
						("spot_inf_targets_case" flag(1))
						("spot_inf_targets_case" flag(2))
						("spot_inf_targets_case" flag(3))
						("spot_inf_targets_case" flag(4))
						("spot_inf_targets_case" flag(5))
					}
					{"delay"
						{time 1}
					}
					{## "effect"
						{selector
							{tag possible_enemy_inf}
							{type human}
							{state "not dead"}
						}
						{effect smoke_for_test}
					}
					{"delay"
						{time 45}
					}
					{"trigger"
						{name "ai_logic/spot_priority_inf_targets"}
					}
				}
			}
			{"ai_logic/spot_priority_targets"
				{condition
					{expression "(1 | 2 | 3 | 4) & !5"}
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
									}
								}
							}
							{enemy
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
											{prop artillery_minimap_heavy}
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
										{player
											{player "1"}
										}
										{player
											{player "0"}
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
							{detection visible}
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
											{tag _ai_defender}
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
										{zone
											{zone "gamezone"}
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
										{player
											{player "1"}
										}
										{player
											{player "0"}
										}
										{tag
											{tag possible_enemy_tank}
										}
										{prop
											{prop artillery_minimap_heavy}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 200}
							}
							{detection visible}
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
											{tag _ai_defender}
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
										{zone
											{zone "gamezone"}
										}
									}
									{include
										{state
											{state operatable}
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
										{player
											{player "1"}
										}
										{player
											{player "0"}
										}
										{tag
											{tag possible_enemy_cannon}
										}
										{prop
											{prop artillery_minimap_heavy}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 200}
							}
							{detection visible}
							{tag
								{"tag pair"}
								{"for enemy" possible_enemy_cannon}
							}
						}
						{"4.see_actors"
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
									}
								}
							}
							{enemy
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
										{tag
											{tag officer}
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
										{player
											{player "1"}
										}
										{player
											{player "0"}
										}
										{tag
											{tag possible_enemy_officer}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 200}
							}
							{detection visible}
							{tag
								{"tag pair"}
								{"for enemy" possible_enemy_officer}
							}
						}
						{"5.event"
							{id "cannon_artillery_script_thread_active"}
						}
					}
				}
				{actions
					{## "timer"
						{time 25}
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
									}
								}
							}
							{enemy
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
											{prop artillery_minimap_heavy}
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
										{player
											{player "1"}
										}
										{player
											{player "0"}
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
							{detection visible}
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
											{tag _ai_defender}
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
										{zone
											{zone "gamezone"}
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
										{player
											{player "1"}
										}
										{player
											{player "0"}
										}
										{tag
											{tag possible_enemy_tank}
										}
										{prop
											{prop artillery_minimap_heavy}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 200}
							}
							{detection visible}
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
											{tag _ai_defender}
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
										{zone
											{zone "gamezone"}
										}
									}
									{include
										{state
											{state operatable}
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
										{player
											{player "1"}
										}
										{player
											{player "0"}
										}
										{tag
											{tag possible_enemy_cannon}
										}
										{prop
											{prop artillery_minimap_heavy}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 200}
							}
							{detection visible}
							{tag
								{"tag pair"}
								{"for enemy" possible_enemy_cannon}
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
									}
								}
							}
							{enemy
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
										{tag
											{tag officer}
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
										{player
											{player "1"}
										}
										{player
											{player "0"}
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
							{detection visible}
							{tag
								{"tag pair"}
								{"for enemy" possible_enemy_officer}
							}
						}
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
										{tag possible_enemy_artillery}
									}
									{tag
										{tag possible_enemy_cannon}
									}
									{tag
										{tag possible_enemy_tank}
									}
									{tag
										{tag possible_enemy_officer}
									}
								}
							}
						}
						{effect smoke_for_test}
					}
					{"delay"
						{time 45}
					}
					{"trigger"
						{name "ai_logic/spot_priority_targets"}
					}
				}
			}

			
;=========== Trucks =======================================================================================
			{"ai_logic/send_empty_transport_back"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _ai_veh_empty}
										}
									}
									{include
										{prop
											{prop vehicle}
										}
										{state
											{state "chassis_work inhabited"}
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
											{tag _ai_veh_empty_selected}
										}
										{tag
											{tag _lua_mi}
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
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_veh_empty}
									}
								}
								{include
									{prop
										{prop vehicle}
									}
									{state
										{state "chassis_work inhabited"}
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
										{tag _ai_veh_empty_selected}
									}
									{tag
										{tag _lua_mi}
									}
									{state
										{state user_control}
									}
								}
							}
							{amount 1
							}
						}
						{tag_add _ai_veh_empty_selected}
						{tag_remove _ai_veh_empty}
					}
					{"delay"
						{time 0.1}
					}
					{"select"
						{tag _ai_veh_empty_selected}
						{type vehicle}
						{state inhabited}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "bots_spawnside$"}
								{op "=="}
								{value 1}
							}
							{"action"
								{selector
									{source current}
								}
								{drop orders}
								{action move}
								{target
									{source advanced}
									{group
										{select
											{tag
												{tag spawn_a}
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
											{tag _ai_veh_empty_selected}
											{type vehicle}
											{state inhabited}
										}
									}
									{amount 1
									}
								}
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
									{source advanced}
									{group
										{select
											{tag
												{tag spawn_b}
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
											{tag _ai_veh_empty_selected}
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
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source current}
						}
						{tag_add _transport_rtb}
					}
					{"delay"
						{time 0.1}
					}
					{"actor_state"
						{selector
							{source current}
						}
						{ai_move
							{mode disable}
						}
						{movement
							{speed fast}
						}
						{ai
							{follow_commander off}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source current}
						}
						{tag_add _lua_mi}
						{tag_remove _ai_veh_empty_selected}
					}
					{"delay"
						{time 0.1}
					}
					{"trigger"
						{name "ai_logic/send_empty_transport_back"}
					}
				}
			}
			{"ai_logic/delete_empty_transports"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
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
									{include
										{tag
											{tag _transport_rtb}
										}
										{state
											{state "chassis_work inhabited"}
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
						}
					}
				}
				{actions
					{"delay"
						{time 4}
					}
					{"delete"
						{selector
							{source advanced}
							{group
								{select
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
								{include
									{tag
										{tag _transport_rtb}
									}
									{state
										{state "chassis_work inhabited"}
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
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "ai_logic/delete_empty_transports"}
					}
				}
			}