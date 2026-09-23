-- =========================================================
-- FLAG / OBJECTIVE SELECTION
-- =========================================================
-- Chooses which flag a squad should move toward.

local function ShuffleTable(tbl)
	local rand = math.random
	for i = #tbl, 2, -1 do
		local j = rand(i)
		tbl[i], tbl[j] = tbl[j], tbl[i]
	end
	return tbl
end

local function GetFlagByName(flags, flagName)
	if not flagName then
		return nil
	end

	for _, flag in ipairs(flags or {}) do
		if flag.name == flagName then
			return flag
		end
	end

	return nil
end

local function IsAttackerTargetStillValid(flag, team)
	return flag and flag.owner ~= team
end

local function HasEnemyOwnedFlag(flags, enemyTeam)
	for _, flag in ipairs(flags or {}) do
		if flag.owner == enemyTeam then
			return true
		end
	end

	return false
end

local function GetValidAttackerTargetNames(flags, enemyTeam, team)
	local enemyOwnedOnly = HasEnemyOwnedFlag(flags, enemyTeam)
	local names = {}

	for _, flag in ipairs(flags or {}) do
		if flag.owner ~= team and (not enemyOwnedOnly or flag.owner == enemyTeam) then
			table.insert(names, flag.name)
		end
	end

	table.sort(names)
	ShuffleTable(names)

	return names
end

local function RebuildAttackerTargetOrder(flags, enemyTeam, team)
	ConquestState.attackerFlagTargetOrder = GetValidAttackerTargetNames(flags, enemyTeam, team)
	ConquestState.attackerFlagTargetOrderIndex = 1
end

local function SelectNewAttackerWaveTarget(flags, enemyTeam, team)
	if not ConquestState.attackerFlagTargetOrder or #ConquestState.attackerFlagTargetOrder == 0 then
		RebuildAttackerTargetOrder(flags, enemyTeam, team)
	end

	for _ = 1, 2 do
		local order = ConquestState.attackerFlagTargetOrder or {}
		local startIndex = ConquestState.attackerFlagTargetOrderIndex or 1

		for index = startIndex, #order do
			local target = GetFlagByName(flags, order[index])
			ConquestState.attackerFlagTargetOrderIndex = index + 1

			if IsAttackerTargetStillValid(target, team) then
				ConquestState.attackerWaveTargetFlagName = target.name

				if printDebug then
					print("Print: attacker wave target selected",
						"wave=", tostring(ConquestState.waveNumber + 1),
						"flag=", tostring(target.name),
						"orderIndex=", tostring(index),
						"orderSize=", tostring(#order))
				end

				return target
			end
		end

		RebuildAttackerTargetOrder(flags, enemyTeam, team)
	end

	ConquestState.attackerWaveTargetFlagName = nil
	return nil
end

local function GetAttackerWaveTarget(flags, enemyTeam, team)
	local storedTarget = GetFlagByName(flags, ConquestState.attackerWaveTargetFlagName)

	if IsAttackerTargetStillValid(storedTarget, team) then
		return storedTarget
	end

	return SelectNewAttackerWaveTarget(flags, enemyTeam, team)
end

local function GetActiveCounterattackTarget(flags, team)
	if ConquestState.purchasePhase ~= "defender_counterattack" then
		return nil
	end

	local target = GetFlagByName(flags, ConquestState.counterattackFlagName)
	if target and target.owner ~= team then
		return target
	end

	return nil
end

-- Function to calculate flag priority for defender
local function calculateDefenderPriority(f, enemyTeam, team)
	if f.owner == enemyTeam then
		return f.priority * 2
	elseif f.owner == team then
		return f.priority * 0.5
	end

	return f.priority
end

-- Selects the next flag target using weighted priorities.
function GetFlagToCapture(flagPoints, getPriority, flags)
	local alliedFlags, opponentFlags, neutralFlags, totalFlags = CalculateFlagStatistics(BotApi.Scene.Flags)
	local capturableFlags = CalculateCapturableFlags(totalFlags, alliedFlags)

	PrintFlagDebugInfo(alliedFlags, opponentFlags, neutralFlags, totalFlags, capturableFlags, teamIsLosing)

	searchDestroy = CalculateSearchDestroyValue(capturableFlags, alliedFlags, opponentFlags)

	if not ConquestState.botDefender then
		return GetAttackerWaveTarget(flags, enemyTeam, team)
	end

	local counterattackTarget = GetActiveCounterattackTarget(flags, team)
	if counterattackTarget then
		return counterattackTarget
	end

	return GetRandomItem(flags, function(f)
		return calculateDefenderPriority(f, enemyTeam, team)
	end)
end
