

;/*=============== Presets Begin ===============*/

; // Distances are in meters. Units are spotted when one the following conditions are met.
; // These preset values are multiplied by radius values in generic defines section to calculate in-game settings. 
; // Additionally, there is a global radius modifier on vision.set for a global vision reduction or augmentation. At the moment the radius modifier is 1.

(define "hear_firing"			;// Shooting specific weapons. These weappons/terms must be defined in vision/settings.set before use here. 
	{firing_welrod 0}
	{firing_delisle 0}
	{firing_silencer_m 0}
	{firing_silencer_n 0}
	{firing_k98_scope 100}
	{firing_mosin_scope 100}
	{firing_g43_scope 100}
	{firing_m1903a4 100}
	{firing_mosin_m27_scope 100}
	{firing_garand_scope 100}
	{firing_svt40_scope 100}
	{thrower 0}
)

(define "hear_human"

	{visible 5}

	{cover 5					;// default value incase condition isn't defined below. Important that {cover} block comes before non-cover {stand}, {squat}, and {crawl} blocks, else cover values will be overwritten. 
		{stand 5				;// "stand" stance - in cover
			{stealth 5}			;// "stand" stance - in cover and human has stealth skill
		}
		{squat 5				;// "squat" stance - in cover
			{stealth 5}			;// "squat" stance - in cover and human has stealth skill
		}
		{crawl 5				;// "crawl" stance - in cover
			{stealth 5}			;// "crawl" stance - in cover and human has stealth skill
		}
	}

	{stand 5					;// "stand" stance - moving. Also serves as default if other conditions are not defined in this block.
		{stealth 5}				;// "stand" stance - moving and human has stealth skill
		{still 5				;// "stand" stance - still / not moving. standing.
			{stealth 5}			;// "stand" stance - still / not moving and human has stealth skill
		}
	}

	{squat 5					;// "squat" stance - moving. Also serves as default if other conditions are not defined in this block. (doesn't apply, squat motion doesn't exist in Gem2)
		{stealth 5}				;// "squat" stance - moving and human has stealth skill (doesn't apply, squat motion doesn't exist in Gem2)
		{still 5				;// "squat" stance - still / not moving. kneeling.
			{stealth 5}			;// "squat" stance - still / not moving and human has stealth skill
		}
	}

	{crawl 5					;// "crawl" stance - moving. Also serves as default if other conditions are not defined in this block.
		{stealth 5}				;// "crawl" stance - moving and human has stealth skill
		{still 5				;// "crawl" stance - still / not moving. kneeling.
			{stealth 5}			;// "crawl" stance - still / not moving. kneeling and human has stealth skill
		}
	}
)

(define "hear_cannon"				;// This section defines the distances at which different types of cannons are spotted under various conditions.

	;//heavy mgun
	{cannon_00 5					;// distance at which it will be spotted when moving
		{firing (/ 80 %r)}			;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 5}					;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 5}					;// unit still / not moving. 1st Blue line in v_visor
	}

	;//infantry mortar
	{cannon_01 5					;// distance at which it will be spotted when moving
		{firing (/ 80 %r)}			;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 5}					;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 5}					;// unit still / not moving. 1st Blue line in v_visor
	}

	;// light gun
	{cannon_02 5					;// distance at which it will be spotted when moving
		{firing (/ 100 %r)}			;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 5}					;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 5}					;// unit still / not moving
	}

	;// medium gun
	{cannon_03 5					;// distance at which it will be spotted when moving
		{firing (/ 140 %r)}			;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 5}					;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 5}					;// unit still / not moving
	}

	;// heavy gun
	{cannon_04 5					;// distance at which it will be spotted when moving
		{firing (/ 160 %r)}			;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 5}					;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 5}					;// unit still / not moving
	}

	;// artillery
	{cannon_05 5					;// distance at which it will be spotted when moving
		{firing (/ 550 %r)}			;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 5}					;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 5}					;// unit still / not moving
	}
)

(define "hear_vehicle"				;// This section defines the distances at which different types of vehicles are spotted under various conditions.

	;// goliath
	{vehicle_00 10					;// distance at which it will be spotted when moving, 50m past visor range.
		{firing (/ 140 %r)}			;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 5}					;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 5}					;// unit still / not moving
	}
	
	;// moto, jeep
	{vehicle_01 (+ 100 (/ 50 %r))	;// distance at which it will be spotted when moving, 50m past visor range.
		{firing (/ 140 %r)}			;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 5}					;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 5}					;// unit still / not moving
	}

	;// armoredcars, trucks
	{vehicle_02 (+ 100 (/ 50 %r))	;// distance at which it will be spotted when moving, 50m past visor range.
		{firing (/ 160 %r)}			;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 5}					;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 5}					;// unit still / not moving
	}

	;// light tanks
	{vehicle_03 (+ 100 (/ 50 %r))	;// distance at which it will be spotted when moving, 50m past visor range.
		{firing (/ 180 %r)}			;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 5}					;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 5}					;// unit still / not moving
	}

	;// medium tanks, rocket artillery
	{vehicle_04 (+ 100 (/ 50 %r))	;// distance at which it will be spotted when moving, 50m past visor range.
		{firing (/ 200 %r)}			;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 5}					;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 5}					;// unit still / not moving
	}

	;//heavy tanks
	{vehicle_05 (+ 100 (/ 50 %r))	;// distance at which it will be spotted when moving, 50m past visor range.
		{firing (/ 220 %r)}			;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 5}					;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 5}					;// unit still / not moving
	}

	;//SPG indirect  artillery vehicles (105+mm)
	{vehicle_06 (+ 100 (/ 50 %r))	;// distance at which it will be spotted when moving, 50m past visor range.
		{firing (/ 550 %r)}			;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 5}					;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 5}					;// unit still / not moving
	}

	;// recon aircraft
	{plane_01 350					;// distance at which it will be spotted when moving
		{firing (/ 300 %r)}		;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 350}				;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 5}					;// unit still / not moving
	}

	;// fighter/bomber aircraft
	{plane_02 500					;// distance at which it will be spotted when moving
		{firing (/ 600 %r)}		;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 500}				;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 5}					;// unit still / not moving
	}
)

(define "hear_ship"				;// This section defines the distances at which different types of ships are spotted under various conditions.

	;// Small vessel
	{marine_01 (+ 100 (/ 50 %r));// distance at which it will be spotted when moving, 50m past visor range.
		{firing (/ 80 %r)}		;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 5}				;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 5}				;// unit still / not moving
	}

	;// Marine Small
	{marine_02 (+ 100 (/ 50 %r));// distance at which it will be spotted when moving, 50m past visor range.
		{firing (/ 80 %r)}		;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 5}				;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 5}				;// unit still / not moving
	}

	;// Marine Medium
	{marine_03 (+ 100 (/ 100 %r));// distance at which it will be spotted when moving, 200m past visor range.
		{firing (/ 80 %r)}		;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 5}				;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 5}				;// unit still / not moving
	}

	;// Marine Large
	{marine_04 (+ 100 (/ 100 %r));// distance at which it will be spotted when moving, 200m past visor range.
		{firing (/ 80 %r)}		;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 5}				;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 5}				;// unit still / not moving
	}

	;// Marine Max
	{marine_05 (+ 100 (/ 100 %r));// distance at which it will be spotted when moving, 200m past visor range.
		{firing (/ 80 %r)}		;// When this unit fires its weapon, it will be spotted up to this distance. Then, it will become fogged again after remaining visible for the period of time defined in set/detect.set
		{visible 5}				;// once spotted, the distance the unit will remain spotted until Line Of Sight is broken.
		{still 5}				;// unit still / not moving
	}
)

;/*=============== Presets End ===============*/

;/*=============== Generic Defines Begin ===============*/

(define "hearing"
	("radius" r(%0))				;// vision = radius * (one) applicable "rules" situation * (one) applicable "mods" situation
	{rules							;// no multiplication within rules blocks
		{human 5					;// fallback value if no other subordinated case is applicable
			{firing (/ 100 %0)		;// To achieve a constant distance of firing through noise, it divides by the radius multiplier. 1st Green line in v_visor
				("hear_firing" r(%0))	;// Preset from above (a modifier picked here is final, the stance for example will not be considered anymore)
			}
			("hear_human")			;// Preset from above
		}
		("hear_cannon" r(%0))		;// Preset from above
		("hear_vehicle" r(%0))		;// Preset from above
		("hear_ship" r(%0))			;// Preset from above
	}
	{mods							;// no nested blocks allowed, but all applicable values will be multiplied
		{stand 1}
	}
)

;/*=============== Generic defines End ===============*/
