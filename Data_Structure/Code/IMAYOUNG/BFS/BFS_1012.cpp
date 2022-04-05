#include <bits/stdc++.h>
using namespace std;

int board[51][51];
int vis[51][51];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	int t;
	cin >> t;
	int num = 0;

	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			board[i][j] = 0;
			vis[i][j] = 0;
		}
		
		int m, n, k;
		cin >> m >> n >> k;

		while (k--) {
			int a, b;
			cin >> a >> b;
			board[a][b] = 1;
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 0 || vis[i][j] == 1)continue;
				num++;
				queue < pair<int, int>> q;
				vis[i][j] = 1;
				q.push({ i,j });

				while (!q.empty()) {
					pair<int, int> current = q.front();
					q.pop();
					
					for (int di = 0; di < 4; di++) {
						int x = current.first + dx[di];
						int y = current.second + dy[di];

						if (x < 0 || x >= m || y < 0 || y >= n)continue;
						if (board[x][y] == 0 vis[x][y] == 1)continue;

						vis[x][y] = 1;
						q.push({ x,y });
					}
				}
			}
		}
		cout << num << "\n";
	}
}