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
											{tag player_veh}
										}
										{tag
											{tag player_armor}
										}
										{tag
											{tag player_car}
										}
									}
									{include
										{prop
											{prop vehicle}
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
											{prop vehicle}
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
						{time 1}
					}
					{"ables"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag player_veh}
									}
									{tag
										{tag player_armor}
									}
									{tag
										{tag player_car}
									}
								}
								{include
									{prop
										{prop vehicle}
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
										{prop vehicle}
									}
									{state
										{state user_control}
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
											{state inhabited}
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
												{state "inhabited user_control"}
											}
                                            {state
                                                {state inhabited}
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

;============ AI DEFENDER SETUP SCRIPTS========================================
			(define "delete_ai_defenders_thread" ;parms: flag_number
				{"thread"				
					{"delay"
						{time 0.2}
					}
					{"while"
						{condition
							{type entities}
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag "%flag_a_1-3"}
										}
										{tag
											{tag "%flag_b_1-3"}
										}
										{tag
											{tag "%flag_a_2-3"}
										}
										{tag
											{tag "%flag_b_2-3"}
										}
										{tag
											{tag "%flag_a_3"}
										}
										{tag
											{tag "%flag_b_3"}
										}
									}
									{include
										{prop
											{prop human}
										}
										{tag
											{tag cmp_def}
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
									}
								}
								{group
									{select
										{tag
											{tag "%flag_a_1-3"}
										}
										{tag
											{tag "%flag_b_1-3"}
										}
										{tag
											{tag "%flag_a_2-3"}
										}
										{tag
											{tag "%flag_b_2-3"}
										}
										{tag
											{tag "%flag_a_3"}
										}
										{tag
											{tag "%flag_b_3"}
										}
									}
									{include
										{prop
											{prop human}
										}
										{tag
											{tag _def}
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
									}
								}
							}
							{count
								{op ">"}
								{value "max_ai_defender_inf_per_flag_count$"}
							}
						}
						{"delay"
							{time 0.1}
						}
						{"delete"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag "%flag_a_1-3"}
										}
										{tag
											{tag "%flag_b_1-3"}
										}
										{tag
											{tag "%flag_a_2-3"}
										}
										{tag
											{tag "%flag_b_2-3"}
										}
										{tag
											{tag "%flag_a_3"}
										}
										{tag
											{tag "%flag_b_3"}
										}
									}
									{include
										{prop
											{prop human}
										}
										{tag
											{tag cmp_def}
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
									}
								}
								{group
									{select
										{tag
											{tag "%flag_a_1-3"}
										}
										{tag
											{tag "%flag_b_1-3"}
										}
										{tag
											{tag "%flag_a_2-3"}
										}
										{tag
											{tag "%flag_b_2-3"}
										}
										{tag
											{tag "%flag_a_3"}
										}
										{tag
											{tag "%flag_b_3"}
										}
									}
									{include
										{prop
											{prop human}
										}
										{tag
											{tag _def}
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
									}
								}
								{amount 3
								}
							}
						}
						{"delay"
							{time 0.5}
						}
					}
				}
			)

			{"conquest_enhanced_mechanics/ai_defenders/populate_ai_defender_infantry"
				{condition
					{terms
						{"1.cmp_i"
							{var "balance$"}
							{op "=="}
							{value 1}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag extra_inf_def}
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
										{zone
											{zone "gamezone"}
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
					{"while"
						{condition
							{type cmp_i}
							{var "current_ai_inf_def_x5_count$"}
							{op "<<"}
							{value "max_ai_inf_def_x5_count$"}
						}
						{"set_i"
							{var "current_ai_inf_def_x5_count$"}
							{op "+"}
							{value 1}
						}
						{"delay"
							{time 0.3}
						}
						{"call"
							{function "move_extra_ai_defenders_to_point"}
						}
						{"delay"
							{time 0.3}
						}
					}
					{"delay"
						{time 4}
					}					
					{"actor_to_cover"
						{selector
							{ignore_captured_by_user 0}
							{tag not_delete}
							{type human}
							{state "not dead"}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"actor_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{zone
										{zone "fpc1"}
									}
									{zone
										{zone "fpc2"}
									}
									{zone
										{zone "fpc3"}
									}
									{zone
										{zone "fpc4"}
									}
									{zone
										{zone "fpc5"}
									}
								}
								{include
									{tag
										{tag not_delete}
									}
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
						{move_mode zone}
						{move_radius 20}
						{weapon_prepare on}
						{ai
							{advance_ratio 1}
							{retreat_ratio 5}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"actor_state"
						{selector
							{ignore_captured_by_user 0}
							{tag cmp_def}
							{type human}
							{state "not dead"}
						}
						{move_mode zone}
						{move_radius 20}
						{weapon_prepare on}
						{ai
							{advance_ratio 1}
							{retreat_ratio 5}
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
									{zone
										{zone "gamezone"}
									}
									{tag
										{tag cmp_def}
									}
									{tag
										{tag _def}
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
										{state user_control}
									}
									{tag
										{tag player}
									}
									{tag
										{tag _user}
									}
								}
							}
						}
						{tag_add ignore_spawn_logic}
					}

					("delete_ai_defenders_thread" flag(1))
					("delete_ai_defenders_thread" flag(2))
					("delete_ai_defenders_thread" flag(3))
					("delete_ai_defenders_thread" flag(4))
					("delete_ai_defenders_thread" flag(5))

					{"delay"
						{time 10.5}
					}                                      
					{"delete"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag cmp_def}
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
										{state linked}
									}
									{state
										{state user_control}
									}
									{zone
										{zone "gamezone"}
									}
									
									{tag
										{tag not_delete}
									}
								}
							}
						}
					}
                    {"delay"
						{time 10.5}
					}
				}
			}
			{"conquest_enhanced_mechanics/ai_defenders/hide_ai_defenders_to_keep"
				{condition
				}
				{actions
					{"delay"
						{time 3}
					}
					{"entity_state"
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
									{state
										{state operatable}
									}
								}
								{exclude
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
							{amount 10
							}
						}
						{tag_add not_delete}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{amount 10
							}
							{tag not_delete}
						}
						{inactive on}
					}
				}
			}
			{"conquest_enhanced_mechanics/ai_defenders/set_defense_level"
				{condition
					{terms
						{"1.cmp_i"
							{var "defense_level$"}
							{op "=="}
							{value 0}
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
												{tag "1_a_3"}
											}
											{tag
												{tag "1_b_3"}
											}
											{tag
												{tag "2_a_3"}
											}
											{tag
												{tag "2_b_3"}
											}
											{tag
												{tag "3_a_3"}
											}
											{tag
												{tag "3_b_3"}
											}
											{tag
												{tag "4_a_3"}
											}
											{tag
												{tag "4_b_3"}
											}
											{tag
												{tag "5_a_3"}
											}
											{tag
												{tag "5_b_3"}
											}
										}
										{include
											{prop
												{prop human}
											}
											
											{tag
												{tag cmp_def}
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
								{var "defense_level$"}
								{op "="}
								{value 3}
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
												{tag flag_point}
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
								}
								{tag_add defense_level_3}
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
												{tag "1_a_2-3"}
											}
											{tag
												{tag "1_b_2-3"}
											}
											{tag
												{tag "2_a_2-3"}
											}
											{tag
												{tag "2_b_2-3"}
											}
											{tag
												{tag "3_a_2-3"}
											}
											{tag
												{tag "3_b_2-3"}
											}
											{tag
												{tag "4_a_2-3"}
											}
											{tag
												{tag "4_b_2-3"}
											}
											{tag
												{tag "5_a_2-3"}
											}
											{tag
												{tag "5_b_2-3"}
											}
										}
										{include
											{prop
												{prop human}
											}
											
											{tag
												{tag cmp_def}
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
								{var "defense_level$"}
								{op "="}
								{value 2}
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
												{tag flag_point}
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
								}
								{tag_add defense_level_2}
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
												{tag "1_a_1-3"}
											}
											{tag
												{tag "1_b_1-3"}
											}
											{tag
												{tag "2_a_1-3"}
											}
											{tag
												{tag "2_b_1-3"}
											}
											{tag
												{tag "3_a_1-3"}
											}
											{tag
												{tag "3_b_1-3"}
											}
											{tag
												{tag "4_a_1-3"}
											}
											{tag
												{tag "4_b_1-3"}
											}
											{tag
												{tag "5_a_1-3"}
											}
											{tag
												{tag "5_b_1-3"}
											}
										}
										{include
											{prop
												{prop human}
											}
											{zone
												{zone "gamezone"}
											}
											{tag
												{tag cmp_def}
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
								{var "defense_level$"}
								{op "="}
								{value 1}
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
												{tag flag_point}
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
								}
								{tag_add defense_level_1}
							}
						}
						{"default"
							{"set_i"
								{var "defense_level$"}
								{op "="}
								{value 1}
							}
						}
					}
				}
			}
			{"conquest_enhanced_mechanics/ai_defenders/spawn_hedgehogs"
				{condition
					{terms
						{"1.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 0}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{zone
											{zone "combat"}
										}
									}
									{include
										{prop
											{prop logic_post}
										}
									}
								}
							}
						}
						{"3.event"
							{id "dcg"}
						}
					}
				}
				{actions
					{"delay"
						{time 15}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "defense_level$"}
								{op ">="}
								{value 3}
							}
							{"effect"
								{selector
									{source advanced}
									{group
										{select
											{zone
												{zone "combat"}
											}
										}
										{include
											{prop
												{prop logic_post}
											}
										}
									}
									{sort
										{type shuffle}
									}
									{amount 20
									}
								}
								{effect spawn_hedgehogs}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "defense_level$"}
								{op "=="}
								{value 2}
							}
							{"effect"
								{selector
									{source advanced}
									{group
										{select
											{zone
												{zone "combat"}
											}
										}
										{include
											{prop
												{prop logic_post}
											}
										}
									}
									{sort
										{type shuffle}
									}
									{amount 12
									}
								}
								{effect spawn_hedgehogs}
							}
						}
						{"default"
							{"effect"
								{selector
									{source advanced}
									{group
										{select
											{zone
												{zone "combat"}
											}
										}
										{include
											{prop
												{prop logic_post}
											}
										}
									}
									{sort
										{type shuffle}
									}
									{amount 8
									}
								}
								{effect spawn_hedgehogs}
							}
						}
					}
				}
			}
			
			{"conquest_enhanced_mechanics/ai_defenders/tag_ai_defenders"
				{condition
					{terms
						{"1.cmp_i"
							{var "id_defenderbot$"}
							{op ">"}
							{value 0}
						}
					}
				}
				{actions
					{"delay"
						{time 10}
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
									{state
										{state "operatable inhabited"}
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
						{tag_add _ai_defender}
					}
					{"event"
						{event "ai_defender_vehicles_tagged"}
						{mode set}
						{delay 0}
					}
				}
			}
			{"conquest_enhanced_mechanics/ai_defenders/balance_ai_veh"
				{condition
					{terms
						{"1.cmp_i"
							{var "defense_level$"}
							{op ">"}
							{value 0}
						}
						{"2.cmp_i"
							{var "id_defenderbot$"}
							{op ">"}
							{value 0}
						}
						{"3.entities"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag _ai_defender}
										}
									}
									{include
										{state
											{state "operatable"}
										}
									}
									{exclude
										{state
											{state inactive}
										}
										{state
											{state dead}
										}
									}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 3}
					}
					{## "effect"
						{selector
							{tag _ai_defender}
							{zone "gamezone"}
							{type tank}
							{state inhabited}
						}
						{effect tag_ai_defender_veh}
					}
					{## "delay"
						{time 5}
					}
					{## "if"
						{condition
							{type cmp_i}
							{var "defense_level$"}
							{op "<<"}
							{value 3}
						}
						{"delete"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _ai_defender}
										}
									}
									{include
										{tag
											{tag stage_3}
										}
										{prop
											{prop vehicle}
										}
										{state
											{state inhabited}
										}
									}
									{exclude
										{state
											{state user_control}
										}
										{state
											{state linked}
										}
									}
								}
							}
						}
					}
					{## "delay"
						{time 0.2}
					}
					{## "if"
						{condition
							{type cmp_i}
							{var "defense_level$"}
							{op "<<"}
							{value 2}
						}
						{"delete"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _ai_defender}
										}
									}
									{include
										{tag
											{tag stage_2}
										}
										{prop
											{prop vehicle}
										}
										{state
											{state inhabited}
										}
									}
									{exclude
										{state
											{state user_control}
										}
										{state
											{state linked}
										}
									}
								}
							}
						}
					}
					{"event"
						{event "emplacement_stage_balancing"}
						{mode set}
						{delay 0}
					}
				}
			}
			{"conquest_enhanced_mechanics/ai_defenders/randomize_emplacements"
				{condition
					{expression "1 & !(2 & 4)"}
					{terms
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag challenge_map}
										}
									}
								}
							}
						}
                        {"4.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 0}
						}
						{"1.event"
							{id "ai_defender_vehicles_tagged"}
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
							{var "user_is_defender$"}
							{op "=="}
							{value 0}
						}
						{"switch"
							{"case"
								{condition
									{type cmp_i}
									{var "defense_level$"}
									{op ">="}
									{value 3}
								}
								{"set_i"
									{var "max_ai_defender_emplacement_total_count$"}
									{op "="}
									{value "max_ai_defender_emplacement_count_level_3$"}
								}
							}
							{"case"
								{condition
									{type cmp_i}
									{var "defense_level$"}
									{op "=="}
									{value 2}
								}
								{"set_i"
									{var "max_ai_defender_emplacement_total_count$"}
									{op "="}
									{value "max_ai_defender_emplacement_count_level_2$"}
								}
							}
							{"default"
								{"set_i"
									{var "max_ai_defender_emplacement_total_count$"}
									{op "="}
									{value "max_ai_defender_emplacement_count_level_1$"}
								}
							}
						}
					}
                    {"if"
						{condition
							{type cmp_i}
							{var "user_is_defender$"}
							{op "=="}
							{value 1}
						}
						{"switch"
							{"case"
								{condition
									{type cmp_i}
									{var "defense_level$"}
									{op ">="}
									{value 3}
								}
                                
                                {"set_i"
									{var "max_ai_defender_emplacement_total_count$"}
									{op "+"}
									{value "6"}
								}
								{"set_i"
									{var "max_ai_defender_emplacement_total_count$"}
									{op "="}
									{value "max_ai_defender_emplacement_total_count$"}
								}
							}
							{"case"
								{condition
									{type cmp_i}
									{var "defense_level$"}
									{op "=="}
									{value 2}
								}
                                
                                {"set_i"
									{var "max_ai_defender_emplacement_total_count$"}
									{op "+"}
									{value "3"}
								}
								{"set_i"
									{var "max_ai_defender_emplacement_total_count$"}
									{op "="}
									{value "max_ai_defender_emplacement_total_count$"}
								}
							}
                            {"default"
								
                                {"set_i"
									{var "max_ai_defender_emplacement_total_count$"}
									{op "="}
									{value "max_ai_defender_emplacement_total_count$"}
								}
							}
							
						}
					}
					{"delay"
						{time 1}
					}
                    
					{"while"
						{condition
							{type entities}
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
											{state inhabited}
										}
										{prop
											{prop vehicle}
										}
										{tag
											{tag _ai_defender}
										}
									}
									{exclude
										{state
											{state linked}
										}
										{state
											{state user_control}
										}
										{tag
											{tag hidden}
										}
										{prop
											{prop airborne}
										}
									}
								}
							}
							{count
								{op ">"}
								{value "max_ai_defender_emplacement_total_count$"}
							}
						}
						{"delay"
							{time 0.2}
						}
						{"delete"
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
											{state inhabited}
										}
										{tag
											{tag _ai_defender}
										}
									}
									{exclude
										
										{state
											{state user_control}
										}
										{tag
											{tag hidden}
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
						{"delay"
							{time 0.2}
						}
					}
				}
			}
			{"conquest_enhanced_mechanics/ai_defenders/delete_bazookas_for_def_level_1"
				{condition
					{terms
						{"1.inventory"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag cmp_def}
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
										{tag
											{tag bot}
										}
										{state
											{state user_control}
										}
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
									}
								}
							}
							{where "all holders"}
							{item "rocketlauncher"}
							{compare equal}
							{amount 1}
						}
						{"10.cmp_i"
							{var "defense_level$"}
							{op "=="}
							{value 1}
						}
					}
				}
				{actions
					{"delay"
						{time 5}
					}
					{"select"
						{source advanced}
						{group
							{select
								{tag
									{tag cmp_def}
								}
							}
							{include
								{with_item
									{type amount}
									{item "rocketlauncher"}
									{min 1}
								}
                                {state
									{state operatable}
								}
								{prop
									{prop human}
								}
							}
                            {exclude
								{tag
									{tag bot}
								}
								{state
									{state user_control}
								}
                                {state
									{state linked}
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
						{weapon_prepare off}
					}
					{"delay"
						{time 3}
					}
					{"inventory"
						{selector
							{source current}
						}
						{action remove}
						{item "rocketlauncher"}
						{amount 7}
					}
				}
			}
			
            {"conquest_enhanced_mechanics/challenge_map_defend_info"
				{condition
					{terms
						{"1.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 1}
						}
                        {"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag challenge_map}
										}
									}
									
								}
							}
						}
                    }
				}
				{actions
					{"delay"
						{time 25}
					}
					{"timer"
						{time 65}
						{title "This is a defense challenge map. AI will spawn from the side you spawned in. This message will dissappear in:"}
					}
				}
            }
            {"conquest_enhanced_mechanics/challenge_map_attack_info"
				{condition
					{terms
						{"1.cmp_i"
							{var "id_defenderbot$"}
							{op ">"}
							{value 0}
						}
                        {"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag challenge_map}
										}
									}
									
								}
							}
						}
                        {"3.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 0}
						}
                    }
				}
				{actions
					{"delay"
						{time 25}
					}
                    {"timer"
						{time 35}
						{title "This is an attack challenge map. AI will not have reinforcements..."}
					}
					
				}
			}
			{"conquest_enhanced_mechanics/delete_mines"
				{condition
					{terms
						{"1.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 1}
						}
                    }
                }
                {actions
					{"delay"
						{time 0.1}
					}
					{"delete"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag mine_planted}
									}
									{tag
										{tag dcg_mine_sign}
									}
								}
								{include
									{tag
										{tag cmp_def}
									}
								}
							}
						}
					}
				}
            }
            {"conquest_enhanced_mechanics/check_the_number_of_aa"
				{condition
					{terms
						{"1.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 1}
						}
                        
                    }
				}
				{actions
					{"delay"
						{time 600}
					}
					{"if"
						{condition
							{type entities}
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
											{prop c_aa_hvy}
										}
										{state
											{state operatable}
										}
										{state
											{state user_control}
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
											{prop c_aa_med}
										}
										{state
											{state operatable}
										}
										{state
											{state user_control}
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
											{prop c_aa_lite}
										}
										{state
											{state operatable}
										}
										{state
											{state user_control}
										}
									}
								}
							}
							{count
								{op "<<"}
								{value 1}
							}
						}
						{## "timer"
							{time 11}
							{title ""}
						}
						{"entity_state"
							{selector
								{tag scene_variable}
							}
							{tag_add nub_no_aa}
						}
						{"delay"
							{time 90}
						}
						{"entity_state"
							{selector
								{tag scene_variable}
							}
							{tag_remove nub_no_aa}
						}
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
						{"2.event"
							{id "enable_ai_attack_logic"}
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
			{"conquest_enhanced_mechanics/call_defense_crates"
				{condition
					{terms
						{"3.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag defense_level_3}
										}
										{tag
											{tag defense_level_2}
										}
									}
									{include
										{tag
											{tag player_defending}
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
											{tag flag_point}
										}
									}
									{exclude
										{state
											{state inactive}
										}
									}
								}
						}
						{effect call_flag_defense_crates}
					}
				}
			}
            {## "1april"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag cow}
										}
									}
									{include
										{relation
											{relation ally}
											{player "1"}
										}
									}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 20}
					}
					{"switch"
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"talk"
								{selector
									{tag cow}
									{state operatable}
								}
								{text "mission/multi/cowtalk1"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"talk"
								{selector
									{tag cow}
									{state operatable}
								}
								{text "mission/multi/cowtalk2"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"talk"
								{selector
									{tag cow}
									{state operatable}
								}
								{text "mission/multi/cowtalk3"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"talk"
								{selector
									{tag cow}
									{state operatable}
								}
								{text "mission/multi/cowtalk4"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"talk"
								{selector
									{tag cow}
									{state operatable}
								}
								{text "mission/multi/cowtalk5"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"talk"
								{selector
									{tag cow}
									{state operatable}
								}
								{text "mission/multi/cowtalk6"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"talk"
								{selector
									{tag cow}
									{state operatable}
								}
								{text "mission/multi/cowtalk7"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"talk"
								{selector
									{tag cow}
									{state operatable}
								}
								{text "mission/multi/cowtalk8"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"talk"
								{selector
									{tag cow}
									{state operatable}
								}
								{text "mission/multi/cowtalk9"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"talk"
								{selector
									{tag cow}
									{state operatable}
								}
								{text "mission/multi/cowtalk10"}
							}
						}
					}
					{"delay"
						{time 40}
					}
					{"trigger"
						{name "1april"}
					}
				}
			}