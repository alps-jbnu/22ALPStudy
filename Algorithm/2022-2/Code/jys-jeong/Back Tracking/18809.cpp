#include <bits/stdc++.h>
using namespace std;


int n, m, g, r;
int board[52][52];
vector<pair<int, int>> gv;
vector<pair<int, int>> rv;
vector<pair<int, int>> v;
pair<int, int> p[10];
bool vis[2500];
int ans = 0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int bfs() {
	queue<pair<int, int>> q;
	queue<pair<int, int>> rq;
	int board1[52][52] = { 0 };
	int board2[52][52] = { 0 };
	bool flower[52][52];
	int mx = 0;
	for (int i = 0; i < 52; i++) {
		fill(board1[i], board1[i] + 52, -1);
		fill(board2[i], board2[i] + 52, -1);
		fill(flower[i], flower[i] + 52, 0);
	}
	for (int i = 0;  i < gv.size(); i++) {
		q.push(gv[i]);
		board1[gv[i].first][gv[i].second] = 0;
	}
	for (int i = 0; i < rv.size(); i++) {
		rq.push(rv[i]);
		board2[rv[i].first][rv[i].second] = 0;
	}
	
	while (!q.empty() || !rq.empty()) {
		int rsize = rq.size();
		int gsize=q.size();

		while (gsize--) {
			auto dot = q.front();
			q.pop();
			if (flower[dot.first][dot.second])	continue;
			for (int dir = 0; dir < 4; dir++) {
				int x = dx[dir] + dot.first;
				int y = dy[dir] + dot.second;
				if (x < 0 || y < 0 || x >= n || y >= m)	continue;
				if (board1[x][y] != -1 || board[x][y] == 0)	continue;
				if (flower[x][y])continue;
				if (board2[x][y] != -1 && board2[x][y] != board1[dot.first][dot.second] + 1)	continue;
				else if (board2[x][y] != -1 && board2[x][y] == board1[dot.first][dot.second] + 1) {
					++mx;
					flower[x][y] = 1;
					board1[x][y] = board1[dot.first][dot.second] + 1;
					continue;
				}
				board1[x][y] = board1[dot.first][dot.second] + 1;
				q.push({ x,y });
			}

		}
		while (rsize--) {
			auto dot = rq.front();
			rq.pop();
			if (flower[dot.first][dot.second])	continue;
			for (int dir = 0; dir < 4; dir++) {
				int x = dx[dir] + dot.first;
				int y = dy[dir] + dot.second;
				if (x < 0 || y < 0 || x >= n || y >= m)	continue;
				if (board[x][y] == 0 || board2[x][y] != -1)	continue;
				if (flower[x][y])	continue;
				if (board1[x][y] != -1 && board1[x][y] != board2[dot.first][dot.second] + 1)	continue;
				else if (board1[x][y] != -1 && board1[x][y] == board2[dot.first][dot.second] + 1) {
					++mx;
					flower[x][y] = 1;
					board2[x][y] = board2[dot.first][dot.second] + 1;
					continue;
				}
				else {
					board2[x][y] = board2[dot.first][dot.second] + 1;
					rq.push({ x,y });
				}
			}
		}
	}
	return mx ;
}




void func(int cur,int gcnt,int rcnt) {
	if (gcnt+rcnt > v.size()-cur)	return;
	if (gcnt==0&&rcnt==0) {
		ans = max(ans, bfs());
		return;
	}

	if (cur == v.size())	return;
	func(cur + 1, gcnt, rcnt);
	if (gcnt > 0) {
		gv.push_back({v[cur].first,v[cur].second});
		func(cur + 1, gcnt - 1, rcnt);
		gv.pop_back();
	}
	if (rcnt > 0) {
		rv.push_back({ v[cur].first,v[cur].second });
		func(cur + 1, gcnt, rcnt-1);
		rv.pop_back();
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> g >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				v.push_back({ i,j });
			}
		}
	}
	func(0,g,r);
	cout << ans;
 }