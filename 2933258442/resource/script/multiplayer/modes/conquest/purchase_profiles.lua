-- =========================================================
-- PURCHASE PROFILES
-- =========================================================
-- Battle-local force identity and slot-budget planning.

ConquestPurchaseProfiles = ConquestPurchaseProfiles or {}

local FORCE_NONE = "none"
local PRIMARY_INFANTRY = "infantry_force"
local PRIMARY_ARMORED = "armored_force"

local LANE_INFANTRY_BODY = "infantry_body"
local LANE_INFANTRY_ORGANIC_SUPPORT = "infantry_organic_support"
local LANE_ARMORED_BODY = "armored_body"
local LANE_ARMORED_INFANTRY_SUPPORT = "armored_infantry_support"
local LANE_ARMORED_MOBILE_SUPPORT = "armored_mobile_support"
local LANE_SECONDARY_ARMORED = "secondary_armored_force"
local LANE_ANTI_TANK = "anti_tank_force"
local LANE_ARTILLERY = "artillery_support_force"
local LANE_AA = "aa_support_force"
local LANE_PROBE_MOBILE = "probe_mobile"
local LANE_PROBE_INFANTRY = "probe_infantry"
local LANE_PROBE_LIGHT_ARMOR = "probe_light_armor"

local function Round(value)
	return math.floor((value or 0) + 0.5)
end

local function ResetPendingPurchaseState()
	ConquestState.pendingPurchaseForceCost = ConquestConfig.PurchaseForces.DefaultForceCost
	ConquestState.pendingPurchaseLane = nil
	ConquestState.pendingPurchaseUnit = nil
end

local function AddLane(lanes, laneName, budget)
	if not laneName or not budget or budget <= 0 then
		return
	end

	table.insert(lanes, {
		name = laneName,
		budget = budget,
		spent = 0,
	})
end

local function GetRandomListItem(list)
	if not list or #list == 0 then
		return nil
	end

	return list[math.random(1, #list)]
end

local function ValidateSecondaryForce(primaryForce, secondaryForce)
	if not secondaryForce then
		return FORCE_NONE
	end

	if secondaryForce == primaryForce then
		return FORCE_NONE
	end

	return secondaryForce
end

local function GetSecondaryRollList(primaryForce)
	local config = ConquestConfig.PurchaseForces
	return config.SecondaryForceRoll[primaryForce]
end

local function GetPrimaryForceProfile(primaryForce)
	return ConquestConfig.PurchaseProfiles.PrimaryForce[primaryForce]
end

local function GetArmoredProbeProfile()
	return ConquestConfig.PurchaseProfiles.Probe.armored_force
end

local function RollPrimaryForce()
	return GetRandomListItem(ConquestConfig.PurchaseForces.PrimaryForceRoll) or PRIMARY_INFANTRY
end

local function RollSecondaryForce(primaryForce)
	local secondaryForce = GetRandomListItem(GetSecondaryRollList(primaryForce)) or FORCE_NONE
	return ValidateSecondaryForce(primaryForce, secondaryForce)
end

local function GetSecondaryBudget(targetBudget, secondaryForce)
	local config = ConquestConfig.PurchaseForces

	if not secondaryForce or secondaryForce == FORCE_NONE then
		return 0
	end

	if targetBudget < config.SecondaryMinTarget then
		return 0
	end

	local secondaryShare = config.SecondaryShare
	local forceShare = config.SecondaryShareByForce and config.SecondaryShareByForce[secondaryForce]

	if type(forceShare) == "table" then
		secondaryShare = forceShare[BotApi.Instance.difficulty] or secondaryShare
	elseif forceShare then
		secondaryShare = forceShare
	end

	return math.max(1, Round(targetBudget * secondaryShare))
end

local function AddInfantryPrimaryLanes(lanes, primaryBudget)
	if primaryBudget <= 0 then
		return
	end

	local profile = GetPrimaryForceProfile(PRIMARY_INFANTRY)
	local supportBudget = 0
	if primaryBudget >= 2 then
		supportBudget = Round(primaryBudget * profile.OrganicSupportShare)
	end

	if supportBudget >= primaryBudget then
		supportBudget = primaryBudget - 1
	end

	local bodyBudget = primaryBudget - supportBudget

	AddLane(lanes, LANE_INFANTRY_BODY, bodyBudget)
	AddLane(lanes, LANE_INFANTRY_ORGANIC_SUPPORT, supportBudget)
end

local function AddArmoredPrimaryLanes(lanes, primaryBudget)
	if primaryBudget <= 0 then
		return
	end

	if primaryBudget == 1 then
		AddLane(lanes, LANE_ARMORED_BODY, 1)
		return
	end

	if primaryBudget == 2 then
		AddLane(lanes, LANE_ARMORED_BODY, 1)
		AddLane(lanes, LANE_ARMORED_INFANTRY_SUPPORT, 1)
		return
	end

	local profile = GetPrimaryForceProfile(PRIMARY_ARMORED)
	local bodyBudget = math.max(1, Round(primaryBudget * profile.BodyShare))
	local infantryBudget = math.max(1, Round(primaryBudget * profile.InfantrySupportShare))
	local mobileBudget = primaryBudget - bodyBudget - infantryBudget

	if mobileBudget < 0 then
		mobileBudget = 0
		infantryBudget = primaryBudget - bodyBudget
	end

	AddLane(lanes, LANE_ARMORED_BODY, bodyBudget)
	AddLane(lanes, LANE_ARMORED_INFANTRY_SUPPORT, infantryBudget)
	AddLane(lanes, LANE_ARMORED_MOBILE_SUPPORT, mobileBudget)
end

local function AddArmoredProbePrimaryLanes(lanes, primaryBudget)
	if primaryBudget <= 0 then
		return
	end

	if primaryBudget == 1 then
		AddLane(lanes, LANE_PROBE_MOBILE, 1)
		return
	end

	if primaryBudget == 2 then
		AddLane(lanes, LANE_PROBE_MOBILE, 1)
		AddLane(lanes, LANE_PROBE_INFANTRY, 1)
		return
	end

	local profile = GetArmoredProbeProfile()
	local mobileBudget = math.max(1, Round(primaryBudget * profile.MobileShare))
	local infantryBudget = math.max(1, Round(primaryBudget * profile.InfantryShare))
	local lightArmorBudget = primaryBudget - mobileBudget - infantryBudget

	if lightArmorBudget < 0 then
		lightArmorBudget = 0
		infantryBudget = primaryBudget - mobileBudget
	end

	AddLane(lanes, LANE_PROBE_MOBILE, mobileBudget)
	AddLane(lanes, LANE_PROBE_INFANTRY, infantryBudget)
	AddLane(lanes, LANE_PROBE_LIGHT_ARMOR, lightArmorBudget)
end

local function AddInfantryProbePrimaryLanes(lanes, primaryBudget)
	AddLane(lanes, LANE_PROBE_INFANTRY, primaryBudget)
end

local function AddProbePrimaryLanes(lanes, primaryForce, primaryBudget)
	if primaryForce == PRIMARY_ARMORED then
		AddArmoredProbePrimaryLanes(lanes, primaryBudget)
		return
	end

	AddInfantryProbePrimaryLanes(lanes, primaryBudget)
end

local function AddPrimaryLanes(lanes, primaryForce, primaryBudget)
	if primaryForce == PRIMARY_ARMORED then
		AddArmoredPrimaryLanes(lanes, primaryBudget)
		return
	end

	AddInfantryPrimaryLanes(lanes, primaryBudget)
end

local function AddSecondaryLane(lanes, secondaryForce, secondaryBudget)
	if secondaryBudget <= 0 then
		return
	end

	if secondaryForce == PRIMARY_ARMORED then
		AddLane(lanes, LANE_SECONDARY_ARMORED, secondaryBudget)
	elseif secondaryForce == "anti_tank_force" then
		AddLane(lanes, LANE_ANTI_TANK, secondaryBudget)
	elseif secondaryForce == "artillery_support_force" then
		AddLane(lanes, LANE_ARTILLERY, secondaryBudget)
	elseif secondaryForce == "aa_support_force" then
		AddLane(lanes, LANE_AA, secondaryBudget)
	end
end


local function PrintPurchaseSceneContext(phase)
	if not printDebug or not ConquestSceneMemory or not ConquestSceneMemory.GetPlayerMemory then
		return
	end

	local playerMemory = ConquestSceneMemory.GetPlayerMemory()
	local latest = playerMemory and playerMemory.latest
	local values = latest and latest.values

	if not values then
		return
	end

	print("Print: purchaseSceneContext",
		"phase=", tostring(phase),
		"source=", tostring(latest.source),
		"playerInfantry=", tostring(values.infantry or 0),
		"playerArmor=", tostring(values.armor or 0),
		"playerHeavyArmor=", tostring(values.heavyArmor or 0),
		"playerAntiArmor=", tostring(values.antiArmor or 0),
		"playerATGun=", tostring(values.atGun or 0),
		"playerDirectFire=", tostring(values.directFire or 0),
		"playerMachineGun=", tostring(values.machineGun or 0),
		"playerAmmoSupply=", tostring(values.ammoSupply or 0))
end

local function FormatLaneBudgets(lanes)
	local parts = {}

	for _, lane in ipairs(lanes or {}) do
		table.insert(parts, tostring(lane.name) .. "=" .. tostring(lane.budget))
	end

	if #parts == 0 then
		return "none"
	end

	return table.concat(parts, ",")
end

function ConquestPurchaseProfiles.InitializeBattleForce()
	ConquestState.primaryForce = RollPrimaryForce()
	ConquestState.secondaryForce = RollSecondaryForce(ConquestState.primaryForce)

	if printDebug then
		print("Print: purchaseForce primary=", ConquestState.primaryForce, "secondary=", ConquestState.secondaryForce)
		print("Print: Operation Day " .. BotApi.Conquest.OperationDay)
	end
end

function ConquestPurchaseProfiles.StartPurchasePhasePlan(phase, targetBudget)
	local phaseIntent = nil
	local secondaryBudget = GetSecondaryBudget(targetBudget, ConquestState.secondaryForce)
	local primaryBudget = targetBudget - secondaryBudget
	local lanes = {}

	if phase == "attacker_wave" then
		phaseIntent = ConquestState.attackerWaveIntent
	end

	if phase == "attacker_wave" and phaseIntent == "probe" then
		secondaryBudget = 0
		primaryBudget = targetBudget
		AddProbePrimaryLanes(lanes, ConquestState.primaryForce, primaryBudget)
	else
		AddPrimaryLanes(lanes, ConquestState.primaryForce, primaryBudget)
		AddSecondaryLane(lanes, ConquestState.secondaryForce, secondaryBudget)
	end

	ConquestState.purchasePlan = {
		phase = phase,
		targetBudget = targetBudget,
		primaryForce = ConquestState.primaryForce,
		secondaryForce = ConquestState.secondaryForce,
		intent = phaseIntent,
		lanes = lanes,
	}

	ResetPendingPurchaseState()

	if printDebug then
		print("Print: purchasePlan phase=", phase,
			"targetBudget=", targetBudget,
			"primary=", ConquestState.primaryForce,
			"secondary=", ConquestState.secondaryForce,
			"intent=", tostring(ConquestState.purchasePlan.intent or "none"),
			"lanes=", FormatLaneBudgets(lanes))

		PrintPurchaseSceneContext(phase)
	end
end

function ConquestPurchaseProfiles.FinishPurchasePhasePlan()
	if printDebug and ConquestState.purchasePlan then
		print("Print: purchasePlanFinished phase=", ConquestState.purchasePlan.phase,
			"spent=", ConquestState.phasePurchaseCount,
			"targetBudget=", ConquestState.purchasePlan.targetBudget)
	end

	ConquestState.purchasePlan = nil
	ResetPendingPurchaseState()
end

function ConquestPurchaseProfiles.CommitPendingPurchaseCost()
	local plan = ConquestState.purchasePlan
	local laneName = ConquestState.pendingPurchaseLane
	local forceCost = ConquestState.pendingPurchaseForceCost or ConquestConfig.PurchaseForces.DefaultForceCost

	if plan and laneName then
		for _, lane in ipairs(plan.lanes or {}) do
			if lane.name == laneName then
				lane.spent = (lane.spent or 0) + forceCost
				break
			end
		end
	end

	ResetPendingPurchaseState()

	return forceCost
end
