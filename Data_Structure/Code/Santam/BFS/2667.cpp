#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

char board[25][25];
int vis[25][25];
int d_x[4] = { 1,0,-1,0 };
int d_y[4] = { 0,-1,0,1 };

int main()
{
	queue <pair<int, int>> q;
	int res_w[625] = { 0 };
	int n,res=0;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0;j < n;j++)
		{
			board[j][i] = temp[j];
		}
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (board[j][i] == '1' && vis[j][i] == 0)
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
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						if (vis[nx][ny] != 0 || board[nx][ny] == '0') continue;
						vis[nx][ny] = 1;
						q.push({ nx, ny });
					}
				}
				res++;
			}
		}
	}
	cout << res << "\n";
	sort(res_w, res_w + res);
	for (int i=0;i < res;i++) cout << res_w[i] << "\n";

	return 0;
}

/*
bfs의 그림 문제와 같은 유형 다른점은 각각의 넓이를 전부 저장해주고 오름차순으로 출력하는 정도
*/