#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
using namespace std;

string arr1[1000000];
int arr2[1000000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr1[i];

		reverse(arr1[i].begin(), arr1[i].end());

		arr2[i] = stoi(arr1[i]);
	}

	sort(arr2, arr2 + n);

	for (int i = 0; i < n; i++)
	{
		cout << arr2[i] << '\n';
	}
}