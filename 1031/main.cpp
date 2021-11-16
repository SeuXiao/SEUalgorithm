#include <iostream>
#include <math.h>
#include<algorithm>
using namespace std;
struct points
{
    int x;
    int y;
};
struct edge
{
    double left;
    double right;
};
bool compare(const edge&p,const edge&q)
{
    return p.right<q.right;
}
int main()
{
    int m;
    cin>>m;
    int n,d;
    points p[10001];
    edge e[10001];
    int res[m];
    for(int l=0;l<m;l++)
    {
        int counts=1;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i].x>>p[i].y;
            e[i].left=p[i].x-sqrt(d*d-p[i].y*p[i].y);
            e[i].right=p[i].x+sqrt(d*d-p[i].y*p[i].y);
        }
        sort(e+1,e+n+1,compare);
        for(int i=1;i<=n;i++)
        {
            if(e[i].right>=e[i+1].left)
            {
                e[i].left=e[i+1].left;
                e[i+1].right=min(e[i].right,e[i+1].right);
            } else
            {
                e[i].left=-10000;
                e[i].right=-10000;
                counts++;
            }
        }
        res[l]=counts;
    }
    for(int i=0;i<m;i++)
    {
        cout<<res[i]<<endl;
    }
}