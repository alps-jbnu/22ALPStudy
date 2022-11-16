#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int D[205][205];
int d[205][205];
int nxt[205][205];
int n, m;
int ans = INF;
int tmp = 0;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		fill(d[i], d[i] + 1 + n, INF);
	}

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		D[a][b] = D[b][a] = max(D[a][b], c);
		d[a][b] = d[b][a] = min(d[a][b], c);
		nxt[a][b] = b;
		nxt[b][a] = a;
	}

	for (int i = 1; i <= n; i++)d[i][i] = 0;
	
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
					nxt[i][j] = nxt[i][k];
				}

	for (int k = 1; k <= n; k++) {
		tmp = 0;
		for (int i = 1; i <= n; i++) {
			int ki = d[k][i];
			for (int j = 1; j <= n; j++) {
				tmp = max(tmp, ki + d[k][j] + D[i][j]);
			}
		}
		ans = min(ans, tmp);
	}
	
	cout << ("%.1f", (double)ans / 2.0);
	
	return 0;
}