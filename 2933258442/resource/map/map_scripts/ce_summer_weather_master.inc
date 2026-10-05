	{Environment "goh/black"}
	{Helpers
		(include "ce_events.inc")
		;(include "ce_tasks.inc")	
		{vars
			(include "ce_vars.inc")
		}
		{functions			
			(include "ce_functions.inc")
		}
		{triggers
			;(include "../summer_environment.inc")	
			{"environment/summer"
				{condition
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition
								{type rand}
								{value 0.15}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/summer/clear/evening_01"}
								{time -1}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.15}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/summer/clear/midday_1"}
								{time -1}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.15}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/summer/cloudy/morning_01"}
								{time -1}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.15}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/summer/cloudy/evening_01"}
								{time -1}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.15}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/summer/cloudy/midday_1"}
								{time -1}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.15}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "goh/west/wip/summer/night_1"}
								{time -1}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.15}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "goh/west/wip/summer/night_2"}
								{time -1}
								{apply}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/summer/clear/morning_01"}
								{time -1}
								{apply}
							}
						}
					}
					{"set_i"
						{var "season_set$"}
						{op "="}
						{value 2}
					}
				}
			}					
			(include "../multi/dcg_script.inc")
			(include "ce_triggers.inc")
		}
		;(include "../../ce_generic_waypoint.inc")