{"laffly_v15t"
	{on spawn
    	{if not tagged "radiorus"
		    {tags add "radio_car"}
		}
		{tags add "french"}
		{tags add "laffly_v15t"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_armor-disablededcar"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}

;AUTOMATIC WEAPONRY
{"0_3cal_m1919a4_fr"
	{on spawn
	    {tags add "HMG"}
		{tags add "french"}
		{tags add "0_3cal_m1919a4_fr"}
		{delay 10
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
									        {if not tagged "preplaced_mg"
									        	{tags add "enemymg"}
									    	}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"0_5cal_m2hb_fr"
	{on spawn
	    {tags add "HMG"}
		{tags add "french"}
		{tags add "0_5cal_m2hb_fr"}
		{delay 10
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
									        {if not tagged "preplaced_mg"
									        	{tags add "enemymg"}
									    	}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}

;AA WEAPONRY
{"13mm_hotchkiss"
	{on spawn
	    {tags add "AAFLAK"}
		{tags add "french"}
		{tags add "13mm_hotchkiss"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
									        {tags add "ai_aa-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"40_mm_m1_fr"
	{on spawn
	    {tags add "AAFLAK"}
		{tags add "french"}
		{tags add "40_mm_m1_fr"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
									        {tags add "ai_aa-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}


; AT WEAPONRY

{"25mm_hotchkiss_mle34"
	{on spawn
	    {tags add "light_at_gun"}
		{tags add "french"}
		{tags add "25mm_hotchkiss_mle34"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
									        {tags add "ai_atgun-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"47mm_puteaux_mle37"
	{on spawn
	    {tags add "light_at_gun"}
		{tags add "french"}
		{tags add "47mm_puteaux_mle37"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
									        {tags add "ai_atgun-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"57_mm_m1_fr"
	{on spawn
	    {tags add "medium_at_gun"}
		{tags add "french"}
		{tags add "57_mm_m1_fr"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
									        {tags add "ai_atgun-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}


;HOWITZERS
{"75_mm_m1897a4_fr"
	{on spawn
    	{tags add "artillery"}
		{tags add "french"}
		{tags add "75_mm_m1897a4_fr"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "enemyarty-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	
	}
}
{"81_mm_m1_fr"
	{on spawn
    	{tags add "artillery"}
		{tags add "french"}
		{tags add "81_mm_m1_fr"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "enemyarty-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"105_mm_m2a1l_fr"
	{on spawn
    	{tags add "artillery"}
		{tags add "french"}
		{tags add "105_mm_m2a1l_fr"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "enemyarty-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"155_mm_m1918"
	{on spawn
    	{tags add "artillery"}
		{tags add "french"}
		{tags add "155_mm_m1918"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "enemyarty-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"22cm_mortier"
	{on spawn
    	{tags add "artillery"}
		{tags add "french"}
		{tags add "22cm_mortier"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "enemyarty-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
;_________________________________________________
;|               Wheeled vehicles                 |
;|________________________________________________|


{"cckw352_fr_inf"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "french"}
		{tags add "cckw352_fr_inf"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_car-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
    }
}
{"chevrolet_fuel_fr"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "french"}
		{tags add "chevrolet_fuel_fr"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_car-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
    }
}
{"cckw352_fr_art"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "french"}
		{tags add "cckw352_fr_art"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_car-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
    }
}
{"cckw352_fr_eng"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "french"}
		{tags add "cckw352_fr_eng"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_car-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
    }
}
{"m3a1_scout_fr"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "french"}
		{tags add "m3a1_scout_fr"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_armor-disablededcar"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"dodgewc55_fr"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "french"}
		{tags add "dodgewc55_fr"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_car-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"m20_fr"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "french"}
		{tags add "m20_fr"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_car-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"m8_grayhound_fr"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "french"}
		{tags add "m8_grayhound_fr"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_rocketarty-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"m17_fr"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "french"}
		{tags add "m17_fr"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_rocketarty-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"m4halftrack_fr"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "french"}
		{tags add "m4halftrack_fr"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_armor-disablededcar"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"laffly_v15t_mg"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "french"}
		{tags add "laffly_v15t_mg"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_armor-disablededcar"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"laffly_s15_toe"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "french"}
		{tags add "laffly_s15_toe"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_armor-disablededcar"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"autocanon_75mm"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "french"}
		{tags add "autocanon_75mm"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_armor-disablededcar"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"panhard"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "french"}
		{tags add "panhard"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_armor-disablededcar"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
;_________________________________________________
;|        Main Battle Tanks and SPGs              |
;|________________________________________________|

;LIGHT
{"m5a1_fr"
	{on spawn
    	{tags add "light_tank"}
		{tags add "french"}
		{tags add "m5a1_fr"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_armor-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"m8_fr"
	{on spawn
    	{tags add "light_tank"}
		{tags add "french"}
		{tags add "m8_fr"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								   {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_armor-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"amr35-13mm"
	{on spawn
    	{tags add "light_tank"}
		{tags add "french"}
		{tags add "amr35-13mm"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								   {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_armor-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"r35"
	{on spawn
    	{tags add "light_tank"}
		{tags add "french"}
		{tags add "r35"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								   {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_armor-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"amr35-25mm"
	{on spawn
    	{tags add "light_tank"}
		{tags add "french"}
		{tags add "amr35-25mm"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								   {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_armor-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"r39"
	{on spawn
    	{tags add "light_tank"}
		{tags add "french"}
		{tags add "r39"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								   {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_armor-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"h39"
	{on spawn
    	{tags add "light_tank"}
		{tags add "french"}
		{tags add "h39"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								   {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_armor-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}


;MEDIUM
{"cavalier_mk_vii"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "french"}
		{tags add "cavalier_mk_vii"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_armor-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"m4a3_75_fr"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "french"}
		{tags add "m4a3_75_fr"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_armor-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"m4a3_76_fr"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "french"}
		{tags add "m4a3_76_fr"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_armor-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"char_d2"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "french"}
		{tags add "char_d2"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_armor-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"s35"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "french"}
		{tags add "s35"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_armor-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"b1bis"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "french"}
		{tags add "b1bis"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_armor-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}

;SPG
{"m10wolverine_fr"
	{on spawn
    	{tags add "spg"}
		{tags add "french"}
		{tags add "m10wolverine_fr"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_armor-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"m4a3_105_fr"
	{on spawn
    	{tags add "spg"}
		{tags add "french"}
		{tags add "m4a3_105_fr"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_armor-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"m7_fr"
	{on spawn
    	{tags add "spg"}
		{tags add "french"}
		{tags add "m7_fr"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_armor-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"laffly15tcc"
	{on spawn
    	{tags add "spg"}
		{tags add "french"}
		{tags add "laffly15tcc"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_armor-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"bs-75"
	{on spawn
    	{tags add "spg"}
		{tags add "french"}
		{tags add "bs-75"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "ai_armor-disabled"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}