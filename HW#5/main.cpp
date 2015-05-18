#include <iostream>
#include <cstdio>
#include <string>
#include "binomial_heap.h"
using namespace std;

int main()
{
    BinomialHeap<int> _bh;
    _bh.insert(1);
    _bh.insert(2);
    _bh.insert(3);
    _bh.insert(4);
    _bh.insert(5);
    _bh.insert(6);
    _bh.insert(7);
    _bh.insert(8);
    _bh.insert(9);
    _bh.pop();
    //printf("%d", _bh.trees[0]->element);
    /*int c, w;
      scanf("%d%d", &c, &w);
      string command;
      while( cin >> command )
      {
      if(command == "assign")
      {   //BH tmp(T element);
      int cm = -1, id = -1, p = -1;
      scanf("%d%d%d", &cm, &id, &p);
      }
      else if(command == "execute")
      {   //traversal
      int cm = -1;
      scanf("%d", &cm);
      }
      else if(command == "merge")
      {   //merge
      int cm1 = -1, cm2 = -1;
      scanf("%d%d", &cm1, &cm2);
      }
      else
      {
      printf("ERROR\n");
      return false;
      }
      }*/
    return 0;
}
