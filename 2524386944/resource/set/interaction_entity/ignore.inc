{"vehicle"
    {on spawn
	    {add_view	"marker_veterancy"			"marker_veterancy"			"turret" not_manual not_scenario}
	} 
	
	{on "ignore_infantry" 		;// UI button to toggle engine on/off
		{if operatable
			{if work "turret"
				{if work "body"
					{if not tagged "ignore_off"
						{if not "toggle_delay"
							{tags add "ignore_off"}
							{tags remove "ignore_on"}
							{set "backward" 1}
						}
					else not "toggle_delay"
						{tags add "ignore_on"}
						{tags remove "ignore_off"}
						{set "backward" 0}
					}
				}
			else
				{tags add "ignore_infantry_off"}	;// allows engine to be set to off state when damaged. Cancels auto engine start on repair
			}
		}
		{set "toggle_delay" 1}			;// stops accidental double click of UI button
		{delay 1 {set "toggle_delay" 0}}
	}
	
	{on "reverse_toggle" 		;// UI button to toggle engine on/off
		{if operatable
			{if work "turret"
				{if work "body"
					{if not tagged "reverse_on"
						{if not "toggle_delay"
							{tags add "reverse_on"}
							{tags remove "reverse_off"}
							{set "backward" 0}
							{view start ally neutral "marker_veterancy"}
						}
					else not "toggle_delay"
						{tags add "reverse_off"}
						{tags remove "reverse_on"}
						{set "backward" 1}
						{view pause "marker_veterancy"}
					}
				}
			else
				{tags add "ignore_infantry_off"}	;// allows engine to be set to off state when damaged. Cancels auto engine start on repair
			}
		}
		{set "toggle_delay" 1}			;// stops accidental double click of UI button
		{delay 1 {set "toggle_delay" 0}}
	}
}

