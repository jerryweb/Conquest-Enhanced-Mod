-- =========================================================
-- ORDERS FLAGS FILE FOR CONQUEST ENHANCED
-- =========================================================
local ATTACKER_TARGET_FLAG_VAR = "attacker_target_flag"

-- Sets the wave target and publishes it to the mission layer.
-- flag = a flag entry from the flags list, or nil to clear the target.
function SetAttackerWaveTargetFlag(flag)
  ConquestState.attackerWaveTargetFlagName = flag and flag.name or nil
  if printDebug then print("Wave will target flag ", ConquestState.attackerWaveTargetFlagName) end 
  BotApi.Scene:SetVar(ATTACKER_TARGET_FLAG_VAR, flag and flag.id or 0)
end