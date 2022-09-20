#include<bits/stdc++.h>
using namespace std;

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		int l, r, c;
		cin >> l >> r >> c;
		if (l + r + c == 0) break;

		queue<tuple<int, int, int>> q;
		char board[35][35][35];
		int mini[35][35][35];
		bool isEscape = false;

		fill(&mini[0][0][0], &mini[34][34][35], -1);

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> board[i][j][k];
					if (board[i][j][k] == 'S') {
						q.push({ i, j, k });
						mini[i][j][k] = 0;
					}
				}
			}
		}

		while (!q.empty()) {
			if (isEscape) break;
			auto cur = q.front();
			q.pop();
			int curz, curx, cury;
			tie(curz, curx, cury) = cur;

			for (int dir = 0; dir < 6; dir++) {
				int nx = curx + dx[dir];
				int ny = cury + dy[dir];
				int nz = curz + dz[dir];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) continue;
				if (board[nz][nx][ny] == '#' || mini[nz][nx][ny] > 0) continue;

				mini[nz][nx][ny] = mini[curz][curx][cury] + 1;
				if (board[nz][nx][ny] == 'E') {
					cout << "Escaped in " << mini[nz][nx][ny] << " minute(s)."<< "\n";
					isEscape = true;
					break;
				}
				q.push({ nz, nx, ny });
			}
		}

		while (!q.empty()) q.pop();
		if (!isEscape) cout << "Trapped!" << "\n";
	}
	
	return 0;
}