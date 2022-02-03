{"airborne"
	{on "engine_full_para_fix"
		{delay 2.5 "engine_full"			;// delay for accelerate sound
			{if not destroyed "engine1"
				{play_sound "engine1_full" 1}
				{play_sound "bkg_plane" 1}
				{stop_sound "engine1_idle"}
			}
			{if not destroyed "engine2"
				{play_sound "engine2_full" 1}
				{play_sound "bkg_plane" 1}
				{stop_sound "engine2_idle"}
			}
		}
	}
}


{"bf110_para_plane"
	("bf110_sound")

	{on fire "gun" overload
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{delay 0.42
					{view pause "flashbarrel%0"}
				}
		)

		{if ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		}
	}

	{on "engine_count" overload
		{tags add "engine_count_2"}
	}

	{on "engine_start_sequence" overload
		{inherited}
		{if work "engine1"
			{delay 4.5 0.5
				{call "engine2_start_sequence"}
			}
		else
			{call "engine2_start_sequence"}
		}
	}

	{on "engine1_stop_sequence" overload
		{inherited}
		{if not "engine_on"
			{call "engine2_stop_sequence"}
		}
	}

	{on "air_attack"
		{play_sound "attack"}
	}

	{on "die"
		{bone hide "bomb00"}
		{bone hide "bomb01"}
		{bone hide "bomb02"}
		{bone hide "bomb03"}
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
	}

	{on "tear_part"
		{if volume "wingr2"
			{bone hide "bomb02"}
			{bone hide "bomb03"}
		else volume "wingl2"
			{bone hide "bomb00"}
			{bone hide "bomb01"}
		}
	}
}

{"il2_mod42_para_plane"
	("il2_sound")

	{on spawn
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
	}
	{on fire "gun" overload
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{delay 0.42
					{view pause "flashbarrel%0"}
				}
		)

		{if ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		}
	}

	{on fire "rocket" overload
		{play_sound "bkg_rocket"}
	}
	{on "die"
		{bone hide "rocket00"}
		{bone hide "rocket02"}
		{bone hide "rocket04"}
		{bone hide "rocket06"}
		{bone hide "rocket01"}
		{bone hide "rocket03"}
		{bone hide "rocket05"}
		{bone hide "rocket07"}
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
	}

	{on "tear_part"
		{if volume "wingr2"
			{bone hide "rocket00"}
			{bone hide "rocket02"}
			{bone hide "rocket04"}
			{bone hide "rocket06"}
		else volume "wingl2"
			{bone hide "rocket01"}
			{bone hide "rocket03"}
			{bone hide "rocket05"}
			{bone hide "rocket07"}
		}
	}
}

{"b25_para_plane"
	{on spawn
		{add_view "flash_zenit"	"flashbarrel1m00"	"shooter1m_00"}
		{add_view "flash_zenit"	"flashbarrel1m01"	"shooter1m_01"}
		{add_view "flash_zenit"	"flashbarrel1m02"	"shooter1m_02"}
		{add_view "flash_zenit"	"flashbarrel1m03"	"shooter1m_03"}
		{add_view "flash_zenit"	"flashbarrel2m00"	"shooter2m_00"}
		{add_view "flash_zenit"	"flashbarrel2m01"	"shooter2m_01"}
		{add_view "flash_zenit"	"flashbarrel3m00"	"shooter3m_00"}
		{add_view "flash_zenit"	"flashbarrel3m01"	"shooter3m_01"}
		{add_view "flash_zenit"	"flashbarrel4"	"foresight7"}
		{add_view "flash_zenit"	"flashbarrel5"	"foresight8"}
	}
	("bf110_sound")
	{on fire "mgun1"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel1m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel1m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
                                      else ("fire_barrel" args 03)
		}
	}
	{on fire "mgun2"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel2m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel2m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun3"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel3m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel3m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun4"
		{view start "flashbarrel4"}
		{delay 0.5
			{view pause "flashbarrel4"}
		}
	}
	{on fire "mgun5"
		{view start "flashbarrel5"}
		{delay 0.5
			{view pause "flashbarrel5"}
		}
	}
}

{"beaufighter_para_plane"
	{on spawn
		{add_view	 "flash_zenit"	"flashbarrel_g00"	"shooter_g00"}
		{add_view	 "flash_zenit"	"flashbarrel_g01"	"shooter_g01"}
		{add_view	 "flash_zenit"	"flashbarrel_g02"	"shooter_g02"}
		{add_view	 "flash_zenit"	"flashbarrel_g03"	"shooter_g03"}
		{add_view "light_flash_zenit"	"flashbarrel_m00"	"shooter_m00"}
		{add_view "light_flash_zenit"	"flashbarrel_m01"	"shooter_m01"}
		{add_view "light_flash_zenit"	"flashbarrel_m02"	"shooter_m02"}
		{add_view "light_flash_zenit"	"flashbarrel_m03"	"shooter_m03"}
		{add_view "light_flash_zenit"	"flashbarrel_m04"	"shooter_m04"}
		{add_view "light_flash_zenit"	"flashbarrel_m05"	"shooter_m05"}
	}
	("bf110_sound")
	{on fire "zenite"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel_g%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel_g%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		}
	}
	{on fire "mgun1"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel_m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel_m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		  else ("fire_barrel" args 04)
  		  else ("fire_barrel" args 05)
		}
	}
}

{"sm79_para_plane"
	("bf110_sound")
}

{"j2m_raiden_para_plane"
	{on spawn
		{add_view "flash_zenit"	"flashbarrel00"	"shooter00"}
		{add_view "flash_zenit"	"flashbarrel01"	"shooter01"}
		{add_view "flash_zenit"	"flashbarrel02"	"shooter02"}
		{add_view "flash_zenit"	"flashbarrel03"	"shooter03"}
	}
	{on fire "zenite"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		}
	}
	{on fire "bomb" 
		{if not tagged "bombrunout"
			{if not tagged "bomb1"
				{tags add "bomb1"}
				{bone hide "rocket00"}
			else not tagged "bomb2"
				{tags add "bomb2"}
				{bone hide "rocket01"}
			else not tagged "bomb3"
				{tags add "bomb3"}
				{bone hide "rocket02"}
			else not tagged "bomb4"
				{tags add "bomb4"}
				{bone hide "rocket03"}
			else not tagged "bomb5"
				{tags add "bomb5"}
				{bone hide "rocket04"}
			else not tagged "bomb6"
				{tags add "bomb6"}
				{bone hide "rocket05"}
			else not tagged "bomb7"
				{tags add "bomb7"}
				{bone hide "rocket06"}
			else 
				{tags add "bombrunout"} ;8 
				{tags remove "bomb1"}
				{tags remove "bomb2"}
				{tags remove "bomb3"}
				{tags remove "bomb4"}
				{tags remove "bomb5"}
				{tags remove "bomb6"}
				{tags remove "bomb7"}
				{bone hide "rocket07"}
			}
		}
	}
	{on "die"
		{bone hide "rocket00"}
		{bone hide "rocket01"}
		{bone hide "rocket02"}
		{bone hide "rocket03"}
		{bone hide "rocket04"}
		{bone hide "rocket05"}
		{bone hide "rocket06"}
		{bone hide "rocket07"}
	}
	("bf109_sound")
}