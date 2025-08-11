			{## "debug/vars"
				{condition
					{terms
						{"1.cmp_i"
							{var "user_team$"}
							{op ">"}
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
								{var "enemyid$"}
								{op "=="}
								{value 1}
							}
							{"timer"
								{time 8}
								{title "enemid is 1"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "enemyid$"}
								{op "=="}
								{value 2}
							}
							{"timer"
								{time 8}
								{title "enemid is 2"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "enemyid$"}
								{op "=="}
								{value 3}
							}
							{"timer"
								{time 8}
								{title "enemid is 3"}
							}
						}
						{"default"
							{"timer"
								{time 8}
								{title "enemyid is above 3"}
							}
						}
					}
					{"delay"
						{time 7}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "user_is_defender$"}
								{op "=="}
								{value 0}
							}
							{"timer"
								{time 8}
								{title "user is defender == 0"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "user_is_defender$"}
								{op "=="}
								{value 1}
							}
							{"timer"
								{time 8}
								{title "user is defender == 1"}
							}
						}
						{"default"
							{"timer"
								{time 8}
								{title "user is defender not 0 or 1!"}
							}
						}
					}
					{"delay"
						{time 7}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "def_team$"}
								{op "=="}
								{value 1}
							}
							{"timer"
								{time 8}
								{title "def_team == 1 (a)"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "def_team$"}
								{op "=="}
								{value 2}
							}
							{"timer"
								{time 8}
								{title "def_team == 2(b)"}
							}
						}
						{"default"
							{"timer"
								{time 8}
								{title "DEF TEAM UNKNOWN"}
							}
						}
					}
					{"delay"
						{time 7}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "arrows$"}
								{op "=="}
								{value 1}
							}
							{"timer"
								{time 8}
								{title "arrows == 1(a)"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "arrows$"}
								{op "=="}
								{value 2}
							}
							{"timer"
								{time 8}
								{title "arrows == 2(b)"}
							}
						}
						{"default"
							{"timer"
								{time 8}
								{title "arrows invalid!"}
							}
						}
					}
					{"delay"
						{time 7}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "bot_army$"}
								{op "=="}
								{value 1}
							}
							{"timer"
								{time 8}
								{title "bot army==1 RUS"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "bot_army$"}
								{op "=="}
								{value 2}
							}
							{"timer"
								{time 8}
								{title "bot army==2 GER"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "bot_army$"}
								{op "=="}
								{value 3}
							}
							{"timer"
								{time 8}
								{title "bot army==3 FIN"}
							}
						}
						{"default"
							{"timer"
								{time 8}
								{title "bot army ABOVE 3!!!!"}
							}
						}
					}
					{"delay"
						{time 5}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "bot_mp_team$"}
								{op "=="}
								{value 1}
							}
							{"timer"
								{time 8}
								{title "bot_mp_team 1"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "bot_mp_team$"}
								{op "=="}
								{value 2}
							}
							{"timer"
								{time 8}
								{title "bot_mp_team 2"}
							}
						}
						{"default"
							{"timer"
								{time 8}
								{title "bot_mp_team INVALID"}
							}
						}
					}
					{"event"
						{event "ai_air_possible"}
						{mode set}
						{delay 0}
					}
					{"delay"
						{time 5}
					}
					{"set_i"
						{var "ai_air_on$"}
						{op "="}
						{value 1}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "ai_sabotage$"}
								{op "=="}
								{value 1}
							}
							{## "timer"
								{time 8}
								{title "ai_sabotage == true"}
							}
						}
						{"default"
							{## "timer"
								{time 8}
								{title "ai_sabotage not set in bot file"}
							}
						}
					}
				}
			}
			{## "debug/test_script"
				{condition
					{terms
						{"1.entities"
							{selector
								{ignore_captured_by_user 0}
								{tag _bot}
								{zone "gamezone"}
								{state operatable}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 15}
					}
					{"timer"
						{time 5}
						{title "creating new squad"}
					}
					{"squad_create"
						{selector
							{ignore_captured_by_user 0}
							{tag _bot}
							{zone "gamezone"}
							{state operatable}
						}
						{name test_squad}
					}
					{"delay"
						{time 5}
					}
					{"squad_dismiss"
						{squad test_squad}
					}
				}
			}


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
							{distance 25}
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
										{var "user_team$"}
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
												{value 0.35}
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
												{value 0.35}
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
												{value 0.35}
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
												{value 0.35}
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
												{value 0.35}
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
										{value 0.35}
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
										{value 0.35}
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
										{value 0.35}
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
										{value 0.35}
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
										{value 0.35}
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
										{value 0.35}
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
						{## "case"
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
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 135}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"music"
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 90}
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
						{## "case"
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
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 135}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"music"
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 90}
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
						{## "case"
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
										{stop_all}
										{volume game}
										{fade 5}
										{loop}
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
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 85}
									}
									{"music"
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 35}
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
						{## "case"
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
										{stop_all}
										{volume game}
										{fade 5}
										{loop}
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
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 85}
									}
									{"music"
										{stop_all}
										{volume game}
										{fade 5}
									}
									{"delay"
										{time 35}
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
						{## "case"
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
										{stop_all}
										{volume game}
										{fade 3}
									}
									{"delay"
										{time 55}
									}
									{"music"
										{volume game}
										{fade 5}
									}
								}
								{"default"
									{"delay"
										{time 0.1}
									}
									{"music"
										{stop_all}
										{volume game}
										{fade 3}
									}
									{"delay"
										{time 60}
									}
									{"music"
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
										{tag
											{tag air_vehicle}
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
								{## "case"
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
									{tag
										{tag cmp_def}
									}
								}
								{include
									{prop
										{prop human}
									}
									{state
										{state inactive}
									}
								}
								{exclude
									{tag
										{tag not_delete}
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
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "user_is_defender$"}
								{op ">"}
								{value 0}
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
								{tag_add player_defending}
							}
						}
						{"default"
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
								{tag_add player_attacking}
							}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"event"
						{event "attack_or_defend_mission_set"}
						{mode set}
						{delay 0}
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
									{amount 12
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
									{amount 8
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
									{amount 12
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
									{amount 8
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
									{amount 12
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
									{amount 8
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
									{amount 12
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
									{amount 8
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
									{amount 12
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
									{amount 8
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
			{## "balance_cmp_def"
				{condition
					{terms
						{"1.cmp_i"
							{var "balance$"}
							{op "=="}
							{value 1}
						}
						{"3.entities"
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
					}
				}
				{actions
					{"delay"
						{time 0.5}
					}				
					{## "if"
						{condition
							{type cmp_i}
							{var "user_is_defender$"}
							{op "=="}
							{value 1}
						}
						{"while"
							{condition
								{type entities}
								{selector
									{source advanced}
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
											{state
												{state linked}
											}
											{state
												{state user_control}
											}
										}
									}
								}
								{count
									{op ">"}
									{value 20}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"delete"
								{selector
									{source advanced}
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
								}
							}
							{"delay"
								{time 0.5}
							}
						}
					}
					{## "delay"
						{time 10}
					}
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
												{tag "1_a_1-3"}
											}
											{tag
												{tag "1_b_1-3"}
											}
											{tag
												{tag "1_a_2-3"}
											}
											{tag
												{tag "1_b_2-3"}
											}
											{tag
												{tag "1_a_3"}
											}
											{tag
												{tag "1_b_3"}
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
												{tag "1_a_1-3"}
											}
											{tag
												{tag "1_b_1-3"}
											}
											{tag
												{tag "1_a_2-3"}
											}
											{tag
												{tag "1_b_2-3"}
											}
											{tag
												{tag "1_a_3"}
											}
											{tag
												{tag "1_b_3"}
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
												{tag "1_a_1-3"}
											}
											{tag
												{tag "1_b_1-3"}
											}
											{tag
												{tag "1_a_2-3"}
											}
											{tag
												{tag "1_b_2-3"}
											}
											{tag
												{tag "1_a_3"}
											}
											{tag
												{tag "1_b_3"}
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
												{tag "1_a_1-3"}
											}
											{tag
												{tag "1_b_1-3"}
											}
											{tag
												{tag "1_a_2-3"}
											}
											{tag
												{tag "1_b_2-3"}
											}
											{tag
												{tag "1_a_3"}
											}
											{tag
												{tag "1_b_3"}
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
												{tag "2_a_1-3"}
											}
											{tag
												{tag "2_b_1-3"}
											}
											{tag
												{tag "2_a_2-3"}
											}
											{tag
												{tag "2_b_2-3"}
											}
											{tag
												{tag "2_a_3"}
											}
											{tag
												{tag "2_b_3"}
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
												{tag "2_a_1-3"}
											}
											{tag
												{tag "2_b_1-3"}
											}
											{tag
												{tag "2_a_2-3"}
											}
											{tag
												{tag "2_b_2-3"}
											}
											{tag
												{tag "2_a_3"}
											}
											{tag
												{tag "2_b_3"}
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
												{tag "2_a_1-3"}
											}
											{tag
												{tag "2_b_1-3"}
											}
											{tag
												{tag "2_a_2-3"}
											}
											{tag
												{tag "2_b_2-3"}
											}
											{tag
												{tag "2_a_3"}
											}
											{tag
												{tag "2_b_3"}
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
												{tag "2_a_1-3"}
											}
											{tag
												{tag "2_b_1-3"}
											}
											{tag
												{tag "2_a_2-3"}
											}
											{tag
												{tag "2_b_2-3"}
											}
											{tag
												{tag "2_a_3"}
											}
											{tag
												{tag "2_b_3"}
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
												{tag "3_a_1-3"}
											}
											{tag
												{tag "3_b_1-3"}
											}
											{tag
												{tag "3_a_2-3"}
											}
											{tag
												{tag "3_b_2-3"}
											}
											{tag
												{tag "3_a_3"}
											}
											{tag
												{tag "3_b_3"}
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
												{tag "3_a_1-3"}
											}
											{tag
												{tag "3_b_1-3"}
											}
											{tag
												{tag "3_a_2-3"}
											}
											{tag
												{tag "3_b_2-3"}
											}
											{tag
												{tag "3_a_3"}
											}
											{tag
												{tag "3_b_3"}
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
												{tag "3_a_1-3"}
											}
											{tag
												{tag "3_b_1-3"}
											}
											{tag
												{tag "3_a_2-3"}
											}
											{tag
												{tag "3_b_2-3"}
											}
											{tag
												{tag "3_a_3"}
											}
											{tag
												{tag "3_b_3"}
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
												{tag "3_a_1-3"}
											}
											{tag
												{tag "3_b_1-3"}
											}
											{tag
												{tag "3_a_2-3"}
											}
											{tag
												{tag "3_b_2-3"}
											}
											{tag
												{tag "3_a_3"}
											}
											{tag
												{tag "3_b_3"}
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
									{amount 3
									}
								}
							}
							{"delay"
								{time 0.5}
							}
						}
					}
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
												{tag "4_a_1-3"}
											}
											{tag
												{tag "4_b_1-3"}
											}
											{tag
												{tag "4_a_2-3"}
											}
											{tag
												{tag "4_b_2-3"}
											}
											{tag
												{tag "4_a_3"}
											}
											{tag
												{tag "4_b_3"}
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
												{tag "4_a_1-3"}
											}
											{tag
												{tag "4_b_1-3"}
											}
											{tag
												{tag "4_a_2-3"}
											}
											{tag
												{tag "4_b_2-3"}
											}
											{tag
												{tag "4_a_3"}
											}
											{tag
												{tag "4_b_3"}
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
												{tag "4_a_1-3"}
											}
											{tag
												{tag "4_b_1-3"}
											}
											{tag
												{tag "4_a_2-3"}
											}
											{tag
												{tag "4_b_2-3"}
											}
											{tag
												{tag "4_a_3"}
											}
											{tag
												{tag "4_b_3"}
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
												{tag "4_a_1-3"}
											}
											{tag
												{tag "4_b_1-3"}
											}
											{tag
												{tag "4_a_2-3"}
											}
											{tag
												{tag "4_b_2-3"}
											}
											{tag
												{tag "4_a_3"}
											}
											{tag
												{tag "4_b_3"}
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
									{amount 3
									}
								}
							}
							{"delay"
								{time 0.5}
							}
						}
					}
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
												{tag "5_a_1-3"}
											}
											{tag
												{tag "5_b_1-3"}
											}
											{tag
												{tag "5_a_2-3"}
											}
											{tag
												{tag "5_b_2-3"}
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
												{tag "5_a_1-3"}
											}
											{tag
												{tag "5_b_1-3"}
											}
											{tag
												{tag "5_a_2-3"}
											}
											{tag
												{tag "5_b_2-3"}
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
												{tag "5_a_1-3"}
											}
											{tag
												{tag "5_b_1-3"}
											}
											{tag
												{tag "5_a_2-3"}
											}
											{tag
												{tag "5_b_2-3"}
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
												{tag "5_a_1-3"}
											}
											{tag
												{tag "5_b_1-3"}
											}
											{tag
												{tag "5_a_2-3"}
											}
											{tag
												{tag "5_b_2-3"}
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
						{"2.event"
							{id "ai_defender_vehicles_tagged"}
						}
					}
				}
				{actions
					{"delay"
						{time 3.9}
					}
					{"delay"
						{time 0.1}
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
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_defender}
									}
								}
								{include
									{state
										{state inhabited}
									}
									{prop
										{prop vehicle}
									}
								}
								{exclude
									{tag
										{tag player_veh}
									}
									{state
										{state inactive}
									}
									{state
										{state user_control}
									}
									{tag
										{tag player}
									}
									{prop
										{prop no_sandbags}
									}
								}
							}
							{group
								{select
									{tag
										{tag _ai_defender}
									}
								}
								{include
									{state
										{state inhabited}
									}
									{prop
										{prop vehicle}
									}
									{prop
										{prop panzer1f}
									}
								}
								{exclude
									{tag
										{tag player_veh}
									}
									{state
										{state inactive}
									}
									{state
										{state user_control}
									}
									{tag
										{tag player}
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
							{group
								{select
									{tag
										{tag _ai_defender}
									}
								}
								{include
									{state
										{state inhabited}
									}
									{prop
										{prop vehicle}
									}
								}
								{exclude
									{tag
										{tag player_veh}
									}
									{state
										{state inactive}
									}
									{state
										{state user_control}
									}
									{tag
										{tag player}
									}
									{prop
										{prop no_sandbags}
									}
								}
							}
							{group
								{select
									{tag
										{tag _ai_defender}
									}
								}
								{include
									{state
										{state inhabited}
									}
									{prop
										{prop vehicle}
									}
									{prop
										{prop panzer1f}
									}
								}
								{exclude
									{tag
										{tag player_veh}
									}
									{state
										{state inactive}
									}
									{state
										{state user_control}
									}
									{tag
										{tag player}
									}
								}
							}
						}
						{tag_add no_scavenge}
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
												{zone "gamezone"}
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
														}
														{exclude
															{state
																{state user_control}
															}
															{tag
																{tag air_vehicle}
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
														}
														{exclude
															{state
																{state user_control}
															}
															{tag
																{tag air_vehicle}
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
														}
														{exclude
															{tag
																{tag cmp_mg}
															}
															{state
																{state user_control}
															}
															{tag
																{tag air_vehicle}
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
														}
														{exclude
															{tag
																{tag cmp_mg}
															}
															{state
																{state user_control}
															}
															{tag
																{tag air_vehicle}
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
														}
														{exclude
															{tag
																{tag cmp_mg}
															}
															{state
																{state user_control}
															}
															{tag
																{tag air_vehicle}
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
														}
														{exclude
															{tag
																{tag cmp_mg}
															}
															{state
																{state user_control}
															}
															{tag
																{tag air_vehicle}
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
														}
														{exclude
															{tag
																{tag cmp_mg}
															}
															{state
																{state user_control}
															}
															{tag
																{tag air_vehicle}
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
														}
														{exclude
															{tag
																{tag cmp_mg}
															}
															{state
																{state user_control}
															}
															{tag
																{tag air_vehicle}
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
														}
														{exclude
															{tag
																{tag cmp_mg}
															}
															{state
																{state user_control}
															}
															{tag
																{tag air_vehicle}
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
														}
														{exclude
															{tag
																{tag cmp_mg}
															}
															{state
																{state user_control}
															}
															{tag
																{tag air_vehicle}
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
												{zone "gamezone"}
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
														}
														{exclude
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
														}
														{exclude
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
														}
														{exclude
															{tag
																{tag cmp_mg}
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
														}
														{exclude
															{tag
																{tag cmp_mg}
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
														}
														{exclude
															{tag
																{tag cmp_mg}
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
														}
														{exclude
															{tag
																{tag cmp_mg}
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
														}
														{exclude
															{tag
																{tag cmp_mg}
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
														}
														{exclude
															{tag
																{tag cmp_mg}
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
														}
														{exclude
															{tag
																{tag cmp_mg}
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
														}
														{exclude
															{tag
																{tag cmp_mg}
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
						{time 0.4}
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
								{time 1}
							}
							{"effect"
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
											{prop
												{prop cannon_sandbag_small}
											}
											{prop
												{prop mg_stan}
											}
											{prop
												{prop tank}
											}
										}
									}
								}
								{effect construction_sandbag_cannon_standard}
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
												{tag cmp_mg}
											}
										}
										{include
											{prop
												{prop cannon_sandbag_small}
											}
											{prop
												{prop vehicle}
											}
										}
										{exclude
											{prop
												{prop mg_stan}
											}
											{prop
												{prop tank}
											}
										}
									}
								}
								{effect construction_sandbag_cannon_shallow}
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
												{tag cmp_mg}
											}
										}
										{include
											{prop
												{prop vehicle}
											}
											{prop
												{prop mg_stan}
											}
											{prop
												{prop cannon_sandbag_standard}
											}
										}
										{exclude
											{prop
												{prop cannon_sandbag_small}
											}
											{prop
												{prop tank}
											}
										}
									}
								}
								{effect construction_sandbag_cannon_standard}
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
												{tag cmp_mg}
											}
										}
										{include
											{prop
												{prop cannon_sandbag_small}
											}
											{prop
												{prop vehicle}
											}
											{prop
												{prop mg_stan}
											}
										}
										{exclude
											{prop
												{prop cannon_sandbag_standard}
											}
											{prop
												{prop tank}
											}
										}
									}
								}
								{effect construction_sandbag_cannon_shallow}
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
												{tag cmp_mg}
											}
										}
										{include
											{prop
												{prop fixed}
											}
											{prop
												{prop vehicle}
											}
											{prop
												{prop mg_stan}
											}
										}
										{exclude
											{prop
												{prop tank}
											}
										}
									}
								}
								{effect construction_sandbag_cannon_shallow}
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
									{"effect"
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
														{prop tank}
													}
													{prop
														{prop vehicle}
													}
												}
												{exclude
													{prop
														{prop cannon}
													}
												}
											}
										}
										{effect hull_down}
									}
								}
								{"default"
									{"effect"
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
														{prop tank}
													}
													{prop
														{prop vehicle}
													}
												}
												{exclude
													{prop
														{prop cannon}
													}
												}
											}
										}
										{effect tank_cover_hull_down}
									}
								}
							}
							{"delay"
								{time 1}
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
													{state
														{state user_control}
													}
													{state
														{state inactive}
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
								{## "default"
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
			{## "dcg/ai_airstrike"
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
												{tag air_vehicle}
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
												{tag air_vehicle}
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
			{## "dcg/ai_airstrike_do"
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
								{amount 1
								}
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
								{amount 1
								}
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
											{state
												{state "inactive linked"}
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
			{## "dcg/ai_air_chance"
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
							{var "user_team$"}
							{op "=="}
							{value "def_team$"}
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
								{tag player}
								{zone "gamezone"}
								{type human}
								{state "not dead"}
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
												{tag player_armor}
											}
											{tag
												{tag player_car}
											}
											{tag
												{tag player_veh}
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
													{tag
														{tag player_armor}
													}
													{tag
														{tag player_car}
													}
													{tag
														{tag player_veh}
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
														{tag player_armor}
													}
													{tag
														{tag player_car}
													}
													{tag
														{tag player_veh}
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
														{tag player_armor}
													}
													{tag
														{tag player_car}
													}
													{tag
														{tag player_veh}
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
														{tag player_armor}
													}
													{tag
														{tag player_car}
													}
													{tag
														{tag player_veh}
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
														{tag player_armor}
													}
													{tag
														{tag player_car}
													}
													{tag
														{tag player_veh}
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
													{tag
														{tag player}
													}
												}
												{include
													{zone
														{zone "gamezone"}
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
														{tag player}
													}
												}
												{include
													{zone
														{zone "gamezone"}
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
														{tag player}
													}
												}
												{include
													{zone
														{zone "gamezone"}
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
														{tag player}
													}
												}
												{include
													{zone
														{zone "gamezone"}
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
														{tag player}
													}
												}
												{include
													{zone
														{zone "gamezone"}
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
					{"delay"
						{time 1.2}
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
									{tag
										{tag spawn_b}
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
											{state
												{state "inactive linked"}
											}
										}
									}
								}
							}
							{amount 1
							}
						}
						{tag_add user_team}
					}
					{"delay"
						{time 1}
					}
					{## "switch"
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag spawn_b}
											}
										}
										{include
											{tag
												{tag user_team}
											}
										}
										{exclude
											{tag
												{tag spawn_a}
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
							{## "delete"
								{selector
									{ignore_captured_by_user 0}
									{tag arrow_enemy_b}
								}
							}
						}
						{## "default"
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
								{var "user_is_defender$"}
								{op "=="}
								{value 1}
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
								{tag_add player_defending}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "user_is_defender$"}
								{op "=="}
								{value 0}
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
								{tag_add player_attacking}
							}
						}
						{"default"
							{"delay"
								{time 0.2}
							}
							{## "objective_progress"
								{set 0}
								{add 0}
								{title "dcg eid error 01 - report if you see this"}
							}
							{"delay"
								{time 5}
							}
							{## "objective_progress"
								{hide}
								{set 0}
								{add 0}
								{title "dcg eid error 01 - report if you see this"}
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
								{tag_add player_attacking}
							}
						}
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
						{"case"
							{condition
								{type side}
								{side ita}
							}
							{"delay"
								{time 0.1}
							}
							{"set_i"
								{var "user_nation$"}
								{op "="}
								{value 6}
							}
						}
						{"case"
							{condition
								{type side}
								{side fra}
							}
							{"delay"
								{time 0.1}
							}
							{"set_i"
								{var "user_nation$"}
								{op "="}
								{value 7}
							}
						}
						{"case"
							{condition
								{type side}
								{side pol}
							}
							{"delay"
								{time 0.1}
							}
							{"set_i"
								{var "user_nation$"}
								{op "="}
								{value 8}
							}
						}
						{"case"
							{condition
								{type side}
								{side jap}
							}
							{"delay"
								{time 0.1}
							}
							{"set_i"
								{var "user_nation$"}
								{op "="}
								{value 9}
							}
						}
						{"case"
							{condition
								{type side}
								{side hun}
							}
							{"delay"
								{time 0.1}
							}
							{"set_i"
								{var "user_nation$"}
								{op "="}
								{value 10}
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
							{## "objective_progress"
								{set 0}
								{add 0}
								{title "dcg side 01 error - report if you see this"}
							}
							{"delay"
								{time 30}
							}
							{## "objective_progress"
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
			{## "minimap/1"
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
			{## "minimap/2"
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
			{## "minimap/3"
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
			{## "minimap/4"
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
			{"minimap/arrows"
				{condition
					{terms
						{"1.event"
							{id "init"}
						}
						;{"2.cmp_i"
						;	{var "dcg_on$"}
						;	{op ">"}
						;	{value 0}
						;}
						{"3.entities"
							{selector
								{tag ai_spawn}
								{zone "gamezone"}
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
							{"if"
								{condition
									{type cmp_i}
									{var "user_is_defender$"}
									{op "=="}
									{value 1}
								}
								{"delay"
									{time 300}
								}
							}
							{"entity_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag arrow_enemy_b}
											}
										}
										{exclude
											{tag
												{tag arrow_enemy_a}
											}
										}
									}
								}
								{tag_remove hidden}
								{inactive off}
							}
						}
						{"default"
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
							{"if"
								{condition
									{type cmp_i}
									{var "user_is_defender$"}
									{op "=="}
									{value 1}
								}
								{"delay"
									{time 300}
								}
							}
							{"entity_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag arrow_enemy_a}
											}
										}
										{exclude
											{tag
												{tag arrow_enemy_b}
											}
										}
									}
								}
								{tag_remove hidden}
								{inactive off}
							}
						}
					}
				}
			}
			{"minimap/user_team"
				{condition
					{expression "(1 & 2) | (1 & 3)"}
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
										{zone
											{zone "combat"}
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
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"delay"
						{time 0.5}
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
														{tag user_team}
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
								{time 0.1}
							}
							{"set_i"
								{var "dcg_error$"}
								{op "-"}
								{value 1}
							}
							{## "objective_progress"
								{set 0}
								{add 0}
								{title "dcg arrow error - report if you see this"}
							}
							{"delay"
								{time 5}
							}
							{## "objective_progress"
								{hide}
								{set 0}
								{add 0}
								{title "dcg arrow error - report if you see this"}
							}
							{"delay"
								{time 0.1}
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
								}
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
						{time 0.5}
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
						{time 1}
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
					{"delay"
						{time 0.5}
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
			{"dcg/def/show"
				{condition
					{expression "!1 & 2 & 3 & 4"}
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
						{"4.entities"
							{selector
								{ignore_captured_by_user 0}
								{tag player}
								{zone "gamezone"}
								{type human}
								{state operatable}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
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
					{"delay"
						{time 1}
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
			{"dcg/def/display_a"
				{condition
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

