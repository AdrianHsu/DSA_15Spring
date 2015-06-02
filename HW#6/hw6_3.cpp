#include <iostream>
#include <string>
extern "C" {
	#include "avl_ntudsa.h"
}

using namespace std;
typedef unsigned long long long_int;

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
int _TOTAL_GAME = 0;

int find_owner(int);
void owner_identified();
void first_incident(int , int);

void inorder_integer_avl(const struct avl_node *,const long_int , long_int *, int *);
int int_compare(const void *, const void *, void *);
void second_incident(int , long_int);

int main()
{

	int n = 0, m = 0;
	scanf("%d%d",&n, &m);
	_TOTAL_GAME = _NUM_OF_OWNER = n;

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
			int i = 0;
			long_int s = 0;
			scanf("%d%llu",&i, &s);
			second_incident(i, s);
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
}

void inorder_integer_avl(const struct avl_node* node,const long_int s, long_int* total , int* k)
{
	if(node == NULL)
		return;
	
	if(node->avl_link[0] != NULL)
	inorder_integer_avl(node->avl_link[0], s, total, k);
	if(*total == s)
		return;
	else if(*total > s)
	{
		(*k)--;
		return;
	}
	
	*total += node->avl_data;
	(*k)++;
	if(*total == s)
		return;
	else if(*total > s)
	{
		(*k)--;
		return;
	}
	if(node->avl_link[1] != NULL)
	inorder_integer_avl(node->avl_link[1], s, total, k);
}
int int_compare(const void *pa, const void *pb, void * param)
{
	long_int a = *(const long_int *)pa;
	long_int b = *(const long_int *)pb;
	if(a < b) return -1;
	else if (a > b)return +1;
	else return 0;
}
void second_incident(int i, long_int s)
{
	i = find_owner(i);
	struct avl_table *avl_tree ;
	avl_tree = avl_create(int_compare , NULL, NULL);

	for(int j = 0; j < _TOTAL_GAME; j++)
		if(disjoint_Set[ j ].owner == i)
		{
			avl_probe(avl_tree, disjoint_Set[ j ].price);
		}
	
	long_int* total = new long_int(0);
	int* k = new int(0);
	inorder_integer_avl(avl_tree->avl_root, s, total, k);
	cout << i << " " << *k << endl;

}
