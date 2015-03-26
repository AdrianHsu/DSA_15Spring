#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

//The code should take two 4-byte integers a and b 
//To prevent overflowing in multiplication, use unsign long int
typedef unsigned long int longint;

//function prototype
int RS(longint, longint, longint&);
int F(longint, longint, longint&);
int FF(longint, longint, int, longint&);
int B(longint, longint, longint&);
int E(longint, longint, longint&);

bool _b_is_zero(longint b)
{
	if(b == 0) return true;
	return false;
}

int main()
{
	longint arrA[1] = {11260};
	longint arrB[2261];
	int i = 0; // i represents arr element position
	//from the standard input per line until reaching a = 0
	//input loop
	for(int j = 0; j <= 2260; j++)
	{
		arrB[j] = j + 52000;
	}
	longint **result = new longint *[5];
	for(int k = 0; k < 5; k++)
		result[k] = new longint[2260];
	//output loop
	while(i <= 2260)
	{
		if( _b_is_zero(arrB[i]) )
		{
			cout << "Case (" << arrA[0] << ", " << arrB[i] << "): GCD-By-Reverse-Search = 0, taking 0 iterations" << endl;
			cout << "Case (" << arrA[0] << ", " << arrB[i] << "): GCD-By-Filter = 0, taking 0 iterations" << endl;
			cout << "Case (" << arrA[0] << ", " << arrB[i] << "): GCD-By-Filter-Faster = 0, taking 0 iterations" << endl;
			cout << "Case (" << arrA[0] << ", " << arrB[i] << "): GCD-By-Binary = 0, taking 0 iterations" << endl;
			cout << "Case (" << arrA[0] << ", " << arrB[i] << "): GCD-By-Euclid = 0, taking 0 iterations" << endl;
			i++;
			continue;
		}
		longint c[5] = {0};
		//GCD-By-Reverse-Search, RS
		cout << "Case (" << arrA[0] << ", " << arrB[i] << "): GCD-By-Reverse-Search = "
		<< RS(arrA[0], arrB[i], c[0]);
		cout << ", taking " << c[0] << " iterations" << endl;
		//GCD-By-Filter, F
		cout << "Case (" << arrA[0] << ", " << arrB[i] << "): GCD-By-Filter = "
		<< F(arrA[0], arrB[i], c[1]);
		cout << ", taking " << c[1] << " iterations" << endl;
		//GCD-By-Filter-Faster, FF
		cout << "Case (" << arrA[0] << ", " << arrB[i] << "): GCD-By-Filter-Faster = "
		<< FF(arrA[0], arrB[i], 2, c[2]);
		cout << ", taking " << c[2] << " iterations" << endl;
		//GCD-By-Binary, B
		cout << "Case (" << arrA[0] << ", " << arrB[i] << "): GCD-By-Binary = "
		<< B(arrA[0], arrB[i], c[3]); 
		cout << ", taking " << c[3] << " iterations" << endl;
		//GCD-By-Euclid, E
		cout << "Case (" << arrA[i] << ", " << arrB[i] << "): GCD-By-Euclid = "
		<< E(arrA[i], arrB[i], c[4]);
		cout << ", taking " << c[4] << " iterations" << endl;
		for(int a = 0; a < 5; a++)
				result[a][i] = c[a];
		i++;
	}
	longint average[5] = {0, 0, 0, 0, 0};
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j <= 2260; j++)
			average[i] += result[i][j];
		average[i] /= 2261;
		cout << "Algorithm " << i + 1 <<": taking " << average[i] << " iterations" << endl;
	}
}

int RS(longint a, longint b, longint& c)
{
	for(int i = min(a, b); i >= 1; i--)
	{
		c++;
		if(a % i == 0 && b % i == 0)
			return i;
	}
	return 1;
}
int F(longint a, longint b, longint& c)
{
	for(int i = 2; i <= min(a, b); i++)
	{
		c++;
		if(a % i == 0 && b % i == 0)
			return i * F( (a/i), (b/i), c );
	}
	return 1;
}
int FF(longint a, longint b, int s, longint& c)
{
	for(int i = s; i <= min(a , b); i++)
	{
		c++;
		if(a % i == 0 && b % i == 0)
			return i * FF( (a/i), (b/i), i, c );
	}
	return 1;
}
int B(longint a, longint b, longint& c)
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
int E(longint a, longint b, longint& c)
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