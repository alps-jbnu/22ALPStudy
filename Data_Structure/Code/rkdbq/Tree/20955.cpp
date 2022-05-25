#include <iostream>
#include <vector>
using namespace std;

int N, M;
int cut, ans;
vector<int> adj[100001];
bool vis[100001];

void dfs(int cur, int bef) {
	vis[cur] = true;
	for (int i{}; i < adj[cur].size(); i++) {
		int nxt{ adj[cur][i] };
		if (nxt == bef || nxt == 0) continue;
		if (vis[nxt]) {
			cut++;
			continue;
		}
		dfs(nxt, cur);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	for (int i{}; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i{ 1 }; i <= N; i++) {
		cut = 0;
		if (!vis[i]) {
			dfs(i, -1);
			ans += cut / 2 + 1;
		}
	}
	cout << ans - 1;
	return 0;
}