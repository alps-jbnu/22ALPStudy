#include<iostream>
#include<queue>
#include<string>
#include<memory.h>
#include<vector>
using namespace std;

int board[22][22];
int vis[22][22];
int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { -1, 0, 0, 1 };
int bx, by;
int answer = 0;
int s = 2;
bool stop = false;
bool eat = false;
int n;

void bfs(int a, int b, bool vis[][22], int sSize) {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(a, b), 0));
	vis[b][a] = true;
	int temp;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;

		if (board[y][x] > 0 && board[y][x] < sSize && temp == cnt) {
			if ((by > y) || (by == y && bx > x)) {
				by = y;
				bx = x;
				continue;
			}
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[ny][nx]) {
				if (board[ny][nx] <= sSize) {
					if (board[ny][nx] > 0 && board[ny][nx] < sSize && !eat) {
						eat = true;
						bx = nx;
						by = ny;
						temp = cnt + 1;
						answer += temp;
					}
					else{
						q.push(make_pair(make_pair(nx, ny), cnt + 1));
					vis[ny][nx] = true;
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int count = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				by = i;
				bx = j;
				board[i][j] = 0;
			}
		}
	}

	while (!stop) {
		bool vis[22][22] = { 0 };
		bfs(bx, by, vis, s);
		if (eat) {
			eat = false;
			count += 1;
			board[by][bx] = 0;
			if (count == s) {
				s += 1;
				count = 0;
			}
		}
		else {
			stop = true;
		}
	}
	cout << answer;
}