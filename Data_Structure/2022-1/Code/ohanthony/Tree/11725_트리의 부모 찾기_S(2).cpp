#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int parent[100005];

void dfs(int root) {
	for (int nxt : adj[root]) {
		if (parent[root] == nxt) continue;
		parent[nxt] = root;
		dfs(nxt);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);
	for (int i = 2; i <= n; i++) cout << parent[i] << "\n";
	return 0;
}

