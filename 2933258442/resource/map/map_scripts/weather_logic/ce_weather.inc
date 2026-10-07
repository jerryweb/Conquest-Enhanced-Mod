; File created by Hawka
;==========================================================================================================
			
; Lua owns the 5-20 minute delay. This trigger consumes one request per battle.
			; Leaf-level only: season_id/pool_id are now tested once by the grouping
			; wrapper in weather_cases.inc, not repeated per entry. Duplicate
			; top-level cases (same season/pool, different selection) cause GEM's
			; switch to commit to the first match and never reach the rest.
			(define "ce_weather_case"
			    {"case"
			        {condition
			            {type cmp_i}
			            {var "weather_selection$"}
			            {op "=="}
			            {value %selection}
			        }
			        {"environment" {name "%weather_path"} {time %apply_time} {apply}}
			    }
			)
			
			{"environment/dynamic_weather_script"
			    {condition
			        {expression "1 & 2 & 3"}
			        {terms
			            {"1.cmp_i" {var "weather_change_pending$"} {op "=="} {value 1}}
			            {"2.cmp_i" {var "weather_selection$"} {op ">"} {value 0}}
			            {"3.cmp_i" {var "weather_season$"} {op ">"} {value 0}}
			        }
			    }
			    {actions
			        {"switch"
			            (include "weather_cases.inc")
			        }
			        {"set_i" {var "weather_change_pending$"} {op "="} {value 0}}
			        {"delay" {time 5}}
			        {"trigger"
			            {name "environment/dynamic_weather_script"}
			        }
			    }
			}