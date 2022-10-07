//#include <iostream>
//#include <queue>
//#include <utility>
//#include <algorithm>
//using namespace std;
//
//int dx[8] = { 2, 1, -1, -2,-2, -1, 1, 2 };
//int dy[8] = { 1, 2, 2 , 1, -1, -2, -2,-1 };
//int dist[300][300];
//
//int main() {
//	queue<pair<int, int>> q;
//	int T, I, x, y, x_goal, y_goal, ans;
//	cin >> T;
//	for (int test_c = 0; test_c < T; test_c++) {
//		cin >> I >> x >> y >> x_goal >> y_goal;
//		for (int i = 0; i < I; i++) {
//			fill(dist[i], dist[i] + I, -1);
//		}
//		dist[x][y] = 0;
//		q.push({ x,y });
//		while (!q.empty()) {
//			pair<int, int> cur = q.front(); q.pop();
//			for (int dir = 0; dir < 8; dir++) {
//				int nx = cur.first + dx[dir];
//				int ny = cur.second + dy[dir];
//				if (nx < 0 || nx >= I || ny < 0 || ny >= I) continue;
//				if (dist[nx][ny] >= 0) continue;
//				dist[nx][ny] = dist[cur.first][cur.second] + 1;
//				q.push({ nx,ny });
//			}
//		}
//		cout << dist[x_goal][y_goal]<<"\n";
//	}
//	return 0;
//}