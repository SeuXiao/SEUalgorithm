#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct build {
    int a,b,h;
} buildings[50001];

int n;

int getSkyline()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>buildings[i].a>>buildings[i].b>>buildings[i].h;
    }
    priority_queue<pair<int,int>> bd;
    vector<vector<int>> res;
    int i = 0;
    int A,H;
    while(i < n || !bd.empty())
    {
        if(bd.empty() || i < n && buildings[i].a <= bd.top().second)
        {
            A = buildings[i].a;
            while(i < n && A == buildings[i].a)
            {
                bd.emplace(buildings[i].h, buildings[i].b);
                i++;
            }
        }else
            {
            A = bd.top().second;
            while(!bd.empty() && A >= bd.top().second)
            {
                bd.pop();
            }
        }

        H = (bd.empty()) ? 0 : bd.top().first;

        if(res.empty() || H != res.back()[1])
            res.push_back({A, H});
    }
    for(const auto& e : res){
        for(const auto& i : e)
            cout << i << ' ';
        cout << '\n';
    }
    return 0;
}

int main()
{
    getSkyline();
}