#include<bits/stdc++.h>
using namespace std;


int dx[8] = { 2,2,1,1,-1,-1,-2,-2 };
int dy[8] = { 1,-1,2,-2,2,-2,1,-1 };
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a;
		cin >> a;
		int vis[304][304];
		for (int j = 0; j < a; j++) {
			fill(vis[j], vis[j] + a, -1);
		}
		pair<int, int> finish;
		int b, c;
		cin >> b >> c;
		queue<pair<int, int>> q;
		q.push({ b,c });
		vis[b][c] = 0;
		cin >> finish.first >> finish.second;
		while (!q.empty()) {
			auto dot = q.front();
			q.pop();
			for (int dir = 0; dir < 8; dir++) {
				int x = dx[dir] + dot.first;
				int y = dy[dir] + dot.second;
				if (x < 0 || y < 0 || x >= a || y >= a)	continue;
				if (vis[x][y]!=-1)	continue;
				vis[x][y] = vis[dot.first][dot.second] + 1;
				q.push({ x,y });
			}
		}
		cout << vis[finish.first][finish.second] << "\n";
	}
}