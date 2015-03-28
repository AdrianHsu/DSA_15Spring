#ifndef HASHNODE_H
#define HASHNODE_H

#include <string>
using namespace std; //std::string

//to prevent UserID, key from overflowing

class HashNode {

public:
	HashNode(){};
	
	string& getElement(const int i);

protected:
	string Click;
	string Impression;
	string DisplayURL;
	string AdID;
	string AdvertiserID;
	string Depth;
	string Position;
	string QueryID;
	string KeywordID;
	string TitleID;
	string DescriptionID;
	string UserID;

};
#endif