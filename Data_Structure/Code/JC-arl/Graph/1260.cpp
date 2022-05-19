#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
vector<int> adj[1005];
bool vis[1005];
int N, M, V;
void dfs(int cur)
{
	vis[cur] = true;
	cout << cur << ' ';
	for (auto nxt : adj[cur])
	{
		if (vis[nxt])	continue;
		dfs(nxt);
	}
}
void bfs()
{
	queue<int> q;
	q.push(V);
	vis[V] = true;
	while (!q.empty())
	{
		int cur = q.front();	q.pop();
		cout << cur << " ";
		for (int nxt : adj[cur])
		{
			if (vis[nxt])	continue;
			q.push(nxt);
			vis[nxt] = true;
		}
	}
}

int main(void)
{

	cin >> N >> M >> V;
	int u, v;
	while (M--)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= N; i++)
		sort(adj[i].begin(), adj[i].end());
	dfs(V);
	cout << "\n";
	fill(vis + 1, vis + N + 1, false);
	bfs();

	return 0;
}