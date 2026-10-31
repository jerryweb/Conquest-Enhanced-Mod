{on operatable on
    {if tagged "sabotage_possible"
        {if user_control
            {tags remove "sabotage_possible"}
            {if rand 0.5
                {delay 0.1
                    {if user_control
                        {damage_report "sabotage" "<s(10)b+c(#FF0000)>SABOTAGE"}
                        {if not operatable
                            {if able "repair"
                                {clear_inventory}
                                {call_synced "explosion"}
                            }
                        else
                            {clear_inventory}
                            {call_synced "break_all"}
                        }
                    }
                }
            }
        }
    }
}
