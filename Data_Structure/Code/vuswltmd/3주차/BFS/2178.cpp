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

string board[102];
int vis[102][102];


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}

	

	queue<pair<int, int>> Q;
	Q.push({ 0, 0 });
	vis[0][0] = 1;

	while (!Q.empty())
	{
		pair<int, int> cur = Q.front(); Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == '0' || vis[nx][ny] > 0) continue;
			vis[nx][ny] = vis[cur.X][cur.Y] + 1;
			Q.push({ nx, ny });
		}
	}
	cout << vis[n - 1][m - 1];

}
