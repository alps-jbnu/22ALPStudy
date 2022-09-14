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

int arr[10];

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

	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] > k)
		{
			continue;
		}
		else
		{
			count = count + (k / arr[i]);

			k = k - ( arr[i] * (k / arr[i]));
		}
		
	}

	cout << count;

}