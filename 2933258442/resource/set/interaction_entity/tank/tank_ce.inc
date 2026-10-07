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
}
