#include <iostream>
#include <queue>
using namespace std;

int N;
char grid[101][101];
bool vis[101][101];
int dx[4]{ 0,1,0,-1 };
int dy[4]{ 1,0,-1,0 };
queue<pair<int, int>> Q;
int cnt;

void initialize() {
	for (int i{}; i < 101; i++) {
		for (int j{}; j < 101; j++) {
			vis[i][j] = 0;
		}
	}
	cnt = 0;
}
void bfs(char color) {
	while (!Q.empty()) {
		int curX{ Q.front().first };
		int curY{ Q.front().second };
		Q.pop();
		for (int i{}; i < 4; i++) {
			int nX{ curX + dx[i] };
			int nY{ curY + dy[i] };
			if (nX < 0 || nY < 0 || nX >= N || nY >= N) continue;
			if (grid[nX][nY] != color || vis[nX][nY]) continue;
			vis[nX][nY] = true;
			Q.push({ nX, nY });
		}
	}
	cnt++;
}
void blinding() {
	for (int i{}; i < N; i++) {
		for (int j{}; j < N; j++) {
			if (grid[i][j] == 'B') continue;
			grid[i][j] = 'X';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i{}; i < N; i++) {
		for (int j{}; j < N; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i{}; i < N; i++) {
		for (int j{}; j < N; j++) {
			if (vis[i][j]) continue;
			if (grid[i][j] == 'R') {
				Q.push({ i, j });
				bfs('R');
			}
			else if (grid[i][j] == 'G') {
				Q.push({ i, j });
				bfs('G');
			}
			else if (grid[i][j] == 'B') {
				Q.push({ i, j });
				bfs('B');
			}
		}
	}
	cout << cnt << "\n";
	initialize();
	blinding();
	for (int i{}; i < N; i++) {
		for (int j{}; j < N; j++) {
			if (vis[i][j]) continue;
			if (grid[i][j] == 'B') {
				Q.push({ i, j });
				bfs('B');
			}
			else if (grid[i][j] == 'X') {
				Q.push({ i, j });
				bfs('X');
			}
		}
	}
	cout << cnt << "\n";
	return 0;
}