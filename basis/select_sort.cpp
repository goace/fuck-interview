#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void sort(int *a, int n)
{
    int min, index;
    for(int i = 0; i < n-1; ++i)
    {
        min = a[i];
        index = i;

        for(int j = i+1; j < n; ++j)
        {
            if(a[j] < min)
            {
                index = j;
                min = a[j];
            }
        }
        swap(&a[i], &a[index]);
    }
}

int main()
{
    int a[5] = {5,4,3,2,1};
    sort(a, 5);

    for(int i = 0; i < 5; ++i)
        cout << a[i] << endl;
}
