#include <bits/stdc++.h>
#define MAX 2500 + 1
#define INF 987654321
using namespace std;

int N = 0, result = 0;
int dp[MAX][MAX], arr[MAX];
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s; s.insert(0, " ");
	N = s.size();

	for (int i = 1; i <= N; i++) // 펠린드롬
	{
		dp[i][i] = 1;
	}

	for (int i = 1; i < N; i++) // 펠린드롬
	{
		if (s[i] == s[i + 1])
			dp[i][i + 1] = 1;
	}

	for (int i = 2; i < N; i++) // 펠린드롬
	{
		for (int j = 1; j <= N - i; j++)
		{
			if (s[i + j] == s[j] && dp[j + 1][i + j - 1])
				dp[j][i + j] = 1;
		}
	}

	for (int i = 1; i < N; i++) // 점화식 판별
	{
		arr[i] = INF;

		for (int j = 1; j <= i; j++)
		{
			if (dp[j][i])
				arr[i] = min(arr[i], arr[j - 1] + 1);
		}
	}

	cout << arr[N - 1];

	return 0;
}