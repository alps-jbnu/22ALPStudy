#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> vec;
vector<int> dp;

int main()
{
	cin >> N;
	vec.resize(N + 1);
	dp.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> vec[i];
	}
	dp[1] = vec[1];

	if (N > 1) dp[2] = vec[1] + vec[2];
	if (N > 2)
	{
		for (int i = 3; i <= N; i++)
		{
			dp[i] = max(dp[i - 1], dp[i - 2] + vec[i]);
			dp[i] = max(dp[i], dp[i - 3] + vec[i - 1] + vec[i]);
		}
	}

	cout << dp[N];

	return 0;
}