
;/*=============== Human Begin ===============*/

{"human"								; Standard human vision
	{uncover 15}
	{h_fov 170}
	{v_fov 180}
	("vision_human" args 1)
}

{"human_peripheral"
	{uncover 10}
	{h_fov 270}
	{v_fov 220}
	("vision_human_peripheral" args 0.2)
}

{"human_elite"							; Soldiers with better vision (elites, officers, snipers)
	{uncover 15}
	{h_fov 110}
	{v_fov 190}
	("vision_human" args 1.1)
}

{"human_recon"							; Soldiers with better vision (recon soldiers)
	{uncover 15}
	{h_fov 120}
	{v_fov 200}
	("vision_human" args 1.2)
}

{"rifle_telescope"						; Primary vision for sniper scopes
	{uncover 10}
	{h_fov 360}
	{v_fov 120}
	("glass" args 10)
}

{"field_glass"							; Primary vision for binoculars
	{uncover 160}
	{h_fov 360}
	{v_fov 120}
	("glass" args 70)
}

{"soldier_focused"						; Secondary vision when soldier is looking through scope or binoculars
	{uncover 111}
	{h_fov 110}
	{v_fov 190}
	("vision_human" args 1.3)			; Disabled secondary vision when looking through scopes or binoculars
}

;/*=============== Human End ===============*/

;/*=============== Cannon Begin ===============*/

{"cannon_main"							; Standard main gun / gunner vision for cannons
	{uncover 5}
	{h_fov 50}
	{v_fov 170}
	("vision_vehicle_optic")
}

{"cannon_mortar"						; All mortars
	{uncover 5}
	{h_fov 90}
	{v_fov 170}
	("vision_human" args 1)
}

{"cannon_mgun"							; Machine Gun tripods
	{uncover 5}
	{h_fov 50}
	{v_fov 170}
	("vision_human" args 1)
}

{"cannon_crew"							; Cannon peripheral / loader vision
	{uncover 5}
	{h_fov 280}
	{v_fov 170}
	("vision_vehicle_around")
}

;/*=============== Cannon End ===============*/

;/*=============== Vehicle Begin ===============*/

{"vehicle_main"							; Standard vehicle / driver vision
	{uncover 3}
	{h_fov 50}
	{v_fov 100}
	("vision_human" args 1)
}

{"vehicle_top_mgun"						; Top mounted Machine gunners vision (jeeps, halftracks, etc)
	{uncover 3}
	{h_fov 90}
	{v_fov 150}
	("vision_human" args 1)
}

{"vehicle_top_turret"					; Vision for cars with closed top / turret gunner
	{uncover 3}
	{h_fov 30}
	{v_fov 30}
	("vision_vehicle")
}

{"vehicle_around"						; Vehicle peripheral / commander vision
	{uncover 3}
	{h_fov 360}
	{v_fov 60}
	("vision_vehicle_around")
}

;/*=============== Vehicle End ===============*/

;/*=============== Tank Begin ===============*/

{"tank_main-l"							; Light tank gunner vision
	{uncover 5}
	{h_fov 30}
	{v_fov 30}
	("vision_vehicle_optic")
}

{"tank_main-m"							; Medium tank gunner vision
	{uncover 5}
	{h_fov 30}
	{v_fov 30}
	("vision_vehicle_optic")
}

{"tank_main-h"							; Heavy tank gunner vision
	{uncover 5}
	{h_fov 30}
	{v_fov 30}
	("vision_vehicle_optic")
}

{"tank_main-aa"							; Tank's that have a AA gun from main weapon
	{uncover 5}
	{h_fov 50}
	{v_fov 170}
	("vision_vehicle_optic")
}

{"tank_driver"							; Tank Driver vision
	{uncover 3}
	{h_fov 35}
	{v_fov 20}
	("vision_vehicle")
}

{"tank_hull-mg"							; Tank Hull Machine gunner
	{uncover 3}
	{h_fov 30}
	{v_fov 30}
	("vision_vehicle")
}

{"tank_back"							; Tank with rear turret machine gun
	{uncover 3}
	{h_fov 50}
	{v_fov 50}
	("vision_vehicle")
}

{"tank_remote-mg"						; Remote controlled roof Machine gun (Hetzer, Stug3g, etc)
	{uncover 1}
	{h_fov 8}
	{v_fov 8}
	("vision_vehicle")
}

{"tank_shielded-mg"						; Shielded Machine gun (BA-64)
	{uncover 1}
	{h_fov 8}
	{v_fov 30}
	("vision_human" args 1)
}

{"tank_around"							; Tank peripheral / Commander vision
	{uncover 1}
	{h_fov 360}
	{v_fov 170}
	("vision_tank_around")
}

;/*=============== Tank End ===============*/

;/*=============== Airborne Begin ===============*/

{"airborne_main"						; Standard plane pilot vision
	{uncover 511}
	{h_fov 110}
	{v_fov 180}
	("vision_plane")
}

{"airborne_around"						; Pilot peripheral vision
	{uncover 35}
	{h_fov 360}
	{v_fov 360}
	("vision_plane_around")
}

{"airborne_scout"						; Scout plane vision (better than normal plane)
	{uncover 5}
	{h_fov 360}
	{v_fov 360}
	("vision_plane_scout")
}

;/*=============== Airborne End ===============*/

;/*=============== Marine Begin ===============*/

{"marine_main"
	{h_fov 120}
	{v_fov 180}
	("vision_vehicle")
}

{"marine_around"
	{h_fov 360}
	{v_fov 180}
	("vision_vehicle")
}

{"marine_cannon"
	{h_fov 110}
	{v_fov 110}
	("vision_vehicle_optic")
}

{"marine_torpedo"
	{h_fov 40}
	{v_fov 40}
	("vision_vehicle")
}

;/*=============== Marine End ===============*/

;/*=============== Other Begin ===============*/

{"cover-detector"
	{uncover 5}
	{h_fov 60}
	{v_fov 120}
	("vision_human" args 1)
}

{"animal"
	{uncover 2}
	{h_fov 360}
	{v_fov 120}
}

{"searchlight"
	("vision_vehicle_searchlight")
	{uncover 100}
	{h_fov 12}
	{v_fov 90}
}

{"watchtower"
	{h_fov 90}
	{v_fov 90}
	("vision_human" args 1)
}

(define "ultra_vision"
	{radius 20}
	{h_fov 360}
	{v_fov 180}
	{uncover %range}
)

{"start_point"	("ultra_vision" range(20))}
{"map_point"	("ultra_vision" range(20))}
{"flag_point"	("ultra_vision" range(20))}

{"none"}