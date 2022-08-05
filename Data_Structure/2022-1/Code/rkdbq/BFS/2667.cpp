#define X first
#define Y second
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int dx[4]{ 0,1,0,-1 };
int dy[4]{ 1,0,-1,0 };
bool map[26][26];
bool vis[26][26];
queue<pair<int, int>> Q;
int ans[626];
int cnt;

void bfs() {
	while (!Q.empty()) {
		int curX = { Q.front().X };
		int curY = { Q.front().Y };
		Q.pop();
		for (int i{}; i < 4; i++) {
			int nX{ curX + dx[i] };
			int nY{ curY + dy[i] };
			if (nX < 0 || nY < 0 || nX >= N || nY >= N) continue;
			if (map[nX][nY] == false) continue;
			if (vis[nX][nY]) continue;
			vis[nX][nY] = true;
			Q.push({ nX, nY });
			ans[cnt]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for (int i{}; i < N; i++) {
		string input;
		cin >> input;
		for (int j{}; j < N; j++) {
			map[i][j] = input[j] - '0';
		}
	}
	for (int i{}; i < N; i++) {
		for (int j{}; j < N; j++) {
			if (map[i][j] == false) continue;
			if (vis[i][j]) continue;
			Q.push({ i, j });
			vis[i][j] = true;
			ans[cnt]++;
			bfs();
			cnt++;
		}
	}
	cout << cnt << "\n";
	sort(ans, ans + cnt);
	for (int i{}; i < cnt; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}