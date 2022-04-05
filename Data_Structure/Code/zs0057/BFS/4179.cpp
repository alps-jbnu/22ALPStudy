#include <iostream>
#include <queue>
#include <string>

using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

string board[1001];
int dist1[1001][1001];
int dist2[1001][1001];

int main(void) {
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> board[i];
	}
	queue<pair<int, int>> Q;
	queue<pair<int, int>> Q2;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 'F') {
				Q.push({ i, j });
				dist1[i][j] = 1;
			}
		}
	}

	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
				continue;
			}
			if (board[nx][ny] == '#' || dist1[nx][ny] >= 1) {
				continue;
			}
			dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
			Q.push({ nx, ny });
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 'J') {
				Q2.push({ i, j });
				dist2[i][j] = 1;
			}
		}
	}

	while (!Q2.empty()) {
		pair<int, int> cur = Q2.front(); Q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
				cout << dist2[cur.X][cur.Y];
				return 0;

			}
			if (board[nx][ny] == '#' || dist2[nx][ny] >= 1) {
				continue;
			}
			dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
			if (dist1[nx][ny] != 0 && dist2[nx][ny] >= dist1[nx][ny]) {
				dist2[nx][ny] = 0;
				continue;
			}

			Q2.push({ nx, ny });
		}
	}
	cout << "IMPOSSIBLE";
}