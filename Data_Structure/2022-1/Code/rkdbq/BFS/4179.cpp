#include <iostream>
#include <queue>
using namespace std;

//#: 벽
//. : 지나갈 수 있는 공간
//J : 지훈이의 미로에서의 초기위치(지나갈 수 있는 공간)
//F : 불이 난 공간

const int MAX = 1000001;

char maze[1001][1001];
bool visJ[1001][1001];
int visJCnt[1001][1001];
bool visF[1001][1001];
int visFCnt[1001][1001]; //2MB, 공간복잡도 여유 있음
int dx[4]{ 1,0,-1,0 };
int dy[4]{ 0,1,0,-1 };
int R, C;
queue<pair<int, int>> jMove;
queue<pair<int, int>> fMove;

void movementOfJ() {
	while (!jMove.empty()) {
		int curX{ jMove.front().first };
		int curY{ jMove.front().second };
		jMove.pop();
		for (int i{}; i < 4; i++) {
			int nX{ curX + dx[i] };
			int nY{ curY + dy[i] };
			if (nX < 0 || nY < 0 || nX >= R || nY >= C) continue;
			if (maze[nX][nY] == '#' || maze[nX][nY] == 'F') continue;
			if (visJ[nX][nY]) continue;
			visJ[nX][nY] = true;
			visJCnt[nX][nY] = visJCnt[curX][curY] + 1;
			//cout << "J " << nX << " " << nY << " visited, " << visJCnt[nX][nY] << " moved\n";
			jMove.push({ nX,nY });
		}
	}
}
void movementOfF() {
	while (!fMove.empty()) {
		int curX{ fMove.front().first };
		int curY{ fMove.front().second };
		fMove.pop();
		for (int i{}; i < 4; i++) {
			int nX{ curX + dx[i] };
			int nY{ curY + dy[i] };
			if (nX < 0 || nY < 0 || nX >= R || nY >= C) continue;
			if (maze[nX][nY] == '#') continue;
			if (visF[nX][nY]) continue;
			visF[nX][nY] = true;
			visFCnt[nX][nY] = visFCnt[curX][curY] + 1;
			//cout << "F " << nX << " " << nY << " visited, " << visFCnt[nX][nY] << " moved\n";
			fMove.push({ nX,nY });
		}
	}
}
void exitCheck() {
	int ans{ MAX };
	for (int i{}; i < R; i++) {
		for (int j{}; j < C; j++) {
			if ((i > 0 && i < R - 1) && (j > 0 && j < C - 1)) continue;
			if (maze[i][j] == '#' || maze[i][j] == 'F') continue;
			if (visJCnt[i][j] < visFCnt[i][j])	ans = min(ans, visJCnt[i][j]);
		}
	}
	if (ans == MAX) cout << "IMPOSSIBLE";
	else cout << ans + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> R >> C;
	for (int i{}; i < R; i++) {
		for (int j{}; j < C; j++) {
			visJCnt[i][j] = visFCnt[i][j] = MAX; //J, F가 갇혀 있을 때
			cin >> maze[i][j];
			if (maze[i][j] == 'J') jMove.push({ i,j }), visJ[i][j] = true, visJCnt[i][j] = 0;
			else if (maze[i][j] == 'F') fMove.push({ i,j }), visF[i][j] = true, visFCnt[i][j] = 0;
		}
	}
	movementOfJ();
	movementOfF();
	exitCheck();
	return 0;
}