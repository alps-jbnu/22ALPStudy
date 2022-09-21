#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int board[55][55] = { 0, };
		bool vis[55][55] = { 0, };
		int m, n, k, count = 0;
		cin >> m >> n >> k;

		while (k--) {
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}

		queue<pair<int, int>> q;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vis[i][j] || board[i][j] != 1) continue;

				vis[i][j] = true;
				q.push({ i, j });
				count++;
				while (!q.empty()) {
					auto cur = q.front();
					q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vis[nx][ny] || board[nx][ny] == 0) continue;

						q.push({ nx, ny });
						vis[nx][ny] = true;
					}
				}
			}
		}
		cout << count << "\n";
	}
	return 0;
}
