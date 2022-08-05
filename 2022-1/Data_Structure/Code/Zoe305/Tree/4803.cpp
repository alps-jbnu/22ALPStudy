#include <bits/stdc++.h>
using namespace std;

int n, m, u, v;
int ans, cnt;
bool visit[501];
vector<int> graph[501];

bool DFS(int x, int post_x)
{
	visit[x] = true;

	for (int i = 0; i < graph[x].size(); i++)
	{
		if (graph[x][i] == post_x) continue;

		if (visit[graph[x][i]]) return false;

		if (DFS(graph[x][i], x) == false) return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		cnt++;
		ans = 0;
		for (int i = 1; i <= 500; i++)
		{
			graph[i].clear();
			visit[i] = false;
		}

		for (int i = 0; i < m; i++)
		{
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		for (int i = 1; i <= n; i++)
		{
			if (!visit[i])
				if (DFS(i, 0)) ans++;
		}

		cout << "Case " << cnt << ": ";
		if (ans > 1)
			cout << "A forest of " << ans << " trees." << '\n';
		else if (ans == 1)
			cout << "There is one tree." << '\n';
		else if (ans == 0)
			cout << "No trees." << '\n';
	}
}