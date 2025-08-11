;============ AUTO MEDIC SCRIPTS========================================
			{## "player_logic/tag_player_medic"
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
											{state "operatable user_control"}
										}
										{prop
											{prop human}
										}
										{with_item
											{type existance}
											{item "tent_kit"}
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
											{tag medic}
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
									{state
										{state "operatable user_control"}
									}
									{with_item
										{type existance}
										{item "tent_kit"}
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
										{tag medic}
									}
								}
							}
						}
						{tag_add medic}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "player_logic/tag_player_medic"}
					}
				}
			}
			{## "player_logic/auto_medic_revive"
				{condition
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag auto_medic}
										}
									}
									{include
										{state
											{state user_control}
										}
										{prop
											{prop human}
										}
										{tag
											{tag player}
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
										{tag
											{tag hidden}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag healing}
										}
										{state
											{state inactive}
										}
										{tag
											{tag ignore_auto_medic}
										}
										{tag
											{tag move_to_auto_healing_zone}
										}
										{tag
											{tag _bleedout_}
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
											{tag bleeding}
										}
									}
									{include
										{state
											{state user_control}
										}
										{prop
											{prop human}
										}
										{tag
											{tag player}
										}
									}
									{exclude
										{state
											{state linked}
										}
										{tag
											{tag medic_patient}
										}
										{tag
											{tag ignore_auto_medic}
										}
										{state
											{state inactive}
										}
									}
								}
								{amount 1
								}
							}
							{distance
								{mode near_than}
								{meters 50}
							}
							{detection located}
							{tag
								{"tag pair"}
								{"for selector" medic_action_revive}
								{"for enemy" medic_patient}
							}
						}
						{"2.event"
							{id "dcg"}
						}
						{"3.event"
							{id "init2"}
						}
					}
				}
				{actions
					{"delay"
						{time 0.5}
					}
					{"call"
						{function "send_auto_medic_to_heal"}
						{context
							{specified}
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag medic_action_revive}
										}
									}
									{include
										{prop
											{prop human}
										}
										{tag
											{tag player}
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
											{state linked}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag healing}
										}
										{tag
											{tag ignore_auto_medic}
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
					}
					{"delay"
						{time 3}
					}
					{"trigger"
						{name "player_logic/auto_medic_revive"}
					}
				}
			}
			{## "player_logic/send_medics_to_location_for_reviving"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag medic_pointer}
										}
									}
									{exclude
										{tag
											{tag ignore_pointer}
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
					{"talk"
						{selector
							{amount 1
							}
							{tag medic}
							{type human}
							{state operatable}
						}
						{text "mission/multi/goingheal"}
					}
					{"loop" 3
						{"delay"
							{time 0.5}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag bleeding}
											}
										}
										{include
											{state
												{state user_control}
											}
											{prop
												{prop human}
											}
											{tag
												{tag player}
											}
										}
										{exclude
											{state
												{state linked}
											}
											{tag
												{tag medic_patient}
											}
											{tag
												{tag ignore_auto_medic}
											}
											{tag
												{tag _bleedout_}
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
												{tag medic}
											}
										}
										{include
											{state
												{state user_control}
											}
											{prop
												{prop human}
											}
											{tag
												{tag player}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state linked}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag bleeding}
											}
											{tag
												{tag healing}
											}
											{state
												{state inactive}
											}
											{tag
												{tag ignore_auto_medic}
											}
											{tag
												{tag _bleedout_}
											}
											{tag
												{tag move_to_auto_healing_zone}
											}
										}
									}
									{amount 1
									}
									{sort
										{type entity}
										{entity
											{source advanced}
											{group
												{select
													{tag
														{tag medic_pointer}
													}
												}
												{exclude
													{tag
														{tag ignore_pointer}
													}
												}
											}
										}
									}
								}
								{tag_add medic_action_revive}
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
												{tag bleeding}
											}
										}
										{include
											{state
												{state user_control}
											}
											{prop
												{prop human}
											}
											{tag
												{tag player}
											}
										}
										{exclude
											{state
												{state linked}
											}
											{tag
												{tag medic_patient}
											}
											{tag
												{tag ignore_auto_medic}
											}
											{tag
												{tag _bleedout_}
											}
										}
									}
									{amount 1
									}
									{sort
										{type entity}
										{entity
											{source advanced}
											{group
												{select
													{tag
														{tag medic_pointer}
													}
												}
												{exclude
													{tag
														{tag ignore_pointer}
													}
												}
											}
										}
									}
								}
								{tag_add medic_patient}
							}
							{"delay"
								{time 1}
							}
							{"call"
								{function "send_auto_medic_to_heal"}
								{context
									{specified}
									{selector
										{source advanced}
										{group
											{select
												{tag
													{tag medic_action_revive}
												}
											}
											{include
												{prop
													{prop human}
												}
												{tag
													{tag player}
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
													{state linked}
												}
												{tag
													{tag bleeding}
												}
												{tag
													{tag healing}
												}
												{tag
													{tag ignore_auto_medic}
												}
												{state
													{state inactive}
												}
												{tag
													{tag _bleedout_}
												}
											}
										}
										{amount 1
										}
									}
								}
							}
							{"delay"
								{time 2}
							}
						}
					}
					{"delay"
						{time 2}
					}
					{"trigger"
						{name "player_logic/send_medics_to_location_for_reviving"}
					}
				}
			}
			
;============ AUTO RESUPPLY SCRIPTS========================================
			{"player_logic/auto_resupply"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.near"
							{units
								{source advanced}
								{group
									{select
										{tag
											{tag no_ammo}
										}
									}
									{include
										{tag
											{tag player}
										}
										{state
											{state user_control}
										}
										{prop
											{prop human}
										}
										{tag
											{tag auto_resupply}
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
											{tag ignore_auto_resupply}
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
								{amount 1
								}
							}
							{distance 120}
						}
						{"2.trigger"
							{name "player_logic/send_men_with_no_ammo_to_resupply"}
						}
					}
				}
				{actions
					{"delay"
						{time 0.5}
					}
					{"call"
						{function "send_auto_resupply"}
						{context
							{specified}
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag no_ammo}
										}
									}
									{include
										{tag
											{tag player}
										}
										{state
											{state user_control}
										}
										{prop
											{prop human}
										}
										{tag
											{tag auto_resupply}
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
											{tag ignore_auto_resupply}
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
									}
								}
								{amount 1
								}
							}
						}
					}
					{"delay"
						{time 4}
					}
					{"trigger"
						{name "player_logic/auto_resupply"}
					}
				}
			}
			{"player_logic/send_men_with_no_ammo_to_resupply"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag resupply_pointer}
										}
									}
								}
							}
						}
						{"2.trigger"
							{name "player_logic/auto_resupply"}
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
								{type rand}
								{value 0.33}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag player}
									{type human}
									{state operatable}
								}
								{text "mission/multi/request_supply_drop_1"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.33}
							}
							{"talk"
								{selector
									{amount 1
									}
									{tag player}
									{type human}
									{state operatable}
								}
								{text "mission/multi/request_supply_drop_2"}
							}
						}
						{"default"
							{"talk"
								{selector
									{amount 1
									}
									{tag player}
									{type human}
									{state operatable}
								}
								{text "mission/multi/request_supply_drop_3"}
							}
						}
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
										{tag no_ammo}
									}
								}
								{include
									{tag
										{tag player}
									}
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
									{tag
										{tag ignore_auto_resupply}
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
											{state
												{state dead}
											}
										}
									}
								}
							}
							{amount 5
							}
						}
						{effect set_auto_resupply}
					}
					{"delay"
						{time 1}
					}
					{"loop" 5
						{"call"
							{function "send_auto_resupply"}
							{context
								{specified}
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag no_ammo}
											}
										}
										{include
											{tag
												{tag player}
											}
											{state
												{state user_control}
											}
											{prop
												{prop human}
											}
											{tag
												{tag auto_resupply}
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
												{tag ignore_auto_resupply}
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
													{state
														{state dead}
													}
												}
											}
										}
									}
									{amount 1
									}
								}
							}
						}
						{"delay"
							{time 4}
						}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "player_logic/send_men_with_no_ammo_to_resupply"}
					}
				}
			}

;============ Vehicle SCRIPTS========================================
			{"player_logic/enable_slow_move"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag set_slow_move}
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
										{state
											{state linked}
										}
										{tag
											{tag slow_move_activated}
										}
									}
								}
							}
						}
						{"2.trigger"
							{name "player_logic/disable_slow_move"}
						}
					}
				}
				{actions
					{"delay"
						{time 0.2}
					}
					{"select"
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select
								{tag
									{tag set_slow_move}
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
								{state
									{state linked}
								}
								{tag
									{tag slow_move_activated}
								}
							}
						}
						{amount 1
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
							{speed slow}
							{kind slow}
						}
					}
					{"delay"
						{time 0.2}
					}
					{"effect"
						{selector
							{source current}
						}
						{effect process_slow_move_tags}
					}
					{"delay"
						{time 0.2}
					}
					{"trigger"
						{name "player_logic/enable_slow_move"}
					}
				}
			}
			{"player_logic/disable_slow_move"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag set_remove_slow_move_tag}
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
										{state
											{state linked}
										}
										{tag
											{tag set_slow_move}
										}
									}
								}
							}
						}
						{"2.trigger"
							{name "player_logic/enable_slow_move"}
						}
					}
				}
				{actions
					{"delay"
						{time 0.2}
					}
					{"select"
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select
								{tag
									{tag set_remove_slow_move_tag}
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
								{state
									{state linked}
								}
								{tag
									{tag set_slow_move}
								}
							}
						}
						{amount 1
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
						{time 0.2}
					}
					{"effect"
						{selector
							{source current}
						}
						{effect process_slow_move_tags}
					}
					{"delay"
						{time 0.2}
					}
					{"trigger"
						{name "player_logic/disable_slow_move"}
					}
				}
			}

;============ Air SCRIPTS========================================
			{"player_logic/air/move_player_planes_offmap"
				{condition
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
										{tag
											{tag move_to_start_waypoint}
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
										{tag
											{tag player_drop_plane_moving_to_start}
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
										{state inhabited}
									}
									{tag
										{tag move_to_start_waypoint}
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
									{tag
										{tag player_drop_plane_moving_to_start}
									}
								}
							}
						}
						{tag_add player_drop_plane_moving_to_start}
						{impregnability full}
					}
					{"delay"
						{time 0.5}
					}
					{"select"
						{tag player_drop_plane_moving_to_start}
						{type vehicle}
						{state inhabited}
					}
					{"delay"
						{time 0.5}
					}
					{"air_state"
						{selector
							{source current}
						}
						{drop orders}
						{altitude 45}
					}
					{"delay"
						{time 0.5}
					}
					{"actor_to_waypoint"
						{selector
							{source current}
						}
						{waypoint "3000"}
						{approach "safe teleport & rotate"}
					}
					{"delay"
						{time 0.5}
					}
					{"select"
						{tag player_drop_plane_moving_to_start}
						{type vehicle}
						{state inhabited}
					}
					{"delay"
						{time 0.5}
					}
					{"effect"
						{selector
							{source current}
						}
						{effect move_plane_to_initial_waypoint}
					}
					{"delay"
						{time 0.5}
					}
					{"trigger"
						{name "player_logic/air/move_player_planes_offmap"}
					}
				}
			}
			{"player_logic/air/send_player_drop_plane"
				{condition
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
										{tag
											{tag ready_to_move}
										}
										{state
											{state inhabited}
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
											{tag move_to_start_waypoint}
										}
									}
								}
							}
						}
						{"2.event"
							{id "air_raid_start"}
						}
					}
				}
				{actions
					{"delay"
						{time 0.5}
					}
					{"select"
						{source advanced}
						{ignore_captured_by_user 0}
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
								{tag
									{tag ready_to_move}
								}
								{state
									{state inhabited}
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
									{tag move_to_start_waypoint}
								}
								{zone
									{zone "gamezone"}
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
						{effect prep_drop_plane_to_move}
					}
					{"delay"
						{time 0.2}
					}
					{"select"
						{source advanced}
						{group
							{select
								{tag
									{tag moving_to_drop_zone}
								}
							}
							{include
								{prop
									{prop drop_plane}
								}
								{state
									{state user_control}
								}
								{tag
									{tag user_plane}
								}
								{state
									{state inhabited}
								}
							}
							{exclude
								{state
									{state linked}
								}
								{tag
									{tag dropping_troopers}
								}
								{prop
									{prop ai}
								}
								{state
									{state inactive}
								}
								{zone
									{zone "gamezone"}
								}
							}
						}
						{amount 1
						}
					}
					{## "delay"
						{time 0.2}
					}
					{## "air_state"
						{selector
							{source current}
						}
						{drop orders}
						{altitude 45}
					}
					{"delay"
						{time 0.2}
					}
					{"switch"
						{"case"
							{condition
								{type rand}
								{value 0.33}
							}
							{"air_attack"
								{selector
									{source current}
								}
								{drop orders}
								{enemies
									{amount 1
									}
									{tag drop_zone}
									{zone "gamezone"}
								}
								{move_from_back}
								{force_placement}
								{random_weapon 0}
								{attack_altitude 43}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.33}
							}
							{"air_attack"
								{selector
									{source current}
								}
								{drop orders}
								{enemies
									{amount 1
									}
									{tag drop_zone}
									{zone "gamezone"}
								}
								{move_from_back}
								{force_placement}
								{random_weapon 0}
								{attack_altitude 46}
							}
						}
						{"default"
							{"air_attack"
								{selector
									{source current}
								}
								{drop orders}
								{enemies
									{amount 1
									}
									{tag drop_zone}
									{zone "gamezone"}
								}
								{move_from_back}
								{force_placement}
								{random_weapon 0}
								{attack_altitude 40}
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
						{tag_remove moving_to_drop_zone}
						{impregnability disabled}
					}
					{"delay"
						{time 2}
					}
					{"trigger"
						{name "player_logic/air/send_player_drop_plane"}
					}
				}
			}
			{"player_logic/air/player_jump_prepare_emote"
				{condition
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
											{state "inhabited user_control"}
										}
										{prop
											{prop drop_plane}
										}
										{zone
											{zone "gamezone"}
										}
										{tag
											{tag on_mission}
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
					}
				}
				{actions			
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
											{zone
												{zone "gamezone"}
											}
										}
										{include
											{state
												{state "linked user_control"}
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
									{amount 1
									}
								}
								{text "mission/multi/player_paratrooper_prepare_to_jump"}
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
											{zone
												{zone "gamezone"}
											}
										}
										{include
											{state
												{state "linked user_control"}
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
									{amount 1
									}
								}
								{text "mission/multi/player_paratrooper_prepare_to_jump_02"}
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
												{state "linked user_control"}
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
									{amount 1
									}
								}
								{text "mission/multi/player_paratrooper_prepare_to_jump_03"}
							}
						}
					}
				}
			}
			{"player_logic/air/player_jump_emote"
				{condition
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
											{state "inhabited user_control"}
										}
										{prop
											{prop drop_plane}
										}
										{zone
											{zone "gamezone"}
										}
										{tag
											{tag dropping_troopers}
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
											{tag green_light}
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
								{value 0.33}
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
												{state "linked user_control"}
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
									{amount 1
									}
								}
								{text "mission/multi/player_paratrooper_jump_02"}
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
											{zone
												{zone "gamezone"}
											}
										}
										{include
											{state
												{state "linked user_control"}
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
									{amount 1
									}
								}
								{text "mission/multi/player_paratrooper_jump_03"}
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
												{state "linked user_control"}
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
									{amount 1
									}
								}
								{text "mission/multi/player_paratrooper_jump"}
							}
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
										{tag dropping_troopers}
									}
								}
								{include
									{prop
										{prop drop_plane}
									}
									{state
										{state "inhabited user_control"}
									}
									{zone
										{zone "gamezone"}
									}
									{tag
										{tag user_plane}
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
										{tag green_light}
									}
								}
							}
							{amount 1
							}
						}
						{tag_add green_light}
					}
					{"delay"
						{time 0.2}
					}
					{"trigger"
						{name "player_logic/air/player_jump_emote"}
					}
				}
			}
			{"player_logic/air/enable_player_drop_plane_select"
				{condition
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
							{value 0}
						}
					}
				}
				{actions
					{"delay"
						{time 0.2}
					}
					{"ables"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
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
										{state "operatable user_control"}
									}
								}
								{exclude
									{state
										{state linked}
									}
									{state
										{state inactive}
									}
								}
							}
						}
						{add select}
					}
					{"delay"
						{time 0.2}
					}
					{"trigger"
						{name "player_logic/air/enable_player_drop_plane_select"}
					}
				}
			}

;============ Teleport ==========
            {"player_scripts/move_player_spawn"
				{condition
					{expression "1 & 2 & !3 & 4"}
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
										{state
											{state user_control}
										}
									}
									{exclude
										{state
											{state inactive}
										}
										{state
											{state dead}
										}
										{state
											{state linked}
										}
									}
								}
							}
						}
						{"2.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 1}
						}
						{"3.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag bot}
										}
										{tag
											{tag bot_tank}
										}
										{tag
											{tag bot_car}
										}
										{tag
											{tag bot_veh}
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
											{state user_control}
										}
										{state
											{state inactive}
										}
										{state
											{state dead}
										}
										{state
											{state linked}
										}
									}
								}
							}
						}
						{"4.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag pointer_defend}
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
				}
				{actions
					{"delay"
						{time 3}
					}
					{"talk"
						{selector
							{source advanced}
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
								}
								{exclude
									{state
										{state dead}
									}
								}
							}
							{amount 1
							}
						}
						{text "mission/multi/teleporting_player_defense_units"}
					}
					{"delay"
						{time 5}
					}
					{"actor_to_waypoint"
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
										{state user_control operatable}
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
						{waypoint "6666"}
						{approach "safe teleport & rotate"}
					}
				}
			}
			
			
;============ DEFENSE START SCRIPTS ==========
			{"player_logic/inform_defense_end"
				{condition
					{expression "1"}
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
						{time 1800}
					}
					{"talk"
						{selector
							{amount 1
							}
							{tag player}
							{state "not dead"}
						}
						{text "mission/multi/pointmessage"}
					}
					{"delay"
						{time 200}
					}

					{"talk"
						{selector
							{amount 1
							}
							{tag player}
							{state "not dead"}
						}
						{text "mission/multi/pointmessage"}
					}
                    {"delay"
						{time 200}
					}

					{"talk"
						{selector
							{amount 1
							}
							{tag player}
							{state "not dead"}
						}
						{text "mission/multi/pointmessage"}
					}
                    {"delay"
						{time 200}
					}

					{"talk"
						{selector
							{amount 1
							}
							{tag player}
							{state "not dead"}
						}
						{text "mission/multi/pointmessage"}
					}
                    {"delay"
						{time 200}
					}

					{"talk"
						{selector
							{amount 1
							}
							{tag player}
							{state "not dead"}
						}
						{text "mission/multi/pointmessage"}
					}
                    {"delay"
						{time 200}
					}

					{"talk"
						{selector
							{amount 1
							}
							{tag player}
							{state "not dead"}
						}
						{text "mission/multi/pointmessage"}
					}
                    {"delay"
						{time 200}
					}

					{"talk"
						{selector
							{amount 1
							}
							{tag player}
							{state "not dead"}
						}
						{text "mission/multi/pointmessage"}
					}
                    {"delay"
						{time 200}
					}

					{"talk"
						{selector
							{amount 1
							}
							{tag player}
							{state "not dead"}
						}
						{text "mission/multi/pointmessage"}
					}
				}
			}
			{"player_logic/inform_early_attack_option"
				{condition
					{expression "1"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag player}
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
						{time 60}
					}
					{"if"
						{condition
							{type entities}
							{selector
								{tag defense_mission_started}
							}
							{count
								{op "<<"}
								{value 0}
							}
						}
						{"talk"
							{selector
								{amount 1
								}
								{tag player}
								{state "not dead"}
							}
							{text "mission/multi/defense_start_early_option"}
						}
					}
					{"delay"
						{time 300}
					}
					{"if"
						{condition
							{type entities}
							{selector
								{tag defense_mission_started}
							}
							{count
								{op "<<"}
								{value 0}
							}
						}
						{"talk"
							{selector
								{amount 1
								}
								{tag player}
								{state "not dead"}
							}
							{text "mission/multi/defense_start_early_option"}
						}
					}
				}
			}
			{"player_logic/start_defense_early"
				{condition
					{expression "1 & 2 & 3 & !4"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag start_defense}
										}
									}
								}
							}
						}
						{"2.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 1}
						}
						{"3.event"
							{id "attack_or_defend_mission_set"}
						}
						{"4.entities"
							{selector
								{source advanced}
								{group
									{select
										{zone
											{zone "gamezone"}
										}
									}
									{include
										{tag
											{tag bot}
										}
										{prop
											{prop human}
										}
										{state
											{state operatable}
										}
									}
									{exclude
										{player
											{player "1"}
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
						{time 0.5}
					}
					{"talk"
						{selector
							{amount 1
							}
							{zone "gamezone"}
							{type human}
							{state operatable}
						}
						{text "mission/multi/start_player_defense_ask"}
					}
					{"timer"
						{time 12}
						{title "mission/multi/defense_started_timer"}
					}
					{"delay"
						{time 12}
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
												{tag start_defense}
											}
										}
									}
								}
							}
                            {"entity_state"
                                {selector
                                    {tag scene_variable}
                                }
                                {tag_add _lua_start_defense_mission}
                            }
							{"talk"
								{selector
									{amount 1
									}
									{zone "gamezone"}
									{type human}
									{state operatable}
								}								
								{text "mission/multi/start_player_defense_confirm"}
							}
                            {"delay"
                                {time 60}
                            }
                            {"entity_state"
                                {selector
                                    {tag scene_variable}
                                }
                                {tag_add defense_mission_started}
                                {tag_remove _lua_start_defense_mission}
                            }
						}
						{"default"
							{"trigger"
								{name "player_logic/start_defense_early"}
							}
						}
					}
				}
			}
            
;============ CHANGE WEATHER SCRIPTS ==========            
            {"player_scripts/change_weather"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag pointer_going}
										}
									}
								}
							}
						}
					}
				}
				{actions
					{"timer"
						{time 10}
						{title "Change weather cooldown"}
					}
					{"switch"
						(include "weather_cases.inc")
					}
					{"delay"
						{time 10}
					}
					{"trigger"
						{name "player_scripts/change_weather"}
					}
				}
			}
            {"player_scripts/allied_infantry"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag ally_infantry_mark}
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
										{tag player}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop human}
									}
                                    {zone
											{zone "gamezone"}
										}
                                        {state
											{state user_control}
										}
								}
								{exclude
									{state
										{state inhabited}
									}
									{tag
										{tag _user_ally}
									}
                                    {tag
										{tag medic}
									}
                                    {tag
										{tag tankman}
									}
                                    {tag
										{tag _def}
									}
                                    {state
										{state linked}
									}
                                    
								}
							}
                            
						}
						{tag_add cloneme}
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
										{tag cloneme}
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
										{state inhabited}
									}
									{tag
										{tag _user_ally}
									}
								}
							}
						}
						{tag_add hidden}
						{inactive on}
					}
					{"delay"
						{time 0.2}
					}
                    {## "if"
						{condition
                            {type entities}
                                {selector
                                {tag challenge_map}
                            }
                        }
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme}
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
											{state
												{state linked}
											}
										}
									}
	                                {amount 5
									}
								}
							}
							{action
								{type start}
								{waypoint "1003"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
	                    {"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme}
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
											{state
												{state linked}
											}
										}
									}
	                                {amount 5
									}
								}
							}
							{action
								{type start}
								{waypoint "1002"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
	                    {"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme}
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
											{state
												{state linked}
											}
										}
									}
	                                {amount 5
									}
								}
							}
							{action
								{type start}
								{waypoint "1001"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
	                    {"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme}
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
											{state
												{state linked}
											}
										}
									}
	                                {amount 5
									}
								}
							}
							{action
								{type start}
								{waypoint "1004"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "bots_spawnside$"}
								{op "=="}
								{value 2}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
		                                {amount 5
										}
									}
								}
								{action
									{type start}
									{waypoint "1003"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
		                    {"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
		                                {amount 5
										}
									}
								}
								{action
									{type start}
									{waypoint "1002"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
		                    {"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
		                                {amount 5
										}
									}
								}
								{action
									{type start}
									{waypoint "1001"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
		                    {"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
		                                {amount 5
										}
									}
								}
								{action
									{type start}
									{waypoint "1004"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
						}
						{"default"
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
		                                {amount 5
										}
									}
								}
								{action
									{type start}
									{waypoint "2003"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
		                    {"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
		                                {amount 5
										}
									}
								}
								{action
									{type start}
									{waypoint "2004"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
		                    {"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
		                                {amount 5
										}
									}
								}
								{action
									{type start}
									{waypoint "2002"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
		                    {"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
		                                {amount 5
										}
									}
								}
								{action
									{type start}
									{waypoint "2001"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
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
										{tag cloneme}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop human}
									}
                                    {state
										{state user_control}
									}
								}
								{exclude
									{state
										{state inhabited}
									}
                                    {state
										{state linked}
									}
									{tag
										{tag hidden}
									}
									{tag
										{tag _user_ally}
									}
                                    {tag
										{tag _def}
									}
                                    {tag
										{tag medic}
									}
								}
							}
						}
						{tag_add _user_ally}
					}
                    
					{"ables"
						{selector
							{tag _user_ally}
						}
						{remove "select personage"}
					}
					{"delay"
						{time 0.1}
					}
                    {"actor_state"
						{selector
							{tag _user_ally}
							{state operatable}
						}
						{control AI}
						{fire_mode open}
						{move_mode free}
						{weapon_prepare on}
						
						{movement
							{speed assault}
						}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag hidden}
									}
								}
								{include
									{tag
										{tag player}
									}
									{prop
										{prop human}
									}
								}
							}
						}
						{tag_remove hidden}
						{inactive off}
					}
                    {"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag cloneme}
									}
								}
								{include
									{tag
										{tag player}
									}
									{prop
										{prop human}
									}
								}
							}
						}
						{tag_remove cloneme}
					}
                    {"delay"
						{time 0.2}
					}
					{"action"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag player}
									}
								}
								{include
									{state
										{state operatable}
									}
								}
								{exclude
									{tag
										{tag engaged}
									}
                                    {tag
										{tag _def}
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
                        {drop orders}
						{action advance}
						{target
							{tag ally_infantry_mark}
						}
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
										{tag  _user_ally}
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
										{state inhabited}
									}
									{tag
										{tag hidden}
									}
									
                                    {tag
										{tag engaged}
									}
								}
							}
						}
						{tag_add engaged}
					}
                    {"delay"
						{time 1}
					}
					{"trigger"
						{name "player_scripts/allied_infantry"}
					}
				}
			}
            {## "player_scripts/allied_tanks"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag ally_infantry_mark}
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
                    {"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag player_armor}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop tank}
									}
                                    {zone
											{zone "gamezone"}
										}
								}
								{exclude
									{tag
											{tag radio_car}
										}
									{tag
										{tag _user_ally2}
									}
								}
							}
                            
						}
						{tag_add cloneme2}
					}
                    {"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag cloneme2}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop tank}
									}
								}
								{exclude
									
									{tag
										{tag _user_ally2}
									}
								}
							}
						}
						{tag_add hidden}
						{inactive on}
					}
					{"delay"
						{time 0.1}
					}
                    {"if"
						{condition
                                        {type entities}
                                            {selector
                                            {tag challenge_map}
                                        }
                                    }
						{"waypoint"
						{who
							{type actor}
							{actors
								{source advanced}
								{group
									{select
										{tag
											{tag cloneme2}
										}
									}
									{include
										{prop
											{prop tank}
										}
                                        {tag
										{tag hidden}
									}
									}
									
								}
                                {amount 1
								}
							}
						}
						{action
							{type start}
							{waypoint "1003"}
							{clone}
							{approach "safe teleport & rotate"}
						}
					}
                    {"waypoint"
						{who
							{type actor}
							{actors
								{source advanced}
								{group
									{select
										{tag
											{tag cloneme2}
										}
									}
									{include
										{prop
											{prop tank}
										}
                                        {tag
										{tag hidden}
									}
									}
									
								}
                                {amount 1
								}
							}
						}
						{action
							{type start}
							{waypoint "1002"}
							{clone}
							{approach "safe teleport & rotate"}
						}
					}
                    {"waypoint"
						{who
							{type actor}
							{actors
								{source advanced}
								{group
									{select
										{tag
											{tag cloneme2}
										}
									}
									{include
										{prop
											{prop tank}
										}
                                        {tag
										{tag hidden}
									}
									}
									
								}
                                {amount 1
								}
							}
						}
						{action
							{type start}
							{waypoint "1001"}
							{clone}
							{approach "safe teleport & rotate"}
						}
					}
                    {"waypoint"
						{who
							{type actor}
							{actors
								{source advanced}
								{group
									{select
										{tag
											{tag cloneme2}
										}
									}
									{include
										{prop
											{prop tank}
										}
                                        {tag
										{tag hidden}
									}
									}
									
								}
                                {amount 1
								}
							}
						}
						{action
							{type start}
							{waypoint "1004"}
							{clone}
							{approach "safe teleport & rotate"}
						}
					}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "bots_spawnside$"}
								{op "=="}
								{value 2}
							}
							{"waypoint"
						{who
							{type actor}
							{actors
								{source advanced}
								{group
									{select
										{tag
											{tag cloneme2}
										}
									}
									{include
										{prop
											{prop tank}
										}
                                        {tag
										{tag hidden}
									}
									}
									
								}
                                {amount 1
								}
							}
						}
						{action
							{type start}
							{waypoint "1003"}
							{clone}
							{approach "safe teleport & rotate"}
						}
					}
                    {"waypoint"
						{who
							{type actor}
							{actors
								{source advanced}
								{group
									{select
										{tag
											{tag cloneme2}
										}
									}
									{include
										{prop
											{prop tank}
										}
                                        {tag
										{tag hidden}
									}
									}
									
								}
                                {amount 1
								}
							}
						}
						{action
							{type start}
							{waypoint "1002"}
							{clone}
							{approach "safe teleport & rotate"}
						}
					}
                    {"waypoint"
						{who
							{type actor}
							{actors
								{source advanced}
								{group
									{select
										{tag
											{tag cloneme2}
										}
									}
									{include
										{prop
											{prop tank}
										}
                                        {tag
										{tag hidden}
									}
									}
									
								}
                                {amount 1
								}
							}
						}
						{action
							{type start}
							{waypoint "1001"}
							{clone}
							{approach "safe teleport & rotate"}
						}
					}
                    {"waypoint"
						{who
							{type actor}
							{actors
								{source advanced}
								{group
									{select
										{tag
											{tag cloneme2}
										}
									}
									{include
										{prop
											{prop tank}
										}
                                        {tag
										{tag hidden}
									}
									}
									
								}
                                {amount 1
								}
							}
						}
						{action
							{type start}
							{waypoint "1004"}
							{clone}
							{approach "safe teleport & rotate"}
						}
					}
						}
						{"default"
							{"waypoint"
						{who
							{type actor}
							{actors
								{source advanced}
								{group
									{select
										{tag
											{tag cloneme2}
										}
									}
									{include
										{prop
											{prop tank}
										}
                                        {tag
										{tag hidden}
									}
									}
									
								}
                                {amount 1
								}
							}
						}
						{action
							{type start}
							{waypoint "2003"}
							{clone}
							{approach "safe teleport & rotate"}
						}
					}
                    {"waypoint"
						{who
							{type actor}
							{actors
								{source advanced}
								{group
									{select
										{tag
											{tag cloneme2}
										}
									}
									{include
										{prop
											{prop tank}
										}
                                        {tag
										{tag hidden}
									}
									}
									
								}
                                {amount 1
								}
							}
						}
						{action
							{type start}
							{waypoint "2004"}
							{clone}
							{approach "safe teleport & rotate"}
						}
					}
                    {"waypoint"
						{who
							{type actor}
							{actors
								{source advanced}
								{group
									{select
										{tag
											{tag cloneme2}
										}
									}
									{include
										{prop
											{prop tank}
										}
                                        {tag
										{tag hidden}
									}
									}
									
								}
                                {amount 1
								}
							}
						}
						{action
							{type start}
							{waypoint "2002"}
							{clone}
							{approach "safe teleport & rotate"}
						}
					}
                    {"waypoint"
						{who
							{type actor}
							{actors
								{source advanced}
								{group
									{select
										{tag
											{tag cloneme2}
										}
									}
									{include
										{prop
											{prop tank}
										}
                                        {tag
										{tag hidden}
									}
									}
									
								}
                                {amount 1
								}
							}
						}
						{action
							{type start}
							{waypoint "2001"}
							{clone}
							{approach "safe teleport & rotate"}
						}
					}
						}
					}
                    
                    
					{"delay"
						{time 0.1}
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
										{tag player_armor}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop tank}
									}
								}
								{exclude
									
									{tag
										{tag hidden}
									}
									{tag
										{tag _user_ally2}
									}
                                    {tag
										{tag radio_car}
									}
								}
							}
						}
						{tag_add _user_ally2}
					}
                    
					{"ables"
						{selector
							{tag _user_ally2}
						}
						{remove "select personage"}
					}
					{"delay"
						{time 0.1}
					}
                    {"actor_state"
						{selector
							{tag _user_ally2}
							{state operatable}
						}
						{control AI}
						{fire_mode open}
						{move_mode free}
						{weapon_prepare on}
						
						{movement
							{speed assault}
						}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag hidden}
									}
								}
								{include
									{tag
										{tag player_armor}
									}
									{prop
										{prop tank}
									}
								}
							}
						}
						{tag_remove hidden}
						{inactive off}
					}
                    {"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag cloneme2}
									}
								}
								{include
									{tag
										{tag player_armor}
									}
									{prop
										{prop tank}
									}
								}
							}
						}
						{tag_remove cloneme2}
					}
					{"delay"
						{time 0.1}
					}
                    
                    {"delay"
						{time 0.1}
					}
					{"action"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _user_ally2}
									}
								}
								{include
									{state
										{state operatable}
									}
								}
								{exclude
									{tag
										{tag engaged}
									}
								}
							}
						}
                        {drop orders}
						{action advance}
						{target
							{tag ally_infantry_mark}
						}
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
										{tag  _user_ally2}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop tank}
									}
								}
								{exclude
									
									{tag
										{tag hidden}
									}
									
                                    {tag
										{tag engaged}
									}
								}
							}
						}
						{tag_add engaged}
					}
					{"delay"
						{time 0.1}
					}
                    
                    {"delay"
						{time 1}
					}
					{"trigger"
						{name "player_scripts/allied_tanks"}
					}
				}
			}
            {## "player_scripts/allied_support_high"
				{condition
					{expression "!2 & 4 & 1 & 3 & !5"}
					{terms
						{"2.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 1}
						}
						{"4.entities"
							{selector
								{ignore_captured_by_user 0}
								{tag player}
								{zone "gamezone"}
								{type human}
								{state operatable}
							}
						}
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag engaged}
										}
									}
									{include
										{state
											{state operatable}
										}
									}
								}
							}
							{count
								{op "<<"}
								{value 60}
							}
						}
                        {"3.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag support_mark_high}
										}
									}
								}
							}
						}
                        {"5.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag support_mark_low}
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
								{var "defense_level$"}
								{op "<<"}
								{value 2}
							}
							{"delay"
						{time 0.1}
					}
                    {"timer"
						{time 120}
						{title "AI support will come in:"}
					}
                    {"delay"
						{time 120.1}
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
										{tag player}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop human}
									}
									{zone
										{zone "gamezone"}
									}
									{state
										{state user_control}
									}
								}
								{exclude
									{state
										{state inhabited}
									}
									{tag
										{tag _user_ally}
									}
									{tag
										{tag medic}
									}
									{tag
										{tag tankman}
									}
									{tag
										{tag _def}
									}
									{state
										{state linked}
									}
								}
							}
                            {amount 13
									}
						}
						{tag_add cloneme}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag cloneme}
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
										{state inhabited}
									}
									{tag
										{tag _user_ally}
									}
								}
							}
						}
						{tag_add hidden}
						{inactive on}
					}
					{"delay"
						{time 0.1}
					}
					{## "if"
						{condition
							{type entities}
							{selector
								{tag challenge_map}
							}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme}
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
											{state
												{state linked}
											}
										}
									}
									{amount 13
									}
								}
							}
							{action
								{type start}
								{waypoint "1003"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme}
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
											{state
												{state linked}
											}
										}
									}
									{amount 13
									}
								}
							}
							{action
								{type start}
								{waypoint "1002"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme}
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
											{state
												{state linked}
											}
										}
									}
									{amount 13
									}
								}
							}
							{action
								{type start}
								{waypoint "1001"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme}
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
											{state
												{state linked}
											}
										}
									}
									{amount 13
									}
								}
							}
							{action
								{type start}
								{waypoint "1004"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "bots_spawnside$"}
								{op "=="}
								{value 2}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
										{amount 13
										}
									}
								}
								{action
									{type start}
									{waypoint "1003"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
										{amount 13
										}
									}
								}
								{action
									{type start}
									{waypoint "1002"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
										{amount 13
										}
									}
								}
								{action
									{type start}
									{waypoint "1001"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
										{amount 13
										}
									}
								}
								{action
									{type start}
									{waypoint "1004"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
						}
						{"default"
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
										{amount 13
										}
									}
								}
								{action
									{type start}
									{waypoint "2003"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
										{amount 13
										}
									}
								}
								{action
									{type start}
									{waypoint "2004"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
										{amount 13
										}
									}
								}
								{action
									{type start}
									{waypoint "2002"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
										{amount 13
										}
									}
								}
								{action
									{type start}
									{waypoint "2001"}
									{clone}
									{approach "safe teleport & rotate"}
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
							{group
								{select
									{tag
										{tag cloneme}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop human}
									}
									{state
										{state user_control}
									}
								}
								{exclude
									{state
										{state inhabited}
									}
									{state
										{state linked}
									}
									{tag
										{tag hidden}
									}
									{tag
										{tag _user_ally}
									}
									{tag
										{tag _def}
									}
									{tag
										{tag medic}
									}
								}
							}
						}
						{tag_add _user_ally}
					}
					{"ables"
						{selector
							{tag _user_ally}
						}
						{remove "select personage"}
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
										{tag _user_ally}
									}
								}
								{include
									{tag
										{tag player}
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
										{tag hidden}
									}
                                }
							}
                            {amount 100
										}
                            
						}
						{control AI}
						{fire_mode open}
						{move_mode free}
						{weapon_prepare on}
						
						{movement
							{speed assault}
						}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag hidden}
									}
								}
								{include
									{tag
										{tag player}
									}
									{prop
										{prop human}
									}
								}
							}
						}
						{tag_remove hidden}
						{inactive off}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag cloneme}
									}
								}
								{include
									{tag
										{tag player}
									}
									{prop
										{prop human}
									}
								}
							}
						}
						{tag_remove cloneme}
					}
					{"delay"
						{time 0.1}
					}
					
					{"action"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag player}
									}
								}
								{include
									{state
										{state operatable}
									}
								}
								{exclude
									{tag
										{tag _def}
									}
									{state
										{state linked}
									}
									{state
										{state user_control}
									}
								}
							}
                            {amount 100
										}
						}
						{drop orders}
						{action advance}
						{target
							{tag flag_point}
						}
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
										{tag _user_ally}
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
										{state inhabited}
									}
									{tag
										{tag hidden}
									}
									{tag
										{tag engaged}
									}
								}
							}
						}
						{tag_add engaged}
					}
					
					{"delay"
						{time 10}
					}
					{"trigger"
						{name "player_scripts/allied_support_high"}
					}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "defense_level$"}
								{op "=="}
								{value 2}
							}
                            {"timer"
						{time 90}
						{title "AI support will come in:"}
					}
							{"delay"
						{time 90.1}
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
										{tag player}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop human}
									}
									{zone
										{zone "gamezone"}
									}
									{state
										{state user_control}
									}
								}
								{exclude
									{state
										{state inhabited}
									}
									{tag
										{tag _user_ally}
									}
									{tag
										{tag medic}
									}
									{tag
										{tag tankman}
									}
									{tag
										{tag _def}
									}
									{state
										{state linked}
									}
								}
							}
                            {amount 13
									}
						}
						{tag_add cloneme}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag cloneme}
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
										{state inhabited}
									}
									{tag
										{tag _user_ally}
									}
								}
							}
						}
						{tag_add hidden}
						{inactive on}
					}
					{"delay"
						{time 0.1}
					}
					{## "if"
						{condition
							{type entities}
							{selector
								{tag challenge_map}
							}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme}
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
											{state
												{state linked}
											}
										}
									}
									{amount 13
									}
								}
							}
							{action
								{type start}
								{waypoint "1003"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme}
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
											{state
												{state linked}
											}
										}
									}
									{amount 13
									}
								}
							}
							{action
								{type start}
								{waypoint "1002"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme}
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
											{state
												{state linked}
											}
										}
									}
									{amount 13
									}
								}
							}
							{action
								{type start}
								{waypoint "1001"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme}
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
											{state
												{state linked}
											}
										}
									}
									{amount 13
									}
								}
							}
							{action
								{type start}
								{waypoint "1004"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "bots_spawnside$"}
								{op "=="}
								{value 2}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
										{amount 13
										}
									}
								}
								{action
									{type start}
									{waypoint "1003"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
										{amount 13
										}
									}
								}
								{action
									{type start}
									{waypoint "1002"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
										{amount 13
										}
									}
								}
								{action
									{type start}
									{waypoint "1001"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
										{amount 13
										}
									}
								}
								{action
									{type start}
									{waypoint "1004"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
						}
						{"default"
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
										{amount 13
										}
									}
								}
								{action
									{type start}
									{waypoint "2003"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
										{amount 13
										}
									}
								}
								{action
									{type start}
									{waypoint "2004"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
										{amount 13
										}
									}
								}
								{action
									{type start}
									{waypoint "2002"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
										{amount 13
										}
									}
								}
								{action
									{type start}
									{waypoint "2001"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
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
										{tag cloneme}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop human}
									}
									{state
										{state user_control}
									}
								}
								{exclude
									{state
										{state inhabited}
									}
									{state
										{state linked}
									}
									{tag
										{tag hidden}
									}
									{tag
										{tag _user_ally}
									}
									{tag
										{tag _def}
									}
									{tag
										{tag medic}
									}
								}
							}
						}
						{tag_add _user_ally}
					}
					{"ables"
						{selector
							{tag _user_ally}
						}
						{remove "select personage"}
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
										{tag _user_ally}
									}
								}
								{include
									{tag
										{tag player}
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
										{tag hidden}
									}
                                }
							}
                            
						}
						{control AI}
						{fire_mode open}
						{move_mode free}
						{weapon_prepare on}

						{movement
							{speed assault}
						}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag hidden}
									}
								}
								{include
									{tag
										{tag player}
									}
									{prop
										{prop human}
									}
								}
							}
						}
						{tag_remove hidden}
						{inactive off}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag cloneme}
									}
								}
								{include
									{tag
										{tag player}
									}
									{prop
										{prop human}
									}
								}
							}
						}
						{tag_remove cloneme}
					}
					{"delay"
						{time 0.1}
					}
					{"delay"
						{time 0.1}
					}
					{"action"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag player}
									}
								}
								{include
									{state
										{state operatable}
									}
								}
								{exclude
									{tag
										{tag _def}
									}
									{state
										{state linked}
									}
									{state
										{state user_control}
									}
								}
							}
                            {amount 100
										}
						}
						{drop orders}
						{action advance}
						{target
							{tag flag_point}
						}
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
										{tag _user_ally}
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
										{state inhabited}
									}
									{tag
										{tag hidden}
									}
									{tag
										{tag engaged}
									}
								}
							}
						}
						{tag_add engaged}
					}
					{"delay"
						{time 0.1}
					}
					{"delay"
						{time 30}
					}
					{"trigger"
						{name "player_scripts/allied_support_high"}
					}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "defense_level$"}
								{op "=="}
								{value 3}
							}
                            {"timer"
						{time 60}
						{title "AI support will come in:"}
					}
							{"delay"
						{time 0.1}
					}
					{"delay"
						{time 60.1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag player}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop human}
									}
									
									{state
										{state user_control}
									}
								}
								{exclude
									{state
										{state inhabited}
									}
									{tag
										{tag _user_ally}
									}
									{tag
										{tag medic}
									}
									{tag
										{tag tankman}
									}
									{tag
										{tag _def}
									}
									{state
										{state linked}
									}
								}
							}
                            {amount 13
									}
						}
						{tag_add cloneme}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag cloneme}
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
										{state inhabited}
									}
									{tag
										{tag _user_ally}
									}
								}
							}
						}
						{tag_add hidden}
						{inactive on}
					}
					{"delay"
						{time 0.1}
					}
					{## "if"
						{condition
							{type entities}
							{selector
								{tag challenge_map}
							}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme}
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
											{state
												{state linked}
											}
										}
									}
									{amount 13
									}
								}
							}
							{action
								{type start}
								{waypoint "1003"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme}
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
											{state
												{state linked}
											}
										}
									}
									{amount 13
									}
								}
							}
							{action
								{type start}
								{waypoint "1002"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme}
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
											{state
												{state linked}
											}
										}
									}
									{amount 13
									}
								}
							}
							{action
								{type start}
								{waypoint "1001"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme}
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
											{state
												{state linked}
											}
										}
									}
									{amount 13
									}
								}
							}
							{action
								{type start}
								{waypoint "1004"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "bots_spawnside$"}
								{op "=="}
								{value 2}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
										{amount 13
										}
									}
								}
								{action
									{type start}
									{waypoint "1003"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
										{amount 13
										}
									}
								}
								{action
									{type start}
									{waypoint "1002"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
										{amount 13
										}
									}
								}
								{action
									{type start}
									{waypoint "1001"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
										{amount 13
										}
									}
								}
								{action
									{type start}
									{waypoint "1004"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
						}
						{"default"
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
                                        {amount 13
										}
										
									}
								}
								{action
									{type start}
									{waypoint "2003"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
										{amount 13
										}
									}
								}
								{action
									{type start}
									{waypoint "2004"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
										{amount 13
										}
									}
								}
								{action
									{type start}
									{waypoint "2002"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme}
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
												{state
													{state linked}
												}
											}
										}
										{amount 13
										}
									}
								}
								{action
									{type start}
									{waypoint "2001"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
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
										{tag cloneme}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop human}
									}
									{state
										{state user_control}
									}
								}
								{exclude
									{state
										{state inhabited}
									}
									{state
										{state linked}
									}
									{tag
										{tag hidden}
									}
									{tag
										{tag _user_ally}
									}
									{tag
										{tag _def}
									}
									{tag
										{tag medic}
									}
								}
							}
						}
						{tag_add _user_ally}
					}
					{"ables"
						{selector
							{tag _user_ally}
						}
						{remove "select personage"}
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
										{tag _user_ally}
									}
								}
								{include
									{tag
										{tag player}
									}
                                    {state
										{state operatable}
									}
									{prop
										{prop human}
									}
								}
                                
							}
                            
						}
						{control AI}
						{fire_mode open}
						{move_mode free}
						{weapon_prepare on}

						{movement
							{speed assault}
						}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag hidden}
									}
								}
								{include
									{tag
										{tag player}
									}
									{prop
										{prop human}
									}
								}
							}
						}
						{tag_remove hidden}
						{inactive off}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag cloneme}
									}
								}
								{include
									{tag
										{tag player}
									}
									{prop
										{prop human}
									}
								}
							}
						}
						{tag_remove cloneme}
					}
					{"delay"
						{time 0.1}
					}
					{"delay"
						{time 0.1}
					}
					{"action"
						{selector
							{source advanced}
							{group
								{select
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
									{tag
										{tag _def}
									}
									{state
										{state linked}
									}
									{state
										{state user_control}
									}
								}
							}
                            {amount 100
										}
						}
						{drop orders}
						{action advance}
						{target
							{tag flag_point}
						}
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
										{tag _user_ally}
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
										{state inhabited}
									}
									{tag
										{tag hidden}
									}
									{tag
										{tag engaged}
									}
                                    {state
										{state user_control}
									}
								}
							}
						}
						{tag_add engaged}
					}
					{"delay"
						{time 0.1}
					}
					{"delay"
						{time 10}
					}
					{"trigger"
						{name "player_scripts/allied_support_high"}
					}
						}
					}
				}
            }
			{## "player_scripts/allied_tank_support_high"
				{condition
					{expression "!2 & 4 & 1 & 3 & !5"}
					{terms
						{"2.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 1}
						}
						{"4.entities"
							{selector
								{ignore_captured_by_user 0}
								{tag player}
								{zone "gamezone"}
								{type human}
								{state operatable}
							}
						}
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _user_ally2}
										}
									}
									{include
										{state
											{state operatable}
										}
									}
									{exclude
										{broken_components
											{masks
												"engine"
											}
										}
									}
								}
							}
							{count
								{op "<<"}
								{value 5}
							}
						}
                        {"3.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag support_mark_high}
										}
									}
								}
							}
						}
                        {"5.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag support_mark_low}
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
								{var "defense_level$"}
								{op "<<"}
								{value 2}
							}
							{"delay"
						{time 600.1}
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
										{tag player_armor}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop tank}
									}
									{zone
										{zone "gamezone"}
									}
								}
								{exclude
									{tag
										{tag _user_ally2}
									}
                                    {tag
											{tag radio_car}
										}
                                    {broken_components
										{masks
												"engine"
										}
                                        
									}
                                    {broken_components
										{masks
												"turret"
										}
                                        
									}
                                    {broken_components
										{masks
												"gun"
										}
                                        
									}
                                    {broken_components
										{masks
												"trackright"
										}
                                        
									}
                                    {broken_components
										{masks
												"trackleft"
										}
                                        
									}
                                    
								}
							}
						}
						{tag_add cloneme2}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag cloneme2}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop tank}
									}
								}
								{exclude
									{tag
										{tag _user_ally2}
									}
								}
							}
						}
						{tag_add hidden}
						{inactive on}
					}
					{"delay"
						{time 0.1}
					}
					{"if"
						{condition
							{type entities}
							{selector
								{tag challenge_map}
							}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme2}
											}
										}
										{include
											{prop
												{prop tank}
											}
											{tag
												{tag hidden}
											}
										}
									}
									{amount 1
									}
								}
							}
							{action
								{type start}
								{waypoint "1003"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme2}
											}
										}
										{include
											{prop
												{prop tank}
											}
											{tag
												{tag hidden}
											}
										}
									}
									{amount 1
									}
								}
							}
							{action
								{type start}
								{waypoint "1002"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme2}
											}
										}
										{include
											{prop
												{prop tank}
											}
											{tag
												{tag hidden}
											}
										}
									}
									{amount 1
									}
								}
							}
							{action
								{type start}
								{waypoint "1001"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme2}
											}
										}
										{include
											{prop
												{prop tank}
											}
											{tag
												{tag hidden}
											}
										}
									}
									{amount 1
									}
								}
							}
							{action
								{type start}
								{waypoint "1004"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "bots_spawnside$"}
								{op "=="}
								{value 2}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme2}
												}
											}
											{include
												{prop
													{prop tank}
												}
												{tag
													{tag hidden}
												}
											}
										}
										{amount 1
										}
									}
								}
								{action
									{type start}
									{waypoint "1003"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme2}
												}
											}
											{include
												{prop
													{prop tank}
												}
												{tag
													{tag hidden}
												}
											}
										}
										{amount 1
										}
									}
								}
								{action
									{type start}
									{waypoint "1002"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme2}
												}
											}
											{include
												{prop
													{prop tank}
												}
												{tag
													{tag hidden}
												}
											}
										}
										{amount 1
										}
									}
								}
								{action
									{type start}
									{waypoint "1001"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme2}
												}
											}
											{include
												{prop
													{prop tank}
												}
												{tag
													{tag hidden}
												}
											}
										}
										{amount 1
										}
									}
								}
								{action
									{type start}
									{waypoint "1004"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
						}
						{"default"
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme2}
												}
											}
											{include
												{prop
													{prop tank}
												}
												{tag
													{tag hidden}
												}
											}
										}
										{amount 1
										}
									}
								}
								{action
									{type start}
									{waypoint "2003"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme2}
												}
											}
											{include
												{prop
													{prop tank}
												}
												{tag
													{tag hidden}
												}
											}
										}
										{amount 1
										}
									}
								}
								{action
									{type start}
									{waypoint "2004"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme2}
												}
											}
											{include
												{prop
													{prop tank}
												}
												{tag
													{tag hidden}
												}
											}
										}
										{amount 1
										}
									}
								}
								{action
									{type start}
									{waypoint "2002"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme2}
												}
											}
											{include
												{prop
													{prop tank}
												}
												{tag
													{tag hidden}
												}
											}
										}
										{amount 1
										}
									}
								}
								{action
									{type start}
									{waypoint "2001"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
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
										{tag player_armor}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop tank}
									}
								}
								{exclude
									{tag
										{tag hidden}
									}
									{tag
										{tag _user_ally2}
									}
                                    {tag
										{tag radio_car}
									}
								}
							}
						}
						{tag_add _user_ally2}
					}
					{"ables"
						{selector
							{tag _user_ally2}
						}
						{remove "select personage"}
					}
					{"delay"
						{time 0.1}
					}
					{"actor_state"
						{selector
							{tag _user_ally2}
							{state operatable}
						}
						{control AI}
						{fire_mode open}
						{move_mode free}
						{weapon_prepare on}
						
						{movement
							{speed assault}
						}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag hidden}
									}
								}
								{include
									{tag
										{tag player_armor}
									}
									{prop
										{prop tank}
									}
								}
							}
						}
						{tag_remove hidden}
						{inactive off}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag cloneme2}
									}
								}
								{include
									{tag
										{tag player_armor}
									}
									{prop
										{prop tank}
									}
								}
							}
						}
						{tag_remove cloneme2}
					}
					{"delay"
						{time 0.1}
					}
					{"delay"
						{time 0.1}
					}
					{"action"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _user_ally2}
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
						{action advance}
						{target
							{source advanced}
							{group
								{select
									{tag
										{tag flag_point}
									}
								}
								{include
									{state
										{state discovered}
									}
								}
							}
							{sort
								{type shuffle}
							}
						}
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
										{tag _user_ally2}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop tank}
									}
								}
								{exclude
									{tag
										{tag hidden}
									}
									{tag
										{tag engaged}
									}
								}
							}
						}
						{tag_add engaged}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _user_ally2}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop tank}
									}
									{tag
										{tag engaged}
									}
								}
								{exclude
									{tag
										{tag hidden}
									}
								}
							}
						}
						{tag_add no_scavenge}
					}
					{"delay"
						{time 0.1}
					}
					{"delay"
						{time 10}
					}
					{"trigger"
						{name "player_scripts/allied_tank_support_high"}
					}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "defense_level$"}
								{op "=="}
								{value 2}
							}
							{"delay"
						{time 300.1}
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
										{tag player_armor}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop tank}
									}
									{zone
										{zone "gamezone"}
									}
								}
								{exclude
									{tag
										{tag _user_ally2}
									}
                                    {tag
											{tag radio_car}
										}
                                    {broken_components
										{masks
												"engine"
										}
                                        
									}
                                    {broken_components
										{masks
												"turret"
										}
                                        
									}
                                    {broken_components
										{masks
												"gun"
										}
                                        
									}
                                    {broken_components
										{masks
												"trackright"
										}
                                        
									}
                                    {broken_components
										{masks
												"trackleft"
										}
                                        
									}
                                    
								}
							}
						}
						{tag_add cloneme2}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag cloneme2}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop tank}
									}
								}
								{exclude
									{tag
										{tag _user_ally2}
									}
								}
							}
						}
						{tag_add hidden}
						{inactive on}
					}
					{"delay"
						{time 0.1}
					}
					{## "if"
						{condition
							{type entities}
							{selector
								{tag challenge_map}
							}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme2}
											}
										}
										{include
											{prop
												{prop tank}
											}
											{tag
												{tag hidden}
											}
										}
									}
									{amount 1
									}
								}
							}
							{action
								{type start}
								{waypoint "1003"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme2}
											}
										}
										{include
											{prop
												{prop tank}
											}
											{tag
												{tag hidden}
											}
										}
									}
									{amount 1
									}
								}
							}
							{action
								{type start}
								{waypoint "1002"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme2}
											}
										}
										{include
											{prop
												{prop tank}
											}
											{tag
												{tag hidden}
											}
										}
									}
									{amount 1
									}
								}
							}
							{action
								{type start}
								{waypoint "1001"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme2}
											}
										}
										{include
											{prop
												{prop tank}
											}
											{tag
												{tag hidden}
											}
										}
									}
									{amount 1
									}
								}
							}
							{action
								{type start}
								{waypoint "1004"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "bots_spawnside$"}
								{op "=="}
								{value 2}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme2}
												}
											}
											{include
												{prop
													{prop tank}
												}
												{tag
													{tag hidden}
												}
											}
										}
										{amount 1
										}
									}
								}
								{action
									{type start}
									{waypoint "1003"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme2}
												}
											}
											{include
												{prop
													{prop tank}
												}
												{tag
													{tag hidden}
												}
											}
										}
										{amount 1
										}
									}
								}
								{action
									{type start}
									{waypoint "1002"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme2}
												}
											}
											{include
												{prop
													{prop tank}
												}
												{tag
													{tag hidden}
												}
											}
										}
										{amount 1
										}
									}
								}
								{action
									{type start}
									{waypoint "1001"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme2}
												}
											}
											{include
												{prop
													{prop tank}
												}
												{tag
													{tag hidden}
												}
											}
										}
										{amount 1
										}
									}
								}
								{action
									{type start}
									{waypoint "1004"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
						}
						{"default"
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme2}
												}
											}
											{include
												{prop
													{prop tank}
												}
												{tag
													{tag hidden}
												}
											}
										}
										{amount 1
										}
									}
								}
								{action
									{type start}
									{waypoint "2003"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme2}
												}
											}
											{include
												{prop
													{prop tank}
												}
												{tag
													{tag hidden}
												}
											}
										}
										{amount 1
										}
									}
								}
								{action
									{type start}
									{waypoint "2004"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme2}
												}
											}
											{include
												{prop
													{prop tank}
												}
												{tag
													{tag hidden}
												}
											}
										}
										{amount 1
										}
									}
								}
								{action
									{type start}
									{waypoint "2002"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme2}
												}
											}
											{include
												{prop
													{prop tank}
												}
												{tag
													{tag hidden}
												}
											}
										}
										{amount 1
										}
									}
								}
								{action
									{type start}
									{waypoint "2001"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
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
										{tag player_armor}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop tank}
									}
								}
								{exclude
									{tag
										{tag hidden}
									}
                                    {tag
										{tag radio_car}
									}
									{tag
										{tag _user_ally2}
									}
								}
							}
						}
						{tag_add _user_ally2}
					}
					{"ables"
						{selector
							{tag _user_ally2}
						}
						{remove "select personage"}
					}
					{"delay"
						{time 0.1}
					}
					{"actor_state"
						{selector
							{tag _user_ally2}
							{state operatable}
						}
						{control AI}
						{fire_mode open}
						{move_mode free}
						{weapon_prepare on}
						
						{movement
							{speed assault}
						}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag hidden}
									}
								}
								{include
									{tag
										{tag player_armor}
									}
									{prop
										{prop tank}
									}
								}
							}
						}
						{tag_remove hidden}
						{inactive off}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag cloneme2}
									}
								}
								{include
									{tag
										{tag player_armor}
									}
									{prop
										{prop tank}
									}
								}
							}
						}
						{tag_remove cloneme2}
					}
					{"delay"
						{time 0.1}
					}
					{"delay"
						{time 0.1}
					}
					{"action"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _user_ally2}
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
						{action advance}
						{target
							{source advanced}
							{group
								{select
									{tag
										{tag flag_point}
									}
								}
								{include
									{state
										{state discovered}
									}
								}
							}
							{sort
								{type shuffle}
							}
						}
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
										{tag _user_ally2}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop tank}
									}
								}
								{exclude
									{tag
										{tag hidden}
									}
									{tag
										{tag engaged}
									}
								}
							}
						}
						{tag_add engaged}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _user_ally2}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop tank}
									}
									{tag
										{tag engaged}
									}
								}
								{exclude
									{tag
										{tag hidden}
									}
								}
							}
						}
						{tag_add no_scavenge}
					}
					{"delay"
						{time 0.1}
					}
					{"delay"
						{time 10}
					}
					{"trigger"
						{name "player_scripts/allied_tank_support_high"}
					}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "defense_level$"}
								{op "=="}
								{value 3}
							}
							{"delay"
						{time 150.1}
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
										{tag player_armor}
									}
								}
								{include
									{state
										{state operatable}
									}
                                    
									{prop
										{prop tank}
									}
									{zone
										{zone "gamezone"}
									}
								}
								{exclude
									{tag
										{tag _user_ally2}
									}
                                    {tag
											{tag radio_car}
										}
                                    {broken_components
										{masks
												"engine"
										}
                                        
									}
                                    {broken_components
										{masks
												"turret"
										}
                                        
									}
                                    {broken_components
										{masks
												"gun"
										}
                                        
									}
                                    {broken_components
										{masks
												"trackright"
										}
                                        
									}
                                    {broken_components
										{masks
												"trackleft"
										}
                                        
									}
                                    
								}
							}
						}
						{tag_add cloneme2}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag cloneme2}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop tank}
									}
								}
								{exclude
									{tag
										{tag _user_ally2}
									}
								}
							}
						}
						{tag_add hidden}
						{inactive on}
					}
					{"delay"
						{time 0.1}
					}
					{## "if"
						{condition
							{type entities}
							{selector
								{tag challenge_map}
							}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme2}
											}
										}
										{include
											{prop
												{prop tank}
											}
											{tag
												{tag hidden}
											}
										}
									}
									{amount 1
									}
								}
							}
							{action
								{type start}
								{waypoint "1003"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme2}
											}
										}
										{include
											{prop
												{prop tank}
											}
											{tag
												{tag hidden}
											}
										}
									}
									{amount 1
									}
								}
							}
							{action
								{type start}
								{waypoint "1002"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme2}
											}
										}
										{include
											{prop
												{prop tank}
											}
											{tag
												{tag hidden}
											}
										}
									}
									{amount 1
									}
								}
							}
							{action
								{type start}
								{waypoint "1001"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
						{"waypoint"
							{who
								{type actor}
								{actors
									{source advanced}
									{group
										{select
											{tag
												{tag cloneme2}
											}
										}
										{include
											{prop
												{prop tank}
											}
											{tag
												{tag hidden}
											}
										}
									}
									{amount 1
									}
								}
							}
							{action
								{type start}
								{waypoint "1004"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "bots_spawnside$"}
								{op "=="}
								{value 2}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme2}
												}
											}
											{include
												{prop
													{prop tank}
												}
												{tag
													{tag hidden}
												}
											}
										}
										{amount 1
										}
									}
								}
								{action
									{type start}
									{waypoint "1003"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme2}
												}
											}
											{include
												{prop
													{prop tank}
												}
												{tag
													{tag hidden}
												}
											}
										}
										{amount 1
										}
									}
								}
								{action
									{type start}
									{waypoint "1002"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme2}
												}
											}
											{include
												{prop
													{prop tank}
												}
												{tag
													{tag hidden}
												}
											}
										}
										{amount 1
										}
									}
								}
								{action
									{type start}
									{waypoint "1001"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme2}
												}
											}
											{include
												{prop
													{prop tank}
												}
												{tag
													{tag hidden}
												}
											}
										}
										{amount 1
										}
									}
								}
								{action
									{type start}
									{waypoint "1004"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
						}
						{"default"
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme2}
												}
											}
											{include
												{prop
													{prop tank}
												}
												{tag
													{tag hidden}
												}
											}
										}
										{amount 1
										}
									}
								}
								{action
									{type start}
									{waypoint "2003"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme2}
												}
											}
											{include
												{prop
													{prop tank}
												}
												{tag
													{tag hidden}
												}
											}
										}
										{amount 1
										}
									}
								}
								{action
									{type start}
									{waypoint "2004"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme2}
												}
											}
											{include
												{prop
													{prop tank}
												}
												{tag
													{tag hidden}
												}
											}
										}
										{amount 1
										}
									}
								}
								{action
									{type start}
									{waypoint "2002"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
							{"waypoint"
								{who
									{type actor}
									{actors
										{source advanced}
										{group
											{select
												{tag
													{tag cloneme2}
												}
											}
											{include
												{prop
													{prop tank}
												}
												{tag
													{tag hidden}
												}
											}
										}
										{amount 1
										}
									}
								}
								{action
									{type start}
									{waypoint "2001"}
									{clone}
									{approach "safe teleport & rotate"}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
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
										{tag player_armor}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop tank}
									}
								}
								{exclude
									{tag
										{tag hidden}
									}
                                    {tag
										{tag radio_car}
									}
									{tag
										{tag _user_ally2}
									}
								}
							}
						}
						{tag_add _user_ally2}
					}
					{"ables"
						{selector
							{tag _user_ally2}
						}
						{remove "select personage"}
					}
					{"delay"
						{time 0.1}
					}
					{"actor_state"
						{selector
							{tag _user_ally2}
							{state operatable}
						}
						{control AI}
						{fire_mode open}
						{move_mode free}
						{weapon_prepare on}
						
						{movement
							{speed assault}
						}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag hidden}
									}
								}
								{include
									{tag
										{tag player_armor}
									}
									{prop
										{prop tank}
									}
								}
							}
						}
						{tag_remove hidden}
						{inactive off}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag cloneme2}
									}
								}
								{include
									{tag
										{tag player_armor}
									}
									{prop
										{prop tank}
									}
								}
							}
						}
						{tag_remove cloneme2}
					}
					{"delay"
						{time 0.1}
					}
					{"delay"
						{time 0.1}
					}
					{"action"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _user_ally2}
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
						{action advance}
						{target
							{source advanced}
							{group
								{select
									{tag
										{tag flag_point}
									}
								}
								{include
									{state
										{state discovered}
									}
								}
							}
							{sort
								{type shuffle}
							}
						}
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
										{tag _user_ally2}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop tank}
									}
								}
								{exclude
									{tag
										{tag hidden}
									}
									{tag
										{tag engaged}
									}
								}
							}
						}
						{tag_add engaged}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _user_ally2}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop tank}
									}
									{tag
										{tag engaged}
									}
								}
								{exclude
									{tag
										{tag hidden}
									}
								}
							}
						}
						{tag_add no_scavenge}
					}
					{"delay"
						{time 0.1}
					}
					{"delay"
						{time 10}
					}
					{"trigger"
						{name "player_scripts/allied_tank_support_high"}
					}
						}
					}
                    
				}
			}
            {## "player_scripts/allied_support_low"
				{condition
					{terms
						{"2.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 0}
						}
						{"4.entities"
							{selector
								{ignore_captured_by_user 0}
								{tag player}
								{zone "gamezone"}
								{type human}
								{state operatable}
							}
						}
						{"3.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag support_mark_low}
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
								{var "defense_level$"}
								{op "<<"}
								{value 2}
							}
							{"loop" 3
								{"call"
									{function "spawn_allied_support"}
								}
								{"delay"
									{time 160}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "defense_level$"}
								{op "=="}
								{value 2}
							}
							{"loop" 4
								{"call"
									{function "spawn_allied_support"}
								}
								{"delay"
									{time 160}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "defense_level$"}
								{op "=="}
								{value 3}
							}
							{"loop" 5
								{"call"
									{function "spawn_allied_support"}
								}
								{"delay"
									{time 160}
								}
							}
						}
					}
				}
			}
			{## "player_scripts/allied_tank_support_low"
				{condition
					{terms
						{"2.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 0}
						}
						{"4.entities"
							{selector
								{ignore_captured_by_user 0}
								{tag player}
								{zone "gamezone"}
								{type human}
								{state operatable}
							}
						}
						{"3.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag support_mark_low}
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
								{var "defense_level$"}
								{op "<<"}
								{value 2}
							}
							{"loop" 1
								{"call"
									{function "spawn_allied_armor_support"}
								}
								{"delay"
									{time 630}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "defense_level$"}
								{op "=="}
								{value 2}
							}
							{"loop" 2
								{"call"
									{function "spawn_allied_armor_support"}
								}
								{"delay"
									{time 630}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "defense_level$"}
								{op "=="}
								{value 3}
							}
							{"loop" 3
								{"call"
									{function "spawn_allied_armor_support"}
								}
								{"delay"
									{time 630}
								}
							}
						}
					}
				}
			}