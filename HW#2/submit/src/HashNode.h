#ifndef HASHNODE_H
#define HASHNODE_H

#include <string>
using namespace std; //std::string

typedef unsigned long long int longint; 
//to prevent UserID, key from overflowing

class HashNode {

public:
	HashNode(){};
	
	int& pFlag(const int);
	void setURL(string url){	DisplayURL = url;	}
	void setUserID(int* id){	UserID = (longint)*id;	}
	string getURL(){	return DisplayURL;	}
	longint getUserID(){	return UserID;	}

protected:

	int Click;
	int Impression;
	string DisplayURL;
	int AdID;
	int AdvertiserID;
	int Depth;
	int Position;
	int QueryID;
	int KeywordID;
	int TitleID;
	int DescriptionID;
	longint UserID;
	longint key;

};
#endif