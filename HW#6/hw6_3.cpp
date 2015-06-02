#include <iostream>
#include <string>
extern "C" {
	#include "avl_ntudsa.h"
}

using namespace std;

typedef unsigned long long int longint;

int id_compare(const void *pa, const void *pb, void * param)
{
	int a = *(const int*)pa;
	int b = *(const int*)pb;
	if(a < b) return -1;
	else if (a > b)return +1;
	else return 0;
}

int main()
{

	unsigned int n = 0, m = 0;
	scanf("%u%u",&n, &m);

	struct avl_table **avl_tree = new avl_table* [ n ];
	
	for(int i = 0; i < n; i++)
	{
		avl_tree[i] = avl_create(id_compare , NULL, NULL);
		int price = 0;
		scanf("%u", &price);
		int* p = avl_probe(avl_tree[i], price);
	}

	string incident;
	while(cin >> incident)
	{
		if(incident == "1")
		{
			unsigned int i = 0, j = 0;
			scanf("%u%u",&i, &j);
			if(i == j)
			{
				printf("ERROR\n");
				break;				
			}


		}
		else if(incident == "2")
		{
			unsigned int i = 0;
			longint s = 0;
			scanf("%u%llu",&i, &s);
			
		}
		else
		{
			printf("ERROR\n");
			break;
		}
	}

	return 0;
}