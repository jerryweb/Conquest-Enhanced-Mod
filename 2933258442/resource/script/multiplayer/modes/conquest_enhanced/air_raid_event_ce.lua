-- =========================================================
-- Air raid event (player-defense missions only). Lua only rolls the chance and sets the mission
-- variables; the .mi layer runs the raid itself.
--   air_raid_warning = 1 : the raid was rolled on (warning phase)
--   air_raid_active  = 1 : the raid should start now (stays 1, the event only happens once)

ConquestAirRaid = ConquestAirRaid or {}

local VAR_WARNING = "air_raid_warning"
local VAR_ACTIVE = "air_raid_active"

local rolled = false
local rollTimer, activeTimer = nil, nil

local function IsMatchOver()
	return ConquestBattleResult.IsWinnerDecided() or ConquestBattleResult.IsBotRetreatRequested()
end

local function IsAuthorityBot()
	local id = BotApi.Conquest.FirstEnemyId or BotApi.Conquest.DefenderBotId
	return id == nil or BotApi.Instance.playerId == id
end

local function KillTimer(timer)
	if timer then BotApi.Events:KillQuantTimer(timer) end
	return nil
end

-- Called from OnPrepTimeOver in conquest.lua
function ConquestAirRaid.OnPrepTimeOver()
	if ConquestState.botDefender or rolled or not IsAuthorityBot() then
		return
	end
	rolled = true -- one roll per match, never resets

	local cfg = ConquestConfig.AirRaid
	rollTimer = BotApi.Events:SetQuantTimer(function()
		rollTimer = nil
		if IsMatchOver() or math.random() >= cfg.Chance then
			return
		end

		BotApi.Scene:SetVar(VAR_WARNING, 1)
		print("Print: air raid warning")

		activeTimer = BotApi.Events:SetQuantTimer(function()
			activeTimer = nil
			if IsMatchOver() then
				return
			end
			BotApi.Scene:SetVar(VAR_ACTIVE, 1)
			print("Print: air raid active")
		end, cfg.ActiveDelay)
	end, math.random(cfg.DelayMin, cfg.DelayMax))
end

-- Called from OnGameStop in utility.lua
function ConquestAirRaid.Stop()
	rollTimer = KillTimer(rollTimer)
	activeTimer = KillTimer(activeTimer)
end
