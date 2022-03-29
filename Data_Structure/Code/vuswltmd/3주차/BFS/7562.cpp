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

int board[302][302];
int vis[302][302];

int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int l;
		cin >> l;

		queue<pair<int, int>> Q;
		pair<int, int> knight;
		pair<int, int> dest;

		cin >> knight.X;
		cin >> knight.Y;

		cin >> dest.X;
		cin >> dest.Y;

		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < l; j++)
			{
				vis[i][j] = -1;
			}
		}
	
		vis[knight.X][knight.Y] = 0;

		Q.push({ knight.X, knight.Y });

		

			while (!Q.empty())
			{
				pair<int, int> cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 8; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
					if (vis[nx][ny] >= 0) continue;

					vis[nx][ny] = vis[cur.X][cur.Y] + 1;
					Q.push({ nx, ny });
				}
			}
		

			cout << vis[dest.X][dest.Y] << "\n";
	}
}