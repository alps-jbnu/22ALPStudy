#include <bits/stdc++.h>
using namespace std;

int i, j, cnt = 0;
int n1, n2;
int dp[1001][1001];
char str1[1001], str2[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str1 >> str2;

	n1 = strlen(str1);
	n2 = strlen(str2);

	for (i = 1; i <= n1; i++)
	{
		for (j = 1; j <= n2; j++)
		{
			if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[n1][n2] << "\n";

	return 0;
}