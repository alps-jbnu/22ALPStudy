#include <iostream>
using namespace std;

int main()
{
	int T, N;
	long long dp[101];
	dp[0] = dp[1] = dp[2] = 1;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;

		for (int i = 3; i < N; i++)
		{
			dp[i] = dp[i - 3] + dp[i - 2];
		}

		cout << dp[N - 1] << "\n";
	}

	return 0;
}