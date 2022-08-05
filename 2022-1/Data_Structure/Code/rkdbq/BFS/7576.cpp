#include <iostream>
#include <queue>
using namespace std;

int wareHouse[1001][1001];
bool vis[1001][1001];
int visCnt[1001][1001];
int dx[4]{ 1,0,-1,0 };
int dy[4]{ 0,-1,0,1 };
int N, M;
queue<pair<int, int>> Q;

void bfs() {
	while (!Q.empty()) {
		int curX{ Q.front().first };
		int curY{ Q.front().second };
		Q.pop();
		for (int i{}; i < 4; i++) {
			int nX{ curX + dx[i] };
			int nY{ curY + dy[i] };
			if (nX < 0 || nY < 0 || nX >= M || nY >= N) continue;
			if (vis[nX][nY]) continue;
			if (wareHouse[nX][nY] == -1 || wareHouse[nX][nY] == 1) continue;
			vis[nX][nY] = true;
			visCnt[nX][nY] = visCnt[curX][curY] + 1;
			//cout << nX << " " << nY << " is visited, " << visCnt[nX][nY] << " day(s)\n";
			Q.push({ nX,nY });
		}
	}
}
int allVisCheck() {
	int day{};
	for (int i{}; i < M; i++) {
		for (int j{}; j < N; j++) {
			if (wareHouse[i][j]== 0 && vis[i][j] == false) return -1;
			day = max(day, visCnt[i][j]);
		}
	}
	return day;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i{}; i < M; i++) {
		for (int j{}; j < N; j++) {
			cin >>  wareHouse[i][j];
			if (wareHouse[i][j] == 1) {
				Q.push({ i,j });
				vis[i][j] = true;
			}
		}
	}
	bfs();
	cout << allVisCheck();
}