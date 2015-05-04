#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <vector>

//#include "Node.h"

using namespace std;
#define MAX_FEATURE (1024+1)

class Data{

public:
    Data(int _label, double* features)
        :attr(features), label(_label){};

    double* attr;
    int label;
};

int main(int argc, char** argv) {

    vector < Data > data_set;

    std::ifstream fin;
    string istring;
    fin.open(argv[1]);

    while (std::getline(fin, istring)) {
    
        double* features = new double[MAX_FEATURE];
        char *cstring, *tmp;
        int _label;
        memset(features, 0, sizeof(double) * MAX_FEATURE);

        cstring = new char[istring.size() + 1];
        strncpy(cstring, istring.c_str(), istring.size()+1);

        tmp =  strtok(cstring, ": ");
        _label = atoi(tmp);
        tmp = strtok(NULL, ": ");

        while(tmp != NULL) {
            int id = atoi(tmp);
            tmp = strtok(NULL, ": ");
            features[id - 1] = atof(tmp);
            tmp = strtok(NULL, ": ");
        }
        Data data(_label, features);

        data_set.push_back(data);        
        delete[] cstring;
    }
    /*cout << data_set.size() << endl;
    cout << data_set[69].attr[0] << endl;
    cout << data_set[69].attr[1] << endl;
    cout << data_set[69].attr[2] << endl;*/

    return 0;
}
