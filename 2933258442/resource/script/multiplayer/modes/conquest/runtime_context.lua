-- =========================================================
-- RUNTIME CONTEXT
-- =========================================================
-- Battle context setup for Conquest.

ConquestContext = ConquestContext or {}

function ConquestContext.SetBotRole()
	ConquestState.botDefender = not BotApi.Conquest.Attacking
end

function ConquestContext.SetVarsInMissionScript()
	-- Mission script var is from the user's perspective.
	BotApi.Scene:SetVar("user_is_defender", ConquestState.botDefender and 0 or 1)

	local nationMap = { rus = 1, ger = 2, fin = 3, usa = 4, eng = 5 }
	local difficultyMap = { easy = 1, normal = 2, hard = 3, heroic = 4 }
	local spawnMap = { a = 1, b = 2 }
	local playerSpawnNameMap = {
		a1 = 1, a2 = 2, a3 = 3, a4 = 4,
		b1 = 5, b2 = 6, b3 = 7, b4 = 8,
	}

	BotApi.Scene:SetVar("bot_army", nationMap[BotApi.Instance.army] or 0)
	BotApi.Scene:SetVar("bot_difficulty", difficultyMap[BotApi.Instance.difficulty] or 0)
	BotApi.Scene:SetVar("bots_spawnside", spawnMap[spawnSide] or 0)
	BotApi.Scene:SetVar("player_spawn_name", playerSpawnNameMap[BotApi.Conquest.PlayerSpawnPoint] or 0)

	BotApi.Scene:SetVar("enemyid", BotApi.Instance.playerId)
	BotApi.Scene:SetVar("id_1st_enemy", BotApi.Conquest.FirstEnemyId)
	BotApi.Scene:SetVar("id_defenderbot", BotApi.Conquest.DefenderBotId)
	BotApi.Scene:SetVar("id_1st_player", BotApi.Conquest.FirstPlayerId)
end
