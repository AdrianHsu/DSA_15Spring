#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../src/HashMap.h"
#include "../src/HashNode.h"
#include "../src/KeyNode.h"

#define _TOTAL_LINE = 149639105

using namespace std;
typedef unsigned long int longInt; //-2^(64-1) ~ 2^(64-1)-1

void import(HashMap &);


int main()
{
	HashMap hashMap;
	import( hashMap );



}
    //記得要分段偵錯
    //輸入所有資料
    //自己建unordered map，存入資料
    //實作四個function

void import(HashMap &hashMap)
{
	//inport all data into hash map
	ifstream ifs;
	string line;
	ifs.open("textdata.txt", ifstream::in);
	if(!ifs)
		cerr << "ERROR: open file failed" << endl;
	
	while(getline(ifs, line)) //getline() reads from ifs a line, and store it into "line"
	{
		istringstream s(line); //change the string "line" into a stringstream "s"
		HashNode temp;
		
		for(int i = 0; i < 12; i++)
			s >> temp.pFlag(i);
		
		hashMap.put(temp);
	}
	ifs.close();
}