			{"parachute"
				{condition
					{terms
						{"1.near"
							{units
								{ignore_captured_by_user 0}
								{tag eject}
								{type human}
							}
							{near_to
								{ignore_captured_by_user 0}
								{tag base}
							}
							{distance 100}
						}
					}
				}
				{actions
					{"delay"
						{time 0.05}
					}
					{"linker"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag base}
									}
								}
								{exclude
									{tag
										{tag _flight}
									}
								}
							}
						}
						{entities
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag eject}
									}
								}
								{include
									{prop
										{prop human}
									}
								}
								{exclude
									{state
										{state linked}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.05}
					}
					{"effect"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag base}
									}
								}
								{exclude
									{tag
										{tag _flight}
									}
								}
							}
						}
						{effect start}
					}
					{"delay"
						{time 0.05}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag base}
									}
								}
								{include
									{tag
										{tag _flight}
									}
								}
							}
						}
						{tag_add base_null}
						{tag_remove base}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag eject}
									}
								}
								{include
									{state
										{state linked}
									}
								}
							}
						}
						{tag_add eject_null}
						{tag_remove eject}
					}
					{"delay"
						{time 0.2}
					}
					{"trigger"
						{name "parachute"}
					}
				}
			}
			{"music/music_regular"
				{condition
					{terms
						{"1.event"
							{id "music_regular"}
						}
						{"2.cmp_i"
							{var "music_rnd$"}
							{op "=="}
							{value 1}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"event"
						{event "music_regular"}
						{mode reset}
						{delay 0}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
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
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "user_nation$"}
										{op "=="}
										{value 4}
									}
									{"delay"
										{time 0.1}
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
											{"music"
												{start "/music/ger_ambient_west_lvl2.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 63}
											}
										}
										{"case"
											{condition
												{type rand}
												{value 0.33}
											}
											{"delay"
												{time 0.1}
											}
											{"music"
												{start "/music/ger_theme_west.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 129}
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
											{"music"
												{start "/music/ambient_4.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 130}
											}
										}
										{"default"
											{"delay"
												{time 0.1}
											}
											{"music"
												{start "/music/ger_battle_west_lvl1.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 69}
											}
										}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "user_nation$"}
										{op "=="}
										{value 5}
									}
									{"delay"
										{time 0.1}
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
											{"music"
												{start "/music/ger_ambient_west_lvl2.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 63}
											}
										}
										{"case"
											{condition
												{type rand}
												{value 0.33}
											}
											{"delay"
												{time 0.1}
											}
											{"music"
												{start "/music/ger_theme_west.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 129}
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
											{"music"
												{start "/music/cmw_ambient_lvl3.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 91}
											}
										}
										{"default"
											{"delay"
												{time 0.1}
											}
											{"music"
												{start "/music/ger_battle_west_lvl1.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 69}
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
												{value 0.25}
											}
											{"delay"
												{time 0.1}
											}
											{"music"
												{start "/music/ger_battle_lvl1.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 177}
											}
										}
										{"case"
											{condition
												{type rand}
												{value 0.33}
											}
											{"delay"
												{time 0.1}
											}
											{"music"
												{start "/music/action_theme_4.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 170}
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
											{"music"
												{start "/music/ambient_4.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 130}
											}
										}
										{"default"
											{"delay"
												{time 0.1}
											}
											{"music"
												{start "/music/ger_ambient_lvl1.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 137}
											}
										}
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
							{"delay"
								{time 0.1}
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
									{"music"
										{start "/music/fin_ambient_lvl3.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 99}
									}
								}
								{"case"
									{condition
										{type rand}
										{value 0.33}
									}
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/intro_volokolamsk.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 56}
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
									{"music"
										{start "/music/ambient_4.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 169}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/fin_battle_lvl1.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 185}
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
							{"delay"
								{time 0.1}
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
									{"music"
										{start "/music/airborne_ambient_lvl2.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 114}
									}
								}
								{"case"
									{condition
										{type rand}
										{value 0.33}
									}
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/airborne_ambient.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 101}
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
									{"music"
										{start "/music/ambient_4.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 130}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/usa_battle_lvl2.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 86}
									}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "bot_army$"}
								{op "=="}
								{value 5}
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
									{"music"
										{start "/music/cmw_ambient_lvl1.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 154}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/cmw_ambient_lvl2.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 176}
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
										{value 0.25}
									}
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/rus_battle_lvl1.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 222}
									}
								}
								{"case"
									{condition
										{type rand}
										{value 0.33}
									}
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/action_theme_1.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 415}
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
									{"music"
										{start "/music/action_theme_8.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 228}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/rus_battle_lvl2.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 235}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"event"
						{event "music_detect"}
						{mode set}
						{delay 0}
					}
					{"delay"
						{time 5}
					}
					{"event"
						{event "music_reset"}
						{mode set}
						{delay 0}
					}
					{"delay"
						{time 0.1}
					}
					{"trigger"
						{name "music/music_regular"}
					}
				}
			}
			{"music/music_regular_attack"
				{condition
					{terms
						{"1.event"
							{id "music_regular"}
						}
						{"2.cmp_i"
							{var "music_rnd$"}
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
						{event "music_regular"}
						{mode reset}
						{delay 0}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "user_nation$"}
								{op "=="}
								{value 2}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
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
									{"switch"
										{"case"
											{condition
												{type rand}
												{value 0.4}
											}
											{"delay"
												{time 0.1}
											}
											{"music"
												{start "/music/ger_ambient_west_lvl2.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 63}
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
											{"music"
												{start "/music/ger_theme_west.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 129}
											}
										}
										{"default"
											{"delay"
												{time 0.1}
											}
											{"music"
												{start "/music/ger_battle_west_lvl1.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 69}
											}
										}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "bot_army$"}
										{op "=="}
										{value 5}
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
											{"music"
												{start "/music/ger_ambient_west_lvl2.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 63}
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
											{"music"
												{start "/music/cmw_ambient_lvl3.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 91}
											}
										}
										{"default"
											{"delay"
												{time 0.1}
											}
											{"music"
												{start "/music/ger_battle_west_lvl1.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 69}
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
												{value 0.4}
											}
											{"delay"
												{time 0.1}
											}
											{"music"
												{start "/music/ger_battle_lvl1.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 177}
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
											{"music"
												{start "/music/action_theme_4.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 170}
											}
										}
										{"default"
											{"delay"
												{time 0.1}
											}
											{"music"
												{start "/music/ger_ambient_lvl1.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 137}
											}
										}
									}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "user_nation$"}
								{op "=="}
								{value 3}
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
									{"music"
										{start "/music/fin_ambient_lvl3.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 99}
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
									{"music"
										{start "/music/intro_volokolamsk.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 56}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/fin_battle_lvl1.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 185}
									}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "user_nation$"}
								{op "=="}
								{value 4}
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
									{"music"
										{start "/music/airborne_ambient_lvl2.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 114}
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
									{"music"
										{start "/music/airborne_ambient.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 101}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/usa_battle_lvl2.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 86}
									}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "user_nation$"}
								{op "=="}
								{value 5}
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
									{"music"
										{start "/music/cmw_ambient_lvl1.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 154}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/cmw_ambient_lvl2.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 176}
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
										{value 0.35}
									}
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/rus_battle_lvl1.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 222}
									}
								}
								{"case"
									{condition
										{type rand}
										{value 0.35}
									}
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/action_theme_1.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 415}
									}
								}
								{"case"
									{condition
										{type rand}
										{value 0.35}
									}
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/action_theme_8.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 228}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/rus_battle_lvl2.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 235}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"event"
						{event "music_detect"}
						{mode set}
						{delay 0}
					}
					{"delay"
						{time 5}
					}
					{"event"
						{event "music_reset"}
						{mode set}
						{delay 0}
					}
					{"delay"
						{time 0.1}
					}
					{"trigger"
						{name "music/music_regular_attack"}
					}
				}
			}
			{"music/music_intense"
				{condition
					{terms
						{"1.event"
							{id "music_intense"}
						}
						{"2.cmp_i"
							{var "music_rnd$"}
							{op "=="}
							{value 1}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"event"
						{event "music_intense"}
						{mode reset}
						{delay 0}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
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
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "user_nation$"}
										{op "=="}
										{value 4}
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
											{"music"
												{start "/music/ger_battle_west_lvl2.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 47}
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
											{"music"
												{start "/music/ger_valkyrie.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 67}
											}
										}
										{"default"
											{"delay"
												{time 0.1}
											}
											{"music"
												{start "/music/airborne_action_lvl1.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 110}
											}
										}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "user_nation$"}
										{op "=="}
										{value 5}
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
											{"music"
												{start "/music/ger_valkyrie.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 67}
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
											{"music"
												{start "/music/ger_battle_west_lvl2.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 47}
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
											{"music"
												{start "/music/cmw_action_lvl5.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 76}
											}
										}
										{"default"
											{"delay"
												{time 0.1}
											}
											{"music"
												{start "/music/cmw_action_lvl2.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 62}
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
											{"music"
												{start "/music/ger_action_lvl3.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 127}
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
											{"music"
												{start "/music/scorched_earth.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 95}
											}
										}
										{"default"
											{"delay"
												{time 0.1}
											}
											{"music"
												{start "/music/ger_battle_lvl2.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 113}
											}
										}
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
									{"music"
										{start "/music/fin_battle_lvl2.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 94}
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
									{"music"
										{start "/music/finland.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 60}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/fin_battle_lvl3.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 300}
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
									{"music"
										{start "/music/usa_battle_lvl3.wav"}
										{stop_all}
										{volume game}
										{fade 5}
										{loop}
									}
									{"delay"
										{time 170}
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
									{"music"
										{start "/music/airborne_orchestra.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 178}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/usa_battle_lvl1.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 141}
									}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "bot_army$"}
								{op "=="}
								{value 5}
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
									{"music"
										{start "/music/cmw_action_lvl1.wav"}
										{stop_all}
										{volume game}
										{fade 5}
										{loop}
									}
									{"delay"
										{time 76}
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
									{"music"
										{start "/music/cmw_action_lvl3.wav"}
										{stop_all}
										{volume game}
										{fade 5}
										{loop}
									}
									{"delay"
										{time 106}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/cmw_action_lvl4.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 123}
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
										{value 0.4}
									}
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/action_theme_3.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 171}
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
									{"music"
										{start "/music/rus_battle_lvl3.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 60}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/action_theme_2.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 195}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"event"
						{event "music_detect"}
						{mode set}
						{delay 0}
					}
					{"delay"
						{time 5}
					}
					{"event"
						{event "music_reset"}
						{mode set}
						{delay 0}
					}
					{"delay"
						{time 0.1}
					}
					{"trigger"
						{name "music/music_intense"}
					}
				}
			}
			{"music/music_intense_attack"
				{condition
					{terms
						{"1.event"
							{id "music_intense"}
						}
						{"2.cmp_i"
							{var "music_rnd$"}
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
						{event "music_intense"}
						{mode reset}
						{delay 0}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "user_nation$"}
								{op "=="}
								{value 2}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
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
									{"switch"
										{"case"
											{condition
												{type rand}
												{value 0.5}
											}
											{"delay"
												{time 0.1}
											}
											{"music"
												{start "/music/ger_battle_west_lvl2.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 47}
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
											{"music"
												{start "/music/ger_valkyrie.wav"}
												{stop_all}
												{volume game}
												{fade 5}
												{loop}
											}
											{"delay"
												{time 67}
											}
										}
										{"default"
											{"delay"
												{time 0.1}
											}
											{"music"
												{start "/music/airborne_action_lvl1.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 110}
											}
										}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "bot_army$"}
										{op "=="}
										{value 5}
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
											{"music"
												{start "/music/ger_valkyrie.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 67}
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
											{"music"
												{start "/music/ger_battle_west_lvl2.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 47}
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
											{"music"
												{start "/music/cmw_action_lvl5.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 76}
											}
										}
										{"default"
											{"delay"
												{time 0.1}
											}
											{"music"
												{start "/music/cmw_action_lvl2.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 62}
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
											{"music"
												{start "/music/ger_action_lvl3.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 127}
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
											{"music"
												{start "/music/scorched_earth.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 95}
											}
										}
										{"default"
											{"delay"
												{time 0.1}
											}
											{"music"
												{start "/music/ger_battle_lvl2.wav"}
												{stop_all}
												{volume game}
												{fade 5}
											}
											{"delay"
												{time 113}
											}
										}
									}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "user_nation$"}
								{op "=="}
								{value 3}
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
									{"music"
										{start "/music/fin_battle_lvl2.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 94}
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
									{"music"
										{start "/music/finland.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 60}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/fin_battle_lvl3.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 300}
									}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "user_nation$"}
								{op "=="}
								{value 4}
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
									{"music"
										{start "/music/usa_battle_lvl3.wav"}
										{stop_all}
										{volume game}
										{fade 5}
										{loop}
									}
									{"delay"
										{time 170}
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
									{"music"
										{start "/music/airborne_orchestra.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 178}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/usa_battle_lvl1.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 141}
									}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "user_nation$"}
								{op "=="}
								{value 5}
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
									{"music"
										{start "/music/cmw_action_lvl1.wav"}
										{stop_all}
										{volume game}
										{fade 5}
										{loop}
									}
									{"delay"
										{time 76}
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
									{"music"
										{start "/music/cmw_action_lvl3.wav"}
										{stop_all}
										{volume game}
										{fade 5}
										{loop}
									}
									{"delay"
										{time 106}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/cmw_action_lvl4.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 123}
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
										{value 0.4}
									}
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/action_theme_3.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 171}
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
									{"music"
										{start "/music/rus_battle_lvl3.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 60}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/action_theme_2.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 195}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"event"
						{event "music_detect"}
						{mode set}
						{delay 0}
					}
					{"delay"
						{time 5}
					}
					{"event"
						{event "music_reset"}
						{mode set}
						{delay 0}
					}
					{"delay"
						{time 0.1}
					}
					{"trigger"
						{name "music/music_intense_attack"}
					}
				}
			}
			{"music/start"
				{condition
					{terms
						{"1.event"
							{id "music_start"}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"event"
						{event "music_rnd"}
						{mode set}
						{delay 0}
					}
					{"delay"
						{time 0.5}
					}
					{"event"
						{event "music_regular"}
						{mode set}
						{delay 0}
					}
				}
			}
			{"music/music_reset"
				{condition
					{expression "1 & !2 & !3"}
					{terms
						{"1.event"
							{id "music_reset"}
						}
						{"2.cmp_i"
							{var "music_hero$"}
							{op ">"}
							{value 2}
						}
						{"3.trigger"
							{name "music/music_detect"}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"event"
						{event "music_rnd"}
						{mode set}
						{delay 0}
					}
					{"event"
						{event "music_detect"}
						{mode reset}
						{delay 0}
					}
					{"delay"
						{time 0.5}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "music_intense$"}
								{op "=="}
								{value 0}
							}
							{"delay"
								{time 0.1}
							}
							{"event"
								{event "music_regular"}
								{mode set}
								{delay 0}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"event"
								{event "music_intense"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 0.1}
							}
							{"set_i"
								{var "music_intense$"}
								{op "="}
								{value 0}
							}
						}
					}
					{"delay"
						{time 4.8}
					}
					{"event"
						{event "music_reset"}
						{mode reset}
						{delay 0}
					}
					{"delay"
						{time 0.1}
					}
					{"trigger"
						{name "music/music_reset"}
					}
				}
			}
			{"music/init"
				{condition
				}
				{actions
					{"delay"
						{time 1.8}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "user_nation$"}
								{op "=="}
								{value 2}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
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
									{"switch"
										{"case"
											{condition
												{type rand}
												{value 0.5}
											}
											{"delay"
												{time 0.1}
											}
											{"music"
												{start "/music/ambient_west_1.wav"}
												{stop_all}
												{volume game}
												{fade 3}
											}
											{"delay"
												{time 163}
											}
											{"music"
												{stop "/music/ambient_west_1.wav"}
												{volume game}
												{fade 5}
											}
										}
										{"default"
											{"delay"
												{time 0.1}
											}
											{"music"
												{start "/music/ambient_west_2.wav"}
												{stop_all}
												{volume game}
												{fade 3}
											}
											{"delay"
												{time 126}
											}
											{"music"
												{stop "/music/ambient_west_2.wav"}
												{volume game}
												{fade 5}
											}
										}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "bot_army$"}
										{op "=="}
										{value 5}
									}
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/cmw_ambient_lvl3.wav"}
										{stop_all}
										{volume game}
										{fade 3}
									}
									{"delay"
										{time 91}
									}
									{"music"
										{stop "/music/cmw_ambient_lvl3.wav"}
										{volume game}
										{fade 4}
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
											{"music"
												{start "/music/ambient_1.wav"}
												{stop_all}
												{volume game}
												{fade 3}
											}
											{"delay"
												{time 130}
											}
											{"music"
												{stop "/music/ambient_1.wav"}
												{volume game}
												{fade 5}
											}
										}
										{"default"
											{"delay"
												{time 0.1}
											}
											{"music"
												{start "/music/ambient_2.wav"}
												{stop_all}
												{volume game}
												{fade 3}
											}
											{"delay"
												{time 107}
											}
											{"music"
												{stop "/music/ambient_2.wav"}
												{volume game}
												{fade 5}
											}
										}
									}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "user_nation$"}
								{op "=="}
								{value 3}
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
									{"music"
										{start "/music/fin_ambient_lvl1.wav"}
										{stop_all}
										{volume game}
										{fade 3}
									}
									{"delay"
										{time 157}
									}
									{"music"
										{stop "/music/fin_ambient_lvl1.wav"}
										{volume game}
										{fade 5}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/fin_ambient_lvl2.wav"}
										{stop_all}
										{volume game}
										{fade 3}
									}
									{"delay"
										{time 119}
									}
									{"music"
										{stop "/music/fin_ambient_lvl2.wav"}
										{volume game}
										{fade 5}
									}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "user_nation$"}
								{op "=="}
								{value 4}
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
									{"music"
										{start "/music/usa_ambient_lvl1.wav"}
										{stop_all}
										{volume game}
										{fade 3}
									}
									{"delay"
										{time 70}
									}
									{"music"
										{stop "/music/usa_ambient_lvl1.wav"}
										{volume game}
										{fade 5}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/usa_ambient_lvl2.wav"}
										{stop_all}
										{volume game}
										{fade 3}
									}
									{"delay"
										{time 64}
									}
									{"music"
										{stop "/music/usa_ambient_lvl2.wav"}
										{volume game}
										{fade 5}
									}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "user_nation$"}
								{op "=="}
								{value 5}
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
									{"music"
										{start "/music/cmw_ambient_lvl1.wav"}
										{stop_all}
										{volume game}
										{fade 3}
									}
									{"delay"
										{time 154}
									}
									{"music"
										{stop "/music/cmw_ambient_lvl1.wav"}
										{volume game}
										{fade 5}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/cmw_ambient_lvl2.wav"}
										{stop_all}
										{volume game}
										{fade 3}
									}
									{"delay"
										{time 175}
									}
									{"music"
										{stop "/music/cmw_ambient_lvl2.wav"}
										{volume game}
										{fade 5}
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
									{"music"
										{start "/music/rus_ambient_lvl1.wav"}
										{stop_all}
										{volume game}
										{fade 3}
									}
									{"delay"
										{time 101}
									}
									{"music"
										{stop "/music/rus_ambient_lvl1.wav"}
										{volume game}
										{fade 5}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/ambient_3.wav"}
										{stop_all}
										{volume game}
										{fade 3}
									}
									{"delay"
										{time 93}
									}
									{"music"
										{stop "/music/ambient_3.wav"}
										{volume game}
										{fade 5}
									}
								}
							}
						}
					}
					{"delay"
						{time 3}
					}
					{"event"
						{event "music_start"}
						{mode set}
						{delay 0}
					}
					{"set_i"
						{var "music_intense$"}
						{op "="}
						{value 0}
					}
					{"set_i"
						{var "music_hero$"}
						{op "="}
						{value 0}
					}
				}
			}
			{"music/music_detect"
				{condition
					{expression "(1 & 2) | (1 & 3) | (1 & 4)"}
					{terms
						{"1.event"
							{id "music_detect"}
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
										{prop
											{prop human}
										}
										{state
											{state dead}
										}
									}
									{exclude
										{tag
											{tag _m}
										}
									}
								}
								{amount 3
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
							{distance 45}
						}
						{"3.entities"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag _user}
										}
										{tag
											{tag _bot}
										}
									}
									{include
										{zone
											{zone "gamezone"}
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
										{tag
											{tag _m}
										}
									}
								}
							}
						}
						{"4.signal"
							{zone "combat"}
							{signals "explosion mandie"}
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
								{value 0.33}
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
										{var "music_hero$"}
										{op "=="}
										{value 0}
									}
									{"delay"
										{time 0.1}
									}
									{"set_i"
										{var "music_hero$"}
										{op "="}
										{value 1}
									}
								}
								{"default"}
							}
							{"delay"
								{time 0.1}
							}
							{"set_i"
								{var "music_intense$"}
								{op "="}
								{value 1}
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
											{prop
												{prop human}
											}
											{state
												{state dead}
											}
										}
										{exclude
											{tag
												{tag _m}
											}
										}
									}
									{amount 3
									}
								}
								{tag_add _m}
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
											{tag
												{tag _bot}
											}
										}
										{include
											{zone
												{zone "gamezone"}
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
											{tag
												{tag _m}
											}
											{state
												{state inactive}
											}
										}
									}
									{amount 1
									}
								}
								{tag_add _m}
							}
						}
					}
					{"delay"
						{time 3.9}
					}
					{"event"
						{event "music_detect"}
						{mode reset}
						{delay 0}
					}
					{"delay"
						{time 0.4}
					}
					{"trigger"
						{name "music/music_detect"}
					}
				}
			}
			{"music/hero"
				{condition
					{expression "(1 & 2 & 3 & 4) | (1 & 2 & 3 & 5)"}
					{terms
						{"1.event"
							{id "music_detect"}
						}
						{"2.cmp_i"
							{var "music_hero$"}
							{op "=="}
							{value 1}
						}
						{"3.near"
							{units
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
										{prop
											{prop airborne}
										}
										{state
											{state inactive}
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
							{distance 80}
						}
						{"4.entities"
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
											{tag player_armor}
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
							{count
								{op ">="}
								{value 4}
							}
						}
						{"5.entities"
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
											{tag player}
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
							{count
								{op ">"}
								{value 50}
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
								{type trigger}
								{name "music/music_reset"}
							}
							{"delay"
								{time 10}
							}
							{"trigger"
								{name "music/hero"}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"set_i"
								{var "music_hero$"}
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
										{var "user_nation$"}
										{op "=="}
										{value 2}
									}
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/panzerlied.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 199}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "user_nation$"}
										{op "=="}
										{value 3}
									}
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/fin_orchestra.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 169}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "user_nation$"}
										{op "=="}
										{value 4}
									}
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/usa_orchestra.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 93}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "user_nation$"}
										{op "=="}
										{value 5}
									}
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/cmw_theme_02.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 169}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"music"
										{start "/music/russian_theme.wav"}
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 113}
									}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"set_i"
								{var "music_hero$"}
								{op "="}
								{value 2}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type event}
										{id "music_reset"}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"event"
										{event "music_reset"}
										{mode set}
										{delay 0}
									}
								}
							}
						}
					}
				}
			}
			{"music/music_rnd"
				{condition
					{terms
						{"1.event"
							{id "music_rnd"}
						}
						{"2.cmp_i"
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
					{"event"
						{event "music_rnd"}
						{mode reset}
						{delay 0}
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
							{"set_i"
								{var "music_rnd$"}
								{op "="}
								{value 1}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"set_i"
								{var "music_rnd$"}
								{op "="}
								{value 0}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"trigger"
						{name "music/music_rnd"}
					}
				}
			}
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
						{var "music_rnd$"}
						{op "="}
						{value 0}
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
						{time 1}
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
				}
				{actions
					{"delay"
						{time 1.5}
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
						{"default"
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "bot_difficulty$"}
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
													{amount 2
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
													{amount 2
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
													{amount 2
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
													{amount 2
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
													{amount 2
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
											{amount 7
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
											{amount 7
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
											{amount 7
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
											{amount 7
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
											{amount 7
											}
										}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "bot_difficulty$"}
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
													{amount 1
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
													{amount 1
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
													{amount 1
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
													{amount 1
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
													{amount 1
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
											{amount 5
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
											{amount 5
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
											{amount 5
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
											{amount 5
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
											{amount 5
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
									{prop
										{prop no_scavenge}
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
						{time 0.5}
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
											{tag
												{tag airstrike_eng}
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
											{tag
												{tag airstrike_eng}
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
											{tag
												{tag airstrike_eng}
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
											{tag
												{tag airstrike_eng}
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
								{value 5}
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
												{tag airstrike_rus}
											}
											{tag
												{tag airstrike_ger}
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
											{tag
												{tag airstrike_eng}
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
											{tag
												{tag airstrike_eng}
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
											{tag
												{tag airstrike_eng}
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
											{tag
												{tag airstrike_eng}
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
											{tag
												{tag airstrike_eng}
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
								{title "mission/multi/dcg_error01"}
							}
							{"con"
								{text "(Warning) - dcg error 01: enemyid is above 4.(setting to 5)"}
							}
							{"delay"
								{time 5}
							}
							{"objective_progress"
								{hide}
								{set 0}
								{add 0}
								{title "mission/multi/dcg_error01"}
							}
						}
					}
				}
			}
			{"dcg/player_nation"
				{condition
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
						{"case"
							{condition
								{type side}
								{side eng}
							}
							{"delay"
								{time 0.1}
							}
							{"set_i"
								{var "user_nation$"}
								{op "="}
								{value 5}
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
								{title "mission/multi/dcg_error02"}
							}
							{"con"
								{text "(Warning) - dcg error 02: user nation unknown.(defaulting to rus)"}
							}
							{"delay"
								{time 10}
							}
							{"objective_progress"
								{hide}
								{set 0}
								{add 0}
								{title "mission/multi/dcg_error02"}
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
										{tag
											{tag _user}
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
											{state inactive}
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
						{time 1}
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
												{tag _user}
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
												{state inactive}
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
													{tag
														{tag _user}
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
														{state inactive}
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
														{state operatable}
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
														{state operatable}
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
														{state operatable}
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
						{"default"
							{"delay"
								{time 5}
							}
							{"trigger"
								{name "dcg/warning_mines"}
							}
						}
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
								{meters 195}
							}
							{tag
								{"tag pair"}
								{"for selector" tow_act}
							}
						}
						{"2.entities"
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
											{state linked}
										}
									}
									{exclude
										{state
											{state operatable}
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
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag tow_act}
								}
							}
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
												{tag bot_tow}
											}
										}
										{include
											{prop
												{prop vehicle}
											}
											{state
												{state linked}
											}
										}
										{exclude
											{tag
												{tag tow_act}
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
								{tag_add tow_drop}
								{tag_remove bot_tow}
							}
							{"delay"
								{time 0.2}
							}
							{"linker"
								{selector
									{type vehicle}
								}
								{action unlink}
								{entities
									{ignore_captured_by_user 0}
									{tag tow_drop}
								}
							}
							{"delay"
								{time 2}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag tow_drop}
								}
								{tag_remove tow_drop}
							}
						}
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
			{"ai/ai_flag_smoke"
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
											{state operatable}
										}
										;{state
										;	{state user_control}
										;}
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
							}
							{distance
								{mode near_than}
								{meters 140}
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
								{distance 170}
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
								{tag_remove smk_}
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
							{"inventory"
								{selector
									{tag ai_smoke}
									{type human}
									{state "not dead"}
								}
								{action take}
								{item "smoke"}
							}
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
									{"actor_fire"
										{selector
											{tag ai_smoke}
											{type human}
											{state operatable}
										}
										{drop "orders sensor senseless"}
										{deviate}
										{enemies
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
												{type entity}
												{entity
													{ignore_captured_by_user 0}
													{tag ai_smoke}
												}
											}
											{amount 1
											}
										}
										{interval 0}
										{time 0}
										{burst_mode once}
									}
									{"delay"
										{time 8}
									}
									{"action"
										{selector
											{tag ai_smoke}
											{type human}
											{state operatable}
										}
										{action advance}
										{target
											{ignore_captured_by_user 0}
											{tag smk_target}
										}
									}
									{"delay"
										{time 3}
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
											{advance_ratio "0.2"}
										}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"actor_fire"
										{selector
											{tag ai_smoke}
											{type human}
											{state operatable}
										}
										{drop "orders sensor senseless"}
										{deviate}
										{enemies
											{ignore_captured_by_user 0}
											{tag smk_target}
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
											{advance_ratio 1}
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
							{tag smk_target}
						}
						{tag_remove smk_target}
					}
					{"delay"
						{time 0.5}
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
						{time 45}
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
									{prop
										{prop airborne}
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
								{"for enemy" _noted}
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
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag smk_veh_target}
						}
						{tag_remove smk_veh_target}
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
						{tag_remove _mi_temp_veh_smoke}
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
									{"delete"
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
									{"delete"
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
			{"dcg/def/show"
				{condition
					{expression "!1 & 2 & 3"}
					{terms
						{"1.event"
							{id "talk_on"}
						}
						{"2.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 1}
						}
						{"3.cmp_i"
							{var "arrows$"}
							{op ">"}
							{value 0}
						}
					}
				}
				{actions
					{"delay"
						{time 2}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "prep_inform$"}
								{op "=="}
								{value 1}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"set_i"
								{var "display$"}
								{op "="}
								{value 4}
							}
							{"event"
								{event "talk_on"}
								{mode set}
								{delay 0}
							}
							{"sound"
								{name "interface/morse"}
							}
							{"delay"
								{time 6}
							}
							{"switch"
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
									{"talk"
										{selector
											{ignore_captured_by_user 0}
											{amount 1
											}
											{tag player}
											{zone "gamezone"}
											{type human}
											{state operatable}
										}
										{text "mission/multi/display_defense_ger"}
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
									{"talk"
										{selector
											{ignore_captured_by_user 0}
											{amount 1
											}
											{tag player}
											{zone "gamezone"}
											{type human}
											{state operatable}
										}
										{text "mission/multi/display_defense_fin"}
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
									{"talk"
										{selector
											{ignore_captured_by_user 0}
											{amount 1
											}
											{tag player}
											{zone "gamezone"}
											{type human}
											{state operatable}
										}
										{text "mission/multi/display_defense_usa"}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "bot_army$"}
										{op "=="}
										{value 5}
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
											{state operatable}
										}
										{text "mission/multi/display_defense_eng"}
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
											{state operatable}
										}
										{text "mission/multi/display_defense_rus"}
									}
								}
							}
							{"delay"
								{time 10}
							}
							{"event"
								{event "talk_on"}
								{mode reset}
								{delay 0}
							}
							{"set_i"
								{var "display$"}
								{op "="}
								{value 0}
							}
						}
					}
				}
			}
			{"dcg/def/display_a"
				{condition
					{expression "1 & 2 & !3"}
					{terms
						{"1.cmp_i"
							{var "display$"}
							{op ">"}
							{value 0}
						}
						{"2.cmp_i"
							{var "arrows$"}
							{op "=="}
							{value 1}
						}
						{"3.event"
							{id "dcg2/defense_prep_end"}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"spawn"
						{entity "conquest_spawn_helper"}
						{waypoint "0"}
					}
					{"set_i"
						{var "display$"}
						{op "-"}
						{value 1}
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
										{tag spawn_a}
									}
								}
								{exclude
									{tag
										{tag _displayed}
									}
								}
							}
							{amount 1
							}
						}
						{tag_add _d}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag conquest_spawn_helper}
									}
								}
								{exclude
									{tag
										{tag _placed}
									}
								}
							}
						}
						{tag_add _p}
					}
					{"delay"
						{time 0.2}
					}
					{"placement"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag conquest_spawn_helper}
									}
								}
								{include
									{tag
										{tag _p}
									}
								}
							}
						}
						{target
							{ignore_captured_by_user 0}
							{tag _d}
						}
					}
					{"delay"
						{time 0.2}
					}
					{"effect"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag conquest_spawn_helper}
									}
								}
								{include
									{tag
										{tag _p}
									}
								}
							}
						}
						{effect start}
					}
					{"delay"
						{time 0.2}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _d}
						}
						{tag_add _displayed}
						{tag_remove _d}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _p}
						}
						{tag_add _placed}
						{tag_remove _p}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "display$"}
								{op "<<="}
								{value 0}
							}
							{"delay"
								{time 1}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag _displayed}
								}
								{tag_remove _displayed}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag _placed}
								}
								{tag_remove _placed}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"trigger"
								{name "dcg/def/display_a"}
							}
						}
					}
				}
			}
			{"dcg/def/display_b"
				{condition
					{expression "1 & 2 & !3"}
					{terms
						{"1.cmp_i"
							{var "display$"}
							{op ">"}
							{value 0}
						}
						{"2.cmp_i"
							{var "arrows$"}
							{op "=="}
							{value 2}
						}
						{"3.event"
							{id "dcg2/defense_prep_end"}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"spawn"
						{entity "conquest_spawn_helper"}
						{waypoint "0"}
					}
					{"set_i"
						{var "display$"}
						{op "-"}
						{value 1}
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
										{tag spawn_b}
									}
								}
								{exclude
									{tag
										{tag _displayed}
									}
								}
							}
							{amount 1
							}
						}
						{tag_add _d}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag conquest_spawn_helper}
									}
								}
								{exclude
									{tag
										{tag _placed}
									}
								}
							}
						}
						{tag_add _p}
					}
					{"delay"
						{time 0.2}
					}
					{"placement"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag conquest_spawn_helper}
									}
								}
								{include
									{tag
										{tag _p}
									}
								}
							}
						}
						{target
							{ignore_captured_by_user 0}
							{tag _d}
						}
					}
					{"delay"
						{time 0.2}
					}
					{"effect"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag conquest_spawn_helper}
									}
								}
								{include
									{tag
										{tag _p}
									}
								}
							}
						}
						{effect start}
					}
					{"delay"
						{time 0.2}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _d}
						}
						{tag_add _displayed}
						{tag_remove _d}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _p}
						}
						{tag_add _placed}
						{tag_remove _p}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "display$"}
								{op "<<="}
								{value 0}
							}
							{"delay"
								{time 1}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag _displayed}
								}
								{tag_remove _displayed}
							}
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag _placed}
								}
								{tag_remove _placed}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"trigger"
								{name "dcg/def/display_b"}
							}
						}
					}
				}
			}
			{"dcg2/init"
				{condition
				}
				{actions
					{"call"
						{function "default_spawns"}
					}
					{"delay"
						{time 0.1}
					}
					{"set_i"
						{var "attacker_retreat_requested$"}
						{op "="}
						{value 0}
					}
					{"set_i"
						{var "defender_retreat_requested$"}
						{op "="}
						{value 0}
					}
					{"set_i"
						{var "bot_retreat_active$"}
						{op "="}
						{value 0}
					}
					{"set_i"
						{var "flags$"}
						{op "="}
						{value 0}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "garrison_end$"}
								{op ">"}
								{value 0}
							}
						}
						{"default"
							{"set_i"
								{var "garrison_end$"}
								{op "="}
								{value 0}
							}
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
						}
						{"default"
							{"event"
								{event "dcg2/attack_bot_spawning"}
								{mode set}
								{delay 0}
							}
							{"set_i"
								{var "garrison_ready$"}
								{op "="}
								{value 0}
							}
							{"set_i"
								{var "attacker_retreat_requested$"}
								{op "="}
								{value 0}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "bots_spawnside$"}
										{op "=="}
										{value 1}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag spawn_a}
										}
										{tag_add _s_notmoved}
									}
								}
								{"default"
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag spawn_b}
										}
										{tag_add _s_notmoved}
									}
								}
							}
						}
					}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag flag}
									{zone "fpc1"}
								}
							}
							{"set_i"
								{var "flag1$"}
								{op "="}
								{value 1}
							}
							{"set_i"
								{var "flags$"}
								{op "+"}
								{value 1}
							}
							{"if"
								{condition
									{type rand}
									{value 0.5}
								}
								{"set_i"
									{var "gun1_tele$"}
									{op "="}
									{value 2}
								}
							}
							{"if"
								{condition
									{type rand}
									{value 0.5}
								}
								{"set_i"
									{var "tank1_tele$"}
									{op "="}
									{value 2}
								}
							}
							{"if"
								{condition
									{type rand}
									{value 0.5}
								}
								{"set_i"
									{var "arty1_rnd$"}
									{op "="}
									{value 3}
								}
							}
							{"event"
								{event "flag1"}
								{mode set}
								{delay 0}
							}
						}
						{"default"
							{"set_i"
								{var "flag1$"}
								{op "="}
								{value 0}
							}
						}
					}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag flag}
									{zone "fpc2"}
								}
							}
							{"set_i"
								{var "flag2$"}
								{op "="}
								{value 1}
							}
							{"set_i"
								{var "flags$"}
								{op "+"}
								{value 1}
							}
							{"if"
								{condition
									{type rand}
									{value 0.5}
								}
								{"set_i"
									{var "gun2_tele$"}
									{op "="}
									{value 2}
								}
							}
							{"if"
								{condition
									{type rand}
									{value 0.5}
								}
								{"set_i"
									{var "tank2_tele$"}
									{op "="}
									{value 2}
								}
							}
							{"if"
								{condition
									{type rand}
									{value 0.5}
								}
								{"set_i"
									{var "arty2_rnd$"}
									{op "="}
									{value 3}
								}
							}
							{"event"
								{event "flag2"}
								{mode set}
								{delay 0}
							}
						}
						{"default"
							{"set_i"
								{var "flag2$"}
								{op "="}
								{value 0}
							}
						}
					}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag flag}
									{zone "fpc3"}
								}
							}
							{"set_i"
								{var "flag3$"}
								{op "="}
								{value 1}
							}
							{"set_i"
								{var "flags$"}
								{op "+"}
								{value 1}
							}
							{"if"
								{condition
									{type rand}
									{value 0.5}
								}
								{"set_i"
									{var "gun3_tele$"}
									{op "="}
									{value 2}
								}
							}
							{"if"
								{condition
									{type rand}
									{value 0.5}
								}
								{"set_i"
									{var "tank3_tele$"}
									{op "="}
									{value 2}
								}
							}
							{"if"
								{condition
									{type rand}
									{value 0.5}
								}
								{"set_i"
									{var "arty3_rnd$"}
									{op "="}
									{value 3}
								}
							}
							{"event"
								{event "flag3"}
								{mode set}
								{delay 0}
							}
						}
						{"default"
							{"set_i"
								{var "flag3$"}
								{op "="}
								{value 0}
							}
						}
					}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag flag}
									{zone "fpc4"}
								}
							}
							{"set_i"
								{var "flag4$"}
								{op "="}
								{value 1}
							}
							{"set_i"
								{var "flags$"}
								{op "+"}
								{value 1}
							}
							{"if"
								{condition
									{type rand}
									{value 0.5}
								}
								{"set_i"
									{var "gun4_tele$"}
									{op "="}
									{value 2}
								}
							}
							{"if"
								{condition
									{type rand}
									{value 0.5}
								}
								{"set_i"
									{var "tank4_tele$"}
									{op "="}
									{value 2}
								}
							}
							{"if"
								{condition
									{type rand}
									{value 0.5}
								}
								{"set_i"
									{var "arty4_rnd$"}
									{op "="}
									{value 3}
								}
							}
							{"event"
								{event "flag4"}
								{mode set}
								{delay 0}
							}
						}
						{"default"
							{"set_i"
								{var "flag4$"}
								{op "="}
								{value 0}
							}
						}
					}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag flag}
									{zone "fpc5"}
								}
							}
							{"set_i"
								{var "flag5$"}
								{op "="}
								{value 1}
							}
							{"set_i"
								{var "flags$"}
								{op "+"}
								{value 1}
							}
							{"if"
								{condition
									{type rand}
									{value 0.5}
								}
								{"set_i"
									{var "gun5_tele$"}
									{op "="}
									{value 2}
								}
							}
							{"if"
								{condition
									{type rand}
									{value 0.5}
								}
								{"set_i"
									{var "tank5_tele$"}
									{op "="}
									{value 2}
								}
							}
							{"if"
								{condition
									{type rand}
									{value 0.5}
								}
								{"set_i"
									{var "arty5_rnd$"}
									{op "="}
									{value 3}
								}
							}
							{"event"
								{event "flag5"}
								{mode set}
								{delay 0}
							}
						}
						{"default"
							{"set_i"
								{var "flag5$"}
								{op "="}
								{value 0}
							}
						}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "prep_inform$"}
								{op ">"}
								{value 0}
							}
						}
						{"default"
							{"set_i"
								{var "prep_inform$"}
								{op "="}
								{value 0}
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
									{zone
										{zone "gamezone"}
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
								}
							}
						}
						{tag_add _garrison_off}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{include
									{prop
										{prop no_scavenge}
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
						{tag_add _garrison_off}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _garrison_off}
						}
						{tag_add "+garrisoned"}
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
									{zone
										{zone "gamezone"}
									}
								}
								{include
									{prop
										{prop creature}
									}
									{state
										{state operatable}
									}
								}
								{exclude
									{prop
										{prop human}
									}
									{prop
										{prop vehicle}
									}
									{state
										{state user_control}
									}
								}
							}
						}
						{tag_add _animal}
						{tag_remove "_garrison_todo+"}
					}
					{"event"
						{event "dcg2/flags_set"}
						{mode set}
						{delay 0}
					}
				}
			}
			{"dcg2/botdefend/setup"
				{condition
					{terms
						{"1.cmp_i"
							{var "garrison_ready$"}
							{op "=="}
							{value 0}
						}
						{"2.entities"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{zone
											{zone "forward1"}
										}
										{zone
											{zone "forward2"}
										}
										{zone
											{zone "forward3"}
										}
										{zone
											{zone "forward4"}
										}
										{zone
											{zone "forward5"}
										}
									}
									{include
										{tag
											{tag "_garrison_todo+"}
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
						}
						{"3.event"
							{id "dcg2/flags_set"}
						}
					}
				}
				{actions
					{"actor_state"
						{selector
							{ignore_captured_by_user 0}
							{tag "_garrison_todo+"}
							{type human}
							{state operatable}
						}
						{movement
							{speed assault}
						}
					}
					{"actor_state"
						{selector
							{ignore_captured_by_user 0}
							{tag "_garrison_todo+"}
							{type vehicle}
							{state operatable}
						}
						{drop orders}
						{ai_move
							{mode enable}
						}
					}
					{"if"
						{condition
							{type cmp_i}
							{var "flag1$"}
							{op ">"}
							{value 0}
						}
						{"call"
							{function "flag1_bots_d"}
						}
					}
					{"delay"
						{time 0.05}
					}
					{"if"
						{condition
							{type cmp_i}
							{var "flag2$"}
							{op ">"}
							{value 0}
						}
						{"call"
							{function "flag2_bots_d"}
						}
					}
					{"delay"
						{time 0.05}
					}
					{"if"
						{condition
							{type cmp_i}
							{var "flag3$"}
							{op ">"}
							{value 0}
						}
						{"call"
							{function "flag3_bots_d"}
						}
					}
					{"delay"
						{time 0.05}
					}
					{"if"
						{condition
							{type cmp_i}
							{var "flag4$"}
							{op ">"}
							{value 0}
						}
						{"call"
							{function "flag4_bots_d"}
						}
					}
					{"delay"
						{time 0.05}
					}
					{"if"
						{condition
							{type cmp_i}
							{var "flag5$"}
							{op ">"}
							{value 0}
						}
						{"call"
							{function "flag5_bots_d"}
						}
					}
					{"delay"
						{time 1.2}
					}
					{"trigger"
						{name "dcg2/botdefend/setup"}
					}
				}
			}
			{"dcg2/botdefend/start2flags"
				{condition
					{terms
						{"1.cmp_i"
							{var "garrison_end$"}
							{op "=="}
							{value 0}
						}
						{"2.cmp_i"
							{var "flags$"}
							{op "=="}
							{value 2}
						}
						{"3.event"
							{id "dcg2/flags_set"}
						}
						{"4.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 0}
						}
					}
				}
				{actions
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "bots_spawnside$"}
								{op "=="}
								{value 1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "flag1$"}
										{op ">"}
										{value 0}
									}
									{"entity_state"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag a1}
													}
													{tag
														{tag a2}
													}
												}
											}
										}
										{tag_add _s_move}
										{tag_remove _s_notmoved}
									}
									{"delay"
										{time 0.05}
									}
									{"placement"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag _s_move}
													}
												}
												{exclude
													{tag
														{tag _s_moved}
													}
												}
											}
										}
										{target_waypoint "15"}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag _s_move}
										}
										{tag_add _s_moved}
									}
								}
								{"default"}
							}
							{"delay"
								{time 0.05}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "flag2$"}
										{op ">"}
										{value 0}
									}
									{"switch"
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag _s_notmoved}
												}
												{count
													{op ">"}
													{value 2}
												}
											}
											{"delay"
												{time 0.01}
											}
											{"entity_state"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag a1}
															}
															{tag
																{tag a2}
															}
														}
													}
												}
												{tag_add _s_move}
												{tag_remove _s_notmoved}
											}
											{"delay"
												{time 0.05}
											}
											{"placement"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag _s_move}
															}
														}
														{exclude
															{tag
																{tag _s_moved}
															}
														}
													}
												}
												{target_waypoint "16"}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{tag _s_move}
												}
												{tag_add _s_moved}
											}
										}
										{"default"
											{"delay"
												{time 0.01}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{amount 2
													}
													{tag _s_notmoved}
												}
												{tag_add _s_move}
												{tag_remove _s_notmoved}
											}
											{"delay"
												{time 0.05}
											}
											{"placement"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag _s_move}
															}
														}
														{exclude
															{tag
																{tag _s_moved}
															}
														}
													}
													{amount 2
													}
												}
												{target_waypoint "16"}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{tag _s_move}
												}
												{tag_add _s_moved}
											}
										}
									}
								}
								{"default"}
							}
							{"delay"
								{time 0.05}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "flag3$"}
										{op ">"}
										{value 0}
									}
									{"switch"
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag _s_notmoved}
												}
												{count
													{op ">"}
													{value 2}
												}
											}
											{"delay"
												{time 0.01}
											}
											{"entity_state"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag a1}
															}
															{tag
																{tag a2}
															}
														}
													}
												}
												{tag_add _s_move}
												{tag_remove _s_notmoved}
											}
											{"delay"
												{time 0.05}
											}
											{"placement"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag _s_move}
															}
														}
														{exclude
															{tag
																{tag _s_moved}
															}
														}
													}
												}
												{target_waypoint "17"}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{tag _s_move}
												}
												{tag_add _s_moved}
											}
										}
										{"default"
											{"delay"
												{time 0.01}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{amount 2
													}
													{tag _s_notmoved}
												}
												{tag_add _s_move}
												{tag_remove _s_notmoved}
											}
											{"delay"
												{time 0.05}
											}
											{"placement"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag _s_move}
															}
														}
														{exclude
															{tag
																{tag _s_moved}
															}
														}
													}
													{amount 2
													}
												}
												{target_waypoint "17"}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{tag _s_move}
												}
												{tag_add _s_moved}
											}
										}
									}
								}
								{"default"}
							}
							{"delay"
								{time 0.05}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "flag4$"}
										{op ">"}
										{value 0}
									}
									{"switch"
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag _s_notmoved}
												}
												{count
													{op ">"}
													{value 2}
												}
											}
											{"delay"
												{time 0.01}
											}
											{"entity_state"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag a1}
															}
															{tag
																{tag a2}
															}
														}
													}
												}
												{tag_add _s_move}
												{tag_remove _s_notmoved}
											}
											{"delay"
												{time 0.05}
											}
											{"placement"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag _s_move}
															}
														}
														{exclude
															{tag
																{tag _s_moved}
															}
														}
													}
												}
												{target_waypoint "18"}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{tag _s_move}
												}
												{tag_add _s_moved}
											}
										}
										{"default"
											{"delay"
												{time 0.01}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{amount 2
													}
													{tag _s_notmoved}
												}
												{tag_add _s_move}
												{tag_remove _s_notmoved}
											}
											{"delay"
												{time 0.05}
											}
											{"placement"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag _s_move}
															}
														}
														{exclude
															{tag
																{tag _s_moved}
															}
														}
													}
													{amount 2
													}
												}
												{target_waypoint "18"}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{tag _s_move}
												}
												{tag_add _s_moved}
											}
										}
									}
								}
								{"default"}
							}
							{"delay"
								{time 0.05}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "flag5$"}
										{op ">"}
										{value 0}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{amount 2
											}
											{tag _s_notmoved}
										}
										{tag_add _s_move}
										{tag_remove _s_notmoved}
									}
									{"delay"
										{time 0.05}
									}
									{"placement"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag _s_move}
													}
												}
												{exclude
													{tag
														{tag _s_moved}
													}
												}
											}
											{amount 2
											}
										}
										{target_waypoint "19"}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag _s_move}
										}
										{tag_add _s_moved}
									}
								}
								{"default"}
							}
						}
						{"default"
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "flag1$"}
										{op ">"}
										{value 0}
									}
									{"entity_state"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag b1}
													}
													{tag
														{tag b2}
													}
												}
											}
										}
										{tag_add _s_move}
										{tag_remove _s_notmoved}
									}
									{"delay"
										{time 0.05}
									}
									{"placement"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag _s_move}
													}
												}
												{exclude
													{tag
														{tag _s_moved}
													}
												}
											}
										}
										{target_waypoint "20"}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag _s_move}
										}
										{tag_add _s_moved}
									}
								}
								{"default"}
							}
							{"delay"
								{time 0.05}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "flag2$"}
										{op ">"}
										{value 0}
									}
									{"switch"
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag _s_notmoved}
												}
												{count
													{op ">"}
													{value 2}
												}
											}
											{"delay"
												{time 0.01}
											}
											{"entity_state"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag b1}
															}
															{tag
																{tag b2}
															}
														}
													}
												}
												{tag_add _s_move}
												{tag_remove _s_notmoved}
											}
											{"delay"
												{time 0.05}
											}
											{"placement"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag _s_move}
															}
														}
														{exclude
															{tag
																{tag _s_moved}
															}
														}
													}
												}
												{target_waypoint "21"}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{tag _s_move}
												}
												{tag_add _s_moved}
											}
										}
										{"default"
											{"delay"
												{time 0.01}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{amount 2
													}
													{tag _s_notmoved}
												}
												{tag_add _s_move}
												{tag_remove _s_notmoved}
											}
											{"delay"
												{time 0.05}
											}
											{"placement"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag _s_move}
															}
														}
														{exclude
															{tag
																{tag _s_moved}
															}
														}
													}
													{amount 2
													}
												}
												{target_waypoint "21"}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{tag _s_move}
												}
												{tag_add _s_moved}
											}
										}
									}
								}
								{"default"}
							}
							{"delay"
								{time 0.05}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "flag3$"}
										{op ">"}
										{value 0}
									}
									{"switch"
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag _s_notmoved}
												}
												{count
													{op ">"}
													{value 2}
												}
											}
											{"delay"
												{time 0.01}
											}
											{"entity_state"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag b1}
															}
															{tag
																{tag b2}
															}
														}
													}
												}
												{tag_add _s_move}
												{tag_remove _s_notmoved}
											}
											{"delay"
												{time 0.05}
											}
											{"placement"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag _s_move}
															}
														}
														{exclude
															{tag
																{tag _s_moved}
															}
														}
													}
												}
												{target_waypoint "22"}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{tag _s_move}
												}
												{tag_add _s_moved}
											}
										}
										{"default"
											{"delay"
												{time 0.01}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{amount 2
													}
													{tag _s_notmoved}
												}
												{tag_add _s_move}
												{tag_remove _s_notmoved}
											}
											{"delay"
												{time 0.05}
											}
											{"placement"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag _s_move}
															}
														}
														{exclude
															{tag
																{tag _s_moved}
															}
														}
													}
													{amount 2
													}
												}
												{target_waypoint "22"}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{tag _s_move}
												}
												{tag_add _s_moved}
											}
										}
									}
								}
								{"default"}
							}
							{"delay"
								{time 0.05}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "flag4$"}
										{op ">"}
										{value 0}
									}
									{"switch"
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag _s_notmoved}
												}
												{count
													{op ">"}
													{value 2}
												}
											}
											{"delay"
												{time 0.01}
											}
											{"entity_state"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag b1}
															}
															{tag
																{tag b2}
															}
														}
													}
												}
												{tag_add _s_move}
												{tag_remove _s_notmoved}
											}
											{"delay"
												{time 0.05}
											}
											{"placement"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag _s_move}
															}
														}
														{exclude
															{tag
																{tag _s_moved}
															}
														}
													}
												}
												{target_waypoint "23"}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{tag _s_move}
												}
												{tag_add _s_moved}
											}
										}
										{"default"
											{"delay"
												{time 0.01}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{amount 2
													}
													{tag _s_notmoved}
												}
												{tag_add _s_move}
												{tag_remove _s_notmoved}
											}
											{"delay"
												{time 0.05}
											}
											{"placement"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag _s_move}
															}
														}
														{exclude
															{tag
																{tag _s_moved}
															}
														}
													}
													{amount 2
													}
												}
												{target_waypoint "23"}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{tag _s_move}
												}
												{tag_add _s_moved}
											}
										}
									}
								}
								{"default"}
							}
							{"delay"
								{time 0.05}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "flag5$"}
										{op ">"}
										{value 0}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{amount 2
											}
											{tag _s_notmoved}
										}
										{tag_add _s_move}
										{tag_remove _s_notmoved}
									}
									{"delay"
										{time 0.05}
									}
									{"placement"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag _s_move}
													}
												}
												{exclude
													{tag
														{tag _s_moved}
													}
												}
											}
											{amount 2
											}
										}
										{target_waypoint "24"}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag _s_move}
										}
										{tag_add _s_moved}
									}
								}
								{"default"}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"call"
						{function "debug_garrison"}
					}
				}
			}
			{"dcg2/botdefend/start3flags"
				{condition
					{terms
						{"1.cmp_i"
							{var "garrison_end$"}
							{op "=="}
							{value 0}
						}
						{"2.cmp_i"
							{var "flags$"}
							{op "=="}
							{value 3}
						}
						{"3.event"
							{id "dcg2/flags_set"}
						}
						{"4.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 0}
						}
					}
				}
				{actions
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "bots_spawnside$"}
								{op "=="}
								{value 1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "flag1$"}
										{op ">"}
										{value 0}
									}
									{"entity_state"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag a1}
													}
													{tag
														{tag a2}
													}
												}
											}
										}
										{tag_add _s_move}
										{tag_remove _s_notmoved}
									}
									{"delay"
										{time 0.05}
									}
									{"placement"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag _s_move}
													}
												}
												{exclude
													{tag
														{tag _s_moved}
													}
												}
											}
										}
										{target_waypoint "15"}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag _s_move}
										}
										{tag_add _s_moved}
									}
								}
								{"default"}
							}
							{"delay"
								{time 0.05}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "flag2$"}
										{op ">"}
										{value 0}
									}
									{"switch"
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag _s_notmoved}
												}
												{count
													{op ">"}
													{value 2}
												}
											}
											{"delay"
												{time 0.01}
											}
											{"entity_state"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag a1}
															}
															{tag
																{tag a2}
															}
														}
													}
												}
												{tag_add _s_move}
												{tag_remove _s_notmoved}
											}
											{"delay"
												{time 0.05}
											}
											{"placement"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag _s_move}
															}
														}
														{exclude
															{tag
																{tag _s_moved}
															}
														}
													}
												}
												{target_waypoint "16"}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{tag _s_move}
												}
												{tag_add _s_moved}
											}
										}
										{"default"
											{"delay"
												{time 0.01}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{amount 1
													}
													{tag _s_notmoved}
												}
												{tag_add _s_move}
												{tag_remove _s_notmoved}
											}
											{"delay"
												{time 0.05}
											}
											{"placement"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag _s_move}
															}
														}
														{exclude
															{tag
																{tag _s_moved}
															}
														}
													}
													{amount 1
													}
												}
												{target_waypoint "16"}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{tag _s_move}
												}
												{tag_add _s_moved}
											}
										}
									}
								}
								{"default"}
							}
							{"delay"
								{time 0.05}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "flag3$"}
										{op ">"}
										{value 0}
									}
									{"switch"
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag _s_notmoved}
												}
												{count
													{op ">"}
													{value 2}
												}
											}
											{"delay"
												{time 0.01}
											}
											{"entity_state"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag a1}
															}
															{tag
																{tag a2}
															}
														}
													}
												}
												{tag_add _s_move}
												{tag_remove _s_notmoved}
											}
											{"delay"
												{time 0.05}
											}
											{"placement"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag _s_move}
															}
														}
														{exclude
															{tag
																{tag _s_moved}
															}
														}
													}
												}
												{target_waypoint "17"}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{tag _s_move}
												}
												{tag_add _s_moved}
											}
										}
										{"default"
											{"delay"
												{time 0.01}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{amount 1
													}
													{tag _s_notmoved}
												}
												{tag_add _s_move}
												{tag_remove _s_notmoved}
											}
											{"delay"
												{time 0.05}
											}
											{"placement"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag _s_move}
															}
														}
														{exclude
															{tag
																{tag _s_moved}
															}
														}
													}
													{amount 1
													}
												}
												{target_waypoint "17"}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{tag _s_move}
												}
												{tag_add _s_moved}
											}
										}
									}
								}
								{"default"}
							}
							{"delay"
								{time 0.05}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "flag4$"}
										{op ">"}
										{value 0}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{amount 1
											}
											{tag _s_notmoved}
										}
										{tag_add _s_move}
										{tag_remove _s_notmoved}
									}
									{"delay"
										{time 0.05}
									}
									{"placement"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag _s_move}
													}
												}
												{exclude
													{tag
														{tag _s_moved}
													}
												}
											}
											{amount 1
											}
										}
										{target_waypoint "18"}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag _s_move}
										}
										{tag_add _s_moved}
									}
								}
								{"default"}
							}
							{"delay"
								{time 0.05}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "flag5$"}
										{op ">"}
										{value 0}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{amount 1
											}
											{tag _s_notmoved}
										}
										{tag_add _s_move}
										{tag_remove _s_notmoved}
									}
									{"delay"
										{time 0.05}
									}
									{"placement"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag _s_move}
													}
												}
												{exclude
													{tag
														{tag _s_moved}
													}
												}
											}
											{amount 1
											}
										}
										{target_waypoint "19"}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag _s_move}
										}
										{tag_add _s_moved}
									}
								}
								{"default"}
							}
						}
						{"default"
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "flag1$"}
										{op ">"}
										{value 0}
									}
									{"entity_state"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag b1}
													}
													{tag
														{tag b2}
													}
												}
											}
										}
										{tag_add _s_move}
										{tag_remove _s_notmoved}
									}
									{"delay"
										{time 0.05}
									}
									{"placement"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag _s_move}
													}
												}
												{exclude
													{tag
														{tag _s_moved}
													}
												}
											}
										}
										{target_waypoint "20"}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag _s_move}
										}
										{tag_add _s_moved}
									}
								}
								{"default"}
							}
							{"delay"
								{time 0.05}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "flag2$"}
										{op ">"}
										{value 0}
									}
									{"switch"
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag _s_notmoved}
												}
												{count
													{op ">"}
													{value 2}
												}
											}
											{"delay"
												{time 0.01}
											}
											{"entity_state"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag b1}
															}
															{tag
																{tag b2}
															}
														}
													}
												}
												{tag_add _s_move}
												{tag_remove _s_notmoved}
											}
											{"delay"
												{time 0.05}
											}
											{"placement"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag _s_move}
															}
														}
														{exclude
															{tag
																{tag _s_moved}
															}
														}
													}
												}
												{target_waypoint "21"}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{tag _s_move}
												}
												{tag_add _s_moved}
											}
										}
										{"default"
											{"delay"
												{time 0.01}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{amount 1
													}
													{tag _s_notmoved}
												}
												{tag_add _s_move}
												{tag_remove _s_notmoved}
											}
											{"delay"
												{time 0.05}
											}
											{"placement"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag _s_move}
															}
														}
														{exclude
															{tag
																{tag _s_moved}
															}
														}
													}
													{amount 1
													}
												}
												{target_waypoint "21"}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{tag _s_move}
												}
												{tag_add _s_moved}
											}
										}
									}
								}
								{"default"}
							}
							{"delay"
								{time 0.05}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "flag3$"}
										{op ">"}
										{value 0}
									}
									{"switch"
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag _s_notmoved}
												}
												{count
													{op ">"}
													{value 2}
												}
											}
											{"delay"
												{time 0.01}
											}
											{"entity_state"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag b1}
															}
															{tag
																{tag b2}
															}
														}
													}
												}
												{tag_add _s_move}
												{tag_remove _s_notmoved}
											}
											{"delay"
												{time 0.05}
											}
											{"placement"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag _s_move}
															}
														}
														{exclude
															{tag
																{tag _s_moved}
															}
														}
													}
												}
												{target_waypoint "22"}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{tag _s_move}
												}
												{tag_add _s_moved}
											}
										}
										{"default"
											{"delay"
												{time 0.01}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{amount 1
													}
													{tag _s_notmoved}
												}
												{tag_add _s_move}
												{tag_remove _s_notmoved}
											}
											{"delay"
												{time 0.05}
											}
											{"placement"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{select
															{tag
																{tag _s_move}
															}
														}
														{exclude
															{tag
																{tag _s_moved}
															}
														}
													}
													{amount 1
													}
												}
												{target_waypoint "22"}
											}
											{"entity_state"
												{selector
													{ignore_captured_by_user 0}
													{tag _s_move}
												}
												{tag_add _s_moved}
											}
										}
									}
								}
								{"default"}
							}
							{"delay"
								{time 0.05}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "flag4$"}
										{op ">"}
										{value 0}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{amount 1
											}
											{tag _s_notmoved}
										}
										{tag_add _s_move}
										{tag_remove _s_notmoved}
									}
									{"delay"
										{time 0.05}
									}
									{"placement"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag _s_move}
													}
												}
												{exclude
													{tag
														{tag _s_moved}
													}
												}
											}
											{amount 1
											}
										}
										{target_waypoint "23"}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag _s_move}
										}
										{tag_add _s_moved}
									}
								}
								{"default"}
							}
							{"delay"
								{time 0.05}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "flag5$"}
										{op ">"}
										{value 0}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{amount 1
											}
											{tag _s_notmoved}
										}
										{tag_add _s_move}
										{tag_remove _s_notmoved}
									}
									{"delay"
										{time 0.05}
									}
									{"placement"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag
														{tag _s_move}
													}
												}
												{exclude
													{tag
														{tag _s_moved}
													}
												}
											}
											{amount 1
											}
										}
										{target_waypoint "24"}
									}
									{"entity_state"
										{selector
											{ignore_captured_by_user 0}
											{tag _s_move}
										}
										{tag_add _s_moved}
									}
								}
								{"default"}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"call"
						{function "debug_garrison"}
					}
				}
			}
			{"dcg2/botdefend/default_spawns"
				{condition
					{terms
						{"1.cmp_i"
							{var "garrison_end$"}
							{op "=="}
							{value 1}
						}
						{"2.event"
							{id "dcg2/attack_bot_spawning"}
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
								{var "bots_spawnside$"}
								{op "=="}
								{value 1}
							}
							{"placement"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag a1}
											}
										}
										{include
											{tag
												{tag spawn_a}
											}
										}
									}
								}
								{target
									{ignore_captured_by_user 0}
									{tag _default_a1}
								}
							}
							{"placement"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag a2}
											}
										}
										{include
											{tag
												{tag spawn_a}
											}
										}
									}
								}
								{target
									{ignore_captured_by_user 0}
									{tag _default_a2}
								}
							}
							{"placement"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag a3}
											}
										}
										{include
											{tag
												{tag spawn_a}
											}
										}
									}
								}
								{target
									{ignore_captured_by_user 0}
									{tag _default_a3}
								}
							}
							{"placement"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag a4}
											}
										}
										{include
											{tag
												{tag spawn_a}
											}
										}
									}
								}
								{target
									{ignore_captured_by_user 0}
									{tag _default_a4}
								}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"placement"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag b1}
											}
										}
										{include
											{tag
												{tag spawn_b}
											}
										}
									}
								}
								{target
									{ignore_captured_by_user 0}
									{tag _default_b1}
								}
							}
							{"placement"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag b2}
											}
										}
										{include
											{tag
												{tag spawn_b}
											}
										}
									}
								}
								{target
									{ignore_captured_by_user 0}
									{tag _default_b2}
								}
							}
							{"placement"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag b3}
											}
										}
										{include
											{tag
												{tag spawn_b}
											}
										}
									}
								}
								{target
									{ignore_captured_by_user 0}
									{tag _default_b3}
								}
							}
							{"placement"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag b4}
											}
										}
										{include
											{tag
												{tag spawn_b}
											}
										}
									}
								}
								{target
									{ignore_captured_by_user 0}
									{tag _default_b4}
								}
							}
						}
					}
					{"delay"
						{time 60}
					}
					{"switch"
						{"case"
							{condition
								{type trigger}
								{name "dcg2/botdefend/garrison_ready"}
							}
						}
						{"default"
							{"trigger"
								{name "dcg2/botdefend/garrison_ready"}
								{on}
							}
							{"objective_progress"
								{set 0}
								{add 0}
								{title "mission/multi/dcg2_garrison_failsafe"}
							}
							{"con"
								{text "(Warning) - dcg garrison error: Waiting too long... Forcing Garrison Ready!"}
							}
							{"delay"
								{time 8}
							}
							{"objective_progress"
								{hide}
								{set 0}
								{add 0}
								{title "mission/multi/dcg2_garrison_failsafe"}
							}
						}
					}
				}
			}
			{"dcg2/userdefend/prep_end"
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
						{time 0.1}
					}
					{"event"
						{event "dcg2/defense_prep_end"}
						{mode set}
						{delay 0}
					}
					{"delete"
						{selector
							{ignore_captured_by_user 0}
							{tag conquest_spawn_indicator}
						}
					}
					{"set_i"
						{var "display$"}
						{op "="}
						{value 0}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "player_spawn_name$"}
								{op "=="}
								{value 1}
							}
							{"placement"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag a1}
											}
										}
										{include
											{tag
												{tag spawn_a}
											}
										}
									}
								}
								{target
									{ignore_captured_by_user 0}
									{tag _default_a1}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "player_spawn_name$"}
								{op "=="}
								{value 2}
							}
							{"placement"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag a2}
											}
										}
										{include
											{tag
												{tag spawn_a}
											}
										}
									}
								}
								{target
									{ignore_captured_by_user 0}
									{tag _default_a2}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "player_spawn_name$"}
								{op "=="}
								{value 3}
							}
							{"placement"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag a3}
											}
										}
										{include
											{tag
												{tag spawn_a}
											}
										}
									}
								}
								{target
									{ignore_captured_by_user 0}
									{tag _default_a3}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "player_spawn_name$"}
								{op "=="}
								{value 4}
							}
							{"placement"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag a4}
											}
										}
										{include
											{tag
												{tag spawn_a}
											}
										}
									}
								}
								{target
									{ignore_captured_by_user 0}
									{tag _default_a4}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "player_spawn_name$"}
								{op "=="}
								{value 5}
							}
							{"placement"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag b1}
											}
										}
										{include
											{tag
												{tag spawn_b}
											}
										}
									}
								}
								{target
									{ignore_captured_by_user 0}
									{tag _default_b1}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "player_spawn_name$"}
								{op "=="}
								{value 6}
							}
							{"placement"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag b2}
											}
										}
										{include
											{tag
												{tag spawn_b}
											}
										}
									}
								}
								{target
									{ignore_captured_by_user 0}
									{tag _default_b2}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "player_spawn_name$"}
								{op "=="}
								{value 7}
							}
							{"placement"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag b3}
											}
										}
										{include
											{tag
												{tag spawn_b}
											}
										}
									}
								}
								{target
									{ignore_captured_by_user 0}
									{tag _default_b3}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "player_spawn_name$"}
								{op "=="}
								{value 8}
							}
							{"placement"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag b4}
											}
										}
										{include
											{tag
												{tag spawn_b}
											}
										}
									}
								}
								{target
									{ignore_captured_by_user 0}
									{tag _default_b4}
								}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
						}
					}
				}
			}
			{"dcg2/botdefend/cartank_to_set"
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
								{ignore_captured_by_user 0}
								{group
									{select
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
										{state
											{state inactive}
										}
									}
								}
							}
						}
						{"3.cmp_i"
							{var "garrison_ready$"}
							{op "=="}
							{value 0}
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
										{tag "+bots_ct"}
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
										{state user_control}
									}
								}
							}
							{amount 1
							}
						}
						{tag_add "-bots_ct"}
						{tag_remove "+bots_ct"}
					}
					{"delay"
						{time 0.1}
					}
					{"call"
						{function "bot_mobiles_stop"}
						{context
							{specified}
							{selector
								{ignore_captured_by_user 0}
								{tag "-bots_ct"}
							}
						}
					}
					{"delay"
						{time 0.3}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag "-bots_ct"}
						}
						{tag_add bots_ct}
						{tag_remove "-bots_ct"}
					}
					{"delay"
						{time 0.1}
					}
					{"trigger"
						{name "dcg2/botdefend/cartank_to_set"}
					}
				}
			}
			{"dcg2/botdefend/garrison_tagging"
				{condition
					{terms
						{"1.event"
							{id "dcg2/attack_bot_spawning"}
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
											{tag "+garrisoned"}
										}
										{tag
											{tag cmp_def}
										}
										{tag
											{tag _animal}
										}
										{tag
											{tag no_scavenge}
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
						{"3.event"
							{id "dcg2/flags_set"}
						}
						{"4.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 0}
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
										{tag "+garrisoned"}
									}
									{tag
										{tag _animal}
									}
									{tag
										{tag cmp_def}
									}
									{tag
										{tag no_scavenge}
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
						{tag_add "_garrison_todo+"}
					}
					{"delay"
						{time 1.4}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag "_garrison_todo+"}
									}
								}
								{include
									{prop
										{prop human}
									}
									{state
										{state "operatable inactive"}
									}
								}
							}
							{group
								{select
									{tag
										{tag "_garrison_todo+"}
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
							}
						}
						{tag_add "+garrisoned"}
						{tag_remove "_garrison_todo+"}
					}
					{"trigger"
						{name "dcg2/botdefend/garrison_tagging"}
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
			{"dcg2/botdefend/garrison_to_cover"
				{condition
					{terms
						{"1.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 0}
						}
						{"2.entities"
							{selector
								{ignore_captured_by_user 0}
								{tag "+need_cover"}
								{zone "gamezone"}
								{type human}
								{state operatable}
							}
						}
						{"3.cmp_i"
							{var "garrison_ready$"}
							{op ">"}
							{value 0}
						}
					}
				}
				{actions
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{amount 3
							}
							{tag "+need_cover"}
							{zone "gamezone"}
							{type human}
							{state operatable}
						}
						{tag_add _cover}
						{tag_remove "+need_cover"}
					}
					{"delay"
						{time 0.1}
					}
					{"actor_to_cover"
						{selector
							{ignore_captured_by_user 0}
							{tag _cover}
							{type human}
							{state operatable}
						}
					}
					{"delay"
						{time 0.25}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _cover}
						}
						{tag_add "+covered"}
						{tag_remove _cover}
					}
					{"trigger"
						{name "dcg2/botdefend/garrison_to_cover"}
					}
				}
			}
			{"dcg2/victory/bots_retreat"
				{condition
					{terms
						{"1.event"
							{id "dcg"}
						}
						{"2.cmp_i"
							{var "bot_retreat_active$"}
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
											{tag x_bot}
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
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag x_bot}
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
										{state inhabited}
									}
								}
								{exclude
									{tag
										{tag _bot_veh}
									}
									{state
										{state chassis_work}
									}
									{state
										{state user_control}
									}
								}
							}
							{amount 1
							}
						}
						{tag_add _s_destruct}
						{tag_remove x_bot}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag x_bot}
									}
								}
								{include
									{tag
										{tag bot_veh}
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
								}
							}
							{amount 1
							}
						}
						{tag_add _s_cannon_bail}
						{tag_remove x_bot}
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
												{tag _s_cannon_bail}
											}
										}
										{include
											{broken_components
												{masks
													"*"
												}
											}
										}
									}
								}
							}
							{"switch"
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
									{"emit"
										{selector
											{tag _s_cannon_bail}
											{zone "gamezone"}
											{type vehicle}
											{state inhabited}
										}
										{waypoint "6"}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"emit"
										{selector
											{tag _s_cannon_bail}
											{zone "gamezone"}
											{type vehicle}
											{state inhabited}
										}
										{waypoint "0"}
									}
								}
							}
						}
						{"default"
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag _s_cannon_bail}
								}
								{tag_add _s_destruct}
								{tag_remove _s_cannon_bail}
							}
						}
					}
					{"delay"
						{time 0.2}
					}
					{"effect"
						{selector
							{tag _s_destruct}
							{type vehicle}
							{state inhabited}
						}
						{effect leave_unit}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _s_destruct}
						}
						{tag_add _s_emits}
						{tag_remove _s_destruct}
					}
					{"delay"
						{time 0.1}
					}
					{"call"
						{function "retreat_bail_bots"}
					}
					{"delay"
						{time 0.8}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag x_bot}
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
										{state "operatable chassis_work"}
									}
								}
								{exclude
									{tag
										{tag _bot_veh}
									}
									{tag
										{tag _escape}
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
									{tag flag}
								}
							}
							{amount 1
							}
						}
						{tag_add _d_escape}
					}
					{"delay"
						{time 0.1}
					}
					{"actor_state"
						{selector
							{tag _d_escape}
							{type vehicle}
							{state operatable}
						}
						{drop orders}
						{fire_mode hold}
						{move_mode hold}
						{ai_move
							{mode disable}
						}
						{movement
							{speed fast}
							{type normal}
							{forward on}
						}
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
									{tag _d_escape}
									{type vehicle}
									{state operatable}
								}
								{action move}
								{target
									{ignore_captured_by_user 0}
									{amount 1
									}
									{tag spawn_a}
								}
							}
						}
						{"default"
							{"action"
								{selector
									{tag _d_escape}
									{type vehicle}
									{state operatable}
								}
								{action move}
								{target
									{ignore_captured_by_user 0}
									{amount 1
									}
									{tag spawn_b}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _d_escape}
						}
						{tag_add _escape}
					}
					{"delay"
						{time 2.8}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _d_escape}
						}
						{tag_add _escape}
						{tag_remove _d_escape}
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
									{group
										{select
											{tag
												{tag _d_escape}
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
							{"entity_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag _d_escape}
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
								{tag_add x_bot}
							}
						}
						{"default"
							{"entity_state"
								{selector
									{ignore_captured_by_user 0}
									{tag _d_escape}
								}
								{tag_remove _d_escape}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"trigger"
						{name "dcg2/victory/bots_retreat"}
					}
				}
			}
			{"dcg2/victory/request_win"
				{condition
					{terms
						{"1.event"
							{id "dcg"}
						}
						{"2.cmp_i"
							{var "attacker_retreat_requested$"}
							{op ">"}
							{value 0}
						}
						{"3.cmp_i"
							{var "dcg_on$"}
							{op "=="}
							{value 10}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"set_i"
						{var "gameover_request_player_win$"}
						{op "="}
						{value 1}
					}
					{"sound"
						{name "mission/task_fulfilled"}
					}
				}
			}
			{"dcg2/victory/bots_delete"
				{condition
					{terms
						{"1.cmp_i"
							{var "bot_retreat_active$"}
							{op ">"}
							{value 0}
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
											{tag _escape}
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
					{"entity_state"
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
										{tag _escape}
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
								}
							}
						}
						{tag_add del_escape}
						{tag_remove _escape}
					}
					{"delay"
						{time 0.2}
					}
					{"delete"
						{selector
							{ignore_captured_by_user 0}
							{tag del_escape}
						}
					}
					{"delay"
						{time 0.3}
					}
					{"trigger"
						{name "dcg2/victory/bots_delete"}
					}
				}
			}
			{"dcg2/victory/retreat_init"
				{condition
					{expression "(1 & !3) | (2 & !3)"}
					{terms
						{"1.cmp_i"
							{var "attacker_retreat_requested$"}
							{op ">"}
							{value 0}
						}
						{"2.cmp_i"
							{var "defender_retreat_requested$"}
							{op ">"}
							{value 0}
						}
						{"3.trigger"
							{name "lua/bot_tags"}
						}
					}
				}
				{actions
					{"set_i"
						{var "bot_retreat_active$"}
						{op "="}
						{value 1}
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
									{zone
										{zone "gamezone"}
									}
								}
								{exclude
									{tag
										{tag pilot}
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
						{tag_add x_bot}
						{tag_remove _bot}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag bot}
						}
						{tag_remove bot}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag _ai}
						}
						{tag_remove _ai}
					}
					{"delay"
						{time 0.1}
					}
					{"event"
						{event "talk_on"}
						{mode set}
						{delay 0}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag bot_tank}
						}
						{tag_remove bot_tank}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag bot_car}
						}
						{tag_remove bot_car}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag x_bot}
						}
						{tag_add _lua_mi}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag unhold_iq}
						}
						{tag_remove unhold_iq}
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
							{tag _act}
						}
						{tag_remove _act}
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
										{tag arrow_enemy_a}
									}
									{tag
										{tag arrow_enemy_b}
									}
								}
							}
						}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "attacker_retreat_requested$"}
								{op ">"}
								{value 0}
							}
							{"delay"
								{time 12}
							}
							{"sound"
								{name "gui/multi/chat"}
							}
							{"talk"
								{selector
									{ignore_captured_by_user 0}
									{amount 1
									}
									{tag player}
									{zone "gamezone"}
									{type human}
									{state operatable}
								}
								{text "mission/multi/enemy_retreat"}
							}
							{"delay"
								{time 6}
							}
							{"event"
								{event "talk_on"}
								{mode reset}
								{delay 0}
							}
							{"set_i"
								{var "dcg_on$"}
								{op "="}
								{value 10}
							}
						}
						{"default"
							{"delay"
								{time 10}
							}
							{"sound"
								{name "gui/multi/chat"}
							}
							{"talk"
								{selector
									{ignore_captured_by_user 0}
									{amount 1
									}
									{tag player}
									{zone "gamezone"}
									{type human}
									{state operatable}
								}
								{text "mission/multi/enemy_retreat2"}
							}
							{"delay"
								{time 6}
							}
							{"event"
								{event "talk_on"}
								{mode reset}
								{delay 0}
							}
						}
					}
				}
			}