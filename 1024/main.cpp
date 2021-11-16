#include <iostream>
#include<iomanip>
#include<string.h>
using namespace std;
double arr[502][502];
double brr[502][502];
int main()
{
    int M,N;
    cin>>M;
    double res[M];
    for(int i=0;i<M;i++)
    {
        cin >> N;
        int key[N+1];
        for (int j = 1; j <=N; j++)
        {
            cin >> key[j];
        }
        double p[N+1];
        double q[N + 1];
        for (int j = 1; j <=N; j++)
        {
            cin >> p[j];
        }
        for (int j = 0; j <= N; j++)
        {
            cin >> q[j];
        }
        memset(brr, 0, sizeof(brr));
        memset(arr, 0, sizeof(arr));
        for(int j=1;j<=N+1;j++)
        {
            brr[j][j - 1]=0;
            arr[j][j - 1]=q[j - 1];
        }
        for(int t=0;t<N;t++)
        {
            for(int l=1;l<=N-t;l++)
            {
                int j=l+t;
                arr[l][j]= arr[l][j - 1] + p[j] + q[j];
                brr[l][j]=brr[l + 1][j];
                for(int k=l+1;k<=j;k++)
                {
                    if((brr[l][k - 1] + brr[k + 1][j]) < brr[l][j])
                        brr[l][j]= brr[l][k - 1] + brr[k + 1][j];
                }
                brr[l][j]+=arr[l][j];
            }
        }
        res[i]=brr[1][N];
    }
    for(int j=0;j<M;j++)
    {
        cout<<fixed<<setprecision(6)<<res[j]<<endl;
    }

}