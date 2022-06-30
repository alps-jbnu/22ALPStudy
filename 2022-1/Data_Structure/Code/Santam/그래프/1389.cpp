#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

vector<int> board[101];
int vis[101] = { 0 };

int main()
{

	queue<int> q;
	int n,m,res, res_score = 1000;
	cin >> n >>m;

	for(int i=0;i<m;i++)
	{
		int u, v;
		cin >> u >> v;
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
		for (int j = 1;j <= n;j++) vis[0] += vis[j];
		if (res_score > vis[0])
		{
			res_score = vis[0];
			res = i;
		}
		memset(vis, 0, sizeof(int) * 51);
	}
	cout << res;
	return 0;
}
/*
회장뽑기 문제 하위호환
1. 각 정점에서 나머지 정점까지의 최소 거리 구하기 (bfs활용)
2. 거리의 합을 기존의 score점수와 비교해 작은 걸 저장,출력
*/