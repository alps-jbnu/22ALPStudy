#include <bits/stdc++.h>
using namespace std;

int board[101][101];
int vis[101][101];

#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = {0, 1, 0, -1};


int main(void) {
	int mx = 0;
	int h = 0;
	int num = 0;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			h = max(h, board[i][j]);
		}
	}
	queue<pair<int, int>> Q;
	for (int k = 0; k <= h; k++) {
		
		num = 0;
		for (int a = 0; a < n; a++) {
			fill(vis[a], vis[a] + n, 0);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] <= k || vis[i][j]) continue;
				Q.push({ i, j });
				vis[i][j] = 1;
				num++;
				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (board[nx][ny] <= k || vis[nx][ny]) continue;
						Q.push({ nx, ny });
						vis[nx][ny] = 1;
					}
				}
			}

		}
		mx = max(mx, num);
	}

		
	cout << mx;
}