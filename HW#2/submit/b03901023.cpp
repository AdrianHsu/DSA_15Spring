#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

//#include "../src/HashMap.h"
//#include "../src/HashNode.h"
//#include "../src/KeyNode.h"

#define _TOTAL_LINE = 149639105
#define _PRIME_NUM = 149639071

using namespace std;
typedef unsigned long int longInt; //-2^(64-1) ~ 2^(64-1)-1

//void import(HashMap &, char* );
void import( const string& );

int main()
{
	//HashMap hashMap;
	//import( hashMap , "textdata.txt");
	ifstream ifs;
	ifs.open("textdata.txt", ifstream::in);
	if(!ifs.is_open())
		cout << "ERROR: open file failed" << endl;
	//import("textdata.txt");

}
    //記得要分段偵錯
    //輸入所有資料
    //自己建unordered map，存入資料
    //實作四個function

//void import(HashMap &hashMap, char* path)
void import(const string& path)
{
	//inport all data into hash map
	ifstream ifs;
	ifs.open( path.c_str(), ifstream::in);
	if(!ifs.is_open())
		cout << "ERROR: open file failed" << endl;
	cout << path.c_str() << endl;
	
	string line;
	while(getline(ifs, line)) //getline() reads from ifs a line, and store it into "line"
	{
		istringstream s(line); //change the string "line" into a stringstream "s"
		//HashNode temp;
		string temp;
		for(int i = 0; i < 12; i++)
		{
			//s >> temp.pFlag(i);
			s >> temp;
			cout << temp << endl;
		}	
		//hashMap.put(temp);
	}
	ifs.close();
}