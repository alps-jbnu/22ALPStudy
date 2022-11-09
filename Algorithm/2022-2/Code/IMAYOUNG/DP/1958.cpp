#include <iostream>
#include <string>
#include <algorithm>

//1958 - LCS 3
using namespace std;
pair<string, int> dp[101][101][101];

//n1과 n2의 i번째 j번째 문자가 같다면 
//최대 길이에 1을 더하고..
//최대 부분 수열에 현재 문자를 더한다. 

//기존 LCS 2문제에서 문자열이 하나 더 추가


int main(void) {
	string n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	int n = n1.length();
	int m = n2.length();
	int l = n3.length();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= l; k++) {
				if (n1[i - 1] == n2[j - 1] && n2[j - 1] == n3[k - 1]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else {
					dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
				}
			}

		}
	}
	std::cout << dp[n][m][l];
}