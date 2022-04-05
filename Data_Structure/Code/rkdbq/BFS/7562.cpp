#include <iostream>
#include <queue>
using namespace std;

int T;
int I;
pair<int, int> curPos, ansPos;
//bool chessboard[301][301];
bool vis[301][301];
int visCnt[301][301];
int dx[8]{ -2,-1,1,2,-2,-1,1,2 };
int dy[8]{ 1,2,-2,-1,-1,-2,2,1 };
queue<pair<int, int>> Q;

void initialize() {
	for (int i{}; i < 301; i++) {
		for (int j{}; j < 301; j++) {
			vis[i][j] = visCnt[i][j] = 0;
		}
	}
	while (!Q.empty()) Q.pop();
}
void bfs() {
	while (!Q.empty()) {
		int curX{ Q.front().first };
		int curY{ Q.front().second };
		Q.pop();
		for (int i{}; i < 8; i++) {
			int nX{ curX + dx[i] };
			int nY{ curY + dy[i] };
			if (nX < 0 || nY < 0 || nX >= I || nY >= I) continue;
			if (vis[nX][nY]) continue;
			vis[nX][nY] = true;
			//cout << nX << ", " << nY << " is visited\n";
			visCnt[nX][nY] = visCnt[curX][curY] + 1;
			//cout << visCnt[nX][nY] << " moves\n";
			Q.push({ nX, nY });
			if (vis[ansPos.first][ansPos.second]) return;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	for (int i{}; i < T; i++) {
		initialize();
		cin >> I;
		cin >> curPos.first >> curPos.second;
		Q.push({ curPos.first, curPos.second });
		vis[curPos.first][curPos.second] = true;
		cin >> ansPos.first >> ansPos.second;
		bfs();
		cout << visCnt[ansPos.first][ansPos.second] << "\n";
	}	
	return 0;
}