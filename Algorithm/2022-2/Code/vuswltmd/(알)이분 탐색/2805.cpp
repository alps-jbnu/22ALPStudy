#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
using namespace std;

int arr[1000002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	long long st = 0;
	long long en = *max_element(arr, arr + n);

	while (st < en)
	{
		long long cur = 0;
		long long mid = (st + en + 1) / 2;

		for (int i = 0; i < n; i++)
		{
			if (arr[i] > mid)
			{
				cur += (arr[i] - mid);
			}
			else
			{
				continue;
			}
		}

		if (cur >= m)
		{
			st = mid;
		}
		else
		{
			en = mid-1;
		}
	}

	cout << st;
}