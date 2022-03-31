#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dist[301][301];
int dx[8] = { 1, 1, 2, 2, -1, -1, 2, 2 };
int dy[8] = { 2, -2, 1, -1, 2, -2, 1, -1 };
queue<pair<int, int>> Q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int l;
	cin >> l;
	int x, y;
	cin >> x >> y;
	for (int i = 0; i < l; i++)
		fill(dist[i], dist[i] + l, -1);

	int finx, finy;
	cin >> finx >> finy;

	
	Q.push({ x, y });
	dist[x][y] = 0;

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 8; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
			if (dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({ nx, ny });
		}
	}
	cout << dist[finx][finy];
}