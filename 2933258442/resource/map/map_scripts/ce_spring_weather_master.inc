; Include at the same location as ce_summer_weather_master.inc.
; Helpers stays open; the .mi's existing zones, waypoints and closing brace follow.
{Environment "goh/black"}
{Helpers
    (include "ce_events.inc")
    {vars (include "ce_vars.inc")}
    {functions (include "ce_functions.inc")}
    {triggers
        (include "weather_logic/ce_weather.inc")
        {"environment/spring"
            {condition}
            {actions
                {"set_i" {var "season_set$"} {op "="} {value 1}}
                {"delay" {time 1}}
                {"switch"
                    ("ce_weather_case" selection(1) weather_path(dynamic_campaign/spring/clear/morning_1) apply_time(150))
                    ("ce_weather_case" selection(2) weather_path(dynamic_campaign/spring/clear/midday_1) apply_time(150))
                    ("ce_weather_case" selection(3) weather_path(dynamic_campaign/spring/clear/evening_1) apply_time(150))
                    ("ce_weather_case" selection(4) weather_path(dynamic_campaign/dcg_dunkirk/clear/morning_1) apply_time(150))
                    ("ce_weather_case" selection(5) weather_path(dynamic_campaign/dcg_dunkirk/clear/midday_1) apply_time(150))
                    ("ce_weather_case" selection(6) weather_path(dynamic_campaign/dcg_dunkirk/clear/evening_1) apply_time(150))
                }
            }
        }
        (include "../multi/dcg_script.inc")
        (include "ce_triggers.inc")
    }
