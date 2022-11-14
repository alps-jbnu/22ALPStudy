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

bool vis[1005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int school_MW[1005];
	for (int i = 0; i <= 1004; i++)
	{
		school_MW[i] = -1;
	}

	int N, M;
	int u, v, d;

	vector< pair<int, int> > adj[20005];


	priority_queue< tuple<int, int, int>,
		vector<tuple<int, int, int>>,
		greater<tuple<int, int, int>> > pq;

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		char MW;
		cin >> MW;

		if (MW == 'M')
		{
			school_MW[i] = 1;
		}
		else
		{
			school_MW[i] = 0;
		}
	}

	for (int i = 1; i <= M; i++)
	{
		cin >> u >> v >> d;
		adj[u].push_back({ d, v });
		adj[v].push_back({ d, u });
	}

	vis[1] = 1;

	for (auto nxt : adj[1])
		pq.push({ nxt.first, 1, nxt.second });

	int cnt = 0;
	int ans = 0;

	while (!pq.empty()) {
		int a, b, c;
		tie(c, a, b) = pq.top(); pq.pop();

		if (vis[b]) continue;
		if (school_MW[b] == school_MW[a]) continue;

		vis[b] = 1;
		ans += c;
		cnt++;

		for (auto nxt : adj[b])
		{
			if (!vis[nxt.second])
				pq.push({ nxt.first, b, nxt.second });
		}
	}

	if (cnt == N - 1)
	{
		cout << ans;
	}
	else
	{
		cout << -1;
	}
}