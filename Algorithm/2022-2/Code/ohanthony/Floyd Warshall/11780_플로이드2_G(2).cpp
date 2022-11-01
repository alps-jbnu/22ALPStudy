#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f // 플로이드 와샬에서 INF+INF 더 할때 int overflow를 방지하기 위해 0x7f7f7f7f대신 쓴 값
#define ll long long
#define X first
#define Y second

int n, m, a, b, c;
/*
- n: 도시의 개수
- m: 버스의 개수
- a: 출발 도시의 번호
- b: 도착 도시의 번호
- c: 한번 타는데 필요한 비용
*/

int bus[105][105];
int nxt[105][105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) { // bus값 초기화
		for (int j = 1; j <= n; j++) {
			if (i == j) bus[i][j] = 0;
			else bus[i][j] = INF;
		}
	}

	while (m--) {
		cin >> a >> b >> c;
		bus[a][b] = min(bus[a][b], c);
		nxt[a][b] = b;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (bus[i][j] > bus[i][k] + bus[k][j]) {
					bus[i][j] = bus[i][k] + bus[k][j];
					nxt[i][j] = nxt[i][k]; // 중간에 다른 정점을 거칠 경우 nxt 테이블도 마찬가지로 중간 지점의 값으로 갱신해 준다.
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (bus[i][j] == INF) cout << "0 ";
			else cout << bus[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (bus[i][j] == 0 || bus[i][j] == INF) {
				cout << "0\n";
				continue;
			}

			vector<int> path;
			int st = i;
			while (st != j) {
				path.push_back(st);
				st = nxt[st][j];
			}
			path.push_back(j);
			cout << path.size() << ' ';
			for (auto x : path) cout << x << ' ';
			cout << '\n';

		}
	}

	return 0;
}
