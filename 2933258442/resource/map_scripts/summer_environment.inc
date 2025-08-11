			{"environment/summer"
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