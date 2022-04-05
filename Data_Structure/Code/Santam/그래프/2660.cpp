#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> board[51];
int vis[51] = { 0 };

int main()
{

	queue<int> q;
	vector<int> res;
	int n,res_score=51;
	cin >> n;

	while (1)
	{
		int u, v;
		cin >> u >> v;
		if (u + v == -2) break;
		board[u].push_back(v);
		board[v].push_back(u);
	}
	for (int i = 1;i <= n;i++)
	{
		q.push(i);
		while (!q.empty())
		{
			int cur = q.front(); q.pop();
			for (int dir = 0;dir < board[cur].size();dir++)
			{
				if (vis[board[cur][dir]] <= vis[cur] + 1)
				{
					if (vis[board[cur][dir]] != 0) continue;
				}
				vis[board[cur][dir]] = vis[cur] + 1;
				q.push(board[cur][dir]);
			}
		}
		vis[i] = 0;
		sort(vis, vis+n+1);
		if (res_score >= vis[n])
		{
			if (res_score > vis[n])
			{
				res_score = vis[n];
				res.clear();
			}
			res.push_back(i);
		}
		memset(vis, 0, sizeof(int) * 51);
	}
	
	cout << res_score << " " << res.size() << "\n";
	for (int i = 0;i < res.size();i++)
	{
		cout << res[i] << " ";
	}

	return 0;
}
/*
각 사람마다 bfs를 돌려 가장 먼 친구의 거리를 구해서 비교, 그리고, 만약 거리가 같다면 그 사람을 저장하는 방식을 생각했다.
==> 각 정점을 시작점으로 한 bfs수행, 각 정점의 최대 거리 구하여 비교
*/