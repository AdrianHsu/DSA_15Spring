#include <iostream>
using namespace std;

int& sub1(int& a, int& b){

    int* pc = new int;
    *pc = a - b;
    return *pc;
}
int main(){

    int a = 3;
    int b = 1;
    cout << sub1(a, b);
    return 0;
}
