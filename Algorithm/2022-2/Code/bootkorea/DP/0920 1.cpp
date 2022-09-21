#include <bits/stdc++.h>
#define MAX 2000 + 1
using namespace std;

int N, M;
int arr[MAX];
bool dp[MAX][MAX];

void Solve()
{
	for (int i = 1; i <= N; i++) // 1일 때
	{
		dp[i][i] = 1;
	}

	for (int i = 1; i < N; i++) // 2일 때
	{
		if (arr[i] == arr[i + 1])
		{
			dp[i][i + 1] = 1;
		}
	}

	for (int i = 2; i < N; i++)
	{
		for (int j = 1; j <= N - i; j++)
		{
			if (arr[j] == arr[j + i] && dp[j + 1][j + i - 1])
			{
				dp[j][j + i] = 1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	cin >> M;
	memset(dp, 0, sizeof(dp));

	Solve();

	for (int i = 0; i < M; i++)
	{
		int S, E;
		cin >> S >> E;
		cout << dp[S][E] << "\n";
	}

	return 0;
}