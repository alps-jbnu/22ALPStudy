#include <bits/stdc++.h>
using namespace std;


int dp[100001];
bool visited[100001];
vector<int> adj[100001];
int n, r, q;

void DFS(int node, int parent) {
	visited[node] = true;
	for (auto nxt : adj[node]) {
		if (visited[nxt]) continue;
		DFS(nxt, node);
	}
	if (parent != -1) {
		dp[parent] += dp[node];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> r >> q;
	fill(dp, dp+100001, 1);

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	DFS(r, -1);
	for (int i = 0; i < q; i++) {
		int s;
		cin >> s;
		cout << dp[s];
		cout << '\n';
	}
}
