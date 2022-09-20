#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 5000 + 1
using namespace std;

int N;
long long int lnum, mnum, rnum, l, result = 3e9;
long long int arr[MAX];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);

	for (int i = 0; i < N - 2; i++)
	{
		l = arr[i];
		int m = i + 1;
		int r = N - 1;

		while (m < r)
		{
			long long int temp = l + arr[m] + arr[r];

			if (result > abs(temp))
			{
				result = abs(temp);

				lnum = l;
				mnum = arr[m];
				rnum = arr[r];
			}

			if (temp < 0) m++;
			else if (temp > 0) r--;
			else
			{
				i = N;
				break;
			}
		}
	}

	cout << lnum << " " << mnum << " " << rnum;

	return 0;
}