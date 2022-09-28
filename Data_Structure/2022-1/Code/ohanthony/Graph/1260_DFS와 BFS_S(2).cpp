#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool bvis[1005];
bool dvis[1005];

void dfs(int v) {
	dvis[v] = true;
	cout << v << ' ';
	for (auto nxt : adj[v]) {
		if (dvis[nxt]) continue;
		dfs(nxt);
	}
}

void bfs(int v) {
	queue<int> q;
	q.push(v);
	bvis[v] = true;
	while (!q.empty()) {
		auto cur = q.front();
		cout << cur << ' ';
		q.pop();
		for (auto nxt : adj[cur]) {
			if (bvis[nxt]) continue;
			q.push(nxt);
			bvis[nxt] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, v;
	cin >> n >> m >> v;

	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end()); // 정점이 여러 개인 경우 정점 번호가 작은 것을 먼저 방문
	}

	dfs(v);
	cout << '\n';
	bfs(v);
	
	return 0;
}
