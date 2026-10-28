{"airborne"
    {on "move_plane_to_initial_waypoint" 
        {set "landing" 1}
        {call "takeoff_load"}
        {call "takeoff"} 
        {tags add "_bot"} 
        
        {delay 4
            {if prop "drop_plane"
                {tags add "transport_plane_ready_for_mission"}
            else 
                {tags add "plane_ready_for_mission"}
            } 
        }        
    }

    {on "bomber_make_first_pass"
        {tags remove "plane_ready_for_mission"}
        {delay 40 
            {tags remove "enemy_air"}
            {tags add "bomber_making_first_pass"}
        }
    }
}

{"drop_plane"
    (define "eject_troopers"
        {delay %delay
            {with_linked_entity %seat
                {unlink}
                {if not user_control
                    {tags add "paratrooper"}    
                    {tags add "ignore_spawn_logic"} 
                else 
                    {tags add "player_paratrooper"} 
                }
                        
            }
        }   
    )

    {on "drop_paratroopers"
        {tags add "dropping_troopers"}
        {spawn "artillery_warning_light"}   
        ;("drop_vehicle"   delay(4.5))
    
        ("eject_troopers" delay(1)      seat("seat1"))
        ("eject_troopers" delay(2)    seat("seat2"))
        ("eject_troopers" delay(3)      seat("seat3"))
        ("eject_troopers" delay(4)    seat("seat4"))
        ("eject_troopers" delay(5)      seat("seat5"))
        ("eject_troopers" delay(6)    seat("seat6"))
        ("eject_troopers" delay(7)      seat("seat7"))
        ("eject_troopers" delay(8)      seat("seat8"))
        ("eject_troopers" delay(9)    seat("seat9"))
        
        ("eject_troopers" delay(1)    seat("seat01"))
        ("eject_troopers" delay(2)    seat("seat02"))
        ("eject_troopers" delay(3)    seat("seat03"))
        ("eject_troopers" delay(4)    seat("seat04"))
        ("eject_troopers" delay(5)    seat("seat05"))
        ("eject_troopers" delay(6)    seat("seat06"))
        ("eject_troopers" delay(7)    seat("seat07"))
        ("eject_troopers" delay(8)    seat("seat08"))
        ("eject_troopers" delay(9)    seat("seat09"))

        ("eject_troopers" delay(10)    seat("seat10"))
        ("eject_troopers" delay(11)    seat("seat11"))
        ("eject_troopers" delay(12)    seat("seat12"))
        ("eject_troopers" delay(13)    seat("seat13"))
        ("eject_troopers" delay(14)    seat("seat14"))
        ("eject_troopers" delay(15)    seat("seat15"))
        ("eject_troopers" delay(16)    seat("seat16"))
        ("eject_troopers" delay(17)    seat("seat17"))
        ("eject_troopers" delay(18)    seat("seat18"))
        ("eject_troopers" delay(19)    seat("seat19"))
        ("eject_troopers" delay(20)    seat("seat20"))

        {delay 25 
            {hide 5}
        }
    }

    {on "prep_drop_plane_to_move"
        {tags remove "selected_transport_plane"}
        {delay_ex 12 6 "drop_move_timer"
            {call "drop_paratroopers"}
        }
    }

    {on break               ;// component breaks
        {if not tagged "exploded"
            {if chassis "airborne"
                {if component "body"
                    {if not tagged "dropping_troopers"
                        {if rand 0.5
                            {call "drop_paratroopers"}
                        }
                    }
                }
            }
        }
    }

    {on destroy             ;// component destroyed
        {if not tagged "exploded"
            {if chassis "airborne"
                {if not tagged "dropping_troopers"
                    {call "drop_paratroopers"}
                }
            }
        }
    }

    {on "die"
        {kill_delay "drop_move_timer"}
    }
}