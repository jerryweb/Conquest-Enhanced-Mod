;/*=========== Artillery Begin ==========*/
	{"offmap_dummy"
		(define "offmap_rocket"
			{on spawn
				{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
				{play_sound "bkg_rocket"}
				{delay 8
					{start_sound "bkg_rocket"}
					{spawn %0 offset -250 0 1000}
					{hide 1}
				}
			}
		)

		(define "offmap_artillery_cannon_custom"
			{on spawn
				{start_sound "weapon/shot/ambient_cannon"}
				{delay %0
					{start_sound "weapon/shot/mortar/whistle"}
					{delay 1
						{start_sound "weapon/shot/artillery"}
						;{spawn %1 offset -250 0 1000}
						{spawn %1 offset -250 0 %2}
						{hide 1}
					}
				}
			}
		)
	}

	{"offmap_dummy rocket 132"
		("offmap_rocket" args "artillery_single_rocket_132")
	}

	{"offmap_dummy rocket 300"
		("offmap_rocket" args "artillery_single_rocket_300")
	}

	{"offmap_dummy 600"
		("offmap_artillery_cannon_custom" args 10 "artillery_single_600" 2000)
	}


;======================================

	(define "ce_light_barrage"
		{on spawn overload
			{if not tagged "fired"
				{tags add "fired"}
	
				("rnd_art_bomb" delay(0.5) shell(%shell) postion(%postion))
				("rnd_art_bomb" delay(2)   shell(%shell) postion(%postion))
				("rnd_art_bomb" delay(2.5) shell(%shell) postion(%postion))
				("rnd_art_bomb" delay(3.0) shell(%shell) postion(%postion))
				("rnd_art_bomb" delay(4.5) shell(%shell) postion(%postion))
				("rnd_art_bomb" delay(6.0) shell(%shell) postion(%postion))
				("rnd_art_bomb" delay(6.1) shell(%shell) postion(%postion))
				("rnd_art_bomb" delay(6.3) shell(%shell) postion(%postion))
				("rnd_art_bomb" delay(6.5) shell(%shell) postion(%postion))
				
				("rnd_art_bomb" delay(9.2) shell(%shell) postion(%postion))
				("rnd_art_bomb" delay(9.4) shell(%shell) postion(%postion))
				("rnd_art_bomb" delay(9.6) shell(%shell) postion(%postion))
				("rnd_art_bomb" delay(9.7) shell(%shell) postion(%postion))
				
				("rnd_art_bomb" delay(13.0) shell(%shell) postion(%postion))
				("rnd_art_bomb" delay(13.5) shell(%shell) postion(%postion))
				("rnd_art_bomb" delay(14.0) shell(%shell) postion(%postion))
				("rnd_art_bomb" delay(14.5) shell(%shell) postion(%postion))
				("rnd_art_bomb" delay(15.0) shell(%shell) postion(%postion))
				("rnd_art_bomb" delay(15.5) shell(%shell) postion(%postion))
	
				{hide 18}
			}
		}
	)

	(define "ce_heavy_barrage"
		;{on spawn
			{if not tagged "fired"
				{tags add "fired"}
	
				("rnd_art_bomb" delay(0.5) 	shell(%shell) postion(%postion))
				("rnd_art_bomb" delay(1) 	shell(%shell) postion(%postion))
				("rnd_art_bomb" delay(1.5) 	shell(%shell) postion(%postion))
				("rnd_art_bomb" delay(2) 	shell(%shell) postion(%postion))
				("rnd_art_bomb" delay(2.5) 	shell(%shell) postion(%postion))
				("rnd_art_bomb" delay(3) 	shell(%shell) postion(%postion))
				("rnd_art_bomb" delay(3.5) 	shell(%shell) postion(%postion))
				("rnd_art_bomb" delay(4) 	shell(%shell) postion(%postion))
	
				("rnd_art_bomb" delay(10) 	shell(%shell) postion(%postion))
				("rnd_art_bomb" delay(10.5)	shell(%shell) postion(%postion))
				("rnd_art_bomb" delay(11) 	shell(%shell) postion(%postion))
				{hide 13}
			}
		;}
	)

	{"artillery_barrage_180"
		{on spawn
			("ce_heavy_barrage" shell(artillery_single_180_dummy) postion(1200))
		}
	}

	{"artillery_barrage_600"
		{on spawn
			{delay 30
				("rnd_art_bomb" delay(0) shell(artillery_single_600_dummy) postion(500))
				{hide 5}
			}
		}
	}

	{"light_rocket_barrage"
		("ce_light_barrage" shell(artillery_single_152_rus_dummy) postion(1200))
	}

	{"heavy_rocket_barrage"
		{on spawn 
			("ce_heavy_barrage" shell(artillery_single_rocket_300_dummy) postion(1000))
		}
	}

;=====================Conquest Barrages=================

	{"conquest_smoke_barrage_105_ger"
		{on spawn overload
			("barrage_delay" delay(15) barrage(smoke_barrage_105_ger))
			("last_barrage_delay" delay(25) barrage(smoke_barrage_105_ger))
		}
	}

	{"conquest_smoke_barrage_122_rus"
		{on spawn overload
			("barrage_delay" delay(15) barrage(smoke_barrage_122_rus))
			("last_barrage_delay" delay(25) barrage(smoke_barrage_122_rus))
		}
	}

	{"conquest_artillery_barrage_heavy"
		{on spawn 
			("barrage_delay" delay(30) barrage(artillery_barrage_180))
			{delay 50
				{delete}
			}
		}
	}

	{"conquest_artillery_barrage_super_heavy"
		{on spawn 
			("barrage_delay" delay(0) barrage(artillery_barrage_600))
			{delay 50
				{delete}
			}
		}
	}

	{"conquest_light_rocket_barrage"
		{on spawn 
			("barrage_delay" delay(15) barrage(light_rocket_barrage))
			{delay 50
				{delete}
			}
		}
	}

	{"conquest_heavy_rocket_barrage"
		{on spawn 
			("barrage_delay" delay(15) barrage(heavy_rocket_barrage))
			{delay 50
				{delete}
			}
		}
	}

;======== AI Barrage ========

	{"flare_artillery"			;// Flare that spawns shells that fall to ground. Off-map artillery
		(define "show_flare_smoke"
			;{add_view "smoke_flare_red" "smoke" "root"}
			{add_view %color "smoke" "root"}
			{view start "smoke"}
			{delay 30 {view stop "smoke"}}
			{delay 50 {delete}}
		)

		{on spawn overload
			{delay 2.5
				{tags add "flare_artillery"}
			}
			{if rand 0.2
				;orange
				("show_flare_smoke" color("smoke_flare_orange"))
	            {delay 2.5
	            	{tags add "medium_artillery_barrage"}
	            	{delay 20
	            		{spawn "artillery_barrage_150_ger"}
	            		;{delay 20
	            		;	{spawn "artillery_barrage_150_ger"}
	            		;}
	            	}
				}
	        else rand 0.2
	        	;red
	        	("show_flare_smoke" color("smoke_flare_red"))
	            {delay 2.5
	            	{tags add "heavy_artillery_barrage"}
	            	{delay 30
	            		{spawn "artillery_barrage_180"}
	            	}
				}
	        else rand 0.2
	        	;blue
	        	("show_flare_smoke" color("smoke_flare_blue"))
	            {delay 2.5
	            	{tags add "smoke_barrage"}
	            	{delay 20
						{spawn "smoke_barrage_105_ger"}
	            		{delay 20
	            			{spawn "smoke_barrage_105_ger"}
	            		}
					}
				}
	        else rand 0.2
	        	;light purple
	        	("show_flare_smoke" color("smoke_flare_light_purple"))
	            {delay 2.5
	            	{tags add "light_rocket_barrage"}
	            	{delay 15
						{spawn "light_rocket_barrage"}
					}
				}
	        else rand 0.2
	        	;purple
	        	("show_flare_smoke" color("smoke_flare_purple"))
	            {delay 2.5
	            	{tags add "heavy_rocket_barrage"}
	            	{delay 15
						{spawn "heavy_rocket_barrage"}
					}
				}
	        else rand 0.2
	        	;dark red
	        	("show_flare_smoke" color("smoke_flare_dark_red"))
	            {delay 2.5
	            	{tags add "super_heavy_artillery_barrage"}
	            	;// this entity already has a 30 second delay before spawning the actual entity
					{spawn "artillery_barrage_600"
						{delay 34
							{tags add "super_heavy_arty_fired"}
						}
					}
				}
	        else 
	        	;light red
	            ("show_flare_smoke" color("smoke_flare_light_red"))
	            {delay 2.5
	            	{tags add "light_artillery_barrage"}
					{delay 15
						{spawn "artillery_barrage_105_ger"}
	            		;{delay 15
	            		;	{spawn "artillery_barrage_105_ger"}
	            		;}
					}
				}
	        }
	        {spawn "artillery_warning_heavy"}	
            {delay 5 {spawn "artillery_warning_heavy"}}  
		}

		{on "acknowledge_flare_artillery"
			{tags add "acknowledged"}
		}
	}