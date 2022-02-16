;AUTOMATIC WEAPONRY
{"maxim"
	{on spawn
	    {tags add "HMG"}
		{tags add "soviet"}
		{tags add "maxim"}
	}
}
{"dshk_stan"
	{on spawn
	    {tags add "HMG"}
		{tags add "soviet"}
		{tags add "dshk_stan"}
	}
}
{"dshk_aa"
	{on spawn
	    {tags add "HMG"}
		{tags add "soviet"}
		{tags add "dshk_aa"}
	}
}
{"25mm_72k"
	{on spawn
	    {tags add "AAFLAK"}
		{tags add "soviet"}
		{tags add "25mm_72k"}
	}
}
{"37mm_61k"
	{on spawn
	    {tags add "AAFLAK"}
		{tags add "soviet"}
		{tags add "37mm_61k"}
	}
}


; AT WEAPONRY
{"m41_ampulomet"
	{on spawn
	    {tags add "light_at_gun"}
		{tags add "soviet"}
		{tags add "m41_ampulomet"}
	}
}
{"45mm_m37"
	{on spawn
	    {tags add "light_at_gun"}
		{tags add "soviet"}
		{tags add "45mm_m37"}
	}
}
{"45mm_m42"
	{on spawn
	    {tags add "light_at_gun"}
		{tags add "soviet"}
		{tags add "45mm_m42"}
	}
}
{"57mm_zis2"
	{on spawn
	    {tags add "medium_at_gun"}
		{tags add "soviet"}
		{tags add "57mm_zis2"}
	}
}
{"76mm_f22"
	{on spawn
	    {tags add "medium_at_gun"}
		{tags add "soviet"}
		{tags add "76_f22"}
	}
}
{"76mm_zis3"
	{on spawn
	    {tags add "medium_at_gun"}
		{tags add "soviet"}
		{tags add "76mm_zis3"}
	}
}
{"85mm_52k"
	{on spawn
	    {tags add "heavy_at_gun"}
		{tags add "soviet"}
		{tags add "85mm_52k"}
	}
}
{"100mm_bs3"
	{on spawn
	    {tags add "heavy_at_gun"}
		{tags add "soviet"}
		{tags add "100mm_bs3"}
	}
}


;HOWITZERS
{"76mm_m1927"
	{on spawn
    	{tags add "medium_at_gun"}
		{tags add "soviet"}
		{tags add "76mm_m1927"}
	}
}
{"76mm_m43"
	{on spawn
    	{tags add "medium_at_gun"}
		{tags add "soviet"}
		{tags add "76mm_m43"}
	}
}
{"82mm_bm37"
	{on spawn
		{tags add "artillery"}
		{tags add "soviet"}
		{tags add "82mm_bm37"}
	}
}
{"120mm_pm38"
	{on spawn
		{tags add "artillery"}
		{tags add "soviet"}
		{tags add "120mm_pm38"}
	}
}
{"122mm_m30"
	{on spawn
    	{tags add "artillery"}
		{tags add "soviet"}
		{tags add "122mm_m30"}
	}
}
{"122mm_a19"
	{on spawn
    	{tags add "artillery"}
	{tags add "heavy_artillery"}
		{tags add "soviet"}
		{tags add "122mm_a19"}
	}
}
{"152mm_ml20"
	{on spawn
    	{tags add "artillery"}
	{tags add "heavy_artillery"}
		{tags add "soviet"}
		{tags add "152mm_ml20"}
	}
}
{"203mm_b4"
	{on spawn
    	{tags add "artillery"}
	{tags add "heavy_artillery"}
		{tags add "soviet"}
		{tags add "203mm_b4"}
	}
}

;_________________________________________________
;|               Wheeled vehicles                 |
;|________________________________________________|


{"gaz_aaa"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "gaz_aaa"}
    }
}
{"gaz_aaa_supply"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "gaz_aaa_supply"}
    }
}
{"gaz_fuel"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "gaz_fuel"}
    }
}
{"gaz_aaa_72k"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "gas_aaa_72k"}
	}
}
{"zis5"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "zis5"}
	}
}
{"zis5eng"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "zis5eng"}
	}
}
{"bm13_studebaker"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "rocket_artillery"}
		{tags add "soviet"}
		{tags add "bm13_studebaker"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "enemy_rocketarty"}
										    {tags add "enemyarty"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"bm31_12"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "rocket_artillery"}
		{tags add "soviet"}
		{tags add "bm31_12"}
		{delay 6
		    {if not tagged "player_car"
			    {if not tagged "cmp_def"
			        {if not tagged "ger"
				        {if not tagged "rus"
					        {if not tagged "player_armor"
							    {if not tagged "player_veh"
								    {if not tagged "player"
									    {if not tagged "hidden"
										    {tags add "enemy_rocketarty"}
										    {tags add "enemyarty"}
										}
									}
								}
						    }
					    }
				    }
			    }
		   }
	    }
	}
}
{"gaz67b"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "gaz67b"}
	}
}
{"gaz67"
	{on spawn
    	{if not tagged "radiorus"
		    {tags add "radio_car"}
		}
		{tags add "soviet"}
		{tags add "gaz67"}
	}
}
{"ba20"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "ba20"}
	}
}
{"ba6"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "ba6"}
	}
}
{"ba64"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "ba64"}
	}
}
{"universal_carrier_rus"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "universal_carrier_rus"}
	}
}
{"mmg_carrier_rus"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "mmg_carrier_rus"}
	}
}
{"m3a1e1_scout_mgun"
	{on spawn
    	{tags add "wheeled_vehicle"}
		{tags add "soviet"}
		{tags add "m3a1e1_scout_mgun"}
	}
}
;_________________________________________________
;|        Main Battle Tanks and SPGs              |
;|________________________________________________|

;LIGHT
{"t27"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "t27"}
	}
}
{"t37a"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "t37a"}
	}
}
{"t40"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "t40"}
	}
}
{"t30"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "t30"}
	}
}
{"t60"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "t60"}
	}
}
{"t70"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "t70"}
	}
}
{"t70m"
	{on spawn
    	{tags add "light_tank"}
		{tags add "t70m"}
	}
}
{"bt2_da2"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "bt2_da2"}
	}
}
{"bt2"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "bt2"}
	}
}
{"bt5"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "bt5"}
	}
}
{"bt7"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "bt7"}
	}
}
{"t26_31"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "t26_31"}
	}
}
{"kht26"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "kht26"}
	}
}
{"t26_33"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "t26_33"}
	}
}
{"t26_39"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "t26_39"}
	}
}
{"valentine2"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "valentine2"}
	}
}
{"valentine7"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "valentine7"}
	}
}
{"valentine9"
	{on spawn
    	{tags add "light_tank"}
		{tags add "soviet"}
		{tags add "valentine9"}
	}
}

;MEDIUM
{"t28"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "soviet"}
		{tags add "t28"}
	}
}
{"t3476_40"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "soviet"}
		{tags add "t3476_40"}
	}
}
{"t3476_41"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "soviet"}
		{tags add "t3476_41"}
	}
}
{"t3457_41"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "soviet"}
		{tags add "t3457_41"}
	}
}
{"t3476_42"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "soviet"}
		{tags add "t3476_42"}
	}
}
{"t3476_43"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "soviet"}
		{tags add "t3476_43"}
	}
}
{"t3457_43"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "soviet"}
		{tags add "t3457_43"}
	}
}
{"t3476_43_flame"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "soviet"}
		{tags add "t3476_43_flame"}
	}
}
{"t3485_44"
	{on spawn
    	{tags add "medium_tank"}
		{tags add "soviet"}
		{tags add "t3485_44"}
	}
}

;HEAVY
{"churchill3"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "soviet"}
		{tags add "churchill3"}
	}
}
{"kv1_40"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "soviet"}
		{tags add "kv1_40"}
	}
}
{"kv1_41"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "soviet"}
		{tags add "kv1_41"}
	}
}
{"kv2_40"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "soviet"}
		{tags add "kv2_40"}
	}
}
{"kv1s"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "soviet"}
		{tags add "kv1s"}
	}
}
{"kv85"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "soviet"}
		{tags add "kv85"}
	}
}
{"is1_43"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "soviet"}
		{tags add "is1_43"}
	}
}
{"is2_43"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "soviet"}
		{tags add "is2_43"}
	}
}
{"is2_44"
	{on spawn
    	{tags add "heavy_tank"}
		{tags add "soviet"}
		{tags add "is2_44"}
	}
}

;SPG
{"zis30"
	{on spawn
    	{tags add "spg"}
		{tags add "soviet"}
		{tags add "zis30"}
	}
}
{"su76"
	{on spawn
    	{tags add "spg"}
		{tags add "soviet"}
		{tags add "su76"}
	}
}
{"su85"
	{on spawn
    	{tags add "spg"}
		{tags add "soviet"}
		{tags add "su85"}
	}
}
{"su100"
	{on spawn
    	{tags add "spg"}
		{tags add "soviet"}
		{tags add "su100"}
	}
}
{"su122"
	{on spawn
    	{tags add "spg"}
		{tags add "soviet"}
		{tags add "su122"}
	}
}
{"su152"
	{on spawn
    	{tags add "spg"}
		{tags add "soviet"}
		{tags add "su152"}
	}
}
{"isu122s"
	{on spawn
    	{tags add "spg"}
		{tags add "soviet"}
		{tags add "isu122s"}
	}
}
{"isu152"
	{on spawn
    	{tags add "spg"}
		{tags add "soviet"}
		{tags add "isu152"}
	}
}
;_______________________________________________
;|					Aircraft					|
;|______________________________________________|

{"conquest_il2"
	{on spawn
    	{tags add "aircraft"}
		{tags add "conquest_il2"}
	}
}

{"il2_mod42" 
	{on spawn
    	{tags add "aircraft"}
	}
}

{"il2_mod42_para_plane" 
	{on spawn
    	{tags add "aircraft"}
    	{tags add "soviet"}
		{tags add "drop_plane"}
		{tags add "ready_to_move"}
	}
}