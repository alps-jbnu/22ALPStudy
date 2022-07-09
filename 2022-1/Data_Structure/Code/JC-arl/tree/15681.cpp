#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, R, Q;
vector<int> adj[100000];
bool vis[100000];
bool check;
int bfs(int sub_root)
{
	int node = 0;
	queue<int> q;
	q.push(R);
	while (!q.empty())
	{
		int cur = q.front();	q.pop();
		if (cur == sub_root)
		{
			check = true;
			while (!q.empty())
				q.pop();
		}
			
		for (auto nxt : adj[cur])
		{
			if (vis[nxt])	continue;
			vis[cur] = true;
			q.push(nxt);
			
		}
		if (check)
			node++;
	}

	return node;
}

int main(void)
{
	cin >> N >> R >> Q;
	for (int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < Q; i++)
	{
		fill(vis, vis + N, false);
		check = false;
		int q;
		cin >> q;
		cout << bfs(q)<<"\n";
	}
	return 0;
}