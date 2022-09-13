#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
using namespace std;

long long arr[100000];

int main()
{
	int n;
	long long m;
	int count = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int st = 0;
	int en = 0;
	int min = 210000000;

	while (en < n)
	{
		if (arr[en] - arr[st] < m)
		{
			en++;
		}
		else if (arr[en] - arr[st] >= m)
		{
			if (min > arr[en] - arr[st])
			{
				min = arr[en] - arr[st];
			}
			st++;
		}
	}

	cout << min;
}