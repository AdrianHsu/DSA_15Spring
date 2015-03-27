#include <iostream>
#include <cmath>
using namespace std;

int main(){

    long long int x = 149639105;
    bool flag = true;
    while(flag)
    {
        x--;
        int i = 2;
        while(x % i != 0 && i <= sqrt(x))
        {
            if((int)(sqrt(x)) == i)
            {
                flag = false;
                break;
            }
            i++;
        }
    }
    cout << x << endl;//ans: 149639071
    return 0;
}
