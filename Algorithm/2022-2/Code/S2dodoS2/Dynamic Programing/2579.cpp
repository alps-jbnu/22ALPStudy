#include <bits/stdc++.h>
using namespace std;

long long dp[301][2];
long long score[301];
int T;
int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> score[i];
	}

	//초기값
	dp[1][0] = score[1];
	dp[1][1] = 0;
	dp[2][0] = score[2];
	dp[2][1] = score[1] + score[2];

	int ans = 0;

	for (int i = 3; i <= T; i++) {
		dp[i][0] = max(dp[i - 2][1], dp[i - 2][0])+score[i];
		dp[i][1] = dp[i - 1][0] + score[i];
	}

	ans = max(dp[T][0], dp[T][1]);
	cout << ans;

}
