{"shell_smoke" ;// props from shell_smoke service entity
	{on spawn
		{add_view "smoke_cover-up_norm"		"smoke2" "root"}
		{add_view "smoke_cover-up_big"		"smoke3" "root"}
		{call "activate"}
	}
	{on "activate" overload
	    {tags add "smokecover"}
		(define "spawn_volume"
			{spawn "smoke_volume_%0" offset %1 %2 0
				{delay %3 {hide 1}}
			}
		)
		{view start "smoke3"}
		{delay 2
		    {spawn "smoke_volume_cylinder" random_position 500 {delay 85 {hide 1}}}
		}
		{delay 2
			("spawn_volume" args cylinder 110 0 84 random_position 20)
			("spawn_volume" args cylinder -110 0 84 random_position 20)
			("spawn_volume" args cylinder 0 110 84 random_position 20)
			("spawn_volume" args cylinder 0 -110 84 random_position 20)
			("spawn_volume" args cylinder 110 110 84 random_position 20)
			("spawn_volume" args cylinder -110 -110 84 random_position 20)
			("spawn_volume" args cylinder -110 110 84 random_position 20)
			("spawn_volume" args cylinder 110 -110 84 random_position 20)
		}
		{delay 5
			("spawn_volume" args cylinder_sm 220 0 82 random_position 20)
			("spawn_volume" args cylinder_sm -220 0 82 random_position 20)
			("spawn_volume" args cylinder_sm 0 220 82 random_position 20)
			("spawn_volume" args cylinder_sm 0 -220 82 random_position 20)
		}
		{delay 85
			{view stop "smoke3"}
			{stop_sound "smoke"}
		}
		{delay 90
			{hide 1}
		}
	}
}