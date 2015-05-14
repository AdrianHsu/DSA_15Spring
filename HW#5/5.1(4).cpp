// suppose heap T is realized by "Level Numbering" method
// that is: (see p.295)
// If v is the root of T,then f(v)= 1
// If v is the left child of node u, then f(v) = 2f(u)
// If v is the right child of node u, then f(v) = 2f(u) + 1

class Node {

    Node(int _k, DATATYPE _v)
        :key(_k), value(_v){};
    int key;
    DATATYPE value;
};
void dfs( Node heap[], int id, int k)
{
    if( heap[id].key > k ) return;
    cout << heap[id].value << " "; //head[id].key <= k
    dfs( heap, id * 2, k);
    dfs( heap, id * 2 + 1, k);
}
void findKeyLowerThanK( Node T[], int k )
{
    dfs( T, 1, k ); //1-based
}



