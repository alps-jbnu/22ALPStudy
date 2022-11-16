#include <bits/stdc++.h>
#define x first
#define y second
#define INF 300000
using namespace std;

vector<pair<int, int>> adj[20005]{}; //간선 데이터
int d[20005]{}; // 갱신 데이터
int n, m, a, b, c, sum, res;

void dijk()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // x:간선 거리 , y:노드
	q.push({ 0,a });
	d[a] = 0;
	while (!q.empty())
	{
		auto cur = q.top(); q.pop();
		if (d[cur.y] < cur.x) continue; //갱신되기 전 데이터가 남아있어서 선택된경우
		for (auto nxt : adj[cur.y])
		{
			if (d[nxt.y] <= d[cur.y] + nxt.x) continue;
			d[nxt.y] = d[cur.y] + nxt.x;
			q.push({ d[nxt.y], nxt.y });
		}
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	fill(&d[0], &d[20004], INF);
	cin >> n >> m >> a;
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}
	dijk();
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == INF) cout << "INF\n";
		else cout << d[i] << "\n";
	}
	return 0;
}