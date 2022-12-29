#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define X first
#define Y second

int a, b, c;
int dp[25][25][25]; // a, b, c > 20이라는 조건 때문에 다음과 같은 dp 크기 설정

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1; // base condition

	if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
	if (dp[a][b][c]) return dp[a][b][c];
	if (a < b && b < c) {
		dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		return dp[a][b][c];
	}

	dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	return dp[a][b][c];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) return 0;

		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
	}
}