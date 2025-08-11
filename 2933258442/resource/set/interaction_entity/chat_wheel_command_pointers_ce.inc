;{"pointer_help"
;	{on spawn
;		{tags add "medic_pointer"}
;		{delay 15
;			{tags add "ignore_pointer"}
;			{delay 25
;				{delete}
;			}
;		}
;	}
;}

{"pointer_attack"
	{on spawn
		{tags add "resupply_pointer"}
		{delay 15
			{tags add "ignore_pointer"}
			{delay 21
				{delete}
			}
		}
	}
}

{"pointer_enemy"
	{on spawn
		{delay 0.5
			{spawn "spawn_aim"
				{tags add "start_defense"}
				{delay 9
					{delete}
				}
			}
        }
	}
}