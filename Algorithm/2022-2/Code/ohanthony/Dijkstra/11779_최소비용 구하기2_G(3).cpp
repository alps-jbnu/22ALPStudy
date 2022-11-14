#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f 
#define ll long long
#define X first
#define Y second

int n, m, u, v, w, st, en;
/*
- n: 도시의 개수
- m: 버스의 개수

- u: 출발 도시번호
- v: 도착 도시번호
- w: 버스 비용

- st: 출발점의 도시번호
- en: 도착점의 도시번호
*/

vector<pair<int, int>> adj[20005];
int d[1005]; // 최단 거리 테이블
int pre[1005]; // 경로 복원 테이블

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	fill(d, d + n + 1, INF); // 최단거리 테이블 초기화
	while (m--) {
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
	}
	cin >> st >> en;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[st] = 0; // 시작점 설정
	pq.push({ d[st], st });

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		if (d[cur.Y] != cur.X) continue;
		for (auto nxt : adj[cur.Y]) {
			// 최단 거리 테이블 갱신 조건
			if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
			d[nxt.Y] = d[cur.Y] + nxt.X;
			pq.push({ d[nxt.Y], nxt.Y });
			pre[nxt.Y] = cur.Y;
		}
	}

	cout << d[en] << '\n';

	vector<int> path;
	int cur = en;
	while (cur != st) {
		path.push_back(cur);
		cur = pre[cur];
	}
	path.push_back(st); // 문제에서 출발 도시와 도착 도시 포함이라 했으므로

	cout << path.size() << '\n';
	reverse(path.begin(), path.end());
	for (auto i : path) cout << i << ' ';

	return 0;
}
