-- =========================================================
-- BATTLE RESULT
-- =========================================================
-- Handles battle-ending communication between mission script, mode Lua,
-- and the C++ battle-result event.

-- Direction summary:
--   mission script -> Lua: request GameOver as player win/loss
--   Lua -> C++: call BotApi.Commands:GameOver(winner)
--   C++ -> Lua: WinnerDecided event fires when result is official
--   Lua -> mission script: set winner_decided = 1

ConquestBattleResult = ConquestBattleResult or {}

-- Mission script sets one of these when it is ready for Lua to end the battle.
-- Example: attacker failed, mission script ordered retreat, combat ceased,
-- then mission script sets gameover_request_player_win = 1.
local GAMEOVER_REQUEST_PLAYER_WIN_VAR = "gameover_request_player_win"
local GAMEOVER_REQUEST_PLAYER_LOSS_VAR = "gameover_request_player_loss"

-- Scene-level lock used so GameOver is only called once
local GAMEOVER_COMMAND_CALLED_VAR = "gameover_command_called"

-- Set when Win Condidtion has been officially met for one side, regardless of how
-- the result happened: normal game rules like score/flags, or Lua GameOver command.
-- Mission script reads this to stop/cancel scripts, order cleanup, etc.
local WINNER_DECIDED_VAR = "winner_decided"

-- Mission script retreats and removes surviving bot units while the var matching the bot's role is set.
-- Split by role because the attacker package speaks a retreat line that only reads right to a player who was defending.
local ATTACKER_RETREAT_REQUESTED_VAR = "attacker_retreat_requested"
local DEFENDER_RETREAT_REQUESTED_VAR = "defender_retreat_requested"

local function MissionVarEnabled(name)
	return BotApi.Scene:GetVar(name) == 1
end

local function GameOverCommandCalled()
	return BotApi.Scene:GetVar(GAMEOVER_COMMAND_CALLED_VAR) == 1
end

function ConquestBattleResult.IsWinnerDecided()
	return BotApi.Scene:GetVar(WINNER_DECIDED_VAR) == 1
end

local function IsGameOverAuthority()
	local authorityPlayerId = BotApi.Conquest.FirstEnemyId or BotApi.Conquest.DefenderBotId
	return authorityPlayerId == nil or BotApi.Instance.playerId == authorityPlayerId
end

local function EndBattleWithWinner(winner, reason)
	if GameOverCommandCalled() then
		return true
	end

	if not IsGameOverAuthority() then
		return false
	end

	BotApi.Scene:SetVar(GAMEOVER_COMMAND_CALLED_VAR, 1)
	BotApi.Commands:GameOver(winner)

	if printDebug then
		print("Print: GameOver called", "reason=", reason, "winner=", winner)
	end

	return true
end

function ConquestBattleResult.EndBattlePlayerWin(reason)
	return EndBattleWithWinner(enemyTeam, reason or "player_win")
end

function ConquestBattleResult.EndBattlePlayerLoss(reason)
	return EndBattleWithWinner(team, reason or "player_loss")
end

function ConquestBattleResult.CheckGameOverRequestVars()
	if GameOverCommandCalled() then
		return true
	end

	if MissionVarEnabled(GAMEOVER_REQUEST_PLAYER_LOSS_VAR) then
		return ConquestBattleResult.EndBattlePlayerLoss("gameover_request_player_loss")
	end

	if MissionVarEnabled(GAMEOVER_REQUEST_PLAYER_WIN_VAR) then
		return ConquestBattleResult.EndBattlePlayerWin("gameover_request_player_win")
	end

	return false
end

-- Returns the retreat var matching the role the bot played this battle.
local function GetBotRetreatVar()
	return ConquestState.botDefender and DEFENDER_RETREAT_REQUESTED_VAR or ATTACKER_RETREAT_REQUESTED_VAR
end

-- Hands surviving bot units to the mission script, which owns retreat movement and removal from here on.
function ConquestBattleResult.RequestBotRetreat()
	local retreatVar = GetBotRetreatVar()

	BotApi.Scene:SetVar(retreatVar, 1)

	if printDebug then
		print("Print: bot retreat requested", "missionVar=", retreatVar)
	end
end

function ConquestBattleResult.IsBotRetreatRequested()
	return BotApi.Scene:GetVar(GetBotRetreatVar()) == 1
end

function ConquestBattleResult.OnWinnerDecided(args)
	if ConquestBattleResult.IsWinnerDecided() then
		return
	end

	BotApi.Scene:SetVar(WINNER_DECIDED_VAR, 1)

	if printDebug then
		print("Print: winner_decided set to 1")
	end

	-- The event carries the winning team, so an unreadable winner is treated as not a loss rather than guessed at.
	local winner = type(args) == "table" and args.winner or nil

	if winner ~= nil and winner ~= team then
		ConquestBattleResult.RequestBotRetreat()
	end
end
