#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int board[1001][1001];

void bfs(int v)
{
	int vis[1001] = { 0 };
	queue<int> q;
	vis[v] = 1;
	q.push(v);
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		cout << cur << " ";
		for (int i = 1;i <= 1000;i++)
		{
			if (board[cur][i] == 0) continue;
			if (vis[i] != 0) continue;
			vis[i] = 1;
			q.push(i);
		}
	}
	cout << "\n";
}

void dfs(int v)
{
	int vis[1001] = { 0 };
	stack<int> s;
	s.push(v);
	while (!s.empty())
	{
		int cur = s.top(); s.pop();
		if (vis[cur] != 0) continue;
		vis[cur] = 1;
		cout << cur << " ";
		for (int i = 1000;i >= 1;i--)
		{
			if (board[cur][i] == 0) continue;
			if (vis[i] != 0) continue;
			s.push(i);
		}
	}
	cout << "\n";
} //비 재귀 dfs


int main()
{
	int n, m, v;
	cin >> n >> m >> v;
	for (int i = 0;i < m;i++)
	{
		int x, y;
		cin >> x >> y;
		board[x][y] = 1;
		board[y][x] = 1;
	}
	dfs(v);
	bfs(v);
	return 0;
}
// 이 문제에 dfs(비재귀)와 bfs함수를 각각 만들어 pop이 될때마다==(현재 탐색중인 수)를 출력하도록 했다.