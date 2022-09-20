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

int N;
vector<pair<int, int>> adj[1005];
bool chk[1005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int cost; cin >> cost;

			adj[i].push_back({ cost, j });
			adj[j].push_back({ cost, i });
		}
	}

	int cnt = 0;
	long long ans = 0;

	priority_queue<tuple<int, int, int>,
		vector<tuple<int, int, int>>,
		greater<tuple<int, int, int>> > pq;

	chk[1] = 1;

	for (auto nxt : adj[1])
	{
		pq.push({ nxt.first, 1, nxt.second });
	}

	while (cnt < N - 1)
	{
		int cost, a, b;
		tie(cost, a, b) = pq.top(); pq.pop();
		
		//if (a == b) continue;
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

	cout << ans;

}
