#include <iostream>
#include <string>
#include <algorithm>

//9252 - LCS 2
using namespace std;
pair<string, int> dp[1001][1001];

//n1과 n2의 i번째 j번째 문자가 같다면 
//최대 길이에 1을 더하고..
//최대 부분 수열에 현재 문자를 더한다. 


int main(void) {
	string n1, n2;
	cin >> n1 >> n2;
	int n = n1.length();
	int m = n2.length();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (n1[i - 1] == n2[j - 1]) {
				dp[i][j].first = dp[i - 1][j - 1].first + n1[i - 1];
				dp[i][j].second = dp[i - 1][j - 1].second + 1;
			}
			else {
				if (dp[i - 1][j].second < dp[i][j - 1].second)
					dp[i][j] = dp[i][j - 1];
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[n][m].second << '\n';
	cout << dp[n][m].first << '\n';
}