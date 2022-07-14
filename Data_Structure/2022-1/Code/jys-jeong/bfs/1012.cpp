#include<bits/stdc++.h>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		queue<pair<int, int>> q;
		int board[52][52] = { 0 };
		bool vis[52][52] = { false };
		int m, n, k;
		cin >> m >> n >> k;
		int cnt = 0;
		for (int j = 0; j < k; j++) {
			int a, b;
			cin >> a >> b;
			board[a][b] = 1;
		}
		for (int a = 0; a < m; a++) {
			for (int b = 0; b < n; b++) {
				if (board[a][b] == 0 || vis[a][b])	continue;
				q.push({ a,b });
				++cnt;
				vis[a][b] = 1;
				while (!q.empty()) {
					auto dot = q.front();
					q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int x = dx[dir] + dot.first;
						int y = dy[dir] + dot.second;
						if (x < 0 || y < 0 || x >= m || y >= n)	continue;
						if (board[x][y] == 0 || vis[x][y])	continue;
						vis[x][y] = 1;
						q.push({ x,y });
					}
				}
			}
		}
		cout << cnt<<"\n";
	}

}