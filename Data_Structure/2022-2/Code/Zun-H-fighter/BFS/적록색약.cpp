//#include <iostream>
//#include <queue>
//#include <utility>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int dx[4] = { 0,1,0,-1 };
//int dy[4] = { 1,0,-1,0 };
//int bound[100][100];
//
//int main() {
//	queue<pair<int, int>> q;
//	string board[100];
//	int n, ans=0, ans2=0;
//
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		 cin >> board[i];
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (!bound[i][j]) {
//				ans++;
//				q.push({ i,j });
//				if (board[i][j] == 'R') bound[i][j] = 1;
//				else if (board[i][j] == 'G') bound[i][j] = 2;
//				else if (board[i][j] == 'B') bound[i][j] = 3;
//				while (!q.empty()) {
//					pair<int, int> cur = q.front(); q.pop();
//					for (int dir = 0; dir < 4; dir++) {
//						int nx = cur.first + dx[dir];
//						int ny = cur.second + dy[dir];
//						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
//						if (bound[nx][ny]) continue;
//						if (board[nx][ny] == board[cur.first][cur.second]) {
//							bound[nx][ny] = bound[cur.first][cur.second];
//							q.push({ nx,ny });
//						}
//					}
//				}
//			}
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		fill(bound[i], bound[i] + n, 0);
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (!bound[i][j]) {
//				ans2++;
//				q.push({ i,j });
//				if (board[i][j] == 'R' || board[i][j] == 'G') bound[i][j] = 1;
//				else if (board[i][j] == 'B') bound[i][j] = 3;
//				while (!q.empty()) {
//					pair<int, int> cur = q.front(); q.pop();
//					for (int dir = 0; dir < 4; dir++) {
//						int nx = cur.first + dx[dir];
//						int ny = cur.second + dy[dir];
//						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
//						if (bound[nx][ny]) continue;
//						if (board[nx][ny] == 'B' && board[cur.first][cur.second]=='B') {
//							bound[nx][ny] = bound[cur.first][cur.second];
//							q.push({ nx,ny });
//						}
//						else if ((board[nx][ny] == 'R' || board[nx][ny] == 'G') && (board[cur.first][cur.second] == 'R' || board[cur.first][cur.second] == 'G')) {
//							bound[nx][ny] = bound[cur.first][cur.second];
//							q.push({ nx,ny });
//						}
//					}
//				}
//			}
//		}
//	}
//	cout << ans << " " << ans2;
//	return 0;
//	}