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

    double epsilon = atof(argv[2]);
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
    int a = 0, b = 0, c = 0, d = 0;
    for(int i = 0; i < data_set.size(); i++)
    {
        if(data_set[i].label == +1) a++;
        else if(data_set[i].label == -1)b++;
    }
    if(confusion(a, b) <= e || (a == 0 || b == 0))
    {
        label = (a > b? +1 : -1);
        return false;
    }
    int total = 0;
    for(int i = 0; i < MAX_FEATURE; i++)
    {
        total = 0;
        bool _same = true;
        double tmp = data_set[0].attr[i];
        for(int j = 0; j < data_set.size(); j++)
        {
            data_set[j].idx = i;
            if(data_set[j].attr[i] != tmp)
                _same = false;
        }
        if(_same)
        {
            total++;
            continue;
        }

        sort(data_set.begin(), data_set.end(), cmp);
        
        c = 0, d = 0;
        vector< int > j_vector;
        for(int j = 0; j < data_set.size(); j++)
        {
            if(data_set[j].label == +1) c++;
            else if(data_set[j].label == -1) d++;
            if(j + 1 < data_set.size())
                if(data_set[j].attr[i] == data_set[j + 1].attr[i])
                {
                    continue;
                }
            double t = t_confusion(c, d, a - c, b - d);
            if(t < min_confusion)
            {
                min_idx = i;
                min_j = j;
                min_confusion = t;

                if(!j_vector.empty())
                    j_vector.clear();
            }
            else if(t == min_confusion)
            {
                j_vector.push_back(min_j);
            }
        }
        if(!j_vector.empty())
        {
            srand(time(NULL));
            int count = rand() % j_vector.size();
            min_j = j_vector[count];
        }
    }
    if(total == MAX_FEATURE)
    {
        cout << "//ERROR" << endl;// unique so that every node is different
        label = 0;
        return false;
    }    
    for(int j = 0; j < data_set.size(); j++)
        data_set[j].idx = min_idx;
    sort(data_set.begin(), data_set.end(), cmp); 
    if(min_j >= 0 && (data_set.size() - 1) > min_j)
        min_threshold = (data_set[min_j].attr[min_idx] + data_set[min_j + 1].attr[min_idx]) / 2;
    else if(min_j == data_set.size() - 1)
        min_threshold = data_set[min_j].attr[min_idx] + 1;
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
    vector < Data > set_1(data_set.begin(), data_set.begin() + min_j + 1); //[, )
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
        if(min_idx == 12 && min_threshold == 6)
        {    
            /*cout << "//min_idx: " << min_idx << endl;
            cout << "//min_j: " << min_j << endl;
            cout << "//min_threshold: " << min_threshold << endl;
            cout << "//data_set.size: " << data_set.size() << endl;
            cout << "//set_1.size: " << set_1.size() << endl;
            cout << "//set_2.size: " << set_2.size() << endl;
            cout << "//min_confusion: " << min_confusion << endl;
            for(int k = 0; k < data_set.size(); k++)
                cout << "//" << data_set[k].attr[min_idx] << " " << min_idx << endl;*/
        }
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
