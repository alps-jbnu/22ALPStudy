#include <bits/stdc++.h>
using namespace std;

vector<int> adj[102];
bool vis[102];
int v, e;

int main(void)
{
	cin >> v >> e;
	int area = 0;
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue<int> q;
	q.push(1);
	vis[1] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto nxt : adj[cur]) {
			if (vis[nxt]) continue;
			vis[nxt] = true;
			area++;
			q.push(nxt);
		}
	}
	cout << area;
}
