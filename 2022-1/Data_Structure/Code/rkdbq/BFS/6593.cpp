#define X first
#define Y second.first
#define Z second.second
#include <iostream>
#include <queue>
using namespace std;

int L, R, C;
pair<int, pair<int, int>> S, E;
int dx[6]{ 1,0,0,-1,0,0 };
int dy[6]{ 0,1,0,0,-1,0 };
int dz[6]{ 0,0,1,0,0,-1 };
char building[31][31][31];
bool vis[31][31][31];
int cnt[31][31][31];
int ans;
queue<pair<int, pair<int, int>>> Q;

void init() {
	for (int i{}; i < 31; i++) {
		for (int j{}; j < 31; j++) {
			for (int k{}; k < 31; k++) {
				building[i][j][k] = 0;
				vis[i][j][k] = false;
				cnt[i][j][k] = 0;
			}
		}
	}
}
void bfs() {
	while (!Q.empty()) {
		int curX{ Q.front().X };
		int curY{ Q.front().Y };
		int curZ{ Q.front().Z };
		Q.pop();
		for (int i{}; i < 6; i++) {
			int nX{ curX + dx[i] };
			int nY{ curY + dy[i] };
			int nZ{ curZ + dz[i] };
			if (nX < 0 || nY < 0 || nZ < 0 || nX >= L || nY >= R || nZ >= C) continue;
			if (building[nX][nY][nZ] == '#') continue;
			if (vis[nX][nY][nZ]) continue;
			vis[nX][nY][nZ] = true;
			cnt[nX][nY][nZ] = cnt[curX][curY][curZ] + 1;
			Q.push({ nX, {nY, nZ} });
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (true) {
		init();
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;
		for (int i{}; i < L; i++) {
			for (int j{}; j < R; j++) {
				for (int k{}; k < C; k++) {
					cin >> building[i][j][k];
					if (building[i][j][k] == 'S') S.X = i, S.Y = j, S.Z = k;
					if (building[i][j][k] == 'E') E.X = i, E.Y = j, E.Z = k;
				}
			}
		}
		vis[S.X][S.Y][S.Z] = true;
		Q.push({ S.X, {S.Y, S.Z} });
		bfs();
		ans = cnt[E.X][E.Y][E.Z];
		if (ans == 0) cout << "Trapped!\n";
		else cout << "Escaped in " << ans << " minute(s).\n";
	}
	return 0;
}