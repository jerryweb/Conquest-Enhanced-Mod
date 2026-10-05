; File created by Hawka
;==========================================================================================================
			
	(include "ai_logic/ce_ai_spawn_triggers.inc")

	{"weather_scripts/dynamic_weather_script"
				{condition
					{expression "1 & 2"}
					{terms
						{"1.cmp_i"
							{var "weather_selection$"}
							{op ">"}
							{value 0}
						}
						{"2.cmp_i"
							{var "season_set$"}
							{op ">"}
							{value 0}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{## "timer"
						{time 150}
						{title "dynamic weather system activated"}
					}
					{## "delay"
						{time 150}
					}
					{## "set_i"
						{var "prev_weather_selection$"}
						{op "="}
						{value "weather_selection$"}
					}
					{## "trigger"
						{name "weather_scripts/dynamic_weather_script"}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "strong_weather_enabled$"}
								{op "=="}
								{value 1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "weather_selection$"}
										{op "=="}
										{value 1}
									}
									{"environment"
										{name "dynamic_campaign/summer/clear/morning_01"}
										{time 150}
										{apply}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "weather_selection$"}
										{op "=="}
										{value 2}
									}
									{"environment"
										{name "dynamic_campaign/summer/clear/midday_1"}
										{time 150}
										{apply}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "weather_selection$"}
										{op "=="}
										{value 3}
									}
									{"environment"
										{name "dynamic_campaign/summer/clear/evening_01"}
										{time 150}
										{apply}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "weather_selection$"}
										{op "=="}
										{value 4}
									}
									{"environment"
										{name "dynamic_campaign/summer/sloudy/morning_01"}
										{time 150}
										{apply}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "weather_selection$"}
										{op "=="}
										{value 5}
									}
									{"environment"
										{name "dynamic_campaign/summer/sloudy/midday_1"}
										{time 150}
										{apply}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "weather_selection$"}
										{op "=="}
										{value 6}
									}
									{"environment"
										{name "dynamic_campaign/summer/sloudy/evening_01"}
										{time 150}
										{apply}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "weather_selection$"}
										{op "=="}
										{value 7}
									}
									{"environment"
										{name "goh/west/wip/summer/night_1"}
										{time 150}
										{apply}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "weather_selection$"}
										{op "=="}
										{value 8}
									}
									{"environment"
										{name "goh/west/wip/summer/night_2"}
										{time 150}
										{apply}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "weather_selection$"}
										{op "=="}
										{value 9}
									}
									{"environment"
										{name "goh/west/wip/summer/sunset_1"}
										{time 150}
										{apply}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "weather_selection$"}
										{op "=="}
										{value 10}
									}
									{"environment"
										{name "goh/west/wip/summer/sunset_rain_1"}
										{time 150}
										{apply}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "weather_selection$"}
										{op "=="}
										{value 11}
									}
									{"environment"
										{name "goh/west/wip/summer/sunrise_1"}
										{time 150}
										{apply}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "weather_selection$"}
										{op "=="}
										{value 12}
									}
									{"environment"
										{name "goh/west/wip/summer/sunrise_2"}
										{time 150}
										{apply}
									}
								}
							}
						}
						{"default"
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "weather_selection$"}
										{op "=="}
										{value 1}
									}
									{"environment"
										{name "dynamic_campaign/summer/clear/morning_01"}
										{time 150}
										{apply}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "weather_selection$"}
										{op "=="}
										{value 2}
									}
									{"environment"
										{name "dynamic_campaign/summer/clear/midday_1"}
										{time 150}
										{apply}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "weather_selection$"}
										{op "=="}
										{value 3}
									}
									{"environment"
										{name "dynamic_campaign/summer/clear/evening_01"}
										{time 150}
										{apply}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "weather_selection$"}
										{op "=="}
										{value 4}
									}
									{"environment"
										{name "dynamic_campaign/summer/sloudy/morning_01"}
										{time 150}
										{apply}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "weather_selection$"}
										{op "=="}
										{value 5}
									}
									{"environment"
										{name "dynamic_campaign/summer/sloudy/midday_1"}
										{time 150}
										{apply}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "weather_selection$"}
										{op "=="}
										{value 6}
									}
									{"environment"
										{name "dynamic_campaign/summer/sloudy/evening_01"}
										{time 150}
										{apply}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "weather_selection$"}
										{op "=="}
										{value 7}
									}
									{"environment"
										{name "goh/west/wip/summer/night_1"}
										{time 150}
										{apply}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "weather_selection$"}
										{op "=="}
										{value 8}
									}
									{"environment"
										{name "goh/west/wip/summer/night_2"}
										{time 150}
										{apply}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "weather_selection$"}
										{op "=="}
										{value 9}
									}
									{"environment"
										{name "goh/west/wip/summer/sunset_1"}
										{time 150}
										{apply}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "weather_selection$"}
										{op "=="}
										{value 10}
									}
									{"environment"
										{name "goh/west/wip/summer/sunset_rain_1"}
										{time 150}
										{apply}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "weather_selection$"}
										{op "=="}
										{value 11}
									}
									{"environment"
										{name "goh/west/wip/summer/sunrise_1"}
										{time 150}
										{apply}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "weather_selection$"}
										{op "=="}
										{value 12}
									}
									{"environment"
										{name "goh/west/wip/summer/sunrise_2"}
										{time 150}
										{apply}
									}
								}
							}
						}
					}
				}
			}



