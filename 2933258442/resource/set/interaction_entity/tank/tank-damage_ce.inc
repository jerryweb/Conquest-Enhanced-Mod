{on "ammo_break"
	{call "stat_break"}
	{if rand 0.25
		{call_synced "ammo_explosion"}
	else
		{call_synced "pre_cookoff"}
	}
}

{on "ammo_explosion"
	{if not tagged "ammo_cooked2"
		{tags add "ammo_broken"}
		{call "explosion"}
	}
}

{on "pre_cookoff"						;// Main cookoff decider script (decides which cookoff path is taken)
	{if not tagged "ammo_cooked"
		{call "stat_break"}
		{able minimap 0}
		{able select 0}
		{able repaired 0}
		{tags add "ammo_cooked"}
		{tags add "no_scavenge"}		;// tag for conquest so that vehicle cannot be repaired/recovered
		{if not tagged "_ai_defender"
			{mark_for_persistence}			;// Conquest map persistence
		}
		{link_sound "cook_off" "detonation/cook_off/cook"}
		{link_sound "cook_off" "detonation/cook_off/transition"}
		{link_sound "burnup_ammo" "detonation/cook_off/burn_ammo"}
		{call "engine_off"}
		{if tagged "vehicle_destroyed" ;// vehicle already burning so no build up
			;//random explosion timer
			{if rand 0.25
				{delay 7 7
					{call_synced "cookoff_rand_explosion"}
				}
			}

			;//explosion and slightly delayed normal cookoff
			{if rand 0.7
				{call_synced "rand_hatch_normal_explosion"}

			;//instant normal cookoff
			else
				{call_synced "normal_cookoff"}
			}
		else
			;// 1st Path pre smoke cookoff
			{if rand 0.3

				;//random explosion timer
				{if rand 0.25
					{delay 11 11
						{call_synced "cookoff_rand_explosion"}
					}
				}

				;// explosion at hatch
				{call_synced "rand_hatch_pre_smoke_explosion"}

			;// 2nd Path to pre smoke cookoff
			else rand 0.4

				;//random explosion timer
				{if rand 0.25
					{delay 12 12
						{call_synced "cookoff_rand_explosion"}
					}
				}

				;//delayed presmoke cookoff
				{if rand 0.3
					{call_synced "rand_pre_smoke_delay"}

				;//instant presmoke cookoff
				else
					{call_synced "rand_pre_smoke"}
				}

			;// 3rd Path to normal cookoff path
			else rand 0.3

				;//random explosion timer
				{if rand 0.25
					{delay 7 7
						{call_synced "cookoff_rand_explosion"}
					}
				}

				;//explosion and slightly delayed normal cookoff
				{if rand 0.7
					{call_synced "rand_hatch_normal_explosion"}

				;//instant normal cookoff
				else
					{call_synced "normal_cookoff"}
				}
			else ;// slow burn cookoff
				{if rand 0.25 
					{delay 250 100
						{call_synced "cookoff_rand_explosion"}
					}
				}
				{call_synced "slow_cookoff"}
			}
		}
	}
}

{on "slow_cookoff"
	{if not tagged "slow_cookoff"
		{tags add "slow_cookoff"}
		{ani_wind "open" end}
		{if rand 0.5
			{call_synced "slow_cookoff_1"}
		else
			{call_synced "slow_cookoff_2"}
		}
		{delay 30 20 "slow_cookoff1"
			{view pause "cooking_presmoke_1"}
			{if rand 0.5
				{call_synced "slow_cookoff_3"} ;// continue smoke buildup
			else
				{call_synced "slow_cookoff_4"} ;// hatch fire
			}
		}
	}
}
{on "slow_cookoff_1"
	{delay 3 "slow_cookoff2"
		{call "emit_crew"}
		{delay 1
			{view start "cooking_presmoke_1"}
		}
	}
}
{on "slow_cookoff_2"
	{view start "cooking_presmoke_1"}
	{delay 3 {call "burn_emit"}}
}
{on "slow_cookoff_3"
	{view start "cooking_presmoke_2"}
	{delay 60 60 "slow_cookoff3"
		{call_synced "slow_cookoff_4"} ;// hatch fire
	}
}
{on "slow_cookoff_4"
	{view pause "cooking_presmoke_2"}
	{link_sound "hatch_fire" "fire/loops/big"}
	{view show "cooking_hatch_fire"}
	{view start "cooking_hatch_fire"}
	{play_sound "hatch_fire" 1}
	{delay 500 150 "slow_cookoff4"
		{if rand 0.8
			{call_synced "slow_cookoff_5"} ;// normal cookoff
		else
			{call_synced "slow_cookoff_6"} ;// slow burn no cookoff
		}
	}
}
{on "slow_cookoff_5"
	{spawn "fire_cooking_explosion" "FXfire3"}
	{delay 0.6 "slow_cookoff5"
		{stop_sound "hatch_fire"}
		{view pause "cooking_hatch_fire"}
		{call "normal_cookoff"}
	}
}
{on "slow_cookoff_6"
	{delay 150 50 "slow_cookoff6"
		{call_synced "slow_cookoff_6_events"}
	}
}

{on "slow_cookoff_6_events"
	{stop_sound "hatch_fire"}
	{view pause "cooking_hatch_fire"}
	{view start "cooking_hatch_smoke"}
	{tags add "ammo_cooked2"}
}

{on "pre_smoke_cookoff"		;// pre-smoke delayed normal cookoff path
	{if not tagged "pre_smoke_cookoff"
		{tags add "pre_smoke_cookoff"}
		{view start "cooking_presmoke_1"}
		{start_sound "detonation/cook_off/internal_explosions"}
		{delay 3
			{call "burn_emit"}
		}

		;// build up of smoke to cookoff
		{delay 8 6 "cookoff4"
			{if not able "exploded"
				{view stop "cooking_presmoke_1"}
				{view start "cooking_presmoke_2"}
				{start_sound "detonation/cook_off/internal_explosions"}

				{if rand 0.3
					{call_synced "rand_barrel_fire"}
				}

				{delay 1.5 0.5 "cookoff5"
					{if tagged "barrel_fire"
						{view pause "cooking_barrel_aftersmoke"}
						{view start "cooking_barrel_smoke"}
					}
					{view stop "cooking_presmoke_2"}
					{view start "cooking_presmoke_3"}
					{start_sound "detonation/cook_off/internal_explosions"}

					{delay 0.4 0.2
						{start_sound "detonation/cook_off/internal_explosions"}
					}
					{delay 0.8 0.2
						{start_sound "detonation/cook_off/internal_explosions"}
					}
					{delay 1.5 0.5 "cookoff6"
						{view stop "cooking_presmoke_3"}
						{call_synced "normal_cookoff"}
					}
				}
			}
		}
	}
}

{on "normal_cookoff"		;//normal cookoff, instant
	{if not able "exploded"
		{if not tagged "ammo_cooked2"
			{if rand 0.5
				{call_synced "rand_hatch_explosion"}
			}
			{if rand 0.4
				{call_synced "turret_ring_fire"}
			}
			{if tagged "barrel_fire"					;// barrel smoke turns into fire
				{view stop "cooking_barrel_smoke"}
				{view start "cooking_barrel_fire"}
			}

			{fire radius 4 time 4 heating 0.5}
			{kill_crew}
			{clear_inventory}
			{link_sound "hatch_fire" "fire/loops/big"}
			{view show "cooking_high"}
			{view start "cooking_high"}
			{ani_wind "open" end}
			{ani_wind "open1" end}
			{play_sound "cook_off" 1}
			{play_sound "burnup_ammo" 1}

			{delay 10 2 "cookoff7"
				{view show "cooking_high_2"}
				{view start "cooking_high_2"}
				{view start "cooking_turret_smoke"}
				{view hide "cooking_high"}
				{view stop "cooking_high"}
				{view stop "cooking_turret_fire"}
				{stop_sound "burnup_ammo"}
				{start_sound "detonation/cook_off/transition"}

				{delay 4 2 "cookoff8"
					{stop_sound "cook_off"}
					{start_sound "detonation/cook_off/transition"}
					{view show "cooking_hatch_fire"}
					{view start "cooking_hatch_fire"}
					{play_sound "hatch_fire" 1}
					{view hide "cooking_high_2"}
					{view stop "cooking_high_2"}
					{call_synced "tags_add_ammo_cooked2"}

					{if tagged "barrel_fire"
						{view start "cooking_barrel_aftersmoke"}
						{view stop "cooking_barrel_fire"}
					}
					{delay 60 10 "cookoff9"
						{view start "cooking_hatch_smoke"}
						{view hide "cooking_hatch_fire"}
						{view stop "cooking_hatch_fire"}
						{stop_sound "hatch_fire"}
					}
				}
			}
		}
	}
}

{on "tags_add_ammo_cooked"
	{tags add "ammo_cooked"}
}
{on "tags_add_ammo_cooked2"
	{tags add "ammo_cooked2"}
}

{on "rand_pre_smoke_delay"
	{delay 1 "cookoff1"
		{call "burn_emit"}
		{delay 2 "cookoff2"
			{ani_play "open" +1.0 resume}
			{call "pre_smoke_cookoff"}
		}
	}
}

{on "rand_pre_smoke"
	{call "pre_smoke_cookoff"}
	{ani_wind "open" end}
	{ani_wind "open1" end}
}

{on "rand_hatch_normal_explosion"
	{spawn "fire_cooking_explosion" "FXfire3"}
	{start_sound "detonation/he_size1/bkg/"}
	{ani_wind "open" end}
	{ani_wind "open1" end}
	{call "kill_crew_chance"}
	{call "burn_emit"}
	{delay 0.8 0.4 "cookoff3"
		{call "normal_cookoff"}
	}
}

{on "rand_hatch_pre_smoke_explosion"
	{spawn "fire_cooking_explosion" "FXfire3"}
	{start_sound "detonation/he_size1/bkg/"}
	{call "kill_crew_chance"}
	{call "pre_smoke_cookoff"}
	{ani_wind "open" end}
	{ani_wind "open1" end}
}

{on "rand_barrel_fire"
	{view start "cooking_barrel_aftersmoke"}
	{tags add "barrel_fire"}
}

{on "rand_hatch_explosion"
	{spawn "fire_cooking_explosion" "FXfire3"}		;// hatch explosion
	{start_sound "detonation/he_size1/bkg/"}
}

{on "turret_ring_fire"
	{view start "cooking_turret_fire"}				;// turret ring fire
}

{on "cookoff_rand_explosion"	;// calls random explosion that can happen during cookoff
	{tags add "ammo_broken"}
	{call "kill_cookoff"}
	{call "explosion"}
}

{on "kill_cookoff"			;//stops all cookoff delays and sounds
	{kill_delay "cookoff1"}
	{kill_delay "cookoff2"}
	{kill_delay "cookoff3"}
	{kill_delay "cookoff4"}
	{kill_delay "cookoff5"}
	{kill_delay "cookoff6"}
	{kill_delay "cookoff7"}
	{kill_delay "cookoff8"}
	{kill_delay "cookoff9"}
	{kill_delay "cookoff_open1"}
	{kill_delay "cookoff_open2"}
	{kill_delay "cookoff_open3"}
	{kill_delay "slow_cookoff1"}
	{kill_delay "slow_cookoff2"}
	{kill_delay "slow_cookoff3"}
	{kill_delay "slow_cookoff4"}
	{kill_delay "slow_cookoff5"}
	{kill_delay "slow_cookoff6"}
	{tags add "cookoff_killed"}
	{stop_sound "cook_off"}
	{stop_sound "burnup_ammo"}
	{start_sound "detonation/cook_off/transition"}
}

{on "kill_crew_chance"
	{if rand 0.75	{call_synced "kill_gunner"}}
	{if rand 0.75	{call_synced "kill_gunner2"}}
	{if rand 0.75	{call_synced "kill_gunner3"}}
	{if rand 0.75	{call_synced "kill_gunner4"}}
	{if rand 0.75	{call_synced "kill_gunner5"}}
	{if rand 0.75	{call_synced "kill_charger"}}
	{if rand 0.75	{call_synced "kill_charger2"}}
	{if rand 0.75	{call_synced "kill_charger3"}}
	{if rand 0.75	{call_synced "kill_charger4"}}
	{if rand 0.75	{call_synced "kill_commander"}}
	{if rand 0.75	{call_synced "kill_driver"}}
}

{on "pre_cookoff_open_top"						;// Open top vehicle cookoffs
	{if not tagged "ammo_cooked"
		{call "stat_break"}
		{able minimap 0}
		{able select 0}
		{able repaired 0}
		{tags add "ammo_cooked"}
		{tags add "no_scavenge"}		;// tag for conquest so that vehicle cannot be repaired/recovered
		{if not tagged "_ai_defender"
			{mark_for_persistence}			;// Conquest map persistence
		}
		{link_sound "fire" "fire/loops/big"}
		{link_sound "cook_off" "detonation/cook_off/cook-off"}
		{link_sound "burnup_ammo" "detonation/cook_off/burn_ammo"}
		{call "engine_off"}
		{if tagged "vehicle_destroyed" ;// vehicle already burning so no build up
			;//random explosion timer
			{if rand 0.25
				{delay 7 7
					{call_synced "cookoff_rand_explosion"}
				}
			}
			{call_synced "normal_open_top_cookoff"}
		else
			;//random explosion timer
			{if rand 0.5
				{if rand 0.25
					{delay 30 30
						{call_synced "cookoff_rand_explosion"}
					}
				}
				{call_synced "slow_open_top_cookoff"}
			else
				{if rand 0.25
					{delay 11 11
						{call_synced "cookoff_rand_explosion"}
					}
				}
				{call_synced "normal_open_top_cookoff"}
			}
		}
	}
}
{on "slow_open_top_cookoff"
	{if not tagged "exploded"
		{call "kill_crew_chance"}
		{call "burn_emit"}
		{view start "smoke_vehicle_death"}
		{delay 10 10
			{if not tagged "exploded"
				{view pause "smoke_vehicle_death"}
				{view start "fire_vehicle_death"}
				{play_sound "fire" 1}
				{delay 60 60
					{if not tagged "exploded"
						{view pause "fire_vehicle_death"}
						{stop_sound "fire"}
						{call_synced "ammo_explosion_small_2"}
						{call_synced "normal_open_top_cookoff"}
					}
				}
			}
		}
	}
}
{on "normal_open_top_cookoff"
	{if not able "exploded"
		{fire radius 4 time 4 heating 0.5}
		{kill_crew}
		{clear_inventory}
		{view show "cooking_high_open"}
		{view start "cooking_high_open"}
		{play_sound "cook_off" 1}
		{play_sound "burnup_ammo" 1}

		{delay 10 2 "cookoff_open1"
			{view show "cooking_high_open_2"}
			{view start "cooking_high_open_2"}
			{view hide "cooking_high_open"}
			{view stop "cooking_high_open"}
			{stop_sound "burnup_ammo"}
			{start_sound "detonation/cook_off/transition"}
			{delay 10 2 "cookoff_open2"
				{stop_sound "cook_off"}
				{start_sound "detonation/cook_off/transition"}
				{view hide "cooking_high_open_2"}
				{view stop "cooking_high_open_2"}
				{call_synced "tags_add_ammo_cooked2"}
				{if not tagged "exploded"
					{view start "fire_vehicle_death"}
					{play_sound "fire" 1}
					{delay 400 60 "cookoff_open3"
						{if not tagged "exploded"
							{view pause "fire_vehicle_death"}
							{view start "smoke_vehicle_death"}
							{stop_sound "fire"}
						}
					}
				}
			}
		}
	}
}
;/*=========== Ammo Break End ===========*/
