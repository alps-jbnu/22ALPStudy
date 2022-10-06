//#include <iostream>
//#include <queue>
//#include <utility>
//#include <algorithm>
//#define x first
//#define y second
//#define max1 50
//using namespace std;
//
//int board[max1][max1];
//int dx[4] = { 0,1,0,-1 };
//int dy[4] = { 1,0,-1,0 };
//int main() {
//    queue<pair<int, int>> q;
//    int m, n, k, T, a, b, ans;
//    cin >> T;
//    for (int i = 0; i < T; i++) {
//        for (int j = 0; j < n; j++) {
//            fill(board[j], board[j] + m, 0);
//        }
//        ans = 0;
//        cin >> m >> n >> k;
//        for (int j = 0; j < k; j++) {
//            cin >> a >> b;
//            board[b][a] = 1;
//        }
//        for (int i1=0; i1 < n; i1++) {
//            for (int j1=0; j1 < m; j1++) {
//                if (board[i1][j1])
//                {
//                    q.push({i1, j1});
//                    while (!q.empty()) {
//                        pair<int, int> cur = q.front(); q.pop();
//                        for (int dir = 0; dir < 4; dir++) {
//                            int nx = cur.x + dx[dir]; int ny = cur.y + dy[dir];
//                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
//                            if (board[nx][ny]) {
//                                q.push({ nx, ny });
//                                board[nx][ny] = 0;
//                            }
//                        }
//                    }
//                    ans++;
//                }
//            }
//        }
//        cout << ans <<"\n";
//    }
//    return 0;
//}
