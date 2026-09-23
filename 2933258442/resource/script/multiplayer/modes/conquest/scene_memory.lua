-- =========================================================
-- SCENE MEMORY
-- =========================================================
-- Stores match-local scene snapshot memory without running extra scene queries.
-- Purchase selection does not consume this yet.

ConquestSceneMemory = ConquestSceneMemory or {}

local BOT_SCENE_MEMORY_KEY = "botSceneMemory"
local PLAYER_SCENE_MEMORY_KEY = "playerSceneMemory"

local SceneMemoryFieldOrder = {
	"infantry",
	"armor",
	"heavyArmor",
	"heWeapons",
	"antiArmor",
	"machineGun",
	"autoCannon",
	"lightAT",
	"atGun",
	"flame",
	"mediumHE",
	"largeHE",
	"directFire",
	"engineer",
	"ammoSupply",
}

local function Number(value)
	if type(value) ~= "number" then
		return 0
	end

	if value < 0 then
		return 0
	end

	return value
end

-- Builds compact match-local memory values from a scene composition.
function ConquestSceneMemory.BuildValues(composition)
	local c = composition or {}

	return {
		infantry = Number(c.Infantry),
		armor = Number(c.Armor),
		heavyArmor = Number(c.HeavyArmor) + Number(c.SuperHeavyArmor),
		heWeapons = Number(c.HE),
		antiArmor = Number(c.ATInfantry) + Number(c.LightAT) + Number(c.ATGun),
		machineGun = Number(c.MachineGun),
		autoCannon = Number(c.AutoCannon),
		lightAT = Number(c.LightAT),
		atGun = Number(c.ATGun),
		flame = Number(c.Flame),
		mediumHE = Number(c.MediumHE),
		largeHE = Number(c.LargeHE),
		directFire = Number(c.DirectFireThreat),
		engineer = Number(c.Engineer),
		ammoSupply = Number(c.AmmoSupply),
	}
end

local function CreateEmptyValues()
	return ConquestSceneMemory.BuildValues(nil)
end

local function EnsureMemory(stateFieldName)
	ConquestState[stateFieldName] = ConquestState[stateFieldName] or {
		latest = nil,
		peak = CreateEmptyValues(),
	}

	ConquestState[stateFieldName].peak = ConquestState[stateFieldName].peak or CreateEmptyValues()

	return ConquestState[stateFieldName]
end

local function UpdatePeak(peak, values)
	for _, fieldName in ipairs(SceneMemoryFieldOrder) do
		peak[fieldName] = math.max(peak[fieldName] or 0, values[fieldName] or 0)
	end
end

function ConquestSceneMemory.FormatValues(values)
	local v = values or {}
	local parts = {}

	for _, fieldName in ipairs(SceneMemoryFieldOrder) do
		parts[#parts + 1] = fieldName .. "=" .. tostring(v[fieldName] or 0)
	end

	return table.concat(parts, ",")
end

local function UpdateMemory(stateFieldName, source, composition)
	local memory = EnsureMemory(stateFieldName)
	local values = ConquestSceneMemory.BuildValues(composition)

	memory.latest = {
		source = source,
		values = values,
	}

	UpdatePeak(memory.peak, values)

	return memory, values
end

-- Updates bot and player scene memory from already-captured scene compositions.
function ConquestSceneMemory.Update(source, botComposition, playerComposition, printLine)
	local botMemory, botValues = UpdateMemory(BOT_SCENE_MEMORY_KEY, source, botComposition)
	local playerMemory, playerValues = UpdateMemory(PLAYER_SCENE_MEMORY_KEY, source, playerComposition)

	if printDebug and printLine then
		print(
			"Print: scene memory",
			"source=", source,
			"botLatest=", ConquestSceneMemory.FormatValues(botValues),
			"botPeak=", ConquestSceneMemory.FormatValues(botMemory.peak),
			"playerLatest=", ConquestSceneMemory.FormatValues(playerValues),
			"playerPeak=", ConquestSceneMemory.FormatValues(playerMemory.peak)
		)
	end

	return botMemory, playerMemory
end

function ConquestSceneMemory.GetBotMemory()
	return EnsureMemory(BOT_SCENE_MEMORY_KEY)
end

function ConquestSceneMemory.GetPlayerMemory()
	return EnsureMemory(PLAYER_SCENE_MEMORY_KEY)
end
