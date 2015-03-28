#ifndef HASHMAP_H
#define HASHMAP_H

#include "HashNode.h"
#include "Entry.h"
#include "vector"

using namespace std;
typedef unsigned long long int longint; //2^63 is about 10^20

class HashMap {
	friend class HashNode;

public:

	
	//create a vector to prevent Hash collisions
	void put(HashNode&);
	void get(int , int, int, int, int);
	void click(int);
	void impressed(int, int);
	void profit(double, double);

protected:
	typedef vector< Entry > Bucket;
	typedef vector< Bucket > Bucket_Array;
	Bucket_Array unordered_map;

};
#endif