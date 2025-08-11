{"sand sandbag onestage construction"
	{on spawn
		{delay 0.1
			{spawn "building_smoke" "service_bone"}
			{link_sound "deploy" "vehicle/deploy"}
			{play_sound "deploy"}
			{if terrain_fx "ice"
				{tex_mod "win"}
			else terrain_fx "snow"
				{tex_mod "win"}
			else
				; do nothing
			}
		}
	}
}