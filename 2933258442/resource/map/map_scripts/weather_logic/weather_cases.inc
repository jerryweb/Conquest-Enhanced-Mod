; Generated from CEWeather.Presets by tools/generate_weather_cases.py.
; Edit the Lua arrays and regenerate this file. Transition time is in seconds.
; Each season/pool combination is tested exactly once; selections are the
; only true siblings, since GEM switch commits to the first matching
; top-level case and will not fall through to a sibling with the same condition.

; ===== season 1 (spring) =====
{"case"
	{condition
		{type cmp_i}
		{var "weather_season$"}
		{op "=="}
		{value 1}
	}
	{"switch"
		; spring/regular: 6 presets
		{"case"
			{condition
				{type cmp_i}
				{var "weather_pool_selected$"}
				{op "=="}
				{value 0}
			}
			{"switch"
				("ce_weather_case" selection(1) weather_path(dynamic_campaign/spring/clear/morning_1) apply_time(150))
				("ce_weather_case" selection(2) weather_path(dynamic_campaign/spring/clear/midday_1) apply_time(150))
				("ce_weather_case" selection(3) weather_path(dynamic_campaign/spring/clear/evening_1) apply_time(150))
				("ce_weather_case" selection(4) weather_path(dynamic_campaign/dcg_dunkirk/clear/morning_1) apply_time(150))
				("ce_weather_case" selection(5) weather_path(dynamic_campaign/dcg_dunkirk/clear/midday_1) apply_time(150))
				("ce_weather_case" selection(6) weather_path(dynamic_campaign/dcg_dunkirk/clear/evening_1) apply_time(150))
			}
		}
		; spring/strong: 6 presets
		{"case"
			{condition
				{type cmp_i}
				{var "weather_pool_selected$"}
				{op "=="}
				{value 1}
			}
			{"switch"
				("ce_weather_case" selection(1) weather_path(dynamic_campaign/spring/cloudy/morning_1) apply_time(150))
				("ce_weather_case" selection(2) weather_path(dynamic_campaign/spring/cloudy/midday_1) apply_time(150))
				("ce_weather_case" selection(3) weather_path(dynamic_campaign/spring/cloudy/evening_1) apply_time(150))
				("ce_weather_case" selection(4) weather_path(dynamic_campaign/dcg_dunkirk/cloudy/morning_1) apply_time(150))
				("ce_weather_case" selection(5) weather_path(dynamic_campaign/dcg_dunkirk/cloudy/midday_1) apply_time(150))
				("ce_weather_case" selection(6) weather_path(dynamic_campaign/dcg_dunkirk/cloudy/evening_1) apply_time(150))
			}
		}
	}
}

; ===== season 2 (summer) =====
{"case"
	{condition
		{type cmp_i}
		{var "weather_season$"}
		{op "=="}
		{value 2}
	}
	{"switch"
		; summer/regular: 12 presets
		{"case"
			{condition
				{type cmp_i}
				{var "weather_pool_selected$"}
				{op "=="}
				{value 0}
			}
			{"switch"
				("ce_weather_case" selection(1) weather_path(dynamic_campaign/summer/clear/morning_01) apply_time(150))
				("ce_weather_case" selection(2) weather_path(dynamic_campaign/summer/clear/midday_1) apply_time(150))
				("ce_weather_case" selection(3) weather_path(dynamic_campaign/summer/clear/evening_01) apply_time(150))
				("ce_weather_case" selection(4) weather_path(goh/west/wip/summer/night_1) apply_time(150))
				("ce_weather_case" selection(5) weather_path(goh/west/wip/summer/night_2) apply_time(150))
				("ce_weather_case" selection(6) weather_path(goh/west/wip/summer/sunset_1) apply_time(150))
				("ce_weather_case" selection(7) weather_path(goh/west/wip/summer/sunrise_1) apply_time(150))
				("ce_weather_case" selection(8) weather_path(goh/west/wip/summer/sunrise_2) apply_time(150))
				("ce_weather_case" selection(9) weather_path(goh/west/wip/summer/day_1) apply_time(150))
				("ce_weather_case" selection(10) weather_path(goh/west/wip/summer/day_2) apply_time(150))
				("ce_weather_case" selection(11) weather_path(goh/west/wip/summer/day_3) apply_time(150))
				("ce_weather_case" selection(12) weather_path(goh/west/wip/summer/day_clear_1) apply_time(150))
			}
		}
		; summer/strong: 10 presets
		{"case"
			{condition
				{type cmp_i}
				{var "weather_pool_selected$"}
				{op "=="}
				{value 1}
			}
			{"switch"
				("ce_weather_case" selection(1) weather_path(dynamic_campaign/summer/cloudy/morning_01) apply_time(150))
				("ce_weather_case" selection(2) weather_path(dynamic_campaign/summer/cloudy/midday_1) apply_time(150))
				("ce_weather_case" selection(3) weather_path(dynamic_campaign/summer/cloudy/evening_01) apply_time(150))
				("ce_weather_case" selection(4) weather_path(goh/west/wip/summer/day_clear_2_rain) apply_time(150))
				("ce_weather_case" selection(5) weather_path(goh/west/wip/summer/day_rain_1_b) apply_time(150))
				("ce_weather_case" selection(6) weather_path(goh/west/wip/summer/day_rain_4) apply_time(150))
				("ce_weather_case" selection(7) weather_path(goh/west/wip/summer/day_rain_5) apply_time(150))
				("ce_weather_case" selection(8) weather_path(goh/west/wip/summer/sunset_rain_1) apply_time(150))
				("ce_weather_case" selection(9) weather_path(ce_weather/summer/heavy_rain) apply_time(150))
				("ce_weather_case" selection(10) weather_path(ce_weather/summer/thunderstorm) apply_time(150))
			}
		}
	}
}

; ===== season 3 (autumn) =====
{"case"
	{condition
		{type cmp_i}
		{var "weather_season$"}
		{op "=="}
		{value 3}
	}
	{"switch"
		; autumn/regular: 12 presets
		{"case"
			{condition
				{type cmp_i}
				{var "weather_pool_selected$"}
				{op "=="}
				{value 0}
			}
			{"switch"
				("ce_weather_case" selection(1) weather_path(dynamic_campaign/autumn/clear/morning_1) apply_time(150))
				("ce_weather_case" selection(2) weather_path(dynamic_campaign/autumn/clear/midday_1) apply_time(150))
				("ce_weather_case" selection(3) weather_path(dynamic_campaign/autumn/clear/midday_1b) apply_time(150))
				("ce_weather_case" selection(4) weather_path(dynamic_campaign/autumn/clear/evening_1) apply_time(150))
				("ce_weather_case" selection(5) weather_path(goh/west/wip/autumn/day_clear_1) apply_time(150))
				("ce_weather_case" selection(6) weather_path(goh/west/wip/autumn/day_clear_2) apply_time(150))
				("ce_weather_case" selection(7) weather_path(goh/west/wip/autumn/day_clear_3) apply_time(150))
				("ce_weather_case" selection(8) weather_path(goh/west/wip/autumn/day_cloudy_1) apply_time(150))
				("ce_weather_case" selection(9) weather_path(goh/west/wip/autumn/day_cloudy_2) apply_time(150))
				("ce_weather_case" selection(10) weather_path(goh/west/wip/autumn/evening_1) apply_time(150))
				("ce_weather_case" selection(11) weather_path(goh/west/wip/autumn/night_1) apply_time(150))
				("ce_weather_case" selection(12) weather_path(goh/west/wip/autumn/night_3) apply_time(150))
			}
		}
		; autumn/strong: 6 presets
		{"case"
			{condition
				{type cmp_i}
				{var "weather_pool_selected$"}
				{op "=="}
				{value 1}
			}
			{"switch"
				("ce_weather_case" selection(1) weather_path(dynamic_campaign/autumn/cloudy/morning_1) apply_time(150))
				("ce_weather_case" selection(2) weather_path(dynamic_campaign/autumn/cloudy/midday_1) apply_time(150))
				("ce_weather_case" selection(3) weather_path(dynamic_campaign/autumn/cloudy/midday_1b) apply_time(150))
				("ce_weather_case" selection(4) weather_path(dynamic_campaign/autumn/cloudy/midday_2) apply_time(150))
				("ce_weather_case" selection(5) weather_path(dynamic_campaign/autumn/cloudy/evening_1) apply_time(150))
				("ce_weather_case" selection(6) weather_path(goh/west/wip/autumn/day_rain_2) apply_time(150))
			}
		}
	}
}

; ===== season 4 (winter) =====
{"case"
	{condition
		{type cmp_i}
		{var "weather_season$"}
		{op "=="}
		{value 4}
	}
	{"switch"
		; winter/regular: 20 presets
		{"case"
			{condition
				{type cmp_i}
				{var "weather_pool_selected$"}
				{op "=="}
				{value 0}
			}
			{"switch"
				("ce_weather_case" selection(1) weather_path(dynamic_campaign/winter/clear/morning_1) apply_time(150))
				("ce_weather_case" selection(2) weather_path(dynamic_campaign/winter/clear/midday_1) apply_time(150))
				("ce_weather_case" selection(3) weather_path(dynamic_campaign/winter/clear/midday_2) apply_time(150))
				("ce_weather_case" selection(4) weather_path(dynamic_campaign/winter/clear/midday_2b) apply_time(150))
				("ce_weather_case" selection(5) weather_path(dynamic_campaign/winter/clear/evening_01) apply_time(150))
				("ce_weather_case" selection(6) weather_path(dynamic_campaign/winter/cloudy/morning_1) apply_time(150))
				("ce_weather_case" selection(7) weather_path(dynamic_campaign/winter/cloudy/midday_1) apply_time(150))
				("ce_weather_case" selection(8) weather_path(dynamic_campaign/winter/cloudy/midday_1a) apply_time(150))
				("ce_weather_case" selection(9) weather_path(dynamic_campaign/winter/cloudy/midday_1b) apply_time(150))
				("ce_weather_case" selection(10) weather_path(dynamic_campaign/winter/cloudy/evening_01) apply_time(150))
				("ce_weather_case" selection(11) weather_path(dynamic_campaign/winter/foggy/foggy_1) apply_time(150))
				("ce_weather_case" selection(12) weather_path(dynamic_campaign/winter/foggy/foggy_2) apply_time(150))
				("ce_weather_case" selection(13) weather_path(dynamic_campaign/winter/foggy/foggy_3) apply_time(150))
				("ce_weather_case" selection(14) weather_path(goh/west/wip/winter/night_1) apply_time(150))
				("ce_weather_case" selection(15) weather_path(goh/west/wip/winter/night_2) apply_time(150))
				("ce_weather_case" selection(16) weather_path(goh/west/wip/winter/day_clear_1) apply_time(150))
				("ce_weather_case" selection(17) weather_path(goh/west/wip/winter/day_clear_2) apply_time(150))
				("ce_weather_case" selection(18) weather_path(goh/west/wip/winter/day_snow_1) apply_time(150))
				("ce_weather_case" selection(19) weather_path(goh/west/wip/winter/day_snow_2) apply_time(150))
				("ce_weather_case" selection(20) weather_path(goh/west/wip/winter/day_snow_3) apply_time(150))
			}
		}
		; winter/strong: 6 presets
		{"case"
			{condition
				{type cmp_i}
				{var "weather_pool_selected$"}
				{op "=="}
				{value 1}
			}
			{"switch"
				("ce_weather_case" selection(1) weather_path(goh/west/wip/winter/day_blizzard_1) apply_time(150))
				("ce_weather_case" selection(2) weather_path(goh/west/wip/winter/day_blizzard_2) apply_time(150))
				("ce_weather_case" selection(3) weather_path(goh/multi/2v2_blizzard/var1) apply_time(150))
				("ce_weather_case" selection(4) weather_path(goh/single/01-fin/1940_01_raate_road/blizzard) apply_time(150))
				("ce_weather_case" selection(5) weather_path(goh/single/01-ger/1942_09_elbrus/01_storm) apply_time(150))
				("ce_weather_case" selection(6) weather_path(goh/single/1942_01_vyazma/storm) apply_time(150))
			}
		}
	}
}
