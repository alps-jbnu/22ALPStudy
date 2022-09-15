#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;
long long t[1500000];
long long p[1500000];
long long d[1500000];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> t[i] >> p[i];
	}

	for (int i = n; i >= 1; i--)
	{
		if(i + t[i] <= n+1)
		{
			d[i] = max(d[i+t[i]] + p[i], d[i+1]);
		}
		else d[i] = d[i + 1];
	}

	cout << d[1];
}