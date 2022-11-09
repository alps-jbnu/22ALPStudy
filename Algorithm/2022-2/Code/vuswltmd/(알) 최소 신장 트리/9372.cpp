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

int T;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;

	while (T--)
	{
		int n, m;
		cin >> n >> m;

		vector<pair<int, int>> adj[1005];
		bool chk[1005] = { 0, };

		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;

			adj[a].push_back({ 1, b });
			adj[b].push_back({ 1, a });
		}

		int cnt = 0;
		int ans = 0;

		priority_queue< tuple<int, int, int>,
			vector<tuple<int, int, int>>,
			greater<tuple<int, int, int>> > pq;

		chk[1] = 1;


		for (auto nxt : adj[1])
		{
			pq.push({nxt.first, 1, nxt.second});
		}

		while (cnt < n - 1)
		{
			int cost, a, b;
			tie(cost, a, b) = pq.top(); pq.pop();

			if (chk[b]) continue;
			ans += cost;
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

		cout << ans << '\n';

	}
}
