require([[/script/multiplayer/bot.data]])
require([[/script/multiplayer/bot.wave_system]])

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
		-- print("flag name: ", flag.name)
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

function OnGameStart()
	math.randomseed(os.time()*BotApi.Instance.hostId)
	math.random() math.random() math.random() math.random()

	if math.random() < 0.3 then -- 30% chance to change when enemy reinforcements spawn 
		firstWaveOffsetTime = math.random(480,780)
	end
	if math.random() < 0.5 then -- 50% chance to for typhoon wave mode 
		setTyphoonWaveMode()
	end
-- 
	gameStartTime = os.clock()
	print("first enemy wave will start at ", gameStartTime + firstWaveOffsetTime)
	nextTyphoonWaveTime = gameStartTime + firstWaveOffsetTime
	nextTyphoonWaveToggleTime = gameStartTime + typhoonWaveToggleInterval + firstWaveOffsetTime
	print("Next typhoon wave toggle time will start at ", gameStartTime + firstWaveOffsetTime)



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
		print("flag name: ", flag.name)
		totalFlags = totalFlags + 1
	end

	-- for j, mapPoint in pairs(BotApi.Scene.Spawns) do 
	-- 	print("map point name: ", mapPoint.name)
	-- end
	
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
	    defaultSpawnCooldownTime = SpawnCooldownTime

	    if typhoonWaveMode then
	    	 setTyphoonWaveMode()
	    end
	    
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
	collectgarbage("collect")
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
		-- print(unit, "not available, player#" .. BotApi.Instance.playerId)
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
		-- print("can't spawn ", unit, ", max number of squads for this wave reached")
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

	if typhoonWaveModeInGameToggle then
		if os.clock() > nextTyphoonWaveToggleTime then
			if math.random() < 0.5 then 
				print("Flipping typhoon wave mode")
				if typhoonWaveMode then
					disableTyphoonWaveMode()
				else
					setTyphoonWaveMode()
				end
			end
			nextTyphoonWaveToggleTime = os.clock() + typhoonWaveToggleInterval
		end 
	end

	if os.clock() > (gameStartTime + firstWaveOffsetTime) then
		if typhoonWaveMode then
			if os.clock() > nextTyphoonWaveTime then
				TrySpawnUnit()
				if os.clock() > nextTyphoonWaveTime + typhoonWaveDuration then
					setNextTyphoonWaveTime()
				end
			end
		else 
			TrySpawnUnit()
		end
	end

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
	-- print("spawned squad id: ", tostring(args.squadId))

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
