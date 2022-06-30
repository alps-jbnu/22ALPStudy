#include<bits/stdc++.h>
using namespace std;
int board[51][51];
int vis[51][51];
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	int t;
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		for (int k = 0; k < 51; k++) {
			fill(board[k], board[k] + 51, 0);
			fill(vis[k], vis[k] + 51, 0);
		}
		int m, n, k;
		cin >> m >> n >> k;
		int num = 0;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}
		queue<pair<int, int>> Q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vis[i][j] || board[i][j] == 0) continue;
				vis[i][j] = 1;
				num++;
				Q.push({ i, j });
				while (!Q.empty()) {
					pair<int, int> cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.second + dx[dir];
						int ny = cur.first + dy[dir];
						if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
						if (board[ny][nx] != 1 || vis[ny][nx]) continue;
						vis[ny][nx] = 1;
						Q.push({ ny, nx });
					}
				}
			}
		}
		cout << num << '\n';
	}
}