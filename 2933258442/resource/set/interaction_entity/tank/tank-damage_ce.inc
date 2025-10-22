{on "pre_cookoff" overload						;// Main cookoff decider script (decides which cookoff path is taken)
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

{on "pre_cookoff_open_top" overload						;// Open top vehicle cookoffs
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