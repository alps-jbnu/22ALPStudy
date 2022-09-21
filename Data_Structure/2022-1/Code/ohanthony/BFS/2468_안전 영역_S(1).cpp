#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int height[105][105];
int n, M, result; // M: 최댓 강수량 기준, result: 결과값

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> height[i][j];
			if (M < height[i][j]) M = height[i][j]; // 최대 높이
		}
	}

	for (int i = 0; i < M; i++) { // 모든 경우 구할 필요 없이 최대 강수량 전까지만 구하면 된다
		bool vis[105][105] = { 0, };
		int count = 0;
		queue<pair <int, int>> q;

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (vis[j][k] || height[j][k] <= i) continue;

				vis[j][k] = 1;
				q.push({ j, k });
				count++;

				while (!q.empty()) {
					auto cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (vis[nx][ny] || height[nx][ny] <= i) continue;

						vis[nx][ny] = 1;
						q.push({ nx, ny });
					}
				}
			}
		}
		result = max(result, count);
	}
	cout << result;
	return 0;
}