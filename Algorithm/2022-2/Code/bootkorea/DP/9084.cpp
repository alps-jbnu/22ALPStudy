#include <iostream>
#include <algorithm>
using namespace std;

int T, N, M;
int arr[21];

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		cin >> M;

		int dp[10001] = { 0, };

		dp[0] = 1;

		for (int i = 0; i < N; i++)
		{
			for (int j = arr[i]; j <= M; j++)
			{
				dp[j] += dp[j - arr[i]];
			}
		}

		cout << dp[M] << "\n";
	}

	return 0;
}