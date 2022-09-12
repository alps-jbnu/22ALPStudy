#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

long long arr[1005];
long long d[1005];
int n;


int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		d[i] = arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (arr[i] > arr[j])
			{
				d[i] = max(d[i], d[j] + arr[i]);
			}
		}
	}

	cout << *max_element(d, d + n+1);
}