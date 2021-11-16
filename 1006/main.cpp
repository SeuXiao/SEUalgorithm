#include <iostream>
using namespace std;
const int defaultSize =20;
template <class T>
class MinHeap
{
public:
    MinHeap(T arr[],int n);
    ~MinHeap(){delete[]heap;}
    void siftDown(int start,int m);
    void siftUp(int start);
    T *heap;
private:
    int currentSize;
    int maxHeapSize;
};

template<class T>
MinHeap<T>::MinHeap(T arr[], int n)
{
    maxHeapSize=(defaultSize<n)?n:defaultSize;
    heap=new T[maxHeapSize];
    if(heap==NULL)
    {
        cerr<<"堆存储分配失败！"<<endl;
        exit(1);
    }
    for(int i=0;i<n;i++) heap[i]=arr[i];
    currentSize=n;
    int currentPos=(currentSize-2)/2;
    while(currentPos>=0)
    {
        siftDown(currentPos,currentSize-1);
        currentPos--;
    }
}

template<class T>
void MinHeap<T>::siftDown(int start,int m)
{
    int i=start,j=2*i+1;
    T temp=heap[i];
    while(j<=m)
    {
        if(j<m&&heap[j]>heap[j+1]) j++;
        if(temp<=heap[j]) break;
        else{heap[i]=heap[j];i=j;j=2*j+1;}
    }
    heap[i]=temp;
}


int main()
{
    int m,n;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>n;
        int data[n];
        for(int j=0;j<n;j++)
        {
            cin>>data[j];
        }
        MinHeap<int> mheap(data, n);
        for (int j = 0; j <n; j++) {
            data[j] = mheap.heap[n - j - 1];
        }
        for(int j=n-1;j>=0;j--)
        {
            cout<<data[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

