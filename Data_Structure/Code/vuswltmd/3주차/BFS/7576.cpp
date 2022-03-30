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
int board[1002][1002];
int vis[1002][1002];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1,  0, -1};

int n, m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	

	cin >> m >> n; //n세로, m가로

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{						
			vis[i][j] = -1;		
		}
	}

	queue<pair<int, int>> Q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == 1)
			{
				Q.push({ i, j });
				vis[i][j] = 0;
			}
		}
	}

	while (!Q.empty())
	{
		pair<int, int> cur = Q.front(); Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] >= 0 || board[nx][ny] == -1) continue;
			
			vis[nx][ny] = vis[cur.X][cur.Y] + 1;
			
			Q.push({ nx, ny });
		}
	}

	int mx = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (vis[i][j] == -1 && board[i][j]!= -1)
			{
				cout << -1;
				return 0;
			}
			mx = max(mx, vis[i][j]);
		}
	}
	cout << mx;
}