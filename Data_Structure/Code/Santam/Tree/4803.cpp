#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int Bfs(int n,bool vis_check[],vector<int> graph[])
{
	int p[501] = { 0 };
	queue<int> q;
	q.push(n);
	while (!q.empty())
	{
		int cur = q.front(); q.pop(); 
		if (vis_check[cur]) return 0;
		vis_check[cur] = true;
		for (int i = 0;i < graph[cur].size();i++)
		{
			if (p[cur] == graph[cur][i]) continue;
			p[graph[cur][i]] = cur;
			q.push(graph[cur][i]);
		}
	}
	return 1;
}

int main()
{
	int cnt = 0;
	while (true)
	{
		cnt++;
		vector<int> graph[501];
		bool vis_check[501] = { false };
		int n,m,tree_num=0;
		cin >> n >> m;
		if (!(n + m)) break;
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		for (int i = 1; i <= n; i++)
		{
			tree_num+=Bfs(i, vis_check, graph);
		}
		switch (tree_num)
		{
		case 0:
			cout << "Case " << cnt << ": No trees.\n";
			break;
		case 1:
			cout << "Case " << cnt << ": There is one tree.\n";
			break;
		default:
			cout << "Case " << cnt << ": A forest of " << tree_num << " trees.\n";
			break;
		}
	}
}