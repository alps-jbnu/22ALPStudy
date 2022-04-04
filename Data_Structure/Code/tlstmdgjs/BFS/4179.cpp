#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[1002];
int dist1[1002][1002];
int dist2[1002][1002];
int R, C;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		fill(dist1[i], dist1[i] + C, -1);
		fill(dist2[i], dist2[i] + C, -1);
	}
	for (int i = 0; i < R; i++)
		cin >> board[i];
	queue<pair<int, int>>Q1;
	queue<pair<int, int>>Q2;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == 'F') {
				Q1.push({ i,j });
				dist1[i][j] = 0;
			}
			if (board[i][j] == 'J') {
				Q2.push({ i,j });
				dist2[i][j] = 0;
			}
		}
	}
	while (!Q1.empty()) {
		auto cur = Q1.front();
		Q1.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;
			if (dist1[nx][ny] >= 0 || board[nx][ny] == '#')
				continue;
			dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
			Q1.push({ nx,ny });
		}
	}
	while (!Q2.empty()) {
		auto cur = Q2.front();
		Q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
				cout << dist2[cur.X][cur.Y] + 1;
				return 0;
			}
			if (dist2[nx][ny] >= 0 || board[nx][ny] == '#')
				continue;
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1)
				continue;
			dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
			Q2.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE";
}