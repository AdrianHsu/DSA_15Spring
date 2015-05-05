int tree_predict(double *attr)
{
	if(attr[12] <= 4.500000)
	{
		if(attr[2] <= 3.500000)
		{
			if(attr[9] <= 2.300000)
			{
				if(attr[11] <= 0.000000)
				{
					return -1;
				}
				else
				{
					if(attr[7] <= 128.000000)
					{
						if(attr[9] <= 0.950000)
						{
							if(attr[8] <= 0.500000)
							{
								return 1;
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
						return -1;
					}
				}
			}
			else
			{
				if(attr[10] <= 2.500000)
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
			if(attr[11] <= 0.500000)
			{
				if(attr[3] <= 145.000000)
				{
					if(attr[7] <= 96.500000)
					{
						return 1;
					}
					else
					{
						return -1;
					}
				}
				else
				{
					if(attr[0] <= 63.000000)
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
				if(attr[1] <= 0.500000)
				{
					if(attr[10] <= 2.000000)
					{
						if(attr[10] <= 1.500000)
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
						if(attr[11] <= 2.500000)
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
	}
	else
	{
		if(attr[11] <= 0.500000)
		{
			if(attr[2] <= 3.500000)
			{
				if(attr[0] <= 39.000000)
				{
					return 1;
				}
				else
				{
					if(attr[7] <= 143.000000)
					{
						if(attr[9] <= 0.250000)
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
			}
			else
			{
				if(attr[0] <= 56.500000)
				{
					if(attr[9] <= 0.250000)
					{
						if(attr[0] <= 42.000000)
						{
							return 1;
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
					if(attr[3] <= 140.000000)
					{
						return -1;
					}
					else
					{
						if(attr[12] <= 6.500000)
						{
							return -1;
						}
						else
						{
							return 1;
						}
					}
				}
			}
		}
		else
		{
			if(attr[4] <= 151.500000)
			{
				return -1;
			}
			else
			{
				return 1;
			}
		}
	}
}