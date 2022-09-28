#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string maze[1005];
int Ftime[1005][1005];
int Jtime[1005][1005];

queue<pair<int, int>> J;
queue<pair<int, int>> F;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++) cin >> maze[i];

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (maze[i][j] == 'J') {
				J.push({ i, j });
				Jtime[i][j] = 1;
			}
			if (maze[i][j] == 'F') {
				F.push({ i, j });
				Ftime[i][j] = 1;
			}
		}
	}

	// 불에 대한 BFS
	while (!F.empty()) {
		auto cur = F.front();
		F.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (Ftime[nx][ny] > 0 || maze[nx][ny] == '#') continue;

			F.push({ nx, ny });
			Ftime[nx][ny] = Ftime[cur.X][cur.Y] + 1;
		}
	}

	while (!J.empty()) {
		auto cur = J.front();
		J.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c) { // 이 범위에 들어왔다는건 탈출했다는 의미
				cout << Jtime[cur.X][cur.Y];
				return 0;
			}
			if (Jtime[nx][ny] > 0 || maze[nx][ny] == '#') continue;
			if (Ftime[nx][ny] != 0 && Ftime[nx][ny] <= Jtime[cur.X][cur.Y] + 1) continue; // 불의 전파시간을 고려

			J.push({ nx, ny });
			Jtime[nx][ny] = Jtime[cur.X][cur.Y] + 1;
		}

	}

	cout << "IMPOSSIBLE";
	return 0;
}
