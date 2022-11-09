#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int num = 1;

	while (1) {
		int n, m, tree = 0;
		cin >> n >> m;
		if (n + m == 0) break;

		vector<int> adj[505];
		int parent[505] = { 0, };
		bool vis[505] = { 0, };

		while (m--) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;

			bool isCycle = false; // 사이클 여부 판단하는 bool 변수, 사이클 형성 == 트리 x
			queue<int> q;
			q.push(i);
			vis[i] = true;

			while (!q.empty()) {
				auto cur = q.front();
				q.pop();

				for (auto nxt : adj[cur]) {
					if (parent[cur] == nxt) continue;

					if (vis[nxt]) {
						isCycle = true;
						break;
					}

					q.push(nxt);
					parent[nxt] = cur;
					vis[nxt] = true;
				}
				if (isCycle) break;
			}
			if (!isCycle) tree++;
		}

		cout << "Case " << num++ << ": ";
		if (tree == 0) cout << "No trees.\n";
		else if (tree == 1) cout << "There is one tree.\n";
		else cout << "A forest of " << tree << " trees.\n";
	}
	return 0;
}

