			{"environment/winter"
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
								{value 0.1}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/winter/clear/evening_01"}
								{time -1}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/winter/clear/midday_1"}
								{time -1}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/winter/foggy/foggy_1"}
								{time -1}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/winter/cloudy/morning_1"}
								{time -1}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/winter/cloudy/evening_01"}
								{time -1}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/winter/foggy/foggy_2"}
								{time -1}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/winter/cloudy/midday_1"}
								{time -1}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/winter/cloudy/midday_1a"}
								{time -1}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/winter/cloudy/midday_1b"}
								{time -1}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/winter/foggy/foggy_3"}
								{time -1}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/winter/clear/midday_2"}
								{time -1}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/winter/clear/midday_2b"}
								{time -1}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "goh/west/wip/winter/night_1"}
								{time 8}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "goh/west/wip/winter/night_2"}
								{time 8}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "goh/west/wip/winter/day_blizzard_1"}
								{time 8}
								{apply}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "goh/west/wip/winter/day_blizzard_2"}
								{time 8}
								{apply}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"environment"
								{name "dynamic_campaign/winter/clear/morning_1"}
								{time -1}
								{apply}
							}
						}
					}
				}
			}