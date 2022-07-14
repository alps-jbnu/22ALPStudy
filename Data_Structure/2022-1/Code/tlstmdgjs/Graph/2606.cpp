#include <bits/stdc++.h>
using namespace std;

int adj[101][101];
bool vis[101];
int num;
int n, m;

void bfs(int cur) {
	queue<int>q;
	q.push(cur);
	vis[cur] = true;

	while (!q.empty()) {
		cur = q.front();
		q.pop();

		for (auto i = 1; i <= n; i++) {
			if (adj[cur][i] == 1 && vis[i] == 0) {
				q.push(i);
				vis[i] = true;
				num++;
			}
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
		adj[u][v]=1;
		adj[v][u]=1;
	}

	bfs(1);
	cout << num;
}