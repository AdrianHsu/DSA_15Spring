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
bool find_threshold(vector< Data >&, int &,int &,int&, double, double &, double &);

void imput(vector< Data > &, char**);
void print(vector< Data >, double);
void build_tree(vector< Data >, double, int);

int main(int argc, char** argv)
{
    vector < Data > data_set;
    imput(data_set, argv);

    vector< Data >::iterator erase_it;
    sort(data_set.begin(), data_set.end(), cmp); // sort by index == 0
    erase_it = unique(data_set.begin(), data_set.end(), unique_func);
    data_set.erase(erase_it, data_set.end());

    double epsilon = atoi(argv[2]);
    print(data_set, epsilon);
    /*cout << data_set.size() << endl;
      cout << data_set[1].attr[0] << endl;
      cout << data_set[1].attr[1] << endl;
      cout << data_set[1].label << endl;*/

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
bool find_threshold(vector< Data > &data_set, int &min_idx,int &min_j,int &label, 
                    double e, double &min_threshold, double &min_confusion)
{
    for(int i = 0; i < MAX_FEATURE; i++)
    {
        int a = 0, b = 0, c = 0, d = 0; //aY + bN = (c + d)Y + (e + f)N
        for(int j = 0; j < data_set.size(); j++)
        {
            data_set[j].idx = i;
            if(data_set[j].label == +1) a++;
            else if(data_set[j].label == -1) b++;
        }
        sort(data_set.begin(), data_set.end(), cmp);
        //min_threshold = data_set[0].attr[i] - 1;
        if(confusion(a, b) <= e || a == 0 || b == 0)
        {
            label = (a > b? +1 : -1);
            min_idx = i;
            min_j = 0; //don't care
            min_threshold = 0; //don't care
            min_confusion = confusion(a, b);
            return false;
        }
        for(int j = 0; j < data_set.size(); j++)
        {
            if(data_set[j].label == +1) c++;
            else if(data_set[j].label == -1) d++;

            double t = t_confusion(c, d, a - c, b - d);
            if(t < min_confusion)
            {
                min_idx = i;
                min_j = j;
                if(j >= 0 && (data_set.size() - 1) > j)
                    min_threshold = (data_set[j].attr[i] + data_set[j + 1].attr[i]) / 2;
                else if(j == data_set.size() - 1)
                    min_threshold = data_set[j].attr[i] + 1;
                min_confusion = t;
            }
        }
    }
    for(int j = 0; j < data_set.size(); j++)
        data_set[j].idx = min_idx;
    sort(data_set.begin(), data_set.end(), cmp);
    /*cout << min_idx << endl;
      cout << min_j << endl;
      cout << min_threshold << endl;
      cout << min_confusion << endl;*/
    return true;
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
void print(vector < Data > data_set, double e)
{
    printf("int tree_predict(double *attr)\n{\n");
    build_tree(data_set, e, 1);
    printf("}");
}
void build_tree(vector < Data > data_set, double e, int recur)
{
    int min_idx = 0, min_j = 0, label = 1;
    double min_threshold = 0, min_confusion = 1;
    bool flag = find_threshold(data_set, min_idx, min_j, label, e, min_threshold, min_confusion);
    vector < Data > set_1(data_set.begin(), data_set.begin() + min_j + 1); //(, ]
    vector < Data > set_2(data_set.begin() + min_j + 1, data_set.end());
    
    /*cout << set_1.size() << endl;
    cout << set_2.size() << endl;
    cout << data_set[39].attr[0] << endl;
    cout << set_1[39].attr[0] << endl;
    cout << set_2[0].attr[0] << endl;*/
    if(!flag)
    {
        for(int i = 0; i < recur; i++)
            printf("\t");
        printf("return %d;\n",label);
        /*for(int i = 0; i < recur - 1; i++)
            printf("\t");*/
        //printf("\n");
        return;
    }
    else
    {
        for(int i = 0; i < recur; i++)
            printf("\t");
        printf("if(attr[%d] <= %lf)\n", min_idx, min_threshold);
        
        for(int i = 0; i < recur; i++)
            printf("\t");
        printf("{\n");
        
        build_tree(set_1, e, recur + 1); //left tree
        for(int i = 0; i < recur; i++)
            printf("\t");
        printf("}\n");

        for(int i = 0; i < recur; i++)
            printf("\t");        
        printf("else\n");
        for(int i = 0; i < recur; i++)
            printf("\t");        
        printf("{\n");
        
        build_tree(set_2, e, recur + 1); //right tree
        for(int i = 0; i < recur; i++)
            printf("\t");     
        printf("}\n");
    }
}
