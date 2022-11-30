#include <iostream>
using namespace std;

int dist[201][201];
int edgeL[20000], edgeR[20000], distedge[20000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M; cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) dist[i][j] = 1000000007;
	}
	for (int m = 0; m < M; m++) {
		int S, E, L; cin >> S >> E >> L;
		dist[S][E] = dist[E][S] = min(dist[S][E], L);
		edgeL[m] = S, edgeR[m] = E, distedge[m] = L;
	}

	for (int i = 1; i <= N; i++) dist[i][i] = 0;

	for (int k = 1; k <= N; k++) {
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				dist[r][c] = min(dist[r][c], dist[r][k] + dist[k][c]);
			}
		}
	}

	int ans = 1000000007;
	for (int k = 1; k <= N; k++) {
		int tmp = 0;
		for (int m = 0; m < M; m++) {
			int d1 = dist[k][edgeL[m]], d2 = dist[k][edgeR[m]], l = distedge[m];
			int diff = abs(d1 - d2);
			l -= diff;
			tmp = max(tmp, 2 * max(d1, d2) + l);
		}
		ans = min(ans, tmp);
	}

	cout << ans / 2 << '.';
	if (ans & 1) cout << 5;
	else cout << 0;
}