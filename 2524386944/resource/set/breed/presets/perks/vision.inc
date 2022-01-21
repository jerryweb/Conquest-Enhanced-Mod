
; Vision abilities for use with sniper rifles and binoculars

(define "standard_vision"
	{"vision" human}
)

(define "elite_vision"
	{"vision" human_elite}
)

(define "recon_vision"
	{"vision" human_recon}
)

(define "sniper_vision"
	{"telescope"}
	{"aimedshot"}
	{"vision" human_elite}
)

(define "binocular_vision"
	{"field_glass"}
	{"vision" soldier_focused}
)