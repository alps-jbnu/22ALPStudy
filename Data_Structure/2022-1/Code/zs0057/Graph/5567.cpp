#include <bits/stdc++.h>

using namespace std;
int dist[1001];
queue<int> q;
vector<int> adj[1001];
int num = 0;

void bfs(int cur) {
	dist[cur]=0;
	q.push(cur);
	while (!q.empty()) {
		cur = q.front(); q.pop();
		for (auto nxt : adj[cur]) {
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			if (dist[nxt] > 2) continue;
			q.push(nxt);
			num++;
		}
	}
}
int main(void) {
	int n, m;
	cin >> n >> m;
	fill(dist, dist + n, -1);

	cout << dist[6] << '\n';

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bfs(1);
	cout << num;
}