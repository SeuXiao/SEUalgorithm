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
    int NOE=0;
    double ae=0;
}Road[401][401];

struct PATH{
    int start;
    int NOFE;
}path[8001];

void dij(int n,int u,double dist[],int p[], ROAD C[401][401])
{
    bool visited[n+1];
    for(int i=0;i<n;i++)
    {
        if(C[u][i].te) dist[i]=C[u][i].te;
        else dist[i]=MAXD;
        visited[i]= false;
        if(dist[i]==MAXD) p[i]=-1;
        else p[i]=u;
    }
    dist[u]=0;
    visited[u]= true;
    for(int i=0;i<n;i++)
    {
        double temp=MAXD;
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
            if((!visited[j])&&(C[t][j].te<MAXD))
            {
                if(dist[j]>(dist[t]+C[t][j].te))
                {
                    dist[j]=dist[t]+C[t][j].te;
                    p[j]=t;
                }
            }
        }
    }
}

int Getlen(int p[],int s,int t)
{
    int l=1;
    while(p[t]!=s)
    {
        l+=2;
        t=p[t];
    }
    return l;
}
int main()
{
    int T,m,E,n,s,t,u,v;
    cin>>T;
    int x,y;
    double t0,ae1,ae2;
    int index2;
    for(int i=0;i<T;i++)
    {
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
            for(int k=0;k<401;k++)
            {
                dis[k]=0;
            }
            memset(P,0,sizeof(P));
            memset(path,0,sizeof(path));
            dij(m,DH[j][0],dis,P,Road);
            x=DH[j][0];
            y=DH[j][1];
            index2=Getlen(P,x,y);
            index2+=2;
            cout<<index2<<endl;
            if(index2!=3) {
                t=y;
                int index=(index2 - 1)/2-1;
                for (int k = index; k >= 0; k--)
                {
                    Road[P[t]][t].te += Road[P[t]][t].t0 * Road[P[t]][t].ae;
                    path[k].start = P[t];
                    int temp = P[t];
                    path[k].NOFE = Road[temp][t].NOE;
                    t = temp;
                }
                for (int k = 0; k <= index; k++) {
                    cout << path[k].start << " " << path[k].NOFE << " ";
                }
                cout << y<<endl;
            }
            else{
                Road[x][y].te += Road[x][y].t0 * Road[x][y].ae;
                cout << x << " " << Road[x][y].NOE << " " <<y << endl;
            }
        }
    }
}

