#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, M, cnt = 0;
bool Visited[1001];

vector<pair<int, int>> vec[1001];
queue<int> q;

void BFS(int x)
{
	if (!Visited[x])
	{
		q.push(x);
		Visited[x] = true;

		while (!q.empty())
		{
			int num = q.front();
			q.pop();

			for (int i = 0; i < vec[num].size(); i++)
			{
				if (!Visited[vec[num][i].first])
				{
					Visited[vec[num][i].first] = true;
					q.push(vec[num][i].first);
				}
			}
		}
		cnt++;
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;

		vec[u].push_back(make_pair(v, v));
		vec[v].push_back(make_pair(u, u));
	}

	for (int i = 1; i <= N; i++)
	{
		BFS(i);
	}

	cout << cnt << "\n";

	return 0;
}