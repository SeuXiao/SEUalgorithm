#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define maxn 10001
vector<int> v[maxn];
int d[maxn], s[maxn], gs[maxn];
int dfs(int n, int fa)
{
    for(int i = 0; i < v[n].size(); i++)
    {
        int m = v[n][i];
        if(m != fa)dfs(m, n);
        s[n] += d[m];
        if(fa != -1)
            gs[fa] += d[m];
    }
    d[n] = max(s[n], gs[n] + 1);
    return d[n];
}
int main()
{
    int T;
    cin>>T;
    int res[T];
    int n;
    for(int j=0;j<T;j++)
    {
        cin>>n;
        memset(v,0,sizeof(v));
        for(int i = 0; i < n-1; i++)
        {
            int a, b;
            cin >> a >> b;;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        memset(d, 0, sizeof(d));
        memset(s, 0, sizeof(s));
        memset(gs, 0, sizeof(gs));
        res[j]=dfs(n, -1);
    }
    for(int j=0;j<T;j++)
    {
        cout<<res[j]<<endl;
    }
    return 0;
}
