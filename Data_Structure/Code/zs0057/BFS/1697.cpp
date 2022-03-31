#include <bits/stdc++.h>
using namespace std;
#define X first
#define count second
int vis[200002];

int main(void) {
	int n, k;
	cin >> n >> k;
	queue<pair<int, int>> Q;
	Q.push({ n, 0 });
	vis[n] = 1;
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		if (cur.X == k) {
			cout << cur.count;
			return 0;
		}
		for (int i = 0; i < 3; i++) {
			int nx;
			int sum;
			if (i == 0) {
				nx = cur.X + 1;
				sum = cur.count + 1;
				if (nx > 200000) continue;
				if (vis[nx] != 0) continue;
				vis[nx] = 1;
				Q.push({ nx, sum });
			}
			if (i == 1) {
				nx = cur.X - 1;
				sum = cur.count + 1;
				if (nx < 0) continue;
				if (vis[nx] != 0) continue;
				vis[nx] = 1;
				Q.push({ nx, sum });
			}
			if (i == 2) {
				nx = cur.X * 2;
				sum = cur.count + 1;
				if (nx > 200000) continue;
				if (vis[nx] != 0) continue;
				vis[nx] = 1;
				Q.push({ nx, sum });
			}
		}

	}

}