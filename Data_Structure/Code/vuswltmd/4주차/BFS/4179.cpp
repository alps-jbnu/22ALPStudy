#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iterator>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
using namespace std;
#define X first
#define Y second
char board[1002][1002];
int visf[1002][1002];
int visj[1002][1002];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1,  0, -1};

int n, m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);



	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visf[i][j] = -1;
			visj[i][j] = -1;
		}
		
	}

	queue<pair<int, int>> Qj;
	queue<pair<int, int>> Qf;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			
			if (board[i][j] == 'J')
			{
				visj[i][j] = 0;
				Qj.push({ i, j });
			}

			if (board[i][j] == 'F')
			{
				visf[i][j] = 0;
				Qf.push({ i, j });
			}
		}
	}


	while (!Qf.empty())
	{
		auto cur = Qf.front(); Qf.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (visf[nx][ny] >= 0 || board[nx][ny] == '#') continue;

			visf[nx][ny] = visf[cur.X][cur.Y] + 1;
			Qf.push({ nx, ny });
		}

	}
	//불 bfs가 잘 작동됨
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		cout << visf[i][j];
	//	}
	//	cout << endl;
	//}

	while (!Qj.empty())
	{
		auto cur = Qj.front(); Qj.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if(nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				cout << visj[cur.X][cur.Y] + 1;
				return 0;
			}
			if (board[nx][ny] == '#' || visj[nx][ny] >= 0) continue;
			if (visf[nx][ny] != -1 && visf[nx][ny] <= visj[cur.X][cur.Y]+1)continue;
			
			visj[nx][ny] = visj[cur.X][cur.Y] + 1;
			Qj.push({ nx, ny });
		}

		
	}
	cout << "IMPOSSIBlE";
}