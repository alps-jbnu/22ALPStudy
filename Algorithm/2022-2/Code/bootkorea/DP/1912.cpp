#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, result = 0;
vector<int> vec, dp;

int main()
{
	cin >> N;
	vec.resize(N); dp.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	dp[0] = vec[0];
	result = dp[0];

	for (int i = 1; i < N; i++)
	{
		dp[i] = max(dp[i - 1] + vec[i], vec[i]);
		result = max(result, dp[i]);
	}

	cout << result;

	return 0;
}