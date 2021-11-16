#include <iostream>
#include <string.h>
using namespace std;

void dij(int n,int u,int dist[],int p[], int C[][502])
{
    bool visited[n+1];
    for(int i=0;i<n;i++)
    {
        if(C[u][i]) dist[i]=C[u][i];
        else dist[i]=10000;
        visited[i]= false;
        if(dist[i]==10000) p[i]=-1;
        else p[i]=u;
    }
    dist[u]=0;
    visited[u]= true;
    for(int i=0;i<n;i++)
    {
        int temp=10000;
        int t=u;
        for(int j=0;j<n;j++)
        {
            if((!visited[j])&&(dist[j]<temp))
            {
                t=j;
                temp=dist[j];
            }
        }
        if(t==u) break;
        visited[t]= true;
        for(int j=0;j<n;j++)
        {
            if((!visited[j])&&(C[t][j]<10000))
            {
                if(dist[j]>(dist[t]+C[t][j]))
                {
                    dist[j]=dist[t]+C[t][j];
                    p[j]=t;
                }
            }
        }
    }
}
int main()
{
    int T;
    cin>>T;
    int n,E,s,t;
    int u,v,w;
    int arr[502][502];
    int dis[502];
    int P[502];
    int res[T];
    for(int i=0;i<T;i++) {
        memset(arr,10000,sizeof(arr));
        cin >> n >> E >> s >> t;
        for (int j = 0; j < E; j++) {
            cin >> u >> v >> w;
            if (arr[u][v] > w)
            {
                arr[u][v] = w;
                arr[v][u] = w;
            }
        }
        dij(n,s,dis,P,arr);
        if(dis[t]<10000)   res[i]=dis[t];
        else res[i]=-1;
        cout<<P[t];
    }
    for(int i=0;i<T;i++)
    {
        cout<<res[i]<<endl;
    }
}

