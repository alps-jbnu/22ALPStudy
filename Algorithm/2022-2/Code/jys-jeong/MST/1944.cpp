#include <bits/stdc++.h>
using namespace std;

int n, m,sx,sy;
string board[52];
bool vis[52][52];
int key_num[52][52];
vector<pair<int, int>> k;
vector<tuple<int, int, int>> edge;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int p[255];
int find(int x) {
	if (p[x] < 0)	return x;
	return p[x] = find(p[x]);
}
bool is_diff_grp(int u ,int v) {
	u = find(u);
	v = find(v);
	if (u == v)	return 0;
	if (p[u] > p[v])	swap(u, v);
	p[u] += p[v];
	p[v] = u;
	return 1;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int key = 1;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'K') {
				k.push_back({ i,j });
				key_num[i][j] = key++;
			}
			else if (board[i][j] == 'S') {
				sx = i;
				sy = j;
			}
		}
	}

	for (int i = 0; i < k.size(); i++) {
		memset(vis, false, sizeof(vis));
		queue<tuple<int, int,int>> q;
		q.push({ sx,sy,0 });
		while (!q.empty()) {
			int x;
			int y;
			int cnt;
			tie(x, y, cnt) = q.front();
			q.pop();
			if (x == k[i].first && y == k[i].second) {
				edge.push_back({ cnt,0,key_num[x][y] });
				break;
			}
			for (int dir = 0; dir < 4; dir++) {
				int nx = dx[dir] + x;
				int ny = dy[dir] + y;
				if (nx < 0 || ny < 0 || nx >= n || ny >= n)	continue;
				if (board[nx][ny] == '1')	continue;
				if (vis[nx][ny])	continue;
				vis[nx][ny] = 1;
				q.push({ nx,ny,cnt+1 });
			}
		}
		if (!vis[k[i].first][k[i].second]) {
			cout << "-1";
			return 0;
		}
	}
	for (int i = 0; i < k.size(); i++) {
		int x = k[i].first;
		int y = k[i].second;
		for (int j = i + 1; j < k.size(); j++) {
			memset(vis, false, sizeof(vis));
			int xx = k[j].first;
			int yy = k[j].second;
			queue<tuple<int, int, int>> q;
			q.push({ x,y,0 });
			while (!q.empty()) {
				int ax;
				int ay;
				int cnt;
				tie(ax, ay, cnt) = q.front();
				q.pop();
				if (ax == xx && ay ==yy) {
					edge.push_back({ cnt,key_num[x][y], key_num[xx][yy]});
					break;
				}
				for (int dir = 0; dir < 4; dir++) {
					int nx = dx[dir] + ax;
					int ny = dy[dir] + ay;
					if (nx < 0 || ny < 0 || nx >= n || ny >= n)	continue;
					if (board[nx][ny] == '1')	continue;
					if (vis[nx][ny])	continue;
					vis[nx][ny] = 1;
					q.push({ nx,ny,cnt+1 });
				}
			}
			if (!vis[k[j].first][k[j].second]) {
				cout << "-1";
				return 0;
			}
		}
	}

	fill(p, p + m+1, -1);
	sort(edge.begin(), edge.end());
	int ans = 0;
	for (int i = 0; i < edge.size(); i++) {
		int cost,node1,node2;
		tie(cost, node1, node2) = edge[i];
		if (is_diff_grp(node1, node2)) {
			ans += cost;
		}
	}
	cout << ans;

}