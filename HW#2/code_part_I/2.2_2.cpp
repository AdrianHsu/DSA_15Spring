int get(int a[], int i, int j)
{
    return [( (i * (i - 1)) / 2) + j];
}
int put(int a[], int i, int j, int k)
{
    a[( (i * (i - 1)) / 2) + j] = k; // k = A[i][j], passed in main 
}

int main(){
    int A[][] , a[];
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= i ; j ++ )
            put( a , i , j , A[ i ][ j ] );
}
