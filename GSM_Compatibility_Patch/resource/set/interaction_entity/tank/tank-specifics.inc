
;/*=========== German Vehicles Begin ===========*/

{"sdkfz221 tank"
	("sdkfz222_sound")
}
{"sdkfz221_spzb41 tank"
	("sdkfz222_sound")
}
{"sdkfz222 tank"
	("sdkfz222_sound")
}
{"sdkfz223 tank"
	("sdkfz222_sound")
}
{"sdkfz231 tank"
	("sdkfz232_sound")
}
{"sdkfz232 tank"
	("sdkfz232_sound")
}
{"sdkfz234 tank"
	("sdkfz234_sound")
}
{"sdkfz234_2 tank"
	("sdkfz234_sound")
}
{"p204_f tank"
	("sdkfz234_sound") ;Placeholder
}
{"p204_f_rail tank"
	("sdkfz234_sound") ;Placeholder
}
{"panzer742r tank"
	("bt_sound")
}
{"sdkfz251c tank"
	("hanomag_sound")

	{on "event_no_crew" overload}
	{on "event_with_crew" overload}

	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner4_hatch_open" overload
		{ani_play "mgun_aa_2" +1.0 resume}
	}
	{on "gunner4_hatch_close" overload
		{ani_play "mgun_aa_2" -1.0 resume}
	}
}
{"sdkfz251d tank"
	("hanomag_sound")
}
{"sdkfz10_pak38 tank"
	("hanomag_sound")

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.20 0.2)
	}
}
{"sdkfz4 tank"
	("hanomag_sound")
}
{"sdkfz302"
	("sdkfz302_sound")
	{on "explosion_blastwave" overload
		{start_sound "detonation/he_size4/bkg/"}
		{blastwave c4 15 r0 5 r1 8}
		{blastwave c4 1.5 r0 7 r1 12}


		{spawn "shockwave_sphere"}
		{spawn "ex_bomb_50kg"}

		{spawn "crater_medium" "basis" x terrain_texmod}

		{if terrain_fx "snow"
			{spawn "tank_die_snow"}
		else terrain_fx "ice"
			{spawn "tank_die_snow"}
		else
			{spawn "tank_die_dust"}
		}
	}
}
{"sdkfz303b"
	("sdkfz303_sound")
	{on "explosion_blastwave" overload
		{start_sound "detonation/he_size4/bkg/"}
		{blastwave c4 25 r0 5 r1 8}
		{blastwave c4 1.75 r0 7 r1 14}


		{spawn "shockwave_sphere"}
		{spawn "ex_bomb_100kg"}

		{spawn "crater_big" "basis" x terrain_texmod}

		{if terrain_fx "snow"
			{spawn "tank_die_snow"}
		else terrain_fx "ice"
			{spawn "tank_die_snow"}
		else
			{spawn "tank_die_dust"}
		}
	}
}
{"sdkfz8_flak18 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret"		"vehicle/turret/cannon/big"}
		{link_sound "rotate_gun"		"vehicle/turret/cannon/big"}
		{link_sound "engine_start"		"vehicle/engine/sdkfz251/start"}
		{link_sound "engine_stop"		"vehicle/engine/sdkfz251/stop"}
		{link_sound "engine_idle"		"vehicle/engine/sdkfz251/idle"}
		{link_sound "engine_full"		"vehicle/engine/sdkfz251/full"}
		{link_sound "exhaust"			"vehicle/engine/sdkfz251/exhaust"}
		{link_sound "move"				"vehicle/tracks/sdkfz251"}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.3 0.22)
	}
	{on "reload_delay" overload
		("reload_delay" args 7.0 0.5 6.0)
	}
}
{"sdkfz4 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret"		"vehicle/turret/cannon/big"}
		{link_sound "rotate_gun"		"vehicle/turret/cannon/big"}
		{link_sound "engine_start"		"vehicle/engine/sdkfz251/start"}
		{link_sound "engine_stop"		"vehicle/engine/sdkfz251/stop"}
		{link_sound "engine_idle"		"vehicle/engine/sdkfz251/idle"}
		{link_sound "engine_full"		"vehicle/engine/sdkfz251/full"}
		{link_sound "exhaust"			"vehicle/engine/sdkfz251/exhaust"}
		{link_sound "move"				"vehicle/tracks/sdkfz251"}
	}
}
{"sdkfz7_1 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret"		"vehicle/turret/cannon/big"}
		{link_sound "rotate_gun"		"vehicle/turret/cannon/big"}
		{link_sound "engine_start"		"vehicle/engine/sdkfz251/start"}
		{link_sound "engine_stop"		"vehicle/engine/sdkfz251/stop"}
		{link_sound "engine_idle"		"vehicle/engine/sdkfz251/idle"}
		{link_sound "engine_full"		"vehicle/engine/sdkfz251/full"}
		{link_sound "exhaust"			"vehicle/engine/sdkfz251/exhaust"}
		{link_sound "move"				"vehicle/tracks/sdkfz251"}
	}
}

{"panzer1b tank"
	("pz1_sound")
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
	}
	{on fire "mgun" overload
		{play_sound "bkg_mg"}
		{if  name "00"
			{view start "flashbarrel00"}
			{delay 0.2
				{view pause "flashbarrel00"}
			}
		else name "01"
			{view start "flashbarrel01"}
			{delay 0.2
				{view pause "flashbarrel01"}
			}
		}
	}
}
{"panzer1f tank"
	("pz1_sound")
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
	}
	{on fire "mgun" overload
		{play_sound "bkg_mg"}
		{if  name "00"
			{view start "flashbarrel00"}
			{delay 0.2
				{view pause "flashbarrel00"}
			}
		else name "01"
			{view start "flashbarrel01"}
			{delay 0.2
				{view pause "flashbarrel01"}
			}
		}
	}
	{on break						;// {on break} is for when components break
		{if not tagged "exploded"
			{if component "turret"
				{weapon_work "mgun" 0}
			else component "mantlet"
				{weapon_work "mgun" 0}
			}
		}
	}
	{on repair
		{if component "turret"
			{if work "mantlet"
				{weapon_work "mgun" 1}
			}
		else component "mantlet"
			{if work "turret"
				{weapon_work "mgun" 1}
			}
		}
	}
}
{"panzerjager1 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz1/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz1/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz1/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz1/full"}
		{link_sound "exhaust"			"vehicle/engine/pz1/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz1"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.15 0.05)
	}
}
{"bison tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz1/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz1/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz1/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz1/full"}
		{link_sound "exhaust"			"vehicle/engine/pz1/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz1"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on pierce overload
		{if volume "turret"
			;do nothing    ;// disables kill_crew events when turret is pen. Calls for kill_crew are in gun_shield code for this vehicle.
		else
			{inherited}
		}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 2.25)
	}
}

{"panzer2c tank"
	("pz2_sound")
}
{"panzer2f tank"
	("pz2_sound")
	{on break
		{if not tagged "exploded"
			{if component "shieldw1"
				{components "shieldw2" destroy}
			}
			{if component "shieldw2"
				{components "shieldw1" destroy}
			}
		}
	}
}
{"panzer2l tank"
	("pz2_sound")
}

{"marder2 tank"
	("pz2_sound")
}
{"grille_m tank"
	("pz38_sound")
	{on "zenite_terrain_fx" overload} ; // overwrites and stops dust fx on ground from firing main gun
}
{"marder3m tank"
	("pz38_sound")
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.15 0.05)
	}
}
{"pz35t tank"
	("pz38_sound")
	{##on "commander_hatch_open" overload
		{ani_wind "open" end}
	}
	{##on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
}
{"pz38t_a tank"
	("pz38_sound")
}
{"pz38t_f tank"
	("pz38_sound")
	{on break
		{if not tagged "exploded"
			{if component "shieldw1"
				{components "shieldw2" destroy}
			}
		}
	}
}
{"pz38t_g tank"
	("pz38_sound")
}
{"pz38t_20mm tank"
	("pz38_sound")
}
{"hetzer tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/hetzer/start"}
		{link_sound "engine_stop"		"vehicle/engine/hetzer/stop"}
		{link_sound "engine_idle"		"vehicle/engine/hetzer/idle"}
		{link_sound "engine_full"		"vehicle/engine/hetzer/full"}
		{link_sound "exhaust"			"vehicle/engine/hetzer/exhaust"}
		{link_sound "move"				"vehicle/tracks/hetzer"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}

{"panzer3e tank"
	("pz3_sound")
	{on spawn
		{add_view	"flash_gun_big" "flashbarrel00" "shooter00"}
		{add_view	"flash_gun_big" "flashbarrel01" "shooter01"}
	}
	{on fire "mgun2" overload
		{play_sound "bkg_mg"}
		{if  name "00"
			{view start "flashbarrel00"}
			{delay 0.2
				{view pause "flashbarrel00"}
			}
		else name "01"
			{view start "flashbarrel01"}
			{delay 0.2
				{view pause "flashbarrel01"}
			}
		}
	}
	{on "commander_hatch_open" overload
		{ani_play "open" 1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
}
{"panzer3f tank"
	("pz3_sound")
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
}
{"panzer3j tank"
	("pz3_sound")
}
{"panzer3j1 tank"
	("pz3_sound")
}
{"panzer3j2 tank"
	("pz3_sound")
}
{"panzer3l tank"
	("pz3_sound")
}
{"panzer3m tank"
	("pz3_sound")
}
{"panzer3n tank"
	("pz3_sound")
}
{"panzer3_flamm tank"
	("pz3_sound")
	{on spawn
		{add_view "flamer_fire_tank" "flame" "foresight1"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args gun 60 1 40)
}
{"stug3b tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"stug3e tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"sig33b tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"stug3f tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"stug3g tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "charger_hatch_open" overload
		{ani_wind "open1" end}
		{ani_play "mgun_aa" 1.0 resume}
	}
	{on "charger_hatch_close" overload
		{ani_play "open1" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"stug3g_late tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "gunner2_hatch_open" overload
		{ani_wind "open1" end}
		{ani_play "open" -1.0 resume}
	}
}
{"stuh42 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "charger_hatch_open" overload
		{ani_wind "open1" end}
		{ani_play "mgun_aa" 1.0 resume}
	}
	{on "charger_hatch_close" overload
		{ani_play "open1" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"panzer4d tank"
	("pz4_sound")
}
{"panzer4f1 tank"
	("pz4_sound")
}
{"panzer4f2 tank"
	("pz4_sound")
}
{"panzer4g tank"
	("pz4_sound")
}
{"panzer4h tank"
	("pz4_sound")
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"panzer4j tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/handcrank/handcrank_heavy"}
	}
}
{"stug4g tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"sturmpanzer4 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "charger_hatch_open" overload
		{ani_wind "open1" end}
		{ani_play "mgun_aa" 1.0 resume}
	}
	{on "charger_hatch_close" overload
		{ani_play "open1" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"jagdpanzer_iv tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"nashorn tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.80 0.2)
	}
}
{"hummel tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"wespe tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.75 0.15)
	}
}
{"welberwind tank"
	("pz4_sound")
}
{"panzer5g tank"
	("pz5_sound")
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"panzer5a tank"
	("pz5_sound")
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"panzer5d tank"
	("pz5_sound")
}
{"jagdpanther tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz5/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz5/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz5/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz5/full"}
		{link_sound "exhaust"			"vehicle/engine/pz5/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz5"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"pz756r tank"
	("kv_sound")
	{on break
		{if not tagged "exploded"
			{if component "detail2"
				{components "detail2" destroy}
			}
		}
		("shed_shield_part" args "detail2")
	}
}
{"tiger1e tank"
	("pz6_sound")
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"tiger1h tank"
	("pz6_sound")
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
}
{"tiger1hunt tank"
	("pz6_sound")
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"ferdinand tank"
	("ferdinand_sound")
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}
	{on "reload_delay" overload
		("reload_delay" args 3.5 0 0)
	}
}
{"elefant tank"
	("ferdinand_sound")
}
{"sturmtiger"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz6/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz6/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz6/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz6/full"}
		{link_sound "exhaust"			"vehicle/engine/pz6/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz6"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "bkg_cannon_huge"   "weapon/shot/bkg/cannon/huge/"}
		{link_sound "bkg_rocket"        "weapon/shot/bkg/rocket/"}
	}
	{on fire "gun"
		{play_sound "bkg_cannon_huge"}
		{play_sound "bkg_rocket"}
		{spawn "sturmtiger_fire" inv_normal}
		{volumes "rocket" disable bullet blast}		;// Disables rocket volume after firing while reloading
		{delay 90									;// Delay set to match reload time of main weapon
			{volumes "rocket" enable bullet blast}
		}
	}
	{on break_armor				;// volume breaks
		{if not tagged "exploded"
			{if volume "rocket"
				{call "stat_break"}
				{call "_explosion"}
				{##delay 0.01
					{call "spawn_shellhole"}
				}
			}
		}
	}
	{on "__explosion"
		{tags add "exploded"}
		{blastwave c4 30 r0 8 r1 16 offset 0 0 75}
		{blastwave c4 3 r0 20 r1 30 offset 0 0 75}
		{spawn "train_die" "basis"}
		{delay 0.1
			{call "_explosion"}
		}
	}
	{on "explosion_blastwave" overload
		{blastwave c4 15 r0 7 r1 14 offset 0 0 75}
		{blastwave c4 2 r0 10 r1 20 offset 0 0 75}
		{impulse up 0.1 0.1 dir 0.2 0.1}
		{spawn "tank_die_heavy" "basis"}
		{start_sound "detonation/explosion_vehicle/bkg/"}
		{if terrain_fx "snow"
			{spawn "tank_die_snow" "basis"}
		else terrain_fx "ice"
			{spawn "tank_die_snow" "basis"}
		else
			{spawn "tank_die_dust" "basis"}
		}
	}
}

{"tiger2h tank"
	("pz6b_sound")
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"tiger2p tank"
	("pz6b_sound")
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"jagdtiger tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz6b/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz6b/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz6b/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz6b/full"}
		{link_sound "exhaust"			"vehicle/engine/pz6b/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz6b"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.0 0.3)
	}
}
{"maus tank"
	("pz6b_sound")
	{on spawn
		{add_view "tank_canon_fire_75_76"			"flashbarrelmedium"	"Foresight2"}
		{add_view "tank_fire_medium_dust_ground_rain"		"medium_ground_r_fx"	"basis"}
		{add_view "tank_fire_medium_dust_ground"		"medium_ground_fx"	"basis"}
		{add_view "tank_fire_medium_dust_sand_rain"		"medium_sand_r_fx"	"basis"}
		{add_view "tank_fire_medium_dust_sand"			"medium_sand_fx"	"basis"}
		{add_view "tank_fire_medium_dust_snow"			"medium_snow_fx"	"basis"}
		{link_sound "bkg_cannon_medium" 			"weapon/shot/bkg/cannon/medium/"}
	}
	{on fire "gun2"
		{view start "flashbarrelmedium"}
		{play_sound "bkg_cannon_medium"}
		{start_sound "weapon/shot/tracer/"}
		{call "medium_terrain_fx"}
	}
}


;/*=========== German Vehicles End ===========*/

;/*=========== Soviet Vehicles Begin ===========*/

{"nkl26"
	("nkl_sound")
	{on "hatch_fire" overload} ;//disables typical hatch fire that tanks have on hull destroyed
;	{on "add_overlay_sound" overload} ;//disables standard track overlay sounds
}

{"stalinetz60"
	("s60_sound")
}

{"ba64"
	("ba_sound")
}

{"ba20"
	("ba_sound")
}

{"ba6"
	("ba_sound")
}

{"ba11 tank"
	("ba_sound")
}

{"m3a1e1_scout tank"
	("ba_sound")
}

{"m3a1e1_scout_mgun tank"
	("ba_sound")
}

{"t20 tank"
	("t27_sound")
}
{"zis30 tank"
	("t27_sound")
}

{"bt2 tank"
	("bt_sound")
}
{"bt2_da2 tank"
	("bt_sound")
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
	}
	{on fire "mgun2" overload
		{play_sound "bkg_mg"}
		{if  name "00"
			{view start "flashbarrel00"}
			{delay 0.2
				{view pause "flashbarrel00"}
			}
		else name "01"
			{view start "flashbarrel01"}
			{delay 0.2
				{view pause "flashbarrel01"}
			}
		}
	}
}
{"bt5 tank"
	("bt_sound")
}
{"bt7 tank"
	("bt_sound")
}
{"panzer742r tank"
	("bt_sound")
}
{"bt7a tank"
	("bt_sound")
}
{"kht26 tank"
	("t26_sound")
	{on spawn
		("rand_cut_else" args "cooler1" "cooler2")
		{add_view "flamer_fire" "flame" "foresight1"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args gun 40 1 40)
}
{"ot130 tank"
	("t26_sound")
	{on spawn
		("rand_cut_else" args "cooler1" "cooler2")
		{add_view "flamer_fire" "flame" "foresight1"}
	}
	{on "lights_on"
		{ani_play "headlight"}
		{tags add "lights_on"}
	}
	{on "lights_off"
		{if tagged "lights_on"
			{ani_play "headlight" -1}
			{tags remove "lights_on"}
		}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args gun 40 1 40)
}
{"t26_31 tank"
	("t26_sound")
	{on spawn
		("rand_cut_else" args "cooler1" "cooler2")
	}
}
{"t26_33 tank"
	("t26_sound")
	{on spawn
		("rand_cut" args "turret_light")
		("rand_cut_else" args "cooler1" "cooler2")
	}
	{on "lights_on"
		{ani_play "headlight"}
		{tags add "lights_on"}
	}
	{on "lights_off"
		{if tagged "lights_on"
			{ani_play "headlight" -1}
			{tags remove "lights_on"}
		}
	}
}
{"t26_38 tank"
	("t26_sound")
	{on spawn
		("rand_cut_else" args "cooler1" "cooler2")
		("rand_cut" args "turret_light")
		("rand_cut" args "antenna")
	}
	{on "lights_on"
		{ani_play "headlight"}
		{tags add "lights_on"}
	}
	{on "lights_off"
		{if tagged "lights_on"
			{ani_play "headlight" -1}
			{tags remove "lights_on"}
		}
	}
}
{"t26_39 tank"
	("t26_sound")
	{on spawn
		("rand_cut_else" args "cooler1" "cooler2")
		("rand_cut" args "turret_light")
	}
	{on "lights_on"
		{ani_play "headlight"}
		{tags add "lights_on"}
	}
	{on "lights_off"
		{if tagged "lights_on"
			{ani_play "headlight" -1}
			{tags remove "lights_on"}
		}
	}
}
{"t27 tank"
	("t27_sound")
}
{"t28 tank"
	("t28_sound")
	{on break
		{if not tagged "exploded"
			{if component "aux_turret2"
				{call "kill_gunner3"}
			else component "aux_turret1"
				{call "kill_charger2"}
			}
		}
	}
}
{"t37a tank"
	("t27_sound")
}
{"panzer731r tank"
	("t27_sound")
}
{"t30 tank"
	("t70_sound")
}
{"t40 tank"
	("t70_sound")
}
{"t60 tank"
	("t70_sound")
}
{"t70 tank"
	("t70_sound")
}
{"t70m tank"
	("t70_sound")
}
{"su76 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/t70/start"}
		{link_sound "engine_stop"		"vehicle/engine/t70/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t70/idle"}
		{link_sound "engine_full"		"vehicle/engine/t70/full"}
		{link_sound "exhaust"			"vehicle/engine/t70/exhaust"}
		{link_sound "move"				"vehicle/tracks/t70"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.4 0.3)
	}
}
{"zsu37 tank"
	("t70_sound")
}

{"t3457_41 tank"
	("t34_sound")
}
{"t3457_43 tank"
	("t34_sound")
}
{"t3476_40 tank"
	("t34_sound")
}
{"t3476_41 tank"
	("t34_sound")
}
{"t3476_42 tank"
	("t34_sound")
}
{"t3476_43 tank"
	("t34_sound")
}
{"t3476_43_flame tank"
	("t34_sound")
	{on spawn
		{add_view "flamer_fire_tank" "flame" "foresight4"}
	}
	{on operatable on
		{view start "fire"}
	}
	{on operatable off
		{view stop "fire"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args flamer1 80 4 45)
}

{"t3485_44 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/t34/start"}
		{link_sound "engine_stop"		"vehicle/engine/t34/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t34/idle"}
		{link_sound "engine_full"		"vehicle/engine/t34/full"}
		{link_sound "exhaust"			"vehicle/engine/t34/exhaust"}
		{link_sound "move"				"vehicle/tracks/t34"}
		{link_sound "rotate_turret"		"vehicle/turret/electric/electric_light"}
	}
}
{"su85 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/t34/start"}
		{link_sound "engine_stop"		"vehicle/engine/t34/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t34/idle"}
		{link_sound "engine_full"		"vehicle/engine/t34/full"}
		{link_sound "exhaust"			"vehicle/engine/t34/exhaust"}
		{link_sound "move"				"vehicle/tracks/t34"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"su100 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/t34/start"}
		{link_sound "engine_stop"		"vehicle/engine/t34/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t34/idle"}
		{link_sound "engine_full"		"vehicle/engine/t34/full"}
		{link_sound "exhaust"			"vehicle/engine/t34/exhaust"}
		{link_sound "move"				"vehicle/tracks/t34"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"su122 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/t34/start"}
		{link_sound "engine_stop"		"vehicle/engine/t34/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t34/idle"}
		{link_sound "engine_full"		"vehicle/engine/t34/full"}
		{link_sound "exhaust"			"vehicle/engine/t34/exhaust"}
		{link_sound "move"				"vehicle/tracks/t34"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}

{"kv1_40 tank"
	("kv_sound")
}
{"kv1_41 tank"
	("kv_sound")
}
{"kv1s tank"
	("kv_sound")
}
{"kv2_40 tank"
	("kv_sound")
}
{"kv85 tank"
	("kv_sound")
}
{"su100y tank" ;// Temp until it gets it's own sound
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/kv/start"}
		{link_sound "engine_stop"		"vehicle/engine/kv/stop"}
		{link_sound "engine_idle"		"vehicle/engine/kv/idle"}
		{link_sound "engine_full"		"vehicle/engine/kv/full"}
		{link_sound "exhaust"			"vehicle/engine/kv/exhaust"}
		{link_sound "move"				"vehicle/tracks/kv/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"su152 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/kv/start"}
		{link_sound "engine_stop"		"vehicle/engine/kv/stop"}
		{link_sound "engine_idle"		"vehicle/engine/kv/idle"}
		{link_sound "engine_full"		"vehicle/engine/kv/full"}
		{link_sound "exhaust"			"vehicle/engine/kv/exhaust"}
		{link_sound "move"				"vehicle/tracks/kv/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"is1_43 tank"
	("is_sound")
}
{"is2_43 tank"
	("is_sound")
}
{"is2_44 tank"
	("is_sound")
}
{"isu122s tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/is/start"}
		{link_sound "engine_stop"		"vehicle/engine/is/stop"}
		{link_sound "engine_idle"		"vehicle/engine/is/idle"}
		{link_sound "engine_full"		"vehicle/engine/is/full"}
		{link_sound "exhaust"			"vehicle/engine/is/exhaust"}
		{link_sound "move"				"vehicle/tracks/is/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "commander_hatch_open" overload
		{ani_wind "open_right" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_right" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"isu152 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/is/start"}
		{link_sound "engine_stop"		"vehicle/engine/is/stop"}
		{link_sound "engine_idle"		"vehicle/engine/is/idle"}
		{link_sound "engine_full"		"vehicle/engine/is/full"}
		{link_sound "exhaust"			"vehicle/engine/is/exhaust"}
		{link_sound "move"				"vehicle/tracks/is/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "commander_hatch_open" overload
		{ani_wind "open_right" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_right" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}


;/*=========== Soviet Vehicles End ===========*/

;/*=========== Generic Vehicles Begin ===========*/

{"universal_carrier_rus tank"
	("universal_carrier_sound")
}

{"mmg_carrier_rus tank"
	("universal_carrier_sound")
	{on fire "mgun2"
		{ani_play "fire_mgun"}
	}
	{on "reload"
		{if effector "stuff weapon"
		
		else
			{ani_play "reload_mgun"}
		}
	}
}
{"valentine2 tank"
	("valentine_sound")
}
{"valentine7 tank"
	("valentine_sound")
}
{"valentine9 tank"
	("valentine_sound")
}
{"churchill3 tank"
	("churchill_sound")
}


;/*=========== Generic Vehicles End ===========*/



;----------------------------------
;----------gsm neu :
;----------------------------------
{"sdkfz4 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret"		"vehicle/turret/cannon/big"}
		{link_sound "rotate_gun"		"vehicle/turret/cannon/big"}
		{link_sound "engine_start"		"vehicle/engine/sdkfz251/start"}
		{link_sound "engine_stop"		"vehicle/engine/sdkfz251/stop"}
		{link_sound "engine_idle"		"vehicle/engine/sdkfz251/idle"}
		{link_sound "engine_full"		"vehicle/engine/sdkfz251/full"}
		{link_sound "exhaust"			"vehicle/engine/sdkfz251/exhaust"}
		{link_sound "move"				"vehicle/tracks/sdkfz251"}
	}
}
{"sdkfz7_2 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret"		"vehicle/turret/cannon/big"}
		{link_sound "rotate_gun"		"vehicle/turret/cannon/big"}
		{link_sound "engine_start"		"vehicle/engine/sdkfz251/start"}
		{link_sound "engine_stop"		"vehicle/engine/sdkfz251/stop"}
		{link_sound "engine_idle"		"vehicle/engine/sdkfz251/idle"}
		{link_sound "engine_full"		"vehicle/engine/sdkfz251/full"}
		{link_sound "exhaust"			"vehicle/engine/sdkfz251/exhaust"}
		{link_sound "move"			"vehicle/tracks/sdkfz251"}
	}
}
{"sdkfz222 tank"
	("sdkfz222_sound")
}
{"sdkfz234_1 tank"
	("sdkfz234_sound")
}
{"sdkfz234_3 tank"
	("sdkfz234_sound")
}
{"sdkfz234_4 tank"
	("sdkfz234_sound")
}
{"sdkfz250_1 tank"
	("hanomag_sound")
}
{"sdkfz250_11 tank"
	("hanomag_sound")
}
{"sdkfz251_1_stuka tank"
	("hanomag_sound")
}
{"zgkw303f tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret"		"vehicle/turret/cannon/big"}
		{link_sound "rotate_gun"		"vehicle/turret/cannon/big"}
		{link_sound "engine_start"		"vehicle/engine/sdkfz251/start"}
		{link_sound "engine_stop"		"vehicle/engine/sdkfz251/stop"}
		{link_sound "engine_idle"		"vehicle/engine/sdkfz251/idle"}
		{link_sound "engine_full"		"vehicle/engine/sdkfz251/full"}
		{link_sound "exhaust"			"vehicle/engine/sdkfz251/exhaust"}
		{link_sound "move"				"vehicle/tracks/sdkfz251"}
	}
}
;----------------------------------

{"elefant tank"
	("ferdinand_sound")
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}
	{on "reload_delay" overload
		("reload_delay" args 3.5 0 0)
	}
}
{"jagdtiger tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz6b/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz6b/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz6b/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz6b/full"}
		{link_sound "exhaust"			"vehicle/engine/pz6b/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz6b"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"kv2_754r tank"
	("kv_sound")
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.0 1.0)
	}
}
{"sturer_emil tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz6"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"tiger_p tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/ferdinand/start"}
		{link_sound "engine_stop"		"vehicle/engine/ferdinand/stop"}
		{link_sound "engine_idle"		"vehicle/engine/ferdinand/idle"}
		{link_sound "engine_full"		"vehicle/engine/ferdinand/full"}
		{link_sound "exhaust"			"vehicle/engine/ferdinand/exhaust"}
		{link_sound "move"			"vehicle/tracks/ferdinand/"}
		{link_sound "rotate_turret"		"vehicle/turret/hydraulic/hydraulic_heavy"}
	}
}
;----------------------------------
{"bison2 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz2/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz2/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz2/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz2/full"}
		{link_sound "exhaust"			"vehicle/engine/pz2/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz2/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.75 0.25)
	}
}
{"flakpanzer1a tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz1/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz1/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz1/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz1/full"}
		{link_sound "exhaust"			"vehicle/engine/pz1/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz1"}
		{link_sound "rotate_turret"		"vehicle/turret/cannon/small"}
		{link_sound "rotate_gun"		"vehicle/turret/cannon/small"}
	}
}
{"grille tank"
	("pz38_sound")
}
{"h39_ger tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/h39/start"}
		{link_sound "engine_stop"		"vehicle/engine/h39/stop"}
		{link_sound "engine_idle"		"vehicle/engine/h39/idle"}
		{link_sound "engine_full"		"vehicle/engine/h39/full"}
		{link_sound "exhaust"			"vehicle/engine/h39/exhaust"}
		{link_sound "move"			"vehicle/tracks/h39"}
		{link_sound "rotate_turret"		"vehicle/turret/electric/electric_light"}
	}
}
{"marder3h tank"
	("pz38_sound")
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.15 0.05)
	}
}
{"panzer2h tank"
	("pz2_sound")
}
{"panzer2j tank"
	("pz2_sound")
}
{"sdkfz301wanze tank"
	("hanomag_sound")
}
{"wespe tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz2/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz2/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz2/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz2/full"}
		{link_sound "exhaust"			"vehicle/engine/pz2/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz2/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
;----------------------------------
{"b1sf tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/b1bis/start"}
		{link_sound "engine_stop"		"vehicle/engine/b1bis/stop"}
		{link_sound "engine_idle"		"vehicle/engine/b1bis/idle"}
		{link_sound "engine_full"		"vehicle/engine/b1bis/full"}
		{link_sound "exhaust"			"vehicle/engine/b1bis/exhaust"}
		{link_sound "move"			"vehicle/tracks/b1bis"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"char_b1 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/b1bis/start"}
		{link_sound "engine_stop"		"vehicle/engine/b1bis/stop"}
		{link_sound "engine_idle"		"vehicle/engine/b1bis/idle"}
		{link_sound "engine_full"		"vehicle/engine/b1bis/full"}
		{link_sound "exhaust"			"vehicle/engine/b1bis/exhaust"}
		{link_sound "move"			"vehicle/tracks/b1bis"}
		{link_sound "rotate_turret"		"vehicle/turret/electric/electric_light"}
	}
	{on spawn
		{add_view "tank_canon_fire_75_76"		"flashbarrelmedium"		"Foresight2"}
		{add_view "tank_fire_medium_dust_ground_rain"	"medium_ground_r_fx"		"basis"}
		{add_view "tank_fire_medium_dust_ground"	"medium_ground_fx"		"basis"}
		{add_view "tank_fire_medium_dust_sand_rain"	"medium_sand_r_fx"		"basis"}
		{add_view "tank_fire_medium_dust_sand"		"medium_sand_fx"		"basis"}
		{add_view "tank_fire_medium_dust_snow"		"medium_snow_fx"		"basis"}
		{add_view	"cooking_barrel"		"cooking_barrel_fire"		"Foresight2"}
		{add_view	"cooking_barrel_smoke"		"cooking_barrel_smoke" 		"Foresight2"}
		{add_view	"cooking_barrel_aftersmoke"	"cooking_barrel_aftersmoke" 	"Foresight2"}

		{link_sound "bkg_cannon_medium" "weapon/shot/bkg/cannon/medium/"}
	}
	{on fire "gun2"
		{view start "flashbarrelmedium"}
		{play_sound "bkg_cannon_medium"}
		{start_sound "weapon/shot/tracer/"}
		{call "medium_terrain_fx"}
	}
}
{"char_b1_flamer tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/b1bis/start"}
		{link_sound "engine_stop"		"vehicle/engine/b1bis/stop"}
		{link_sound "engine_idle"		"vehicle/engine/b1bis/idle"}
		{link_sound "engine_full"		"vehicle/engine/b1bis/full"}
		{link_sound "exhaust"			"vehicle/engine/b1bis/exhaust"}
		{link_sound "move"				"vehicle/tracks/b1bis"}
		{link_sound "rotate_turret"		"vehicle/turret/electric/electric_light"}
	}
	{on spawn
		{add_view "flamer_fire_tank" "flame" "foresight4"}
		{add_view "flamer_fire_barrel" "fire" "foresight4"}
	}
	{on operatable on
		{view start "fire"}
	}
	{on operatable off
		{view stop "fire"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args flamer1 80 4 45)
}
{"d2_ger tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/t70/start"}
		{link_sound "engine_stop"		"vehicle/engine/t70/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t70/idle"}
		{link_sound "engine_full"		"vehicle/engine/t70/full"}
		{link_sound "exhaust"			"vehicle/engine/t70/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz4/"}
		{link_sound "rotate_turret"		"vehicle/turret/electric/electric_light"}
	}
}
{"dicker_max tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"geschuetzwagen_ivb tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/handcrank/handcrank_heavy"}
	}
}
{"hummel tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"jagdpanzer_iv tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"m4a4_firefly_ger tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/m4a4/start"}
		{link_sound "engine_stop"		"vehicle/engine/m4a4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/m4a4/idle"}
		{link_sound "engine_full"		"vehicle/engine/m4a4/full"}
		{link_sound "exhaust"			"vehicle/engine/m4a4/exhaust"}
		{link_sound "move"			"vehicle/tracks/m4"}
		{link_sound "rotate_turret"		"vehicle/turret/electric/electric_light"}
	}
}
{"marder_1fcm_36 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/t70/start"}
		{link_sound "engine_stop"		"vehicle/engine/t70/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t70/idle"}
		{link_sound "engine_full"		"vehicle/engine/t70/full"}
		{link_sound "exhaust"			"vehicle/engine/t70/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz4/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"nashorn tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"ostwind tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz4/"}
		{link_sound "rotate_turret" 		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_gun" 		"vehicle/turret/gun/gun_vertical"}
	}
}
{"panzer3_flamm tank"
	("pz3_sound")
	{on spawn
		{add_view "flamer_fire_tank" "flame" "foresight1"}
		{add_view "flamer_fire_barrel" "fire" "foresight1"}
	}
	{on operatable on
		{view start "fire"}
	}
	{on operatable off
		{view stop "fire"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args gun 60 1 40)
}
{"stug3a tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"stug4g tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"t3476_43_ger tank"
	("t34_sound")
}
{"t3485_44_ger tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/t34/start"}
		{link_sound "engine_stop"		"vehicle/engine/t34/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t34/idle"}
		{link_sound "engine_full"		"vehicle/engine/t34/full"}
		{link_sound "exhaust"			"vehicle/engine/t34/exhaust"}
		{link_sound "move"				"vehicle/tracks/t34"}
		{link_sound "rotate_turret"		"vehicle/turret/electric/electric_light"}
	}
}
{"wirbelwind tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz4/"}
		{link_sound "rotate_turret" 		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_gun" 		"vehicle/turret/gun/gun_vertical"}
	}
}
{"kugelblitz tank"
	{on "event_with_crew"
		{ani_play "open_driver" -1.0 resume}
		{ani_play "open_commander" -1.0 resume}
		{ani_play "open_gunner" -1.0 resume}
	}


	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz4/"}
		{link_sound "rotate_turret" 		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_gun" 		"vehicle/turret/gun/gun_vertical"}
	}
}
;----------------------------------
;----------------------------------
;----------------------------------
{"ba11 tank"
	("ba_sound")
}
{"m3"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/us_halftrack/start"}
		{link_sound "engine_stop"		"vehicle/engine/us_halftrack/stop"}
		{link_sound "engine_idle"		"vehicle/engine/us_halftrack/idle"}
		{link_sound "engine_full"		"vehicle/engine/us_halftrack/full"}
		{link_sound "exhaust"			"vehicle/engine/us_halftrack/exhaust"}
		{link_sound "move"			"vehicle/tracks/m3a1"}
	}
}
{"m17"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/us_halftrack/start"}
		{link_sound "engine_stop"		"vehicle/engine/us_halftrack/stop"}
		{link_sound "engine_idle"		"vehicle/engine/us_halftrack/idle"}
		{link_sound "engine_full"		"vehicle/engine/us_halftrack/full"}
		{link_sound "exhaust"			"vehicle/engine/us_halftrack/exhaust"}
		{link_sound "move"			"vehicle/tracks/m3a1"}
		{link_sound "rotate_turret"		"vehicle/turret/cannon/small"}
		{link_sound "rotate_gun"		"vehicle/turret/cannon/small"}
	}
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
		{add_view	"flash_gun_big"	"flashbarrel02"	"shooter02"}
		{add_view	"flash_gun_big"	"flashbarrel03"	"shooter03"}
	}
	{on fire "mgun" overload
		{if  name "00"
			{view start "flashbarrel00"}
			{delay 0.2
				{view pause "flashbarrel00"}
			}
		else name "01"
			{view start "flashbarrel01"}
			{delay 0.2
				{view pause "flashbarrel01"}
			}
		}
		{if  name "02"
			{view start "flashbarrel02"}
			{delay 0.2
				{view pause "flashbarrel02"}
			}
		else name "03"
			{view start "flashbarrel03"}
			{delay 0.2
				{view pause "flashbarrel03"}
			}
		}
	}
}
{"su57"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/us_halftrack/start"}
		{link_sound "engine_stop"		"vehicle/engine/us_halftrack/stop"}
		{link_sound "engine_idle"		"vehicle/engine/us_halftrack/idle"}
		{link_sound "engine_full"		"vehicle/engine/us_halftrack/full"}
		{link_sound "exhaust"			"vehicle/engine/us_halftrack/exhaust"}
		{link_sound "move"			"vehicle/tracks/m3a1"}
		{link_sound "rotate_turret" 		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_gun" 		"vehicle/turret/gun/gun_vertical"}
	}
}
;----------------------------------
{"churchill4"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz6"}
		{link_sound "rotate_turret"		"vehicle/turret/hydraulic/hydraulic_heavy"}
	}
}
{"is3 tank"
	("is_sound")
}
{"isu122 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/is/start"}
		{link_sound "engine_stop"		"vehicle/engine/is/stop"}
		{link_sound "engine_idle"		"vehicle/engine/is/idle"}
		{link_sound "engine_full"		"vehicle/engine/is/full"}
		{link_sound "exhaust"			"vehicle/engine/is/exhaust"}
		{link_sound "move"			"vehicle/tracks/is/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"kv1e_40 tank"
	("kv_sound")
}
{"kv1e_41 tank"
	("kv_sound")
}
{"kv-122 tank"
	("kv_sound")
}
{"kv220 tank"
	("is_sound")
}
{"su14 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz6/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz6/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz6/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz6/full"}
		{link_sound "exhaust"			"vehicle/engine/pz6/exhaust"}
		{link_sound "move"			"vehicle/tracks/kv/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
;----------------------------------
{"at-1 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/t26/start"}
		{link_sound "engine_stop"		"vehicle/engine/t26/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t26/idle"}
		{link_sound "engine_full"		"vehicle/engine/t26/full"}
		{link_sound "exhaust"			"vehicle/engine/t26/exhaust"}
		{link_sound "move"				"vehicle/tracks/t26/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"bm_8_24 tank"
	("t70_sound")
}
{"kht26 tank"
	("t26_sound")
	{on spawn
		("rand_cut_else" args "cooler1" "cooler2")
		{add_view "flamer_fire" "flame" "foresight1"}
		{add_view "flamer_fire_barrel" "fire" "foresight1"}
	}
	{on operatable on
		{view start "fire"}
	}
	{on operatable off
		{view stop "fire"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args gun 40 1 40)
}
{"m3stuart tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/m3stuart/start"}
		{link_sound "engine_stop"		"vehicle/engine/m3stuart/stop"}
		{link_sound "engine_idle"		"vehicle/engine/m3stuart/idle"}
		{link_sound "engine_full"		"vehicle/engine/m3stuart/full"}
		{link_sound "exhaust"			"vehicle/engine/m3stuart/exhaust"}
		{link_sound "move"			"vehicle/tracks/m3a1_stuart"}
		{link_sound "rotate_turret"		"vehicle/turret/handcrank/handcrank_light"}
	}
}
{"su5 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/t26/start"}
		{link_sound "engine_stop"		"vehicle/engine/t26/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t26/idle"}
		{link_sound "engine_full"		"vehicle/engine/t26/full"}
		{link_sound "exhaust"			"vehicle/engine/t26/exhaust"}
		{link_sound "move"				"vehicle/tracks/t26/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"t18 tank"
	("t27_sound")
}
{"t50 tank"
	("t70_sound")
}
{"t80 tank"
	("t70_sound")
}
;----------------------------------
{"m4a2 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/m4a2/start"}
		{link_sound "engine_stop"		"vehicle/engine/m4a2/stop"}
		{link_sound "engine_idle"		"vehicle/engine/m4a2/idle"}
		{link_sound "engine_full"		"vehicle/engine/m4a2/full"}
		{link_sound "exhaust"			"vehicle/engine/m4a2/exhaust"}
		{link_sound "move"			"vehicle/tracks/m4"}
		{link_sound "rotate_turret"		"vehicle/turret/electric/electric_light"}
	}
}
{"m4a2_76w tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/m4a2/start"}
		{link_sound "engine_stop"		"vehicle/engine/m4a2/stop"}
		{link_sound "engine_idle"		"vehicle/engine/m4a2/idle"}
		{link_sound "engine_full"		"vehicle/engine/m4a2/full"}
		{link_sound "exhaust"			"vehicle/engine/m4a2/exhaust"}
		{link_sound "move"			"vehicle/tracks/m4"}
		{link_sound "rotate_turret"		"vehicle/turret/electric/electric_light"}
	}
}
{"matilda2 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/t70/start"}
		{link_sound "engine_stop"		"vehicle/engine/t70/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t70/idle"}
		{link_sound "engine_full"		"vehicle/engine/t70/full"}
		{link_sound "exhaust"			"vehicle/engine/t70/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz4/"}
		{link_sound "rotate_turret"		"vehicle/turret/electric/electric_light"}
	}
}
{"su76i tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"su85m tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/t34/start"}
		{link_sound "engine_stop"		"vehicle/engine/t34/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t34/idle"}
		{link_sound "engine_full"		"vehicle/engine/t34/full"}
		{link_sound "exhaust"			"vehicle/engine/t34/exhaust"}
		{link_sound "move"				"vehicle/tracks/t34"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"t3476_43_flame tank"
	("t34_sound")
	{on spawn
		{add_view "flamer_fire_tank" "flame" "foresight4"}
		{add_view "flamer_fire_barrel" "fire" "foresight4"}
	}
	{on operatable on
		{view start "fire"}
	}
	{on operatable off
		{view stop "fire"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args flamer1 80 4 45)
}
{"t44 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/t34/start"}
		{link_sound "engine_stop"		"vehicle/engine/t34/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t34/idle"}
		{link_sound "engine_full"		"vehicle/engine/t34/full"}
		{link_sound "exhaust"			"vehicle/engine/t34/exhaust"}
		{link_sound "move"			"vehicle/tracks/t34"}
		{link_sound "rotate_turret"		"vehicle/turret/electric/electric_light"}
	}
}
{"t44_122 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/t34/start"}
		{link_sound "engine_stop"		"vehicle/engine/t34/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t34/idle"}
		{link_sound "engine_full"		"vehicle/engine/t34/full"}
		{link_sound "exhaust"			"vehicle/engine/t34/exhaust"}
		{link_sound "move"			"vehicle/tracks/t34"}
		{link_sound "rotate_turret"		"vehicle/turret/electric/electric_heavy"}
	}
}
{"wolverine tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/m4a2/start"}
		{link_sound "engine_stop"		"vehicle/engine/m4a2/stop"}
		{link_sound "engine_idle"		"vehicle/engine/m4a2/idle"}
		{link_sound "engine_full"		"vehicle/engine/m4a2/full"}
		{link_sound "exhaust"			"vehicle/engine/m4a2/exhaust"}
		{link_sound "move"			"vehicle/tracks/m7"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
;----------------------------------
;----------------------------------



