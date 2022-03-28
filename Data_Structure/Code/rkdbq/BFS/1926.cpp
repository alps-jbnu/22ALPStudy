#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool paper[501][501];
bool vis[501][501];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i{}; i < n; i++) {
		for (int j{}; j < m; j++) {
			cin >> paper[i][j];
		}
	}
	int mx = 0; // 그림의 최댓값
	int num = 0; // 그림의 수
	for (int i{}; i < n; i++) {
		for (int j{}; j < m; j++) {
			if (vis[i][j] || paper[i][j] == false) continue;
			num++;
			queue<pair<int, int>> bfs;
			vis[i][j] = true;
			//cout << i << " " << j <`< " checked\n";
			bfs.push({ i, j });
			int area = 0;
			while (!bfs.empty()) {
				area++;
				int curX{ bfs.front().first };
				int curY{ bfs.front().second };
				bfs.pop();
				for (int k{}; k < 4; k++) {
					int nX{ curX + dx[k] };
					int nY{ curY + dy[k] };
					if (nX < 0 || nY < 0 || nX >= n || nY >= m) continue;
					if (vis[nX][nY]) continue;
					if (paper[nX][nY] == false) continue;
					vis[nX][nY] = true;
					//cout << nX << " " << nY << " checked\n";
					bfs.push({ nX, nY });
				}
			}
			mx = max(mx, area);
		}
	}
	cout << num << "\n" << mx;
}