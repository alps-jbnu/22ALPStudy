#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>
#include <tuple>
using namespace std;

int board[105][105][105];
int dist[105][105][105];

int dx[6] = { 0, 0, 1, 0, 0, -1 };
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 1, 0, 0, -1, 0, 0 };

int ans = 0;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int m, n, h;
	cin >> m >> n >> h;

	queue<tuple<int, int, int>> Q;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> board[j][k][i];
				if (board[j][k][i] == 1) Q.push({ j, k, i });
				if (board[j][k][i] == 0) dist[j][k][i] = -1;
			}
		}
	}

	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();

		int curX, curY, curZ;
		tie(curX, curY, curZ) = cur;

		for (int dir = 0; dir < 6; dir++)
		{
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			int nz = curZ + dz[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if (dist[nx][ny][nz] != -1 || board[nx][ny][nz] != 0) continue;
			if (dist[nx][ny][nz] >= 0) continue;
			dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
			Q.push({ nx, ny, nz });
		}

	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (dist[j][k][i] == -1)
				{
					cout << -1 << '\n';
					return 0;
				}
				ans = max(ans, dist[j][k][i]);
			}
		}
	}

	cout << ans << "\n";
	return 0;


}