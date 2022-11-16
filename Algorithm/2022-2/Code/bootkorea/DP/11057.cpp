#include <iostream>
#define MOD 10007
using namespace std;

int N, result = 0;
int dp[1001][10] = { 0, };

int main()
{
	cin >> N;

	for (int i = 0; i < 10; i++)
	{
		dp[0][i] = 1;
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = j; k < 10; k++)
			{
				dp[i][k] += dp[i - 1][j];
				dp[i][k] %= MOD;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		result += dp[N - 1][i];
	}

	result %= MOD;
	cout << result;

	return 0;
}