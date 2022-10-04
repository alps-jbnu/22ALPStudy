#include <bits/stdc++.h>

using namespace std;

int N;
char arr[5002];
int dp[5002][5002];

int answer(int start, int end) {
    if (dp[start][end] == -1) {
        if (start >= end) {
            dp[start][end] = 0;
        } else if (arr[start] == arr[end]) {
            dp[start][end] = answer(start + 1, end - 1);
        } else {
            dp[start][end] = min(answer(start + 1, end) + 1, answer(start, end - 1) + 1);
        }
    }
    return dp[start][end];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << answer(1, N);
    return 0;
}