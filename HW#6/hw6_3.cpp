#include <iostream>
#include <string>
extern "C" {
	#include "avl_ntudsa.h"
}

using namespace std;

class Game{

public:
	Game()
		:owner(0), price(0){}
	Game(int _owner, int _price)
		:owner(_owner), price(_price){}

	int owner;
	int price;
};

Game disjoint_Set[110000]; //disjoint_Set[i] means i-th game
int _NUM_OF_OWNER = 0;

int find_owner(int);
void owner_identified();
void first_incident(int , int);

int main()
{

	int n = 0, m = 0;
	scanf("%d%d",&n, &m);
	_NUM_OF_OWNER = n;

	disjoint_Set[0] = Game(-1, -1);

	int price = 0;
	for(int i = 1; i <= _NUM_OF_OWNER; i++)
	{
		scanf("%d", &price);
		disjoint_Set[i] = Game(i, price);
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
			unsigned long long s = 0;
			scanf("%u%llu",&i, &s);
			//second_incident(i, s);
		}
		else
		{
			printf("ERROR\n");
			break;
		}
	}
	return 0;
}
int find_owner(int c)
{
	if(disjoint_Set[ c ].owner == c)
		return c;
	else
		return find_owner( disjoint_Set[ c ].owner );
}
void owner_identified() //O(N) time
{
	for(int c = 1; c <= _NUM_OF_OWNER; c++)
		disjoint_Set[ c ].owner = find_owner(c);
}
void first_incident(int i, int j)
{	
	// CASE1: If u also owns the j-th computer game, 
	// u will simply switch to play her/his j-th game.

	i = find_owner(i);
	j = find_owner(j);
	if(disjoint_Set[ i ].owner == disjoint_Set[ j ].owner)
		return;

	// CASE2: If u doesn’t own the j-th computer game, 
	// u will visit the person who owns the j-th game,
	// say v, and borrow all v’s computer games.

	while(j != disjoint_Set[ j ].owner)
		j = disjoint_Set[ j ].owner;	
	
	disjoint_Set[ j ].owner = i;
	_NUM_OF_OWNER--;
	owner_identified();
	//for(int i = 1; i <= 4; i++)
		//cout << disjoint_Set[ i ].owner << endl;
}

