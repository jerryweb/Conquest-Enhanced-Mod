; // This script defines the VISION FIELDS of the units. 
; // Units can have several vision fields. For example, a human has the forward main vision field and the peripheral one.
; // 
; // {uncover 15} <- Will spot hidden soldiers in bushes within 15m
; // {h_fov 100}  <- Horizontal field of view arc = 100 degree
; // {v_fov 180}  <- Vertical field of view arc = 180 degree (straight up or down)
; // ("spotting" args 2)  <- Sets the "vision range", defined in generic.inc, so this unit will do spotting twice as far.
; // Or in other terms, the vision distances will be x2


;/*=============== Human Begin ===============*/

; These are overwrites of the vanilla spotting values
{"human"								; // Standard human vision
	{uncover 25}
	{h_fov 150}
	{v_fov 180}
	("spotting" r(1.0))
}

{"human_peripheral"						; // Additional all-round (weaker) situational awareness vision for humans
	{uncover 10}
	{h_fov 240}
	{v_fov 120}
	("spotting" r(0.22))
}

{"human_elite"							; // Soldiers with better vision (elites, officers, snipers)
	{uncover 30}
	{h_fov 150}
	{v_fov 180}
	("spotting" r(1.1))
}

{"human_recon"							; // Soldiers with dedicated best vision (recon soldiers)	
	{uncover 50}	
	{h_fov 150}	
	{v_fov 180}	
	("spotting" r(1.50))	
}	

{"rifle_telescope"						; // Primary vision for sniper scopes	
	{uncover 15}	
	{h_fov 360}	
	{v_fov 120}	
	("glass" r(15))	
}	

{"field_glass"							; // Primary vision for binoculars	
	{uncover 25}	
	{h_fov 360}	
	{v_fov 120}	
	("glass" r(60))	
}	

{"soldier_focused"						; // Secondary vision when soldier is looking through scope or binoculars	
	{uncover 10}	
	{h_fov 70}	
	{v_fov 150}	
	("spotting" r(1))			; // Disabled secondary vision when looking through scopes or binoculars	
	{wide 2}	
}

;/*=============== Long Range Cannon Begin ===============*/

;/*=============== Long Range Cannon End ===============*/


{"airborne_scout"						; // Scout plane vision (better than normal plane)
	{uncover 500} 						; // Planes cannot spot concealed soldiers
	{h_fov 360}
	{v_fov 360}
	("spotting" r(2.7))
}

;/*=============== Vehicle Begin ===============*/


{"vehicle_top_mgun"						; // Top mounted Machine gunners vision (jeeps, halftracks, etc)
	{uncover 15}
	{h_fov 90}
	{v_fov 170}
	("spotting" r(0.8))
}

{"vehicle_around"						; // Vehicle peripheral / commander vision
	{uncover 25}
	{h_fov 360}
	{v_fov 150}
	("spotting" r(1.0))
}

;/*=============== Tank Begin ===============*/


{"recon_main"							; // Recon gunner vision
	{uncover 50}
	{h_fov 60}
	{v_fov 90}
	("spotting2" r(1.5) r_human(0.9) veh_vis(95) can_vis(90) can_fire(120))
}

{"recon_open"							; // Open Top Recon gunner vision
	{uncover 50}
	{h_fov 90}
	{v_fov 170}
	("spotting2" r(1.5) r_human(1.0) veh_vis(110) can_vis(90) can_fire(120))
}