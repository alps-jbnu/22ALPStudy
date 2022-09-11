#include <bits/stdc++.h>
const int MAX = 1000 + 1;
using namespace std;

int N;
int dp[MAX] = { 0, 1, 0, 1, 1, 1, };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 6; i <= N; i++)
	{
		dp[i] = 0;
		if (dp[i - 1] == 0) dp[i] = 1;
		if (dp[i - 3] == 0) dp[i] = 1;
		if (dp[i - 4] == 0) dp[i] = 1;
	}

	if (dp[N] == 1) cout << "SK";
	else cout << "CY";

	return 0;
}