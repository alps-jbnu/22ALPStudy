#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

char wall[1005][1005];
int length[1000][1000][2];
int n, m;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> wall[i][j];
		}
	}
		

	length[0][0][0] = 1;
	length[0][0][1] = 1;

	queue<tuple<int, int, int> > q;
	q.push({ 0, 0, 0 });

	while (!q.empty()) {
		int x, y, broke;
		tie(x, y, broke) = q.front();

		// 최단 경로
		if (x == n - 1 && y == m - 1) {
			cout << length[x][y][broke];
			return 0;
		}

		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (x < 0 || x >= n || y < 0 || y >= m) continue;
			if (wall[nx][ny] == '0' && length[nx][ny][broke] == 0) {
				length[nx][ny][broke] = length[x][y][broke] + 1;
				q.push({ nx, ny, broke });
			}

			// 벽을 부수는 경우
			if (!broke && wall[nx][ny] == '1' && length[nx][ny][1] == 0) {
				length[nx][ny][1] = length[x][y][broke] + 1;
				q.push({ nx, ny, 1 });
			}
		}
	}
	cout << -1;
	return 0;
}

/*
- 주어진 범위 때문에 기존의 완전탐색을 통해 모든 벽을 깨서 확인하고 비교하는 방법은 시간초과가 발생하게 된다.
- 따라서 이 문제의 핵심은 시간초과하지 않고 접근해야 한다.
*/
