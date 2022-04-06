#include <iostream>
#include <queue>
using namespace std;

//'.': 빈 공간
//'#' : 벽
//'@' : 상근이의 시작 위치
//'*' : 불

const int MAX = 1000001;

int T;
char maze[1001][1001];
bool visJ[1001][1001];
int visJCnt[1001][1001];
bool visF[1001][1001];
int visFCnt[1001][1001]; //2MB, 공간복잡도 여유 있음
int dx[4]{ 1,0,-1,0 };
int dy[4]{ 0,1,0,-1 };
int h, w;
queue<pair<int, int>> jMove;
queue<pair<int, int>> fMove;

void initialize() {
	for (int i{}; i < 1001; i++) {
		for (int j{}; j < 1001; j++) {
			maze[i][j] = 0;
			visJ[i][j] = 0;
			visJCnt[i][j] = 0;
			visF[i][j] = 0;
			visFCnt[i][j] = 0;
		}
	}
}
void movementOfJ() {
	while (!jMove.empty()) {
		int curX{ jMove.front().first };
		int curY{ jMove.front().second };
		jMove.pop();
		for (int i{}; i < 4; i++) {
			int nX{ curX + dx[i] };
			int nY{ curY + dy[i] };
			if (nX < 0 || nY < 0 || nX >= h || nY >= w) continue;
			if (maze[nX][nY] == '#' || maze[nX][nY] == '*') continue;
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
			if (nX < 0 || nY < 0 || nX >= h || nY >= w) continue;
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
	for (int i{}; i < h; i++) {
		for (int j{}; j < w; j++) {
			if ((i > 0 && i < h - 1) && (j > 0 && j < w - 1)) continue;
			if (maze[i][j] == '#' || maze[i][j] == '*') continue;
			if (visJCnt[i][j] < visFCnt[i][j])	ans = min(ans, visJCnt[i][j]);
		}
	}
	if (ans == MAX) cout << "IMPOSSIBLE\n";
	else cout << ans + 1 << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	for (int i{}; i < T; i++) {
		initialize();
		cin >> w >> h;
		for (int i{}; i < h; i++) {
			for (int j{}; j < w; j++) {
				visJCnt[i][j] = visFCnt[i][j] = MAX;
				cin >> maze[i][j];
				if (maze[i][j] == '@') jMove.push({ i,j }), visJ[i][j] = true, visJCnt[i][j] = 0;
				else if (maze[i][j] == '*') fMove.push({ i,j }), visF[i][j] = true, visFCnt[i][j] = 0;
			}
		}
		movementOfJ();
		movementOfF();
		exitCheck();
	}
	return 0;
}