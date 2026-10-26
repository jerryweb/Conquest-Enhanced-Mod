			{## "debug/test_script"
				{condition
					;{terms
					;	{"1.entities"
					;		{source advanced}
					;		{ignore_captured_by_user 0}
					;		{group
					;			{select
					;				{tag
					;					{tag rocket_artillery}
					;				}
					;			}
					;			{include
					;				{state
					;					{state "operatable inhabited"}
					;				}
					;				{prop
					;					{prop cannon}
					;				}
					;				{tag
					;					{tag _bot}
					;				}
					;			}
					;			{exclude
					;				{tag
					;					{tag artillery_in_combat}
					;				}
					;				{state
					;					{state inactive}
					;				}
					;				{state
					;					{state linked}
					;				}
					;				{state
					;					{state user_control}
					;				}
					;				{tag
					;					{tag _user}
					;				}
					;				{tag
					;					{tag _user_ally}
					;				}
					;				{tag
					;					{tag player_veh}
					;				}
					;				{tag
					;					{tag rocket_arty_selected}
					;				}
					;			}
					;		}
					;	}
					;}
				}
				{actions
					{"delay"
						{time 5}
					}
					{"sound"
	  					{name "mission/task_fail"}
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
									;{prop
									;	{prop no_scavenge}
									;}
									{prop {prop cannon}}
									{state
										{state "operatable inhabited"}
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
									{tag
										{tag pilot}
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
						{time 0.1}
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
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "user_is_defender$"}
										{op "=="}
										{value 1}
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
														{tag _user}
													}
													{tag
														{tag cmp_def}
													}
													{tag
														{tag _animal}
													}
													{prop
														{prop airborne}
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
										{time 0.1}
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
									{## "effect"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag {tag cmp_def}}
													{tag {tag cmp_mg}}
												}
												{include
													{zone {zone "gamezone"}}
													{prop {prop cannon}}
													{state {state operatable}}
												}
												{exclude
													{tag {tag "ce_ai_cannon_sandbags"}}
													{tag {tag _user}}
													{tag {tag _player}}
													{prop {prop tank}}
													{state {state inactive}}
													{state {state user_control}}
												}
											}
										}
										{effect smoke_for_test}
									}
									{"effect"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag {tag cmp_def}}
													{tag {tag cmp_mg}}
												}
												{include
													{zone {zone "gamezone"}}
													{prop {prop cannon}}
													{state {state operatable}}
												}
												{exclude
													{tag {tag "ce_ai_cannon_sandbags"}}
													{tag {tag _user}}
													{tag {tag _player}}
													{prop {prop tank}}
													{state {state inactive}}
													{state {state user_control}}
												}
											}
										}
										{effect ce_build_ai_cannon_sandbags}
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
														{prop no_scavenge}
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
						{time 3}
					}
					{"set_i"
						{var "dcg_on$"}
						{op "+"}
						{value 1}
					}
				}
			}
			{## "dcg/ai_air_decide"
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
								{type cmp_i}
								{var "flag1$"}
								{op ">"}
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
											{tag player}
											{zone "forward1"}
											{type human}
											{state operatable}
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
										{type cmp_i}
										{var "flag2$"}
										{op ">"}
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
													{tag player}
													{zone "forward2"}
													{type human}
													{state operatable}
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
										{type cmp_i}
										{var "flag3$"}
										{op ">"}
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
													{tag player}
													{zone "forward3"}
													{type human}
													{state operatable}
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
										{type cmp_i}
										{var "flag4$"}
										{op ">"}
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
													{tag player}
													{zone "forward4"}
													{type human}
													{state operatable}
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
										{type cmp_i}
										{var "flag5$"}
										{op ">"}
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
													{tag player}
													{zone "forward5"}
													{type human}
													{state operatable}
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
						{time 25}
					}
					{"trigger"
						{name "dcg/ai_air_decide"}
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
											{tag
												{tag airstrike_eng}
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
											{tag
												{tag airstrike_eng}
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
									}
									{include
										{tag
											{tag enemy_air}
										}
										{prop
											{prop vehicle}
										}
										{state
											{state operatable}
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
											{tag enemy_air}
										}
										{prop
											{prop vehicle}
										}
										{state
											{state operatable}
										}
									}
								}
							}
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
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag enemy_air}
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
												{tag enemy_air}
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
									{tag enemy_air}
									{type vehicle}
									{state inhabited}
								}
								{drop "orders sensor senseless"}
								{enemies
									{ignore_captured_by_user 0}
									{tag ai_air_target}
								}
								{attack_altitude 47}
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
						{"5.cmp_i"
							{var "prep_inform$"}
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
								{type rand}
								{value 0.2}
							}
							{"delay"
								{time 60}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.25}
							}
							{"delay"
								{time 120}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.33}
							}
							{"delay"
								{time 300}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.5}
							}
							{"delay"
								{time 200}
							}
						}
						{"default"
							{"delay"
								{time 360}
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
			{## "dcg/ai_air_on"
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
							{var "bot_retreat_active$"}
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


			{"dcg2/botdefend/garrison_ready"
				{condition
					{expression "1 & !2 & !3 & !4 & 5"}
					{terms
						{"1.cmp_i"
							{var "garrison_end$"}
							{op "=="}
							{value 1}
						}
						{"2.trigger"
							{name "dcg2/botdefend/garrison_tagging"}
						}
						{"3.trigger"
							{name "dcg2/botdefend/setup"}
						}
						{"4.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag "_garrison_todo+"}
										}
										{tag
											{tag "+1teles_h"}
										}
										{tag
											{tag "+2teles_h"}
										}
										{tag
											{tag "+3teles_h"}
										}
										{tag
											{tag "+4teles_h"}
										}
										{tag
											{tag "+5teles_h"}
										}
										{tag
											{tag "+bots_ct"}
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
						{"5.event"
							{id "dcg2/attack_bot_spawning"}
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
							{ignore_captured_by_user 0}
							{group
								{select
									{tag {tag "+garrisoned"}}
									{tag {tag cmp_mg}}
								}
								{include
									{zone {zone "gamezone"}}
									{prop {prop cannon}}
									{state {state operatable}}
								}
								{exclude
									{tag {tag "_garrison_todo+"}}
									{tag {tag "ce_ai_cannon_sandbags"}}
									{tag {tag _user}}
									{tag {tag _user_ally}}
									{prop {prop tank}}
									{state {state inactive}}
									{state {state user_control}}
								}
							}
						}
						{effect ce_build_ai_cannon_sandbags}
					}
					{"set_i"
						{var "garrison_ready$"}
						{op "="}
						{value 1}
					}
					{"con"
						{text "(Debug) - garrison_ready set to 1"}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag "+garrisoned"}
									}
								}
								{include
									{zone
										{zone "gamezone"}
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
										{tag _garrison_off}
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
						{tag_add "+need_cover"}
					}
					{"delay"
						{time 1.4}
					}
					{"event"
						{event "dcg2/attack_bot_spawning"}
						{mode reset}
						{delay 0}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _garrison_off}
						}
						{tag_remove "+garrisoned"}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _garrison_off}
						}
						{tag_remove _garrison_off}
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
											{tag "+mobilegun"}
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
			{"minimap/arrows"
				{condition
					{terms
						{"1.event"
							{id "init"}
						}
						{"2.cmp_i"
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
								{type cmp_i}
								{var "user_is_defender$"}
								{op "=="}
								{value 1}
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
										{value 2}
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
									{## "delete"
										{selector
											{ignore_captured_by_user 0}
											{tag arrow_enemy_a}
										}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "bots_spawnside$"}
										{op "=="}
										{value 1}
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
									{## "delete"
										{selector
											{ignore_captured_by_user 0}
											{tag arrow_enemy_b}
										}
									}
								}
								{"default"}
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
												{tag arrow_enemy_a}
											}
											{tag
												{tag arrow_enemy_b}
											}
										}
									}
								}
							}
							{"set_i"
								{var "arrows$"}
								{op "="}
								{value 3}
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
										{value 2}
									}
									{"delay"
										{time 0.1}
									}
									{"set_i"
										{var "user_team$"}
										{op "="}
										{value 1}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "bots_spawnside$"}
										{op "=="}
										{value 1}
									}
									{"delay"
										{time 0.1}
									}
									{"set_i"
										{var "user_team$"}
										{op "="}
										{value 2}
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
								{var "user_team$"}
								{op ">"}
								{value 0}
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
								{title "mission/multi/dcg_error03"}
							}
							{"con"
								{text "(Warning) - arrows/bots_spawnside values unknown.(defaulting user_side to A)"}
							}
							{"delay"
								{time 10}
							}
							{"objective_progress"
								{hide}
								{set 0}
								{add 0}
								{title "mission/multi/dcg_error03"}
							}
							{"delay"
								{time 0.1}
							}
						}
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
						}
						{"3.cmp_i"
							{var "bot_retreat_active$"}
							{op "=="}
							{value 0}
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
					{"ables"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag _bot_veh}
									}
								}
								{include
									{zone
										{zone "gamezone"}
									}
									{state
										{state operatable}
									}
									{prop
										{prop detect_artillery}
									}
								}
								{exclude
									{state
										{state user_control}
									}
									{state
										{state inactive}
									}
								}
							}
						}
						{remove select}
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
										{type existance}
										{item "smoke"}
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
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "lua/bot_tags"}
					}
				}
			}

