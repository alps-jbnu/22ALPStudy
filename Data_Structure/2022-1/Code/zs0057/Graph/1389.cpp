#include <bits/stdc++.h>
using namespace std;

int dist[105];
vector<int> adj[105];
queue<int> q;

void bfs(int cur) {
	dist[cur] = 0;
	q.push(cur);
	while (!q.empty()) {
		cur = q.front(); q.pop();
		for (auto nxt : adj[cur]) {
			if (dist[nxt] > -1)continue;
			q.push(nxt);
			dist[nxt] = dist[cur] + 1;
		}
	}
}

int main(void) {
	int n, m;
	cin >> n >> m;
	int sum[55]{};
	int min = 100001;

	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		fill(dist, dist + n + 1, -1);
		bfs(i);
		for (int j = 1; j <= n; j++)
			sum[i] += dist[j];
	}
	for (int i = 1; i <= n; i++) {
		if (min > sum[i]) min = sum[i];
	}
	for (int i = 1; i <= n; i++) {
		if (min == sum[i]) {
			cout << i;
			break;
		}


	}
}