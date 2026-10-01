-- =========================================================
-- ORDERS FILE FOR CONQUEST ENHANCED
-- =========================================================
local generalSquadTagCheckDelay = 10 * 1000 -- 10 seconds
local SQUAD_TAG_ALWAYS_IGNORE = "_lua_always_ignore"
local SQUAD_TAG_NEED_NEXT_ORDER = "_lua_need_next_order"

-- =================== Check Squad Tags ==================
function IsSquadToAlwaysIgnore(squad)
  return BotApi.Scene:IsSquadTagged(squad, SQUAD_TAG_ALWAYS_IGNORE)
end

function IsSquadNeedNextOrder(squad)
  return BotApi.Scene:IsSquadTagged(squad, SQUAD_TAG_NEED_NEXT_ORDER)
end

function SetGeneralSquadTagCheckTimer()
  local setTagCheckTimer
  setTagCheckTimer = function(callback)
    Context.GeneralSquadTagCheckTimer = BotApi.Events:SetQuantTimer(
      function()
        Context.GeneralSquadTagCheckTimer = nil
        for _, squad in pairs(BotApi.Scene.Squads) do
          if IsSquadNeedNextOrder(squad) then
            if printDebug then print("squad ", squad, " getting next order") end
            Context.SquadTimers[squad] = nil
          end
        end
        callback(callback)
      end, generalSquadTagCheckDelay)
  end
  setTagCheckTimer(setTagCheckTimer)
end

function KillGeneralSquadTagCheckTimer()
  if Context.GeneralSquadTagCheckTimer then 
    BotApi.Events:KillQuantTimer(Context.GeneralSquadTagCheckTimer)
    Context.GeneralSquadTagCheckTimer = nil
  end
end