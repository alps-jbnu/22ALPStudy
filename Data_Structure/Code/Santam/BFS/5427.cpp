#include <iostream>
#include <queue>

using namespace std;

int vis_f[1000][1000];
int vis_j[1000][1000];
int d_x[4] = { 1,0,-1,0 };
int d_y[4] = { 0,-1,0,1 };

void tester(queue<pair<int,int>> q_f, queue<pair<int, int>> q_j,int x,int y)
{
	int result = 0;
	bool exit_success = false;
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
	while (!q_j.empty() && !exit_success)
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
					if (vis_f[cur.first][cur.second] != -1) continue;
				}
				result = vis_j[cur.first][cur.second];
				exit_success = true;
				break;
			}
			if (vis_j[nx][ny] >= 0) continue;
			if (vis_j[nx][ny] >= vis_f[nx][ny])
			{
				if (vis_f[nx][ny] != -1) continue;
			}
			vis_j[nx][ny] = vis_j[cur.first][cur.second] + 1;
			q_j.push({ nx,ny });
		}
	}

	if (exit_success) cout << result<<"\n";
	else cout << "IMPOSSIBLE" << "\n";

	for (int i = 0;i < 1000;i++)
	{
		for (int j = 0;j < 1000;j++)
		{
			vis_f[i][j]=0;
			vis_j[i][j]=0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int cnt = 0;cnt < n;cnt++)
	{
		queue<pair<int, int>> q_f, q_j;
		int x, y;
		cin >> x >> y;
		for (int i = 0;i < y;i++)
		{
			for (int j = 0;j < x;j++)
			{
				char temp;
				cin >> temp;
				if (temp == '*')
				{
					q_f.push({ j,i });
					vis_f[j][i] = 1;
				}
				if (temp == '@')
				{
					q_j.push({ j,i });
					vis_j[j][i] = 1;
					vis_f[j][i] = -1;
				}
				if (temp == '.')
				{
					vis_f[j][i] = -1;
					vis_j[j][i] = -1;
				}
			}
		}
		tester(q_f, q_j, x, y);
	}
	

	return 0;
}

/*
연습문제 4179의 불!과 같은 문제(테스터 1개냐 다수개냐의 차이)
*/