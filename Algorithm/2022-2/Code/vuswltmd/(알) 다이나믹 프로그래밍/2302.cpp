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

int d[45];
vector<int> vip = {0};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int m;
	cin >> m;

	for (int i = 1; i <= m; i++)
	{
		int num;
		cin >> num;

		vip.push_back(num);
	}
	vip.push_back(n + 1);

	d[0] = 1;
	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		d[i] = d[i - 1] + d[i - 2];
	}

	int ans = 1;

	for (int i = 1; i < (int)vip.size(); i++)
	{
		ans = ans * d[vip[i] - vip[i - 1] - 1];
	}

	cout << ans;

}