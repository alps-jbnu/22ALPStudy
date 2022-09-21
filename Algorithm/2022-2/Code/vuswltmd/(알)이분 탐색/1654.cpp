#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
using namespace std;

int arr[10000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int k;
	int n;

	cin >> k >> n;

	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
	}

	long long st = 1;
	long long en = 0x7fffffff;
	long long mid;

	while (st < en)
	{
		long long cur = 0;
		mid = (st + en + 1) / 2;

		for (int i = 0; i < k; i++)
		{
			cur += arr[i] / mid;
		}

		if (cur >= n)
		{
			st = mid;
		}
		else
		{
			en = mid - 1;
		}
	}

	cout << st;
}