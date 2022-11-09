#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>
#include <tuple>
using namespace std;

char board[1005][1005];
int dist[1005][1005][2];
int dx[4] = { 0 , 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dist[i][j][0] = dist[i][j][1] = -1;
		}
	}
	dist[0][0][0] = dist[0][0][1] = 1;

	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, 0 });

	while (!q.empty())
	{
		int x, y, broke;
		tie(x, y, broke) = q.front(); 

		if (x == n - 1 && y == m - 1)
		{
			cout << dist[x][y][broke];
			return 0;
		}

		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx > n || ny < 0 || ny > m) continue;
			if (board[nx][ny] == '0' && dist[nx][ny][broke] == -1)
			{
				dist[nx][ny][broke] = dist[x][y][broke] + 1;
				q.push({ nx, ny, broke });
			}
			
			if (broke != 1 && dist[nx][ny][0] == -1 && board[nx][ny] == '1')
			{
				dist[nx][ny][1] = dist[x][y][broke] + 1;
				q.push({ nx, ny, 1});
			}
		}
	}

	cout << -1;

}