#include <bits/stdc++.h>
const int MAX = 100 + 1;
using namespace std;

int i, j, k, cnt = 0;
int dp[MAX][MAX][MAX];
char in_1[MAX], in_2[MAX], in_3[MAX];

int main()
{
	cin >> in_1 >> in_2 >> in_3;

	int x = strlen(in_1);
	int y = strlen(in_2);
	int z = strlen(in_3);

	for (i = 1; i <= x; i++)
	{
		for (j = 1; j <= y; j++)
		{
			for (k = 1; k <= z; k++)
			{
				if (in_1[i - 1] == in_2[j - 1] && in_2[j - 1] == in_3[k - 1])
				{
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else
				{
					int case1 = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
					int case2 = max(dp[i - 1][j - 1][k], max(dp[i][j - 1][k - 1], dp[i - 1][j][k - 1]));
					dp[i][j][k] = max(case1, case2);
				}
			}
		}
	}

	cout << dp[x][y][z] << "\n";

	return 0;
}