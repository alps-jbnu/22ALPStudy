#include<bits/stdc++.h>
using namespace std;

int n, m, cnt;	//n:정점갯수, m:간선갯수, cnt:Case수
bool visited[501];
vector<int>adj[501];

//단순회기 dfs
bool dfs(int cur, int parent) {
	visited[cur] = true;

	for (auto nxt : adj[cur]) {
		if (parent == nxt)
			continue;
		if (visited[nxt])
			return false;
		if (dfs(nxt, cur) == false)
			return false;
	}
	return true;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		int tree = 0;
		memset(visited, false, sizeof(visited));	//visit배열 초기화

		for (int i = 1; i <= n; ++i)
			adj[i].clear();

		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		for (int i = 1; i <= n; ++i)
			if (!visited[i])
				if (dfs(i, 0))
					tree++;

		if (tree == 0)
			cout << "Case " << ++cnt << ": No trees.";
		else if (tree == 1)
			cout << "Case " << ++cnt << ": There is one tree.";
		else
			cout << "Case " << ++cnt << ": A forest of " << tree << " trees.";
		cout << "\n";
	}
	return 0;
}