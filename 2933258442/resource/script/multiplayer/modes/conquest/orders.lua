-- =========================================================
-- AI ORDERS
-- =========================================================
-- Squad order behavior for Conquest.

local SQUAD_TAG_MISSION_SCRIPT = "_lua_mi"
local SQUAD_TAG_REPAIRING = "repairing"
local SQUAD_TAG_ALERT = "_lua_alert"
local SQUAD_TAG_IGNORE = "_lua_ignore"

-- Returns true when normal Lua movement orders must stop for battle result or bot retreat.
function ShouldStopNormalSquadOrders()
	return ConquestBattleResult.IsWinnerDecided()
		or ConquestBattleResult.IsBotRetreatRequested()
end

-- Sends a squad to a random waypoint when the map uses waypoint movement.
function GotoNextWaypoint(squad)
	if ShouldStopNormalSquadOrders() then
		return
	end

	if IsGarrisonSquad(squad) then
		return
	end

	local waypoints = BotApi.Scene.Waypoints
	BotApi.Commands:CaptureFlag(squad, waypoints[math.random(#waypoints)]) -- CaptureFlag acts like go-there-and-attack.
	if printDebug then print("Print: #captureFlag call inside GoToNextWaypoint") end
end

-- Sends a squad to another waypoint after it reaches its current one.
function OnWaypoint(args)
	if ShouldStopNormalSquadOrders() then
		return
	end

	if IsGarrisonSquad(args.squadId) then
		return
	end

	if printDebug then print("Print: #GotoNextWaypoint call inside OnWaypoint") end
	GotoNextWaypoint(args.squadId)
end

-- Returns true when a squad was bought during defender opening and should keep holding position.
function IsGarrisonSquad(squad)
	return ConquestState.garrisonSquads[squad] == true
end

-- Marks a defender opening squad so later quant checks do not add Lua movement orders.
function RegisterGarrisonSquad(squad)
	ConquestState.garrisonSquads[squad] = true
end

-- Marks all current bot squads as defender-opening garrison squads.
function RegisterCurrentGarrisonSquads()
	for _, squad in pairs(BotApi.Scene.Squads) do
		RegisterGarrisonSquad(squad)
	end
end

-- Returns true when normal Lua capture orders should not be applied.
-- "_lua_mi" = reserved for mission script use.
-- "repairing" = squad is busy repairing.
-- "_lua_alert" = squad ran into enemy force and should seek/destroy instead.
-- Returns true when mission-script tags should override normal Lua orders.
function IsSquadInScript(squad)
	if BotApi.Scene:IsSquadTagged(squad, SQUAD_TAG_MISSION_SCRIPT) or BotApi.Scene:IsSquadTagged(squad, SQUAD_TAG_REPAIRING) then
		if printDebug then print("Print: SQUADinSCRIPT thus no action squad", squad, "Player#", BotApi.Instance.playerId, "Team", team) end
		return true
	elseif BotApi.Scene:IsSquadTagged(squad, SQUAD_TAG_ALERT) then
		if printDebug then print("Print: SQUADinALERT thus seek by squad", squad, "Player#", BotApi.Instance.playerId, "Team", team) end
		BotApi.Commands:SeekAndDestroy(squad)
		return true
	end
end

-- Returns true when squad is tagged for general ignore behavior.
function IsSquadToIgnore(squad)
	if BotApi.Scene:IsSquadTagged(squad, SQUAD_TAG_IGNORE) then
		return true
	end
end

-- Chooses a flag target for a squad and issues the capture order.
function CaptureFlag(squad)
	if ShouldStopNormalSquadOrders() then
		return
	end

	if IsGarrisonSquad(squad) then
		return
	end

	if IsSquadToAlwaysIgnore(squad) then
		if printDebug then print("Print: SQUAD always ignored thus no action squad ", squad, "Player#", BotApi.Instance.playerId) end
		return
	end

	local flags = {}
	for i, flag in pairs(BotApi.Scene.Flags) do
		table.insert(flags, {id = i, name = flag.name, priority = getDefaultFlagPriority(flag), owner = flag.occupant})
	end

	local flag = GetFlagToCapture(BotApi.Scene.Flags, getDefaultFlagPriority, flags)

	if not flag then
		if printDebug then print("Print: No Flags so SeekAndDestroy by squad ", squad, "Player#", BotApi.Instance.playerId) end
		BotApi.Commands:SeekAndDestroy(squad)
		return
	end


	if IsSquadInScript(squad) then
		return
	end

	if IsSquadToIgnore(squad) then
		local rndAI = math.random()
		if searchDestroy > rndAI then
			if printDebug then print("Print: [see_enemy] seek by squad ", squad, "Player#", BotApi.Instance.playerId) end
			BotApi.Commands:SeekAndDestroy(squad)
			return
		else
			if printDebug then print("Print: [see_enemy] donothing by squad ", squad, "Player#", BotApi.Instance.playerId) end
			return
		end
	end

	if printDebug then print("Print: [notags] ctf by squad", squad, "Player#", BotApi.Instance.playerId, "Flag name: ", flag.name) end
	return BotApi.Commands:CaptureFlag(squad, flag.name)
end
