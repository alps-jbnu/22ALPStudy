#include<bits/stdc++.h>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool vis1[102][102];
bool vis2[102][102];
string board[102];
int cnt1 = 0, cnt2=0;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis1[i][j])	continue;
			++cnt1;
			queue<pair<int, int>> q;
			q.push({ i,j });
			vis1[i][j] = 1;
			while (!q.empty()) {
				auto dot = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int x = dx[dir] + dot.first;
					int y = dy[dir] + dot.second;
					if (x < 0 || y < 0 || x >= n || y >= n)	continue;
					if (vis1[x][y] || board[x][y] != board[dot.first][dot.second])	continue;
					vis1[x][y] = 1;
					q.push({ x,y });
				}
			}
		}
	}
	cout << cnt1<<" ";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'R')	board[i][j] = 'G';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis2[i][j])	continue;
			++cnt2;
			queue<pair<int, int>> q;
			q.push({ i,j });
			vis1[i][j] = 1;
			while (!q.empty()) {
				auto dot = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int x = dx[dir] + dot.first;
					int y = dy[dir] + dot.second;
					if (x < 0 || y < 0 || x >= n || y >= n)	continue;
					if (vis2[x][y] || board[x][y] != board[dot.first][dot.second])	continue;
					vis2[x][y] = 1;
					q.push({ x,y });
				}
			}
		}
	}
	cout << cnt2;
}