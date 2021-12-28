;AUTOMATIC WEAPONRY
{"maxim"
	{on spawn
	    {tags add "HMG"}
		{tags add "soviet"}
		{tags add "maxim"}
		{delay 6
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
{"dshk_stan"
	{on spawn
	    {tags add "HMG"}
		{tags add "soviet"}
		{tags add "dshk_stan"}
		{delay 6
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
{"dshk_aa"
	{on spawn
	    {tags add "HMG"}
		{tags add "soviet"}
		{tags add "dshk_aa"}
		{delay 6
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
{"25mm_72k"
	{on spawn
	    {tags add "AAFLAK"}
		{tags add "soviet"}
		{tags add "25mm_72k"}
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
{"37mm_61k"
	{on spawn
	    {tags add "AAFLAK"}
		{tags add "soviet"}
		{tags add "37mm_61k"}
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
{"m41_ampulomet"
	{on spawn
	    {tags add "light_at_gun"}
		{tags add "soviet"}
		{tags add "m41_ampulomet"}
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
{"45mm_m37"
	{on spawn
	    {tags add "light_at_gun"}
		{tags add "soviet"}
		{tags add "45mm_m37"}
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
{"45mm_m42"
	{on spawn
	    {tags add "light_at_gun"}
		{tags add "soviet"}
		{tags add "45mm_m42"}
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
{"57mm_zis2"
	{on spawn
	    {tags add "medium_at_gun"}
		{tags add "soviet"}
		{tags add "57mm_zis2"}
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
{"76mm_f22"
	{on spawn
	    {tags add "medium_at_gun"}
		{tags add "soviet"}
		{tags add "76_f22"}
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
{"76mm_zis3"
	{on spawn
	    {tags add "medium_at_gun"}
		{tags add "soviet"}
		{tags add "76mm_zis3"}
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
{"85mm_52k"
	{on spawn
	    {tags add "heavy_at_gun"}
		{tags add "soviet"}
		{tags add "85mm_52k"}
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
{"100mm_bs3"
	{on spawn
	    {tags add "heavy_at_gun"}
		{tags add "soviet"}
		{tags add "100mm_bs3"}
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
{"76mm_m1927"
	{on spawn
    	{tags add "field_gun"}
		{tags add "soviet"}
		{tags add "76mm_m1927"}
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
{"76mm_m43"
	{on spawn
    	{tags add "field_gun"}
		{tags add "soviet"}
		{tags add "76mm_m43"}
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
{"82mm_bm37"
	{on spawn
    	{tags add "artillery"}
		{tags add "soviet"}
		{tags add "82mm_bm37"}
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
{"120mm_pm38"
	{on spawn
    	{tags add "artillery"}
		{tags add "soviet"}
		{tags add "120mm_pm38"}
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
{"122mm_m30"
	{on spawn
    	{tags add "artillery"}
		{tags add "soviet"}
		{tags add "122mm_m30"}
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
{"122mm_a19"
	{on spawn
    	{tags add "artillery"}
	{tags add "heavy_artillery"}
		{tags add "soviet"}
		{tags add "122mm_a19"}
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
{"152mm_ml20"
	{on spawn
    	{tags add "artillery"}
	{tags add "heavy_artillery"}
		{tags add "soviet"}
		{tags add "152mm_ml20"}
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
{"203mm_b4"
	{on spawn
    	{tags add "artillery"}
	{tags add "heavy_artillery"}
		{tags add "soviet"}
		{tags add "203mm_b4"}
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


{"gaz_aaa"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "gaz_aaa"}
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
{"gaz_aaa_supply"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "gaz_aaa_supply"}
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
{"gaz_fuel"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "gaz_fuel"}
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
{"gaz_aaa_72k"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "gas_aaa_72k"}
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
{"zis5"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "zis5"}
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
{"zis5eng"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "zis5eng"}
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
{"bm13_studebaker"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "rocket_artillery"}
		{tags add "artillery"}
		{tags add "soviet"}
		{tags add "bm13_studebaker"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "enemy_rocketarty"}
										    {tags add "enemyarty"}
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
{"bm31_12"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "rocket_artillery"}
		{tags add "artillery"}
		{tags add "soviet"}
		{tags add "bm31_12"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "enemy_rocketarty"}
										    {tags add "enemyarty"}
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
{"gaz67b"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "gaz67b"}
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
{"gaz67"
	{on spawn
    	{if not tagged "radiorus"
		    {tags add "radio_car"}
		}
		{tags add "soviet"}
		{tags add "gaz67"}
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
{"ba20"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "ba20"}
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
{"ba6"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "ba6"}
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
{"ba64"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "ba64"}
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
{"universal_carrier_rus"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "universal_carrier_rus"}
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
{"mmg_carrier_rus"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "mmg_carrier_rus"}
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
{"m3a1e1_scout_mgun"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "m3a1e1_scout_mgun"}
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
{"t27"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "t27"}
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
{"t37a"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "t37a"}
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
{"t40"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "t40"}
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
{"t30"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "t30"}
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
{"t60"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "t60"}
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
{"t70"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "t70"}
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
{"t70m"
	{on spawn
    	{tags add "light_tank"}
		{tags add "t70m"}
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
{"bt2_da2"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "bt2_da2"}
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
{"bt2"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "bt2"}
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
{"bt5"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "bt5"}
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
{"bt7"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "bt7"}
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
{"t26_31"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "t26_31"}
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
{"kht26"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "kht26"}
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
{"t26_33"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "t26_33"}
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
{"t26_39"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "t26_39"}
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
{"valentine2"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "valentine2"}
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
{"valentine7"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "valentine7"}
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
{"valentine9"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "valentine9"}
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
{"t28"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "soviet"}
		{tags add "t28"}
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
{"t3476_40"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "soviet"}
		{tags add "t3476_40"}
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
{"t3476_41"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "soviet"}
		{tags add "t3476_41"}
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
{"t3457_41"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "soviet"}
		{tags add "t3457_41"}
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
{"t3476_42"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "soviet"}
		{tags add "t3476_42"}
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
{"t3476_43"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "soviet"}
		{tags add "t3476_43"}
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
{"t3457_43"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "soviet"}
		{tags add "t3457_43"}
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
{"t3476_43_flame"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "soviet"}
		{tags add "t3476_43_flame"}
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
{"t3485_44"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "soviet"}
		{tags add "t3485_44"}
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

;HEAVY
{"churchill3"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "soviet"}
		{tags add "churchill3"}
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
{"kv1_40"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "soviet"}
		{tags add "kv1_40"}
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
{"kv1_41"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "soviet"}
		{tags add "kv1_41"}
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
{"kv2_40"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "soviet"}
		{tags add "kv2_40"}
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
{"kv1s"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "soviet"}
		{tags add "kv1s"}
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
{"kv85"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "soviet"}
		{tags add "kv85"}
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
{"is1_43"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "soviet"}
		{tags add "is1_43"}
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
{"is2_43"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "soviet"}
		{tags add "is2_43"}
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
{"is2_44"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "soviet"}
		{tags add "is2_44"}
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
{"zis30"
	{on spawn
    	{tags add "spg"}
		{tags add "soviet"}
		{tags add "zis30"}
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
{"su76"
	{on spawn
    	{tags add "spg"}
		{tags add "soviet"}
		{tags add "su76"}
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
{"su85"
	{on spawn
    	{tags add "spg"}
		{tags add "soviet"}
		{tags add "su85"}
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
{"su100"
	{on spawn
    	{tags add "spg"}
		{tags add "soviet"}
		{tags add "su100"}
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
{"su122"
	{on spawn
    	{tags add "spg"}
		{tags add "soviet"}
		{tags add "su122"}
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
{"su152"
	{on spawn
    	{tags add "spg"}
		{tags add "soviet"}
		{tags add "su152"}
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
{"isu122s"
	{on spawn
    	{tags add "spg"}
		{tags add "soviet"}
		{tags add "isu122s"}
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
{"isu152"
	{on spawn
    	{tags add "spg"}
		{tags add "soviet"}
		{tags add "isu152"}
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
;_______________________________________________
;|					Aircraft					|
;|______________________________________________|

{"conquest_il2"
	{on spawn
    	{tags add "aircraft"}
		{tags add "conquest_il2"}
	}
}

{"il2_mod42" 
	{on spawn
    	{tags add "aircraft"}
	}
}