; File created by Hawka
;==========================================================================================================

; Vanilla var includes
(include "../multi/dcg_functions.inc")

;============ AI ORDERS LOGIC  ========================================
			{"issue_idle_squad_orders"
				{"delay"
					{time 10}
				}
				{"effect"
					{effect tag_squad_need_next_order}
				}
			}