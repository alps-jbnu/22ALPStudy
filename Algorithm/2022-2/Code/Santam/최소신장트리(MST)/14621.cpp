#include <bits/stdc++.h>
#define x first
#define y second
#define tp tuple<int,int,int>

using namespace std;

priority_queue<tp, vector<tp>, greater<tp>> pq; // x: 비용, y: u, z: v
vector<pair<int, int>> adj[1001]; // x: 비용 , y: v
int cost[1001][1001]{};
bool chk_group[1001]{};
bool vis[1001]{};
int n, m, u, v, d;

void insert_q(int a)
{
	for (auto b : adj[a])
	{
		if (!vis[b.y]) pq.push({ b.x, a, b.y });
	} // 신장트리에 새로운 정점추가할 경우, 해당 노드의 next간선들 전부 push
}


int MST()
{
	insert_q(1);
	vis[1] = 1;
	int res = 0, cnt = 0; // 신장트리에 확정된 간선 수
	while (cnt < n - 1&&!pq.empty()) //그룹이 전부 같은경우 예외처리 -->bfs방식과 유사
	{
		int cost, s, e;
		tie(cost, s, e) = pq.top(); pq.pop();
		if (vis[e]) continue; // 그룹의 비교는 pq 삽입될때 해주므로 제외
		vis[e] = 1;
		cnt++;
		res += cost;
		insert_q(e);
	}
	if (cnt == n - 1) return res;
	return -1;
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		char c; cin >> c;
		chk_group[i + 1] = (c == 'M');
	}
	while (m--)
	{
		cin >> u >> v >> d;
		if (chk_group[u] == chk_group[v]) continue;
		adj[u].push_back({ d,v });
		adj[v].push_back({ d,u });
	}
	cout << MST();
	return 0;
}