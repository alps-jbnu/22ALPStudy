//#include <iostream>
//#include <queue>
//#include <utility>
//#include <algorithm>
//#include <tuple>
//using namespace std;
//
//int dx[6] = { 1,0,0,-1,0,0 };
//int dy[6] = { 0,1,0,0,-1,0 };
//int dz[6] = { 0,0,1,0,0,-1 };
//int stog[100][100][100];
//int dist[100][100][100];
//
//int main() {
//	queue<tuple<int, int, int>> q;
//	int m, n, h, x, y, z, ans=0;
//
//	cin >> m >> n >> h;
//	for (int i = 0; i < h; i++)
//		for (int j = 0; j < n; j++)
//			for (int k = 0; k < m; k++){ 
//				cin >> stog[i][j][k];
//				if (stog[i][j][k] == 1) q.push(make_tuple(i,j,k));
//				else if(stog[i][j][k] == 0) dist[i][j][k] = -1;
//			}
//	while (!q.empty()) {
//		auto cur = q.front(); q.pop();
//		tie(x, y, z) = cur;
//		for (int dir = 0; dir < 6; dir++) {
//			int nx = get<0>(cur) + dx[dir];
//			int ny = get<1>(cur) + dy[dir];
//			int nz = get<2>(cur) + dz[dir];
//			if (nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m)
//				continue;
//			if (dist[nx][ny][nz] >= 0) continue;
//			dist[nx][ny][nz] = dist[x][y][z] + 1;
//			q.push(make_tuple(nx, ny, nz));
//		}
//	}
//	for (int i = 0; i < h; i++) {
//		for (int j = 0; j < n; j++) {
//			for (int k = 0; k < m; k++) {
//				if (dist[i][j][k] == -1) {
//					cout << -1;
//					return 0;
//				}
//				ans = max(ans, dist[i][j][k]);
//			}
//		}
//	}
//	cout << ans;
//	return 0;
//}