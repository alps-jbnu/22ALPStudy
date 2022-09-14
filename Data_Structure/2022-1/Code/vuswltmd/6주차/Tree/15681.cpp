#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>
#include <tuple>
using namespace std;

vector<int> adj[100005];
int size1[100005];

int dfs(int cur, int par)
{
	size1[cur] = 1;
	for (auto nxt : adj[cur])
	{
		if (par == nxt) continue;
		size1[cur] += dfs(nxt, cur);
	}
	return size1[cur];
}

int main()
{	
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, r, q;

	cin >> n >> r >> q;

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(r, 0);

	while (q--)
	{
		int t; 
		cin >> t;
		cout << size1[t] << '\n';
	}
}