#include<iostream>
#include<algorithm>
using namespace std;

struct Work{
    int d;
    int p;
};
Work job[50001];
int selec[50001];

bool compare(const Work& a,const Work& b)
{
    return a.p > b.p;
}
int main()
{
    int T,N;
    cin>>T;
    for (int l = 0; l < T; l++)
    {
        long long maxp=0;
        cin>>N;
        for (int i = 0; i < N; i++)
        {
            Work temp;
            cin >> temp.d>>temp.p;
            job[i]=temp;
            selec[i]=0;
        }
        sort(job, job + N, compare);
        for (int i = 0; i < N; i++)
        {
            int nowd=job[i].d;
            while (selec[nowd])
            {
                nowd--;
            }
            if (!nowd)
            {
                continue;
            }
            selec[nowd]=1;
            maxp+=job[i].p;
        }
        cout << maxp << endl;
    }

}