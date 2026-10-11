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