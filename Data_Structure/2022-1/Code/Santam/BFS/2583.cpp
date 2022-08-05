#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int board[100][100];
int vis[100][100];
int d_x[4] = { 1,0,-1,0 };
int d_y[4] = { 0,-1,0,1 };

int main()
{
	queue<pair<int, int>> q;
	int res_w[100] = { 0 };
	int n, m, k,res=0;
	cin >> n >> m >> k;
	for (int i = 0;i < k;i++)
	{
		int s_x, s_y, f_x, f_y;
		cin >> s_x >> s_y >> f_x >> f_y;
		for (int j = s_y;j < f_y;j++)
		{
			for (int l = s_x;l < f_x;l++)
			{
				board[l][j] = 1;
			}
		}
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (!board[j][i] && !vis[j][i])
			{				
				vis[j][i] = 1;
				q.push({ j,i });
				while (!q.empty())
				{
					pair<int, int> cur = q.front(); q.pop();
					res_w[res]++;
					for (int dir = 0;dir < 4;dir++)
					{
						int nx = cur.first + d_x[dir];
						int ny = cur.second + d_y[dir];
						if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
						if (vis[nx][ny] != 0 || board[nx][ny] != 0) continue;
						vis[nx][ny] = 1;
						q.push({ nx,ny });
					}
				}
				res++;
			}
		}
	}
	sort(res_w, res_w+res);
	cout << res << "\n";
	for (int i = 0;i < res;i++) cout << res_w[i] << " ";

	return 0;
}

/*
입력받은 직사각형을 벽이라고 생각하고 bfs 그림유형으로 생각하고 풀면 된다고 생각+넓이 전부를 다 저장해야해서 배열 추가

1. 입력받은 직사각형 넓이 좌표 영역대로 board에 벽 추가
2. vis이 0이면서 board가 벽이 아닌 곳이 나올때면 분리된 영역 개수 추가하면서 그 영역의 넓이를 큐안의 원소를 pop할때마다 1씩 더해주며 구함
*/