;{"td -turret muzzle_150mm_155mm_sides"
;    {on "spg_reverse_to_reload"
;        {delay 2
;            {call "deploy_smoke"}
;        }
;        {spawn "ai_waypoint_pole_h" "basis" x constrain_after_dir scale 4
;            {spawn "ai_waypoint_pole" "reverse_here" x constrain_after_dir
;                {tags add "back_up_to_reload"}
;            }
;            {delay 0.01 {delete}}
;        }
;    }
;
;
;    {on fire "gun"
;        {if not user_control
;            {if operatable
;                {tags add "spg_fired"}
;                {delay 2
;                    {tags remove "spg_fired"}
;                }
;            }
;        }
;    }
;}
;
;{"spg muzzle_122mm_128mm"
;    {on "spg_reverse_to_reload"
;        {delay 2
;            {call "deploy_smoke"}
;        }
;        {spawn "ai_waypoint_pole_h" "basis" x constrain_after_dir scale 4
;            {spawn "ai_waypoint_pole" "reverse_here" x constrain_after_dir
;                {tags add "back_up_to_reload"}
;            }
;            {delay 0.01 {delete}}
;        }
;    }
;
;
;    {on fire "gun"
;        {if not user_control
;            {if operatable
;                {tags add "spg_fired"}
;                {delay 2
;                    {tags remove "spg_fired"}
;                }
;            }
;        }
;    }
;}
;
;{"sturmtiger"
;    {on "spg_reverse_to_reload"
;        {delay 2
;            {call "deploy_smoke"}
;        }
;        {spawn "ai_waypoint_pole_h" "basis" x constrain_after_dir scale 4
;            {spawn "ai_waypoint_pole" "reverse_here" x constrain_after_dir
;                {tags add "back_up_to_reload"}
;            }
;            {delay 0.01 {delete}}
;        }
;    }
;
;
;    {on fire "gun"
;        {if not user_control
;            {if operatable
;                {tags add "spg_fired"}
;                {delay 2
;                    {tags remove "spg_fired"}
;                }
;            }
;        }
;    }
;};

{"bergepanther tank"
	("pz5_sound")
	{on spawn
		{add_view	"repair"		"repair"	"hearing_bone"}
		{tags add "ai_engineer_vehicle"}
		{link_sound "screw_twist"		"human/anims/repair/screw_twist/"}
		{link_sound "wrench_turn"		"human/anims/repair/wrench_turn/"}
		{link_sound "toolbox_open"		"human/anims/repair/toolbox_open/"}
		{link_sound "toolbox_close"		"human/anims/repair/toolbox_close/"}
		{link_sound "tool_equip"		"human/anims/repair/tool_equip/"}
	}
	{on break
		{if not tagged "exploded"
			{if component "trackright"
				{tags add "major_broken1"}
				{tags add "major_broken"}
			else component "trackleft"
				{tags add "major_broken2"}
				{tags add "major_broken"}
			else component "engine"
				{tags add "major_broken3"}
				{tags add "major_broken"}
			}
		}
    }
	{on repair
		{if not tagged "exploded"
			{if component "trackleft"
			 	{tags remove "major_broken2"}
				{if not tagged "major_broken1"
					{tags remove "major_broken"}
				}
				{if not tagged "major_broken3"
					{tags remove "major_broken"}
				}
			}	
			{if component "trackright"
			 	{tags remove "major_broken1"}
				{if not tagged "major_broken2"
					{tags remove "major_broken"}
				}
				{if not tagged "major_broken3"
					{tags remove "major_broken"}
				}
			}
			{if component "engine"
			 	{tags remove "major_broken3"}
				{if not tagged "major_broken1"
					{tags remove "major_broken"}
				}
				{if not tagged "major_broken2"
					{tags remove "major_broken"}
				}
			}
		}
	}	
	{on "recovery_repair"			
;		("repair_sounds_1")
		{delay 12
;			("repair_sounds_2")
		}
		{delay 24
;			("repair_sounds_1")
		}
		{delay 36
;			("repair_sounds_2")
		}
		{delay 48
;			("repair_sounds_1")
		}
		{view start "repair"}
		{spawn "recovery_repair_start" "basis"}
		{delay 0.5
			{spawn "recovery_repair_remover_effect" "basis"}
		}
		{delay 1
			{spawn "recovery_repair_checker_effect" "basis"}
		}
		{chassis_work 0}
		{damage_report "recovery_message_start" "<c(f3ff00)>Starting Repairs"}
		{delay 1 ;//SafeSwitch To avoid self Repair
			{tags remove "recovery_repair"}
		}
		{delay 40
			{if operatable
				{if not tagged "major_broken"
					{spawn "recovery_repair_area" "basis"}
					{spawn "recovery_repair_remover" "basis"}
					{delay 1
						{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Complete"}
						{view pause "repair"} 
						{chassis_work 1}
						{call "engine_on"}
					}
				}	
				{if tagged "major_broken1"
					{spawn "recovery_repair_area" "basis"}
					{spawn "recovery_repair_remover" "basis"}
					{delay 1
						{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Complete"}
						{view pause "repair"} 
						{call "engine_on"}
					}
					{delay 1.5
						{chassis_work 0}
					}
				}	
				{if tagged "major_broken2"
					{spawn "recovery_repair_area" "basis"}
					{spawn "recovery_repair_remover" "basis"}
					{delay 1
						{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Complete"}
						{view pause "repair"} 
						{call "engine_on"}
					}
					{delay 1.5
						{chassis_work 0}
					}
				}	
				{if tagged "major_broken3"
					{spawn "recovery_repair_area" "basis"}
					{spawn "recovery_repair_remover" "basis"}
					{delay 1
						{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Complete"}
						{view pause "repair"} 
						{call "engine_on"}
					}
					{delay 1.5
						{chassis_work 0}
					}	
				}
				{if not operatable
					{spawn "recovery_repair_remover_effect" "basis"}
					{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Failed"}
					{view pause "repair"} 
					{chassis_work 1}
					{call "engine_on"}
				}		
			}	
		}	
	}
}