#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int arr[100005];
long long d[100005];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		d[i] = arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		d[i] = max(d[i], d[i - 1] + arr[i]);
	}

	int mx = d[1];
	for (int i = 2; i <= n; i++)
	{
		if (d[i] > mx)
		{
			mx = d[i];
		}
	}
	cout << mx;


}