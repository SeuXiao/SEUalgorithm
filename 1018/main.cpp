#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int M;
    cin>>M;
    int maxvalue[M];
    for(int i=0;i<M;i++)
    {
        int N,C;
        cin>>N>>C;
        int size[N+1];
        int value[N+1];
        for(int j=1;j<=N;j++)
        {
            cin>>size[j]>>value[j];
        }
        int res[C+1];
        res[0]=0;
        for(int j=1;j<=C;j++)
        {
            res[j]=-1000000;
        }
        for(int j=1; j <= N; j++)
        {
            for(int k=C; k >= size[j]; k--)
            {
                res[k]=max(res[k], res[k - size[j]] + value[j]);
            }
        }
        maxvalue[i]=res[C];
    }
    for(int i=0;i<M;i++)
    {
        cout<<maxvalue[i]<<endl;
    }
    return 0;
}