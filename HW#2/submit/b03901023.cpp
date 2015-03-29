#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
#include <cmath>

#include "src/HashNode.h"

#define _TOTAL_LINE 149639105
//#define _HASH_MAX  134217728 //2^27
#define _HASH_MAX 9999999999 //suppose key is at most 10 bits

using namespace std;
typedef unordered_map<string, vector<HashNode>> _HashMap;
typedef unsigned long long int longint;

longint string2Int(const string&, longint&);
double string2Double(const string&);

string int2String(longint &);
void get(string, string, string, string, string);
void clicked(string);
void impressed(string, string);
void profit(double, double);

static _HashMap hashMap;
int main()
{

	string path = "kddcup2012track2_7924321.txt";
	//string path =  "test_235466.txt";

	//import
	ifstream ifs;
	ifs.open( path.c_str(), ifstream::in);
	if (!ifs.is_open())
		printf( "ERROR: open file failed\n");

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
				temp->setKey(key);
				temp->setd_click(string2Double(temp->getElement(0)));
				temp->setd_impression(string2Double(temp->getElement(1)));
				if ( hashMap.count(key) == 0)
				{
					vector<HashNode>* _vec = new vector<HashNode>;
					_vec->push_back(*temp);
					hashMap.insert( pair<string, vector<HashNode>>( key , *_vec ) );
				} else
				{
					if (key == hashMap[key][0].getKey())
						hashMap[temp->getKey()].push_back(*temp);
					else
					{
						do {
							longint temp;
							temp = string2Int(key, temp) + 1;
							if (temp >= _HASH_MAX)
								temp = 0;
							key = int2String(temp);
						} while ( hashMap.count(key) != 0 );

						cout << "oops, collision happened!" << endl;
						temp->setKey(key);//key has been hashed once again
						vector<HashNode>* _vec = new vector<HashNode>;
						_vec->push_back(*temp);
					}
				}
			}
			i++;
		}
	}
	ifs.close();
	printf("DONE!\n");

	longint _line = 0;
	for (auto& x : hashMap) {
		//cout << x.first << ": " << x.second[0].getElement(2)<< endl;
		//cout << "size: " << x.second.size() << endl;
		_line += x.second.size();
	}
	get("6231944", "20157628", "0", "3", "3");//(0, 1)
	get("2647468", "20711336", "22138939", "1", "1");//line 100000, (0, 1)
	get("516038", "6434912", "1205", "2", "2");//line 100000, (0, 1)
	clicked("11416328"); //line 226448
	clicked("67385"); //line 227151
	impressed("490234", "86056");
	impressed("67385", "388585"); //line 67385, 227370
	double a = 0;
	profit(a, 2);

	cout << "TOTAL_LINE: " << _line << endl;
	cout << "MAP_SIZE: " << hashMap.size() << endl;
	return 0;
}

longint string2Int(const string& str, longint& num)
{
	num = 0;
	for (longint i = 0; i < str.size(); i++) {
		if (isdigit(str[i])) {
			num *= 10;
			num += int(str[i] - '0');
		}
	}
	return num;
}
double string2Double(const string& str)
{
	longint num = 0;
	for (longint i = 0; i < str.size(); i++) {
		if (isdigit(str[i])) {
			num *= 10;
			num += int(str[i] - '0');
		}
	}
	return (double)num;
}
string int2String(longint &i) {

	string s;
	stringstream ss(s);
	ss << i;

	return ss.str();
}
void get(string u, string a, string q, string p, string d)
{
	if (hashMap.count(u) == 0) return;

	unsigned int i = 0;
	while (i < hashMap[u].size())
	{
		if (hashMap[u][i].getElement(3) == a && hashMap[u][i].getElement(7) == q
		 && hashMap[u][i].getElement(6) == p && hashMap[u][i].getElement(5) == d)
		{
			cout << "(" << hashMap[u][i].getElement(0) << ", " << hashMap[u][i].getElement(1) << ")" << endl;
			//break; // maybe more than one set
		}
		i++;
	}

	return;
}
void clicked(string u)
{
	if (hashMap.count(u) == 0) return;

	for (unsigned int i = 0; i < hashMap[u].size(); i++)
	{
		longint temp;
		if ( string2Int(hashMap[u][i].getElement(0), temp) > 0)
			cout << "(" << hashMap[u][i].getElement(3) << ", " << hashMap[u][i].getElement(7) << ")" << endl;
	}
}
void impressed(string u1, string u2)
{
	if (hashMap.count(u1) == 0 || hashMap.count(u2) == 0) return;

	if (hashMap[u1].size() < hashMap[u2].size())
	{
		string temp = u2;
		u2 = u1;
		u1 = temp;
	}
	int size_MAX = hashMap[u1].size();
	int size_MIN = hashMap[u2].size();

	string s[size_MAX];
	int a[size_MAX];
	for (int i = 0, j = 0; i < size_MAX; i++)
	{
		longint temp;
		if (string2Int(hashMap[u1][i].getElement(1), temp) > 0)
		{
			s[j] = hashMap[u1][i].getElement(3);
			a[i] = 1;
			j++;
		}
	}
	for (int k1 = 0; k1 < size_MAX; k1++)
	{
		for (int k2 = 0; k2 < size_MIN; k2++)
		{
			if (s[k1] == hashMap[u2][k2].getElement(3))
			{
				a[k1]++;
			}
		}
	}
	for (int i = 0; i < size_MAX; i++)
	{
		if (a[i] > 1)
			cout  << hashMap[u1][i].getElement(3)  << "\t" << hashMap[u1][i].getElement(2)  << "\t" << hashMap[u1][i].getElement(4) << "\t"
			      << hashMap[u1][i].getElement(8)  << "\t" << hashMap[u1][i].getElement(9)  << "\t" << hashMap[u1][i].getElement(10) << endl;
	}
}

void profit(double a, double theta)
{
	unsigned int i;
	double t0, t1;
	for (auto& x : hashMap) {

		t0 = 0.0, t1 = 0.0;
		for (i = 0; i < x.second.size(); i++)
		{
			t0 += x.second[i].getd_click();
			t1 += x.second[i].getd_impression();
		}
		a = t0 / t1;
		if (a >= theta)
			cout << "Profit UserID: " << x.second[0].getKey() << endl;
	}
}
