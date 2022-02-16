; // This script defines the VISION FIELDS of the units. 
; // Units can have several vision fields. For example, a human has the forward main vision field and the peripheral one.
; // 
; // {uncover 15} <- Will spot hidden soldiers in bushes within 15m
; // {h_fov 100}  <- Horizontal field of view arc = 100 degree
; // {v_fov 180}  <- Vertical field of view arc = 180 degree (straight up or down)
; // ("spotting" args 2)  <- Sets the "vision range", defined in generic.inc, so this unit will do spotting twice as far.
; // Or in other terms, the vision distances will be x2


;/*=============== Human Begin ===============*/


{"human"								; // Standard human vision
	{uncover 20}
	{h_fov 100}
	{v_fov 180}
	("spotting" args 1.0)
}

{"human_peripheral"						; // Additional all-round (weaker) situational awareness vision for humans
	{uncover 10}
	{h_fov 240}
	{v_fov 120}
	("spotting" args 0.2)
}

{"human_elite"							; // Soldiers with better vision (elites, officers, snipers)
	{uncover 20}
	{h_fov 120}
	{v_fov 180}
	("spotting" args 1.0)
}

{"human_recon"							; // Soldiers with dedicated best vision (recon soldiers)
	{uncover 20}
	{h_fov 120}
	{v_fov 180}
	("spotting" args 1.25)
}

{"rifle_telescope"						; // Primary vision for sniper scopes
	{uncover 15}
	{h_fov 360}
	{v_fov 120}
	("glass" args 15)
}

{"field_glass"							; // Primary vision for binoculars
	{uncover 330}
	{h_fov 360}
	{v_fov 120}
	("glass" args 50)
}

{"soldier_focused"						; // Secondary vision when soldier is looking through scope or binoculars
	{uncover 10}
	{h_fov 70}
	{v_fov 150}
	;("spotting" args 1)			; // Disabled secondary vision when looking through scopes or binoculars
}

;/*=============== Human End ===============*/

;/*=============== Cannon Begin ===============*/

{"cannon_main"							; // Standard main gun / gunner vision for cannons
	{uncover 25}
	{h_fov 30}
	{v_fov 170}
	("spotting" args 1.5)
}

{"cannon_mortar"						; // All mortars
	{uncover 25}
	{h_fov 90}
	{v_fov 170}
	("spotting" args 1)
}

{"cannon_range_200"						; // Gunner Vision - Gun range 200m or less (direct fire only)
	{uncover 25}
	{h_fov 30}
	{v_fov 170}
	("spotting2" args 1.5 50)
}

{"cannon_range_210"						; // Gunner Vision - Gun range 210m (direct fire only)
	{uncover 25}
	{h_fov 30}
	{v_fov 170}
	("spotting2" args 1.5 60)
}

{"cannon_range_220"						; // Gunner Vision - Gun range 220m (direct fire only)
	{uncover 25}
	{h_fov 30}
	{v_fov 170}
	("spotting2" args 1.5 70)
}

{"cannon_range_230"						; // Gunner Vision - Gun range 230m (direct fire only)
	{uncover 25}
	{h_fov 30}
	{v_fov 170}
	("spotting2" args 1.5 80)
}

{"cannon_range_240"						; // Gunner Vision - Gun range 240m (direct fire only)
	{uncover 25}
	{h_fov 30}
	{v_fov 170}
	("spotting2" args 1.5 90)
}

{"cannon_range_250"						; // Gunner Vision - Gun range 250m (direct fire only)
	{uncover 25}
	{h_fov 30}
	{v_fov 170}
	("spotting2" args 1.5 100)
}

;/*=============== Cannon End ===============*/

;/*=============== Vehicle Begin ===============*/

{"vehicle_main"							; // Standard vehicle / driver vision
	{uncover 25}
	{h_fov 50}
	{v_fov 100}
	("spotting" args 1)
}

{"vehicle_top_mgun"						; // Top mounted Machine gunners vision (jeeps, halftracks, etc)
	{uncover 25}
	{h_fov 90}
	{v_fov 150}
	("spotting" args 1)
}

{"vehicle_top_turret"					; // Vision for cars with closed top / turret gunner
	{uncover 25}
	{h_fov 30}
	{v_fov 30}
	("spotting" args 0.85)
}

{"vehicle_around"						; // Vehicle peripheral / commander vision
	{uncover 15}
	{h_fov 360}
	{v_fov 60}
	("spotting" args 0.6)
}

;/*=============== Vehicle End ===============*/

;/*=============== Tank Begin ===============*/

{"recon_main"							; // Recon gunner vision
	{uncover 25}
	{h_fov 60}
	{v_fov 90}
	("spotting" args 1.25)
}

{"tank_main_mg"							; // Gunner vision when main gun is MG
	{uncover 20}
	{h_fov 15}
	{v_fov 30}
	("spotting" args 1.0)
}

{"tank_main-l"							; // Light tank gunner vision
	{uncover 20}
	{h_fov 15}
	{v_fov 30}
	("spotting" args 1.5)
}

{"tank_main-m"							; // Medium tank gunner vision
	{uncover 20}
	{h_fov 15}
	{v_fov 30}
	("spotting" args 1.5)
}

{"tank_main-h"							; // Heavy tank gunner vision
	{uncover 20}
	{h_fov 15}
	{v_fov 30}
	("spotting" args 1.5)
}

{"tank_main-aa"							; // Tank's that have a AA gun from main weapon
	{uncover 20}
	{h_fov 30}
	{v_fov 170}
	("spotting" args 1.5)
}

{"tank_driver"							; //Tank Driver vision
	{uncover 20}
	{h_fov 45}
	{v_fov 30}
	("spotting" args 0.85)
}

{"tank_hull-mg"							; // Tank Hull Machine gunner
	{uncover 20}
	{h_fov 30}
	{v_fov 30}
	("spotting" args 0.85)
}

{"tank_back"							; // Tank with rear turret machine gun
	{uncover 20}
	{h_fov 50}
	{v_fov 50}
	("spotting" args 0.85)
}

{"tank_remote-mg"						; // Remote controlled roof Machine gun (Hetzer, Stug3g, etc)
	{uncover 20}
	{h_fov 8}
	{v_fov 8}
	("spotting" args 0.85)
}

{"tank_shielded-mg"						; // Shielded Machine gun (BA-64)
	{uncover 20}
	{h_fov 8}
	{v_fov 30}
	("spotting" args 1)
}

{"tank_around"							; // Tank peripheral / Commander vision
	{uncover 15}
	{h_fov 360}
	{v_fov 170}
	("spotting" args 0.6)
}

;/*=============== Tank End ===============*/

;/*=============== New Setup Begin ===============*/

{"tank_range_200"							; // Gunner Vision - Gun range 200m or less (direct fire only)
	{uncover 20}
	{h_fov 15}
	{v_fov 30}
	("spotting2" args 1.5 50)
}

{"tank_range_210"							; // Gunner Vision - Gun range 210m (direct fire only)
	{uncover 20}
	{h_fov 15}
	{v_fov 30}
	("spotting2" args 1.5 60)
}

{"tank_range_220"							; // Gunner Vision - Gun range 220m (direct fire only)
	{uncover 20}
	{h_fov 15}
	{v_fov 30}
	("spotting2" args 1.5 70)
}

{"tank_range_230"							; // Gunner Vision - Gun range 230m (direct fire only)
	{uncover 20}
	{h_fov 15}
	{v_fov 30}
	("spotting2" args 1.5 80)
}

{"tank_range_240"							; // Gunner Vision - Gun range 240m (direct fire only)
	{uncover 20}
	{h_fov 15}
	{v_fov 30}
	("spotting2" args 1.5 90)
}

{"tank_range_250"							; // Gunner Vision - Gun range 250m (direct fire only)
	{uncover 20}
	{h_fov 15}
	{v_fov 30}
	("spotting2" args 1.5 100)
}

;/*=============== New Setup End ===============*/

;/*=============== Airborne Begin ===============*/

{"airborne_main"						; // Standard plane pilot vision
	{uncover 0} 						; // Planes cannot spot concealed soldiers
	{h_fov 110}
	{v_fov 180}
	("spotting" args 3.5)
}

{"airborne_around"						; // Pilot peripheral vision
	{uncover 0} 						; // Planes cannot spot concealed soldiers
	{h_fov 360}
	{v_fov 360}
	("spotting" args 1)
}

{"airborne_scout"						; // Scout plane vision (better than normal plane)
	{uncover 0} 						; // Planes cannot spot concealed soldiers
	{h_fov 360}
	{v_fov 360}
	("spotting" args 1.3)
}

;/*=============== Airborne End ===============*/

;/*=============== Marine Begin ===============*/

{"marine_main"
	{h_fov 120}
	{v_fov 180}
	("spotting" args 0.85)
}

{"marine_around"
	{h_fov 360}
	{v_fov 180}
	("spotting" args 0.85)
}

{"marine_cannon"
	{h_fov 110}
	{v_fov 110}
	("spotting" args 1.3)
}

{"marine_torpedo"
	{h_fov 40}
	{v_fov 40}
	("spotting" args 0.85)
}

;/*=============== Marine End ===============*/

;/*=============== Other Begin ===============*/

{"noise_detection"								; // hearing aid
	{uncover 5}
	{h_fov 360}
	{v_fov 180}
	("hearing" args 1)
}

{"cover-detector"
	{uncover 5}
	{h_fov 60}
	{v_fov 120}
	("spotting" args 1)
}

{"animal"
	{uncover 2}
	{h_fov 360}
	{v_fov 120}
}

{"searchlight"
	{uncover 100}
	{h_fov 12}
	{v_fov 90}
	("spotting" args 2.5)
}

{"watchtower"
	{h_fov 90}
	{v_fov 90}
	("spotting" args 1)
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