#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define ll long long
#define pll pair<long long, long long>
const int MAX = 10000 + 1;
using namespace std;

int n, k;
int arr[100 + 1], dp[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= k; i++)
	{
		dp[i] = 100000 + 1;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];

		for (int j = arr[i]; j <= k; j++)
		{
			dp[j] = min(dp[j], dp[j - arr[i]] + 1);
		}
	}

	if (dp[k] == 100001) cout << -1;
	else cout << dp[k];

	return 0;
}