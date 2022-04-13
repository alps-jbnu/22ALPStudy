#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> adj[100000];
bool vist[100000];
int dist[100000];
int num[10];
int N, M;

int main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	int max1 = 0, index;
	cin >> N >> M;
	int u, v;
	while (M--)
	{
		cin >> u >> v;
		adj[v].push_back(u);
	}
	for (int i = 1; i <= N; i++)
	{
		fill(vist, vist + N + 1, false);
		fill(dist, dist + N + 1, 0);
		int count = 0;
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
				count++;
				vist[nxt] = true;
			}
		}
		//for (int j = 1; j <= N; j++)
			//num[i] = max(-1, dist[j]);
		num[i] = count;
	}

	vector<int> re;
	for (int i = 1; i <= N; i++)
	{
		if (num[i] >= max1)
		{
			max1 = num[i];
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (max1 == num[i])
			cout << i << " ";
	}

	return 0;
}
