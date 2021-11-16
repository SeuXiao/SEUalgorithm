#include <iostream>
#include <algorithm>
#include <string.h>
#define SSS -10000000
using namespace std;


int main()
{
    int m,n,k;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>n>>k;
        int p[100000];
        memset(p,0, sizeof(p));
        int temp1,temp2;
        for(int j=1;j<=k;j++)
        {
            cin>>temp1;
            cin>>temp2;
            p[temp1]=temp2;
        }
        int r[n+1];
        r[0]=0;
        for(int j=1;j<=n;j++)
        {
            int temp=SSS;
            for(int l=1;l<=j;l++)
            {
                temp=max(temp,p[l]+r[j-l]);
            }
            r[j]=temp;
        }
        cout<<r[n]<<endl;
    }
}