{"foxhole_destroy"  ;// New sandbags with FX bones to spawn extra stuff. 
	{on blast
		{if volume "body"
			{if min_energy 4.7
				{call "stage2"}
			else min_energy 4
				{if rand 0.25
					{if not "stage1"
						{call_synced "stage1"}
					else
						{call_synced "stage2"}
					}
				else
					{call_synced "stage2"}
				}
			else min_energy 3
				{if rand 0.6
					{if not "stage1"
						{call_synced "stage1"}
					else
						{call_synced "stage2"}
					}
				else
					{call_synced "stage2"}
				}
			else min_energy 1.6
				{if rand 0.4
					{if not "stage1"
						{call_synced "stage1"}
					}
				else rand 0.4
					{call_synced "stage2"}
				}
			}
		}
	}
	{on break_armor
		{##if volume "body"
			{call "stage2"}
		}
	}
	{on contact
		{if can_crush
			{volumes disable contact}
			{if effector "tank"
				{if not "stage1"
					{delay 0
						{call "stage1"}
					}
					{delay 1
						{volumes enable contact visible}
					}
				else 
					{delay 0
						{tags add "crushed"}
						{call "stage2"}
					}
				}
			else
				{if not effector "cannon"
					{delay 0
						{call "stage1"}
					}
					{delay 0.01
						{volumes enable contact visible}
					}
				}
			}
		}
	}
	{on bullet_hit
		{if stuff "shell"
			{##if stuff "fg"
				{if stuff "big"
					{call "stage2"}
				}
			}
		}
	}
	{on "stage1"
		{if not "stage1"
			{set "stage1" 1}
			{call "sandbag_crush_fx"}
		}
	}
	{on "stage2"
		{if not "stage2"
			{set "stage1" 1}
			{set "stage2" 1}
			;{call "destroyed_stamp"}
			;{call "sandbag_crush_fx"}
			{if not "sliced"
				{set "sliced" 1}
				{delay 0
					{set_skeleton "_x"}
					{volumes disable contact visible}
					{if tagged "crushed"
						{call "cut_pieces_noblast"}
					else
						{call "cut_pieces"}
					}
				}
			}
			{delay 1
				{tags add "crushed"}
			}
		}
	}
	{on "cut_pieces_noblast"
		(define "cut_piece"
			{tear "piece_medium_sand" bone "piece%0"
				{volumes enable contact}
				{impulse up 0.25 0.25 dir 0.25 0.25 rnd_dir 2 no_position}
				{if rand 1
					{add_view "dust_small" "dust" "root"}
					{view start "dust"}
					{delay_effect 2 1 "stop"}
				}
			}
		)
		("cut_pieces")
	}
	{on "cut_pieces"
		(define "cut_piece"
			{tear "piece_medium_sand" bone "piece%0"
				{volumes enable contact}
				{impulse up 1 1.4 dir 3.5 2.5 rnd_dir 5 no_position}
				{if rand 1
					{add_view "dust_small" "dust" "root"}
					{view start "dust"}
					{delay_effect 2 1 "stop"}
				}
			}
		)
		("cut_pieces")
	}
	{on "destroyed_stamp" overload
		; do nothing
	}
}

{"foxhole_destroy jettison_sandbags1"
	{on "sandbag_crush_fx"
		{if terrain_fx "snow"
			{spawn "sandbag_crush_win" "fx_sandbag1"}
			{spawn "spheredust_norm" "fx_sandbag1"}
		else terrain_fx "ice"
			{spawn "sandbag_crush_win" "fx_sandbag1"}
			{spawn "spheredust_norm" "fx_sandbag1"}
		else terrain_fx "sand"
			{spawn "sandbag_crush_win" "fx_sandbag1"}
			{spawn "spheredust_norm" "fx_sandbag1"}
		else
			{spawn "sandbag_crush" "fx_sandbag1"}
			{spawn "spheredust_norm" "fx_sandbag1"}
		}
	}
}
{"foxhole_destroy jettison_sandbags2"
	{on "sandbag_crush_fx"
		{if terrain_fx "snow"
			{spawn "sandbag_crush_win" "fx_sandbag1"}
			{spawn "sandbag_crush_win" "fx_sandbag2"}
			{spawn "spheredust_norm" "fx_sandbag2"}
		else terrain_fx "ice"
			{spawn "sandbag_crush_win" "fx_sandbag1"}
			{spawn "sandbag_crush_win" "fx_sandbag2"}
			{spawn "spheredust_norm" "fx_sandbag2"}
		else terrain_fx "sand"
			{spawn "sandbag_crush" "fx_sandbag1"}
			{spawn "sandbag_crush" "fx_sandbag2"}
			{spawn "spheredust_norm" "fx_sandbag2"}
		else
			{spawn "sandbag_crush" "fx_sandbag1"}
			{spawn "sandbag_crush" "fx_sandbag2"}
			{spawn "spheredust_norm" "fx_sandbag2"}
		}
	}
}

{"foxhole_destroy jettison_sandbags3"
	{on "sandbag_crush_fx"
		{if terrain_fx "snow"	
			{spawn "sandbag_crush_win" "fx_sandbag1"}
			{spawn "sandbag_crush_win" "fx_sandbag2"}
			{spawn "sandbag_crush_win" "fx_sandbag3"}
			{spawn "spheredust_norm" "fx_sandbag2"}
		else terrain_fx "ice"
			{spawn "sandbag_crush_win" "fx_sandbag1"}
			{spawn "sandbag_crush_win" "fx_sandbag2"}
			{spawn "sandbag_crush_win" "fx_sandbag3"}
			{spawn "spheredust_norm" "fx_sandbag2"}
		else terrain_fx "sand"
			{spawn "sandbag_crush" "fx_sandbag1"}
			{spawn "sandbag_crush" "fx_sandbag2"}
			{spawn "sandbag_crush" "fx_sandbag3"}
			{spawn "spheredust_norm" "fx_sandbag2"}
		else
			{spawn "sandbag_crush" "fx_sandbag1"}
			{spawn "sandbag_crush" "fx_sandbag2"}
			{spawn "sandbag_crush" "fx_sandbag3"}
			{spawn "spheredust_norm" "fx_sandbag2"}
		}
	}
}

{"foxhole_destroy jettison_sandbags4"
	{on "sandbag_crush_fx"
		{if terrain_fx "snow"
			{spawn "sandbag_crush_win" "fx_sandbag1"}
			{spawn "sandbag_crush_win" "fx_sandbag2"}
			{spawn "sandbag_crush_win" "fx_sandbag3"}
			{spawn "sandbag_crush_win" "fx_sandbag4"}
			{spawn "spheredust_norm" "fx_sandbag2"}
		else terrain_fx "ice"
			{spawn "sandbag_crush_win" "fx_sandbag1"}
			{spawn "sandbag_crush_win" "fx_sandbag2"}
			{spawn "sandbag_crush_win" "fx_sandbag3"}
			{spawn "sandbag_crush_win" "fx_sandbag4"}
			{spawn "spheredust_norm" "fx_sandbag2"}
		else terrain_fx "sand"
			{spawn "sandbag_crush" "fx_sandbag1"}
			{spawn "sandbag_crush" "fx_sandbag2"}
			{spawn "sandbag_crush" "fx_sandbag3"}
			{spawn "sandbag_crush" "fx_sandbag4"}
			{spawn "spheredust_norm" "fx_sandbag2"}
		else
			{spawn "sandbag_crush" "fx_sandbag1"}
			{spawn "sandbag_crush" "fx_sandbag2"}
			{spawn "sandbag_crush" "fx_sandbag3"}
			{spawn "sandbag_crush" "fx_sandbag4"}
			{spawn "spheredust_norm" "fx_sandbag2"}
		}
	}
}
{"soldier_foxhole"
	{on spawn
		{if terrain_fx "ice"
			{tex_mod "win"}
		else terrain_fx "snow"
			{tex_mod "win"}
		else terrain_fx "sand"
			{tex_mod "sand"}
		else terrain_fx "ground"
			{tex_mod "ground"}
		else
			{tex_mod "ground"}
		}
		{delay 0.2
			{spawn "building_smoke" "inside"}
			{link_sound "trench_deploy" "vehicle/deploy/foxhole/"}
			{play_sound "trench_deploy"}
		}
	}
}
{"trench_engineer"
	{on spawn
		{if terrain_fx "ice"
			{tex_mod "win"}
		else terrain_fx "snow"
			{tex_mod "win"}
		else terrain_fx "sand"
			{tex_mod "sand"}
		else terrain_fx "ground"
			{tex_mod "ground"}
		else
			{tex_mod "ground"}
		}
		{delay 0.2
			{spawn "building_smoke" "fx_dirt01"}
			{spawn "building_smoke" "fx_dirt02"}
			{spawn "building_smoke" "fx_dirt03"}
			{spawn "building_smoke" "fx_dirt04"}
			{spawn "building_smoke" "fx_dirt05"}
			{link_sound "trench_deploy" "vehicle/deploy/trench/"}
			{play_sound "trench_deploy"}
		}
	}
}