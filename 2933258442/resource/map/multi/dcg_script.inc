			{"random_cmp_def"
				{condition
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"fade"
						{time 15}
						{color 0xff000000}
					}
					{"delay"
						{time 1}
					}
					{"set_i"
						{var "balance$"}
						{op "="}
						{value 1}
					}
					{"set_i"
						{var "arrows$"}
						{op "="}
						{value 0}
					}
					{"set_i"
						{var "user_team$"}
						{op "="}
						{value 0}
					}
					{"delay"
						{time 2}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag fpc1}
									}
								}
								{include
									{state
										{state inactive}
									}
								}
							}
						}
						{tag_remove fpc1}
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
										{tag fpc2}
									}
								}
								{include
									{state
										{state inactive}
									}
								}
							}
						}
						{tag_remove fpc2}
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
										{tag fpc3}
									}
								}
								{include
									{state
										{state inactive}
									}
								}
							}
						}
						{tag_remove fpc3}
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
										{tag fpc4}
									}
								}
								{include
									{state
										{state inactive}
									}
								}
							}
						}
						{tag_remove fpc4}
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
										{tag fpc5}
									}
								}
								{include
									{state
										{state inactive}
									}
								}
							}
						}
						{tag_remove fpc5}
					}
					{"delay"
						{time 0.5}
					}
					{"actor_state"
						{selector
							{ignore_captured_by_user 0}
							{tag random_def}
							{type human}
							{state "not dead"}
						}
						{move_mode free}
					}
					{"delay"
						{time 1}
					}
					{## "delete"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{zone
										{zone "combat"}
									}
								}
								{include
									{tag
										{tag cmp_def}
									}
									{prop
										{prop human}
									}
									{state
										{state inactive}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"set_i"
						{var "dcg_error$"}
						{op "="}
						{value 5}
					}
					{"delay"
						{time 0.5}
					}
					{"event"
						{event "init"}
						{mode set}
						{delay 0}
					}
				}
			}
			{"cmp_def_1_tune"
				{condition
					{terms
						{"1.entities"
							{selector
								{ignore_captured_by_user 0}
								{tag cmp_def}
								{zone "fpc1"}
								{type human}
								{state dead}
							}
						}
						{"2.event"
							{id "init2"}
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
									{ignore_captured_by_user 0}
									{tag cmp_def}
									{zone "fpc1"}
									{type human}
									{state "not dead"}
								}
								{count
									{op ">"}
									{value 12}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_state"
								{selector
									{ignore_captured_by_user 0}
									{amount 6
									}
									{tag cmp_def}
									{zone "fpc1"}
									{type human}
									{state "not dead"}
								}
								{move_mode zone}
								{move_radius 20}
								{ai
									{advance_ratio 1}
									{retreat_ratio 5}
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
									{amount 4
									}
									{tag cmp_def}
									{zone "fpc1"}
									{type human}
									{state "not dead"}
								}
								{move_mode zone}
								{move_radius 20}
								{ai
									{advance_ratio 1}
									{retreat_ratio 5}
								}
							}
						}
					}
					{"delay"
						{time 40}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "user_is_defender$"}
								{op "=="}
								{value 1}
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
												{tag cmp_def}
											}
										}
										{include
											{zone
												{zone "fpc1"}
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
												{state inactive}
											}
											{state
												{state linked}
											}
										}
									}
								}
								{tag_add _def}
								{tag_remove cmp_def}
							}
						}
					}
				}
			}
			{"cmp_def_2_tune"
				{condition
					{terms
						{"1.entities"
							{selector
								{ignore_captured_by_user 0}
								{tag cmp_def}
								{zone "fpc2"}
								{type human}
								{state dead}
							}
						}
						{"2.event"
							{id "init2"}
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
									{ignore_captured_by_user 0}
									{tag cmp_def}
									{zone "fpc2"}
									{type human}
									{state "not dead"}
								}
								{count
									{op ">"}
									{value 12}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_state"
								{selector
									{ignore_captured_by_user 0}
									{amount 6
									}
									{tag cmp_def}
									{zone "fpc2"}
									{type human}
									{state "not dead"}
								}
								{move_mode zone}
								{move_radius 20}
								{ai
									{advance_ratio 1}
									{retreat_ratio 5}
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
									{amount 4
									}
									{tag cmp_def}
									{zone "fpc2"}
									{type human}
									{state "not dead"}
								}
								{move_mode zone}
								{move_radius 20}
								{ai
									{advance_ratio 1}
									{retreat_ratio 5}
								}
							}
						}
					}
					{"delay"
						{time 40}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "user_is_defender$"}
								{op "=="}
								{value 1}
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
												{tag cmp_def}
											}
										}
										{include
											{zone
												{zone "fpc2"}
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
												{state inactive}
											}
											{state
												{state linked}
											}
										}
									}
								}
								{tag_add _def}
								{tag_remove cmp_def}
							}
						}
					}
				}
			}
			{"cmp_def_3_tune"
				{condition
					{terms
						{"1.entities"
							{selector
								{ignore_captured_by_user 0}
								{tag cmp_def}
								{zone "fpc3"}
								{type human}
								{state dead}
							}
						}
						{"2.event"
							{id "init2"}
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
									{ignore_captured_by_user 0}
									{tag cmp_def}
									{zone "fpc3"}
									{type human}
									{state "not dead"}
								}
								{count
									{op ">"}
									{value 12}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_state"
								{selector
									{ignore_captured_by_user 0}
									{amount 6
									}
									{tag cmp_def}
									{zone "fpc3"}
									{type human}
									{state "not dead"}
								}
								{move_mode zone}
								{move_radius 20}
								{ai
									{advance_ratio 1}
									{retreat_ratio 5}
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
									{amount 4
									}
									{tag cmp_def}
									{zone "fpc3"}
									{type human}
									{state "not dead"}
								}
								{move_mode zone}
								{move_radius 20}
								{ai
									{advance_ratio 1}
									{retreat_ratio 5}
								}
							}
						}
					}
					{"delay"
						{time 40}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "user_is_defender$"}
								{op "=="}
								{value 1}
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
												{tag cmp_def}
											}
										}
										{include
											{zone
												{zone "fpc3"}
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
												{state inactive}
											}
											{state
												{state linked}
											}
										}
									}
								}
								{tag_add _def}
								{tag_remove cmp_def}
							}
						}
					}
				}
			}
			{"cmp_def_4_tune"
				{condition
					{terms
						{"1.entities"
							{selector
								{ignore_captured_by_user 0}
								{tag cmp_def}
								{zone "fpc4"}
								{type human}
								{state dead}
							}
						}
						{"2.event"
							{id "init2"}
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
									{ignore_captured_by_user 0}
									{tag cmp_def}
									{zone "fpc4"}
									{type human}
									{state "not dead"}
								}
								{count
									{op ">"}
									{value 12}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_state"
								{selector
									{ignore_captured_by_user 0}
									{amount 6
									}
									{tag cmp_def}
									{zone "fpc4"}
									{type human}
									{state "not dead"}
								}
								{move_mode zone}
								{move_radius 20}
								{ai
									{advance_ratio 1}
									{retreat_ratio 5}
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
									{amount 4
									}
									{tag cmp_def}
									{zone "fpc4"}
									{type human}
									{state "not dead"}
								}
								{move_mode zone}
								{move_radius 20}
								{ai
									{advance_ratio 1}
									{retreat_ratio 5}
								}
							}
						}
					}
					{"delay"
						{time 40}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "user_is_defender$"}
								{op "=="}
								{value 1}
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
												{tag cmp_def}
											}
										}
										{include
											{zone
												{zone "fpc4"}
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
												{state inactive}
											}
											{state
												{state linked}
											}
										}
									}
								}
								{tag_add _def}
								{tag_remove cmp_def}
							}
						}
					}
				}
			}
			{"cmp_def_5_tune"
				{condition
					{terms
						{"1.entities"
							{selector
								{ignore_captured_by_user 0}
								{tag cmp_def}
								{zone "fpc5"}
								{type human}
								{state dead}
							}
						}
						{"2.event"
							{id "init2"}
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
									{ignore_captured_by_user 0}
									{tag cmp_def}
									{zone "fpc5"}
									{type human}
									{state "not dead"}
								}
								{count
									{op ">"}
									{value 12}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_state"
								{selector
									{ignore_captured_by_user 0}
									{amount 6
									}
									{tag cmp_def}
									{zone "fpc5"}
									{type human}
									{state "not dead"}
								}
								{move_mode zone}
								{move_radius 20}
								{ai
									{advance_ratio 1}
									{retreat_ratio 5}
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
									{amount 4
									}
									{tag cmp_def}
									{zone "fpc5"}
									{type human}
									{state "not dead"}
								}
								{move_mode zone}
								{move_radius 20}
								{ai
									{advance_ratio 1}
									{retreat_ratio 5}
								}
							}
						}
					}
					{"delay"
						{time 40}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "user_is_defender$"}
								{op "=="}
								{value 1}
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
												{tag cmp_def}
											}
										}
										{include
											{zone
												{zone "fpc5"}
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
												{state inactive}
											}
											{state
												{state linked}
											}
										}
									}
								}
								{tag_add _def}
								{tag_remove cmp_def}
							}
						}
					}
				}
			}
			{"random_cmp_def_to_cover"
				{condition
					{expression "1 & 2 & !3"}
					{terms
						{"1.event"
							{id "init"}
						}
						{"2.entities"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag random_def}
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
											{tag hidden}
										}
										{state
											{state inactive}
										}
									}
								}
							}
							{count
								{op ">"}
								{value 1}
							}
						}
						{"3.event"
							{id "init2"}
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
										{tag random_def}
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
							{amount 3
							}
						}
						{tag_add def_do_cover}
						{tag_remove random_def}
					}
					{"delay"
						{time 0.2}
					}
					{"actor_to_cover"
						{selector
							{ignore_captured_by_user 0}
							{tag def_do_cover}
							{type human}
							{state "not dead"}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag def_do_cover}
						}
						{tag_add rnd_def}
						{tag_remove def_do_cover}
					}
					{"delay"
						{time 0.5}
					}
					{"trigger"
						{name "random_cmp_def_to_cover"}
					}
				}
			}
			{"random_cmp_def_states"
				{condition
					{expression "1 & !2 & 3"}
					{terms
						{"1.event"
							{id "init"}
						}
						{"2.trigger"
							{name "random_cmp_def_to_cover"}
						}
						{"3.entities"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag random_def}
										}
									}
									{include
										{prop
											{prop human}
										}
									}
									{exclude
										{tag
											{tag hidden}
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
							{count
								{op "<<="}
								{value 1}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"event"
						{event "init2"}
						{mode set}
						{delay 0}
					}
					{"delay"
						{time 0.9}
					}
					{"actor_state"
						{selector
							{ignore_captured_by_user 0}
							{tag rnd_def}
							{type human}
							{state "not dead"}
						}
						{move_mode zone}
						{move_radius 45}
						{ai
							{advance_ratio 1}
							{retreat_ratio 5}
						}
					}
					{"delay"
						{time 10}
					}
					{"ables"
						{selector
							{ignore_captured_by_user 0}
							{tag cmp_def}
							{zone "gamezone"}
							{type human}
							{state "not dead"}
						}
						{remove personage}
					}
					{"delay"
						{time 120}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "user_is_defender$"}
								{op "=="}
								{value 1}
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
												{tag rnd_def}
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
												{state inactive}
											}
										}
									}
								}
								{tag_add _def}
								{tag_remove cmp_def}
							}
						}
					}
				}
			}
			{"cmp_def_covers_fix"
				{condition
					{terms
						{"1.event"
							{id "init2"}
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
											{zone
												{zone "fpc1"}
											}
										}
										{include
											{tag
												{tag cmp_def}
											}
											{prop
												{prop human}
											}
										}
										{exclude
											{tag
												{tag rnd_def}
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
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_cover"
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
											{zone
												{zone "fpc1"}
											}
											{prop
												{prop human}
											}
										}
										{exclude
											{tag
												{tag rnd_def}
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
							}
						}
						{"default"}
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
									{ignore_captured_by_user 0}
									{group
										{select
											{zone
												{zone "fpc2"}
											}
										}
										{include
											{tag
												{tag cmp_def}
											}
											{prop
												{prop human}
											}
										}
										{exclude
											{tag
												{tag rnd_def}
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
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_cover"
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
											{zone
												{zone "fpc2"}
											}
											{prop
												{prop human}
											}
										}
										{exclude
											{tag
												{tag rnd_def}
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
							}
						}
						{"default"}
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
									{ignore_captured_by_user 0}
									{group
										{select
											{zone
												{zone "fpc3"}
											}
										}
										{include
											{tag
												{tag cmp_def}
											}
											{prop
												{prop human}
											}
										}
										{exclude
											{tag
												{tag rnd_def}
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
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_cover"
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
											{zone
												{zone "fpc3"}
											}
											{prop
												{prop human}
											}
										}
										{exclude
											{tag
												{tag rnd_def}
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
							}
						}
						{"default"}
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
									{ignore_captured_by_user 0}
									{group
										{select
											{zone
												{zone "fpc4"}
											}
										}
										{include
											{tag
												{tag cmp_def}
											}
											{prop
												{prop human}
											}
										}
										{exclude
											{tag
												{tag rnd_def}
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
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_cover"
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
											{zone
												{zone "fpc4"}
											}
											{prop
												{prop human}
											}
										}
										{exclude
											{tag
												{tag rnd_def}
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
							}
						}
						{"default"}
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
									{ignore_captured_by_user 0}
									{group
										{select
											{zone
												{zone "fpc5"}
											}
										}
										{include
											{tag
												{tag cmp_def}
											}
											{prop
												{prop human}
											}
										}
										{exclude
											{tag
												{tag rnd_def}
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
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_cover"
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
											{zone
												{zone "fpc5"}
											}
											{prop
												{prop human}
											}
										}
										{exclude
											{tag
												{tag rnd_def}
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
							}
						}
						{"default"}
					}
				}
			}
			{"balance_cmp_def"
				{condition
					{terms
						{"1.cmp_i"
							{var "balance$"}
							{op "=="}
							{value 1}
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
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag cmp_def}
											}
										}
										{include
											{zone
												{zone "fpc1"}
											}
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag random_def}
											}
											{state
												{state inactive}
											}
										}
									}
								}
								{count
									{op ">"}
									{value 6}
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
												{tag cmp_def}
											}
										}
										{include
											{zone
												{zone "fpc1"}
											}
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag random_def}
											}
											{state
												{state inactive}
											}
										}
									}
									{amount 3
									}
								}
							}
						}
						{"default"}
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
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag cmp_def}
											}
										}
										{include
											{zone
												{zone "fpc2"}
											}
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag random_def}
											}
											{state
												{state inactive}
											}
										}
									}
								}
								{count
									{op ">"}
									{value 6}
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
												{tag cmp_def}
											}
										}
										{include
											{zone
												{zone "fpc2"}
											}
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag random_def}
											}
											{state
												{state inactive}
											}
										}
									}
									{amount 3
									}
								}
							}
						}
						{"default"}
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
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag cmp_def}
											}
										}
										{include
											{zone
												{zone "fpc3"}
											}
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag random_def}
											}
											{state
												{state inactive}
											}
										}
									}
								}
								{count
									{op ">"}
									{value 6}
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
												{tag cmp_def}
											}
										}
										{include
											{zone
												{zone "fpc3"}
											}
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag random_def}
											}
											{state
												{state inactive}
											}
										}
									}
									{amount 3
									}
								}
							}
						}
						{"default"}
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
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag cmp_def}
											}
										}
										{include
											{zone
												{zone "fpc4"}
											}
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag random_def}
											}
											{state
												{state inactive}
											}
										}
									}
								}
								{count
									{op ">"}
									{value 6}
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
												{tag cmp_def}
											}
										}
										{include
											{zone
												{zone "fpc4"}
											}
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag random_def}
											}
											{state
												{state inactive}
											}
										}
									}
									{amount 3
									}
								}
							}
						}
						{"default"}
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
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag cmp_def}
											}
										}
										{include
											{zone
												{zone "fpc5"}
											}
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag random_def}
											}
											{state
												{state inactive}
											}
										}
									}
								}
								{count
									{op ">"}
									{value 6}
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
												{tag cmp_def}
											}
										}
										{include
											{zone
												{zone "fpc5"}
											}
											{prop
												{prop human}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag random_def}
											}
											{state
												{state inactive}
											}
										}
									}
									{amount 3
									}
								}
							}
						}
						{"default"}
					}
					{"delay"
						{time 0.2}
					}
					{"delete"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag random_def}
									}
								}
								{include
									{tag
										{tag "1_a_1-3"}
									}
									{tag
										{tag "1_b_1-3"}
									}
									{state
										{state operatable}
									}
								}
							}
							{amount 10
							}
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
										{tag random_def}
									}
								}
								{include
									{tag
										{tag "2_a_1-3"}
									}
									{tag
										{tag "2_b_1-3"}
									}
									{state
										{state operatable}
									}
								}
							}
							{amount 10
							}
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
										{tag random_def}
									}
								}
								{include
									{tag
										{tag "3_a_1-3"}
									}
									{tag
										{tag "3_b_1-3"}
									}
									{state
										{state operatable}
									}
								}
							}
							{amount 10
							}
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
										{tag random_def}
									}
								}
								{include
									{tag
										{tag "4_a_1-3"}
									}
									{tag
										{tag "4_b_1-3"}
									}
									{state
										{state operatable}
									}
								}
							}
							{amount 10
							}
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
										{tag random_def}
									}
								}
								{include
									{tag
										{tag "5_a_1-3"}
									}
									{tag
										{tag "5_b_1-3"}
									}
									{state
										{state operatable}
									}
								}
							}
							{amount 10
							}
						}
					}
				}
			}
			{"cmp_def_b_mines"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag mine_planted}
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
						{"2.event"
							{id "init"}
						}
						{"3.cmp_i"
							{var "user_is_defender$"}
							{op "!="}
							{value 1}
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
									{ignore_captured_by_user 0}
									{tag fpc1}
									{zone "gamezone"}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"event"
								{event "flag1"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type rand}
										{value 0.1}
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
														{tag mines_1_b}
													}
													{tag
														{tag mines_1_c}
													}
													{tag
														{tag mines_1_d}
													}
												}
											}
										}
									}
								}
								{"case"
									{condition
										{type rand}
										{value 0.1}
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
														{tag mines_1_a}
													}
													{tag
														{tag mines_1_c}
													}
													{tag
														{tag mines_1_d}
													}
												}
											}
										}
									}
								}
								{"case"
									{condition
										{type rand}
										{value 0.1}
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
														{tag mines_1_a}
													}
													{tag
														{tag mines_1_b}
													}
													{tag
														{tag mines_1_d}
													}
												}
											}
										}
									}
								}
								{"case"
									{condition
										{type rand}
										{value 0.1}
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
														{tag mines_1_a}
													}
													{tag
														{tag mines_1_b}
													}
													{tag
														{tag mines_1_c}
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
														{tag "1_b_2-3"}
													}
												}
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
												{tag "1_b_2-3"}
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
					{"delay"
						{time 0.2}
					}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag fpc2}
									{zone "gamezone"}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"event"
								{event "flag2"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type rand}
										{value 0.1}
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
														{tag mines_2_b}
													}
													{tag
														{tag mines_2_c}
													}
													{tag
														{tag mines_2_d}
													}
												}
											}
										}
									}
								}
								{"case"
									{condition
										{type rand}
										{value 0.1}
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
														{tag mines_2_a}
													}
													{tag
														{tag mines_2_c}
													}
													{tag
														{tag mines_2_d}
													}
												}
											}
										}
									}
								}
								{"case"
									{condition
										{type rand}
										{value 0.1}
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
														{tag mines_2_a}
													}
													{tag
														{tag mines_2_b}
													}
													{tag
														{tag mines_2_d}
													}
												}
											}
										}
									}
								}
								{"case"
									{condition
										{type rand}
										{value 0.1}
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
														{tag mines_2_a}
													}
													{tag
														{tag mines_2_b}
													}
													{tag
														{tag mines_2_c}
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
														{tag "2_b_2-3"}
													}
												}
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
												{tag "2_b_2-3"}
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
					{"delay"
						{time 0.2}
					}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag fpc3}
									{zone "gamezone"}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"event"
								{event "flag3"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type rand}
										{value 0.1}
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
														{tag mines_3_b}
													}
													{tag
														{tag mines_3_c}
													}
													{tag
														{tag mines_3_d}
													}
												}
											}
										}
									}
								}
								{"case"
									{condition
										{type rand}
										{value 0.1}
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
														{tag mines_3_a}
													}
													{tag
														{tag mines_3_c}
													}
													{tag
														{tag mines_3_d}
													}
												}
											}
										}
									}
								}
								{"case"
									{condition
										{type rand}
										{value 0.1}
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
														{tag mines_3_a}
													}
													{tag
														{tag mines_3_b}
													}
													{tag
														{tag mines_3_d}
													}
												}
											}
										}
									}
								}
								{"case"
									{condition
										{type rand}
										{value 0.1}
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
														{tag mines_3_a}
													}
													{tag
														{tag mines_3_b}
													}
													{tag
														{tag mines_3_c}
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
														{tag "3_b_2-3"}
													}
												}
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
												{tag "3_b_2-3"}
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
					{"delay"
						{time 0.2}
					}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag fpc4}
									{zone "gamezone"}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"event"
								{event "flag4"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type rand}
										{value 0.1}
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
														{tag mines_4_b}
													}
													{tag
														{tag mines_4_c}
													}
													{tag
														{tag mines_4_d}
													}
												}
											}
										}
									}
								}
								{"case"
									{condition
										{type rand}
										{value 0.1}
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
														{tag mines_4_a}
													}
													{tag
														{tag mines_4_c}
													}
													{tag
														{tag mines_4_d}
													}
												}
											}
										}
									}
								}
								{"case"
									{condition
										{type rand}
										{value 0.1}
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
														{tag mines_4_a}
													}
													{tag
														{tag mines_4_b}
													}
													{tag
														{tag mines_4_d}
													}
												}
											}
										}
									}
								}
								{"case"
									{condition
										{type rand}
										{value 0.1}
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
														{tag mines_4_a}
													}
													{tag
														{tag mines_4_b}
													}
													{tag
														{tag mines_4_c}
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
														{tag "4_b_2-3"}
													}
												}
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
												{tag "4_b_2-3"}
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
					{"delay"
						{time 0.2}
					}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag fpc5}
									{zone "gamezone"}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"event"
								{event "flag5"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type rand}
										{value 0.1}
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
														{tag mines_5_b}
													}
													{tag
														{tag mines_5_c}
													}
													{tag
														{tag mines_5_d}
													}
												}
											}
										}
									}
								}
								{"case"
									{condition
										{type rand}
										{value 0.1}
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
														{tag mines_5_a}
													}
													{tag
														{tag mines_5_c}
													}
													{tag
														{tag mines_5_d}
													}
												}
											}
										}
									}
								}
								{"case"
									{condition
										{type rand}
										{value 0.1}
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
														{tag mines_5_a}
													}
													{tag
														{tag mines_5_b}
													}
													{tag
														{tag mines_5_d}
													}
												}
											}
										}
									}
								}
								{"case"
									{condition
										{type rand}
										{value 0.1}
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
														{tag mines_5_a}
													}
													{tag
														{tag mines_5_b}
													}
													{tag
														{tag mines_5_c}
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
														{tag "5_b_2-3"}
													}
												}
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
												{tag "5_b_2-3"}
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
				}
			}
			{"sandbag_mg_cmp_def"
				{condition
					{terms
						{"1.event"
							{id "init2"}
						}
					}
				}
				{actions
					{"delay"
						{time 3.9}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag cmp_mg}
						}
						{tag_remove cmp_mg}
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
												{tag "1_a_2-3"}
											}
											{tag
												{tag "2_a_2-3"}
											}
											{tag
												{tag "3_a_2-3"}
											}
											{tag
												{tag "4_a_2-3"}
											}
											{tag
												{tag "5_a_2-3"}
											}
										}
										{include
											{zone
												{zone "combat"}
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
														{tag cmp_def}
													}
												}
												{include
													{zone
														{zone "fpc1"}
													}
													{prop
														{prop human}
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
									{"delay"
										{time 0.1}
									}
									{"switch"
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag "1_a_2-3_mg"}
												}
												{count
													{op "=="}
													{value 2}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop vehicle}
															}
															{state
																{state inhabited}
															}
														}
														{exclude
															{tag
																{tag air_vehicle}
															}
															{prop
																{prop car}
															}
															{prop
																{prop tank}
															}
															{state
																{state user_control}
															}
														}
													}
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag "1_a_2-3_mg"}
														}
													}
													{amount 2
													}
												}
												{tag_add cmp_mg}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop human}
															}
															{state
																{state "operatable linked"}
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
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag fpc1}
														}
													}
													{amount 4
													}
												}
												{tag_add cmp_def}
											}
										}
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag "1_a_2-3_mg"}
												}
												{count
													{op "=="}
													{value 1}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop vehicle}
															}
															{state
																{state inhabited}
															}
														}
														{exclude
															{tag
																{tag air_vehicle}
															}
															{prop
																{prop car}
															}
															{prop
																{prop tank}
															}
															{state
																{state user_control}
															}
														}
													}
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag "1_a_2-3_mg"}
														}
													}
													{amount 1
													}
												}
												{tag_add cmp_mg}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop human}
															}
															{state
																{state "operatable linked"}
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
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag fpc1}
														}
													}
													{amount 2
													}
												}
												{tag_add cmp_def}
											}
										}
										{"default"}
									}
								}
								{"default"}
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
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag cmp_def}
													}
												}
												{include
													{zone
														{zone "fpc2"}
													}
													{prop
														{prop human}
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
									{"delay"
										{time 0.1}
									}
									{"switch"
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag "2_a_2-3_mg"}
												}
												{count
													{op "=="}
													{value 2}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop vehicle}
															}
															{state
																{state inhabited}
															}
														}
														{exclude
															{tag
																{tag cmp_mg}
															}
															{tag
																{tag air_vehicle}
															}
															{prop
																{prop car}
															}
															{prop
																{prop tank}
															}
															{state
																{state user_control}
															}
														}
													}
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag "2_a_2-3_mg"}
														}
													}
													{amount 2
													}
												}
												{tag_add cmp_mg}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop human}
															}
															{state
																{state "operatable linked"}
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
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag fpc2}
														}
													}
													{amount 4
													}
												}
												{tag_add cmp_def}
											}
										}
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag "2_a_2-3_mg"}
												}
												{count
													{op "=="}
													{value 1}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop vehicle}
															}
															{state
																{state inhabited}
															}
														}
														{exclude
															{tag
																{tag cmp_mg}
															}
															{tag
																{tag air_vehicle}
															}
															{prop
																{prop car}
															}
															{prop
																{prop tank}
															}
															{state
																{state user_control}
															}
														}
													}
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag "2_a_2-3_mg"}
														}
													}
													{amount 1
													}
												}
												{tag_add cmp_mg}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop human}
															}
															{state
																{state "operatable linked"}
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
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag fpc2}
														}
													}
													{amount 2
													}
												}
												{tag_add cmp_def}
											}
										}
										{"default"}
									}
								}
								{"default"}
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
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag cmp_def}
													}
												}
												{include
													{zone
														{zone "fpc3"}
													}
													{prop
														{prop human}
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
									{"delay"
										{time 0.1}
									}
									{"switch"
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag "3_a_2-3_mg"}
												}
												{count
													{op "=="}
													{value 2}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop vehicle}
															}
															{state
																{state inhabited}
															}
														}
														{exclude
															{tag
																{tag cmp_mg}
															}
															{tag
																{tag air_vehicle}
															}
															{prop
																{prop car}
															}
															{prop
																{prop tank}
															}
															{state
																{state user_control}
															}
														}
													}
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag "3_a_2-3_mg"}
														}
													}
													{amount 2
													}
												}
												{tag_add cmp_mg}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop human}
															}
															{state
																{state "operatable linked"}
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
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag fpc3}
														}
													}
													{amount 4
													}
												}
												{tag_add cmp_def}
											}
										}
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag "3_a_2-3_mg"}
												}
												{count
													{op "=="}
													{value 1}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop vehicle}
															}
															{state
																{state inhabited}
															}
														}
														{exclude
															{tag
																{tag cmp_mg}
															}
															{tag
																{tag air_vehicle}
															}
															{prop
																{prop car}
															}
															{prop
																{prop tank}
															}
															{state
																{state user_control}
															}
														}
													}
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag "3_a_2-3_mg"}
														}
													}
													{amount 1
													}
												}
												{tag_add cmp_mg}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop human}
															}
															{state
																{state "operatable linked"}
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
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag fpc3}
														}
													}
													{amount 2
													}
												}
												{tag_add cmp_def}
											}
										}
										{"default"}
									}
								}
								{"default"}
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
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag cmp_def}
													}
												}
												{include
													{zone
														{zone "fpc4"}
													}
													{prop
														{prop human}
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
									{"delay"
										{time 0.1}
									}
									{"switch"
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag "4_a_2-3_mg"}
												}
												{count
													{op "=="}
													{value 2}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop vehicle}
															}
															{state
																{state inhabited}
															}
														}
														{exclude
															{tag
																{tag cmp_mg}
															}
															{tag
																{tag air_vehicle}
															}
															{prop
																{prop car}
															}
															{prop
																{prop tank}
															}
															{state
																{state user_control}
															}
														}
													}
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag "4_a_2-3_mg"}
														}
													}
													{amount 2
													}
												}
												{tag_add cmp_mg}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop human}
															}
															{state
																{state "operatable linked"}
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
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag fpc4}
														}
													}
													{amount 4
													}
												}
												{tag_add cmp_def}
											}
										}
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag "4_a_2-3_mg"}
												}
												{count
													{op "=="}
													{value 1}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop vehicle}
															}
															{state
																{state inhabited}
															}
														}
														{exclude
															{tag
																{tag cmp_mg}
															}
															{tag
																{tag air_vehicle}
															}
															{prop
																{prop car}
															}
															{prop
																{prop tank}
															}
															{state
																{state user_control}
															}
														}
													}
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag "4_a_2-3_mg"}
														}
													}
													{amount 1
													}
												}
												{tag_add cmp_mg}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop human}
															}
															{state
																{state "operatable linked"}
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
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag fpc4}
														}
													}
													{amount 2
													}
												}
												{tag_add cmp_def}
											}
										}
										{"default"}
									}
								}
								{"default"}
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
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag cmp_def}
													}
												}
												{include
													{zone
														{zone "fpc5"}
													}
													{prop
														{prop human}
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
									{"delay"
										{time 0.1}
									}
									{"switch"
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag "5_a_2-3_mg"}
												}
												{count
													{op "=="}
													{value 2}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop vehicle}
															}
															{state
																{state inhabited}
															}
														}
														{exclude
															{tag
																{tag cmp_mg}
															}
															{tag
																{tag air_vehicle}
															}
															{prop
																{prop car}
															}
															{prop
																{prop tank}
															}
															{state
																{state user_control}
															}
														}
													}
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag "5_a_2-3_mg"}
														}
													}
													{amount 2
													}
												}
												{tag_add cmp_mg}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop human}
															}
															{state
																{state "operatable linked"}
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
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag fpc5}
														}
													}
													{amount 4
													}
												}
												{tag_add cmp_def}
											}
										}
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag "5_a_2-3_mg"}
												}
												{count
													{op "=="}
													{value 1}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop vehicle}
															}
															{state
																{state inhabited}
															}
														}
														{exclude
															{tag
																{tag cmp_mg}
															}
															{tag
																{tag air_vehicle}
															}
															{prop
																{prop car}
															}
															{prop
																{prop tank}
															}
															{state
																{state user_control}
															}
														}
													}
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag "5_a_2-3_mg"}
														}
													}
													{amount 1
													}
												}
												{tag_add cmp_mg}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop human}
															}
															{state
																{state "operatable linked"}
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
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag fpc5}
														}
													}
													{amount 2
													}
												}
												{tag_add cmp_def}
											}
										}
										{"default"}
									}
								}
								{"default"}
							}
							{"delay"
								{time 0.5}
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
												{tag "1_b_2-3"}
											}
											{tag
												{tag "2_b_2-3"}
											}
											{tag
												{tag "3_b_2-3"}
											}
											{tag
												{tag "4_b_2-3"}
											}
											{tag
												{tag "5_b_2-3"}
											}
										}
										{include
											{zone
												{zone "combat"}
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
														{tag cmp_def}
													}
												}
												{include
													{zone
														{zone "fpc1"}
													}
													{prop
														{prop human}
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
									{"delay"
										{time 0.1}
									}
									{"switch"
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag "1_b_2-3_mg"}
												}
												{count
													{op "=="}
													{value 2}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop vehicle}
															}
															{state
																{state inhabited}
															}
														}
														{exclude
															{tag
																{tag air_vehicle}
															}
															{prop
																{prop car}
															}
															{prop
																{prop tank}
															}
															{state
																{state user_control}
															}
														}
													}
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag "1_b_2-3_mg"}
														}
													}
													{amount 2
													}
												}
												{tag_add cmp_mg}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop human}
															}
															{state
																{state "operatable linked"}
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
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag fpc1}
														}
													}
													{amount 4
													}
												}
												{tag_add cmp_def}
											}
										}
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag "1_b_2-3_mg"}
												}
												{count
													{op "=="}
													{value 1}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop vehicle}
															}
															{state
																{state inhabited}
															}
														}
														{exclude
															{tag
																{tag air_vehicle}
															}
															{prop
																{prop car}
															}
															{prop
																{prop tank}
															}
															{state
																{state user_control}
															}
														}
													}
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag "1_b_2-3_mg"}
														}
													}
													{amount 1
													}
												}
												{tag_add cmp_mg}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop human}
															}
															{state
																{state "operatable linked"}
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
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag fpc1}
														}
													}
													{amount 2
													}
												}
												{tag_add cmp_def}
											}
										}
										{"default"}
									}
								}
								{"default"}
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
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag cmp_def}
													}
												}
												{include
													{zone
														{zone "fpc2"}
													}
													{prop
														{prop human}
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
									{"delay"
										{time 0.1}
									}
									{"switch"
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag "2_b_2-3_mg"}
												}
												{count
													{op "=="}
													{value 2}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop vehicle}
															}
															{state
																{state inhabited}
															}
														}
														{exclude
															{tag
																{tag cmp_mg}
															}
															{tag
																{tag air_vehicle}
															}
															{prop
																{prop car}
															}
															{prop
																{prop tank}
															}
															{state
																{state user_control}
															}
														}
													}
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag "2_b_2-3_mg"}
														}
													}
													{amount 2
													}
												}
												{tag_add cmp_mg}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop human}
															}
															{state
																{state "operatable linked"}
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
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag fpc2}
														}
													}
													{amount 4
													}
												}
												{tag_add cmp_def}
											}
										}
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag "2_b_2-3_mg"}
												}
												{count
													{op "=="}
													{value 1}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop vehicle}
															}
															{state
																{state inhabited}
															}
														}
														{exclude
															{tag
																{tag cmp_mg}
															}
															{tag
																{tag air_vehicle}
															}
															{prop
																{prop car}
															}
															{prop
																{prop tank}
															}
															{state
																{state user_control}
															}
														}
													}
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag "2_b_2-3_mg"}
														}
													}
													{amount 1
													}
												}
												{tag_add cmp_mg}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop human}
															}
															{state
																{state "operatable linked"}
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
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag fpc2}
														}
													}
													{amount 2
													}
												}
												{tag_add cmp_def}
											}
										}
										{"default"}
									}
								}
								{"default"}
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
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag cmp_def}
													}
												}
												{include
													{zone
														{zone "fpc3"}
													}
													{prop
														{prop human}
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
									{"delay"
										{time 0.1}
									}
									{"switch"
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag "3_b_2-3_mg"}
												}
												{count
													{op "=="}
													{value 2}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop vehicle}
															}
															{state
																{state inhabited}
															}
														}
														{exclude
															{tag
																{tag cmp_mg}
															}
															{tag
																{tag air_vehicle}
															}
															{prop
																{prop car}
															}
															{prop
																{prop tank}
															}
															{state
																{state user_control}
															}
														}
													}
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag "3_b_2-3_mg"}
														}
													}
													{amount 2
													}
												}
												{tag_add cmp_mg}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop human}
															}
															{state
																{state "operatable linked"}
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
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag fpc3}
														}
													}
													{amount 4
													}
												}
												{tag_add cmp_def}
											}
										}
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag "3_b_2-3_mg"}
												}
												{count
													{op "=="}
													{value 1}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop vehicle}
															}
															{state
																{state inhabited}
															}
														}
														{exclude
															{tag
																{tag cmp_mg}
															}
															{tag
																{tag air_vehicle}
															}
															{prop
																{prop car}
															}
															{prop
																{prop tank}
															}
															{state
																{state user_control}
															}
														}
													}
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag "3_b_2-3_mg"}
														}
													}
													{amount 1
													}
												}
												{tag_add cmp_mg}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop human}
															}
															{state
																{state "operatable linked"}
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
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag fpc3}
														}
													}
													{amount 2
													}
												}
												{tag_add cmp_def}
											}
										}
										{"default"}
									}
								}
								{"default"}
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
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag cmp_def}
													}
												}
												{include
													{zone
														{zone "fpc4"}
													}
													{prop
														{prop human}
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
									{"delay"
										{time 0.1}
									}
									{"switch"
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag "4_b_2-3_mg"}
												}
												{count
													{op "=="}
													{value 2}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop vehicle}
															}
															{state
																{state inhabited}
															}
														}
														{exclude
															{tag
																{tag cmp_mg}
															}
															{tag
																{tag air_vehicle}
															}
															{prop
																{prop car}
															}
															{prop
																{prop tank}
															}
															{state
																{state user_control}
															}
														}
													}
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag "4_b_2-3_mg"}
														}
													}
													{amount 2
													}
												}
												{tag_add cmp_mg}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop human}
															}
															{state
																{state "operatable linked"}
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
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag fpc4}
														}
													}
													{amount 4
													}
												}
												{tag_add cmp_def}
											}
										}
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag "4_b_2-3_mg"}
												}
												{count
													{op "=="}
													{value 1}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop vehicle}
															}
															{state
																{state inhabited}
															}
														}
														{exclude
															{tag
																{tag cmp_mg}
															}
															{tag
																{tag air_vehicle}
															}
															{prop
																{prop car}
															}
															{prop
																{prop tank}
															}
															{state
																{state user_control}
															}
														}
													}
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag "4_b_2-3_mg"}
														}
													}
													{amount 1
													}
												}
												{tag_add cmp_mg}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop human}
															}
															{state
																{state "operatable linked"}
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
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag fpc4}
														}
													}
													{amount 2
													}
												}
												{tag_add cmp_def}
											}
										}
										{"default"}
									}
								}
								{"default"}
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
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag cmp_def}
													}
												}
												{include
													{zone
														{zone "fpc5"}
													}
													{prop
														{prop human}
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
									{"delay"
										{time 0.1}
									}
									{"switch"
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag "5_b_2-3_mg"}
												}
												{count
													{op "=="}
													{value 2}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop vehicle}
															}
															{state
																{state inhabited}
															}
														}
														{exclude
															{tag
																{tag cmp_mg}
															}
															{tag
																{tag air_vehicle}
															}
															{prop
																{prop car}
															}
															{prop
																{prop tank}
															}
															{state
																{state user_control}
															}
														}
													}
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag "5_b_2-3_mg"}
														}
													}
													{amount 2
													}
												}
												{tag_add cmp_mg}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop human}
															}
															{state
																{state "operatable linked"}
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
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag fpc5}
														}
													}
													{amount 4
													}
												}
												{tag_add cmp_def}
											}
										}
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag "5_b_2-3_mg"}
												}
												{count
													{op "=="}
													{value 1}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop vehicle}
															}
															{state
																{state inhabited}
															}
														}
														{exclude
															{tag
																{tag cmp_mg}
															}
															{tag
																{tag air_vehicle}
															}
															{prop
																{prop car}
															}
															{prop
																{prop tank}
															}
															{state
																{state user_control}
															}
														}
													}
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag "5_b_2-3_mg"}
														}
													}
													{amount 1
													}
												}
												{tag_add cmp_mg}
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
															{zone
																{zone "combat"}
															}
														}
														{include
															{prop
																{prop human}
															}
															{state
																{state "operatable linked"}
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
													{sort
														{type entity}
														{entity
															{ignore_captured_by_user 0}
															{tag fpc5}
														}
													}
													{amount 2
													}
												}
												{tag_add cmp_def}
											}
										}
										{"default"}
									}
								}
								{"default"}
							}
							{"delay"
								{time 0.5}
							}
						}
						{"default"}
					}
					{"delay"
						{time 0.5}
					}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag cmp_mg}
									{type vehicle}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"effect"
								{selector
									{ignore_captured_by_user 0}
									{tag cmp_mg}
									{type vehicle}
								}
								{effect construction_sandbag_cannon_standard}
							}
							{"delay"
								{time 2}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "user_is_defender$"}
										{op "=="}
										{value 1}
									}
									{"delay"
										{time 0.1}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag cmp_mg}
										}
										{tag_add cmp_def}
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
													{zone
														{zone "combat"}
													}
												}
												{include
													{state
														{state operatable}
													}
												}
												{exclude
													{tag
														{tag _user}
													}
													{tag
														{tag cmp_def}
													}
													{tag
														{tag air_vehicle}
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
										{tag_add cmp_def}
									}
									{"delay"
										{time 0.5}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag cmp_def}
										}
										{tag_remove bot}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag cmp_def}
										}
										{tag_remove _bot}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag cmp_def}
										}
										{tag_remove _ai}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag cmp_def}
										}
										{tag_remove bot_veh}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"ables"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag cmp_mg}
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
										{remove select}
									}
								}
							}
						}
						{"default"}
					}
					{"delay"
						{time 1}
					}
					{"set_i"
						{var "dcg_on$"}
						{op "+"}
						{value 1}
					}
				}
			}
			{"dcg/ai_air_decide"
				{condition
					{terms
						{"1.event"
							{id "ai_air_possible"}
						}
						{"2.cmp_i"
							{var "ai_air_on$"}
							{op "=="}
							{value 0}
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
									{ignore_captured_by_user 0}
									{tag fpc1}
									{zone "gamezone"}
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
											{ignore_captured_by_user 0}
											{tag player}
											{zone "fpc1"}
											{type human}
											{state "not dead"}
										}
									}
									{"delay"
										{time 0.1}
									}
									{"set_i"
										{var "ai_air_on$"}
										{op "="}
										{value 1}
									}
								}
								{"default"}
							}
						}
						{"default"}
					}
					{"delay"
						{time 2}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "ai_air_on$"}
								{op "=="}
								{value 0}
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
											{tag fpc2}
											{zone "gamezone"}
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
													{ignore_captured_by_user 0}
													{tag player}
													{zone "fpc2"}
													{type human}
													{state "not dead"}
												}
											}
											{"delay"
												{time 0.1}
											}
											{"set_i"
												{var "ai_air_on$"}
												{op "="}
												{value 2}
											}
										}
										{"default"}
									}
								}
								{"default"}
							}
						}
						{"default"}
					}
					{"delay"
						{time 2}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "ai_air_on$"}
								{op "=="}
								{value 0}
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
											{tag fpc3}
											{zone "gamezone"}
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
													{ignore_captured_by_user 0}
													{tag player}
													{zone "fpc3"}
													{type human}
													{state "not dead"}
												}
											}
											{"delay"
												{time 0.1}
											}
											{"set_i"
												{var "ai_air_on$"}
												{op "="}
												{value 3}
											}
										}
										{"default"}
									}
								}
								{"default"}
							}
						}
						{"default"}
					}
					{"delay"
						{time 2}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "ai_air_on$"}
								{op "=="}
								{value 0}
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
											{tag fpc4}
											{zone "gamezone"}
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
													{ignore_captured_by_user 0}
													{tag player}
													{zone "fpc4"}
													{type human}
													{state "not dead"}
												}
											}
											{"delay"
												{time 0.1}
											}
											{"set_i"
												{var "ai_air_on$"}
												{op "="}
												{value 4}
											}
										}
										{"default"}
									}
								}
								{"default"}
							}
						}
						{"default"}
					}
					{"delay"
						{time 2}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "ai_air_on$"}
								{op "=="}
								{value 0}
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
											{tag fpc5}
											{zone "gamezone"}
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
													{ignore_captured_by_user 0}
													{tag player}
													{zone "fpc5"}
													{type human}
													{state "not dead"}
												}
											}
											{"delay"
												{time 0.1}
											}
											{"set_i"
												{var "ai_air_on$"}
												{op "="}
												{value 5}
											}
										}
										{"default"}
									}
								}
								{"default"}
							}
						}
						{"default"}
					}
					{"delay"
						{time 50}
					}
					{"trigger"
						{name "dcg/ai_air_decide"}
					}
				}
			}
			{"dcg/def_team"
				{condition
					{terms
						{"1.event"
							{id "dcg"}
						}
						{"2.cmp_i"
							{var "user_team$"}
							{op ">"}
							{value 0}
						}
						{"3.cmp_i"
							{var "enemyid$"}
							{op ">"}
							{value 0}
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
								{var "user_is_defender$"}
								{op "=="}
								{value 1}
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
						{"default"}
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
												{tag def_team_1}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
										}
										{exclude
											{tag
												{tag def_team_2}
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
							{"set_i"
								{var "def_team$"}
								{op "="}
								{value 1}
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
											{state
												{state inactive}
											}
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
												{tag def_team_2}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
										}
										{exclude
											{tag
												{tag def_team_1}
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
							{"set_i"
								{var "def_team$"}
								{op "="}
								{value 2}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"set_i"
								{var "def_team$"}
								{op "="}
								{value "user_team$"}
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
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag "1_a_2-3"}
											}
											{tag
												{tag "2_a_2-3"}
											}
											{tag
												{tag "3_a_2-3"}
											}
											{tag
												{tag "4_a_2-3"}
											}
											{tag
												{tag "5_a_2-3"}
											}
										}
										{include
											{zone
												{zone "combat"}
											}
										}
										{exclude
											{tag
												{tag hidden}
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
							{"set_i"
								{var "tier2$"}
								{op "="}
								{value 1}
							}
						}
						{"default"}
					}
					{"delay"
						{time 1}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "tier2$"}
								{op "=="}
								{value 0}
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
														{tag "1_b_2-3"}
													}
													{tag
														{tag "2_b_2-3"}
													}
													{tag
														{tag "3_b_2-3"}
													}
													{tag
														{tag "4_b_2-3"}
													}
													{tag
														{tag "5_b_2-3"}
													}
												}
												{include
													{zone
														{zone "combat"}
													}
												}
												{exclude
													{tag
														{tag hidden}
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
									{"set_i"
										{var "tier2$"}
										{op "="}
										{value 1}
									}
								}
								{"default"}
							}
						}
						{"default"}
					}
					{"delay"
						{time 0.9}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "tier2$"}
								{op "=="}
								{value 1}
							}
						}
						{"default"
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
											{state
												{state inactive}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"delete"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag def_team_1}
									}
									{tag
										{tag def_team_2}
									}
								}
							}
						}
					}
				}
			}
			{"dcg/ai_airstrike"
				{condition
					{terms
						{"1.event"
							{id "ai_air_on"}
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
							{tag enemy_air}
						}
						{tag_remove enemy_air}
					}
					{"delay"
						{time 0.1}
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
												{tag airstrike_ger}
											}
											{tag
												{tag airstrike_rus}
											}
											{tag
												{tag airstrike_fin}
											}
											{tag
												{tag airstrike_usa}
											}
										}
										{include
											{tag
												{tag hidden}
											}
										}
									}
									{amount 1
									}
								}
								{waypoint "0"}
								{clone}
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
												{tag airstrike_ger}
											}
											{tag
												{tag airstrike_rus}
											}
											{tag
												{tag airstrike_fin}
											}
											{tag
												{tag airstrike_usa}
											}
										}
										{include
											{tag
												{tag hidden}
											}
										}
									}
									{amount 1
									}
								}
								{waypoint "6"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
					}
				}
			}
			{"dcg/ai_airstrike_do"
				{condition
					{expression "(1 & 2 & 4) | (1 & 3 & !4)"}
					{terms
						{"1.event"
							{id "ai_air_on"}
						}
						{"2.near"
							{units
								{ignore_captured_by_user 0}
								{tag enemy_air}
								{type vehicle}
								{state inhabited}
							}
							{near_to
								{ignore_captured_by_user 0}
								{tag spawn_a}
							}
							{distance 76}
						}
						{"3.near"
							{units
								{ignore_captured_by_user 0}
								{tag enemy_air}
								{type vehicle}
								{state inhabited}
							}
							{near_to
								{ignore_captured_by_user 0}
								{tag spawn_b}
							}
							{distance 76}
						}
						{"4.cmp_i"
							{var "user_team$"}
							{op "=="}
							{value 1}
						}
					}
				}
				{actions
					{"delay"
						{time 4.5}
					}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag ai_air_target}
									{zone "gamezone"}
								}
							}
							{"delay"
								{time 0.1}
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
								}
								{tag_add ai_air_target}
							}
						}
					}
					{"delay"
						{time 1.1}
					}
					{"switch"
						{"default"
							{"delay"
								{time 0.1}
							}
							{"air_attack"
								{selector
									{ignore_captured_by_user 0}
									{tag enemy_air}
									{type vehicle}
									{state inhabited}
								}
								{drop "orders sensor senseless"}
								{enemies
									{ignore_captured_by_user 0}
									{tag ai_air_target}
								}
								{attack_altitude 46}
							}
						}
					}
				}
			}
			{"dcg/ai_air_chance"
				{condition
					{terms
						{"1.event"
							{id "airplane_set"}
						}
						{"2.cmp_i"
							{var "user_team$"}
							{op ">"}
							{value 0}
						}
						{"3.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 1}
						}
						{"4.cmp_i"
							{var "tier2$"}
							{op "=="}
							{value 1}
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
								{value 0.2}
							}
							{"delay"
								{time 660}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.2}
							}
							{"delay"
								{time 900}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.2}
							}
							{"delay"
								{time 950}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.2}
							}
							{"delay"
								{time 800}
							}
						}
						{"default"
							{"delay"
								{time 700}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"switch"
						{"case"
							{condition
								{type rand}
								{value 0.25}
							}
							{"delay"
								{time 0.1}
							}
							{"trigger"
								{name "dcg/ai_air_chance"}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"event"
								{event "ai_air_possible"}
								{mode set}
								{delay 0}
							}
						}
					}
				}
			}
			{"dcg/ai_air_on"
				{condition
					{terms
						{"1.event"
							{id "dcg"}
						}
						{"2.cmp_i"
							{var "enemyid$"}
							{op ">"}
							{value 0}
						}
						{"3.entities"
							{selector
								{ignore_captured_by_user 0}
								{tag _user}
								{zone "gamezone"}
								{state operatable}
							}
						}
						{"4.cmp_i"
							{var "ai_air_on$"}
							{op ">"}
							{value 0}
						}
						{"5.cmp_i"
							{var "dcg_on$"}
							{op ">"}
							{value 0}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"event"
						{event "ai_air_on"}
						{mode set}
						{delay 0}
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
												{tag _user}
											}
										}
										{include
											{zone
												{zone "combat"}
											}
											{prop
												{prop vehicle}
											}
											{state
												{state operatable}
											}
											{state
												{state user_control}
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
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "ai_air_on$"}
										{op "=="}
										{value 5}
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
														{tag _user}
													}
												}
												{include
													{zone
														{zone "gamezone"}
													}
													{prop
														{prop vehicle}
													}
													{state
														{state operatable}
													}
													{state
														{state user_control}
													}
												}
												{exclude
													{tag
														{tag destroyed}
													}
												}
											}
											{sort
												{type waypoint}
												{wpid "5"}
											}
											{amount 1
											}
										}
										{tag_add ai_air_target}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "ai_air_on$"}
										{op "=="}
										{value 2}
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
														{tag _user}
													}
												}
												{include
													{zone
														{zone "gamezone"}
													}
													{prop
														{prop vehicle}
													}
													{state
														{state operatable}
													}
													{state
														{state user_control}
													}
												}
												{exclude
													{tag
														{tag destroyed}
													}
												}
											}
											{sort
												{type waypoint}
												{wpid "2"}
											}
											{amount 1
											}
										}
										{tag_add ai_air_target}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "ai_air_on$"}
										{op "=="}
										{value 3}
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
														{tag _user}
													}
												}
												{include
													{zone
														{zone "gamezone"}
													}
													{prop
														{prop vehicle}
													}
													{state
														{state operatable}
													}
													{state
														{state user_control}
													}
												}
												{exclude
													{tag
														{tag destroyed}
													}
												}
											}
											{sort
												{type waypoint}
												{wpid "3"}
											}
											{amount 1
											}
										}
										{tag_add ai_air_target}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "ai_air_on$"}
										{op "=="}
										{value 4}
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
														{tag _user}
													}
												}
												{include
													{zone
														{zone "gamezone"}
													}
													{prop
														{prop vehicle}
													}
													{state
														{state operatable}
													}
													{state
														{state user_control}
													}
												}
												{exclude
													{tag
														{tag destroyed}
													}
												}
											}
											{sort
												{type waypoint}
												{wpid "4"}
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
													{prop
														{prop vehicle}
													}
													{state
														{state operatable}
													}
													{state
														{state user_control}
													}
												}
												{exclude
													{tag
														{tag destroyed}
													}
												}
											}
											{sort
												{type waypoint}
												{wpid "1"}
											}
											{amount 1
											}
										}
										{tag_add ai_air_target}
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
										{type cmp_i}
										{var "ai_air_on$"}
										{op "=="}
										{value 5}
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
												}
											}
											{sort
												{type waypoint}
												{wpid "5"}
											}
											{amount 1
											}
										}
										{tag_add ai_air_target}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "ai_air_on$"}
										{op "=="}
										{value 2}
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
												}
											}
											{sort
												{type waypoint}
												{wpid "2"}
											}
											{amount 1
											}
										}
										{tag_add ai_air_target}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "ai_air_on$"}
										{op "=="}
										{value 3}
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
												}
											}
											{sort
												{type waypoint}
												{wpid "3"}
											}
											{amount 1
											}
										}
										{tag_add ai_air_target}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "ai_air_on$"}
										{op "=="}
										{value 4}
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
												}
											}
											{sort
												{type waypoint}
												{wpid "4"}
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
												}
											}
											{sort
												{type waypoint}
												{wpid "1"}
											}
											{amount 1
											}
										}
										{tag_add ai_air_target}
									}
								}
							}
						}
					}
				}
			}
			{"dcg/init"
				{condition
					{expression "1"}
					{terms
						{"1.event"
							{id "init2"}
						}
					}
				}
				{actions
					{"delay"
						{time 3}
					}
					{"set_i"
						{var "ai_air_on$"}
						{op "="}
						{value 0}
					}
					{"set_i"
						{var "def_team$"}
						{op "="}
						{value 0}
					}
					{"set_i"
						{var "tier2$"}
						{op "="}
						{value 0}
					}
					{"set_i"
						{var "user_nation$"}
						{op "="}
						{value 0}
					}
					{"delay"
						{time 0.4}
					}
					{"event"
						{event "dcg"}
						{mode set}
						{delay 0}
					}
					{"delay"
						{time 1}
					}
					{"set_i"
						{var "dcg_on$"}
						{op "+"}
						{value 1}
					}
				}
			}
			{"dcg/nation_init"
				{condition
					{terms
						{"1.event"
							{id "dcg"}
						}
						{"2.cmp_i"
							{var "bot_army$"}
							{op ">"}
							{value 0}
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
								{type cmp_i}
								{var "bot_army$"}
								{op "=="}
								{value 1}
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
												{tag airstrike_ger}
											}
											{tag
												{tag airstrike_fin}
											}
											{tag
												{tag airstrike_usa}
											}
										}
									}
								}
							}
							{"delay"
								{time 1}
							}
							{"set_i"
								{var "dcg_on$"}
								{op "+"}
								{value 1}
							}
							{"delay"
								{time 1}
							}
							{"event"
								{event "airplane_set"}
								{mode set}
								{delay 0}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "bot_army$"}
								{op "=="}
								{value 2}
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
												{tag airstrike_rus}
											}
											{tag
												{tag airstrike_fin}
											}
											{tag
												{tag airstrike_usa}
											}
										}
									}
								}
							}
							{"delay"
								{time 1}
							}
							{"set_i"
								{var "dcg_on$"}
								{op "+"}
								{value 1}
							}
							{"delay"
								{time 1}
							}
							{"event"
								{event "airplane_set"}
								{mode set}
								{delay 0}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "bot_army$"}
								{op "=="}
								{value 3}
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
												{tag airstrike_rus}
											}
											{tag
												{tag airstrike_ger}
											}
											{tag
												{tag airstrike_usa}
											}
										}
									}
								}
							}
							{"delay"
								{time 1}
							}
							{"set_i"
								{var "dcg_on$"}
								{op "+"}
								{value 1}
							}
							{"delay"
								{time 1}
							}
							{"event"
								{event "airplane_set"}
								{mode set}
								{delay 0}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "bot_army$"}
								{op "=="}
								{value 4}
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
												{tag airstrike_ger}
											}
											{tag
												{tag airstrike_fin}
											}
											{tag
												{tag airstrike_rus}
											}
										}
									}
								}
							}
							{"delay"
								{time 1}
							}
							{"set_i"
								{var "dcg_on$"}
								{op "+"}
								{value 1}
							}
							{"delay"
								{time 1}
							}
							{"event"
								{event "airplane_set"}
								{mode set}
								{delay 0}
							}
						}
						{"default"
							{"delay"
								{time 1}
							}
							{"set_i"
								{var "dcg_on$"}
								{op "+"}
								{value 1}
							}
						}
					}
				}
			}
			{"dcg/enemyai_teamid"
				{condition
					{terms
						{"1.event"
							{id "dcg"}
						}
						{"2.cmp_i"
							{var "dcg_on$"}
							{op ">"}
							{value 0}
						}
						{"3.cmp_i"
							{var "enemyid$"}
							{op ">"}
							{value 0}
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
								{type cmp_i}
								{var "enemyid$"}
								{op "=="}
								{value 1}
							}
							{"delay"
								{time 0.1}
							}
							{"player"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag airstrike_ger}
											}
											{tag
												{tag airstrike_rus}
											}
											{tag
												{tag airstrike_fin}
											}
											{tag
												{tag airstrike_usa}
											}
										}
										{include
											{prop
												{prop vehicle}
											}
										}
									}
								}
								{operation set}
								{player "1"}
							}
							{"player"
								{selector
									{ignore_captured_by_user 0}
									{tag pilot}
									{type human}
								}
								{operation set}
								{player "1"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "enemyid$"}
								{op "=="}
								{value 2}
							}
							{"delay"
								{time 0.1}
							}
							{"player"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag airstrike_ger}
											}
											{tag
												{tag airstrike_rus}
											}
											{tag
												{tag airstrike_fin}
											}
											{tag
												{tag airstrike_usa}
											}
										}
										{include
											{prop
												{prop vehicle}
											}
										}
									}
								}
								{operation set}
								{player "2"}
							}
							{"player"
								{selector
									{ignore_captured_by_user 0}
									{tag pilot}
									{type human}
								}
								{operation set}
								{player "2"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "enemyid$"}
								{op "=="}
								{value 3}
							}
							{"delay"
								{time 0.1}
							}
							{"player"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag airstrike_ger}
											}
											{tag
												{tag airstrike_rus}
											}
											{tag
												{tag airstrike_fin}
											}
											{tag
												{tag airstrike_usa}
											}
										}
										{include
											{prop
												{prop vehicle}
											}
										}
									}
								}
								{operation set}
								{player "3"}
							}
							{"player"
								{selector
									{ignore_captured_by_user 0}
									{tag pilot}
									{type human}
								}
								{operation set}
								{player "3"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "enemyid$"}
								{op "=="}
								{value 4}
							}
							{"delay"
								{time 0.1}
							}
							{"player"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag airstrike_ger}
											}
											{tag
												{tag airstrike_rus}
											}
											{tag
												{tag airstrike_fin}
											}
											{tag
												{tag airstrike_usa}
											}
										}
										{include
											{prop
												{prop vehicle}
											}
										}
									}
								}
								{operation set}
								{player "4"}
							}
							{"player"
								{selector
									{ignore_captured_by_user 0}
									{tag pilot}
									{type human}
								}
								{operation set}
								{player "4"}
							}
						}
						{"default"
							{"delay"
								{time 0.2}
							}
							{"set_i"
								{var "enemyid$"}
								{op "="}
								{value 5}
							}
							{"player"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag airstrike_ger}
											}
											{tag
												{tag airstrike_rus}
											}
											{tag
												{tag airstrike_fin}
											}
											{tag
												{tag airstrike_usa}
											}
										}
										{include
											{prop
												{prop vehicle}
											}
										}
									}
								}
								{operation set}
								{player "5"}
							}
							{"player"
								{selector
									{ignore_captured_by_user 0}
									{tag pilot}
									{type human}
								}
								{operation set}
								{player "5"}
							}
							{"objective_progress"
								{set 0}
								{add 0}
								{title "dcg eid error 01 - enemyid above 4!"}
							}
							{"delay"
								{time 5}
							}
							{"objective_progress"
								{hide}
								{set 0}
								{add 0}
								{title "dcg eid error 01 - enemyid above 4!"}
							}
						}
					}
				}
			}
			{"dcg/player_nation"
				{condition
					{expression "1 & !2 & 3"}
					{terms
						{"1.entities"
							{selector
								{ignore_captured_by_user 0}
								{tag player}
								{zone "gamezone"}
								{type human}
								{state "not dead"}
							}
						}
						{"2.cmp_i"
							{var "user_nation$"}
							{op ">"}
							{value 0}
						}
						{"3.event"
							{id "dcg"}
						}
					}
				}
				{actions
					{"delay"
						{time 0.9}
					}
					{"switch"
						{"case"
							{condition
								{type side}
								{side rus}
							}
							{"delay"
								{time 0.1}
							}
							{"set_i"
								{var "user_nation$"}
								{op "="}
								{value 1}
							}
						}
						{"case"
							{condition
								{type side}
								{side ger}
							}
							{"delay"
								{time 0.1}
							}
							{"set_i"
								{var "user_nation$"}
								{op "="}
								{value 2}
							}
						}
						{"case"
							{condition
								{type side}
								{side fin}
							}
							{"delay"
								{time 0.1}
							}
							{"set_i"
								{var "user_nation$"}
								{op "="}
								{value 3}
							}
						}
						{"case"
							{condition
								{type side}
								{side usa}
							}
							{"delay"
								{time 0.1}
							}
							{"set_i"
								{var "user_nation$"}
								{op "="}
								{value 4}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"set_i"
								{var "user_nation$"}
								{op "="}
								{value 1}
							}
							{"delay"
								{time 0.1}
							}
							{"objective_progress"
								{set 0}
								{add 0}
								{title "dcg side 01 error - report if you see this"}
							}
							{"delay"
								{time 30}
							}
							{"objective_progress"
								{hide}
								{set 0}
								{add 0}
								{title "dcg side 01 error - report if you see this"}
							}
						}
					}
				}
			}
			{"dcg/players_units"
				{condition
					{terms
						{"1.entities"
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
										{state
											{state user_control}
										}
									}
									{exclude
										{tag
											{tag _user}
										}
									}
								}
							}
						}
						{"2.event"
							{id "dcg"}
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
									{state
										{state user_control}
									}
								}
								{exclude
									{tag
										{tag _user}
									}
								}
							}
						}
						{tag_add _user}
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
										{tag _user}
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
									{tag
										{tag hidden}
									}
									{tag
										{tag player}
									}
								}
							}
						}
						{tag_add player}
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
										{tag _user}
									}
								}
								{include
									{prop
										{prop tank}
									}
									{state
										{state "operatable user_control"}
									}
								}
								{exclude
									{tag
										{tag player_armor}
									}
									{tag
										{tag no_scavenge}
									}
								}
							}
						}
						{tag_add player_armor}
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
										{tag _user}
									}
								}
								{include
									{prop
										{prop car}
									}
									{state
										{state "operatable user_control"}
									}
								}
								{exclude
									{tag
										{tag player_car}
									}
									{tag
										{tag no_scavenge}
									}
								}
							}
						}
						{tag_add player_car}
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
										{tag _user}
									}
								}
								{include
									{prop
										{prop vehicle}
									}
									{state
										{state "operatable user_control"}
									}
								}
								{exclude
									{tag
										{tag player_veh}
									}
									{tag
										{tag no_scavenge}
									}
									{tag
										{tag player_armor}
									}
									{tag
										{tag player_car}
									}
								}
							}
						}
						{tag_add player_veh}
					}
					{"delay"
						{time 1}
					}
					{"actor_state"
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
										{state "operatable user_control"}
									}
								}
								{exclude
									{tag
										{tag no_scavenge}
									}
								}
							}
						}
						{movement
							{forward on}
							{backward on}
						}
					}
					{"delay"
						{time 3.2}
					}
					{"trigger"
						{name "dcg/players_units"}
					}
				}
			}
			{"dcg/warning_air"
				{condition
					{expression "!1 & 2"}
					{terms
						{"1.event"
							{id "talk_on"}
						}
						{"2.trigger"
							{name "dcg/ai_airstrike"}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"event"
						{event "talk_on"}
						{mode set}
						{delay 0}
					}
					{"delay"
						{time 6}
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
								{text "mission/multi/enemy_plane_alert2"}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
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
								{text "mission/multi/enemy_plane_alert1"}
							}
						}
					}
					{"delay"
						{time 8}
					}
					{"event"
						{event "talk_on"}
						{mode reset}
						{delay 0}
					}
				}
			}
			{"dcg/warning_mines"
				{condition
					{expression "1 & 2 & !3 & 4"}
					{terms
						{"1.cmp_i"
							{var "tier2$"}
							{op ">"}
							{value 0}
						}
						{"2.near"
							{units
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
											{state "operatable user_control"}
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
							{near_to
								{ignore_captured_by_user 0}
								{tag dcg_mine_sign}
							}
							{distance 46}
						}
						{"3.event"
							{id "talk_on"}
						}
						{"4.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 0}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"event"
						{event "talk_on"}
						{mode set}
						{delay 0}
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
										{tag dcg_mine_sign}
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
											{zone
												{zone "gamezone"}
											}
										}
										{include
											{state
												{state "operatable user_control"}
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
							{amount 2
							}
						}
						{tag_add warning_talk}
						{tag_remove dcg_mine_sign}
					}
					{"delay"
						{time 0.5}
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
							{"talk"
								{selector
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
												{state linked}
											}
										}
										{exclude
											{state
												{state dead}
											}
										}
									}
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
											{state
												{state linked}
											}
										}
									}
									{sort
										{type entity}
										{entity
											{ignore_captured_by_user 0}
											{tag warning_talk}
										}
									}
									{amount 1
									}
								}
								{text "mission/multi/minefield_alert3"}
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
							{"talk"
								{selector
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
												{state linked}
											}
										}
										{exclude
											{state
												{state dead}
											}
										}
									}
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
											{state
												{state linked}
											}
										}
									}
									{sort
										{type entity}
										{entity
											{ignore_captured_by_user 0}
											{tag warning_talk}
										}
									}
									{amount 1
									}
								}
								{text "mission/multi/minefield_alert2"}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"talk"
								{selector
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
												{state linked}
											}
										}
										{exclude
											{state
												{state dead}
											}
										}
									}
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
											{state
												{state linked}
											}
										}
									}
									{sort
										{type entity}
										{entity
											{ignore_captured_by_user 0}
											{tag warning_talk}
										}
									}
									{amount 1
									}
								}
								{text "mission/multi/minefield_alert1"}
							}
						}
					}
					{"delay"
						{time 8}
					}
					{"event"
						{event "talk_on"}
						{mode reset}
						{delay 0}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag warning_talk}
						}
						{tag_remove warning_talk}
					}
					{"delay"
						{time 300}
					}
					{"trigger"
						{name "dcg/warning_mines"}
					}
				}
			}
			{"minimap/1"
				{condition
					{expression "(1 & 2) | (3 & 4)"}
					{terms
						{"1.cmp_i"
							{var "arrows$"}
							{op "=="}
							{value 1}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{zone
											{zone "a_1"}
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
											{tag _arrowed}
										}
										{state
											{state user_control}
										}
									}
								}
							}
						}
						{"3.cmp_i"
							{var "arrows$"}
							{op "=="}
							{value 2}
						}
						{"4.entities"
							{selector
								{source advanced}
								{group
									{select
										{zone
											{zone "b_1"}
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
											{tag _arrowed}
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
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "arrows$"}
								{op "=="}
								{value 1}
							}
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag a_1}
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
									{ignore_captured_by_user 0}
									{group
										{select
											{zone
												{zone "a_1"}
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
												{tag _arrowed}
											}
											{state
												{state user_control}
											}
										}
									}
								}
								{tag_add _arrowed}
							}
							{"delay"
								{time 19.5}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag a_1}
								}
								{tag_add hidden}
								{inactive on}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag b_1}
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
									{ignore_captured_by_user 0}
									{group
										{select
											{zone
												{zone "b_1"}
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
												{tag _arrowed}
											}
											{state
												{state user_control}
											}
										}
									}
								}
								{tag_add _arrowed}
							}
							{"delay"
								{time 19.5}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag b_1}
								}
								{tag_add hidden}
								{inactive on}
							}
						}
					}
					{"delay"
						{time 30}
					}
					{"trigger"
						{name "minimap/1"}
					}
				}
			}
			{"minimap/2"
				{condition
					{expression "(1 & 2) | (3 & 4)"}
					{terms
						{"1.cmp_i"
							{var "arrows$"}
							{op "=="}
							{value 1}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{zone
											{zone "a_2"}
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
											{tag _arrowed}
										}
										{state
											{state user_control}
										}
									}
								}
							}
						}
						{"3.cmp_i"
							{var "arrows$"}
							{op "=="}
							{value 2}
						}
						{"4.entities"
							{selector
								{source advanced}
								{group
									{select
										{zone
											{zone "b_2"}
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
											{tag _arrowed}
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
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "arrows$"}
								{op "=="}
								{value 1}
							}
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag a_2}
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
									{ignore_captured_by_user 0}
									{group
										{select
											{zone
												{zone "a_2"}
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
												{tag _arrowed}
											}
											{state
												{state user_control}
											}
										}
									}
								}
								{tag_add _arrowed}
							}
							{"delay"
								{time 19.5}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag a_2}
								}
								{tag_add hidden}
								{inactive on}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag b_2}
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
									{ignore_captured_by_user 0}
									{group
										{select
											{zone
												{zone "b_2"}
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
												{tag _arrowed}
											}
											{state
												{state user_control}
											}
										}
									}
								}
								{tag_add _arrowed}
							}
							{"delay"
								{time 19.5}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag b_2}
								}
								{tag_add hidden}
								{inactive on}
							}
						}
					}
					{"delay"
						{time 30}
					}
					{"trigger"
						{name "minimap/2"}
					}
				}
			}
			{"minimap/3"
				{condition
					{expression "(1 & 2) | (3 & 4)"}
					{terms
						{"1.cmp_i"
							{var "arrows$"}
							{op "=="}
							{value 1}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{zone
											{zone "a_3"}
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
											{tag _arrowed}
										}
										{state
											{state user_control}
										}
									}
								}
							}
						}
						{"3.cmp_i"
							{var "arrows$"}
							{op "=="}
							{value 2}
						}
						{"4.entities"
							{selector
								{source advanced}
								{group
									{select
										{zone
											{zone "b_3"}
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
											{tag _arrowed}
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
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "arrows$"}
								{op "=="}
								{value 1}
							}
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag a_3}
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
									{ignore_captured_by_user 0}
									{group
										{select
											{zone
												{zone "a_3"}
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
												{tag _arrowed}
											}
											{state
												{state user_control}
											}
										}
									}
								}
								{tag_add _arrowed}
							}
							{"delay"
								{time 19.5}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag a_3}
								}
								{tag_add hidden}
								{inactive on}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag b_3}
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
									{ignore_captured_by_user 0}
									{group
										{select
											{zone
												{zone "b_3"}
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
												{tag _arrowed}
											}
											{state
												{state user_control}
											}
										}
									}
								}
								{tag_add _arrowed}
							}
							{"delay"
								{time 19.5}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag b_3}
								}
								{tag_add hidden}
								{inactive on}
							}
						}
					}
					{"delay"
						{time 30}
					}
					{"trigger"
						{name "minimap/3"}
					}
				}
			}
			{"minimap/4"
				{condition
					{expression "(1 & 2) | (3 & 4)"}
					{terms
						{"1.cmp_i"
							{var "arrows$"}
							{op "=="}
							{value 1}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{zone
											{zone "a_4"}
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
											{tag _arrowed}
										}
										{state
											{state user_control}
										}
									}
								}
							}
						}
						{"3.cmp_i"
							{var "arrows$"}
							{op "=="}
							{value 2}
						}
						{"4.entities"
							{selector
								{source advanced}
								{group
									{select
										{zone
											{zone "b_4"}
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
											{tag _arrowed}
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
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "arrows$"}
								{op "=="}
								{value 1}
							}
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag a_4}
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
									{ignore_captured_by_user 0}
									{group
										{select
											{zone
												{zone "a_4"}
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
												{tag _arrowed}
											}
											{state
												{state user_control}
											}
										}
									}
								}
								{tag_add _arrowed}
							}
							{"delay"
								{time 19.5}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag a_4}
								}
								{tag_add hidden}
								{inactive on}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag b_4}
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
									{ignore_captured_by_user 0}
									{group
										{select
											{zone
												{zone "b_4"}
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
												{tag _arrowed}
											}
											{state
												{state user_control}
											}
										}
									}
								}
								{tag_add _arrowed}
							}
							{"delay"
								{time 19.5}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag b_4}
								}
								{tag_add hidden}
								{inactive on}
							}
						}
					}
					{"delay"
						{time 30}
					}
					{"trigger"
						{name "minimap/4"}
					}
				}
			}
			{## "ai/ai_untow"
				{disabled}
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
											{tag bot_tow}
										}
									}
									{include
										{prop
											{prop vehicle}
										}
										{state
											{state operatable}
										}
										{state
											{state linked}
										}
									}
									{exclude
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
											{tag _user}
										}
									}
									{include
										{prop
											{prop vehicle}
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
							{distance
								{mode near_than}
								{meters 200}
							}
							{tag
								{"tag pair"}
								{"for selector" tow_act}
							}
						}
						{"2.see_actors"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag bot_tow}
										}
									}
									{include
										{prop
											{prop vehicle}
										}
										{state
											{state operatable}
										}
										{state
											{state linked}
										}
									}
									{exclude
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
											{tag _user}
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
								}
							}
							{distance
								{mode near_than}
								{meters 200}
							}
							{tag
								{"tag pair"}
								{"for selector" tow_act}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"linker"
						{selector
							{type vehicle}
						}
						{action unlink}
						{entities
							{ignore_captured_by_user 0}
							{tag tow_act}
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
										{tag bot_car}
									}
									{tag
										{tag bot_tank}
									}
								}
								{include
									{state
										{state operatable}
									}
								}
								{exclude
									{tag
										{tag bot_towing}
									}
									{state
										{state user_control}
									}
								}
							}
							{sort
								{type entity}
								{entity
									{ignore_captured_by_user 0}
									{tag tow_act}
								}
							}
							{amount 1
							}
						}
						{tag_add bot_towing}
					}
					{"delay"
						{time 0.2}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag bot_towing}
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
								{type near}
								{units
									{ignore_captured_by_user 0}
									{tag bot_towing}
								}
								{near_to
									{ignore_captured_by_user 0}
									{tag tow_act}
								}
								{distance 22}
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
														{tag bot_towing}
													}
												}
												{include
													{prop
														{prop car}
													}
													{state
														{state inhabited}
													}
												}
												{exclude
													{state
														{state moveable}
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
									{"emit"
										{selector
											{ignore_captured_by_user 0}
											{tag bot_towing}
											{type vehicle}
											{state inhabited}
										}
										{drop orders}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"action"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag bot_towing}
													}
												}
												{include
													{prop
														{prop vehicle}
													}
													{state
														{state "operatable moveable"}
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
										{action move}
										{target
											{ignore_captured_by_user 0}
											{tag flag}
											{zone "gamezone"}
										}
									}
									{"delay"
										{time 5}
									}
									{"if"
										{condition
											{type entities}
											{selector
												{source advanced}
												{ignore_captured_by_user 0}
												{group
													{select
														{tag
															{tag bot_towing}
														}
													}
													{include
														{prop
															{prop car}
														}
														{state
															{state inhabited}
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
										{"emit"
											{selector
												{tag bot_towing}
												{type vehicle}
												{state operatable}
											}
											{drop orders}
										}
									}
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
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag bot_tow}
									}
								}
								{include
									{tag
										{tag tow_act}
									}
								}
							}
						}
						{tag_remove bot_tow}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag tow_act}
						}
						{tag_remove tow_act}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag bot_towing}
						}
						{tag_remove _lua_mi}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag bot_towing}
						}
						{tag_remove bot_towing}
					}
					{"delay"
						{time 8}
					}
					{"trigger"
						{name "ai/ai_untow"}
					}
				}
			}
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
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "id_1st_enemy$"}
								{op "=="}
								{value 1}
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
														{tag bail_veh}
													}
												}
												{include
													{player
														{player "1"}
													}
													{state
														{state operatable}
													}
												}
											}
										}
									}
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
										{time 1}
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
									{"delay"
										{time 1}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag bail_veh}
										}
										{tag_remove bail_veh}
									}
								}
								{"default"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "id_1st_enemy$"}
								{op "=="}
								{value 2}
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
														{tag bail_veh}
													}
												}
												{include
													{player
														{player "2"}
													}
													{state
														{state operatable}
													}
												}
											}
										}
									}
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
										{time 1}
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
									{"delay"
										{time 1}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag bail_veh}
										}
										{tag_remove bail_veh}
									}
								}
								{"default"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "id_1st_enemy$"}
								{op "=="}
								{value 3}
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
														{tag bail_veh}
													}
												}
												{include
													{player
														{player "3"}
													}
													{state
														{state operatable}
													}
												}
											}
										}
									}
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
										{time 1}
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
									{"delay"
										{time 1}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag bail_veh}
										}
										{tag_remove bail_veh}
									}
								}
								{"default"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "id_1st_enemy$"}
								{op "=="}
								{value 4}
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
														{tag bail_veh}
													}
												}
												{include
													{player
														{player "4"}
													}
													{state
														{state operatable}
													}
												}
											}
										}
									}
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
										{time 1}
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
									{"delay"
										{time 1}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag bail_veh}
										}
										{tag_remove bail_veh}
									}
								}
								{"default"}
							}
						}
						{"default"}
					}
					{"delay"
						{time 5}
					}
					{"trigger"
						{name "ai/bail_portables"}
					}
				}
			}
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
										{tag cmp_def}
									}
									{tag
										{tag air_vehicle}
									}
									{tag
										{tag player}
									}
									{player
										{player "0"}
									}
									{state
										{state user_control}
									}
								}
							}
						}
						{tag_add _ai}
					}
					{"delay"
						{time 0.5}
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
						{time 0.5}
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
									{tag
										{tag air_vehicle}
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
						{time 1}
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
					{## "entity_state"
						{selector
							{source advanced}
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
									{state
										{state linked}
									}
								}
								{exclude
									{tag
										{tag bot_tow}
									}
									{state
										{state user_control}
									}
								}
							}
						}
						{tag_add bot_tow}
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
						{time 1}
					}
					{"switch"
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
						{time 8}
					}
					{"trigger"
						{name "lua/bot_tags"}
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
										{tag
											{tag engine_count_1}
										}
										{tag
											{tag engine_count_2}
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
										{drop orders}
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
			{## "ai/ai_flag_smoke"
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
										{state
											{state inactive}
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
								{"for selector" ai_smoke}
								{"for enemy" smk_target}
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
								{type near}
								{units
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag smk_target}
											}
										}
										{include
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
								{distance 150}
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
														{tag ai_smoke}
													}
												}
												{include
													{with_item
														{type amount}
														{item "nbk39" "grenade"}
														{min 1}
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
													{with_item
														{type amount}
														{item "nbk39" "grenade"}
														{min 1}
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
														{tag ai_smoke}
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
													{tag ai_smoke}
												}
											}
											{amount 2
											}
										}
										{tag_add ai_smoke}
									}
									{"delay"
										{time 0.3}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag ai_smoke}
											{state operatable}
										}
										{tag_add _mi_temp1}
									}
									{"delay"
										{time 0.2}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag _mi_temp1}
										}
										{tag_add _lua_mi}
									}
									{"delay"
										{time 0.1}
									}
									{"inventory"
										{selector
											{tag ai_smoke}
											{type human}
											{state "not dead"}
										}
										{action take}
										{item "nbk39" "grenade"}
									}
									{"delay"
										{time 0.5}
									}
									{"action"
										{selector
											{tag ai_smoke}
											{type human}
											{state "not dead"}
										}
										{drop "orders sensor senseless"}
										{action attack_ground}
										{target
											{ignore_captured_by_user 0}
											{tag null}
										}
									}
									{"delay"
										{time 4}
									}
									{"action"
										{selector
											{tag ai_smoke}
											{type human}
											{state "not dead"}
										}
										{drop orders}
										{action advance}
										{target
											{ignore_captured_by_user 0}
											{tag smk_target}
										}
									}
									{"delay"
										{time 1}
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
														{tag ai_smoke}
													}
												}
												{include
													{with_item
														{type amount}
														{item "rdg1_smoke" "grenade"}
														{min 1}
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
													{with_item
														{type amount}
														{item "rdg1_smoke" "grenade"}
														{min 1}
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
														{tag ai_smoke}
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
													{tag ai_smoke}
												}
											}
											{amount 2
											}
										}
										{tag_add ai_smoke}
									}
									{"delay"
										{time 0.3}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag ai_smoke}
											{state operatable}
										}
										{tag_add _mi_temp1}
									}
									{"delay"
										{time 0.2}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag _mi_temp1}
										}
										{tag_add _lua_mi}
									}
									{"delay"
										{time 0.1}
									}
									{"inventory"
										{selector
											{tag ai_smoke}
											{type human}
											{state "not dead"}
										}
										{action take}
										{item "rdg1_smoke" "grenade"}
									}
									{"delay"
										{time 0.5}
									}
									{"action"
										{selector
											{ignore_captured_by_user 0}
											{tag ai_smoke}
											{type human}
											{state "not dead"}
										}
										{drop "orders sensor senseless"}
										{action attack_ground}
										{target
											{ignore_captured_by_user 0}
											{tag null}
										}
									}
									{"delay"
										{time 4}
									}
									{"action"
										{selector
											{tag ai_smoke}
											{type human}
											{state "not dead"}
										}
										{drop orders}
										{action advance}
										{target
											{ignore_captured_by_user 0}
											{tag smk_target}
										}
									}
									{"delay"
										{time 1}
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
														{tag ai_smoke}
													}
												}
												{include
													{with_item
														{type amount}
														{item "m24_smoke" "grenade"}
														{min 1}
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
													{with_item
														{type amount}
														{item "m24_smoke" "grenade"}
														{min 1}
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
														{tag ai_smoke}
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
													{tag ai_smoke}
												}
											}
											{amount 2
											}
										}
										{tag_add ai_smoke}
									}
									{"delay"
										{time 0.3}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag ai_smoke}
											{state operatable}
										}
										{tag_add _mi_temp1}
									}
									{"delay"
										{time 0.2}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag _mi_temp1}
										}
										{tag_add _lua_mi}
									}
									{"delay"
										{time 0.1}
									}
									{"inventory"
										{selector
											{tag ai_smoke}
											{type human}
											{state "not dead"}
										}
										{action take}
										{item "m24_smoke" "grenade"}
									}
									{"delay"
										{time 0.5}
									}
									{"action"
										{selector
											{ignore_captured_by_user 0}
											{tag ai_smoke}
											{type human}
											{state "not dead"}
										}
										{drop "orders sensor senseless"}
										{action attack_ground}
										{target
											{ignore_captured_by_user 0}
											{tag null}
										}
									}
									{"delay"
										{time 4}
									}
									{"action"
										{selector
											{tag ai_smoke}
											{type human}
											{state "not dead"}
										}
										{drop orders}
										{action advance}
										{target
											{ignore_captured_by_user 0}
											{tag smk_target}
										}
									}
									{"delay"
										{time 1}
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
														{tag ai_smoke}
													}
												}
												{include
													{with_item
														{type amount}
														{item "m43_smoke" "grenade"}
														{min 1}
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
													{with_item
														{type amount}
														{item "m43_smoke" "grenade"}
														{min 1}
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
														{tag ai_smoke}
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
													{tag ai_smoke}
												}
											}
											{amount 2
											}
										}
										{tag_add ai_smoke}
									}
									{"delay"
										{time 0.3}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag ai_smoke}
											{state operatable}
										}
										{tag_add _mi_temp1}
									}
									{"delay"
										{time 0.2}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag _mi_temp1}
										}
										{tag_add _lua_mi}
									}
									{"delay"
										{time 0.1}
									}
									{"inventory"
										{selector
											{tag ai_smoke}
											{type human}
											{state "not dead"}
										}
										{action take}
										{item "m43_smoke" "grenade"}
									}
									{"delay"
										{time 0.5}
									}
									{"action"
										{selector
											{ignore_captured_by_user 0}
											{tag ai_smoke}
											{type human}
											{state "not dead"}
										}
										{drop "orders sensor senseless"}
										{action attack_ground}
										{target
											{ignore_captured_by_user 0}
											{tag null}
										}
									}
									{"delay"
										{time 4}
									}
									{"action"
										{selector
											{tag ai_smoke}
											{type human}
											{state "not dead"}
										}
										{drop orders}
										{action advance}
										{target
											{ignore_captured_by_user 0}
											{tag smk_target}
										}
									}
									{"delay"
										{time 1}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag ai_smoke}
										}
										{tag_remove ai_smoke}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag smk_target}
										}
										{tag_remove smk_target}
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
									{tag smk_target}
								}
								{tag_remove smk_target}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag ai_smoke}
								}
								{tag_remove ai_smoke}
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
									{ignore_captured_by_user 0}
									{tag ai_smoke}
									{state operatable}
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
											{tag ai_smoke}
											{state operatable}
										}
									}
									{"delay"
										{time 1}
									}
									{"actor_state"
										{selector
											{ignore_captured_by_user 0}
											{tag ai_smoke}
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
										{time 1}
									}
									{"actor_to_cover"
										{selector
											{ignore_captured_by_user 0}
											{tag ai_smoke}
											{state operatable}
										}
									}
								}
								{"default"
									{"delay"
										{time 8}
									}
									{"actor_state"
										{selector
											{ignore_captured_by_user 0}
											{tag ai_smoke}
											{state operatable}
										}
										{drop orders}
										{fire_mode open}
										{move_mode free}
										{ai_move
											{mode enable}
										}
										{ai
											{advance_ratio "0.5"}
										}
									}
								}
							}
							{"delay"
								{time 1}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag smk_target}
								}
								{tag_remove smk_target}
							}
							{"delay"
								{time 50}
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
							{tag ai_smoke}
						}
						{tag_remove ai_smoke}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _mi_temp1}
						}
						{tag_remove _lua_mi}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _mi_temp1}
						}
						{tag_remove _mi_temp1}
					}
					{"delay"
						{time 80}
					}
					{"trigger"
						{name "ai/ai_flag_smoke"}
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
												{state linked}
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
									}
									{sort
										{type shuffle}
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
									{ignore_captured_by_user 0}
									{tag flag}
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
						}
						{"default"
							{"delay"
								{time 0.1}
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
					{"set_i"
						{var "dcg_on$"}
						{op "+"}
						{value 1}
					}
				}
			}
			{"dcg/user_error"
				{condition
					{terms
						{"1.event"
							{id "dcg"}
						}
						{"2.entities"
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
										{tag
											{tag bot}
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
										{tag _user}
									}
								}
								{include
									{tag
										{tag bot}
									}
								}
							}
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
										{tag _user}
									}
								}
								{include
									{tag
										{tag bot}
									}
								}
							}
						}
						{tag_remove bot}
					}
					{"delay"
						{time 4.4}
					}
					{"trigger"
						{name "dcg/user_error"}
					}
				}
			}
			{"minimap/arrows"
				{condition
					{expression "(1 & 2 & 4) | (1 & 3 & 4)"}
					{terms
						{"1.event"
							{id "init"}
						}
						{"2.entities"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
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
											{tag _bot}
										}
										{state
											{state operatable}
										}
									}
									{exclude
										{tag
											{tag air_vehicle}
										}
										{tag
											{tag cmp_def}
										}
										{relation
											{relation ally}
											{player "0"}
										}
										{state
											{state user_control}
										}
									}
								}
							}
						}
						{"3.entities"
							{selector
								{ignore_captured_by_user 0}
								{tag _user}
								{zone "gamezone"}
								{state operatable}
							}
						}
						{"4.cmp_i"
							{var "dcg_on$"}
							{op ">"}
							{value 0}
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
												{tag _bot}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{zone
												{zone "combat"}
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
							{"delay"
								{time 0.1}
							}
							{"set_i"
								{var "user_team$"}
								{op "="}
								{value 1}
							}
							{"set_i"
								{var "arrows$"}
								{op "="}
								{value 2}
							}
							{"delete"
								{selector
									{ignore_captured_by_user 0}
									{tag arrow_enemy_a}
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
										}
										{include
											{tag
												{tag _bot}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{zone
												{zone "combat"}
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
							{"delay"
								{time 0.1}
							}
							{"set_i"
								{var "user_team$"}
								{op "="}
								{value 2}
							}
							{"set_i"
								{var "arrows$"}
								{op "="}
								{value 1}
							}
							{"delete"
								{selector
									{ignore_captured_by_user 0}
									{tag arrow_enemy_b}
								}
							}
						}
						{"default"}
					}
					{"delay"
						{time 0.2}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "arrows$"}
								{op "=="}
								{value 0}
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
														{tag _user}
													}
												}
											}
										}
									}
									{"delay"
										{time 0.1}
									}
									{"set_i"
										{var "user_team$"}
										{op "="}
										{value 2}
									}
									{"set_i"
										{var "arrows$"}
										{op "="}
										{value 1}
									}
									{"delete"
										{selector
											{ignore_captured_by_user 0}
											{tag arrow_enemy_b}
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
												}
												{include
													{tag
														{tag _user}
													}
												}
											}
										}
									}
									{"delay"
										{time 0.1}
									}
									{"set_i"
										{var "user_team$"}
										{op "="}
										{value 1}
									}
									{"set_i"
										{var "arrows$"}
										{op "="}
										{value 2}
									}
									{"delete"
										{selector
											{ignore_captured_by_user 0}
											{tag arrow_enemy_a}
										}
									}
								}
								{"default"}
							}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "arrows$"}
								{op ">"}
								{value 0}
							}
						}
						{"default"
							{"delay"
								{time 1}
							}
							{"set_i"
								{var "dcg_error$"}
								{op "-"}
								{value 1}
							}
							{"delay"
								{time 4}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "dcg_error$"}
										{op ">"}
										{value 0}
									}
									{"delay"
										{time 0.1}
									}
									{"trigger"
										{name "minimap/arrows"}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"set_i"
										{var "user_team$"}
										{op "="}
										{value 1}
									}
									{"delay"
										{time 0.1}
									}
									{"objective_progress"
										{set 0}
										{add 0}
										{title "dcg arrow error - report if you see this"}
									}
									{"delay"
										{time 10}
									}
									{"objective_progress"
										{hide}
										{set 0}
										{add 0}
										{title "dcg arrow error - report if you see this"}
									}
									{"delay"
										{time 0.1}
									}
								}
							}
						}
					}
				}
			}

;//Temporary additions for CE Player Scripts 
			(include "../../map_scripts/conquest_enhanced_player_triggers.inc")

			;============== AI GRENADES	==============		
			{"ai_add_smoke_grenade"
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
											{item "ai_smoke_grenade_1"}
											{min 1}
										}
										{with_item
											{type amount}
											{item "ai_smoke_grenade_2"}
											{min 1}
										}
										{with_item
											{type amount}
											{item "ai_smoke_grenade_3"}
											{min 1}
										}
										{with_item
											{type amount}
											{item "ai_smoke_grenade_4"}
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
										{item "ai_smoke_grenade_1"}
										{min 1}
									}
									{with_item
										{type amount}
										{item "ai_smoke_grenade_2"}
										{min 1}
									}
									{with_item
										{type amount}
										{item "ai_smoke_grenade_3"}
										{min 1}
									}
									{with_item
										{type amount}
										{item "ai_smoke_grenade_4"}
										{min 1}
									}
								}
							}
							{amount 30
							}
						}
						{effect add_custom_smoke_grande}
					}
					{"delay"
						{time 1}
					}
					{## "effect"
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
									{tag
										{tag give_custom_smoke_grenade}
									}
									{state
										{state user_control}
									}
									{with_item
										{type amount}
										{item "ai_smoke_grenade_1"}
										{min 1}
									}
									{with_item
										{type amount}
										{item "ai_smoke_grenade_2"}
										{min 1}
									}
									{with_item
										{type amount}
										{item "ai_smoke_grenade_3"}
										{min 1}
									}
									{with_item
										{type amount}
										{item "ai_smoke_grenade_4"}
										{min 1}
									}
								}
							}
							{amount 15
							}
						}
						{effect add_custom_smoke_grande}
					}
					{"switch"
						{"case"
							{condition
								{type rand}
								{value 0.25}
							}
							{"inventory"
								{selector
									{tag give_custom_smoke_grenade}
									{type human}
									{state operatable}
								}
								{action add}
								{item "ai_smoke_grenade_1"}
								{stack 0}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.25}
							}
							{"inventory"
								{selector
									{tag give_custom_smoke_grenade}
									{type human}
									{state operatable}
								}
								{action add}
								{item "ai_smoke_grenade_2"}
								{stack 0}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.25}
							}
							{"inventory"
								{selector
									{tag give_custom_smoke_grenade}
									{type human}
									{state operatable}
								}
								{action add}
								{item "ai_smoke_grenade_3"}
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
								{item "ai_smoke_grenade_4"}
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
						{name "ai_add_smoke_grenade"}
					}
				}
			}

		}
		{waypoints "generic_waypoint"
			{"3000"
				{position -17463.2 -767.075 116}
				{radius 2500}
				{RandomPosition 1}
			}
		