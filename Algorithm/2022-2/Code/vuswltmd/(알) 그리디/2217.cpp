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

	sort(arr, arr + n);

	int max = 0;

	for (int i = 0; i < n; i++)
	{
		if (max < arr[i] * (n-i))
		{
			max = arr[i] * (n - i);
		}
	}

	cout << max;
}