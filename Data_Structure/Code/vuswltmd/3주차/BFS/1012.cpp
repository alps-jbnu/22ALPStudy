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

int board[52][52];
int vis[52][52];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n, m, k;
		cin >> m >> n >> k;

		queue<pair<int, int>> Q;

		int num = 0; // Áö··ÀÌ¼ö 

		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;

			board[y][x] = 1;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] == 1 && !vis[i][j])
				{
					Q.push({ i, j });
					
					vis[i][j] = 1;
					num++;
				}

				while (!Q.empty())
				{
					auto cur = Q.front(); Q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (board[nx][ny] == 0 || vis[nx][ny] == 1) continue;

						vis[nx][ny] = 1;
						Q.push({ nx, ny });
					}
				}
			}
		}

		cout << num << '\n';

		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < m; j++)
			{
				board[i][j] = 0;
				vis[i][j] = 0;
			}
		}
	}

	


	

}
