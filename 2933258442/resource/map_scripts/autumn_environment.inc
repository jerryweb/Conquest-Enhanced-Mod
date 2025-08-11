			{"environment/autumn"
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
								{value 0.13}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/autumn/clear/morning_1"}
								{time -1}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.13}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/autumn/clear/evening_1"}
								{time -1}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.13}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/autumn/clear/midday_1"}
								{time -1}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.13}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/autumn/cloudy/morning_1"}
								{time -1}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.13}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/autumn/cloudy/midday_1"}
								{time -1}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.13}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/autumn/cloudy/midday_2"}
								{time -1}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.13}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/autumn/cloudy/midday_1b"}
								{time -1}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.13}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/autumn/cloudy/evening_1"}
								{time -1}
								{apply}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/autumn/clear/midday_1b"}
								{time -1}
								{apply}
							}
						}
					}
				}
			}