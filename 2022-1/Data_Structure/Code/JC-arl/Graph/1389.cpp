#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> adj[5005];
bool vist[5005];
int dist[5005];
int num[5005];
int N, M;

int main(void)
{
	int min = 100000, index;
	cin >> N >> M;
	int u, v;
	while (M--)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= N; i++)
	{
		fill(vist, vist + N + 1, false);
		fill(dist, dist + N + 1, 0);
		queue<int> q;
		q.push(i);
		vist[i] = true;

		while (!q.empty())
		{
			int cur = q.front(); q.pop();
			for (auto nxt : adj[cur])
			{
				if (vist[nxt])	continue;
				q.push(nxt);
				dist[nxt] = dist[cur] + 1;
				vist[nxt] = true;
			}
		}
		for (int j = 1; j <= N; j++)
			num[i] += dist[j];
	}
	
	for (int i = 1; i <= N; i++)
	{
		if (num[i] < min)
		{
			min = num[i];
			index = i;
		}
	}
	cout << index;

	return 0;
}
