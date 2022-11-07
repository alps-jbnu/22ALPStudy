#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f // 플로이드 와샬에서 INF+INF 더 할때 int overflow를 방지하기 위해 0x7f7f7f7f대신 쓴 값
#define ll long long
#define X first
#define Y second

int n, m, a, b, c;
/*
- n: 집하장 개수
- m: 집하장간 경로의 개수
- a, b: 두 집하장의 번호 
- c: 두 집하장으로 오가는데 필요한 시간
*/

int center[205][205];
int nxt[205][205];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) { // 집하장 값 초기화
		for (int j = 1; j <= n; j++) {
			if (i == j) center[i][j] = 0;
			else center[i][j] = INF;
		}
	}

	while (m--) {
		cin >> a >> b >> c;
		center[a][b] = c;
		center[b][a] = c;
		nxt[a][b] = b;
		nxt[b][a] = a;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (center[i][j] > center[i][k] + center[k][j]) {
					center[i][j] = center[i][k] + center[k][j];
					nxt[i][j] = nxt[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << "- ";
			else cout << nxt[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
