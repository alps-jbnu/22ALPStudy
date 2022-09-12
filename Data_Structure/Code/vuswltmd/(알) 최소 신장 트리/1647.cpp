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
using namespace std;

int N, M;
vector<pair<int, int>> adj[100005];
bool chk[100005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= M; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;

		adj[a].push_back({ cost, b });
		adj[b].push_back({ cost, a });
	}

	int cnt = 0;
	long long ans = 0;

	priority_queue< tuple<int, int, int>,
		vector<tuple<int, int, int>>,
		greater<tuple<int, int, int>> > pq;


	chk[1] = 1;
	int most_cost = 0;

	for (auto nxt : adj[1])
	{
		pq.push({ nxt.first, 1, nxt.second });
	}

	while (cnt < N - 1)
	{
		int a, b, cost;

		tie(cost, a, b) = pq.top(); pq.pop();

		if (chk[b]) continue;
		ans += cost;
		if (cost > most_cost)
		{
			most_cost = cost;
		}
		chk[b] = 1;
		cnt++;

		for (auto nxt : adj[b])
		{
			if (!chk[nxt.second])
			{
				pq.push({ nxt.first, b, nxt.second });
			}
		}

	}

	cout << ans - most_cost << '\n';

}
