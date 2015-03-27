#include <iostream>
using namespace std;

void func(int a[], int i, int len)
{
    if(i == len - 1) return;
    if(a[i] % 2 == 0) //only care about even number
    {
        int temp = a[i];
        for(int j = i - 1; j >= 0; j--)
        {
            a[j + 1] = a[j]; //move elements backward
        }
        a[0] = temp;
    }
    func(a, i + 1, len); //recursion
}
void func(int a[], int len)
{
    for(int i = 0; i < len; i++) //in single loop
    {
        if(a[i] % 2 == 0)
        {
            int temp = a[i];
            for(int j = i - 1; j >= 0; j--)
            {
                a[j + 1] = a[j];
            }
            a[0] = temp;
        }
    }
}

int main(){

    int a[11] = {1, 298, 46, 3, 529, 44, 67, 2, 92, 5, 11};
    func(a, 11);
    for(int i = 0; i < 11; i++)
        cout << a[i] << endl;
}
