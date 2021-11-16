#include <iostream>
using namespace std;

int main()
{
    int T;
    int n,m;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>n>>m;
        int numsofn;
        int women[n+1][m+1];
        for(int j=0;j<n;j++)
        {
            cin>>numsofn;
            for(int k=0;k<numsofn;k++)
            {
                cin>>women[j][k];
            }
        }
        
    }
}