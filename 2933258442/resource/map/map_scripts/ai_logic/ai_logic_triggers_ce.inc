; File created by Hawka
;==========================================================================================================

			{"ai/ai_vehicle_smoke"
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
								{meters 140}
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
					{"timer"
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
							{amount 2}
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
						{time 2}
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
						{time 45}
					}
					{"trigger"
						{name "ai/ai_vehicle_smoke"}
					}
				}
			}