#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> adj[1001];
bool visited[1001];


int BFS(int start, int finish) {
	fill(visited, visited + 1001, false);

	queue<pair<int, int>> Q;
	visited[start] = true;
	Q.push(make_pair(start, 0));


	while (!Q.empty()) {
		int cur = Q.front().first;
		int curCost = Q.front().second;
		Q.pop();

		if (cur == finish) {
			return curCost;
		}

		for (auto nxt : adj[cur]) {
			if (visited[nxt.first] == true) continue;
			int nxtCur = nxt.first;
			int nxtCost = curCost + nxt.second;
			visited[nxtCur] = true;
			Q.push(make_pair(nxtCur, nxtCost));

		}
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back(make_pair(v, c));
		adj[v].push_back(make_pair(u, c));
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << BFS(a, b) << '\n';
	}
}
