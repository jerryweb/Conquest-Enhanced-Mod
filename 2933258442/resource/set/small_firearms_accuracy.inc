;(include "small_firearms_reticles.inc")

;/*----------------------*/

	(define "velocity"				;// muzzle velocity in meters per second
		{speed (* 0.70 %mps)}
	)
	(define "fire rate"				;// rate of fire in rounds per minute 
		{recoveryTime (/ 60 (* %rpm 1.07))}
	)
	(define "reload time"			;// reload time for magazine or shell
		{rechargeTime %seconds}
	)
	(define "human health"
		{healthDamage (* 1.0 %damage)}
	)
	(define "armor health"
		{minimumDamageModifier (* 1.0 %damage)}
	)

;/*----------------------*/

	(define "accuracy_pistol"
		("pistol_range"  r1(0.4) r2(1.0) globalaccuracy(1.00))
	)

;/*----------------------*/

	(define "accuracy_smg"
		("smg_range"  r1(0.9) r2(2.2) globalaccuracy(3.00))
	)

;/*----------------------*/

	(define "accuracy_rifle"
		("rifle_range"	r0(0.2) r1(0.4) r2(0.8) r3(1.00) globalaccuracy(1.50))
	)
	(define "accuracy_rifle_sniper"
		("sniper_range" r0(0.2) r1(0.4) r2(0.8) r3(1.00) globalaccuracy(1.00))
	)
	(define "accuracy_rifle_auto"
		("rifle_range"	r0(0.2) r1(0.5) r2(1.0) r3(1.50) globalaccuracy(2.00))
	)
	(define "accuracy_rifle_auto_sniper"
		("sniper_range" r0(0.4) r1(0.5) r2(1.0) r3(1.50) globalaccuracy(1.00))
	)
	(define "accuracy_battle_rifle"
		("rifle_range"	r0(0.3) r1(0.6) r2(1.2) r3(1.80) globalaccuracy(1.00))
	)
	(define "accuracy_assault_rifle"
		("rifle_range"	r0(0.2) r1(0.6) r2(1.25) r3(2.00) globalaccuracy(2.00))
	)
	(define "accuracy_shotgun"
		("rifle_range"	r0(0.2) r1(1.4) r2(0.9) r3(1.25) globalaccuracy(1.00))
	)
	(define "accuracy_rifle_at"
		("rifle_range"	r0(0.4) r1(0.8) r2(1.2) r3(1.50) globalaccuracy(1.00))
	)

;/*----------------------*/

	(define "accuracy_mg"
		("mg_range" r1(0.5) r2(1.3) r3(1.5) globalaccuracy(1.00))
	)
	(define "accuracy_hmg"
		("hmg_range" r1(0.5) r2(1.3) r3(1.5) globalaccuracy(1.00))
	)
	(define "accuracy_hmg_tank"
		("hmg_range" r1(0.4) r2(1.2) r3(1.4) globalaccuracy(1.00))
	)

	(define "accuracy_mg_plane"
		("plane_range" r1(1.0) globalaccuracy(1.00))
	)


;/*=========================Curves======================*/


 	(define "pistol_range"
		{spreading
			{radiusTable {0 0.01} {30 (* %globalaccuracy %r1)} {60 (* %globalaccuracy %r2)}}
		}
	)
	(define "smg_range"
		{spreading
			{radiusTable {0 0.01} {60 (* %globalaccuracy %r1)} {110 (* %globalaccuracy %r2)}}
		}
	)
 	(define "rifle_range"
		{spreading
			{radiusTable {0 0.01} {30 %r0} {60 (* %globalaccuracy %r1)} {95 (* %globalaccuracy %r2)} {120 (* %globalaccuracy %r3)}}
		}
	)
	(define "sniper_range"
		{spreading
			{radiusTable {0 0.01} {30 %r0} {60 (* %globalaccuracy %r1)} {95 (* %globalaccuracy %r2)} {120 (* %globalaccuracy %r3)} {130 (* %globalaccuracy %r3)} {180 5}}
		}
	)
	(define "mg_range"
		{spreading
			{radiusTable {0 0.04} {40 (* %globalaccuracy %r1)} {80 (* %globalaccuracy %r2)} {110 (* %globalaccuracy %r3)} {120 (* %globalaccuracy %r3)} {180 5}}
		}
	)
	(define "hmg_range"
		{spreading
			{radiusTable {0 0.02} {40 (* %globalaccuracy %r1)} {80 (* %globalaccuracy %r2)} {110 (* %globalaccuracy %r3)} {140 (* %globalaccuracy %r3)} {200 5}}
		}
	)
	(define "plane_range"
		{spreading
			{radiusTable {0 1} {100 (* 3 (* %globalaccuracy %r1))} {200 (* 5 (* %globalaccuracy %r1))} {300 (* 8 (* %globalaccuracy %r1))} {400 (* 10 (* %globalaccuracy %r1))}}
		}
	)


;/*====================Slope Multiplier==================*/


	(define "ap_slope_multiplier"	;use for AP and for any other Projectiles not specifically defined below
		{overmatchCalibre
			{0		0.96		0.0637	}
			{5		0.96297		0.0637	}
			{10		0.98297		0.0637	}
			{15		1.00066		0.0969	}
			{20		1.0361		0.13561	}
			{25		1.1116		0.16164	}
			{30		1.2195		0.19702	}
			{35		1.3771		0.22546	}
			{40		1.6263		0.26313	}
			{45		2.0033		0.34717	}
			{50		2.6447		0.57353	}
			{55		3.231		0.69075	}
			{60		4.0708		0.81826	}
			{65		6.2655		0.9192	}
			{70		8.6492		1.00539	}
			{75		13.7512		1.074	}
			{80		21.8713		1.17973	}
			{85		34.4862		1.28631	}
			{90		99.0000		0.00000	}
		}
	)
	(define "ap_7_62_slope_multiplier"	;	7.62mm - 8mm bullets, MG, rifles
		{overmatchCalibre
			{0		1			0.00	}
			{10		1.037		0.01	}
			{20		1.10		0.02	}
			{30		1.435		0.15	}
			{40		2.19		0.10	}
			{45		2.79		0.12	}
			{50		3.86		0.12	}
			{60		6.23		0.15	}
			{65		7.70		0.15	}
			{70		9.93		0.15	}
			{75		14.3		0.17	}
			{80		22.9		0.17	}
			{85		62.7		0.242	}
			{90		99.0000		0.00000	}
		}
	)
	(define "ap_12_slope_multiplier"	;	12.7mm bullets, HMG
		{overmatchCalibre
			{0		1			0.00	}
			{20		1.24		-0.015	}
			{30		1.59		0.015	}
			{40		1.885		0.11	}
			{45		2.395		0.15	}
			{50		3.32		0.14	}
			{60		5.43		0.185	}
			{65		6.78		0.192	}
			{70		8.85		0.193	}
			{75		12.75		0.21	}
			{80		22.17		0.245	}
			{85		69.6		0.36	}
			{90		99.0000		0.00000	}
		}
	)
	
	(define "at_rifle_slope_multiplier"	;use for AP and for any other Projectiles not specifically defined below
		{overmatchCalibre
			{0		0.1			0.0637	}
			{10		1.00066		0.0969	}
			{15		1.0361		0.13561	}
			{20		1.1116		0.16164	}
			{25		1.2195		0.19702	}
			{30		1.3771		0.22546	}
			{40		1.6263		0.26313	}
			{65		2.0033		0.34717	}
			{70		2.6447		0.57353	}
			{80		8.6492		1.00539	}
			{85		21.8713		1.17973	}
			{90		99.0000		0.00000	}
		}
	)

	(define "apcr_slope_multiplier"	;use for APCR & HVAP Projectiles 76mm Caliber or below
		{overmatchFixed
			{0  1.00	}
			{10	1.01	}
			{10	1.03	}
			{15	1.07	}
			{20	1.13	}
			{25	1.23	}
			{30	1.36	}
			{35	1.59	}
			{40	1.90	}
			{45	2.28	}
			{50	2.78	}
			{55	3.41	}
			{60	4.23	}
			{65	5.29	}
			{70	6.69	}
			{75	8.52	}
			{80	10.93	}
			{85	14.15	}
			{90 99		}
		}
	)

	(define "sway_pistol"
		{swayparams
			{bounds -0.25 0.2 -0.35 0.3}		; x -> negativeYaw, y -> positiveYaw, z -> negativePitch, w -> positive Pitch (in degree)
			{speed 0.1}						; sway speed coef
		}
	)

	(define "sway_smg"
		{swayparams
			{bounds -0.25 0.2 -0.35 0.3}		; x -> negativeYaw, y -> positiveYaw, z -> negativePitch, w -> positive Pitch (in degree)
			{speed 0.1}						; sway speed coef
		}
	)

	(define "sway_mg"
		{swayparams
			{bounds -0.3 0.2 -0.4 0.3}		; x -> negativeYaw, y -> positiveYaw, z -> negativePitch, w -> positive Pitch (in degree)
			{speed 0.3}						; sway speed coef
		}
	)

	(define "sway_rifle"
		{swayparams
			{bounds -0.3 0.2 -0.4 0.3}		; x -> negativeYaw, y -> positiveYaw, z -> negativePitch, w -> positive Pitch (in degree)
			{speed 0.2}						; sway speed coef
		}
	)

	(define "sway_sniper"
		{swayparams
			{bounds -0.35 0.25 -0.45 0.35}		; x -> negativeYaw, y -> positiveYaw, z -> negativePitch, w -> positive Pitch (in degree)
			{speed 0.2}						; sway speed coef
		}
	)

	(define "recoil_shotgun"
		{recoil
			{shoot {2.50 0.75} {1 0.75}}		; pitch / +- random and yaw / +- random, per shot, degree
			{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
			{restoreTime 1.00 0.025}			; recoil restore time, first -> minimum time, second -> additional time per shot, sec
			{restoreDelay 0.20}					; delay before restore, sec
		}
	)

	(define "recoil_rifle_at"
		{recoil
			{shoot {2.50 0.75} {1 0.75}}		; pitch / +- random and yaw / +- random, per shot, degree
			{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
			{restoreTime 1.10 0.025}			; recoil restore time, first -> minimum time, second -> additional time per shot, sec
			{restoreDelay 0.20}					; delay before restore, sec
		}
	)

	(define "recoil_pistol"
		{recoil
			{shoot {0.40 0.15} {0 0.45}}		; pitch / +- random and yaw / +- random, per shot, degree
			{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
			{restoreTime 0.25 0.005}			; recoil restore time, first -> minimum time, second -> additional time per shot, sec
			{restoreDelay 0.2}					; delay before restore, sec
		}
	)

	(define "recoil_stg"
		{recoil
			{shoot {0.45 0.20} {0 0.50}}		; pitch / +- random and yaw / +- random, per shot, degree
			{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
			{restoreTime 0.25 0.005}			; recoil restore time, first -> minimum time, second -> additional time per shot, sec
			{restoreDelay 0.2}					; delay before restore, sec
		}
	)

	(define "recoil_fg42"
		{recoil
			{shoot {0.55 0.20} {0.10 0.50}}		; pitch / +- random and yaw / +- random, per shot, degree
			{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
			{restoreTime 0.5 0.025}				; recoil restore time, first -> minimum time, second -> additional time per shot, sec
			{restoreDelay 0.20}					; delay before restore, sec
		}
	)

	(define "recoil_rifle_semi"
		{recoil
			{shoot {0.75 0.25} {0 0.60}}		; pitch / +- random and yaw / +- random, per shot, degree
			{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
			{restoreTime 0.5 0.025}				; recoil restore time, first -> minimum time, second -> additional time per shot, sec
			{restoreDelay 0.20}					; delay before restore, sec
		}
	)

	(define "recoil_rifle_bolt"
		{recoil
			{shoot {0.90 0.25} {0 0.60}}		; pitch / +- random and yaw / +- random, per shot, degree
			{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
			{restoreTime 0.5 0.025}				; recoil restore time, first -> minimum time, second -> additional time per shot, sec
			{restoreDelay 0.20}					; delay before restore, sec
		}
	)

	(define "recoil_sniper_semi"
		{recoil
			{shoot {1.20 0.25} {0 0.75}}		; pitch / +- random and yaw / +- random, per shot, degree
			{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
			{restoreTime 1.00 0.025}			; recoil restore time, first -> minimum time, second -> additional time per shot, sec
			{restoreDelay 0.20}					; delay before restore, sec
		}
	)

	(define "recoil_sniper_bolt"
		{recoil
			{shoot {1.50 0.25} {0 0.75}}		; pitch / +- random and yaw / +- random, per shot, degree
			{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
			{restoreTime 1.00 0.025}			; recoil restore time, first -> minimum time, second -> additional time per shot, sec
			{restoreDelay 0.20}					; delay before restore, sec
		}
	)

	(define "recoil_smg_low"
		{recoil
			{shoot {0.325 0.10} {0 0.2}}		; pitch / +- random and yaw / +- random, per shot, degree
			{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
			{restoreTime 0.15 0.005}				; recoil restore time, first -> minimum time, second -> additional time per shot, sec
			{restoreDelay 0.2}					; delay before restore, sec
		}
	)

	(define "recoil_smg_medium"
		{recoil
			{shoot {0.325 0.15} {0 0.25}}		; pitch / +- random and yaw / +- random, per shot, degree
			{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
			{restoreTime 0.15 0.005}				; recoil restore time, first -> minimum time, second -> additional time per shot, sec
			{restoreDelay 0.2}					; delay before restore, sec
		}
	)

	(define "recoil_mg_medium"
		{recoil
			{shoot {0.45 0.25} {0 0.515}}		; pitch / +- random and yaw / +- random, per shot, degree
			{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
			{restoreTime 0.25 0.005}				; recoil restore time, first -> minimum time, second -> additional time per shot, sec
			{restoreDelay 0.2}					; delay before restore, sec
		}
	)

	(define "recoil_hmg_medium"
		{recoil
			{shoot {0.50 0.25} {0 0.55}}		; pitch / +- random and yaw / +- random, per shot, degree
			{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
			{restoreTime 0.25 0.005	}			; recoil restore time, first -> minimum time, second -> additional time per shot, sec
			{restoreDelay 0.2}					; delay before restore, sec
		}
	)