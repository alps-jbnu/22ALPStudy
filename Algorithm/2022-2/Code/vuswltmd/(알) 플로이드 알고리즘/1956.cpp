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

const int INF = 400 * 10000 * 10;
int d[405][405];
int V, E;
int ans = INF;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E;

	for (int i = 1; i <= E; i++)
	{
		for (int j = 1; j <= E; j++)
		{
			d[i][j] = INF;
		}
	}

	for (int i = 1; i <= E; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;

		d[a][b] = cost;
	}

	for (int k = 1; k <= V; k++)
	{
		for (int i = 1; i <= V; i++)
		{
			for (int j = 1; j <= V; j++)
			{
				if (d[i][k] + d[k][j] < d[i][j])
				{
					d[i][j] = d[i][k] + d[k][j];
					if (i == j)
					{
						ans = min(ans, d[i][j]);
					}
				}
					
			}
		}
	}

	if (ans == INF)
	{
		cout << -1 << '\n';
	}
	else
	cout << ans;
}
