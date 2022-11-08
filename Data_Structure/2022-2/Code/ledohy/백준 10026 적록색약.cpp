//#include <iostream>
//#include <queue>
//#define X first
//#define Y second
//
//char board[101][101] = { NULL };
//int dx[4] = { 1, 0, -1, 0 };
//int dy[4] = { 0, 1, 0, -1 };
//
//int main(void) {
//	std::ios_base::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	int n;
//	char c;
//
//	std::cin >> n;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			std::cin >> c;
//			board[i][j] = c;
//		}
//	}
//
//	for (int k = 0; k < 2; k++) {
//
//		std::queue<std::pair<int, int>> q;
//		bool vis[101][101] = { 0 };
//		int area = 0;
//		if (k == 1) {
//			for (int i = 0; i < n; i++) {
//				for (int j = 0; j < n; j++) {
//					if (board[i][j] == 'G')
//						board[i][j] = 'R';
//				}
//			}
//		}
//
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				if (!vis[i][j]) {
//					vis[i][j] = 1;
//					q.push({ i, j });
//					while (!q.empty()) {
//						std::pair<int, int> cur = q.front(); q.pop();
//						for (int dir = 0; dir < 4; dir++) {
//							int nx = cur.X + dx[dir];
//							int ny = cur.Y + dy[dir];
//							if (nx < 0 || nx >= n || ny < 0 || ny >= n)
//								continue;
//							if (vis[nx][ny] || board[i][j] != board[nx][ny])
//								continue;
//							vis[nx][ny] = 1;
//							q.push({ nx, ny });
//						}
//					}
//					area++;
//				}
//			}
//		}
//		std::cout << area << ' ';
//	}
//}