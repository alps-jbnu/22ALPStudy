#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000 + 1
#define INF 987654321
using namespace std;

int N, S, len = INF;
int arr[MAX];
int low = 0, high = 0;

int main()
{
	cin >> N >> S;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int sum = arr[0];

	while (low <= high && high < N)
	{
		if (sum < S)
		{
			sum += arr[++high];
		}
		else if (sum == S)
		{
			len = min(len, (high - low + 1));
			sum += arr[++high];
		}
		else if (sum > S)
		{
			len = min(len, (high - low + 1));
			sum -= arr[low++];
		}
	}

	if (len == INF)
	{
		cout << 0;
	}
	else cout << len;

	return 0;
}