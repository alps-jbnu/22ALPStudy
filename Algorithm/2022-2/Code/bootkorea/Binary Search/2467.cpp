#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 100000 + 1
using namespace std;

int N;
long long lnum, rnum, result = 0;
long long arr[MAX];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int l = 0;
	int r = N - 1;

	int result = abs(arr[l] + arr[r]);
	lnum = arr[l];
	rnum = arr[r];

	while (l < r)
	{
		int temp = abs(arr[l] + arr[r]);

		if (result > temp)
		{
			result = temp;
			lnum = arr[l];
			rnum = arr[r];
		}

		if (arr[l] + arr[r] < 0) l++;
		else r--;
	}

	cout << lnum << " " << rnum;

	return 0;
}