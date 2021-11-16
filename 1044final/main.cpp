#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

const double MAXD=100000.0;
struct Eg
{
    int destination;
    double te=MAXD;
    double t0=MAXD;
    double ae=0;
    int link=0;
}ROAD[10001*2];
struct dh
{
    int start;
    int endOrNOE;
}DH[8001],shortPath[8001];

int resDH[10001];
int P[401];
double dis[401];
int index1=1;
int NumOE=0;
bool ifvisited[401];

queue<int> Qroad;

void SearchForSHORT(int s) {
    int begin;
    dis[s] = 0;
    ifvisited[s] = true;
    Qroad.push(s);
    while (!Qroad.empty()) {
        begin = Qroad.front();
        Qroad.pop();
        ifvisited[begin] = 1;
        for (int x = P[begin]; x != -1; x = ROAD[x].link)
        {
            int end = ROAD[x].destination;
            if (dis[begin] + ROAD[x].te < dis[end])
            {
                dis[end] = dis[begin] + ROAD[x].te;
                shortPath[end].start = begin;
                shortPath[end].endOrNOE= x;
                Qroad.push(end);
            }
        }
    }
}
void Updatafe(int star, int ending)
{
    memset(resDH,0, sizeof(resDH));
    index1=1;
    NumOE=0;
    for(int i=ending; i != star; i=shortPath[i].start)
    {
        resDH[NumOE]=i;
        index1+=2;
        NumOE++;
        ROAD[shortPath[i].endOrNOE].te+= ROAD[shortPath[i].endOrNOE].ae * ROAD[shortPath[i].endOrNOE].t0*1.01;
    }
}
int main()
{
    int T,m,E,n,s,t,u,v;
    cin>>T;
    double t0,ae1,ae2;
    for(int l=0;l<T;l++)
    {
        cin>>m>>E>>n;
        memset(P,-1, sizeof(P));
        for(int j=0;j<n;j++)
        {
            cin>>s>>t;
            DH[j].start=s;
            DH[j].endOrNOE=t;
        }
        for(int j=0;j<2*E-1;j+=2)
        {
            cin>>u>>v>>t0>>ae1>>ae2;
            ROAD[j].destination=v;
            ROAD[j].t0=t0*0.1;
            ROAD[j].te=t0*0.1;
            ROAD[j].ae=ae1;
            ROAD[j].link=P[u];
            P[u]=j;
            ROAD[j+1].destination=u;
            ROAD[j+1].t0=t0*0.1;
            ROAD[j+1].te=t0*0.1;
            ROAD[j+1].ae=ae2;
            ROAD[j+1].link=P[v];
            P[v]=j+1;
        }
        for(int j=0;j<n;j++)
        {
            while (!Qroad.empty()) Qroad.pop();
            for(double & di : dis)
            {
                di=MAXD;
            }
            memset(ifvisited, 0, sizeof(ifvisited));
            memset(shortPath, -1, sizeof(shortPath));
            int f,g;
            for (int j = 0; j < 2 * E - 1; j += 2)
            {
                f=ROAD[j].destination;
                g=ROAD[j + 1].destination;
                shortPath[f].start=g;
                shortPath[g].start=f;
                shortPath[f].endOrNOE=j;
                shortPath[g].endOrNOE= j + 1;
            }
            dis[s] = 0;
            ifvisited[s] = true;
            SearchForSHORT(DH[j].start);
            Updatafe(DH[j].start,DH[j].endOrNOE);
            cout<<index1<<endl;
            cout << DH[j].start << " ";
            for(int i=NumOE-1;i>=0;i--)
            {
                cout << shortPath[resDH[i]].endOrNOE << " " << resDH[i] << " ";
            }
            cout<<endl;
        }
    }
}
