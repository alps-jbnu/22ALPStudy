#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {

	int i, j, cnt = 0;
	int dp[1001][1001];
	char str1[1001], str2[1001];

	cin >> str1 >> str2;

	int n1 = strlen(str1);
	int n2 = strlen(str2);

	for (i = 1; i <= n1; i++)
	{
		for (j = 1; j <= n2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[n1][n2] << "\n";

	return 0;
}