#include <bits/stdc++.h>

using namespace std;
bool vis1[1001];
bool vis2[1001];
queue<int> q;
vector<int> adj[1001];
int sum = 0;

void dfs(int cur) {
	vis1[cur] = true;
	cout << cur << ' ';
	
	for (auto nxt : adj[cur]) {
		if (vis1[nxt]) continue;
		dfs(nxt);
	}
}

void bfs(int cur) {
	vis2[cur] = true;
	q.push(cur);
	cout << cur << ' ';
	while (!q.empty()) {
		cur = q.front(); q.pop();
		for (auto nxt : adj[cur]) {
			if (vis2[nxt]) continue;
			vis2[nxt] = true;
			q.push(nxt);
			cout << nxt << ' ';
		}
	}
}
int main(void) {
	int n, m, v;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < 1001; i++)
		sort(adj[i].begin(), adj[i].end());
	
	dfs(v);
	cout << '\n';
	bfs(v);
}