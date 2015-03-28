#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>

#include "src/HashMap.h"
#include "src/HashNode.h"
#include "src/Entry.h"

#define _TOTAL_LINE = 149639105
//#define _PRIME_NUM = 149639071

using namespace std;
typedef unordered_map<string, vector<HashNode>> _HashMap;

unsigned int string2Int(const string&, unsigned int&);
bool insert(_HashMap&, HashNode*);
int main()
{
	_HashMap hashMap;
	string path =  "test_235466.txt";

	//import
	ifstream ifs;
	ifs.open( path.c_str(), ifstream::in);
	if (!ifs.is_open())
		cout << "ERROR: open file failed" << endl;

	int count = 0;
	string line;
	while (getline(ifs, line)) //getline() reads from ifs a line, and store it into "line"
	{
		istringstream ss(line);
		HashNode* temp = new HashNode;

		int i = 0;
		while ( i < 12 )
		{
			ss >> temp->getElement(i);
			if (i == 11)
			{
				string key = temp->getElement(11);
				if ( hashMap.count(key) == 0)
				{
					vector<HashNode>* _vec = new vector<HashNode>;
					_vec->push_back(*temp);
					hashMap.insert( pair<string, vector<HashNode>>( key , *_vec ) );
					count++;
				} else
				{
					/*if(hashMap[temp->getElement(11)])
					hashMap[temp->getElement(11)].push_back(*temp);*/
				}
			}
			//cout << i << " " << temp->getElement(i) << endl;
			i++;
		}
	}
	for (auto& x: hashMap) {
    cout << x.first << ": " << x.second[0].getElement(2)<< endl;
  	}
	ifs.close();
	return 0;
}

bool insert(_HashMap& hashMap, HashNode* node)
{	return true;}

unsigned int string2Int(const string& str, unsigned int& num)
{
	num = 0;
	for (unsigned int i = 0; i < str.size(); i++) {
		if (isdigit(str[i])) {
			num *= 10;
			num += int(str[i] - '0');
		}
	}
	return num;
}