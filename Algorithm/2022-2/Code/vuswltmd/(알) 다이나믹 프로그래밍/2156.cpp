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

int a[10005];
long long d[10005][3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	d[1][1] = a[1];

	for (int i = 2; i <= n; i++)
	{
		d[i][0] = max({ d[i - 1][0], d[i - 1][1], d[i - 1][2] });
		d[i][1] = d[i - 1][0] + a[i];
		d[i][2] = d[i - 1][1] + a[i];
	}
	
	long long ans = -1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			if (d[i][j] > ans)
			{
				ans = d[i][j];
			}
		}
	}

	cout << ans;
}