#include<bits/stdc++.h>
using namespace std;

int n, m;	//n:정점갯수, m:노드쌍의 수
vector<pair<int, int>>adj[1001];
bool visited[1001];

int bfs(int u, int v) {
	for (int i = 0; i < 1001; i++) {
		visited[i] = false;
	}

	queue<pair<int,int>>q;
	q.push({ u,0 });
	visited[u] = true;
	while (!q.empty()) {
		int curU = q.front().first;
		int curDist = q.front().second;
		q.pop();

		if (curU == v)
			return curDist;

		for (int i = 0; i < adj[curU].size(); i++) {
			int nxtU = adj[curU][i].first;
			int nxtDist = adj[curU][i].second;
			if (!visited[nxtU]) {
				visited[nxtU] = true;
				q.push({ nxtU,curDist + nxtDist });
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int u, v, dis;

	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v >> dis;
		adj[u].push_back({ v,dis });
		adj[v].push_back({ u,dis });
	}

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		cout << bfs(u, v) << "\n";
	}
}