#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[5002];
int dp[5002][5002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i - 1] == arr[n - j])  dp[i][j] = dp[i - 1][j - 1] + 1;
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << n - dp[n][n];
}


