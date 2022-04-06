#include <bits/stdc++.h>
using namespace std;

vector<int>adj[501];
int vis[501];
int n, m;
int num;

void bfs() {
	queue<int>q;
	q.push(1);
	vis[1] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto nxt:adj[cur]) {
			if (vis[nxt] || vis[cur] >= 3)
				continue;
				q.push(nxt);
				vis[nxt] = vis[cur]+1;
				num++;
			}
		}
	}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	
	for (auto i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bfs();
	cout << num;
}