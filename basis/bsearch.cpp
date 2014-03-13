#include <iostream>
using namespace std;

int bsearch(int *a, int n, int x)
{
    if(!a || n < 1)
        return -1;

    int l = 0, r = n-1;

    while(l <= r)
    {
        int m = (l + r) / 2;
        if(a[m] == x)
            return m;
        else if(a[m] > x)
            r = m - 1;
        else
            l = m + 1;
    }
    
    return -1;
}

int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};

    cout << bsearch(a, 10, -1) << endl;
}
