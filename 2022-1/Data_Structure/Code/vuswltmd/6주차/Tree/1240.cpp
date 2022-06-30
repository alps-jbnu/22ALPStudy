#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
vector<int> v[1001];
int vis[1001];
int dis[1001][1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n - 1; i++)
	{
		int x, y, z;

		cin >> x >> y >> z;

		v[x].push_back(y);
		v[y].push_back(x);
		dis[x][y] = z;
		dis[y][x] = z;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		for (int i = 0; i < n+1; i++)
		{
			vis[i] = 0;
		}

		queue<pair<int,int>> q;
		q.push({ a, 0 });
		vis[a] = 1;

		while (!q.empty())
		{
			int cur = q.front().first;
			int pp = q.front().second;
			q.pop();

			if (cur == b)
			{
				cout << pp << '\n';
				break;
			}

			for (int nxt : v[cur])
			{
					if (vis[nxt] == 0)
					{
						vis[nxt] = 1;
						q.push({ nxt, pp + dis[cur][nxt] });
					}
			}
		}
	}

}