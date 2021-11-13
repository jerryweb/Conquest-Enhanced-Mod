{Hard
	{GlobalMaxCP 1900}
	{StageCP 100 120 150 180 200}
	{SpecialCP 1001}					;// airstrikes special tab
	{EmplacementCP 50}				;// buildable with engineer
	{Bots
		{StartMP	0.05 min 3000 attackerMultiplier 4.0}
		{FinishMP	1.25 attackerMultiplier 5.5}
		{CP
			{Base "0:0,20:0,720:10,740:10,900:0,1080:10,1300:10,1500:10,1800:0,2200:10"} ;// seconds : CP
			{RoundMultiplier "0:0.1 1:0.5 2:0.6 3:0.6 5:0.8 7:0.9 8:0.9 10:1.0 12:1.2 14:1.2 16:1.2 19:1.3"} ;// games played : multiplier for CP
			{AttackMultiplier 5.0}
		}
		{DefenseLevel
			{level_1
				{DefenseBudgetPlayer	3.5}	;// budget it multiplied by number of flags
				{DefenseBudgetAI		3.5}	;// places defender units with bot StartMP * this factor (StartMP without attackermultiplier) for player side
				{unlock games 0 progress 0.0}	;// number of games to unlock this level, or progress in percent (campaign progress bar)
			}
			{level_2							;// once level is reached previous level values are ignored only currently level is used
				{DefenseBudgetPlayer	200.0}
				{DefenseBudgetAI		200.0}
				{unlock games 4 progress 0.4}
			}
			{level_3
				{DefenseBudgetPlayer	404.5}
				{DefenseBudgetAI		444.5}
				{unlock games 12 progress 0.75}
			}
		}
	}
	{PaybackFactor 0.4}		;// MP paid back when loosing solider, squad or vehicle
	{SellFactor 0.7}
	{ScavengedVehicleSellFactor 0.5}		;// captured enemy vehicle 
	{RiskFactor
		{Low
			{BotResources 5.0}
			{BotVeterancy 0}
			{Rewards 1.0}
		}
		{Standard
			{BotResources 6.0}
			{BotVeterancy 2}
			{Rewards 1.5}
		}
		{High
			{BotResources 7.0}
			{BotVeterancy 3}
			{Rewards 1.75}
		}
	}
	{Resources
		{Standard
			{MP ;// Manpower (generic money)
				{StartVal 4000}
				{WinGain "1:200 4:300 6:700 8:900 10:1000 12:1400 14:1700"} ;// games played : MP gain 
				{LoseGain "1:150"}
				{MapRewards	;//Bonus resources on various game types (a game can only be one randomly chosen type). Types: Airfield, Ammodepot, Bonus, Factory, Research.
					{Airfield	1200}
					{Ammodepot	200}
					{Bonus		1000}
					{Factory	500}
					{Research	200}
				}
			}
			{SP ;// Special Points (airstrikes)
				{StartVal 0}
				{WinGain 0}
				{LoseGain 0}
				{MapRewards
					{Airfield	15}
				}
			}
			{AP ;// Ammo points
				{StartVal 2500}
				{WinGain "5:100 10:200 15:300"}
				{LoseGain "1:200"}
				{MapRewards
					{Ammodepot	1500}
					{Factory	1000}
				}
			}
			{RP ;// Research points
				{StartVal 8}
				{WinGain 1.5}
				{LoseGain 1}
				{MapRewards
					{Bonus		1}
					{Research	3}
				}
			}
			{Budget
				{Start "0:0 4:0 8:0 12:0 16:0 20:0"} ;// games played : starting CP of each match 
				{PointsPerSecond 13.95} ;// CP income
				{Limit 1001} ;// Max CP 
			}
		}
	}
	{Duration
		{Short
			{FlagCount "2:5 2:5 2:5 2:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 5:5 5:5 5:5 5:5 5:5 4:5 4:5 5:5 4:5 5:5 4:5 4:5 5:5 4:5 4:5 5:5"}
			{Bots
				{ResearchStages "0:1 1:1 2:2 3:4 4:4 5:5 6:5 7:6 8:6 9:6 10:7 11:7 12:7 13:8 14:9 14:10 15:11 16:12 16:13"} ;// number of games played : research tree level bots can have
			}
			{MapSelection "0:1"}	;// number of games played : map selection value from map .info file
			{MapBorder "0:1"}
		}
		{Normal
			{FlagCount "2:5 2:5 2:5 2:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 5:5 5:5 5:5 5:5 5:5 4:5 4:5 5:5 4:5 5:5 4:5 4:5 5:5 4:5 4:5 5:5"}
			{Bots
				{ResearchStages "0:1 1:1 2:2 3:4 4:4 5:5 6:5 7:6 8:6 9:6 10:7 11:7 12:7 13:8 14:9 14:10 15:11 16:12 16:13"}
			}
			{MapSelection "0:1"}
			{MapBorder "0:1"}
		}
		{Long
			{FlagCount "2:5 2:5 2:5 2:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 5:5 5:5 5:5 5:5 5:5 4:5 4:5 5:5 4:5 5:5 4:5 4:5 5:5 4:5 4:5 5:5"}
			{Bots
				{ResearchStages "0:1 1:1 2:2 3:4 4:4 5:5 6:5 7:6 8:6 9:6 10:7 11:7 12:7 13:8 14:9 14:10 15:11 16:12 16:13"}
			}
			{MapSelection "0:1"}
			{MapBorder "0:1"}
		}
		{VeryLong
			{FlagCount "2:5 2:5 2:5 2:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 5:5 5:5 5:5 5:5 5:5 4:5 4:5 5:5 4:5 5:5 4:5 4:5 5:5 4:5 4:5 5:5"}
			{Bots
				{ResearchStages "0:1 1:1 2:2 3:4 4:4 5:5 6:5 7:6 8:6 9:6 10:7 11:7 12:7 13:8 14:9 14:10 15:11 16:12 16:13"}
			}
			{MapSelection "0:1"}
			{MapBorder "0:1"}
		}
		{Unlimited
			{FlagCount "2:5 2:5 2:5 2:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 5:5 5:5 5:5 5:5 5:5 4:5 4:5 5:5 4:5 5:5 4:5 4:5 5:5 4:5 4:5 5:5"}
			{Bots
				{ResearchStages "0:1 1:1 2:2 3:4 4:4 5:5 6:5 7:6 8:6 9:6 10:7 11:7 12:7 13:8 14:9 14:10 15:11 16:12 16:13"}
			}
			{MapSelection "0:1"}
			{MapBorder "0:1"}
		}
	}
}