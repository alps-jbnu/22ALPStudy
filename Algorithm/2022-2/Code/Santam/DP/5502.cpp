#include <bits/stdc++.h>

using namespace std;

int n,dp[5001][5001]{};
string t;

int rec(int f, int s)
{
	if (dp[f][s]) return dp[f][s];
	if (s - f < 2)
	{
		if (t[s - 1] != t[f - 1]) dp[f][s] = 2;
		else dp[f][s] = 1;
		dp[f][f] = 1;
		dp[s][s] = 1;
		return dp[f][s];
	}
	if (t[s - 1] == t[f - 1]) dp[f][s] = rec(f + 1, s - 1);
	else dp[f][s] = min(rec(f + 1, s)+1, rec(f, s - 1)+1);
	return dp[f][s];
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> n >> t;
	cout << rec(1, n)-1;

	return 0;
}