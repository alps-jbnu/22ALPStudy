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

vector<int> adj[1005];
int deg[1005];
int n;
int m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;

	while (m--)
	{
		int l;
		cin >> l;
		int pre;
		for (int i = 1; i <= l; i++)
		{
			int num;
			cin >> num;

			if (i == 1)
			{
				pre = num;
				continue;
			}

			adj[pre].push_back(num);
			pre = num;
			deg[num]++;
		}
	}

	queue<int> Q;
	vector<int> result;

	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0)
		{
			Q.push(i);
		}
	}

	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		result.push_back(cur);

		for (auto nxt : adj[cur])
		{
			deg[nxt]--;
			if (deg[nxt] == 0)
			{
				Q.push(nxt);
			}
		}
	}

	if (result.size() != n)
	{
		cout << '0' << '\n';
	}

	else
	{
		for (auto a : result)
		{
			cout << a << '\n';
		}
	}
}