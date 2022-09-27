#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, result = 0;
int low = 0, high = 0;
int arr[10001];

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int sum = arr[0];

	while (low <= high && high < N)
	{
		if (sum < M)
		{
			sum += arr[++high];
		}
		else if (sum == M)
		{
			result++;
			sum += arr[++high];
		}
		else
		{
			sum -= arr[low++];

			if (low > high && low < N)
			{
				high = low;
				sum = arr[low];
			}
		}
	}

	cout << result;

	return 0;
}