#ifndef HASHNODE_H
#define HASHNODE_H

#include <string>
using namespace std; //std::string
class HashNode {

public:
	HashNode()
		:d_click(0.0), d_impression(0.0){};
	string& getElement(const int i);
	void setKey(const string k){ _key = k;}
	string& getKey(){return _key;}
	void setd_click(const double c ){d_click = c;}
	void setd_impression(const double i ){d_impression = i;}
	double getd_click(){return d_click;}
	double getd_impression(){return d_impression;}
protected:
	string _key;
	double d_click;
	double d_impression;

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