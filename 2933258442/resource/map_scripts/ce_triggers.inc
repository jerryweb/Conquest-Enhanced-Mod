; File created by Hawka
;==========================================================================================================
			{## "test_check_plane_properties"
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
											{prop airborne}
										}
										;{state
										;	{state "user_control"}
										;}
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
					{"timer"
						{time 10}
						{title "user plane detected."}
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
									{state
										{state "operatable inhabited user_control"}
									}
									{prop
										{prop airborne}
									}
								}
							}
						}
						{effect smoke_for_test}
					}
					{"delay"
						{time 1}
					}
				}
			}
			(include "ce_player_triggers.inc")
			(include "ce_mechanics_triggers.inc")
			(include "ai_logic/ce_lua_triggers.inc")
			(include "ai_logic/ce_ai_spawn_triggers.inc")
			(include "ai_logic/ce_ai_logic_triggers.inc")
			(include "map_setup/base_map_setup_triggers.inc")
			(include "map_setup/ce_map_setup_triggers.inc")
			

