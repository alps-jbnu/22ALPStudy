#include <bits/stdc++.h>

//1167 트리의 지름

using namespace std;

const int MAX = 100001;

int V;
vector<pair<int,int>> adj[MAX];
vector<long long> dist(MAX,0);
int maxdist = 0;
int maxidx;
bool visited[MAX];

void dfs(int cur)
{
    for(auto &e : adj[cur])
    {
        if(visited[e.first] == true)
        {
            continue;
        }
        dist[e.first] = dist[cur] + e.second;
        visited[e.first] = true;
        dfs(e.first);
    }
}

bool compare(long long &a, long long &b)
{
    return a > b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>V;

    for(int i = 1;i<=V;++i)
    {
        int u,v,w;
        cin>>u;
        while(true)
        {
            cin>>v;
            if(v == -1)
            {
                break;
            }
            cin>>w;
            adj[u].push_back({v,w});
        }
    }

    visited[1] = true;
    dist[1] = 0;
    dfs(1);

    for(int i = 1;i<=V;++i)
    {
        visited[i] = false;
        if(maxdist < dist[i])
        {
            maxdist = dist[i];
            maxidx = i;
        }
    }

    visited[maxidx] = true;
    dist[maxidx] = 0;
    dfs(maxidx);
    
    for(int i = 1;i<=V;++i)
    {
        if(maxdist < dist[i])
        {
            maxdist = dist[i];
        }
    }

    cout<<maxdist;

    return 0;
}