#include <iostream>
#include<cstdlib>
using namespace std;
long long cost[100001];
long long yield[100001];
long long dp[100001];
const int defaultSize =20;

template <class T>
class MinHeap
{
public:
    MinHeap(int sz=defaultSize);
    MinHeap(T arr[],int n);
    ~MinHeap(){delete[]heap;}
    bool Insert(long long int d);
    T getTop();
    bool Romove(T&d);
    bool IsEmpty()const
    {
        return currentSize==0;
    }
    bool IsFull() const
    {
        return currentSize==maxHeapSize;
    }
    void MakeEmpty(){currentSize=0;}
    void siftDown(int start,int m);
    void siftUp(int start);
    int getcurrentSize()
    {
        return currentSize;
    }
    T *heap;
private:
    int currentSize;
    int maxHeapSize;

};

template<class T>
MinHeap<T>::MinHeap(int sz)
{
    maxHeapSize=(defaultSize<sz)?sz:defaultSize;
    heap=new T[maxHeapSize];
    if(heap==NULL)
    {
        cerr<<"堆存储分配失败！"<<endl;
        exit(1);
    }
    currentSize=0;
}

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
template<class T>
bool MinHeap<T>::Romove(T &d)
{
    if(!currentSize){cout<<"Heap empty"<<endl;return false;}
    d=heap[0];
    cout<<d<<" ";
    heap[0]=heap[currentSize-1];
    heap[currentSize-1]=d;
    currentSize--;
    siftDown(0,currentSize-1);
    return true;
}

template<class T>
bool MinHeap<T>::Insert(long long int d)
{
    if(currentSize==maxHeapSize){cerr<<"Heap Full！"<<endl;return false;}
    heap[currentSize]=d;
    siftUp(currentSize);
    currentSize++;
    return true;
}

template<class T>
void MinHeap<T>::siftUp(int start)
{
    int j=start,i=(j-1)/2;
    T temp=heap[j];
    while(j>0)
    {
        if(heap[i]<=temp) break;
        else {heap[j]=heap[i];j=i;i=(i-1)/2;}
    }
    heap[j]=temp;
}

template<class T>
T MinHeap<T>::getTop()
{
    return heap[0];
}

int main()
{
    int l;
    cin>>l;
    int N;
    for (int test = 0; test < l; test++)
    {
        cin>>N;
        for (int i = 1; i <=N ; i++)
        {
            cin>>cost[i];
        }
        for (int i = 1; i <=N ; i++)
        {
            cin>>yield[i];
            dp[i]=0;
        }
        dp[1]=cost[1]*yield[1];
        MinHeap<long long int> hp(N+1);
        hp.Insert(cost[1]-1);
        for (int i = 2; i <= N; i++)
        {
            hp.Insert(cost[i]-i);
            dp[i]=dp[i-1]+yield[i]*(hp.getTop()+i);
        }
        cout<<dp[N]<<endl;
    }

}