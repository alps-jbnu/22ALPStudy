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
vector<pair<int, int>> adj[1005];
bool chk[1005];
bool chk2[1005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i <= M; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;

		adj[a].push_back({ cost, b });
		adj[b].push_back({ cost, a });
	}

	int cnt = 0;
	int cnt2 = 0;

	long long ans = 0;
	long long ans2 = 0;

	priority_queue<tuple<int, int, int>,
		vector<tuple<int, int, int>>,
		greater<tuple<int, int, int>> > pq;

	priority_queue<tuple<int, int, int>> pq2;

	chk[0] = 1;
	chk2[0] = 1;

	for (auto nxt : adj[0])
	{
		pq.push({ nxt.first, 0, nxt.second });
	}

	for (auto nxt : adj[0])
	{
		pq2.push({ nxt.first, 0, nxt.second });
	}

	while (cnt < N )
	{
		int a, b, cost;

		tie(cost, a, b) = pq.top(); pq.pop();

		if (chk[b]) continue;
		if (cost == 0)
		{
			ans += 1;
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

	while (cnt2 < N )
	{
		int a, b, cost;
		tie(cost, a, b) = pq2.top(); pq2.pop();

		if (chk2[b]) continue;
		if (cost == 0)
		{
			ans2 += 1;
		}
		chk2[b] = 1;
		cnt2++;

		for (auto nxt : adj[b])
		{
			if (!chk2[nxt.second])
			{
				pq2.push({ nxt.first, b, nxt.second });
			}
		}
	}

	cout << (ans*ans) - (ans2 * ans2)<< '\n';

}
