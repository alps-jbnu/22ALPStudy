#include <bits/stdc++.h>

using namespace std;
int vis[105];
queue<int> q;
vector<int> adj[105];
void bfs(int cur) {
	
	q.push(cur);
	while (!q.empty()) {
		cur = q.front(); q.pop();
		for (auto nxt : adj[cur]) {
			if (vis[nxt]) continue;
			q.push(nxt);
			vis[nxt] = true;
		}
	}
}

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;
			if (a == 1) {
				adj[i].push_back(j);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		bfs(i);
		for (int i = 1; i <= n; i++) {
			if (vis[i]) cout << 1 << ' ';
			else cout << 0 << ' ';
			
		}
		cout << '\n';
		fill(vis, vis + 1 + n, 0);
	}
	
}