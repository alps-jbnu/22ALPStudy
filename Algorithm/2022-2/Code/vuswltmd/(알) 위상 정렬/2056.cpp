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

vector<int> adj[10005];
int deg[10005];
int time1[10005];
int min_time[10005];

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> time1[i];

		int par_count;
		cin >> par_count;

		for (int j = 0; j < par_count; j++)
		{
			int par;
			cin >> par;

			adj[par].push_back(i);
			deg[i]++;
		}
	}

	queue<int> Q;

	int max1 = 0;

	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0)
		{
			Q.push(i);
			min_time[i] = time1[i];
		}	
	}

	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();

		for (auto nxt : adj[cur])
		{
			deg[nxt]--;

			if (min_time[nxt] < time1[nxt] + min_time[cur])
			{
				min_time[nxt] = time1[nxt] + min_time[cur];
			}

			if (deg[nxt] == 0)
			{
				
				Q.push(nxt);
			}
		}
	}

	cout << *max_element(min_time, min_time+n+1) << '\n';
}