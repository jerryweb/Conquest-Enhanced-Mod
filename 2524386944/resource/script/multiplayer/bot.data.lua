MaxSquadSize = 22
OrderRotationPeriod = 1 * 60 * 1000 -- 2:30 min (ms)
SpawnCooldownTime = {
	Min = 1 * 500, -- 10 sec (ms) -- 20s
	Max = 2 * 500 -- 30 sec (mRs) -- 50s
}
UnitSpawnWaitTime = 1.0 * 500 -- 1 min (ms) -- 2:30mn
FlagPriority = { Captured = 2, Enemy = 1, Neutral = 3 } -- Was Captured =1, enemy = 2
FlagCaptureArea = {
	Infantry = 20,
	Captor = 30,
	Vehicle = 40,
	Helicopter = 3,
	ATgun = 80,
	Mortar = 100,
	Artillery = 200
}
UnitClass = {
	Infantry = "infantry",
	ATInfantry = "at-infantry",
	Vehicle = "vehicle",
	Tank = "tank",
	AATank = "aa-tank",
	ATTank = "at-tank",
	HeavyTank = "heavy-tank",
	ArtilleryTank = "artillery-tank",
}

Purchases = {}
LimitedPurchases={}
require([[/script/multiplayer/bot.data.purchase.standard]])
Purchases["ammunition"] = Purchases["standard"]
Purchases["battle_zones"] = Purchases["standard"]
Purchases["combined_arms"] = Purchases["standard"]
Purchases["koth"] = Purchases["standard"]
Purchases["evacuation"] = Purchases["standard"]




