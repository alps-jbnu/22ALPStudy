#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f 
#define ll long long
#define X first
#define Y second

int n, m, k, a, b, c;
/*
- n: 도시의 개수
- m: 도시 간에 존재하는 도로의 수
- k: i번째 줄에 1번 도시에서 i번 도시로 가는 k번째 최단경로

- a, b, c: a->b 갈 때 c의 시간이 걸린다
*/

vector<pair<int, int>> adj[1005];
int d[1005]; // 최단거리 테이블
priority_queue<int> max_pq[1005]; // 해당 도시마다 우선순위 큐를 가지도록 함

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	fill(d, d + n + 1, INF); // 최단거리 테이블 초기화
	while (m--) {
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[1] = 0; // 시작점이 주어짐
	pq.push({ d[1], 1 });
	max_pq[1].push(0);

	while (!pq.empty()) {
		auto cur = pq.top().Y;	// 현재지점
		auto cost = pq.top().X; // 비용
		pq.pop();

		for (int i = 0; i < adj[cur].size(); i++) {
			int nxtCur = adj[cur][i].Y;
			int nxtCost = adj[cur][i].X;

			if (max_pq[nxtCur].size() < k) { // k개보다 적은 데이터가 있다면 경로 데이터 push
				max_pq[nxtCur].push(nxtCost + cost);
				pq.push({ nxtCost + cost , nxtCur });
			}
			else if (max_pq[nxtCur].top() > cost + nxtCost) { // 새로 구한 정점으로의 소요시간이 해당 정점의 top보다 작은 경우 top 수는 k번째 최단 경로가 될수 없다.
				max_pq[nxtCur].pop();
				max_pq[nxtCur].push(cost + nxtCost);
				pq.push({ nxtCost + cost, nxtCur });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		// k개 미만의 데이터가 있다면 k번째 최단 경로는 존재하지 않음을 의미
		if (max_pq[i].size() < k) cout << "-1\n";
		else cout << max_pq[i].top() << '\n';
	}

	return 0;
}

/*
기존의 다익스트라 문제와 다르게 최단경로만 저장하고 끝내는게 아니라
주어진 k번째에 해당하는 경로 값까지 저장하는 또 하나의 priority_queue 생성해 접근
*/