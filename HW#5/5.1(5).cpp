typedef unsigned long long int longint;

// O(1) Time Complexity
longint postfixHash(string str,int k); 

int binary_search(string str_1, string str_2)
{
    int left = 0;
    int right = str.size() - 1;
    while( left <= right )
    {
        int mid = (left + right) / 2;

        if(postfixHash(str_1, mid) != postfixHash(str_2, mid))
        {
            if(str_1.size() == 1)
                return mid;
            else
                left = mid + 1;
        }
        else // (postfixHash(str_1, mid) == postfixHash(str_2, mid))
            right = mid - 1;
    }
    return "KEY_NOT_FOUND";
}

