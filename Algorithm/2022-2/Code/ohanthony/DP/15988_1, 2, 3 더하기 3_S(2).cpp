#include <bits/stdc++.h>
using namespace std;
#define ll long long // -2^63 ~ 2^63-1
#define X first
#define Y second
#define MODE 1000000009

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

ll dp[1000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	/*
	4를 만드는 경우를 생각해보면
	4 = 3 + dp[1] -> 3인 상태에서 1을 더하는 가짓 수
	  = 2 + dp[2] -> 2인 상태에서 2을 더하는 가짓 수
	  = 1 + dp[3] -> 1인 상태에서 3을 더하는 가짓 수
	*/
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 1000000; i++) {
		dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % MODE;
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}
