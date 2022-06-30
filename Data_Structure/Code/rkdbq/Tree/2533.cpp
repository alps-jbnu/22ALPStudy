#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int eaNum;
int dp[1000001][2];
vector<int> adj[1000001];

void dfs(int bef, int cur) {
	dp[cur][1] = 1;

	for (auto it{ adj[cur].begin() }; it != adj[cur].end(); it++) {
		int nxt{ *it };
		if (nxt == bef) continue;

		dfs(cur, nxt);
		dp[cur][0] += dp[nxt][1];
		//cout << cur << ", not ea " << dp[cur][0] << "\n";
		dp[cur][1] += min(dp[nxt][0], dp[nxt][1]);
		//cout << cur << ", ea " << dp[cur][1] << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i{ 1 }; i < N; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(0, 1);
	cout << min(dp[1][0], dp[1][1]) << "\n";

	return 0;
}