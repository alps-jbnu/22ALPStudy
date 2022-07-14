#include <iostream>
#include <queue>

using namespace std;

vector<int> board[20001];
int vis[20001] = { 0 };

int main()
{
	vector<int> res_num;
	queue<int> q;
	int n, m,res=0;
	cin >> n >> m;
	for (int i = 0;i < m;i++)
	{
		int u, v;
		cin >> u >> v;
		board[u].push_back(v);
		board[v].push_back(u);
	}
	q.push(1);
	vis[1] = 1;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int i = 0;i < board[cur].size();i++)
		{
			if (vis[board[cur][i]] != 0) continue;
			vis[board[cur][i]] = vis[cur] + 1;
			q.push(board[cur][i]);
		}
	}
	for (int i = 1;i <= n;i++)
	{
		if (vis[i] >= res)
		{
			if (vis[i] > res)
			{
				res = vis[i];
				res_num.clear();
			}
			res_num.push_back(i);
		}
	}
	cout << res_num[0] << " " << res - 1 << " " << res_num.size();
	return 0;
}
/*
bfs이용해 시작점이 하나라는점, 거리가 가장 먼 정점들을 구하면 된다는 점을 생각해서 풀었다.
*/