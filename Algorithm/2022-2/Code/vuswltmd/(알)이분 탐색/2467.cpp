#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
using namespace std;

int arr[100005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int min1 = 1000000000;
	int min2 = 1000000000;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		int idx = lower_bound(arr, arr + n, -arr[i]) - arr;

		if (idx < n && idx != i && abs(arr[idx] + arr[i]) < abs(min1 + min2))
		{
			min1 = arr[idx];
			min2 = arr[i];
		}
		else if(idx + 1 < n && idx + 1 != i && abs(arr[idx+1] + arr[i]) < abs(min1 + min2))
		{
			min1 = arr[idx+1];
			min2 = arr[i];
		}
		else if (idx != 0 && idx-1 != i && abs(arr[idx - 1] + arr[i]) < abs(min1 + min2))
		{
			min1 = arr[idx - 1];
			min2 = arr[i];
		}
	}

	if (min1 > min2) swap(min1, min2);
	cout << min1 << ' ' << min2;
}