#include <bits/stdc++.h>

//24367 회사 문화 1

using namespace std;

const int MAX = 100001;

int n,m;
int parent[MAX];
long long good[MAX];
vector<int> adj[MAX];

void dfs(int cur)
{
    for(auto &e : adj[cur])
    {
        parent[e] = cur;
        dfs(e);
    }
}

void gooddfs(int cur)
{
    for(auto &e : adj[cur])
    {
        good[e] += good[cur];
        gooddfs(e);
    }
}

void init()
{
    for(int i = 1;i<MAX;++i)
    {
        parent[i] = -1;
        good[i] = 0;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    init();
    cin>>n>>m;

    for(int i = 1;i<=n;++i)
    {
        int p;
        cin>>p;
        parent[i] = p;
        if(p != -1)
        {
            adj[p].push_back(i);
        }
    }

    for(int j = 1;j<=m;++j)
    {
        int i,w;
        cin>>i>>w;
        good[i] += w;
    }

    gooddfs(1);
    
    for(int i = 1;i<=n;++i)
    {
        cout<<good[i]<<" ";
    }

    return 0;
}