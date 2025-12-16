;/*=========== Generic Weapon Settings Begin ===========*/
{"stuff weapon"
	{on "drop_item"}			;// when item is not in hand and is dropped from inventory.
	
	{on "fire"
		{play_sound "mid"}
		{play_sound "far"}
		{play_sound "action_recoil"}
		{ani_play "recoil"}
		{view show "flashbarrel"}
		{view start "flashbarrel"}
		{delay 0.2 "fire"
			{view hide	"flashbarrel"}
			{view pause	"flashbarrel"}
		}
	}
	{on "link_human"
		{play_sound "holster"}
		{delay 0.4
			{ani_play "prepare"}
		}
	}
	{on "unlink_human"
		{ani_play "prepare" -1}
	}
	{on "case_eject"
		{view start "shell"}
		{view show	"ejectsmoke"}
		{view start	"ejectsmoke"}
		{delay 0.1 "shell"
			{view pause "shell"}
			{view hide	"ejectsmoke"}
			{view pause	"ejectsmoke"}
		}
	}
	{on "weapon_reload"
		{kill_delay "bolt_action"}
		{ani_play "reload"}
		{call "magazine_delay"}
		{play_sound "eject_clip"}
		{delay 0.075
			{stop_sound "action_recoil"}
		}
	}
	(define "magazine"
		{on "magazine_delay" %override
			{delay %cut
				{view hide "bullet"}
				{tear "piece_tiny_steel" bone "magazine" copy
					%impulse
				}
				{delay 0
					{view hide "magazine"}
					{delay %show
						{view show "magazine"}
						{view show "bullet"}
					}
				}
			}
		}
	)
	("magazine" cut(0) show(1.8) override() impulse({impulse up -0.01 com}))

	(define "drop"
		{on ground_hit %override
			{if terrain_fx "road"
				{start_sound "weapon/drop/%material/rock"}
			
			else terrain_fx "rock"
				{start_sound "weapon/drop/%material/rock"}

			else terrain_fx "ice"
				{start_sound "weapon/drop/%material/rock"}
			
			else terrain_fx "snow"
				{start_sound "weapon/drop/%material/snow"}
			
			else terrain_fx "sand"
				{start_sound "weapon/drop/%material/snow"}
			
			else terrain_fx "bridge_wood"
				{start_sound  "weapon/drop/%material/wood"}
			
			else terrain_fx "shallow_water"

			else terrain_fx "water"

			else
				{start_sound "weapon/drop/%material/ground"}
			}
		}
	)
	("drop" material(metal) override())
}

{"stuff weapon stg44"						;// props added to StG 44 and MKb 42(H)
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/StG44New/"}
		{link_sound "mid"		"weapon/shot/smallarms/s2/d2/GER/StG44New/"}
		{link_sound "far"		"weapon/shot/smallarms/s2/d3/GER/StG44New/"}
	}
	("magazine" cut(1.20) show(1.95) override(overload) impulse({impulse up -0.01}))
}

(define "shell_fx"
	{"stuff weapon %tag"
		{on spawn
			{add_view "%shell" "shell" "fxshell"}
		}
	}
)

("shell_fx" tag(shell_cannon)			shell(shell_cannon))