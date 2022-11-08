//#include <iostream>
//#include <queue>
//#define X first
//#define Y second
//
//int board[301][301];
//int dx[8] = { 2, 1, 1, 2, -1, -2, -2, -1 };
//int dy[8] = { 1, 2, -2, -1, 2, 1, -1, -2 };
//
//int main(void) {
//	std::ios_base::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	int test, length;
//	int x1, y1, x2, y2;
//	std::cin >> test;
//	
//	while (test--) {
//		std::queue<std::pair<int, int> > q;
//		int dist[301][301] = { 0, };
//		std::cin >> length;
//		std::cin >> x1 >> y1;
//		q.push({ x1, y1});
//		std::cin >> x2 >> y2;
//		if (x1 == x2 && y1 == y2) {
//			std::cout << 0 << '\n';
//			continue;
//		}
//		while (!q.empty()) {
//			std::pair<int, int> cur = q.front(); q.pop();
//			for (int dir = 0; dir < 8; dir++) {
//				int nx = cur.X + dx[dir];
//				int ny = cur.Y + dy[dir];
//				if (nx >= length || nx < 0 || ny >= length || ny < 0)
//					continue;
//				if (dist[nx][ny] > 0)
//					continue;
//				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
//				if (nx == x2 && ny == y2) {
//					std::cout << dist[nx][ny] << '\n';
//					for (int i = 0; i < q.size(); i++)
//						q.pop();
//					break;
//				}
//				q.push({ nx, ny });		
//			}
//		}
//	}
//}