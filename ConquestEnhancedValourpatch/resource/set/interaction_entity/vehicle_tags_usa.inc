{"willys_com"
	{on spawn
    	{if not tagged "radiorus"
		    {tags add "radio_car"}
		}
		{tags add "american"}
		{tags add "willys_com"}
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