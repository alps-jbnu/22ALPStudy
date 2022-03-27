#include<bits/stdc++.h>
using namespace std;

string board[102];
bool vis[102][102];
int cnt[102][102];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	vis[0][0] = 1;
	cnt[0][0] = 1;
	while (!q.empty()) {
		auto dot = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = dot.first + dx[i];
			int y = dot.second + dy[i];
			if (x < 0 || y < 0 || x >= n || y >= m)	continue;
			if (vis[x][y]||board[x][y] == '0')	continue;
			if(cnt[x][y]==0)
			cnt[x][y] = cnt[dot.first][dot.second]+1;
			vis[x][y] = 1;
			q.push({ x,y });
		}

	}
	cout << cnt[n - 1][m - 1];
}