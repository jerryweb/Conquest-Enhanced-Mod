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