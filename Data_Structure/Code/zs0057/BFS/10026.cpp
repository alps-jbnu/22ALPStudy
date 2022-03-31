#include <bits/stdc++.h>
using namespace std;
string board[101];
int vis[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
#define X first
#define Y second

int main(void) {
	int n;
	int count1 = 0;
	int count2 = 0;
	cin >> n;
	char color1[3] = { 'R', 'B', 'G' };
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	for (char c : color1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (vis[i][j] || board[i][j] != c) continue;
				queue<pair<int, int>> Q;
				Q.push({ i, j });
				vis[i][j] = 1;
				count1++;
				while (!Q.empty()) {
					pair<int, int> cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (board[nx][ny] != c || vis[nx][ny]) continue;
						Q.push({ nx, ny });
						vis[nx][ny] = 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'G') board[i][j] = 'R';
		}
		fill(vis[i], vis[i] + n, 0);
	}
	char color2[2] = { 'B', 'R' };
	for (char c : color2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (vis[i][j] || board[i][j] != c) continue;
				queue<pair<int, int>> Q;
				Q.push({ i, j });
				vis[i][j] = 1;
				count2++;
				while (!Q.empty()) {
					pair<int, int> cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (board[nx][ny] != c || vis[nx][ny]) continue;
						Q.push({ nx, ny });
						vis[nx][ny] = 1;
					}
				}
			}
		}
	}
	cout << count1 << " " << count2;
}