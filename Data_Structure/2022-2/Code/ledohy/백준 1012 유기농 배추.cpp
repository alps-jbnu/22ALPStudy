//#include <iostream>
//#include <queue>
//#define X first
//#define Y second
//
//int dx[4] = { 1, 0, -1, 0 };
//int dy[4] = { 0, 1, 0, -1 };
//
//int main(void) {
//	std::ios_base::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	int test;
//	std::cin >> test;
//	while (test--) {
//		std::queue<std::pair<int, int>> q;
//		int m, n, cabbage, earthworm = 0;
//		int x, y;
//		int board[51][51] = { 0, };
//		bool vis[51][51] = { false };
//
//		std::cin >> m >> n >> cabbage;
//		for (int i = 0; i < cabbage; i++) {
//			std::cin >> x >> y;
//			board[y][x]++;
//		}
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				if (board[i][j] == 1 && !vis[i][j]) {
//					vis[i][j] = 1;
//					q.push({ i, j });
//					while (!q.empty()) {
//						std::pair<int, int> cur = q.front(); q.pop();
//						for (int dir = 0; dir < 4; dir++) {
//							int nx = cur.X + dx[dir];
//							int ny = cur.Y + dy[dir];
//							if (nx < 0 || nx >= n || ny < 0 || ny >= m)
//								continue;
//							if (vis[nx][ny] || board[nx][ny] != 1)
//								continue;
//							vis[nx][ny] = 1;
//							q.push({ nx, ny });
//						}
//					}
//					earthworm++;
//				}
//			}
//		}
//		
//		std::cout << earthworm << '\n';
//	}
//}