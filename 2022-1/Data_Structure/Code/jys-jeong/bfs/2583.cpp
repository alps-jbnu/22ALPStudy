#include<bits/stdc++.h>
using namespace std;

int board[102][102];
bool vis[102][102];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main() {
	int cnt = 0;
	int n, m, k;
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j < x2; j++) {
			for (int a = y1; a < y2; a++) {
				board[j][a] = 1;
			}
		}
	}
	vector<int> area;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 || vis[i][j])	continue;
			queue<pair<int, int>> q;
			q.push({ i,j });
			vis[i][j] = 1;
			++cnt;
			int g = 1;
			while (!q.empty()) {
				auto dot = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int x = dx[dir] + dot.first;
					int y = dy[dir] + dot.second;
					if (x < 0 || y < 0 || x >= n || y >= m)	continue;
					if (vis[x][y] || board[x][y] == 1)	continue;
					++g;
					vis[x][y] = 1;
					q.push({ x,y });
				}
			}
			area.push_back(g);
		}
	}
	std::cout << cnt << "\n"  ;
	sort(area.begin(), area.end());
	for (int i = 0; i < cnt; i++) {
		std::cout << area[i] << " ";
	}
}