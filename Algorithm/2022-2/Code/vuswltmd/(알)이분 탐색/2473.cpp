#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
using namespace std;

long long arr[5000];
vector<long long> arr2;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	long long min1 = 0x7f7f7f7f7f7f;
	long long min2 = 0x7f7f7f7f7f7f;
	long long min3 = 0x7f7f7f7f7f7f;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int idx = lower_bound(arr, arr + n, -1 * (arr[i] + arr[j])) - arr;

			for (int k = -2; k <= 2; k++)
			{
				if (idx + k != i && idx + k != j && 
					idx + k < n && idx + k > 0 &&
					abs(arr[idx + k] + arr[i] + arr[j]) < abs(min1 + min2 + min3))
				{
					min1 = arr[idx + k];
					min2 = arr[i];
					min3 = arr[j];
				}
			}
			
		}
	}

	arr2.push_back(min1);
	arr2.push_back(min2);
	arr2.push_back(min3);

	sort(arr2.begin(), arr2.end());

	for (auto i = arr2.begin(); i < arr2.end(); i++)
	{
		cout << *i << ' ';
	}

}