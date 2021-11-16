#include<iostream>
#include<vector>
#include<queue>
#define MY_MAX 2147483647
using namespace std;
int n,e,s,t,m,T,b[501],ans;
long long minCost[501];
bool visited[501];
vector<int> to[501],weight[501];
typedef pair<int,int> Node;
priority_queue<Node,vector<Node>,greater<Node> >q;
void dfs(int u,int ds,int c)
{
    if(c+minCost[u]>m)return;
    if(ds>ans)return;
    if(u==t)
    {
        ans=min(ans,ds);
        return;
    }
    for(int i=0;i<to[u].size();++i)
    {
        int v=to[u][i],w=weight[u][i];
        if(visited[v])continue;
        visited[v]=1;
        dfs(v,ds+w,c+b[v]);
        visited[v]=0;
    }
}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>e>>s>>t>>m;
        for(int i=1;i<=n;++i)
        {
            to[i].clear();
            weight[i].clear();
        }
        for(int i=1;i<=n;++i)cin>>b[i];
        for(int i=1;i<=n;++i)minCost[i]=MY_MAX;
        for(int i=1;i<=n;++i)visited[i]=0;
        minCost[t]=0;ans=MY_MAX;
        q.push(Node(0,t));
        for(int i=1;i<=e;++i)
        {
            int u,v,w;
            cin>>u>>v>>w;
            to[u].push_back(v);
            weight[u].push_back(w);
            to[v].push_back(u);
            weight[v].push_back(w);
        }
        while(!q.empty())
        {
            int u=q.top().second;
            q.pop();
            if(visited[u])continue;
            visited[u]=1;
            for(int i=0;i<to[u].size();++i)
            {
                int v=to[u][i],w=b[u];
                if(minCost[u]+w<minCost[v])
                {
                    minCost[v]=minCost[u]+w;
                    q.push(Node(minCost[v],v));
                }
            }
        }
        if(minCost[s]>m)
        {
            cout<<-1<<endl;
            continue;
        }
        for(int i=1;i<=n;++i)visited[i]=0;
        visited[s]=1;
        dfs(s,0,0);
        cout<<ans<<endl;
    }
}