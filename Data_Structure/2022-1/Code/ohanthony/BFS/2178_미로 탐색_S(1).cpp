#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
string maze[105];
int length[105][105];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0 , -1, 0 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> maze[i];

	fill(&length[0][0], &length[104][105], -1);
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	length[0][0] = 0;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (length[nx][ny] > -1 || maze[nx][ny] != '1') continue;

			q.push({ nx, ny });
			length[nx][ny] = length[cur.X][cur.Y] + 1;
		}
	}

	cout << length[n - 1][m - 1] + 1;
	return 0;
}
