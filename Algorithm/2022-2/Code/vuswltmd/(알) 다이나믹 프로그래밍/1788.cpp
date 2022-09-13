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

int d[2000005];
int mod = 1000000000;

// 1 ~ (1000000 -1) 까지 양수
// 1000000 은 0
// 1000001 ~ (2000000 - 1) 까지 음수

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	if (n == 0)
	{
		cout << 0 << '\n';
		cout << 0 % mod<< '\n';
		return 0;
	}
	else if (n > 0)
	{
		d[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			d[i] = d[i - 1] + d[i - 2];
		}

		cout << 1 << '\n';
		cout << d[n] % mod << '\n';
	}
	else if (n < 0)
	{
		d[1000000] = 0;
		d[1000001] = 1;

		for (int i = 1000002; i <= 1000000 + (n * -1); i++)
		{
			d[i] = d[i - 2] - d[i - 1];
		}
		
		if (d[(- 1 * n) + 1000000] > 0)
		{
			cout << 1 << '\n';
			cout << d[(-1 * n) + 1000000] % mod << '\n';
		}
		else
		{
			cout << -1 << '\n';
			cout << ( - 1 * d[(-1 * n) + 1000000])% mod << '\n';
		}
	}

}