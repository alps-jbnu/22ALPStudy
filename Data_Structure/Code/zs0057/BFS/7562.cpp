#include <bits/stdc++.h>
using namespace std;
int dist[301][301];
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
#define X first
#define Y second
int t;
int l;

int finx, finy;
queue<pair<int, int>> Q;

int main(void) {
	cin >> t;
	while (t--) {
		cin >> l;
		for (int i = 0; i < l; i++) fill(dist[i], dist[i] + l, -1);
		int x, y;
		cin >> x >> y;
		Q.push({ x, y });
		dist[x][y] = 0;
		cin >> finx >> finy;
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
		cout << dist[finx][finy] << '\n';
	}
	
}