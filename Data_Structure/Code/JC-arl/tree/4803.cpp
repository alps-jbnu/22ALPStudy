#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int N, M;
vector<int> adj[505];
bool vis[505];

bool dfs(int cur,int before)
{
	vis[cur] = true;

	for (auto nxt : adj[cur])
	{
		if (nxt == before)	continue;
		if (vis[nxt]) return false;
		if (dfs(nxt, cur) == false)	return false;
	}
	return true;
}
int main(void)
{
	int num = 0;

	while (true)
	{
		num++;
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		int u, v;
		int t = 0;
		memset(vis, false, sizeof(vis));
		for (int j = 0; j <= N; j++)
		{
			adj[j].clear();
		}
			
		for (int i = 0; i < M; i++)
		{
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int i = 1; i <= N; i++)
		{
			if (!vis[i])
				if (dfs(i, 0)) t++;
		}
		if (t == 0)
			cout << "Case " << num << ": No trees.\n";
		else if (t == 1)
			cout << "Case " << num << ": There is one tree.\n";
		else
			cout << "Case " << num << ": A forest of " << t << " trees.\n";
	}


	return 0;
}