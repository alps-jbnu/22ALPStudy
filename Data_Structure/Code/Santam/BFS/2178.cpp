#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

char board[105][105] = { 0 };
int vis[105][105] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	queue<pair<int, int>> q;
	int d_x[4] = { 1,0,-1,0 };
	int d_y[4] = { 0,-1,0,1 };
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0;j < m;j++)
		{
			board[j][i]=temp[j];
		}	
	}
	vis[0][0] = 1;
	q.push({ 0,0 });
	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();
		for (int dir = 0;dir < 4;dir++)
		{
			int nx = cur.first + d_x[dir];
			int ny = cur.second + d_y[dir];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (vis[nx][ny] || board[nx][ny] != '1') continue;
			vis[nx][ny] = vis[cur.first][cur.second]+1;
			q.push({ nx, ny });
		}
	}
	cout << vis[m-1][n-1] << "\n";

	return 0;
}

/*
BFS를 이용하는데 최소 이동거리를 찾기위해 방문표시를 담당하는 vis를 이용

1. vis배열에 처음에는 1로 시작해서 새로운 vis를 표시할때 원래 vis에 +1을 더한 값을 저장하도록 한다.
2. 1의 과정을 반복하면 m,n의 칸에 대해 몇칸을 왔는지 카운트가 자동으로 된다.
*/