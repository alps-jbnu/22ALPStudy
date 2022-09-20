#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, result = 0;
int arr[1001];
int dp[1001];
int num[1001];
vector<int> vec;

void Rescan(int idx)
{
	if (idx == -1)
	{
		return;
	}
	vec.push_back(arr[idx]);

	Rescan(num[idx]);
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
		num[i] = -1;

		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
				num[i] = j;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		result = max(result, dp[i]);

	}

	cout << result << "\n";

	for (int i = 0; i < N; i++)
	{
		if (dp[i] == result)
		{
			vec.push_back(arr[i]);
			Rescan(num[i]);

			break;
		}
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}

	return 0;
}