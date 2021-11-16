#include <iostream>
#include <string.h>
using namespace std;
const double MAXD=1000000.0;
int DH[8001][2];
int P[401];
double dis[401];
struct ROAD{
    double t0=MAXD;
    double te=MAXD;
    double t=te;
    int NOE=0;
    double ae=0;
}Road[401][401];
int path[401][401];
void init(int m)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i!=j)
                Road[i][j].te=MAXD;
            else
                Road[i][j].te=0;
            path[i][j]=j;
        }
    }
}
void Floyd(int m)
{
    for(int k=0;k<m;k++)
    for(int i=0;i<m;i++)
    for(int j=0;j<m;j++)
        if(Road[i][k].te!=MAXD&&Road[k][j].te!=MAXD)
        {
            int temp=Road[i][k].te+Road[k][j].te;
            if(Road[i][j].te>temp)
            {
                Road[i][j].te=temp;
                path[i][j]=path[i][k];
            }
            else if(Road[i][j].te==temp&&path[i][j]>path[i][k])
            {
                path[i][j]=path[i][k];
            }
        }
}
int main()
{
    int T,m,E,n,s,t,u,v;
    cin>>T;
    int x,y;
    double t0,ae1,ae2;
    for(int i=0;i<T;i++)
    {
        init(m);
        cin>>m>>E>>n;
        for(int j=0;j<n;j++)
        {
            cin>>s>>t;
            DH[j][0]=s;
            DH[j][1]=t;
        }
        for(int j=0;j<2*E-1;j+=2)
        {
            cin>>u>>v>>t0>>ae1>>ae2;
            Road[u][v].NOE=j;
            Road[u][v].t0=t0;
            Road[u][v].te=t0;
            Road[u][v].ae=ae1;
            Road[v][u].NOE=j+1;
            Road[v][u].t0=t0;
            Road[v][u].te=t0;
            Road[v][u].ae=ae2;
        }
        for(int j=0;j<n;j++)
        {
            Floyd(m);

        }
    }
}

