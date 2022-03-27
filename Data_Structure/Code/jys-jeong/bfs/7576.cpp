#include<bits/stdc++.h>
using namespace std;

int tomato[1002][1002];
bool vis[1002][1002];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main() {
	int m, n;
	cin >> n >> m;
	int day = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}
	while (!q.empty()) {
		auto dot = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = dx[i] + dot.first;
			int y = dy[i] + dot.second;
			if (x < 0 || y < 0 || x >= m || y >= n)	continue;
			if (tomato[x][y] != 0)	continue;
			tomato[x][y] = tomato[dot.first][dot.second] + 1;
			q.push({ x,y });
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (day < tomato[i][j]) {
				day = tomato[i][j];
			}
			if (tomato[i][j] == 0) {
				cout << "-1";
				return 0;
			}
		}
	}
	cout << day-1;
}