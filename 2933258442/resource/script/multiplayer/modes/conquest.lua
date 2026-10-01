require([[/script/multiplayer/modes/utility]]) -- shared functions across all game modes

require([[/script/multiplayer/modes/conquest/runtime_config]]) -- timing and tuning values.
require([[/script/multiplayer/modes/conquest/runtime_state]]) -- mutable battle state.
require([[/script/multiplayer/modes/conquest/runtime_context]]) -- context builder.

require([[/script/multiplayer/modes/conquest/purchase_profiles]]) -- phase/force/difficulty profile data.
require([[/script/multiplayer/modes/conquest/purchase_scoring]]) -- scoring helpers.
require([[/script/multiplayer/modes/conquest/purchase]]) -- current unit selection hook.
require([[/script/multiplayer/modes/conquest/purchase_pressure]]) -- purchase count/pressure scaling.

require([[/script/multiplayer/modes/conquest/scene]]) -- scene-query snapshot logic.
require([[/script/multiplayer/modes/conquest/combat_pressure]]) -- weighted combat-pressure scoring.
require([[/script/multiplayer/modes/conquest/scene_memory]]) -- match-local scene snapshot memory.
require([[/script/multiplayer/modes/conquest/defender_counterattack]]) -- defender counterattack ownership and planning snapshot.
require([[/script/multiplayer/modes/conquest/attacker_pressure]]) -- reusable attacker pressure snapshot.
require([[/script/multiplayer/modes/conquest/attacker_wave_off]]) -- attacker wave-off timing controller.
require([[/script/multiplayer/modes/conquest/battle_result]]) -- battle result handling.
require([[/script/multiplayer/modes/conquest/attacker_failure]]) -- post-final-wave attacker failure watcher.
require([[/script/multiplayer/modes/conquest/waves]]) -- wave and cooldown behavior.

require([[/script/multiplayer/modes/conquest/orders_flags]]) -- flag priority and capture-target selection.
require([[/script/multiplayer/modes/conquest/orders]]) -- squad order assignment and tag handling.

require([[/script/multiplayer/modes/conquest_enhanced/utilities_ce]])
require([[/script/multiplayer/modes/conquest_enhanced/orders_ce]])

local firstSpawn = false 

function OnGameStart()
	ConquestContext.SetBotRole()
	ConquestPurchaseProfiles.InitializeBattleForce()
	ConquestContext.SetVarsInMissionScript()
	ConquestContext.SetCEVarsInMissionScript(ConquestState.botDefender)
	OnGameStartUtility("conquest")
	--ConquestDebug.StartSceneQueryTestLog()
end

function OnGameQuant()
	if ConquestBattleResult.IsWinnerDecided() then
		return
	end

	if ConquestBattleResult.CheckGameOverRequestVars() then
		return
	end

	if ShouldStopNormalSquadOrders() then
		return
	end

	if ConquestState.botDefender then
		ConquestWaves.UpdateDefenderOpeningCutoff()
	end

	TrySpawnUnit()
	if ConquestState.botDefender then
		ConquestDefenderCounterattack.UpdateFlagOwnership()

		if ConquestState.defenderOpeningHoldRegistrationActive then
			RegisterCurrentGarrisonSquads()
			ConquestWaves.UpdateDefenderOpeningGarrisonReady()
		end
	end

	local waypoints = BotApi.Scene.Waypoints
	if #waypoints == 0 then
		for i, squad in pairs(BotApi.Scene.Squads) do
			if not IsGarrisonSquad(squad) and not Context.SquadTimers[squad] then
				if printDebug then print("SQUAD ", squad, " SquadTimers = nil") end
				SetSquadOrder(CaptureFlag, squad, ConquestConfig.OrderRotationPeriod, true)
			end
		end
	end
end

-- Assigns initial movement orders when a bot squad spawns.
function OnGameSpawn(args)
	if ShouldStopNormalSquadOrders() then
		return
	end

	if ConquestState.botDefender
		and ConquestConfig.DefenderOpening.UnitsHoldMovement
		and ConquestState.defenderOpeningHoldRegistrationActive then
		RegisterGarrisonSquad(args.squadId)
		return
	end

	if not firstSpawn then  
		firstSpawn = true
		SetGeneralSquadTagCheckTimer()
	end

	local waypoints = BotApi.Scene.Waypoints
	if #waypoints == 0 then
		local initialOrder = CheckUnitPropertiesToFollowWaypoints()
		-- local initialOrder = true
		SetSquadOrder(CaptureFlag, args.squadId, ConquestConfig.OrderRotationPeriod, initialOrder)
	else
		GotoNextWaypoint(args.squadId)
	end
end

-- Notifies the mission script that player defense prep time is over.
function OnPrepTimeOver()
	BotApi.Scene:SetVar("prep_inform", 1)
	--ConquestDebug.StartAttackerRetreatTest()
	if printDebug then print("Print: prep_inform set to 1, Player defense prep is over.") end
end

BotApi.Events:Subscribe(BotApi.Events.GameStart, OnGameStart)
BotApi.Events:Subscribe(BotApi.Events.GameEnd, OnGameStop)
BotApi.Events:Subscribe(BotApi.Events.Quant, OnGameQuant)
BotApi.Events:Subscribe(BotApi.Events.GameSpawn, OnGameSpawn)
BotApi.Events:Subscribe(BotApi.Events.Waypoint, OnWaypoint)
BotApi.Events:Subscribe(BotApi.Events.PrepTimeOver, OnPrepTimeOver)
BotApi.Events:Subscribe(BotApi.Events.WinnerDecided, ConquestBattleResult.OnWinnerDecided)
