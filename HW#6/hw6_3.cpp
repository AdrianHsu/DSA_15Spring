#include <iostream>
#include <string>
extern "C" {
	#include "avl_ntudsa.h"
}

using namespace std;

typedef unsigned long long int longint;

class Node{

public:
	Node()
		:key(0), price(0){}
	Node(int _key, int _price)
		:key(_key), price(_price){}

	int key;
	int price;
};

Node disjoint_Set[110000]; //User == disjoint set
int _NUM_OF_USER = 0;

/*int find_root(int i)
{
	while(i != disjoint_Set[ i ].key)
	{
		i = disjoint_Set[ i ].key;
	}
	return i;
}*/
void first_incident(int i, int j)
{	
	// CASE1: If u also owns the j-th computer game, 
	// u will simply switch to play her/his j-th game.

	if(disjoint_Set[ i ].key == disjoint_Set[ j ].key)
		return;

	// CASE2: If u doesn’t own the j-th computer game, 
	// u will visit the person who owns the j-th game,
	// say v, and borrow all v’s computer games.

	while(j != disjoint_Set[ j ].key)
	{
		int key = disjoint_Set[ j ].key;
		disjoint_Set[ j ].key = i;
		j = key;
	}
	
	disjoint_Set[ j ].key = i;	
	_NUM_OF_USER--;
}
int main()
{

	int n = 0, m = 0;
	scanf("%d%d",&n, &m);
	_NUM_OF_USER = n;

	disjoint_Set[0] = Node(-1, -1);

	int price = 0;
	for(int i = 1; i <= _NUM_OF_USER; i++)
	{
		scanf("%d", &price);
		disjoint_Set[i] = Node(i, price);
	}
	
	string incident;
	for(int counter = 0; counter < m; counter++)
	{
		cin >> incident;
		if(incident == "1")
		{
			int i = 0, j = 0;
			scanf("%d%d",&i, &j);
			first_incident(i, j);
		}
		else if(incident == "2")
		{
			unsigned int i = 0;
			longint s = 0;
			scanf("%u%llu",&i, &s);
			
			//second_incident(i, s);
		}
		else
		{
			printf("ERROR\n");
			break;
		}
		cout << disjoint_Set[1].key << endl;
		cout << disjoint_Set[2].key << endl;
		cout << disjoint_Set[3].key << endl;
	}
	return 0;
}