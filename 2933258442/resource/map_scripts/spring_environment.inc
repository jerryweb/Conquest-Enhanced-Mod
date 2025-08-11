			{"environment/spring"
				{condition
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"switch"
						(include "weather_cases.inc")
						{"case"
							{condition
								{type rand}
								{value 0.15}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/spring/clear/evening_1"}
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
								{name "dynamic_campaign/spring/clear/midday_1"}
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
								{name "dynamic_campaign/spring/cloudy/morning_1"}
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
								{name "dynamic_campaign/spring/cloudy/evening_1"}
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
								{name "dynamic_campaign/spring/cloudy/midday_1"}
								{time -1}
								{apply}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/spring/clear/morning_1"}
								{time -1}
								{apply}
							}
						}
					}
				}
			}