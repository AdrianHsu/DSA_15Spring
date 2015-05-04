int tree_predict(double *attr)
{
	if(attr[12] <= 7.000000)
	{
		if(attr[11] <= 1.000000)
		{
			if(attr[6] <= 2.000000)
			{
				if(attr[0] <= 58.000000)
				{
					return -1;
				}
				else
				{
					if(attr[9] <= 1.700000)
					{
						if(attr[1] <= 1.000000)
						{
							if(attr[1] <= 1.000000)
							{
								if(attr[1] <= 0.500000)
								{
									return -1;
								}
								else
								{
									return 1;
								}
							}
							else
							{
								return -1;
							}
						}
						else
						{
							return -1;
						}
					}
					else
					{
						return 1;
					}
				}
			}
			else
			{
				return -1;
			}
		}
		else
		{
			if(attr[0] <= 69.000000)
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
	}
	else
	{
		if(attr[2] <= 3.500000)
		{
			if(attr[5] <= 0.000000)
			{
				if(attr[3] <= 122.500000)
				{
					if(attr[9] <= 1.000000)
					{
						if(attr[9] <= 0.800000)
						{
							return -1;
						}
						else
						{
							return 1;
						}
					}
					else
					{
						return -1;
					}
				}
				else
				{
					return 1;
				}
			}
			else
			{
				if(attr[4] <= 247.000000)
				{
					return -1;
				}
				else
				{
					return 1;
				}
			}
		}
		else
		{
			return 1;
		}
	}
}
