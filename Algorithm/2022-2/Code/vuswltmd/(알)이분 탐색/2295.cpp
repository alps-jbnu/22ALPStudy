#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
using namespace std;
int two[1000000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[10000];
	int twocount = 0;

	int max;
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			two[twocount] = arr[i] + arr[j];
			twocount++;
		}
	}
	
	sort(two, two + twocount);

	for(int i = n-1; i > 2; i--)
	{
		for (int j = i - 1; j >= 0; j--) 
		{
			if (binary_search(two, two + twocount, arr[i] - arr[j - 1]))
			{
				cout << arr[i];
				return 0;
			}
		}
	}
	
}