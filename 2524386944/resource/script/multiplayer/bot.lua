require([[/script/multiplayer/bot.data]])

-- Number of unit division roster files to randomly select for each period in the war 
local maxNumOfEarlyDivisions = 5
local maxNumOfMidDivisions = 5
local maxNumOfLateDivisions = 5

-- Wave offset is used to set how much extra time the first wave will last in since the wave is loaded automatically
local firstWaveOffsetTime = 720
-- This is used to add the offset ONLY to the first wave
local initialWave = true

local currentWaveMaxUnitCount = 0

local squadDictionary = {}

local Context = {
	Purchase = nil,
	SpawnInfo = nil,
	SpawnWait = {
		CooldownTimer = nil,
		WaitTimer = nil
	},
	SquadTimers = {}
}

function SetSpawnCooldownTimer()
	Context.SpawnWait.CooldownTimer = BotApi.Events:SetQuantTimer(
		function()
			Context.SpawnWait.CooldownTimer = nil
		end,
		math.random(SpawnCooldownTime.Min, SpawnCooldownTime.Max))
end

function KillSpawnCooldownTimer()
	if Context.SpawnWait.CooldownTimer then
		BotApi.Events:KillQuantTimer(Context.SpawnWait.CooldownTimer)
		Context.SpawnWait.CooldownTimer = nil
	end
end

function KillSpawnWaitTimer()
	if Context.SpawnWait.WaitTimer then
		BotApi.Events:KillQuantTimer(Context.SpawnWait.WaitTimer)
		Context.SpawnWait.WaitTimer = nil
	end
end

local PIter = {}
PIter.__index = PIter

function PIter:new(data)
	local obj = {
		idx = nil,
		rpt = nil,
		purchases = data,
		skipped = false,
		minRepeat = 0,
		maxRepeat = 0,
		waveDuration = nil,
		waveStartTime = nil,
		unlockedUnits = nil
	}
	
	print("loading division: ", obj.purchases[1].divisionName)
	self.nextIndex(obj)

	return setmetatable(obj, self)
end

function PIter:current()
	if self.idx then
		return self.purchases[self.idx].Units
	end
end

-- function PIter:nextValidWave()
-- 	print("finding next valid wave")
-- 	local availableUnits = {}

-- 	while #availableUnits == 0 do
-- 		if not self.idx then
-- 			self.idx = 1
-- 		end
		
-- 		local potentialUnits = self.purchases[self.idx].Units[BotApi.Instance.army]
-- 		print("Finding unlocked units for this wave")
-- 		-- if not self.unlockedUnits then
-- 		for i, unit in pairs(potentialUnits) do
-- 			if BotApi.Commands:IsUnitAvailable(unit.unit) then
-- 				print("Adding ", unit.unit, " to available units")
-- 				table.insert(availableUnits, unit)
-- 			else 
-- 				print(unit.unit, " is not yet available to the AI")
-- 			end
-- 		end
		
-- 		if #availableUnits > 0 then
-- 			break
-- 		end

-- 		print("wave ", self.idx, " has no available units")
-- 		self.idx = next(self.purchases, self.idx)
-- 	end	

-- 	print("number of available units for wave ", self.idx, ": ", #availableUnits)
-- 	self.unlockedUnits = availableUnits


-- 	-- return self
-- end

function PIter:nextIndex()

	-- self.idx = next(self.purchases, self.idx)

	-- if not self.idx then
	-- 	self.idx = 1
	-- end
	-- self.nextValidWave()
	print("finding next valid wave")
	local availableUnits = {}

	-- Find the next wave that has at least 1 unlocked unit to buy
	while #availableUnits == 0 do

		self.idx = next(self.purchases, self.idx)

		if not self.idx then
			self.idx = 1
		end

		print("wave ", self.idx)
		
		local potentialUnits = self.purchases[self.idx].Units[BotApi.Instance.army]
		print("Finding unlocked units for this wave")

		for i, unit in pairs(potentialUnits) do
			if BotApi.Commands:IsUnitAvailable(unit.unit) then
				print("Adding ", unit.unit, " to available units")
				table.insert(availableUnits, unit)
			else 
				print(unit.unit, " is not yet available to the AI")
			end
		end
		
		if #availableUnits == 0 then
			print("wave ", self.idx, " has no available units")

		end
	end	

	print("number of available units for wave ", self.idx, ": ", #availableUnits)
	self.unlockedUnits = availableUnits

	print("grabbing wave number: ", self.purchases[self.idx].waveNumber)

	self.waveStartTime = os.clock()
	
	if self.purchases[self.idx].minRepeat and self.purchases[self.idx].maxRepeat then 
		self.rpt = math.random(self.purchases[self.idx].minRepeat, self.purchases[self.idx].maxRepeat)
	else 
		self.rpt = self.purchases[self.idx].Repeat
	end


	print("Min number of squads for this wave: ", self.rpt)

	if self.purchases[self.idx].maxRepeat then
		currentWaveMaxUnitCount = self.purchases[self.idx].maxRepeat
	else 
		currentWaveMaxUnitCount = self.rpt
	end	

	print("Max number of squads for this wave: ", self.rpt)

	self.waveDuration = self.purchases[self.idx].waveDuration

	if initialWave then 
		self.waveDuration = self.waveDuration + firstWaveOffsetTime
		initialWave = false
		print("OS time: ", os.clock()) 
		print("Initial wave offset: ", firstWaveOffsetTime)
	end

	print("waveStartTime:", self.waveStartTime)
	print("waveDuration: ", self.waveDuration)
	print("time when current wave is over: ", self.waveDuration + self.waveStartTime)
end

function PIter:moveNext()
	if initialWave and os.clock() < (firstWaveOffsetTime + self.waveStartTime) then
		return
	end

	if self.rpt > 0 then
		self.rpt = self.rpt - 1
		print("Repeat attempts left for wave: ", self.rpt)
	end

	if self.rpt == 0 then
		if os.clock() > (self.waveDuration + self.waveStartTime) then
			print("Ready for next wave")
			self:nextIndex()
		end
	end
end

function GetRandomItem(items, getRate)
	local item_rates = {}
	
	local total = 0
	for i, item in pairs(items) do
		local rate = getRate(item)
		total = total + rate
		table.insert(item_rates, {i = item, r = rate})
	end
	
	local rnd = math.random()
	local bound = 0.0
	
	for j, item_rate in pairs(item_rates) do
		bound = bound + item_rate.r	
		if rnd < bound / total then
			return item_rate.i
		end
	end
end

function IsCapturedFlag(flag)
	return flag.occupant == BotApi.Instance.team
end

function IsEnemyFlag(flag)
	return flag.occupant == BotApi.Instance.enemyTeam
end

function GetFlagPriority(flag)
	if		IsCapturedFlag(flag)then return FlagPriority.Enemy
	elseif	IsEnemyFlag(flag)	then return FlagPriority.Enemy
	else 							 return FlagPriority.Neutral
	end
end

function GetFlagToCapture(flagPoints, getPriority)
	local flags = {}
	
	for i, flag in pairs(flagPoints) do
		print("flag name: ", flag.name)
		table.insert(flags, {name = flag.name, k = getPriority(flag)})
	end

	return GetRandomItem(flags, function(f) return f.k end)
end

function GetNextUnitToSpawn(purchase)
	-- local units = purchase:current()
	print("Grabbing unlocked units for wave: ", purchase.idx)
	local units = purchase.unlockedUnits
	
	if not units then
		print("wave ", purchase.idx, " has no available units")
		return nil
	end
	
	-- local unit = GetUnitToSpawn(units[BotApi.Instance.army])
	local unit = GetUnitToSpawn(units)
	purchase:moveNext()
	return unit
end

function GetUnitToSpawn(units)
	if not units then
		return nil
	end
	
	local unitsToSpawn = {}
	
	local teamSize = BotApi.Instance.teamSize
	local income = BotApi.Commands:Income(BotApi.Instance.playerId)

	for i, unit in pairs(units) do

		local min_income = unit.min_income
		local min_team = unit.min_team
		
		if not min_income then min_income = -1 end
		if not min_team then min_team = 0 end
		
		if teamSize >= min_team and income >= min_income then
			table.insert(unitsToSpawn, unit)
		end
		
	end
	
	if #unitsToSpawn == 0 then
		return nil
	end
	
	local capturedFlags, enemyFlags = 0, 0
	for i, flag in pairs(BotApi.Scene.Flags) do
		if IsCapturedFlag(flag) then
			capturedFlags = capturedFlags + 1
		end
		if IsEnemyFlag(flag) then
			enemyFlags = enemyFlags + 1
		end
	end
	
	if capturedFlags < enemyFlags then
		choice = 0.01
	elseif capturedFlags == enemyFlags then
		choice = 0.01
	else
		choice = 0.02	-- higher choice(0-1+rnd) = higher % of CaptureFlag(bots going for flags). Lower choice favors SeekAndDestroy.
	end
	
	local enemyHasTanks = BotApi.Commands:EnemyHasTanks();
	
	return GetRandomItem(unitsToSpawn, function(t)
		if capturedFlags <= enemyFlags and (t.class == UnitClass.Tank or
							                t.class == UnitClass.Infantry) then
			return t.priority * 2.0
		end
		
		if enemyHasInfantry and (t.class == UnitClass.Tank or
							    t.class == UnitClass.ArtilleryTank) then
			return t.priority * 1.5
		end
		
		if enemyHasTanks and (t.class == UnitClass.ATTank or
		                      t.class == UnitClass.Tank or
							  t.class == UnitClass.HeavyTank) then
			return t.priority * 2.0
		end
		return t.priority
	end)
end

function UpdateUnitToSpawn(purchase)
	Context.SpawnInfo = GetNextUnitToSpawn(purchase)
end

-- This selects which unit roster file to load given the total number of flags on the map
-- TODO: figure out how to extract the campaign day progress for more accurate file selection
function selectArmyDivision(totalFlags)

	local fileNumber = 1
	local divisionPurchaseModel = nil

	if totalFlags < 3 then
		fileNumber = math.random(1, maxNumOfEarlyDivisions)
		divisionPurchaseModel = [[/script/multiplayer/bot.data.purchase.conquest.early.]] .. fileNumber;
		print("selected early division number: ", fileNumber)
	
	elseif totalFlags == 3 then
		fileNumber = math.random(1, maxNumOfMidDivisions)
		divisionPurchaseModel = [[/script/multiplayer/bot.data.purchase.conquest.mid.]] .. fileNumber;
		print("selected mid division number: ", fileNumber)
	
	else
		fileNumber = math.random(1, maxNumOfLateDivisions)
		divisionPurchaseModel = [[/script/multiplayer/bot.data.purchase.conquest.late.]] .. fileNumber;
		print("selected late division number: ", fileNumber)
	end
	print("loading")
	-- REMOVE THIS LINE (ONLY FOR TESTING)
	-- divisionPurchaseModel = [[/script/multiplayer/bot.data.purchase.conquest.late.4]]
	

	return divisionPurchaseModel
end

function OnGameStart()
	math.randomseed(os.time()*BotApi.Instance.hostId)
	math.random() math.random() math.random() math.random()


	local purchasesModule = [[/script/multiplayer/bot.data.purchase.]] .. BotApi.Instance.gameMode;
	if module_exists(purchasesModule) then
		require(purchasesModule)
	end

	local purchases = Purchases[BotApi.Instance.gameMode];
	if not purchases then
		purchases = {}
	end
	
	local totalFlags = 0
	for i, flag in pairs(BotApi.Scene.Flags) do
		totalFlags = totalFlags + 1
	end
	
	print("Total flags detected:", totalFlags)

	if BotApi.Instance.gameMode == "campaign_capture_the_flag" then
		print("getting ready to load roster")
	    local divisionPurchases = {}
	    local counter = 0
	    local spawnMultiplier = 5 - totalFlags
		local purchaseModel = selectArmyDivision(totalFlags)

		if module_exists(purchaseModel) then
	      require(purchaseModel)
		  print("model loading")
	      divisionPurchases = Purchases["campaign_capture_the_flag"]
		  print("model loaded")
	    else
		print("model failed to load")
	      local limit = totalFlags + 1
	      for key, value in pairs(purchases) do
	        if counter < limit then
	          table.insert(divisionPurchases, value)
	          counter = counter + 1
	        end
	      end
	    end
	    
	    SpawnCooldownTime.Min = SpawnCooldownTime.Min * spawnMultiplier
	    SpawnCooldownTime.Max = SpawnCooldownTime.Max * spawnMultiplier
	    
	    print("Spawn multipliers (min, max):", SpawnCooldownTime.Min, SpawnCooldownTime.Max)
	    purchases = divisionPurchases
	end

	Context.Purchase = PIter:new(purchases)

	UpdateUnitToSpawn(Context.Purchase)
	SetSpawnCooldownTimer()

	-- print("BotApi.Commands properties:")
	-- print(BotApi.Commands)
	-- local count = 0
	-- for i, BotApi.Scene in pairs(metatable(BotApi.Scene)) do 
	-- 	print("stuffs ", i)
	-- 	-- count = count + 1
	-- 	-- print(i, "properties")
	-- 	-- for j, BotApi[1] in pairs(BotApi[count]) do
	-- 	-- 	print(j)
	-- 	-- end
	-- end
end

function OnGameStop()
	KillSpawnCooldownTimer()
	KillSpawnWaitTimer()

	for squad, timer in pairs(Context.SquadTimers) do
		if timer then
			BotApi.Events:KillQuantTimer(timer)
		end
	end
end

function TrySpawnUnit()
	if Context.SpawnWait.CooldownTimer then
		return
	end

	if not BotApi.Commands:CanSpawn() then
		return
	end
	
	if not Context.SpawnInfo then
		UpdateUnitToSpawn(Context.Purchase)
		return
	end

	local unit = Context.SpawnInfo.unit
	
	if not BotApi.Commands:IsUnitAvailable(unit) then
		print(unit, "not available, player#" .. BotApi.Instance.playerId)
		KillSpawnWaitTimer()
		UpdateUnitToSpawn(Context.Purchase)
		return
	end
	if currentWaveMaxUnitCount > 0 then
		if BotApi.Commands:Spawn(unit, MaxSquadSize) then
			currentWaveMaxUnitCount = currentWaveMaxUnitCount - 1
			KillSpawnWaitTimer()
			SetSpawnCooldownTimer()
			UpdateUnitToSpawn(Context.Purchase)
			return
		end
	else
		print("can't spawn ", unit, ", max number of squads for this wave reached")
		UpdateUnitToSpawn(Context.Purchase)
		return
	end 

	local tts = BotApi.Commands:TimeToSpawnUnit(unit)
	if tts > UnitSpawnWaitTime then
		print(unit, tts, "wait too long, player#" .. BotApi.Instance.playerId)
		KillSpawnWaitTimer()
		UpdateUnitToSpawn(Context.Purchase)
		return
	end

	if not Context.SpawnWait.WaitTimer then
		print(unit, tts, "set wait timer, player#" .. BotApi.Instance.playerId)
		Context.SpawnWait.WaitTimer = BotApi.Events:SetQuantTimer(
			function()
				Context.SpawnWait.WaitTimer = nil
				UpdateUnitToSpawn(Context.Purchase)
			end, UnitSpawnWaitTime + 1000)
	end
end

function OnGameQuant()
	TrySpawnUnit()
	local waypoints = BotApi.Scene.Waypoints

	if #waypoints == 0 then
		for i, squad in pairs(BotApi.Scene.Squads) do
			-- print("squad ", squad, " with unlock time = ", squadDictionary[squad])
			if squadDictionary[squad] and  squadDictionary[squad] <= os.clock() then
				if not Context.SquadTimers[squad] then
					SetSquadOrder(CaptureFlag, squad, OrderRotationPeriod)
				end
			end
			 if not squadDictionary[squad] then
			 	local squadOrderTime = math.random(180, 300)
			 	print("nil squad ", squad, " with unlock time = ", squadDictionary[squad])
				squadDictionary[squad] = os.clock() + squadOrderTime
			end
		end
	end


end

function SeekAndDestroy(squad)
	BotApi.Commands:SeekAndDestroy(squad)
end

function GotoNextWaypoint(squad)
	local waypoints = BotApi.Scene.Waypoints
	BotApi.Commands:CaptureFlag(squad, waypoints[math.random(#waypoints)]) --captureflag is basically gothereandattack
	print("#captureFlag call inside GoToNextWaypoint")
end

function OnWaypoint(args)
	print("#GotoNextWaypoint call inside OnWaypoint")
	GotoNextWaypoint(args.squadId)
end

function CaptureFlag(squad)
	local flag = GetFlagToCapture(BotApi.Scene.Flags, GetFlagPriority)
	-- local rnd = 0.1 + choice
	local rnd = math.random() + choice
	if flag then
		if rnd < 0.25 then
			print(rnd, "+SeekAndDestroy with squad", squad)
			BotApi.Commands:SeekAndDestroy(squad)
		else
			print(rnd, "+CaptureFlag with squad", squad)
			BotApi.Commands:CaptureFlag(squad, flag.name)
		end
	else
			print(rnd, "!SeekAndDestroy with squad", squad)
			BotApi.Commands:SeekAndDestroy(squad)
	end
end

function SetSquadOrder(order, squad, delay)
	order(squad)
	local setTimer = function(callback)
		Context.SquadTimers[squad] = BotApi.Events:SetQuantTimer(
			function()
				order(squad)
				Context.SquadTimers[squad] = nil
				if BotApi.Scene:IsSquadExists(squad) then
					callback(callback)
				end
			end,
			delay)
	end
	print("squad timer: ", Context.SquadTimers[squad] )
	setTimer(setTimer)--
end

function OnGameSpawn(args)
	local waypoints = BotApi.Scene.Waypoints

	for i, waypoints in pairs(waypoints) do
		print("points", i)
	end
	print("spawned squad id: ", tostring(args.squadId))

	local str = tostring(args.squadId)

	local squadOrderTime = math.random(240, 300)


	squadDictionary[args.squadId] = os.clock() + squadOrderTime
	-- print("squad time = ", squadDictionary[args.squadId])
	-- table.insert(squadDictionary, {squadid = args.squadId, unlockTime = os.clock + 10})

	-- if #waypoints == 0 then
	-- 	SetSquadOrder(CaptureFlag, args.squadId, OrderRotationPeriod)
	-- else
	-- 	GotoNextWaypoint(args.squadId)
	-- 	print("#waypoints != 0")
	-- end
end

BotApi.Events:Subscribe(BotApi.Events.GameStart, OnGameStart)
BotApi.Events:Subscribe(BotApi.Events.GameEnd, OnGameStop)
BotApi.Events:Subscribe(BotApi.Events.Quant, OnGameQuant)
BotApi.Events:Subscribe(BotApi.Events.GameSpawn, OnGameSpawn)
BotApi.Events:Subscribe(BotApi.Events.Waypoint, OnWaypoint)
