-- =========================================================
-- REAR ATTACK EVENT (CONQUEST ENHANCED)
-- =========================================================
-- A match-level event for missions where the bot attacks (the player defends).
--
-- Rules:
--   * Rolled once at match start (EventChance). Never active when the bot defends.
--   * Not gated on the map: it works on maps without waypoint graphs too.
--   * While the event is active, every attacker wave (including the first) rolls
--     ToggleChance. A successful roll asks the mission layer to swap the bot's
--     spawns to the other side. With ToggleChance = 0.5 that gives every wave a
--     50% chance to spawn on the player's side, whatever the previous wave did.
--   * While the event is active, no newly spawning AI squad follows the mission
--     waypoint graph for the whole match (see utilities_ce.lua).
--
-- Mission-layer contract (move_ai_spawn trigger):
--   change_ai_spawns            Lua writes 1; the trigger swaps the spawns (it reads
--                               their current position) and resets the var to 0
--   enable_rear_attack_mechanic 1 when the event is active, otherwise 0
-- Lua does not track which side the spawns are on. The mission layer owns that.

ConquestRearAttack = ConquestRearAttack or {}

local VAR_ENABLE = "enable_rear_attack_mechanic"
local VAR_CHANGE = "change_ai_spawns"
local eventActive = false

local function GetPlan()
	return ConquestConfig.RearAttack
end

-- True when the event is active for this match.
function ConquestRearAttack.IsEventActive()
	return eventActive
end

-- Rolls the match-level event. Call once from OnGameStart, after the bot role is set.
function ConquestRearAttack.Init()
	eventActive = false

	if not ConquestState.botDefender then
		eventActive = math.random() < GetPlan().EventChance
	end

	BotApi.Scene:SetVar(VAR_ENABLE, eventActive and 1 or 0)

	if printDebug then
		print("Print: rear attack event active =", eventActive)
	end

	-- The graph is off for the whole match when the event is active.
	ConquestContext.RefreshWaypointGraph()
end

-- Rolls whether the spawns swap sides before this attacker wave. Call once per wave,
-- before its first purchase.
function ConquestRearAttack.OnAttackerWaveStart()
	if not eventActive then
		return
	end

	local swap = math.random() < GetPlan().ToggleChance

	if printDebug then
		print("Print: rear attack swap roll =", swap, "wave =", ConquestState.waveNumber + 1)
	end

	if swap then
		BotApi.Scene:SetVar(VAR_CHANGE, 1)
	end
end
