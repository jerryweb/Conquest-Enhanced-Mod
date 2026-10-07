; Include at the same location as ce_summer_weather_master.inc.
; Helpers stays open; the .mi's existing zones, waypoints and closing brace follow.
{Environment "goh/black"}
{Helpers
    (include "ce_events.inc")
    {vars (include "ce_vars.inc")}
    {functions (include "ce_functions.inc")}
    {triggers
        (include "weather_logic/ce_weather.inc")
        {"environment/autumn"
            {condition}
            {actions
                {"set_i" {var "season_set$"} {op "="} {value 3}}
                {"delay" {time 1}}
                {"switch"
                    ("ce_weather_case" selection(1) weather_path(dynamic_campaign/autumn/clear/morning_1) apply_time(5))
                    ("ce_weather_case" selection(2) weather_path(dynamic_campaign/autumn/clear/midday_1) apply_time(5))
                    ("ce_weather_case" selection(3) weather_path(dynamic_campaign/autumn/clear/midday_1b) apply_time(5))
                    ("ce_weather_case" selection(4) weather_path(dynamic_campaign/autumn/clear/evening_1) apply_time(5))
                    ("ce_weather_case" selection(5) weather_path(goh/west/wip/autumn/day_clear_1) apply_time(5))
                    ("ce_weather_case" selection(6) weather_path(goh/west/wip/autumn/day_clear_2) apply_time(5))
                    ("ce_weather_case" selection(7) weather_path(goh/west/wip/autumn/day_clear_3) apply_time(5))
                    ("ce_weather_case" selection(8) weather_path(goh/west/wip/autumn/day_cloudy_1) apply_time(5))
                    ("ce_weather_case" selection(9) weather_path(goh/west/wip/autumn/day_cloudy_2) apply_time(5))
                    ("ce_weather_case" selection(10) weather_path(goh/west/wip/autumn/evening_1) apply_time(5))
                    ("ce_weather_case" selection(11) weather_path(goh/west/wip/autumn/night_1) apply_time(5))
                    ("ce_weather_case" selection(12) weather_path(goh/west/wip/autumn/night_3) apply_time(5))
                }
            }
        }
        (include "../multi/dcg_script.inc")
        (include "ce_triggers.inc")
    }
