#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[105][105];
bool vis[105][105];
int counth; // 사각형 갯수
int area[105]; // 나누어진 사각형 넓이

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        for (int i = b; i <= d-1; i++) {
            for (int j = a; j <= c-1; j++) {
                board[i][j] = 1;
            }
        }
    }

    queue<pair<int, int>>q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] || board[i][j] != 0) continue;
            // 시작점 설정
            
            counth++;
            vis[i][j] = 1;
            q.push({ i,j });
            while (!q.empty()) {
                area[counth]++;
                auto cur = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] || board[nx][ny] == 1) continue;

                    vis[nx][ny] = 1;
                    q.push({ nx, ny });
                }
            }
        }
    }

    sort(area, area + counth + 1);
    cout << counth << "\n";
    for (int i = 1; i <= counth; i++) {
        cout << area[i] << " ";
    }
    return 0;
}