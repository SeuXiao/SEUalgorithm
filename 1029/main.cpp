#include<iostream>
using namespace std;

int Primtree(int n,int u,int C[][502])
{
    bool visited[n+1];
    int close[n+1];
    int leastcost[502];
    visited[u]= true;
    int total=0;
    int counts=1;
    for(int i=2;i<=n;i++)
    {
        if(i!=u)
        {
            if(C[u][i]) leastcost[i]=C[u][i];
            else leastcost[i]=10000;
            close[i]=u;
            visited[i]= false;
        }
    }
    for(int i=2;i<=n;i++)
    {
        int tempcost=10000;
        int t=u;
        for(int j=2;j<=n;j++)
        {
            if((!visited[j])&&(leastcost[j]<tempcost))
            {
                t=j;
                tempcost=leastcost[j];
            }
        }
        if(t==u) break;
        visited[t]= true;
        counts++;
        total+=leastcost[t];
        for(int j=1;j<=n;j++)
        {
            if((!visited[j])&&(C[t][j]<leastcost[j]))
            {
                leastcost[j]=C[t][j];
                close[j]=t;
            }
        }
    }
    if(counts==n) return total;
    else return -1;
}
int main()
{
    int T;
    cin>>T;
    int arr[502][502];
    int n,E,u,v,w;
    int res[T];
    for(int i=0;i<T;i++)
    {
        for(int m=0;m<502;m++)
        {
            for(int l=0;l<502;l++)
                arr[m][l]=10000;
        }
        cin>>n>>E;
        for (int j = 0; j < E; j++)
        {
            cin >> u >> v >> w;
            if (arr[u][v] > w)
            {
                arr[u][v] = w;
                arr[v][u] = w;
            }
        }
        res[i]=Primtree(n,1,arr);
    }
    for(int i=0;i<T;i++) cout<<res[i]<<endl;
    return 0;
}