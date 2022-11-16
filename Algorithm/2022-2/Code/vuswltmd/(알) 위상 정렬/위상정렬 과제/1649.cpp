#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>
#include <tuple>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;
vector<int> adj[10000];

int deg[10000];
int N, M;
int visit[10000];
int route[10000];
set<int> dest; // 방문할 곳

int st_point;
int en_point;
int num_to_visit;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int st, en;
		cin >> st >> en;
		adj[st].push_back(en);
		deg[en]++;
	}

	cin >> st_point >> en_point >> num_to_visit;
	
	for (int i = 0; i < num_to_visit; i++)
	{
		int destnum; //거쳐가야하는 장소;
		cin >> destnum;
		dest.insert(destnum);
	}
	
	queue<int> q;
	route[st_point] = 1;

	for (int i = 1; i <= N; i++) {
		if (!deg[i]) q.push(i);
	}

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();

		if (dest.find(cur) != dest.end()) visit[cur]++;

		for (auto nxt : adj[cur])
		{
			if (visit[nxt] == visit[cur])
			{
				route[nxt] += route[cur];
			}
			else if (visit[nxt] < visit[cur])
			{
				visit[nxt] = visit[cur];
				route[nxt] = route[cur];
			}

			deg[nxt]--;
			if (deg[nxt] == 0) q.push(nxt);
		}
	}

	if (visit[en_point] == dest.size()) cout << route[en_point];
	else cout << 0;
}

// https://real-012.tistory.com/49 참고 사이트