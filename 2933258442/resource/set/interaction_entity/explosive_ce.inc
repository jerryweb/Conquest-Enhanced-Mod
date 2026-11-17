
(define "barrage_delay_ce"
	{link_sound "click" "gui/pointer/"}
	{play_sound "click"}
	{delay %delay {spawn "%barrage"}}
)
(define "last_barrage_delay_ce"
	{delay %delay {spawn "%barrage"} {delay 1 {delete}}}
)

;// Shared radio-verify body. Two barrages: first at %first, last at %last.
(define "conquest_barrage_ce"
	{on spawn overload
		{tags add "_barrage_requested"}
	}
	{on "verify_radio_present"
		{if tagged "_rejected"
			{delay 3 {delete}}
		 else tagged "_accepted"
			("barrage_delay_ce" delay(%first) barrage(%barrage))
			("last_barrage_delay_ce" delay(%last) barrage(%barrage))
		}
	}
)

;// Smoke variant: click sound, single barrage at %last.
(define "conquest_smoke_barrage_ce"
	{on spawn overload
		{tags add "_barrage_requested"}
	}
	{on "verify_radio_present"
		{if tagged "_rejected"
			{delay 3 {delete}}
		 else tagged "_accepted"
			{link_sound "click" "gui/pointer/"}
			{play_sound "click"}
			("last_barrage_delay_ce" delay(%last) barrage(%barrage))
		}

		{tags remove "_accepted"}
		{tags remove "_rejected"}		
	}
)

;// Mortars
{"conquest_mortar_barrage_80"
	("conquest_barrage_ce" first(5) last(20) barrage(mortar_barrage_80))
}
{"conquest_mortar_barrage_120"
	("conquest_barrage_ce" first(5) last(20) barrage(mortar_barrage_120))
}

;// Smoke
{"conquest_smoke_barrage_88_eng"
	("conquest_smoke_barrage_ce" last(10) barrage(smoke_barrage_88_eng))
}
{"conquest_smoke_barrage_105_ger"
	("conquest_smoke_barrage_ce" last(10) barrage(smoke_barrage_105_ger))
}
{"conquest_smoke_barrage_105_usa"
	("conquest_smoke_barrage_ce" last(10) barrage(smoke_barrage_105_usa))
}
{"conquest_smoke_barrage_122_rus"
	("conquest_smoke_barrage_ce" last(10) barrage(smoke_barrage_122_rus))
}

;// Artillery
{"conquest_artillery_barrage_88_eng"
	("conquest_barrage_ce" first(15) last(40) barrage(artillery_barrage_88_eng))
}
{"conquest_artillery_barrage_105_ger"
	("conquest_barrage_ce" first(15) last(40) barrage(artillery_barrage_105_ger))
}
{"conquest_artillery_barrage_105_usa"
	("conquest_barrage_ce" first(15) last(40) barrage(artillery_barrage_105_usa))
}
{"conquest_artillery_barrage_122_rus"
	("conquest_barrage_ce" first(15) last(40) barrage(artillery_barrage_122_rus))
}
{"conquest_artillery_barrage_140_eng"
	("conquest_barrage_ce" first(20) last(45) barrage(artillery_barrage_140_eng))
}
{"conquest_artillery_barrage_150_ger"
	("conquest_barrage_ce" first(20) last(45) barrage(artillery_barrage_150_ger))
}
{"conquest_artillery_barrage_152_rus"
	("conquest_barrage_ce" first(20) last(45) barrage(artillery_barrage_152_rus))
}
{"conquest_artillery_barrage_155_fin"
	("conquest_barrage_ce" first(20) last(45) barrage(artillery_barrage_155_fin))
}
{"conquest_artillery_barrage_155_usa"
	("conquest_barrage_ce" first(20) last(45) barrage(artillery_barrage_155_usa))
}
