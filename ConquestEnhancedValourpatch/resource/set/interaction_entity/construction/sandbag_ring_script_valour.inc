{"vehicle"
    {on spawn
	    {add_view	"marker_veterancy"			"marker_veterancy"			"turret" not_manual not_scenario}
	} 
	{on "sandbag_heavy_flak"
		{delay 1
			{if operatable
				{if tagged "88mm_flak18"
					{call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.2
						{call "sandbag_ring_heap_curved"}
					else rand 0.4
						{call "sandbag_ring_framed_curved"}
					else rand 0.6
						{call "sandbag_ring_heap_straight"}
					else rand 0.8
						{call "sandbag_ring_framed_straight"}
					else rand 1
						{call "sandbag_ring_heap_straight_with_lane"}
					}
				else tagged "88mm_flak36"
					{call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.2
						{call "sandbag_ring_heap_curved"}
					else rand 0.4
						{call "sandbag_ring_framed_curved"}
					else rand 0.6
						{call "sandbag_ring_heap_straight"}
					else rand 0.8
						{call "sandbag_ring_framed_straight"}
					else rand 1
						{call "sandbag_ring_heap_straight_with_lane"}
					}
				else tagged "qf40mm"
					{call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.2
						{call "sandbag_ring_heap_curved"}
					else rand 0.6
						{call "sandbag_ring_heap_straight"}
					else rand 1
						{call "sandbag_ring_heap_straight_with_lane"}
					}
				else tagged "40_mm_m1_fr"
					{call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.2
						{call "sandbag_ring_heap_curved"}
					else rand 0.6
						{call "sandbag_ring_heap_straight"}
					else rand 1
						{call "sandbag_ring_heap_straight_with_lane"}
					}
				else tagged "qf40mm_pol"
					{call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.2
						{call "sandbag_ring_heap_curved"}
					else rand 0.6
						{call "sandbag_ring_heap_straight"}
					else rand 1
						{call "sandbag_ring_heap_straight_with_lane"}
					}
				else tagged "40_mm_m1"
					{call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.2
						{call "sandbag_ring_heap_curved"}
					else rand 0.6
						{call "sandbag_ring_heap_straight"}
					else rand 1
						{call "sandbag_ring_heap_straight_with_lane"}
					}
				else tagged "90_mm_m1"
					{call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.2
						{call "sandbag_ring_heap_curved"}
					else rand 0.4
						{call "sandbag_ring_framed_curved"}
					else rand 0.6
						{call "sandbag_ring_heap_straight"}
					else rand 0.8
						{call "sandbag_ring_framed_straight"}
					else rand 1
						{call "sandbag_ring_heap_straight_with_lane"}
					}
				else tagged "75mm_type_4"
					{call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.2
						{call "sandbag_ring_heap_curved"}
					else rand 0.4
						{call "sandbag_ring_framed_curved"}
					else rand 0.6
						{call "sandbag_ring_heap_straight"}
					else rand 0.8
						{call "sandbag_ring_framed_straight"}
					else rand 1
						{call "sandbag_ring_heap_straight_with_lane"}
					}
				else tagged "75mm_type_88"
					{call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.2
						{call "sandbag_ring_heap_curved"}
					else rand 0.4
						{call "sandbag_ring_framed_curved"}
					else rand 0.6
						{call "sandbag_ring_heap_straight"}
					else rand 0.8
						{call "sandbag_ring_framed_straight"}
					else rand 1
						{call "sandbag_ring_heap_straight_with_lane"}
					}
				else tagged "75mm_aa_wz36"
					{call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.2
						{call "sandbag_ring_heap_curved"}
					else rand 0.4
						{call "sandbag_ring_framed_curved"}
					else rand 0.6
						{call "sandbag_ring_heap_straight"}
					else rand 0.8
						{call "sandbag_ring_framed_straight"}
					else rand 1
						{call "sandbag_ring_heap_straight_with_lane"}
					}
				else tagged "120mm_sgrw42"
				    {call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.5
						{call "sandbag_ring_heap_curved_small"}
					else rand 1
						{call "sandbag_ring_frame_curved_small"}
					}
				else tagged "80mm_sgrw34"
				    {call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.5
						{call "sandbag_ring_heap_curved_small"}
					else rand 1
						{call "sandbag_ring_frame_curved_small"}
					}
				else tagged "120mm_pm38"
				    {call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.5
						{call "sandbag_ring_heap_curved_small"}
					else rand 1
						{call "sandbag_ring_frame_curved_small"}
					}
				else tagged "82mm_bm37"
				    {call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.5
						{call "sandbag_ring_heap_curved_small"}
					else rand 1
						{call "sandbag_ring_frame_curved_small"}
					}
				else tagged "150mm_type_97"
				    {call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.5
						{call "sandbag_ring_heap_curved_small"}
					else rand 1
						{call "sandbag_ring_frame_curved_small"}
					}
				else tagged "81mm_brandt_jap"
				    {call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.5
						{call "sandbag_ring_heap_curved_small"}
					else rand 1
						{call "sandbag_ring_frame_curved_small"}
					}
				else tagged "81mm_brandt_pol"
				    {call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.5
						{call "sandbag_ring_heap_curved_small"}
					else rand 1
						{call "sandbag_ring_frame_curved_small"}
					}
				else tagged "81_mm_m1"
				    {call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.5
						{call "sandbag_ring_heap_curved_small"}
					else rand 1
						{call "sandbag_ring_frame_curved_small"}
					}
				else tagged "107_mm_m2"
				    {call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.5
						{call "sandbag_ring_heap_curved_small"}
					else rand 1
						{call "sandbag_ring_frame_curved_small"}
					}
				else tagged "81mm_brandt_ita"
				    {call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.5
						{call "sandbag_ring_heap_curved_small"}
					else rand 1
						{call "sandbag_ring_frame_curved_small"}
					}
				else tagged "76mm_mk_ii"
				    {call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.5
						{call "sandbag_ring_heap_curved_small"}
					else rand 1
						{call "sandbag_ring_frame_curved_small"}
					}
				else tagged "200mm_type_4"
				    {call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.5
						{call "sandbag_ring_heap_curved_small"}
					else rand 1
						{call "sandbag_ring_frame_curved_small"}
					}
				else tagged "81_mm_m1_fr"
				    {call "deactivate_vehicle"}
					{start_sound "vehicle/deploy/foxhole"}
					{if rand 0.5
						{call "sandbag_ring_heap_curved_small"}
					else rand 1
						{call "sandbag_ring_frame_curved_small"}
					}
				}		
			}
		}
	}
}
