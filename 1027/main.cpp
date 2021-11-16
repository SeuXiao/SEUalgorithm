#include <iostream>
#include<algorithm>
using namespace std;

struct Work
{
    int start=0;
    int final=0;
    int value=0;
};

bool compare(const Work&p,const Work&q)
{
    return p.final<q.final;
}


int main()
{
    int M,N;
    cin>>M;
    int res[M];
    Work work[10001];
    int maxvalue[10001];
    for(int i=0;i<M;i++)
    {
        cin >> N;
        for(int j=1;j<=N;j++)
        {
            cin>>work[j].start>>work[j].final>>work[j].value;
            maxvalue[j]=0;
        }
        sort(work+1,work+N+1,compare);
        for(int j=1;j<=N;j++)
        {
            maxvalue[j]=work[j].value;
            for(int s=1;s<j;s++)
            {
                if(work[s].final>work[j].start)
                {
                    maxvalue[j]=max(maxvalue[j],maxvalue[s]);
                }
                else
                {
                    maxvalue[j]=max(maxvalue[j],maxvalue[s]+work[j].value);
                }
            }
        }
        res[i]=maxvalue[N];
    }
    for(int i=0;i<M;i++)
    {
        cout<<res[i]<<endl;
    }
}
