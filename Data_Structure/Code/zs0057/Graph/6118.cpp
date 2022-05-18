#include <bits/stdc++.h>
using namespace std;

queue<int> q;
vector<int> adj[20005];
int dist[20005];
int num[20005];

void bfs(int cur) {
	dist[cur] = 0;
	q.push(cur);
	while (!q.empty()) {
		cur = q.front(); q.pop();
		for (auto nxt : adj[cur]) {
			if (dist[nxt] > -1) continue;
			q.push(nxt);
			dist[nxt] = dist[cur]+1;
		}
	}
}

int main(void) {
	int n, m;
	int mx = 0;
	int count = 0;
	int temp = 0;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	fill(dist, dist + n + 1, -1);
	bfs(1);
	for (int i = 1; i <= n; i++) {
		if (mx < dist[i]) mx = dist[i];
	}
	for (int i = n; i >= 1; i--) {
		if (mx == dist[i]) {
			count++;
			temp = i;
		}
	}
	cout << temp << ' ' << dist[temp] << ' ' << count;

	
}