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

vector<int> adj[32005];
int deg[32005];
pair<int, int> p[100005];
int n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);

		deg[b]++;
	}

	priority_queue<int, vector<int>, greater<int>> Q;

	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0)
		{
			Q.push(i);
		}
	}

	while (!Q.empty())
	{
		int cur = Q.top(); Q.pop();

		cout << cur << ' ';

		for (auto nxt : adj[cur])
		{
			deg[nxt]--;
			if (deg[nxt] == 0) Q.push(nxt);
		}
	}

}