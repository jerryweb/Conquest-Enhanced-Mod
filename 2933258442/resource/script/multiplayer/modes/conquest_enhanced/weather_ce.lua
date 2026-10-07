-- =========================================================
-- WEATHER FILE FOR CONQUEST ENHANCED
-- =========================================================

local weatherTimer = nil
local firstWeatherSet = false

-- Lua selects weather once per battle; the mission script applies the preset.
CEWeather = CEWeather or {}

CEWeather.Config = {
  Enabled = true,
  ApplyDelay = { min = 5 * 60 * 1000, max = 20 * 60 * 1000 },
  StrongWeatherChance = 0.5, -- Used only when strong_weather_enabled == 1.
}

-- season_set belongs to the map layer. Never infer the season from unit tags.
CEWeather.Seasons = { [1] = "spring", [2] = "summer", [3] = "autumn", [4] = "winter" }

-- BEGIN WEATHER PRESETS
-- Array position is weather_selection within the selected season and pool.
-- After editing these arrays, run tools/generate_weather_cases.py.
CEWeather.Presets = {
  spring = {
    regular = {
      "dynamic_campaign/spring/clear/morning_1",
      "dynamic_campaign/spring/clear/midday_1",
      "dynamic_campaign/spring/clear/evening_1",
      "dynamic_campaign/dcg_dunkirk/clear/morning_1",
      "dynamic_campaign/dcg_dunkirk/clear/midday_1",
      "dynamic_campaign/dcg_dunkirk/clear/evening_1",
    },
    strong = {
      "dynamic_campaign/spring/cloudy/morning_1",
      "dynamic_campaign/spring/cloudy/midday_1",
      "dynamic_campaign/spring/cloudy/evening_1",
      "dynamic_campaign/dcg_dunkirk/cloudy/morning_1",
      "dynamic_campaign/dcg_dunkirk/cloudy/midday_1",
      "dynamic_campaign/dcg_dunkirk/cloudy/evening_1",
    },
  },
  summer = {
    regular = {
      "dynamic_campaign/summer/clear/morning_01",
      "dynamic_campaign/summer/clear/midday_1",
      "dynamic_campaign/summer/clear/evening_01",
      "goh/west/wip/summer/night_1",
      "goh/west/wip/summer/night_2",
      "goh/west/wip/summer/sunset_1",
      "goh/west/wip/summer/sunrise_1",
      "goh/west/wip/summer/sunrise_2",
      "goh/west/wip/summer/day_1",
      "goh/west/wip/summer/day_2",
      "goh/west/wip/summer/day_3",
      "goh/west/wip/summer/day_clear_1",
    },
    strong = {
      "dynamic_campaign/summer/cloudy/morning_01",
      "dynamic_campaign/summer/cloudy/midday_1",
      "dynamic_campaign/summer/cloudy/evening_01",
      "goh/west/wip/summer/day_clear_2_rain",
      "goh/west/wip/summer/day_rain_1_b",
      "goh/west/wip/summer/day_rain_4",
      "goh/west/wip/summer/day_rain_5",
      "goh/west/wip/summer/sunset_rain_1",
      "ce_weather/summer/heavy_rain",
      "ce_weather/summer/thunderstorm",
    },
  },
  autumn = {
    regular = {
      "dynamic_campaign/autumn/clear/morning_1",
      "dynamic_campaign/autumn/clear/midday_1",
      "dynamic_campaign/autumn/clear/midday_1b",
      "dynamic_campaign/autumn/clear/evening_1",
      "goh/west/wip/autumn/day_clear_1",
      "goh/west/wip/autumn/day_clear_2",
      "goh/west/wip/autumn/day_clear_3",
      "goh/west/wip/autumn/day_cloudy_1",
      "goh/west/wip/autumn/day_cloudy_2",
      "goh/west/wip/autumn/evening_1",
      "goh/west/wip/autumn/night_1",
      "goh/west/wip/autumn/night_3",
    },
    strong = {
      "dynamic_campaign/autumn/cloudy/morning_1",
      "dynamic_campaign/autumn/cloudy/midday_1",
      "dynamic_campaign/autumn/cloudy/midday_1b",
      "dynamic_campaign/autumn/cloudy/midday_2",
      "dynamic_campaign/autumn/cloudy/evening_1",
      "goh/west/wip/autumn/day_rain_2",
    },
  },
  winter = {
    regular = {
      "dynamic_campaign/winter/clear/morning_1",
      "dynamic_campaign/winter/clear/midday_1",
      "dynamic_campaign/winter/clear/midday_2",
      "dynamic_campaign/winter/clear/midday_2b",
      "dynamic_campaign/winter/clear/evening_01",
      "dynamic_campaign/winter/cloudy/morning_1",
      "dynamic_campaign/winter/cloudy/midday_1",
      "dynamic_campaign/winter/cloudy/midday_1a",
      "dynamic_campaign/winter/cloudy/midday_1b",
      "dynamic_campaign/winter/cloudy/evening_01",
      "dynamic_campaign/winter/foggy/foggy_1",
      "dynamic_campaign/winter/foggy/foggy_2",
      "dynamic_campaign/winter/foggy/foggy_3",
      "goh/west/wip/winter/night_1",
      "goh/west/wip/winter/night_2",
      "goh/west/wip/winter/day_clear_1",
      "goh/west/wip/winter/day_clear_2",
      "goh/west/wip/winter/day_snow_1",
      "goh/west/wip/winter/day_snow_2",
      "goh/west/wip/winter/day_snow_3",
    },
    strong = {
      "goh/west/wip/winter/day_blizzard_1",
      "goh/west/wip/winter/day_blizzard_2",
      "goh/multi/2v2_blizzard/var1",
      "goh/single/01-fin/1940_01_raate_road/blizzard",
      "goh/single/01-ger/1942_09_elbrus/01_storm",
      "goh/single/1942_01_vyazma/storm",
    },
  },
}
-- END WEATHER PRESETS

-- Derived counts cannot select beyond the corresponding array.
CEWeather.MaxWeatherOptions = {}
for season, pools in pairs(CEWeather.Presets) do
  CEWeather.MaxWeatherOptions[season] = { regular = #pools.regular, strong = #pools.strong }
end


function KillDynamicWeatherTimer()
  if weatherTimer then
    BotApi.Events:KillQuantTimer(weatherTimer)
    weatherTimer = nil
  end
end

function CEWeather.Start()
  SetDynamicWeatherVars()
  SetDynamicWeatherTimer()
end

-- Reads the map's current settings at the moment a change is due.
function SetDynamicWeatherVars()
  if BotApi.Scene:GetVar("weather_change_pending") == 1 then return end
  local seasonId = BotApi.Scene:GetVar("season_set")
  local season = CEWeather.Seasons[seasonId]
  local pools = season and CEWeather.Presets[season]


  if not pools then return end

  local strong = math.random() < CEWeather.Config.StrongWeatherChance and firstWeatherSet
  local poolName = strong and "strong" or "regular"
  local pool = pools[poolName]

  if #pool == 0 then return end

  local selection = math.random(1, #pool)

  -- Publish the complete request before raising the mission-layer ready flag.
  BotApi.Scene:SetVar("weather_season", seasonId)
  BotApi.Scene:SetVar("weather_selection", selection)
  BotApi.Scene:SetVar("weather_pool_selected", strong and 1 or 0)
  if firstWeatherSet then
    BotApi.Scene:SetVar("weather_change_pending", 1)
  end
  KillDynamicWeatherTimer()
  if printDebug then
    print("Print: CE weather selected", season, poolName, selection, pool[selection])
  end
  firstWeatherSet = true
  return
end

function SetDynamicWeatherTimer()
  -- if changePublished or weatherTimer or not active or not CEWeather.Config.Enabled or BattleEnded() then return end
  if not CEWeather.Config.Enabled then return end

  local season = CEWeather.Seasons[BotApi.Scene:GetVar("season_set")]
  if not season then return end
  if BotApi.Scene:GetVar("weather_change_pending") == 1 then return end
  local delay = math.random(CEWeather.Config.ApplyDelay.min, CEWeather.Config.ApplyDelay.max)
  weatherTimer = BotApi.Events:SetQuantTimer(function()
    weatherTimer = nil -- Quant timers are one-shot, as in the existing spawn timers.
    SetDynamicWeatherVars()
  end, delay)
  if printDebug then print("Print: CE weather single change in seconds", delay / 1000) end
end