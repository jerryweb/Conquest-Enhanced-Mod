-- Number of unit division roster files to randomly select for each period in the war 
local maxNumOfEarlyDivisions = 5
local maxNumOfMidDivisions = 5
local maxNumOfLateDivisions = 6

-- Wave offset is used to set how much extra time the first wave will last in since the wave is loaded automatically
local gameStartTime = 0
local firstWaveOffsetTime = 30
-- This is used to add the offset ONLY to the first wave
local initialWave = true

-- This variable controls whether units will spawn all at once for 15 seconds, creating a massive wave, every x seconds
local typhoonWaveMode = true
local nextTyphoonWaveTime = 0
local typhoonWaveInterval = 60
local typhoonWaveDuration = 15 
local defaultSpawnCooldownTime = {}

local currentWaveMaxUnitCount = 0

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
	-- divisionPurchaseModel = [[/script/multiplayer/bot.data.purchase.conquest.late.6]]
	

	return divisionPurchaseModel
end

function setNextTyphoonWaveTime() 
	nextTyphoonWaveTime = os.clock() + typhoonWaveInterval
end

function setTyphoonWaveMode()
	typhoonWaveMode = true
	SpawnCooldownTime.Min = 2
	SpawnCooldownTime.Max = 2
end

function disableTyphoonWaveMode()
	typhoonWaveMode = false
	SpawnCooldownTime.Min = defaultSpawnCooldownTime.Min
	SpawnCooldownTime.Max = defaultSpawnCooldownTime.Max
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

