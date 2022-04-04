#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int board[100][100];
int vis[100][100];
int d_x[4] = { 1,0,-1,0 };
int d_y[4] = { 0,-1,0,1 };

int main()
{
	queue<pair<int, int>> q;
	int n,res_max=0,temp_max=0;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cin>>board[j][i];
		}
	}

	for (int i = 0;i <= 100;i++)
	{
		for (int j = 0;j < n;j++)
		{
			for (int k = 0;k < n;k++)
			{
				if (board[k][j] > i &&vis[k][j]==0)
				{
					vis[k][j] = 1;
					q.push({ k,j });
					while (!q.empty())
					{
						pair<int, int> cur = q.front();q.pop();
						for (int dir = 0;dir < 4;dir++)
						{
							int nx = cur.first + d_x[dir];
							int ny = cur.second + d_y[dir];
							if (nx < 0 || ny < 0 || nx >= n||ny >= n) continue;
							if (vis[nx][ny] != 0 || board[nx][ny] <= i) continue;
							vis[nx][ny] = 1;
							q.push({ nx,ny });
						}
					}
					temp_max++;
				}
			}
		}
		if (res_max < temp_max) res_max = temp_max;
		temp_max = 0;
		memset(vis, 0, sizeof(int) *10000);
	}

	cout << res_max;
	return 0;
}
/*
기존 bfs 영역 개수 구하는 유형에서 영역을 나누는 기준이 벽이 아닌 높이에 따라서 나눠진다는 걸 생각하고 문제를 풀어봄
1. 영역 개수를 저장할 res_max와 높이의 기준이 0~100까지 될때의 각각의 케이스마다 영역 개수의 결과가 임시로 될 temp_max를 만들었다.
2. for문을 이용해 높이 100까지의 케이스를 전부 돌려서 그 각각의 케이스마다의 영역 개수중 최대값을 저장, 출력해주었다.
*/
