#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m, piece, result;
int board[505][505];
bool vis[505][505];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0 , -1, 0 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] || board[i][j] != 1) continue;

			int area = 0;
			vis[i][j] = true;
			queue<pair<int, int> > q;
			q.push({ i, j });
			piece++;
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				area++;
				
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny] || board[nx][ny] != 1) continue;

					q.push({ nx, ny });
					vis[nx][ny] = true;
				}
			}
			result = max(result, area);
		}
	}

	cout << piece << "\n" << result;
	return 0;
}
