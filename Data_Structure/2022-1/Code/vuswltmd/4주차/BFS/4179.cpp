#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>
using namespace std;

char board[1005][1005];
int j_vis[1005][1005];
int f_vis[1005][1005];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int R, C;
	cin >> R >> C;

	queue<pair<int, int>> JQ;
	queue<pair<int, int>> FQ;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == 'J')
			{
				JQ.push({ i, j });
				j_vis[i][j] = 1;
			}

			if (board[i][j] == 'F')
			{
				FQ.push({ i, j });
				f_vis[i][j] = 1;
			}
		}
	}

	while (!FQ.empty()) // บา BFS
	{
		auto cur = FQ.front(); FQ.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (f_vis[nx][ny] >= 1 || board[nx][ny] == '#') continue;

			f_vis[nx][ny] = f_vis[cur.first][cur.second] + 1;
			FQ.push({ nx, ny });
		}
	}

	while (!JQ.empty())
	{
		auto cur = JQ.front(); JQ.pop();

		for (int dir = 0; dir < 4; dir++)
		{ 
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			{
				cout << j_vis[cur.first][cur.second];
				return 0;
			}
			if (j_vis[nx][ny] >= 1 || board[nx][ny] == '#') continue;
			if (f_vis[nx][ny] <= j_vis[cur.first][cur.second] + 1 && f_vis[nx][ny] != 0) continue;
			j_vis[nx][ny] = j_vis[cur.first][cur.second] + 1;
			JQ.push({ nx,ny });
		}
	}

	cout << "IMPOSSIBLE";
}