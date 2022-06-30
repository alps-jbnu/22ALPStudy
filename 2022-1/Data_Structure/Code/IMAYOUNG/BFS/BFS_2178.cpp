#include <bits/stdc++.h>
using namespace std;

//최소의 칸 -> 최단 거리 

string map[100];
int dis[100][100];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	queue<pair<int, int> > q;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> map[i];

	q.push(make_pair(0, 0));
	dis[0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m
				&& dis[nx][ny] == 0 && map[nx][ny] == '1') {
				q.push(make_pair(nx, ny));
				dis[nx][ny] = dis[x][y] + 1;
			}
		}
	}
	cout << dis[n - 1][m - 1]; //조심하기.

	return 0;
}