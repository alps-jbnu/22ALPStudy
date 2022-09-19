#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[1005][1005];
int day[1005][1005]; // 토마토 들어있지 않은 칸, 익은 토마토 모두 0으로 초기화
int result;
queue<pair<int, int>> q;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) q.push({ i, j }); // 시작점이 여러개인 경우 모두 queue에 집어 넣고 시작
			if (board[i][j] == 0) day[i][j] = -1;
		}
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (day[nx][ny] > -1) continue;

			day[nx][ny] = day[cur.X][cur.Y] + 1;
			q.push({ nx, ny });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (day[i][j] == -1) {
				cout << -1;
				return 0;
			}
			result = max(result, day[i][j]);
		}
	}

	cout << result;
	return 0;
}
