#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
using namespace std;
int arr[100000];

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

	int min1 = 1000000000;
	int min2 = 1000000000;

	for (int i = 0; i < n; i++)
	{
		int index1 = lower_bound(arr, arr + n, -arr[i]) - arr;

		if (index1 + 1 < n && index1 + 1 != i && abs(arr[i] + arr[index1 + 1]) < abs(min1 + min2))
		{
			min1 = arr[i];
			min2 = arr[index1 + 1];
		}
		if (index1 - 1 >= 0 && i != index1 - 1 && abs(arr[i] + arr[index1 - 1]) < abs(min1 + min2))
		{
			min1 = arr[i];
			min2 = arr[index1 - 1];
		}
		if (index1 < n && index1 != i && abs(arr[i] + arr[index1]) < abs(min1 + min2))
		{
			min1 = arr[i];
			min2 = arr[index1];
		}
	}
	

	cout << min1 + min2;

	//int index3 = index1 - 1;
}