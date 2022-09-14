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

int arr[100];

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

	int count = 0;

	for (int i = n - 1; i > 0; i--)
	{
		if (arr[i] <= arr[i - 1])
		{
			int num = arr[i - 1] - arr[i] + 1;
			count += num;

			arr[i - 1] = arr[i - 1] - num;
		}
	}

	cout << count;
}