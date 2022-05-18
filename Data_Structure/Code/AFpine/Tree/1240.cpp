#include <bits/stdc++.h>

//1240 노드사이의 거리

using namespace std;

const int MAX = 1001;

int N,M;
vector<pair<int,int>> adj[MAX];
int parent[MAX];
int dist[MAX];
int depth[MAX];

void makeTree(int cur)
{
    for(auto &e : adj[cur])
    {
        if(parent[cur] == e.first)
        {
            continue;
        }
        parent[e.first] = cur;
        dist[e.first] = dist[cur] + e.second;
        depth[e.first] = depth[cur] + 1;
        makeTree(e.first);
    }
}

int distance(int a, int b)
{
    if(a == b)
    {
        return 0;
    }
    int tempa,tempb;
    int p;
    tempa = a;
    tempb = b;
    while(a != b)
    {
        if(depth[a] == depth[b])
        {
            a = parent[a];
            b = parent[b];
        }
        else if(depth[a] < depth[b])
        {
            b = parent[b];
        }
        else
        {
            a = parent[a];
        }
    }
    p = a;
    return (dist[tempa]-dist[p]) + (dist[tempb]-dist[p]);
}

void init()
{
    for(int i = 0;i<MAX;++i)
    {
        parent[i] = -1;
        dist[i] = -1;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    init();

    cin>>N>>M;

    for(int i = 1;i<=N-1;++i)
    {
        int a,b,c;
        cin>>a>>b>>c;

        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    dist[1] = 0;
    depth[1] = 0;

    makeTree(1);

    while(M--)
    {
        int a,b;
        cin>>a>>b;
        cout<<distance(a,b)<<'\n';
    }

    return 0;
}