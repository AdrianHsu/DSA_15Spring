#include <iostream>
#include <string>
#include "avl_ntudsa.h"

using namespace std;

typedef unsigned long long int longint;

int main()
{
	longint n = 0, m = 0;
	scanf("%llu%llu",&n, &m);

	longint* price = new longint [ n ];
	for(int i = 0; i < n; i++)
		scanf("%llu", &price[i]);

	string incident;
	while(cin >> incident)
	{
		if(incident == "1")
		{
			longint i = 0, j = 0;
			scanf("%llu%llu",&i, &j);
			if(i == j)
			{
				printf("ERROR\n");
				break;				
			}

		}
		else if(incident == "2")
		{
			longint i = 0, s = 0;
			scanf("%llu%llu",&i, &s);
			
		}
		else
		{
			printf("ERROR\n");
			break;
		}
	}

	return 0;
}