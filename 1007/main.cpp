#include<iostream>
#include "string.h"
using namespace std;
int main()
{
    int M;
    int K;
    int N;
    cin>>M;
    int result[41][7];
    int *res=new int [M];
    int num[41][41];
    for(int i=0;i<M;i++)
    {
        cin>>N>>K;
        memset(result,0,sizeof(result));
        memset(num,0,sizeof(num));
        char szc[41];
        cin >> szc;
        for(int i=0;i<N;i++)
        {
            int tempnum=0;
            for(int j=i;j<N;j++)
            {
                tempnum= tempnum * 10 + szc[j] - '0';
                num[i][j]=tempnum;
            }
        }
        for(int i=0;i<N;i++)
        {
            result[i][0]=num[0][i];
        }
        for(int i=0;i<N;i++)
        {
            for(int m=1;m<=K;m++)
            {
                for(int n=0;n<i;n++)
                {
                    result[i][m]=result[n][m-1]*num[n+1][i]>result[i][m]?result[n][m-1]*num[n+1][i]:result[i][m];
                }
            }
        }
        res[i]=result[N - 1][K];
    }
    for(int i=0;i<M;i++) 
    {
        cout<<res[i]<<endl;
    }
    delete []res;
    return 0;
}