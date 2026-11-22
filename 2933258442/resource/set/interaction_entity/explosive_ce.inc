
(define "barrage_delay_ce"
	{link_sound "click" "gui/pointer/"}
	{play_sound "click"}
	{delay %delay {spawn "%barrage"}}
)
(define "last_barrage_delay_ce"
	{delay %delay {spawn "%barrage"} {delay 1 {delete}}}
)

;// Shared radio-verify body. Two barrages: first at %first, last at %last.
(define "conquest_barrage_ce"
	{on spawn overload
		{tags add "_barrage_requested"}
	}
	{on "verify_radio_present"
		{if tagged "_rejected"
			{delay 3 {delete}}
		 else tagged "_accepted"
			("barrage_delay_ce" delay(%first) barrage(%barrage))
			("last_barrage_delay_ce" delay(%last) barrage(%barrage))
		}
	}
)

;// Smoke variant: click sound, single barrage at %last.
(define "conquest_smoke_barrage_ce"
	{on spawn overload
		{tags add "_barrage_requested"}
	}
	{on "verify_radio_present"
		{if tagged "_rejected"
			{delay 3 {delete}}
		 else tagged "_accepted"
			{link_sound "click" "gui/pointer/"}
			{play_sound "click"}
			("last_barrage_delay_ce" delay(%last) barrage(%barrage))
		}

		{tags remove "_accepted"}
		{tags remove "_rejected"}		
	}
)

;// Mortars
{"conquest_mortar_barrage_80"
	("conquest_barrage_ce" first(5) last(20) barrage(mortar_barrage_80))
}
{"conquest_mortar_barrage_120"
	("conquest_barrage_ce" first(5) last(20) barrage(mortar_barrage_120))
}

;// Smoke
{"conquest_smoke_barrage_88_eng"
	("conquest_smoke_barrage_ce" last(10) barrage(smoke_barrage_88_eng))
}
{"conquest_smoke_barrage_105_ger"
	("conquest_smoke_barrage_ce" last(10) barrage(smoke_barrage_105_ger))
}
{"conquest_smoke_barrage_105_usa"
	("conquest_smoke_barrage_ce" last(10) barrage(smoke_barrage_105_usa))
}
{"conquest_smoke_barrage_122_rus"
	("conquest_smoke_barrage_ce" last(10) barrage(smoke_barrage_122_rus))
}

;// Artillery
{"conquest_artillery_barrage_88_eng"
	("conquest_barrage_ce" first(15) last(40) barrage(artillery_barrage_88_eng))
}
{"conquest_artillery_barrage_105_ger"
	("conquest_barrage_ce" first(15) last(40) barrage(artillery_barrage_105_ger))
}
{"conquest_artillery_barrage_105_usa"
	("conquest_barrage_ce" first(15) last(40) barrage(artillery_barrage_105_usa))
}
{"conquest_artillery_barrage_122_rus"
	("conquest_barrage_ce" first(15) last(40) barrage(artillery_barrage_122_rus))
}
{"conquest_artillery_barrage_140_eng"
	("conquest_barrage_ce" first(20) last(45) barrage(artillery_barrage_140_eng))
}
{"conquest_artillery_barrage_150_ger"
	("conquest_barrage_ce" first(20) last(45) barrage(artillery_barrage_150_ger))
}
{"conquest_artillery_barrage_152_rus"
	("conquest_barrage_ce" first(20) last(45) barrage(artillery_barrage_152_rus))
}
{"conquest_artillery_barrage_155_fin"
	("conquest_barrage_ce" first(20) last(45) barrage(artillery_barrage_155_fin))
}
{"conquest_artillery_barrage_155_usa"
	("conquest_barrage_ce" first(20) last(45) barrage(artillery_barrage_155_usa))
}

;/*=========== Artillery Begin ==========*/
	{"offmap_dummy"
		(define "offmap_artillery_cannon_custom"
			{on spawn
				{start_sound "weapon/shot/ambient_cannon/"}
				{delay %0
					{start_sound "weapon/shot/mortar/whistle/"}
					{delay 1
						{start_sound "weapon/shot/artillery/"}
						{spawn %1 offset -250 0 %2}
						{hide 1}
					}
				}
			}
		)
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

;=====================Conquest Barrages=================

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


;======== AI Barrage ========

	{"flare_artillery"			;// Flare that spawns shells that fall to ground. Off-map artillery
		(define "show_flare_smoke"
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