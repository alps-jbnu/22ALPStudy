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

	int n;
	cin >> n;

	long long count = 0;
	int temp;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr+n);

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i+1; j < n - 1; j++)
		{
			temp = -1 * (arr[i] + arr[j]);

			int idx = (upper_bound(arr + j + 1, arr + n, temp) - arr);
			int idx2 = (lower_bound(arr + j + 1, arr+n, temp)- arr);
			count += (idx - idx2);
		}
	}

	cout << count;
}