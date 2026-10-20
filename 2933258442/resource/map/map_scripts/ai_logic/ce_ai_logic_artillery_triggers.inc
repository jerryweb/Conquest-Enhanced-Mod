;============== AI ARTILLERY (CEv3, 3 range classes x 5 flags) ==============
; Flow per pass:
;   pick one eligible gun -> run the pipeline for its range class:
;     1) flag-priority target (attacker_target_flag$ = N): nearest vehicle/officer in zone forwardN,
;        else nearest infantry
;     2) drop the target if it is farther than the class range from the gun
;     3) if nothing is tagged, fall back to the nearest enemy vehicle/officer within range of the gun
;   -> fire (suppression_fire) and start the combat timer, or release the gun and retry.
; Ranges: long_range 400 m, regular (neither tag) 355 m, short_range 270 m.
; Assumes zones forward1..forward5 exist and var attacker_target_flag$ holds 1..5.
; The DBG timers print on-screen text; remove them for release.
; REQUIRES the handlers select_artillery / artillery_attempt_failed /
; artillery_start_combat_timer in vehicle_ce.inc.


; ---- Shared: flag-priority targeting for flag %flag (range independent) ----
; 1) nearest vehicle/officer in zone forward%flag   2) if none, nearest infantry
(define "artillery_flag_case"
	{"case"
		{condition
			{type cmp_i}
			{var "attacker_target_flag$"}
			{op "=="}
			{value %flag}
		}
		{"entity_state"
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
						{zone
							{zone "forward%flag"}
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
						{state dead}
					}
					{tag
						{tag _bot}
					}
				}
				}
				{sort
					{type entity}
					{entity
						{amount 1
						}
						{tag artillery_selected}
						{type vehicle}
						{state inhabited}
					}
				}
				{amount 1
				}
			}
			{tag_add artillery_target}
		}
		{"if"
			{condition
				{type entities}
				{selector
					{tag artillery_target}
					{zone "forward%flag"}
					{state operatable}
				}
				{count
					{op "=="}
					{value 0}
				}
			}
			{"entity_state"
				{selector
					{source advanced}
					{group
						{select
							{tag
								{tag possible_enemy_inf}
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
								{state inactive}
							}
							{state
								{state linked}
							}
							{tag
								{tag _bot}
							}
						}
					}
					{sort
						{type entity}
						{entity
							{tag artillery_selected}
							{type vehicle}
							{state inhabited}
						}
					}
					{amount 1
					}
				}
				{tag_add artillery_target}
			}
		}
	}
)

; ---- Shared: the whole targeting pipeline for ONE range class ----
;   need/ban1/ban2 = tags that identify the class of the selected gun
;   dist           = metres from the gun to the target
;   1) flag priority   2) drop target if out of range   3) fallback: any enemy near the gun
(define "artillery_range_block"
	{"case"
		{condition
			{type entities}
			{selector
				{source advanced}
				{group
					{select
						{tag
							{tag artillery_selected}
						}
					}
					{include
						{tag
							{tag %need}
						}
					}
					{exclude
						{state
							{state user_control}
						}
						{tag
							{tag %ban1}
						}
						{tag
							{tag %ban2}
						}
					}
				}
			}
		}
		{"switch"
			("artillery_flag_case" flag(1))
			("artillery_flag_case" flag(2))
			("artillery_flag_case" flag(3))
			("artillery_flag_case" flag(4))
			("artillery_flag_case" flag(5))
		}
		{"delay"
			{time 1}
		}
		{"switch"
			{"case"
				{condition
					{type near}
					{units
						{tag artillery_selected}
					}
					{near_to
						{tag artillery_target}
						{state operatable}
					}
					{distance %dist}
				}
			}
			{"default"
				{"entity_state"
					{selector
						{tag artillery_target}
					}
					{tag_remove artillery_target}
				}
			}
		}
		{"delay"
			{time 1}
		}
		{"if"
			{condition
				{type entities}
				{selector
					{tag artillery_target}
					{zone "gamezone"}
					{state operatable}
				}
				{count
					{op "=="}
					{value 0}
				}
			}
			{"switch"
				{"case"
					{condition
						{type near}
						{units
							{amount 1
							}
							{tag artillery_selected}
							{type vehicle}
							{state inhabited}
						}
						{near_to
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
								{state
									{state inactive}
								}
								{state
									{state linked}
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
						{distance %dist}
					}
					{## "timer"
						{time 3}
						{title "DBG: near matched"}
					}
					{"entity_state"
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
									{state
										{state inactive}
									}
									{state
										{state linked}
									}
									{state
										{state dead}
									}
									{tag
										{tag _bot}
									}
								}
							}
							{sort
								{type entity}
								{entity
									{amount 1
									}
									{tag artillery_selected}
									{type vehicle}
									{state inhabited}
								}
							}
							{amount 1
							}
						}
						{tag_add artillery_target}
					}
				}
				{"default"
					{## "timer"
						{time 2}
						{title "DBG: No targets in artillery range!"}
					}
					{"delay"
						{time 2}
					}
				}
			}
		}
	}
)

{"ai_logic/artillery/cannon_artillery_pick_target"
	{condition
		{terms
			{"1.entities"
				{selector
					{source advanced}
					{group
						{select
							{tag
								{tag _bot}
							}
						}
						{include
							{prop
								{prop cannon}
							}
							{prop
								{prop detect_artillery}
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
								{tag artillery_in_combat}
							}
							{tag
								{tag gun_fired}
							}
							{tag
								{tag artillery_advancing}
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
				{tag artillery_target}
			}
			{tag_remove artillery_target}
		}
		{"effect"
			{selector
				{source advanced}
				{group
					{select
						{tag
							{tag _bot}
						}
					}
					{include
						{prop
							{prop cannon}
						}
						{prop
							{prop detect_artillery}
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
							{tag artillery_in_combat}
						}
						{tag
							{tag gun_fired}
						}
						{tag
							{tag artillery_advancing}
						}
					}
				}
				{amount 1
				}
			}
			{effect select_artillery}
		}
		{"delay"
			{time 0.2}
		}
		{"select"
			{amount 1
			}
			{tag artillery_selected}
			{type vehicle}
			{state inhabited}
		}
		{"delay"
			{time 0.2}
		}
		; One pipeline per range class. A gun matches exactly one of these.
		; NOTE: a switch only runs the FIRST matching case; "default" does not stop the trigger.
		{"switch"
			("artillery_range_block" need(long_range) ban1(short_range) ban2(short_range) dist(400))
			("artillery_range_block" need(short_range) ban1(long_range) ban2(long_range) dist(270))
			("artillery_range_block" need(artillery_selected) ban1(long_range) ban2(short_range) dist(355))
		}
		{"delay"
			{time 1}
		}
		{"switch"
			{"case"
				{condition
					{type entities}
					{selector
						{tag artillery_target}
						{state operatable}
					}
				}
				{"actor_state"
					{selector
						{source current}
					}
					{drop orders}
					{cannon fire}
				}
				{## "timer"
					{time 2}
					{title "DBG: target tagged"}
				}
				{"delay"
					{time 0.5}
				}
				{"loop" 1
					{"action"
						{selector
							{source current}
						}
						{drop orders}
						{action suppression_fire}
						{target
							{source advanced}
							{group
								{select
									{tag
										{tag artillery_target}
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
									{tag
										{tag _bot}
									}
								}
							}
							{amount 1
							}
						}
					}
				}
				{"delay"
					{time 0.5}
				}
				{"effect"
					{selector
						{tag artillery_selected}
						{type vehicle}
						{state inhabited}
					}
					{effect artillery_start_combat_timer}
				}
				{"delay"
					{time 0.5}
				}
				{"trigger"
					{name "ai_logic/artillery/cannon_artillery_pick_target"}
				}
			}
			{"default"
				{"switch"
					{"case"
						{condition
							{type rand}
							{value 0.3}
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
							{effect artillery_attempt_failed_with_order}
						}

					}
					{"default"
						{"effect"
							{selector
								{source current}
							}
							{effect artillery_attempt_failed}
						}				
					}
				}
				{## "timer"
					{time 2}
					{title "DBG: no target at attack time"}
				}
				{"delay"
					{time 2}
				}
				{"trigger"
					{name "ai_logic/artillery/cannon_artillery_pick_target"}
				}
			}
		}
	}
}
