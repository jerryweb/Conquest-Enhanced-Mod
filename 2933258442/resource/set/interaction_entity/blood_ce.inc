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
}
