{Hard
	{GlobalMaxCP 1900}
	{StageCP 140 140 140 140 140 140 140}
	{SpecialCP 1001}					;// airstrikes special tab
	{EmplacementCP 50}				;// buildable with engineer
	{Bots
		{StartMP	0.05 min 2002 attackerMultiplier 14.0}
		{FinishMP	0.15 attackerMultiplier 55.5}
		{CP
			{Base "0:0,20:0,480:10,900:10,1080:15,1300:15,1500:15,1800:0,2100:15"} ;// seconds : CP
			{RoundMultiplier "0:0.2 1:0.3 2:0.4 3:0.4 4:0.5 5:0.5 6:0.6 7:0.7 8:0.8 9:0.9 10:1.0 19:1.0"} ;// games played : multiplier for CP
			{AttackMultiplier 4.5}
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
	{PaybackFactor 0.4}		;// MP paid back when loosing solider, squad or vehicle
	{SellFactor 0.7}
	{ScavengedVehicleSellFactor 0.5}		;// captured enemy vehicle 
	{RiskFactor
		{Low
			{BotResources 6.0}
			{BotVeterancy 1}
			{Rewards 1.0}
		}
		{Standard
			{BotResources 6.0}
			{BotVeterancy 4}
			{Rewards 1.5}
		}
		{High
			{BotResources 6.0}
			{BotVeterancy 8}
			{Rewards 2.00}
		}
	}
	{Resources
		{Standard
			{MP ;// Manpower (generic money)
				{StartVal 5000}
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
					{Airfield	35}
				}
			}
			{AP ;// Ammo points
				{StartVal 2500}
				{WinGain "5:300 10:500 15:800"}
				{LoseGain "1:200"}
				{MapRewards
					{Ammodepot	2500}
					{Factory	2000}
				}
			}
			{RP ;// Research points
				{StartVal 10}
				{WinGain 2}
				{LoseGain 1}
				{MapRewards
					{Bonus		1}
					{Research	3}
				}
			}
			{Budget
				{Start "0:690 4:690 8:690 12:690 16:690 20:690"} ;// games played : starting CP of each match 
				{PointsPerSecond 0} ;// CP income
				{Limit 1001} ;// Max CP 
			}
		}
	}
	{Duration
		{Short
			{FlagCount "2:5 2:5 2:5 2:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 5:5 5:5 5:5 5:5 5:5 4:5 4:5 5:5 4:5 5:5 4:5 4:5 5:5 4:5 4:5 5:5"}
			{Bots
				{ResearchStages "0:1 1:2 2:3 3:4 4:4 5:5 6:5 7:6 8:6 9:6 10:7 11:7 12:7 13:8 14:9 14:10 15:11 16:11 17:12 18:12 19:13 20:13 21:15"} ;// number of games played : research tree level bots can have
			}
			{MapSelection "0:1"}	;// number of games played : map selection value from map .info file
			{MapBorder "0:1"}
		}
		{Normal
			{FlagCount "2:5 2:5 2:5 2:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 5:5 5:5 5:5 5:5 5:5 4:5 4:5 5:5 4:5 5:5 4:5 4:5 5:5 4:5 4:5 5:5"}
			{Bots
				{ResearchStages "0:1 1:2 2:3 3:4 4:4 5:5 6:5 7:6 8:6 9:6 10:7 11:7 12:7 13:8 14:9 14:10 15:11 16:11 17:12 18:12 19:13 20:13 21:15"}
			}
			{MapSelection "0:1"}
			{MapBorder "0:1"}
		}
		{Long
			{FlagCount "2:5 2:5 2:5 2:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 5:5 5:5 5:5 5:5 5:5 4:5 4:5 5:5 4:5 5:5 4:5 4:5 5:5 4:5 4:5 5:5"}
			{Bots
				{ResearchStages "0:1 1:1 2:3 3:4 4:4 5:5 6:5 7:6 8:6 9:6 10:7 11:7 12:7 13:8 14:9 14:10 15:11 16:11 17:12 18:12 19:13 20:13 21:15"}
			}
			{MapSelection "0:1"}
			{MapBorder "0:1"}
		}
		{VeryLong
			{FlagCount "2:5 2:5 2:5 2:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 5:5 5:5 5:5 5:5 5:5 4:5 4:5 5:5 4:5 5:5 4:5 4:5 5:5 4:5 4:5 5:5"}
			{Bots
				{ResearchStages "0:1 1:2 2:3 3:4 4:4 5:5 6:5 7:6 8:6 9:6 10:7 11:7 12:7 13:8 14:9 14:10 15:11 16:11 17:12 18:12 19:13 20:13 21:15"}
			}
			{MapSelection "0:1"}
			{MapBorder "0:1"}
		}
		{Unlimited
			{FlagCount "2:5 2:5 2:5 2:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 3:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 4:5 5:5 5:5 5:5 5:5 5:5 4:5 4:5 5:5 4:5 5:5 4:5 4:5 5:5 4:5 4:5 5:5"}
			{Bots
				{ResearchStages "0:1 1:2 2:3 3:4 4:4 5:5 6:5 7:6 8:6 9:6 10:7 11:7 12:7 13:8 14:9 14:10 15:11 16:11 17:12 18:12 19:13 20:13 21:15"}
			}
			{MapSelection "0:1"}
			{MapBorder "0:1"}
		}
	}
}