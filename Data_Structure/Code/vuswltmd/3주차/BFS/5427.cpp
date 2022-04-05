#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iterator>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
using namespace std;
#define X first
#define Y second
int TC, bX, bY;
int board[1002][1002];
int visF[1002][1002];
int visS[1002][1002];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC;
    for (int testNo = 0; testNo < TC; testNo++) {
        bool escape = false;
        queue<pair<int, int>> Qf = {}, Qs = {};
        cin >> bY >> bX;
        for (int i = 0; i < bX; i++) {
            fill(visF[i], visF[i] + bY, 0);
            fill(visS[i], visS[i] + bY, 0);
        }
        for (int i = 0; i < bX; i++)
            for (int j = 0; j < bY; j++) {
                char c;
                cin >> c;
                if (c == '#') board[i][j] = -1;
                else {
                    if (c == '@') {
                        Qs.push({ i, j });
                        visS[i][j] = 1;
                    }
                    else if (c == '*') {
                        Qf.push({ i, j });
                        visF[i][j] = 1;
                    }
                    board[i][j] = 0;
                }
            }
        while (!Qf.empty()) {
            auto v = Qf.front();
            Qf.pop();
            for (int k = 0; k < 4; k++) {
                int nx = v.X + dx[k];
                int ny = v.Y + dy[k];
                if (nx < 0 || bX <= nx || ny < 0 || bY <= ny) continue;
                if (board[nx][ny] == -1) continue;
                if (visF[nx][ny]) continue;
                visF[nx][ny] = visF[v.X][v.Y] + 1;
                Qf.push({ nx, ny });
            }
        }
        while ((!Qs.empty()) && (!escape)) {
            auto v = Qs.front();
            Qs.pop();
            for (int k = 0; k < 4; k++) {
                int nx = v.X + dx[k];
                int ny = v.Y + dy[k];
                if (nx < 0 || bX <= nx || ny < 0 || bY <= ny) {
                    cout << visS[v.X][v.Y] << '\n';
                    escape = true;
                    break;
                }
                if (board[nx][ny] == -1) continue;
                if (visS[nx][ny]) continue;
                if (visF[nx][ny] != 0 && visF[nx][ny] <= visS[v.X][v.Y] + 1) continue;
                visS[nx][ny] = visS[v.X][v.Y] + 1;
                Qs.push({ nx, ny });
            }
        }
        if (!escape) cout << "IMPOSSIBLE" << '\n';
    }
}

//#include <iostream>
//#include <string>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//#include <vector>
//#include <iterator>
//#include <list>
//#include <deque>
//#include <queue>
//#include <stack>
//#include <utility>
//using namespace std;
//#define X first
//#define Y second
//char board[1002][1002];
//int visj[1002][1002];
//int visf[1002][1002];
//
//int dx[4] = {1, 0, -1, 0};
//int dy[4] = {0, 1,  0, -1};
//
//int t;
//
//int m, n;
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> t;
//
//	queue<pair<int, int>> Qf;
//	queue < pair<int, int>> Qj;
//
//	while (t--)
//	{
//		cin >> m >> n;
//
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < m; j++)
//			{
//					visf[i][j] = 0;
//					visj[i][j] = 0;
//			}
//		}
//
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < m; j++)
//			{
//				cin >> board[i][j];
//				
//				if (board[i][j] == '*')
//				{
//					Qf.push({ i, j });
//					visf[i][j] = 1;
//				}
//				if (board[i][j] == '@')
//				{
//					Qj.push({ i, j });
//					visj[i][j] = 1;
//				}		
//			}
//		}
//
//		while (!Qf.empty())
//		{
//			auto cur = Qf.front(); Qf.pop();
//
//			for (int dir = 0; dir < 4; dir++)
//			{
//				int nx = cur.X + dx[dir];
//				int ny = cur.Y + dy[dir];
//
//				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
//				if (visf[nx][ny] || board[nx][ny] == '#') continue;
//
//				visf[nx][ny] = visf[cur.X][cur.Y] + 1;
//				Qf.push({ nx, ny });
//			}
//		}
//
//		bool js = false;
//
//		while (!Qj.empty() && (!js))
//		{
//			auto cur = Qj.front(); Qj.pop();
//
//			for (int dir = 0; dir < 4; dir++)
//			{
//				int nx = cur.X + dx[dir];
//				int ny = cur.Y + dy[dir];
//
//				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
//				{
//					js = true;
//					cout << visj[cur.X][cur.Y] << "\n";
//					break;
//				}
//				if (visj[nx][ny] || board[nx][ny] == '#') continue;
//				if (visf[nx][ny] != 0 && visf[nx][ny] <= visj[cur.X][cur.Y] + 1)continue;
//
//				visj[nx][ny] = visj[cur.X][cur.Y] + 1;
//				Qj.push({ nx, ny });
//			}
//		}
//
//		if (!js)
//		{
//			cout << "IMPOSSIBLE" << "\n";
//		}
//	}
//
//}