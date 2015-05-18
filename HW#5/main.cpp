#include <iostream>
#include <cstdio>
#include <string>
#include "binomial_heap.h"
using namespace std;

int main()
{
    int c, w;
    scanf("%d%d", &c, &w);
    string command;
    while( cin >> command )
    {
        if(command == "assign")
        {
            int cm = -1, id = -1, p = -1;
            scanf("%d%d%d", &cm, &id, &p);
        }
        else if(command == "execute")
        {
            int cm = -1;
            scanf("%d", &cm);
        }
        else if(command == "merge")
        {
            int cm1 = -1, cm2 = -1;
            scanf("%d%d", &cm1, &cm2);
        }
        else
        {
            printf("ERROR\n");
            return false;
        }
    }
    return 0;
}
