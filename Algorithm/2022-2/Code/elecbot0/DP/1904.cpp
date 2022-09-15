#include <bits/stdc++.h>

using namespace std;

int N;
int answer[1000002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    answer[0] = 1; answer[1] = 1;
    for (int i = 2; i <= N; i++) {
        answer[i] = answer[i - 1] + answer[i - 2];
        answer[i] %= 15746;
    }
    cout << answer[N];
    // 1 (1)
    // 00 11 (2)
    // 001 100 111 (3) - 00 붙이고
    // 0011 0000 1001 1100 1111 (5) - 1 붙이고
    // 10000 00100 00001 11100 11001 10011 00111 11111 (8)
    return 0;
}