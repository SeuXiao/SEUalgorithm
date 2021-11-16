#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAXC=2147483647;
int n,E,s,t,M;
int u,v,w;
int B[501];
int nowmincost;
long long EAMincost[501];
int ifvisited[501];
vector<int> destination[501];
vector<int> EALengeth[501];
priority_queue<int,vector<int>,greater<int>>path;
void SHORTPATH()
{
    EAMincost[t]=0;
    nowmincost=MAXC;
    path.push(t);
    while(!path.empty())
    {
        int x=path.top();
        path.pop();
        if(ifvisited[x])continue;
        ifvisited[x]= 1;
        for(int i=0;i<destination[x].size();i++)
        {
            int y=destination[x][i];
            int GLF=B[x];
            if(EAMincost[y]>EAMincost[x]+GLF)
            {
                EAMincost[y]=EAMincost[x]+GLF;
                path.push(y);
            }
        }
    }
}
void SearchForSHORT(int x, int cos, int lf)
{
    if(cos>nowmincost) return;
    if(lf+EAMincost[x] > M) return;
    if(x == t)
    {
        nowmincost=min(nowmincost,cos);
        return;
    }
    for(int i=0;i<destination[x].size(); i++)
    {
        int y=destination[x][i];
        int le=EALengeth[x][i];
        ifvisited[y]= 1;
        SearchForSHORT(y, cos + le, lf + B[y]);
        ifvisited[y]= 0;
    }
}
int main()
{
    int T;
    cin>>T;
    for(int index1=0;index1<T;index1++)
    {
        cin >> n >> E >> s >> t >> M;
        for(int i=1;i<=n;i++)
        {
            destination[i].clear();
            EALengeth[i].clear();
        }
        for(int i=1;i<=n;i++)
        {
            cin>>B[i];
            EAMincost[i]=MAXC;
            ifvisited[i]=0;
        }
        for(int i=1;i<=E;i++)
        {
            cin>>u>>v>>w;
            destination[u].push_back(v);
            destination[v].push_back(u);
            EALengeth[u].push_back(w);
            EALengeth[v].push_back(w);
        }
        SHORTPATH();
        if(EAMincost[s]>M)
        {
            cout<<-1<<endl;
            return 0;
        }
        memset(ifvisited,0, sizeof(ifvisited));
        ifvisited[s]= 1;
        SearchForSHORT(s, 0, 0);
        cout<<nowmincost<<endl;
    }
}