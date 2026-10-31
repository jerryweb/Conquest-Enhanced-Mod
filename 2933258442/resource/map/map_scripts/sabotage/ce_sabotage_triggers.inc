{"conquest_enhanced_mechanics/sabotage/notify"
    {condition
        {terms
            {"1.cmp_i" {var "ai_sabotage$"} {op "=="} {value 1}}
            {"2.entities"
                {selector
                    {tag sabotage_checked}
                    {amount 1}
                }
            }
        }
    }
    {actions
        {"delay" {time 15}}
        {"talk"
            {selector
                {source advanced}
                {group
                    {select
                        {zone {zone "gamezone"}}
                    }
                    {include
                        {prop {prop human}}
                        {state {state linked}}
                    }
                    {exclude
                        {state {state user_control}}
                        {state {state dead}}
                        {state {state inactive}}
                        {tag {tag _user_ally}}
                    }
                }
                {amount 1}
            }
            {text "mission/multi/ai_sabotage_notify"}
        }
        {"delay" {time 10}}
        {"talk"
            {selector
                {source advanced}
                {group
                    {select
                        {zone {zone "gamezone"}}
                        {tag {tag player}}
                    }
                    {include
                        {prop {prop human}}
                        {state {state user_control}}
                        {state {state operatable}}
                    }
                    {exclude
                        {state {state dead}}
                        {state {state inactive}}
                    }
                }
                {amount 1}
            }
            {text "mission/multi/player_sabotage_notify"}
        }
    }
}
