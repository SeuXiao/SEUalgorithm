#include <iostream>
using namespace std;

int main()
{
    int M,N;
    cin>>M;
    int MaxSub[M];
    for(int i=0;i<M;i++) {
        cin>>N;
        int arr[N];
        for(int j=0;j<N;j++)
        {
            cin>>arr[j];
        }
        int sub = 0;
        int maxsub=arr[0];
        for (int k = 0; k < N;k++)
        {
            sub=(sub+arr[k])>arr[k]?(sub+arr[k]):arr[k];
            maxsub=maxsub>sub?maxsub:sub;
        }
        MaxSub[i]=maxsub;
    }
    for(int i=0;i<M;i++)
    {
        cout<<MaxSub[i]<<endl;
    }
    return 0;
}