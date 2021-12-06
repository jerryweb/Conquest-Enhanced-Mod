{"human"
    {on bullet_hit
		{if not tagged "player"
		    {tags add "hit"}
		    {chassis_work 0}
		        {delay 3
			        {tags remove "hit"}
				    {chassis_work 1}
		        }
		}	
    }
	
	{on "medic_carry" 		;// UI button to toggle engine on/off
		{if operatable
			{if not tagged "1" 
				{if tagged "default" 
				    {tags add "carry"}
				    {tags remove "default"}
				    {view start ally neutral "marker_personage"}
					{view pause "marker_healing"}
				else tagged "carry_off"
				    {tags add "default"}
					{tags remove "carry_off"}
				    {view pause "marker_healing"}
			    else 
				    {tags add "carry_off"}
					{tags remove "carry"}
					{tags remove "default"}
					{view start ally neutral "marker_healing"}
					{view pause "marker_personage"}
				}
			}
		}
	}
	
	{on "stop_healing"
		{if not tagged "carry_off"
		    {view pause "marker_healing"}
		}
	}
	
	{on "stop_personage"
		{view pause "marker_personage"}
		{view pause "marker_healing"}
	}
	
	{on "go_resupply" 		;// UI button to toggle engine on/off
		{if operatable
			{if not tagged "resupplying" 
				{tags add "resupplying"}
				{tags remove "noresupply"}
				{view pause "marker_ammo_out"}
				{view start ally neutral "start_blinded"}
				{delay 2.5
			        {view pause "start_blinded"}
				}
				else 
				{tags add "noresupply"}
				{tags remove "resupplying"}
				{view pause "marker_ammo_refill"}
				{view start ally neutral "marker_ammo_out"}
				{delay 2.5
			        {view pause "marker_ammo_out"}
				}
			}
		}
	}
	
	{on "start_ammo_out"
		{view start ally neutral "marker_ammo_out"}
		{tags add "noammo"}
	}

	{on "stop_ammo_out"
		{view pause "marker_ammo_out"}
		{tags add "noammo"}
	}
	
	{on "start_ammo_refill"
		{view start ally neutral "marker_ammo_refill"}
		{tags remove "noammo"}
		{delay 2.5
			{view pause "marker_ammo_refill"}
			{tags remove "noammo"}
		}
	}
	
	{on board out							;// exiting a vehicle
		{if linked "sdkfz251c"
			{if not tagged "player"
			    {delay 0.01
				    {tags add "panzergrenadiers"}
			    }
			}
		else
			{tags add "noammo23"}
		}
	}
	
	{on "fortification"
	    {if rand 0.08
		    {spawn "soldier_foxhole" "basis" x}
		else rand 0.08 
		    {spawn "mg_foxhole" "basis" x}
		else rand 0.08 
		    {spawn "sandbag_heap_curved" "basis" x}
		else rand 0.08 
		    {spawn "sandbag_heap_straight" "basis" x}
		else rand 0.08 
		    {spawn "sandbag_structured_curved" "basis" x}
		else rand 0.08 
		    {spawn "sandbag_structured_curved_big" "basis" x}
		else rand 0.08 
		    {spawn "sandbag_structured_straight" "basis" x}
		else rand 0.08 
		    {spawn "sandbag_watchtower" "basis" x}
		else rand 0.08 
		    {spawn "sandbag_curved" "basis" x}
		else rand 0.08 
		    {spawn "sandbag_curved_heap" "basis" x}
		else rand 0.08 
		    {spawn "sandbag_straight" "basis" x}
		else 
		    {spawn "sandbag_straight_heap" "basis" x}
		}
	}
}

{"antitank_1"
    {on spawn
	    {tags add "automatic_weaponary"}
	}
}


{"artillery_aim2"
    {on spawn
	    {tags add "automatic_weaponary"}
		{delay 1
			{if rand 0.08
			    {spawn "soldier_foxhole" "basis" x}
			else rand 0.08 
			    {spawn "mg_foxhole" "basis" x}
			else rand 0.08 
		    	{spawn "sandbag_heap_curved" "basis" x}
			else rand 0.08 
			    {spawn "sandbag_heap_straight" "basis" x}
			else rand 0.08 
			    {spawn "sandbag_structured_curved" "basis" x}
			else rand 0.08 
			    {spawn "sandbag_structured_curved_big" "basis" x}
			else rand 0.08 
			    {spawn "sandbag_structured_straight" "basis" x}
			else rand 0.08 
			    {spawn "sandbag_watchtower" "basis" x}
			else rand 0.08 
			    {spawn "sandbag_curved" "basis" x}
			else rand 0.08 
			    {spawn "sandbag_curved_heap" "basis" x}
			else rand 0.08 
			    {spawn "sandbag_straight" "basis" x}
			else 
			    {spawn "sandbag_straight_heap" "basis" x}
			}
		}
	}
}