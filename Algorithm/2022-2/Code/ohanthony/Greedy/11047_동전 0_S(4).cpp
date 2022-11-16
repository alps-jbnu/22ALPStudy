#include <bits/stdc++.h>
using namespace std;

int coin[15];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k, index, sum = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> coin[i];
    for (int i = n - 1; i >= 0; i--) {
        sum += k / coin[i]; // k값 보다 큰 동전일 경우 값에 영향을 안미침
        k %= coin[i];
    }

    cout << sum;
    return 0;
}