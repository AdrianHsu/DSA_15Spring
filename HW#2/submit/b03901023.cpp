#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
#include <cmath>

#include "HashNode.h"

#define _TOTAL_LINE 149639105
#define _HASH_MAX    25000000
//suppose unordered_mapered_maps are at most 20000000(approximately)

using namespace std;
typedef unordered_map< string, vector<HashNode> > _HashMap;
typedef unsigned int longint; //0 to 4,294,967,295

bool import(string&);
longint string2Int(const string&, longint&);
longint string2Int(const string&);
string int2String(longint &);
double string2Double(const string&);

void get(longint, longint, longint, longint, longint);
void clicked(longint);
void impressed(longint, longint);
void profit(double, double);

static _HashMap hashMap;

int main()
{
	//absolutely string path
	string path = "/tmp2/KDDCup2012/track2/kddcup2012track2.txt";


	if(import(path)) //if import data successfully
		printf("DONE!\n");
	
	get(6231944, 20157628, 0, 3, 3);//(0, 1)
	get(2647468, 20711336, 22138939, 1, 1);//line 100000, (0, 1)
	get(516038, 6434912, 1205, 2, 2);//line 100000, (0, 1)
	clicked(11416328); //line 226448
	clicked(67385); //line 227151
	impressed(490234, 86056);
	impressed(67385, 388585); //line 67385, 227370
	impressed(55984, 872615);
	double a = 0;
	profit(a, 2);

	return 0;
}

bool import(string& path)
{
	//import data into unordered map
	ifstream ifs;
	ifs.open( path.c_str(), ifstream::in); // .open() receives char*, not string
	if (!ifs.is_open())
	{
		printf( "ERROR: open file failed\n");
		return false;
	}
	string line; // stream ifs into line temporarily
	while (getline(ifs, line)) //getline() reads from ifs a line, and store it into "line"
	{
		istringstream ss(line);
		HashNode temp; //temp is used to store those 12 elements
					   //and would be push_back() into specific vector in hashMap
		int i = 0;
		while ( i < 12 )
		{
			string str;
			ss >> str;
			if(i != 2)temp.getElement(i) = string2Int(str); //.getElement(i) is longint
			
			if(i == 2)
				temp.setURL(str); //URL is a string
			else if (i == 11)
			{
				string key = str;
				temp.setKey(key);
				if ( hashMap.count(key) == 0) //hashMap[key] is empty, with no vector
				{	// use .count() since unordered_map doesn't have .empty()
					
					vector<HashNode> _vec;
					_vec.push_back(temp);
					hashMap.insert( pair<string, vector<HashNode> >( key , _vec ) );
				} else
				{
					//if (key == hashMap[key][0].getKey) which is trivial
					
					if(temp.getElement(11) == hashMap[key][0].getElement(11)) 
						hashMap[temp.getKey()].push_back(temp);
					else //hash funtion may cause .first() collsion
					{
						longint tmp = 0;
						do {
							tmp = string2Int(key, tmp) + 1;
							if (tmp >= _HASH_MAX)
								tmp = 1; //rehash
							key = int2String(tmp);
						} while ( hashMap.count(key) != 0 );

						printf( "oops, collision happened!\n" );
						temp.setKey(key);//key should be reset
						vector<HashNode> _vec;
						_vec.push_back(temp);
						hashMap.insert( pair<string, vector<HashNode> >( key , _vec ) );
					}
				}
			}
			i++;
		}
	}
	ifs.close();
	return true;
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
longint string2Int(const string& str)
{
	longint num = 0;
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
void get(longint _u, longint a, longint q, longint p, longint d)
{
	string u = int2String(_u);
	if (hashMap.count(u) == 0) return;

	unsigned int i = 0;
	while (i < hashMap[u].size())
	{
		if (hashMap[u][i].getElement(3) == a && hashMap[u][i].getElement(7) == q
		        && hashMap[u][i].getElement(6) == p && hashMap[u][i].getElement(5) == d)
		{
			printf( "(%u, %u)\n", hashMap[u][i].getElement(0), hashMap[u][i].getElement(1));
		}
		i++;
	}
	return;
}
void clicked(longint _u)
{
	string u = int2String(_u);
	if (hashMap.count(u) == 0) return;

	for (unsigned int i = 0; i < hashMap[u].size(); i++)
	{
		if ( hashMap[u][i].getElement(0) > 0)
			printf( "(%u, %u)\n", hashMap[u][i].getElement(3), hashMap[u][i].getElement(7));
	}
}
void impressed(longint u_1, longint u_2)
{
	string u1 = int2String(u_1);
	string u2 = int2String(u_2);
	if (hashMap.count(u1) == 0 || hashMap.count(u2) == 0) return;
	if (hashMap[u1].size() < hashMap[u2].size())
	{
		string temp = u2;
		u2 = u1;
		u1 = temp;
	}
	int size_MAX = hashMap[u1].size();
	int size_MIN = hashMap[u2].size();

	longint s[size_MAX];
	int a[size_MAX];
	for (int i = 0, j = 0; i < size_MAX; i++)
	{
		if (hashMap[u1][i].getElement(1) > 0)
		{
			s[j] = hashMap[u1][i].getElement(3);
			a[i] = 1;
			j++;
		}
	}
	vector<HashNode*> vec_Ptr;
	for (int k1 = 0; k1 < size_MAX; k1++)
	{
		for (int k2 = 0; k2 < size_MIN; k2++)
		{
			if (s[k1] == hashMap[u2][k2].getElement(3))
			{
				a[k1]++;
				HashNode* temp;
				temp = &hashMap[u2][k2];
				vec_Ptr.push_back(temp);
			}
		}
	}
	longint i, j, k; //shell sort
	for (k = vec_Ptr.size() / 2; k > 0; k /= 2) {
		for (i = k; i < vec_Ptr.size(); i++) {

			HashNode* temp = vec_Ptr[i];
			for (j = i; j >= k; j -= k) {

				if (temp->getElement(3) < vec_Ptr[j - k]->getElement(3))
					vec_Ptr[j] = vec_Ptr[j - k];
				else
					break;
			}
			vec_Ptr[j] = temp;
		}
	}
	for (i = 0; i < vec_Ptr.size(); i++)
	{
		printf("%u\t%s\t%u\t", vec_Ptr[i]->getElement(3),
		       vec_Ptr[i]->getURL().c_str(), vec_Ptr[i]->getElement(4));
		printf("%u\t%u\t%u\n", vec_Ptr[i]->getElement(8),
		       vec_Ptr[i]->getElement(9), vec_Ptr[i]->getElement(10));
	}
}

void profit(double a, double theta)
{
	longint i, j, temp, k;
	double t0, t1;
	vector<longint> sorted_ID;
	for (auto& x : hashMap) {

		t0 = 0.0;
		t1 = 0.0;
		for (i = 0; i < x.second.size(); i++)
		{		
			t0 += x.second[i].getElement(0);
			t1 += x.second[i].getElement(1);
		}
		if(t1 == 0) a = 0;
		else
			a = t0 / t1;
		if (a >= theta)
			sorted_ID.push_back(x.second[0].getElement(11));
	}
	//sorting, using shell sort
	for (k = sorted_ID.size() / 2; k > 0; k /= 2) {
		for (i = k; i < sorted_ID.size(); i++) {
			temp = sorted_ID[i];
			for (j = i; j >= k; j -= k) {
				if (temp < sorted_ID[j - k])
					sorted_ID[j] = sorted_ID[j - k];
				else
					break;
			}
			sorted_ID[j] = temp;
		}
	}
	for (i = 0; i < sorted_ID.size(); i++)
		printf("%u\n", sorted_ID[i]);
}