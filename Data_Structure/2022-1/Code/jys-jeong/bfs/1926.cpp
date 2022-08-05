#include<bits/stdc++.h>
using namespace std;

int board[502][502];
bool vis[502][502];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int max = 0;
	int count = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] || board[i][j] == 0)	continue;
			int cnt = 1;
			q.push({ i,j });
			++count;
			vis[i][j] = 1;
			while (!q.empty()) {
				auto dot = q.front();
				q.pop();
				for (int dis = 0; dis < 4; dis++) {
					int x = dx[dis]+dot.first;
					int y = dy[dis] + dot.second;
					if (x < 0 || y < 0 || x >= n || y >= m)	continue;
					if (vis[x][y]==1||board[x][y]==0)	continue;
					++cnt;
					vis[x][y] = 1;
					q.push({ x,y });
				}
			}
			if (cnt >= max) {
				max = cnt;
			}
		}
	}
	cout << count << "\n" << max;


}