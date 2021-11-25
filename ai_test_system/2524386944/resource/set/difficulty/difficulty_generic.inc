	{any
		{translate_damage 8}		; damage multiplier for blastwave damage to humans
		{cover_hitchance 0.2}		; the probability of hitting a soldier behind cover
		{crawl_hitchance 0.5}		; the probabiltiy of hitting a soldier in crawl position
		{cover_damage 0.90}			; damage when protected by cover

		{vehicle_burst 1}			; increase timeout between bursts for all vehicles
		{cover_mgun_burst 1}		; increase bullet count in 1 burst of soldier with mgun in horizontal cover
		{cover_mgun_delay 0.75}		; decrease timeout between bursts of soldier with mgun in horizontal cover

		{recoil			1}			; recoil multiplier for all machine guns
		{recoil_zoom	0.5}		; recoil multiplier in zoom mode
		{vehicle_recoil 0}			; recoil multiplier for all machine guns mounted on vehicles

		{cover_efficiency			; how cover efficiency will drop with distance
			0		0
			10		0.30
			50		0.70
			100		1.00
		}

		;// Modifies human's distance from blastwave center when calculating amount of energy that hits the human. 2.0 = double the distance. 
		{blast_crawl 1.00}			; simply lying on the ground
		{blast_cover 1.25}			; in cover from protected side
		{blast_crawl_prepared 1.50}	; lying on the ground & waiting for explosion
		{blast_cover_prepared 2.75}	; in cover not from protected side, but waiting for explosion
		{blast_squat 1.00}			; on the knees

		{death_delay_min 420}		; min bleeding out time in seconds
		{death_delay_max 880}		; max bleeding out time in seconds

		{firing_timeout 1.00}		; time out between bursts	(modifier on FiringTimeout)
		{grenade_timeout 0.50}		; time out between grenades	(modifier on FiringTimeout)

		{ai_damage 1.0}				; damage multiplier for AI humans agaisnt other AI humans, does not effect player controlled units
		{burst 1}					; multiplier to number of bullets in burst from weapon settings
		{accuracy 1}				; accuracy multiplier from weapon settings
		{health 1}					; health multiplier from soldier settings
	}