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

int arr[1000000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int k;
	cin >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int count = 0;
	int en = 0;
	count = arr[0] % 2;
	int max = 0;

	for (int st = 0; st < n; st++)
	{
		while (en < n - 1 && count + arr[en + 1] % 2 <= k)
		{
			en++;
			count += arr[en] % 2;
		}

		if (max < en - st + 1 - count)
		{
			max = en - st + 1 - count;
		}

		count -= arr[st] % 2;
	}

	cout << max;

}