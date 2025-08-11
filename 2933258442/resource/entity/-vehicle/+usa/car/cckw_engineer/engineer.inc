
	(include "/properties/car.ext")
	(include "/properties/selection/vehicle_elongated.inc" scale(1.15))
	(include "/properties/resupply.inc")
	{props "truck" "vision_lev02" "tractor" "tractor_heavy" "blast_large"}
	{able "emit_on_attack"}
	{collider "truck"}
	{patherId "cckw"}

	("supply_engineer")

	("wheel" args "wheelright1")
	("wheel" args "wheelleft1")
	("wheel" args "wheelright2")
	("wheel" args "wheelleft2")
	("wheel" args "wheelright3")
	("wheel" args "wheelleft3")

	("glass" args "window1")
	("glass" args "window2")
	("glass" args "window3")
	("glass" args "window4")
	("fuel" args "fuel")
	("transmission" args "transmission")

	("bodyback" repair(30))

	("shield_cover")

	{volume "detail4"
		{thickness 1}
	}
	{volume "detail5"
		{thickness 1}
	}

	{volume "body2" {able {holed}}}
	{volume "bodyback1" {able {holed}}}
	{volume "shield_cover" {able {holed}}}

	("crew_human"	place(driver)		bone(driver)	door(emit1) animation(driver)		group(crew))
	("crew_human_v" place(commander)	bone(commander)	door(emit2) animation(commander)	group(crew))

	("board_animation"
		place(driver)
		board_begin(board_big-midcar_driver)
		board_end(seat_driver_car)
		base(doorleft)
	)
	("board_animation"
		place(commander)
		board_begin(board_big-midcar)
		board_end(seat_passenger)
		base(doorright)
	)

	{extender "shield" {on}}

	{extender "inventory"
		{box
			{item "repair_kit" 5}
			
			{item "mine_detector" 2}
			{item "shovel_usa" 5}
			{item "satchel_charge_usa" 5}
			{item "pickaxe" 5}
			{item "wirecutters" 2}
		}
	}

	{mass 4160}
	{Chassis
		("car_trace" fx("tracewheel03") step(0.08) wheell("wlf") wheelr("wrf") bonel("FXtraceL1") boner("FXtraceR1"))
		("car_trace" fx("tracewheel03d") step(0.08) wheell("wlr") wheelr("wrr") bonel("FXtraceL2") boner("FXtraceR2"))
		("mobility_car"
			speed(72) ;----------------------------------Max speed.
			speedatmaxturn(15) ;-------------------------Max speed at max turn.
			reverse(22) ;--------------------------------Max speed in Reverse.
			weight(4.16) ;-------------------------------Weight in Tonnes.
			power(104) ;----------------------------------Horse Power.
			fuel(150) ;----------------------------------Fuel capacity in Litres.
			type(fuel) ;---------------------------------Fuel type.
			range(480) ;---------------------------------Range in Kilometers.
		)
	}

