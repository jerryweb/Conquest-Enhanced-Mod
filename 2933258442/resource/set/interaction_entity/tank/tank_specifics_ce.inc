; ===== Radio Vehicle Tagging ========================================
{"ho_ha_radio" 
        {on spawn
            {delay 0.2
                {if work "body"
                    ("tag_veh" args "radio_car")
                }
            }
        }
    }
    
	{"sdkfz250a_3" 
		{on spawn
			{delay 0.2
				{if work "body"
					("tag_veh" args "radio_car")
				}
			}
		}
	}

	{"ba20_command" 
		{on spawn
			{delay 0.2
				{if work "body"
					("tag_veh" args "radio_car")
				}
			}
		}
	}

	{"ba20_command_fin" 
		{on spawn
			{delay 0.2
				{if work "body"
					("tag_veh" args "radio_car")
				}
			}
		}
	}

    {"armored_command" 
		{on spawn
			{delay 0.2
				{if work "body"
					("tag_veh" args "radio_car")
				}
			}
		}
	}
    
    {"m3a1_halftrack_radio" 
		{on spawn
			{delay 0.2
				{if work "body"
					("tag_veh" args "radio_car")
				}
			}
		}
	}
    
    {"blitz3_6_radio"
        {on spawn
            {delay 0.2
                {chassis_work 0}
                {tags add "radio_car"}
                
            }
            {delay 0.5
                {chassis_work 0}                
                {able "select" 1}
            }
        }
    }
; ===== Radio Vehicle Tagging End ====================================

;/*=========== Specific Vehicle Logic Begin ===========*/    
	{"marder3m tank"
	    ("pz38_sound")
	    {on "spawn_shell_delay" overload
	        ("shell_eject_delay" args 0.15 0.25)
	    }
	}

	{"sdkfz303b"
        {on spawn
            {delay 10
                {able "select" 1}
                {drop_orders}
            }
        }
    }

	{"sdkfz251c"
	    {on pierce
	        {if not user_control
	           {if not linked
	               {delay 1
	                    {crew_emit}
	                }
	            }
	        }
	    }
	}

	{"t27" 
		{on "hull_down"
			{delay 8
		   	    {spawn "sandbag_heap_straight" offset 110 40 0}
		   	    {spawn "sandbag_heap_straight" offset 110 -40 0}
		   	    {delay 2
					{spawn "sandbag_heap_pile" offset 100 -100 0}
					{delay 2
				   	    {spawn "sandbag_heap_straight_90" offset 40 -110 0}
				   	    {spawn "sandbag_heap_straight_90" offset -40 -110 0}
				   	    {delay 2
							{spawn "sandbag_heap_pile" offset -100 -100 0}
							{delay 2
								{spawn "sandbag_heap_straight" offset -110 40 0}
		   	    				{spawn "sandbag_heap_straight" offset -110 -40 0}
		   	    				{delay 2
				   	    			{spawn "sandbag_heap_straight_90" offset 40 110 0}
				   	    			{spawn "sandbag_heap_straight_90" offset -40 110 0}
				   	    			{delay 2
										{spawn "sandbag_heap_pile" offset 100 100 0}
									}
				   	    		}
							}
						}
				   	}
				}
		   	}
		}
	}

	{"panzerb2" 
		{on "hull_down"
			{delay 8
		   	    {spawn "sandbag_heap_straight" offset 110 40 0}
		   	    {spawn "sandbag_heap_straight" offset 110 -40 0}
		   	    {delay 2
					{spawn "sandbag_heap_pile" offset 100 -100 0}
					{delay 2
				   	    {spawn "sandbag_heap_straight_90" offset 40 -110 0}
				   	    {spawn "sandbag_heap_straight_90" offset -40 -110 0}
				   	    {delay 2
							{spawn "sandbag_heap_pile" offset -100 -100 0}
							{delay 2
								{spawn "sandbag_heap_straight" offset -110 40 0}
		   	    				{spawn "sandbag_heap_straight" offset -110 -40 0}
		   	    				{delay 2
			   	    			{spawn "sandbag_heap_straight_90" offset 40 110 0}
			   	    			{spawn "sandbag_heap_straight_90" offset -40 110 0}
			   	    			{delay 2
									{spawn "sandbag_heap_pile" offset 100 100 0}
								}
				   	    		}
							}
						}
				   	}
				}
		   	}
		}
	}
;/*=========== Specific Vehicle Logic End ===========*/    

;/*=========== minesweeper Vehicles Begin ===========*/

	{"t34m tank"
		("t34_sound")
		{on "add_weapon_sound" overload
			("DT")
		}
	}
	
	{"m4a3m tank"
		("m4a2_sherman_sound")
	}
	
	{"pz3m tank"
		("pz3_sound")
		{on "add_weapon_sound" overload
			("MG34")
		}
	}

;/*=========== minesweeper Vehicles End ===========*/

;============================TDs and SPGs ============================
	; grille_k and bison
	{"spg light -turret muzzle_150mm_155mm"
	    {on fire "gun"
	        {if not user_control
	            {if tagged "bot_tank"
	                {call "engine_off"}
	                {delay 25
	                    {if operatable
	                        {if not user_control
	                            {if tagged "bot_tank"  
	                                {if not "engine_on"
	                                    {call "engine_on"}
	                                }
	                            }
	                        }
	                    }  
	                }
	            }
	        }
	    }
	}

	; sig33 and sturmpanzer 4
	{"spg medium -turret muzzle_122mm_128mm vision_lev05"
	    {on fire "gun"
	        {if not user_control
	            {if tagged "bot_tank"
	                {call "engine_off"}
	                {delay 25
	                    {if operatable
	                        {if not user_control
	                            {if tagged "bot_tank"  
	                                {if not "engine_on"
	                                    {call "engine_on"}
	                                }
	                            }
	                        }
	                    }  
	                }
	            }
	        }
	    }
	}

	{"jagdtiger"
	    {on fire "gun"
	        {if not user_control
	            {if tagged "bot_tank"
	                {call "engine_off"}
	                {delay 16
	                    {if operatable
	                        {if not user_control
	                            {if tagged "bot_tank"  
	                                {if not "engine_on"
	                                    {call "engine_on"}
	                                }
	                            }
	                        }
	                    }  
	                }
	            }
	        }
	    }
	}

	{"sturmtiger"
	    {on fire "gun"
	        {if not user_control
	            {if tagged "bot_tank"
	                {call "engine_off"}
	                {delay 85
	                    {if operatable
	                        {if not user_control
	                            {if tagged "bot_tank"  
	                                {if not "engine_on"
	                                    {call "engine_on"}
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
	    {on fire "gun"
	        {if not user_control
	            {if tagged "bot_tank"
	                {call "engine_off"}
	                {delay 15
	                    {if operatable
	                        {if not user_control
	                            {if tagged "bot_tank"  
	                                {if not "engine_on"
	                                    {call "engine_on"}
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
	    {on fire "gun"
	        {if not user_control
	            {if tagged "bot_tank"
	                {call "engine_off"}
	                {delay 15
	                    {if operatable
	                        {if not user_control
	                            {if tagged "bot_tank"  
	                                {if not "engine_on"
	                                    {call "engine_on"}
	                                }
	                            }
	                        }
	                    }  
	                }
	            }
	        }
	    }
	}

	; su152 and isu152
	{"td heavy -turret muzzle_150mm_155mm_sides"
	    {on fire "gun"
	        {if not user_control
	            {if tagged "bot_tank"
	                {call "engine_off"}
	                {delay 30
	                    {if operatable
	                        {if not user_control
	                            {if tagged "bot_tank"  
	                                {if not "engine_on"
	                                    {call "engine_on"}
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
	    {on fire "gun"
	        {if not user_control
	            {if tagged "bot_tank"
	                {call "engine_off"}
	                {delay 25
	                    {if operatable
	                        {if not user_control
	                            {if tagged "bot_tank"  
	                                {if not "engine_on"
	                                    {call "engine_on"}
	                                }
	                            }
	                        }
	                    }  
	                }
	            }
	        }
	    }
	}

	{"hetzer" 
	{on "hull_down"
		{delay 8
	   	    {spawn "sandbag_heap_straight" offset 110 40 0}
	   	    {spawn "sandbag_heap_straight" offset 110 -40 0}
	   	    {delay 2
				{spawn "sandbag_heap_pile" offset 100 -100 0}
				{delay 2
			   	    {spawn "sandbag_heap_straight_90" offset 40 -110 0}
			   	    {spawn "sandbag_heap_straight_90" offset -40 -110 0}
			   	    {delay 2
						{spawn "sandbag_heap_pile" offset -100 -100 0}
						{delay 2
							{spawn "sandbag_heap_straight" offset -110 40 0}
	   	    				{spawn "sandbag_heap_straight" offset -110 -40 0}
	   	    				{delay 2
			   	    			{spawn "sandbag_heap_straight_90" offset 40 110 0}
			   	    			{spawn "sandbag_heap_straight_90" offset -40 110 0}
			   	    			{delay 2
									{spawn "sandbag_heap_pile" offset 100 100 0}
								}
			   	    		}
						}
					}
			   	}
			}
	   	}
	}
	}
; ===== Artillery ===== 
	{"pz38h_w40" 
		{on spawn
			{delay 1
				{call "tag_rocket_artillery"}
			}
		}
	}

	{"150mm_sig33" 
		{on spawn
			{delay 1
				{tags remove "artillery"}
				{tags remove "heavy_artillery"}
			}
		}
	}


	{"m4a3_calliope" 
		{on spawn
			{delay 1
				{call "tag_rocket_artillery"}
			}
		}
	}

	{"m7b1_hmc" 
		{on spawn
			{delay 1
				{tags add "artillery"}
			}
		}
	}

	{"m7_hmc" 
		{on spawn
			{delay 1
				{tags add "artillery"}
			}
		}
	}
;=====================================================================
; ===== Supply Vehicles ===== 
	{"ammo_crate"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}

	{"ford_3ton_ammo"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}
	{"ford_v3000_ammo"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}

	{"blitz3_6_art_ammo"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}
	{"opel_maultier"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}
	{"ammo_trailer"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}

	{"gaz_aaa_supply"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}
	{"ap_2"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}
	{"c_supply"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}
	{"cckw_art_ammo"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}
	{"cckw_redball"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}

	; ====== MACE ======
	{"gmc_ammo"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}
	{"stud_ammo"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}