// unique algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::unique, std::distance
#include <vector>       // std::vector

using namespace std;
bool myfunction (int i, int j) {
    return (i==j);
}

int main () {

    std::cout << "start!" << std::endl;
    std::vector<int>::iterator eraseit;
    int myints[] = {10,10,20,20,20,20,20,30,30};           // 10 20 20 20 30 30 20 20 10
    std::vector<int> vch (myints,myints+9);


    std::sort(vch.begin(), vch.end());  //排序
    for (int i = 0; i < vch.size(); i++)
        std::cout << ' ' << vch[i];
    cout << endl;
    eraseit = std::unique(vch.begin(), vch.end(), myfunction);  //排不重覆元素
    for (int i = 0; i < vch.size(); i++)
        std::cout << ' ' << vch[i];
    cout << endl;
    vch.erase(eraseit, vch.end()); //沒被排到的刪掉
    for (int i = 0; i < vch.size(); i++)
        std::cout << ' ' << vch[i];
    cout << endl;

    return 0;
}
