#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f // 플로이드 와샬에서 INF+INF 더 할때 int overflow를 방지하기 위해 0x7f7f7f7f대신 쓴 값
#define ll long long
#define X first
#define Y second

int N, M, S, E, L;
double result = INF;
/*
- n: 그래프의 정점의 수
- m: 간선의 수
- S: 각 간선의 시작점
- E: 각 간선의 끝점
- L: 각 간선의 길이

- result: 주어진 그래프를 모두 태우는데 걸리는 최소 기간
*/

int d[205][205];
vector<tuple<int, int, int>> edge;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) { // 집하장 값 초기화
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			d[i][j] = INF;
		}
	}

	while (M--) {
		cin >> S >> E >> L;
		d[S][E] = min(d[S][E], L);
		d[E][S] = min(d[E][S], L);
		edge.push_back({ S, E, L });
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) { // 각 시작점에서의 태우는데 걸리는 시간을 파악해 최솟값을 구함
		double time = 0.0; // 마지막 간선이 사라지는 최종시간

		for (int j = 0; j < edge.size(); j++) {
			tie(S, E, L) = edge[j];

			double m = min(d[i][S], d[i][E]);
			double M = max(d[i][S], d[i][E]);

			time = max(time, m + (double)(L - (M - m)) / 2 + (M - m));
		}
		result = min(result, time);
	}

	cout << fixed;
	cout.precision(1);
	cout << result;

	return 0;
}

/*
- 시작점과 끝점이 같은 간선이 있을 수도 있지만 최단 경로를 구하면 되니까 같은 간선 중에 최소 길이만 고려한다.
- 특정 정점에서 시작했을때 최솟값을 구하기 위해 모든 주어진 모든 정점에서의 경우를 파악
*/