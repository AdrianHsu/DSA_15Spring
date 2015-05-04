#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX_FEATURE (1024+1)

class Data {
    public:
        Data(int _label, double* features)
            :attr(features), label(_label), idx(0){};

        double* attr;
        int label;
        int idx;
};

bool cmp(Data& a, Data& b)
{
    return a.attr[a.idx] < b.attr[a.idx];
}
bool unique_func(Data a, Data b)
{
    if(a.label == b.label)
    {
        for(int i = 0; i < MAX_FEATURE; i++)
            if(a.attr[i] != b.attr[i])
                return false;
        return true;
    }
    return false;
}
double confusion(int, int);
double t_confusion(int, int, int, int);

void imput(vector< Data > &, char**);
void build_tree(vector< Data >, double);


int main(int argc, char** argv)
{
    vector < Data > data_set;
    imput(data_set, argv);

    double epsilon = atoi(argv[2]);
    vector< Data >::iterator erase_it;
    sort(data_set.begin(), data_set.end(), cmp); // sort by index == 0
    erase_it = unique(data_set.begin(), data_set.end(), unique_func);
    data_set.erase(erase_it, data_set.end());

    build_tree(data_set, epsilon);
    cout << data_set.size() << endl;
      cout << data_set[1].attr[0] << endl;
      cout << data_set[1].attr[1] << endl;
      cout << data_set[1].label << endl;

    return 0;
}
double confusion(int a, int b)
{
    if(a == 0 && b == 0)
        return 0;
    double _a = a;
    double _b = b;
    return 1 - (_a / (_a + _b)) * (_a / (_a + _b)) - (_b / (_a + _b)) * (_b / (_a + _b)) ;
}
double t_confusion(int c, int d, int e, int f)
{
    double total = c + d + e + f;
    double c_add_d = c + d;
    double e_add_f = e + f;
    if(total == 0)
        return 0;
    return ( c_add_d / total ) * confusion(c, d) + ( e_add_f / total ) * confusion(e, f) ;
}
void imput(vector< Data > &data_set, char** argv)
{
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
}
void build_tree(vector < Data > data_set, double e)
{
    
}
