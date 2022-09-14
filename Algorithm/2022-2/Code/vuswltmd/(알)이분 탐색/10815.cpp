#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
using namespace std;

int arr1[500000];
int arr2[500000];
int arr3[500000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}

	sort(arr1, arr1 + n);

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;

		arr2[i] = num;
		arr3[i] = num;
	}

	for (int i = 0; i < m; i++)
	{
		if (binary_search(arr1, arr1 + n, arr2[i]))
		{
			cout << 1 << ' ';
		}
		else
		{
			cout << 0 << ' ';
		}
	}
	

}