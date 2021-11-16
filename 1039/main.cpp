#include<iostream>
#include <list>
#include <queue>
#include<vector>
using namespace std;

vector<int> resul;

class GraphList
{
    int V;
    list<int> *listnode;
    queue<int> linkv;
    int* indegree;
public:
    GraphList(int V);
    ~GraphList();
    void addeg(int v, int w);
    bool toposort();
};

GraphList::GraphList(int V)
{
    this->V = V;
    indegree = new int[V];
    listnode = new list<int>[V];
    for(int i=0; i<V; ++i)
        indegree[i] = 0;
}

void GraphList::addeg(int v, int w)
{
    listnode[v].push_back(w);
    indegree[w]++;
}

bool GraphList::toposort()
{

    for(int i=0; i<V; i++) {
        if (indegree[i] == 0)
            linkv.push(i);
    }
    int counts = 0;
    while(!linkv.empty())
    {
        int v = linkv.front();
        linkv.pop();
        counts++;
        resul.push_back(v);
        auto beg = listnode[v].begin();
        for( ; beg != listnode[v].end(); ++beg)
            if(!(--indegree[*beg]))
                linkv.push(*beg);
    }

    if(counts < V)
        return false;
    else
        return true;
}

GraphList::~GraphList() {
        delete [] listnode;
        delete [] indegree;
}

int main()
{
    int T;
    cin >> T;
    int n,m;
    for (int l = 0; l < T; l++)
    {
        resul.clear();
        cin>>n>>m;
        GraphList g(n);
        for (int i = 0; i < m; i++)
        {
            int a,b;
            cin>>a>>b;
            g.addeg(a - 1, b - 1);
        }
        if(g.toposort())
        {
            for (int i : resul)
            {
                cout << i + 1 << ' ';
            }
            cout<<endl;
        }
        else
            cout<<0<<endl;
    }

}