; Include at the same location as ce_summer_weather_master.inc.
; Helpers stays open; the .mi's existing zones, waypoints and closing brace follow.
{Environment "goh/black"}
{Helpers
    (include "ce_events.inc")
    {vars (include "ce_vars.inc")}
    {functions (include "ce_functions.inc")}
    {triggers
        (include "weather_logic/ce_weather.inc")
        {"environment/winter"
            {condition}
            {actions               
                {"set_i" {var "season_set$"} {op "="} {value 4}}
                {"delay" {time 1}}
                {"switch"
                    ("ce_weather_case" selection(1) weather_path(dynamic_campaign/winter/clear/morning_1) apply_time(5))
                    ("ce_weather_case" selection(2) weather_path(dynamic_campaign/winter/clear/midday_1) apply_time(5))
                    ("ce_weather_case" selection(3) weather_path(dynamic_campaign/winter/clear/midday_2) apply_time(5))
                    ("ce_weather_case" selection(4) weather_path(dynamic_campaign/winter/clear/midday_2b) apply_time(5))
                    ("ce_weather_case" selection(5) weather_path(dynamic_campaign/winter/clear/evening_01) apply_time(5))
                    ("ce_weather_case" selection(6) weather_path(dynamic_campaign/winter/cloudy/morning_1) apply_time(5))
                    ("ce_weather_case" selection(7) weather_path(dynamic_campaign/winter/cloudy/midday_1) apply_time(5))
                    ("ce_weather_case" selection(8) weather_path(dynamic_campaign/winter/cloudy/midday_1a) apply_time(5))
                    ("ce_weather_case" selection(9) weather_path(dynamic_campaign/winter/cloudy/midday_1b) apply_time(5))
                    ("ce_weather_case" selection(10) weather_path(dynamic_campaign/winter/cloudy/evening_01) apply_time(5))
                    ("ce_weather_case" selection(11) weather_path(dynamic_campaign/winter/foggy/foggy_1) apply_time(5))
                    ("ce_weather_case" selection(12) weather_path(dynamic_campaign/winter/foggy/foggy_2) apply_time(5))
                    ("ce_weather_case" selection(13) weather_path(dynamic_campaign/winter/foggy/foggy_3) apply_time(5))
                    ("ce_weather_case" selection(14) weather_path(goh/west/wip/winter/night_1) apply_time(5))
                    ("ce_weather_case" selection(15) weather_path(goh/west/wip/winter/night_2) apply_time(5))
                    ("ce_weather_case" selection(16) weather_path(goh/west/wip/winter/day_clear_1) apply_time(5))
                    ("ce_weather_case" selection(17) weather_path(goh/west/wip/winter/day_clear_2) apply_time(5))
                    ("ce_weather_case" selection(18) weather_path(goh/west/wip/winter/day_snow_1) apply_time(5))
                    ("ce_weather_case" selection(19) weather_path(goh/west/wip/winter/day_snow_2) apply_time(5))
                    ("ce_weather_case" selection(20) weather_path(goh/west/wip/winter/day_snow_3) apply_time(5))
                }
            }
        }
        (include "../multi/dcg_script.inc")
        (include "ce_triggers.inc")
    }
