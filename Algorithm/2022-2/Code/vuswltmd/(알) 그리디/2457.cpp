#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

vector<pair<int, int>> f;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int sm, sd, em, ed;
		cin >> sm >> sd >> em >> ed;

		f.push_back({ sm * 100 + sd, em * 100 + ed });
	}

	int time = 301;
	int count = 0;

	while (time < 1201)
	{
		int next = time;

		for (int i = 0; i < n; i++)
		{
			if (f[i].first <= time && f[i].second > next)
			{
				next = f[i].second;
			}
		}

		if (next == time)
		{
			cout << 0;
			return 0;
		}

		time = next;
		count++;
	}

	cout << count;

}