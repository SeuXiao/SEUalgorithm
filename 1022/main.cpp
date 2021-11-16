#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int M;
    cin>>M;
    int maxL[M];
    for(int i=0;i<M;i++) maxL[i]=0;
    for(int i=0;i<M;i++)
    {
        string s1,s2;
        cin>>s1;
        cin>>s2;
        int l1=s1.size();
        int l2=s2.size();
        int len[l1+1][l2+1];
        for(int j=0;j<=l1;j++)
            for(int k=0;k<=l2;k++)
                len[j][k]=0;
        for(int j=1;j<=l1;j++)
        {
            for (int k=1; k <= l2; k++)
            {
                if (s1[j-1] == s2[k-1]) {len[j][k] = len[j-1][k-1] + 1;}
                else {len[j][k] = max(len[j-1][k], len[j][k -1]);}
            }
        }
        maxL[i] = len[l1][l2];
    }
    for(int i=0;i<M;i++) cout<<maxL[i]<<endl;
    return 0;
}