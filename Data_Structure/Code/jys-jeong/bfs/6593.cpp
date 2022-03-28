#include<bits/stdc++.h>
using namespace std;

char board[32][32][32];
int cnt[32][32][32];
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int main() {
	int l, r, c;
	cin >> l >> r >> c;
	while (l!=0||r!=0||c!=0) {
		int ax, ay, az;
		queue<tuple<int, int, int>> q;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				fill(cnt[i][j], cnt[i][j] + c, -1);
			}
		}
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> board[i][j][k];
					if (board[i][j][k] == 'S') {
						q.push({ i,j,k });
						cnt[i][j][k] = 0;
					}
					if (board[i][j][k] == 'E'){
						ax = i;
						ay = j;
						az = k;
					}
				}
			}
		}

		while (!q.empty()) {
			int a, b, d;
			tie(a, b, d) = q.front();
			q.pop();
			for (int dir = 0; dir < 6; dir++) {
				int x = dx[dir] + a;
				int y = dy[dir] + b;
				int z = dz[dir] + d;
				if (x < 0 || y < 0 || z < 0 || x >= l || y >= r || z >= c)	continue;
				if (cnt[x][y][z] != -1 || board[x][y][z] == '#')	continue;
				cnt[x][y][z] = cnt[a][b][d] + 1;
				q.push({ x,y,z });
			}
		}
		if (cnt[ax][ay][az] != -1) {
			cout << "Escaped in "<<cnt[ax][ay][az] << " minute(s).\n";
		}
		else {
			cout << "Trapped!\n";
		}
		cin >> l >> r >> c;
	}
}