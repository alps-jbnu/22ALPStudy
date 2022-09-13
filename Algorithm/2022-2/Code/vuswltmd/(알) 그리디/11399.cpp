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

int arr[1000];

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

	int sum = 0;
	int sum2 = 0;

	for (int i = 0; i < n; i++)
	{
		sum = sum + arr[i];
		sum2 = sum2 + sum;
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << sum2;
}