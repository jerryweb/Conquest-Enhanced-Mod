{Easy
	{GlobalMaxCP 1900}
	{StageCP 70 70 70 70 70 70 70}
	{SpecialCP 1001}					;// airstrikes special tab
	{EmplacementCP 50}				;// buildable with engineer
	{Bots
		{StartMP	0.05 min 2000 attackerMultiplier 14.0}
		{FinishMP	0.15 attackerMultiplier 55.5}
		{CP
			{Base "0:0,20:0,300:5,900:5,1080:5,1300:6,1500:5,1900:5,2100:6"} ;// seconds : CP
			{RoundMultiplier "0:0.2 1:0.5 2:0.5 3:0.6 4:0.6 5:0.7 6:0.7 7:0.8 8:1.0 9:1.0 10:1.0 19:1.0"} ;// games played : multiplier for CP
			{AttackMultiplier 6.0}
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
				{unlock games 14 progress 0.75}
			}
		}
	}
	{PaybackFactor 0.2}		;// MP paid back when loosing solider, squad or vehicle
	{SellFactor 0.7}
	{ScavengedVehicleSellFactor 0.5}		;// captured enemy vehicle 
	{RiskFactor
		{Low
			{BotResources 6.1}
			{BotVeterancy 0}
			{Rewards 1.0}
		}
		{Standard
			{BotResources 6.1}
			{BotVeterancy 2}
			{Rewards 1.5}
		}
		{High
			{BotResources 6.1}
			{BotVeterancy 4}
			{Rewards 2.00}
		}
	}
	{Resources
		{Standard
			{MP ;// Manpower (generic money)
				{StartVal 3500}
				{WinGain "1:200 4:200 6:300 8:400 10:500 12:800 14:1300"} ;// games played : MP gain 
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
				{WinGain "1:2 4:5 6:7 8:6 10:9 12:12 14:15"}
				{LoseGain 0}
				{MapRewards
					{Airfield	35}
				}
			}
			{AP ;// Ammo points
				{StartVal 2500}
				{WinGain "5:200 10:500 15:700"}
				{LoseGain "1:200"}
				{MapRewards
					{Ammodepot	2500}
					{Factory	1000}
				}
			}
			{RP ;// Research points
				{StartVal 12}
				{WinGain "1:2 4:5 6:4 10:5 15:6"}
				{LoseGain 1}
				{MapRewards
					{Bonus		1}
					{Research	3}
					{Factory	1}
				}
			}
			{Budget
				{Start "0:355 4:355 8:355 12:355 16:355 20:355"} ;// games played : starting CP of each match 
				{PointsPerSecond 0} ;// CP income
				{Limit 1001} ;// Max CP 
			}
		}
	}
	{Duration
		{Short
			{FlagCount "1:5 1:5 1:5 1:5 3:5 2:5 3:5 2:5 3:5 2:5 3:5 2:5 3:5 2:5 3:5 2:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5"}
			{Bots
				{ResearchStages "0:1 1:2 2:3 3:4 4:4 5:5 6:5 7:6 8:6 9:7 10:8 11:9 12:10 13:11 14:12 14:13 15:13 16:14 17:14 18:14 19:14 20:15 21:15"} ;// number of games played : research tree level bots can have
			}
			{MapSelection "0:1"}	;// number of games played : map selection value from map .info file
			{MapBorder "0:1"}
		}
		{Normal
			{FlagCount "1:5 1:5 1:5 1:5 3:5 2:5 3:5 2:5 3:5 2:5 3:5 2:5 3:5 2:5 3:5 2:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5"}
			{Bots
				{ResearchStages "0:1 1:2 2:3 3:4 4:4 5:5 6:5 7:6 8:6 9:7 10:8 11:9 12:10 13:11 14:12 14:13 15:13 16:14 17:14 18:14 19:14 20:15 21:15"}
			}
			{MapSelection "0:1"}
			{MapBorder "0:1"}
		}
		{Long
			{FlagCount "1:5 1:5 1:5 1:5 3:5 2:5 3:5 2:5 3:5 2:5 3:5 2:5 3:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5"}
			{Bots
				{ResearchStages "0:1 1:2 2:3 3:4 4:4 5:5 6:5 7:6 8:6 9:7 10:8 11:9 12:10 13:11 14:12 14:13 15:13 16:14 17:14 18:14 19:14 20:15 21:15"}
			}
			{MapSelection "0:1"}
			{MapBorder "0:1"}
		}
		{VeryLong
			{FlagCount "1:5 1:5 1:5 1:5 1:5 1:5 3:5 2:5 3:5 2:5 3:5 2:5 3:5 2:5 3:5 2:5 3:5 2:5 3:5 2:5 3:5 2:5 3:5 2:5 3:5 2:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5"}
			{Bots
				{ResearchStages "0:1 1:2 2:3 3:4 4:4 5:5 6:5 7:6 8:6 9:7 10:8 11:9 12:10 13:11 14:12 14:13 15:13 16:14 17:14 18:14 19:14 20:15 21:15"} 
			}
			{MapSelection "0:1"}
			{MapBorder "0:1"}
		}
		{Unlimited
			{FlagCount "1:5 1:5 1:5 1:5 3:5 2:5 3:5 2:5 3:5 2:5 3:5 2:5 3:5 2:5 3:5 2:5 3:5 2:5 3:5 2:5 3:5 2:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5 4:5 5:5"}
			{Bots
				{ResearchStages "0:1 1:2 2:3 3:4 4:4 5:5 6:5 7:6 8:6 9:7 10:8 11:9 12:10 13:11 14:12 14:13 15:13 16:14 17:14 18:14 19:14 20:15 21:15"}
			}
			{MapSelection "0:1"}
			{MapBorder "0:1"}
		}
	}
}