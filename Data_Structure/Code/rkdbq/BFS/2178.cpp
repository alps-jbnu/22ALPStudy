#include <iostream>
#include <queue>
using namespace std;

bool maze[101][101];
bool vis[101][101];
int dx[4]{ 1,0,-1,0 };
int dy[4]{ 0,1,0,-1 };
int moveCnt[101][101];

void bfs(int N, int M) {
	queue<pair<int, int>> Q;
	Q.push({ 0, 0 });
	vis[0][0] = true;
	moveCnt[0][0] = 1;
	//cout << "0 0 visited\n";
	while (!Q.empty()) {
		int forCnt{};
		int curX{ Q.front().first };
		int curY{ Q.front().second };
		Q.pop();
		for (int i{}; i < 4; i++) {
			int nX{ curX + dx[i] };
			int nY{ curY + dy[i] };
			if (nX < 0 || nY < 0 || nX >= N || nY >= M) continue;
			if (vis[nX][nY] || maze[nX][nY] == false) continue;
			vis[nX][nY] = true;
			moveCnt[nX][nY] = moveCnt[curX][curY] + 1;
			//cout << nX << " " << nY << " visited\n";
			forCnt++;
			Q.push({ nX, nY });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M;
	cin >> N >> M;
	string input;
	for (int i{}; i < N; i++) {
		cin >> input;
		for (int j{}; j < M; j++) {
			maze[i][j] = input[j] - '0';
		}
	}
	bfs(N, M);
	cout << moveCnt[N-1][M-1];
	return 0;
}