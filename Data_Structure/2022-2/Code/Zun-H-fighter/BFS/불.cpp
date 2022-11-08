//#include <iostream>
//#include <queue>
//#include <string>
//#include <algorithm>
//#include <utility>
//using namespace std;
//
//int dx[4] = { 0,1,0,-1 };
//int dy[4] = { 1,0,-1,0 };
//string map[1000];
//int dist1[1000][1000];
//int dist2[1000][1000];
//
//int main() {
//	queue<pair<int, int>> q1;
//	queue<pair<int, int>> q2;
//	int T, w, h;
//	bool cant_E;
//	cin >> T;
//	while (T--) {
//		cant_E = true;
//		cin >> w >> h;
//		for (int i = 0; i < h; i++) {
//			cin >> map[i];
//			fill(dist1[i], dist1[i] + w, -1);
//			fill(dist2[i], dist2[i] + w, -1);
//		}
//		for (int i = 0; i < h; i++) {
//			for (int j = 0; j < w; j++) {
//				if (map[i][j] == '*') { q1.push({ i,j }); dist1[i][j] = 0; }
//				if (map[i][j] == '@') { q2.push({ i,j }); dist2[i][j] = 0; }
//			}
//		}
//		while (!q1.empty()) {
//			auto cur = q1.front(); q1.pop();
//			for (int dir = 0; dir < 4; dir++) {
//				int nx = cur.first + dx[dir];
//				int ny = cur.second + dy[dir];
//				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
//				if (dist1[nx][ny] >= 0 || map[nx][ny] == '#') continue;
//				dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
//				q1.push({ nx,ny });
//			}
//		}
//		while (!q2.empty()) {
//			auto cur = q2.front(); q2.pop();
//			for (int dir = 0; dir < 4; dir++) {
//				int nx = cur.first + dx[dir];
//				int ny = cur.second + dy[dir];
//				if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
//					cout << dist2[cur.first][cur.second] + 1<<"\n";
//					while (!q2.empty()) q2.pop();
//					cant_E = false;
//					break;
//				}
//				if (dist2[nx][ny] >= 0 || map[nx][ny] == '#') continue;
//				if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.first][cur.second] + 1) continue;
//				dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
//				q2.push({ nx,ny });
//			}
//		}
//		if(cant_E==true)	cout << "IMPOSSIBLE\n";
//	}
//	return 0;
//}