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

const int INF = 30 * 100  * 100;
int d[105][105];
int item[105];
int n, m, r;
int ans[105];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			d[i][j] = INF;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> item[i];
	}

	for (int i = 1; i <= r; i++)
	{
		int a, b, leng;
		cin >> a >> b >> leng;

		d[a][b] = leng;
		d[b][a] = leng;
	}

	for (int i = 1; i <= n; i++)
	{
		d[i][i] = 0;
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

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			//cout << "i: " << i << "j: "<< j << ' ' << d[i][j] << '\n';
			if(d[i][j] <= m)
			{
				ans[i] = ans[i] + item[j];
			}
		}
		//ans[i] += item[i];
		//cout << ans[i] << '\n';
	}

	sort(ans, ans + n + 1);

	cout << ans[n];

}
