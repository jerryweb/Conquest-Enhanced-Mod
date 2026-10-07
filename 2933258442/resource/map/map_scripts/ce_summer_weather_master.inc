; Include at the same location as ce_summer_weather_master.inc.
; Helpers stays open; the .mi's existing zones, waypoints and closing brace follow.
{Environment "goh/black"}
{Helpers
    (include "ce_events.inc")
    ;(include "ce_tasks.inc")	
    {vars (include "ce_vars.inc")}
    {functions (include "ce_functions.inc")}
    {triggers      		
    	(include "weather_logic/ce_weather.inc")
        {"environment/summer"
            {condition}
            {actions
                {"set_i" {var "season_set$"} {op "="} {value 2}}
                {"delay" {time 1}}
                {"switch"
		            ("ce_weather_case" selection(1) weather_path(dynamic_campaign/summer/clear/morning_01) apply_time(5))
					("ce_weather_case" selection(2) weather_path(dynamic_campaign/summer/clear/midday_1) apply_time(5))
					("ce_weather_case" selection(3) weather_path(dynamic_campaign/summer/clear/evening_01) apply_time(5))
					("ce_weather_case" selection(4) weather_path(goh/west/wip/summer/night_1) apply_time(5))
					("ce_weather_case" selection(5) weather_path(goh/west/wip/summer/night_2) apply_time(5))
					("ce_weather_case" selection(6) weather_path(goh/west/wip/summer/sunset_1) apply_time(5))
					("ce_weather_case" selection(7) weather_path(goh/west/wip/summer/sunrise_1) apply_time(5))
					("ce_weather_case" selection(8) weather_path(goh/west/wip/summer/sunrise_2) apply_time(5))
					("ce_weather_case" selection(9) weather_path(goh/west/wip/summer/day_1) apply_time(5))
					("ce_weather_case" selection(10) weather_path(goh/west/wip/summer/day_2) apply_time(5))
					("ce_weather_case" selection(11) weather_path(goh/west/wip/summer/day_3) apply_time(5))
					("ce_weather_case" selection(12) weather_path(goh/west/wip/summer/day_clear_1) apply_time(5))
		        }
            }
        } 
        (include "../multi/dcg_script.inc")
        (include "ce_triggers.inc")
    }
    ;(include "../../ce_generic_waypoint.inc")