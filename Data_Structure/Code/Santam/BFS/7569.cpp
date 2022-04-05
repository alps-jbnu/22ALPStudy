#include <iostream>
#include <queue>>
#include <tuple>
using namespace std;

int board[100][100][100];
int vis[100][100][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	queue<tuple<int,int,int>> q;
	bool fin_already=true, dont_fin_all=false;
	int n, m, h,day_min=0;
	int d_x[6] = { 1,-1,0,0,0,0 };
	int d_y[6] = { 0,0,1,-1,0,0 };
	int d_z[6] = { 0,0,0,0,1,-1 };
	cin >> m >> n >> h;

	for (int i = 0;i < h;i++)
	{
		for (int j = 0;j < n;j++)
		{
			for (int k = 0;k < m;k++)
			{
				cin>>board[k][j][i];
				if (board[k][j][i] == 1) q.push(make_tuple(k, j, i));
				if (board[k][j][i] == 0)
				{
					vis[k][j][i] = -1;
					fin_already = false;
				}
			}
		}
	}
	while (!q.empty())
	{
		tuple<int, int, int> cur = q.front(); q.pop();
		for (int dir = 0;dir < 6;dir++)
		{
			int nx = get<0>(cur) + d_x[dir];
			int ny = get<1>(cur) + d_y[dir];
			int nz = get<2>(cur) + d_z[dir];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= m | ny >= n || nz >= h) continue;
			if (vis[nx][ny][nz]>=0) continue;
			vis[nx][ny][nz] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			q.push(make_tuple(nx, ny, nz));
		}
	}

	for (int i = 0;i < h;i++)
	{
		for (int j = 0;j < n;j++)
		{
			for (int k = 0;k < m;k++)
			{
				if (vis[k][j][i]==-1)
				{
					dont_fin_all = true;
				}
				if (vis[k][j][i] > day_min) day_min = vis[k][j][i];
			}
		}
	}

	if (fin_already || dont_fin_all)
	{
		if (fin_already) cout << 0;
		else cout << -1;
	}
	else cout << day_min;
	
	return 0;
}

/*
토마토 2차원 문제와 같음
1. 토마토 2차원 배열에 z축만 추가하고 pair대신 tuple을 이용해 z축을 표현하면 된다. 유의할 점은 z축이 추가되면서 방향도 2개 더 늘어난다는 점?

*/