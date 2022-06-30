#include<bits/stdc++.h>
using namespace std;

int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int board[102][102][102];
int tomato[102][102][102];
int main() {
	int n,m, k;
	cin >> n >> m >> k;
	queue<tuple<int, int,int>> q;

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < m; j++) {
			for (int g = 0; g < n; g++) {
				cin >> board[i][j][g];
				if (board[i][j][g] == 1) {
					q.push({ i,j,g });
				}
			}
		}
	}
	while (!q.empty()) {
		int a, b, c;
		tie(a, b, c) = q.front();
		q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int x = a + dx[dir];
			int y = b + dy[dir];
			int z = c + dz[dir];
			if (x < 0 || y < 0 || z < 0 || x >= k || y >= m || z >= n)	continue;
			if (board[x][y][z] != 0 || tomato[x][y][z] > 0)	continue;
			tomato[x][y][z] = tomato[a][b][c] + 1;
			board[x][y][z] = 1;
			q.push({ x,y,z });
		}
	}
	int day = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < m; j++) {
			for (int g = 0; g < n; g++) {
				if (board[i][j][g] == 0) {
					cout << "-1";
					return 0;
				}
				if (day < tomato[i][j][g]) {
					day = tomato[i][j][g];
				}
			}
		}
	}
	cout << day;
}