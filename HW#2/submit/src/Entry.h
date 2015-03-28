#ifndef ENTRY_H
#define ENTRY_H
#include "HashNode.h"

typedef unsigned long long int longint; 
//to prevent UserID, key from overflowing

class Entry { //class for storing an entry storing a key-value pair

	friend class HashNode;
public:
	Entry(const longint& key, const HashNode& value)
		:_key(key), _value(value){};
	const longint& getKey() const{return _key;}
	const HashNode& getValue() const{return _value;}
	void setPair(const longint& userID, const HashNode& node)
	{	
		_key = userID;	
		_value = node;
	};
protected:
	longint _key;
	HashNode _value;

};

#endif