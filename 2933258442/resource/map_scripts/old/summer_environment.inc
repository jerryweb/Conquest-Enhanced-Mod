			(define "weather_case"  ; parms: weather_selection_value, weather_path, apply_time
				{"case"
					{condition
						{type cmp_i}
						{var "weather_selection$"}
						{op "=="}
						{value %weather_selection_value}
					}
					{"environment"
						{name "%weather_path"}
						{time %apply_time}
						{apply}
					}
				}
			)
			{"set_weather_tag"
				{condition
					{terms
						{"1.entities"
							{selector
								{tag scene_variable}
								{type vehicle}
							}
						}
					}
				}
				{actions
					{"select"
						{tag scene_variable}
						{type vehicle}
					}
					{"delay"
						{time 2}
					}
					{"entity_state"
						{selector
							{source current}
						}
						{tag_add "_summer"}
					}
				}
			}
			{"player_scripts/dynamic_weather_script"
				{condition
					{terms
						{"2.cmp_i"
							{var "weather_selection$"}
							{op "!="}
							{value "prev_weather_selection$"}
						}
					}
				}
				{actions
					{## "timer"
						{time 150}
						{title "dynamic weather system activated"}
					}
					{"switch"
						("weather_case" weather_selection_value(1) weather_path(dynamic_campaign/summer/clear/morning_01) 	apply_time(150))
						("weather_case" weather_selection_value(2) weather_path(dynamic_campaign/summer/clear/midday_1) 	apply_time(150))
						("weather_case" weather_selection_value(3) weather_path(dynamic_campaign/summer/clear/evening_01) 	apply_time(150))

						("weather_case" weather_selection_value(4) weather_path(dynamic_campaign/summer/sloudy/morning_01) 	apply_time(150))
						("weather_case" weather_selection_value(5) weather_path(dynamic_campaign/summer/sloudy/midday_1) 	apply_time(150))
						("weather_case" weather_selection_value(6) weather_path(dynamic_campaign/summer/sloudy/evening_01) 	apply_time(150))

						("weather_case" weather_selection_value(7) weather_path(goh/west/wip/summer/night_1) 	apply_time(150))
						("weather_case" weather_selection_value(8) weather_path(goh/west/wip/summer/night_2) 	apply_time(150))

						("weather_case" weather_selection_value(9) weather_path(goh/west/wip/summer/sunset_1) 			apply_time(150))
						("weather_case" weather_selection_value(10) weather_path(goh/west/wip/summer/sunset_rain_1) 	apply_time(150))

						("weather_case" weather_selection_value(11) weather_path(goh/west/wip/summer/sunrise_1) 		apply_time(150))
						("weather_case" weather_selection_value(12) weather_path(goh/west/wip/summer/sunrise_2) 		apply_time(150))
					}						
					{"delay"
						{time 150}
					}
					{"set_i"
						{var "prev_weather_selection$"}
						{op "="}
						{value "weather_selection$"}
					}	
					{"delay"
						{time 1}
					}					
					{"trigger"
						{name "player_scripts/dynamic_weather_script"}
					}
				}	
			}
			{"environment/summer"
				{condition
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"switch"
						;(include "weather_cases.inc")
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
				}
			}