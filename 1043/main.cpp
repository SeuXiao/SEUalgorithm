#include <iostream>
using namespace std;

int getF(int k,int n)
{
    int arr[k+1][n+1];
    int F=0;
    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<=n;j++)
        {
            arr[i][j]=0;
        }
    }
    while(arr[k][F]<n)
    {
        F++;
        for (int i = 1; i <= k; i++)
        {
            arr[i][F] = arr[i][F-1] +arr[i-1][F-1] + 1;
        }
    }
    return F;
}

int main()
{
    int M;
    cin>>M;
    int result[M];
    int K,N;
    for(int i=0;i<M;i++)
    {
        cin>>K>>N;
        result[i]=getF(K,N);
    }
    for(int i=0;i<M;i++)
    {
        cout<<result[i]<<endl;
    }
}
