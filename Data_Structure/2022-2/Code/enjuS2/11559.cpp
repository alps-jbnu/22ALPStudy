#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
char board[12][6];
bool vis[12][6];
int ans = 0;

bool bfs(int x, int y) {
	queue<pair<int, int>> q;
	queue<pair<int, int>> boom;
	memset(vis, false, sizeof(vis));
	q.push({x,y});
	boom.push({x,y});
	vis[x][y] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6 || vis[nx][ny]) continue;
			if (board[nx][ny] == board[x][y] && !vis[nx][ny]) {
				q.push(make_pair(nx, ny));
				boom.push(make_pair(nx, ny));
				vis[nx][ny] = true;
			}
		}
	}

	if (boom.size() >= 4) {
		while (!boom.empty()) {
			board[boom.front().first][boom.front().second] = '.';
			boom.pop();
		}
		return true;
	}
	else {
		return false;
	}
}

void down() {
	for (int i = 0; i < 6; i++) {
		queue<char>q;
		for (int j = 12 - 1; j >= 0; j--) {
			if (board[j][i] != '.') {
				q.push(board[j][i]);
			}
		}
		int qsize = q.size();
		for (int j = 12 - 1; j >= 12 - qsize; j--) {
			board[j][i] = q.front();
			q.pop();
		}
		for (int j = 12 - qsize - 1; j >= 0; j--) {
			board[j][i] = '.';
		}
	}
}

void print() {
	cout << "---------------------------------------\n";
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> board[i][j];
		}
	}

	while (1) {
		bool flag = false;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (board[i][j] != '.') {
					if (bfs(i, j)) {
						flag = true;
					}
				}
			}
		}

		if (flag == false) {
			break;
		}
		else {
			ans++;
			down();
		}
	}
	cout << ans;
}