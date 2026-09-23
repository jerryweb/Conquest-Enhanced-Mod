-- =========================================================
-- PURCHASE PRESSURE
-- =========================================================
-- Calculates purchase-count pressure deltas for finite purchase phases.
-- This file decides how many extra/fewer units a phase should buy, not what units to buy.

ConquestPressure = ConquestPressure or {}

local RISK_LOW = "low"
local RISK_STANDARD = "standard"
local RISK_HIGH = "high"

local DIFFICULTY_NORMAL = "normal"

local CP_STAGE_2 = "Stage2"
local CP_STAGE_5 = "Stage5"

local COMMITMENT_NORMAL = "NormalCommitment"
local COMMITMENT_FULL = "FullCommitment"

-- Clamps a number inside a min/max range.
local function Clamp(value, minValue, maxValue)
	if minValue ~= nil and value < minValue then
		return minValue
	end

	if maxValue ~= nil and value > maxValue then
		return maxValue
	end

	return value
end

-- Returns the current risk key from BotApi.Conquest.Risk.
local function GetRiskKey()
	local risk = BotApi.Conquest.Risk

	if risk == 0 then
		return RISK_LOW
	elseif risk == 1 then
		return RISK_STANDARD
	elseif risk == 2 then
		return RISK_HIGH
	end

	return RISK_STANDARD
end

-- Returns the current difficulty key from BotApi.Instance.difficulty.
local function GetDifficultyKey()
	return BotApi.Instance.difficulty
end

-- Returns the configured delta for a phase from a keyed delta table.
local function GetPhaseDelta(deltaTable, key, phaseName, fallbackKey)
	if not deltaTable then
		return 0
	end

	local row = deltaTable[key] or deltaTable[fallbackKey]
	if not row then
		return 0
	end

	return row[phaseName] or 0
end

-- Returns the CP-limit stage band for the current battle scale.
local function GetPlayerCPLimitStage()
	local cpLimit = BotApi.Conquest.ArmyCPLimit
	if not cpLimit or cpLimit <= 0 then
		return CP_STAGE_2
	end

	for _, stage in ipairs(ConquestConfig.PurchasePressure.CPLimitStages) do
		if stage.max == nil or cpLimit <= stage.max then
			return stage.band
		end
	end

	return CP_STAGE_5
end

-- Returns the commitment band based on ArmyCP / ArmyCPLimit.
local function GetPlayerBattleCommitmentBand()
	local playerCP = BotApi.Conquest.ArmyCP
	local cpLimit = BotApi.Conquest.ArmyCPLimit

	if not playerCP or not cpLimit or cpLimit <= 0 then
		return COMMITMENT_NORMAL
	end

	local commitment = playerCP / cpLimit

	for _, threshold in ipairs(ConquestConfig.PurchasePressure.CommitmentThresholds) do
		if threshold.max == nil or commitment <= threshold.max then
			return threshold.band
		end
	end

	return COMMITMENT_FULL
end

-- Returns detailed purchase-count pressure deltas for one phase.
function ConquestPressure.GetPurchaseCountDeltaDetails(phaseName)
	local config = ConquestConfig.PurchasePressure
	local riskKey = GetRiskKey()
	local difficultyKey = GetDifficultyKey()
	local cpLimitStage = GetPlayerCPLimitStage()
	local commitmentBand = GetPlayerBattleCommitmentBand()

	local riskDelta = GetPhaseDelta(config.RiskPurchaseCountDelta, riskKey, phaseName, RISK_STANDARD)
	local difficultyDelta = GetPhaseDelta(config.DifficultyPurchaseCountDelta, difficultyKey, phaseName, DIFFICULTY_NORMAL)
	local battleScaleDelta = GetPhaseDelta(config.PlayerBattleScalePurchaseCountDelta, cpLimitStage, phaseName, CP_STAGE_2)
	local battleCommitmentDelta = GetPhaseDelta(config.PlayerBattleCommitmentPurchaseCountDelta, commitmentBand, phaseName, COMMITMENT_NORMAL)

	local unclampedDelta = riskDelta
		+ difficultyDelta
		+ battleScaleDelta
		+ battleCommitmentDelta

	local clamp = config.DeltaClamp[phaseName] or config.DeltaClamp.Default
	local totalDelta = Clamp(unclampedDelta, clamp.min, clamp.max)

	return {
		phaseName = phaseName,

		riskKey = riskKey,
		difficultyKey = difficultyKey,
		cpLimitStage = cpLimitStage,
		commitmentBand = commitmentBand,

		riskDelta = riskDelta,
		difficultyDelta = difficultyDelta,
		battleScaleDelta = battleScaleDelta,
		battleCommitmentDelta = battleCommitmentDelta,

		unclampedDelta = unclampedDelta,
		totalDelta = totalDelta,
	}
end

-- Returns the final clamped purchase-count delta for one phase.
function ConquestPressure.GetPurchaseCountDelta(phaseName)
	return ConquestPressure.GetPurchaseCountDeltaDetails(phaseName).totalDelta
end

-- Prints purchase-pressure details when printDebug is enabled.
local function PrintPurchasePressureDetails(details, baseCount, finalCount)
	if not printDebug then
		return
	end

	print(
		"Print: purchasePressure",
		details.phaseName,
		"base=", baseCount,
		"pressureAdjusted=", finalCount,
		"risk=", details.riskKey,
		"riskDelta=", details.riskDelta,
		"difficulty=", details.difficultyKey,
		"difficultyDelta=", details.difficultyDelta,
		"cpStage=", details.cpLimitStage,
		"battleScaleDelta=", details.battleScaleDelta,
		"ArmyCP=", tostring(BotApi.Conquest.ArmyCP),
		"ArmyCPLimit=", tostring(BotApi.Conquest.ArmyCPLimit),
		"ArmySquads=", tostring(BotApi.Conquest.ArmySquads),
		"commitment=", details.commitmentBand,
		"commitmentDelta=", details.battleCommitmentDelta,
		"unclampedDelta=", details.unclampedDelta,
		"totalDelta=", details.totalDelta
	)
end

-- Applies the current pressure delta to a base count and clamps to a minimum count.
function ConquestPressure.ApplyPurchaseCountDelta(baseCount, phaseName, minCount)
	local details = ConquestPressure.GetPurchaseCountDeltaDetails(phaseName)
	local adjustedCount = baseCount + details.totalDelta
	local finalCount = math.max(minCount or 1, adjustedCount)

	PrintPurchasePressureDetails(details, baseCount, finalCount)

	return finalCount
end