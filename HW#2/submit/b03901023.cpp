#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
#include <cmath>

#include "src/HashNode.h"

#define _TOTAL_LINE = 149639105
//#define _PRIME_NUM = 149639071

using namespace std;
typedef unordered_map<string, vector<HashNode>> _HashMap;
typedef unsigned long long int longint;

longint string2Int(const string&, longint&);
string int2String(longint &);
void get(string, string, string, string, string);
void clicked(string);
void impressed(string, string);
void profit(double, double);

static _HashMap hashMap;
int main()
{

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
					if (key == hashMap[key][0].getElement(11))
						hashMap[temp->getElement(11)].push_back(*temp);
					else
					{
						do {
							longint temp;
							temp = string2Int(key, temp) + 1;
							key = int2String(temp);
						} while ( hashMap.count(key) != 0 );
						vector<HashNode>* _vec = new vector<HashNode>;
						_vec->push_back(*temp);
						hashMap.insert( pair<string, vector<HashNode>>( key , *_vec ) );
						count++;
					}
				}
			}
			i++;
		}
	}
	ifs.close();
	cout << "DONE!" << endl;

	longint _line = 0;
	for (auto& x : hashMap) {
		//cout << x.first << ": " << x.second[0].getElement(2)<< endl;
		//cout << "size: " << x.second.size() << endl;
		_line += x.second.size();
	}

	cout << "TOTAL_LINE: " << _line << endl;
	cout << "MAP_SIZE: " << hashMap.size() << endl;

	get("6231944", "20157628", "0", "3", "3");
	clicked("6231944");
	impressed("490234", "86056");
	double a = 0;
	profit(a, 0.0001);
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
	while (i <= hashMap[u].size()) //改成二分搜尋法
	{
		if (hashMap[u][i].getElement(3) == a && hashMap[u][i].getElement(7) == q
		        && hashMap[u][i].getElement(6) == p && hashMap[u][i].getElement(5) == d)
		{
			cout << "(" << hashMap[u][i].getElement(0) << ", " << hashMap[u][i].getElement(1) << ")" << endl;
			break;
		}
		else i++;
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
	longint tmp0 = 0;
	longint tmp1 = 0;
	double t0, t1;
	for (auto& x : hashMap) {
		
		t0 = 0.0, t1 = 0.0;
		for (i = 0; i < x.second.size(); i++)
		{
			tmp0 = 0;
			tmp1 = 0;
			t0 += (double)string2Int(x.second[i].getElement(0), tmp0);
			t1 += (double)string2Int(x.second[i].getElement(1), tmp1);
		}
		a = (double)((double)t0 / (double)t1);
		if (a >= theta)
			cout << "Profit UserID: " << x.second[0].getElement(11) << endl;
	}
}
