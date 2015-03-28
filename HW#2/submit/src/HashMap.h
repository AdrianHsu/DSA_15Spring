#ifndef HASHMAP_H
#define HASHMAP_H

#include "HashNode.h"
#include "Entry.h"
#include <vector>


//#define PRIME 39916801
using namespace std;
typedef unsigned long long int longint; //2^63 is about 10^20

class HashMap {
	friend class HashNode;

public:
	HashMap(){};
	~HashMap(){};

protected:
	//typedef vector< Entry > Bucket;


};
#endif