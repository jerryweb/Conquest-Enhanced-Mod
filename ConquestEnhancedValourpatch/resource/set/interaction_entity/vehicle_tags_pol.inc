{"pf508"
	{on spawn
    	{if not tagged "radiorus"
		    {tags add "radio_car"}
		}
		{tags add "polish"}
		{tags add "pf508"}
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
{"303_bren_pol"
	{on spawn
	    {tags add "HMG"}
		{tags add "polish"}
		{tags add "303_bren_pol"}
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
{"qf40mm_pol"
	{on spawn
	    {tags add "AAFLAK"}
		{tags add "polish"}
		{tags add "qf40mm_pol"}
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
{"qf2pdr_pol"
	{on spawn
	    {tags add "light_at_gun"}
		{tags add "polish"}
		{tags add "qf2pdr_pol"}
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
{"qf6pdr_pol"
	{on spawn
	    {tags add "medium_at_gun"}
		{tags add "polish"}
		{tags add "qf6pdr_pol"}
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
{"qf17pdr_pol"
	{on spawn
	    {tags add "heavy_at_gun"}
		{tags add "polish"}
		{tags add "qf17pdr_pol"}
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
{"81mm_brandt_pol"
	{on spawn
    	{tags add "artillery"}
		{tags add "polish"}
		{tags add "81mm_brandt_pol"}
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
{"qf25pdr_pol"
	{on spawn
    	{tags add "artillery"}
		{tags add "polish"}
		{tags add "qf25pdr_pol"}
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
{"bl45_pol"
	{on spawn
    	{tags add "artillery"}
		{tags add "polish"}
		{tags add "bl45_pol"}
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


{"bedford_ql_inf"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "polish"}
		{tags add "bedford_ql_inf"}
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
{"bedford_ql_art"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "polish"}
		{tags add "bedford_ql_art"}
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
{"bedford_ql_eng"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "polish"}
		{tags add "bedford_ql_eng"}
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
{"dingo_pol"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "polish"}
		{tags add "dingo_pol"}
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
{"m3halftrack_pol"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "polish"}
		{tags add "m3halftrack_pol"}
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
{"staghound_pol"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "polish"}
		{tags add "staghound_pol"}
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
{"crusader_aa2_pol"
	{on spawn
    	{tags add "light_tank"}
		{tags add "polish"}
		{tags add "crusader_aa2_pol"}
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
{"crusader_pol"
	{on spawn
    	{tags add "light_tank"}
		{tags add "polish"}
		{tags add "crusader_pol"}
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
{"cromwell_mk_iv_pol"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "polish"}
		{tags add "cromwell_mk_iv_pol"}
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
{"m4a4_pol"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "polish"}
		{tags add "m4a4_pol"}
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
{"challenger_pol"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "polish"}
		{tags add "challenger_pol"}
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
{"m4a4_firefly_pol"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "polish"}
		{tags add "m4a4_firefly_pol"}
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
{"achilles_pol"
	{on spawn
    	{tags add "spg"}
		{tags add "polish"}
		{tags add "achilles_pol"}
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
{"m4a3_105_pol"
	{on spawn
    	{tags add "spg"}
		{tags add "polish"}
		{tags add "m4a3_105_pol"}
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
{"sexton_pol"
	{on spawn
    	{tags add "spg"}
		{tags add "polish"}
		{tags add "sexton_pol"}
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
