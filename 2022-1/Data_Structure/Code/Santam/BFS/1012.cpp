#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int d_x[4] = { 1,0, -1,0 };
int d_y[4] = { 0,-1,0,1 };
int board[50][50];
int vis[50][50];

void tester()
{
	queue<pair<int, int>> q;
	int n, m, k, res = 0;
	cin >> m >> n >> k;

	for (int i = 0;i < k;i++)
	{
		int temp_x, temp_y;
		cin >> temp_x >> temp_y;
		board[temp_x][temp_y] = 1;
	}

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (board[j][i] > 0 && vis[j][i] == 0)
			{
				res++;
				q.push({ j,i });
				vis[j][i] = 1;
				while (!q.empty())
				{
					pair<int, int> cur = q.front(); q.pop();
					for (int dir = 0;dir < 4;dir++)
					{
						int nx = cur.first + d_x[dir];
						int ny = cur.second + d_y[dir];
						if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
						if (vis[nx][ny] != 0 || board[nx][ny] != 1) continue;
						vis[nx][ny] = 1;
						q.push({ nx,ny });
					}
				}
			}
		}
	}

	cout << res << "\n";
}

int main()
{
	int cnt;
	cin >> cnt;
	for (int i = 0;i < cnt;i++)
	{
		tester();
		memset(board, 0, sizeof(int) * 2500);
		memset(vis, 0, sizeof(int) * 2500);

	}
	return 0;

}

/*
배추의 위치를 board에 저장하고 그후 board전체에 대해 반복문을 돌려주면서 배추가 있는데 bfs의 방문 흔적이 없는 경우에 그 값을 큐에 넣고 bfs실시하는 방식으로 하면 배추군집의 개수를 알 수있다고 생각
1. 배추 위치 board에 저장, 그 후 board에 대해 만약, 배추가 있지만 방문한 흔적이 없는 경우에 대해 그 위치를 vis에 표시를 해주면서 큐에 push한 후, bfs 실시
2. 어떤 하나의 배추에 대해 bfs를 실시 후에, 그 배추와 인접해있는 배추들은 전부 방문 흔적이 남아있기에 board를 다시 검사할때 예외됨
*/