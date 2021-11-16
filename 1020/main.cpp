#include <iostream>
#define SSS 1000000000
using namespace std;

int main()
{
    int M,N;
    cin>>M;
    int res[M];
    for(int i=0;i<M;i++)
    {
        cin>>N;
        int r[N+1];
        int c[N+1];
        int m[N+1][N+1];
        for(int j=1;j<=N;j++)
        {
            cin>>r[j];
            cin>>c[j];
        }
        for(int j=1;j<=N;j++)
        {
            m[j][j]=0;
        }
        for(int j=1;j<=N-1;j++)
        {
            for(int k=1;k<=N-j;k++)
            {
                int l=k+j;
                m[k][l]=SSS;
                for(int s=k;s<=l-1;s++)
                {
                    int temp=m[k][s]+m[s+1][l]+r[k]*c[s]*c[l];
                    if(temp<m[k][l])
                    {
                        m[k][l]=temp;
                    }
                }
            }
        }
        res[i]=m[1][N];
    }
    for(int i=0;i<M;i++)
    {
        cout<<res[i]<<endl;
    }
}