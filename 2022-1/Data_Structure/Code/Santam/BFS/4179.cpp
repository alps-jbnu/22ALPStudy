#include <iostream>
#include <queue>

using namespace std;

char board[1000][1000];
int vis_f[1000][1000];
int vis_j[1000][1000];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	queue<pair<int, int>> q_f, q_j;
	int d_x[4] = { 1,0,-1,0 };
	int d_y[4] = { 0,-1,0,1 };
	bool exit_success = false;
	int x, y,result;
	cin >> y >> x;
	for (int i = 0;i < y;i++)
	{
		for (int j = 0;j < x;j++)
		{
			cin >> board[j][i];
			if (board[j][i] == 'F')
			{
				q_f.push({ j,i });
				vis_f[j][i] = 1;
			}
			if (board[j][i] == 'J')
			{
				q_j.push({ j,i });
				vis_j[j][i] = 1;
				vis_f[j][i] = -1;
			}
			if (board[j][i] == '.')
			{
				vis_f[j][i] = -1;
				vis_j[j][i] = -1;
			}
		}
	}
	while (!q_f.empty())
	{
		pair<int, int> cur = q_f.front();q_f.pop();
		for (int dir = 0;dir < 4;dir++)
		{
			int nx = cur.first + d_x[dir];
			int ny = cur.second + d_y[dir];
			if (nx < 0 || ny < 0 || nx >= x || ny >= y) continue;
			if (vis_f[nx][ny] >= 0) continue;
			vis_f[nx][ny] = vis_f[cur.first][cur.second] + 1;
			q_f.push({ nx,ny });
		}
	}
	while (!q_j.empty()&&!exit_success)
	{
		pair<int, int> cur = q_j.front();q_j.pop();
		for (int dir = 0;dir < 4;dir++)
		{
			int nx = cur.first + d_x[dir];
			int ny = cur.second + d_y[dir];
			if (nx < 0 || ny < 0 || nx >= x || ny >= y)
			{
				if (vis_j[cur.first][cur.second] >= vis_f[cur.first][cur.second])
				{
					if(vis_f[cur.first][cur.second]!=-1) continue;
				}
				result = vis_j[cur.first][cur.second];
				exit_success = true;
				break;
			}
			if (vis_j[nx][ny] >= 0) continue;
			if (vis_j[nx][ny] >= vis_f[nx][ny])
			{
				if(vis_f[nx][ny]!=-1) continue;
			}
			vis_j[nx][ny] = vis_j[cur.first][cur.second] + 1;
			q_j.push({ nx,ny });
		}
	}

	if (exit_success) cout << result;
	else cout << "IMPOSSIBLE";


	return 0;
}