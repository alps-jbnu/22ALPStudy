#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n{ 1 }, m{ 1 }, T;
vector<int> adj[501];
bool vis[501];

void init() {
	for (int i{}; i < 501; i++) {
		vis[i] = 0;
		adj[i].clear();
	}
}

bool dfs(int cur, int bef) {
	vis[cur] = true;
	for (int i{}; i < adj[cur].size(); i++) {
		int nxt{ adj[cur][i] };
		if (nxt == bef) continue;
		if (vis[nxt]) return false;
		if (!dfs(nxt, cur)) return false; //?
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (true) {
		init();
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		T++;
		for (int i{}; i < m; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int ans{};
		for (int i{ 1 }; i <= n; i++) {
			if (vis[i] == false) ans += dfs(i, 0);
		}
		if (ans > 1) cout << "Case " << T << ": A forest of " << ans << " trees.\n";
		else if(ans>0) cout << "Case " << T << ": There is one tree.\n"
		else cout << "Case " << T << ": No trees.\n";
	}
	return 0;
}