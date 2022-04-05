#include<iostream>
#include<queue>
#include<vector>
#include <algorithm>
using namespace std;
int num[55];
vector<int> adj[55];
bool vist[55];
int dist[55];
int N;

int main(void)
{
	cin >> N;
	int u, v;
	while (true)
	{
		cin >> u >> v;
		if (u == -1 && v == -1)
			break;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= N; i++)
	{
		fill(vist, vist + N+1, false);
		fill(dist, dist + N+1, 0);
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
			num[i] = max(num[i], dist[j]);
	}
	int min_=10000;
	for(int i=1;i<=N;i++)
		min_ = min(min_, num[i]);
	vector<int> re;
	for (int i = 1; i <= N; i++)
	{
		if (min_ == num[i])
			re.push_back(i);
	}
	cout << min_ << ' ' << re.size() << "\n";
	for (auto r : re)
		cout << r << " ";
	return 0;
}