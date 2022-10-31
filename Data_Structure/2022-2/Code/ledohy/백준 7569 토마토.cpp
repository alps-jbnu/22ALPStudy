//#include <iostream>
//#include <queue>
//#define X first
//#define Y second
//
//int board[101][101][101];
//int day[101][101][101];
//int dx[6] = { 0, 0, 0, 0, 1, -1 };
//int dy[6] = { 0, 0, 1, -1, 0, 0 };
//int dz[6] = { 1, -1, 0, 0, 0, 0 };
//std::queue<std::pair<std::pair<int, int>, int> > q;
//
//int main(void) {
//	std::ios_base::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	int m, n, h;
//	int max = 0, zero_flag = 0;
//	std::cin >> m >> n >> h;
//	for (int i = 0; i < h; i++) {
//		for (int j = 0; j < n; j++) {
//			for (int k = 0; k < m; k++) {
//				std::cin >> board[j][k][i];
//				if (board[j][k][i] == 1)
//					q.push({ { j, k }, i });
//				else if (board[j][k][i] == 0) {
//					day[j][k][i] = -1;
//					zero_flag = 1;
//				}
//			}
//		}
//	}
//	if (!zero_flag) {
//		std::cout << 0;
//		return 0;
//	}
//
//	while (!q.empty()) {
//		std::pair<std::pair<int, int>, int > cur = q.front(); q.pop();
//		for (int dir = 0; dir < 6; dir++) {
//			int nx = cur.X.X + dx[dir];
//			int ny = cur.X.Y + dy[dir];
//			int nz = cur.Y + dz[dir];
//			if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h)
//				continue;
//			if (day[nx][ny][nz] >= 0)
//				continue;
//			day[nx][ny][nz] = day[cur.X.X][cur.X.Y][cur.Y] + 1;
//			q.push({ {nx, ny }, nz });
//		}
//	}
//	for (int i = 0; i < h; i++) {
//		for (int j = 0; j < n; j++) {
//			for (int k = 0; k < m; k++) {
//				if (day[j][k][i] == -1) {
//					std::cout << -1;
//					return 0;
//				}
//				if (day[j][k][i] > max)
//					max = day[j][k][i];
//			}
//		}
//	}
//	std::cout << max;
//}