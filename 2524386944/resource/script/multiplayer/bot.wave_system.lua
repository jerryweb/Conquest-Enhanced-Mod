require([[/script/multiplayer/bot.data]])

-- This enables early testing so that units come 30 seconds after start. 
testing = true
verbose = false

-- Number of unit division roster files to randomly select for each period in the war 
maxNumOfEarlyDivisions = 5
maxNumOfMidDivisions = 6
maxNumOfLateDivisions = 7
firstWaveOffsetTime  = 720

-- Wave offset is used to set how much extra time the first wave will last in since the wave is loaded automatically
gameStartTime = os.clock()

if testing then
	firstWaveOffsetTime = 90
end 

-- This is used to add the offset ONLY to the first wave
initialWave = true

-- This variable controls whether units will spawn all at once for 15 seconds, creating a massive wave, every x seconds
typhoonWaveMode = true
nextTyphoonWaveTime = 0
typhoonWaveInterval = 90
typhoonWaveDuration = 25

-- This controls whether typhoon wave mode can turn on or off dynamically ingame
typhoonWaveModeInGameToggle = false
-- This is the interval at which the typhoon wave mode can toggle on or off during a game
typhoonWaveToggleInterval = 300
-- Next movment at ingame time at which a chance to toggle typhoon wave mode
nextTyphoonWaveToggleTime = 0


defaultSpawnCooldownTime = {}

currentWaveMaxUnitCount = 0

function verbosePrinting( verbose, printString )
	if verbose then
		print(printString)
	end
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
	if testing then
		-- divisionPurchaseModel = [[/script/multiplayer/bot.data.purchase.conquest.late.7]]
	end


	return divisionPurchaseModel
end

function setFirstWaveOffset( flags )
	local switch = {
		[1] = function()
			firstWaveOffsetTime = 480
		end,
		[2] = function()
			firstWaveOffsetTime = 1200
		end,
		[3] = function()
			firstWaveOffsetTime = 720
		end,
		[4] = function()
			firstWaveOffsetTime = 1500
		end,
		[5] = function()
			firstWaveOffsetTime = 900
		end
	}

	local f = switch[flags]

	if(f) then
		f()
	else
	   	firstWaveOffsetTime = 720
	end

	if testing then
		firstWaveOffsetTime = 90
	end 

	return firstWaveOffsetTime
end

function setNextTyphoonWaveTime() 
	nextTyphoonWaveTime = os.clock() + typhoonWaveInterval
end

function setTyphoonWaveMode()
	typhoonWaveMode = true
	SpawnCooldownTime.Min = 2
	SpawnCooldownTime.Max = 2
	print("typhoon wave mode activated")
end

function  activateToggleTyphoonWaveMode()
	
	typhoonWaveModeInGameToggle = true
	print("typhoonWaveMode in game toggle on")
	
end

function disableTyphoonWaveMode()
	typhoonWaveMode = false
	SpawnCooldownTime.Min = defaultSpawnCooldownTime.Min
	SpawnCooldownTime.Max = defaultSpawnCooldownTime.Max
	print("typhoon wave mode deactivated")
end

PIter = {}
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
		unlockedUnits = nil,
		isHeavyArty = false,
		isMortar = false
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

function PIter:nextIndex()

	-- self.idx = next(self.purchases, self.idx)

	-- if not self.idx then
	-- 	self.idx = 1
	-- end
	-- self.nextValidWave()
	if verbose then
		print("finding next valid wave")
	end
	local availableUnits = {}

	-- Find the next wave that has at least 1 unlocked unit to buy
	while #availableUnits == 0 do

		self.idx = next(self.purchases, self.idx)

		if not self.idx then
			self.idx = 1
		end

		if verbose then
			print("wave ", self.idx)
		end 
		local potentialUnits = self.purchases[self.idx].Units[BotApi.Instance.army]
		
		if verbose then
			print("Finding unlocked units for this wave")
		end
		
		for i, unit in pairs(potentialUnits) do
			if BotApi.Commands:IsUnitAvailable(unit.unit) then
				if verbose then
					print("Adding ", unit.unit, " to available units")
				end
				table.insert(availableUnits, unit)
			else 
				if verbose then
					print(unit.unit, " is not yet available to the AI")
				end
			end
		end
		
		if #availableUnits == 0 then
			if verbose then
				print("wave ", self.idx, " has no available units")
			end
		end
	end	


	--print("number of available units for wave ", self.idx, ": ", #availableUnits)
	
	self.unlockedUnits = availableUnits

	
	if verbose then
		print("grabbing wave number: ", self.purchases[self.idx].waveNumber)
	end

	self.waveStartTime = os.clock()
	
	if self.purchases[self.idx].minRepeat and self.purchases[self.idx].maxRepeat then 
		self.rpt = math.random(self.purchases[self.idx].minRepeat, self.purchases[self.idx].maxRepeat)
	else 
		self.rpt = self.purchases[self.idx].Repeat
	end

	if verbose then
			print("Min number of squads for this wave: ", self.rpt)
	end


	if self.purchases[self.idx].maxRepeat then
		currentWaveMaxUnitCount = self.purchases[self.idx].maxRepeat
	else 
		currentWaveMaxUnitCount = self.rpt
	end	

	

	if verbose then
		print("Max number of squads for this wave: ", self.rpt)
	end

	if typhoonWaveMode then 
		self.waveDuration = 3
	else
		self.waveDuration = self.purchases[self.idx].waveDuration
	end 

	if initialWave then 
		self.waveDuration = self.waveDuration + firstWaveOffsetTime
		initialWave = false
		print("OS time: ", os.clock()) 
		print("Initial wave offset: ", firstWaveOffsetTime)
	end

	if self.purchases[self.idx].isHeavyArty then 
		if verbose then
			print("setting ", self.purchases[self.idx].isHeavyArty)
		end
		self.isHeavyArty = self.purchases[self.idx].isHeavyArty
	else
		self.isHeavyArty = false
	end

	if self.purchases[self.idx].isMortar then 
		print("setting mortar ", self.purchases[self.idx].isMortar)
		self.isMortar = self.purchases[self.idx].isMortar
	else
		self.isMortar = false
	end
	
	if verbose then
		print("waveStartTime:", self.waveStartTime)
		print("waveDuration: ", self.waveDuration)
		print("time when current wave is over: ", self.waveDuration + self.waveStartTime)
	end

end

function PIter:moveNext()
	if initialWave and os.clock() < (firstWaveOffsetTime + self.waveStartTime) then
		return
	end

	if self.rpt > 0 then
		self.rpt = self.rpt - 1
		if verbose then
			print("Repeat attempts left for wave: ", self.rpt)			
		end
	end

	if self.rpt == 0 then
		if typhoonWaveMode then
			if os.clock() > (3 + self.waveStartTime) then
				if verbose then
					print("Ready for next typhoon wave")		
				end
				self:nextIndex()
			end
		elseif os.clock() > (self.waveDuration + self.waveStartTime) then
			if verbose then
				print("Ready for next wave")		
			end
			self:nextIndex()
		end
	end
end

