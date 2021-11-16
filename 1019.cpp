#include <iostream>
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
        int size[N];
        int value[N];
        for(int j=0;j<N;j++)
        {
            cin>>size[j]>>value[j];
        }
        int res[C+1];
        for(int j=0;j<C+1;j++)
        {
            res[j]=0;
        }
        for(int m=0;m<N;m++)
        {
            for(int n=C;n>=size[m];n--)
            {
                res[n]=res[n]>(res[n-size[m]]+value[m])?res[n]:(res[n-size[m]]+value[m]);
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