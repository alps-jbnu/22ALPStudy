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
long long d[1000005];
long long num[1000005];
int max_num = -1;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	d[1] = 1;
	d[2] = 2;
	d[3] = 4;

	for (int i = 1; i <= T; i++)
	{
		cin >> num[i];

		if (num[i] > max_num)
		{
			max_num = num[i];
		}
	}

	for (int i = 4; i <= max_num; i++)
	{
		d[i] = d[i - 2] + d[i - 3] + d[i - 1];
	}

	for (int i = 1; i <= T; i++)
	{
		cout << d[num[i]] << '\n';
	}

}