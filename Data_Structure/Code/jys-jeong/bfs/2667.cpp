#include<bits/stdc++.h>
using namespace std;

string board[30];
bool vis[30][30];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
			cin >> board[i];
	}
	vector<int> cnt;
	int got = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == '0' || vis[i][j])	continue;
			queue<pair<int, int>> q;
			q.push({ i,j });
			vis[i][j] = 1;
			int a = 1;
			++got;
			while (!q.empty()) {
				auto dot = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int x = dx[dir] + dot.first;
					int y = dy[dir] + dot.second;
					if (x < 0 || y < 0 || x >= n || y >= n)	continue;
					if (board[x][y] == '0' || vis[x][y])	continue;
					++a;
					vis[x][y] = 1;
					q.push({ x,y });
				}
			}
			cnt.push_back(a);
		}
	}
	std::sort(cnt.begin(), cnt.end());
	cout << got<<"\n";
	for (int i = 0; i < cnt.size(); i++) {
		cout<<cnt[i]<<"\n";
	}
}