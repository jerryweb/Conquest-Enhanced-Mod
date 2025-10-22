{"tank"
	{on "hull_destroyed" overload
		{if not tagged "hull_destroyed"
			{tags add "hull_destroyed"}
			{tags add "no_scavenge"}		;// tag for conquest so that vehicle cannot be repaired/recovered
			{if not tagged "_ai_defender"
				{mark_for_persistence}			;// Conquest map persistence
			}
			
			{if not tagged "body_break"
				{components "body" break}
			}
			{damage_report "body" "component/body_destroyed"}
			{able select 0}
			{able repaired 0}
			{able minimap 0}
			{delay 2
				{kick_entity_manager}
				{tags add "destroyed"}
			}
			{delay 10
				{call "hatch_fire"}
				{clear_inventory}
			}
			{delay 20 5
				{##/* if rand 0.5
					{call_synced "cookoff"}
					{view stop "smoke3"}
					{stop_sound "flame_1"}
				*/}
			}
			{delay 87
				{stop_sound "flame_1"}
			}
		}
	}

	{on "vehicle_destroyed" overload
		{if not tagged "vehicle_destroyed"
			{if not tagged "ammo_cooked2"
				{tags add "vehicle_destroyed"}
				{ani_wind "open" end}
				{ani_wind "open1" end}
				{tags add "no_scavenge"}		;// tag for conquest so that vehicle cannot be repaired/recovered
				{if not tagged "_ai_defender"
					{mark_for_persistence}			;// Conquest map persistence
				}
				{if not tagged "body_break"
					{components "body" break}
				}
				;//{damage_report "body" "component/body_destroyed"}
				{able select 0}
				{able repaired 0}
				{able minimap 0}
				{delay 2
					{kick_entity_manager}
					{tags add "destroyed"}
				}
				{if not tagged "exploded"
					;//{view pause "cooking_presmoke_1"}
					{view start "fire_vehicle_death"}
					{play_sound "flame_1" 1}
					{clear_inventory}
					{delay 500 60
						{if not tagged "exploded"
							{view pause "fire_vehicle_death"}
							{view start "smoke_vehicle_death"}
							{stop_sound "flame_1"}
							{call_synced "tags_add_ammo_cooked"}
							{call_synced "tags_add_ammo_cooked2"}
						}
					}
				}
				{delay 200 200
					{if rand 0.3
						{call_synced "rand_break_ammo"}
					}
				}
			}
		}
	}

	(include "tank-damage_ce.inc")	
}