토마토
=====================================
토마토가 다 익게 되는 최소 일 수 구하기. 
-------------------------------------

#1. 해결방법
> 삼차원 배열을 사용한다. z,y,x (h,n,m) 
> 익지 않은 토마토와 익은 토마토의 위치를 이용한다. queue를 두 개 이용해야 한다.

#2. 코드
<pre><code>{#include <bits/stdc++.h>
using namespace std;

int m, n, h;
int tomato[103][103][103];
int dist[103][103][103];

int dh[6] = { 0,0,0,0,1,-1 };
int dy[6] = { 0,0,1,-1,0,0 };
int dx[6] = { 1,-1,0,0,0,0 };

queue<tuple<int, int, int>> q;

void bfs() {

}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> h;
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				int tmp;
				cin >> tmp;
				tomato[j][k][i] = tmp;
				if (tmp == 1) q.push({ j, k, i });
				if (tmp == 0) dist[j][k][i] = -1;
			}
		}
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int curX, curY, curZ;
		tie(curX, curY, curZ) = cur;
		for (int dir = 0; dir < 6; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			int nz = curZ + dz[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if (dist[nx][ny][nz] >= 0) continue;
			dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
			q.push({ nx, ny, nz });
		}
	}

	int ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (dist[j][k][i] == -1) {
					cout << -1 << "\n";
					return 0;
				}
				ans = max(ans, dist[j][k][i]);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}}</code>

#3. 어려웠던 점
어떻게 처음부터 그렇게 구현하는 건지 정말 어렵네요.
