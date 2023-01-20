#include <bits/stdc++.h>
using namespace std;
#define ll long long // -2^63 ~ 2^63-1
#define X first
#define Y second
#define MAX 10000005

int dp[10005];	// x 개 카드를 구매했을 때의 최대 비용
int card[1005];

int result;

int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/vsCode_C++/input.txt", "r", stdin);
	freopen("E:/vsCode_C++/output.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fill(&dp[0], &dp[10004], MAX);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> card[i];

	dp[0] = 0; // dp[0] = MAX이면 dp[k] = card[k] 값 고려 못하게 됨
	dp[1] = card[1];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j] + card[j]);
		}
	}

	cout << dp[n];
}

/*
dp문제는 각 해당 되는 경우를 여러개 나열해서 규칙을 찾으면 된다.
- 1개짜리 카드팩 구매시: dp[n-1] + card[1]
- 2개까지 카드팩 구매시: dp[n-2] + card[2]
.
.
.
- k개짜리 카드팩 구매시: dp[n-k] + card[k] 가 나오게 된다.
*/
