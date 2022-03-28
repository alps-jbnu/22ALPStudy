#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iterator>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

int n, m;
int u, v;

vector<int> vec[1002];
int vis[1002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;

		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	queue<int> Q;
	int num = 0;

	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == 0)
		{
			num++;
			Q.push({ i });

			while (!Q.empty())
			{
				int cur = Q.front(); Q.pop();
				
				for (auto nxt : vec[cur])
				{
					if (vis[nxt] == 0)
					{
						Q.push(nxt);
						vis[nxt] = 1;
					}
				}
				
			}
		}


	}

	cout << num;
}