#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "src/HashMap.h"
#include "src/HashNode.h"

#define _TOTAL_LINE = 149639105
//#define _PRIME_NUM = 149639071

using namespace std;
typedef unsigned long long int longInt; //-2^(64-1) ~ 2^(64-1)-1

void import(HashMap &, const string& );

bool string2Int(const string& str, int& num)
{
   num = 0;
   bool flag = true;
   for (unsigned int i = 0; i < str.size(); i++) {
      if (isdigit(str[i])) {
         num *= 10;
         num += int(str[i] - '0');
         flag = true;
      }
      else return false;
   }
   return flag;
}


int main()
{
	HashMap hashMap;
	import( hashMap , "testdata.txt");

	return 0;
}
    //記得要分段偵錯
    //輸入所有資料
    //自己建unordered map，存入資料
    //實作四個function

void import(HashMap &hashMap, const string& path)
{
	//inport all data into hash map
	ifstream ifs;
	ifs.open( path.c_str(), ifstream::in);
	if(!ifs.is_open())
		cout << "ERROR: open file failed" << endl;
	
	string line;
	while(getline(ifs, line)) //getline() reads from ifs a line, and store it into "line"
	{
		istringstream ss(line);
		string s;
		HashNode temp;
		int i = 0, num;
		while( i < 12 )
		{
			ss >> s;
			if(i == 11)
			{
				string2Int(s, num);
				temp.setUserID(num);
				cout << i << " " <<temp.getUserID() << endl;
				temp.setKey();
			}
			else if(i == 2)
			{
				temp.setURL(s);
				cout << i << " " << temp.getURL() << endl;
			}
			else
			{
				string2Int(s, num);
				temp.pFlag(i) = num;
				cout << i << "  " << temp.pFlag(i) << endl;
			}
			i++;
		}

	}
	ifs.close();
}

