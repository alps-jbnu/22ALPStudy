#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

long long tr[505][505];
long long d[505][505];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> tr[i][j];
		}
	}

	d[1][1] = tr[1][1];
	d[2][1] = d[1][1] + tr[2][1];
	d[2][2] = d[1][1] + tr[2][2];

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + tr[i][j];
		}
	}
	int mx = d[n][1];
	for (int i = 2; i <= n; i++)
	{
		if (mx < d[n][i])
		{
			mx = d[n][i];
		}
	}

	cout << mx;
}