; File created by Hawka
;==========================================================================================================

; Vanilla var includes
(include "../map/multi/dcg_functions.inc")

;============ AI SPAWN LOGIC  ========================================


;============ AI TAGGING LOGIC  ========================================
			{"select_ai_bot_units_to_tag"
				{"switch"
					{"case"
						{condition
							{type cmp_i}
							{var "id_defenderbot$"}
							{op "=="}
							{value 1}
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
											{tag air_vehicle}
										}
										{player
											{player "0"}
										}
										{state
											{state user_control}
										}
										{player
											{player "1"}
										}
										{tag
											{tag _ai_defender}
										}
									}
								}
							}
							{tag_add _ai}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "id_defenderbot$"}
							{op "=="}
							{value 2}
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
											{tag air_vehicle}
										}
										{player
											{player "0"}
										}
										{state
											{state user_control}
										}
										{player
											{player "2"}
										}
										{tag
											{tag _ai_defender}
										}
									}
								}
							}
							{tag_add _ai}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "id_defenderbot$"}
							{op "=="}
							{value 3}
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
											{tag air_vehicle}
										}
										{player
											{player "0"}
										}
										{state
											{state user_control}
										}
										{player
											{player "3"}
										}
										{tag
											{tag _ai_defender}
										}
									}
								}
							}
							{tag_add _ai}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "id_defenderbot$"}
							{op "=="}
							{value 4}
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
											{tag air_vehicle}
										}
										{player
											{player "0"}
										}
										{state
											{state user_control}
										}
										{player
											{player "4"}
										}
										{tag
											{tag _ai_defender}
										}
									}
								}
							}
							{tag_add _ai}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "id_defenderbot$"}
							{op "=="}
							{value 5}
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
											{tag air_vehicle}
										}
										{player
											{player "0"}
										}
										{state
											{state user_control}
										}
										{player
											{player "5"}
										}
										{tag
											{tag _ai_defender}
										}
									}
								}
							}
							{tag_add _ai}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "id_defenderbot$"}
							{op "=="}
							{value 6}
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
											{tag air_vehicle}
										}
										{player
											{player "0"}
										}
										{state
											{state user_control}
										}
										{player
											{player "6"}
										}
										{tag
											{tag _ai_defender}
										}
									}
								}
							}
							{tag_add _ai}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "id_defenderbot$"}
							{op "=="}
							{value 7}
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
											{tag air_vehicle}
										}
										{player
											{player "0"}
										}
										{state
											{state user_control}
										}
										{player
											{player "7"}
										}
										{tag
											{tag _ai_defender}
										}
									}
								}
							}
							{tag_add _ai}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "id_defenderbot$"}
							{op "=="}
							{value 8}
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
											{tag air_vehicle}
										}
										{player
											{player "0"}
										}
										{state
											{state user_control}
										}
										{player
											{player "8"}
										}
										{tag
											{tag _ai_defender}
										}
									}
								}
							}
							{tag_add _ai}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "id_defenderbot$"}
							{op "=="}
							{value 9}
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
											{tag air_vehicle}
										}
										{player
											{player "0"}
										}
										{state
											{state user_control}
										}
										{player
											{player "9"}
										}
										{tag
											{tag _ai_defender}
										}
									}
								}
							}
							{tag_add _ai}
						}
					}
					{"default"
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
											{tag air_vehicle}
										}
										{player
											{player "0"}
										}
										{state
											{state user_control}
										}
										{tag
											{tag _ai_defender}
										}
									}
								}
							}
							{tag_add _ai}
						}
					}
				}
			}