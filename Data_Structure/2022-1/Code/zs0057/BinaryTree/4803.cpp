#include <bits/stdc++.h>
using namespace std;

bool visited[1000];
vector<int> adj[1000];
int i = 1;

bool DFS(int cur, int before) {
	visited[cur] = true;

	for (auto nxt : adj[cur]) {
		if (nxt == before) {
			continue;
		}
		if (visited[nxt] == true) return false;
		if (DFS(nxt, cur) == false) return false;
	}
	return true;
}
int main(void) {
	int n, m;
	while (1) {
		
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		int u, v;
		while (m--) {
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int ans = 0;


		for (int i = 1; i <= n; i++) {
			if (visited[i] == false) {
				if (DFS(i, 0) == true) ans++;
			}
		}
		cout << "Case ";
		cout << i << ": ";
		if (ans == 0) {
			cout << "No trees." << '\n';
		}
		else if (ans == 1) {
			cout << "There is one tree." << '\n';
		}
		else {
			cout << "A forest of " << ans << " trees." << '\n';
		}
		i++;
		memset(visited, false, sizeof(visited));
		memset(adj, 0, sizeof(adj));
	}
}