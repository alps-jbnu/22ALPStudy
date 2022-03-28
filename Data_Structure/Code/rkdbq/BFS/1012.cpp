#include <iostream>
#include <queue>
using namespace std;

int N, M;
int K;
int wormCnt;
int dx[4]{ 0, 1, 0, -1 };
int dy[4]{ 1, 0, -1, 0 };
bool field[51][51];
bool vis[51][51];
queue<pair<int, int>> Q;

void initialize() { //Testcase 별 초기화 필요
	wormCnt = 0;
	for (int i{}; i < 51; i++) {
		for (int j{}; j < 51; j++) {
			field[i][j] = false;
			vis[i][j] = false;
		}
	}
}
void bfs() {
	while (!Q.empty()) {
		int curX{ Q.front().first };
		int curY{ Q.front().second };
		Q.pop();
		for (int i{}; i < 4; i++) {
			int nX{ curX + dx[i] };
			int nY{ curY + dy[i] };
			if (nX < 0 || nY < 0 || nX >= N || nY >= M) continue;
			if (field[nX][nY] == false || vis[nX][nY])continue;
			vis[nX][nY] = true;
			//cout << nX << " " << nY << " is visited\n";
			Q.push({ nX, nY });
		}
		//cout << "wormCnt++\n";
	}
	wormCnt++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T{};
	cin >> T;
	for (int j{}; j < T; j++) {
		initialize();
		cin >> M >> N;
		cin >> K;
		for (int i{}; i < K; i++) {
			int pos[2]{};
			cin >> pos[0] >> pos[1];
			field[pos[1]][pos[0]] = true;
		}
		for (int i{}; i < N; i++) {
			for (int j{}; j < M; j++) {
				if (field[i][j] == false || vis[i][j]) continue;
				Q.push({ i, j });
				bfs();
			}
		}
		cout << wormCnt <<"\n";
	}
	return 0;
}