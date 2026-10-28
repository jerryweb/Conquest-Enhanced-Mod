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
							{amount 4
							}
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
							{amount 1
							}
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
						{time 0.1}
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
						{time 0.1}
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
						{time 55}
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
						{"1.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 1}
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
			{"ai_logic/check_idle_cannons"
				{condition
					{terms
						{"1.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 1}
						}
						{"2.cmp_i"
							{var "prep_inform$"}
							{op "=="}
							{value 1}
						}
					}
				}
				{actions
					{"delay"
						{time 180}
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
								}
							}
						}
						{tag_add cannon_need_next_order}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "ai_logic/check_idle_cannons"}
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
			{"ai_logic/tank_reverse_to_repair"
				{condition
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
										{tag
											{tag "-turret"}
										}
										{tag
											{tag _lua_mi}
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
									{tag
										{tag "-turret"}
									}
									{tag
										{tag _lua_mi}
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
												{tag cmp_def}
											}
											{tag
												{tag cmp_mg}
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
						{time 0.5}
					}
					{"select"
						{tag selected_tank_to_repair}
						{type tank}
						{state inhabited}
					}
					{"delay"
						{time 0.5}
					}
					{"effect"
						{selector
							{source current}
						}
						{effect reverse_to_repair}
					}
					{"actor_state"
						{selector
							{source current}
						}
						{movement
							{forward off}
						}
					}
					{"delay"
						{time 0.5}
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
							{tag back_up_to_repair}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"delete"
						{selector
							{tag back_up_to_repair}
						}
					}
					{"delay"
						{time 5}
					}
					{"actor_state"
						{selector
							{source current}
						}
						{movement
							{forward on}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{tag selected_tank_to_repair}
						}
						{tag_remove selected_tank_to_repair}
					}
					{"delay"
						{time 0.5}
					}
					{"trigger"
						{name "ai_logic/tank_reverse_to_repair"}
					}
				}
			}
			
;=========== Air =======================================================================================
			{"ai_logic/air/stage_ai_planes"
				{condition
					{expression "1 & (2 & 3) | (!2 & !3)"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag engine_count_2}
										}
										{tag
											{tag engine_count_1}
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
											{state user_control}
										}
										{tag
											{tag air_vehicle}
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
										{tag
											{tag transport_plane_ready_for_mission}
										}
										{tag
											{tag plane_ready_for_mission}
										}
										{player
											{player "0"}
										}
									}
								}
								{amount 1
								}
							}
						}
						{"2.cmp_i"
							{var "prep_inform$"}
							{op ">"}
							{value 0}
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
							{source advanced}
							{group
								{select
									{tag
										{tag engine_count_2}
									}
									{tag
										{tag engine_count_1}
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
										{state user_control}
									}
									{tag
										{tag air_vehicle}
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
									{tag
										{tag selected_for_staging}
									}
									{tag
										{tag plane_ready_for_mission}
									}
									{player
										{player "0"}
									}
								}
							}
							{amount 1
							}
						}
						{tag_add selected_for_staging}
					}
					{"delay"
						{time 0.2}
					}
					{"select"
						{tag selected_for_staging}
						{type vehicle}
						{state inhabited}
					}
					{"delay"
						{time 0.25}
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
												{tag selected_for_staging}
											}
										}
										{include
											{prop
												{prop drop_plane}
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
								{drop "orders sensor senseless"}
								{altitude 85}
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
												{tag selected_for_staging}
											}
										}
										{include
											{tag
												{tag recon_plane}
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
						{"default"
							{"air_state"
								{selector
									{source current}
								}
								{drop orders}
								{altitude 75}
							}
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
						{time 1}
					}
					{"waypoint"
						{who
							{type actor}
							{actors
								{tag selected_for_staging}
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
						{time 1}
					}
					{"entity_state"
						{selector
							{tag selected_for_staging}
						}
						{tag_remove selected_for_staging}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "ai_logic/air/stage_ai_planes"}
					}
				}
			}
			{"ai_logic/air/send_ai_attack_plane"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag plane_ready_for_mission}
										}
									}
									{include
										{prop
											{prop airborne}
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
											{state user_control}
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
											{tag bomber_making_first_pass}
										}
										{tag
											{tag enemy_air}
										}
										{tag
											{tag air_vehicle}
										}
										{prop
											{prop drop_plane}
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
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "user_team$"}
								{op "=="}
								{value 1}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag plane_ready_for_mission}
											}
										}
										{include
											{prop
												{prop airborne}
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
												{state user_control}
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
												{tag bomber_making_first_pass}
											}
											{tag
												{tag enemy_air}
											}
											{tag
												{tag air_vehicle}
											}
											{prop
												{prop drop_plane}
											}
										}
									}
									{amount 1
									}
								}
								{waypoint "0"}
								{approach "safe teleport & rotate"}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag plane_ready_for_mission}
											}
										}
										{include
											{prop
												{prop airborne}
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
												{state user_control}
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
												{tag bomber_making_first_pass}
											}
											{tag
												{tag enemy_air}
											}
											{tag
												{tag air_vehicle}
											}
											{prop
												{prop drop_plane}
											}
										}
									}
									{amount 1
									}
								}
								{waypoint "6"}
								{approach "safe teleport & rotate"}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"effect"
						{selector
							{tag plane_ready_for_mission}
						}
						{effect bomber_make_first_pass}
					}
					{"delay"
						{time 4}
					}
					{"trigger"
						{name "ai_logic/air/send_ai_attack_plane"}
					}
				}
			}
			{"ai_logic/air/airstrike_attack_target"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag bomber_making_first_pass}
										}
									}
									{include
										{prop
											{prop airborne}
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
						{time 2.5}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag bomber_making_first_pass}
									}
								}
								{include
									{prop
										{prop airborne}
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
						{tag_add selected_bomber_for_targeting}
						{tag_remove bomber_making_first_pass}
					}
					{"delay"
						{time 1}
					}
					{"select"
						{source advanced}
						{group
							{select
								{tag
									{tag selected_bomber_for_targeting}
								}
							}
							{include
								{prop
									{prop airborne}
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
										{include
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag _bot}
											}
											{state
												{state dead}
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
								{time 0.1}
							}
							{"entity_state"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
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
										{include
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag _bot}
											}
											{state
												{state dead}
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
								{tag_add ai_air_target}
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
												{tag _user}
											}
										}
										{include
											{zone
												{zone "gamezone"}
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
										}
									}
									{amount 1
									}
								}
								{tag_add ai_air_target}
							}
						}
					}
					{"delay"
						{time 1.1}
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
												{tag selected_bomber_for_targeting}
											}
										}
										{include
											{tag
												{tag altitude_high}
											}
										}
									}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"air_attack"
								{selector
									{source current}
									{ignore_captured_by_user 0}
								}
								{drop "orders sensor senseless"}
								{enemies
									{ignore_captured_by_user 0}
									{tag ai_air_target}
								}
								{attack_altitude 64}
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
												{tag selected_bomber_for_targeting}
											}
										}
										{include
											{tag
												{tag altitude_low}
											}
										}
										{exclude
											{tag
												{tag altitude_high}
											}
										}
									}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"air_attack"
								{selector
									{source current}
									{ignore_captured_by_user 0}
								}
								{drop "orders sensor senseless"}
								{enemies
									{ignore_captured_by_user 0}
									{tag ai_air_target}
								}
								{attack_altitude 30}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"air_attack"
								{selector
									{ignore_captured_by_user 0}
									{tag selected_bomber_for_targeting}
									{type vehicle}
									{state inhabited}
								}
								{drop "orders sensor senseless"}
								{enemies
									{ignore_captured_by_user 0}
									{tag ai_air_target}
								}
								{attack_altitude 60}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag ai_air_target}
						}
						{tag_remove ai_air_target}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag selected_bomber_for_targeting}
						}
						{tag_remove selected_bomber_for_targeting}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "ai_logic/air/airstrike_attack_target"}
					}
				}
			}
			{"ai_logic/air/send_ai_transport_plane"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag transport_plane_ready_for_mission}
										}
									}
									{include
										{prop
											{prop drop_plane}
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
											{state user_control}
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
											{tag bomber_making_first_pass}
										}
										{tag
											{tag enemy_air}
										}
										{tag
											{tag air_vehicle}
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
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag transport_plane_ready_for_mission}
									}
								}
								{include
									{prop
										{prop drop_plane}
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
										{state user_control}
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
										{tag bomber_making_first_pass}
									}
									{tag
										{tag enemy_air}
									}
									{tag
										{tag air_vehicle}
									}
								}
							}
							{amount 1
							}
						}
						{tag_add selected_transport_plane}
						{tag_remove transport_plane_ready_for_mission}
					}
					{"delay"
						{time 1}
					}
					{"select"
						{source advanced}
						{group
							{select
								{tag
									{tag selected_transport_plane}
								}
							}
							{include
								{prop
									{prop drop_plane}
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
						{time 1}
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
						{attack_altitude 85}
					}
					{"delay"
						{time 1}
					}
					{"effect"
						{selector
							{source current}
						}
						{effect prep_drop_plane_to_move}
					}
					{"delay"
						{time 4}
					}
					{"trigger"
						{name "ai_logic/air/send_ai_transport_plane"}
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
					{expression "1 | 2 | 3 | 4"}
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
					{## "delete"
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
					{"effect"
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
						{effect hide_transports}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "ai_logic/delete_empty_transports"}
					}
				}
			}