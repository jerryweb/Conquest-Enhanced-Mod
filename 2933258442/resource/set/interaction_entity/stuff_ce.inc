{"bullet_sound"
	{on spawn
		;// link all possible sounds for projectiles
		{delay 0 ;// required
		;// check for specific bone names in the {view "entity"} of the weapons ammo file
			{if bone "sound_shell_high_vel"		;// high velocity shells
				{link_sound "shell_high"		"projectile/shell/standard_high/"}
				{play_sound "shell_high"}
			}	
		}
	}
}