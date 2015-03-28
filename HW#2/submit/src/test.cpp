// unordered_map::hash_function
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

typedef unordered_map<string,int> stringmap;

int main ()
{
  stringmap mymap;

  stringmap::hasher fn = mymap.hash_function();
  int a = 32322928;
  int b = 2929922;

  std::cout << "32322928: " << fn ((string)a) << std::endl;
  std::cout << "2929922: " << fn ((string)b) << std::endl;

  return 0;
}
