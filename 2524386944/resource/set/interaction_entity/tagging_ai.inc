{"car"
	{on spawn
		{delay 0.2
			{if not user_control
			    {if not tagged "player_car"
				    {if not tagged "cmp_def"
				        {if not tagged "ger"
					        {if not tagged "rus"
						        {if not tagged "player_armor"
								    {if not tagged "player_veh"
									    {if operatable
									        {if not "hidden"
										        {tags add "ai_car"}
										    }
										}
									}
							    }
						    }
					    }
				    }
			    }
			}
	    }
	    {tags remove "test"}
	}
}

{"cannon"
	{on spawn
		{delay 0.1
			{if not user_control	
		    	{if operatable
				    {if tagged "cmp_mg" 
				        {tags add "no_scavenge"}
				    else tagged "cmp_def"
				    	{tags add "no_scavenge"}
					else 
				        {if not tagged "ger"
					        {if not tagged "rus"
						        {if not tagged "player_armor"
								    {if not tagged "player_veh"
								        {if not "hidden"
									        {tags add "ai_veh"}
									        {if tagged "artillery"
								        		{tags add "freeroam"}
								    		}
									    }
								    }
							    }
							}
						}
					} 			
				}
			}
		}
		{tags remove "test"}		           
	}
	{on "set_no_scavage"
		 {if not tagged "player_veh"
			{if operatable
			    {if tagged "cmp_mg" 
			        {tags add "no_scavenge"}
			    else tagged "cmp_def"
			    	{tags add "no_scavenge"}
				}
			}
		}
	}
}

{"truck"
	{on spawn
		{delay 0.2
			{if not user_control
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player_car"
									    {if operatable
									        {if not "hidden"
										        {tags add "ai_car"}
										    }
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	    {tags remove "test"} 
	}
}

{"halftrack"
	{on spawn
		{delay 0.2
			{if not user_control	    
		        {if not tagged "ger"
			        {if not tagged "rus"
				        {if not tagged "player_armor"
						    {if not tagged "player_veh"
							    {if not tagged "cmp_def"
								    {if operatable
								        {if not "hidden"
									        {tags add "ai_car"}
									    }
									}
								}									
							}
					    }
				    }
			    }
		    }
	    }
	    {tags remove "test"}
	}
}

{"tank"
	{on spawn
		{delay 0.2
			{if not user_control		    
		        {if not tagged "ger"
			        {if not tagged "rus"
				        {if not tagged "player_armor"
						    {if not tagged "player_veh"
							    {if not tagged "cmp_def"
								    {if operatable
								        {if not "hidden"
									        {tags add "ai_armor"}
									    }
									}
								}	
							}
					    }
				    }
			    }
		    }
	    }
	    {tags remove "test"}
	}
}

{"human"
	{on spawn
		{delay 0.1
			{if not user_control
				{if not linked 
					{if not "hidden"
						{if not tagged "player"
						    {if not tagged "cmp_def"
						        {if not tagged "ger"
							        {if not tagged "rus"
										{tags add "ai_inf"}
									}
								}		
							}
						}	
					}	
				}
			}
		}
		{tags remove "test"}
	}
}


