{"ce_register_sabotage_vehicles"
    {"select"
        {source advanced}
        {group
            {select
                {tag {tag _ai}}
            }
            {include
                {prop {prop vehicle}}
                {state {state operatable}}
                {zone {zone "gamezone"}}
            }
            {exclude
                {state {state user_control}}
                {state {state inactive}}
                {prop {prop airborne}}
                {tag {tag _user}}
                {tag {tag _user_ally}}
                {tag {tag supplies}}
                {tag {tag sabotage_checked}}
            }
        }
    }
    {"entity_state"
        {selector {source current}}
        {tag_add sabotage_checked}
    }
    {"entity_state"
        {selector {source current}}
        {tag_add sabotage_possible}
    }
}

{"ce_arm_garrison_sabotage"
    {"select"
        {source advanced}
        {group
            {select
                {tag {tag "+garrisoned"}}
                {tag {tag cmp_def}}
                {tag {tag cmp_mg}}
            }
            {include
                {prop {prop vehicle}}
                {state {state operatable}}
                {zone {zone "gamezone"}}
            }
            {exclude
                {state {state user_control}}
                {state {state inactive}}
                {prop {prop airborne}}
                {tag {tag _user}}
                {tag {tag _user_ally}}
                {tag {tag supplies}}
                {tag {tag sabotage_checked}}
            }
        }
    }
    {"entity_state"
        {selector {source current}}
        {tag_add sabotage_checked}
    }
    {"entity_state"
        {selector {source current}}
        {tag_add sabotage_possible}
    }
}
