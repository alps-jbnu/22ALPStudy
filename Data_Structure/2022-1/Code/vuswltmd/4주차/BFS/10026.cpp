#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>
using namespace std;

char board[105][105];
char h_board[105][105];
bool n_vis[105][105]; // 정상
bool h_vis[105][105]; // 적록색약
int n_count; //정상인이 보는 수
int h_count; // 적록색약이 보는 수
int n;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char a;
			cin >> a;
			board[i][j] = a;

			if (a == 'G')
			{
				h_board[i][j] = 'R';
			}
			else
			{
				h_board[i][j] = a;
			}
		}
	}

	queue<pair<int, int>> nq;
	queue<pair<int, int>> hq;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (n_vis[i][j] == 0)
			{
				nq.push({ i, j });
				n_count++;
			}

			while (!nq.empty())
			{
				auto cur = nq.front(); nq.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (n_vis[nx][ny] != 0 || board[nx][ny] != board[cur.first][cur.second]) continue;
					n_vis[nx][ny] = 1;
					nq.push({ nx, ny });
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (h_vis[i][j] == 0)
			{
				hq.push({ i, j });
				h_count++;
			}

			while (!hq.empty())
			{
				auto cur = hq.front(); hq.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (h_vis[nx][ny] != 0 || h_board[nx][ny] != h_board[cur.first][cur.second]) continue;
					h_vis[nx][ny] = 1;
					hq.push({ nx, ny });
				}
			}
		}
	}

	cout << n_count << ' ' << h_count;
	
}