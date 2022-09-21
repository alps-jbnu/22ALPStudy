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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		vector<int> adj[1005];
		int min_time[1005] = { 0, };
		int t[1005] = { 0, };
		int deg[1005] = { 0, };

		int N, K;
		cin >> N >> K;

		for (int i = 1; i <= N; i++)
		{
			cin >> t[i];
		}

		for (int i = 1; i <= K; i++)
		{
			int a, b;
			cin >> a >> b;

			adj[a].push_back(b);
			deg[b]++;
		}

		queue<int> q;

		for (int i = 1; i <= N; i++)
		{
			if (deg[i] == 0)
			{
				q.push(i);
				min_time[i] = t[i];
			}
		}

		while (!q.empty())
		{
			int cur = q.front(); q.pop();

			for (auto nxt : adj[cur])
			{
				deg[nxt]--;

				if (min_time[nxt] < min_time[cur] + t[nxt])
				{
					min_time[nxt] = min_time[cur] + t[nxt];
				}

				if (deg[nxt] == 0)
				{
					q.push(nxt);
				}
			}
		}

		int W;
		cin >> W;

		cout << min_time[W] << '\n';
	}

}