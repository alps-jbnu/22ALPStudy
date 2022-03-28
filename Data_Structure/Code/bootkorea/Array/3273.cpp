#include<iostream>
#include<algorithm>
#define MAX 100000 + 1
using namespace std;

int n, x, l, r, result = 0;
int arr[MAX];

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> x;

	sort(arr, arr + n);
	l = 0;
	r = n - 1;

	while (l < r)
	{
		if (arr[l] + arr[r] == x)
		{
			result++;
			r--;
		}
		else if (arr[l] + arr[r] > x)
		{
			r--;
		}
		else
		{
			l++;
		}
	}

	cout << result;
}