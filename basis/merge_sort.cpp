#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

void merge(int *a, int *t, int l, int m, int r)
{
    memcpy(t + l, a + l, sizeof(int) * (m - l + 1));
    memcpy(t + m + 1, a + m + 1, sizeof(int) * (r - m));

    int i = l, j = m+1, k = i;
    while(true)
    {
        if(i <= m && j <= r)
            a[k++] = t[i] < t[j] ? t[i++] : t[j++];
        else if(i > m)
        {
            memcpy(a + k, t + j, sizeof(int) * (r - j + 1));
            break;
        }
        else
        {
            memcpy(a + k, t + i, sizeof(int) * (m - i + 1));
            break;
        }
    }
}

void msort(int *a, int *t, int l, int r)
{
    if(l == r)
        return;

    int m = (l + r) / 2;
    msort(a, t, l, m);
    msort(a, t, m+1, r);
    merge(a, t, l, m, r);
}

void sort(int *a, int n)
{
    int *t = (int*)malloc(n * sizeof(int));
    int l = 0, r = n-1, m = (l + r) / 2;
    msort(a, t, l, m);
    msort(a, t, m+1, r);
    merge(a, t, l, m, r);
}

int main()
{
    int a[100] = {-829, -900, 172, 890, -225, 881, -748, -16, -886, -931, 47, -805, -25, 917, -22, -971, -950, -852, 712, -424, -577, 557, -712, -933, -843, 770, 422, 888, -253, -485, 958, 361, 360, -669, -628, -902, 210, 232, 407, 609, 585, -600, 151, -320, 230, 506, -731, -349, -644, 74, -685, -194, -824, -770, 274, -336, 8, -780, -937, 561, 270, 589, -347, 237, 75, 817, -758, -17, -99, 141, -415, 518, -715, -802, 191, -635, 21, -394, -975, 740, -551, -8, 122, 354, 998, 702, 478, -586, 686, 839, 344, -373, 398, 102, 626, 453, 222, 536, 567, 505};
    sort(a, 100);

    for(int i = 0; i < 100; ++i)
        cout << a[i] << endl;
}
