#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[2002];
int dp[2002][2002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            dp[i][i + 1] = 1;
        }
    }
    for (int i = 2; i < n; i++) {// 팰린드롬의 길이
        for (int j = 0; j < n-i; j++) {
            int s = j, e = j + i;
            if (arr[s] == arr[e]&&dp[s+1][e-1]==1) {
                dp[s][e] = 1;
            }
        }
    }
    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << dp[a-1][b-1] << '\n';
    }
}


