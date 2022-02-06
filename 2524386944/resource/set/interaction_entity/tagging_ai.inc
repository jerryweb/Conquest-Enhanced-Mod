{"car"
	{on spawn
	    {tags add "test"}
		{delay 30
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
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
	    }
	}
}

{"cannon"
	{on spawn
	    {tags add "test"}
		{delay 30
		    {if not tagged "player_veh"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {if operatable
										        {if not "hidden"
												    {if not tagged "cmp_mg"
											            {tags add "ai_veh"}
													}
											    }
											}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}

{"cannon"
	{on spawn
	    {tags add "test"}
		{delay 30
		    {if not tagged "player_veh"
			    {if tagged "cmp_def"
			        {if operatable
						{if tagged "cmp_mg"
						    {tags add "no_scavenge"}
						}
				    }
			    }
		   }
	    }
	}
}

{"cannon"
	{on spawn
	    {tags add "test"}
		{delay 30
		    {if not tagged "player_veh"
			    {if tagged "cmp_mg"
			        {tags add "no_scavenge"}
						
				}
		    }
	    }
	}
}

{"cannon"
	{on spawn
	    {tags add "test"}
		{delay 30
		    {if not tagged "player_veh"
			    {if tagged "cmp_def"
			        {tags add "no_scavenge"}
						
				}
		    }
	    }
	}
}

{"truck"
	{on spawn
	    {tags add "test"}
		{delay 30
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
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
	    }
	}
}

{"halftrack"
	{on spawn
	    {tags add "test"}
		{delay 30
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
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
	    }
	}
}

{"tank"
	{on spawn
	    {tags add "test"}
		{delay 30
		    {if not tagged "player_armor"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
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
		   }
	    }
	}
}

{"human"
	{on spawn
	    {tags add "test"}
		{delay 30
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {if operatable
										        {if not "hidden"
												    {if not linked
											            {tags add "ai_inf"}
													}
											    }
											}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}



