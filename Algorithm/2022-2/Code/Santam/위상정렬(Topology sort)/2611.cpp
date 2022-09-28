#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

vector<pair<int, int>> adj[1001]; // x:간선의 목적지 노드 y: road's score
int n, m, deg[1001]{}, res[1001][2]; //res 1: 해당 지점까지의 누적 score 최대값   0: 누적 score 최대값에 해당하는 node 경로

void BFS()
{
	queue<int> q;
	q.push(1); //출발점이 하나로 고정
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (auto cnt : adj[cur])
		{
			deg[cnt.x]--;
			if (res[cur][1] + cnt.y > res[cnt.x][1])
			{
				res[cnt.x][0] = cur;
				res[cnt.x][1] = res[cur][1] + cnt.y;
			} //해당 지점까지 누적 score 최대값 갱신
			if (cnt.x == 1) continue; //종료 조건
			if (deg[cnt.x] == 0)
			{
				q.push(cnt.x);
			}
		}
	}
	cout << res[1][1] << "\n";
	vector<int> tmp;
	tmp.push_back(1);
	int cnt = res[1][0];
	while (1)
	{
		tmp.push_back(cnt);
		if (cnt == 1) break; //1에서 시작해서 1까지 출력해야되므로 1도 push
		cnt = res[cnt][0];
	}
	for (int i = tmp.size() - 1; i >= 0; i--)
	{
		cout << tmp[i] << " ";
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> n >> m;
	while (m--)
	{
		int u, v, k;
		cin >> u >> v >> k;
		deg[v]++;
		adj[u].push_back({ v,k });
	}
	BFS();
}