#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> adj[505];
bool vis[505];
int dist[505];
int N,m;
int main(void)
{
	cin >> N >> m;
	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int num = 0;
	queue<int> q;
	q.push(1);
	vis[1]=true;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (auto nxt : adj[cur])
		{
			if (vis[nxt])continue;
			q.push(nxt);
			dist[nxt] = dist[cur] + 1;
			if(dist[nxt]<=2)
				num++;
			vis[nxt] = true;
			
		}
	}
	cout << num;
	return 0;
}