{"vehicle"
	{on "sandbag_ring_heap_curved"
		{delay 10
			{spawn "sandbag_heap_curved" offset 70 0 0}
			{delay 2
				{spawn "sandbag_heap_pile" offset 60 60 0}
				{delay 2
					{spawn "sandbag_heap_curved_90" offset 0 70 0}
					{delay 2
						{spawn "sandbag_heap_pile" offset -60 60 0}
						{delay 2
							{spawn "sandbag_heap_curved_180" offset -70 0 0}
							{delay 2
								{spawn "sandbag_heap_curved_270" offset 0 -70 0}
								{delay 2
									{spawn "sandbag_heap_pile" offset 60 -60 0}
									{call "activate_vehicle"}
								}
							}
						}
					}
				}
			}
			{if rand 0.2
			    {spawn "crate_one" offset 30 -30 0}
			else rand 0.4
				{spawn "ammo_box_01" offset 30 -30 0}
			else rand 0.6
				{spawn "ammo_box_02" offset 30 -30 0}
			else rand 0.8
				{spawn "ammo_box_03" offset 30 -30 0}
			else rand 1
				{spawn "ammo_box_04" offset 30 -30 0}
			}
		}
	}			
	{on "sandbag_ring_framed_curved"
		{delay 10
			{spawn "sandbag_framed_curved" offset 70 0 0}
			{delay 2
				{spawn "sandbag_heap_pile" offset 60 60 0}
				{delay 2
					{spawn "sandbag_framed_curved_90" offset 0 70 0}
					{delay 2
						{spawn "sandbag_heap_pile" offset -60 60 0}
						{delay 2
							{spawn "sandbag_framed_curved_180" offset -70 0 0}
							{delay 2
								{spawn "sandbag_framed_curved_270" offset 0 -70 0}
								{delay 2
									{spawn "sandbag_heap_pile" offset 60 -60 0}
									{call "activate_vehicle"}
								}
							}
						}
					}
				}
			}
			{if rand 0.2
			    {spawn "crate_one" offset 30 -30 0}
			else rand 0.4
				{spawn "ammo_box_01" offset 30 -30 0}
			else rand 0.6
				{spawn "ammo_box_02" offset 30 -30 0}
			else rand 0.8
				{spawn "ammo_box_03" offset 30 -30 0}
			else rand 1
				{spawn "ammo_box_04" offset 30 -30 0}
			}
		}
	}
	{on "sandbag_ring_framed_straight"
		{delay 10
			{spawn "sandbag_framed_straight" offset 78 25 0}
			{spawn "sandbag_framed_straight" offset 78 -25 0}
			{delay 2
				{spawn "sandbag_heap_pile" offset 65 65 0}
				{delay 2
					{spawn "sandbag_framed_straight_90" offset 25 78 0}
					{spawn "sandbag_framed_straight_90" offset -25 78 0}
					{delay 2
						{spawn "sandbag_heap_pile" offset -65 65 0}
						{delay 2
							{spawn "sandbag_framed_straight_180" offset -80 25 0}
							{spawn "sandbag_framed_straight_180" offset -80 -25 0}
							{delay 2
								{spawn "sandbag_framed_straight_270" offset 25 -78 0}
								{spawn "sandbag_framed_straight_270" offset -25 -78 0}
								{delay 2
									{spawn "sandbag_heap_pile" offset 65 -65 0}
									{call "activate_vehicle"}
								}
							}
						}
					}
				}		
			}
			{if rand 0.2
			    {spawn "crate_one" offset 30 -30 0}
			else rand 0.4
				{spawn "ammo_box_01" offset 30 -30 0}
			else rand 0.6
				{spawn "ammo_box_02" offset 30 -30 0}
			else rand 0.8
				{spawn "ammo_box_03" offset 30 -30 0}
			else rand 1
				{spawn "ammo_box_04" offset 30 -30 0}
			}
		}	
	}	
	{on "sandbag_ring_heap_straight_with_lane"
		{delay 10
			{spawn "sandbag_heap_straight" offset 78 25 0}
			{spawn "sandbag_heap_straight" offset 78 -25 0}
			{delay 2
				{spawn "sandbag_heap_pile" offset 70 70 0}
				{delay 2
					{spawn "sandbag_heap_straight_90" offset 25 78 0}
					{spawn "sandbag_heap_straight_90" offset -25 78 0}
					{delay 2
						{spawn "sandbag_heap_pile" offset -70 70 0}
						{delay 2
							{spawn "sandbag_heap_straight_180" offset -80 25 0}
							{spawn "sandbag_heap_pile" offset -90 -25 0}
							{spawn "sandbag_heap_pile" offset -130 -25 0}
							{delay 2
								{spawn "sandbag_heap_straight_270" offset 25 -78 0}
								{spawn "sandbag_heap_pile" offset -30 -80 0}
								{spawn "sandbag_heap_pile" offset -70 -80 0}
								{spawn "sandbag_heap_pile" offset -110 -80 0}
								{delay 2
									{spawn "sandbag_heap_pile" offset 70 -70 0}
									{call "activate_vehicle"}
								}
							}
						}
					}
				}		
			}
			{if rand 0.2
			    {spawn "crate_one" offset 30 -30 0}
			else rand 0.4
				{spawn "ammo_box_01" offset 30 -30 0}
			else rand 0.6
				{spawn "ammo_box_02" offset 30 -30 0}
			else rand 0.8
				{spawn "ammo_box_03" offset 30 -30 0}
			else rand 1
				{spawn "ammo_box_04" offset 30 -30 0}
			}
		}	
	}	
	{on "sandbag_ring_heap_straight"
		{delay 8
			{spawn "sandbag_heap_straight" offset 78 25 0}
			{spawn "sandbag_heap_straight" offset 78 -25 0}
			{delay 2
				{spawn "sandbag_heap_pile" offset 70 70 0}
				{delay 2
					{spawn "sandbag_heap_straight_90" offset 25 78 0}
					{spawn "sandbag_heap_straight_90" offset -25 78 0}
					{delay 2
						{spawn "sandbag_heap_pile" offset -70 70 0}
						{delay 2
							{spawn "sandbag_heap_straight_180" offset -80 25 0}
							{delay 2
								{spawn "sandbag_heap_pile" offset -70 -70 0}
								{delay 2
									{spawn "sandbag_heap_straight_270" offset 25 -78 0}
									{spawn "sandbag_heap_straight_270" offset -25 -78 0}
									{delay 2
										{spawn "sandbag_heap_pile" offset 70 -70 0}
										{call "activate_vehicle"}
									}
								}
							}
						}
					}
				}		
			}
			{if rand 0.2
			    {spawn "crate_one" offset 30 -30 0}
			else rand 0.4
				{spawn "ammo_box_01" offset 30 -30 0}
			else rand 0.6
				{spawn "ammo_box_02" offset 30 -30 0}
			else rand 0.8
				{spawn "ammo_box_03" offset 30 -30 0}
			else rand 1
				{spawn "ammo_box_04" offset 30 -30 0}
			}
		}	
	}
	{on "sandbag_ring_heap_curved_small"
		{delay 10
			{spawn "sandbag_heap_curved" offset 40 0 0}
			{delay 5
				{spawn "sandbag_heap_curved_90" offset 0 40 0}
				{delay 5
					{spawn "sandbag_heap_curved_270" offset 0 -40 0}
					{delay 5
						{spawn "sandbag_heap_pile" offset -60 30 0}
						{delay 5
							{spawn "sandbag_heap_pile" offset -60 -30 0}
							{call "activate_vehicle"}
						}
					}
				}
			}
		}
	}
	{on "sandbag_ring_frame_curved_small"
		{delay 10
			{spawn "sandbag_framed_curved" offset 40 0 0}
			{delay 5
				{spawn "sandbag_framed_curved_90" offset 0 40 0}
				{delay 5
					{spawn "sandbag_framed_curved_270" offset 0 -40 0}
					{delay 5
						{spawn "sandbag_heap_pile" offset -60 30 0}
						{delay 5
							{spawn "sandbag_heap_pile" offset -60 -30 0}
							{call "activate_vehicle"}
						}
					}
				}
			}
		}
	}			
}
