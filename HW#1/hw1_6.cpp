#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

//The code should take two 4-byte integers a and b 
//To prevent overflowing in multiplication, use unsign long int
typedef unsigned long int longint;

//function prototype
int RS(longint, longint, int&);
int F(longint, longint, int&);
int FF(longint, longint, int, int&);
int B(longint, longint, int&);
int E(longint, longint, int&);

bool _b_is_zero(longint b)
{
	if(b == 0) return true;
	return false;
}

int main()
{
	longint arrA[1000];
	longint arrB[1000];
	int i = 0; // i represents arr element position
	//from the standard input per line until reaching a = 0
	//input loop
	while(cin >> arrA[i])
	{
		if(arrA[i] == 0) break;
		cin >> arrB[i];
		i++;
	}
	
	i = 0; //return i to the first arr element
	//output loop
	while(arrA[i] != 0)
	{
		if( _b_is_zero(arrB[i]) )
		{
			cout << "Case (" << arrA[i] << ", " << arrB[i] << "): GCD-By-Reverse-Search = 0, taking 0 iterations" << endl;
			cout << "Case (" << arrA[i] << ", " << arrB[i] << "): GCD-By-Filter = 0, taking 0 iterations" << endl;
			cout << "Case (" << arrA[i] << ", " << arrB[i] << "): GCD-By-Filter-Faster = 0, taking 0 iterations" << endl;
			cout << "Case (" << arrA[i] << ", " << arrB[i] << "): GCD-By-Binary = 0, taking 0 iterations" << endl;
			cout << "Case (" << arrA[i] << ", " << arrB[i] << "): GCD-By-Euclid = 0, taking 0 iterations" << endl;
			i++;
			continue;
		}
		int c[5] = {0};
		//GCD-By-Reverse-Search, RS
		cout << "Case (" << arrA[i] << ", " << arrB[i] << "): GCD-By-Reverse-Search = "
		<< RS(arrA[i], arrB[i], c[0]);
		cout << ", taking " << c[0] << " iterations" << endl;
		//GCD-By-Filter, F
		cout << "Case (" << arrA[i] << ", " << arrB[i] << "): GCD-By-Filter = "
		<< F(arrA[i], arrB[i], c[1]);
		cout << ", taking " << c[1] << " iterations" << endl;
		//GCD-By-Filter-Faster, FF
		cout << "Case (" << arrA[i] << ", " << arrB[i] << "): GCD-By-Filter-Faster = "
		<< FF(arrA[i], arrB[i], 2, c[2]);
		cout << ", taking " << c[2] << " iterations" << endl;
		//GCD-By-Binary, B
		cout << "Case (" << arrA[i] << ", " << arrB[i] << "): GCD-By-Binary = "
		<< B(arrA[i], arrB[i], c[3]); 
		cout << ", taking " << c[3] << " iterations" << endl;
		//GCD-By-Euclid, E
		cout << "Case (" << arrA[i] << ", " << arrB[i] << "): GCD-By-Euclid = "
		<< E(arrA[i], arrB[i], c[4]);
		cout << ", taking " << c[4] << " iterations" << endl;
		i++;
	}
}

int RS(longint a, longint b, int& c)
{
	for(int i = min(a, b); i >= 1; i--)
	{
		c++;
		if(a % i == 0 && b % i == 0)
			return i;
	}
	return 1;
}
int F(longint a, longint b, int& c)
{
	for(int i = 2; i <= min(a, b); i++)
	{
		c++;
		if(a % i == 0 && b % i == 0)
			return i * F( (a/i), (b/i), c );
	}
	return 1;
}
int FF(longint a, longint b, int s, int& c)
{
	for(int i = s; i <= min(a , b); i++)
	{
		c++;
		if(a % i == 0 && b % i == 0)
			return i * FF( (a/i), (b/i), i, c );
	}
	return 1;
}
int B(longint a, longint b, int& c)
{

    longint n, m;
    longint ans(1);

    if (a < b){
        n = a; m = b;
    }
    else{
        n = b; m = a;
    }

    while( n != 0 && m != 0 ){
        
        c++;
        if (n % 2 == 0){
            
            if (m % 2 == 0){
                ans *= 2;
                n /= 2;
                m /= 2;
            }
            else{
                n /= 2;
            }
        }
        else if (m % 2 == 0){
            m /= 2;
        }
        if (m < n){
            longint tmp;
            tmp = n; n = m; m = tmp;
        }
        m = m - n;
    } 
    return (n * ans);

}
int E(longint a, longint b, int& c)
{
  	longint n, m;
	if(a < b){
		n = a; m = b;
	}
	else{
		n = b; m = a;
	}
	
	while(!((m % n) == 0))
	{
		c++;
		longint temp = 0;
		temp = n;
		n = m % n;
		m = temp;
	}
	return n;

}