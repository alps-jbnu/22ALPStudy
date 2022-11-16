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

	sort(arr, arr + n);

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		if (binary_search(arr, arr + n, num))
		{
			cout << '1' << '\n';
		}
		else
		{
			cout << '0' << '\n';
		}
	}
}