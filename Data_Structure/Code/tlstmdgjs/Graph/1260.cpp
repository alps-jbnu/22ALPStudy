#include <bits/stdc++.h>
using namespace std;

int n, m, st;
vector<int> adj[1001];
bool vis[1001];

void dfs1() {
	stack<int> s;
	s.push(st);
	while (!s.empty()) {
		int cur = s.top();
		s.pop();
		if (vis[cur]) continue;
		vis[cur] = true;
		cout << cur << ' ';
		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = adj[cur][adj[cur].size() - 1 - i];
			if (vis[nxt]) continue;
			s.push(nxt);
		}
	}
}

void dfs2(int cur) {
	vis[cur] = true;
	cout << cur << ' ';
	for (auto nxt : adj[cur]) {
		if (vis[nxt]) continue;
		dfs2(nxt);
	}
}

void bfs() {
	queue<int> q;
	q.push(st);
	vis[st] = true;
	while (!q.empty()) {
		int cur = q.front();
		cout << cur << ' ';
		q.pop();
		for (auto nxt : adj[cur]) {
			if (vis[nxt]) continue;
			q.push(nxt);
			vis[nxt] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> st;
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		sort(adj[i].begin(), adj[i].end());
	dfs1();
	cout << '\n';
	fill(vis + 1, vis + n + 1, false);
	bfs();
}