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

int n, m;
vector<pair<int, int>> adj[1005];
double v[1005][1005];
bool chk[1005];
double cost = 0;
int cnt = 0;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;

		adj[i].push_back({ x, y });
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;

			v[i][j] = sqrt(pow(adj[i][0].first - adj[j][0].first, 2.0) + pow(adj[i][0].second - adj[j][0].second, 2.0));
		}
	}

	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;

		v[x][y] = 0;
		v[y][x] = 0;
	}

	priority_queue<pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>> > pq;

	chk[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		int next = i;
		double nextcost = v[1][i];

		pq.push({ nextcost, next });
	}

	while (!pq.empty())
	{
		int now, nowcost;
		tie(nowcost, now) = pq.top(); pq.pop();

		if (chk[now]) continue;

		chk[now] = 1;
		cost += nowcost;
		cnt++;

		for (int i = 1; i <= n; i++)
		{
			if (now == i) continue;
			int nxt = i;
			double nextcost = v[now][i];

			if (chk[nxt] == 0)
			{
				pq.push({ nextcost, nxt });
			}
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << cost << '\n';
}
