#define first nxtNode
#define second len
#include <iostream>
#include <vector>
using namespace std;

int n, totalLen, ans, ansIdx;
vector<pair<int, int>> adj[10001];

void dfs(int cur, int bef) {
	for (int i{}; i < adj[cur].size(); i++) {

		int nxtNode{ adj[cur][i].nxtNode };
		int nxtLen{ adj[cur][i].len };

		if (nxtNode == bef) {
			if (adj[cur].size() == 1 && ans < totalLen) {
				ans = totalLen;
				ansIdx = cur;
			}
			continue;
		}

		totalLen += nxtLen;
		dfs(nxtNode, cur);
		totalLen -= nxtLen;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i{}; i < n - 1; i++) {
		int u, v, l;
		cin >> u >> v >> l;
		adj[u].push_back({ v, l });
		adj[v].push_back({ u, l });
	}

	dfs(1, -1);
	ans = 0;
	dfs(ansIdx, -1);
	cout << ans;
	return 0;
}