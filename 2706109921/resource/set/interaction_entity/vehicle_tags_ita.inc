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
{"8mm_breda_37"
	{on spawn
	    {tags add "HMG"}
		{tags add "italian"}
		{tags add "8mm_breda_37"}
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
{"cannone_2065"
	{on spawn
	    {tags add "HMG"}
		{tags add "italian"}
		{tags add "cannone_2065"}
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



; AT WEAPONRY

{"2cm_solothurn"
	{on spawn
	    {tags add "light_at_gun"}
		{tags add "italian"}
		{tags add "2cm_solothurn"}
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
{"cannone_4732"
	{on spawn
	    {tags add "light_at_gun"}
		{tags add "italian"}
		{tags add "cannone_4732"}
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
{"cannone_7527"
	{on spawn
	    {tags add "medium_at_gun"}
		{tags add "italian"}
		{tags add "cannone_7527"}
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
{"7_5cm_pak97_38"
	{on spawn
	    {tags add "heavy_at_gun"}
		{tags add "italian"}
		{tags add "cmpak9738"}
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
{"obice_7513"
	{on spawn
    	{tags add "artillery"}
		{tags add "italian"}
		{tags add "obice_7513"}
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
{"81mm_brandt_ita"
	{on spawn
    	{tags add "artillery"}
		{tags add "italian"}
		{tags add "81mm_brandt_ita"}
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
{"obice_10017"
	{on spawn
    	{tags add "artillery"}
		{tags add "italian"}
		{tags add "obice_10017"}
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
{"obice_210"
	{on spawn
    	{tags add "artillery"}
		{tags add "italian"}
		{tags add "obice_210"}
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


{"fiat626"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "italian"}
		{tags add "fiat626"}
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
{"fiat626_fuel"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "italian"}
		{tags add "fiat626_fuel"}
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
{"fiat626_inf"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "italian"}
		{tags add "fiat626_inf"}
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
{"fiat626_art"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "italian"}
		{tags add "fiat626_art"}
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
{"fiat626_eng"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "italian"}
		{tags add "fiat626_eng"}
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
{"as42"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "italian"}
		{tags add "as42"}
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
{"ab41"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "italian"}
		{tags add "ab41"}
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
{"autocannone10017"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "italian"}
		{tags add "autocannone10017"}
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

;_________________________________________________
;|        Main Battle Tanks and SPGs              |
;|________________________________________________|

;LIGHT
{"cv35"
	{on spawn
    	{tags add "light_tank"}
		{tags add "italian"}
		{tags add "cv35"}
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
{"l640"
	{on spawn
    	{tags add "light_tank"}
		{tags add "italian"}
		{tags add "l640"}
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
{"m1441"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "italian"}
		{tags add "m1441"}
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
{"m1542"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "italian"}
		{tags add "m1542"}
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
{"pz3n_ita"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "italian"}
		{tags add "pz3n_ita"}
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
{"pz4g_ita"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "italian"}
		{tags add "pz4g_ita"}
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
{"m7518"
	{on spawn
    	{tags add "spg"}
		{tags add "italian"}
		{tags add "m7518"}
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
{"m7534"
	{on spawn
    	{tags add "spg"}
		{tags add "italian"}
		{tags add "m7534"}
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
{"stug3g_ita"
	{on spawn
    	{tags add "spg"}
		{tags add "italian"}
		{tags add "stug3g_ita"}
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

;_________________________________________________
;|               Aircraft                         |
;|________________________________________________|

{"sm79_para_plane"
	{on spawn
		{tags add "italian"}
		{tags add "german"}
		{tags add "drop_plane"}	
		{tags add "aircraft"}
		{tags add "ready_to_move"}		
	}
}
