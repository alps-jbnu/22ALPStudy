#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		long long d[105];
		d[1] = 1;
		d[2] = 1;
		d[3] = 1;

		for (int i = 4; i <= n; i++)
		{
			d[i] = d[i - 2] + d[i - 3];
		}

		cout << d[n] << '\n';
	}

}