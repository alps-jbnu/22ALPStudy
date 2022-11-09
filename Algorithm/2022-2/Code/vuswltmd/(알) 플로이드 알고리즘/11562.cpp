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
#include <unordered_map>
using namespace std;

int n, m;
int d[255][255];
const int INF = 999999999;
int k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			d[i][j] = INF;
		}
	}

	for (int j = 1; j <= n; j++)
	{
		d[j][j] = 0;
	}


	for (int i = 1; i <= m; i++)
	{
		int u, v, b;
		cin >> u >> v >> b;

		if (b == 0)
		{
			d[u][v] = 0;
			d[v][u] = 1;
		}
		else if (b == 1)
		{
			d[u][v] = 0; 
			d[v][u] = 0; 
		}
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (d[i][k] + d[k][j] < d[i][j])
				{
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	cin >> k;

	while (k--)
	{
		int a, b;
		cin >> a >> b;

		cout << d[a][b] << '\n';
	}
}
