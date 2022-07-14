#include <bits/stdc++.h>
using namespace std;

int vis[10005];
vector<int> adj[10005];
queue<int> q;
int num[10005]{};

void bfs(int cur, int idx) {
	vis[cur] = 1;
	q.push(cur);
	while (!q.empty()) {
		cur = q.front(); q.pop();
		for (auto nxt : adj[cur]) {
			if (vis[nxt])continue;
			q.push(nxt);
			vis[nxt] = 1;
			num[idx]++;
		}
	}
}

int main(void) {
	int n, m;
	cin >> n >> m;
	int mx = 0;
	

	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		fill(vis, vis + n + 1, 0);
		bfs(i, i);
		if (mx < num[i]) mx = num[i];
	}
	for (int i = 1; i <= n; i++) {
		if (mx == num[i]) cout << i << ' ';
	}

}