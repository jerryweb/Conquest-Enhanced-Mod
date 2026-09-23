-- =========================================================
-- PURCHASE SCORING
-- =========================================================
-- Slot candidate matching and weighted unit selection.

ConquestPurchaseScoring = ConquestPurchaseScoring or {}

local function HasValue(list, tag)
	if type(list) == "string" then
		return list == tag
	end

	if type(list) ~= "table" then
		return false
	end

	for _, value in ipairs(list) do
		if value == tag then
			return true
		end
	end

	return false
end

function ConquestPurchaseScoring.UnitHasTag(unit, tag)
	if not unit then
		return false
	end

	return HasValue(unit.type, tag)
		or HasValue(unit.base, tag)
		or HasValue(unit.class, tag)
		or HasValue(unit.posture, tag)
		or HasValue(unit.role, tag)
		or HasValue(unit.roles, tag)
		or HasValue(unit.effects, tag)
		or HasValue(unit.mobility, tag)
		or HasValue(unit.identity, tag)
		or unit.grade == tag
end

local function UnitHasTag(unit, tag)
	return ConquestPurchaseScoring.UnitHasTag(unit, tag)
end

function ConquestPurchaseScoring.GetPlatformLabel(unit)
	if UnitHasTag(unit, "Infantry") and UnitHasTag(unit, "Squad") then
		return "InfantrySquad"
	end

	if UnitHasTag(unit, "Infantry") and UnitHasTag(unit, "Single") then
		return "InfantrySingle"
	end

	if UnitHasTag(unit, "Cannon") then
		return "Cannon"
	end

	if UnitHasTag(unit, "Vehicle") then
		return "Vehicle"
	end

	if UnitHasTag(unit, "Tank") then
		return "Tank"
	end

	if UnitHasTag(unit, "SPG") then
		return "SPG"
	end

	return "UnknownPlatform"
end

local function IsPlatform(unit, platform)
	return ConquestPurchaseScoring.GetPlatformLabel(unit) == platform
end

local function IsInfantrySingle(unit)
	return IsPlatform(unit, "InfantrySingle")
end

local function IsInfantrySquad(unit)
	return IsPlatform(unit, "InfantrySquad")
end

local function IsCannon(unit)
	return IsPlatform(unit, "Cannon")
end

local function IsVehicle(unit)
	return IsPlatform(unit, "Vehicle")
end

local function IsTank(unit)
	return IsPlatform(unit, "Tank")
end

local function IsSPG(unit)
	return IsPlatform(unit, "SPG")
end

local function IsMobilePlatform(unit)
	return IsVehicle(unit) or IsTank(unit) or IsSPG(unit)
end

local function IsInfantryLine(unit)
	return UnitHasTag(unit, "InfantryLine")
		or (IsInfantrySquad(unit) and UnitHasTag(unit, "Line"))
end

local function IsAssault(unit)
	return UnitHasTag(unit, "InfantryAssault")
		or UnitHasTag(unit, "Assault")
end

local function IsInfantryAT(unit)
	return UnitHasTag(unit, "InfantryAT")
		or ((IsInfantrySquad(unit) or IsInfantrySingle(unit)) and UnitHasTag(unit, "AntiTank"))
end

local function IsRecon(unit)
	return UnitHasTag(unit, "Recon")
end

local function IsAntiArmor(unit)
	return UnitHasTag(unit, "AntiArmor")
		or UnitHasTag(unit, "AntiTank")
end

local function IsMachineGun(unit)
	return UnitHasTag(unit, "MachineGun")
		or UnitHasTag(unit, "MG")
end

local function IsInfantryGun(unit)
	return UnitHasTag(unit, "InfantryGun")
end

local function IsFieldGun(unit)
	return UnitHasTag(unit, "FieldGun")
end

local function IsMortar(unit)
	return UnitHasTag(unit, "Mortar")
end

local function IsArtillery(unit)
	return UnitHasTag(unit, "Artillery")
end

local function IsAirDefense(unit)
	return UnitHasTag(unit, "AirDefense")
end

local function IsArmorTank(unit)
	if not IsTank(unit) then
		return false
	end

	if IsAntiArmor(unit) or IsInfantryGun(unit) or IsFieldGun(unit) then
		return false
	end

	return UnitHasTag(unit, "Armor") or not IsRecon(unit)
end

local function IsLight(unit)
	return UnitHasTag(unit, "Light")
end

local function IsHeavy(unit)
	return UnitHasTag(unit, "Heavy")
end

local function HasOffensivePosture(unit)
	return UnitHasTag(unit, "Offensive")
end

local function HasDefensivePosture(unit)
	return UnitHasTag(unit, "Defensive")
end

local function HasFlexiblePosture(unit)
	return UnitHasTag(unit, "Flexible")
end

local function IsMountedInfantry(unit)
	return (IsInfantrySquad(unit) or IsInfantrySingle(unit))
		and (UnitHasTag(unit, "Motorized") or UnitHasTag(unit, "Mechanized"))
end

function ConquestPurchaseScoring.GetPurchaseForceCost(unit)
	if IsInfantrySingle(unit) then
		return ConquestConfig.PurchaseForces.SingleForceCost
	end

	return ConquestConfig.PurchaseForces.DefaultForceCost
end

local function GetPurchaseScoringConfig()
	return ConquestConfig.PurchaseScoring
end

local function GetLaneFitConfig(laneName)
	local config = GetPurchaseScoringConfig().LaneFit
	return config[laneName] or {}
end

local function GetRuleWeight(rules, key)
	return rules[key] or 0
end

local function GetAvailabilityWeight(unit)
	local weights = GetPurchaseScoringConfig().AvailabilityWeight
	return weights[tostring(unit.availability)] or 1.0
end

local function GetGradeWeight(unit)
	local difficulty = BotApi.Instance.difficulty or "normal"
	local weights = GetPurchaseScoringConfig().DifficultyGradeWeight
	local row = weights[difficulty] or weights.normal
	return row[unit.grade] or 1.0
end

local class_gate_group = {
	Tank = "Tank",
	SPG = "SPG",
	Vehicle = "Vehicle",
	Cannon = "Cannon",
}

local function GetClassGateGroup(unit)
	return class_gate_group[ConquestPurchaseScoring.GetPlatformLabel(unit)]
end

local function GetClassTier(unit)
	if IsHeavy(unit) then
		return "Heavy"
	end

	if UnitHasTag(unit, "Medium") then
		return "Medium"
	end

	if IsLight(unit) then
		return "Light"
	end

	return nil
end

local function GetClassWeight(unit)
	local group = GetClassGateGroup(unit)
	if not group then
		return 1.0
	end

	local config = GetPurchaseScoringConfig().DifficultyClassWeight
	if not config then
		return 1.0
	end

	local strength = (config.ClassGateStrength or {})[group]
	if not strength or strength <= 0 then
		return 1.0
	end

	local tier = GetClassTier(unit)
	if not tier then
		return 1.0
	end

	local row = (config.Curve or {})[BotApi.Instance.difficulty]
	if not row then
		return 1.0
	end

	local base = row[tier] or 1.0
	return 1.0 + strength * (base - 1.0)
end

local function GetIndirectWeight(key)
	local config = GetPurchaseScoringConfig().DifficultyIndirectWeight
	if not config then
		return 1.0
	end

	local row = config[BotApi.Instance.difficulty]
	if not row then
		return 1.0
	end

	return row[key] or 1.0
end

local function GetPhaseFit(unit)
	local rules = GetPurchaseScoringConfig().PhaseFit[ConquestState.purchasePhase]
	if not rules then
		return 1.0
	end

	local fit = 1.0

	if rules.OffensiveOrFlexible and (HasOffensivePosture(unit) or HasFlexiblePosture(unit)) then
		fit = fit * rules.OffensiveOrFlexible
	end

	if rules.Defensive and HasDefensivePosture(unit) then
		fit = fit * rules.Defensive
	end

	if rules.DefensiveOrFlexible and (HasDefensivePosture(unit) or HasFlexiblePosture(unit)) then
		fit = fit * rules.DefensiveOrFlexible
	end

	if rules.MountedInfantry and IsMountedInfantry(unit) then
		fit = fit * rules.MountedInfantry
	end

	if rules.OffensiveVehicleSupport
		and HasOffensivePosture(unit)
		and IsVehicle(unit)
		and (IsArtillery(unit) or IsMortar(unit) or IsAntiArmor(unit) or IsFieldGun(unit)) then
		fit = fit * rules.OffensiveVehicleSupport
	end

	return fit
end

local function GetActiveIntent()
	local plan = ConquestState.purchasePlan

	if plan and plan.phase == "attacker_wave" then
		return plan.intent or "main_attack"
	end

	return nil
end

local function GetArmoredInfantrySupportPhaseFit(unit, laneName)
	if laneName ~= "armored_infantry_support" then
		return 1.0
	end

	local phaseRules = GetPurchaseScoringConfig().ArmoredInfantrySupportPhaseFit[ConquestState.purchasePhase]
	if not phaseRules then
		return 1.0
	end

	if phaseRules.MountedInfantry and IsMountedInfantry(unit) then
		return phaseRules.MountedInfantry
	end

	return 1.0
end

local support_phase_lanes = {
	infantry_organic_support = true,
	armored_mobile_support = true,
	anti_tank_force = true,
	artillery_support_force = true,
	aa_support_force = true,
}

local function IsSupportLane(laneName)
	return support_phase_lanes[laneName] == true
end

local function IsHeavyIndirectSupport(unit)
	return IsArtillery(unit) or (IsMortar(unit) and IsHeavy(unit))
end

local function ApplySupportPhaseRule(unit, laneName, rule)
	local fit = 1.0

	if rule.MobilePlatform and IsMobilePlatform(unit) then
		fit = fit * rule.MobilePlatform
	end

	if rule.Cannon and IsCannon(unit) then
		fit = fit * rule.Cannon
	end

	if rule.HeavyIndirectSupport and IsHeavyIndirectSupport(unit) then
		fit = fit * rule.HeavyIndirectSupport
	end

	if rule.MobileAirDefense and IsAirDefense(unit) and IsMobilePlatform(unit) then
		fit = fit * rule.MobileAirDefense
	end

	local laneRule = rule.LaneRules and rule.LaneRules[laneName]
	if laneRule and laneRule.InfantryAT and IsInfantryAT(unit) then
		fit = fit * laneRule.InfantryAT
	end

	return fit
end

local function GetSupportLanePhaseFit(unit, laneName)
	if not IsSupportLane(laneName) then
		return 1.0
	end

	local config = GetPurchaseScoringConfig().SupportLanePhaseFit
	local rule = config.PhaseRules[ConquestState.purchasePhase]
	if not rule then
		return 1.0
	end

	return ApplySupportPhaseRule(unit, laneName, rule)
end

local function GetInfantryBodyFit(unit)
	local rules = GetLaneFitConfig("infantry_body")

	if IsInfantryLine(unit) then
		return GetRuleWeight(rules, "InfantryLine")
	end

	if IsRecon(unit) and IsInfantrySquad(unit) then
		return GetRuleWeight(rules, "ReconInfantrySquad")
	end

	if IsRecon(unit) and IsInfantrySingle(unit) then
		return GetRuleWeight(rules, "ReconInfantrySingle")
	end

	if IsAssault(unit) and IsInfantrySquad(unit) then
		return GetRuleWeight(rules, "AssaultInfantrySquad")
	end

	return 0
end

local function GetInfantryOrganicSupportFit(unit)
	local rules = GetLaneFitConfig("infantry_organic_support")

	if IsMachineGun(unit) and IsCannon(unit) then
		return GetRuleWeight(rules, "CannonMachineGun")
	end

	if IsMortar(unit) and IsCannon(unit) and not IsHeavy(unit) then
		return GetRuleWeight(rules, "LightCannonMortar")
	end

	if IsInfantryGun(unit) and IsCannon(unit) then
		return GetRuleWeight(rules, "CannonInfantryGun")
	end

	if IsFieldGun(unit) then
		return GetRuleWeight(rules, "FieldGun")
	end

	if IsAntiArmor(unit) and IsCannon(unit) and IsLight(unit) then
		return GetRuleWeight(rules, "LightCannonAntiArmor")
	end

	if IsInfantryAT(unit) then
		return GetRuleWeight(rules, "InfantryAT")
	end

	if IsInfantryGun(unit) and IsMobilePlatform(unit) then
		return GetRuleWeight(rules, "MobileInfantryGun")
	end

	return 0
end

local function GetArmoredBodyFit(unit)
	local rules = GetLaneFitConfig("armored_body")

	if IsArmorTank(unit) then
		return GetRuleWeight(rules, "ArmorTank")
	end

	if IsRecon(unit) and (IsVehicle(unit) or IsTank(unit)) then
		return GetRuleWeight(rules, "ReconVehicleOrTank")
	end

	return 0
end

local function GetArmoredInfantrySupportFit(unit)
	local rules = GetLaneFitConfig("armored_infantry_support")

	if IsInfantryLine(unit) then
		return GetRuleWeight(rules, "InfantryLine")
	end

	if IsRecon(unit) and IsInfantrySquad(unit) then
		return GetRuleWeight(rules, "ReconInfantrySquad")
	end

	if IsAssault(unit) and IsInfantrySquad(unit) then
		return GetRuleWeight(rules, "AssaultInfantrySquad")
	end

	if IsInfantryAT(unit) then
		return GetRuleWeight(rules, "InfantryAT")
	end

	return 0
end

local function GetArmoredMobileSupportFit(unit)
	local rules = GetLaneFitConfig("armored_mobile_support")

	if IsMachineGun(unit) and IsVehicle(unit) then
		return GetRuleWeight(rules, "VehicleMachineGun")
	end

	if IsInfantryGun(unit) and IsMobilePlatform(unit) then
		return GetRuleWeight(rules, "MobileInfantryGun")
	end

	if IsAssault(unit) and (IsTank(unit) or IsVehicle(unit)) then
		return GetRuleWeight(rules, "AssaultVehicleOrTank")
	end

	if IsMachineGun(unit) and IsCannon(unit) then
		return GetRuleWeight(rules, "CannonMachineGun")
	end

	if IsMortar(unit) and IsVehicle(unit) then
		return GetRuleWeight(rules, "VehicleMortar")
	end

	if IsRecon(unit) and IsVehicle(unit) then
		return GetRuleWeight(rules, "VehicleRecon")
	end

	return 0
end

local function GetSecondaryArmoredFit(unit)
	local rules = GetLaneFitConfig("secondary_armored_force")

	if IsArmorTank(unit) then
		return GetRuleWeight(rules, "ArmorTank")
	end

	if IsRecon(unit) and (IsVehicle(unit) or IsTank(unit)) then
		return GetRuleWeight(rules, "ReconVehicleOrTank")
	end

	if IsAssault(unit) and (IsTank(unit) or IsVehicle(unit)) then
		return GetRuleWeight(rules, "AssaultVehicleOrTank")
	end

	return 0
end

local function GetAntiTankFit(unit)
	local rules = GetLaneFitConfig("anti_tank_force")

	if IsInfantryAT(unit) then
		return GetRuleWeight(rules, "InfantryAT")
	end

	if IsFieldGun(unit) then
		return GetRuleWeight(rules, "FieldGun")
	end

	if IsAntiArmor(unit) then
		return GetRuleWeight(rules, "AntiArmor")
	end

	return 0
end

local function GetArtilleryFit(unit)
	local rules = GetLaneFitConfig("artillery_support_force")

	if IsArtillery(unit) then
		return GetRuleWeight(rules, "Artillery") * GetIndirectWeight("Artillery")
	end

	if IsMortar(unit) and IsHeavy(unit) then
		return GetRuleWeight(rules, "HeavyMortar") * GetIndirectWeight("HeavyMortar")
	end

	return 0
end

local function GetAirDefenseFit(unit)
	local rules = GetLaneFitConfig("aa_support_force")

	if IsAirDefense(unit) then
		return GetRuleWeight(rules, "AirDefense")
	end

	return 0
end

local function GetProbeMobileFit(unit)
	local rules = GetLaneFitConfig("probe_mobile")

	if IsRecon(unit) and (IsVehicle(unit) or IsTank(unit)) then
		return GetRuleWeight(rules, "ReconVehicleOrTank")
	end

	if IsMachineGun(unit) and IsVehicle(unit) then
		return GetRuleWeight(rules, "VehicleMachineGun")
	end

	if IsArmorTank(unit) and IsTank(unit) and IsLight(unit) then
		return GetRuleWeight(rules, "LightArmorTank")
	end

	return 0
end

local function GetProbeInfantryFit(unit)
	local rules = GetLaneFitConfig("probe_infantry")

	if IsInfantryLine(unit) then
		return GetRuleWeight(rules, "InfantryLine")
	end

	if IsRecon(unit) and IsInfantrySquad(unit) then
		return GetRuleWeight(rules, "ReconInfantrySquad")
	end

	if IsRecon(unit) and IsInfantrySingle(unit) then
		return GetRuleWeight(rules, "ReconInfantrySingle")
	end

	return 0
end

local function GetProbeLightArmorFit(unit)
	local rules = GetLaneFitConfig("probe_light_armor")

	if IsArmorTank(unit) and IsTank(unit) and IsLight(unit) then
		return GetRuleWeight(rules, "LightArmorTank")
	end

	if IsRecon(unit) and (IsVehicle(unit) or IsTank(unit)) then
		return GetRuleWeight(rules, "ReconVehicleOrTank")
	end

	if IsMachineGun(unit) and IsVehicle(unit) then
		return GetRuleWeight(rules, "VehicleMachineGun")
	end

	if IsArmorTank(unit) and IsTank(unit) and not IsHeavy(unit) then
		return GetRuleWeight(rules, "NonHeavyArmorTank")
	end

	return 0
end

local function GetLaneFit(unit, laneName)
	if laneName == "infantry_body" then
		return GetInfantryBodyFit(unit)
	elseif laneName == "infantry_organic_support" then
		return GetInfantryOrganicSupportFit(unit)
	elseif laneName == "armored_body" then
		return GetArmoredBodyFit(unit)
	elseif laneName == "armored_infantry_support" then
		return GetArmoredInfantrySupportFit(unit)
	elseif laneName == "armored_mobile_support" then
		return GetArmoredMobileSupportFit(unit)
	elseif laneName == "secondary_armored_force" then
		return GetSecondaryArmoredFit(unit)
	elseif laneName == "anti_tank_force" then
		return GetAntiTankFit(unit)
	elseif laneName == "artillery_support_force" then
		return GetArtilleryFit(unit)
	elseif laneName == "aa_support_force" then
		return GetAirDefenseFit(unit)
	elseif laneName == "probe_mobile" then
		return GetProbeMobileFit(unit)
	elseif laneName == "probe_infantry" then
		return GetProbeInfantryFit(unit)
	elseif laneName == "probe_light_armor" then
		return GetProbeLightArmorFit(unit)
	end

	return 0
end

function ConquestPurchaseScoring.GetLaneFitForSim(unit, laneName)
	return GetLaneFit(unit, laneName)
end

local function GetCandidateWeight(unit, laneName, laneFit)
	local weight = GetAvailabilityWeight(unit)
		* GetGradeWeight(unit)
		* GetClassWeight(unit)
		* laneFit
		* GetPhaseFit(unit)
		* GetArmoredInfantrySupportPhaseFit(unit, laneName)
		* GetSupportLanePhaseFit(unit, laneName)

	if IsInfantrySingle(unit) then
		weight = weight * GetPurchaseScoringConfig().SingleInfantryWeight
	end

	return weight
end

local function GetWeightedRandom(candidates)
	local totalWeight = 0

	for _, candidate in ipairs(candidates or {}) do
		totalWeight = totalWeight + (candidate.weight or 0)
	end

	if totalWeight <= 0 then
		return nil
	end

	local roll = math.random() * totalWeight
	local running = 0

	for _, candidate in ipairs(candidates or {}) do
		running = running + (candidate.weight or 0)
		if roll <= running then
			return candidate.unit, candidate.laneName, candidate.weight
		end
	end

	local last = candidates[#candidates]
	if last then
		return last.unit, last.laneName, last.weight
	end

	return nil
end

local function BuildLaneCandidates(units, laneName)
	local candidates = {}

	for _, unit in ipairs(units or {}) do
		local laneFit = GetLaneFit(unit, laneName)
		if laneFit > 0 then
			table.insert(candidates, {
				unit = unit,
				laneName = laneName,
				weight = GetCandidateWeight(unit, laneName, laneFit),
			})
		end
	end

	return candidates
end

local function BuildFallbackCandidates(units)
	local candidates = {}

	for _, unit in ipairs(units or {}) do
		table.insert(candidates, {
			unit = unit,
			laneName = "fallback",
			weight = GetAvailabilityWeight(unit) * GetGradeWeight(unit) * GetClassWeight(unit),
		})
	end

	return candidates
end

local function SelectLane(plan, units)
	local bestLane = nil
	local bestRemaining = -1
	local bestCandidates = nil

	for _, lane in ipairs(plan.lanes or {}) do
		local remaining = (lane.budget or 0) - (lane.spent or 0)
		if remaining > 0 then
			local candidates = BuildLaneCandidates(units, lane.name)
			if #candidates > 0 and remaining > bestRemaining then
				bestLane = lane
				bestRemaining = remaining
				bestCandidates = candidates
			end
		end
	end

	return bestLane, bestCandidates
end

function ConquestPurchaseScoring.SelectUnitForCurrentPlan(units)
	local plan = ConquestState.purchasePlan
	local candidates = nil
	local laneName = nil

	if plan then
		local lane, laneCandidates = SelectLane(plan, units)
		if lane then
			laneName = lane.name
			candidates = laneCandidates
		end
	end

	if not candidates or #candidates == 0 then
		candidates = BuildFallbackCandidates(units)
		laneName = "fallback"
	end

	local unit, selectedLaneName, selectedWeight = GetWeightedRandom(candidates)
	if not unit then
		return nil
	end

	local forceCost = ConquestPurchaseScoring.GetPurchaseForceCost(unit)
	ConquestState.pendingPurchaseForceCost = forceCost
	ConquestState.pendingPurchaseLane = selectedLaneName or laneName

	if printDebug then
		print("Print: purchasePick phase=", tostring(ConquestState.purchasePhase),
			"intent=", tostring(GetActiveIntent() or "none"),
			"lane=", tostring(ConquestState.pendingPurchaseLane),
			"unit=", tostring(unit.unit),
			"grade=", tostring(unit.grade or "none"),
			"platform=", ConquestPurchaseScoring.GetPlatformLabel(unit),
			"cost=", tostring(forceCost),
			"weight=", tostring(selectedWeight or 0))
	end

	return unit
end
