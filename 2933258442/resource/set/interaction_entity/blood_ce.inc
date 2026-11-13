{"human"
    {on "ce_blood_pool"
        {if rand 0.2
            {call "ce_blood_size_vanilla"}
        else rand 0.25
            {call "ce_blood_size_02a"}
        else rand 0.333333333
            {call "ce_blood_size_03a"}
        else rand 0.5
            {call "ce_blood_size_04a"}
        else
            {call "ce_blood_size_05b"}
        }
    }

    {on "ce_blood_size_vanilla"
        {if rand 0.4
            {spawn "ce_blood_overlap_vanilla_small" "basis" x}
        else rand 0.666666667
            {spawn "ce_blood_overlap_vanilla_medium" "basis" x}
        else
            {spawn "ce_blood_overlap_vanilla" "basis" x}
        }
    }

    {on "ce_blood_size_02a"
        {if rand 0.4
            {spawn "ce_blood_overlap_02a_small" "basis" x}
        else rand 0.666666667
            {spawn "ce_blood_overlap_02a_medium" "basis" x}
        else
            {spawn "ce_blood_overlap_02a" "basis" x}
        }
    }

    {on "ce_blood_size_03a"
        {if rand 0.4
            {spawn "ce_blood_overlap_03a_small" "basis" x}
        else rand 0.666666667
            {spawn "ce_blood_overlap_03a_medium" "basis" x}
        else
            {spawn "ce_blood_overlap_03a" "basis" x}
        }
    }

    {on "ce_blood_size_04a"
        {if rand 0.4
            {spawn "ce_blood_overlap_04a_small" "basis" x}
        else rand 0.666666667
            {spawn "ce_blood_overlap_04a_medium" "basis" x}
        else
            {spawn "ce_blood_overlap_04a" "basis" x}
        }
    }

    {on "ce_blood_size_05b"
        {if rand 0.4
            {spawn "ce_blood_overlap_05b_small" "basis" x}
        else rand 0.666666667
            {spawn "ce_blood_overlap_05b_medium" "basis" x}
        else
            {spawn "ce_blood_overlap_05b" "basis" x}
        }
    }

    {on "ce_blood_splash"
        {if rand 0.5
            {spawn "blood_small"}
        else
            {spawn "blood_medium"}
        }
    }

    {on "ce_blood_pool_once"
        {if dead
            {if not burned
                {if not tagged "ce_blood_pool_spawned"
                    {if not tagged "ce_blood_pool_pending"
                        {tags add "ce_blood_pool_pending"}
                        {delay 1
                            {if dead
                                {if not burned
                                    {if not tagged "ce_blood_pool_spawned"
                                        {tags add "ce_blood_pool_spawned"}
                                        {call "ce_blood_pool"}
                                    }
                                }
                            }
                            {tags remove "ce_blood_pool_pending"}
                        }
                    }
                }
            }
        }
    }

	{on "hit-light" overload
		{if not dead
			{spawn "ce_hit_blood_small"}
		}
	}

	{on "hit-heavy" overload
		{spawn "ce_hit_blood_medium"}
	}

	{on "die_with_blood" overload
		{if not able "personage"
			{if not burned
				{call "ce_blood_splash"}
				{delay 2
					{call "ce_blood_pool_once"}
				}
			}
			{tags add "_bleedout_"}
		}
		{call "die_without_blood"}
	}

	{on ground_hit overload
		{if linked "parachute_attach"
			{tags remove "can_die"}
			{unlink}

		else tagged "can_die"
			{tags add "call_die"}
			{call "die"}
			{kill_delay "parachute"}
			{tags remove "can_die"}
			{tags remove "eject"}
			{call "disable_physics"}
		else
			{if min_speed 10
				{spawn "blood_medium" "basis" x}
				{call "ce_blood_splash"}
			}
		}
		{call "ce_blood_pool_once"}
		{if tagged "paratrooper"
			{if not user_control
				{if not dead
					{tags add "paratrooper_need_orders"}
					{delay 120 "para_orders_timer"
						{tags remove "paratrooper_need_orders"}
					}
				}
			}
			{tags remove "paratrooper"}
		}
	}

	{on "explosion" overload
		{if not dead
			{if not burned
				{spawn "ce_blood_blast"}
			}
		}
		{spawn "blood_medium"}
		{call "die"}
	}

	{on "stop_personage" overload
		{set "die_sound" 0}
		{view pause "marker_personage"}
		{view pause "marker_personage_acute"}
		{if tagged "start_personage"
			{delay 1
				{if dead
					{call "ce_blood_pool_once"}
					{tags add "_bleedout_"}
				}
			}
		}
		{tags remove "start_personage"}
	}

	{on "spawn_blood_delayed" overload
		{call "ce_blood_splash"}
		{tags add "blood_delay_active"}
		{delay 1.0
			{tags remove "blood_delay_active"}
		}
	}
}
