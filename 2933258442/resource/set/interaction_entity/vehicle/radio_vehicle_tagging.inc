; ===== Radio Vehicle Tagging ========================================
; Radio vehicles are tagged once, at spawn. Whether they are crewed or player-controlled
; is checked by the watcher trigger in the radio script, not here.
	{"ho_ha_radio"
		{on spawn
			{tags add "radio_operator"}
		}
	}

	{"sdkfz250a_3"
		{on spawn
			{tags add "radio_operator"}
		}
	}

	{"ba20_command"
		{on spawn
			{tags add "radio_operator"}
		}
	}

	{"ba20_command_fin"
		{on spawn
			{tags add "radio_operator"}
		}
	}

	{"m3a1_commander"
		{on spawn
			{tags add "radio_operator"}
		}
	}

	{"m3a1_halftrack_radio"
		{on spawn
			{tags add "radio_operator"}
		}
	}

	{"m5a1_halftrack_radio"
		{on spawn
			{tags add "radio_operator"}
		}
	}
; ===== Radio Vehicle Tagging End ====================================