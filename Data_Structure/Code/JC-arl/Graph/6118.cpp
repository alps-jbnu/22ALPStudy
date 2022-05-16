#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> adj[20005];
bool vist[20005];
int dist[20005];
int N, M;
int main(void)
{
	cin >> N >> M;
	int u, v;
	while (M--)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int max = 0;
	queue<int> q;
	q.push(1);
	vist[1] = true;
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
	}for (int i = 1; i <= N; i++)
	{
		if (max < dist[i])
			max = dist[i];
	}

	queue<int> re;
	bool check=false;
	for (int i = 1; i <= N; i++)
	{
		if (max == dist[i])
			q.push(i);
	}
	cout << q.front() << " " << max << " " << q.size();
	return 0;
}