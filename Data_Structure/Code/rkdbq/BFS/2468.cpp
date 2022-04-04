#define X first
#define Y second
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int area[101][101];
bool vis[101][101];
int ans[10001];
int cnt;
queue<pair<int, int>> Q;
int dx[4]{ 0,1,0,-1 };
int dy[4]{ 1,0,-1,0 };

void init() {
	for (int i{}; i < 101; i++) {
		for (int j{}; j < 101; j++) {
			vis[i][j] = false;
		}
	}
}
void bfs(int height) {
	while (!Q.empty()) {
		int curX{ Q.front().X };
		int curY{ Q.front().Y };
		Q.pop();
		for (int i{}; i < 4; i++) {
			int nX{ curX + dx[i] };
			int nY{ curY + dy[i] };
			if (nX < 0 || nY < 0 || nX >= N || nY >= N) continue;
			if (vis[nX][nY]) continue;
			if (area[nX][nY] < height) continue;
			vis[nX][nY] = true;
			Q.push({ nX,nY });
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for (int i{}; i < N; i++) {
		for (int j{}; j < N; j++) {
			cin >> area[i][j];
		}
	}
	for (int i{}; i < 101; i++) {
		init();
		for (int j{}; j < N; j++) {
			for (int k{}; k < N; k++) {
				if (area[j][k] < i) continue;
				if (vis[j][k]) continue;
				Q.push({ j,k });
				bfs(i);
				ans[cnt]++;
			}
		}
		//cout << ans[cnt] << "\n";
		cnt++;
	}
	cout << *max_element(ans, ans + cnt);
	return 0;
}