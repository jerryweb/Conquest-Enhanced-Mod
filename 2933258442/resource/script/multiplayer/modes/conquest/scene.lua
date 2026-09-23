-- =========================================================
-- SCENE QUERY / COMPOSITION HELPERS
-- =========================================================
-- Scene-query snapshot helpers used by wave pressure and battle-flow systems.
-- Scene-query props are primary threat labels, not a full unit-role schema.

ConquestScene = ConquestScene or {}

-- Props queried from the scene-query system.
ConquestScene.QueryProps = {
	-- Infantry / crew
	"soldier",
	"crew",
	"soldier_pzscheck",
	"soldier_pzfaust",
	"soldier_atr",
	"soldier_atr_grenade",
	"soldier_bazooka",

	-- Primary weapon / special threat
	"sq_mg",
	"sq_autocannon",
	"sq_at_light",
	"sq_at_gun",
	"sq_flame",

	-- HE threat
	"sq_he_medium",
	"sq_he_large",

	-- Engineer / supply utility
	"sq_engineer",
	"sq_ammo_supply",

	-- Armor threat
	"sq_armor_light",
	"sq_armor_medium",
	"sq_armor_heavy",
	"sq_armor_super_heavy",
}

-- Creates an empty scene composition table.
function ConquestScene.CreateEmptyComposition()
	return {
		soldier = 0,
		crew = 0,
		soldier_pzscheck = 0,
		soldier_pzfaust = 0,
		soldier_atr = 0,
		soldier_atr_grenade = 0,
		soldier_bazooka = 0,

		sq_mg = 0,
		sq_autocannon = 0,
		sq_at_light = 0,
		sq_at_gun = 0,
		sq_flame = 0,
		sq_he_medium = 0,
		sq_he_large = 0,
		sq_engineer = 0,
		sq_ammo_supply = 0,
		sq_armor_light = 0,
		sq_armor_medium = 0,
		sq_armor_heavy = 0,
		sq_armor_super_heavy = 0,

		Infantry = 0,
		Crew = 0,
		ATInfantry = 0,
		LightArmor = 0,
		MediumArmor = 0,
		HeavyArmor = 0,
		SuperHeavyArmor = 0,
		Armor = 0,
		MachineGun = 0,
		AutoCannon = 0,
		LightAT = 0,
		ATGun = 0,
		Flame = 0,
		MediumHE = 0,
		LargeHE = 0,
		HE = 0,
		DirectFireThreat = 0,
		Engineer = 0,
		AmmoSupply = 0,
	}
end

-- Adds derived totals to a scene composition.
function ConquestScene.UpdateDerivedCompositionValues(composition)
	composition.ATInfantry =
		(composition.soldier_pzscheck or 0)
		+ (composition.soldier_pzfaust or 0)
		+ (composition.soldier_atr or 0)
		+ (composition.soldier_atr_grenade or 0)
		+ (composition.soldier_bazooka or 0)

	composition.Infantry =
		(composition.soldier or 0)
		+ composition.ATInfantry

	composition.Crew = composition.crew or 0

	composition.LightArmor = composition.sq_armor_light or 0
	composition.MediumArmor = composition.sq_armor_medium or 0
	composition.HeavyArmor = composition.sq_armor_heavy or 0
	composition.SuperHeavyArmor = composition.sq_armor_super_heavy or 0

	-- Armor is light/medium only. Heavy and super-heavy armor are tracked separately.
	composition.Armor =
		composition.LightArmor
		+ composition.MediumArmor

	composition.MachineGun = composition.sq_mg or 0
	composition.AutoCannon = composition.sq_autocannon or 0
	composition.LightAT = composition.sq_at_light or 0
	composition.ATGun = composition.sq_at_gun or 0
	composition.Flame = composition.sq_flame or 0
	composition.MediumHE = composition.sq_he_medium or 0
	composition.LargeHE = composition.sq_he_large or 0

	composition.HE =
		composition.MediumHE
		+ composition.LargeHE

	composition.DirectFireThreat =
		composition.MachineGun
		+ composition.AutoCannon
		+ composition.LightAT
		+ composition.ATGun
		+ composition.Flame

	composition.Engineer = composition.sq_engineer or 0
	composition.AmmoSupply = composition.sq_ammo_supply or 0

end

-- Builds a composition table from one QueryScene prop-count row.
function ConquestScene.BuildCompositionFromPropCounts(propCounts, queryProps)
	local composition = ConquestScene.CreateEmptyComposition()

	for i, propName in ipairs(queryProps) do
		composition[propName] = propCounts[i] or 0
	end

	ConquestScene.UpdateDerivedCompositionValues(composition)

	return composition
end

-- Builds a map of scene compositions keyed by player ID.
function ConquestScene.BuildCompositionByPlayer(sceneUnits, queryProps)
	local compositions = {}

	for _, row in ipairs(sceneUnits or {}) do
		local playerId = row[1]
		local propCounts = row[2]

		if playerId ~= nil and propCounts then
			compositions[playerId] = ConquestScene.BuildCompositionFromPropCounts(propCounts, queryProps)
		end
	end

	return compositions
end

-- Takes a scene-query composition snapshot.
function ConquestScene.QueryCompositionSnapshot(queryIntervalSeconds)
	local queryProps = ConquestScene.QueryProps
	local intervalSeconds = queryIntervalSeconds or 5

	local sceneUnits = BotApi.Scene:QueryScene(queryProps, intervalSeconds)
	local compositions = ConquestScene.BuildCompositionByPlayer(sceneUnits, queryProps)

	return {
		sceneUnits = sceneUnits,
		queryProps = queryProps,
		compositions = compositions,
	}
end

-- Returns a compact debug string for one composition.
function ConquestScene.FormatCompositionSummary(composition)
	if not composition then
		return "none"
	end

	return "Infantry=" .. tostring(composition.Infantry or 0)
		.. " Crew=" .. tostring(composition.Crew or 0)
		.. " ATInfantry=" .. tostring(composition.ATInfantry or 0)
		.. " Armor=" .. tostring(composition.Armor or 0)
		.. " HeavyArmor=" .. tostring(composition.HeavyArmor or 0)
		.. " SuperHeavyArmor=" .. tostring(composition.SuperHeavyArmor or 0)
		.. " MachineGun=" .. tostring(composition.MachineGun or 0)
		.. " AutoCannon=" .. tostring(composition.AutoCannon or 0)
		.. " LightAT=" .. tostring(composition.LightAT or 0)
		.. " ATGun=" .. tostring(composition.ATGun or 0)
		.. " Flame=" .. tostring(composition.Flame or 0)
		.. " MediumHE=" .. tostring(composition.MediumHE or 0)
		.. " LargeHE=" .. tostring(composition.LargeHE or 0)
		.. " HE=" .. tostring(composition.HE or 0)
		.. " DirectFireThreat=" .. tostring(composition.DirectFireThreat or 0)
		.. " Engineer=" .. tostring(composition.Engineer or 0)
		.. " AmmoSupply=" .. tostring(composition.AmmoSupply or 0)
end