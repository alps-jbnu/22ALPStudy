#include <bits/stdc++.h>
using namespace std;

//연속된 1을 찾는다. bfs로 방문!
//열을 반복해서 돈다. 하지만 값이 1이고, 방문을 하지 않은 곳이어야 함.
//for -> 값 1 && 방문X
//돌면서, 카운팅 해서 최댓값 찾기

int pic[501][501];
bool visit[501][501];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue <pair <int, int>> q;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> pic[i][j];

	int cnt = 0;
	int maximum = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (pic[i][j] == 1 && visit[i][j]== false) {
				cnt++;
				visit[i][j] = 1;
				q.push({ i,j });

				int size = 0;

				while (!q.empty()) {
					size++;
					pair<int, int> now = q.front();
					q.pop();
					for (int i = 0; i < 4; i++) {
						int py = now.first + y[i];
						int px = now.second + x[i];

						if (px < 0 || px >= n || py < 0 || py >= m) continue; 
						if (visit[px][py] || pic[px][py] != 1) continue;
						visit[py][px] = 1;
						q.push(make_pair(py, px)); 
					}

				}
					maximum = max(maximum, size);
			}
		}
	}

	cout << cnt << "\n" << maximum;

}