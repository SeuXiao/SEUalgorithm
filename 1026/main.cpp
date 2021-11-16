#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int M;
    cin>>M;
    long long res[M];
    int N,K;
    for(int l=0;l<M;l++)
    {
        cin>>N>>K;
        int a[N+1];
        for(int j=1;j<=N;j++) cin>>a[j];
        long long sumda[N+1][N+1];
        long long F[N+1][K+1];
        for(int i=1;i<=N;i++)
        {
            for(int j=i;j<=N;j++)
            {
                int sum=0;
                for(int k=i;k<=j;k++) sum+=a[k];
                sumda[i][j]=sum;
            }
        }
        for(int i=1;i<=N;i++) F[i][0]=sumda[1][i];
        for(int k=1;k<=K;k++)
        {
            for(int i=k+1;i<=N;i++)
            {
                F[i][k]=-1;
                for(int s=k;s<i;s++)
                {
                    F[i][k]=max(F[i][k],F[s][k-1]*sumda[s+1][i]);
                }
            }
        }
        res[l]=F[N][K];
    }
    for(int i=0;i<M;i++)
    {
        cout<<res[i]<<endl;
    }
    return 0;
}