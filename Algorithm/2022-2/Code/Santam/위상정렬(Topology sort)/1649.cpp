#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

vector<int> road[1001];
int vis[1001]{};
int res[1001][2]{}; //0: 해당 지점의 노드까지 오면서 지난 중간지점 개수, 1: 해당 지점노드까지 온 경로개수
int deg[1001]{};
int n, m, s, e, k;

int BFS()
{
	queue<pair<int,int>> q; //x:현재 노드, y: 지나온 중간 지점 개수
	for (int i = 1; i <= n; i++)
	{
		if(deg[i]==0) q.push({i,vis[i]});
	}
	res[s][1] = 1; //시작점도 무조건 지나가야되는 중요지점(이곳을 거치지 않으면 경로 카운트가 안됨)
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (auto cnt : road[cur.x])
		{
			deg[cnt]--;
			if (res[cnt][0] == cur.y + vis[cnt]) res[cnt][1] += res[cur.x][1]; //중요지점개수가 같을때만 카운트
			if (res[cnt][0] < cur.y + vis[cnt])
			{
				res[cnt][0] = cur.y + vis[cnt];
				res[cnt][1] = res[cur.x][1]; //중요지점을 가장 많이 지난 것이 오도록 갱신
			}
			if (cnt == e) continue;
			if (deg[cnt] == 0) q.push({ cnt,res[cnt][0] });
		}
	}
	if (res[e][0] != k) return 0; //필수 지점을 다 못 통과했을때
	return res[e][1]; 
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		deg[v]++;
		road[u].push_back(v);
	}
	cin >> s >> e >> k;
	for (int i = 0; i < k; i++)
	{
		int a;
		cin >> a;
		vis[a] = true;
	}
	cout << BFS();
	return 0;
}