-- =========================================================
-- COMBAT PRESSURE
-- =========================================================
-- Shared weighted combat-pressure scoring for scene compositions.
-- This is not a scene-query source; it only evaluates already-captured compositions.

ConquestCombatPressure = ConquestCombatPressure or {}

function ConquestCombatPressure.CalculateScore(composition)
	local weights = ConquestConfig.CombatPressureWeights
	local c = composition or {}

	return
		((c.Infantry or 0) * weights.Infantry)
		+ ((c.Armor or 0) * weights.Armor)
		+ ((c.HeavyArmor or 0) * weights.HeavyArmor)
		+ ((c.SuperHeavyArmor or 0) * weights.SuperHeavyArmor)
		+ ((c.MachineGun or 0) * weights.MachineGun)
		+ ((c.AutoCannon or 0) * weights.AutoCannon)
		+ ((c.LightAT or 0) * weights.LightAT)
		+ ((c.ATGun or 0) * weights.ATGun)
		+ ((c.Flame or 0) * weights.Flame)
		+ ((c.MediumHE or 0) * weights.MediumHE)
		+ ((c.LargeHE or 0) * weights.LargeHE)
end

function ConquestCombatPressure.GetRatio(currentScore, baselineScore)
	if not baselineScore or baselineScore <= 0 then
		if currentScore and currentScore > 0 then
			return 1
		end

		return 0
	end

	return (currentScore or 0) / baselineScore
end

function ConquestCombatPressure.ClampRatio(ratio)
	if not ratio or ratio < 0 then
		return 0
	end

	if ratio > 1 then
		return 1
	end

	return ratio
end

function ConquestCombatPressure.GetLevelFromRatio(ratio, config)
	local c = config or ConquestConfig.AttackerDynamicWaveOff

	if ratio < c.DegradedRatio then
		return "degraded"
	end

	if ratio < c.RetainedRatio then
		return "reduced"
	end

	return "retained"
end
