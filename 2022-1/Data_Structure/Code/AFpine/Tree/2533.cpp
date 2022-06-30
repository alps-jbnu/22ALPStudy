#include <bits/stdc++.h>

//2533 사회망 서비스 SNS

using namespace std;

const int MAX = 1000001;

int N;
int u,v;
vector<int> adj[MAX];
vector<int> child[MAX];
bool visited[MAX];
int dp[MAX][2];
//0 is not early adapter, 1 is it

void dfs(int cur)
{
    for(auto &e : adj[cur])
    {
        if(visited[e] == true)
        {
            continue;
        }
        visited[e] = true;
        child[cur].push_back(e);
        dfs(e);
    }
}

int sns(int cur, int ea)
{
    int &ret = dp[cur][ea];
    if(ret != -1)
    {
        return ret;
    }

    int EA, NEA;
    EA = 1, NEA = 0;

    if(ea == 0)
    {
        for(auto &e : child[cur])
        {
            EA += sns(e,1);
        }
        NEA = 1e9+5;
    }
    else
    {
        for(auto &e : child[cur])
        {
            EA += sns(e,1);
            NEA += sns(e,0);
        }
    }

    ret = min(EA,NEA);

    return ret;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    memset(dp,-1,sizeof(dp));

    cin>>N;

    for(int i = 1;i<N;++i)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited[1] = true;
    dfs(1);

    int result = sns(1,1);

    cout<<result;

    return 0;
}