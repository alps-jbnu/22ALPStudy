#include <bits/stdc++.h>
using namespace std;
#define ll long long // -2^63 ~ 2^63-1
#define X first
#define Y second
#define SIZE 1500000
#define MODE 1000000

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

ll dp[SIZE];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < SIZE; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MODE;
    }
    cout << dp[n % SIZE];
    return 0;
}