(include "human2.inc")
(include "ignore.inc")
(include "katyreload.inc")
(include "vehicle_tags_ger.inc")
(include "vehicle_tags_rus.inc")
(include "construction/sandbag_ring_structures.inc")
{"skirmish_bonus_pointer"
     {on spawn
        {call "add_number"}
	{delay 0
	    {start_sound "mission/bonus/"}
            {view start "fx"}
	}
;        {call "add_smoke"}
;        {delay 0.5
;            {view start "smoke"}
;        }
;        {delay 1.5
;            {view start "smoke2"}
;        }

     }
	{on "add_number" overload
		{add_view "bonus_pointer" "fx" "fx_mp_pointer"}
;		{add_view "smoke_yellow_small" "smoke" "fx_mp_pointer"}
;		{add_view "smoke_yellow_norm" "smoke2" "fx_mp_pointer"}
	}
}



{"skirmish_fx_base"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "skirmish_flag_border" "fx" "fx_number"}
	}
}


{"skirmish_fx_5_rocket"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "5_rocket" "fx" "fx_number"}
		{add_view "skirmish_flag_border" "fx" "fx_number"}
	}
}
{"skirmish_fx_5_heavy"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "5_heavy"	"fx" "fx_number"}
		{add_view "skirmish_flag_border"  "fx" "fx_number"}
	}
}
{"skirmish_fx_5_victory"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "5_victory" "fx" "fx_number"}
		{add_view "skirmish_flag_border" "fx" "fx_number"}
	}
}


{"skirmish_fx_15_bonus"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "15_bonus" "fx" "fx_number"}
		{add_view "skirmish_flag_border" "fx" "fx_number"}
	}
}
{"skirmish_fx_15_tank"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "15_tank"	"fx" "fx_number"}
		{add_view "skirmish_flag_border" "fx" "fx_number"}
	}
}


{"skirmish_fx_victory"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "victory"	"fx" "fx_number"}
		{add_view "skirmish_flag_border" "fx" "fx_number"}
	}
}
{"skirmish_fx_20_victory"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "20_victory" "fx" "fx_number"}
		{add_view "skirmish_flag_border" "fx" "fx_number"}
	}
}
{"skirmish_fx_250_victory"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "250_victory" "fx" "fx_number"}
		{add_view "skirmish_flag_border" "fx" "fx_number"}
	}
}

{"skirmish_fx_30_defence"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "30_defence" "fx" "fx_number"}
		{add_view "skirmish_flag_border" "fx" "fx_number"}
	}
}
{"skirmish_fx_30_infantry"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "30_infantry"	"fx" "fx_number"}
		{add_view "skirmish_flag_border" "fx" "fx_number"}
	}
}
{"skirmish_fx_30_special"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "30_special" "fx" "fx_number"}
		{add_view "skirmish_flag_border" "fx" "fx_number"}
	}
}
{"skirmish_fx_30_tank"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "30_tank"	"fx" "fx_number"}
		{add_view "skirmish_flag_border" "fx" "fx_number"}
	}
}
{"skirmish_fx_30_jeep"
    {on spawn
        {call "add_number"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_number" overload
		{add_view "30_jeep"	"fx" "fx_number"}
		{add_view "skirmish_flag_border" "fx" "fx_number"}
	}
}
