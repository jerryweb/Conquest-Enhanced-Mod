
;/*=========== Mines Begin ==========*/

{"mine"
	{inflammation_time 3}
	{on spawn
		{volumes "body1" disable all}
		{add_view "mined_view_own"		"mined_own"		"mined_view"}
		{add_view "mined_view_enemy"	"mined_enemy"	"mined_view"}
		{add_view "mined_view_defused"	"defused"		"mined_view"}
		{call "change_state"}
	}
	{on "explosion"
		{if mined
			{tags remove "mine_planted"}
			{volumes "body1" disable blast}
			{volumes "body" disable blast}
			{stuff_detonate}
		}
	}
	{on "change_state"
		{if mined
			{tags add "mine_planted"}
			{volumes "body1" disable all}
			{volumes "body" enable select touch contact contact_ground blast}
		else
			{delay 1.1
			    {spawn "pointer_mines"}
			}
			{tags remove "mine_planted"}
			{volumes "body" disable all}
			{volumes "body1" enable select touch contact contact_ground blast}
		    {delay 4.1
			    {view stop "mines"}
			}
		}
	}
	{on blast_hit
		{if mined
			{if min_energy 3
				{stuff_detonate}
			}
		else
			{if min_energy 0.8
				{stuff_detonate}
			}
		}
	}
	{on bullet_hit
		{if not mined
			{stuff_detonate}
		}
	}
}

{"mine antipersonnel"
	{on contact
		{if mine_effector "human"
			{call "explosion"}
		else mine_effector "vehicle"
			{call "explosion"}
		else mine_effector "animal"
			{call "explosion"}
		}
	}
}

{"mine antitank"
	{on contact
		{if mine_effector "mine_exploder"
			{delay 0
				{call "explosion"}
			}
		else mine_effector "vehicle"
			{if mined
				{volumes disable contact}
				{delay 0.20
					{call "explosion"}
				}
			}
		}
	}
}

{"mine bounding"
	{on contact overload
		{if mine_effector "human"
			{call "bound"}
		else mine_effector "vehicle"
			{call "explosion"}
		else mine_effector "animal"
			{call "bound"}
		}
	}
	{on "bound"
		{if mined
			{delete}
			{spawn "mine_s" "antipersonal_mine" x
				{link_sound "jump" "detonation/small/smine"}
				{play_sound "jump"}
				{physics_work 1}
				{volumes "body" disable all}
				{volumes "body1" disable all}
				{impulse up 5.5 0.1 com}
				{delay 0.5
					{stuff_detonate}
				}
			}
		}
	}
}

;/*=========== Mines End ==========*/

;/*=========== Explosive Charges Begin ==========*/

{"dynamite"
	{on "undermine"
		{tags add "fuse dynamite_planted"}
		{add_view "flash_fuse_small" "fire" "fire"}
		{view start "fire"}
		{ani_play "fire" 0.06}
		{delay 1
			{explosive 1}
		}
		{volumes disable touch select}
	}
	{on "onThrow"
		{if stuff_activated
			{tags add "fuse"}
			{add_view "flash_fuse_small" "fire" "fire"}
			{view start "fire"}
			{ani_play "fire" 0.06}
			{volumes disable touch select}
		}
	}
	{on blast
		{if min_energy 0.25
			{stuff_detonate}
		}
	}
	{on "explosion"
		{stuff_detonate}
	}
}

;/*=========== Explosive Charges End ==========*/

;/*=========== Bombs Begin ==========*/

{"air_bomb"
	{on "explosion"
		{stuff_detonate}
	}
	{on spawn
		{if air
			{ani_play "start"}
			{delay 1
				{volumes enable contact}
			}
		}
	}
	{on ground_hit
		{if min_speed 10
			{call "explosion"}
		}
	}
	{on contact
		{if min_speed 8
			{call "explosion"}
		}
	}
}

;/*=========== Bombs End ==========*/

;/*=========== Artillery Begin ==========*/

{"offmap_dummy"			;// Helper that spawns firing sounds and falling shells after delay
	(define "offmap"
		{on spawn
			{start_sound "weapon/shot/ambient_cannon"}
			{delay 5
				{start_sound "weapon/shot/mortar/whistle"}
				{delay 1
					{start_sound "weapon/shot/artillery"}
					{spawn %0 offset -250 0 1000}
					{hide 1}
				}
			}
		}
	)
}

{"offmap_dummy 105"
	("offmap" args "artillery_single_105")
}

{"offmap_dummy 150"
	("offmap" args "artillery_single_150")
}

{"artillery_shell"			;// Settings for all shells that fall to ground
	{on spawn
		{add_view "pfaust_tail" "trace" "tail"}
		{view start "trace"}
		{impulse up -75 forward 20 rnd_dir 3 com}
	}
	{on ground_hit
		{call "explosion"}
	}
	{on contact
		{call "explosion"}
	}
	{on "explosion"
		{stuff_detonate}
	}
}

{"artillery_barrage_105"
	{on spawn
		{if not tagged "fired"
			{tags add "fired"}
			(define "rnd_art_bomb"
				{delay %delay 0.5
					{spawn "artillery_single_105_dummy" random_position 550}
				}
			)
			("rnd_art_bomb" delay(0.5))
			("rnd_art_bomb" delay(1))
			("rnd_art_bomb" delay(1.5))
			("rnd_art_bomb" delay(2))
			("rnd_art_bomb" delay(2.5))
			("rnd_art_bomb" delay(3))
			("rnd_art_bomb" delay(3.5))
			("rnd_art_bomb" delay(4))

			("rnd_art_bomb" delay(13.5))
			("rnd_art_bomb" delay(14))
			("rnd_art_bomb" delay(14.5))
			("rnd_art_bomb" delay(15))
			("rnd_art_bomb" delay(15.5))
			("rnd_art_bomb" delay(16))
			("rnd_art_bomb" delay(16.5))
			("rnd_art_bomb" delay(17))
			{hide 18}
		}
	}
}

{"artillery_barrage_150"
	{on spawn
		{if not tagged "fired"
			{tags add "fired"}
			(define "rnd_art_bomb"
				{delay %delay 0.5
					{spawn "artillery_single_150_dummy" random_position 700}
				}
			)
			("rnd_art_bomb" delay(0.5))
			("rnd_art_bomb" delay(1))
			("rnd_art_bomb" delay(1.5))
			("rnd_art_bomb" delay(2))
			("rnd_art_bomb" delay(2.5))
			("rnd_art_bomb" delay(3))
			("rnd_art_bomb" delay(3.5))
			("rnd_art_bomb" delay(4))

			("rnd_art_bomb" delay(13.5))
			("rnd_art_bomb" delay(14))
			("rnd_art_bomb" delay(14.5))
			("rnd_art_bomb" delay(15))
			("rnd_art_bomb" delay(15.5))
			("rnd_art_bomb" delay(16))
			("rnd_art_bomb" delay(16.5))
			("rnd_art_bomb" delay(17))
			{hide 18}
		}
	}
}

{"flare_artillery"			;// Flare that spawns shells that fall to ground. Off-map artillery
	{on spawn
		{add_view "smoke_flare_red" "smoke" "root"}
		{view start "smoke"}
		{tags add "paradrophere"}
		{delay 50 {view stop "smoke"}}
		{delay 50 {delete}}
	}
}

{"offmap_mortar"			;// Spawns delayed explosion (fake mortar)
	{on spawn
		{start_sound "weapon/mortar/whistle"}
		{delay 1.5
			{stuff_detonate}
		}
	}
}

{"mortar_single_120_dummy"			;// Shells that fall to ground. Source Off-map artillery
	{on spawn 
		{start_sound "weapon/shot/ambient_cannon" ambient}
		{tags add "120"}
		{delay 7
			{start_sound "weapon/shot/artillery"}
			{spawn "mortar_single_120" offset -250 0 1000 random_position 300}
			{hide 1}
		}
	}
}

{"mortar_single_120_dummy2"			;// Shells that fall to ground. Source Off-map artillery
	{on spawn 
		{start_sound "weapon/mortar/whistle" ambient}
		{delay 5.1
		    {spawn "mortar_single_1202" offset -250 0 600}
		}
		{tags add "smoke"}
		{delay 5.1
			{spawn "shell_smoke" offset -500 0 -500 random_position 700}
			{spawn "shell_smoke" offset -500 0 -500 random_position 700}
			{spawn "shell_smoke" offset -500 0 -500 random_position 700}
			{spawn "shell_smoke" offset -500 25 -500 random_position 700}
			{spawn "shell_smoke" offset -500 77 -500 random_position 700}
			{spawn "shell_smoke" offset -500 33 -500 random_position 700}
			{spawn "shell_smoke" offset -500 0 -500 random_position 700}
			{spawn "shell_smoke" offset -500 0 -500  random_position 700}
			{spawn "shell_smoke" offset -500 0 -500  random_position 700}
			{spawn "shell_smoke" offset -500 0 -500  random_position 700}
			{spawn "shell_smoke" offset -500 25 -500  random_position 700}
			{spawn "shell_smoke" offset -500 77 -500  random_position 700}
			{spawn "shell_smoke" offset -500 33 -500  random_position 700}
			{spawn "shell_smoke" offset -500 0 -500  random_position 700}
			{spawn "shell_smoke" offset -500 0 -500 random_position 700}
			{spawn "shell_smoke" offset -500 0 -500 random_position 700}
			{spawn "shell_smoke" offset -500 0 -500 random_position 700}
			{spawn "shell_smoke" offset -500 25 -500 random_position 700}
			{spawn "shell_smoke" offset -500 77 -500 random_position 700}
			{spawn "shell_smoke" offset -500 33 -500 random_position 700}
			{spawn "shell_smoke" offset -500 0 -500 random_position 700}
			{spawn "shell_smoke" offset -500 0 -500  random_position 700}
			{spawn "shell_smoke" offset -500 0 -500  random_position 700}
			{spawn "shell_smoke" offset -500 0 -500  random_position 700}
			{spawn "shell_smoke" offset -500 25 -500  random_position 700}
			{spawn "shell_smoke" offset -500 77 -500  random_position 700}
			{spawn "shell_smoke" offset -500 33 -500  random_position 700}
			{spawn "shell_smoke" offset -500 0 -500  random_position 700}
			{hide 1}
		}
	}
}

{"mortar_barrage"			;// Flare that spawns timed explosions randomized in area
	{on spawn
		{if not tagged "fired"
			{tags add "fired"}
			(define "rnd_art_bomb"
				{delay %delay 0.5
					{spawn "mortar_single_120_dummy" random_position 350}
				}
			)
			("rnd_art_bomb" delay(2))
			("rnd_art_bomb" delay(4))
			("rnd_art_bomb" delay(6))
			("rnd_art_bomb" delay(8))
			("rnd_art_bomb" delay(10))
			("rnd_art_bomb" delay(12))
			("rnd_art_bomb" delay(14))
			("rnd_art_bomb" delay(16))
			("rnd_art_bomb" delay(18))

			{hide 19}
		}
	}
}

;/*=========== Artillery End ==========*/

;/*=========== Contaniers Begin ==========*/


{"explosive_barrel"			;// properties/barrel.ext
	{inflammation_time 5}
	{on break_armor
		{if name "pierce"
			{if stuff "bullet"
				{if stuff_filled "fuel" 20
					{call "explosion"}
				else stuff_filled "diesel" 20
					{call "explosion"}
				else stuff_filled "water" 20
					{burn fx "drops_water_small_short" fake}
				}
			
			else stuff "shell"
				{if stuff_filled "fuel" 20
					{call "explosion"}
				else stuff_filled "diesel" 20
					{call "explosion"}
				else 
					{call "break"}
				}
			}
		else name "blast"
			{call "break"}
		}
	}
	{on "burn"
		{call "break"}
	}
	{on "break"
		{if stuff_filled "fuel" 20
			{call "explosion"}
		else stuff_filled "diesel" 20
			{call "explosion"}
		else
			{spawn "car_die_particle"}
			{hide 0.3}
		}
	}
	{on "explosion"
		{if not tagged "explosioned"
			{tags add "explosioned"}
			{impulse up 9 5 dir 2 1 cx 0.6 0.5 cy 0.6 0.5 com}
			{blastwave c4 3 r0 4 r1 6}
			{fire radius 1.5 time 1.5 heating 5 effector}

			{spawn "barrel_die_big"}
			{spawn "car_die_particle"}
			{spawn "fire_shellhole"}

			{add_view "smoke_barrel" "smoke" "root"}
			{view start "smoke"}

			{delay 25
				{view stop "smoke"}
				{hide 1}
			}
		}
	}
	{on ground_hit
		{if tagged "explosioned"
			{blastwave c4 2 r0 4 r1 6}
			{spawn "fire_shellhole"}
			{spawn "car_die_particle"}
			{spawn "barrel_die" offset 0 0 7}
			{delete}
		}
	}
}

{"explosion"
	{on "explosion"
		{stuff_detonate}
	}
	{on spawn
		{call "explosion"}
	}
}

{"explosive_stuff"			;// props for bombs, rockets, mortars, and cannon shells
	{inflammation_time 10}
	{on "burn_volume"
		{if volume "body"
			{stuff_detonate}
		}
	}
	{on pierce
		{if rand 0.2
			{call_synced "stuff_detonated"}
		}
	}
	{on blast_hit
		{if min_energy 2
			{stuff_detonate}
		else min_energy 1
			{if rand 0.5
				{call_synced "stuff_detonated"}
			}
		}
	}
	{on "stuff_detonated"
		{stuff_detonate}
	}
}

;/*=========== Contaniers End ==========*/

;/*=========== Special Begin ==========*/

{"smoke activate"			;// ammo for vehicle smoke lauchers (50mm mortar smoke) that is not a grenade. Arms entity for detation specifically when launched from vehicle.
	{on "activate"			;// called via spawn through tank-main on "smoke_screen" event
		{tags add "activated"}
		{volumes "body" disable contact}
		{delay 0.1
			{volumes "body" enable contact}
		}
	}
	{on ground_hit
		{if tagged "activated"
			{stuff_detonate}
		}
	}
	{on contact
		{if tagged "activated"
			{stuff_detonate}
		}
	}
}

;/*=========== Special End ==========*/