#include <bits/stdc++.h>

using namespace std;
bool vis1[1001];
bool vis2[1001];
queue<int> q;
vector<int> adj[1001];
int num = 0;

void bfs(int cur) {
	vis2[cur] = true;
	q.push(cur);
	while (!q.empty()) {
		cur = q.front(); q.pop();
		for (auto nxt : adj[cur]) {
			if (vis2[nxt]) continue;
			vis2[nxt] = true;
			q.push(nxt);
			num++;
		}
	}
}
int main(void) {
	int n, m, v;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bfs(1);
	cout << num;
}