{"tank"
    (define "deploy_smoke_screen"
        {if not user_control
            {if not tagged "smoke_screen_launch"
                {if operatable
                    {call "smoke_screen"}
                    {tags add "smoke_screen_launch"}
                    {delay 60
                        {tags remove "smoke_screen_launch"}
                    }
                }   
            }
        }
    )

    {on "deploy_smoke" overload
        ("deploy_smoke_screen")
    }

    {on "tag_reverse_to_repair"
        {tags add "_reversing_to_repair"}
        {delay 20        
            {tags remove "_reversing_to_repair"}
        }
    }

    {on break                       ;// {on break} is for when components break
        {if not tagged "exploded"
            {if not user_control
                {if rand 0.5
                    ("deploy_smoke_screen")
                }
            }
        }
    }

    {on "reverse_to_repair"
        {call "deploy_smoke"}
        {spawn "ai_waypoint_pole_h" "basis" x constrain_after_dir scale 4
            {spawn "ai_waypoint_pole" "reverse_here" x constrain_after_dir
                {tags add "back_up_to_repair"}
            }
            {delay 0.01 {delete}}
        }
        {tags add "_lua_mi"}
        {delay 20        
            {tags remove "_lua_mi"}
        }
    }
}
