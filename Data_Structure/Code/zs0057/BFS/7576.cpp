#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int board[1001][1001];
int dis[1001][1001];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main(void) {
	int m, n;
	int mx = 0;
	cin >> m >> n;
	queue<pair<int, int>> Q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				Q.push({ i, j });
			}
		}
	}

	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dis[nx][ny] > 0 || board[nx][ny] != 0) continue;
			dis[nx][ny] = dis[cur.X][cur.Y] + 1;
			board[nx][ny] = 1;
			mx = max(mx, dis[nx][ny]);
			Q.push({ nx, ny });
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	
	cout << mx;
	




}