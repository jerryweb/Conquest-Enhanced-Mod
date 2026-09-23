-- =========================================================
-- RUNTIME STATE
-- =========================================================
-- Mutable battle state for Conquest AI behavior.

ConquestState = ConquestState or {}

ConquestState.botDefender = nil
ConquestState.firstPurchase = true

-- SpawnAt state. Normal purchases use one round-robin counter.
-- Defender-opening garrison purchases use separate placement-class.
ConquestState.spawnPointIndex = 0
ConquestState.defenderOpeningFlagCount = 1
ConquestState.garrisonSpawnPointIndexByPlacementClass = {}

-- Generic purchase phase state.
-- phasePurchaseCount is spent force budget, not raw purchase count.
ConquestState.purchasePhase = nil
ConquestState.phasePurchaseCount = 0
ConquestState.phasePurchaseTarget = 0


-- Battle-local purchase force identity.
ConquestState.primaryForce = nil
ConquestState.secondaryForce = nil

-- Active slot-budget purchase plan for the current finite purchase phase.
ConquestState.purchasePlan = nil
ConquestState.pendingPurchaseForceCost = 1.0
ConquestState.pendingPurchaseLane = nil
-- Selected unit metadata retained until spawn placement and purchase commit finish.
ConquestState.pendingPurchaseUnit = nil

-- Attacker wave state.
ConquestState.waveSpawnActive = true
ConquestState.waveNumber = 0
ConquestState.waveUnitTotal = 0
ConquestState.attackerWaveIntent = nil
ConquestState.attackerWaveTargetFlagName = nil
ConquestState.attackerFlagTargetOrder = nil
ConquestState.attackerFlagTargetOrderIndex = 1

-- Attacker wave-count state.
ConquestState.attackerMaxWaves = 0
ConquestState.attackerWavesFinished = false

-- Attacker dynamic wave-off state.
ConquestState.attackerPreWaveSnapshot = nil
ConquestState.attackerPostWaveSnapshot = nil
ConquestState.attackerWaveOffElapsedSeconds = 0
ConquestState.attackerWaveOffTargetSeconds = 0
ConquestState.attackerWaveOffVarianceSeconds = 0
ConquestState.attackerWaveOffPlayerPeakComposition = nil
ConquestState.attackerWaveOffReleaseReady = false

-- Post-final-wave attacker failure watcher state.
ConquestState.attackerFailureArmed = false
ConquestState.attackerFailureElapsedSeconds = 0
ConquestState.attackerFailureCheckCount = 0

-- Defender finite-purchase state.
ConquestState.defenderOpeningFinished = false

-- Failsafe for the defender bot spawning troops after the garrison stage (may break if I use defenderOpeningFinished)
ConquestState.defenderOpeningExpired = false

-- Defender opening squads that should never enter Lua movement rotation.
ConquestState.garrisonSquads = {}
ConquestState.defenderOpeningHoldRegistrationActive = false
ConquestState.defenderOpeningGarrisonReadyPending = false
ConquestState.defenderOpeningGarrisonReadyFailsafeWarning = false

-- Defender counterattack trigger state.
ConquestState.flagOwners = {}
ConquestState.counterattackPendingByFlag = {}
ConquestState.counterattackFlagName = nil
ConquestState.totalCounterattacksStarted = 0
ConquestState.counterattacksByFlag = {}

-- Latest scene snapshot captured when a defender counterattack purchase plan starts.
ConquestState.defenderCounterattackSnapshot = nil

-- Match-local force memory built from existing scene snapshots.
ConquestState.playerSceneMemory = nil
ConquestState.botSceneMemory = nil
