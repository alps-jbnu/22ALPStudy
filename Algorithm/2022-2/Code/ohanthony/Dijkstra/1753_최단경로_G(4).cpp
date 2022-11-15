#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f 
#define ll long long
#define X first
#define Y second

int V, E, K;
/*
- V: 정점의 개수
- E: 간선의 개수
- K: 시작 정점의 번호
*/

int u, v, w;
/*
- u: 시작 정점 
- v: 도착 정점
- w: u->v 가중치
*/

int d[20005]; // 최단거리 테이블
vector<pair<int, int>> adj[20005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> V >> E >> K;

	fill(d, d + V + 1, INF); // 최단거리 테이블 초기화
	while (E--) {
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[K] = 0; // 시작점 설정
	pq.push({ d[K], K });

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		if (d[cur.Y] != cur.X) continue;
		for (auto nxt : adj[cur.Y]) {
			// 최단 거리 테이블 갱신 조건
			if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
			d[nxt.Y] = d[cur.Y] + nxt.X;
			pq.push({ d[nxt.Y], nxt.Y });
		}
	}

	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) cout << "INF\n";
		else cout << d[i] << '\n';
	}
	return 0;
}
