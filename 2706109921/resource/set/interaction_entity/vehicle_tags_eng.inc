{"morris_cs8"
	{on spawn
    	{if not tagged "radiorus"
		    {tags add "radio_car"}
		}
		{tags add "english"}
		{tags add "morris_cs8"}
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
{"303_bren"
	{on spawn
	    {tags add "HMG"}
		{tags add "english"}
		{tags add "303_bren"}
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
{"qf40mm"
	{on spawn
	    {tags add "AAFLAK"}
		{tags add "english"}
		{tags add "qf40mm"}
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
{"qf3,7inch"
	{on spawn
	    {tags add "AAFLAK"}
		{tags add "english"}
		{tags add "qf3,7inch"}
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
{"qf2pdr"
	{on spawn
	    {tags add "light_at_gun"}
		{tags add "english"}
		{tags add "qf2pdr"}
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
{"qf6pdr"
	{on spawn
	    {tags add "medium_at_gun"}
		{tags add "english"}
		{tags add "qf6pdr"}
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
{"qf17pdr"
	{on spawn
	    {tags add "heavy_at_gun"}
		{tags add "english"}
		{tags add "qf17pdr"}
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
{"76mm_mk_ii"
	{on spawn
    	{tags add "artillery"}
		{tags add "english"}
		{tags add "76mm_mk_ii"}
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
{"qf25pdr"
	{on spawn
    	{tags add "artillery"}
		{tags add "english"}
		{tags add "qf25pdr"}
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
{"bl45"
	{on spawn
    	{tags add "artillery"}
		{tags add "english"}
		{tags add "bl45"}
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
{"bl72"
	{on spawn
    	{tags add "artillery"}
		{tags add "english"}
		{tags add "bl72"}
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
{"land_mattress"
	{on spawn
    		{tags add "rocket_artillery"}
		{tags add "english"}
		{tags add "land_mattress"}
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


{"matador"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "english"}
		{tags add "matador"}
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
{"matador_art"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "english"}
		{tags add "matador_art"}
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
{"matador_eng"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "english"}
		{tags add "matador_eng"}
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
{"matador_fuel"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "english"}
		{tags add "matador_fuel"}
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
{"dingo"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "english"}
		{tags add "dingo"}
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
{"m3halftrack_eng"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "english"}
		{tags add "m3halftrack_eng"}
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
{"humber"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "english"}
		{tags add "humber"}
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
{"mk2daimler"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "english"}
		{tags add "mk2daimler"}
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
{"staghound"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "english"}
		{tags add "staghound"}
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

;_________________________________________________
;|        Main Battle Tanks and SPGs              |
;|________________________________________________|

;LIGHT
{"crusader_aa2"
	{on spawn
    	{tags add "light_tank"}
		{tags add "english"}
		{tags add "crusader_aa2"}
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
{"crusader_mk6"
	{on spawn
    	{tags add "light_tank"}
		{tags add "english"}
		{tags add "crusader_mk6"}
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
{"valentine_mkiii"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "english"}
		{tags add "valentine_mkiii"}
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
{"matilda_mkii"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "english"}
		{tags add "matilda_mkii"}
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
{"cromwell_mk_iv"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "english"}
		{tags add "cromwell_mk_iv"}
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
{"m4a4"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "english"}
		{tags add "m4a4"}
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
{"cromwell_mk_vi"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "english"}
		{tags add "cromwell_mk_vi"}
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
{"comet_a34"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "english"}
		{tags add "comet_a34"}
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
{"challenger_a30"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "english"}
		{tags add "challenger_a30"}
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
{"m4a4_firefly"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "english"}
		{tags add "m4a4_firefly"}
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
		{tags add "english"}
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
{"churchill_mk_ii"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "english"}
		{tags add "churchill_mk_ii"}
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
{"churchill_avre"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "english"}
		{tags add "churchill_avre"}
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
{"churchill_mk_iv"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "english"}
		{tags add "churchill_mk_iv"}
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
{"churchill_mk_vii"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "english"}
		{tags add "churchill_mk_vii"}
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
{"churchill_crocodile"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "english"}
		{tags add "churchill_crocodile"}
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
{"achilles"
	{on spawn
    	{tags add "spg"}
		{tags add "english"}
		{tags add "achilles"}
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
{"m4a3_105_eng"
	{on spawn
    	{tags add "spg"}
		{tags add "english"}
		{tags add "m4a3_105_eng"}
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
{"sexton"
	{on spawn
    	{tags add "spg"}
		{tags add "english"}
		{tags add "sexton"}
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
