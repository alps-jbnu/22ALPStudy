#include<bits/stdc++.h>
using namespace std;

int board[102][102];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int big = 0;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (big < board[i][j])
				big = board[i][j];
		}
	}
	int mx = 0;
	for (int a = 0; a <= big; a++) {
		bool vis[102][102] = { false };
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] <= a || vis[i][j])	continue;
				queue<pair<int, int>> q;
				q.push({ i,j });
				vis[i][j] = 1;
				++cnt;
				while (!q.empty()) {
					auto dot = q.front();
					q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int x = dx[dir] + dot.first;
						int y = dy[dir] + dot.second;
						if (x < 0 || y < 0 || x >= n || y >= n)	continue;
						if (vis[x][y] || board[x][y] <= a)	continue;
						vis[x][y] = 1;
						q.push({ x,y });
					}
				}
			}
		}
		if (mx < cnt) {
			mx = cnt;
		}
	}
	cout << mx;
}