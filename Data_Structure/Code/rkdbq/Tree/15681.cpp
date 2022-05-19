#include <iostream>
#include <vector>
using namespace std;

int N, R, Q;
vector<int> adj[100001];
int query[100001];

int dfs(int cur, int bef) {
	for (int i{}; i < adj[cur].size(); i++) {
		int nxt{ adj[cur][i] };
		if (bef == nxt) continue;
		query[cur] += dfs(nxt, cur);
	}
	return query[cur] + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> R >> Q;
	for (int i{}; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(R, 0);
	for (int i{}; i < Q; i++) {
		int q;
		cin >> q;
		cout << query[q] + 1 << "\n";
	}
	return 0;
}