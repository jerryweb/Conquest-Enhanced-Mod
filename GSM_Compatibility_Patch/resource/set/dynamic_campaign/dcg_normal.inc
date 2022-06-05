{Normal
	{GlobalMaxCP 1900}
	{StageCP 110 110 110 110 110 110 110}
	{SpecialCP 1001}					;// airstrikes special tab
	{EmplacementCP 50}				;// buildable with engineer
	{Bots
		{StartMP	0.05 min 2002 attackerMultiplier 14.0}
		{FinishMP	0.15 attackerMultiplier 55.5}
		{CP
			{Base "0:0,60:0,300:11,960:10,1080:10,1300:10,1500:11,1900:10,2100:12"} ;// seconds : CP
			{RoundMultiplier "0:0.2 1:0.3 2:0.3 3:0.4 4:0.4 5:0.5 6:0.6 7:0.7 8:0.6 9:0.9 10:1.0 11:1.1 12:1.2"} ;// games played : multiplier for CP
			{AttackMultiplier 3.9}
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
			{BotResources 7.0}
			{BotVeterancy 1}
			{Rewards 1.0}
		}
		{Standard
			{BotResources 7.0}
			{BotVeterancy 3}
			{Rewards 1.5}
		}
		{High
			{BotResources 7.0}
			{BotVeterancy 5}
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
				{WinGain "1:2 4:5 6:7 8:6 10:9 12:10 14:12"}
				{LoseGain 0}
				{MapRewards
					{Airfield	20}
				}
			}
			{AP ;// Ammo points
				{StartVal 2500}
				{WinGain "5:300 10:500 15:800"}
				{LoseGain "1:200"}
				{MapRewards
					{Ammodepot	2500}
					{Factory	1000}
				}
			}
			{RP ;// Research points
				{StartVal 10}
				{WinGain "1:2 4:5 5:3 6:4 10:5 15:6"}
				{LoseGain 1}
				{MapRewards
					{Bonus		1}
					{Research	3}
					{Factory	1}
				}
			}
			{Budget
				{Start "0:551 4:551 8:551 12:551 16:551 20:551"} ;// games played : starting CP of each match 
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