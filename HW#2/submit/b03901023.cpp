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

bool string2Int(const string&, int*);
bool insert(_HashMap&, string, HashNode*);
int main()
{
	_HashMap hashMap;
	string path =  "test_1000.txt";

	//import
	ifstream ifs;
	ifs.open( path.c_str(), ifstream::in);
	if(!ifs.is_open())
		cout << "ERROR: open file failed" << endl;
	
	string line;
	while(getline(ifs, line)) //getline() reads from ifs a line, and store it into "line"
	{
		istringstream ss(line);
		HashNode* temp = new HashNode;
		int i = 0;
		while( i < 12 )
		{
			ss >> temp->getElement(i);
			//insert(hashMap, key, temp);
			//if(i == 11)delete temp;
			cout << i << " " << temp->getElement(i) << endl; 

			i++;
		}
	}
	ifs.close();
	return 0;
}

/*bool insert(_HashMap& hashMap, int* n, HashNode* node)
{
	_HashMap::hasher fn = hashMap.hash_function();
	int k = *n;

	cout << *n << " - " << fn( k ) << endl;
	//longint flag = hashMap[ fn( (longint)*n ) ];
	if( flag != 0)
	{
		vector<HashNode> test;
		test.push_back(*node);
		hashMap.insert( pair<longint, vector<HashNode>>( (longint)*n, test ) );
		return true;
	}else
	{
		return false;
	}
	return false;

}*/

bool string2Int(const string& str, int* num)
{
   *num = 0;
   bool flag = true;
   for (unsigned int i = 0; i < str.size(); i++) {
      if (isdigit(str[i])) {
         *num *= 10;
         *num += int(str[i] - '0');
         flag = true;
      }
      else return false;
   }
   return flag;
}