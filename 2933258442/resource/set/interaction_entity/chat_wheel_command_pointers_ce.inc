{"pointer_attack"
	{on spawn
		{tags add "resupply_pointer"}
		{delay 15
			{tags add "ignore_pointer"}
			{delay 21
				{delete}
			}
		}
	}
}
