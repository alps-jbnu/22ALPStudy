#include <bits/stdc++.h>

//15681 트리

using namespace std;

const int MAX = 100001;

int N,R,Q;
vector<int> adj[MAX];
int parent[MAX];
int dp[MAX];

void makeTree(int cur)
{
    for(auto &e : adj[cur])
    {
        if(parent[cur] == e)
        {
            continue;
        }
        parent[e] = cur;
        makeTree(e);
    }
}

int subtreeNodes(int cur)
{
    int &res = dp[cur];
    if(res != -1)
    {
        return res;
    }
    res = 1;
    for(auto &e : adj[cur])
    {
        if(parent[cur] == e)
        {
            continue;
        }
        res += subtreeNodes(e);
    }
    return res;
}

void init()
{
    for(int i = 0;i<MAX;++i)
    {
        parent[i] = -1;
        dp[i] = -1;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    init();

    cin>>N>>R>>Q;

    for(int i = 1;i<=N-1;++i)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }  

    makeTree(R);

    while(Q--)
    {
        int U;
        cin>>U;
        cout<<subtreeNodes(U)<<'\n';
    }

    return 0;
}