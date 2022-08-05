#define first nxtNode
#define second len
#include <iostream>
#include <vector>
using namespace std;

int V, totalLen, ans, ansIdx;
vector<pair<int, int>> adj[100001];

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

	cin >> V;
	for (int i{}; i < V; i++) {
		int u, v, l;
		cin >> u;
		while (true) {
			cin >> v;
			if (v == -1) break;
			cin >> l;
			adj[u].push_back({ v, l });
		}
	}

	dfs(1, -1);
	ans = 0;
	dfs(ansIdx, -1);
	cout << ans;
	return 0;
}