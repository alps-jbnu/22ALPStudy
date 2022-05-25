#define first node
#define second len
#include <iostream>
#include <vector>
using namespace std;

int N, M, from, to;
vector<pair<int, int>> adj[1001];
int totalLen;

void dfs(int cur, int bef) {
	if (cur == to) {
		cout << totalLen << "\n";
		return;
	}
	for (int i{}; i < adj[cur].size(); i++) {
		int nxt{ adj[cur][i].node };
		int nxtLen{ adj[cur][i].len };
		if (bef == nxt) continue;
		totalLen += nxtLen;
		dfs(nxt, cur);
		totalLen -= nxtLen;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	for (int i{}; i < N - 1; i++) {
		int u, v, len;
		cin >> u >> v >> len;
		adj[u].push_back({ v, len });
		adj[v].push_back({ u, len });
	}
	for (int i{}; i < M; i++) {
		totalLen = 0;
		cin >> from >> to;
		dfs(from, 0);
	}
	return 0;
}