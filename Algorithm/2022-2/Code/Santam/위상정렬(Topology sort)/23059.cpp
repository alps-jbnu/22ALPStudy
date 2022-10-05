#include <bits/stdc++.h>
#include <unordered_map>
#define x first
#define y second
using namespace std;

unordered_map<string, int> m;
string idx_to_s[400001];
vector<int> adj[400001]{};
vector<pair<int, string>> res; //1: 우선순위에 따라 먼저 정렬
int n, deg[400001]{};

int BFS()
{
	queue<pair<int, int>> q; // x: 아이템의 우선순위, y:해당되는 아이템 id값
	for (int i = 1; i <= m.size(); i++)
	{
		if (deg[i] == 0) q.push({ 0,i });
	}
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		res.push_back({ cur.x,idx_to_s[cur.y] }); //현재 방문한 아이템 res에 삽입
		for (auto cnt : adj[cur.y])
		{
			deg[cnt]--;
			if (deg[cnt] == 0)
			{
				q.push({ cur.x + 1,cnt }); //상위 아이템 구매 가능해졌기에 우선순위 높여서 큐에 삽입
			}
		}
	}
	for (int i = 1; i <= m.size(); i++)
	{
		if (deg[i]) return -1;
	}
	return 0;
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string u, v;
		cin >> u >> v;
		if (m.find(u) == m.end()) {
			m.insert({ u, m.size() + 1 });
			idx_to_s[m.size()] = u;
		}
		if (m.find(v) == m.end()) {
			m.insert({ v, m.size() + 1 });
			idx_to_s[m.size()] = v;
		}  // map에 해당 키 존재여부 확인 및 삽입
		int u_i = m[u], v_i = m[v]; // 입력된 string 키에 해당하는 값 찾기
		deg[v_i]++;
		adj[u_i].push_back(v_i);
	}
	if (BFS() == -1) cout << -1;
	else
	{
		sort(res.begin(), res.end()); //이미 벡터내에 x:우선순위, y:아이템명으로 저장되어 있기에 정렬조건에 맞게 정렬이된다.
		for (auto a : res) { cout << a.y << "\n"; }
	}
	return 0;
}