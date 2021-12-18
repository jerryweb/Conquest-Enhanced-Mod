game_entity
	(include "construction_generic.inc")
	{collider "construction"}
	{obstacleID "construction"}

	{lodclass "decor_big"}
	{mass 300}

	(define "add_climb_bones"
		{bone "%0"
			{bone "left_%0"
				{Matrix34
					{pos 8 8 0}
					{xform 0 -0.79 0}
				}
			}
			{bone "right_%0"
				{Matrix34
					{pos 8 -8 0}
					{xform 0 0.79 0}
				}
			}
		}
	)