{ZClipVisibility 0}

(define "body_vol"
	{Volume "%0"
		{tags "body"}
		{able {visible %1}}
	}
)

(define "roof_vol"
	{Volume "%0"
		{tags "roof"}
		{able {visible %1}}
	}
)

(define "declare_fire_volume"
	{Volume "fire%0"
		{able clear}
		{tags "fire"}
	}
	{Volume "smoke%0"
		{able clear}
		{tags "fire"}
	}
)

(define "declare_fire_volumes"
	{props "burning_old"}
	("declare_fire_volume" args 0)	("declare_fire_volume" args 1)
	("declare_fire_volume" args 2)	("declare_fire_volume" args 3)
	("declare_fire_volume" args 4)	("declare_fire_volume" args 5)
	("declare_fire_volume" args 6)	("declare_fire_volume" args 7)
	("declare_fire_volume" args 8)	("declare_fire_volume" args 9)
)

(define "armor_construction"
	{armor
		{setting "body"
			{threshold {pierce {koef 1}}}
			{ray_cast_thickness}
			{volumes "body*"}
		}
		{setting "roof"
			{threshold {pierce {koef 1}}}
			{ray_cast_thickness}
			{volumes "roof*"}
		}
	}
)

(define "blast_protection"
	{armor
		{setting "body"
			{threshold {blast {value %dmg}}}
		}
		{setting "roof"
			{threshold {blast {value %dmg}}}
		}
	}
)

(define "frag_grenade_protection"
	("blast_protection" dmg(6))
)

(define "armor_light"
	("armor_construction")
	{armor
		{setting "body"
			{threshold
				{blast {value 10}}
			}
		}
		{setting "roof"
			{threshold
				{blast {value 10}}
			}
		}
	}
)
(define "armor_medium"
	("armor_construction")
	{armor
		{setting "body"
			{threshold
				{blast {value 13}}
			}
		}
		{setting "roof"
			{threshold
				{blast {value 12}}
			}
		}
	}
)
(define "armor_heavy"
	("armor_construction")
	{armor
		{setting "body"
			{threshold
				{blast {value 22}}
			}
		}
		{setting "roof"
			{threshold 
				{blast {value 24}}
			}
		}
	}
)
(define "armor_sandbag_woodbeam"
	("armor_construction")
	{armor
		{setting "body"
			{threshold
				{blast {value 10}}
			}
		}
		{setting "roof"
			{threshold
				{blast {value 10}}
			}
		}
	}
)

(define "armor_adjustable"
	{armor
		{setting "body"
			{threshold
				{blast 
					{value %thresh_fg}
				}
				{pierce
					{value %thresh_ap}
					{calibre %calibre}
				}
			}
		}
		{setting "roof"
			{threshold {blast {value 10}}}
		}
	}
)

(define "armor_house_wood"
	("armor_light")
)
(define "armor_house_wood_heavy"
	("armor_heavy")
)

(define "armor_house_concrete"
	("armor_medium")
)
(define "armor_house_concrete_light"
	("armor_medium")
)


(define "armor_hedgehog"
	("armor_adjustable" thresh_fg(20) thresh_ap(45) calibre(57))
)

(define "armor_fabric"
	("armor_adjustable" thresh_fg(10) thresh_ap(15) calibre(12))
)

(define "armor_stack"
	("armor_adjustable" thresh_fg(10) thresh_ap(15) calibre(12))
)

(define "armor_glass"
	("armor_adjustable" thresh_fg(10) thresh_ap(15) calibre(0))
)

(define "armor_sandbag"
	("armor_adjustable" thresh_fg(10) thresh_ap(15) calibre(30))
)

(define "armor_post"
	("armor_adjustable" thresh_fg(10) thresh_ap(15) calibre(12))
)

(define "armor_wires"
	("armor_adjustable" thresh_fg(10) thresh_ap(15) calibre(12))
)

(define "armor_fence_wood"
	("armor_construction")
	{armor
		{setting "body"
			{threshold
				{blast {value 5}}
			}
		}
		{setting "roof"
			{threshold
				{blast {value 10}}
			}
		}
	}
)

(define "armor_use_volume_thickness"
	{armor
		{setting "body"
			{ray_cast_thickness 0}
		}
		{setting "roof"
			{ray_cast_thickness 0}
		}
	}
)

(define "armor_disable_damage_acc"
	{armor
		{setting "body"
			{disable_damage_acc}
		}
		{setting "roof"
			{disable_damage_acc}
		}
	}
)

(include "texmod.inc")

("armor_medium")