#include <iostream>
#include <vector>
using namespace std;

class Heap
{
    public:
        Heap(int *a, int n):arr(a, a+n){arr.insert(arr.begin(), 0);}
        void build();
        int pop();
        int insert(int x);
        vector<int> arr;

    private:
        void make(int root);
        void swap(int *a, int *b);
};

void Heap::swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void Heap::make(int root)
{
    int min;
    while(root <= (arr.size() - 1) / 2)
    {
        min = root*2;
        if(root * 2 + 1 <= arr.size() - 1 && arr[root*2] > arr[root*2 + 1]) min++;
        
        if(arr[root] < arr[min]) return;
        
        swap(&arr[root], &arr[min]);
        root = min;
    }
}

//O(n)
void Heap::build()
{
    size_t length = arr.size() - 1;

    for(int i = length/2; i > 0; --i)
        make(i);
}

//O(lg(n))
int Heap::pop()
{
    int res = arr[1];
    swap(&arr[1], &arr[arr.size() - 1]);
    arr.pop_back();

    make(1);
    return res;
}

//O(lg(n))
void insert(int x)
{}


int main()
{
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    Heap min(a, 10);
    min.build();
    //for(int i = 0; i < 10; ++i)
        //cout << min.arr[i] << endl; 
    cout << min.pop() << endl;
    cout << min.pop() << endl;
    cout << min.pop() << endl;
    cout << min.pop() << endl;
}
