

;/*=============== Presets Begin ===============*/

; // Distances are in meters. Units are spotted when one the following conditions are met.
; // These preset values are multiplied by radius values in generic defines section to calculate in-game settings. 
; // Additionally, there is a global radius modifier on vision.set for a global vision reduction or augmentation. At the moment the radius modifier is 1.

(define "firing"				;// Shooting specific weapons. These weappons/terms must be defined in vision/settings.set before use here. 
	{firing_welrod 0}
	{firing_delisle 0}
	{firing_silencer_m 0}
	{firing_silencer_n 0}
	{thrower 0}
)

(define "spot_human"			;// This section defines the distances at which a human is spotted under various conditions.

	{visible 100}				;// once human is spotted, the distance the human will remain spotted until Line Of Sight is broken. When placed outside of a specific stance block, it becomes a master value for all stances.

	{cover 80					;// default value incase condition isn't defined below. Important that {cover} block comes before non-cover {stand}, {squat}, and {crawl} blocks, else cover values will be overwritten. 
		{stand 80				;// "stand" stance - in cover
			{stealth 40}		;// "stand" stance - in cover and human has stealth skill
		}
		{squat 40				;// "squat" stance - in cover
			{stealth 20}		;// "squat" stance - in cover and human has stealth skill
		}
		{crawl 10				;// "crawl" stance - in cover
			{stealth 5}		;// "crawl" stance - in cover and human has stealth skill
		}
	}

	{stand 90					;// "stand" stance - moving. Also serves as default if other conditions are not defined in this block.
		{stealth 90}			;// "stand" stance - moving and human has stealth skill
		{still 90				;// "stand" stance - still / not moving. standing.
			{stealth 50}		;// "stand" stance - still / not moving and human has stealth skill
		}
	}

	{squat 80					;// "squat" stance - moving. Also serves as default if other conditions are not defined in this block. (doesn't apply, squat motion doesn't exist in Gem2)
		{stealth 80}			;// "squat" stance - moving and human has stealth skill (doesn't apply, squat motion doesn't exist in Gem2)
		{still 70				;// "squat" stance - still / not moving. kneeling.
			{stealth 20}		;// "squat" stance - still / not moving and human has stealth skill
		}
	}

	{crawl 30					;// "crawl" stance - moving. Also serves as default if other conditions are not defined in this block.
		{stealth 10}			;// "crawl" stance - moving and human has stealth skill
		{still 15				;// "crawl" stance - still / not moving. kneeling.
			{stealth 5}		;// "crawl" stance - still / not moving. kneeling and human has stealth skill
		}
	}
)

(define "spot_cannon"			;// This section defines the distances at which different types of cannons are spotted under various conditions.

	;//heavy mgun
	{cannon_00 100				;// distance at which it will be spotted when moving
		{firing (/ 200 %r)}		;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 100}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 100}				;// unit still / not moving. 1st Blue line in v_visor
	}

	;//infantry mortar
	{cannon_01 100				;// distance at which it will be spotted when moving
		{firing (/ 200 %r)}		;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 100}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 100}				;// unit still / not moving. 1st Blue line in v_visor
	}

	;// light gun
	{cannon_02 100				;// distance at which it will be spotted when moving
		{firing (/ 250 %r)}		;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 100}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 100}				;// unit still / not moving
	}

	;// medium gun
	{cannon_03 100				;// distance at which it will be spotted when moving
		{firing (/ 250 %r)}		;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 100}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 100}				;// unit still / not moving
	}

	;// heavy gun
	{cannon_04 100				;// distance at which it will be spotted when moving
		{firing (/ 300 %r)}		;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 100}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 100}				;// unit still / not moving
	}

	;// artillery
	{cannon_05 100				;// distance at which it will be spotted when moving
		{firing (/ 500 %r)}		;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 100}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 100}				;// unit still / not moving
	}
)

(define "spot_vehicle"			;// This section defines the distances at which different types of vehicles are spotted under various conditions.

	;// moto, jeep
	{vehicle_01 (+ 100 (/ 50 %r))	;// distance at which it will be spotted when moving, 50m past visor range.
		{firing (/ 200 %r)}			;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible (+ 100 (/ %d %r))}	;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 100}					;// unit still / not moving
	}

	;// armoredcars, trucks
	{vehicle_02 (+ 100 (/ 50 %r))	;// distance at which it will be spotted when moving, 50m past visor range.
		{firing (/ 200 %r)}			;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible (+ 100 (/ %d %r))}	;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 100}					;// unit still / not moving
	}

	;// light tanks
	{vehicle_03 (+ 100 (/ 50 %r))	;// distance at which it will be spotted when moving, 50m past visor range.
		{firing (/ 200 %r)}			;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible (+ 100 (/ %d %r))}	;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 100}					;// unit still / not moving
	}

	;// medium tanks, rocket artillery
	{vehicle_04 (+ 100 (/ 50 %r))	;// distance at which it will be spotted when moving, 50m past visor range.
		{firing (/ 250 %r)}			;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible (+ 100 (/ %d %r))}	;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 100}					;// unit still / not moving
	}

	;//heavy tanks
	{vehicle_05 (+ 100 (/ 50 %r))	;// distance at which it will be spotted when moving, 50m past visor range.
		{firing (/ 300 %r)}			;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible (+ 100 (/ %d %r))}	;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 100}					;// unit still / not moving
	}

	;// SPG or tanks with a really large gun that make a lot of noise, alike artillery (105+mm)
	{vehicle_06 (+ 100 (/ 50 %r))	;// distance at which it will be spotted when moving, 50m past visor range.
		{firing (/ 400 %r)}			;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible (+ 100 (/ %d %r))}	;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 100}					;// unit still / not moving
	}

	;// aircraft
	{plane_01 1000				;// distance at which it will be spotted when moving
		{firing (/ 1000 %r)}	;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 1000}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 100}				;// unit still / not moving
	}
)

(define "spot_ship"				;// This section defines the distances at which different types of ships are spotted under various conditions.

	;// Small vessel
	{marine_01 (+ 100 (/ 50 %r));// distance at which it will be spotted when moving, 50m past visor range.
		{firing (/ 200 %r)}		;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 100}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 100}				;// unit still / not moving
	}

	;// Marine Small
	{marine_02 (+ 100 (/ 50 %r));// distance at which it will be spotted when moving, 50m past visor range.
		{firing (/ 200 %r)}		;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 100}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 100}				;// unit still / not moving
	}

	;// Marine Medium
	{marine_03 (+ 100 (/ 200 %r));// distance at which it will be spotted when moving, 200m past visor range.
		{firing (/ 300 %r)}		;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 200}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 200}				;// unit still / not moving
	}

	;// Marine Large
	{marine_04 (+ 100 (/ 200 %r));// distance at which it will be spotted when moving, 200m past visor range.
		{firing (/ 400 %r)}		;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 300}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 300}				;// unit still / not moving
	}

	;// Marine Max
	{marine_05 (+ 100 (/ 200 %r));// distance at which it will be spotted when moving, 200m past visor range.
		{firing (/ 400 %r)}		;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 300}			;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 300}				;// unit still / not moving
	}
)

;/*=============== Presets End ===============*/

;/*=============== Generic Defines Begin ===============*/

(define "spotting"
	("radius" r(%0))				;// vision = radius * (one) applicable "rules" situation * (one) applicable "mods" situation
	{rules							;// no multiplication within rules blocks
		{human 100					;// fallback value if no other subordinated case is applicable
			{firing (/ 200 %0)	   ; // To achieve a constant distance of firing through noise, it divides by the radius multiplier. 1st Green line in v_visor
				("firing")			;// Preset from above (a modifier picked here is final, the stance for example will not be considered anymore)
			}
			("spot_human")			;// Preset from above
		}
		("spot_cannon" r(%0))		;// Preset from above
		("spot_vehicle" r(%0) d(50));// Preset from above
		("spot_ship" r(%0))			;// Preset from above
	}
	{mods							;// no nested blocks allowed, but all applicable values will be multiplied
		{stand 1}
	}
)

(define "glass"
	("radius" r(%0))
)

(define "spotting2"
	("radius" r(%0))				;// vision = radius * (one) applicable "rules" situation * (one) applicable "mods" situation
	{rules							;// no multiplication within rules blocks
		{human 100					;// fallback value if no other subordinated case is applicable
			{firing (/ 200 %0)	   ; // To achieve a constant distance of firing through noise, it divides by the radius multiplier. 1st Green line in v_visor
				("firing")			;// Preset from above (a modifier picked here is final, the stance for example will not be considered anymore)
			}
			("spot_human")			;// Preset from above
		}
		("spot_cannon" r(%0))		;// Preset from above
		("spot_vehicle" r(%0) d(%1));// Preset from above
		("spot_ship" r(%0))			;// Preset from above
	}
	{mods							;// no nested blocks allowed, but all applicable values will be multiplied
		{stand 1}
	}
)

;/*=============== Generic defines End ===============*/
