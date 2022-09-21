#include <iostream>
#include <algorithm>
using namespace std;

int N;
int Score[301];
int dp[301];

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> Score[i];
	}

	dp[0] = Score[0];
	dp[1] = max(Score[0] + Score[1], Score[1]);
	dp[2] = max(Score[0] + Score[2], Score[1] + Score[2]);

	for (int i = 3; i < N; i++)
	{
		dp[i] = max(dp[i - 2] + Score[i], dp[i - 3] + Score[i - 1] + Score[i]);
	}

	cout << dp[N - 1] << "\n";

	return 0;
}