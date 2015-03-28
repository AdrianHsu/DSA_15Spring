#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "src/HashMap.h"
#include "src/HashNode.h"
#include "src/Entry.h"

#define _TOTAL_LINE = 149639105
//#define _PRIME_NUM = 149639071

using namespace std;
typedef unsigned long long int longInt; //-2^(64-1) ~ 2^(64-1)-1
//typedef unordered_map<longint, vector< HashNode > > _HashMap;

bool string2Int(const string& , int*);

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
		string s;
		HashNode* temp = new HashNode;
		int* num = new int;
		int i = 0;
		while( i < 12 )
		{
			ss >> s;
			if(i == 2)
			{
				temp->setURL(s);
				cout << i << " " << temp->getURL() << endl;
			}
			else
			{
				string2Int(s, num);
				if(i == 11)
				{
					temp->setUserID(num);
					cout << i << " " <<temp->getUserID() << endl;
					vector<HashNode> test;
					test.push_back(*temp);
					//hashMap.insert((longint)*num, test);
	
					delete temp;
					delete num;
					//stored value will not be deleted, checked.
					cout << i << " " <<test[test.size() - 1].getUserID() << endl;
					cout << "7" << "  " << test[test.size() - 1].pFlag(7) << endl;	
					cout << "2" << " " << test[test.size() - 1].getURL() << endl;
				}else
				{
					temp->pFlag(i) = *num;
					cout << i << "  " << temp->pFlag(i) << endl;
				}
			}
			i++;
		}
	}
	ifs.close();

    //記得要分段偵錯
    //輸入所有資料
    //自己建unordered map，存入資料
    //實作四個function

	return 0;
}

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