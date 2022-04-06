#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> adj[105];
bool vis[105];
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
	queue<int> q;
	int num = 0;
	q.push(1);
	vis[1] = true;
	while (!q.empty())
	{
		int cur = q.front();	q.pop();
		
		for (auto nxt : adj[cur])
		{
			if (vis[nxt])	continue;
			q.push(nxt);
			num++;
			vis[nxt] = true;
		}
		
	}
	cout << num;
	return 0;
}