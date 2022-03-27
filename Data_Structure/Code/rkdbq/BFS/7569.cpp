#include <iostream>
#include <queue>
using namespace std;

int H, N, M;
int tomato[101][101][101];
bool vis[101][101][101];
int dx[6]{ 1,-1,0,0,0,0 };
int dy[6]{ 0,0,1,-1,0,0 };
int dz[6]{ 0,0,0,0,1,-1 };
queue <pair<int, pair<int, int>>> Q; //x, (y, z)
int cnt[101][101][101];
int ans;

void bfs() {
	while (!Q.empty()) {
		int curX{ Q.front().first };
		int curY{ Q.front().second.first };
		int curZ{ Q.front().second.second };
		Q.pop();
		for (int i{}; i < 6; i++) {
			int nX{ curX + dx[i] };
			int nY{ curY + dy[i] };
			int nZ{ curZ + dz[i] };
			if (nX < 0 || nY < 0 || nZ < 0 || nX >= H || nY >= N || nZ >= M) continue;
			if (vis[nX][nY][nZ]) continue;
			if (tomato[nX][nY][nZ] != 0) continue;
			vis[nX][nY][nZ] = true;
			cout << nX << " " << nY << " " << nZ << " is visited\n";
			Q.push({ nX,{nY,nZ} });
			cnt[nX][nY][nZ] = cnt[curX][curY][curZ] + 1;
			cout << nX << nY << nZ << " need " << cnt[nX][nY][nZ] << "days\n";
		}
	}
}
int check() {
	for (int i{}; i < H; i++) {
		for (int j{}; j < N; j++) {
			for (int k{}; k < M; k++) {
				if (vis[i][j][k] == false && tomato[i][j][k] == 0) return -1;
				ans = max(ans, cnt[i][j][k]);
				
			}
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> N >> H;
	for (int i{}; i < H; i++) {
		for (int j{}; j < N; j++) {
			for (int k{}; k < M; k++) {
				cin >> tomato[i][j][k];
			}
		}
	}
	for (int i{}; i < H; i++) {
		for (int j{}; j < N; j++) {
			for (int k{}; k < M; k++) {
				if (vis[i][j][k]) continue;
				if (tomato[i][j][k] == 1) {
					Q.push({ i,{j,k} });
				}
			}
		}
	}
	bfs();
	cout << check();
	return 0;
}