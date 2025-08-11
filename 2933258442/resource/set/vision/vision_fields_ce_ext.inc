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
{"human_recon"							; // Soldiers with dedicated best vision (recon soldiers)	
	{uncover 50}	
	{h_fov 120}	
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
	{uncover 15}	
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

{"cannon_range_280"						; // Gunner Vision - Gun range 300m
	{uncover 1}
	{h_fov 50}
	{v_fov 170}
	("spotting2" r(2.8) r_human(1.0) veh_vis(110) can_vis(110) can_fire(110))
}

{"cannon_range_300"						; // Gunner Vision - Gun range 300m
	{uncover 1}
	{h_fov 50}
	{v_fov 170}
	("spotting2" r(3.0) r_human(1.0) veh_vis(110) can_vis(110) can_fire(110))
}

{"cannon_range_350"						; // Gunner Vision - Gun range 350m
	{uncover 1}
	{h_fov 50}
	{v_fov 170}
	("spotting2" r(3.5) r_human(0.152) veh_vis(120) can_vis(120) can_fire(120))
}

{"cannon_range_400"						; // Gunner Vision - Gun range 400m 
	{uncover 1}
	{h_fov 50}
	{v_fov 170}
	("spotting2" r(4.0) r_human(0.152) veh_vis(400) can_vis(130) can_fire(130))
}

{"cannon_range_450"						; // Gunner Vision - Gun range 450m 
	{uncover 1}
	{h_fov 50}
	{v_fov 170}
	("spotting2" r(4.5) r_human(0.152) veh_vis(140) can_vis(140) can_fire(140))
}

{"cannon_range_500"						; // Gunner Vision - Gun range 500m 
	{uncover 1}
	{h_fov 50}
	{v_fov 170}
	("spotting2" r(5.0) r_human(0.152) veh_vis(150) can_vis(150) can_fire(150))
}

{"cannon_range_550"						; // Gunner Vision - Gun range 550m 
	{uncover 1}
	{h_fov 50}
	{v_fov 170}
	("spotting2" r(5.5) r_human(0.152) veh_vis(160) can_vis(160) can_fire(160))
}

{"cannon_range_600"						; // Gunner Vision - Gun range 600m 
	{uncover 1}
	{h_fov 50}
	{v_fov 170}
	("spotting2" r(6.0) r_human(0.152) veh_vis(170) can_vis(170) can_fire(170))
}

;/*=============== Long Range Cannon End ===============*/


{"airborne_scout"						; // Scout plane vision (better than normal plane)
	{uncover 500} 						; // Planes cannot spot concealed soldiers
	{h_fov 360}
	{v_fov 360}
	("spotting" r(2.7))
}