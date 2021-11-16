#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int dp[50001][2],father[50001];
vector<int> Black[50001];

void GetMaxBlack(int u)
{
    dp[u][0]=0;
    dp[u][1]=1;
    for(int i=0;i<Black[u].size();i++)
    {
        int temp=Black[u][i];
        GetMaxBlack(temp);
        dp[u][0]+=max(dp[temp][0],dp[temp][1]);
        dp[u][1]+=dp[temp][0];
    }
}

int main()
{
    int T;
    cin>>T;
    int res[T];
    int N,u,v;
    for(int l=0;l<T;l++)
    {
        cin >> N;
        memset(dp,0,sizeof(dp));
        memset(father,0,sizeof(father));
        memset(Black,0,sizeof(Black));
        for (int i = 1; i < N; i++)
        {
            cin >> u >> v;
            father[v]=u;
            Black[u].push_back(v);
        }
        for(int i=1;i<=N;i++){
            if(father[i]==0)
            {
                GetMaxBlack(i);
                res[l]=max(dp[i][0],dp[i][1]);
            }
        }

    }
    for(int i=0;i<T;i++)
    {
        cout<<res[i]<<endl;
    }
    return 0;
}
