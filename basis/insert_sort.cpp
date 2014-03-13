#include <iostream>
using namespace std;

void sort(int *a, int n)
{
    int t, j;
    for(int i = 1; i < n; ++i)
    {
        t = a[i];
        j = i - 1;
        while(j > -1 && a[j] > t)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = t;
    }
}

int main()
{
    int a[5] = {5,4,3,2,1};
    sort(a, 5);

    for(int i = 0; i < 5; ++i)
        cout << a[i] << endl;
}
