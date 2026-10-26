{"airborne"
    {on "move_plane_to_initial_waypoint" 
        {set "landing" 1}
        {call "takeoff_load"}
        {call "takeoff"} 
        {tags add "_bot"}  
        {delay 3
            {tags add "plane_ready_for_mission"}
        } 
    }
}