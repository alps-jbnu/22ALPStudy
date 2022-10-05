#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>
#include <tuple>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

int N;
int seq[5001];
int dp[5001][5001];

void func(int s, int e)
{
	if (s == e) return;
	if (s > e) return;
	if (dp[s][e]) return;
	else
	{
		if (seq[s] == seq[e])
		{
			func(s + 1, e - 1);
			dp[s][e] = dp[s+1][e-1];
		}
		else
		{
			func(s + 1, e);
			func(s, e - 1);
			dp[s][e] = min (dp[s+1][e] + 1, dp[s][e-1] + 1);
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
		cin >> seq[i];
	}

	func(1, N);
	
	cout << dp[1][N];
}
