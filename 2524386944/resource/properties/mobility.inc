;/*=============== TANK DEF CONTENTS GUIDE BEGIN ===============*/

;// Every tank has it's values related to mobility in the define file.

;		("mobility_*****"  <- This specifies which specific mobility class
;			speed(55) ;----------------------------------Max speed when fully accelerated on road, km/h.
;			reverse(25) ;--------------------------------Max speed in reverse, km/h.
;			traverse(10) ;-------------------------------Track traverse, per second, in degrees.
;			weight(30.9) ;-------------------------------Weight in Tonnes.
;			power(500) ;---------------------------------Engine Power, in hp.
;			track(6) ;-----------------------------------Track performance: (0,10], 10=ideal. Sluggish tanks and vehicles with narrow and non-gripping tracks have a lower performance.
;			fuel(420) ;----------------------------------Fuel capacity in Litres.
;			type(diesel OR fuel) ;-----------------------Fuel type.
;			range(210) ;---------------------------------Range in km, off-road.

;// These values are then placed into the mobility formulas below, and to derive secondary values.

;/*===============  TANK DEF GUIDE END ===============*/


(define "mobility_tank"
	{Locomotion
		{Slow 10}																								;// Slow speed. Mainly used in mission scripting
		{Normal (* %speed 0.5)} 																				;// Standard speed. Single click movement order
		{Fast (* %speed 0.9)}																							;// Sprint speed. Double click movement order
		{MaxSpeed %speed}																						;// Max speed.
		{maxSpeedAtMaxTurn (* %speed (* (/ %track 30) (/ %power (* %weight 5))))}								;// Direct Control, Max speed the vehicle is limited to when executing a tight turn.

	;	{TurnTime (/ 360 (+ (/ %power %weight) (/ (* %speed %track) 10)))};/									;// Direct Control, Time it takes to do a full 360 degree at max turn speed, mathematical approximation
		{TurnTime (/ 360 %traverse)};/								                                          	;// Direct Control, Time it takes to do a full 360 degree at max turn speed, fetching custom define
		
		{TurnStart (+ 0.75 (* (/ %weight 6) 0.04))};/															;// Direct Control, Time for vehicle to from 0°/s rotation speed to max rotation speed.
		{TurnStop (+ 0.75 (* (/ %weight 6) 0.04))};/															;// Direct Control, Time for vehicle to from max rotation speed to 0°/s rotation speed to max rotation speed.


		{TurnRadius (+ 8 (+ (/ %weight 30) (/ (* 1000 %weight) (* %traverse %power))))}		                    ;// AI turning radius, lower = able to turn more without stopping.


		{StartTime (* 5 (/ %speed (/ %power %weight)))}															;// Time for vehicle to accelerate from 0kph to max speed.		
		{StopTime (+ 1.50 (* %weight 0.04))}																	;// Time to come to a complete stop from max speed with out applying brakes. "Coasting".
		{BrakeTime (+ 0.80 (* %weight 0.04))}																	;// Time to come to a complete stop from max speed with brakes applied.

		{Gears 0.5 0.65 0.8 0.9 1.0}																				;// Forward gear ratios
		{RearGears 0.05 (/ %reverse %speed)};/																	;// Reverse max speed.
		{GearSwitchDelay 0.5}																					;// Time to switch between forward and reverse.
		{MaxSlope 	75}																							;// Maximum slope to drive up hill
		{FallSlope 	75}																							;// Maximum slope before physics kick in
	}
	{FuelBag
		{volume %fuel}						;// Fuel capacity in Litres.
		{rate (* 10 (/ %fuel %range))};/	;// Fuel cunsumption rate. Based on off-road range of vehicle.
		{remain %fuel}						;// Amount of fuel in vehicle when spawned.
		{fuel "%type"}						;// Fuel type.
	}
)

(define "mobility_car"
	{Locomotion
		{Slow 10}												;// Slow speed. Mainly used in mission scripting
		{Normal 20}												;// Standard speed. Single click movement order
		{Fast %speed}											;// Sprint speed. Double click movement order
		{MaxSpeed %speed}										;// Max speed.
		{maxSpeedAtMaxTurn %speedatmaxturn}						;// Max speed the vehicle is limited to when executing a tight turn.
		{StartTime (* (/ %speed (/ %power %weight)) 7)}			;// Time for vehicle to accelerate from 0kph to max speed.
		{SteerOn	30}											;// Steering wheel's turn speed, degrees per second.
		{SteerOff	30}											;// Steering wheel's relaxed (no control applied) neutral position return speed, degrees per second.
		{TurnRadius 5}											;// AI turning radius, lower = able to turn more without stopping.
		{StopTime (+ 3 (* %weight (* %speed 0.020)))}			;// Time to come to a complete stop from max speed with out applying brakes. "Coasting".
		{BrakeTime (+ 1 (* %weight (* %speed 0.004)))}			;// Time to come to a complete stop from max speed with brakes applied. 
		{Gears 0.15 1}											;// Gearing affects acceleration curve.
		{RearGears (/ %reverse %speed)};/						;// Reverse max speed.
		{GearSwitchDelay 0.5}									;// Time to switch between forward and reverse.
		{SplineRadius 0.75}										;// limit turning radius on the splines (path planner parameter), meters
		{MaxSlope	75}											;// Maximum slope to drive up hill
		{FallSlope	75}											;// Maximum slope before physics kick in
	}
	{FuelBag
		{volume %fuel }						;// Fuel capacity in Litres.
		{rate (* 10 (/ %fuel %range))};/	;// Fuel cunsumption rate. Based on off-road range of vehicle.
		{remain %fuel }						;// Amount of fuel in vehicle when spawned.
		{fuel "%type"}						;// Type of fuel used. "fuel" = petrol/gasoline. "diesel" = diesel.
	}
)

(define "mobility_btr"
	{Locomotion
		{Slow 10}												;// Slow speed. Mainly used in mission scripting
		{Normal 20}												;// Standard speed. Single click movement order
		{Fast %speed}											;// Sprint speed. Double click movement order
		{MaxSpeed %speed}										;// Max speed.
		{maxSpeedAtMaxTurn %speedatmaxturn}						;// Max speed the vehicle is limited to when executing a tight turn.
		{StartTime (* (/ %speed (/ %power %weight)) 4)}			;// Time for vehicle to accelerate from 0kph to max speed.
		{SteerOn	20}											;// Steering wheel's turn speed, degrees per second.
		{SteerOff	20}											;// Steering wheel's relaxed (no control applied) neutral position return speed, degrees per second.
		{TurnRadius 5}											;// AI turning radius, lower = able to turn more without stopping.
		{StopTime (+ 2 (* %weight (* %speed 0.004)))}			;// Time to come to a complete stop from max speed with out applying brakes. "Coasting".
		{BrakeTime (+ 1 (* %weight (* %speed 0.004)))}			;// Time to come to a complete stop from max speed with brakes applied. 
		{Gears 0.15 1}											;// Gearing affects acceleration curve.
		{RearGears (/ %reverse %speed)};/						;// Reverse max speed.
		{GearSwitchDelay 0.5}									;// Time to switch between forward and reverse.
		{SplineRadius 0.75}										;// limit turning radius on the splines (path planner parameter), meters
		{MaxSlope	75}											;// Maximum slope to drive up hill
		{FallSlope	75}											;// Maximum slope before physics kick in
	}
	{FuelBag
		{volume %fuel}						;// Fuel capacity in Litres.
		{rate (* 10 (/ %fuel %range))};/	;// Fuel cunsumption rate. Based on off-road range of vehicle.
		{remain %fuel}						;// Amount of fuel in vehicle when spawned.
		{fuel "%type"}						;// Type of fuel used. "fuel" = petrol/gasoline. "diesel" = diesel.
	}
)

(define "mobility_cannon"
	{Locomotion
		{Slow (* %speed 0.33)}									;// Slow speed. Mainly used in mission scripting
		{Normal (* %speed 0.66)}								;// Standard speed. Single click movement order
		{Fast %speed}											;// Sprint speed. Double click movement order
		{MaxSpeed	%speed}
		{StartTime	(+ 1.25 (/ %weight 4000))};/
		{TurnTime	(- (+ (/ %weight 500) (/ 100 %speed)) 4)}
		{BrakeTime	(+ 0.5 (/ %weight 10000))};/
		{StopTime	(+ 1.25 (/ %weight 4000))};/
		{TurnRadius	(+ 2 (/ %weight 5000))};/
		{TurnStart	(+ 0.65 (/ %weight 1500))};/
		{TurnStop	(+ 0.65 (/ %weight 2500))};/
		{Gears		0.35 0.5 0.7 1.0}
		{RearGears	0.33 0.75}
		{MaxSlope	60}
		{FallSlope	70}
	}
)


(define "flight_model"
	{locomotion
		{Slow	 (* 0.7 (/ (* %speed %power) (* %weight %aerodynamics)))};/	;// Slow speed. Mainly used in mission scripting
		{Normal	 (* 1.0 (/ (* %speed %power) (* %weight %aerodynamics)))};/	;// Standard speed. Single click movement order
		{Fast	 (* 1.0 (/ (* %speed %power) (* %weight %aerodynamics)))};/	;// Sprint speed. Double click movement order
		{Maxspeed(* 1.0	(/ (* %speed %power) (* %weight %aerodynamics)))};/	;// max speed while in flight mode in kph
		{turnRadius		(* 0.3 %turn)} 										;// radius to do a 360° turn in meters
	}

	{FuelBag
		{volume %fuel}						;// Fuel capacity in Litres.
		{rate (* 20 (/ %fuel %range))};/	;// Fuel cunsumption rate. Based on off-road range of vehicle.
		{remain %fuel}						;// Amount of fuel in vehicle when spawned.
		{fuel "fuel"}						;// Type of fuel used. "fuel" = petrol/gasoline. "diesel" = diesel.
	}

	{sideSlopeSpeed %roll_rate	}					;// how quickly in degrees per second that aircraft rolls 
	{maxSideSlope 	%roll_angle	}					;// limit in degrees that aircraft can roll while in a turn

	{maxElevationSpeed (+ (/ %climb_speed 6) 2)};/		;// climb rate, how many meters per second aircraft changes altitude when in full climb or dive
	{elevationAcceleration (+ (/ %climb_speed 4) 2)};/	;// how quickly aircraft can change from level flight to full climb or dive. (m/s^2)
)



(define "mobility_train"
	{Locomotion
		{Slow (* %speed 0.33)}									;// Slow speed. Mainly used in mission scripting
		{Normal (* %speed 0.66)}								;// Standard speed. Single click movement order
		{Fast %speed}											;// Sprint speed. Double click movement order
		{MaxSpeed %speed}
		{StartTime (* (/ %speed (/ %power %weight)) 9)}			;// Time for vehicle to accelerate from 0kph to max speed.
		{StopTime (+ 3 (* %weight (* %speed 0.025)))}			;// Time to come to a complete stop from max speed with out applying brakes. "Coasting".
		{BrakeTime (+ 2 (* %weight (* %speed 0.01)))}			;// Time to come to a complete stop from max speed with brakes applied. 
		{RearGears (/ %reverse %speed)};/						;// Reverse max speed.
		{GearSwitchDelay 0.5}									;// Time to switch between forward and reverse.
	}

	{FuelBag
		{volume %fuel}						;// Fuel capacity in Litres.
		{rate (* 10 (/ %fuel %range))};/	;// Fuel cunsumption rate. Based on off-road range of vehicle.
		{remain %fuel}						;// Amount of fuel in vehicle when spawned.
		{fuel "%type"}						;// Type of fuel used. "fuel" = petrol/gasoline. "diesel" = diesel.
	}

	{Locomotive 1}
)
