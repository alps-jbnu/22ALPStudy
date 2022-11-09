#include<bits/stdc++.h>
using namespace std;

int board[105][105][105];
int day[105][105][105];
queue<tuple<int, int, int>> q;

int dx[6] = { 0, 0, 1, -1, 0, 0 };
int dy[6] = { 1, -1, 0, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 }; 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int m, n, h;
	cin >> m >> n >> h;

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 0) day[i][j][k] = -1;
				if (board[i][j][k] == 1) q.push({ i, j, k });
			}
		}
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		int cur_X, cur_Y, cur_Z;
		tie(cur_X, cur_Y, cur_Z) = cur;

		for (int dir = 0; dir < 6; dir++) {
			int nx = cur_X + dx[dir];
			int ny = cur_Y + dy[dir];
			int nz = cur_Z + dz[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if (day[nx][ny][nz] >= 0) continue;

			day[nx][ny][nz] = day[cur_X][cur_Y][cur_Z] + 1;
			q.push({ nx, ny, nz });
		}
	}

	int result = 0;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (day[i][j][k] == -1) {
					cout << -1 << "\n";
					return 0;
				}
				result = max(result, day[i][j][k]);
			}
		}
	}

	cout << result << "\n";
	return 0;
}
