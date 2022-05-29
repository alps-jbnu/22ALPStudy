#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int dis[1005][1005];
bool vis[1005];
vector<int> adj[1005];

int bfs(int fir,int sec)
{
	int r=0;
	queue<int> q;
	q.push(fir);
	while (!q.empty())
	{
		int cur = q.front();	q.pop();
		for (auto nxt : adj[cur])
		{
			if (vis[nxt] == true)	continue;
			vis[cur] = true;
			//vis[nxt][cur] = true;
			r += dis[cur][nxt];
			if (nxt == sec)
				break;
			q.push(nxt);
		}
	}
	return r;
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N-1; i++)
	{
		int u, v, d;
		cin >> u >> v >> d;
		adj[u].push_back(v);
		adj[v].push_back(u);
		
		dis[u][v] = d;
		dis[v][u] = d;
	}
	for (int i = 0;i < M; i++)
	{
		fill(vis, vis + N, false);
		//for (int j = 0; j < N; j++)
		{
		}
		int fir, sec;
		cin >> fir >> sec;
		cout << bfs(fir, sec) << "\n";
	}

	return 0;
}