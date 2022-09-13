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

int d[1005][10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	
	for (int i = 1; i <= n; i++)
	{
		d[i][0] = 1;

		for (int j = 1; j <= 9; j++)
		{
			d[i][j] = (d[i - 1][j] + d[i][j - 1]) % 10007;
		}
	}

	int ans = 0;

	for (int i = 0; i < 10; i++)
	{
		ans = ans + d[n][i];
	}
	cout << ans % 10007 << '\n';
}