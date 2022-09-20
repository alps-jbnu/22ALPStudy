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
using namespace std;

vector<int> adj[32005];
int deg[32005];
int n;
int m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int num1, num2;
		cin >> num1 >> num2;

		adj[num1].push_back(num2);
		deg[num2]++;
	}

	queue<int> q;
	vector<int> result;

	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0) q.push(i);
	}

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		result.push_back(cur);

		for (int nxt : adj[cur])
		{
			deg[nxt]--;
			if (deg[nxt] == 0) q.push(nxt);
		}
	}

	for (auto a : result)
	{
		cout << a << ' ';
	}
	
}