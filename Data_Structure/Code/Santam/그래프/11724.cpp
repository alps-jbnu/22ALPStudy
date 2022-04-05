#include <iostream>
#include <queue>

using namespace std;

int vis[1001] = { 0 };
int board[1001][1001] = { 0 };

int main()
{
	queue<int> q;
	int n, m, res = 0;
	cin >> n >> m;
	for (int i = 0;i < m;i++)
	{
		int u, v;
		cin >> u >> v;
		board[u][v] = 1;
		board[v][u] = 1;
		board[u][0] = 1; // 정점에 간선 여부 체크
		board[v][0] = 1;
	}
	for (int i = 1;i <= n;i++)
	{
		if (vis[i] != 1)
		{
			vis[i] = 1;
			res++;
			if (!board[i][0]) continue;
			q.push(i);
			while (!q.empty())
			{
				int cur = q.front(); q.pop();
				for (int j = 1;j <= 1000;j++)
				{
					if (board[cur][j] == 0) continue;
					if (vis[j] == 1) continue;
					vis[j] = 1;
					q.push(j);
				}
			}
		}
	}

	cout << res;

	return 0;

}

/*
그래프 문제인걸 알아서, 인접 행렬 board를 지정해 입력값을 받아주고, bfs를 돌렸다.
*/