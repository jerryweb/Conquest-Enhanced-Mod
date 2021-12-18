

;/*=============== Presets Begin ===============*/

; Distances are in meters. Units are spotted when one the following conditions are met.
; These preset values are multiplied by radius values in generic defines section to calculate in-game settings.

(define "firing"				;// Shooting specific weapons. These weappons/terms must be defined in vision/settings.set before use here. 
	{firing_welrod 0}
	{firing_delisle 0}
	{firing_silencer_m 0}
	{firing_silencer_n 0}
	{thrower 0}
)

(define "human"
	{visible 110}				;// once human is spotted, the distance the human will remain spotted until Line Of Sight is broken. When placed outside of a specific stance block, it becomes a master value for all stances.

	{cover 80					;// default value incase condition isn't defined below. Important that {cover} block comes before non-cover {stand}, {squat}, and {crawl} blocks, else cover values will be overwritten. 
		{stand 80				;// "stand" stance - in cover
			{stealth 70}		;// "stand" stance - in cover and human has stealth skill
		}
		{squat 80				;// "squat" stance - in cover
			{stealth 40}		;// "squat" stance - in cover and human has stealth skill
		}
		{crawl 40				;// "crawl" stance - in cover
			{stealth 15}		;// "crawl" stance - in cover and human has stealth skill
		}
	}

	{stand 110					;// "stand" stance - moving. Also serves as default if other conditions are not defined in this block.
		{stealth 90}			;// "stand" stance - moving and human has stealth skill
		{still 90				;// "stand" stance - still / not moving. standing.
			{stealth 80}		;// "stand" stance - still / not moving and human has stealth skill
		}
	}

	{squat 100					;// "squat" stance - moving. Also serves as default if other conditions are not defined in this block.
		{stealth 50}			;// "squat" stance - moving and human has stealth skill
		{still 80				;// "squat" stance - still / not moving. kneeling.
			{stealth 40}		;// "squat" stance - still / not moving and human has stealth skill
		}
	}

	{crawl 50					;// "crawl" stance - moving. Also serves as default if other conditions are not defined in this block.
		{stealth 20}			;// "crawl" stance - moving and human has stealth skill
		{still 40				;// "crawl" stance - still / not moving. kneeling.
			{stealth 15}		;// "crawl" stance - still / not moving. kneeling and human has stealth skill
		}
	}
)

(define "human_short"           ;// Used in other places (vehicle visions)
	{visible 60}				;// once human is spotted, the distance the human will remain spotted until Line Of Sight is broken. When placed outside of a specific stance block, it becomes a master value for all stances.

	{cover 10					;// default value incase condition isn't defined below. Important that {cover} block comes before non-cover {stand}, {squat}, and {crawl} blocks, else cover values will be overwritten. 
		{stealth 0}				;// default value for all stances - in cover and human has stealth skill
	}

	{stand 60					;// "stand" stance - moving. Also serves as default if other conditions are not defined in this block.
		{stealth 0}				;// "stand" stance - moving and human has stealth skill
		{still 40}				;// "stand" stance - still / not moving. standing.
	}

	{squat 50					;// "squat" stance - moving
		{stealth 0}				;// "squat" stance - moving and human has stealth skill
		{still 40}				;// "squat" stance - still / not moving. kneeling.
	}

	{crawl 10					;// "crawl" stance - moving
		{stealth 0}				;// "crawl" stance - moving and human has stealth skill
		{still 5}				;// "crawl" stance - still / not moving. kneeling.
	}
)

(define "cannon"

	;//heavy mgun
	{cannon_00 90				;// unit moving
		{firing 150}			;// unit shooting weapon
		{visible 100}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 80}				;// unit still / not moving. 1st Blue line in v_visor
	}
	
	;//infantry mortar
	{cannon_01 90				;// unit moving
		{firing 250}			;// unit shooting weapon
		{visible 100}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 80}				;// unit still / not moving. 1st Blue line in v_visor
	}

	;// light gun
	{cannon_02 90				;// unit moving
		{firing 200}			;// unit shooting weapon
		{visible 100}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 85}				;// unit still / not moving
	}

	;// medium gun
	{cannon_03 90				;// unit moving
		{firing 250}			;// unit shooting weapon
		{visible 100}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 85}				;// unit still / not moving
	}

	;// heavy gun
	{cannon_04 100				;// unit moving
		{firing 250}			;// unit shooting weapon
		{visible 110}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 85}				;// unit still / not moving
	}

	;// artillery
	{cannon_05 110				;// unit moving
		{firing 500}			;// unit shooting weapon
		{visible 120}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 85}				;// unit still / not moving
	}
)

(define "vehicle"

	;// moto, jeep
	{vehicle_01 110				;// unit moving
		{firing 150}			;// unit shooting weapon
		{visible 110}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 90}				;// unit still / not moving
	}

	;// armoredcars, trucks
	{vehicle_02 120				;// unit moving
		{firing 180}			;// unit shooting weapon
		{visible 120}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 100}				;// unit still / not moving
	}

	;// light tanks
	{vehicle_03 130				;// unit moving
		{firing 200}			;// unit shooting weapon
		{visible 140}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 110}				;// unit still / not moving
	}

	;// medium tanks, rocket artillery
	{vehicle_04 140				;// unit moving
		{firing 250}			;// unit shooting weapon
		{visible 150}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 120}				;// unit still / not moving
	}

	;//heavy tanks
	{vehicle_05 150				;// unit moving
		{firing 300}			;// unit shooting weapon
		{visible 160}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 130}				;// unit still / not moving
	}
	
	;// SPG or tanks with a really large gun that make a lot of noise, alike artillery (105+mm)
	{vehicle_06 140				;// unit moving
		{firing 400}			;// unit shooting weapon
		{visible 150}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 120}				;// unit still / not moving
	}
	
	;// aircraft
	{plane_01 500				;// unit moving
		{firing 500}			;// unit shooting weapon
		{visible 500}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 200}				;// unit still / not moving
	}
)

(define "ship"

	;// U-Boat / Submarine
	{marine_01 100				;// unit moving
		{firing 180}			;// unit shooting weapon
		{visible 125}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 100}				;// unit still / not moving
	}

	;// Marine Small
	{marine_02 220				;// unit moving
		{firing 270}			;// unit shooting weapon
		{visible 180}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 180}				;// unit still / not moving
	}

	;// Marine Medium
	{marine_03 250				;// unit moving
		{firing 300}			;// unit shooting weapon
		{visible 200}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 200}				;// unit still / not moving
	}

	;// Marine Large
	{marine_04 350				;// unit moving
		{firing 400}			;// unit shooting weapon
		{visible 300}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 300}				;// unit still / not moving
	}

	;// Marine Max
	{marine_05 350				;// unit moving
		{firing 400}			;// unit shooting weapon
		{visible 300}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 300}				;// unit still / not moving
	}
)

;/*=============== Presets End ===============*/

;/*=============== Generic Defines Begin ===============*/

(define "vision_human"
	("radius" r(%0))				;// vision = radius * (one) applicable "rules" situation * (one) applicable "mods" situation
	{rules							;// no multiplication within rules blocks
		{human 80					;// fallback value if no other subordinated case is applicable
			{firing 110				;// firing weapon. 1st Green line in v_visor
				("firing")			;// Preset from above (a modifier picked here is final, the stance for example will not be considered anymore)
			}
			("human")				;// Preset from above
		}
		("cannon")					;// Preset from above
		("vehicle")					;// Preset from above
		("ship")					;// Preset from above
	}
	{mods							;// no nested blocks allowed, but all applicable values will be multiplied
		{stand 1}
	}
)

(define "vision_human_peripheral"
	("radius" r(%0))
	{rules
		{human 85
			{firing 220
				("firing")
			}
			("human")
		}
		("cannon")
		("vehicle")
		("ship")
	}
	{mods
		{stand 1}
	}
)

(define "vision_vehicle_searchlight"
	("radius" r(2.5))
	{rules
		{human 150
			{firing 190
				("firing")
			}
			("human")
		}
		("cannon")
		("vehicle")
		("ship")
	}
	{mods
		{stand 1}
	}
)

(define "vision_vehicle_optic"
	("radius" r(1.3))
	{rules
		{human 61
			{firing 85
				("firing")
			}
			("human")
		}
		("cannon")
		("vehicle")
		("ship")
	}
	{mods
		{stand 1}
	}
)

(define "vision_vehicle"
	("radius" r(0.85))
	{rules
		{human 100
			{firing 100
				("firing")
			}
			("human")
		}
		("cannon")
		("vehicle")
		("ship")
	}
	{mods
		{stand 1}
	}
)

(define "vision_vehicle_around"
	("radius" r(0.6))
	{rules
		{human 60
			{firing 60
				("firing")
			}
			("human")
		}
		("cannon")
		("vehicle")
		("ship")
	}
	{mods
		{stand 1}
	}
)

(define "vision_tank_around"
	("radius" r(0.6))
	{rules
		{human 60
			{firing 60
				("firing")
			}
			("human_short")
		}
		("cannon")
		("vehicle")
		("ship")
	}
	{mods
		{stand 1}
	}
)

(define "vision_plane"
	("radius" r(3.5))
	{rules
		{human 140
			{firing 60
				("firing")
			}
			("human_short")
		}
		("cannon")
		("vehicle")
		("ship")
	}
	{mods
		{stand 1}
	}
)

(define "vision_plane_around"
	("radius" r(1))
	{rules
		{human 60
			{firing 60
				("firing")
			}
			("human_short")
		}
		("cannon")
		("vehicle")
		("ship")
	}
	{mods
		{stand 1}
	}
)

(define "vision_plane_scout"
	("radius" r(1.3))
	{rules
		{human 60
			{firing 60
				("firing")
			}
			("human_short")
		}
		("cannon")
		("vehicle")
		("ship")
	}
	{mods
		{stand 1}
	}
)

(define "glass"
	("radius" r(%0))
)

;/*=============== Generic Defines End ===============*/