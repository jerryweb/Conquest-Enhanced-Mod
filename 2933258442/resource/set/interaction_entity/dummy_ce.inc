(define "spawn_waypoint_poles_x4"
	{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}
	{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}
	{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}
	{spawn "ai_waypoint_pole" random_position 6000 constrain_after_dir scale 4.0}
)

{"flag"
	{on spawn
		{delay 3
			(mod "mp"
				("spawn_waypoint_poles_x4")
				("spawn_waypoint_poles_x4")
				("spawn_waypoint_poles_x4")
				("spawn_waypoint_poles_x4")
			)   
		}
    }
}


{"waypoint_graph_key"
	{on spawn
		{tags add "waypoint_graph_present"}
	}
}

{"ai_waypoint_pole"
	{on spawn
		{tags add "drop_zone"}
	}

	(define "spawn_object_for_defense"
		{if terrain_fx "ice"
			{spawn %object random_position 500 random_orientation constrain_after_dir {tex_mod "win"}}  
		else terrain_fx "snow"
			{spawn %object random_position 500 random_orientation constrain_after_dir {tex_mod "win"}}
		else terrain_fx "deep_water"
			;// don't spawn
		else
			{spawn %object random_position 500 random_orientation constrain_after_dir}
		}
	)

	{on "spawn_hedgehogs"
		{start_sound "vehicle/deploy/foxhole"}
		{spawn "building_smoke" "fx_dirt01"}
		{spawn "building_smoke" "fx_dirt02"}
		{spawn "building_smoke" "fx_dirt03"}
		{spawn "building_smoke" "fx_dirt04"}
		{spawn "building_smoke" "fx_dirt05"}
		{link_sound "trench_deploy" "vehicle/deploy/trench/"}
		{play_sound "trench_deploy"}
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
		("spawn_object_for_defense" object("hedgehog"))
	}
}

{"map_point_conquest"
	{on spawn
		{delay 1
			(mod "mp"
				{spawn "ai_waypoint_pole" 
					{tags add "spawn_anchor"}
				}
			)   
		}
    }
}

{"hedgehog_service"
     {on spawn
        {tags add "player_hedgehog"}
    }
    {on "set_dynamite"
    	{spawn "satchel_charge_rus" random_position 30
    		{delay 0.5
    			{call "onThrow"}
    			{delay 8
    				{call "explosion"}
    			}
    		}
    	}
    	{tags add "dynamite_set"}
    }
}